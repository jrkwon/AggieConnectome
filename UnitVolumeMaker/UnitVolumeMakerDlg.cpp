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
#include "unitvolumemakerdlg.h"

#include "itkImage.h"
#include "itkImageRegionConstIterator.h"
#include "itkImageRegionIterator.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
//#include "itkRegionOfInterestImageFilter.h"

#define sINIT_DATA_DIR					"J:/Jaerock/WholeMouseBrain_IndiaInk/"
//#define sINIT_DATA_DIR					QDir::currentPath()
#define sZOOM_OUT_DIR_PREFIX			"ZO_"
#define sDATA_FILE_FORMAT				".jpg"
#define sVOL_DIR_PREFIX					"VOL"
#define sVOL_FILE_FORMAT				".vol"
#define nDEF_BG_COLOR					255

CUnitVolumeMakerDlg::CUnitVolumeMakerDlg(QWidget *parent)
    : QDialog(parent)
{
	Qt::WindowFlags flags = 0;
	flags = Qt::Dialog | Qt::WindowMinimizeButtonHint;
	setWindowFlags(flags);

	ui.setupUi(this);

	//m_ImageStackInfo.ReadInfo(sTEST_DATA_FILENAME);

	//QVariant v(1);

	//ui.comboBoxZoomOutLevel.addItem("All");
	//for(int i = 0, nZoomOut = 1; i < m_ImageStackInfo.m_nNumZoomLevel+1; i++, nZoomOut*=2)
	//{
	//	ui.comboBoxZoomOut->addItem(tr("%1").arg(nZoomOut));
	//}

	connect(ui.comboBoxZoomOutLevel, SIGNAL(currentIndexChanged(int)),
			this, SLOT(RedoIndexes()));

	m_bStopButtonClicked = false;

	////////////////////////////////////
	// default init
	ui.progressBarImage->setValue(0);
	ui.progressBarZoomOut->setValue(0);
	ui.progressBarWidth->setValue(0);
	ui.progressBarLength->setValue(0);
	ui.progressBarHeight->setValue(0);
}

CUnitVolumeMakerDlg::~CUnitVolumeMakerDlg()
{

}

void CUnitVolumeMakerDlg::PrintToLog(QString strLog)
{
	QDateTime DateTime = QDateTime::currentDateTime();

	ui.listWidgetLog->addItem(
							DateTime.toString("yyyy.MM.dd hh:mm:ss ap")
							+ " - " + strLog);
	ui.listWidgetLog->scrollToBottom();

	QFile fileLog(tr("%1/log4unitvolumemaker.txt").arg(ui.lineEditDataFolder->text()));
	fileLog.open(QIODevice::Append | QIODevice::Text);
	QTextStream txtstrmOut(&fileLog);
	txtstrmOut << DateTime.toString("yyyy.MM.dd hh:mm:ss ap") << " - " << strLog << "\n";
	fileLog.close();
}

void CUnitVolumeMakerDlg::RedoIndexes()
{
	//////////////////////////
	// clear the combo boxes
	ui.comboBoxWidth->clear();
	ui.comboBoxLength->clear();
	ui.comboBoxHeight->clear();

	ui.comboBoxWidth->addItem(tr("All"));
	ui.comboBoxLength->addItem(tr("All"));
	ui.comboBoxHeight->addItem(tr("All"));

	int nSelZoomOut = -1;
	if(ui.comboBoxZoomOutLevel->currentText() != tr("All"))
		nSelZoomOut = ui.comboBoxZoomOutLevel->currentText().toInt();

	int iZoomOut;
	iZoomOut = (nSelZoomOut == -1) ? 1 : nSelZoomOut;

	/* ------------
	int nMaxZoomOut = (int)pow((double)2, (double)m_ImageStackInfo.m_nNumZoomLevel);
	int nMaxIndex = nMaxZoomOut/iZoomOut;

	for(int i = 0; i < nMaxIndex; i++)
	{
		ui.comboBoxWidth->addItem(tr("%1").arg(i));
		ui.comboBoxLength->addItem(tr("%1").arg(i));
		ui.comboBoxHeight->addItem(tr("%1").arg(i));
	}
	------------ */

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

	m_nMaxWidthIndex = nWidth/m_ImageStackInfo.m_nUnitWidth;
	m_nMaxLengthIndex = nLength/m_ImageStackInfo.m_nUnitLength;
	m_nMaxHeightIndex = nHeight/m_ImageStackInfo.m_nUnitHeight;

	qDebug("MaxIndex of Width: %d, Length: %d, Height: %d\n", m_nMaxWidthIndex, m_nMaxLengthIndex, m_nMaxHeightIndex);

	for(int i = 0; i < m_nMaxWidthIndex; i++)
		ui.comboBoxWidth->addItem(tr("%1").arg(i));
	for(int i = 0; i < m_nMaxLengthIndex; i++)
		ui.comboBoxLength->addItem(tr("%1").arg(i));
	for(int i = 0; i < m_nMaxHeightIndex; i++)
		ui.comboBoxHeight->addItem(tr("%1").arg(i));
}

void CUnitVolumeMakerDlg::on_pushButtonClearLog_clicked()
{
	ui.listWidgetLog->clear();
}

void CUnitVolumeMakerDlg::on_pushButtonDataFolder_clicked()
{
	QString strInitName = ui.lineEditDataFolder->text();
	if(strInitName.isEmpty())
		strInitName = sINIT_DATA_DIR; //QDir::homePath();

	QString strFolderName =
		QFileDialog::getExistingDirectory(this, tr("Choose Data Folder"),
										strInitName,
										QFileDialog::ShowDirsOnly
										| QFileDialog::DontResolveSymlinks);
	if(strFolderName.isEmpty())
		return;

	//////////////////////////
	// clear the combo boxes
	ui.comboBoxWidth->clear();
	ui.comboBoxLength->clear();
	ui.comboBoxHeight->clear();

	ui.lineEditDataFolder->setText(strFolderName);
	QStringList strlstFolder = strFolderName.split('/'); //QDir::separator());
	QString strInfoFilename;// = strlstFolder[strlstFolder.size()-1];
	strInfoFilename = strFolderName + "/"
						+ strlstFolder[strlstFolder.size()-1] + ".txt";

	if(!m_ImageStackInfo.Read(strInfoFilename))
	{
		QMessageBox::critical(this, tr("File open error"),
									tr("No %1 exists.").arg(strInfoFilename));
		return;
	}
	ui.listWidgetDataInfo->clear();
	ui.listWidgetDataInfo->addItem(tr("nColNum \t: %L1")
									.arg(m_ImageStackInfo.m_nNumCol));
	ui.listWidgetDataInfo->addItem(tr("Width \t: %L1")
									.arg(m_ImageStackInfo.m_nWidth));
	ui.listWidgetDataInfo->addItem(tr("TotalWidth \t: %L1")
									.arg(m_ImageStackInfo.m_nTotalWidth));
	ui.listWidgetDataInfo->addItem(tr("Length \t: %L1")
									.arg(m_ImageStackInfo.m_nLength));
	ui.listWidgetDataInfo->addItem(tr("MaxHeight \t: %L1")
									.arg(m_ImageStackInfo.m_nMaxHeight));
	ui.listWidgetDataInfo->addItem(tr("UnitWidth \t: %L1")
									.arg(m_ImageStackInfo.m_nUnitWidth));
	ui.listWidgetDataInfo->addItem(tr("UnitLength \t: %L1")
									.arg(m_ImageStackInfo.m_nUnitLength));
	ui.listWidgetDataInfo->addItem(tr("UnitHeight \t: %L1")
									.arg(m_ImageStackInfo.m_nUnitHeight));
	ui.listWidgetDataInfo->addItem(tr("NumZoomLevel \t: %L1")
									.arg(m_ImageStackInfo.m_nNumZoomLevel));

	ui.pushButtonStart->setEnabled(true);
	ui.pushButtonStop->setEnabled(false);

	//ui.comboBoxZoomOutLevel->clear();
	QString strZoomOutLevel;
	ui.comboBoxZoomOutLevel->addItem("All");
	int nZoomOut = 1;
	for(unsigned int i = 0; i < m_ImageStackInfo.m_nNumZoomLevel+1; i++, nZoomOut *= 2)
	{
		strZoomOutLevel = QString(tr("%1").arg(nZoomOut));
		ui.comboBoxZoomOutLevel->addItem(strZoomOutLevel);
	}

	RedoIndexes();
	//ReadSettings();
}

void CUnitVolumeMakerDlg::on_pushButtonStart_clicked()
{
	m_bStopButtonClicked = false;
	ui.pushButtonStop->setEnabled(true);
	ui.pushButtonStart->setEnabled(false);
	ui.comboBoxZoomOutLevel->setEnabled(false);
	ui.comboBoxWidth->setEnabled(false);
	ui.comboBoxLength->setEnabled(false);
	ui.comboBoxHeight->setEnabled(false);

	int iSelWidth, iSelLength, iSelHeight, 	nSelZoomOut;
	int iZoomOut, iHeight, iLength, iWidth, nMaxZoomOut;
	bool bOneZoomOut, bOneHeight, bOneLength, bOneWidth;

	iSelWidth = iSelLength = iSelHeight = nSelZoomOut = -1;
	bOneZoomOut = bOneHeight = bOneLength = bOneWidth = false;

	if(ui.comboBoxZoomOutLevel->currentText() != tr("All"))
		nSelZoomOut = ui.comboBoxZoomOutLevel->currentText().toInt();
	if(ui.comboBoxWidth->currentText() != tr("All"))
		iSelWidth = ui.comboBoxWidth->currentText().toInt();
	if(ui.comboBoxLength->currentText() != tr("All"))
		iSelLength = ui.comboBoxLength->currentText().toInt();
	if(ui.comboBoxHeight->currentText() != tr("All"))
		iSelHeight = ui.comboBoxHeight->currentText().toInt();

	//PrintToLog(tr("%1,%2,%3,%4").arg(nSelZoomOut).arg(iSelWidth).arg(iSelLength).arg(iSelHeight));

	nMaxZoomOut = (int)pow((double)2, (double)m_ImageStackInfo.m_nNumZoomLevel);
	iZoomOut = (nSelZoomOut == -1) ? 1 : nSelZoomOut;

	ui.progressBarZoomOut->setRange(0, nMaxZoomOut-1);

	//int nMaxIndex = nMaxZoomOut/iZoomOut;
	//if(nMaxIndex > 1)
	//{
	ui.progressBarWidth->setRange(0, m_nMaxWidthIndex-1);
	ui.progressBarLength->setRange(0, m_nMaxLengthIndex-1);
	ui.progressBarHeight->setRange(0, m_nMaxHeightIndex-1);
	//}

	//PrintToLog(tr("%1").arg(nMaxIndex));

	int i; // progressBarZoomOut index
	for(iZoomOut = 1, i = 0; iZoomOut < nMaxZoomOut && !m_bStopButtonClicked; iZoomOut*=2, i++)
	{
		ui.progressBarZoomOut->setValue(i);
		QCoreApplication::processEvents();

		if(nSelZoomOut != -1)
		{
			iZoomOut = nSelZoomOut;
			bOneZoomOut = true;
		}

		for(iWidth = 0; iWidth < m_nMaxWidthIndex && !m_bStopButtonClicked; iWidth++)
		{
			if(m_nMaxWidthIndex > 1)
				ui.progressBarWidth->setValue(iWidth);
			QCoreApplication::processEvents();

			if(iSelWidth != -1)
			{
				iWidth = iSelWidth;
				bOneWidth = true;
			}
			for(iLength = 0; iLength < m_nMaxLengthIndex && !m_bStopButtonClicked; iLength++)
			{
				if(m_nMaxLengthIndex > 1)
					ui.progressBarLength->setValue(iLength);
				QCoreApplication::processEvents();

				if(iSelLength != -1)
				{
					iLength = iSelLength;
					bOneLength = true;
				}
				for(iHeight = 0; iHeight < m_nMaxHeightIndex && !m_bStopButtonClicked; iHeight++)
				{
					if(m_nMaxHeightIndex > 1)
						ui.progressBarHeight->setValue(iHeight);
					QCoreApplication::processEvents();

					if(iSelHeight != -1)
					{
						iHeight = iSelHeight;
						bOneHeight = true;
					}
					PrintToLog(tr("Vol(%1,%2,%3)").arg(iWidth).arg(iLength).arg(iHeight));
					GetVolume(iWidth, iLength, iHeight, (EZoomOut)iZoomOut);
					if(bOneHeight)
						break;
				}
				if(bOneLength)
					break;
			}
			if(bOneWidth)
				break;
		}
		if(bOneZoomOut)
			break;
	}

	on_pushButtonStop_clicked();
}

void CUnitVolumeMakerDlg::on_pushButtonStop_clicked()
{
	m_bStopButtonClicked = true;
	ui.pushButtonStop->setEnabled(false);
	ui.pushButtonStart->setEnabled(true);
	ui.comboBoxZoomOutLevel->setEnabled(true);
	ui.comboBoxWidth->setEnabled(true);
	ui.comboBoxLength->setEnabled(true);
	ui.comboBoxHeight->setEnabled(true);

	ui.progressBarImage->setValue(0);
	ui.progressBarZoomOut->setValue(0);
	ui.progressBarWidth->setValue(0);
	ui.progressBarLength->setValue(0);
	ui.progressBarHeight->setValue(0);
}

void CUnitVolumeMakerDlg::GetImage(int iWidth, int iLength, int iHeight, int iZ,
								 EZoomOut eZoomOutLevel)
{
	int nCol;
	int nX, nY, nZ;
	int nRibbonWidth;
	int nImageWidth;
	int nRightWidth;
	int nTotalWidth;
	QString strPathName, strImageFileName, strImageVolPathName, strImage4VolFileName;
	QString strDataFolder = ui.lineEditDataFolder->text();

	nRibbonWidth = qRound(float(m_ImageStackInfo.m_nWidth)/eZoomOutLevel);
	nCol = (int)((m_ImageStackInfo.m_nUnitWidth*iWidth)/nRibbonWidth);
	nX = nRibbonWidth - (nRibbonWidth*(nCol+1)-(iWidth*m_ImageStackInfo.m_nUnitWidth));
	nY = iLength*m_ImageStackInfo.m_nUnitLength;
	nZ = iHeight*m_ImageStackInfo.m_nUnitHeight;

	/////////////////////////////////////////////////////////
	// get an output image file name (full path)
	strImageVolPathName = QString(tr("%1/%2%3/%4/")
			.arg(strDataFolder).arg(sZOOM_OUT_DIR_PREFIX).arg(eZoomOutLevel).arg(sVOL_DIR_PREFIX));
	QString strVolDir;
	strVolDir.sprintf("%03d_%03d_%03d", iWidth, iLength, iHeight);
	strVolDir = strImageVolPathName + strVolDir;

	QDir dir;
	dir.mkdir(strImageVolPathName);
	dir.mkdir(strVolDir);
	strImage4VolFileName.sprintf("%03d_%03d_%03d/%05d%s",
			iWidth, iLength, iHeight, nZ*eZoomOutLevel+eZoomOutLevel*iZ, sDATA_FILE_FORMAT);
	strImage4VolFileName = strImageVolPathName + strImage4VolFileName;

	if(QFile::exists(strImage4VolFileName))
	{
		PrintToLog(tr("%1 already exists").arg(strImage4VolFileName));
		return;
	}

	////////////////////////
	// get source filename
	strPathName = QString(tr("%1/%2%3/%4/")
			.arg(strDataFolder).arg(sZOOM_OUT_DIR_PREFIX).arg(eZoomOutLevel).arg(nCol));
	strImageFileName.sprintf("%05d%s", nZ*eZoomOutLevel+eZoomOutLevel*iZ, sDATA_FILE_FORMAT);

	nRightWidth = nRibbonWidth - nX;

	if(nRightWidth > (int) m_ImageStackInfo.m_nUnitWidth)
	{
		nImageWidth = qMin((int)m_ImageStackInfo.m_nUnitWidth, nRibbonWidth);
	}
	else
	{
		nImageWidth = nRightWidth;
	}

	// extract nX, nY, nImageWidth, m_TissueBlock.m_UnitCube.m_nLength
	//...
	//qDebug() << "nX: " << nX << ", nY: " << nY << ", nImageWidth: " << nImageWidth << "\n";
	//ui.listWidgetLog->addItem();
	PrintToLog(tr("Vol(%1,%2,%3) nCol: %4, nX: %5, nY: %6, nImageWidth: %7, %8 - %9")
			.arg(iWidth).arg(iLength).arg(iHeight)
			.arg(nCol).arg(nX).arg(nY).arg(nImageWidth)
			.arg(strPathName).arg(strImageFileName));
	//ui.listWidgetLog->scrollToBottom();

	// source image filename (full path)
	QString strFileName = strPathName + strImageFileName;

	/////////////////////////
	// read an image
	// typedef

	typedef unsigned char PixelType;
	const unsigned int nDimension = 2;
	typedef itk::Image<PixelType, nDimension> ImageType;
	typedef itk::ImageFileReader<ImageType> ReaderType;
	typedef itk::ImageFileWriter<ImageType> WriterType;
	//typedef itk::RegionOfInterestImageFilter<ImageType, ImageType> ROIFilterType;
	typedef itk::ImageRegionConstIterator< ImageType > ConstIteratorType;
	typedef itk::ImageRegionIterator< ImageType>       IteratorType;

	/////////////////////////////////////
	// input: a region of a source image
	ImageType::RegionType InputRegion;
	ImageType::RegionType::IndexType InputStart;
	ImageType::RegionType::SizeType  InputSize;

	InputStart[0] = nX;
	InputStart[1] = nY;

	InputSize[0]  = nImageWidth;
	InputSize[1]  = m_ImageStackInfo.m_nUnitLength;

	InputRegion.SetSize( InputSize );
	InputRegion.SetIndex( InputStart );

	/////////////////////////////////////
	// output: a region of a output image
	ImageType::RegionType OutputRegion, OutputSubRegion;
	ImageType::RegionType::IndexType OutputStart;
	ImageType::RegionType::SizeType  OutputSize;

	OutputStart[0] = 0;
	OutputStart[1] = 0;
	OutputSize[0]  = m_ImageStackInfo.m_nUnitWidth; //InputSize[0];
	OutputSize[1]  = m_ImageStackInfo.m_nUnitLength; //InputSize[1];

	OutputRegion.SetSize( OutputSize );
	OutputRegion.SetIndex( OutputStart );

	OutputSize[0]  = InputSize[0];
	OutputSize[1]  = InputSize[1];

	OutputSubRegion.SetSize( OutputSize );
	OutputSubRegion.SetIndex( OutputStart );

	bool bErrorInSourceImage = false;

	/////////////////////////////////////
	// read the source image
	ReaderType::Pointer pReader = ReaderType::New();
	pReader->SetFileName(strFileName.toStdString());
	try
	{
	    pReader->Update();
	}
	catch ( itk::ExceptionObject &err)
	{
	    std::cerr << "ExceptionObject caught !" << std::endl;
	    std::cerr << err << std::endl;
	    bErrorInSourceImage = true;
	    //return; // -1;
	}

	// Check that the region is contained within the input image.
	if(!pReader->GetOutput()->GetRequestedRegion().IsInside( InputRegion ) )
	{
	    std::cerr << "Error" << std::endl;
	    std::cerr << "The region " << InputRegion << "is not contained within the input image region "
	              << pReader->GetOutput()->GetRequestedRegion() << std::endl;
	    bErrorInSourceImage = true;
	    //return; // -1;
	}

	////////////////////////////////////
	// prepare the output
	ImageType::Pointer pOutputImage = ImageType::New();
	pOutputImage->SetRegions( OutputRegion );
	pOutputImage->Allocate();

	///////////////////////////////////
	// fill buffer with initial value
	ImageType::PixelType  InitialValue = nDEF_BG_COLOR;
	pOutputImage->FillBuffer( InitialValue );

	/////////////////////////////////////////////////////////////////////////
	// get pixels from the source image file and put them into the output image file
	if(bErrorInSourceImage != true)
	{
		ConstIteratorType InputIt(   pReader->GetOutput(), InputRegion  );
		IteratorType      OutputIt(  pOutputImage,         OutputSubRegion );

		for(InputIt.GoToBegin(), OutputIt.GoToBegin(); !InputIt.IsAtEnd(); ++InputIt, ++OutputIt)
		{
		    OutputIt.Set(InputIt.Get());
		}
	}

	nTotalWidth = nImageWidth;

	while(nTotalWidth < (int)m_ImageStackInfo.m_nUnitWidth)
	{
		nCol++;
		if(nCol == (int)m_ImageStackInfo.m_nNumCol)
			break;
		nX = 0;
		nImageWidth = m_ImageStackInfo.m_nUnitWidth - nTotalWidth;
		if(nImageWidth > nRibbonWidth)
		{
			nImageWidth = nRibbonWidth;
		}

		strPathName = QString(tr("%1/%2%3/%4/")
				.arg(strDataFolder).arg(sZOOM_OUT_DIR_PREFIX).arg(eZoomOutLevel).arg(nCol));
		strImageFileName.sprintf("%05d%s", nZ*eZoomOutLevel+eZoomOutLevel*iZ, sDATA_FILE_FORMAT);

		// extract nX, nY, nImageWidth, m_TissueBlock.m_UnitCube.m_nLength
		// for display
		//qDebug() << "nX: " << nX << ", nY: " << nY << ", nImageWidth: " << nImageWidth << "\n";
		//ui.listWidgetLog->addItem(
		PrintToLog(tr("Vol(%1,%2,%3) nCol: %4, nX: %5, nY: %6, nImageWidth: %7, %8 - %9")
				.arg(iWidth).arg(iLength).arg(iHeight)
				.arg(nCol).arg(nX).arg(nY).arg(nImageWidth)
				.arg(strPathName).arg(strImageFileName));
		//ui.listWidgetLog->scrollToBottom();

		// source image filename (full path)
		strFileName = strPathName + strImageFileName;

		// set input size
		InputStart[0] = nX;
		InputStart[1] = nY;

		InputSize[0]  = nImageWidth;
		InputSize[1]  = m_ImageStackInfo.m_nUnitLength;

		InputRegion.SetSize( InputSize );
		InputRegion.SetIndex( InputStart );

		OutputSize[0]  = InputSize[0];
		OutputSize[1]  = InputSize[1];

		ImageType::RegionType::IndexType OutputStartSub;
		OutputStartSub[0] = nTotalWidth;
		OutputStartSub[1] = 0;
		OutputSubRegion.SetSize( OutputSize );
		OutputSubRegion.SetIndex( OutputStartSub );

		bErrorInSourceImage = false;
		/////////////////////////////////////
		// read the source image
		//ReaderType::Pointer pReader = ReaderType::New();
		pReader->SetFileName(strFileName.toStdString());
		try
		{
		    pReader->Update();
		}
		catch ( itk::ExceptionObject &err)
		{
		    std::cerr << "ExceptionObject caught !" << std::endl;
		    std::cerr << err << std::endl;
		    bErrorInSourceImage = true;
		    //return; // -1;
		}

		// Check that the region is contained within the input image.
		if(!pReader->GetOutput()->GetRequestedRegion().IsInside( InputRegion ) )
		{
		    std::cerr << "Error" << std::endl;
		    std::cerr << "The region " << InputRegion << "is not contained within the input image region "
		              << pReader->GetOutput()->GetRequestedRegion() << std::endl;
		    bErrorInSourceImage = true;
		    //return; // -1;
		}

		////////////////////////////////////
		// prepare the output
		//ImageType::Pointer pOutputImage = ImageType::New();
		//pOutputImage->SetRegions( OutputRegion );
		//pOutputImage->Allocate();
		if(bErrorInSourceImage != true)
		{
			ConstIteratorType InputIt(   pReader->GetOutput(), InputRegion  );
			IteratorType      OutputIt(  pOutputImage,         OutputSubRegion );

			for(InputIt.GoToBegin(), OutputIt.GoToBegin(); !InputIt.IsAtEnd(); ++InputIt, ++OutputIt)
			{
			    OutputIt.Set(InputIt.Get());
			}
		}

		nTotalWidth += nImageWidth;

	}

	/////////////////////////////////
	// write an output image
	WriterType::Pointer pWriter = WriterType::New();
	pWriter->SetFileName(strImage4VolFileName.toStdString());
	pWriter->SetInput( pOutputImage );

	try
	{
		pWriter->Update();
	}
	catch ( itk::ExceptionObject &err)
	{
	    std::cerr << "ExceptionObject caught !" << std::endl;
	    std::cerr << err << std::endl;
	    return; // -1;
	}
}

void CUnitVolumeMakerDlg::GetVolume(int iWidth,
								 int iLength,
								 int iHeight,
								 EZoomOut eZoomOutLevel)
{
	int iZ = 0;
	QString strDataFolder = ui.lineEditDataFolder->text();

	///////////////////////
	// check if there already exists the vol folder
	/////////////////////////////////////////////////////////
	// get an output image file name (full path)
	QString strImageVolPathName(tr("%1/%2%3/%4/")
			.arg(strDataFolder).arg(sZOOM_OUT_DIR_PREFIX).arg(eZoomOutLevel).arg(sVOL_DIR_PREFIX));
	QString strVolDir;
	strVolDir.sprintf("%03d_%03d_%03d", iWidth, iLength, iHeight);
	strVolDir = strImageVolPathName + strVolDir;

	QDir dir;
	if(dir.exists(strVolDir))
	{
		PrintToLog(tr("%1 already exists").arg(strVolDir));
		return;
	}

	PrintToLog(tr("Vol: iWidth(%1) iLength(%2) iHeight(%3) ZoomOut(%4")
				.arg(iWidth).arg(iLength).arg(iHeight).arg(eZoomOutLevel));

	ui.progressBarImage->setRange(0, m_ImageStackInfo.m_nUnitHeight-1);
	for(iZ = 0; iZ < (int)m_ImageStackInfo.m_nUnitHeight; iZ++)
	{
		GetImage(iWidth, iLength, iHeight, iZ, eZoomOutLevel);
		ui.progressBarImage->setValue(iZ);

		QCoreApplication::processEvents();
		if(m_bStopButtonClicked)
			break;
	}
	ui.progressBarImage->setValue(0);
}
