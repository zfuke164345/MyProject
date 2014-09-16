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

	// 参数 runInThread 决定 该函数要不要启动线程，默认为true 代表要启动线程 

	/************************************************************************/
	/* 向服务器提交应用程序安装结果                                                                     */
	/************************************************************************/
	void						SubmitAppInstResult(AppInstResult4Submit instResult,bool runInThread = true);

	/************************************************************************/
	/*  向服务器提交 手机信息                                                                    */
	/************************************************************************/

	void						SubmitPhoneInfo(PhoneInfo4Submit info,bool runInThread = true);
	
	/************************************************************************/
	/* 向服务器提交 应用程序下载结果                                                                     */
	/************************************************************************/

	void						SubmitDownLoadAppInfo(DownloadAPPInfo4Submit appInfo,bool runInThread = true);

	/************************************************************************/
	/* 向服务器提交 收集的手机(anroid)信息                                                                     */
	/************************************************************************/

	void						SubmitCollectDeviceInfo(CollectDeviceInfo info,bool runInThread = true);		//这个走甜椒的服务

	/************************************************************************/
	/* 向服务器提交 手机驱动安装结果(android)                                                                     */
	/************************************************************************/

	void						SubmitDriverInstallResult(DriverInstallResult dRet ,bool runInThread = true);

	//以下函数 从服务器获取 信息


	QString						GetAndroidDeviceName(MobileInfo nInfo);

	/************************************************************************/
	/* 获取 授权                                                                     */
	/************************************************************************/

	bool						GetSigFromWeb(GetSigParam param, GetSigReturn &sigRet);

	/************************************************************************/
	/* 获取应用程序列表                                                                     */
	/************************************************************************/

	DownloadInformationList		GetDownloadInformationList(int type);		

	/************************************************************************/
	/* 获取 手机驱动信息(android)                                                                     */
	/************************************************************************/

	bool						GetDriverInfoFromWeb(GetDriverParam param,DriverInfo &info);				 //这个走甜椒的服务 


	/************************************************************************/
	/* 获取升级信息                                                                     */
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
