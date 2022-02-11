#include "vrmine/vr_httphelper/vr_httphelper.h"
#include "vrmine\vr_core\tinyxml\tinyxml.h"

using namespace VirtualMine::HttpHelper;
using namespace VirtualMine::Core;
VR_HttpHelper::VR_HttpHelper()
{

}

VR_HttpHelper::~VR_HttpHelper()
{

}

CFinishedDownloadEvent::CFinishedDownloadEvent()
	:ref_mpDownloadData(NULL)
{

}
CFinishedDownloadEvent::~CFinishedDownloadEvent()
{

}
void CFinishedDownloadEvent::setDownloadData(QByteArray* pData)
{
	ref_mpDownloadData = pData;
}
QByteArray* CFinishedDownloadEvent::getDownloadData()
{
	return this->ref_mpDownloadData;
}




std::string CCurrentDevice::SimuSensorID("");

std::string CCurrentDevice::SimuSubstationID("");

std::string CCurrentDevice::SwitchSensorID("");

std::string CCurrentDevice::SwitchSubstationID("");

DeviceKind CCurrentDevice::CurrentDeviceType = DeviceKind::DK_UNKNOWN;


// CServerConfigParam::CServerConfigParam()
//{
//
//}
//
// CServerConfigParam::~CServerConfigParam()
//{
//
//}
//
// void CServerConfigParam::parseConfig(TiXmlElement* rootNode)
// {
//	 TiXmlElement* serverConfigElement = rootNode->FirstChildElement("ServerConfig");
//	 TiXmlElement* serverElement = serverConfigElement->FirstChildElement("Server");
//	 for (; serverElement != NULL ; serverElement = serverElement->NextSiblingElement())
//	 {
//		 TiXmlAttribute* attributeOfLayer = serverElement->FirstAttribute(); 
//
//		 for (; attributeOfLayer != NULL ; attributeOfLayer = attributeOfLayer->Next())
//		 {
//			 std::string name = attributeOfLayer->Name();
//			 if (name == "Type")
//			 {
//				 CServerConfigParam::Driver = attributeOfLayer->Value();
//			 }
//			 else if (name == "Server")
//			 {
//				 CServerConfigParam::Server = attributeOfLayer->Value();
//			 }
//			 else if (name == "DataBase")
//			 {
//				 CServerConfigParam::DataBase = attributeOfLayer->Value();
//			 }
//			 else if (name == "User")
//			 {
//				 CServerConfigParam::User = attributeOfLayer->Value();
//			 }
//			 else if (name == "Password")
//			 {
//				 CServerConfigParam::Password = attributeOfLayer->Value();
//			 }
//			 else if (name == "SimuUrl")
//			 {
//				 CServerConfigParam::SimuUrl = attributeOfLayer->Value();
//			 }
//			 else if (name == "SwitchUrl")
//			 {
//				 CServerConfigParam::SwitchUrl = attributeOfLayer->Value();
//			 }
//		 }
//	 }
// }
//
// void CServerConfigParam::saveConfig(TiXmlElement* rootNode)
// {
//	 TiXmlElement* serverConfigNode = new TiXmlElement("ServerConfig");
//
//	 TiXmlElement* serverNode = new TiXmlElement("Server");
//	 serverNode->SetAttribute("Type","SQL SERVER");
//	 serverNode->SetAttribute("Server",CServerConfigParam::Server.c_str());
//	 serverNode->SetAttribute("DataBase",CServerConfigParam::DataBase.c_str());
//	 serverNode->SetAttribute("User",CServerConfigParam::User.c_str());
//	 serverNode->SetAttribute("Password",CServerConfigParam::Password.c_str());
//
//	 serverNode->SetAttribute("SimuUrl",CServerConfigParam::SimuUrl.c_str());
//	 serverNode->SetAttribute("SwitchUrl",CServerConfigParam::SwitchUrl.c_str());
//
//	 serverConfigNode->LinkEndChild(serverNode);	 
//	 rootNode->LinkEndChild(serverConfigNode);  
// }
//
//  std::string CServerConfigParam::Driver("SQL SERVER");
//  std::string CServerConfigParam::Server("192.168.1.208");
//  std::string CServerConfigParam::DataBase("location");
//  std::string CServerConfigParam::User("sa");
//  std::string CServerConfigParam::Password("123");
//
//  std::string CServerConfigParam::SimuUrl("http://localhost:90/realdata/RealSimuXML.xml");
//  std::string CServerConfigParam::SwitchUrl("http://localhost:90/realdata/RealSwitchXML.xml");
//
