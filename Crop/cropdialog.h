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

#ifndef CROPDIALOG_H
#define CROPDIALOG_H

#include <QtGui/QDialog>
#include "ui_cropdialog.h"
#include "tissueblock.h"

///////////////////////////
// itk
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkImageLinearConstIteratorWithIndex.h"
#include "itkImageLinearIteratorWithIndex.h"
#include "itkRegionOfInterestImageFilter.h"
#include "itkImage.h"

const unsigned int g_nDimension = 2;

typedef unsigned char PixelType;
typedef itk::Image<PixelType, g_nDimension> ImageType;
typedef itk::ImageFileReader<ImageType> ReaderType;
typedef itk::ImageFileWriter<ImageType> WriterType;
typedef itk::RegionOfInterestImageFilter< ImageType, 
                                          ImageType > FilterType;
typedef itk::ImageLinearConstIteratorWithIndex<ImageType> ConstIteratorType;
typedef itk::ImageLinearIteratorWithIndex<ImageType>      IteratorType;
///////////////////////////

class CSettings
{
public:
	CSettings();
	~CSettings();
	
public:
	QString m_strProjectDir;
	QString m_strToolkit;
	QString m_strImageMagick;
	QString m_strSourceDir;
	QString m_strDestDir;
	QString m_strZoomOutDirPrefix;
	QString m_strDestFileFormat;
};

class CCropDialog : public QDialog
{
    Q_OBJECT

public:
    CCropDialog(QWidget *parent = 0);
    ~CCropDialog();
    
    void reject();
    void closeEvent(QCloseEvent *event);
	bool AskClose();
	void PrintToOutput(QString strOutput);
	void ReadSettings();
	void DoCrop(int nStartX, int nStartY, int nWidth, int nLength, 
			QString strInputFileName, QString strOutputFileName);
	void DoRelight(int nDirection, 
			itk::ImageLinearConstIteratorWithIndex<ImageType> InputIt, 
			itk::ImageLinearIteratorWithIndex<ImageType> OutputIt);
	quint32 SumOfAbsoluteDifferences(
			itk::ImageLinearConstIteratorWithIndex<ImageType> SearchIt, 
			itk::ImageLinearConstIteratorWithIndex<ImageType> TemplateIt);
	bool GetCropX(QString strSrcImage, quint32 &nStartX);

private slots:
	void UpdateOutput();
	// button's clicked() signal is automatically connected to 
	// on_buttonObjName_clicked() slot by setupUi()
	void on_pushButtonSourceFolderBrowse_clicked();
	void on_pushButtonDestFolderBrowse_clicked();
	void on_pushButtonCrop_clicked();
	void on_pushButtonPauseResume_clicked();
	void on_pushButtonStop_clicked();
	void on_pushButtonClearOutput_clicked();
	
	void ProcessFinished(int nExitCode, QProcess::ExitStatus ExitStatus);
	void ProcessError(QProcess::ProcessError Error);

private:
//public:
    Ui::CCropDialogClass ui;
    CTissueBlock	m_TissueBlock;
    QProcess		m_Process;
    bool			m_bStartCropping;
    bool			m_bProcessFinished;
    //CCropThread		*m_pCropThread;
    bool			m_bPause;
    CSettings	  	m_Settings;
    
    int				m_nSrcCropCol;
};

#if 0
class CCropDialog; // forward declaration

class CCropThread : public QThread
{
	Q_OBJECT
	
public:
	CCropThread(CCropDialog* pParent);
	
public:
	void run();
	void stop();

private:
	CCropDialog* m_pParent;
};
#endif

#endif // CROPDIALOG_H
