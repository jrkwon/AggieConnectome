#include "tissueblock.h"

CTissueBlock::CTissueBlock()
{
}

CTissueBlock::~CTissueBlock()
{
}

bool CTissueBlock::ReadInfo(QString strInfoFilename)
{
	m_strInfoFilename = strInfoFilename;
	if(m_strInfoFilename.isEmpty())
		return false;
	
	QFile InfoFile(m_strInfoFilename);
	if(!InfoFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug () << "Cannot open file for reading: " 
				  << qPrintable(InfoFile.errorString());
		return false;
	}
	QTextStream InputTextStream(&InfoFile);
	QString strLine, strTemp;

	while(!InputTextStream.atEnd())
	{
		strLine = InputTextStream.readLine();
		strTemp = strLine.left(2);
		if(strTemp.compare("//") == 0)
			continue;

		QStringList strlstNameValue = strLine.split("=");
		QStringList strlstValue = strlstNameValue[1].split("//");
		QString strName, strValue;
		
		// read tissue raw info
		strName = strlstNameValue[0];
		strValue = strlstValue[0];
		if(strName.compare("RawWidth") == 0)
			m_nRawWidth = strValue.toInt();
		else if(strName.compare("Width") == 0)
			m_nWidth = strValue.toInt();
 		else if(strName.compare("Length") == 0)
			m_nLength = strValue.toInt();
		//else if(strName.compare("MaxHeight") == 0)
		//	m_nMaxHeight = strValue.toInt();
		else if(strName.compare("Thickness") == 0)
			m_rThickness = strValue.toDouble();
		else if(strName.compare("MinStartZ") == 0)
			m_rMinStartZ = strValue.toDouble();
		else if(strName.compare("MaxEndZ") == 0)
			m_rMaxEndZ = strValue.toDouble();
		else if(strName.compare("StartCol") == 0)
			m_nStartCol = strValue.toInt();
		else if(strName.compare("EndCol") == 0)
			m_nEndCol = strValue.toInt();
	}
	// set tissue info
	m_nMaxHeight = qRound((m_rMaxEndZ-m_rMinStartZ+m_rThickness)/m_rThickness);
	qint32 nDiff = m_nEndCol-m_nStartCol;
	m_nNumCol = qAbs(nDiff)+1;
	m_nTotalWidth = m_nWidth*m_nNumCol;
	
	// calculate the size of a unit volume
	quint32 nWidth, nTotalWidth, nLength, nHeight, nZoom, nMaxVertexLength;
	
	nWidth = m_nWidth;
	nLength = m_nLength;
	nHeight = m_nMaxHeight;
	nTotalWidth=nWidth*m_nNumCol;
	nZoom = 0;
	
	// find max length from three vertices of the tissue block
	nMaxVertexLength = (nTotalWidth > nLength) ? nTotalWidth : nLength;
	nMaxVertexLength = (nMaxVertexLength > nHeight) ? nMaxVertexLength : nHeight;
	
	for( ; !(nMaxVertexLength >= 256 && nMaxVertexLength <= 512); nZoom++) 
	{
		nWidth = (int)((nWidth/2.0)+0.5);
		nLength = (int)((nLength/2.0)+0.5);
		nHeight = (int)((nHeight/2.0)+0.5);
		nMaxVertexLength = (int)(nMaxVertexLength/2.0+0.5);
		nTotalWidth = nWidth*m_nNumCol;
	} 
	m_nUnitWidth = nTotalWidth;
	m_nUnitLength = nLength;
	m_nUnitHeight = nHeight;
	m_nNumZoomLevel = nZoom;
	
	return true;
}
