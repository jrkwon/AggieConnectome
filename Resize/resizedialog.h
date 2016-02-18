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

#ifndef RESIZEDIALOG_H
#define RESIZEDIALOG_H

#include <QtGui/QDialog>
#include "ui_resizedialog.h"
#include "imagestackinfo.h"

class CSettings
{
public:
	CSettings();
	~CSettings();
	
public:
	QString m_strProjectDir;
	QString m_strToolkit;
	QString m_strImageMagick;
	QString m_strDataDir;
	QString m_strZoomOutDirPrefix;
	QString m_strDataFileFormat;
};

class CResizeDialog : public QDialog
{
    Q_OBJECT

public:
    CResizeDialog(QWidget *parent = 0);
    ~CResizeDialog();
    
    void reject();
    void closeEvent(QCloseEvent *event);
    void PrintToOutput(QString strOutput);
	bool AskClose();
	void ReadSettings();

private slots:
	// button's clicked() signal is automatically connected to 
	// on_buttonObjName_clicked() slot by setupUi()
	void on_pushButtonDataFolderBrowse_clicked();
	void on_pushButtonClearOutput_clicked();
	void on_pushButtonPauseResume_clicked();
	void on_pushButtonStop_clicked();
	void on_pushButtonResize_clicked();
	
    void ProcessFinished(int nExitCode, QProcess::ExitStatus ExitStatus);
	void ProcessError(QProcess::ProcessError Error);
	void UpdateOutput();
	
private:
    Ui::CResizeDialogClass ui;
    CImageStackInfo m_ImageStackInfo;
    QProcess		m_Process;
    bool			m_bStartResize;
    bool			m_bProcessFinished;
    CSettings	  	m_Settings;
    bool			m_bPause;
    
    //int 			m_nSrcResizeZO;
    //int				m_nSrcResizeCol;
    //bool			m_bDoneAverage;
};

#endif // RESIZEDIALOG_H
