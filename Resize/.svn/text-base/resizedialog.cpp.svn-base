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

#include "resizedialog.h"

#define sSETTINGS_FILENAME				"settings.txt"
// Temporary settings for the test
#define sPROJECT_PATH					"G:/Projects/"
#define sTOOLKIT_PATH					"Toolkits/"
#define sIMAGE_MAGICK_PATH				"ImageMagick-6.4.2-Q16"
#define sINIT_DATA_DIR					"J:/Jaerock/WholeMouseBrain_IndiaInk" //"G:/Projects/TestData" //
#define sZOOM_OUT_DIR_PREFIX			"ZO_"
#define sDATA_FILE_FORMAT				".jpg"

#define sRESUME							tr("Resume") 
#define sPAUSE							tr("Pause") 

CSettings::CSettings()
{
	m_strProjectDir = sPROJECT_PATH;
	m_strToolkit = sTOOLKIT_PATH;
	m_strImageMagick = sIMAGE_MAGICK_PATH;
	m_strDataDir = sINIT_DATA_DIR;
	m_strZoomOutDirPrefix = sZOOM_OUT_DIR_PREFIX;
	m_strDataFileFormat =sDATA_FILE_FORMAT;
}

CSettings::~CSettings()
{

}

CResizeDialog::CResizeDialog(QWidget *parent)
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
	ui.pushButtonResize->setEnabled(false);
	ui.pushButtonPauseResume->setEnabled(false);
	ui.progressBarZoomOut->setValue(0);
	ui.progressBarColumn->setValue(0);
	ui.progressBarImage->setValue(0);

	//if(nSrcResizeZO != -1 && nSrcResizeCol != -1)
	//{
	//	m_nSrcResizeZO = nSrcResizeZO;
	//	m_nSrcResizeCol = nSrcResizeCol;
	//	m_bDoneAverage = bDoneAverage;
	//}
}

CResizeDialog::~CResizeDialog()
{

}

void CResizeDialog::ReadSettings()
{
	
	QString strInfoFilename = ui.lineEditDataFolder->text() + "/" + sSETTINGS_FILENAME;
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
		else if(strName.compare("DataDir") == 0)
			m_Settings.m_strDataDir = strValue;
		else if(strName.compare("ZoomOutDirPrefix") == 0)
			m_Settings.m_strZoomOutDirPrefix = strValue;
		else if(strName.compare("DataFileFormat") == 0)
			m_Settings.m_strDataFileFormat = strValue;
	}
}

void CResizeDialog::reject()
{

}

bool CResizeDialog::AskClose()
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


void CResizeDialog::closeEvent(QCloseEvent *event)
{
    if (AskClose()) {
        event->accept();
    } else {
        event->ignore();
    }
}

void CResizeDialog::PrintToOutput(QString strOutput)
{
	QDateTime DateTime = QDateTime::currentDateTime();
	
	ui.listWidgetOutput->addItem(
							DateTime.toString("yyyy.MM.dd hh:mm:ss ap") 
							+ " - " + strOutput);
	ui.listWidgetOutput->scrollToBottom();
	
	QFile fileLog(tr("%1/log4resize.txt").arg(ui.lineEditDataFolder->text()));
	fileLog.open(QIODevice::Append | QIODevice::Text);
	QTextStream txtstrmOut(&fileLog);
	txtstrmOut << DateTime.toString("yyyy.MM.dd hh:mm:ss ap") << " - " << strOutput << "\n";
	fileLog.close();

}

void CResizeDialog::UpdateOutput()
{
	QByteArray baNewData = m_Process.readAllStandardError();
	PrintToOutput(QString::fromLocal8Bit(baNewData));
}

void CResizeDialog::ProcessFinished(int nExitCode, QProcess::ExitStatus ExitStatus)
{
	if(ExitStatus == QProcess::CrashExit)
	{
		PrintToOutput(tr("Resize program crashed."));
		m_bStartResize = false;
	}
	else if(nExitCode != 0)
	{
		PrintToOutput(tr("Resize failed."));
		m_bStartResize = false;
	}
	else
	{
		// success to create
		PrintToOutput(tr("Succeed..."));
	}
	//ui.convertButton->setEnabled(true);
	m_bProcessFinished = true;
}

void CResizeDialog::ProcessError(QProcess::ProcessError Error)
{
	if(Error == QProcess::FailedToStart)
	{
		PrintToOutput(tr("Resize program not found"));
		//ui.convertButton->setEnabled(true);
	}
	m_bStartResize = false;
	m_bProcessFinished = true;
}

void CResizeDialog::on_pushButtonDataFolderBrowse_clicked()
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
	//ui.listWidgetDataInfo->addItem(tr("** ZoomOut \t: %L1")
	//								.arg(m_nSrcResizeZO));
	//ui.listWidgetDataInfo->addItem(tr("** Col \t: %L1")
	//								.arg(m_nSrcResizeCol));

	ui.pushButtonResize->setEnabled(true);
	ui.pushButtonPauseResume->setEnabled(false);
	
	ui.progressBarZoomOut->setRange(0, m_ImageStackInfo.m_nNumZoomLevel-1);
	ui.progressBarColumn->setRange(0, m_ImageStackInfo.m_nNumCol-1);
	ui.progressBarImage->setRange(0, m_ImageStackInfo.m_nMaxHeight-1);

	QString strZoomOutLevel;
	ui.comboBoxZoomOutLevel->addItem("All");
	int nZoomOut = 1;
	for(unsigned int i = 0; i < m_ImageStackInfo.m_nNumZoomLevel; i++)
	{
		nZoomOut *= 2;
		strZoomOutLevel = QString(tr("%1").arg(nZoomOut));
		ui.comboBoxZoomOutLevel->addItem(strZoomOutLevel);
	}
	
	QString strColumnNum;
	ui.comboBoxColumnNum->addItem("All");
	for(unsigned int i = 0; i < m_ImageStackInfo.m_nNumCol; i++)
	{
		strColumnNum = QString(tr("%1").arg(i));
		ui.comboBoxColumnNum->addItem(strColumnNum);
	}

	ui.checkBoxAverage->setCheckState(Qt::Checked);
	ReadSettings();
}

void CResizeDialog::on_pushButtonClearOutput_clicked()
{
	ui.listWidgetOutput->clear();
}

void CResizeDialog::on_pushButtonStop_clicked()
{
	m_bStartResize = false;
	m_bPause = false;
	ui.pushButtonPauseResume->setText(sPAUSE);
	ui.pushButtonPauseResume->setEnabled(false);
}

void CResizeDialog::on_pushButtonPauseResume_clicked()
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
		m_bPause = false;
	}
}

void CResizeDialog::on_pushButtonResize_clicked()
{
	QString strSubFolder;
	QString strSrcImage;
	QString strDestFolder;
	QString strDestImage;
	QString strArgs;
	QString strImageMagickConvert;
	QString strOptions;
	
	ui.pushButtonResize->setEnabled(false);
	ui.pushButtonPauseResume->setEnabled(true);

	ui.listWidgetOutput->clear();
	m_bStartResize = true;	
	m_bProcessFinished = true;
	m_bPause = false;
	
	bool bOneZoomOut = false;
		
	// here, loop starts...
	for(quint32 nZoomOutLevel = 2, i = 0; 
		(i < m_ImageStackInfo.m_nNumZoomLevel) 
		&& !bOneZoomOut; nZoomOutLevel *= 2, i++)
	{
		if(ui.comboBoxZoomOutLevel->currentText() != tr("All")) // m_nSrcResizeZO != -1)
		{
			// i = ?
			nZoomOutLevel = ui.comboBoxZoomOutLevel->currentText().toInt(); //m_nSrcResizeZO;
			bOneZoomOut = true;
		}
		
		ui.progressBarZoomOut->setValue(i); //nZoomOutLevel);

		bool bOneCol = false;
		for(quint32 nColumn = 0; (nColumn < m_ImageStackInfo.m_nNumCol) && !bOneCol; nColumn++)
		{
			if(ui.comboBoxColumnNum->currentText() != tr("All")) // m_nSrcResizeCol != -1)
			{
				nColumn = ui.comboBoxColumnNum->currentText().toInt(); //m_nSrcResizeCol;
				bOneCol = true;
			}
			
			ui.progressBarColumn->setValue(nColumn);

			// get src file list
			strSubFolder = QString(tr("%1/%2%3/%4"))
											.arg(ui.lineEditDataFolder->text())
											.arg(m_Settings.m_strZoomOutDirPrefix)
											.arg(nZoomOutLevel/2)
											.arg(nColumn);
			qDebug() << strSubFolder;
			
			QDir dirDataFolder(strSubFolder);
		    
			QStringList slstFilters;
		    slstFilters << QString(tr("*%1").arg(m_Settings.m_strDataFileFormat));
		    dirDataFolder.setNameFilters(slstFilters);
			QStringList slstEntry = dirDataFolder.entryList();
			
			PrintToOutput(tr("Files: %1").arg(slstEntry.count()));
			
			if(slstEntry.count() > 0)
				ui.progressBarImage->setRange(0, slstEntry.count()-1);

			//////////////////////
			// 1. Resize
			for(int nImage = 0; nImage < slstEntry.count(); nImage++)
			{
				QStringList slstImageFile = slstEntry.at(nImage).split(".");
				//int nImageNo = slstImageFile[0].toInt();
				
				// comment out for converting all images
				//if(nImageNo % (nZoomOutLevel))
				//	continue;
				
				// make src filename
				strSrcImage = QString(tr("%1/%2")
										.arg(strSubFolder)
										.arg(slstEntry.at(nImage)));
				// make dest filename
				strDestFolder = QString(tr("%1/%2%3/%4")
											.arg(ui.lineEditDataFolder->text()) 
											.arg(m_Settings.m_strZoomOutDirPrefix)
											.arg(nZoomOutLevel)
											.arg(nColumn));
				strDestImage = QString(tr("%1/%2")
											.arg(strDestFolder)
											.arg(slstEntry.at(nImage)));
				
				ui.progressBarImage->setValue(nImage);

				if(QFile::exists(strDestImage))
				{
					// the file already exists
					PrintToOutput(tr("%1 already exists").arg(strDestImage));
					QCoreApplication::processEvents();
					continue;
				}
				
				//strOptions = tr("50%");
				strOptions = tr("%1x%2").arg(qRound(float(m_ImageStackInfo.m_nWidth)/(nZoomOutLevel)))
										.arg(qRound(float(m_ImageStackInfo.m_nLength)/(nZoomOutLevel)));
				strArgs = QString(tr("%1 -resize %2 %3")
								.arg(strSrcImage)
								.arg(strOptions)
								.arg(strDestImage));
				PrintToOutput(strArgs);
			
				QStringList strlstArgs;
				strlstArgs << strSrcImage << tr("-resize") << strOptions << strDestImage;
			
				strImageMagickConvert = QString(tr("%1%2%3%4")
											 .arg(m_Settings.m_strProjectDir)
											 .arg(m_Settings.m_strToolkit)
											 .arg(m_Settings.m_strImageMagick)
											 .arg("/convert"));
				
				//ui.progressBarZoomOut->setValue(i); //nZoomOutLevel);
				//ui.progressBarColumn->setValue(nColumn);
				//ui.progressBarImage->setValue(nImage);
				
				// wait until the external process ends
				while(m_bProcessFinished == false || m_bPause)
				{
					QCoreApplication::processEvents();				
				}
				m_Process.start(strImageMagickConvert, strlstArgs);
				//PrintToOutput(strImageMagickConvert);
				
				m_bProcessFinished = false;
				
				//PrintToOutput(strImageMagickConvert);
			
				QCoreApplication::processEvents();
				if(m_bStartResize != true)
				{
					ui.pushButtonResize->setEnabled(true);
					ui.pushButtonPauseResume->setEnabled(false);
					ui.progressBarZoomOut->setValue(0);
					ui.progressBarColumn->setValue(0);
					ui.progressBarImage->setValue(0);
					return;
				}
			}

			//////////////////////////////////
			// 2. Average two pair images
			if(ui.checkBoxAverage->isChecked()) //m_bDoneAverage != true)
			{
				QString strSrcImage1, strSrcImage2;
				
				for(int nImage = 0; nImage < slstEntry.count(); nImage++)
				{
					QStringList slstImageFile = slstEntry.at(nImage).split(".");
					int nImageNo = slstImageFile[0].toInt();
					
					// comment out for converting all images
					if(nImageNo % (nZoomOutLevel))
						continue;
					
					if(nImage+1 >= slstEntry.count())
						break;
					
					// make dest filename
					strDestFolder = QString(tr("%1/%2%3/%4")
												.arg(ui.lineEditDataFolder->text()) 
												.arg(m_Settings.m_strZoomOutDirPrefix)
												.arg(nZoomOutLevel)
												.arg(nColumn));
					// make src filename
					strSrcImage1 = QString(tr("%1/%2")
											.arg(strDestFolder)
											.arg(slstEntry.at(nImage)));
					strSrcImage2 = QString(tr("%1/%2")
											.arg(strDestFolder)
											.arg(slstEntry.at(nImage+1)));
					
					// if strSrcImage2 is not the 'next' image, don't average them
					QStringList slstNextImageFile = slstEntry.at(nImage+1).split(".");
					unsigned int nNextImageNo = slstNextImageFile[0].toInt();
					if(nNextImageNo != (nImageNo+nZoomOutLevel/2))
					{
						PrintToOutput(tr("The 2nd src image no(%1) is not %2.")
								.arg(nNextImageNo).arg(nImageNo+nZoomOutLevel/2));
						QCoreApplication::processEvents();
						continue;
					}

					// destinmation file name
					strDestImage = QString(tr("%1/%2")
												.arg(strDestFolder)
												.arg(slstEntry.at(nImage)));
					
					strArgs = QString(tr("%1 %2 -average %3")
									.arg(strSrcImage1)
									.arg(strSrcImage2)
									.arg(strDestImage));
					PrintToOutput(strArgs);
				
					QStringList strlstArgs;
					strlstArgs << strSrcImage1 << strSrcImage2 << tr("-average") << strDestImage;
				
					strImageMagickConvert = QString(tr("%1%2%3%4")
												 .arg(m_Settings.m_strProjectDir)
												 .arg(m_Settings.m_strToolkit)
												 .arg(m_Settings.m_strImageMagick)
												 .arg("/convert"));
					
					//ui.progressBarZoomOut->setValue(i); //nZoomOutLevel);
					//ui.progressBarColumn->setValue(nColumn);
					ui.progressBarImage->setValue(nImage);
					
					// wait until the external process ends
					while(m_bProcessFinished == false || m_bPause)
					{
						QCoreApplication::processEvents();				
					}
					m_Process.start(strImageMagickConvert, strlstArgs);
					//PrintToOutput(strImageMagickConvert);
					
					m_bProcessFinished = false;
					
					//PrintToOutput(strImageMagickConvert);
				
					QCoreApplication::processEvents();
				}
			}
			
			/////////////////////////////
			// 3. Rename unnecessary files
			for(int nImage = 0; nImage < slstEntry.count(); nImage++)
			{
				QStringList slstImageFile = slstEntry.at(nImage).split(".");
				int nImageNo = slstImageFile[0].toInt();
				
				if(nImageNo % (nZoomOutLevel))
				{
					// make src filename
					strSrcImage = QString(tr("%1/%2")
										.arg(strDestFolder)
										.arg(slstEntry.at(nImage)));
					strDestImage = strSrcImage + "_not_";

					QFile::rename(strSrcImage, strDestImage);
					PrintToOutput("rename: " + strSrcImage + "->" + strDestImage);
					
					QCoreApplication::processEvents();
				}
				ui.progressBarImage->setValue(nImage);
			}
		}
	}
	ui.pushButtonResize->setEnabled(true);
	ui.pushButtonPauseResume->setEnabled(false);
}
