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

#include "cropdialog.h"
#include "tissueblock.h"

#define sSETTINGS_FILENAME				"settings.txt"

// Temporary settings for the test
#define sPROJECT_PATH					"E:/Projects/"
#define sTOOLKIT_PATH					"Toolkits/"
#define sIMAGE_MAGICK_PATH				"ImageMagick-6.4.2-Q16"
#define sINIT_SRC_DIR					"E:/Jaerock/isbi10" //"G:/Projects/TestData" //
#define sINIT_DEST_DIR					"E:/Jaerock/isbi10/result"	//"G:/Projects/test"  //
#define sZOOM_OUT_DIR_PREFIX			"ZO_"
#define sDEST_FILE_FORMAT				".jpg"

#define sRESUME							tr("Resume") 
#define sPAUSE							tr("Pause") 

CSettings::CSettings()
{
	m_strProjectDir = sPROJECT_PATH;
	m_strToolkit = sTOOLKIT_PATH;
	m_strImageMagick = sIMAGE_MAGICK_PATH;
	m_strSourceDir = sINIT_SRC_DIR;
	m_strDestDir = sINIT_DEST_DIR;
	m_strZoomOutDirPrefix = sZOOM_OUT_DIR_PREFIX;
	m_strDestFileFormat =sDEST_FILE_FORMAT;
}

CSettings::~CSettings()
{

}

CCropDialog::CCropDialog(QWidget *parent)
    : QDialog(parent)
{
	Qt::WindowFlags flags = 0;
	flags = Qt::Dialog | Qt::WindowMinimizeButtonHint;
	setWindowFlags(flags);
	
	ui.setupUi(this);

	connect(&m_Process, SIGNAL(readyReadStandardError()),
			this, SLOT(UpdateOutput()));
	connect(&m_Process, SIGNAL(finished(int, QProcess::ExitStatus)),
			this, SLOT(ProcessFinished(int, QProcess::ExitStatus)));
	connect(&m_Process, SIGNAL(error(QProcess::ProcessError)),
			this, SLOT(ProcessError(QProcess::ProcessError)));

	// init ui items
	ui.pushButtonCrop->setEnabled(false);
	ui.pushButtonPauseResume->setEnabled(false);
	ui.progressBarColumn->setValue(0);
	ui.progressBarImage->setValue(0);
	
	//m_nSrcCropCol = nSrcCropCol;
	ReadSettings();
}

CCropDialog::~CCropDialog()
{
}

void CCropDialog::ReadSettings()
{
	
	QString strInfoFilename = /*ui.lineEditSourceFolder->text() + "/" +*/ QDir::currentPath() + "/" + sSETTINGS_FILENAME;
	if(strInfoFilename.isEmpty())
		return;
	
	QFile InfoFile(strInfoFilename);
	if(!InfoFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug () << "Cannot open file for reading: " 
				  << qPrintable(InfoFile.errorString());
		return;
	}
	QTextStream InputTextStream(&InfoFile);
	QString strLine, strTemp;

	while(!InputTextStream.atEnd())
	{
		strLine = InputTextStream.readLine();
		strTemp = strLine.left(2);
		if(strTemp.compare("//") == 0)
			continue;

		QStringList strlstNameValue = strLine.split("=");
		QStringList strlstValue = strlstNameValue[1].split("//");
		QString strName, strValue;
		
		// read tissue raw info
		strName = strlstNameValue[0];
		strValue = strlstValue[0];
		if(strName.compare("ProjectDir") == 0)
			m_Settings.m_strProjectDir = strValue;
 		else if(strName.compare("Toolkit") == 0)
 			m_Settings.m_strToolkit = strValue;
 		else if(strName.compare("ImageMagick") == 0)
 			m_Settings.m_strImageMagick = strValue;
		else if(strName.compare("SourceDir") == 0)
			m_Settings.m_strSourceDir = strValue;
		else if(strName.compare("DestDir") == 0)
			m_Settings.m_strDestDir = strValue;
		else if(strName.compare("ZoomOutDirPrefix") == 0)
			m_Settings.m_strZoomOutDirPrefix = strValue;
		else if(strName.compare("DestFileFormat") == 0)
			m_Settings.m_strDestFileFormat = strValue;
	}
}

void CCropDialog::reject()
{

}

bool CCropDialog::AskClose()
{
	QMessageBox::StandardButton ret;
    ret = QMessageBox::question(this, tr("Confirm"),
         tr("Do you want to quit?"),
             QMessageBox::Yes | QMessageBox::No);
	if (ret == QMessageBox::Yes)
	    return true;
	else
	    return false;
}


void CCropDialog::closeEvent(QCloseEvent *event)
{
    if (AskClose()) {
        event->accept();
    } else {
        event->ignore();
    }
}

void CCropDialog::PrintToOutput(QString strOutput)
{
	QDateTime DateTime = QDateTime::currentDateTime();
	
	ui.listWidgetOutput->addItem(
							DateTime.toString("yyyy.MM.dd hh:mm:ss ap") 
							+ " - " + strOutput);
	ui.listWidgetOutput->scrollToBottom();
	
	QFile fileLog(tr("%1/log.txt").arg(ui.lineEditDestFolder->text()));
	fileLog.open(QIODevice::Append | QIODevice::Text);
	QTextStream txtstrmOut(&fileLog);
	txtstrmOut << DateTime.toString("yyyy.MM.dd hh:mm:ss ap") << " - " << strOutput << "\n";
	fileLog.close();
}

void CCropDialog::UpdateOutput()
{
	QByteArray baNewData = m_Process.readAllStandardError();
	PrintToOutput(QString::fromLocal8Bit(baNewData));
}

void CCropDialog::ProcessFinished(int nExitCode, QProcess::ExitStatus ExitStatus)
{
	if(ExitStatus == QProcess::CrashExit)
	{
		PrintToOutput(tr("Conversion program crashed."));
		m_bStartCropping = false;
	}
	else if(nExitCode != 0)
	{
		PrintToOutput(tr("Conversion failed."));
		m_bStartCropping = false;
	}
	else
	{
		// success to create
		PrintToOutput(tr("OK..."));
	}
	//ui.convertButton->setEnabled(true);
	m_bProcessFinished = true;
}

void CCropDialog::ProcessError(QProcess::ProcessError Error)
{
	if(Error == QProcess::FailedToStart)
	{
		PrintToOutput(tr("Conversion program not found"));
		//ui.convertButton->setEnabled(true);
	}
	m_bStartCropping = false;
	m_bProcessFinished = true;
}

void CCropDialog::on_pushButtonSourceFolderBrowse_clicked()
{
	QString strInitName = ui.lineEditSourceFolder->text();
	if(strInitName.isEmpty())
		strInitName = m_Settings.m_strSourceDir; //sINIT_SRC_DIR; //QDir::homePath();
	
	QString strFolderName = 
		QFileDialog::getExistingDirectory(this, tr("Choose Source Folder"),
										strInitName, 
										QFileDialog::ShowDirsOnly 
										| QFileDialog::DontResolveSymlinks);
	if(strFolderName.isEmpty())
		return;

	ui.lineEditSourceFolder->setText(strFolderName);
	QStringList strlstFolder = strFolderName.split('/'); //QDir::separator());
	QString strInfoFilename;// = strlstFolder[strlstFolder.size()-1];
	strInfoFilename = strFolderName + "/" 
						+ strlstFolder[strlstFolder.size()-1] + ".txt";

	if(!m_TissueBlock.ReadInfo(strInfoFilename))
	{
		QMessageBox::critical(this, tr("File open error"), 
									tr("No %1 exists.").arg(strInfoFilename));
		return;
	}
	ui.listWidgetSourceInfo->clear();
	ui.listWidgetSourceInfo->addItem(tr("Width \t: %L1").arg(m_TissueBlock.m_nWidth));
	ui.listWidgetSourceInfo->addItem(tr("Length \t: %L1").arg(m_TissueBlock.m_nLength));
	//ui.listWidgetSourceInfo->addItem(tr("MaxHeight \t: %L1").arg(m_TissueBlock.m_nMaxHeight));
	ui.listWidgetSourceInfo->addItem(tr("Thickness \t: %1").arg(m_TissueBlock.m_rThickness));
	ui.listWidgetSourceInfo->addItem(tr("MinStartZ \t: %1").arg(m_TissueBlock.m_rMinStartZ));
	ui.listWidgetSourceInfo->addItem(tr("MaxEndZ \t: %1").arg(m_TissueBlock.m_rMaxEndZ));
	ui.listWidgetSourceInfo->addItem(tr("StartCol \t: %L1").arg(m_TissueBlock.m_nStartCol));
	ui.listWidgetSourceInfo->addItem(tr("EndCol \t: %L1").arg(m_TissueBlock.m_nEndCol));
	ui.listWidgetSourceInfo->addItem(tr("Method \t: %L1").arg((int)m_TissueBlock.m_eRelightMethod));

	ui.comboBoxColumn->addItem("All");
	int nDiffCol = m_TissueBlock.m_nStartCol - m_TissueBlock.m_nEndCol;
	int nStartCol = nDiffCol > 0 ? m_TissueBlock.m_nEndCol : m_TissueBlock.m_nStartCol;
	int nNumCol = qAbs(nDiffCol)+1;
	
	QString strItem;
	for(int i = nStartCol; i < nNumCol; i++)
	{
		strItem.sprintf("%d", i);
		ui.comboBoxColumn->addItem(strItem);
	}

	//if(m_nSrcCropCol != -1)
	//{
	//	ui.listWidgetSourceInfo->addItem(tr("**SpecifiedCol \t: %L1").arg(m_nSrcCropCol));
	//}
	
	if(!ui.lineEditDestFolder->text().isEmpty())
		ui.pushButtonCrop->setEnabled(true);
	
	ui.progressBarColumn->setRange(0, m_TissueBlock.m_nNumCol-1);
	ui.progressBarImage->setRange(0, m_TissueBlock.m_nMaxHeight-1);
}

void CCropDialog::on_pushButtonDestFolderBrowse_clicked()
{
	QString strInitName = ui.lineEditDestFolder->text();
	if(strInitName.isEmpty())
		strInitName = m_Settings.m_strDestDir; //sINIT_DEST_DIR; //QDir::homePath();
	
	QString strFolderName = 
		QFileDialog::getExistingDirectory(this, tr("Choose Destination Folder"),
										strInitName, 
										QFileDialog::ShowDirsOnly 
										| QFileDialog::DontResolveSymlinks);
	if(strFolderName.isEmpty())
		return;

	if(strFolderName == ui.lineEditSourceFolder->text())
	{
		QMessageBox::critical(this, tr("Destination folder error"), 
			tr("Destination folder should be different from Source folder."));
		return;
	}
	ui.lineEditDestFolder->setText(strFolderName);
	
	ui.listWidgetDestInfo->clear();
	// display destination folder info
	ui.listWidgetDestInfo->addItem(tr("Whole Block \t: %L1x%L2x%L3")
									.arg(m_TissueBlock.m_nTotalWidth)
									.arg(m_TissueBlock.m_nLength)
									.arg(m_TissueBlock.m_nMaxHeight));
	ui.listWidgetDestInfo->addItem(tr("Unit Volume \t: %L1x%L2x%L3")
									.arg(m_TissueBlock.m_nUnitWidth)
									.arg(m_TissueBlock.m_nUnitLength)
									.arg(m_TissueBlock.m_nUnitHeight));
	ui.listWidgetDestInfo->addItem(tr("Zoom Levels \t: %1")
									.arg(m_TissueBlock.m_nNumZoomLevel));
	ui.listWidgetDestInfo->addItem(tr("Columns \t: %1")
									.arg(m_TissueBlock.m_nNumCol));
	
	// make info file for dest
	QStringList strlstFolder = ui.lineEditDestFolder->text().split('/'); //QDir::separator());
	QString strInfoFilename = strlstFolder[strlstFolder.size()-1];
	//qDebug() << "dest info file name: " << strInfoFilename;

	QString strDestInfo = QString(ui.lineEditDestFolder->text() + "/"
									+ strInfoFilename + ".txt");
	QFile fileDestInfo(strDestInfo);
	if(!fileDestInfo.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		qDebug () << "Cannot open file for writing: " 
				  << qPrintable(fileDestInfo.errorString());
		return;
	}
	
	QTextStream strmDestInfo(&fileDestInfo);
	strmDestInfo << "//////////////////////////////////////\n";
	strmDestInfo << "// Dest Data Information\n";
	strmDestInfo << "//////////////////////////////////////\n";
	strmDestInfo << "NumCol=" << m_TissueBlock.m_nNumCol << "\n";
	strmDestInfo << "Width=" << m_TissueBlock.m_nWidth << "\n";
	strmDestInfo << "Length=" << m_TissueBlock.m_nLength << "\n";
	strmDestInfo << "MaxHeight=" << m_TissueBlock.m_nMaxHeight << "\n";
	strmDestInfo << "UnitWidth=" << m_TissueBlock.m_nUnitWidth << "\n";
	strmDestInfo << "UnitLength=" << m_TissueBlock.m_nUnitLength << "\n";
	strmDestInfo << "UnitHeight=" << m_TissueBlock.m_nUnitHeight << "\n";
	strmDestInfo << "NumZoomLevel=" << m_TissueBlock.m_nNumZoomLevel << "\n";

	if(!ui.lineEditSourceFolder->text().isEmpty())
		ui.pushButtonCrop->setEnabled(true);
}

void CCropDialog::on_pushButtonClearOutput_clicked()
{
	ui.listWidgetOutput->clear();
}

void CCropDialog::on_pushButtonPauseResume_clicked()
{
	QString strButton = ui.pushButtonPauseResume->text();
	if(strButton.compare(sPAUSE) == 0)
	{
		ui.pushButtonPauseResume->setText(sRESUME);
		m_bPause = true;
	}
	else
	{
		ui.pushButtonPauseResume->setText(sPAUSE);
		m_bPause = false; // reset
	}
}

void CCropDialog::on_pushButtonStop_clicked()
{
	m_bStartCropping = false;
	m_bPause = false;
	ui.pushButtonPauseResume->setText(sPAUSE);
	ui.pushButtonPauseResume->setEnabled(false);
	//m_pCropThread->stop();
}

void CCropDialog::DoCrop(int nStartX, int nStartY, int nWidth, int nLength, 
		QString strInputFileName, QString strOutputFileName)
{
	if(QFile::exists(strOutputFileName))
	{
		return; // 
	}

	ImageType::IndexType start;
	start[0] = nStartX;
	start[1] = nStartY;

	ImageType::SizeType size;
	size[0] = nWidth;
	size[1] = nLength;
	
	ImageType::RegionType desiredRegion;
	desiredRegion.SetSize(  size  );
	desiredRegion.SetIndex( start );
	FilterType::Pointer filter = FilterType::New();
	filter->SetRegionOfInterest( desiredRegion );

	ReaderType::Pointer reader = ReaderType::New();
	const char * inputFilename  = strInputFileName.toStdString().c_str();

	reader->SetFileName( inputFilename  );
	filter->SetInput( reader->GetOutput() );
	
	//bool bbErrorInSourceImage = false;
        try
	{ 
		filter->Update(); 
	} 
	catch( itk::ExceptionObject & err ) 
	{ 
		std::cerr << "ExceptionObject caught !" << std::endl; 
		std::cerr << err << std::endl; 
		return; // EXIT_FAILURE;
        }
	
	////////////////////////////////////
	// prepare the output
	ImageType::Pointer pOutputImage = ImageType::New();
        pOutputImage->SetRegions( filter->GetOutput()->GetRequestedRegion() );
        //pOutputImage->CopyInformation(pReader->GetOutput());
	pOutputImage->Allocate();
	
	///////////////////////////////////
	// fill buffer with initial value
	ImageType::PixelType  InitialValue = 255;
	pOutputImage->FillBuffer( InitialValue );

	//if(bErrorInSourceImage != true)
	{
		ConstIteratorType InputItX(filter->GetOutput(), filter->GetOutput()->GetRequestedRegion());
		IteratorType      OutputItX(pOutputImage, filter->GetOutput()->GetRequestedRegion());
		DoRelight(0, InputItX, OutputItX);

		ConstIteratorType InputItY(pOutputImage, filter->GetOutput()->GetRequestedRegion());
		IteratorType      OutputItY(pOutputImage, filter->GetOutput()->GetRequestedRegion());
		DoRelight(1, InputItY, OutputItY);
	}
	
	WriterType::Pointer pWriter = WriterType::New();
	const char * outputFilename  = strOutputFileName.toStdString().c_str();
	pWriter->SetFileName(outputFilename);
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

#define nILLUMINATION		150
#define nMAX_PIXEL_VALUE	255
#define nERROR_THRESHOLD	75
#define nERROR_FACTOR		0.8

void CCropDialog::DoRelight(int nDirection, 
		itk::ImageLinearConstIteratorWithIndex<ImageType> InputIt, 
		itk::ImageLinearIteratorWithIndex<ImageType> OutputIt)
{
	InputIt.SetDirection(nDirection);
	OutputIt.SetDirection(nDirection);
	 
	for(InputIt.GoToBegin(), OutputIt.GoToBegin(); !InputIt.IsAtEnd();
			InputIt.NextLine(), OutputIt.NextLine())
	{
		int nSum = 0;
		QVector<PixelType> PixelsInLine;

		while( !InputIt.IsAtEndOfLine() )
		{
			PixelsInLine << InputIt.Get();  // it.Set() doesn't exist in the Const Iterator
			if (m_TissueBlock.m_eRelightMethod == CTissueBlock::RM_AVERAGE_BASED)
				nSum += InputIt.Get();
			++InputIt;
		}
		qSort(PixelsInLine.begin(), PixelsInLine.end());
		PixelType Median;
		if (m_TissueBlock.m_eRelightMethod == CTissueBlock::RM_AVERAGE_BASED)
		{
			// this 'Median' is actually an average
			Median = nSum / PixelsInLine.count();
		}
		else
		{
			Median = PixelsInLine[PixelsInLine.size()/2];
		}
		
		bool bIntensityError = false;
		
		if(Median < nERROR_THRESHOLD)
			bIntensityError = true;

		for(InputIt.GoToBeginOfLine(); !InputIt.IsAtEndOfLine(); ++InputIt, ++OutputIt)
		{
			PixelType PixelValue = InputIt.Get();
			if(bIntensityError == true)
			{
				if(PixelValue < Median*nERROR_FACTOR) // (1-0.2)
				{
					OutputIt.Set(PixelValue); // use the original value
					continue;
				}
			}
			double dAdjustPixelValue = (PixelValue/(double)Median) * nILLUMINATION;
			PixelValue = (dAdjustPixelValue > (double)nMAX_PIXEL_VALUE)
							? (PixelType)nMAX_PIXEL_VALUE : (PixelType)dAdjustPixelValue;
			OutputIt.Set(PixelValue);
		}
		QCoreApplication::processEvents();
	}	
}

#define nTEMPLATE_WIDTH				50 //100
#define nTEMPLATE_LENGHT			20 //50
#define sTEMPLATE_IMAGE_FILENAME	"template50x20.tif"

#define nSEARCH_WIDTH				500
#define nDEF_START_X				900
#define nSTART_X					(nDEF_START_X+m_TissueBlock.m_nWidth-nSEARCH_WIDTH/2)
#define nEND_X						(nSTART_X+nSEARCH_WIDTH)

quint32 CCropDialog::SumOfAbsoluteDifferences(
			itk::ImageLinearConstIteratorWithIndex<ImageType> SearchIt, 
			itk::ImageLinearConstIteratorWithIndex<ImageType> TemplateIt)
{
	SearchIt.SetDirection(0);
	TemplateIt.SetDirection(0);
	 
	PixelType SearchPixelValue, TemplatePixelValue;
	quint32 nSAD = 0;
	
	for(SearchIt.GoToBegin(), TemplateIt.GoToBegin(); !SearchIt.IsAtEnd(); 
		SearchIt.NextLine(), TemplateIt.NextLine())
	{
		for(SearchIt.GoToBeginOfLine(); !SearchIt.IsAtEndOfLine(); ++SearchIt, ++TemplateIt)
		{
			SearchPixelValue = SearchIt.Get();
			TemplatePixelValue = TemplateIt.Get();
			nSAD += qAbs((int)SearchPixelValue-(int)TemplatePixelValue);
		}
		QCoreApplication::processEvents();
	}	
	return nSAD;
}

bool CCropDialog::GetCropX(QString strSrcImage, quint32 &nStartX)
{
	if(QFile::exists(strSrcImage) != true)
	{
		return false; // error
	}

	// mostly, when I need to get images processed partially to make a block for a paper
	if(m_TissueBlock.m_nRawWidth == m_TissueBlock.m_nWidth)
		return false; // do not need to crop

	QString strTemplateFilename(tr("%1/%2")
								.arg(ui.lineEditSourceFolder->text())
								.arg(sTEMPLATE_IMAGE_FILENAME));
	///////////////////////////////
	// read the template image file
	
	ReaderType::Pointer pTemplateReader = ReaderType::New();
	pTemplateReader->SetFileName(strTemplateFilename.toStdString().c_str());
	try
	{
		pTemplateReader->Update();
	}
	catch( itk::ExceptionObject & err ) 
	{ 
		std::cerr << "ExceptionObject caught !" << std::endl; 
		std::cerr << err << std::endl; 
		return false; // EXIT_FAILURE;
	} 

	quint32 nX, nY;
	quint32 nMinSAD, nSAD, nMinSADX;
	quint32 nRightEdgeX;
	
	nMinSADX = nDEF_START_X; // just in case
	nMinSAD = 0xFFFFFFFF;
	
	ImageType::SizeType size;
	size[0] = nTEMPLATE_WIDTH;
	size[1] = nTEMPLATE_LENGHT;
	ImageType::IndexType start;

	ReaderType::Pointer pReader = ReaderType::New();
	pReader->SetFileName( strSrcImage.toStdString().c_str() );
	//////////////////////
	// loop start
	
	for(nY = 0, nX = nSTART_X; nX < nEND_X; nX++)
	{
		///////////////////////////////////////
		// read a region from the search image
		start[0] = nX, start[1] = nY;
	
		ImageType::RegionType DesiredRegion;
		DesiredRegion.SetSize(  size  );
		DesiredRegion.SetIndex( start );
		FilterType::Pointer pFilter = FilterType::New();
		pFilter->SetRegionOfInterest( DesiredRegion );
		pFilter->SetInput( pReader->GetOutput() );
		
		//bool bbErrorInSourceImage = false;
		try 
		{ 
			pFilter->Update(); 
		} 
		catch( itk::ExceptionObject & err ) 
		{ 
			std::cerr << "ExceptionObject caught !" << std::endl; 
			std::cerr << err << std::endl; 
			return false; // EXIT_FAILURE;
		} 
		
		ConstIteratorType SearchIt(pFilter->GetOutput(), pFilter->GetOutput()->GetRequestedRegion());
		ConstIteratorType TemplateIt(pTemplateReader->GetOutput(), pTemplateReader->GetOutput()->GetRequestedRegion());
	
		nSAD = SumOfAbsoluteDifferences(SearchIt, TemplateIt);
		if(nSAD < nMinSAD)
		{
			nMinSAD = nSAD;
			nMinSADX = nX;
		}
	}
	////////////////
	// loop end
	nRightEdgeX = nMinSADX +  nTEMPLATE_WIDTH/2;
	nStartX = nRightEdgeX - m_TissueBlock.m_nWidth;
	return true;
}

void CCropDialog::on_pushButtonCrop_clicked()
{
	/* *************************
	m_pCropThread = new CCropThread(this);
	m_pCropThread->start();
	**************************** */

	QString strTemplateFilename(tr("%1/%2")
								.arg(ui.lineEditSourceFolder->text())
								.arg(sTEMPLATE_IMAGE_FILENAME));
	if(QFile::exists(strTemplateFilename) != true)
	{
		QMessageBox::critical(this, tr("Missing the template image file"), 
							tr("%1 is necessary to crop the image stacks.")
							.arg(sTEMPLATE_IMAGE_FILENAME));
		return;
	}
	
	// make sub folders for cropped data
	QString strZoomOutFolder, strColumnFolder;
	QDir Dir;
	
	m_bStartCropping = true;
	ui.pushButtonCrop->setEnabled(false);
	ui.pushButtonPauseResume->setEnabled(true);
	ui.listWidgetOutput->clear();
	m_bProcessFinished = true;
	m_bPause = false;
	
	////////////////////////////////
	// ZO_1 is not a part of ZoomOutLevel, but needs to be made.
	for(quint32 i = 0, nZoomOutLevel = 1; 
		i < m_TissueBlock.m_nNumZoomLevel+1; i++, nZoomOutLevel *= 2)
	{
		strZoomOutFolder = ui.lineEditDestFolder->text() 
							+ "/" 
							+ QString(sZOOM_OUT_DIR_PREFIX"%1")
								.arg(nZoomOutLevel); 
		Dir.mkdir(strZoomOutFolder);
		PrintToOutput(strZoomOutFolder + " folder created.");

		for(quint32 j = 0; j < m_TissueBlock.m_nNumCol; j++)
		{
			strColumnFolder = strZoomOutFolder + "/" + QString("%1").arg(j);
			Dir.mkdir(strColumnFolder);
			PrintToOutput("\t" + strColumnFolder + " folder created.");
		}
	}

	// open list for source image files
	qint32 nOffset = (m_TissueBlock.m_nStartCol > m_TissueBlock.m_nEndCol) ?
					-1 : 1;
	//QString strSrcFile;
	QString strLine;
	quint32 nSrcStartCol = m_TissueBlock.m_nStartCol;
	
	/////////////////////
	// specify a task that processes only one column
	quint32 nColsToCrop = m_TissueBlock.m_nNumCol;
	quint32 iCol = 0;
	
	//if(m_nSrcCropCol != -1) // an image stack number is specified
	if(ui.comboBoxColumn->currentText() != "All")
	{
		int nSrcCropCol = ui.comboBoxColumn->currentText().toInt();
		iCol = qAbs((int)nSrcStartCol - nSrcCropCol);//(int)m_nSrcCropCol);
		nColsToCrop = iCol+1; // only one column
		nSrcStartCol = nSrcCropCol;//m_nSrcCropCol;
	}

	//for( i = 0; i < m_TissueBlock.m_nNumCol; i++, nSrcStartCol+=nOffset)
	for(; iCol < nColsToCrop; iCol++, nSrcStartCol+=nOffset)
	{
#if 0
		//////////////////////////////////////////////////////////////////////
		// src image crop area
		QString strCropFile(tr("%1/%2_crop_point.txt")
								.arg(ui.lineEditSourceFolder->text()) 
								.arg(nSrcStartCol));

		QFile fileCrop(strCropFile);
		if(!(fileCrop.open(QFile::ReadOnly | QFile::Text)))
		{
			PrintToOutput(tr("No %1 exists.").arg(strCropFile));
			continue; // ignore no folder exists
			//QMessageBox::critical(this, tr("File open error"), 
			//							tr("No %1 exists.").arg(strCropFile));
			//return;
		}
		QTextStream txtstrmCrop(&fileCrop);
		while(!txtstrmCrop.atEnd())
		{
			strLine = txtstrmCrop.readLine();
			if(strLine.isNull())
				break;
			m_TissueBlock.m_vCropStartX.append(strLine.toInt());
		};

		//////////////////////////////////////////////////////////////////////
		// src image crop area index
		QString strChunkPosFile(tr("%1/%2_chunk_pos.txt")
									.arg(ui.lineEditSourceFolder->text())
									.arg(nSrcStartCol));

		QFile fileChunkPos(strChunkPosFile);
		if(!fileChunkPos.open(QFile::ReadOnly | QFile::Text))
		{
			PrintToOutput(tr("No %1 exists.").arg(strChunkPosFile));
			continue; // ignore no folder exists
			//QMessageBox::critical(this, tr("File open error"), 
			//							tr("No %1 exists.").arg(strChunkPosFile));
			//return;
		}
		QTextStream txtstrmChunkPos(&fileChunkPos);
		while(!txtstrmChunkPos.atEnd())
		{
			strLine = txtstrmChunkPos.readLine();
			if(strLine.isNull())
				break;
			m_TissueBlock.m_vChunkPos.append(strLine.toDouble());
		}
#endif		

		QString strSubFolder(tr("%1/%2")
									.arg(ui.lineEditSourceFolder->text())
									.arg(nSrcStartCol));
		QDir dirDataFolder(strSubFolder);
	    
		QStringList slstFilters;
	    slstFilters << QString(tr("*%1").arg(m_Settings.m_strDestFileFormat));
	    dirDataFolder.setNameFilters(slstFilters);
		QStringList slstEntry = dirDataFolder.entryList();
		
		PrintToOutput(tr("Files: %1").arg(slstEntry.count()));
		
		if(slstEntry.count() > 0)
			ui.progressBarImage->setRange(0, slstEntry.count()-1);

		QString strDestImage, strOptions, strSrcImage, strArgs;
		//QStrinList strlstLine;
		qreal rZ;
		quint32 nImage;//, nStartImage;//, nIndexChunk = 0;
		//bool bFirst = true;
		
		//while(!txtstrmSrc.atEnd())
		for(int iImage = 0; iImage < slstEntry.count(); iImage++)
		{
			//QStringList slstImageFile = slstEntry.at(nImage).split(".");
			QString strImageFile = slstEntry.at(iImage);

			// src image filename
			//strLine = txtstrmSrc.readLine();
			//if(strLine.isNull())
			//	break;
			
			// get z coordinate value
			int nPosZ = strImageFile.indexOf('z', 0);//strLine.indexOf('z', 0);
			if(nPosZ == -1)
			{
				QMessageBox::critical(this, tr("Invalid src image filename"), 
									tr("%1 is an invalid src image filename.")
									.arg(strImageFile)); //.arg(strLine));
				m_bStartCropping = false;
				ui.pushButtonCrop->setEnabled(true);
				ui.pushButtonPauseResume->setEnabled(false);
				return;
			}
			rZ = strImageFile.mid(nPosZ+1, 6).toDouble();//strLine.mid(nPosZ+1, 6).toDouble();

			nImage = qRound((rZ - m_TissueBlock.m_rMinStartZ)\
							/m_TissueBlock.m_rThickness);
			//if(bFirst)
			//{
			//	bFirst = false;
			//	nStartImage = nImage;
			//}
#if 0			
			//if((nImage - nStartImage) == m_TissueBlock.m_vChunkPos[nIndexChunk])
			if(rZ == m_TissueBlock.m_vChunkPos[nIndexChunk])
				nIndexChunk++;
#endif
			// make src filename
			strSrcImage = QString(tr("%1/%2/%3")
									.arg(ui.lineEditSourceFolder->text())
									.arg(nSrcStartCol)
									.arg(strImageFile));//.arg(strLine));
			// make dest filename
			QString strZoomOutDir = m_Settings.m_strZoomOutDirPrefix + "1";
			//strDestImage = QString(tr("%1/%2/%3/%4%5")
			//							.arg(ui.lineEditDestFolder->text()) 
			//							.arg(strZoomOutDir)
			//							.arg(i)
			//							.arg(nImage)
			//							.arg(m_Settings.m_strDestFileFormat));
			strDestImage.sprintf("%s/%s/%d/%05d%s", 
										ui.lineEditDestFolder->text().toStdString().c_str(),
										strZoomOutDir.toStdString().c_str(),
										iCol, // jrkwon: %05d
										nImage,
										m_Settings.m_strDestFileFormat.toStdString().c_str());
#if 0			
			strOptions = QString(tr("%1x%2+%3+%4")
							.arg(m_TissueBlock.m_nWidth)
							.arg(m_TissueBlock.m_nLength)
							.arg(m_TissueBlock.m_vCropStartX[nIndexChunk])
							.arg(0));
			strArgs = QString(tr("%1 -crop %2 %3")
							.arg(strSrcImage)
							.arg(strOptions)
							.arg(strDestImage));
			PrintToOutput(strArgs);

			QStringList strlstArgs;
			strlstArgs << strSrcImage << tr("-crop") << strOptions << strDestImage;

			QString strImageMagickConvert;
			strImageMagickConvert = QString(tr("%1%2%3%4")
										 .arg(m_Settings.m_strProjectDir)
										 .arg(m_Settings.m_strToolkit)
										 .arg(m_Settings.m_strImageMagick)
										 .arg("/convert"));
#endif
			ui.progressBarColumn->setValue(iCol);
			ui.progressBarImage->setValue(iImage);
#if 0
			while(m_bProcessFinished == false || m_bPause)
			{
				QCoreApplication::processEvents();				
			}
			m_Process.start(strImageMagickConvert, strlstArgs);
			m_bProcessFinished = false;
			//PrintToOutput(strImageMagickConvert);

			QCoreApplication::processEvents();
#endif			
			// see if there already is a dest file, and do this only no dest file exists
			if(QFile::exists(strDestImage) == false)
			{
				quint32 nStartX;
				if(GetCropX(strSrcImage, nStartX))
				{
					DoCrop(nStartX, 0,
							m_TissueBlock.m_nWidth, m_TissueBlock.m_nLength,
							strSrcImage, strDestImage);
					QString strMsg(tr("CropX: %1, Src: %2, Dest: %3")
									.arg(nStartX).arg(strSrcImage).arg(strDestImage));
					PrintToOutput(strMsg);
				}
			}
			
			if(m_bStartCropping != true)
			{
				ui.pushButtonCrop->setEnabled(true);
				ui.pushButtonPauseResume->setEnabled(false);
				ui.progressBarColumn->setValue(0);
				ui.progressBarImage->setValue(0);
				return;
			}
		}
	}
	ui.pushButtonCrop->setEnabled(true);
	ui.pushButtonPauseResume->setEnabled(false);
}

/* *********************************

CCropThread::CCropThread(CCropDialog *pParent)
{
	m_pParent = pParent;
}

void CCropThread::stop()
{
	m_pParent->ui.pushButtonCrop->setEnabled(true);
	m_pParent->ui.progressBarColumn->setValue(0);
	m_pParent->ui.progressBarImage->setValue(0);

}

void CCropThread::run()
{
	// make sub folders for cropped data
	QString strZoomOutFolder, strColumnFolder;
	QDir Dir;
	
	//m_pParent->m_bStartCropping = true;
	m_pParent->ui.pushButtonCrop->setEnabled(false);
	m_pParent->ui.listWidgetOutput->clear();
	m_pParent->m_bProcessFinished = true;
	
	for(quint32 i = 0, nZoomOutLevel = 1; 
		i < m_pParent->m_TissueBlock.m_nNumZoomLevel; i++, nZoomOutLevel *= 2)
	{
		strZoomOutFolder = m_pParent->ui.lineEditDestFolder->text() 
							+ "/" 
							+ QString(sZOOM_OUT_DIR_PREFIX"%1")
								.arg(nZoomOutLevel); 
		Dir.mkdir(strZoomOutFolder);
		m_pParent->PrintToOutput(strZoomOutFolder + " folder created.");

		for(quint32 i = 0; i < m_pParent->m_TissueBlock.m_nNumCol; i++)
		{
			strColumnFolder = strZoomOutFolder + "/" + QString("%1").arg(i);
			Dir.mkdir(strColumnFolder);
			m_pParent->PrintToOutput("\t" + strColumnFolder + " folder created.");
		}
	}
	
	// open list for source image files
	qint32 nOffset = (m_pParent->m_TissueBlock.m_nStartCol > m_pParent->m_TissueBlock.m_nEndCol) ?
					-1 : 1;
	//QString strSrcFile;
	QString strLine;
	quint32 nSrcStartCol = m_pParent->m_TissueBlock.m_nStartCol;
	
	for(quint32 i = 0; i < m_pParent->m_TissueBlock.m_nNumCol; i++, nSrcStartCol+=nOffset)
	{
		//////////////////////////////////////////////////////////////////////
		// src image crop area
		QString strCropFile(tr("%1/%2_crop_point.txt")
								.arg(m_pParent->ui.lineEditSourceFolder->text()) 
								.arg(nSrcStartCol));

		QFile fileCrop(strCropFile);
		if(!(fileCrop.open(QFile::ReadOnly | QFile::Text)))
		{
			m_pParent->PrintToOutput(tr("No %1 exists.").arg(strCropFile));
			continue; // ignore no folder exists
			//QMessageBox::critical(this, tr("File open error"), 
			//							tr("No %1 exists.").arg(strCropFile));
			//return;
		}
		QTextStream txtstrmCrop(&fileCrop);
		while(!txtstrmCrop.atEnd())
		{
			strLine = txtstrmCrop.readLine();
			if(strLine.isNull())
				break;
			m_pParent->m_TissueBlock.m_vCropStartX.append(strLine.toInt());
		};
		
		//////////////////////////////////////////////////////////////////////
		// src image crop area index
		QString strChunkPosFile(tr("%1/%2_chunk_pos.txt")
									.arg(m_pParent->ui.lineEditSourceFolder->text())
									.arg(nSrcStartCol));

		QFile fileChunkPos(strChunkPosFile);
		if(!fileChunkPos.open(QFile::ReadOnly | QFile::Text))
		{
			m_pParent->PrintToOutput(tr("No %1 exists.").arg(strChunkPosFile));
			continue; // ignore no folder exists
			//QMessageBox::critical(this, tr("File open error"), 
			//							tr("No %1 exists.").arg(strChunkPosFile));
			//return;
		}
		QTextStream txtstrmChunkPos(&fileChunkPos);
		while(!txtstrmChunkPos.atEnd())
		{
			strLine = txtstrmChunkPos.readLine();
			if(strLine.isNull())
				break;
			m_pParent->m_TissueBlock.m_vChunkPos.append(strLine.toInt());
		}

		//////////////////////////////////////////////////////////////////////
		// src image list
		QString strSrcFile(tr("%1/%2_list.txt")
							.arg(m_pParent->ui.lineEditSourceFolder->text())
							.arg(nSrcStartCol));

		QFile fileSrc(strSrcFile);
		if(!fileSrc.open(QFile::ReadOnly | QFile::Text))
		{
			m_pParent->PrintToOutput(tr("No %1 exists.").arg(strSrcFile));
			continue; // ignore no folder exists
			//QMessageBox::critical(this, tr("File open error"), 
			//							tr("No %1 exists.").arg(strSrcFile));
			//return;
		}
		
		QTextStream txtstrmSrc(&fileSrc);
		QString strDestImage, strOptions, strSrcImage, strArgs;
		//QStrinList strlstLine;
		qreal rZ;
		quint32 nImage, nStartImage, nIndexChunk = 0;
		bool bFirst = true;
		
		while(!txtstrmSrc.atEnd()) 
		{
			// src image filename
			strLine = txtstrmSrc.readLine();
			if(strLine.isNull())
				break;
			
			// get z coordinate value
			int nPosZ = strLine.indexOf('z', 0);
			if(nPosZ == -1)
			{
				QMessageBox::critical(m_pParent, tr("Invalid src image filename"), 
									tr("%1 is an invalid src image filename.")
									.arg(strLine));
				//m_pParent->m_bStartCropping = false;
				m_pParent->ui.pushButtonCrop->setEnabled(true);
				return;
			}
			rZ = strLine.mid(nPosZ+1, 6).toDouble();

			nImage = qRound((rZ - m_pParent->m_TissueBlock.m_rMinStartZ)\
							/m_pParent->m_TissueBlock.m_rThickness);
			if(bFirst)
			{
				bFirst = false;
				nStartImage = nImage;
			}
			if((nImage - nStartImage) == m_pParent->m_TissueBlock.m_vChunkPos[nIndexChunk])
				nIndexChunk++;
			// make sec filename
			strSrcImage = QString(tr("%1/%2/%3")
									.arg(m_pParent->ui.lineEditSourceFolder->text())
									.arg(nSrcStartCol)
									.arg(strLine));
			// make dest filename
			strDestImage = QString(tr("%1/"sZOOM_OUT_DIR_PREFIX"1/%2/%3%4")
										.arg(m_pParent->ui.lineEditDestFolder->text()) 
										.arg(i)
										.arg(nImage)
										.arg(sDEST_FILE_FORMAT));
			strOptions = QString(tr("%1x%2+%3+%4")
							.arg(m_pParent->m_TissueBlock.m_nWidth)
							.arg(m_pParent->m_TissueBlock.m_nLength)
							.arg(m_pParent->m_TissueBlock.m_vCropStartX[nIndexChunk])
							.arg(0));
			strArgs = QString(tr("%1 -crop %2 %3")
							.arg(strSrcImage)
							.arg(strOptions)
							.arg(strDestImage));
			m_pParent->PrintToOutput(strArgs);

			QStringList strlstArgs;
			strlstArgs << strSrcImage << tr("-crop") << strOptions << strDestImage;

			QString strImageMagickConvert;
			strImageMagickConvert = QString(tr("%1%2%3%4")
										 .arg(sPROJECT_PATH)
										 .arg(sTOOLKIT_PATH)
										 .arg(sIMAGE_MAGICK_PATH)
										 .arg("/convert"));
			
			m_pParent->ui.progressBarColumn->setValue(i);
			m_pParent->ui.progressBarImage->setValue(nImage);
			while(m_pParent->m_bProcessFinished == false)
			{
				;//QCoreApplication::processEvents();				
			}
			m_pParent->m_Process.start(strImageMagickConvert, strlstArgs);
			m_pParent->m_bProcessFinished = false;
			
			//QCoreApplication::processEvents();
			//if(m_pParent->m_bStartCropping != true)
			//{
			//	m_pParent->ui.pushButtonCrop->setEnabled(true);
			//	m_pParent->ui.progressBarColumn->setValue(0);
			//	m_pParent->ui.progressBarImage->setValue(0);
			//	return;
			//}
		}
	}
	m_pParent->ui.pushButtonCrop->setEnabled(true);	
}

********************************** */

