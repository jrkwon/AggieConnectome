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

#ifndef UNITVOLUMEMAKERDLG_H
#define UNITVOLUMEMAKERDLG_H

#include <QtGui/QDialog>
#include "ui_unitvolumemakerdlg.h"
#include "imagestackinfo.h"

class CUnitVolumeMakerDlg : public QDialog
{
    Q_OBJECT

    enum EZoomOut {
		ZO_1	= 1, // actuall size
		ZO_2	= 2,
		ZO_4	= 4,
		ZO_8	= 8,
		ZO_16	= 16,
		ZO_32	= 32,
		ZO_64	= 64,
		ZO_128	= 128,
		ZO_256	= 256,
	};

public:
	CUnitVolumeMakerDlg(QWidget *parent = 0);
    ~CUnitVolumeMakerDlg();

    void PrintToLog(QString strLog);

    void GetImage(int iWidth, int iLength, int iHeight, int iZ, EZoomOut eZoomOutLevel);
    void GetVolume(int iWidth, int iLength, int iHeight, EZoomOut eZoomOutLevel);

private slots:
	void on_pushButtonDataFolder_clicked();
	void on_pushButtonStart_clicked();
	void on_pushButtonStop_clicked();
	void on_pushButtonClearLog_clicked();

	void RedoIndexes();

private:
    Ui::CUnitVolumeMakerDlgClass ui;
    CImageStackInfo	m_ImageStackInfo;
	int m_nMaxWidthIndex;
	int m_nMaxLengthIndex;
	int m_nMaxHeightIndex;

    bool m_bStopButtonClicked;
};

#endif // UNITVOLUMEMAKERDLG_H
