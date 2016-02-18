#ifndef IMAGESTACKINFO_H_
#define IMAGESTACKINFO_H_

#include <QtGui>

class CImageStackInfo
{
public:
	//////////////////////////////////////////////////////////////////////////
	// image stack info
	quint32		m_nNumCol;
	quint32		m_nWidth;			// ribbon width
	quint32 	m_nLength;			// ribbon length
	quint32 	m_nMaxHeight;		// maximum # of images from image stacks
	quint32		m_nUnitWidth;
	quint32		m_nUnitLength;
	quint32		m_nUnitHeight;
	quint32		m_nNumZoomLevel;

	quint32		m_nTotalWidth;

public:
	CImageStackInfo();
	virtual ~CImageStackInfo();

	bool Read(QString strInfoFilename);

private:
	//////////////////////////////////////////////////////////////////////////
	// tissue block info
	QString 	m_strInfoFilename;
};

#endif /*IMAGESTACKINFO_H_*/
