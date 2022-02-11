#include "vrmine/vr_sqlitedatabase/sqlitedatabase/sqlitedatabase.h"
#include "vrmine/vr_databaseengine/database/lanewaydataset.h"
#include "vrmine/vr_databaseengine/database/lanewayfeature.h"
#include "vrmine/vr_databaseengine/database/drillingdataset.h"
#include "vrmine/vr_databaseengine/database/drillingfeature.h"
#include "vrmine/vr_databaseengine/database/logicdataset.h"
#include "vrmine/vr_databaseengine/database/logicfeature.h"
#include "vrmine/vr_databaseengine/database/imagedataset.h"
#include "vrmine/vr_databaseengine/database/imagefeature.h"
#include "vrmine/vr_databaseengine/database/demdataset.h"
#include "vrmine/vr_databaseengine/database/demfeature.h"


#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_core/variant.h"
#include "vrmine/vr_databaseengine/database/field.h"
#include <string>
#include "sqlite3/sqlite3.h"
#include "vrmine/vr_databaseengine/database/faultlayerfeature.h"
#include "vrmine/vr_databaseengine/database/faultlayerdataset.h"
#include <windows.h>


//#include <QTextCodec>
#include "Qt/qtextcodec.h"

//#include <Qt\qtextcodec.h>
//#include "Qt\qsqldatabase.h"
//#include "C:\Qt\4.8.6\include\Qt\qsqldatabase.h"
//#include "C:\Qt\4.8.6\include\Qt\qtextcodec.h"

using namespace std;
using namespace VirtualMine::SQLiteDatabase;
using namespace VirtualMine::Database;
using namespace VirtualMine::Core;


CSQLiteDatabase::CSQLiteDatabase(IDataSourceInfo* pDataSourceInfo)
	:CDatabase(pDataSourceInfo)
{
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	QTextCodec::setCodecForTr(codec);
	//QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

	 
	//SQLiteDatabase db = SQLiteDatabase::addDatabase("QSQLite");

	this->mpDB = NULL;
	//this->mpDatasetSet = new std::vector<VirtualMine::Database::IDataset*>();
	//string name = pDataSourceInfo->getUri();
	std::string name = this->getName();
	int rc = sqlite3_open(G2U(name.c_str()),&mpDB);
	if (rc != SQLITE_OK)
	{
		int res = 0; 
	}
	//int rc = sqlite3_open16(pDataSourceInfo->getUri().c_str(),&mpDB);
	//接口不能用
	//rc = sqlite3_key(mpDB,"abcd",3); //使用密码，第一次为设置密码
	rc = this->createMetadataDataset();
	rc = this->createLogicDataset();


	//创建用户信息表
	rc = this->createUserInfoDataset();
    



	//////以后要注释掉 
	//rc = this->createLanewayDataset();
	//rc = this->createDrillingDataset();
	//rc = this->createImageDataset();
	//rc = this->createCoalLayerDataset();
	//rc = this->createDEMDataset();
	//rc = this->createModelDataset();

	//rc = this->createModelDataset("GroundModelDataset");
	//rc = this->createModelDataset("LocationDataset");
	////rc = this->createFaultLayerDataset();
	//rc = this->createWorkingPlaneDataset();


}

/////DEFAULT,0  
//CSQLiteDatabase::CSQLiteDatabase(VirtualMine::Database::IDataSourceInfo* pDataSourceInfo,int i)
//{
//	this->mpDB = NULL;
//	string name = pDataSourceInfo->getUri();
//	int rc = sqlite3_open(G2U(name.c_str()),&mpDB);
//
//	//int rc = sqlite3_open16(pDataSourceInfo->getUri().c_str(),&mpDB);
//	//接口不能用
//	//rc = sqlite3_key(mpDB,"abcd",3); //使用密码，第一次为设置密码
//	rc = this->createMetadataDataset();
//	rc = this->createLogicDataset();
//
//	//////以后要注释掉 
//	rc = this->createLanewayDataset("LanewayDataset");
//    rc = this->createDrillingDataset("DrillingDataset");
//	rc = this->createImageDataset("ImageDataset");
//	rc = this->createCoalLayerDataset("CoalLayerDataset");
//	rc = this->createDEMDataset("DEMDataset");
//	rc = this->createModelDataset("ModelDataset");
//	rc = this->createModelDataset("GroundModelDataset");
//	rc = this->createModelDataset("LocationDataset");
//
//	////rc = this->createFaultLayerDataset();
//	//rc = this->createWorkingPlaneDataset();
//
//}


//int CSQLiteDatabase::createLevelLanewayDataset()
//{
//	//int rc(0);
//	//rc = sqlite3_open("D:/SqlLiteDB/demo.db",&mpDB);
//	//if (rc != SQLITE_OK)
//	//{
//	//	return 0;
//	//}
//	////rc = sqlite3_exec(db,"create table LevelLanewayDataset( ID integer primary key,Name varchar(32),Width real, Geometry Blob)", NULL, NULL, results );
//	return -1;
//}


CSQLiteDatabase::~CSQLiteDatabase()
{
	/*if (mpDB != NULL)
	{
		delete mpDB;
		mpDB = NULL;
	}*/
}

void  CSQLiteDatabase::createDefaultTable()
{
	if (!this->mpDB)
	{
		return; 
	}
	int rc = 0;
	rc = this->createLanewayDataset();
	rc = this->createDrillingDataset();
	rc = this->createImageDataset();
	rc = this->createCoalLayerDataset();
	rc = this->createDEMDataset();
	rc = this->createModelDataset();

	rc = this->createModelDataset("GroundModelDataset");
	rc = this->createModelDataset("LocationDataset");
	//rc = this->createFaultLayerDataset();
    rc = this->createWorkingPlaneDataset();
}


 WCHAR* CSQLiteDatabase::mbcsToUnicode(const char *zFilename)
{
	int nByte;
	WCHAR *zMbcsFilename;
	int codepage = AreFileApisANSI() ? CP_ACP : CP_OEMCP;

	nByte = MultiByteToWideChar(codepage, 0, zFilename, -1, NULL,0)*sizeof(WCHAR);
	zMbcsFilename = (WCHAR*)malloc( nByte*sizeof(zMbcsFilename[0]) );
	if( zMbcsFilename==0 )
	{
		return 0;
	}
	nByte = MultiByteToWideChar(codepage, 0, zFilename, -1, zMbcsFilename, nByte);
	if( nByte==0 )
	{
		free(zMbcsFilename);
		zMbcsFilename = 0;
	}
	return zMbcsFilename;
}
char* CSQLiteDatabase::unicodeToUtf8(const WCHAR *zWideFilename)
{
	int nByte;
	char *zFilename;

	nByte = WideCharToMultiByte(CP_UTF8, 0, zWideFilename, -1, 0, 0, 0, 0);
	zFilename = (char*)malloc( nByte );
	if( zFilename==0 )
	{
		return 0;
	}
	nByte = WideCharToMultiByte(CP_UTF8, 0, zWideFilename, -1, zFilename, nByte,
		0, 0);
	if( nByte == 0 )
	{
		free(zFilename);
		zFilename = 0;
	}
	return zFilename;
}
 WCHAR* CSQLiteDatabase::utf8ToUnicode(const char *zFilename)
{
	int nChar;
	WCHAR *zWideFilename;

	nChar = MultiByteToWideChar(CP_UTF8, 0, zFilename, -1, NULL, 0);
	zWideFilename = (WCHAR*) malloc( nChar*sizeof(zWideFilename[0]) );
	if( zWideFilename==0 ){
		return 0;
	}
	nChar = MultiByteToWideChar(CP_UTF8, 0, zFilename, -1, zWideFilename, nChar);
	if( nChar==0 ){
		free(zWideFilename);
		zWideFilename = 0;
	}
	return zWideFilename;
}
char* CSQLiteDatabase::unicodeToMbcs(const WCHAR *zWideFilename)
{
	int nByte;
	char *zFilename;
	int codepage = AreFileApisANSI() ? CP_ACP : CP_OEMCP;

	nByte = WideCharToMultiByte(codepage, 0, zWideFilename, -1, 0, 0, 0, 0);
	zFilename = (char*)malloc( nByte );
	if( zFilename==0 ){
		return 0;
	}
	nByte = WideCharToMultiByte(codepage, 0, zWideFilename, -1, zFilename, nByte,
		0, 0);
	if( nByte == 0 ){
		free(zFilename);
		zFilename = 0;
	}
	return zFilename;
}
char* CSQLiteDatabase::AnsiToUtf8( const char *zFilename)   /** ansi 2 utf8 */
{
	char *zFilenameUtf8;
	WCHAR *zTmpWide; 

	zTmpWide = mbcsToUnicode(zFilename);
	if( zTmpWide==0 ){
		return 0;
	}
	zFilenameUtf8 = unicodeToUtf8(zTmpWide);
	free(zTmpWide);
	return zFilenameUtf8;
}
char* CSQLiteDatabase::Utf8ToAnsi( char *zFilename)  /*** utf8 - ansi */
{
	char *zFilenameMbcs;
	WCHAR *zTmpWide;

	zTmpWide = utf8ToUnicode(zFilename);
	if( zTmpWide==0 ){
		return 0;
	}
	zFilenameMbcs = unicodeToMbcs(zTmpWide);
	free(zTmpWide);
	return zFilenameMbcs;
}

//UTF-8到GB2312的转换
char* CSQLiteDatabase::U2G(const char* utf8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len+1];
	memset(wstr, 0, len+1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len+1];
	memset(str, 0, len+1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
	if(wstr) delete[] wstr;
	return str;
}
//GB2312到UTF-8的转换
char* CSQLiteDatabase::G2U(const char* gb2312)
{
	int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len+1];
	memset(wstr, 0, len+1);
	MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len+1];
	memset(str, 0, len+1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	if(wstr) delete[] wstr;
	return str;

/*
	char *zFilenameUtf8;
	WCHAR *zTmpWide; 

	zTmpWide = mbcsToUnicode(gb2312);
	if( zTmpWide==0 ){
		return 0;
	}
	zFilenameUtf8 = unicodeToUtf8(zTmpWide);
	free(zTmpWide);
	return zFilenameUtf8;*/
}



sqlite3 * CSQLiteDatabase::getSQLite3()
{
	return this->mpDB;
}

void CSQLiteDatabase::setSQLite3( sqlite3* sqlDB)
{
	this->mpDB = sqlDB;
}


int CSQLiteDatabase::createUserInfoDataset()
{
	char **results = NULL;  
	int rc(0);
	string name = "create table UserInfoDataset(Name TEXT NULL,Password TEXT NULL)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );


	return rc;

}


//////////////////创建表////////////////////////////////////
int CSQLiteDatabase::createMetadataDataset()
{
	char **results = NULL;  
	int rc(0);
	string name = "create table MetadataDataset(Name TEXT NULL,SpatialReference integer,Type varchar(32),minRangeX real,minRangeY real,minRangeZ real,maxRangeX real,maxRangeY real,maxRangeZ real)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );

	//IDataset* dataset = new CMetadataDataset();
	//if (this->mpDatasetSet)
	//{
	//	this->mpDatasetSet->push_back(dataset);
	//}

	return rc;
}

int CSQLiteDatabase::createLogicDataset()
{
	char **results = NULL; 
	int rc(0);

	string name = "create table LogicDataset( ID integer ,Name TEXT NULL,Type varchar(32) ,minRangeX real,minRangeY real,minRangeZ real,maxRangeX real,maxRangeY real,maxRangeZ real)";

	//string index = "create index NameIndex on LogicDataset(Name)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );

	/////
	//IDataset* dataset = new CLogicDataset();
	//dataset->setName("LogicDataset");
	//if (this->mpDatasetSet)
	//{
	//	this->mpDatasetSet->push_back(dataset);
	//}

	
	return rc;
}

int CSQLiteDatabase::createRoadDataset()
{
	char **results = NULL; 
	int rc(0);
	string name = "create table RoadDataset( ID integer primary key,Name TEXT NULL,Type varchar(32),Width real)";

	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );
	return rc;
}

int CSQLiteDatabase::createFaultLayerDataset()
{
	char **results = NULL; 
	int rc(0);
	string name = "create table FaultLayerDataset( ID integer ,Name TEXT NULL,DipAngle real,UpLength real,DownLength real,Geometry real)";
	
	string index = "create index faultindex on FaultLayerDataset(Name)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );	
	return rc;
}

int CSQLiteDatabase::createLanewayDataset() 
{
	char **results = NULL;  
	int rc(0);
	//string filename = "D:/SqlLiteDB/demo.db";
	//rc = sqlite3_open(filename.c_str(),&mpDB);
	/*
	if (rc != SQLITE_OK)
	{
		return -1;
	}*/
	string name = "create table LanewayDataset(ID integer,Name TEXT NULL,Type varchar(32),Width real,Height real,SectionType integer,SupportType integer,Geometry Blob,LanewayWindType integer)";
	//rc = sqlite3_exec(mpDB,AnsiToUtf8(name.c_str()), NULL, NULL, results );
	rc = sqlite3_exec(mpDB,"create table LanewayDataset(ID integer,Name TEXT NULL,Type varchar(32),Width real,Height real,SectionType integer,SupportType integer,Geometry Blob,LanewayWindType integer)", NULL, NULL, results );
	///unicodeToUtf8()
	///
	//IDataset* dataset = new CLanewayDataset();
	//dataset->setName("LanewayDataset");
	//if (this->mpDatasetSet)
	//{
	//	this->mpDatasetSet->push_back(dataset);
	//}
	
	return rc;
}

int CSQLiteDatabase::createDataset(const std::string& tableName, const std::string& type)
{
	if (type == VirtualMine::Core::GeoDataType::GDT_DRILL)
	{
		int rc = this->createDrillingDataset(tableName);
		return rc;
	}
	else if (type == VirtualMine::Core::GeoDataType::GDT_COALSEAM)
	{
		int rc = this->createCoalLayerDataset(tableName);
		return rc;
	}
	else if (type == VirtualMine::Core::GeoDataType::GDT_DEM)
	{
		int rc = this->createDEMDataset(tableName);
		return rc;
	}
	else if (type == VirtualMine::Core::GeoDataType::GDT_IMAGE)
	{
		int rc = this->createImageDataset(tableName);
		return rc;
	}
	else if (type == VirtualMine::Core::GeoDataType::GDT_LANWAY)
	{
        int rc = this->createLanewayDataset(tableName);
		return rc;
	}
	else if (type == VirtualMine::Core::GeoDataType::GDT_MODEL)
	{
        int rc = this->createModelDataset(tableName);
		return rc;
	}
	else if (type == VirtualMine::Core::GeoDataType::GDT_WORKINGPLANE)
	{
		int rc = this->createWorkingPlaneDataset(tableName);
		return rc;
	}	
	else if (type == VirtualMine::Core::GeoDataType::GDT_FAULT)
	{
		int rc = this->createFaultLayerDataset(tableName);
		return rc;
	}
	else if (type == VirtualMine::Core::GeoDataType::GDT_TERRANE)
	{
		int rc = this->createTerraneDataset(tableName);
		return rc;
	}
	//else if (type == VirtualMine::Core::GeoDataType::GDT_ESCAPEROUTE)
	//{
	//	int rc = this->createEsacpeRouteDataset(tableName);
 //       return rc;
	//}
}

/////////////////需要测试
int CSQLiteDatabase::createLanewayDataset(const std::string& tableName)
{
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	QTextCodec::setCodecForTr(codec);
	//QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());


	char **results = NULL;  
	int rc(0);
	string name = "create table LanewayDataset(ID integer,Name TEXT NULL,Type varchar(32),Width real,Height real,SectionType integer,SupportType integer,Geometry Blob,LanewayWindType integer)";

	string datasetname = "create table " +  tableName + "( ID integer,Name TEXT,Type varchar(32),Width real,Height real,SectionType integer,SupportType integer,Geometry Blob,LanewayWindType integer)";
	
	//string index = "create index lanewayIndex on " + tableName+ "(Name)";//添加索引
	
	rc = sqlite3_exec(mpDB,datasetname.c_str(), NULL, NULL, results);
	/////
	//IDataset* dataset = new CLanewayDataset();
	//dataset->setName(tableName);
	//if (this->mpDatasetSet)
	//{
	//	this->mpDatasetSet->push_back(dataset);
	//}
	//

	return rc;
}

int CSQLiteDatabase::createRoadDataset(const std::string& tableName)
{
	char **results = NULL; 
	int rc(0);
	string name = "create table " + tableName + "( ID integer primary key,Name TEXT NULL,Type varchar(32),Width real)";

	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );
	return rc;
}

int CSQLiteDatabase::createFaultLayerDataset(const std::string& tableName)
{
	char **results = NULL; 
	int rc(0);
	string name = "create table " + tableName  +"( ID integer ,Name TEXT NULL,DipAngle real,UpLength real,DownLength real,Geometry real)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );	
	return rc;
}

int CSQLiteDatabase::createCoalLayerDataset()
{
	char **results = NULL; 
	int rc(0);
	string name = "create table CoalLayerDataset(ID integer,Name TEXT NULL, Geometry Blob,Texture Blob)";
	rc = sqlite3_exec(mpDB,name.c_str(),NULL, NULL, results );
	
	//IDataset* dataset = new CCoalLayerDataset();
	//dataset->setName("CoalLayerDataset");
	//if (this->mpDatasetSet)
	//{
	//	this->mpDatasetSet->push_back(dataset);
	//}

	return rc;
}

/////创建岩层数据集
int CSQLiteDatabase::createTerraneDataset(const std::string& tableName)
{
	char **results = NULL; 
	int rc(0);
	string name = "create table " + tableName + "(ID integer,Name TEXT NULL,RockType TEXT,Geometry Blob)";
	rc = sqlite3_exec(mpDB,name.c_str(),NULL, NULL, results );
	
	return rc;
}


int CSQLiteDatabase::createDrillingDataset()
{
	char **results = NULL; 
	int rc(0);
	string name = "create table DrillingDataset( ID integer,Name TEXT NULL ,PositionX real,PositionY real, PositionZ real,GeoLayerInfo Blob)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );

	//IDataset* dataset = new CCoalLayerDataset();
	//dataset->setName("DrillingDataset");
	//if (this->mpDatasetSet)
	//{
	//	this->mpDatasetSet->push_back(dataset);
	//}
	return rc;
} 

int CSQLiteDatabase::createDEMDataset()
{
	char **results = NULL; 
	int rc(0);
	string name = "create table DEMDataset(ID integer primary key, Name nvarchar(128),Geometry Blob)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );

	//IDataset* dataset = new CCoalLayerDataset();
	//dataset->setName("DEMDataset");
	//if (this->mpDatasetSet)
	//{
	//	this->mpDatasetSet->push_back(dataset);
	//}

	return rc;
}

int CSQLiteDatabase::createWorkingPlaneDataset()
{
	char **results = NULL; 
	int rc(0);
	string name = "create table WorkingplaneDataset(ID integer primary key, Name nvarchar(128),Geometry Blob)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );

	//IDataset* dataset = new CCoalLayerDataset();
	//dataset->setName("WorkingplaneDataset");
	//if (this->mpDatasetSet)
	//{
	//	this->mpDatasetSet->push_back(dataset);
	//}
	return rc;
}


int CSQLiteDatabase::createCoalLayerDataset(const std::string& tableName)
{
	char **results = NULL; 
	int rc(0);
	string name = "create table " + tableName + "(ID integer,Name TEXT NULL, Geometry Blob,Texture Blob)";
	rc = sqlite3_exec(mpDB,name.c_str(),NULL, NULL, results );
	//IDataset* dataset = new CCoalLayerDataset();
	//dataset->setName(tableName);
	//if (this->mpDatasetSet)
	//{
	//	this->mpDatasetSet->push_back(dataset);
	//}
	return rc;
}

int CSQLiteDatabase::createDrillingDataset(const std::string& tableName)
{
	char **results = NULL; 
	int rc(0);
	string name = "create table " + tableName + "(ID integer,Name TEXT NULL ,PositionX real,PositionY real, PositionZ real,GeoLayerInfo Blob)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );

	//IDataset* dataset = new CDrillingDataset();
	//dataset->setName(tableName);
	//if (this->mpDatasetSet)
	//{
	//	this->mpDatasetSet->push_back(dataset);
	//}
	return rc;
} 

int CSQLiteDatabase::createDEMDataset(const std::string& tableName)
{
	char **results = NULL; 
	int rc(0);
	string name = "create table " + tableName + "(ID integer primary key, Name nvarchar(128),Geometry Blob)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );

	//IDataset* dataset = new CDEMDataset();
	//dataset->setName(tableName);
	//if (this->mpDatasetSet)
	//{
	//	this->mpDatasetSet->push_back(dataset);
	//}
	return rc;
}

int CSQLiteDatabase::createWorkingPlaneDataset(const std::string& tableName)
{
	char **results = NULL; 
	int rc(0);
	string name = "create table " + tableName + "(ID integer primary key, Name nvarchar(128),Geometry Blob)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );

	//IDataset* dataset = new CWorkingplaneDataset();
	//dataset->setName(tableName);
	//if (this->mpDatasetSet)
	//{
	//	this->mpDatasetSet->push_back(dataset);
	//}
	return rc;
}


int CSQLiteDatabase::createModelDataset()
{
	char **results = NULL; 
	int rc(0);
	string name = "create table ModelDataset(ID integer, Name TEXT NULL,Type varchar(32), PosX real, PosY real,PosZ real,ScaleX real,ScaleY real,ScaleZ real, TransX real, TransY real,TransZ real,RotateX real,RotateY real,RotateZ real,Tag Blob,DeviceType integer)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );

	//IDataset* dataset = new CModelDataset();
	//dataset->setName("ModelDataset");
	//if (this->mpDatasetSet)
	//{
	//	this->mpDatasetSet->push_back(dataset);
	//}
	return rc;
}

int CSQLiteDatabase::createModelDataset(const std::string& name)
{
	char **results = NULL; 
	int rc(0);
	string datasetname = "create table " +  name + "(ID integer, Name TEXT NULL,Type varchar(32), PosX real, PosY real,PosZ real,ScaleX real,ScaleY real,ScaleZ real, TransX real, TransY real,TransZ real,RotateX real,RotateY real,RotateZ real,Tag Blob,DeviceType integer)";
	//string name = "create table ModelDataset(ID integer primary key, Name TEXT NULL,Type varchar(32), PosX real, PosY real,PosZ real,ScaleX real,ScaleY real,ScaleZ real, TransX real, TransY real,TransZ real,RotateX real,RotateY real,RotateZ real,Tag Blob)";
    rc = sqlite3_exec(mpDB,AnsiToUtf8(datasetname.c_str()), NULL, NULL, results );
	//rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );

	//IDataset* dataset = new CModelDataset();
	//dataset->setName(name);
	//if (this->mpDatasetSet)
	//{
	//	this->mpDatasetSet->push_back(dataset);
	//}
	return rc;
}

///ziduan
int CSQLiteDatabase::createImageDataset()
{
	char **results = NULL; 
	int rc(0);
	string name = "create table ImageDataset(ID integer primary key, Name varchar(32),Image Blob)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );

	//IDataset* dataset = new CImageDataset();
	//dataset->setName("ImageDataset");
	//if (this->mpDatasetSet)
	//{
	//	this->mpDatasetSet->push_back(dataset);
	//}
	return rc;
}

int CSQLiteDatabase::createImageDataset(const std::string& tableName)
{
	char **results = NULL; 
	int rc(0);
	string name = "create table " + tableName + "(ID integer primary key, Name varchar(32),Image Blob,MinPosX real,MinPosY real,MinPosZ real,MaxPosX real,MaxPosY real,MaxPosZ real)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );

	//IDataset* dataset = new CImageDataset();
	//dataset->setName(tableName);
	//if (this->mpDatasetSet)
	//{
	//	this->mpDatasetSet->push_back(dataset);
	//}
	return rc;
}







////////////////////////////插入操作//////////////////////////////////////////
int CSQLiteDatabase::insertFeatureToDataset(VirtualMine::Database::IFeature *feature,const std::string& dataType,const std::string& tableName)
{

	if (feature == NULL )
	{
		return -1;
	}

	if (dataType == VirtualMine::Core::GeoDataType::GDT_DRILL)
	{
		insertDrillingFeatureToDrillingDataset(feature,tableName);		
	}
	 else if (dataType == VirtualMine::Core::GeoDataType::GDT_DEM)
	{
		insertDEMFeatureToDEMDataset(feature,tableName);
	}
	else if (dataType == VirtualMine::Core::GeoDataType::GDT_LANWAY)
	{
		insertLanewayFeatureToLanewayDataset(feature,tableName);
	}
	else if (dataType == VirtualMine::Core::GeoDataType::GDT_FAULT)
	{
		this->insertFaultLayerFeatureToFaultLayerDataset(feature,tableName);
	}
	else if (dataType == VirtualMine::Core::GeoDataType::GDT_COALSEAM)
	{
		insertCoalLayerFeatureToCoalLayerDataset(feature,tableName);
	}
	else if (dataType == VirtualMine::Core::GeoDataType::GDT_IMAGE)
	{
		insertImageFeatureToImageDataset(feature,tableName);
	}
	else if (dataType == VirtualMine::Core::GeoDataType::GDT_WORKINGPLANE)
	{
		insertWorkingplaneFeatureToWorkingPlaneDataset(feature,tableName);
	}
	else if (dataType == VirtualMine::Core::GeoDataType::GDT_MODEL)
	{
#if 1
		CModelFeature* modelfeature = dynamic_cast<CModelFeature*>(feature);

		char **results = NULL;  
		int rc(0);

		CField field1 = modelfeature->getPropertySet()->getFields().at(0);
		int* pID1 = (int*)field1.getVarient().data();
		int id1 = *pID1;

		CField field2 = modelfeature->getPropertySet()->getFields().at(1);
		void* tmp = field2.getVarient().data();
		char*  pName2 = static_cast<char*>(tmp);
		string name1(pName2);

		CField field3 = modelfeature->getPropertySet()->getFields().at(2);
		void* tmp2 = field3.getVarient().data();
		char*  pName3 = static_cast<char*>(tmp2);
		string type(pName3);

		CField field4 = modelfeature->getPropertySet()->getFields().at(3);
		void* tmp3 = field4.getVarient().data();
		double* pWidth1 = static_cast<double*>(tmp3);
		double posx = *pWidth1;


		CField field5 = modelfeature->getPropertySet()->getFields().at(4);
		void* tmp4 = field5.getVarient().data();
		double* pWidth2 = static_cast<double*>(tmp4);
		double posy = *pWidth2;


		CField field6 = modelfeature->getPropertySet()->getFields().at(5);
		void* tmp5 = field6.getVarient().data();
		double* pWidth3 = static_cast<double*>(tmp5);
		double posz = *pWidth3;

		CField field7 = modelfeature->getPropertySet()->getFields().at(6);
		void* tmp6 = field7.getVarient().data();
		double* pscale1 = static_cast<double*>(tmp6);
		double scalex = *pscale1;

		CField field8 = modelfeature->getPropertySet()->getFields().at(7);
		void* tmp7 = field8.getVarient().data();
		double* pscale2 = static_cast<double*>(tmp7);
		double scaley = *pscale2;

		CField field9 = modelfeature->getPropertySet()->getFields().at(8);
		void* tmp8 = field9.getVarient().data();
		double* pscale3 = static_cast<double*>(tmp8);
		double scalez = *pscale3;

		CField field10 = modelfeature->getPropertySet()->getFields().at(9);
		void* tmp9 = field10.getVarient().data();
		double* ptrans1 = static_cast<double*>(tmp9);
		double transx = *ptrans1;

		CField field11 = modelfeature->getPropertySet()->getFields().at(10);
		void* tmp10 = field11.getVarient().data();
		double* ptrans2 = static_cast<double*>(tmp10);
		double transy = *ptrans2;

		CField field12 = modelfeature->getPropertySet()->getFields().at(11);
		void* tmp11 = field12.getVarient().data();
		double* ptrans3 = static_cast<double*>(tmp11);
		double transz = *ptrans3;


		CField field13 = modelfeature->getPropertySet()->getFields().at(12);
		void* tmp12 = field13.getVarient().data();
		double* protate1 = static_cast<double*>(tmp12);
		double rotatex = *protate1;

		CField field14 = modelfeature->getPropertySet()->getFields().at(13);
		void* tmp13 = field14.getVarient().data();
		double* protate2 = static_cast<double*>(tmp13);
		double rotatey = *protate2;

		CField field15 = modelfeature->getPropertySet()->getFields().at(14);
		void* tmp14 = field15.getVarient().data();
		double* protate3 = static_cast<double*>(tmp14);
		double rotatez = *protate3;

		CField field16 = modelfeature->getPropertySet()->getFields().at(15);
		void* tmp15 = field16.getVarient().data();
		double* ptag = static_cast<double*>(tmp15);
		int legth = field16.getVarient().getLength();

		CField field17 = modelfeature->getPropertySet()->getFields().at(16);
		void* tmp16= field17.getVarient().data();
		int* ptag2 = static_cast<int*>(tmp16);
		int detype = *ptag2;



		modelfeature->setDeviceType(VirtualMine::Core::DeviceType(detype));
		sqlite3_stmt * stat;  

		//string nametmp = "insert into ModelDataset(ID,Name,Type,PosX,PosY,PosZ,ScaleX,ScaleY,ScaleZ,TransX,TransY,TransZ,RotateX,RotateY,RotateZ,Tag) values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
		//sqlite3_prepare_v2(mpDB,G2U(nametmp.c_str()), -1,&stat,0);

		std::string insertName = "insert into " + tableName + "(ID,Name,Type,PosX,PosY,PosZ,ScaleX,ScaleY,ScaleZ,TransX,TransY,TransZ,RotateX,RotateY,RotateZ,Tag,DeviceType) values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
		sqlite3_prepare_v2(mpDB,insertName.c_str(), -1,&stat,0);

		sqlite3_bind_int(stat,1,id1);
		sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
		sqlite3_bind_text(stat,3,type.c_str(),strlen(type.c_str()),SQLITE_STATIC);

		sqlite3_bind_double(stat,4,posx);
		sqlite3_bind_double(stat,5,posy);
		sqlite3_bind_double(stat,6,posz);

		sqlite3_bind_double(stat,7,scalex);
		sqlite3_bind_double(stat,8,scaley);
		sqlite3_bind_double(stat,9,scalez);

		sqlite3_bind_double(stat,10,transx);
		sqlite3_bind_double(stat,11,transy);
		sqlite3_bind_double(stat,12,transz);

		sqlite3_bind_double(stat,13,rotatex);
		sqlite3_bind_double(stat,14,rotatey);
		sqlite3_bind_double(stat,15,rotatez);

		sqlite3_bind_blob(stat,16, ptag,legth, NULL );

		sqlite3_bind_int(stat,17,detype);
		
		rc = sqlite3_step(stat);  

		sqlite3_finalize( stat );

		return rc;
#endif
	}
	//else if (dataType == VirtualMine::Core::GeoDataType::GDT_ESCAPEROUTE)
	//{
	//	this->insertEscapeRouteFeatureToEscapeRouteDataset(feature,tableName);
	//}

}



////插入的参数为ifeature，表为默认的；
int CSQLiteDatabase::insertLanewayFeatureToLanewayDataset(VirtualMine::Database::IFeature* lanewayFeature)
{
	if (lanewayFeature == NULL)
	{
		return -1;
	}
	char **results = NULL;  
	int rc(1);

	CLanewayFeature *feature = dynamic_cast<CLanewayFeature*>(lanewayFeature);
	CField field1 = feature->getPropertySet()->getFields().at(1);	
	void* tmp = field1.getVarient().data();
	const char*  pName2 = static_cast<const char*>(tmp);
	string name1(pName2);


	CField field2 = feature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field2.getVarient().data();
	int id1 = *pID1;


	CField field3 = feature->getPropertySet()->getFields().at(2);
	//string* pType1 = (string*)field3.getVarient().data(); 
	const char*  pType1 = (const char* )field3.getVarient().data();
	string type1(pType1);

	CField field4 = feature->getPropertySet()->getFields().at(3);
	void* tmp2 = field4.getVarient().data();
	float* pWidth1 = static_cast<float*>(tmp2);
	float width1 = *pWidth1;

	CField field5 = feature->getPropertySet()->getFields().at(4);
	void* tmp3 = field4.getVarient().data();
	float* pHeight1 = static_cast<float*>(tmp3);
	float height1 = *pHeight1;


	CField field7 = feature->getPropertySet()->getFields().at(5);
	void* tmp4 = field7.getVarient().data();
	int* psectiontype1 = static_cast<int*>(tmp4);
	int sectiontype = *psectiontype1;

	CField field8 = feature->getPropertySet()->getFields().at(6);
	void* tmp5 = field8.getVarient().data();
	int* psupporttype = static_cast<int*>(tmp5);
	int supporttype = *psupporttype;



	CField field6 = feature->getPropertySet()->getFields().at(7);
	void* pData = field6.getVarient().data();
	char*  pGeometry =  (char* )pData;
	int legth = field6.getVarient().getLength();
	//char* sql = "insert into LanewayDataset(ID%d,Name%s,Type%s,Width%f) values(%d,%s,%s,%f),id1,name1,type1,width1";

	//stringstream ss;
	//stringstream ss2;
	//string idstr;
	//string widthstr2;
	//ss<<id1;
	//ss>>idstr;
	//ss2<<width1;
	//ss2>>widthstr2;
	//
	//string sql = "insert into LanewayDataset(ID,Name,Type,Width) values('"+idstr+"','"+name1+"','"+type1+"','"+widthstr2+"')";

	//
	////rc = sqlite3_exec(mpDB,"insert into LanewayDataset(ID, Name, Type, Width, Geometry) values('10', 'lane1', 'type', '5.0', 'dddd')",NULL,NULL,results);
	//
	//rc = sqlite3_exec(mpDB,sql.c_str(),NULL,NULL,results);

	CField field9 = feature->getPropertySet()->getFields().at(8);
	void* tmp8 = field9.getVarient().data();
	int* planewaywindtype = static_cast<int*>(tmp8);
	int lanewayWindType = *planewaywindtype;

	sqlite3_stmt * stat;  
	//sqlite3_prepare( mpDB,"insert into LanewayDataset(Geometry) values( ? )", -1, &stat, 0 ); 
	string nametmp = "insert into LanewayDataset(ID,Name,Type,Width,Height,SectionType,SupportType,Geometry,LanewayWindType) values(?,?,?,?,?,?,?,?,?)";

	//sqlite3_prepare_v2(mpDB,G2U(nametmp.c_str()), -1,&stat,0);

	sqlite3_prepare_v2(mpDB,"insert into LanewayDataset(ID,Name,Type,Width,Height,SectionType,SupportType,Geometry,LanewayWindType) values(?,?,?,?,?,?,?,?,?)", -1,&stat,0);
	sqlite3_bind_int(stat,1,id1);
	//sqlite3_bind_text(stat,2,name1,strlen(name1.c_str()),SQLITE_TRANSIENT);
	rc = sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_TRANSIENT);
	//sqlite3_bind_text(stat,2,G2U(name1.c_str()),strlen(name1.c_str()),SQLITE_STATIC);
	sqlite3_bind_text(stat,3,pType1,strlen(type1.c_str()),SQLITE_STATIC);
	sqlite3_bind_double(stat,4,width1);
	sqlite3_bind_double(stat,5,height1);
	sqlite3_bind_int(stat,6,sectiontype);
	sqlite3_bind_int(stat,7,supporttype);


	//sqlite3_bind_blob(stat,5, pGeometry, strlen(pGeometry), NULL );
	sqlite3_bind_blob(stat,8, pGeometry,legth, NULL );
	sqlite3_bind_int(stat,9,lanewayWindType);


	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;
}

int CSQLiteDatabase::insertCoalLayerFeatureToCoalLayerDataset(VirtualMine::Database::IFeature* coallayerfeature)
{
	//char **results = NULL;  
	//int rc(1);
	//CCoalLayerFeature *feature = dynamic_cast<CCoalLayerFeature*>(coallayerfeature);

	//CField field1 = feature->getPropertySet()->getFields().at(0);
	//int* pID1 = (int*)field1.getVarient().data();
	//int id1 = *pID1;

	//CField field2 =  feature->getPropertySet()->getFields().at(1);
	//void* tmp = field2.getVarient().data();
	//char*  pName2 = static_cast<char*>(tmp);
	//string name1(pName2);

	//CField field3 = feature->getPropertySet()->getFields().at(2);
	//void* pData = field3.getVarient().data();
	//char*  pGeometry =  (char* )pData;
	//int legth = field3.getVarient().getLength();

	//CField field4 = feature->getPropertySet()->getFields().at(3);
	//void* pData2 = field4.getVarient().data();
	//char*  pTexture =  (char* )pData2;
	//int legth2 = field4.getVarient().getLength();

	//sqlite3_stmt * stat;  
	//const char* tmpp = "insert into CoalLayerDataset(ID,Name,Geometry,Texture) values(?,?,?,?)";
	//sqlite3_prepare_v2(mpDB,G2U(tmpp), -1,&stat,0);
	////sqlite3_prepare_v2(mpDB,"insert into CoalLayerDataset(ID,Name,Geometry,Texture) values(?,?,?,?)", -1,&stat,0);

	//sqlite3_bind_int(stat,1,id1);
	//sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	//sqlite3_bind_blob(stat,3,pGeometry,legth,NULL);
	//sqlite3_bind_blob(stat,4,pTexture,legth2,NULL);

	//rc = sqlite3_step( stat );  

	//sqlite3_finalize( stat );

	//return rc;

	if (coallayerfeature == NULL)
	{
		return -1;
	}

	char **results = NULL;  
	int rc(1);

	CCoalLayerFeature* feature = dynamic_cast<CCoalLayerFeature*>(coallayerfeature);

	///////向煤层数据集里添加feature
	//int count = this->mpDatasetSet->size();
	//for (int i = 0; i < count; i++)
	//{
	//	IDataset* dataset = this->mpDatasetSet->at(i);
	//	if (dataset && dataset->getType() == GeoDataType::GDT_COALSEAM)
	//	{
	//		dataset->addFeature(*feature);
	//	}

	//}



	CField field1 = feature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = feature->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);

	CField field3 = feature->getPropertySet()->getFields().at(2);
	void* pData = field3.getVarient().data();
	char*  pGeometry =  (char* )pData;
	int legth = field3.getVarient().getLength();

	CField field4 = feature->getPropertySet()->getFields().at(3);
	void* pData2 = field4.getVarient().data();
	char*  pTexture =  (char* )pData2;
	int legth2 = field4.getVarient().getLength();

	sqlite3_stmt * stat;  
	string nametmp = "insert into CoalLayerDataset(ID,Name,Geometry,Texture) values(?,?,?,?)";
	sqlite3_prepare_v2(mpDB,G2U(nametmp.c_str()), -1,&stat,0);

	sqlite3_bind_int(stat,1,id1);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	sqlite3_bind_blob(stat,3,pGeometry,legth,NULL);
	sqlite3_bind_blob(stat,4,pTexture,legth2,NULL);

	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;

}

int CSQLiteDatabase::insertDrillingFeatureToDrillingDataset(VirtualMine::Database::IFeature* drillingfeature)
{
	if (drillingfeature == NULL)
	{
		return -1;
	}

	char **results = NULL;  
	int rc(1);

	CDrillingFeature *feature = dynamic_cast<CDrillingFeature*>(drillingfeature); 

	///////向钻孔数据集里添加feature
	//int count = this->mpDatasetSet->size();
	//for (int i = 0; i < count; i++)
	//{
	//	IDataset* dataset = this->mpDatasetSet->at(i);
	//	if (dataset && dataset->getType() == GeoDataType::GDT_DRILL )
	//	{
	//		dataset->addFeature(*feature);
	//	}

	//}



	CField field1 = feature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = feature->getPropertySet()->getFields().at(1);
	void*  tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);
	//field2.getVarient().getValue(name1);

	CField field3 = feature->getPropertySet()->getFields().at(2);
	void*  pPosX = field3.getVarient().data();
	double* pX = static_cast<double*>(pPosX);
	double posX = *pX;

	CField field4 = feature->getPropertySet()->getFields().at(3);
	void* pPosY = field4.getVarient().data();
	double* pY = static_cast<double*>(pPosY);
	double posY = *pY;

	CField field5 = feature->getPropertySet()->getFields().at(4);
	void* pPosZ = field5.getVarient().data();
	double* pZ = static_cast<double*>(pPosZ);
	double posZ = *pZ;

	CField field6 = feature->getPropertySet()->getFields().at(5);
	void* pData = field6.getVarient().data();
	int length = field6.getVarient().getLength();

	Ogre::uchar*  pGeoLayerInfo =  (Ogre::uchar* )pData;



	sqlite3_stmt * stat;  

	string nametmp = "insert into DrillingDataset(ID,Name,PositionX,PositionY,PositionZ,GeoLayerInfo) values(?,?,?,?,?,?)";
	sqlite3_prepare_v2(mpDB,nametmp.c_str(), -1,&stat,0);
	sqlite3_bind_int(stat,1,id1);
	//sqlite3_bind_text(stat,2,name1,strlen(name1.c_str()),SQLITE_TRANSIENT);
	//rc = sqlite3_bind_text(stat,2,name1,strlen(name1.c_str()),SQLITE_TRANSIENT);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	//sqlite3_bind_text(stat,3,type1.c_str(),strlen(type1.c_str()),SQLITE_STATIC);
	sqlite3_bind_double(stat,3,posX);
	sqlite3_bind_double(stat,4,posY);
	sqlite3_bind_double(stat,5,posZ);

	//sqlite3_bind_blob(stat,5, pGeometry, strlen(pGeometry), NULL );
	sqlite3_bind_blob(stat,6, pGeoLayerInfo, length, NULL );

	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	/*sqlite3_close(mpDB);*/
	return rc;
}

int CSQLiteDatabase::insertLogicFeatureToLogicDataset(VirtualMine::Database::IFeature* logicfeature)
{

	if (logicfeature == NULL )
	{
		return -1;
	}

	char **results = NULL;  
	int rc(1);

	CLogicFeature* feature = dynamic_cast<CLogicFeature*>(logicfeature);

	///////向逻辑数据集里添加feature
	//int count = this->mpDatasetSet->size();
	//for (int i = 0; i < count; i++)
	//{
	//	IDataset* dataset = this->mpDatasetSet->at(i);
	//	if (dataset && dataset->getType() == "LogicDataset")
	//	{
	//		dataset->addFeature(*feature);
	//	}

	//}



	CField field1 = feature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = feature->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);
	//field2.getVarient().getValue(name1);

	CField field3 = feature->getPropertySet()->getFields().at(2);
	char*  pType1 = (char* )field3.getVarient().data();
	string type1(pType1);

	CField field4 = feature->getPropertySet()->getFields().at(3);
	void* tmp2 = field4.getVarient().data();
	double* pWidth1 = static_cast<double*>(tmp2);
	double minRangeX = *pWidth1;

	CField field5 = feature->getPropertySet()->getFields().at(4);
	void* tmp3 = field5.getVarient().data();
	double* prY = static_cast<double*>(tmp3);
	double minRangeY = *prY;

	CField field6 = feature->getPropertySet()->getFields().at(5);
	void* tmp4 = field6.getVarient().data();
	double* prZ = static_cast<double*>(tmp4);
	double minRangeZ = *prZ;

	CField field7 = feature->getPropertySet()->getFields().at(6);
	void* tmp5 = field7.getVarient().data();
	double* prmaxX = static_cast<double*>(tmp5);
	double maxRangeX = *prmaxX;

	CField field8 = feature->getPropertySet()->getFields().at(7);
	void* tmp6 = field8.getVarient().data();
	double* prmaxY = static_cast<double*>(tmp6);
	double maxRangeY = *prmaxY;

	CField field9 = feature->getPropertySet()->getFields().at(8);
	void* tmp7 = field9.getVarient().data();
	double* prmaxZ = static_cast<double*>(tmp7);
	double maxRangeZ = *prmaxZ;

	sqlite3_stmt * stat;  
	sqlite3_prepare_v2(mpDB,"insert into LogicDataset(ID,Name,Type,minRangeX,minRangeY,minRangeZ,maxRangeX,maxRangeY,maxRangeZ) values(?,?,?,?,?,?,?,?,?)", -1,&stat,0);

	sqlite3_bind_int(stat,1,id1);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	sqlite3_bind_text(stat,3,type1.c_str(),strlen(type1.c_str()),SQLITE_STATIC);

	sqlite3_bind_double(stat,4,minRangeX);
	sqlite3_bind_double(stat,5,minRangeY);
	sqlite3_bind_double(stat,6,minRangeZ);

	sqlite3_bind_double(stat,7,maxRangeX);
	sqlite3_bind_double(stat,8,maxRangeY);
	sqlite3_bind_double(stat,9,maxRangeZ);

	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;
}

int CSQLiteDatabase::insertImageFeatureToImageDataset(VirtualMine::Database::IFeature* imagefeature)
{
	if (imagefeature == NULL)
	{
		return -1;
	}

	char **results = NULL;  
	int rc(0);

	CImageFeature * feature = dynamic_cast<CImageFeature*>(imagefeature);

	///////向影像数据集里添加feature
	//int count = this->mpDatasetSet->size();
	//for (int i = 0; i < count; i++)
	//{
	//	IDataset* dataset = this->mpDatasetSet->at(i);
	//	if (dataset && dataset->getType() == GeoDataType::GDT_IMAGE)
	//	{
	//		dataset->addFeature(*feature);
	//	}

	//}

	CField field1 = feature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = feature->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);

	CField field3 = feature->getPropertySet()->getFields().at(2);
	void* tmp2 = field3.getVarient().data();
	int legth = field3.getVarient().getLength();

	sqlite3_stmt * stat;  


	sqlite3_prepare_v2(mpDB,"insert into ImageDataset(ID,Name,Image) values(?,?,?)", -1,&stat,0);

	sqlite3_bind_int(stat,1,id1);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	sqlite3_bind_blob(stat,3, tmp2,legth, NULL );

	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;

}




////////插入的参数为ifeature 和 表名称
int CSQLiteDatabase::insertLanewayFeatureToLanewayDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName)
{
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	QTextCodec::setCodecForTr(codec);
	//QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

	CLanewayFeature* lanewayFeature = dynamic_cast<CLanewayFeature*>(feature);

	char **results = NULL;  
	int rc(1);

	CField field1 = lanewayFeature->getPropertySet()->getFields().at(1);	
	void* tmp = field1.getVarient().data();
	const char*  pName2 = static_cast<const char*>(tmp);
	string name1(pName2);


	CField field2 = lanewayFeature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field2.getVarient().data();
	int id1 = *pID1;


	CField field3 = lanewayFeature->getPropertySet()->getFields().at(2);
	//string* pType1 = (string*)field3.getVarient().data(); 
	const char*  pType1 = (const char* )field3.getVarient().data();
	string type1(pType1);

	CField field4 = lanewayFeature->getPropertySet()->getFields().at(3);
	void* tmp2 = field4.getVarient().data();
	float* pWidth1 = static_cast<float*>(tmp2);
	float width1 = *pWidth1;

	CField field5 = lanewayFeature->getPropertySet()->getFields().at(4);
	void* tmp3 = field4.getVarient().data();
	float* pHeight1 = static_cast<float*>(tmp3);
	float height1 = *pHeight1;


	CField field7 = lanewayFeature->getPropertySet()->getFields().at(5);
	void* tmp4 = field7.getVarient().data();
	int* psectiontype1 = static_cast<int*>(tmp4);
	int sectiontype = *psectiontype1;

	CField field8 = lanewayFeature->getPropertySet()->getFields().at(6);
	void* tmp5 = field8.getVarient().data();
	int* psupporttype = static_cast<int*>(tmp5);
	int supporttype = *psupporttype;



	CField field6 = lanewayFeature->getPropertySet()->getFields().at(7);
	void* pData = field6.getVarient().data();
	char*  pGeometry =  (char* )pData;
	int legth = field6.getVarient().getLength();
	//char* sql = "insert into LanewayDataset(ID%d,Name%s,Type%s,Width%f) values(%d,%s,%s,%f),id1,name1,type1,width1";

	//stringstream ss;
	//stringstream ss2;
	//string idstr;
	//string widthstr2;
	//ss<<id1;
	//ss>>idstr;
	//ss2<<width1;
	//ss2>>widthstr2;
	//
	//string sql = "insert into LanewayDataset(ID,Name,Type,Width) values('"+idstr+"','"+name1+"','"+type1+"','"+widthstr2+"')";

	//
	////rc = sqlite3_exec(mpDB,"insert into LanewayDataset(ID, Name, Type, Width, Geometry) values('10', 'lane1', 'type', '5.0', 'dddd')",NULL,NULL,results);
	//
	//rc = sqlite3_exec(mpDB,sql.c_str(),NULL,NULL,results);

	CField field9 = lanewayFeature->getPropertySet()->getFields().at(8);
	void* tmp8 = field9.getVarient().data();
	int* planewaywindtype = static_cast<int*>(tmp8);
	int lanewayWindType = *planewaywindtype;

	sqlite3_stmt * stat;  
	//sqlite3_prepare( mpDB,"insert into LanewayDataset(Geometry) values( ? )", -1, &stat, 0 ); 
	//string nametmp = "insert into LanewayDataset(ID,Name,Type,Width,Height,SectionType,SupportType,Geometry,LanewayWindType) values(?,?,?,?,?,?,?,?,?)";
	string nametmp = "insert into " + tableName + "(ID,Name,Type,Width,Height,SectionType,SupportType,Geometry,LanewayWindType) values(?,?,?,?,?,?,?,?,?)";




	//sqlite3_prepare_v2(mpDB,G2U(nametmp.c_str()), -1,&stat,0);

	sqlite3_prepare_v2(mpDB,nametmp.c_str(), -1,&stat,0);
	sqlite3_bind_int(stat,1,id1);
	//sqlite3_bind_text(stat,2,name1,strlen(name1.c_str()),SQLITE_TRANSIENT);
	rc = sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_TRANSIENT);
	//sqlite3_bind_text(stat,2,G2U(name1.c_str()),strlen(name1.c_str()),SQLITE_STATIC);
	sqlite3_bind_text(stat,3,pType1,strlen(type1.c_str()),SQLITE_STATIC);
	sqlite3_bind_double(stat,4,width1);
	sqlite3_bind_double(stat,5,height1);
	sqlite3_bind_int(stat,6,sectiontype);
	sqlite3_bind_int(stat,7,supporttype);


	//sqlite3_bind_blob(stat,5, pGeometry, strlen(pGeometry), NULL );
	sqlite3_bind_blob(stat,8, pGeometry,legth, NULL );
	sqlite3_bind_int(stat,9,lanewayWindType);


	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;

}

int CSQLiteDatabase::insertCoalLayerFeatureToCoalLayerDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName)
{

	CCoalLayerFeature* coallayerfeature = dynamic_cast<CCoalLayerFeature*>(feature);
	char **results = NULL;  
	int rc(1);

	CField field1 = coallayerfeature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = coallayerfeature->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);

	CField field3 = coallayerfeature->getPropertySet()->getFields().at(2);
	void* pData = field3.getVarient().data();
	char*  pGeometry =  (char* )pData;
	int legth = field3.getVarient().getLength();

	CField field4 = coallayerfeature->getPropertySet()->getFields().at(3);
	void* pData2 = field4.getVarient().data();
	char*  pTexture =  (char* )pData2;
	int legth2 = field4.getVarient().getLength();

	sqlite3_stmt * stat;  
	string nametmp = "insert into " + tableName + "(ID,Name,Geometry,Texture) values(?,?,?,?)";
	sqlite3_prepare_v2(mpDB,G2U(nametmp.c_str()), -1,&stat,0);

	sqlite3_bind_int(stat,1,id1);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	sqlite3_bind_blob(stat,3,pGeometry,legth,NULL);
	sqlite3_bind_blob(stat,4,pTexture,legth2,NULL);

	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;


}

 int CSQLiteDatabase::insertTerraneFeatureToCoalLayerDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName)
 {
	 CTerraneFeature* terranefeature = dynamic_cast<CTerraneFeature*>(feature);

	 char **results = NULL;  
	 int rc(1);

	 int proID = terranefeature->getFieldID();
	 
	 std::string name = terranefeature->getFieldName();
	 std::string type = terranefeature->getFieldRockType();


	 CField field4 = terranefeature->getPropertySet()->getFields().at(3);
	 void* pData2 = field4.getVarient().data();
	 char*  pTexture =  (char* )pData2;
	 int legth2 = field4.getVarient().getLength();

	 sqlite3_stmt * stat;  
	 string nametmp = "insert into " + tableName + "(ID,Name,RockType,Geometry) values(?,?,?,?)";
	 sqlite3_prepare_v2(mpDB,G2U(nametmp.c_str()), -1,&stat,0);

	 sqlite3_bind_int(stat,1,proID);
	 sqlite3_bind_text(stat,2,name.c_str(),strlen(name.c_str()),SQLITE_STATIC);
	 sqlite3_bind_text(stat,3,type.c_str(),strlen(type.c_str()),SQLITE_STATIC);
	 sqlite3_bind_blob(stat,4,pTexture,legth2,NULL);

	 rc = sqlite3_step( stat );  

	 sqlite3_finalize( stat );

	 return rc;
 }

int CSQLiteDatabase::insertDrillingFeatureToDrillingDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName)
{
	VirtualMine::Database::CDrillingFeature* drillingFeature = dynamic_cast<VirtualMine::Database::CDrillingFeature*>(feature);

	///////向钻孔数据集里添加feature
	//int count = this->mpDatasetSet->size();
	//for (int i = 0; i < count; i++)
	//{
	//	IDataset* dataset = this->mpDatasetSet->at(i);
	//	if (dataset && dataset->getType() == GeoDataType::GDT_DRILL && dataset->getName() == tableName)
	//	{
	//		dataset->addFeature(*feature);
	//	}

	//}



	char **results = NULL;  
	int rc(1);	

	CField field1 = drillingFeature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = drillingFeature->getPropertySet()->getFields().at(1);
	void*  tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);
	//field2.getVarient().getValue(name1);

	CField field3 = drillingFeature->getPropertySet()->getFields().at(2);
	void*  pPosX = field3.getVarient().data();
	double* pX = static_cast<double*>(pPosX);
	double posX = *pX;

	CField field4 = drillingFeature->getPropertySet()->getFields().at(3);
	void* pPosY = field4.getVarient().data();
	double* pY = static_cast<double*>(pPosY);
	double posY = *pY;

	CField field5 = drillingFeature->getPropertySet()->getFields().at(4);
	void* pPosZ = field5.getVarient().data();
	double* pZ = static_cast<double*>(pPosZ);
	double posZ = *pZ;

	CField field6 = drillingFeature->getPropertySet()->getFields().at(5);
	void* pData = field6.getVarient().data();
	int length = field6.getVarient().getLength();

	Ogre::uchar*  pGeoLayerInfo =  (Ogre::uchar* )pData;



	sqlite3_stmt * stat;  

	string nametmp = "insert into " + tableName + "(ID,Name,PositionX,PositionY,PositionZ,GeoLayerInfo) values(?,?,?,?,?,?)";
	sqlite3_prepare_v2(mpDB,nametmp.c_str(), -1,&stat,0);
	sqlite3_bind_int(stat,1,id1);
	//sqlite3_bind_text(stat,2,name1,strlen(name1.c_str()),SQLITE_TRANSIENT);
	//rc = sqlite3_bind_text(stat,2,name1,strlen(name1.c_str()),SQLITE_TRANSIENT);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	//sqlite3_bind_text(stat,3,type1.c_str(),strlen(type1.c_str()),SQLITE_STATIC);
	sqlite3_bind_double(stat,3,posX);
	sqlite3_bind_double(stat,4,posY);
	sqlite3_bind_double(stat,5,posZ);

	//sqlite3_bind_blob(stat,5, pGeometry, strlen(pGeometry), NULL );
	sqlite3_bind_blob(stat,6, pGeoLayerInfo, length, NULL );

	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	/*sqlite3_close(mpDB);*/
	return rc;
}

int CSQLiteDatabase::insertImageFeatureToImageDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName)
{
	CImageFeature* imagefeature = dynamic_cast<CImageFeature*>(feature);

	///////向影像数据集里添加feature
	//int count = this->mpDatasetSet->size();
	//for (int i = 0; i < count; i++)
	//{
	//	IDataset* dataset = this->mpDatasetSet->at(i);
	//	if (dataset && dataset->getType() == GeoDataType::GDT_IMAGE && dataset->getName() == tableName)
	//	{
	//		dataset->addFeature(*feature);
	//	}

	//}

	char **results = NULL;  
	int rc(0);

	CField field1 = imagefeature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = imagefeature->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);

	CField field3 = imagefeature->getPropertySet()->getFields().at(2);
	void* tmp2 = field3.getVarient().data();
	int legth = field3.getVarient().getLength();

	double minX = imagefeature->getFieldMinPosX();
	double minY = imagefeature->getFieldMinPosY();
	double minZ = imagefeature->getFieldMinPosZ();

	double maxX = imagefeature->getFieldMaxPosX();
	double maxY = imagefeature->getFieldMaxPosY();
	double maxZ = imagefeature->getFieldMaxPosZ();




	sqlite3_stmt * stat;  

	std::string insertName = "insert into " + tableName + "(ID,Name,Image,MinPosX,MinPosY,MinPosZ,MaxPosX,MaxPosY,MaxPosZ) values(?,?,?,?,?,?,?,?,?)";
	sqlite3_prepare_v2(mpDB,insertName.c_str(), -1,&stat,0);

	sqlite3_bind_int(stat,1,id1);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	sqlite3_bind_blob(stat,3, tmp2,legth, NULL );
	sqlite3_bind_double(stat,4,minX);
	sqlite3_bind_double(stat,5,minY);
	sqlite3_bind_double(stat,6,minZ);
	sqlite3_bind_double(stat,7,maxX);
	sqlite3_bind_double(stat,8,maxY);
	sqlite3_bind_double(stat,9,maxZ);

	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;
}

int CSQLiteDatabase::insertMetaDataFeatureToMetaDataset(VirtualMine::Database::IFeature* metadatafeature)
{

	if (metadatafeature == NULL)
	{
		return -1;
	}

	char **results = NULL;  
	int rc(0);

	CMetadataFeature* feature = dynamic_cast<CMetadataFeature*>(metadatafeature);

	///////向元数据集里添加feature
	//int count = this->mpDatasetSet->size();
	//for (int i = 0; i < count; i++)
	//{
	//	IDataset* dataset = this->mpDatasetSet->at(i);
	//	if (dataset && dataset->getType() == "Metadata")
	//	{
	//		dataset->addFeature(*feature);
	//	}

	//}


	CField field1 = feature->getPropertySet()->getFields().at(0);
	void* pID1 = field1.getVarient().data();
	char*  pName = static_cast<char*>(pID1);
	string name  = pName;


	CField field2 = feature->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	int*  pName2 = static_cast<int*>(tmp);
	int rs(*pName2);


	CField field3 = feature->getPropertySet()->getFields().at(2);
	void* tmp2 = field3.getVarient().data();
	char*  pName3 = static_cast<char*>(tmp2);
	string type(pName3);

	CField field4 = feature->getPropertySet()->getFields().at(3);
	void* tmp3 = field4.getVarient().data();
	double*  pminx = static_cast<double*>(tmp3);
	double minX(*pminx);

	CField field5 = feature->getPropertySet()->getFields().at(4);
	void* tmp4 = field5.getVarient().data();
	double*  pminy = static_cast<double*>(tmp4);
	double minY(*pminy);

	CField field6 = feature->getPropertySet()->getFields().at(5);
	void* tmp5 = field6.getVarient().data();
	double*  pminz = static_cast<double*>(tmp5);
	double minZ(*pminz);



	CField field7 = feature->getPropertySet()->getFields().at(6);
	void* tmp6 = field7.getVarient().data();
	double*  pmaxx = static_cast<double*>(tmp6);
	double maxX(*pmaxx);

	CField field8 = feature->getPropertySet()->getFields().at(7);
	void* tmp7 = field8.getVarient().data();
	double*  pmaxy = static_cast<double*>(tmp7);
	double maxY(*pmaxy);

	CField field9 = feature->getPropertySet()->getFields().at(8);
	void* tmp8 = field9.getVarient().data();
	double*  pmaxz = static_cast<double*>(tmp8);
	double maxZ(*pmaxz);



	sqlite3_stmt * stat;  

	//string nametmp = "insert into MetadataDataset(Name,SpatialReference,Type,minRangeX,minRangeY,minRangeZ,maxRangeX,maxRangeY,maxRangeZ) values(?,?,?,?,?,?,?,?,?)";
	//sqlite3_prepare_v2(mpDB,G2U(nametmp.c_str()), -1,&stat,0);
	sqlite3_prepare_v2(mpDB,"insert into MetadataDataset(Name,SpatialReference,Type,minRangeX,minRangeY,minRangeZ,maxRangeX,maxRangeY,maxRangeZ) values(?,?,?,?,?,?,?,?,?)", -1,&stat,0);


	sqlite3_bind_int(stat,2,rs);
	sqlite3_bind_text(stat,1,name.c_str(),strlen(name.c_str()),SQLITE_STATIC);
	sqlite3_bind_blob(stat,3,type.c_str(),strlen(type.c_str()), SQLITE_STATIC );
	sqlite3_bind_double(stat,4,minX);
	sqlite3_bind_double(stat,5,minY);
	sqlite3_bind_double(stat,6,minZ);

	sqlite3_bind_double(stat,7,maxX);
	sqlite3_bind_double(stat,8,maxY);
	sqlite3_bind_double(stat,9,maxZ);

	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;
}

int CSQLiteDatabase::insertFaultLayerFeatureToFaultLayerDataset(VirtualMine::Database::IFeature* faultlayerfeature)
{
	  return -1;
}


//// 没写完
int CSQLiteDatabase::insertFaultLayerFeatureToFaultLayerDataset(VirtualMine::Database::IFeature* faultlayerfeature,const std::string& tableName)
{
	CFaultLayerFeature* faultfeature = dynamic_cast<CFaultLayerFeature*>(faultlayerfeature);

	///////工作面数据集里添加feature
	//int count = this->mpDatasetSet->size();
	//for (int i = 0; i < count; i++)
	//{
	//	IDataset* dataset = this->mpDatasetSet->at(i);
	//	if (dataset && dataset->getType() == GeoDataType::GDT_WORKINGPLANE && dataset->getName() == tableName)
	//	{
	//		dataset->addFeature(*feature);
	//	}

	//}

	char **results = NULL;  
	int rc(0);

	CField field1 = faultfeature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = faultfeature->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);

	CField field3 = faultfeature->getPropertySet()->getFields().at(2);
	void* tmp3 = field3.getVarient().data();
	double* pName3 = static_cast<double*>(tmp3);
	double digAngle = *pName3;

	CField field4 = faultfeature->getPropertySet()->getFields().at(3);
	void* tmp4 = field4.getVarient().data();
	double*  pName4 = static_cast<double*>(tmp4);
	double upH = *pName4;

	CField field5 = faultfeature->getPropertySet()->getFields().at(4);
	void* tmp5 = field5.getVarient().data();
	double*  pName5 = static_cast<double*>(tmp5);
	double downH = *pName5;


	CField field6 = faultfeature->getPropertySet()->getFields().at(5);
	void* tmp6 = field6.getVarient().data();
	int legth = field6.getVarient().getLength();

	sqlite3_stmt * stat;  

	std::string insertName = "insert into " + tableName + "(ID,Name,DipAngle,UpLength,DownLength,Geometry) values(?,?,?,?,?,?)";
	sqlite3_prepare_v2(mpDB,insertName.c_str(), -1,&stat,0);

	sqlite3_bind_int(stat,1,id1);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	
	sqlite3_bind_double(stat,3,digAngle);
	sqlite3_bind_double(stat,4,upH);
	sqlite3_bind_double(stat,5,downH);

	sqlite3_bind_blob(stat,6, tmp6,legth, NULL );

	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;

}

int CSQLiteDatabase::insertDEMFeatureToDEMDataset( VirtualMine::Database::IFeature* demfeature)
{
	char **results = NULL;  
	int rc(0);

	CDEMFeature* feature = dynamic_cast<CDEMFeature*>(demfeature);

	///////向DEM数据集里添加feature
	//int count = this->mpDatasetSet->size();
	//for (int i = 0; i < count; i++)
	//{
	//	IDataset* dataset = this->mpDatasetSet->at(i);
	//	if (dataset && dataset->getType() == GeoDataType::GDT_DEM)
	//	{
	//		dataset->addFeature(*feature);
	//	}

	//}


	CField field1 = feature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = feature->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);

	CField field3 = feature->getPropertySet()->getFields().at(2);
	void* tmp2 = field3.getVarient().data();
	int legth = field3.getVarient().getLength();

	sqlite3_stmt * stat;  
	sqlite3_prepare_v2(mpDB,"insert into DEMDataset(ID,Name,Geometry) values(?,?,?)", -1,&stat,0);

	sqlite3_bind_int(stat,1,id1);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	sqlite3_bind_blob(stat,3, tmp2,legth, NULL );

	rc = sqlite3_step( stat );  


	sqlite3_finalize( stat );

	return rc;
}

int CSQLiteDatabase::insertDEMFeatureToDEMDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName)
{
	char **results = NULL;  
	int rc(0);

	CDEMFeature* demfeature = dynamic_cast<CDEMFeature*>(feature);


	///////向DEM数据集里添加feature
	//int count = this->mpDatasetSet->size();
	//for (int i = 0; i < count; i++)
	//{
	//	IDataset* dataset = this->mpDatasetSet->at(i);
	//	if (dataset && dataset->getType() == GeoDataType::GDT_DEM && dataset->getName() == tableName)
	//	{
	//		dataset->addFeature(*feature);
	//	}

	//}


	CField field1 = demfeature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = demfeature->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);

	CField field3 = demfeature->getPropertySet()->getFields().at(2);
	void* tmp2 = field3.getVarient().data();
	int legth = field3.getVarient().getLength();

	sqlite3_stmt * stat;  

	std::string insertName = "insert into " + tableName + "(ID,Name,Geometry) values(?,?,?)";
	sqlite3_prepare_v2(mpDB,insertName.c_str(), -1,&stat,0);

	sqlite3_bind_int(stat,1,id1);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	sqlite3_bind_blob(stat,3, tmp2,legth, NULL );

	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;
}

int CSQLiteDatabase::insertWorkingplaneFeatureToWorkingPlaneDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName)
{
	CWorkingplaneFeature* imagefeature = dynamic_cast<CWorkingplaneFeature*>(feature);

	///////工作面数据集里添加feature
	//int count = this->mpDatasetSet->size();
	//for (int i = 0; i < count; i++)
	//{
	//	IDataset* dataset = this->mpDatasetSet->at(i);
	//	if (dataset && dataset->getType() == GeoDataType::GDT_WORKINGPLANE && dataset->getName() == tableName)
	//	{
	//		dataset->addFeature(*feature);
	//	}

	//}

	char **results = NULL;  
	int rc(0);

	CField field1 = imagefeature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = imagefeature->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);

	CField field3 = imagefeature->getPropertySet()->getFields().at(2);
	void* tmp2 = field3.getVarient().data();
	int legth = field3.getVarient().getLength();

	sqlite3_stmt * stat;  

	std::string insertName = "insert into " + tableName + "(ID,Name,Geometry) values(?,?,?)";
	sqlite3_prepare_v2(mpDB,insertName.c_str(), -1,&stat,0);

	sqlite3_bind_int(stat,1,id1);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	sqlite3_bind_blob(stat,3, tmp2,legth, NULL );

	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;
}

int CSQLiteDatabase::insertModelFeatureToModelDataset( VirtualMine::Database::IFeature* modelfeature,std::string modeldatasetName)
{

	if (modelfeature == NULL)
	{
		return -1;
	}

	VirtualMine::Database::CModelFeature* modelfeature2 = dynamic_cast<VirtualMine::Database::CModelFeature*>(modelfeature);

	///////模型数据集里添加feature
	//int count = this->mpDatasetSet->size();
	//for (int i = 0; i < count; i++)
	//{
	//	IDataset* dataset = this->mpDatasetSet->at(i);
	//	if (dataset && dataset->getType() == GeoDataType::GDT_MODEL && dataset->getName() == modeldatasetName)
	//	{
	//		dataset->addFeature(*modelfeature2);
	//	}

	//}


	char **results = NULL;  
	int rc(0);

	CField field1 = modelfeature2->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = modelfeature2->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);

	CField field3 = modelfeature2->getPropertySet()->getFields().at(2);
	void* tmp2 = field3.getVarient().data();
	char*  pName3 = static_cast<char*>(tmp2);
	string type(pName3);

	CField field4 = modelfeature2->getPropertySet()->getFields().at(3);
	void* tmp3 = field4.getVarient().data();
	double* pWidth1 = static_cast<double*>(tmp3);
	double posx = *pWidth1;


	CField field5 = modelfeature2->getPropertySet()->getFields().at(4);
	void* tmp4 = field5.getVarient().data();
	double* pWidth2 = static_cast<double*>(tmp4);
	double posy = *pWidth2;


	CField field6 = modelfeature2->getPropertySet()->getFields().at(5);
	void* tmp5 = field6.getVarient().data();
	double* pWidth3 = static_cast<double*>(tmp5);
	double posz = *pWidth3;

	CField field7 = modelfeature2->getPropertySet()->getFields().at(6);
	void* tmp6 = field7.getVarient().data();
	double* pscale1 = static_cast<double*>(tmp6);
	double scalex = *pscale1;

	CField field8 = modelfeature2->getPropertySet()->getFields().at(7);
	void* tmp7 = field8.getVarient().data();
	double* pscale2 = static_cast<double*>(tmp7);
	double scaley = *pscale2;

	CField field9 = modelfeature2->getPropertySet()->getFields().at(8);
	void* tmp8 = field9.getVarient().data();
	double* pscale3 = static_cast<double*>(tmp8);
	double scalez = *pscale3;




	CField field10 = modelfeature2->getPropertySet()->getFields().at(9);
	void* tmp9 = field10.getVarient().data();
	double* ptrans1 = static_cast<double*>(tmp9);
	double transx = *ptrans1;

	CField field11 = modelfeature2->getPropertySet()->getFields().at(10);
	void* tmp10 = field11.getVarient().data();
	double* ptrans2 = static_cast<double*>(tmp10);
	double transy = *ptrans2;

	CField field12 = modelfeature2->getPropertySet()->getFields().at(11);
	void* tmp11 = field12.getVarient().data();
	double* ptrans3 = static_cast<double*>(tmp11);
	double transz = *ptrans3;


	CField field13 = modelfeature2->getPropertySet()->getFields().at(12);
	void* tmp12 = field13.getVarient().data();
	double* protate1 = static_cast<double*>(tmp12);
	double rotatex = *protate1;

	CField field14 = modelfeature2->getPropertySet()->getFields().at(13);
	void* tmp13 = field14.getVarient().data();
	double* protate2 = static_cast<double*>(tmp13);
	double rotatey = *protate2;

	CField field15 = modelfeature2->getPropertySet()->getFields().at(14);
	void* tmp14 = field15.getVarient().data();
	double* protate3 = static_cast<double*>(tmp14);
	double rotatez = *protate3;

	CField field16 = modelfeature2->getPropertySet()->getFields().at(15);
	void* tmp15 = field16.getVarient().data();
	double* ptag = static_cast<double*>(tmp15);
	int legth = field16.getVarient().getLength();

	CField field17 = modelfeature->getPropertySet()->getFields().at(16);
	void* tmp16 = field17.getVarient().data();
	int* ptag2 = static_cast<int*>(tmp16);
	int devicetype = *ptag2;



	sqlite3_stmt * stat;  

	//string nametmp = "insert into ModelDataset(ID,Name,Type,PosX,PosY,PosZ,ScaleX,ScaleY,ScaleZ,TransX,TransY,TransZ,RotateX,RotateY,RotateZ,Tag) values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
	//sqlite3_prepare_v2(mpDB,G2U(nametmp.c_str()), -1,&stat,0);

	//string strtmp = "insert into" +  modeldatasetName + "(ID,Name,Type,PosX,PosY,PosZ,ScaleX,ScaleY,ScaleZ,TransX,TransY,TransZ,RotateX,RotateY,RotateZ,Tag) values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";

	string strtmp = "insert into " + modeldatasetName + "(ID,Name,Type,PosX,PosY,PosZ,ScaleX,ScaleY,ScaleZ,TransX,TransY,TransZ,RotateX,RotateY,RotateZ,Tag,DeviceType) values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
	sqlite3_prepare_v2(mpDB,strtmp.c_str(), -1,&stat,0);

	sqlite3_bind_int(stat,1,id1);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	sqlite3_bind_text(stat,3,type.c_str(),strlen(type.c_str()),SQLITE_STATIC);

	sqlite3_bind_double(stat,4,posx);
	sqlite3_bind_double(stat,5,posy);
	sqlite3_bind_double(stat,6,posz);

	sqlite3_bind_double(stat,7,scalex);
	sqlite3_bind_double(stat,8,scaley);
	sqlite3_bind_double(stat,9,scalez);

	sqlite3_bind_double(stat,10,transx);
	sqlite3_bind_double(stat,11,transy);
	sqlite3_bind_double(stat,12,transz);

	sqlite3_bind_double(stat,13,rotatex);
	sqlite3_bind_double(stat,14,rotatey);
	sqlite3_bind_double(stat,15,rotatez);

	sqlite3_bind_blob(stat,16, ptag,legth, NULL );
	
	sqlite3_bind_int(stat,17,devicetype);

	rc = sqlite3_step(stat);  

	sqlite3_finalize( stat );

	return rc;
}



////参数不是抽象类
int CSQLiteDatabase::insertLanewayFeatureToLanewayDataset( CLanewayFeature* lanewayFeature)
{
	char **results = NULL;  
	int rc(1);
	
	CField field1 = lanewayFeature->getPropertySet()->getFields().at(1);	
	void* tmp = field1.getVarient().data();
	const char*  pName2 = static_cast<const char*>(tmp);
	string name1(pName2);
	

	CField field2 = lanewayFeature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field2.getVarient().data();
	int id1 = *pID1;
	

	CField field3 = lanewayFeature->getPropertySet()->getFields().at(2);
	//string* pType1 = (string*)field3.getVarient().data(); 
	const char*  pType1 = (const char* )field3.getVarient().data();
	string type1(pType1);

	CField field4 = lanewayFeature->getPropertySet()->getFields().at(3);
	void* tmp2 = field4.getVarient().data();
	float* pWidth1 = static_cast<float*>(tmp2);
	float width1 = *pWidth1;

	CField field5 = lanewayFeature->getPropertySet()->getFields().at(4);
	void* tmp3 = field4.getVarient().data();
	float* pHeight1 = static_cast<float*>(tmp3);
	float height1 = *pHeight1;


	CField field7 = lanewayFeature->getPropertySet()->getFields().at(5);
	void* tmp4 = field7.getVarient().data();
	int* psectiontype1 = static_cast<int*>(tmp4);
	int sectiontype = *psectiontype1;

	CField field8 = lanewayFeature->getPropertySet()->getFields().at(6);
	void* tmp5 = field8.getVarient().data();
	int* psupporttype = static_cast<int*>(tmp5);
	int supporttype = *psupporttype;



	CField field6 = lanewayFeature->getPropertySet()->getFields().at(7);
	void* pData = field6.getVarient().data();
	char*  pGeometry =  (char* )pData;
	int legth = field6.getVarient().getLength();
	//char* sql = "insert into LanewayDataset(ID%d,Name%s,Type%s,Width%f) values(%d,%s,%s,%f),id1,name1,type1,width1";

	//stringstream ss;
	//stringstream ss2;
	//string idstr;
	//string widthstr2;
	//ss<<id1;
	//ss>>idstr;
	//ss2<<width1;
	//ss2>>widthstr2;
	//
	//string sql = "insert into LanewayDataset(ID,Name,Type,Width) values('"+idstr+"','"+name1+"','"+type1+"','"+widthstr2+"')";

	//
	////rc = sqlite3_exec(mpDB,"insert into LanewayDataset(ID, Name, Type, Width, Geometry) values('10', 'lane1', 'type', '5.0', 'dddd')",NULL,NULL,results);
	//
	//rc = sqlite3_exec(mpDB,sql.c_str(),NULL,NULL,results);

	CField field9 = lanewayFeature->getPropertySet()->getFields().at(8);
	void* tmp8 = field9.getVarient().data();
	int* planewaywindtype = static_cast<int*>(tmp8);
	int lanewayWindType = *planewaywindtype;
	
	sqlite3_stmt * stat;  
	//sqlite3_prepare( mpDB,"insert into LanewayDataset(Geometry) values( ? )", -1, &stat, 0 ); 
	string nametmp = "insert into LanewayDataset(ID,Name,Type,Width,Height,SectionType,SupportType,Geometry,LanewayWindType) values(?,?,?,?,?,?,?,?,?)";
	
	//sqlite3_prepare_v2(mpDB,G2U(nametmp.c_str()), -1,&stat,0);

	sqlite3_prepare_v2(mpDB,"insert into LanewayDataset(ID,Name,Type,Width,Height,SectionType,SupportType,Geometry,LanewayWindType) values(?,?,?,?,?,?,?,?,?)", -1,&stat,0);
	sqlite3_bind_int(stat,1,id1);
	//sqlite3_bind_text(stat,2,name1,strlen(name1.c_str()),SQLITE_TRANSIENT);
	rc = sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_TRANSIENT);
	//sqlite3_bind_text(stat,2,G2U(name1.c_str()),strlen(name1.c_str()),SQLITE_STATIC);
	sqlite3_bind_text(stat,3,pType1,strlen(type1.c_str()),SQLITE_STATIC);
	sqlite3_bind_double(stat,4,width1);
	sqlite3_bind_double(stat,5,height1);
	sqlite3_bind_int(stat,6,sectiontype);
	sqlite3_bind_int(stat,7,supporttype);


	//sqlite3_bind_blob(stat,5, pGeometry, strlen(pGeometry), NULL );
	sqlite3_bind_blob(stat,8, pGeometry,legth, NULL );
	sqlite3_bind_int(stat,9,lanewayWindType);


	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;

}

int CSQLiteDatabase::insertLogicFeatureToLogicDataset( CLogicFeature* logicfeature)
{
	char **results = NULL;  
	int rc(1);

	CField field1 = logicfeature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = logicfeature->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);
	//field2.getVarient().getValue(name1);

	CField field3 = logicfeature->getPropertySet()->getFields().at(2);
	char*  pType1 = (char* )field3.getVarient().data();
	string type1(pType1);

	CField field4 = logicfeature->getPropertySet()->getFields().at(3);
	void* tmp2 = field4.getVarient().data();
	double* pWidth1 = static_cast<double*>(tmp2);
	double minRangeX = *pWidth1;

	CField field5 = logicfeature->getPropertySet()->getFields().at(4);
	void* tmp3 = field5.getVarient().data();
	double* prY = static_cast<double*>(tmp3);
	double minRangeY = *prY;

	CField field6 = logicfeature->getPropertySet()->getFields().at(5);
	void* tmp4 = field6.getVarient().data();
	double* prZ = static_cast<double*>(tmp4);
	double minRangeZ = *prZ;

	CField field7 = logicfeature->getPropertySet()->getFields().at(6);
	void* tmp5 = field7.getVarient().data();
	double* prmaxX = static_cast<double*>(tmp5);
	double maxRangeX = *prmaxX;

	CField field8 = logicfeature->getPropertySet()->getFields().at(7);
	void* tmp6 = field8.getVarient().data();
	double* prmaxY = static_cast<double*>(tmp6);
	double maxRangeY = *prmaxY;

	CField field9 = logicfeature->getPropertySet()->getFields().at(8);
	void* tmp7 = field9.getVarient().data();
	double* prmaxZ = static_cast<double*>(tmp7);
	double maxRangeZ = *prmaxZ;

	sqlite3_stmt * stat;  
	sqlite3_prepare_v2(mpDB,"insert into LogicDataset(ID,Name,Type,minRangeX,minRangeY,minRangeZ,maxRangeX,maxRangeY,maxRangeZ) values(?,?,?,?,?,?,?,?,?)", -1,&stat,0);
	
	sqlite3_bind_int(stat,1,id1);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	sqlite3_bind_text(stat,3,type1.c_str(),strlen(type1.c_str()),SQLITE_STATIC);

	sqlite3_bind_double(stat,4,minRangeX);
	sqlite3_bind_double(stat,5,minRangeY);
	sqlite3_bind_double(stat,6,minRangeZ);

	sqlite3_bind_double(stat,7,maxRangeX);
	sqlite3_bind_double(stat,8,maxRangeY);
	sqlite3_bind_double(stat,9,maxRangeZ);

	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;
}

int CSQLiteDatabase::insertCoalLayerToCoalLayerDataset( VirtualMine::Database::CCoalLayerFeature* coallayerfeature)
{
	char **results = NULL;  
	int rc(1);

	CField field1 = coallayerfeature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = coallayerfeature->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);

	CField field3 = coallayerfeature->getPropertySet()->getFields().at(2);
	void* pData = field3.getVarient().data();
	char*  pGeometry =  (char* )pData;
	int legth = field3.getVarient().getLength();

	CField field4 = coallayerfeature->getPropertySet()->getFields().at(3);
	void* pData2 = field4.getVarient().data();
	char*  pTexture =  (char* )pData2;
	int legth2 = field4.getVarient().getLength();

	sqlite3_stmt * stat;  
	string nametmp = "insert into CoalLayerDataset(ID,Name,Geometry,Texture) values(?,?,?,?)";
	sqlite3_prepare_v2(mpDB,G2U(nametmp.c_str()), -1,&stat,0);

	sqlite3_bind_int(stat,1,id1);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	sqlite3_bind_blob(stat,3,pGeometry,legth,NULL);
	sqlite3_bind_blob(stat,4,pTexture,legth2,NULL);

	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;

}

int CSQLiteDatabase::insertImageFeatureToImageDataset( VirtualMine::Database::CImageFeature* imagefeature)
{
	char **results = NULL;  
	int rc(0);

	CField field1 = imagefeature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = imagefeature->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);
	
	CField field3 = imagefeature->getPropertySet()->getFields().at(2);
	void* tmp2 = field3.getVarient().data();
	int legth = field3.getVarient().getLength();

	sqlite3_stmt * stat;  
	sqlite3_prepare_v2(mpDB,"insert into ImageDataset(ID,Name,Image) values(?,?,?)", -1,&stat,0);

	sqlite3_bind_int(stat,1,id1);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	sqlite3_bind_blob(stat,3, tmp2,legth, NULL );

	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;

}

int CSQLiteDatabase::insertDrillingFeatureToDrillingDataset( VirtualMine::Database::CDrillingFeature* drillingfeature)
{
	char **results = NULL;  
	int rc(1);

	CField field1 = drillingfeature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = drillingfeature->getPropertySet()->getFields().at(1);
	void*  tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);
	//field2.getVarient().getValue(name1);

	CField field3 = drillingfeature->getPropertySet()->getFields().at(2);
	void*  pPosX = field3.getVarient().data();
	double* pX = static_cast<double*>(pPosX);
	double posX = *pX;

	CField field4 = drillingfeature->getPropertySet()->getFields().at(3);
	void* pPosY = field4.getVarient().data();
	double* pY = static_cast<double*>(pPosY);
	double posY = *pY;

	CField field5 = drillingfeature->getPropertySet()->getFields().at(4);
	void* pPosZ = field5.getVarient().data();
	double* pZ = static_cast<double*>(pPosZ);
	double posZ = *pZ;

	CField field6 = drillingfeature->getPropertySet()->getFields().at(5);
	void* pData = field6.getVarient().data();
	int length = field6.getVarient().getLength();
	
	Ogre::uchar*  pGeoLayerInfo =  (Ogre::uchar* )pData;

	//char* sql = "insert into LanewayDataset(ID%d,Name%s,Type%s,Width%f) values(%d,%s,%s,%f),id1,name1,type1,width1";

	//stringstream ss;
	//stringstream ss2;
	//string idstr;
	//string widthstr2;
	//ss<<id1;
	//ss>>idstr;
	//ss2<<width1;
	//ss2>>widthstr2;
	//
	//string sql = "insert into LanewayDataset(ID,Name,Type,Width) values('"+idstr+"','"+name1+"','"+type1+"','"+widthstr2+"')";

	//
	////rc = sqlite3_exec(mpDB,"insert into LanewayDataset(ID, Name, Type, Width, Geometry) values('10', 'lane1', 'type', '5.0', 'dddd')",NULL,NULL,results);
	//
	//rc = sqlite3_exec(mpDB,sql.c_str(),NULL,NULL,results);


	sqlite3_stmt * stat;  

	string nametmp = "insert into DrillingDataset(ID,Name,PositionX,PositionY,PositionZ,GeoLayerInfo) values(?,?,?,?,?,?)";
	sqlite3_prepare_v2(mpDB,nametmp.c_str(), -1,&stat,0);
	sqlite3_bind_int(stat,1,id1);
	//sqlite3_bind_text(stat,2,name1,strlen(name1.c_str()),SQLITE_TRANSIENT);
	//rc = sqlite3_bind_text(stat,2,name1,strlen(name1.c_str()),SQLITE_TRANSIENT);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	//sqlite3_bind_text(stat,3,type1.c_str(),strlen(type1.c_str()),SQLITE_STATIC);
	sqlite3_bind_double(stat,3,posX);
	sqlite3_bind_double(stat,4,posY);
	sqlite3_bind_double(stat,5,posZ);

	//sqlite3_bind_blob(stat,5, pGeometry, strlen(pGeometry), NULL );
	sqlite3_bind_blob(stat,6, pGeoLayerInfo, length, NULL );

	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	/*sqlite3_close(mpDB);*/
	return rc;

}

int CSQLiteDatabase::insertMetaDataFeatureToMetaDataset( VirtualMine::Database::CMetadataFeature* metadatafeature)
{
	if (metadatafeature == NULL)
	{
		return -1;
	}

	char **results = NULL;  
	int rc(0);

	
	/////向元数据集里添加feature
	int count = this->mpDatasetSet->size();
	for (int i = 0; i < count; i++)
	{
		IDataset* dataset = this->mpDatasetSet->at(i);
		if (dataset && dataset->getType() == "Metadata")
		{
			dataset->addFeature(*metadatafeature);
		}

	}

	CField field1 = metadatafeature->getPropertySet()->getFields().at(0);
	void* pID1 = field1.getVarient().data();
	char*  pName = static_cast<char*>(pID1);
	string name  = pName;
		 
	
	CField field2 = metadatafeature->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	int*  pName2 = static_cast<int*>(tmp);
	int rs(*pName2);


	CField field3 = metadatafeature->getPropertySet()->getFields().at(2);
	void* tmp2 = field3.getVarient().data();
	char*  pName3 = static_cast<char*>(tmp2);
	string type(pName3);

	CField field4 = metadatafeature->getPropertySet()->getFields().at(3);
	void* tmp3 = field4.getVarient().data();
	double*  pminx = static_cast<double*>(tmp3);
	double minX(*pminx);

	CField field5 = metadatafeature->getPropertySet()->getFields().at(4);
	void* tmp4 = field5.getVarient().data();
	double*  pminy = static_cast<double*>(tmp4);
   double minY(*pminy);

	CField field6 = metadatafeature->getPropertySet()->getFields().at(5);
	void* tmp5 = field6.getVarient().data();
	double*  pminz = static_cast<double*>(tmp5);
	double minZ(*pminz);



	CField field7 = metadatafeature->getPropertySet()->getFields().at(6);
	void* tmp6 = field7.getVarient().data();
	double*  pmaxx = static_cast<double*>(tmp6);
	double maxX(*pmaxx);

	CField field8 = metadatafeature->getPropertySet()->getFields().at(7);
	void* tmp7 = field8.getVarient().data();
	double*  pmaxy = static_cast<double*>(tmp7);
	double maxY(*pmaxy);

	CField field9 = metadatafeature->getPropertySet()->getFields().at(8);
	void* tmp8 = field9.getVarient().data();
	double*  pmaxz = static_cast<double*>(tmp8);
	double maxZ(*pmaxz);



	sqlite3_stmt * stat;  

	//string nametmp = "insert into MetadataDataset(Name,SpatialReference,Type,minRangeX,minRangeY,minRangeZ,maxRangeX,maxRangeY,maxRangeZ) values(?,?,?,?,?,?,?,?,?)";
	//sqlite3_prepare_v2(mpDB,G2U(nametmp.c_str()), -1,&stat,0);
	sqlite3_prepare_v2(mpDB,"insert into MetadataDataset(Name,SpatialReference,Type,minRangeX,minRangeY,minRangeZ,maxRangeX,maxRangeY,maxRangeZ) values(?,?,?,?,?,?,?,?,?)", -1,&stat,0);


	sqlite3_bind_int(stat,2,rs);
	sqlite3_bind_text(stat,1,name.c_str(),strlen(name.c_str()),SQLITE_STATIC);
	sqlite3_bind_blob(stat,3,type.c_str(),strlen(type.c_str()), SQLITE_STATIC );
	sqlite3_bind_double(stat,4,minX);
	sqlite3_bind_double(stat,5,minY);
	sqlite3_bind_double(stat,6,minZ);

	sqlite3_bind_double(stat,7,maxX);
	sqlite3_bind_double(stat,8,maxY);
	sqlite3_bind_double(stat,9,maxZ);

	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;
}

int CSQLiteDatabase::insertModelFeatureToModelDataset( VirtualMine::Database::CModelFeature* modelfeature)
{

	char **results = NULL;  
	int rc(0);

	CField field1 = modelfeature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = modelfeature->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);

	CField field3 = modelfeature->getPropertySet()->getFields().at(2);
	void* tmp2 = field3.getVarient().data();
	char*  pName3 = static_cast<char*>(tmp2);
	string type(pName3);

	CField field4 = modelfeature->getPropertySet()->getFields().at(3);
	void* tmp3 = field4.getVarient().data();
	double* pWidth1 = static_cast<double*>(tmp3);
	double posx = *pWidth1;


	CField field5 = modelfeature->getPropertySet()->getFields().at(4);
	void* tmp4 = field5.getVarient().data();
	double* pWidth2 = static_cast<double*>(tmp4);
	double posy = *pWidth2;


	CField field6 = modelfeature->getPropertySet()->getFields().at(5);
	void* tmp5 = field6.getVarient().data();
	double* pWidth3 = static_cast<double*>(tmp5);
	double posz = *pWidth3;

	CField field7 = modelfeature->getPropertySet()->getFields().at(6);
	void* tmp6 = field7.getVarient().data();
	double* pscale1 = static_cast<double*>(tmp6);
	double scalex = *pscale1;

	CField field8 = modelfeature->getPropertySet()->getFields().at(7);
	void* tmp7 = field8.getVarient().data();
	double* pscale2 = static_cast<double*>(tmp7);
	double scaley = *pscale2;

	CField field9 = modelfeature->getPropertySet()->getFields().at(8);
	void* tmp8 = field9.getVarient().data();
	double* pscale3 = static_cast<double*>(tmp8);
	double scalez = *pscale3;




	CField field10 = modelfeature->getPropertySet()->getFields().at(9);
	void* tmp9 = field10.getVarient().data();
	double* ptrans1 = static_cast<double*>(tmp9);
	double transx = *ptrans1;

	CField field11 = modelfeature->getPropertySet()->getFields().at(10);
	void* tmp10 = field11.getVarient().data();
	double* ptrans2 = static_cast<double*>(tmp10);
	double transy = *ptrans2;

	CField field12 = modelfeature->getPropertySet()->getFields().at(11);
	void* tmp11 = field12.getVarient().data();
	double* ptrans3 = static_cast<double*>(tmp11);
	double transz = *ptrans3;


	CField field13 = modelfeature->getPropertySet()->getFields().at(12);
	void* tmp12 = field13.getVarient().data();
	double* protate1 = static_cast<double*>(tmp12);
	double rotatex = *protate1;

	CField field14 = modelfeature->getPropertySet()->getFields().at(13);
	void* tmp13 = field14.getVarient().data();
	double* protate2 = static_cast<double*>(tmp13);
	double rotatey = *protate2;

	CField field15 = modelfeature->getPropertySet()->getFields().at(14);
	void* tmp14 = field15.getVarient().data();
	double* protate3 = static_cast<double*>(tmp14);
	double rotatez = *protate3;

	CField field16 = modelfeature->getPropertySet()->getFields().at(15);
	void* tmp15 = field16.getVarient().data();
	double* ptag = static_cast<double*>(tmp15);
	int legth = field16.getVarient().getLength();


	CField field17 = modelfeature->getPropertySet()->getFields().at(16);
	void* tmp16 = field17.getVarient().data();
	int* ptag2 = static_cast<int*>(tmp16);
	int devicetype = *ptag2;

	sqlite3_stmt * stat;  

	//string nametmp = "insert into ModelDataset(ID,Name,Type,PosX,PosY,PosZ,ScaleX,ScaleY,ScaleZ,TransX,TransY,TransZ,RotateX,RotateY,RotateZ,Tag) values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
	//sqlite3_prepare_v2(mpDB,G2U(nametmp.c_str()), -1,&stat,0);

	sqlite3_prepare_v2(mpDB,"insert into ModelDataset(ID,Name,Type,PosX,PosY,PosZ,ScaleX,ScaleY,ScaleZ,TransX,TransY,TransZ,RotateX,RotateY,RotateZ,Tag,DeviceType) values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", -1,&stat,0);

	sqlite3_bind_int(stat,1,id1);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
    sqlite3_bind_text(stat,3,type.c_str(),strlen(type.c_str()),SQLITE_STATIC);

	sqlite3_bind_double(stat,4,posx);
	sqlite3_bind_double(stat,5,posy);
	sqlite3_bind_double(stat,6,posz);

	sqlite3_bind_double(stat,7,scalex);
	sqlite3_bind_double(stat,8,scaley);
	sqlite3_bind_double(stat,9,scalez);

	sqlite3_bind_double(stat,10,transx);
	sqlite3_bind_double(stat,11,transy);
	sqlite3_bind_double(stat,12,transz);

	sqlite3_bind_double(stat,13,rotatex);
	sqlite3_bind_double(stat,14,rotatey);
	sqlite3_bind_double(stat,15,rotatez);

	sqlite3_bind_blob(stat,16, ptag,legth, NULL );

	sqlite3_bind_int(stat,17, devicetype);

	rc = sqlite3_step(stat);  

	sqlite3_finalize( stat );

	return rc;

}

int CSQLiteDatabase::insertDEMFeatureToDEMDataset( VirtualMine::Database::CDEMFeature* demfeature)
{
	char **results = NULL;  
	int rc(0);

	CField field1 = demfeature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = demfeature->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);

	CField field3 = demfeature->getPropertySet()->getFields().at(2);
	void* tmp2 = field3.getVarient().data();
	int legth = field3.getVarient().getLength();

	sqlite3_stmt * stat;  
	sqlite3_prepare_v2(mpDB,"insert into DEMDataset(ID,Name,Geometry) values(?,?,?)", -1,&stat,0);

	sqlite3_bind_int(stat,1,id1);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	sqlite3_bind_blob(stat,3, tmp2,legth, NULL );

	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;
}

int CSQLiteDatabase::insertWorkingplaneFeatureToWorkingPlaneDataset(VirtualMine::Database::CWorkingplaneFeature* workingplanefeature)
{
	char **results = NULL;  
	int rc(0);

	CField field1 = workingplanefeature->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = workingplanefeature->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);

	CField field3 = workingplanefeature->getPropertySet()->getFields().at(2);
	void* tmp2 = field3.getVarient().data();
	int legth = field3.getVarient().getLength();

	sqlite3_stmt * stat;  
	sqlite3_prepare_v2(mpDB,"insert into WorkingplaneDataset(ID,Name,Geometry) values(?,?,?)", -1,&stat,0);

	sqlite3_bind_int(stat,1,id1);
	sqlite3_bind_text(stat,2,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	sqlite3_bind_blob(stat,3, tmp2,legth, NULL );

	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );

	return rc;
}


int CSQLiteDatabase::insertFaultLayerFeatureToFaultLayerDataset( VirtualMine::Database::CFaultLayerFeature* faultlayerfeature)
{
	return -1;
}






void CSQLiteDatabase::initDB()
{
	this->createMetadataDataset();
	this->createLogicalDataset();
	this->createLanewayDataset();
	this->createCoalLayerDataset();
	this->createDrillingDataset();
	this->createModelDataset();
	this->createModelDataset("GroundModelDataset");
	this->createModelDataset("LocationDataset");
	this->createDEMDataset();
	this->createImageDataset();
	this->createFaultLayerDataset();
}



////////////////////////////////////查询操作////////////////////////////////////////

VirtualMine::Database::CUserInfoDataset* CSQLiteDatabase::queryUserInfoDataset()
{
	CUserInfoDataset* dataset = new CUserInfoDataset();
	sqlite3_stmt * stat;
	char *sql1="select * from UserInfoDataset"; 
	sqlite3_prepare_v2( mpDB, sql1, -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
	
		char* name = (char*)sqlite3_column_text(stat,0);
		char* pwd = (char*)sqlite3_column_text(stat,1);
				
		CUserInfoFeature* feature = new CUserInfoFeature();

		feature->setFieldName(name);
		feature->setFieldPassword(pwd);


		dataset->addFeature(feature);

		//delete feature;
		//feature = NULL;


	}
	sqlite3_finalize(stat);


	dataset->setName("UserInfoDataset");

	return dataset;
}

CLogicDataset* CSQLiteDatabase::queryLogicDataset()
{ 
	//char *errmsg = NULL; 
	//char ***result = NULL;
	//int *row = NULL;
	//int *column = NULL;
	//int rc(0);
	//rc = sqlite3_open(filename.c_str(),&mpDB);
	//char *sql1="select * from LogicDataset"; 

	////GB2312转换为UTF-8
	//char * pSql = G2U(sql1);
	//rc = sqlite3_get_table(mpDB,sql1,result,row,column,0);//方法1
	////rc = sqlite3_exec(db, pSql, LoadMyInfo, NULL, &errmsg);//方法2

	////将result 转为 Feature，构建Feature 将result的值付给Feature



	//if (pSql)
	//{
	//	delete pSql;

	//	pSql = NULL;
	//}
	//sqlite3_close(mpDB);
	//return NULL;
	
    CLogicDataset* dataset = new CLogicDataset();
	sqlite3_stmt * stat;
	char *sql1="select * from LogicDataset"; 
	sqlite3_prepare_v2( mpDB, sql1, -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		 char* name = (char*)sqlite3_column_text(stat,1);
		 char* type = (char*)sqlite3_column_text(stat,2);
		 double minRangeX = sqlite3_column_double(stat,3);
		 double minRangeY = sqlite3_column_double(stat,4);
		 double minRangeZ = sqlite3_column_double(stat,5);

		 double maxRangeX = sqlite3_column_double(stat,6);
		 double maxRangeY = sqlite3_column_double(stat,7);
		 double maxRangeZ = sqlite3_column_double(stat,8);

		 CLogicFeature* feature = new CLogicFeature();

		feature->setFieldID(id);
		feature->setFieldName(name);
		feature->setFieldType(type);
		feature->setFieldmaxRangeX(maxRangeX);
		feature->setFieldmaxRangeY(maxRangeY);
		feature->setFieldmaxRangeZ(maxRangeZ);
		feature->setFieldminRangeX(minRangeX);
		feature->setFieldminRangeY(minRangeY);
		feature->setFieldminRangeZ(minRangeZ);

		
      
		dataset->addFeature(feature);

		//delete feature;
		//feature = NULL;


	}
	sqlite3_finalize(stat);

 	
	dataset->setName("LogicDataset");
	//dataset->setType(VirtualMine::Core::GeoDataType::)
	
	return dataset;
}

CLanewayDataset* CSQLiteDatabase::queryLanewayDataset() 
{
	//char *errmsg = NULL; 
	//char **result = NULL;
	//int row(100);
	//int column(0);
	//int index(0);
	//int rc(0);
	//sqlite3_stmt* stmt3 = NULL;
	//char *sql1="select * from LanewayDataset"; 

	////GB2312转换为UTF-8
	//char * pSql = G2U(sql1);
	//
	//rc = sqlite3_get_table(mpDB,pSql,&result,&row,&column,&errmsg);

	//CLanewayDataset* dataset = new CLanewayDataset();
	////std::vector<IFeature*>* featurelist = dataset->getFeatureList();
	//if (rc == SQLITE_OK )
	//{
	//	index = column;	

	//	for (int i = 0;i < row;i++)
	//	{
	//	    CLanewayFeature* lanewayfeature = new CLanewayFeature();
	//	
	//		for(int j = 0;j < column;j++)
	//		{					
	//			if ( j % column  == 0 )//ID
	//			{
	//				//int v = sqlite3_column_int(stmt3,index);
	//				const char* tmp = result[index];
	//				int v = atoi(tmp);	

	//			//int v = result[index];
	//			lanewayfeature->setFieldID(v);

	//			}
	//			else if(j % column == 1) 
	//			{
	//				//const char* v = (const char*)sqlite3_column_text(stmt3,index);
	//				
	//			    char* v = result[index];
	//				string str(v);
	//				printf("The result of querying is : \n");
	//				printf("result = %s\n",str);
	//				printf("result = %s\n",v);
	//				//string v = result[index];
	//				lanewayfeature->setFieldName(v);
	//				/*CVariant var(v);
	//				CField field;
	//				field.setVarient(var);
	//				lanewayfeature->getPropertySet()->setField(field,1);
	//	*/		
	//			} 
	//			else if(j % column == 2) 
	//			{
	//				//const char* v = (const char*)sqlite3_column_text(stmt3,index);
	//				char* v = result[index];
	//				printf("result = %s\n",v);
	//				//string str(v); 
	//				//string v = result[index];
	//				lanewayfeature->setFieldType(v);
	//				/*CVariant var(v);
	//				CField field;
	//				field.setVarient(var);
	//				lanewayfeature->getPropertySet()->setField(field,2);			*/
	//		     }
	//            else if (j % column == 3) 
	//            {
	//	          // double v = sqlite3_column_text(stmt3,index);
	//			    char* v = result[index];	  
	//				printf("result = %s\n",v);
	//				float width = atof(v);
	//				//float v = result[index];
	//				lanewayfeature->setFieldWidth(width);
	//	/*			CVariant var(v);
	//             	CField field;
	//              	field.setVarient(var);
	//             	lanewayfeature->getPropertySet()->setField(field,3);			*/
	//        	 }
	//			 else if (j % column == 4) 
	//			 {				
	//				char* tmp = result[index];	                
	//				float v = atof(tmp);
	//				printf("result = %s\n",tmp);
	//				printf("result = %f\n",v);
	//				// float v = result[index];
	//				lanewayfeature->setFieldHeight(v);
	//
	//			  }
	//             else if (j % column == 5) 
	//             {	            	
	//				char* v = result[index];
	//				int length(1000);
 //                   printf("result = %s\n",v);
	//				Ogre::uchar* mData = (Ogre::uchar*)v;
	//				CVRDataStream datastream;
	//				datastream.wirteBlob(mData,length);
	//				datastream.reseek(0);
	//				lanewayfeature->setFieldBlob(datastream);
	//                //lanewayfeature->setFieldBlob((Ogre::uchar*)v,length);
	//			
	//	
	//		     }			
	//             ++index;
 //             }	
	//	    dataset->addFeature(lanewayfeature);      	
	//	}

	//	sqlite3_free_table(result);
	//	sqlite3_close(mpDB);		
	//}
	//return dataset;


    CLanewayDataset* dataset = new CLanewayDataset();
	sqlite3_stmt * stat;
	char *sql1="select * from LanewayDataset"; 
	sqlite3_prepare_v2( mpDB, sql1, -1, &stat,0);


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

		dataset->addFeature(feature);

	/*	delete feature;
		feature = NULL;
*/
	}
	sqlite3_finalize(stat);
	dataset->setName("LanewayDataset");
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_LANWAY);
	return dataset;

}

VirtualMine::Database::CLanewayDataset* CSQLiteDatabase::queryLanewayDataset(const std::string& lanewayDatasetName)
{
	CLanewayDataset* dataset = new CLanewayDataset();
	sqlite3_stmt * stat;
	
	std::string querySQL = "select * from " + lanewayDatasetName;

	sqlite3_prepare_v2( mpDB, querySQL.c_str(), -1, &stat,0);


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

		dataset->addFeature(feature);

	/*	delete feature;
		feature = NULL;
*/
	}
	sqlite3_finalize(stat);
	dataset->setName(lanewayDatasetName);
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_LANWAY);
	return dataset;
}

////方法没更新
VirtualMine::Database::CLanewayFeature* CSQLiteDatabase::queryLanewayFeature(const std::string& lanewayDatasetName,const std::string& featureName)
{
	//char *errmsg = NULL; 
	//char **result = NULL;
	//int row(100);
	//int column(0);
	//int index(0);
	//int rc(0);
	//sqlite3_stmt* stmt3 = NULL;
	//char *sql1="select * from LanewayDataset"; 

	////GB2312转换为UTF-8
	//char * pSql = G2U(sql1);

	//rc = sqlite3_get_table(mpDB,pSql,&result,&row,&column,&errmsg);

	//if (rc == SQLITE_OK )
	//{
	//	index = column;	

	//	for (int i = 0;i < row;i++)
	//	{
	//	    CLanewayFeature* lanewayfeature = new CLanewayFeature();
	//	
	//		for(int j = 0;j < column;j++)
	//		{					
	//		
	//			 if(j % column == 1) 
	//			{
	//				
	//			    char* v = result[index];
	//				string str(v);
	//				printf("The result of querying is : \n");
	//				printf("result = %s\n",str);
	//				printf("result = %s\n",v);
	//				
	//				if (v == featureName)
	//				{
	//					lanewayfeature->setFieldName(featureName);
	//					char* tmpID = result[index-1];
	//					int ID = atoi(tmpID);
	//					lanewayfeature->setFieldID(ID);
	//					char* tmpType = result[index+1];
	//					lanewayfeature->setFieldType(tmpType);
	//					char* tmpWidth = result[index+2];	  
	//					float width = atof(tmpWidth);
	//					lanewayfeature->setFieldWidth(width);
	//					char* tmpHeight = result[index+3];	  
	//					float height = atof(tmpHeight);
	//					lanewayfeature->setFieldWidth(height);
	//					return lanewayfeature;
	//					
	//				}

	//					
	//             ++index;
	//             }			  
	//	}
	//	sqlite3_free_table(result);
	//	sqlite3_close(mpDB);		
	//}
	//
	//}
	
	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + lanewayDatasetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
	/*	int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);
		char* type = (char*)sqlite3_column_text(stat,2);
		float width  = sqlite3_column_double(stat,3);
		float height = sqlite3_column_double(stat,4);
		const void * pData = sqlite3_column_blob( stat, 5 );
		int len = sqlite3_column_bytes( stat, 5 );
		Ogre::uchar* pGeometry = (Ogre::uchar*)pData;*/


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

		//int width  = sqlite3_column_double(stat,3);
		//int height = sqlite3_column_double(stat,4);

		CLanewayFeature* feature = new CLanewayFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		feature->setFieldType(type);
		feature->setFieldWidth(width);
		feature->setFieldHeight(height);
		feature->setFieldSectionType(sectiontype);
		feature->setFieldHeightSupportType(supporttype);
		feature->setFieldBlob(pGeometry,len);
		feature->setFieldLanewayWindType(lanewaywindtype);

		if (name == featureName)
		{
			return feature;
		}

	

	}
	sqlite3_finalize(stat);

}

VirtualMine::Database::CDrillingDataset* CSQLiteDatabase::queryDrillingDataset(const std::string& datesetName)
{
	
CDrillingDataset* dataset = new CDrillingDataset();
	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);
		double posX = sqlite3_column_double(stat,2);
		double posY = sqlite3_column_double(stat,3);
		double posZ = sqlite3_column_double(stat,4);
		const void * pData = sqlite3_column_blob( stat, 5 );
		int len = sqlite3_column_bytes( stat, 5 );
		Ogre::uchar* pGeometry = (Ogre::uchar*)pData;

		CDrillingFeature* feature = new CDrillingFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		feature->setFieldPositionX(posX);
		feature->setFieldPositionY(posY);
		feature->setFieldPositionZ(posZ);
		feature->setFieldBlob(pGeometry,len);

		dataset->addFeature(feature);
		 
		/*delete feature;
		feature = NULL;*/
	}
	sqlite3_finalize(stat);

	dataset->setName(datesetName);
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_DRILL);
	return dataset;

}

VirtualMine::Database::CDrillingDataset* CSQLiteDatabase::queryDrillingDataset()
{
	//char *errmsg = NULL; 
	//char **result = NULL;
	//int row(100);
	//int column(0);
	//int index(0);
	//int rc(0);
	//sqlite3_stmt* stmt3 = NULL;
	//char *sql1="select * from DrillingDataset"; 

	////GB2312转换为UTF-8
	//char * pSql = G2U(sql1);
	//
	//rc = sqlite3_get_table(mpDB,pSql,&result,&row,&column,&errmsg);

	//VirtualMine::Database::CDrillingDataset* dataset = new VirtualMine::Database::CDrillingDataset();

	//if (rc == SQLITE_OK )
	//{
	//	index = column;	

	//	for (int i = 0;i < row;i++)
	//	{
	//	    CDrillingFeature* feature = new CDrillingFeature();
	//	
	//		for(int j = 0;j < column;j++)
	//		{					
	//			if ( j % column  == 0 )//ID
	//			{
	//				//int v = sqlite3_column_int(stmt3,index);
	//				const char* tmp = result[index];
	//				int v = atoi(tmp);	

	//			    //int v = result[index];
	//			    feature->setFieldID(v);

	//			}
	//			else if(j % column == 1) 
	//			{
	//				//const char* v = (const char*)sqlite3_column_text(stmt3,index);
	//				
	//			    char* v = result[index];
	//				string str(v);
	//				printf("The result of querying is : \n");
	//				printf("result = %s\n",str);
	//				printf("result = %s\n",v);
	//				//string v = result[index];
	//				feature->setFieldName(v);
	//				/*CVariant var(v);
	//				CField field;
	//				field.setVarient(var);
	//				lanewayfeature->getPropertySet()->setField(field,1);
	//	*/		
	//			} 
	//			else if(j % column == 2) 
	//			{
	//				//const char* v = (const char*)sqlite3_column_text(stmt3,index);
	//				char* v = result[index];
	//				printf("result = %s\n",v);
	//				double posX = atof(v);
	//				//string str(v); 
	//				//string v = result[index];
	//				feature->setFieldPositionX(posX);
	//				/*CVariant var(v);
	//				CField field;
	//				field.setVarient(var);
	//				lanewayfeature->getPropertySet()->setField(field,2);			*/
	//		     }
	//            else if (j % column == 3) 
	//            {
	//	          // double v = sqlite3_column_text(stmt3,index);
	//			    char* v = result[index];	  
	//				printf("result = %s\n",v);
	//				double posY = atof(v);
	//				//float v = result[index];
	//				feature->setFieldPositionY(posY);
	//	/*			CVariant var(v);
	//             	CField field;
	//              	field.setVarient(var);
	//             	lanewayfeature->getPropertySet()->setField(field,3);			*/
	//        	 }
	//			 else if (j % column == 4) 
	//			 {				
	//				char* tmp = result[index];	                
	//				double posZ = atof(tmp);
	//				printf("result = %s\n",tmp);
	//				printf("result = %f\n",posZ);
	//				// float v = result[index];
	//				feature->setFieldPositionZ(posZ);
	//
	//			  }
	//             else if (j % column == 5) 
	//             {	            	
	//				char* v = result[index];
	//				int length(6);///长度待商议
 //                   printf("result = %s\n",v);
	//                feature->setFieldBlob((Ogre::uchar*)v,length);
	//		     }			
	//             ++index;
 //             }	
	//	    dataset->addFeature(feature);      	
	//	}

	//	sqlite3_free_table(result);
	//	sqlite3_close(mpDB);		
	//}
	//return dataset;

	CDrillingDataset* dataset = new CDrillingDataset();
	sqlite3_stmt * stat;
	char *sql1="select * from DrillingDataset"; 
	sqlite3_prepare_v2( mpDB, sql1, -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);
		double posX = sqlite3_column_double(stat,2);
		double posY = sqlite3_column_double(stat,3);
		double posZ = sqlite3_column_double(stat,4);
		const void * pData = sqlite3_column_blob( stat, 5 );
		int len = sqlite3_column_bytes( stat, 5 );
		Ogre::uchar* pGeometry = (Ogre::uchar*)pData;

		CDrillingFeature* feature = new CDrillingFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		feature->setFieldPositionX(posX);
		feature->setFieldPositionY(posY);
		feature->setFieldPositionZ(posZ);
		feature->setFieldBlob(pGeometry,len);

		dataset->addFeature(feature);
		 
		/*delete feature;
		feature = NULL;*/
	}
	sqlite3_finalize(stat);

	dataset->setName("DrillingDataset");
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_DRILL);
	return dataset;

}



VirtualMine::Database::CDrillingFeature*  CSQLiteDatabase::queryDrillingFeature(const std::string& datesetName,const std::string& featureName)
{
	//CDrillingDataset* dataset = new CDrillingDataset();
	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);
		double posX = sqlite3_column_double(stat,2);
		double posY = sqlite3_column_double(stat,3);
		double posZ = sqlite3_column_double(stat,4);
		const void * pData = sqlite3_column_blob( stat, 5 );
		int len = sqlite3_column_bytes( stat, 5 );
		Ogre::uchar* pGeometry = (Ogre::uchar*)pData;

		CDrillingFeature* feature = new CDrillingFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		feature->setFieldPositionX(posX);
		feature->setFieldPositionY(posY);
		feature->setFieldPositionZ(posZ);
		feature->setFieldBlob(pGeometry,len);

 	 if (name == featureName)
 	 {
		 return feature;
 	 }
		 
		/*delete feature;
		feature = NULL;*/
	}
	sqlite3_finalize(stat);



}


VirtualMine::Database::CCoalLayerDataset* CSQLiteDatabase::queryCoalLayerDataset()
{

	CCoalLayerDataset* dataset = new CCoalLayerDataset();
	sqlite3_stmt * stat;
	char *sql1="select * from CoalLayerDataset"; 
	sqlite3_prepare_v2( mpDB, sql1, -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);
	
		const void * pData = sqlite3_column_blob( stat, 2);
		int len = sqlite3_column_bytes( stat, 2 );
		Ogre::uchar* pGeometry = (Ogre::uchar*)pData;

		const void * pData2 = sqlite3_column_blob( stat, 3);
		int len2 = sqlite3_column_bytes( stat, 3 );
		Ogre::uchar* pTexture = (Ogre::uchar*)pData2;

		CCoalLayerFeature* feature = new CCoalLayerFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
	
		feature->setFieldBlob(pGeometry,len);
		feature->setFieldTexture(pTexture,len2);
		
		dataset->addFeature(feature);
		/*delete feature;
		feature = NULL;
		*/
	}
	sqlite3_finalize(stat);

	dataset->setName("CoalLayerDataset");
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_COALSEAM);
	return dataset;
}

VirtualMine::Database::CCoalLayerDataset* CSQLiteDatabase::queryCoalLayerDataset(const std::string& datesetName)
{

	CCoalLayerDataset* dataset = new CCoalLayerDataset();

	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);

		const void * pData = sqlite3_column_blob( stat, 2);
		int len = sqlite3_column_bytes( stat, 2 );
		Ogre::uchar* pGeometry = (Ogre::uchar*)pData;

		const void * pData2 = sqlite3_column_blob( stat, 3);
		int len2 = sqlite3_column_bytes( stat, 3 );
		Ogre::uchar* pTexture = (Ogre::uchar*)pData2;

		CCoalLayerFeature* feature = new CCoalLayerFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		feature->setFieldBlob(pGeometry,len);
		feature->setFieldTexture(pTexture,len2);	

		dataset->addFeature(feature);
		
	}
	sqlite3_finalize(stat);

	dataset->setName(datesetName);
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_COALSEAM);
	return dataset;

}

///查询岩层数据
VirtualMine::Database::CTerraneDataset* CSQLiteDatabase::queryTerraneLayerDataset(const std::string& datesetName)
{
	CTerraneDataset* dataset = new CTerraneDataset();

	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


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


		dataset->addFeature(feature);

	}
	sqlite3_finalize(stat);

	dataset->setName(datesetName);
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_COALSEAM);
	return dataset;
}


VirtualMine::Database::CCoalLayerFeature* CSQLiteDatabase::queryCoalLayerDataset(const std::string& datesetName,const std::string& featureName)
{
	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);

		const void * pData = sqlite3_column_blob( stat, 2);
		int len = sqlite3_column_bytes( stat, 2 );
		Ogre::uchar* pGeometry = (Ogre::uchar*)pData;

		const void * pData2 = sqlite3_column_blob( stat, 3);
		int len2 = sqlite3_column_bytes( stat, 3 );
		Ogre::uchar* pTexture = (Ogre::uchar*)pData2;

		CCoalLayerFeature* feature = new CCoalLayerFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		feature->setFieldBlob(pGeometry,len);
		feature->setFieldTexture(pTexture,len2);	

		if (featureName == name)
		{
			return feature;
		}

	}
	sqlite3_finalize(stat);

	
}



VirtualMine::Database::CDEMDataset* CSQLiteDatabase::queryDEMDataset()
{
	VirtualMine::Database::CDEMDataset* dataset = new VirtualMine::Database::CDEMDataset();
	sqlite3_stmt * stat;
	char *sql1 ="select * from DEMDataset"; 
	sqlite3_prepare_v2( mpDB, sql1, -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);

		const void * pData = sqlite3_column_blob( stat, 2);
		int len = sqlite3_column_bytes( stat, 2 );
		Ogre::uchar* pGeometry = (Ogre::uchar*)pData;

		CDEMFeature* feature = new CDEMFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		feature->setFieldBlob(pGeometry,len);


		dataset->addFeature(feature);
		/*	
		delete feature;
		feature = NULL;
		*/
	}
	sqlite3_finalize(stat);

	dataset->setName("DEMDataset");
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_DEM);
	return dataset;
}

VirtualMine::Database::CDEMDataset*  CSQLiteDatabase::queryDEMDataset(const std::string& datesetName)
{
	VirtualMine::Database::CDEMDataset* dataset = new VirtualMine::Database::CDEMDataset();
	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);

		const void * pData = sqlite3_column_blob( stat, 2);
		int len = sqlite3_column_bytes( stat, 2 );
		Ogre::uchar* pGeometry = (Ogre::uchar*)pData;

		CDEMFeature* feature = new CDEMFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		feature->setFieldBlob(pGeometry,len);

		dataset->addFeature(feature);

	}
	sqlite3_finalize(stat);

	dataset->setName(datesetName);
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_DEM);
	return dataset;
}

VirtualMine::Database::CDEMFeature* CSQLiteDatabase::queryDEMFeature(const std::string& datesetName,const std::string& featureName)
{

	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);

		const void * pData = sqlite3_column_blob( stat, 2);
		int len = sqlite3_column_bytes( stat, 2 );
		Ogre::uchar* pGeometry = (Ogre::uchar*)pData;

		CDEMFeature* feature = new CDEMFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		feature->setFieldBlob(pGeometry,len);

		if (featureName == name)
		{
			return feature;
		}

	}
	sqlite3_finalize(stat);
}



VirtualMine::Database::CWorkingplaneDataset* CSQLiteDatabase::queryWorkingplaneDataset()
{
	VirtualMine::Database::CWorkingplaneDataset* dataset = new VirtualMine::Database::CWorkingplaneDataset();
	sqlite3_stmt * stat;
	char *sql1="select * from WorkingplaneDataset"; 
	sqlite3_prepare_v2( mpDB, sql1, -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);

		const void * pData = sqlite3_column_blob( stat, 2);
		int len = sqlite3_column_bytes( stat, 2 );
		Ogre::uchar* pGeometry = (Ogre::uchar*)pData;

		CWorkingplaneFeature* feature = new CWorkingplaneFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		feature->setFieldBlob(pGeometry,len);


		dataset->addFeature(feature);

		/*	delete feature;
		feature = NULL;*/

	}
	sqlite3_finalize(stat);

	dataset->setName("WorkingplaneDataset");
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_WORKINGPLANE);
	return dataset;
}

VirtualMine::Database::CWorkingplaneDataset* CSQLiteDatabase::queryWorkingplaneDataset(const std::string& datesetName)
{

	VirtualMine::Database::CWorkingplaneDataset* dataset = new VirtualMine::Database::CWorkingplaneDataset();
	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);

		const void * pData = sqlite3_column_blob( stat, 2);
		int len = sqlite3_column_bytes( stat, 2 );
		Ogre::uchar* pGeometry = (Ogre::uchar*)pData;

		CWorkingplaneFeature* feature = new CWorkingplaneFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		feature->setFieldBlob(pGeometry,len);

		dataset->addFeature(feature);
		

	}
	sqlite3_finalize(stat);


	dataset->setName(datesetName);
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_WORKINGPLANE);
	return dataset;
}

VirtualMine::Database::CWorkingplaneFeature* CSQLiteDatabase::queryWorkingplaneDataset(const std::string& datesetName,const std::string& featureName)
{
	
	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);

		const void * pData = sqlite3_column_blob( stat, 2);
		int len = sqlite3_column_bytes( stat, 2 );
		Ogre::uchar* pGeometry = (Ogre::uchar*)pData;

		CWorkingplaneFeature* feature = new CWorkingplaneFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		feature->setFieldBlob(pGeometry,len);

	    if (featureName == name)
	    {
			return feature;
	    }


	}
	sqlite3_finalize(stat);

}





VirtualMine::Database::CModelDataset* CSQLiteDatabase::queryModelDataset()
{
	VirtualMine::Database::CModelDataset* dataset = new VirtualMine::Database::CModelDataset();
	sqlite3_stmt * stat;
	char *sql1="select * from ModelDataset"; 
	sqlite3_prepare_v2( mpDB, sql1, -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);
		//char* meshname = (char*)sqlite3_column_text(stat,2);
		char* type = (char*)sqlite3_column_text(stat,2);

		double posx = sqlite3_column_double(stat,3);
		double posy = sqlite3_column_double(stat,4);
		double posz = sqlite3_column_double(stat,5);

		double scalex = sqlite3_column_double(stat,6);
		double scaley = sqlite3_column_double(stat,7);
		double scalez = sqlite3_column_double(stat,8);

		double transx = sqlite3_column_double(stat,9);
		double transy = sqlite3_column_double(stat,10);
		double transz = sqlite3_column_double(stat,11);

		double rotatex = sqlite3_column_double(stat,12);
		double rotatey = sqlite3_column_double(stat,13);
		double rotatez = sqlite3_column_double(stat,14);


		const void * pData = sqlite3_column_blob(stat,15);
		int len = sqlite3_column_bytes( stat,15);

	
		Ogre::uchar* pTag = (Ogre::uchar*)pData;

		int devicetype = sqlite3_column_int(stat,16);


		CModelFeature* feature = new CModelFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		//feature->setFieldMeshName(meshname);
		feature->setFieldType(type);
		feature->setFieldPosX(posx);
		feature->setFieldPosY(posy);
		feature->setFieldPosZ(posz);

		feature->setFieldScaleX(scalex);
		feature->setFieldScaleY(scaley);
		feature->setFieldScaleZ(scalez);


		feature->setFieldTransX(transx);
		feature->setFieldTransY(transy);
		feature->setFieldTransZ(transz);

		feature->setFieldRotateX(rotatex);
		feature->setFieldRotateY(rotatey);
		feature->setFieldRotateZ(rotatez);

		feature->setFieldBlob(pTag,len);
	
		feature->setFieldDeviceType(devicetype);

		
		dataset->addFeature(feature);

		VirtualMine::Core::DeviceType modelType = (VirtualMine::Core::DeviceType )devicetype;
		feature->setDeviceType(modelType);
		dataset->setModelType(modelType);
		
		/*	delete feature;
		feature = NULL;*/

	}
	sqlite3_finalize(stat);

	dataset->setName("ModelDataset");
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_MODEL);
	return dataset;
}


VirtualMine::Database::CModelFeature* CSQLiteDatabase::queryModelDataset(const std::string& featureName,const std::string& modeldatasetName)
{
	sqlite3_stmt * stat;

	string sql1 = "select * from" + modeldatasetName;


	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);
	

	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);
		char* type = (char*)sqlite3_column_text(stat,2);

		double posx = sqlite3_column_double(stat,3);
		double posy = sqlite3_column_double(stat,4);
		double posz = sqlite3_column_double(stat,5);

		double scalex = sqlite3_column_double(stat,6);
		double scaley = sqlite3_column_double(stat,7);
		double scalez = sqlite3_column_double(stat,8);

		double transx = sqlite3_column_double(stat,9);
		double transy = sqlite3_column_double(stat,10);
		double transz = sqlite3_column_double(stat,11);

		double rotatex = sqlite3_column_double(stat,12);
		double rotatey = sqlite3_column_double(stat,13);
		double rotatez = sqlite3_column_double(stat,14);


		const void * pData = sqlite3_column_blob(stat,15);
		int len = sqlite3_column_bytes( stat,15);

		Ogre::uchar* pTag = (Ogre::uchar*)pData;
		int devicetype = sqlite3_column_int(stat,16);

		CModelFeature* feature = new CModelFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		//feature->setFieldMeshName(meshname);
		feature->setFieldType(type);
		feature->setFieldPosX(posx);
		feature->setFieldPosY(posy);
		feature->setFieldPosZ(posz);

		feature->setFieldScaleX(scalex);
		feature->setFieldScaleY(scaley);
		feature->setFieldScaleZ(scalez);

		feature->setFieldTransX(transx);
		feature->setFieldTransY(transy);
		feature->setFieldTransZ(transz);

		feature->setFieldRotateX(rotatex);
		feature->setFieldRotateY(rotatey);
		feature->setFieldRotateZ(rotatez);	

		feature->setFieldBlob(pTag,len);
		feature->setFieldDeviceType(devicetype);

		VirtualMine::Core::DeviceType modelType = (VirtualMine::Core::DeviceType )devicetype;
		feature->setDeviceType(modelType);

		if (name == featureName)
		{
			return feature;
		}

		

	}
	sqlite3_finalize(stat);


}


VirtualMine::Database::CModelDataset* CSQLiteDatabase::queryModelDataset(const std::string& modeldatasetName)
{
	sqlite3_stmt * stat;

	string sql1 = "select * from " + modeldatasetName;


	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);
	VirtualMine::Database::CModelDataset* dataset = new VirtualMine::Database::CModelDataset();


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);
		char* type = (char*)sqlite3_column_text(stat,2);

		double posx = sqlite3_column_double(stat,3);
		double posy = sqlite3_column_double(stat,4);
		double posz = sqlite3_column_double(stat,5);

		double scalex = sqlite3_column_double(stat,6);
		double scaley = sqlite3_column_double(stat,7);
		double scalez = sqlite3_column_double(stat,8);

		double transx = sqlite3_column_double(stat,9);
		double transy = sqlite3_column_double(stat,10);
		double transz = sqlite3_column_double(stat,11);

		double rotatex = sqlite3_column_double(stat,12);
		double rotatey = sqlite3_column_double(stat,13);
		double rotatez = sqlite3_column_double(stat,14);


		const void * pData = sqlite3_column_blob(stat,15);
		int len = sqlite3_column_bytes( stat,15);

		Ogre::uchar* pTag = (Ogre::uchar*)pData;
		int devicetype = sqlite3_column_int(stat,16);

		CModelFeature* feature = new CModelFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		//feature->setFieldMeshName(meshname);
		feature->setFieldType(type);
		feature->setFieldPosX(posx);
		feature->setFieldPosY(posy);
		feature->setFieldPosZ(posz);

		feature->setFieldScaleX(scalex);
		feature->setFieldScaleY(scaley);
		feature->setFieldScaleZ(scalez);

		feature->setFieldTransX(transx);
		feature->setFieldTransY(transy);
		feature->setFieldTransZ(transz);

		feature->setFieldRotateX(rotatex);
		feature->setFieldRotateY(rotatey);
		feature->setFieldRotateZ(rotatez);	

		feature->setFieldBlob(pTag,len);
		
	    feature->setFieldDeviceType(devicetype);
	
		VirtualMine::Core::DeviceType modelType = (VirtualMine::Core::DeviceType )devicetype;
		feature->setDeviceType(modelType);
		dataset->setModelType(modelType);

		dataset->addFeature(feature);

	/*	delete feature;
		feature = NULL;
*/

	}
	sqlite3_finalize(stat);

	dataset->setName(modeldatasetName);
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_MODEL);
	return dataset;
}



//
//Ogre::Vector3 CSQLiteDatabase::queryModelDataset(const int& id1,const int& id2)
//{
////	sqlite3_stmt * stat;
////	char *sql1="select * from ModelDataset"; 
////	sqlite3_prepare_v2( mpDB, sql1, -1, &stat,0);
////
////
////	while (sqlite3_step(stat) == SQLITE_ROW)
////	{
////		int id = sqlite3_column_int( stat, 0 );
////		char* name = (char*)sqlite3_column_text(stat,1);
////		//char* meshname = (char*)sqlite3_column_text(stat,2);
////
////		double posx = sqlite3_column_double(stat,2);
////		double posy = sqlite3_column_double(stat,3);
////		double posz = sqlite3_column_double(stat,4);
////
////		double scalex = sqlite3_column_double(stat,5);
////		double scaley = sqlite3_column_double(stat,6);
////		double scalez = sqlite3_column_double(stat,7);
////
////		double transx = sqlite3_column_double(stat,8);
////		double transy = sqlite3_column_double(stat,9);
////		double transz = sqlite3_column_double(stat,10);
////
////		double rotatex = sqlite3_column_double(stat,11);
////		double rotatey = sqlite3_column_double(stat,12);
////		double rotatez = sqlite3_column_double(stat,13);
////
////
////		const void * pData = sqlite3_column_blob(stat,14);
////		int len = sqlite3_column_bytes( stat,14);
////
////		Ogre::uchar* pTag = (Ogre::uchar*)pData;
////
////		CVRDataStream database;
////		database.wirteBlob(pData,len);
////		database.reseek(0);
////
////	/*	CModelProperty* modelpro = new CModelProperty();
////		modelpro->fromStream(database);
////*/
////
////		CModelFeature* feature = new CModelFeature();
////		feature->setFieldID(id);
////		feature->setFieldName(name);
////		//feature->setFieldMeshName(meshname);
////		feature->setFieldPosX(posx);
////		feature->setFieldPosY(posy);
////		feature->setFieldPosZ(posz);
////
////		feature->setFieldScaleX(scalex);
////		feature->setFieldScaleY(scaley);
////		feature->setFieldScaleZ(scalez);
////
////		feature->setFieldTransX(transx);
////		feature->setFieldTransY(transy);
////		feature->setFieldTransZ(transz);
////
////		feature->setFieldRotateX(rotatex);
////		feature->setFieldRotateY(rotatey);
////		feature->setFieldRotateZ(rotatez);	
////
////		feature->setFieldBlob(pTag,len);
////
////		if (name == featureName)
////		{
////			return feature;
////		}
////
////	}
////	sqlite3_finalize(stat);
//	return NULL;
//}




VirtualMine::Database::CImageDataset*  CSQLiteDatabase::queryImageDataset()
{

	VirtualMine::Database::CImageDataset* dataset = new VirtualMine::Database::CImageDataset();
	sqlite3_stmt * stat;
	char *sql1="select * from ImageDataset"; 
	sqlite3_prepare_v2( mpDB, sql1, -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);

		const void * pData = sqlite3_column_blob( stat, 2);
		int len = sqlite3_column_bytes( stat, 2 );
		Ogre::uchar* ImageData = (Ogre::uchar*)pData;

		CImageFeature* feature = new CImageFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);	
		feature->setFieldBlob(ImageData,len);

		dataset->addFeature(feature);

		/*delete feature;
		feature = NULL;*/

	}
	sqlite3_finalize(stat);

	dataset->setName("ImageDataset");
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_IMAGE);
	return dataset;
}

VirtualMine::Database::CImageDataset* CSQLiteDatabase::queryImageDataset(const std::string& datesetName)
{
	VirtualMine::Database::CImageDataset* dataset = new VirtualMine::Database::CImageDataset();
	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);

		const void * pData = sqlite3_column_blob( stat, 2);
		int len = sqlite3_column_bytes( stat, 2 );
		Ogre::uchar* ImageData = (Ogre::uchar*)pData;

		double minX = sqlite3_column_double(stat,3);
		double minY = sqlite3_column_double(stat,4);
		double minZ = sqlite3_column_double(stat,5);
		double maxX = sqlite3_column_double(stat,6);
		double maxY = sqlite3_column_double(stat,7);
		double maxZ = sqlite3_column_double(stat,8);

		CImageFeature* feature = new CImageFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);	
		feature->setFieldBlob(ImageData,len);
		feature->setFieldMinPosX(minX);
		feature->setFieldMinPosY(minY);
		feature->setFieldMinPosZ(minZ);
		feature->setFieldMaxPosX(maxX);
		feature->setFieldMaxPosY(maxY);
		feature->setFieldMaxPosZ(maxZ);

		dataset->addFeature(feature);
	

	}
	sqlite3_finalize(stat);

	dataset->setName(datesetName);
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_IMAGE);
	return dataset;
}



VirtualMine::Database::CImageFeature* CSQLiteDatabase::queryImageDataset(const std::string& datesetName,const std::string& featureName)
{
	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);

		const void * pData = sqlite3_column_blob( stat, 2);
		int len = sqlite3_column_bytes( stat, 2 );
		Ogre::uchar* ImageData = (Ogre::uchar*)pData;

		double minX = sqlite3_column_double(stat,3);
		double minY = sqlite3_column_double(stat,4);
		double minZ = sqlite3_column_double(stat,5);
		double maxX = sqlite3_column_double(stat,6);
		double maxY = sqlite3_column_double(stat,7);
		double maxZ = sqlite3_column_double(stat,8);

		CImageFeature* feature = new CImageFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);	
		feature->setFieldBlob(ImageData,len);
		feature->setFieldMinPosX(minX);
		feature->setFieldMinPosY(minY);
		feature->setFieldMinPosZ(minZ);
		feature->setFieldMaxPosX(maxX);
		feature->setFieldMaxPosY(maxY);
		feature->setFieldMaxPosZ(maxZ);

		if (featureName == name)
		{
			return feature;
		}


	}
	sqlite3_finalize(stat);
}











//////////////////////////////////更新操作//////////////////////////////////////////////////
 void CSQLiteDatabase::updataDrillingFeature(VirtualMine::Database::CDrillingFeature* feature,std::string featurename)
 {
	 char* na = (char*)(feature->getPropertySet()->getFields().at(1).getVarient().data());
	 int* id = (int*)(feature->getPropertySet()->getFields().at(0).getVarient().data());
	 double* pX = (double*)(feature->getPropertySet()->getFields().at(2).getVarient().data());
	 double* pY = (double*)(feature->getPropertySet()->getFields().at(3).getVarient().data());
	 double* pZ = (double*)(feature->getPropertySet()->getFields().at(4).getVarient().data());

	 Ogre::uchar* blob = (Ogre::uchar*)(feature->getPropertySet()->getFields().at(5).getVarient().data());
	 int blobLength = feature->getPropertySet()->getFields().at(5).getVarient().getLength();
     
	 int getid = *id;
	 double posX = *pX;
	 double posY = *pY;
	 double posZ = *pZ;

	 sqlite3_stmt *statement;

	 char *sql = "update DrillingDataset set ID = ? ,Name = ? , PositionX = ? , PositionY = ? , PositionZ = ?  WHERE Name = ?";

	 //将SQL语句放入sqlite3_stmt中
	 int success = sqlite3_prepare_v2(mpDB, sql, -1, &statement, NULL);
	 if (success != SQLITE_OK) {

		 return;
	 }

	 sqlite3_bind_int(statement,1,getid);
	 sqlite3_bind_text(statement, 2,na,strlen(na),SQLITE_TRANSIENT);
	 sqlite3_bind_double(statement,3,posX);
	 sqlite3_bind_double(statement,4,posY);
	 sqlite3_bind_double(statement,5,posZ);

	 //sqlite3_bind_blob(statement,6,blob,blobLength,NULL);

	 const char* legth = featurename.c_str();
	 sqlite3_bind_text(statement, 6,featurename.c_str(),strlen(legth),SQLITE_TRANSIENT);

	 success = sqlite3_step(statement);

	 sqlite3_finalize(statement);
 
 }

void CSQLiteDatabase::updateLanewayFeature( VirtualMine::Database::CLanewayFeature* feature,string featurename)
{
	//VirtualMine::Database::CLanewayFeature* findfeature = this->queryLanewayDataset(featurename);
	char* na = (char*)(feature->getPropertySet()->getFields().at(1).getVarient().data());
	int* id = (int*)(feature->getPropertySet()->getFields().at(0).getVarient().data());
	char* type = (char*)(feature->getPropertySet()->getFields().at(2).getVarient().data());
	float* width = (float*)(feature->getPropertySet()->getFields().at(3).getVarient().data());
	float* height = (float*)(feature->getPropertySet()->getFields().at(4).getVarient().data());

	int* psectiontype = (int*)(feature->getPropertySet()->getFields().at(5).getVarient().data());
	int* psupporttype = (int*)(feature->getPropertySet()->getFields().at(6).getVarient().data());


	Ogre::uchar* blob = (Ogre::uchar*)(feature->getPropertySet()->getFields().at(7).getVarient().data());
	//ID 不能相同
	int siseblob = feature->getPropertySet()->getFields().at(7).getVarient().getLength();

	int* planewaywindtype = (int*)(feature->getPropertySet()->getFields().at(8).getVarient().data());

	int getid = *id+100;
	float getwidth = *width;
	float getheight = *height;
	int sectiontype = *psectiontype;
	int supporttype = *psupporttype;
	int lanewaywindtype = *planewaywindtype;

	//findfeature->setFieldID(getid);
	//findfeature->setFieldName(na);
	//findfeature->setFieldType(type) ;
	//findfeature->setFieldWidth(getwidth);
	//findfeature->setFieldHeight(getheight);
	//findfeature->setFieldBlob(blob,feature->getPropertySet()->getFields().at(3).getVarient().getLength());
	//

	sqlite3_stmt *statement;

	char *sql = "update LanewayDataset set ID = ? ,Name = ? , Type = ? , Width = ? , Height = ?,SectionType = ?,SupportType = ? ,Geometry = ?,LanewayWindType = ?  WHERE Name = ?";

	//将SQL语句放入sqlite3_stmt中
	int success = sqlite3_prepare_v2(mpDB, sql, -1, &statement, NULL);
	if (success != SQLITE_OK) {
		
		return;
	}
	sqlite3_bind_int(statement,1,getid);
	sqlite3_bind_text(statement,2,na,strlen(na),SQLITE_TRANSIENT);
	sqlite3_bind_text(statement,3,type,strlen(type),SQLITE_TRANSIENT);
	sqlite3_bind_double(statement,4,getwidth);
	sqlite3_bind_double(statement,5,getheight);
	sqlite3_bind_int(statement,6,sectiontype);
	sqlite3_bind_int(statement,7,supporttype);
	sqlite3_bind_blob(statement,8,blob,siseblob,NULL);
	sqlite3_bind_int(statement,9,lanewaywindtype);

	const char* legth = featurename.c_str();
	sqlite3_bind_text(statement,10,featurename.c_str(),strlen(legth),SQLITE_TRANSIENT);

	success = sqlite3_step(statement);

	sqlite3_finalize(statement);


}

void CSQLiteDatabase::updateLogicFeature(VirtualMine::Database::CLogicFeature* feature,std::string featurename)
{

}

////更新有问题
void CSQLiteDatabase::updateImageFeature(VirtualMine::Database::CImageFeature* feature,std::string featurename)
{
	char* na = (char*)(feature->getPropertySet()->getFields().at(1).getVarient().data());
	int* id = (int*)(feature->getPropertySet()->getFields().at(0).getVarient().data());
	Ogre::uchar* blob = (Ogre::uchar*)(feature->getPropertySet()->getFields().at(2).getVarient().data());

	int siseblob = feature->getPropertySet()->getFields().at(2).getVarient().getLength();

	double minX = feature->getFieldMinPosX();
	double minY = feature->getFieldMinPosY();
	double minZ = feature->getFieldMinPosZ();

	double maxX = feature->getFieldMaxPosX();
	double maxY = feature->getFieldMaxPosY();
	double maxZ = feature->getFieldMaxPosZ();



	int getid = *id;
	sqlite3_stmt *statement;

	char *sql = "update ImageDataset set ID = ? ,Name = ? , Image = ?,MinPosX = ?,MinPosY = ?,MinPosZ = ?,MaxPosX = ?,MaxPosY = ?,MaxPosZ = ? WHERE Name = ?";

	//将SQL语句放入sqlite3_stmt中
	int success = sqlite3_prepare_v2(mpDB, sql, -1, &statement, NULL);
	if (success != SQLITE_OK) 
	{
		return;
	}
	sqlite3_bind_int(statement,1,getid);
	sqlite3_bind_text(statement,2,na,strlen(na),SQLITE_TRANSIENT);
	sqlite3_bind_blob(statement,3,blob,siseblob,NULL);
	sqlite3_bind_double(statement,4,minX);
	sqlite3_bind_double(statement,5,minY);
	sqlite3_bind_double(statement,6,minZ);
	sqlite3_bind_double(statement,7,maxX);
	sqlite3_bind_double(statement,8,maxY);
	sqlite3_bind_double(statement,9,maxZ);


	const char* legth = featurename.c_str();
	sqlite3_bind_text(statement,10,featurename.c_str(),strlen(legth),SQLITE_TRANSIENT);

	success = sqlite3_step(statement);

	sqlite3_finalize(statement);


}

void CSQLiteDatabase::updateCoalLayerFeature(VirtualMine::Database::CCoalLayerFeature* feature,std::string featurename)
{
	int* id = (int*)(feature->getPropertySet()->getFields().at(0).getVarient().data());
	char* na = (char*)(feature->getPropertySet()->getFields().at(1).getVarient().data());
	

	Ogre::uchar* blob = (Ogre::uchar*)(feature->getPropertySet()->getFields().at(2).getVarient().data());
	int siseblob = feature->getPropertySet()->getFields().at(2).getVarient().getLength();

	Ogre::uchar* texture = (Ogre::uchar*)(feature->getPropertySet()->getFields().at(3).getVarient().data());

	int sistexture= feature->getPropertySet()->getFields().at(3).getVarient().getLength();

	int getid = *id;
	sqlite3_stmt *statement;

	char *sql = "update CoalLayerDataset set ID = ? ,Name = ? , Geometry = ? ,Texture = ? WHERE Name = ?";

	//将SQL语句放入sqlite3_stmt中
	int success = sqlite3_prepare_v2(mpDB, sql, -1, &statement, NULL);
	if (success != SQLITE_OK) 
	{
		return;
	}
	sqlite3_bind_int(statement,1,getid);
	sqlite3_bind_text(statement,2,na,strlen(na),SQLITE_TRANSIENT);
	sqlite3_bind_blob(statement,3,blob,siseblob,NULL);
	sqlite3_bind_blob(statement,4,texture,sistexture,NULL);
	const char* legth = featurename.c_str();
	sqlite3_bind_text(statement,5,featurename.c_str(),strlen(legth),SQLITE_TRANSIENT);

	success = sqlite3_step(statement);

	sqlite3_finalize(statement);
}

void CSQLiteDatabase::updateDEMFeature(VirtualMine::Database::CDEMFeature* feature,std::string festurename)
{
  
}

void CSQLiteDatabase::updataModelFeature(VirtualMine::Database::IFeature* feature,std::string featurename)
{

	CModelFeature *modelfeature2 = dynamic_cast<CModelFeature*>(feature);
	

	CField field1 = modelfeature2->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = modelfeature2->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);

	CField field3 = modelfeature2->getPropertySet()->getFields().at(2);
	void* tmp2 = field3.getVarient().data();
	char*  pName3 = static_cast<char*>(tmp2);
	string type(pName3);

	CField field4 = modelfeature2->getPropertySet()->getFields().at(3);
	void* tmp3 = field4.getVarient().data();
	double* pWidth1 = static_cast<double*>(tmp3);
	double posx = *pWidth1;


	CField field5 = modelfeature2->getPropertySet()->getFields().at(4);
	void* tmp4 = field5.getVarient().data();
	double* pWidth2 = static_cast<double*>(tmp4);
	double posy = *pWidth2;


	CField field6 = modelfeature2->getPropertySet()->getFields().at(5);
	void* tmp5 = field6.getVarient().data();
	double* pWidth3 = static_cast<double*>(tmp5);
	double posz = *pWidth3;

	CField field7 = modelfeature2->getPropertySet()->getFields().at(6);
	void* tmp6 = field7.getVarient().data();
	double* pscale1 = static_cast<double*>(tmp6);
	double scalex = *pscale1;

	CField field8 = modelfeature2->getPropertySet()->getFields().at(7);
	void* tmp7 = field8.getVarient().data();
	double* pscale2 = static_cast<double*>(tmp7);
	double scaley = *pscale2;

	CField field9 = modelfeature2->getPropertySet()->getFields().at(8);
	void* tmp8 = field9.getVarient().data();
	double* pscale3 = static_cast<double*>(tmp8);
	double scalez = *pscale3;




	CField field10 = modelfeature2->getPropertySet()->getFields().at(9);
	void* tmp9 = field10.getVarient().data();
	double* ptrans1 = static_cast<double*>(tmp9);
	double transx = *ptrans1;

	CField field11 = modelfeature2->getPropertySet()->getFields().at(10);
	void* tmp10 = field11.getVarient().data();
	double* ptrans2 = static_cast<double*>(tmp10);
	double transy = *ptrans2;

	CField field12 = modelfeature2->getPropertySet()->getFields().at(11);
	void* tmp11 = field12.getVarient().data();
	double* ptrans3 = static_cast<double*>(tmp11);
	double transz = *ptrans3;


	CField field13 = modelfeature2->getPropertySet()->getFields().at(12);
	void* tmp12 = field13.getVarient().data();
	double* protate1 = static_cast<double*>(tmp12);
	double rotatex = *protate1;

	CField field14 = modelfeature2->getPropertySet()->getFields().at(13);
	void* tmp13 = field14.getVarient().data();
	double* protate2 = static_cast<double*>(tmp13);
	double rotatey = *protate2;

	CField field15 = modelfeature2->getPropertySet()->getFields().at(14);
	void* tmp14 = field15.getVarient().data();
	double* protate3 = static_cast<double*>(tmp14);
	double rotatez = *protate3;

	CField field16 = modelfeature2->getPropertySet()->getFields().at(15);
	void* tmp15 = field16.getVarient().data();
	double* ptag = static_cast<double*>(tmp15);
	int legth = field16.getVarient().getLength();




	//int* id = (int*)(modelfeature->getPropertySet()->getFields().at(0).getVarient().data());
	//char* na = (char*)(modelfeature->getPropertySet()->getFields().at(1).getVarient().data());
	//char* type = (char*)(modelfeature->getPropertySet()->getFields().at(2).getVarient().data());

	//float* posX = (float*)(modelfeature->getPropertySet()->getFields().at(3).getVarient().data());
	//float* posY = (float*)(modelfeature->getPropertySet()->getFields().at(4).getVarient().data());
	//float* posZ = (float*)(modelfeature->getPropertySet()->getFields().at(5).getVarient().data());

	//float* scaleX = (float*)(modelfeature->getPropertySet()->getFields().at(6).getVarient().data());
	//float* scaleY = (float*)(modelfeature->getPropertySet()->getFields().at(7).getVarient().data());
	//float* scaleZ = (float*)(modelfeature->getPropertySet()->getFields().at(8).getVarient().data());

	//float* transX = (float*)(modelfeature->getPropertySet()->getFields().at(9).getVarient().data());
	//float* transY = (float*)(modelfeature->getPropertySet()->getFields().at(10).getVarient().data());
	//float* transZ = (float*)(modelfeature->getPropertySet()->getFields().at(11).getVarient().data());

	//float* rotateX = (float*)(modelfeature->getPropertySet()->getFields().at(12).getVarient().data());
	//float* rotateY = (float*)(modelfeature->getPropertySet()->getFields().at(13).getVarient().data());
	//float* rotateZ = (float*)(modelfeature->getPropertySet()->getFields().at(14).getVarient().data());



	//Ogre::uchar* blob = (Ogre::uchar*)(modelfeature->getPropertySet()->getFields().at(15).getVarient().data());
	//int siseblob = modelfeature->getPropertySet()->getFields().at(15).getVarient().getLength();
	/*

	int getid = *id;
	float mposX = *posX; 
	float mposY = *posY; 
	float mposZ = *posZ; 
	float mscaleX = *scaleX;
	float mscaleY = *scaleY;
	float mscaleZ = *scaleZ;
	float mtransX = *transX;
	float mtransY = *transY;
	float mtransZ = *transZ;
	float mrotateX = *rotateX;
	float mrotateY = *rotateY;
	float mrotateZ = *rotateZ; 
	*/



	sqlite3_stmt *statement;
	
	char *sql = "update ModelDataset set ID = ? ,Name = ? ,Type = ?,PosX = ?,PosY = ?,PosZ = ?,ScaleX = ?,ScaleY = ?,ScaleZ = ?,TransX = ?,TransY = ?,TransZ = ?,RotateX = ?,RotateY = ?,RotateZ = ?,Tag = ? WHERE Name = ?";

	//将SQL语句放入sqlite3_stmt中
	int success = sqlite3_prepare_v2(mpDB, sql, -1, &statement, NULL);
	if (success != SQLITE_OK) 
	{
		return;
	}
	sqlite3_bind_int(statement,1,id1);
	sqlite3_bind_text(statement,2,name1.c_str(),strlen(name1.c_str()),SQLITE_TRANSIENT);
	sqlite3_bind_text(statement,3,type.c_str(),strlen(type.c_str()),SQLITE_TRANSIENT);

	sqlite3_bind_double(statement,4,posx);
	sqlite3_bind_double(statement,5,posy);
	sqlite3_bind_double(statement,6,posz);

	sqlite3_bind_double(statement,7,scalex);
	sqlite3_bind_double(statement,8,scaley);
	sqlite3_bind_double(statement,9,scalez);

	sqlite3_bind_double(statement,10,transx);
	sqlite3_bind_double(statement,11,transy);
	sqlite3_bind_double(statement,12,transz);

	sqlite3_bind_double(statement,13,rotatex);
	sqlite3_bind_double(statement,14,rotatey);
	sqlite3_bind_double(statement,15,rotatez);




	sqlite3_bind_blob(statement,16,ptag,legth,NULL);
	
	const char* legth2 = featurename.c_str();
	sqlite3_bind_text(statement,17,featurename.c_str(),strlen(legth2),SQLITE_TRANSIENT);

	success = sqlite3_step(statement);

	sqlite3_finalize(statement);
}

void  CSQLiteDatabase::updataModelFeature2(VirtualMine::Database::IFeature* feature,std::string featurename,std::string datasetname)
{
	CModelFeature *modelfeature2 = dynamic_cast<CModelFeature*>(feature);
	

	CField field1 = modelfeature2->getPropertySet()->getFields().at(0);
	int* pID1 = (int*)field1.getVarient().data();
	int id1 = *pID1;

	CField field2 = modelfeature2->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string name1(pName2);

	CField field3 = modelfeature2->getPropertySet()->getFields().at(2);
	void* tmp2 = field3.getVarient().data();
	char*  pName3 = static_cast<char*>(tmp2);
	string type(pName3);

	CField field4 = modelfeature2->getPropertySet()->getFields().at(3);
	void* tmp3 = field4.getVarient().data();
	double* pWidth1 = static_cast<double*>(tmp3);
	double posx = *pWidth1;


	CField field5 = modelfeature2->getPropertySet()->getFields().at(4);
	void* tmp4 = field5.getVarient().data();
	double* pWidth2 = static_cast<double*>(tmp4);
	double posy = *pWidth2;


	CField field6 = modelfeature2->getPropertySet()->getFields().at(5);
	void* tmp5 = field6.getVarient().data();
	double* pWidth3 = static_cast<double*>(tmp5);
	double posz = *pWidth3;

	CField field7 = modelfeature2->getPropertySet()->getFields().at(6);
	void* tmp6 = field7.getVarient().data();
	double* pscale1 = static_cast<double*>(tmp6);
	double scalex = *pscale1;

	CField field8 = modelfeature2->getPropertySet()->getFields().at(7);
	void* tmp7 = field8.getVarient().data();
	double* pscale2 = static_cast<double*>(tmp7);
	double scaley = *pscale2;

	CField field9 = modelfeature2->getPropertySet()->getFields().at(8);
	void* tmp8 = field9.getVarient().data();
	double* pscale3 = static_cast<double*>(tmp8);
	double scalez = *pscale3;




	CField field10 = modelfeature2->getPropertySet()->getFields().at(9);
	void* tmp9 = field10.getVarient().data();
	double* ptrans1 = static_cast<double*>(tmp9);
	double transx = *ptrans1;

	CField field11 = modelfeature2->getPropertySet()->getFields().at(10);
	void* tmp10 = field11.getVarient().data();
	double* ptrans2 = static_cast<double*>(tmp10);
	double transy = *ptrans2;

	CField field12 = modelfeature2->getPropertySet()->getFields().at(11);
	void* tmp11 = field12.getVarient().data();
	double* ptrans3 = static_cast<double*>(tmp11);
	double transz = *ptrans3;


	CField field13 = modelfeature2->getPropertySet()->getFields().at(12);
	void* tmp12 = field13.getVarient().data();
	double* protate1 = static_cast<double*>(tmp12);
	double rotatex = *protate1;

	CField field14 = modelfeature2->getPropertySet()->getFields().at(13);
	void* tmp13 = field14.getVarient().data();
	double* protate2 = static_cast<double*>(tmp13);
	double rotatey = *protate2;

	CField field15 = modelfeature2->getPropertySet()->getFields().at(14);
	void* tmp14 = field15.getVarient().data();
	double* protate3 = static_cast<double*>(tmp14);
	double rotatez = *protate3;

	CField field16 = modelfeature2->getPropertySet()->getFields().at(15);
	void* tmp15 = field16.getVarient().data();
	double* ptag = static_cast<double*>(tmp15);
	int legth = field16.getVarient().getLength();




	//int* id = (int*)(modelfeature->getPropertySet()->getFields().at(0).getVarient().data());
	//char* na = (char*)(modelfeature->getPropertySet()->getFields().at(1).getVarient().data());
	//char* type = (char*)(modelfeature->getPropertySet()->getFields().at(2).getVarient().data());

	//float* posX = (float*)(modelfeature->getPropertySet()->getFields().at(3).getVarient().data());
	//float* posY = (float*)(modelfeature->getPropertySet()->getFields().at(4).getVarient().data());
	//float* posZ = (float*)(modelfeature->getPropertySet()->getFields().at(5).getVarient().data());

	//float* scaleX = (float*)(modelfeature->getPropertySet()->getFields().at(6).getVarient().data());
	//float* scaleY = (float*)(modelfeature->getPropertySet()->getFields().at(7).getVarient().data());
	//float* scaleZ = (float*)(modelfeature->getPropertySet()->getFields().at(8).getVarient().data());

	//float* transX = (float*)(modelfeature->getPropertySet()->getFields().at(9).getVarient().data());
	//float* transY = (float*)(modelfeature->getPropertySet()->getFields().at(10).getVarient().data());
	//float* transZ = (float*)(modelfeature->getPropertySet()->getFields().at(11).getVarient().data());

	//float* rotateX = (float*)(modelfeature->getPropertySet()->getFields().at(12).getVarient().data());
	//float* rotateY = (float*)(modelfeature->getPropertySet()->getFields().at(13).getVarient().data());
	//float* rotateZ = (float*)(modelfeature->getPropertySet()->getFields().at(14).getVarient().data());



	//Ogre::uchar* blob = (Ogre::uchar*)(modelfeature->getPropertySet()->getFields().at(15).getVarient().data());
	//int siseblob = modelfeature->getPropertySet()->getFields().at(15).getVarient().getLength();
	/*

	int getid = *id;
	float mposX = *posX; 
	float mposY = *posY; 
	float mposZ = *posZ; 
	float mscaleX = *scaleX;
	float mscaleY = *scaleY;
	float mscaleZ = *scaleZ;
	float mtransX = *transX;
	float mtransY = *transY;
	float mtransZ = *transZ;
	float mrotateX = *rotateX;
	float mrotateY = *rotateY;
	float mrotateZ = *rotateZ; 
	*/



	sqlite3_stmt *statement;
	
	std::string sql = "update " + datasetname + " set ID = ? ,Name = ? ,Type = ?,PosX = ?,PosY = ?,PosZ = ?,ScaleX = ?,ScaleY = ?,ScaleZ = ?,TransX = ?,TransY = ?,TransZ = ?,RotateX = ?,RotateY = ?,RotateZ = ?,Tag = ? WHERE Name = ?";

	//将SQL语句放入sqlite3_stmt中
	int success = sqlite3_prepare_v2(mpDB, sql.c_str(), -1, &statement, NULL);
	if (success != SQLITE_OK) 
	{
		return;
	}
	sqlite3_bind_int(statement,1,id1);
	sqlite3_bind_text(statement,2,name1.c_str(),strlen(name1.c_str()),SQLITE_TRANSIENT);
	sqlite3_bind_text(statement,3,type.c_str(),strlen(type.c_str()),SQLITE_TRANSIENT);

	sqlite3_bind_double(statement,4,posx);
	sqlite3_bind_double(statement,5,posy);
	sqlite3_bind_double(statement,6,posz);

	sqlite3_bind_double(statement,7,scalex);
	sqlite3_bind_double(statement,8,scaley);
	sqlite3_bind_double(statement,9,scalez);

	sqlite3_bind_double(statement,10,transx);
	sqlite3_bind_double(statement,11,transy);
	sqlite3_bind_double(statement,12,transz);

	sqlite3_bind_double(statement,13,rotatex);
	sqlite3_bind_double(statement,14,rotatey);
	sqlite3_bind_double(statement,15,rotatez);




	sqlite3_bind_blob(statement,16,ptag,legth,NULL);
	
	const char* legth2 = featurename.c_str();
	sqlite3_bind_text(statement,17,featurename.c_str(),strlen(legth2),SQLITE_TRANSIENT);

	success = sqlite3_step(statement);

	sqlite3_finalize(statement);

}



void CSQLiteDatabase::updateGroundModelFeature(VirtualMine::Database::CModelFeature* feature,std::string festurename)
{

	int* id = (int*)(feature->getPropertySet()->getFields().at(0).getVarient().data());
	char* na = (char*)(feature->getPropertySet()->getFields().at(1).getVarient().data());
	char* type = (char*)(feature->getPropertySet()->getFields().at(2).getVarient().data());

	float* posX = (float*)(feature->getPropertySet()->getFields().at(3).getVarient().data());
	float* posY = (float*)(feature->getPropertySet()->getFields().at(4).getVarient().data());
	float* posZ = (float*)(feature->getPropertySet()->getFields().at(5).getVarient().data());

	float* scaleX = (float*)(feature->getPropertySet()->getFields().at(6).getVarient().data());
	float* scaleY = (float*)(feature->getPropertySet()->getFields().at(7).getVarient().data());
	float* scaleZ = (float*)(feature->getPropertySet()->getFields().at(8).getVarient().data());

	float* transX = (float*)(feature->getPropertySet()->getFields().at(9).getVarient().data());
	float* transY = (float*)(feature->getPropertySet()->getFields().at(10).getVarient().data());
	float* transZ = (float*)(feature->getPropertySet()->getFields().at(11).getVarient().data());

	float* rotateX = (float*)(feature->getPropertySet()->getFields().at(12).getVarient().data());
	float* rotateY = (float*)(feature->getPropertySet()->getFields().at(13).getVarient().data());
	float* rotateZ = (float*)(feature->getPropertySet()->getFields().at(14).getVarient().data());



	Ogre::uchar* blob = (Ogre::uchar*)(feature->getPropertySet()->getFields().at(15).getVarient().data());
	int siseblob = feature->getPropertySet()->getFields().at(15).getVarient().getLength();


	int getid = *id;
	float mposX = *posX; 
	float mposY = *posY; 
	float mposZ = *posZ; 
	float mscaleX = *scaleX;
	float mscaleY = *scaleY;
	float mscaleZ = *scaleZ;
	float mtransX = *transX;
	float mtransY = *transY;
	float mtransZ = *transZ;
	float mrotateX = *rotateX;
	float mrotateY = *rotateY;
	float mrotateZ = *rotateZ; 




	sqlite3_stmt *statement;

	char *sql = "update GroundModelDataset set ID = ? ,Name = ? ,Type = ?,PosX = ?,PosY = ?,PosZ = ?,ScaleX = ?,ScaleY = ?,ScaleZ = ?,TransX = ?,TransY = ?,TransZ = ?,RotateX = ?,RotateY = ?,RotateZ = ?,Tag = ? WHERE Name = ?";

	//将SQL语句放入sqlite3_stmt中
	int success = sqlite3_prepare_v2(mpDB, sql, -1, &statement, NULL);
	if (success != SQLITE_OK) 
	{
		return;
	}
	sqlite3_bind_int(statement,1,getid);
	sqlite3_bind_text(statement,2,na,strlen(na),SQLITE_TRANSIENT);
	sqlite3_bind_text(statement,3,type,strlen(type),SQLITE_TRANSIENT);

	sqlite3_bind_double(statement,4,mposX);
	sqlite3_bind_double(statement,5,mposY);
	sqlite3_bind_double(statement,6,mposZ);

	sqlite3_bind_double(statement,7,mscaleX);
	sqlite3_bind_double(statement,8,mscaleY);
	sqlite3_bind_double(statement,9,mscaleZ);

	sqlite3_bind_double(statement,10,mtransX);
	sqlite3_bind_double(statement,11,mtransY);
	sqlite3_bind_double(statement,12,mtransZ);

	sqlite3_bind_double(statement,13,mrotateX);
	sqlite3_bind_double(statement,14,mrotateY);
	sqlite3_bind_double(statement,15,mrotateZ);




	sqlite3_bind_blob(statement,16,blob,siseblob,NULL);

	const char* legth = festurename.c_str();
	sqlite3_bind_text(statement,17,festurename.c_str(),strlen(legth),SQLITE_TRANSIENT);

	success = sqlite3_step(statement);

	sqlite3_finalize(statement);
}





/////////////////////////删除操作/////////////////////////////////////////////////////
void CSQLiteDatabase::deleteLanewayFeature(const std::string& featurename)
{
	/*VirtualMine::Database::CLanewayFeature* findfeature = this->queryLanewayDataset(featurename);
	delete findfeature;
	findfeature = NULL;
	*/
	/*int rc ;
	char * sql;
	char * zErrMsg = 0;
	sql = sqlite3_mprintf("delete from LanewayDataset where Name = '%q'",featurename);
	rc = sqlite3_exec(mpDB,sql,0,0,&zErrMsg);
	sqlite3_free(sql);*/

	int rc;
	sqlite3_stmt * stat;  
	//sqlite3_prepare( mpDB,"delete from LanewayDataset where Name = ?", -1, &stat, 0 ); 
	sqlite3_prepare_v2(mpDB,"delete from LanewayDataset where Name = ?", -1,&stat,0);
	
	sqlite3_bind_text(stat,1,featurename.c_str(),strlen(featurename.c_str()),SQLITE_STATIC);
	

	
	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );


}

void CSQLiteDatabase::deleteDrillingFeature(const std::string& featurename)
{
	int rc;
	sqlite3_stmt * stat;  
	sqlite3_prepare_v2(mpDB,"delete from DrillingDataset where Name = ?", -1,&stat,0);

	sqlite3_bind_text(stat,1,featurename.c_str(),strlen(featurename.c_str()),SQLITE_STATIC);



	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );
}

void CSQLiteDatabase::deleteDrillingAll()
{
	int rc ;
	char * sql;
	char * zErrMsg = 0;
	sql ="delete from DrillingDataset";
	rc = sqlite3_exec(mpDB,sql,0,0,&zErrMsg);
	sqlite3_free(sql);
}

void CSQLiteDatabase::deleteLanewayFeatureAll()
{
	int rc ;
	char * sql;
	char * zErrMsg = 0;
	sql ="delete from LanewayDataset";
	rc = sqlite3_exec(mpDB,sql,0,0,&zErrMsg);
	sqlite3_free(sql);
}

void CSQLiteDatabase::deleteLogicFeature(const std::string& featurename)
{
	int rc;
	sqlite3_stmt * stat;  
	sqlite3_prepare_v2(mpDB,"delete from LogicDataset where Name = ?", -1,&stat,0);

	sqlite3_bind_text(stat,1,featurename.c_str(),strlen(featurename.c_str()),SQLITE_STATIC);



	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );
}

void CSQLiteDatabase::deleteLogicFeatureALL()
{
	int rc ;
	char * sql;
	char * zErrMsg = 0;
	sql ="delete from LogicDataset";
	rc = sqlite3_exec(mpDB,sql,0,0,&zErrMsg);
	sqlite3_free(sql);
}

void CSQLiteDatabase::deleteImageFeature(const std::string& featurename)
{
	int rc;
	sqlite3_stmt * stat;  
	sqlite3_prepare_v2(mpDB,"delete from ImageDataset where Name = ?", -1,&stat,0);

	sqlite3_bind_text(stat,1,featurename.c_str(),strlen(featurename.c_str()),SQLITE_STATIC);


	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );
}

void CSQLiteDatabase::deleteImageFeatureALL()
{
	int rc ;
	char * sql;
	char * zErrMsg = 0;
	sql ="delete from ImageDataset";
	rc = sqlite3_exec(mpDB,sql,0,0,&zErrMsg);
	sqlite3_free(sql);
}

void CSQLiteDatabase::deleteDEMFeature(const std::string& featurename)
{

	int rc;
	sqlite3_stmt * stat;  
	sqlite3_prepare_v2(mpDB,"delete from DEMDataset where Name = ?", -1,&stat,0);

	sqlite3_bind_text(stat,1,featurename.c_str(),strlen(featurename.c_str()),SQLITE_STATIC);


	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );
}

void CSQLiteDatabase::deleteDEMFeatureALL()
{

	int rc ;
	char * sql;
	char * zErrMsg = 0;
	sql ="delete from DEMDataset";
	rc = sqlite3_exec(mpDB,sql,0,0,&zErrMsg);
	sqlite3_free(sql);
}

void CSQLiteDatabase::deleteModelFeature(const std::string& featurename)
{

	int rc;
	sqlite3_stmt * stat;  
	sqlite3_prepare_v2(mpDB,"delete from ModelDataset where Name = ?", -1,&stat,0);

	sqlite3_bind_text(stat,1,featurename.c_str(),strlen(featurename.c_str()),SQLITE_STATIC);


	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );
}

void CSQLiteDatabase::deleteModelFeatureALL()
{

	int rc ;
	char * sql;
	char * zErrMsg = 0;
	sql ="delete from ModelDataset";
	rc = sqlite3_exec(mpDB,sql,0,0,&zErrMsg);
	sqlite3_free(sql);
}

void  CSQLiteDatabase::deleteFaultLayerFeature(const std::string& featurename)
{


	int rc;
	sqlite3_stmt * stat;  
	sqlite3_prepare_v2(mpDB,"delete from FaultLayerDataset where Name = ?", -1,&stat,0);

	sqlite3_bind_text(stat,1,featurename.c_str(),strlen(featurename.c_str()),SQLITE_STATIC);


	rc = sqlite3_step( stat );  

	sqlite3_finalize( stat );
}

void  CSQLiteDatabase::deleteFaultLayerFeatureALL()
{
	int rc ;
	char * sql;
	char * zErrMsg = 0;
	sql ="delete from FaultLayerDataset";
	rc = sqlite3_exec(mpDB,sql,0,0,&zErrMsg);
	sqlite3_free(sql);
}



void CSQLiteDatabase::closeSQliteDatabase()
{
	sqlite3_close(mpDB);
}




///未写完
VirtualMine::Database::IDataset* CSQLiteDatabase::getDataset(const std::string& datasetName)
{
	if (this->mpDatasetSet)
	{
		std::vector<IDataset*>::iterator bItr = this->mpDatasetSet->begin();
		std::vector<IDataset*>::iterator eItr = this->mpDatasetSet->end();
		while (bItr != eItr)
		{
			if ((*bItr)->getName() == datasetName)
			{
				return *bItr;
			}
			++bItr;
		}
	}
	else
	{
	//   if (datasetName == "LanewayDataset")
	//   {
	//	return queryLanewayDataset();
	//   }
	//   else if (datasetName == "DrillingDataset")
	//   {
	//	   return queryDrillingDataset();
	//   }
	//    else if  (datasetName == "CoalLayerDataset")
	//   {
	//	   return queryCoalLayerDataset();
	//   }
	///* else if (datasetName == "FaultLayerDataset")
	//   {
	//	   return queryFaultLayerDataset;
	//   }*/
	//   else if (datasetName == "ImageDataset")
	//   {
	//	   return queryImageDataset();
	//   }
	//   else if (datasetName == "DEMDataset")
	//   {
	//	   return queryDEMDataset();
	//   }
	//   else if (datasetName == "ModelDataset")
	//   {
	//	   return queryModelDataset();
	//   }
	//   else if (datasetName == "GroundModelDataset")
	//   {
	//	   return queryModelDataset("GroundModelDataset"); 
	//   }
	//   else if (datasetName == "LocationDataset")
	//   {
	//	   return queryModelDataset("LocationDataset");
	//   }

	//   else if (datasetName == "WorkingplaneDataset")
	//   {
	//	   return queryWorkingplaneDataset();
	//   }
	//   else if(datasetName == "LogicDataset")
	//   {
	//	   return queryLogicDataset();
	//   }
	  
		CLogicDataset* logicdataset = this->queryLogicDataset();

		/////从逻辑表中获得各记录的类型，通过类型查找相应记录,名字不固定

		CLanewayDataset* lanewaydataset = NULL;
		CDrillingDataset* drilldataset = NULL;
		CCoalLayerDataset* coallayerdataset = NULL;
		CDEMDataset* demdataset = NULL;
		CImageDataset* imagedataset = NULL;
		CModelDataset* modeldataset = NULL;
		CModelDataset* groundmodeldataset = NULL;
		CModelDataset* locationdataset = NULL;
		CWorkingplaneDataset* workingplanedataset = NULL;
		CFaultLayerDataset* faultlayerDataset = NULL;
		if (logicdataset)
		{


			int count = logicdataset->getCount();
			for (int i = 0; i < count;i++)
			{
				string name = logicdataset->getFeature(i)->getFieldName();
				string type = logicdataset->getFeature(i)->getFieldType();
				if (type == VirtualMine::Core::GeoDataType::GDT_LANWAY)
				{
					lanewaydataset = this->queryLanewayDataset(name);
					return lanewaydataset;
				}
				else if (type == VirtualMine::Core::GeoDataType::GDT_COALSEAM)
				{
					coallayerdataset = this->queryCoalLayerDataset(name);
					return coallayerdataset;
				}
				else if (type == VirtualMine::Core::GeoDataType::GDT_DRILL)
				{
					drilldataset  = this->queryDrillingDataset(name);
					return drilldataset;
				} 
				else if (type == VirtualMine::Core::GeoDataType::GDT_WORKINGPLANE)
				{
					workingplanedataset = this->queryWorkingplaneDataset(name);
					return workingplanedataset;
				}
				if (type == VirtualMine::Core::GeoDataType::GDT_DEM)
				{
					demdataset = this->queryDEMDataset(name);
					return demdataset;
				}
				else if (type == VirtualMine::Core::GeoDataType::GDT_FAULT)
				{
					///////断层
					faultlayerDataset = this->queryFaultLayerDataset(name);
				   
					
					return faultlayerDataset;

				}
				else if (type == VirtualMine::Core::GeoDataType::GDT_IMAGE)
				{
					imagedataset = this->queryImageDataset(name);
					return imagedataset;
				} 
				else if (type == VirtualMine::Core::GeoDataType::GDT_MODEL)
				{
					CModelDataset* modeldst = NULL; 
					modeldst = this->queryModelDataset(name);
					int dtype = dynamic_cast<CModelFeature*>(modeldst->getFeature(0))->getFieldDeviceType();
					VirtualMine::Core::DeviceType devicetype = (VirtualMine::Core::DeviceType)dtype;
					if ( devicetype == VirtualMine::Core::DeviceType::DT_CARDREADER)
					{
						locationdataset = modeldst;
						return locationdataset;
					}
					else if (devicetype == VirtualMine::Core::DeviceType::DT_GAS)
					{
						modeldataset = modeldst;
						return modeldataset;
					}
					else if (devicetype == VirtualMine::Core::DeviceType::DT_UNKNOWN || devicetype == VirtualMine::Core::DeviceType::DT_BUILDING)
					{
						groundmodeldataset = modeldst;
						return groundmodeldataset;
					}


				}

			}
		}





	}

	return NULL;
}

std::vector<IDataset*>* CSQLiteDatabase::getDatasetSet()
{
	if (this->mpDatasetSet)
	{
		return this->mpDatasetSet;
	}



	
	CLogicDataset* logicdataset = this->queryLogicDataset();

	/////从逻辑表中获得各记录的类型，通过类型查找相应记录,名字不固定

	CLanewayDataset* lanewaydataset = NULL; 
	CDrillingDataset* drilldataset = NULL;
	CCoalLayerDataset* coallayerdataset = NULL;
	CDEMDataset* demdataset = NULL;
	CImageDataset* imagedataset = NULL;
	CModelDataset* modeldataset = NULL;
	CModelDataset* groundmodeldataset = NULL;
	CModelDataset* locationdataset = NULL;
	CWorkingplaneDataset* workingplanedataset = NULL;
	CFaultLayerDataset* faultlayerDataset = NULL;
	
	if (logicdataset)
	{


		int count = logicdataset->getCount();
        for (int i = 0; i < count;i++)
        {
			string name = logicdataset->getFeature(i)->getFieldName();
			string type = logicdataset->getFeature(i)->getFieldType();
			if (type == VirtualMine::Core::GeoDataType::GDT_LANWAY)
			{
				lanewaydataset = this->queryLanewayDataset(name);
			}
			else if (type == VirtualMine::Core::GeoDataType::GDT_COALSEAM)
			{
				coallayerdataset = this->queryCoalLayerDataset(name);
			}
			else if (type == VirtualMine::Core::GeoDataType::GDT_DRILL)
			{
				drilldataset  = this->queryDrillingDataset(name);
			} 
			else if (type == VirtualMine::Core::GeoDataType::GDT_WORKINGPLANE)
			{
				workingplanedataset = this->queryWorkingplaneDataset(name);
			}
			else if (type == VirtualMine::Core::GeoDataType::GDT_DEM)
			{
				demdataset = this->queryDEMDataset(name);
			}
			else if (type == VirtualMine::Core::GeoDataType::GDT_FAULT)
			{
				///////断层
				faultlayerDataset = this->queryFaultLayerDataset(name);    
				int i = 0;

			}
			else if (type == VirtualMine::Core::GeoDataType::GDT_IMAGE)
			{
				imagedataset = this->queryImageDataset(name);
			} 
			else if (type == VirtualMine::Core::GeoDataType::GDT_MODEL)
			{
			
				CModelDataset* modeldst = NULL; 
				modeldst = this->queryModelDataset(name);
				int dtype = dynamic_cast<CModelFeature*>(modeldst->getFeature(0))->getFieldDeviceType();
				VirtualMine::Core::DeviceType devicetype = (VirtualMine::Core::DeviceType)dtype;

				if (devicetype == VirtualMine::Core::DeviceType::DT_CARDREADER)
				{
					locationdataset = modeldst;
				}
				else if (devicetype == VirtualMine::Core::DeviceType::DT_GAS)
				{
					modeldataset = modeldst;
				}
				else if (devicetype == VirtualMine::Core::DeviceType::DT_UNKNOWN || devicetype == VirtualMine::Core::DeviceType::DT_BUILDING)
				{
					groundmodeldataset = modeldst;
				}


			}
		
        }
	}






	//CFaultLayerDataset
	if (mpDatasetSet == NULL)
	{
		mpDatasetSet = new std::vector<IDataset*>();
	}
	if (logicdataset)
	{
		this->mpDatasetSet->push_back(logicdataset);
	}
	if (lanewaydataset)
	{
		this->mpDatasetSet->push_back(lanewaydataset);
	}
	if (drilldataset)
	{
		this->mpDatasetSet->push_back(drilldataset);
	}
	if (coallayerdataset)
	{
		this->mpDatasetSet->push_back(coallayerdataset);
	}
	if (demdataset)
	{
		this->mpDatasetSet->push_back(demdataset);
	}
	if (imagedataset)
	{
		this->mpDatasetSet->push_back(imagedataset);
	}
	if (modeldataset)
	{
		this->mpDatasetSet->push_back(modeldataset);
	}
	if (groundmodeldataset)
	{
		this->mpDatasetSet->push_back(groundmodeldataset);
	}
	if (locationdataset)
	{
		this->mpDatasetSet->push_back(locationdataset);
	}
	if (workingplanedataset)
	{
		this->mpDatasetSet->push_back(workingplanedataset);
	}
	if (faultlayerDataset)
	{
		this->mpDatasetSet->push_back(faultlayerDataset);
	}

	return this->mpDatasetSet;
}

int VirtualMine::SQLiteDatabase::CSQLiteDatabase::insertUserInfoToInfoDataset( VirtualMine::Database::IFeature* modelfeature )
{

	char **results = NULL;  
	int rc(0);

	CUserInfoFeature* feature = dynamic_cast<CUserInfoFeature*>(modelfeature);

	///////向DEM数据集里添加feature
	//int count = this->mpDatasetSet->size();
	//for (int i = 0; i < count; i++)
	//{
	//	IDataset* dataset = this->mpDatasetSet->at(i);
	//	if (dataset && dataset->getType() == GeoDataType::GDT_DEM)
	//	{
	//		dataset->addFeature(*feature);
	//	}

	//}


	CField field1 = feature->getPropertySet()->getFields().at(0);
	char* name = (char*)field1.getVarient().data();
	//int id1 = *pID1;
	string name1(name);


	CField field2 = feature->getPropertySet()->getFields().at(1);
	void* tmp = field2.getVarient().data();
	char*  pName2 = static_cast<char*>(tmp);
	string pwd(pName2);



	sqlite3_stmt * stat;  
	rc = sqlite3_prepare_v2(mpDB,"insert into UserInfoDataset(Name,Password) values(?,?)", -1,&stat,0);



	sqlite3_bind_text(stat,1,name1.c_str(),strlen(name1.c_str()),SQLITE_STATIC);
	sqlite3_bind_text(stat,2,pwd.c_str(),strlen(pwd.c_str()),SQLITE_STATIC);
	rc = sqlite3_step( stat );  


	sqlite3_finalize( stat );

	return rc;

}




VirtualMine::Database::CFaultLayerDataset* VirtualMine::SQLiteDatabase::CSQLiteDatabase::queryFaultLayerDataset( const std::string& datesetName )
{
	CFaultLayerDataset* dataset = new CFaultLayerDataset();
	
	sqlite3_stmt * stat;
	std::string sql1="select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);
		double dipAngle = sqlite3_column_double(stat,2);
		double upH = sqlite3_column_double(stat,3);
		double downH = sqlite3_column_double(stat,4);
		
		const void * pData = sqlite3_column_blob( stat, 5 );
		int len = sqlite3_column_bytes( stat, 5 );

		Ogre::uchar* pGeometry = (Ogre::uchar*)pData;

		CFaultLayerFeature* feature = new CFaultLayerFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		feature->setFieldDipAngle(dipAngle);
		feature->setFieldDownLength(downH);
		feature->setFieldUpLength(upH);
		feature->setFieldBlob(pGeometry,len);

		dataset->addFeature(feature);
		 
		/*delete feature;
		feature = NULL;*/
	}
	sqlite3_finalize(stat);

	dataset->setName(datesetName);
	dataset->setType(VirtualMine::Core::GeoDataType::GDT_FAULT);
	return dataset;

}

VirtualMine::Database::CFaultLayerFeature* VirtualMine::SQLiteDatabase::CSQLiteDatabase::queryFaultLayerDataset( const std::string& datesetName,const std::string& featureName )
{

	
	sqlite3_stmt * stat;
	std::string sql1 = "select * from " + datesetName; 
	sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);


	while (sqlite3_step(stat) == SQLITE_ROW)
	{
		int id = sqlite3_column_int( stat, 0 );
		char* name = (char*)sqlite3_column_text(stat,1);
		double dipAngle = sqlite3_column_double(stat,2);
		double upH = sqlite3_column_double(stat,3);
		double downH = sqlite3_column_double(stat,4);
		
		const void * pData = sqlite3_column_blob( stat, 5 );
		int len = sqlite3_column_bytes( stat, 5 );

		Ogre::uchar* pGeometry = (Ogre::uchar*)pData;

		CFaultLayerFeature* feature = new CFaultLayerFeature();
		feature->setFieldID(id);
		feature->setFieldName(name);
		feature->setFieldDipAngle(dipAngle);
		feature->setFieldDownLength(downH);
		feature->setFieldUpLength(upH);
		feature->setFieldBlob(pGeometry,len);


		if (featureName == name)
		{
			return feature;
		}
	}



}

int VirtualMine::SQLiteDatabase::CSQLiteDatabase::deleteDBTable( const std::string& tableName )
{
	char **results = NULL; 
	int rc(0);
	std::string name = "drop table " + tableName;
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );
	this->deleteLogicFeature(tableName);
	return rc;
}



#if 0
/////////爆破系统
int VirtualMine::SQLiteDatabase::CSQLiteDatabase::createLanewSectionDataset(const std::string& tableName)
{
	char **results = NULL; 
	int rc(0);
	string name = "create table " + tableName + "(ProjectID integer, Name nvarchar(128),Type nvarchar(128),Parameter1 real, Parameter2 real,Parameter3 real,Parameter4 real,Parameter5 real)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );
	return rc;
}
int VirtualMine::SQLiteDatabase::CSQLiteDatabase::createShotHoleDataset(const std::string& tableName)
{
	char **results = NULL; 
	int rc(0);
	string name = "create table " + tableName + "(ProjectID integer,HoleID integer,Type nvarchar(128),PositionX real,PositionY real,PositionZ real,EndPositionX real,EndPositionY real,EndPositionZ real,BangOrder integer,ZhuangyaoLength real,ShuipaoniLength real,FengniLength real,ShotHoleDepth real,ShotHoleInterLength real,SmallResistLine real)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );
	return rc;

}
int VirtualMine::SQLiteDatabase::CSQLiteDatabase::createProjectFileDataset(const std::string& tableName)
{
	char **results = NULL; 
	int rc(0);
	string name = "create table " + tableName + "(ProjectID integer primary key,Name nvarchar(128), Type nvarchar(128),Manager nvarchar(128),ProjectPeriod nvarchar(128),StartTime nvarchar(128),DesignerOrginazation nvarchar(128),Designer nvarchar(128),LanewaySectionType nvarchar(128))";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );
	return rc;
}
int VirtualMine::SQLiteDatabase::CSQLiteDatabase::createEsacpeRouteDataset( const std::string& tableName )
{
	char **results = NULL; 
	int rc(0);
	std::string name = "create table " + tableName + "(ProjectID integer,PointID integer,PositionX real,PositionY real,PositionZ real)";
	rc = sqlite3_exec(mpDB,name.c_str(), NULL, NULL, results );
	return rc;
}

int VirtualMine::SQLiteDatabase::CSQLiteDatabase::insertLanewaySectionFeatureToLanewaySectionDataset( VirtualMine::Database::IFeature* feature,std::string datasetName)
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
int VirtualMine::SQLiteDatabase::CSQLiteDatabase::insertShotHoleFeatureToShotHoleDataset( VirtualMine::Database::IFeature* feature,std::string datasetName)
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

int VirtualMine::SQLiteDatabase::CSQLiteDatabase::insertProjectFileFeatureToProjectFileDataset( VirtualMine::Database::IFeature* feature,std::string datasetName)
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

int VirtualMine::SQLiteDatabase::CSQLiteDatabase::insertEscapeRouteFeatureToEscapeRouteDataset( VirtualMine::Database::IFeature* feature,std::string datasetName )
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

///查询数据
VirtualMine::Bang_Database::CLanewaySectionDataset*  VirtualMine::SQLiteDatabase::CSQLiteDatabase::queryLanewaySectionDataset(const std::string& datesetName)
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
VirtualMine::Bang_Database::CLanewaySectionFeature*  VirtualMine::SQLiteDatabase::CSQLiteDatabase::queryLanewaySectionDataset(const std::string& datesetName,const int& peojectID ,const std::string& featureName)
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
VirtualMine::Bang_Database::CProjectFileDataset*  VirtualMine::SQLiteDatabase::CSQLiteDatabase::queryProjectFileDataset(const std::string& datesetName)
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
VirtualMine::Bang_Database::CProjectFileFeature*  VirtualMine::SQLiteDatabase::CSQLiteDatabase::queryProjectFileDataset(const std::string& datesetName,const int& proID)
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

VirtualMine::Bang_Database::CShotHoleDataset*  VirtualMine::SQLiteDatabase::CSQLiteDatabase::queryShotHoleDataset(const std::string& datesetName)
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
VirtualMine::Bang_Database::CShotHoleFeature*  VirtualMine::SQLiteDatabase::CSQLiteDatabase::queryShotHoleDataset(const std::string& datesetName,const int& proId,const int& holeId)
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
VirtualMine::Bang_Database::CEscapeRouteDataset* VirtualMine::SQLiteDatabase::CSQLiteDatabase::queryEscapeRouteDataset( const std::string& datesetName )
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
VirtualMine::Bang_Database::CEscapeRouteFeature* VirtualMine::SQLiteDatabase::CSQLiteDatabase::queryEscapeRouteDataset( const std::string& datesetName,const int& proId,const int& pointId )
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

VirtualMine::Database::IDataset*  VirtualMine::SQLiteDatabase::CSQLiteDatabase::getDatasetByProjectID( const std::string& datesetType,const int& proId )
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
		sqlite3_prepare_v2( mpDB, sql1.c_str(), -1, &stat,0);

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

}

#endif
