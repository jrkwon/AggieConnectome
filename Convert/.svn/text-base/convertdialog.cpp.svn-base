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

#include "convertdialog.h"

ConvertDialog::ConvertDialog(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);

	ui.convertButton->setEnabled(false);
	
	QStringList targetFormat;
	targetFormat << "bmp" << "jpg" << "png" << "gif";
	ui.targetFormatComboBox->addItems(targetFormat);
	
	/* connect signals with slots */
	connect(&process, SIGNAL(readyReadStandardError()), 
			this, SLOT(updateOutputTextEdit()));
	connect(&process, SIGNAL(finished(int, QProcess::ExitStatus)), 
			this, SLOT(processFinished(int, QProcess::ExitStatus)));
	connect(&process, SIGNAL(error(QProcess::ProcessError)), 
			this, SLOT(processError(QProcess::ProcessError)));
}

ConvertDialog::~ConvertDialog()
{

}

void ConvertDialog::on_browseButton_clicked()
{
	QString initialName = ui.sourceFileEdit->text();
	if(initialName.isEmpty())
		initialName = QDir::homePath();
	QString fileName = QFileDialog::getOpenFileName(this, tr("Choose File"), 
													initialName);
	fileName = QDir::toNativeSeparators(fileName);
	if(!fileName.isEmpty())
	{
		ui.sourceFileEdit->setText(fileName);
		ui.convertButton->setEnabled(true);
	}
}

void ConvertDialog::on_closeButton_clicked()
{
	reject();
}

void ConvertDialog::on_convertButton_clicked()
{
	QString sourceFile = ui.sourceFileEdit->text();
	targetFile = QFileInfo(sourceFile).path() + "/" /* QDir::separator()*/
				 + QFileInfo(sourceFile).baseName() + "."
				 + ui.targetFormatComboBox->currentText().toLower();
	ui.convertButton->setEnabled(false);
	ui.outputTextEdit->clear();
	
	QStringList args;
	if(ui.enhanceCheckBox->isChecked())
		args << "-enhance";
	if(ui.monochromeCheckBox->isChecked())
		args << "-monochrome";
	args << sourceFile << targetFile;
	
	QString imageMagickConvert;
	imageMagickConvert = QString(tr("%1%2%3%4")).arg(PROJECT_PATH)\
							.arg(TOOLKIT_PATH).arg(IMAGE_MAGICK_PATH).arg("/convert");
	process.start(imageMagickConvert, args);
}

void ConvertDialog::updateOutputTextEdit()
{
	QByteArray newData = process.readAllStandardError();
	QString text = ui.outputTextEdit->toPlainText()
					+ QString::fromLocal8Bit(newData);
	ui.outputTextEdit->setPlainText(text);
}

void ConvertDialog::processFinished(int exitCode, 
									QProcess::ExitStatus exitStatus)
{
	if(exitStatus == QProcess::CrashExit)
	{
		ui.outputTextEdit->appendPlainText(tr("Conversion program crashed"));
	}
	else if(exitCode != 0)
	{
		ui.outputTextEdit->appendPlainText(tr("Conversion failed"));
	}
	else
	{
		ui.outputTextEdit->appendPlainText(tr("File %1 created").arg(targetFile));
	}
	ui.convertButton->setEnabled(true);
}

void ConvertDialog::processError(QProcess::ProcessError error)
{
	if(error == QProcess::FailedToStart)
	{
		ui.outputTextEdit->appendPlainText(tr("Conversion program not found"));
		ui.convertButton->setEnabled(true);
	}
}
