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

#ifndef VOLUMEVIEWER_H
#define VOLUMEVIEWER_H

#include <QtGui/QMainWindow>
#include "ui_volumeviewer.h"
#include "imagestackinfo.h"

#include "itkImage.h"
#include "itkImageSeriesReader.h"
#include "itkNumericSeriesFileNames.h"
#include "itkJPEGImageIO.h"
#include "itkImageToVTKImageFilter.h"
#include "itkInvertIntensityImageFilter.h"
#include "itkImageFileWriter.h"

const unsigned int g_nDimension = 3;

typedef unsigned char PixelType;
typedef itk::Image<PixelType, g_nDimension> ImageType;
typedef itk::ImageSeriesReader<ImageType> ReaderType;
typedef itk::NumericSeriesFileNames NameGeneratorType;
typedef itk::ImageToVTKImageFilter<ImageType> FilterType;
typedef itk::InvertIntensityImageFilter<ImageType, ImageType> InvertIntensityFilterType;

// Forward class declarations
//class vtkCylinderSource;
//class vtkPolyDataMapper;
//class vtkExodusReader;
//class vtkDataSetMapper;
//class vtkActor;
class vtkFixedPointVolumeRayCastMapper;
class vtkVolume;
class vtkRenderer;
class vtkContourFilter;
class vtkMarchingCubes;
class vtkPolyDataNormals;
class vtkPolyDataMapper;
class vtkActor;
class vtkActor2D;
class vtkTextMapper;

class CVolumeViewer : public QMainWindow
{
    Q_OBJECT

public:
    CVolumeViewer(QWidget *parent = 0);
    ~CVolumeViewer();
	void ReadVolume();
	void Initialize();
	void Finalize();
	
private slots:
	void on_pushButtonDisplayVolume_clicked();
	void on_pushButtonBrowse_clicked();
	void on_pushButtonSaveToVTK_clicked();
	void on_pushButtonSaveToVol_clicked();
	void on_pushButtonReset_clicked();
	void ExecutePipeline();
	void RedoIndexes();

private:
    Ui::CVolumeViewerClass ui;
    QLabel *m_labelStatus;
    CImageStackInfo m_ImageStackInfo;

    FilterType::Pointer m_pConnector;
    ReaderType::Pointer m_pReader;
    NameGeneratorType::Pointer m_pNameGenerator;
    InvertIntensityFilterType::Pointer m_pInvertIntensityFilter;
    ImageType::Pointer m_pImageData;

    vtkRenderer* m_pRenderer;
    vtkFixedPointVolumeRayCastMapper *m_pVolumeMapper;
    vtkVolume *m_pVolume;
    vtkMarchingCubes /*ContourFilter*/ *m_pTissueExtractor;
    vtkPolyDataNormals *m_pTissueNormals;
    vtkPolyDataMapper *m_pTissueMapper;
    vtkActor *m_pTissue;
    vtkActor2D* m_pTextActor;
    vtkTextMapper *m_pTextMapper;

    unsigned int m_iWidth;
    unsigned int m_iLength;
    unsigned int m_iHeight;
    unsigned int m_nZoomOut;
    bool m_bLoadData;
};

#endif // VOLUMEVIEWER_H
