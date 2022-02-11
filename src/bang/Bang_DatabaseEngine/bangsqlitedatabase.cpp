#include "bang/bangsqlitedatabase.h"


using namespace VirtualMine::Database;
using namespace std;

VirtualMine::Bang_Database::CBangSqliteDatabase::CBangSqliteDatabase(VirtualMine::Database::IDataSourceInfo* pDataSourceInfo)
	:CSQLiteDatabase(pDataSourceInfo)
{

}

VirtualMine::Bang_Database::CBangSqliteDatabase::~CBangSqliteDatabase()
{

}


#if 1
/////////爆破系统
int VirtualMine::Bang_Database::CBangSqliteDatabase::createLanewSectionDataset(const std::string& tableName)
{
	char **results = NULL; 
	int rc(0);
	string name = "create table " + tableName + "(ProjectID integer, Name nvarchar(128),Type nvarchar(128),Parameter1 real, Parameter2 real,Parameter3 real,Parameter4 real,Parameter5 real)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );
	return rc;
}
int VirtualMine::Bang_Database::CBangSqliteDatabase::createShotHoleDataset(const std::string& tableName)
{
	char **results = NULL; 
	int rc(0);
	string name = "create table " + tableName + "(ProjectID integer,HoleID integer,Type nvarchar(128),PositionX real,PositionY real,PositionZ real,EndPositionX real,EndPositionY real,EndPositionZ real,BangOrder integer,ZhuangyaoLength real,ShuipaoniLength real,FengniLength real,ShotHoleDepth real,ShotHoleInterLength real,SmallResistLine real)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );
	return rc;

}
int VirtualMine::Bang_Database::CBangSqliteDatabase::createProjectFileDataset(const std::string& tableName)
{
	char **results = NULL; 
	int rc(0);
	string name = "create table " + tableName + "(ProjectID integer primary key,Name nvarchar(128), Type nvarchar(128),Manager nvarchar(128),ProjectPeriod nvarchar(128),StartTime nvarchar(128),DesignerOrginazation nvarchar(128),Designer nvarchar(128),LanewaySectionType nvarchar(128))";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );
	return rc;
}
int VirtualMine::Bang_Database::CBangSqliteDatabase::createEsacpeRouteDataset( const std::string& tableName )
{
	char **results = NULL; 
	int rc(0);
	std::string name = "create table " + tableName + "(ProjectID integer,PointID integer,PositionX real,PositionY real,PositionZ real)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );
	return rc;
}

int VirtualMine::Bang_Database::CBangSqliteDatabase::insertLanewaySectionFeatureToLanewaySectionDataset( VirtualMine::Database::IFeature* feature,std::string datasetName)
{
	if (!feature)
	{
		return -2;
	}
	VirtualMine::Bang_Database::CLanewaySectionFeature* pLanewaysectionfeature = dynamic_cast<VirtualMine::Bang_Database::CLanewaySectionFeature*>(feature);
	char **results = NULL;  
	int rc(1);

	int id = pLanewaysectionfeature->getFieldID();
	std::string name = pLanewaysectionfeature->getFieldName();
	std::string type = pLanewaysectionfeature->getFieldType();

	float para1 = pLanewaysectionfeature->getFieldParameter1();
	float para2 = pLanewaysectionfeature->getFieldParameter2();
	float para3 = pLanewaysectionfeature->getFieldParameter3();
	float para4 = pLanewaysectionfeature->getFieldParameter4();
	float para5 = pLanewaysectionfeature->getFieldParameter5();

	double parameter1(para1);
	double parameter2(para2);
	double parameter3(para3);
	double parameter4(para4);
	double parameter5(para5);

	sqlite3_stmt * stat;  
	string nametmp = "insert into " + datasetName + "(ProjectID,Name,Type,Parameter1,Parameter2,Parameter3,Parameter4,Parameter5) values(?,?,?,?,?,?,?,?)";
	sqlite3_prepare_v2(mpDB,G2U(nametmp.c_str()), -1,&stat,0);

	sqlite3_bind_int(stat,1,id);
	sqlite3_bind_text(stat,2,name.c_str(),strlen(name.c_str()),SQLITE_STATIC);
	sqlite3_bind_text(stat,3,type.c_str(),strlen(type.c_str()),SQLITE_STATIC);

	sqlite3_bind_double(stat,4,parameter1);
	sqlite3_bind_double(stat,5,parameter2);
	sqlite3_bind_double(stat,6,parameter3);
	sqlite3_bind_double(stat,7,parameter4);
	sqlite3_bind_double(stat,8,parameter5);

	rc = sqlite3_step(stat);  

	sqlite3_finalize(stat);

	return rc;
}
int VirtualMine::Bang_Database::CBangSqliteDatabase::insertShotHoleFeatureToShotHoleDataset( VirtualMine::Database::IFeature* feature,std::string datasetName)
{
	VirtualMine::Bang_Database::CShotHoleFeature* pshotholefeature = dynamic_cast<VirtualMine::Bang_Database::CShotHoleFeature*>(feature);
	char **results = NULL;  
	int rc(1);

	int porjectID = pshotholefeature->getFieldProjectID();
	int HoleID = pshotholefeature->getFieldHoleID();
	std::string type = pshotholefeature->getFieldType();
	double startPosX = pshotholefeature->getFieldPositionX();
	double startPosY = pshotholefeature->getFieldPositionY();
	double startPosZ = pshotholefeature->getFieldPositionZ();
	double endPosX = pshotholefeature->getFieldPositionEndX();
	double endPosY = pshotholefeature->getFieldPositionEndY();
	double endPosZ = pshotholefeature->getFieldPositionEndZ();
	int bangOrder = pshotholefeature->getFieldBangOrder();
	double zhuangyaolength = pshotholefeature->getFieldZhuangyaoLength();
	double shuipaonilength = pshotholefeature->getFieldShuipaoniLength();
	double fengnilength = pshotholefeature->getFieldFengniLength();
	double shotholedepth = pshotholefeature->getFieldShotHoleDepth();
	double shotholeinterlength = pshotholefeature->getFieldShotHoleInterLength();
	double shotholesmallline = pshotholefeature->getFieldSmallResistLine();


	sqlite3_stmt* stat;  
	string nametmp ="insert into " + datasetName + "(ProjectID,HoleID,Type,PositionX,PositionY,PositionZ,EndPositionX,EndPositionY,EndPositionZ,BangOrder,ZhuangyaoLength,ShuipaoniLength,FengniLength,ShotHoleDepth,ShotHoleInterLength,SmallResistLine) values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
	sqlite3_prepare_v2(mpDB,G2U(nametmp.c_str()), -1,&stat,0);

	sqlite3_bind_int(stat,1,porjectID);
	sqlite3_bind_int(stat,2,HoleID);
	sqlite3_bind_text(stat,3,type.c_str(),strlen(type.c_str()),SQLITE_STATIC);
	sqlite3_bind_double(stat,4,startPosX);
	sqlite3_bind_double(stat,5,startPosY);
	sqlite3_bind_double(stat,6,startPosZ);
	sqlite3_bind_double(stat,7,endPosX);
	sqlite3_bind_double(stat,8,endPosY);
	sqlite3_bind_double(stat,9,endPosZ);
	sqlite3_bind_int(stat,10,bangOrder);
	sqlite3_bind_double(stat,11,zhuangyaolength);
	sqlite3_bind_double(stat,12,shuipaonilength);
	sqlite3_bind_double(stat,13,fengnilength);
	sqlite3_bind_double(stat,14,shotholedepth);
	sqlite3_bind_double(stat,15,shotholeinterlength);
	sqlite3_bind_double(stat,16,shotholesmallline);

	rc = sqlite3_step(stat);  

	sqlite3_finalize(stat);

	return rc;
}

int VirtualMine::Bang_Database::CBangSqliteDatabase::insertProjectFileFeatureToProjectFileDataset( VirtualMine::Database::IFeature* feature,std::string datasetName)
{
	VirtualMine::Bang_Database::CProjectFileFeature* pProjectfeature = dynamic_cast<VirtualMine::Bang_Database::CProjectFileFeature*>(feature);
	char **results = NULL;  
	int rc(1);

	int porjectID = pProjectfeature->getFieldID();
	std::string projectName = pProjectfeature->getFieldName();
	std::string projectType = pProjectfeature->getFieldType();
	std::string manager = pProjectfeature->getFieldManager();
	std::string projectPeriod = pProjectfeature->getFieldProjectPeriod();
	std::string startTime = pProjectfeature->getFieldStartTime();
	std::string designerOrginazation = pProjectfeature->getFieldDesignerOrginazation();
	std::string designer = pProjectfeature->getFieldDesigner();
	std::string lanewaysectiontype = pProjectfeature->getFieldLanewaySectionType();

	sqlite3_stmt* stat;  
	string nametmp = "insert into " + datasetName + "(ProjectID,Name,Type,Manager,ProjectPeriod,StartTime,DesignerOrginazation,Designer,LanewaySectionType) values(?,?,?,?,?,?,?,?,?)";
	sqlite3_prepare_v2(mpDB,G2U(nametmp.c_str()), -1,&stat,0);

	sqlite3_bind_int(stat,1,porjectID);
	sqlite3_bind_text(stat,2,projectName.c_str(),strlen(projectName.c_str()),SQLITE_STATIC);
	sqlite3_bind_text(stat,3,projectType.c_str(),strlen(projectType.c_str()),SQLITE_STATIC);
	sqlite3_bind_text(stat,4,manager.c_str(),strlen(manager.c_str()),SQLITE_STATIC);
	sqlite3_bind_text(stat,5,projectPeriod.c_str(),strlen(projectPeriod.c_str()),SQLITE_STATIC);
	sqlite3_bind_text(stat,6,startTime.c_str(),strlen(startTime.c_str()),SQLITE_STATIC);
	sqlite3_bind_text(stat,7,designerOrginazation.c_str(),strlen(designerOrginazation.c_str()),SQLITE_STATIC);
	sqlite3_bind_text(stat,8,designer.c_str(),strlen(designer.c_str()),SQLITE_STATIC);
	sqlite3_bind_text(stat,9,lanewaysectiontype.c_str(),strlen(lanewaysectiontype.c_str()),SQLITE_STATIC);


	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;
}

int VirtualMine::Bang_Database::CBangSqliteDatabase::insertEscapeRouteFeatureToEscapeRouteDataset( VirtualMine::Database::IFeature* feature,std::string datasetName )
{
	VirtualMine::Bang_Database::CEscapeRouteFeature* proutefeature = dynamic_cast<VirtualMine::Bang_Database::CEscapeRouteFeature*>(feature);
	char **results = NULL;  
	int rc(1);

	int porjectID = proutefeature->getFieldProjectID();
	int pointID = proutefeature->getFieldPointID();
	double startPosX = proutefeature->getFieldPositionX();
	double startPosY = proutefeature->getFieldPositionY();
	double startPosZ = proutefeature->getFieldPositionZ();


	sqlite3_stmt* stat;  
	std::string nametmp = "insert into " + datasetName + "(ProjectID,PointID,PositionX,PositionY,PositionZ) values(?,?,?,?,?)";
	sqlite3_prepare_v2(mpDB,nametmp.c_str(), -1,&stat,0);

	sqlite3_bind_int(stat,1,porjectID);
	sqlite3_bind_int(stat,2,pointID);
	sqlite3_bind_double(stat,3,startPosX);
	sqlite3_bind_double(stat,4,startPosY);
	sqlite3_bind_double(stat,5,startPosZ);

	rc = sqlite3_step(stat);  
	sqlite3_finalize(stat);

	return rc;
}

//kk施工进度ConProgress
int VirtualMine::Bang_Database::CBangSqliteDatabase::insertConProgressFeatureToConProgressDataset( VirtualMine::Database::IFeature* feature,std::string datasetName )
{
	VirtualMine::Bang_Database::CConProgressFeature* pprogressfeature = dynamic_cast<VirtualMine::Bang_Database::CConProgressFeature*>(feature);
	char **results = NULL;  
	int rc(1);

	int porjectID = pprogressfeature->getFieldProjectID();
	int pointID = pprogressfeature->getFieldPointID();
	double startPosX = pprogressfeature->getFieldPositionX();
	double startPosY = pprogressfeature->getFieldPositionY();
	double startPosZ = pprogressfeature->getFieldPositionZ();


	sqlite3_stmt* stat;  
	std::string nametmp = "insert into " + datasetName + "(ProjectID,PointID,PositionX,PositionY,PositionZ) values(?,?,?,?,?)";
	sqlite3_prepare_v2(mpDB,nametmp.c_str(), -1,&stat,0);

	sqlite3_bind_int(stat,1,porjectID);
	sqlite3_bind_int(stat,2,pointID);
	sqlite3_bind_double(stat,3,startPosX);
	sqlite3_bind_double(stat,4,startPosY);
	sqlite3_bind_double(stat,5,startPosZ);

	rc = sqlite3_step(stat);  
	sqlite3_finalize(stat);

	return rc;
}

///查询数据
VirtualMine::Bang_Database::CLanewaySectionDataset*  VirtualMine::Bang_Database::CBangSqliteDatabase::queryLanewaySectionDataset(const std::string& datesetName)
{

	VirtualMine::Bang_Database::CLanewaySectionDataset* dataset = new VirtualMine::Bang_Database::CLanewaySectionDataset();

	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);
		char* type = (char*)sqlite3_column_text(stat,2);
		double parameter1 = sqlite3_column_double(stat,3);
		double parameter2 = sqlite3_column_double(stat,4);
		double parameter3 = sqlite3_column_double(stat,5);
		double parameter4 = sqlite3_column_double(stat,6);
		double parameter5 = sqlite3_column_double(stat,7);

		VirtualMine::Bang_Database::CLanewaySectionFeature* feature = new VirtualMine::Bang_Database::CLanewaySectionFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		feature->setFieldType(type);
		feature->setFieldParameter1(parameter1);
		feature->setFieldParameter2(parameter2);
		feature->setFieldParameter3(parameter3);
		feature->setFieldParameter4(parameter4);
		feature->setFieldParameter5(parameter5);

		dataset->addFeature(feature);

	}
	sqlite3_finalize(stat);

	dataset->setName(datesetName);
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_POLYGON); /////
	return dataset;

}	
VirtualMine::Bang_Database::CLanewaySectionFeature*  VirtualMine::Bang_Database::CBangSqliteDatabase::queryLanewaySectionDataset(const std::string& datesetName,const int& peojectID ,const std::string& featureName)
{
	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);
		char* type = (char*)sqlite3_column_text(stat,2);
		double parameter1 = sqlite3_column_double(stat,3);
		double parameter2 = sqlite3_column_double(stat,4);
		double parameter3 = sqlite3_column_double(stat,5);
		double parameter4 = sqlite3_column_double(stat,6);
		double parameter5 = sqlite3_column_double(stat,7);

		VirtualMine::Bang_Database::CLanewaySectionFeature* feature = new VirtualMine::Bang_Database::CLanewaySectionFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		feature->setFieldType(type);
		feature->setFieldParameter1(parameter1);
		feature->setFieldParameter2(parameter2);
		feature->setFieldParameter3(parameter3);
		feature->setFieldParameter4(parameter4);
		feature->setFieldParameter5(parameter5);

		if (name == featureName && id == peojectID)
		{
			return feature;
		}

	}
	sqlite3_finalize(stat);
}
VirtualMine::Bang_Database::CProjectFileDataset*  VirtualMine::Bang_Database::CBangSqliteDatabase::queryProjectFileDataset(const std::string& datesetName)
{
	VirtualMine::Bang_Database::CProjectFileDataset* dataset = new VirtualMine::Bang_Database::CProjectFileDataset();

	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int proID = sqlite3_column_int(stat,0);
		char* name = (char*)sqlite3_column_text(stat,1);
		char* type = (char*)sqlite3_column_text(stat,2);
		char* manager = (char*)sqlite3_column_text(stat,3);
		char* projectPeriod = (char*)sqlite3_column_text(stat,4);
		char* startTime = (char*)sqlite3_column_text(stat,5);
		char* designerOrginazation = (char*)sqlite3_column_text(stat,6);
		char* designer = (char*)sqlite3_column_text(stat,7);
		char* lanewaysection = (char*)sqlite3_column_text(stat,8);

		VirtualMine::Bang_Database::CProjectFileFeature* feature = new VirtualMine::Bang_Database::CProjectFileFeature();
		feature->setFieldID(proID);
		feature->setFieldName(name);
		feature->setFieldType(type);
		feature->setFieldDesigner(designer);
		feature->setFieldDesignerOrginazation(designerOrginazation);
		feature->setFieldManager(manager);
		feature->setFieldProjectPeriod(projectPeriod);
		feature->setFieldStartTime(startTime);
		feature->setFieldLanewaySectionType(lanewaysection);

		dataset->addFeature(feature);

	}
	sqlite3_finalize(stat);

	dataset->setName(datesetName);
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_IMAGE); /////代表工程文件
	return dataset;
}
VirtualMine::Bang_Database::CProjectFileFeature*  VirtualMine::Bang_Database::CBangSqliteDatabase::queryProjectFileDataset(const std::string& datesetName,const int& proID)
{
	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int ProID = sqlite3_column_int(stat,0);
		char* name = (char*)sqlite3_column_text(stat,1);
		char* type = (char*)sqlite3_column_text(stat,2);
		char* manager = (char*)sqlite3_column_text(stat,3);
		char* projectPeriod = (char*)sqlite3_column_text(stat,4);
		char* startTime = (char*)sqlite3_column_text(stat,5);
		char* designerOrginazation = (char*)sqlite3_column_text(stat,6);
		char* designer = (char*)sqlite3_column_text(stat,7);
		char* lanewaysection = (char*)sqlite3_column_text(stat,8);

		VirtualMine::Bang_Database::CProjectFileFeature* feature = new VirtualMine::Bang_Database::CProjectFileFeature();
		feature->setFieldID(proID);
		feature->setFieldName(name);
		feature->setFieldType(type);
		feature->setFieldDesigner(designer);
		feature->setFieldDesignerOrginazation(designerOrginazation);
		feature->setFieldManager(manager);
		feature->setFieldProjectPeriod(projectPeriod);
		feature->setFieldStartTime(startTime);
		feature->setFieldLanewaySectionType(lanewaysection);

		if (ProID == proID)
		{
			return feature;
		}

	}
	sqlite3_finalize(stat);
}

VirtualMine::Bang_Database::CShotHoleDataset*  VirtualMine::Bang_Database::CBangSqliteDatabase::queryShotHoleDataset(const std::string& datesetName)
{
	VirtualMine::Bang_Database::CShotHoleDataset* dataset = new VirtualMine::Bang_Database::CShotHoleDataset();

	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int proID = sqlite3_column_int(stat,0);
		int HoleID = sqlite3_column_int(stat,1);
		char* type = (char*)sqlite3_column_text(stat,2);
		double startPosX = sqlite3_column_double(stat,3);
		double startPosY = sqlite3_column_double(stat,4);
		double startPosZ = sqlite3_column_double(stat,5);
		double endPosX = sqlite3_column_double(stat,6);
		double endPosY = sqlite3_column_double(stat,7);
		double endPosZ = sqlite3_column_double(stat,8);
		int bangOrder = sqlite3_column_int(stat,9);
		double zhuangyaolength = sqlite3_column_double(stat,10);
		double shuipaonilength = sqlite3_column_double(stat,11);
		double fengnilength = sqlite3_column_double(stat,12);
		double shotholedepth = sqlite3_column_double(stat,13);
		double shotholeinterlength = sqlite3_column_double(stat,14);
		double shotholesmallline = sqlite3_column_double(stat,15);


		VirtualMine::Bang_Database::CShotHoleFeature* feature = new VirtualMine::Bang_Database::CShotHoleFeature();
		feature->setFieldProjectID(proID);
		feature->setFieldHoleID(HoleID);
		feature->setFieldType(type);
		feature->setFieldPositionEndX(endPosX);
		feature->setFieldPositionEndY(endPosY);
		feature->setFieldPositionEndZ(endPosZ);
		feature->setFieldPositionX(startPosX);
		feature->setFieldPositionY(startPosY);
		feature->setFieldPositionZ(startPosZ);
		feature->setFieldBangOrder(bangOrder);
		feature->setFieldFengniLength(fengnilength);
		feature->setFieldShuipaoniLength(shuipaonilength);
		feature->setFieldZhuangyaoLength(zhuangyaolength);
		feature->setFieldShotHoleDepth(shotholedepth);
		feature->setFieldShotHoleInterLength(shotholeinterlength);
		feature->setFieldSmallResistLine(shotholesmallline);

		dataset->addFeature(feature);

	}
	sqlite3_finalize(stat);

	dataset->setName(datesetName);
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_IMAGE); /////代表工程文件
	return dataset;
}
VirtualMine::Bang_Database::CShotHoleFeature*  VirtualMine::Bang_Database::CBangSqliteDatabase::queryShotHoleDataset(const std::string& datesetName,const int& proId,const int& holeId)
{
	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int proID = sqlite3_column_int(stat,0);
		int HoleID = sqlite3_column_int(stat,1);
		char* type = (char*)sqlite3_column_text(stat,2);
		double startPosX = sqlite3_column_double(stat,3);
		double startPosY = sqlite3_column_double(stat,4);
		double startPosZ = sqlite3_column_double(stat,5);
		double endPosX = sqlite3_column_double(stat,6);
		double endPosY = sqlite3_column_double(stat,7);
		double endPosZ = sqlite3_column_double(stat,8);
		int bangOrder = sqlite3_column_int(stat,9);
		double zhuangyaolength = sqlite3_column_double(stat,10);
		double shuipaonilength = sqlite3_column_double(stat,11);
		double fengnilength = sqlite3_column_double(stat,12);
		double shotholedepth = sqlite3_column_double(stat,13);
		double shotholeinterlength = sqlite3_column_double(stat,14);
		double shotholesmallline = sqlite3_column_double(stat,15);

		VirtualMine::Bang_Database::CShotHoleFeature* feature = new VirtualMine::Bang_Database::CShotHoleFeature();
		feature->setFieldProjectID(proID);
		feature->setFieldHoleID(HoleID);
		feature->setFieldType(type);
		feature->setFieldPositionEndX(endPosX);
		feature->setFieldPositionEndY(endPosY);
		feature->setFieldPositionEndZ(endPosZ);
		feature->setFieldPositionX(startPosX);
		feature->setFieldPositionY(startPosY);
		feature->setFieldPositionZ(startPosZ);
		feature->setFieldBangOrder(bangOrder);
		feature->setFieldFengniLength(fengnilength);
		feature->setFieldShuipaoniLength(shuipaonilength);
		feature->setFieldZhuangyaoLength(zhuangyaolength);
		feature->setFieldShotHoleDepth(shotholedepth);
		feature->setFieldShotHoleInterLength(shotholeinterlength);
		feature->setFieldSmallResistLine(shotholesmallline);

		if (proID == proId && holeId == HoleID)
		{
			return feature;
		}


	}
	sqlite3_finalize(stat);
}
VirtualMine::Bang_Database::CEscapeRouteDataset* VirtualMine::Bang_Database::CBangSqliteDatabase::queryEscapeRouteDataset( const std::string& datesetName )
{
	VirtualMine::Bang_Database::CEscapeRouteDataset* dataset = new VirtualMine::Bang_Database::CEscapeRouteDataset();
	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);

	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int proID = sqlite3_column_int(stat,0);
		int pointID = sqlite3_column_int(stat,1);	
		double startPosX = sqlite3_column_double(stat,3);
		double startPosY = sqlite3_column_double(stat,4);
		double startPosZ = sqlite3_column_double(stat,5);

		VirtualMine::Bang_Database::CEscapeRouteFeature* feature = new VirtualMine::Bang_Database::CEscapeRouteFeature();

		feature->setFieldProjectID(proID);
		feature->setFieldPointID(pointID);
		feature->setFieldPositionX(startPosX);
		feature->setFieldPositionY(startPosY);
		feature->setFieldPositionZ(startPosZ);

		dataset->addFeature(feature);

	}
	sqlite3_finalize(stat);
	return dataset;
}
VirtualMine::Bang_Database::CEscapeRouteFeature* VirtualMine::Bang_Database::CBangSqliteDatabase::queryEscapeRouteDataset( const std::string& datesetName,const int& proId,const int& pointId )
{
	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);

	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int proID = sqlite3_column_int(stat,0);
		int posID = sqlite3_column_int(stat,1);	
		double startPosX = sqlite3_column_double(stat,3);
		double startPosY = sqlite3_column_double(stat,4);
		double startPosZ = sqlite3_column_double(stat,5);

		VirtualMine::Bang_Database::CEscapeRouteFeature* feature = new VirtualMine::Bang_Database::CEscapeRouteFeature();

		feature->setFieldProjectID(proID);
		feature->setFieldPointID(posID);
		feature->setFieldPositionX(startPosX);
		feature->setFieldPositionY(startPosY);
		feature->setFieldPositionZ(startPosZ);

		if (proId == proID && pointId == posID)
		{
			return feature;
		}

	}
	sqlite3_finalize(stat);
	return NULL;
}



//kk
VirtualMine::Bang_Database::CConProgressDataset* VirtualMine::Bang_Database::CBangSqliteDatabase::queryConProgressDataset(const std::string& datesetName)
{
	VirtualMine::Bang_Database::CConProgressDataset* dataset = new VirtualMine::Bang_Database::CConProgressDataset();
	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);

	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int proID = sqlite3_column_int(stat,0);
		int pointID = sqlite3_column_int(stat,1);	
		double startPosX = sqlite3_column_double(stat,3);
		double startPosY = sqlite3_column_double(stat,4);
		double startPosZ = sqlite3_column_double(stat,5);

		VirtualMine::Bang_Database::CConProgressFeature* feature = new VirtualMine::Bang_Database::CConProgressFeature();

		feature->setFieldProjectID(proID);
		feature->setFieldPointID(pointID);
		feature->setFieldPositionX(startPosX);
		feature->setFieldPositionY(startPosY);
		feature->setFieldPositionZ(startPosZ);

		dataset->addFeature(feature);

	}
	sqlite3_finalize(stat);
	return dataset;
}
//kk
VirtualMine::Bang_Database::CConProgressFeature* VirtualMine::Bang_Database::CBangSqliteDatabase::queryConProgressDataset(const std::string& datesetName,const int& proId,const int& pointId)
{
	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);

	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int proID = sqlite3_column_int(stat,0);
		int posID = sqlite3_column_int(stat,1);	
		double startPosX = sqlite3_column_double(stat,3);
		double startPosY = sqlite3_column_double(stat,4);
		double startPosZ = sqlite3_column_double(stat,5);

		VirtualMine::Bang_Database::CConProgressFeature* feature = new VirtualMine::Bang_Database::CConProgressFeature();

		feature->setFieldProjectID(proID);
		feature->setFieldPointID(posID);
		feature->setFieldPositionX(startPosX);
		feature->setFieldPositionY(startPosY);
		feature->setFieldPositionZ(startPosZ);

		if (proId == proID && pointId == posID)
		{
			return feature;
		}

	}
	sqlite3_finalize(stat);
	return NULL;
}
VirtualMine::Database::IDataset*  VirtualMine::Bang_Database::CBangSqliteDatabase::getDatasetByProjectID( const std::string& datesetType,const int& proId )
{
	CLogicDataset* pLogicDataset = this->queryLogicDataset();
	int count = pLogicDataset->getCount();
	std::string datesetName;
	for (int i = 0; i < count; i++)
	{
		std::string type = dynamic_cast<CLogicFeature*>(pLogicDataset->getFeature(i))->getFieldType();
		std::string name = dynamic_cast<CLogicFeature*>(pLogicDataset->getFeature(i))->getFieldName();

		if (type == datesetType)
		{
			datesetName = name;
		}
	}


	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);

	if (datesetType == VirtualMine::Core::GeoDataType::GDT_LANWAY)
	{
		CLanewayDataset* dataset = new CLanewayDataset();

		while (sqlite3_step(stat) == SQLITE_ROW)
		{
			int id = sqlite3_column_int( stat, 0 );
			char* name = (char*)sqlite3_column_text(stat,1);
			char* tmpname = G2U(name);
			char* type = (char*)sqlite3_column_text(stat,2);
			float width  = sqlite3_column_double(stat,3);
			float height = sqlite3_column_double(stat,4);

			int sectiontype = sqlite3_column_int(stat,5);
			int supporttype = sqlite3_column_int(stat,6);

			const void * pData = sqlite3_column_blob( stat, 7 );
			int len = sqlite3_column_bytes( stat, 7 );
			Ogre::uchar* pGeometry = (Ogre::uchar*)pData;
			int lanewaywindtype = sqlite3_column_int(stat,8);


			IFeature* feature = new CLanewayFeature();
			feature->setFieldID(id);
			feature->setFieldName(name);
			feature->setFieldType(type);
			feature->setFieldWidth(width);
			feature->setFieldHeight(height);
			feature->setFieldSectionType(sectiontype);
			feature->setFieldHeightSupportType(supporttype);
			feature->setFieldBlob(pGeometry,len);
			feature->setFieldLanewayWindType(lanewaywindtype);

			if (proId == id)
			{
				dataset->addFeature(feature);
			}

		}
		sqlite3_finalize(stat);
		dataset->setType(VirtualMine::Core::GeoDataType::GDT_LANWAY);
		dataset->setName(datesetName);
		return dataset;
	}
	else if (datesetType == VirtualMine::Core::GeoDataType::GDT_TERRANE)
	{
		CTerraneDataset* dataset = new CTerraneDataset();

		while (sqlite3_step(stat) == SQLITE_ROW)
		{
			int id = sqlite3_column_int( stat, 0 );
			char* name = (char*)sqlite3_column_text(stat,1);
			char* type = (char*)sqlite3_column_text(stat,2);

			const void * pData = sqlite3_column_blob( stat, 3);
			int len = sqlite3_column_bytes( stat, 3 );
			Ogre::uchar* pGeometry = (Ogre::uchar*)pData;


			CTerraneFeature* feature = new CTerraneFeature();
			feature->setFieldID(id);
			feature->setFieldName(name);
			feature->setFieldRockType(type);
			feature->setFieldBlob(pGeometry,len);

			if (id == proId )
			{
				dataset->addFeature(feature);
			}

		}
		sqlite3_finalize(stat);	
		dataset->setName(datesetName);
		return dataset;

	}
	else if (datesetType == VirtualMine::Core::GeoDataType::GDT_SHOTHOLE)
	{
		CShotHoleDataset* pShotHoleDataset = new CShotHoleDataset();

		while (sqlite3_step(stat) == SQLITE_ROW)
		{
			int mProID = sqlite3_column_int(stat,0);
			int HoleID = sqlite3_column_int(stat,1);
			char* type = (char*)sqlite3_column_text(stat,2);
			double startPosX = sqlite3_column_double(stat,3);
			double startPosY = sqlite3_column_double(stat,4);
			double startPosZ = sqlite3_column_double(stat,5);
			double endPosX = sqlite3_column_double(stat,6);
			double endPosY = sqlite3_column_double(stat,7);
			double endPosZ = sqlite3_column_double(stat,8);
			int bangOrder = sqlite3_column_int(stat,9);
			double zhuangyaolength = sqlite3_column_double(stat,10);
			double shuipaonilength = sqlite3_column_double(stat,11);
			double fengnilength = sqlite3_column_double(stat,12);
			double shotholedepth = sqlite3_column_double(stat,13);
			double shotholeinterlength = sqlite3_column_double(stat,14);
			double shotholesmallline = sqlite3_column_double(stat,15);

			VirtualMine::Bang_Database::CShotHoleFeature* feature = new VirtualMine::Bang_Database::CShotHoleFeature();
			feature->setFieldProjectID(mProID);
			feature->setFieldHoleID(HoleID);
			feature->setFieldType(type);
			feature->setFieldPositionEndX(endPosX);
			feature->setFieldPositionEndY(endPosY);
			feature->setFieldPositionEndZ(endPosZ);
			feature->setFieldPositionX(startPosX);
			feature->setFieldPositionY(startPosY);
			feature->setFieldPositionZ(startPosZ);
			feature->setFieldBangOrder(bangOrder);
			feature->setFieldFengniLength(fengnilength);
			feature->setFieldShuipaoniLength(shuipaonilength);
			feature->setFieldZhuangyaoLength(zhuangyaolength);
			feature->setFieldShotHoleDepth(shotholedepth);
			feature->setFieldShotHoleInterLength(shotholeinterlength);
			feature->setFieldSmallResistLine(shotholesmallline);


			if (proId == mProID)
			{
				pShotHoleDataset->addFeature(feature);
			}


		}
		sqlite3_finalize(stat);
		pShotHoleDataset->setName(datesetName);
		return pShotHoleDataset;

	}
	else if(datesetType == VirtualMine::Core::GeoDataType::GDT_LANEWAYSECTION)
	{
		CLanewaySectionDataset* pDataset = new CLanewaySectionDataset();

		while (sqlite3_step(stat) == SQLITE_ROW)
		{
			int id = sqlite3_column_int( stat, 0 );
			char* name = (char*)sqlite3_column_text(stat,1);
			char* type = (char*)sqlite3_column_text(stat,2);
			double parameter1 = sqlite3_column_double(stat,3);
			double parameter2 = sqlite3_column_double(stat,4);
			double parameter3 = sqlite3_column_double(stat,5);
			double parameter4 = sqlite3_column_double(stat,6);
			double parameter5 = sqlite3_column_double(stat,7);

			VirtualMine::Bang_Database::CLanewaySectionFeature* feature = new VirtualMine::Bang_Database::CLanewaySectionFeature();
			feature->setFieldID(id);
			feature->setFieldName(name);
			feature->setFieldType(type);
			feature->setFieldParameter1(parameter1);
			feature->setFieldParameter2(parameter2);
			feature->setFieldParameter3(parameter3);
			feature->setFieldParameter4(parameter4);
			feature->setFieldParameter5(parameter5);

			if (id == proId)
			{
				pDataset->addFeature(feature);
			}

		}
		sqlite3_finalize(stat);
		pDataset->setName(datesetName);
		return pDataset;
	}
	else if(datesetType == VirtualMine::Core::GeoDataType::GDT_ESCAPEROUTE)
	{
		VirtualMine::Bang_Database::CEscapeRouteDataset* dataset = new VirtualMine::Bang_Database::CEscapeRouteDataset();
		sqlite3_stmt * stat;
		std::string sql1 = "select * from " + datesetName; 
		sqlite3_prepare_v2(mpDB, sql1.c_str(), -1, &stat,0);

		while (sqlite3_step(stat) == SQLITE_ROW)
		{
			int proID = sqlite3_column_int(stat,0);
			int pointID = sqlite3_column_int(stat,1);	
			double startPosX = sqlite3_column_double(stat,2);
			double startPosY = sqlite3_column_double(stat,3);
			double startPosZ = sqlite3_column_double(stat,4);

			VirtualMine::Bang_Database::CEscapeRouteFeature* feature = new VirtualMine::Bang_Database::CEscapeRouteFeature();

			feature->setFieldProjectID(proID);
			feature->setFieldPointID(pointID);
			feature->setFieldPositionX(startPosX);
			feature->setFieldPositionY(startPosY);
			feature->setFieldPositionZ(startPosZ);

			if (proID == proId)
			{
				dataset->addFeature(feature);
			}

		}
		sqlite3_finalize(stat);
		return dataset;

	}
	//kk施工进度
	else if(datesetType == VirtualMine::Core::GeoDataType::GDT_CONPROGRESS)
	{
		VirtualMine::Bang_Database::CConProgressDataset* dataset = new VirtualMine::Bang_Database::CConProgressDataset();
		sqlite3_stmt * stat;
		std::string sql1 = "select * from " + datesetName; 
		sqlite3_prepare_v2(mpDB, sql1.c_str(), -1, &stat,0);

		while (sqlite3_step(stat) == SQLITE_ROW)
		{
			int proID = sqlite3_column_int(stat,0);
			int pointID = sqlite3_column_int(stat,1);	
			double startPosX = sqlite3_column_double(stat,2);
			double startPosY = sqlite3_column_double(stat,3);
			double startPosZ = sqlite3_column_double(stat,4);

			VirtualMine::Bang_Database::CConProgressFeature* feature = new VirtualMine::Bang_Database::CConProgressFeature();

			feature->setFieldProjectID(proID);
			feature->setFieldPointID(pointID);
			feature->setFieldPositionX(startPosX);
			feature->setFieldPositionY(startPosY);
			feature->setFieldPositionZ(startPosZ);

			if (proID == proId)
			{
				dataset->addFeature(feature);
			}

		}
		sqlite3_finalize(stat);
		return dataset;

	}

}
#endif