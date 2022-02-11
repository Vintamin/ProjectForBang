#include "bang/lanewaysectionfeature.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace VirtualMine::Core;
using namespace VirtualMine::Database;
using namespace std;

VirtualMine::Bang_Database::CLanewaySectionFeature::CLanewaySectionFeature()
{
	this->setType(VirtualMine::Core::GeoDataType::GDT_LANEWAYSECTION);

	this->mpPropertySet = NULL;
	if(this->mpPropertySet == NULL)
	{
		this->mpPropertySet = new CPropertySet();
	}

	string fieldname1 = "ProjectID";
	CField field1;
	field1.setName(fieldname1);
	field1.setSize(sizeof(int));
	field1.setType(VirtualMine::Core::ValueType::VT_Int32);
	this->mpPropertySet->insertFields(field1);

	string fieldname2 = "Name";
	CField field2;
	field2.setName(fieldname2);
	field2.setType(VirtualMine::Core::ValueType::VT_String);
	this->mpPropertySet->insertFields(field2);

	string fieldname3 = "Type";
	CField field3;
	field3.setName(fieldname3);
	field3.setType(VirtualMine::Core::ValueType::VT_String);
	this->mpPropertySet->insertFields(field3);


	string fieldname4 = "Parameter1";
	CField field4;
	field4.setName(fieldname4);
	field4.setType(VirtualMine::Core::ValueType::VT_Float);
	this->mpPropertySet->insertFields(field4);


	string fieldname5 = "Parameter2";
	CField field5;
	field5.setName(fieldname5);
	field5.setType(VirtualMine::Core::ValueType::VT_Float);
	this->mpPropertySet->insertFields(field5);


	string fieldname6 = "Parameter3";
	CField field6;
	field6.setName(fieldname6);
	field6.setType(VirtualMine::Core::ValueType::VT_Float);
	this->mpPropertySet->insertFields(field6);

	string fieldname7 = "Parameter4";
	CField field7;
	field7.setName(fieldname7);
	field7.setType(VirtualMine::Core::ValueType::VT_Float);
	this->mpPropertySet->insertFields(field7);

	string fieldname8 = "Parameter5";
	CField field8;
	field8.setName(fieldname8);
	field8.setType(VirtualMine::Core::ValueType::VT_Float);
	this->mpPropertySet->insertFields(field8);
}

VirtualMine::Bang_Database::CLanewaySectionFeature::~CLanewaySectionFeature()
{

}

std::string VirtualMine::Bang_Database::CLanewaySectionFeature::getName()
{
	return mName;
}

void VirtualMine::Bang_Database::CLanewaySectionFeature::setName( const std::string& name )
{
	this->mName = name;
}

void VirtualMine::Bang_Database::CLanewaySectionFeature::addField( VirtualMine::Database::CField field )
{
	this->mpPropertySet->insertFields(field);
}

VirtualMine::Database::CField VirtualMine::Bang_Database::CLanewaySectionFeature::getValue( const int& index )
{
	if (this->mpPropertySet)
	{
		return this->mpPropertySet->getFields().at(index);
	}
	
}

VirtualMine::Database::CPropertySet* VirtualMine::Bang_Database::CLanewaySectionFeature::getPropertySet()
{
	return mpPropertySet;
}

void VirtualMine::Bang_Database::CLanewaySectionFeature::setFieldID( const int& id )
{
	VirtualMine::Core::CVariant var(id);
	CField field;
	field.setName("ID");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,0);
}

int VirtualMine::Bang_Database::CLanewaySectionFeature::getFieldID()
{
	if (mpPropertySet)
	{
		int id = this->mpPropertySet->getFields().at(0).getVarient().toInt32();
		return id;
	}
	return 0;
}

void VirtualMine::Bang_Database::CLanewaySectionFeature::setFieldName( const std::string& name )
{
	VirtualMine::Core::CVariant var(name);
	CField field;
	field.setName("Name");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,1);
}

std::string VirtualMine::Bang_Database::CLanewaySectionFeature::getFieldName()
{
	if (mpPropertySet)
	{
		string name = this->mpPropertySet->getFields().at(1).getVarient().toString();
		return name;
	}
	return "";
}

void VirtualMine::Bang_Database::CLanewaySectionFeature::setFieldType( const std::string& type )
{
	VirtualMine::Core::CVariant var(type);
	CField field;
	field.setName("Type");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,2);
}

std::string VirtualMine::Bang_Database::CLanewaySectionFeature::getFieldType()
{
	if (this->mpPropertySet)
	{
		string type = this->mpPropertySet->getFields().at(2).getVarient().toString();
		return type;
	}
	return "";
}

void VirtualMine::Bang_Database::CLanewaySectionFeature::setFieldParameter1(const float& parameter1)
{
	VirtualMine::Core::CVariant var(parameter1);
	CField field;
	field.setName("Parameter1");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,3);
}
float VirtualMine::Bang_Database::CLanewaySectionFeature::getFieldParameter1()
{
	if (this->mpPropertySet)
	{
		float parameter1 = this->mpPropertySet->getFields().at(3).getVarient().toFloat();
		return parameter1;
	}
	return 0;
	
}
void VirtualMine::Bang_Database::CLanewaySectionFeature::setFieldParameter2(const float& parameter2)
{
	VirtualMine::Core::CVariant var(parameter2);
	CField field;
	field.setName("Parameter2");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,4);
}
float VirtualMine::Bang_Database::CLanewaySectionFeature::getFieldParameter2()
{
    if (this->mpPropertySet) 
	{
		float parameter2 = this->mpPropertySet->getFields().at(4).getVarient().toFloat();
		return parameter2;
	}
	return 0;
}
void VirtualMine::Bang_Database::CLanewaySectionFeature::setFieldParameter3(const float& parameter3)
{
	VirtualMine::Core::CVariant var(parameter3);
	CField field;
	field.setName("Parameter3");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,5);
}
float VirtualMine::Bang_Database::CLanewaySectionFeature::getFieldParameter3()
{
	if (this->mpPropertySet) 
	{
		float parameter3 = this->mpPropertySet->getFields().at(5).getVarient().toFloat();
		return parameter3;
	}
	return 0;
}
void VirtualMine::Bang_Database::CLanewaySectionFeature::setFieldParameter4(const float& parameter4)
{
	VirtualMine::Core::CVariant var(parameter4);
	CField field;
	field.setName("Parameter4");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,6);
}
float VirtualMine::Bang_Database::CLanewaySectionFeature::getFieldParameter4()
{
	if (this->mpPropertySet) 
	{
		float parameter4 = this->mpPropertySet->getFields().at(6).getVarient().toFloat();
		return parameter4;
	}
	return 0;
}
void VirtualMine::Bang_Database::CLanewaySectionFeature::setFieldParameter5(const float& parameter5)
{
	VirtualMine::Core::CVariant var(parameter5);
	CField field;
	field.setName("Parameter5");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,7);
}
float VirtualMine::Bang_Database::CLanewaySectionFeature::getFieldParameter5()
{
	if (this->mpPropertySet) 
	{
		float parameter5 = this->mpPropertySet->getFields().at(7).getVarient().toFloat();
		return parameter5;
	}
	return 0;
}

//void VirtualMine::Bang_Database::CLanewaySectionFeature::setFieldHeight( const float& height )
//{
//	VirtualMine::Core::CVariant var(height);
//	CField field;
//	field.setName("Height");
//	field.setVarient(var);
//
//	this->mpPropertySet->setValue(field,3);
//}
//
//float VirtualMine::Bang_Database::CLanewaySectionFeature::getFieldHeight()
//{
//	float height = this->mpPropertySet->getFields().at(3).getVarient().toFloat();
//	return height;
//}
//
//void VirtualMine::Bang_Database::CLanewaySectionFeature::setFieldWidth( const float& width )
//{
//	VirtualMine::Core::CVariant var(width);
//	CField field;
//	field.setName("Width");
//	field.setVarient(var);
//
//	this->mpPropertySet->setValue(field,4);
//}
//
//float VirtualMine::Bang_Database::CLanewaySectionFeature::getFieldWidth()
//{
//	float width = this->mpPropertySet->getFields().at(4).getVarient().toFloat();
//	return width;
//}
//
//void VirtualMine::Bang_Database::CLanewaySectionFeature::setFieldRadius( const float& radius )
//{
//	VirtualMine::Core::CVariant var(radius);
//	CField field;
//	field.setName("Radius");
//	field.setVarient(var);
//
//	this->mpPropertySet->setValue(field,5);
//}
//
//float VirtualMine::Bang_Database::CLanewaySectionFeature::getFieldRadius()
//{
//	float radius = this->mpPropertySet->getFields().at(5).getVarient().toFloat();
//	return radius;
//}
