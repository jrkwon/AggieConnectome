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

#ifndef CONVERTDIALOG_H
#define CONVERTDIALOG_H

#include <QtGui/QDialog>
#include <QtCore/QDir>
#include <QFileDialog>
#include <QDebug>
#include <QProcess>
#include "ui_convertdialog.h"

#define PROJECT_PATH		"G:/Projects/"
#define TOOLKIT_PATH		"Toolkits/"
#define IMAGE_MAGICK_PATH	"ImageMagick-6.4.1-Q16"
//#define QT_PATH				"Qt/4.4.0"
//#define VTK_PATH			"vtk-5.0.4"

class ConvertDialog : public QDialog
{
    Q_OBJECT

public:
    ConvertDialog(QWidget *parent = 0);
    ~ConvertDialog();
	//void on_browseButton_clicked();
	
private slots:
	/* automatic connection */
	void on_browseButton_clicked();
	void on_closeButton_clicked();
	void on_convertButton_clicked();
	
	void updateOutputTextEdit();
	void processFinished(int exitCode, QProcess::ExitStatus exitStatus);
	void processError(QProcess::ProcessError error);

private:
    Ui::ConvertDialogClass ui;
    QProcess process;
    QString targetFile;
};

#endif // CONVERTDIALOG_H
