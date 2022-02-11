#include "vrmine/vr_databaseengine/database/ipropertyset.h"

using namespace std;
using namespace VirtualMine::Database;

int IPropertySet::getCount()
{
	return -1;
}

std::vector<VirtualMine::Database::CField> IPropertySet::getFields()
{
	std::vector<VirtualMine::Database::CField> vec;
	return vec;
}

VirtualMine::Database::CField IPropertySet::getValue(const int& index)
{
    VirtualMine::Database::CField field;
	return field;
}

void IPropertySet::setValue(const VirtualMine::Database::CField& field,const int& index)
{

}


void IPropertySet::insertFields(const VirtualMine::Database::CField& field)
{

}