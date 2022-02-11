#include "vrmine/vr_databaseengine/database/userinfofeature.h"
#include "vrmine/vr_core/variant.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace std;
using namespace VirtualMine::Database;

VirtualMine::Database::CUserInfoFeature::CUserInfoFeature()
{
	this->setType(VirtualMine::Core::GeoDataType::GDT_LINE);
	this->mpPropertySet = NULL;


	if(this->mpPropertySet == NULL)
	{
		this->mpPropertySet = new CPropertySet();
	}
	


	string fieldname2 = "Name";
	CField field2;
	field2.setName(fieldname2);
	//field2.setSize(sizeof(string));
	field2.setType(VirtualMine::Core::ValueType::VT_String);
	this->mpPropertySet->insertFields(field2);

	string fieldname3 = "Password";
	CField field3;
	field2.setName(fieldname3);
	field2.setType(VirtualMine::Core::ValueType::VT_String);
	this->mpPropertySet->insertFields(field3);
}

VirtualMine::Database::CUserInfoFeature::~CUserInfoFeature()
{

}

void VirtualMine::Database::CUserInfoFeature::setFieldName( const std::string& name )
{
	VirtualMine::Core::CVariant var(name);
	CField field;
	field.setName("Name");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,0);
}

void VirtualMine::Database::CUserInfoFeature::setFieldPassword( const std::string& pwd )
{
	VirtualMine::Core::CVariant var(pwd);
	CField field;
	field.setName("Password");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,1);
}

std::string VirtualMine::Database::CUserInfoFeature::getFieldName()
{
	if ( this->mpPropertySet)
	{
		void* ptype =  this->mpPropertySet->getFields().at(0).getVarient().data();
		char* type = (char*)ptype;
		return type;
	}
	return NULL;
}

std::string VirtualMine::Database::CUserInfoFeature::getFieldPassword()
{
	if ( this->mpPropertySet)
	{
		void* ptype =  this->mpPropertySet->getFields().at(1).getVarient().data();
		char* type = (char*)ptype;
		return type;
	}
	return NULL;
}

VirtualMine::Database::CPropertySet* VirtualMine::Database::CUserInfoFeature::getPropertySet()
{

	return this->mpPropertySet;
}
