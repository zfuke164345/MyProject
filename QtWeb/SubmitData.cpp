#include "SubmitData.h"
#include <QThread>
#include <qapplication.h>
#include "qsettings.h"
#include <QUrl>
#include <QTextCodec>


SubmitData::SubmitData(QObject *parent)
	: QObject(parent)
{
	m_commThread = NULL;
}

SubmitData::~SubmitData()
{
	delete m_commThread;
}


void SubmitData::CommHelp(QMap<QString,QString> data,QString serName,QString action,bool runInThread /*= true*/,bool tianjiao /*= false*/)
{
	if (runInThread)
	{
		m_commThread  = new CommThread(data,serName,action,tianjiao);
		m_commThread->start();
	}
	else
	{
		SubmitData2Web(data,serName,action,tianjiao);
	}
}

// some sunmit function
void SubmitData::SubmitAppInstResult(AppInstResult4Submit instResult,bool runInThread /*= true*/)
{
	QMap<QString,QString> data = instResult.toMap();
	CommHelp(data,PackageService,InStallAction,runInThread);
}

void SubmitData::SubmitPhoneInfo(PhoneInfo4Submit info,bool runInThread/* = true*/)
{
	QMap<QString,QString> data = info.toMap();
	CommHelp(data,PackageService,PhoneInfo,runInThread);
}



void SubmitData::SubmitDownLoadAppInfo(DownloadAPPInfo4Submit appInfo,bool runInThread /* = true */)
{
	QMap<QString,QString> data = appInfo.toMap();
	
	CommHelp(data,PackageService,DownAppInfo,runInThread);
}


//走甜椒的服务
void SubmitData::SubmitCollectDeviceInfo(CollectDeviceInfo info,bool runInThread /* = true */)
{
	QMap<QString,QString> data = info.toMap();

	CommHelp(data,PackageService,CollectDevice,runInThread,true);
}

void SubmitData::SubmitDriverInstallResult(DriverInstallResult dRet,bool runInThread /* = true */)
{
	QMap<QString,QString> data = dRet.toMap();

	CommHelp(data,PackageService,DriverInstResult,runInThread);
}


void SubmitData::CommSendData2Web(QMap<QString,QString> need2SubmtData,QString serverName,QString action,bool tianjiao /*= false*/)
{
	loop = new QEventLoop(this);                                           
	//http = new QHttp(this);        
	http = new QIHttp(this, getHostAddr(tianjiao), getHostPort(tianjiao));     
	connect(http, SIGNAL(done(bool)),this, SLOT(on_http_done(bool)));
	//http->setHost(getHostAddr(),getHostPort());
	//IpaType
	QHttpRequestHeader header("POST", "http://" + getHostAddr(tianjiao) + ":" + QString::number(getHostPort(tianjiao)) + "/" + serverName) ;
	header.setValue("Host", getHostAddr(tianjiao)) ;
	header.setContentType("text/xml");
	QString data;

	data.append("<?xml version=\"1.0\" encoding=\"utf-8\"?>");
	data.append("<soap:Envelope xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\">");
	data.append("<soap:Body>");
	data.append("<" + action + "  xmlns=\"http://tempuri.org/\">");

	data.append("<request>");
	QMapIterator<QString, QString> it(need2SubmtData);
	while (it.hasNext()) 
	{
		it.next();
		data.append("<" + it.key() +">" + it.value() + "</" + it.key() + ">");
	}
	data.append("</request>");

	data.append("</" + action + ">");
	data.append("</soap:Body>");
	data.append("</soap:Envelope>");

	http->request(header, data.toUtf8()) ;
	loop->exec();
}




bool SubmitData::GetSigFromWeb(GetSigParam param,GetSigReturn &sigRet)
{
	QMap<QString,QString> sendData = param.toMap();
	CommSendData2Web(sendData,PackageService,GetSig); 	
	
	QTextCodec *tc = QTextCodec::codecForName("UTF-8");
	QByteArray ba = http->readAll();
	QString str = tc->toUnicode(ba);

	QDomDocument document; 
	if (!document.setContent(str))
	{
		return false;//itunesdata;
	}
	QDomElement root = document.documentElement();
	QDomNodeList nodes = root.elementsByTagName("GetitunesDataResult");

	sigRet.rs_array  = nodes.at(0).toElement().elementsByTagName("rs_array").at(0).toElement().text().toLatin1();
	sigRet.rs_array_len = (nodes.at(0).toElement().elementsByTagName("rs_array_len").at(0).toElement().text().toUInt());

	if (sigRet.rs_array.isEmpty() || sigRet.rs_array_len == 0)
	{
		return false;
	}

	return true;

}

DownloadInformationList SubmitData::GetDownloadInformationList(int type)
{
	QMap<QString,QString> intMap;
	intMap.insert("TypeID",QString::number(type));

	CommSendData2Web(intMap,PackageService,GetAppList);


	DownloadInformationList info;

	QTextCodec *tc = QTextCodec::codecForName("UTF-8");
	QByteArray ba = http->readAll();
	QString str = tc->toUnicode(ba);
	if (http!=NULL)
		delete http;
	if (loop!=NULL)
		delete loop;
	QDomDocument document; 
	if (!document.setContent(str))
	{
		return info;  
	} 

	QDomElement root = document.documentElement();
	QDomNodeList nodes = root.elementsByTagName("DownloadInforData");
	for(int i = 0; i < nodes.count(); i ++)
	{
		DownloadInfoObject objDown;

		objDown.strDownloadUrl = nodes.at(i).toElement().elementsByTagName("DownloadUrl").at(0).toElement().text();
		objDown.strMd5 = nodes.at(i).toElement().elementsByTagName("Md5").at(0).toElement().text();
		objDown.strInfoName = nodes.at(i).toElement().elementsByTagName("InformationName").at(0).toElement().text();
		objDown.strVer = nodes.at(i).toElement().elementsByTagName("Version").at(0).toElement().text();
		info.vtDownList.push_back(objDown);
	}

	return info;

}


// 和甜椒的服务通讯
bool SubmitData::GetDriverInfoFromWeb(GetDriverParam param,DriverInfo &driver)
{
	QMap<QString,QString> sendData = param.toMap();

	CommSendData2Web(sendData,PackageService,GetDriver,true);

	QTextCodec *tc = QTextCodec::codecForName("UTF-8");
	QByteArray ba = http->readAll();
	QString str = tc->toUnicode(ba);

	if (http!=NULL)
		delete http;
	if (loop!=NULL)
		delete loop;
	QDomDocument document; 
	if (!document.setContent(str))
	{
		driver.Clear();
		return false;  
	}  
	QDomElement root = document.documentElement();  

	QString isSuccess=getXmlValue(root,"IsSuccess");
	if (isSuccess=="") 
	{
		driver.Clear();
		qDebug() << "network report infomation error\n\n";
		return false;
	}
	else if (isSuccess.toLower()=="false")
	{
		driver.Clear();
		driver.DriverId = -2;
		qDebug() << "backstage not set driver\n\n";
		return false;
	}
	QString deviceId=getXmlValue(root,"DeviceID");
	driver.DriverId=deviceId.toLongLong();
	driver.Url=getXmlValue(root,"Url");
	driver.MD5=getXmlValue(root,"MD5");
	QString tmpDeviceType=getXmlValue(root,"DeviceType");

	if (tmpDeviceType=="INI")
		driver.DrvierType=1;
	else
		driver.DrvierType=2;

	driver.DriverName=getXmlValue(root,"MachineName");
	driver.StartFile=getXmlValue(root,"StartFile");
	driver.Version=getXmlValue(root,"Version").toInt();
	QString s= getXmlValue(root, "IsDeviceCollect");
	driver.isDeviceCollect= s == "true" ? true : false;
	driver.deviceStatue = getXmlValue(root, "DeviceStatue").toInt();
	QString strType = getXmlValue(root, "DataType");
	bool deviceType = strType == "true" ? true : false;
	if (deviceType) 
	{
		qDebug() << "exact driver recognition\n\n";
	}
	else 
	{
		qDebug() << "general driver recognition\n\n";
	}
	driver.DataType = deviceType;

	return true;
}

UpgradeInfo SubmitData::GetUpgradeInfoFromWeb(UpgradeParam param)
{
	QMap<QString,QString> sendData = param.toMap();

	CommSendData2Web(sendData,VersionUpgrade,UpgradeValidate);
	

	UpgradeInfo info;  
	QTextCodec *tc = QTextCodec::codecForName("UTF-8");
	QByteArray ba = http->readAll();
	QString str = tc->toUnicode(ba);
	if (http!=NULL)
		delete http;
	if (loop!=NULL)
		delete loop;
	QDomDocument document; 
	if (!document.setContent(str))
	{
		return info;  
	} 

	QDomElement root = document.documentElement();
	info.strResult = getXmlValue(root,"ResponseCode");
	info.strLastVer = getXmlValue(root,"Version");
	info.strDesc = getXmlValue(root,"Description");
	info.strUpdateDate = getXmlValue(root,"UpdateTime");
	info.strDownUrl = getXmlValue(root,"Url");
	info.strMd5 = getXmlValue(root,"MD5");
	return info;

}




bool SubmitData::SubmitData2Web(QMap<QString,QString> need2SubmtData,QString serverName, QString action,bool tianjiao /*= false*/)
{

	CommSendData2Web(need2SubmtData,serverName,action,tianjiao);
	QHttp::Error err = http->error();
	QByteArray ba = http->readAll();
	QTextCodec *tc = QTextCodec::codecForName("UTF-8");
	QString str = tc->toUnicode(ba);

	qDebug()<< str;
	if (0 == ba.size())///取到内容为空，表示上报失败
	{		
		//DocumentManager::WriteFileContent(DocumentManager::GetTempPath() + "\\SaveIPAInstallLog.txt", data.toUtf8());
		qDebug()<< "!!!!!!!| SaveIPAInstallLog Fail";
	}	
	if (http!=NULL)
		delete http;
	if (loop!=NULL)
		delete loop;
	return (err == QHttp::NoError)?(true):(false);

}



void SubmitData::on_http_done(bool error)
{
	loop->exit();    
}


QString SubmitData::transformXmlValue(QString XmlValue)
{
	//return Qt::escape(XmlValue);/// 这个接口会对 &、"、<、>进行转义，我们暂时不需要转"
	XmlValue.replace("&","&amp;");
	XmlValue.replace("<","&lt;");
	XmlValue.replace(">","&gt;");
	XmlValue.replace("+","%2b");
	//XmlValue.replace(" ","&nbsp;");
	//XmlValue.replace("\"","&quot;");	
	return XmlValue;
}


QString SubmitData::decodeXmlValue(QString XmlValue, bool isXmlData/*如果已经是xml格式的数据，则不能用transformXmlValue进行转义了*/)
{
	if (isXmlData)
	{
		return QUrl::fromEncoded(XmlValue.toUtf8()).toEncoded();
	}
	else
	{
		return transformXmlValue(QUrl::fromEncoded(XmlValue.toUtf8()).toEncoded()); 
	}
}


QString SubmitData::getXmlValue(QDomElement ele,QString name)
{
	QDomNodeList nodes=ele.elementsByTagName(name);
	if (nodes.count() >0 )
	{
		return nodes.at(0).toElement().text();
	}
	else
	{
		return "";
	}
}

//配置内网需要2个 INI 文件
QString SubmitData::getHostAddr(bool tianjiao /*= false*/)
{
	static QString host = "";

	QString strPath = QApplication::applicationDirPath();
	if (tianjiao)
	{
		strPath +=  "/config2.ini";
	}
	else
	{
		strPath +=  "/config.ini";
	}
	QSettings settings(strPath, QSettings::IniFormat);
	host = settings.value("app/host").toString();

	if ("" == host)
	{
		if (tianjiao)
		{
			host = "webserver.onekeyrom.com";
		}
		else
		{
			host = "webapple.onekeyrom.com";
		}
	}

	return host;
	
}

int SubmitData::getHostPort(bool tianjiao /*= false*/)
{
	static int port = 0;

	QString strPath = QApplication::applicationDirPath();
	if (tianjiao)
	{
		strPath += "/config2.ini";
	}
	else
	{
		strPath += "/config.ini";
	}
	QSettings settings(strPath, QSettings::IniFormat);
	port = settings.value("app/port").toInt();
	if (0 == port)
	{
		port = 80;
	}

	return port;

}


QString SubmitData::GetAndroidDeviceName(MobileInfo nInfo)
{
	QMap<QString,QString> sendData = nInfo.toMap();

	CommSendData2Web(sendData,PackageService,GetDeviceName,true);


	QTextCodec *tc = QTextCodec::codecForName("UTF-8");
	QByteArray ba = http->readAll();
	QString str = tc->toUnicode(ba);
	if (http!=NULL)
		delete http;
	if (loop!=NULL)
		delete loop;
	QDomDocument document; 
	if (!document.setContent(str))
	{
	
		return "";  
	}  
	QDomElement root = document.documentElement();  
	bool bNotNeedLoad = false;
	QString isSuccess=getXmlValue(root,"IsSuccess");	
// 	if (isSuccess.toLower()=="false")
// 	{
// 		
// 		bNotNeedLoad = true;
// 	}
// 	else if (isSuccess=="")
// 	{
// 		machine.Clear();
// 		bNotNeedLoad = true;
// 	}
	
	
	QString name =getXmlValue(root,"ShowName");
	

	return name;
}