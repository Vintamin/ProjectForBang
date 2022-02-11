
#include "vrmine/vr_databaseengine/database/databaseinfo.h"
using namespace std;
using namespace VirtualMine::Database;

CDatabaseInfo::CDatabaseInfo():IDataSourceInfo()
{
	this->mType = "";
	this->mUri = "";
}
CDatabaseInfo::~CDatabaseInfo()
{

}
void CDatabaseInfo::setDataSourceType(const string& type)
{
	this->mType = type;
}
std::string CDatabaseInfo::getDataSourceType()
{
	return this->mType;
}
void CDatabaseInfo::setUri(const string& uri)
{ 
	this->mUri = uri;
}
std::string CDatabaseInfo::getUri()
{
	return this->mUri;
}