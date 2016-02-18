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

#define sTEST_DATA_FILENAME				tr("J:/Jaerock/WholeMouseBrain_IndiaInk/WholeMouseBrain_IndiaInk.txt")
#define sPROJECT_PATH					"G:/Projects/"
#define sTOOLKIT_PATH					"Toolkits/"
#define sIMAGE_MAGICK_PATH				"ImageMagick-6.4.2-Q16"
#define sINIT_DATA_DIR					"J:/Jaerock/WholeMouseBrain_IndiaInk/"
#define sZOOM_OUT_DIR_PREFIX			"ZO_"
#define sDATA_FILE_FORMAT				".jpg"
#define sVOL_DIR_PREFIX					"VOL"
#define sVOL_FILE_FORMAT				".vol"
#define nDEF_BG_COLOR					255

CUnitVolumeMakerDlg::CUnitVolumeMakerDlg(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	
	m_TissueBlock.ReadInfo(sTEST_DATA_FILENAME);
	
	QVariant v(1);

	for(int i = 0; i < m_TissueBlock.m_nNumZoomLevel+1; i++)
	{
		if(i == 0) 
			v = 1;
		else
			v = v.toInt()*2; 		
		ui.comboBoxZoomOut->addItem(v.toString(), v);
	}
}

CUnitVolumeMakerDlg::~CUnitVolumeMakerDlg()
{

}

void CUnitVolumeMakerDlg::on_pushButtonGetVolume_clicked()
{
	int iWidth, iLength, iHeight;
	
	iWidth = ui.lineEditWidth->text().toInt();
	iLength = ui.lineEditLength->text().toInt();
	iHeight = ui.lineEditHeight->text().toInt();
	
	//ui.listWidgetResult->addItem(tr("%1, %2, %3").arg(iWidth).arg(iLength).arg(iHeight));
	int iZoomOut = ui.comboBoxZoomOut->currentIndex();
	QVariant v;
	v = ui.comboBoxZoomOut->itemData(iZoomOut);
	EZoomOut eZoomOut = (EZoomOut)v.toInt();
	GetVolume(iWidth, iLength, iHeight, eZoomOut);
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
	
	nRibbonWidth = qRound(float(m_TissueBlock.m_Ribbon.m_nWidth)/eZoomOutLevel);
	nCol = (int)((m_TissueBlock.m_UnitCube.m_nWidth*iWidth)/nRibbonWidth);
	nX = nRibbonWidth - (nRibbonWidth*(nCol+1)-(iWidth*m_TissueBlock.m_UnitCube.m_nWidth));
	nY = iLength*m_TissueBlock.m_UnitCube.m_nLength;
	nZ = iHeight*m_TissueBlock.m_UnitCube.m_nHeight;
	strPathName = QString(tr("%1%2%3/%4/")
			.arg(sINIT_DATA_DIR).arg(sZOOM_OUT_DIR_PREFIX).arg(eZoomOutLevel).arg(nCol));
	strImageFileName.sprintf("%05d%s", nZ+eZoomOutLevel*iZ, sDATA_FILE_FORMAT);
		
	nRightWidth = nRibbonWidth - nX;
	
	if(nRightWidth > m_TissueBlock.m_UnitCube.m_nWidth)
	{
		nImageWidth = qMin(m_TissueBlock.m_UnitCube.m_nWidth, nRibbonWidth);
	}
	else
	{
		nImageWidth = nRightWidth;
	}
	
	// extract nX, nY, nImageWidth, m_TissueBlock.m_UnitCube.m_nLength
	//...
	qDebug() << "nX: " << nX << ", nY: " << nY << ", nImageWidth: " << nImageWidth << "\n";
	ui.listWidgetResult->addItem(tr("nCol: %1, nX: %2, nY: %3, nImageWidth: %4").arg(nCol).arg(nX).arg(nY).arg(nImageWidth));
	ui.listWidgetResult->addItem(strPathName);
	ui.listWidgetResult->addItem(strImageFileName);
	
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
	InputSize[1]  = m_TissueBlock.m_UnitCube.m_nLength;
	
	InputRegion.SetSize( InputSize );
	InputRegion.SetIndex( InputStart );
	
	/////////////////////////////////////
	// output: a region of a output image 
	ImageType::RegionType OutputRegion, OutputSubRegion;
	ImageType::RegionType::IndexType OutputStart;
	ImageType::RegionType::SizeType  OutputSize;

	OutputStart[0] = 0;
	OutputStart[1] = 0;
	OutputSize[0]  = m_TissueBlock.m_UnitCube.m_nWidth; //InputSize[0];
	OutputSize[1]  = m_TissueBlock.m_UnitCube.m_nLength; //InputSize[1];

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

	while(nTotalWidth < m_TissueBlock.m_UnitCube.m_nWidth)
	{
		nCol++;
		if(nCol == m_TissueBlock.m_nNumCol)
			break;
		nX = 0;
		nImageWidth = m_TissueBlock.m_UnitCube.m_nWidth - nTotalWidth;
		if(nImageWidth > nRibbonWidth)
		{
			nImageWidth = nRibbonWidth;
		}
	
		strPathName = QString(tr("%1%2%3/%4/")
				.arg(sINIT_DATA_DIR).arg(sZOOM_OUT_DIR_PREFIX).arg(eZoomOutLevel).arg(nCol));
		strImageFileName.sprintf("%05d%s", nZ+eZoomOutLevel*iZ, sDATA_FILE_FORMAT);

		// extract nX, nY, nImageWidth, m_TissueBlock.m_UnitCube.m_nLength
		// for display
		qDebug() << "nX: " << nX << ", nY: " << nY << ", nImageWidth: " << nImageWidth << "\n";
		ui.listWidgetResult->addItem(tr("nCol: %1, nX: %2, nY: %3, nImageWidth: %4").arg(nCol).arg(nX).arg(nY).arg(nImageWidth));
		ui.listWidgetResult->addItem(strPathName);
		ui.listWidgetResult->addItem(strImageFileName);
		// source image filename (full path)
		strFileName = strPathName + strImageFileName;
		
		// set input size
		InputStart[0] = nX;
		InputStart[1] = nY;
		
		InputSize[0]  = nImageWidth;
		InputSize[1]  = m_TissueBlock.m_UnitCube.m_nLength;
		
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
	
	/////////////////////////////////////////////////////////
	// get an output image file name (full path)
	strImageVolPathName = QString(tr("%1%2%3/%4/")
			.arg(sINIT_DATA_DIR).arg(sZOOM_OUT_DIR_PREFIX).arg(eZoomOutLevel).arg(sVOL_DIR_PREFIX));
	QString strVolDir;
	strVolDir.sprintf("%03d_%03d_%03d", iWidth, iLength, iHeight);
	strVolDir = strImageVolPathName + strVolDir;
	QDir dir;
	dir.mkdir(strImageVolPathName);
	dir.mkdir(strVolDir);
	strImage4VolFileName.sprintf("%03d_%03d_%03d/%05d%s", 
			iWidth, iLength, iHeight, nZ+eZoomOutLevel*iZ, sDATA_FILE_FORMAT);
	strImage4VolFileName = strImageVolPathName + strImage4VolFileName;

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
	
	for(iZ = 0; iZ < m_TissueBlock.m_UnitCube.m_nHeight; iZ++)
		GetImage(iWidth, iLength, iHeight, iZ, eZoomOutLevel);
}
