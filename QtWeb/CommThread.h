#ifndef COMMTHREAD_H
#define COMMTHREAD_H

#include <QThread>
#include <QMap>
#include <QString>

class CommThread : public QThread
{
	Q_OBJECT

public:
	CommThread(QObject *parent);
	CommThread(QMap<QString,QString>,QString,QString,bool);
	~CommThread();

private:

	void run();

	QMap<QString,QString>			m_mapData;
	QString							m_action;
	QString							m_serName;
	bool							m_tianjiao;// 是否走甜椒服务器
};

#endif // COMMTHREAD_H
