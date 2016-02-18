#include "imagestackinfo.h"

CImageStackInfo::CImageStackInfo()
{
}

CImageStackInfo::~CImageStackInfo()
{
}

bool CImageStackInfo::ReadInfo(QString strInfoFilename)
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
		if(strName.compare("NumCol") == 0)
			m_nNumCol = strValue.toInt();
 		else if(strName.compare("Width") == 0)
			m_nWidth = strValue.toInt();
 		else if(strName.compare("Length") == 0)
			m_nLength = strValue.toInt();
		else if(strName.compare("MaxHeight") == 0)
			m_nMaxHeight = strValue.toInt();
		else if(strName.compare("UnitWidth") == 0)
			m_nUnitWidth = strValue.toInt();
		else if(strName.compare("UnitLength") == 0)
			m_nUnitLength = strValue.toInt();
		else if(strName.compare("UnitHeight") == 0)
			m_nUnitHeight = strValue.toInt();
		else if(strName.compare("NumZoomLevel") == 0)
			m_nNumZoomLevel = strValue.toInt();
	}
	// set tissue info
	m_nTotalWidth = m_nWidth*m_nNumCol;
	
	return true;
}
