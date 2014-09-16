
#include <QtCore/QCoreApplication>
#include "SubmitData.h"


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	
	SubmitData sd(NULL);

	//test 1
	AppInstResult4Submit ars;
	ars.MachineGuid = "1233445666";
	ars.AppType = 1;
// 	for (int i = 0;i<11;++i)
// 	{
// 		sd.SubmitAppInstResult(ars);
// 		qDebug()<<i;
// 	}
// 	sd.SubmitAppInstResult(ars);
// 	sd.SubmitAppInstResult(ars);
// 	
// 	int i = 0;
	//test2

	//CollectDeviceInfo cdi;
	//
	//cdi.MachineName = "aaaaaaaaaaaa";
	//cdi.DeviceDesc = "aaaaaaaaaaaa";
	//cdi.HardwareID = "aaaaaaaaaaaa";
	//cdi.CompatibleID = "aaaaaaaaaaaa";
	//cdi.Service = "aaaaaaaaaaaa";
	//cdi.DeviceNodeState = "aaaaaaaaaaaa";//test3

	//cdi.Class = "aaaaaaaaaaaa";
	//cdi.ClassGUID = "aaaaaaaaaaaa";
	//cdi.Driver = "aaaaaaaaaaaa";
	//cdi.ConfigFlags = "aaaaaaaaaaaa";//test4
	//cdi.Mfg = "aaaaaaaaaaaa";
	//cdi.FriendlyName = "aaaaaaaaaaaa";
	//cdi.LocationInformatiom = "aaaaaaaaaaaa";
	//cdi.PhysicalDeviceObjectName = "aaaaaaaaaaaa";//test5
	//cdi.Capabilites = "aaaaaaaaaaaa";
	//cdi.UpperFilters = "aaaaaaaaaaaa";
	//cdi.LowerFilters = "aaaaaaaaaaaa";
	//cdi.BusTypeGUID = "aaaaaaaaaaaa";

	//cdi.LegacyBusType = "aaaaaaaaaaaa";
	//cdi.BusBumber = "aaaaaaaaaaaa";
	//cdi. EnumeratorName = "aaaaaaaaaaaa";
	//cdi.SecuritySDS = "aaaaaaaaaaaa";
	//cdi.DeviceType = "aaaaaaaaaaaa";
	//cdi.Exclusive = "aaaaaaaaaaaa";

	//cdi.Characteristics = "aaaaaaaaaaaa";
	//cdi.Address = "aaaaaaaaaaaa";
	//cdi.UiNumberDescFormat = "aaaaaaaaaaaa";
	//cdi.RemovalPolicy = "aaaaaaaaaaaa";
	//cdi.RemovalPolicyHWDefault = "aaaaaaaaaaaa";
	//cdi.RemovalPolicyOverride = "aaaaaaaaaaaa";

	//cdi.InstallState = "aaaaaaaaaaaa";
	//cdi.LocationPath = "aaaaaaaaaaaa";
	//cdi.BaseContainerID = "aaaaaaaaaaaa";
	//cdi.Model = "aaaaaaaaaaaa";
	//cdi.DeviceStatue = 11;
	//cdi.other = "aaaaaaaaaaaa";

	//cdi.Pid = "0432";
	//cdi.Vid = "0BB4";

	//sd.SubmitCollectDeviceInfo(cdi,false);



	////test3

	//DownloadAPPInfo4Submit das;
	//sd.SubmitDownLoadAppInfo(das,false);


	////test4

	//DriverInstallResult dir;	
	//dir.IMEI =  "11111";
	//dir.MachineMac = "11111";
	//dir.MachineGUID = "11111";
	//dir.LogType = 11;
	//dir.LogStatus = 11;
	//dir.ErrorMessage = "11111";
	//dir.MachineIP = "11111";
	//dir.Vid = "11111";
	//dir.Pid = "11111";
	//dir.ChildErrorMessage = "11111";

	//sd.SubmitDriverInstallResult(dir,false);

	////test5

	//PhoneInfo4Submit pis;

	//pis.MachineName = "222222";
	//pis.isRoot = false;
	//pis.Vid ="222222";
	//pis.Pid = "222222";
	//pis.Statues =2;

	//pis.ErrorMessage = "222222";
	//pis.Machinemac ="222222";
	//pis.MachineGuid ="222222";
	//pis.SystemName ="222222";
	//pis.IsIOS =true;

	//pis.Version = 333;
	//pis.PratnerCode = 23;
	//pis.ActivationState =false;
	//pis.Imei ="222222";
	//pis.Userid = 1235;

	//sd.SubmitPhoneInfo(pis,false);

	////test upgrate
	//UpgradeParam param;
	//param.oldversion = 110;
	//param.PartnerID = 400000;
	//param.TypeID = 2;

	//UpgradeInfo info = sd.GetUpgradeInfoFromWeb(param);



	MobileInfo minfo;
	minfo.Model = "GT-I9100G";
	minfo.Device = "GT-I9100G";

	QString name = sd.GetAndroidDeviceName(minfo);

	return a.exec();
}