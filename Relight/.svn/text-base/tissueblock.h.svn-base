#ifndef TISSUEBLOCK_H_
#define TISSUEBLOCK_H_

#include <QtGui>

class CTissueBlock
{
public:
	//////////////////////////////////////////////////////////////////////////
	// tissue block raw info
	quint32 	m_nRawWidth;		// raw image width
	quint32		m_nWidth;			// ribbon width
	quint32 	m_nLength;			// ribbon length
	qreal 		m_rThickness;		// tissue thickness
	qreal 		m_rMinStartZ;		// minimum z position from image stacks
	qreal 		m_rMaxEndZ;			// maximum z position from image stacks
	quint32 	m_nStartCol;		// start column #
	quint32		m_nEndCol;			// end column #

	//////////////////////////////////////////////////////////////////////////
	// tissue block info
	quint32 	m_nMaxHeight;		// maximum # of images from image stacks
	quint32		m_nNumCol;
	quint32		m_nTotalWidth;
	quint32		m_nUnitWidth;
	quint32		m_nUnitLength;
	quint32		m_nUnitHeight;
	quint32		m_nNumZoomLevel;
	QVector<quint32>	m_vCropStartX;
	QVector<quint32> 	m_vCropStartY; // not used
	//QVector<quint32>	m_vChunkPos;
	QVector<qreal> m_vChunkPos;
	
private:
	//////////////////////////////////////////////////////////////////////////
	// tissue block info
	QString 	m_strInfoFilename;
	
public:
	CTissueBlock();
	virtual ~CTissueBlock();
	
	bool ReadInfo(QString strInfoFilename);
};

#endif /*TISSUEBLOCK_H_*/
