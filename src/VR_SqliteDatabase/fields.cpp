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
//�����ֶ�����
int CFields::addField(CField* field)
{

}
//����ʣ���ֶ����� 
int CFields::deleteField(const string& fieldName)
{

}