#include "vrmine/vr_sqlitedatabase/sqlitedatabase/fields.h"

CFields::CFields()
{

}


CFields::~CFields()
{

}

string CFields::getName()
{

}

void CFields::setName(const string& name)
{

}

/*string getType();
void setType(string type);
*/

int CFields::getFieldCount()
{
	return this->mFieldCount;
}

int CFields::findField(const string& fieldName);
{

}
//返回字段总数
int CFields::addField(CField* field)
{

}
//返回剩余字段总数 
int CFields::deleteField(const string& fieldName)
{

}