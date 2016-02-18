TEMPLATE = app
TARGET = Crop
QT += core \
    gui
HEADERS += tissueblock.h \
    cropdialog.h
SOURCES += tissueblock.cpp \
    main.cpp \
    cropdialog.cpp
FORMS += cropdialog.ui
RESOURCES += qrc/Crop.qrc

INCLUDEPATH += E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\Algorithms \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\BasicFilters \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\Common \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\gdcm\src \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\IO \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\Numerics \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\SpatialObject \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\Utilities \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\Utilities\expat \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\Utilities\itkExtHdrs \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\Utilities\itkpng \
#	E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\Utilities\itksys \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\Utilities\itktiff \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\Utilities\itkzlib \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\Utilities\MetaIO \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\Utilities\NrrdIO \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\Utilities\vxl \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\Utilities\vxl\core \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\Utilities\vxl\core\vnl \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\Utilities\vxl\core\vnl\algo \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\include\InsightToolkit\Utilities\vxl\vcl

# vtk
INCLUDEPATH += E:\Projects\Toolkits\vtk-5.0.4\include\vtk-5.0 \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\Wrapping\WrapITK\ExternalProjects\ItkVtkGlue\src
	

# ITK libs
LIBS += \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libITKAlgorithms.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libITKBasicFilters.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libITKCommon.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libITKIO.a \

LIBS += \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libITKDICOMParser.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libITKEXPAT.a \
    E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libITKFEM.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libitkgdcm.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libitkjpeg12.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libitkjpeg16.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libitkjpeg8.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libITKMetaIO.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libITKniftiio.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libITKNrrdIO.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libITKNumerics.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libitkopenjpeg.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libitkpng.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libITKSpatialObject.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libITKStatistics.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libitksys.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libitktiff.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libitkv3p_netlib.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libitkvcl.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libitkvnl.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libitkvnl_algo.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libitkvnl_inst.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libitkzlib.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\lib\InsightToolkit\libITKznz.a \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\Code\Common\CMakeFiles\ITKCommon.dir\itkLightProcessObject.obj \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\Code\Common\CMakeFiles\ITKCommon.dir\itkMetaDataObjectBase.obj \
        E:\Projects\Toolkits\InsightToolkit-3.8.0\Code\Common\CMakeFiles\ITKCommon.dir\itkSpatialOrientationAdapter.obj
#	E:\Projects\Toolkits\InsightToolkit-3.8.0\Utilities\DICOMParser\CMakeFiles\ITKDICOMParser.dir\DICOMParser.obj \
#	E:\Projects\Toolkits\InsightToolkit-3.8.0\Utilities\DICOMParser\CMakeFiles\ITKDICOMParser.dir\DICOMFile.obj \
#	E:\Projects\Toolkits\InsightToolkit-3.8.0\Utilities\DICOMParser\CMakeFiles\ITKDICOMParser.dir\DICOMAppHelper.obj
#	E:\Projects\Toolkits\InsightToolkit-3.8.0\Utilities\gdcm\src\CMakeFiles\itkgdcm.dir\gdcmGlobal.obj \
#	E:\Projects\Toolkits\InsightToolkit-3.8.0\Utilities\gdcm\src\CMakeFiles\itkgdcm.dir\gdcmDocument.obj \
#	E:\Projects\Toolkits\InsightToolkit-3.8.0\Utilities\gdcm\src\CMakeFiles\itkgdcm.dir\gdcmFile.obj \
#	E:\Projects\Toolkits\InsightToolkit-3.8.0\Utilities\gdcm\src\CMakeFiles\itkgdcm.dir\gdcmFileHelper.obj
#	E:\Projects\Toolkits\InsightToolkit-3.8.0\Code\IO\CMakeFiles\ITKIO.dir\itkMetaDataObject.obj \
#	E:\Projects\Toolkits\InsightToolkit-3.8.0\Code\IO\CMakeFiles\ITKIO.dir\itkMetaDataImageIO.obj \

# Win32 libs complied for MinGW
LIBS += E:\Projects\Toolkits\MinGW\lib\libgdi32.a \
    E:\Projects\Toolkits\MinGW\lib\libwsock32.a \
    E:\Projects\Toolkits\MinGW\lib\libsnmpapi.a \
    E:\Projects\Toolkits\MinGW\lib\librpcrt4.a
	
# vtk
LIBS += E:\Projects\Toolkits\vtk-5.0.4\lib\libQVTK.dll.a \
#	E:\Projects\Toolkits\vtk-5.0.4\lib\libQVTKWidgetPlugin.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkCommon.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkDICOMParser.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkexoIIc.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkexpat.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkFiltering.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkfreetype.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkftgl.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkGenericFiltering.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkGraphics.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkHybrid.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkImaging.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkIO.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkjpeg.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkNetCDF.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkpng.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkRendering.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtksys.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtktiff.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkVolumeRendering.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkWidgets.dll.a \
        E:\Projects\Toolkits\vtk-5.0.4\lib\libvtkzlib.dll.a
