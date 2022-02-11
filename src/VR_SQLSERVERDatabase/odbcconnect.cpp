#include "vrmine/vr_sqlserverdatabase/sqlserverdatabse/odbcconnect.h"
#include "vrmine/vr_databaseengine/database/lanewaydataset.h"
#include "vrmine/vr_databaseengine/database/lanewayfeature.h"
#include "vrmine/vr_core/geodatatype.h"

#include <odbcinst.h>  

using namespace VirtualMine::Database;
using namespace VirtualMine::Core;
using namespace std;


namespace VirtualMine
{
	namespace SQLServerDatabase
	{
		CSQLServerDatasource::CSQLServerDatasource()
		{


		
		
			RETCODE retcode;//错误返回码

			// Allocate the ODBC Environment and save handle.
			retcode = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv); 
			if(retcode < 0 )//错误处理
			{
				//cout<<"allocate ODBC Environment handle errors."<<endl;
				int i = 0;
			}
			// Notify ODBC that this is an ODBC 3.0 application.
			retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION,
				(SQLPOINTER) SQL_OV_ODBC3, SQL_IS_INTEGER);
			if(retcode < 0 ) //错误处理
			{
				//cout<<"the  ODBC is not version3.0 "<<endl;
			     int i = 0;
			}

			// Allocate an ODBC connection and connect.
			retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc1);
			if(retcode < 0 ) //错误处理
			{
				int i = 0;
				//cout<<"allocate ODBC connection handle errors."<<endl;
				
			}
			//Data Source Name must be of type User DNS or System DNS
			//char* szDSN = "sqlhw";
			char* szDSN = "VRMine";

			char* szUID = "sa";//log name
			char* szAuthStr = "sa";//passward
			//connect to the Data Source
			retcode = SQLConnect(hdbc1,(SQLWCHAR*)szDSN,(SWORD)strlen(szDSN),(SQLWCHAR*)szUID, (SWORD)strlen(szUID),(SQLWCHAR*)szAuthStr, (SWORD)strlen(szAuthStr));
			
			//数据库连接
			retcode = SQLConnect(hdbc1,(SQLWCHAR*)L"VRMine",SQL_NTS,NULL,SQL_NTS,NULL,SQL_NTS);
			
			if(retcode < 0 ) //错误处理
			{  
				int i = 0;
				//cout<<"connect to  ODBC datasource errors."<<endl;			
			}
			// Allocate a statement handle.
			retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc1, &hstmt1);
			if(retcode < 0 ) //错误处理
			{
				int i = 0;
				//cout<<"allocate ODBC statement handle errors."<<endl;			
			}


		}

		CSQLServerDatasource::~CSQLServerDatasource()
		{

		}

		void CSQLServerDatasource::OnInitADOConn()
		{
			// 初始化OLE/COM库环境
			//::CoInitialize(NULL);
		}

		bool CSQLServerDatasource::openDB()
		{

			return true; 

		}

		bool CSQLServerDatasource::openDB(std::string dbName)
		{
			
			return true;
		}

		bool  CSQLServerDatasource::ExecuteSQLbyCMD(std::string SQLstr)
		{
			//m_pCommand->c

			return false;
		}

	
		bool CSQLServerDatasource::ExecuteSQL(std::string SQLstr)
		{
			//// 是否已经连接数据库
			//if(m_pConnection == NULL)
			//	OnInitADOConn();
			//_bstr_t bstrSQL = SQLstr.c_str();
			//// Connection对象的Execute方法:(_bstr_t CommandText,
			//// VARIANT * RecordsAffected, long Options )
			//// 其中CommandText是命令字串，通常是SQL命令。
			//// 参数RecordsAffected是操作完成后所影响的行数,
			//// 参数Options表示CommandText的类型：adCmdText-文本命令；adCmdTable-表名
			//// adCmdProc-存储过程；adCmdUnknown-未知
			//m_pConnection->Execute(bstrSQL,NULL,adCmdText);
			return true;

		}

		bool CSQLServerDatasource::createDatabase(std::string databaseName)
		{
			return false;
		//	string dbNameWithoutPath;
		//
		//
		//	dbNameWithoutPath = databaseName.substr(databaseName.find_last_of('\\') + 1);

		//	string path = databaseName.substr(0,databaseName.find_last_of('\\'));
		//	// 是否已经连接数据库
		///*	if(m_pConnection == NULL)
		//		OnInitADOConn();
		//	openDB();///打开数据库*/

		//	//std::string createDBsql = "CREATE DATABASE " + databaseName + " ON PRIMARY" +"(name=test_data,filename = 'D:\\mysql\\mydb2_data.mdf', size=3," +"maxsize=5,filegrowth=10%)log on" +"(name=mydbb_log,filename='D:\\mysql\\mydb2_log.ldf',size=3," + "maxsize=20,filegrowth=1)";
		//	
		//	//std::string createDBsql = "CREATE DATABASE " + dbNameWithoutPath + " ON PRIMARY" +"(name=test2_data,filename = 'D:\\mysql\\mydb2_data.mdf', size=3," +"maxsize=5,filegrowth=10%)log on" +"(name=mydb2_log,filename='D:\\mysql\\mydb2_log.ldf',size=3," + "maxsize=20,filegrowth=1)";


		//	std::string createDBsql = "CREATE DATABASE " + dbNameWithoutPath + " ON PRIMARY" +"(name=" + dbNameWithoutPath + ",filename = '" + databaseName + ".mdf'" + ", size=3," +"maxsize=5,filegrowth=10%)log on" +"(name=" + dbNameWithoutPath + "_log,filename='" + databaseName + "_log.ldf',size=3," + "maxsize=20,filegrowth=1)";




		//	//std::string createDBsql = "CREATE DATABASE " + "mydb"  +  " ON PRIMARY" + "(name=test_data,filename = ‘D:\\mysql\\mydb_data.mdf’, size=3," + "maxsize=5,filegrowth=10%)log on" +"(name=mydbb_log,filename=‘D:\\mysql\\mydb_log.ldf’,size=3," + "maxsize=20,filegrowth=1)";
		//	_bstr_t bstrSQL = createDBsql.c_str();
		//   // m_pConnection->Execute(bstrSQL,NULL,adCmdText);////需要测试


		//	//m_pConnection->Execute(bstrSQL,NULL,adCmdText);
		//
		//	////连接刚创建的数据库
		//	//if(m_pConnection == NULL)
		//		//OnInitADOConn();
		//   // openDB(dbNameWithoutPath);

		//	//_CommandPtr cmdptr;
		//	/////_SQLCommandPtr cmd;
	
		//	////cmdptr.CreateInstance(__uuidof(Command)); 
		//	//cmdptr.CreateInstance("ADODB.Command");


		//	//_variant_t Recordaff;

		//	////cmdptr->CommandType = adCmdStoredProc; 
		//	//cmdptr->ActiveConnection = m_pConnection;
		//	//cmdptr->CommandText = bstrSQL;
		//	//_RecordsetPtr pRs;
		//	//pRs = cmdptr->Execute(NULL,&Recordaff,adCmdText);


	 //      // this->mDatabaseName = dbNameWithoutPath;
		//	//return true; 

		}






		///创建数据集（表）
		int CSQLServerDatasource::createDataset(const std::string& tableName, const std::string& type)
		{
		/*	if(m_pConnection == NULL)
				OnInitADOConn();
			openDB(mDatabaseName);*/

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
		/*	else if (type == VirtualMine::Core::GeoDataType::GDT_IMAGE)
			{
				int rc = this->createImageDataset(tableName);
				return rc;
			}*/
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
				int rc = 0;
				return rc;
			}
			else if (type == VirtualMine::Core::GeoDataType::GDT_MININGAREA)
			{
				int rc =0;
				return rc;
			}

		
		
		}

	
		////创建巷道表
		int CSQLServerDatasource::createLanewayDataset(const std::string& tableName)
		{
		  //// 注意二进制数据 
		   std::string createTableSql= "create table " +  tableName + "(ID int,Name nvarchar(20),Type nvarchar(32),Width real,Height real,SectionType int,SupportType int,Geometry image,LanewayWindType int)";
		  // _bstr_t bstrSQL = createTableSql.c_str();
		
		   //m_pConnection->Execute(bstrSQL,NULL,adCmdText);

			return -1;
		}


	
		////创建模型表
		int CSQLServerDatasource::createModelDataset(const std::string& tableName)
		{
			string createTableSql = "create table " +  tableName + "(ID int, Name  nvarchar(32) ,Type nvarchar(32), PosX real, PosY real,PosZ real,ScaleX real,ScaleY real,ScaleZ real, TransX real, TransY real,TransZ real,RotateX real,RotateY real,RotateZ real,Tag image)";
			//_bstr_t bstrSQL = createTableSql.c_str();
		
			//m_pConnection->Execute(bstrSQL,NULL,adCmdText);

			return -1;
		}


	
		////创建煤层表
		int CSQLServerDatasource::createCoalLayerDataset(const std::string& tableName)
		{
					
			string name = "create table " + tableName + "(ID int,Name nvarchar(20), Geometry image,Texture image)";
			//_bstr_t bstrSQL = name.c_str();
			
			//m_pConnection->Execute(bstrSQL,NULL,adCmdText);

			return -1;
	 
		}



		////创建钻孔表
		int CSQLServerDatasource::createDrillingDataset(const std::string& tableName)
		{
			string name = "create table " + tableName + "(ID int,Name nvarchar(20) ,PositionX real,PositionY real, PositionZ real,GeoLayerInfo image)";
			//_bstr_t bstrSQL = name.c_str();
			
			//m_pConnection->Execute(bstrSQL,NULL,adCmdText);
			return -1;
		}

		////创建断层表
		int CSQLServerDatasource::createFaultLayerDataset(const std::string& tableName)
		{
			return -1;
		}

	


		////创建道路表
		int CSQLServerDatasource::createRoadDataset(const std::string& tableName)
		{
			return -1;
		}


	
		////创建DEM表
		int CSQLServerDatasource::createDEMDataset(const std::string& tableName)
		{

			string name = "create table " + tableName + "(ID int, Name nvarchar(128),Geometry image)";
		    //_bstr_t bstrSQL = name.c_str();
			
			//m_pConnection->Execute(bstrSQL,NULL,adCmdText);
			return -1;
		}


	
		////创建工作面表
		int CSQLServerDatasource::createWorkingPlaneDataset(const std::string& tableName)
		{
			string name = "create table " + tableName + "(ID int, Name nvarchar(128),Geometry image)";
			//_bstr_t bstrSQL = name.c_str();
		
			//m_pConnection->Execute(bstrSQL,NULL,adCmdText);
			return -1;
		}



		////创建影像表
		int CSQLServerDatasource::createImageDataset(const std::string& tableName)
		{
			string name = "create table " + tableName + "(ID int, Name nvarchar(32),Image image)";
			//_bstr_t bstrSQL = name.c_str();
			
			//m_pConnection->Execute(bstrSQL,NULL,adCmdText);
			return -1;
		}





		/////////插入操作
		int CSQLServerDatasource::insertFeatureToDataset(VirtualMine::Database::IFeature *feature,const std::string& tableName)
		{
			if (feature == NULL )
			{
				return -1;
			}
			
			string dataType = feature->getType();

			if(dataType == VirtualMine::Core::GeoDataType::GDT_DRILL)
			{
				insertDrillingFeatureToDrillingDataset(feature,tableName);
			}
			else if (dataType == VirtualMine::Core::GeoDataType::GDT_LANWAY)
			{
				insertLanewayFeatureToLanewayDataset(feature,tableName);
			}
				
			return 1;
		}
		int CSQLServerDatasource::insertLanewayFeatureToLanewayDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName)
		{

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

			
			///need test
			string insertSQL = "insert into " + tableName + "(ID,Name,Type,Width,Height,SectionType,SupportType,Geometry,LanewayWindType) values(?,?,?,?,?,?,?,?,?)";

			//string insertSQL = "insert into " + tableName + "(ID,Name,Type,Width,Height,SectionType,SupportType,Geometry,LanewayWindType) values(" +  

	
			//m_pRecordset->MoveFirst();//移动到第一条记录

			//m_pRecordset->AddNew();//添加新记录

			//m_pRecordset->PutCollect("ID",_variant_t(id1));

			//m_pRecordset->PutCollect("Name",_variant_t(name1.c_str()));

			//m_pRecordset->PutCollect("Type",_variant_t(type1.c_str()));

			//m_pRecordset->PutCollect("Width",_variant_t(width1));

			//m_pRecordset->PutCollect("Height",_variant_t(height1));


			//m_pRecordset->PutCollect("SectionType",_variant_t(sectiontype));

			//m_pRecordset->PutCollect("SupportType",_variant_t(supporttype));

			///////插入二进制
			//m_pRecordset->PutCollect("Geometry",_variant_t(NULL));

			//m_pRecordset->PutCollect("LanewayWindType",_variant_t(lanewayWindType));

			//m_pRecordset->Update();

			//





			return -1;
		}


		int CSQLServerDatasource::insertCoalLayerFeatureToCoalLayerDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName)
		{
			return -1;
		}

		int CSQLServerDatasource::insertDrillingFeatureToDrillingDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName)
		{
			return -1;
		}


		int CSQLServerDatasource::insertLogicFeatureToLogicDataset(VirtualMine::Database::IFeature* logicfeature)
		{
			return -1;
		}

		int CSQLServerDatasource::insertMetaDataFeatureToMetaDataset(VirtualMine::Database::IFeature* metadatafeature)
		{
			return -1;
		}


		int CSQLServerDatasource::insertImageFeatureToImageDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName)
		{
			return -1;
		}





		int CSQLServerDatasource::insertDEMFeatureToDEMDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName)
		{
			return -1;
		}

		int CSQLServerDatasource::insertWorkingplaneFeatureToWorkingPlaneDataset(VirtualMine::Database::IFeature* feature,const std::string& tableName)
		{
			return -1;
		}




		int CSQLServerDatasource::insertModelFeatureToModelDataset( VirtualMine::Database::IFeature* modelfeature,std::string modeldatasetName)
		{
			return -1;
		}


	}
}
//
//{
//
//
//	RETCODE retcode;//错误返回码
//
//	// Allocate the ODBC Environment and save handle.
//	retcode = SQLAllocHandle (SQL_HANDLE_ENV, NULL, &henv); 
//	if(retcode < 0 )//错误处理
//	{
//		cout<<"allocate ODBC Environment handle errors."<<endl;
//		return -1;
//	}
//	// Notify ODBC that this is an ODBC 3.0 application.
//	retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION,
//		(SQLPOINTER) SQL_OV_ODBC3, SQL_IS_INTEGER);
//	if(retcode < 0 ) //错误处理
//	{
//		cout<<"the  ODBC is not version3.0 "<<endl;
//		return -1;
//	}
//
//	// Allocate an ODBC connection and connect.
//	retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc1);
//	if(retcode < 0 ) //错误处理
//	{
//		cout<<"allocate ODBC connection handle errors."<<endl;
//		return -1;
//	}
//	//Data Source Name must be of type User DNS or System DNS
//	char* szDSN = "sqlhw";
//	char* szUID = "sa";//log name
//	char* szAuthStr = "wang";//passward
//	//connect to the Data Source
//	retcode=SQLConnect(hdbc1,(SQLCHAR*)szDSN,(SWORD)strlen(szDSN),(SQLCHAR*)szUID, (SWORD)strlen(szUID),(SQLCHAR*)szAuthStr, (SWORD)strlen(szAuthStr));
//	if(retcode < 0 ) //错误处理
//	{  
//		cout<<"connect to  ODBC datasource errors."<<endl;
//		return -1;
//	}
//	// Allocate a statement handle.
//	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc1, &hstmt1);
//	if(retcode < 0 ) //错误处理
//	{
//		cout<<"allocate ODBC statement handle errors."<<endl;
//		return -1;
//	}
//
//	// Execute an SQL statement directly on the statement handle.每一句后面都跟了一个错误处理，当发生错误时可以很方便的判断错在哪里
//
//	retcode = SQLExecDirect(hstmt1,(SQLCHAR*)"create table provider１(sno char(5) primary key,sname char(10) not null,status int,city char(10))", SQL_NTS);
//	if(retcode<0) 
//	{
//		cout<<"creat errors."<<endl;
//		return -1;
//	}        
//
//	retcode = SQLExecDirect(hstmt1,(SQLCHAR*)"insert into provider１ values('S1','精益','20','天津')",SQL_NTS);
//	if(retcode<0) 
//	{
//		cout<<"s1 insert errors."<<endl;
//		return -1;
//	}
//	retcode = SQLExecDirect(hstmt1,(SQLCHAR*)"insert into provider１ values('S2','胜锡','10','北京')",SQL_NTS);
//	if(retcode<0) 
//	{
//		cout<<"s2 insert errors."<<endl;
//		return -1;
//	}
//	retcode = SQLExecDirect(hstmt1,(SQLCHAR*)"insert into provider１ values('S3','东方红','30','天津')",SQL_NTS);
//	if(retcode<0) 
//	{
//		cout<<"s3 insert errors."<<endl;
//		return -1;
//	}
//	retcode = SQLExecDirect(hstmt1,(SQLCHAR*)"insert into provider１ values('S4','丰泰盛','20','天津')",SQL_NTS);
//	if(retcode<0) 
//	{
//		cout<<"s4 insert errors."<<endl;
//		return -1;
//	}
//	retcode = SQLExecDirect(hstmt1,(SQLCHAR*)"insert into provider１ values('S5','为民','30','上海')",SQL_NTS);
//	if(retcode<0) 
//	{
//		cout<<"s5 insert errors."<<endl;
//		return -1;
//	}
//	retcode = SQLExecDirect(hstmt1,(SQLCHAR*)"insert into provider１ values('S6','通天','25',null)",SQL_NTS);
//	if(retcode<0) 
//	{
//		cout<<"s6 insert errors."<<endl;
//		return -1;
//	}
//	retcode = SQLExecDirect(hstmt1,(SQLCHAR*)"SElECT sname,city  FROM provider１", SQL_NTS);
//	if(retcode < 0 )
//	{
//		cout<<"Executing statement  throught ODBC  errors."<<endl;
//		return -1;
//	}
//	// SQLBindCol variables
//	SQLCHAR      city[MaxNameLen + 1]; 
//	SQLCHAR   name[MaxNameLen + 1];
//	SQLINTEGER   columnLen = 0;//数据库定义中该属性列的长度
//#ifdef SQLBINDCOL
//
//	//游标已被封装在其中，一开始把两个列号分别写为provider中的列号2（name），4（city），结果name的值为city的值，city的值为烫烫烫烫烫烫烫烫，这才发现第二个参数应为游标中的列号，而不是表中的列号，
//	retcode = SQLBindCol(hstmt1, 1, SQL_C_CHAR,name,MaxNameLen , &columnLen); 
//	retcode = SQLBindCol(hstmt1, 2, SQL_C_CHAR,city,MaxNameLen , &columnLen);
//	while ( (retcode = SQLFetch(hstmt1) ) != SQL_NO_DATA) 
//	{  
//		if(columnLen>0)
//			printf("name = %s  city = %s/n", name,city);
//		else
//			printf("name = %s  city = NULL/n", name,city);
//	}
//
//#else
//
//	while(1 )
//	{
//		retcode = SQLFetch(hstmt1);
//		if(retcode == SQL_NO_DATA)
//			break;
//
//		retcode = SQLGetData(hstmt1, 1, SQL_C_CHAR, name, MaxNameLen, &columnLen);
//		retcode = SQLGetData(hstmt1, 2, SQL_C_CHAR, city, MaxNameLen, &columnLen);  
//		if(columnLen>0)
//			printf("name = %s  city = %s/n", name,city);
//		else
//			printf("name = %s  city = NULL/n", name,city);
//
//	}
//#endif
//	/* Clean up.*/
//	SQLFreeHandle(SQL_HANDLE_STMT, hstmt1);
//	SQLDisconnect(hdbc1);
//	SQLFreeHandle(SQL_HANDLE_DBC, hdbc1);
//	SQLFreeHandle(SQL_HANDLE_ENV, henv);
//
//
//
//}
//
//
