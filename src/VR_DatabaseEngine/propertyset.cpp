#include "vrmine/vr_databaseengine/database/propertyset.h"
#include "vrmine/vr_core/variant.h"

using namespace std;
using namespace VirtualMine::Database;

CPropertySet::CPropertySet()
{

}

CPropertySet::~CPropertySet()
{

}

int CPropertySet::getCount()
{
	return this->mPropertySet.size();
}

vector<VirtualMine::Database::CField> CPropertySet::getFields()
{
	return this->mPropertySet;
	
}

////没有是返回空么？
VirtualMine::Database::CField  CPropertySet::getValue(const std::string& fieldName)
{
	int fieldCount = this->mPropertySet.size();
	if (fieldCount > 0)
	{
		for (int i = 0; i < fieldCount; i++)
		{
			if (	this->mPropertySet.at(i).getName() == fieldName)
			{
				return this->mPropertySet.at(i);
			}
		}
	
	}
}

void CPropertySet::insertFields(const VirtualMine::Database::CField& field)
{
	this->mPropertySet.push_back(field);

}
void CPropertySet::setFieldID(const int& id)
{
	std::vector<VirtualMine::Database::CField>::iterator itr = this->mPropertySet.begin();
	while (itr != this->mPropertySet.end())
	{
		if (itr->getName() == "ID" )
		{
			VirtualMine::Core::CVariant var(id);
			itr->setVarient(var);
		}
	}
}

void CPropertySet::setField(const CField& field,const int& id)
{
	this->mPropertySet[id] = field;
}


VirtualMine::Database::CField CPropertySet::getValue(const int& index)
{
	return this->mPropertySet.at(index);
} 

void CPropertySet::setValue(const VirtualMine::Database::CField& field,const int& index)
{
	this->mPropertySet[index] = field;
}

//// void CPropertySet::setProperty(const string& key,ValueType keyvalue)
//{
//
//}