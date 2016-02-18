#include "VolFile.h"

CVolFile::CVolFile()
{
}

~CVolFile::CVolFile()
{
}

bool CVolFile::Init(void)
{
	m_ImageStackInfo.Read()
	m_Header = *pHeader
	m_pcData = new char[m_Header.m_nWidth*m_Header.m_nLength*m_Header.m_nHeight];
	if(!m_pcData)
	{
		qDebug("Not enough memory. Width:%d, Length:%d, Height:%d\n");
		return false;
	}
}

bool CVolFile::Read(quint32 iWidth, quint32 iLength, quint32 iHeight, EZoomOut eLevel)
{
	// get folder name
	
	// read all images
	
	// put images to the m_pcData
	
}

bool CVolFile::Make(void)
{

}