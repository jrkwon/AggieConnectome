/****************************************************************************
**
** Trolltech hereby grants a license to use the Qt/Eclipse Integration
** plug-in (the software contained herein), in binary form, solely for the
** purpose of creating code to be used with Trolltech's Qt software.
**
** Qt Designer is licensed under the terms of the GNU General Public
** License versions 2.0 and 3.0 ("GPL License"). Trolltech offers users the
** right to use certain no GPL licensed software under the terms of its GPL
** Exception version 1.2 (http://trolltech.com/products/qt/gplexception).
**
** THIS SOFTWARE IS PROVIDED BY TROLLTECH AND ITS CONTRIBUTORS (IF ANY) "AS
** IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
** TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
** PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
** OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
** EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
** PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
** LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** Since we now have the GPL exception I think that the "special exception
** is no longer needed. The license text proposed above (other than the
** special exception portion of it) is the BSD license and we have added
** the BSD license as a permissible license under the exception.
**
****************************************************************************/

#include "volumeviewer.h"

#include <vtkFixedPointVolumeRayCastMapper.h>
#include <vtkVolume.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
//#include <vtkContourFilter.h>
#include <vtkMarchingCubes.h>
#include <vtkPolyDataNormals.h>
#include <vtkPolyDataWriter.h>
#include <vtkTextMapper.h>
#include <vtkActor2D.h>

#define sDATA_FOLDER_NAME		"J:/Jaerock/WholeMouseBrain_IndiaInk/"

CVolumeViewer::CVolumeViewer(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	m_labelStatus = new QLabel;
	ui.statusbar->addPermanentWidget(m_labelStatus);
	m_labelStatus->setText(tr("Brain Network Lab - Texas A&M University"));
	connect(ui.comboBoxZoomOutLevel, SIGNAL(currentIndexChanged(int)),
			this, SLOT(RedoIndexes()));

	Initialize();
}

CVolumeViewer::~CVolumeViewer()
{

}

void CVolumeViewer::Initialize()
{
	m_bLoadData = false;

	///////////////////
	// itk objects
	//m_pReader = ReaderType::New();
	//m_pNameGenerator = NameGeneratorType::New();
	m_pInvertIntensityFilter = InvertIntensityFilterType::New();
	m_pConnector = FilterType::New();

	//////////////////////////
	// vtk objects
    // QT/VTK interact
    m_pRenderer = vtkRenderer::New();
	ui.vtkWidget->GetRenderWindow()->AddRenderer(m_pRenderer);

	m_pTissueExtractor = vtkMarchingCubes::New(); //vtkContourFilter::New();
	m_pTissueNormals = vtkPolyDataNormals::New();
	m_pTissueMapper = vtkPolyDataMapper::New();
	m_pTissue = vtkActor::New();
	m_pTextActor = vtkActor2D::New();
	m_pTextMapper = vtkTextMapper::New();

	//ExecutePipeline();

	qDebug("Initialize...");
	
	ui.progressBar->setValue(0);	
}

void CVolumeViewer::Finalize()
{
	//m_pInvertIntensityFilter->Delete();
	//m_pConnector->Delete();

	//////////////////////////
	// vtk objects
    // QT/VTK interact
    m_pRenderer->Delete();

	m_pTissueExtractor->Delete();
	m_pTissueNormals->Delete();
	m_pTissueMapper->Delete();
	m_pTissue->Delete();
	m_pTextActor->Delete();;
	m_pTextMapper->Delete();

	qDebug("Finalize...");
}

void CVolumeViewer::RedoIndexes()
{
	//////////////////////////
	// clear the combo boxes
	ui.comboBoxWidth->clear();
	ui.comboBoxLength->clear();
	ui.comboBoxHeight->clear();

	int	nSelZoomOut = ui.comboBoxZoomOutLevel->currentText().toInt();
	int iZoomOut = (nSelZoomOut == -1) ? 1 : nSelZoomOut;

	qDebug("iZoomOut: %d\n", iZoomOut);

	int nZoomOutLevelCount = 0;
	for(; iZoomOut != 1; nZoomOutLevelCount++)
		iZoomOut /= 2;

	qDebug("nZoomOutLevelCount: %d\n", nZoomOutLevelCount);

	int nWidth = m_ImageStackInfo.m_nWidth*m_ImageStackInfo.m_nNumCol;
	int nLength = m_ImageStackInfo.m_nLength;
	int nHeight = m_ImageStackInfo.m_nMaxHeight;

	qDebug("Original Width: %d, Length: %d, Height: %d\n", nWidth, nLength, nHeight);

	for(int i = 0; i < nZoomOutLevelCount; i++)
	{
		nWidth = (int)((nWidth/2.0)+0.5);
		nLength = (int)((nLength/2.0)+0.5);
		nHeight = (int)((nHeight/2.0)+0.5);
	}
	qDebug("Adjusted Width: %d, Length: %d, Height: %d\n", nWidth, nLength, nHeight);

	int nMaxWidthIndex = nWidth/m_ImageStackInfo.m_nUnitWidth;
	int nMaxLengthIndex = nLength/m_ImageStackInfo.m_nUnitLength;
	int nMaxHeightIndex = nHeight/m_ImageStackInfo.m_nUnitHeight;

	qDebug("MaxIndex of Width: %d, Length: %d, Height: %d\n", nMaxWidthIndex, nMaxLengthIndex, nMaxHeightIndex);

	for(int i = 0; i < nMaxWidthIndex; i++)
		ui.comboBoxWidth->addItem(tr("%1").arg(i));
	for(int i = 0; i < nMaxLengthIndex; i++)
		ui.comboBoxLength->addItem(tr("%1").arg(i));
	for(int i = 0; i < nMaxHeightIndex; i++)
		ui.comboBoxHeight->addItem(tr("%1").arg(i));
}

void CVolumeViewer::on_pushButtonSaveToVTK_clicked()
{
	unsigned int iWidth = ui.comboBoxWidth->currentText().toInt();
	unsigned int iLength = ui.comboBoxLength->currentText().toInt();
	unsigned int iHeight = ui.comboBoxHeight->currentText().toInt();
	unsigned int nZoomOut = ui.comboBoxZoomOutLevel->currentText().toInt();
	//if(nZoomOut == 0) nZoomOut = 32;

	vtkPolyDataWriter* pWriter = vtkPolyDataWriter::New();
	pWriter->SetInput(m_pTissueNormals->GetOutput());
	QString strFileName;
	strFileName.sprintf("/%03d_%03d_%03d_%d.vtk", iWidth, iLength, iHeight, nZoomOut);
	strFileName = ui.lineEditDataFolder->text() + strFileName;
	pWriter->SetFileName(strFileName.toStdString().c_str());
	pWriter->SetFileTypeToBinary();
	pWriter->Write();
}

void CVolumeViewer::on_pushButtonSaveToVol_clicked()
{
	unsigned int iWidth = ui.comboBoxWidth->currentText().toInt();
	unsigned int iLength = ui.comboBoxLength->currentText().toInt();
	unsigned int iHeight = ui.comboBoxHeight->currentText().toInt();
	unsigned int nZoomOut = ui.comboBoxZoomOutLevel->currentText().toInt();

	typedef itk::ImageFileWriter<ImageType> WriterType;
	WriterType::Pointer pWriter = WriterType::New();
	
	QString strFileName;
	strFileName.sprintf("/%03d_%03d_%03d_%d.img", iWidth, iLength, iHeight, nZoomOut);
	strFileName = ui.lineEditDataFolder->text() + strFileName;
	
	qDebug("Vol file name: %s", strFileName.toStdString().c_str());
	pWriter->SetFileName(strFileName.toStdString().c_str());
	
	m_pInvertIntensityFilter->SetInput(m_pImageData);
	pWriter->SetInput(m_pInvertIntensityFilter->GetOutput());
	
	try
	{
		pWriter->Update();
		qDebug("Writing...");
	}
	catch( itk::ExceptionObject & excp )
	{
		std::cerr << "Error writing a vol file." << std::endl;
		std::cerr << excp << std::endl;
	}
}

void CVolumeViewer::on_pushButtonBrowse_clicked()
{
	QString strInitName = ui.lineEditDataFolder->text();
	if(strInitName.isEmpty())
		strInitName = sDATA_FOLDER_NAME; //QDir::homePath();

	QString strFolderName =
		QFileDialog::getExistingDirectory(this, tr("Choose Data Folder"),
										strInitName,
										QFileDialog::ShowDirsOnly
										| QFileDialog::DontResolveSymlinks);
	if(strFolderName.isEmpty())
		return;

	ui.lineEditDataFolder->setText(strFolderName);
	QStringList strlstFolder = strFolderName.split('/'); //QDir::separator());
	QString strInfoFilename;// = strlstFolder[strlstFolder.size()-1];
	strInfoFilename = strFolderName + "/"
						+ strlstFolder[strlstFolder.size()-1] + ".txt";

	if(!m_ImageStackInfo.ReadInfo(strInfoFilename))
	{
		QMessageBox::critical(this, tr("File open error"),
									tr("No %1 exists.").arg(strInfoFilename));
		return;
	}
	
	QString strZoomOutLevel;
	int nZoomOut = 1;
	for(unsigned int i = 0; i < m_ImageStackInfo.m_nNumZoomLevel+1; i++, nZoomOut *= 2)
	{
		strZoomOutLevel = QString(tr("%1").arg(nZoomOut));
		ui.comboBoxZoomOutLevel->addItem(strZoomOutLevel);
	}
	RedoIndexes();
}

void CVolumeViewer::on_pushButtonDisplayVolume_clicked()
{
	ReadVolume();
	ExecutePipeline();
}

void CVolumeViewer::on_pushButtonReset_clicked()
{
	Finalize();
	Initialize();
	//RedoIndexes();
}

void CVolumeViewer::ReadVolume()
{
	ui.progressBar->setRange(0, m_ImageStackInfo.m_nUnitHeight-1);

	unsigned int iWidth = ui.comboBoxWidth->currentText().toInt();
	unsigned int iLength = ui.comboBoxLength->currentText().toInt();
	unsigned int iHeight = ui.comboBoxHeight->currentText().toInt();
	unsigned int nZoomOut = ui.comboBoxZoomOutLevel->currentText().toInt();

	m_pRenderer->RemoveActor(m_pTissue);
	m_pRenderer->RemoveActor(m_pTextActor);

	//typedef itk::NumericSeriesFileNames NameGeneratorType;

	//m_pNameGenerator->SetSeriesFormat( sDATA_FOLDER_NAME"%05d.jpg" );
	QString strVolumeIndex;
	strVolumeIndex.sprintf("/ZO_%d/VOL/%03d_%03d_%03d/", nZoomOut,
											iWidth, iLength, iHeight);
	QString strSeriesFormat;
	strSeriesFormat = QString(tr("%1%2%3").arg(ui.lineEditDataFolder->text()).arg(strVolumeIndex).arg("%05d.jpg"));

	qDebug() << strSeriesFormat;

	NameGeneratorType::Pointer pNameGenerator = NameGeneratorType::New();

	pNameGenerator->SetSeriesFormat(strSeriesFormat.toStdString());
	unsigned int nStartIndex = iHeight * m_ImageStackInfo.m_nUnitHeight * nZoomOut;
	pNameGenerator->SetStartIndex(nStartIndex); //0 );
	pNameGenerator->SetEndIndex(nStartIndex + (m_ImageStackInfo.m_nUnitHeight-1)*nZoomOut);
	pNameGenerator->SetIncrementIndex( nZoomOut );

	qDebug("Start index: %d, End index: %d", nStartIndex, nStartIndex + (m_ImageStackInfo.m_nUnitHeight-1)*nZoomOut);
	//QMessageBox::warning(this, tr("Help"),
	//							tr("nStart: %1, nEdn: %2").arg(nStartIndex).arg((m_ImageStackInfo.m_nUnitHeight-1)*m_nZoomOut));

	///////////
	// optional
	//pReader->SetImageIO(itk::JPEGImageIO::New());

	ReaderType::Pointer pReader = ReaderType::New();
	pReader->SetFileNames(pNameGenerator->GetFileNames());

	try
	{
		pReader->Update();
	}
	catch (itk::ExceptionObject & err )
	{
		std::cerr << "ExceptionObject caught !" << std::endl;
		std::cerr << err << std::endl;
		return; // EXIT_FAILURE;
	}

	m_pImageData = pReader->GetOutput();
	m_pImageData->DisconnectPipeline();

	m_bLoadData = true;
	ExecutePipeline();
}

void CVolumeViewer::ExecutePipeline()
{
	if(m_bLoadData)
	{
		m_pInvertIntensityFilter->SetInput(m_pImageData);
		m_pConnector->SetInput(m_pInvertIntensityFilter->GetOutput()); //m_pReader->GetOutput());
		m_pTissueExtractor->SetInput(m_pConnector->GetOutput());

		int nIsoSurface = ui.lineEditValue->text().toInt();
		if(nIsoSurface == 0)
			nIsoSurface = 155;
		m_pTissueExtractor->SetValue(0, nIsoSurface);

		m_pTissueNormals->SetInput(m_pTissueExtractor->GetOutput());
		m_pTissueNormals->SetFeatureAngle(60.0);
		m_pTissueMapper->SetInput(m_pTissueNormals->GetOutput());
		m_pTissueMapper->ScalarVisibilityOff();
		m_pTissue->SetMapper(m_pTissueMapper);

	//if(!m_pVolumeMapper)
	//{
	//	m_pVolumeMapper = vtkFixedPointVolumeRayCastMapper::New();
	//	m_pVolumeMapper->SetInput(m_pConnector->GetOutput());

	//	m_pVolume = vtkVolume::New();
	//	m_pVolume->SetMapper(m_pVolumeMapper);
	//	m_pVolume->Update();

	//	//m_pRenderer->AddActor(m_pVolume);

		m_pRenderer->AddActor(m_pTissue);
	}
	else
	{
		m_pTextMapper->SetInput("Aggie Connectome");
		//m_pTextMapper->GetTextProperty()->SetFontSize(15);
	    m_pTextActor->SetMapper(m_pTextMapper);

	    m_pRenderer->AddActor(m_pTextActor);

	}
	m_pRenderer->SetBackground(0.0,0.0,0.4);
	m_pRenderer->ResetCamera();
	m_pRenderer->GetRenderWindow()->Render();
}
