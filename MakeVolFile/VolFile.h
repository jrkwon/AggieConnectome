#ifndef VOLFILE_H_
#define VOLFILE_H_

#include <QtGui>
#include "imagestackinfo.h"

class CVoxel
{
public:
	qreal m_dResolX, m_dResolY, m_dResolZ;
};

class CVolFileHeader
{
public:
	quint32	m_nWidth, m_nLength, m_nHeight;
	CVoxel  m_VoxelResol;
};

class CVolFile
{
public:
	CImageStackInfo m_ImageStackInfo;
	CVolFileHeader m_Header;
	uchar *m_pcData;
	
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
	CVolFile();
	~CVolfile();
	
	bool Init(void);
	bool Read(quint32 iWidth, quint32 iLength, quint32 iHeight, EZoomOut eLevel);
	bool Make(void);
};

#endif /*VOLFILE_H_*/
