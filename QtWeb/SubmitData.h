#ifndef SUBMITTEDATA_H
#define SUBMITTEDATA_H

#include <QObject>
#include "qihttp.h"
#include <QEventLoop>
#include <qdom.h>
#include <QDebug>


#include "SubmitDataCfg.h"
#include "CommThread.h"


class SubmitData : public QObject
{
	Q_OBJECT

public:
	SubmitData(QObject *parent);
	~SubmitData();

	// ���� runInThread ���� �ú���Ҫ��Ҫ�����̣߳�Ĭ��Ϊtrue ����Ҫ�����߳� 

	/************************************************************************/
	/* ��������ύӦ�ó���װ���                                                                     */
	/************************************************************************/
	void						SubmitAppInstResult(AppInstResult4Submit instResult,bool runInThread = true);

	/************************************************************************/
	/*  ��������ύ �ֻ���Ϣ                                                                    */
	/************************************************************************/

	void						SubmitPhoneInfo(PhoneInfo4Submit info,bool runInThread = true);
	
	/************************************************************************/
	/* ��������ύ Ӧ�ó������ؽ��                                                                     */
	/************************************************************************/

	void						SubmitDownLoadAppInfo(DownloadAPPInfo4Submit appInfo,bool runInThread = true);

	/************************************************************************/
	/* ��������ύ �ռ����ֻ�(anroid)��Ϣ                                                                     */
	/************************************************************************/

	void						SubmitCollectDeviceInfo(CollectDeviceInfo info,bool runInThread = true);		//������𽷵ķ���

	/************************************************************************/
	/* ��������ύ �ֻ�������װ���(android)                                                                     */
	/************************************************************************/

	void						SubmitDriverInstallResult(DriverInstallResult dRet ,bool runInThread = true);

	//���º��� �ӷ�������ȡ ��Ϣ


	QString						GetAndroidDeviceName(MobileInfo nInfo);

	/************************************************************************/
	/* ��ȡ ��Ȩ                                                                     */
	/************************************************************************/

	bool						GetSigFromWeb(GetSigParam param, GetSigReturn &sigRet);

	/************************************************************************/
	/* ��ȡӦ�ó����б�                                                                     */
	/************************************************************************/

	DownloadInformationList		GetDownloadInformationList(int type);		

	/************************************************************************/
	/* ��ȡ �ֻ�������Ϣ(android)                                                                     */
	/************************************************************************/

	bool						GetDriverInfoFromWeb(GetDriverParam param,DriverInfo &info);				 //������𽷵ķ��� 


	/************************************************************************/
	/* ��ȡ������Ϣ                                                                     */
	/************************************************************************/
	UpgradeInfo					GetUpgradeInfoFromWeb(UpgradeParam param);
	



	bool						SubmitData2Web(QMap<QString,QString> need2SubmtData,QString serverName,QString action,bool tianjiao = false);

private:

	void						CommSendData2Web(QMap<QString,QString> need2SubmtData,QString serverName,QString action,bool tianjiao = false);
	
	void						CommHelp(QMap<QString,QString> data,QString serName,QString action,bool runInThread = true,bool tianjiao = false); 

	
	
	QString						getHostAddr(bool tianjiao = false);
	int							getHostPort(bool tianjiao = false);
	QString						getXmlValue(QDomElement,QString);
	QString						transformXmlValue(QString);	
	QString						decodeXmlValue(QString XmlValue, bool isXmlData=false);

private slots:
	void						on_http_done(bool error);
	


private:
	CommThread*					m_commThread;
	QIHttp*						http;
	QEventLoop*					loop;
};

#endif // SUBMITTEDATA_H
