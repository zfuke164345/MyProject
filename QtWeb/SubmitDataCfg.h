#ifndef _SUBMITDATACFG_H_
#define _SUBMITDATACFG_H_
#include <qstring.h>
#include <QMap>

#define  PackageService     QString::fromStdString("PackageService.asmx")
#define	 VersionUpgrade		QString::fromStdString("VersionUpgrade.asmx")


#define  InStallAction		QString::fromStdString("SaveInstallLog")	
#define  DownAppInfo		QString::fromStdString("SaveDownloadManagerLogForQT")
#define  PhoneInfo		    QString::fromStdString("SaveMachineLog")                          
#define  CollectDevice      QString::fromStdString("SaveCollectDevice")						   // 这个走甜椒的			
#define  GetSig				QString::fromStdString("GetitunesData")
#define  GetAppList			QString::fromStdString("GetDownloadInformationList")
#define  GetDriver			QString::fromStdString("GetNewDeviceForC")						  // 这个走甜椒的
#define  DriverInstResult	QString::fromStdString("SaveDeviceInstallLogForQT")
#define	 UpgradeValidate	QString::fromStdString("UpgradeValidate")	

#define	 GetDeviceName		QString::fromStdString("GetMachineInfoForC")					// 这个走甜椒的

static QString Bool2Qstring(bool b)
{
	if (b)
	{
		return "true";
	}
	return "false";
}

//如果以后 接口 有改动 ，只需改该结构，以及其 toMap方法就行

class PhoneInfo4Submit
{
public:
	

		QString		MachineName;
		bool		isRoot;
		QString		Vid;
		QString		Pid;
		int			Statues;

		QString		ErrorMessage;
		QString		Machinemac;
		QString		MachineGuid;
		QString		SystemName;
		bool		IsIOS;

		int			Version;
		int			PratnerCode;
		bool		ActivationState;
		QString		Imei;
		int			Userid;


	QMap<QString,QString> toMap()
	{
		QMap<QString,QString> myMap;

		myMap.insert("MachineName",MachineName);
		myMap.insert("isRoot",Bool2Qstring(isRoot));
		myMap.insert("Vid",Vid);
		myMap.insert("Pid",Pid);
		myMap.insert("Statues",QString::number(Statues));


		myMap.insert("ErrorMessage",ErrorMessage);
		myMap.insert("Machinemac",Machinemac);
		myMap.insert("MachineGuid",MachineGuid);
		myMap.insert("SystemName",SystemName);
		myMap.insert("IsIOS",Bool2Qstring(IsIOS));

		myMap.insert("Version",QString::number(Version));
		myMap.insert("PratnerCode",QString::number(PratnerCode));
		myMap.insert("ActivationState",Bool2Qstring(ActivationState));
		myMap.insert("Imei",Imei);
		myMap.insert("Userid",QString::number(Userid));

		return myMap;
	}
};


class AppInstResult4Submit
{
public:
	
	QString Installname;
	QString Iemi;
	QString RestMessage;
	int		PanterCode;
	int Status;

	QString MachineGuid;
	QString MachineMac;
	QString ErrorMessage;
	int		LocalVersion;		/// 当前内部版本号
	int		AppType;			//	0 apk 1 正版 IPA 2 盗版IPA
	int		Userid;	

	QMap<QString,QString> toMap()
	{
		QMap<QString,QString> myMap;

		myMap.insert("Installname",Installname);
		myMap.insert("Iemi",Iemi);
		myMap.insert("RestMessage",RestMessage);
		myMap.insert("PanterCode",QString::number(PanterCode));
		myMap.insert("Status",QString::number(Status));

		myMap.insert("MachineMac",MachineMac);
		myMap.insert("MachineGuid",MachineGuid);
		myMap.insert("ErrorMessage",ErrorMessage);
		myMap.insert("LocalVersion",QString::number(LocalVersion));
	
		myMap.insert("AppType",QString::number(AppType));
		myMap.insert("Userid",QString::number(Userid));

		return myMap;
	}

};

//对于不需上报的字段 不要出现在 结构里面

class DownloadAPPInfo4Submit
{
public:

	QString	ResourceName;
	QString	ResourcesURL;
	QString	ResourceID;
	int	ResourcesSize;
	int	ResourceType;

	int	ErrorType;
	QString	ErrorResult;
	int	ConnectResponseTime;
	int	AverageDownloadSpeed;
	QString	ProductVersion;

	int	ProductType;
	bool	IsActivation;
	bool	IsRoot;
	QString	MachineGuid;
	int	PartnerCode;

	QString	MachineSystemName;
	int	LocalVersion;
	int	AppType;                //0 apk 1 正版 IPA 2 盗版IPA
	QString	ResourcesSrcURL;
	int	userid;




	QMap<QString,QString> toMap()
	{
		QMap<QString,QString> myMap;
		
		myMap.insert("ResourceName",ResourceName);
		myMap.insert("ResourcesURL",ResourcesURL);
		myMap.insert("ResourceID",ResourceID);
		myMap.insert("ResourcesSize",QString::number(ResourcesSize));
		myMap.insert("ResourceType",QString::number(ResourceType));

		myMap.insert("ErrorType",QString::number(ErrorType));
		myMap.insert("ErrorResult",ErrorResult);
		myMap.insert("ConnectResponseTime",QString::number(ConnectResponseTime));
		myMap.insert("AverageDownloadSpeed",QString::number(AverageDownloadSpeed));
		myMap.insert("ProductVersion",ProductVersion);

		myMap.insert("ProductType",QString::number(ProductType));
		myMap.insert("IsActivation",Bool2Qstring(IsActivation));
		myMap.insert("IsRoot",Bool2Qstring(IsRoot));
		myMap.insert("MachineGuid",MachineGuid);
		myMap.insert("PartnerCode",QString::number(PartnerCode));

		myMap.insert("MachineSystemName",MachineSystemName);
		myMap.insert("LocalVersion",QString::number(LocalVersion));
		myMap.insert("AppType",QString::number(AppType));
		myMap.insert("ResourcesSrcURL",ResourcesSrcURL);
		myMap.insert("userid",QString::number(userid));
		
		return myMap;
	}
};



class CollectDeviceInfo
{
public:

	QString MachineName;
	QString DeviceDesc;
	QString HardwareID;
	QString CompatibleID;
	QString Service;
	QString DeviceNodeState;

	QString Class;
	QString ClassGUID;
	QString Driver;
	QString ConfigFlags;
	QString Mfg;
	QString FriendlyName;

	QString LocationInformatiom;
	QString PhysicalDeviceObjectName;
	QString Capabilites;
	QString UpperFilters;
	QString LowerFilters;
	QString BusTypeGUID;

	QString LegacyBusType;
	QString BusBumber;
	QString EnumeratorName;
	QString SecuritySDS;
	QString DeviceType;
	QString Exclusive;

	QString Characteristics;
	QString Address;
	QString UiNumberDescFormat;
	QString RemovalPolicy;
	QString RemovalPolicyHWDefault;
	QString RemovalPolicyOverride;

	QString InstallState;
	QString LocationPath;
	QString BaseContainerID;
	QString Model;
	int DeviceStatue;
	QString other;

	QString Pid;
	QString Vid;



	QMap<QString,QString> toMap()
	{
		QMap<QString,QString> myMap;

		myMap.insert("MachineName",MachineName);
		myMap.insert("DeviceDesc",DeviceDesc);
		myMap.insert("HardwareID",HardwareID);
		myMap.insert("CompatibleID",CompatibleID);
		myMap.insert("Service",Service);
		myMap.insert("DeviceNodeState",DeviceNodeState);

		myMap.insert("Class",Class);
		myMap.insert("ClassGUID",ClassGUID);
		myMap.insert("Driver",Driver);
		myMap.insert("ConfigFlags",ConfigFlags);
		myMap.insert("Mfg",Mfg);
		myMap.insert("FriendlyName",FriendlyName);

		myMap.insert("LocationInformatiom",LocationInformatiom);
		myMap.insert("PhysicalDeviceObjectName",PhysicalDeviceObjectName);
		myMap.insert("Capabilites",Capabilites);
		myMap.insert("UpperFilters",UpperFilters);
		myMap.insert("LowerFilters",LowerFilters);
		myMap.insert("BusTypeGUID",BusTypeGUID);

		myMap.insert("LegacyBusType",LegacyBusType);
		myMap.insert("BusBumber",BusBumber);
		myMap.insert("EnumeratorName",EnumeratorName);
		myMap.insert("SecuritySDS",SecuritySDS);
		myMap.insert("DeviceType",DeviceType);
		myMap.insert("Exclusive",Exclusive);

		myMap.insert("Characteristics",Characteristics);
		myMap.insert("Address",Address);
		myMap.insert("UiNumberDescFormat",UiNumberDescFormat);
		myMap.insert("RemovalPolicy",RemovalPolicy);
		myMap.insert("RemovalPolicyHWDefault",RemovalPolicyHWDefault);
		myMap.insert("RemovalPolicyOverride",RemovalPolicyOverride);

		myMap.insert("InstallState",InstallState);
		myMap.insert("LocationPath",LocationPath);
		myMap.insert("BaseContainerID",BaseContainerID);
		myMap.insert("Model",Model);
		myMap.insert("DeviceStatue",QString::number(DeviceStatue));
		myMap.insert("other",other);

		myMap.insert("Pid",Pid);
		myMap.insert("Vid",Vid);


		return myMap;
	}

};


//注意 构造此结构时  fiarPlayCer  rq_buffer 都为base64 加密过的
class GetSigParam
{
public: 
	QString udid;

	int deviceTypeValue;
	int supportVersionValue;

	QString fiarPlayCer;
	int fiarPlayCerleng;


	QString rq_buffer;
	int  rq_bufferleng;



	QMap<QString,QString> toMap()
	{
		QMap<QString,QString> myMap;

		myMap.insert("udid",udid);

		myMap.insert("deviceTypeValue",QString::number(deviceTypeValue));
		myMap.insert("supportVersionValue",QString::number(supportVersionValue));

		myMap.insert("fiarPlayCer",fiarPlayCer);
		myMap.insert("fiarPlayCerleng",QString::number(fiarPlayCerleng));

		myMap.insert("rq_buffer",rq_buffer);
		myMap.insert("rq_bufferleng",QString::number(rq_bufferleng));
		
		return myMap;
	}

};

class GetSigReturn
{
public:
	QString rs_array;
	int		rs_array_len;

	QMap<QString,QString> toMap()
	{
		QMap<QString,QString> myMap;

		myMap.insert("rs_array",rs_array);
		myMap.insert("rs_array_len",QString::number(rs_array_len));

		return myMap;

	}
};



class DownloadInfoObject
{
public:
	QString strInfoName;
	QString strDownloadUrl;
	QString strMd5;
	QString strVer;
};


class DownloadInformationList
{
public:
	QVector<DownloadInfoObject> vtDownList;
};



class GetDriverParam
{
public:
	QString pid;
	QString vid; 
	QString desc; 
	QString deviceGUID;
	QString machinetype;

	QMap<QString,QString> toMap()
	{
		QMap<QString,QString> myMap;

		myMap.insert("PID",pid);
		myMap.insert("VID",vid);
		myMap.insert("DeviceDescription",desc);
		myMap.insert("DeviceGuid",deviceGUID);
		myMap.insert("MachineType",machinetype);

		return myMap;

	}

};


class DriverInfo
{
public:
	qlonglong DriverId;
	QString DriverName;
	int DrvierType;
	bool isFastboot;
	bool isDeviceCollect;
	int deviceStatue;
	bool DataType; // true 精确驱动安装， false 普通驱动安装

	QString Url;
	QString MD5;
	QString StartFile;
	int Version;
	void Clear()
	{
		DriverId=-1;
		DriverName="";
		DrvierType=-1;

		Url="";
		MD5="";
		DataType = false;
		StartFile="";

		Version=-1;
		isDeviceCollect = false;
		deviceStatue = 0;
		isFastboot = false;
	};

	bool IsEmpty()
	{
		if (DriverId>=0)
			return false;
		else
			return true;
	};
	bool IsNotSupport()
	{
		if (-2 == DriverId) 
		{
			return true;
		} else {
			return false;
		}
	};
};


class DriverInstallResult
{
public:

	QString	IMEI;
	QString	MachineMac;
	QString	MachineGUID;
	int		LogType;
	int		LogStatus;
	QString	ErrorMessage;
	QString	MachineIP;
	QString	Vid;
	QString	Pid;
	QString	ChildErrorMessage;

	QMap<QString,QString> toMap()
	{
		QMap<QString,QString> myMap;

		myMap.insert("IMEI",IMEI);
		myMap.insert("MachineMac",MachineMac);
		myMap.insert("MachineGUID",MachineGUID);
		myMap.insert("LogType",QString::number(LogType));
		myMap.insert("LogStatus",QString::number(LogStatus));

		myMap.insert("ErrorMessage",ErrorMessage);
		myMap.insert("MachineIP",MachineIP);
		myMap.insert("Vid",Vid);
		myMap.insert("Pid",Pid);
		myMap.insert("ChildErrorMessage",ChildErrorMessage);


		return myMap;
	}
};



class UpgradeParam
{
public:
	int oldversion;
	int PartnerID;
	int TypeID;									//tob 版本 必须传 2

	QMap<QString,QString> toMap()
	{
		QMap<QString,QString> myMap;
		myMap.insert("oldversion",QString::number(oldversion));
		myMap.insert("PartnerID",QString::number(PartnerID));
		myMap.insert("TypeID",QString::number(TypeID));

		return myMap;
	}

};


class UpgradeInfo
{
public:
	QString strDownUrl;
	QString strResult;
	QString strLastVer;
	QString strDesc;
	QString strUpdateDate;
	QString strMd5;
};




//手机原始信息
class MobileInfo
{
public:
	QString Model;
	QString RomVersion;
	QString ModelVersion;
	QString Bootloader;
	QString Basehand;
	QString Carrier;
	QString Displayid;
	QString Device;
	QString Board;
	QString Product;
	QString Hardware;
	QString VID;
	QString PID;
	bool    NeedBoot;


	QMap<QString,QString> toMap()
	{
		QMap<QString,QString> myMap;
		myMap.insert("Model",Model);
		myMap.insert("RomVersion",RomVersion);
		myMap.insert("ModelVersion",ModelVersion);
		
		myMap.insert("Bootloader",Bootloader);
		myMap.insert("Basehand",Basehand);
		myMap.insert("Carrier",Carrier);

		myMap.insert("Displayid",Displayid);
		myMap.insert("Device",Device);
		myMap.insert("Board",Board);

		myMap.insert("Product",Product);
		myMap.insert("Hardware",Hardware);
		myMap.insert("VID",VID);
		myMap.insert("PID",PID);

		myMap.insert("NeedBoot",Bool2Qstring(NeedBoot));

		return myMap;
	}

};



























#endif