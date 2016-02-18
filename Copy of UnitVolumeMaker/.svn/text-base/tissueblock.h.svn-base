#ifndef TISSUEBLOCK_H_
#define TISSUEBLOCK_H_

#include <QtGui>

class CRect
{
public:
	int		m_nWidth;
	int		m_nLength;
};

class CCube
{
public:
	int		m_nWidth;
	int		m_nLength;
	int		m_nHeight;
};

class CTissueBlock
{
public:
	//////////////////////////////////////////////////////////////////////////
	int			m_nNumCol;
	CRect		m_Ribbon;
	int			m_nMaxHeight;		// maximum # of images from image stacks
	CCube		m_UnitCube;
	int 		m_nNumZoomLevel;
	//////////////////////////////////////////////////////////////////////////
	int			m_nTotalWidth;

public:
	CTissueBlock();
	virtual ~CTissueBlock();

	bool ReadInfo(QString strInfoFilename);

private:
	//////////////////////////////////////////////////////////////////////////
	QString 	m_strInfoFilename;
};

#endif /*TISSUEBLOCK_H_*/
