#include "CommThread.h"
#include "SubmitData.h"

CommThread::CommThread(QObject *parent)
	: QThread(parent)
{
	
}

CommThread::CommThread(QMap<QString,QString> mapData,QString serName,QString action,bool tianjiao)
	: QThread()
{
	m_action = action;
	m_mapData = mapData;
	m_serName = serName;
	m_tianjiao = tianjiao;
}


CommThread::~CommThread()
{

}


void CommThread::run()
{
	SubmitData sd(NULL);
	sd.SubmitData2Web(m_mapData,m_serName,m_action,m_tianjiao);

}