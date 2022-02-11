#include "bang/projectfeature.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace VirtualMine::Core;
using namespace VirtualMine::Database;
using namespace std;



VirtualMine::Bang_Database::CProjectFileFeature::CProjectFileFeature()
{
	this->setType(VirtualMine::Core::GeoDataType::GDT_IMAGE);

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

	string fieldname4 = "Manager";
	CField field4;
	field4.setName(fieldname4);
	field4.setType(VirtualMine::Core::ValueType::VT_String);
	this->mpPropertySet->insertFields(field4);

	string fieldname5 = "ProjectPeriod";
	CField field5;
	field5.setName(fieldname5);
	field5.setType(VirtualMine::Core::ValueType::VT_String);
	this->mpPropertySet->insertFields(field5);

	string fieldname6 = "StartTime";
	CField field6;
	field6.setName(fieldname6);
	field6.setType(VirtualMine::Core::ValueType::VT_String);
	this->mpPropertySet->insertFields(field6);

	

	string fieldname7 = "DesignerOrginazation";
	CField field7;
	field7.setName(fieldname7);
	field7.setType(VirtualMine::Core::ValueType::VT_String);
	this->mpPropertySet->insertFields(field7);

	string fieldname8 = "Designer";
	CField field8;
	field8.setName(fieldname8);
	field8.setType(VirtualMine::Core::ValueType::VT_String);
	this->mpPropertySet->insertFields(field8);

	string fieldname9 = "SectionType";
	CField field9;
	field9.setName(fieldname9);
	field9.setType(VirtualMine::Core::ValueType::VT_String);
	this->mpPropertySet->insertFields(field9);

}

VirtualMine::Bang_Database::CProjectFileFeature::~CProjectFileFeature()
{

}

std::string VirtualMine::Bang_Database::CProjectFileFeature::getName()
{
	return mName;
}

void VirtualMine::Bang_Database::CProjectFileFeature::setName( const std::string& name )
{
	this->mName = name;
}

void VirtualMine::Bang_Database::CProjectFileFeature::addField( VirtualMine::Database::CField field )
{
	this->mpPropertySet->insertFields(field);
}

VirtualMine::Database::CField VirtualMine::Bang_Database::CProjectFileFeature::getValue( const int& index )
{
	if (this->mpPropertySet)
	{
		return this->mpPropertySet->getFields().at(index);
	}
}

VirtualMine::Database::CPropertySet* VirtualMine::Bang_Database::CProjectFileFeature::getPropertySet()
{
	return mpPropertySet;
}

void VirtualMine::Bang_Database::CProjectFileFeature::setFieldID( const int& id )
{
	VirtualMine::Core::CVariant var(id);
	CField field;
	field.setName("ProjectID");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,0);
}



void VirtualMine::Bang_Database::CProjectFileFeature::setFieldName( const std::string& name )
{
	VirtualMine::Core::CVariant var(name);
	CField field;
	field.setName("Name");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,1);
}

std::string VirtualMine::Bang_Database::CProjectFileFeature::getFieldName()
{
	if (this->mpPropertySet)
	{
		string name = this->mpPropertySet->getFields().at(1).getVarient().toString();
		return name;
	}
	return "";
}

int VirtualMine::Bang_Database::CProjectFileFeature::getFieldID()
{
	if (this->mpPropertySet)
	{
		int id = this->mpPropertySet->getFields().at(0).getVarient().toInt32();
		return id;
	}
	return 0;
}

void VirtualMine::Bang_Database::CProjectFileFeature::setFieldType( const std::string& type )
{
	VirtualMine::Core::CVariant var(type);
	CField field;
	field.setName("Type");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,2);
}

std::string VirtualMine::Bang_Database::CProjectFileFeature::getFieldType()
{
	if (this->mpPropertySet)
	{
		string type = this->mpPropertySet->getFields().at(2).getVarient().toString();
		return type;
	}
	return "";
}

void VirtualMine::Bang_Database::CProjectFileFeature::setFieldManager(const std::string& manager)
{
	VirtualMine::Core::CVariant var(manager);
	CField field;
	field.setName("Manager");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,3);
}
std::string VirtualMine::Bang_Database::CProjectFileFeature::getFieldManager()
{
	if (this->mpPropertySet)
	{
		string manager = this->mpPropertySet->getFields().at(3).getVarient().toString();
		return manager;
	}
	return "";
}

void VirtualMine::Bang_Database::CProjectFileFeature::setFieldProjectPeriod(const std::string& projectPeriod)
{
	VirtualMine::Core::CVariant var(projectPeriod);
	CField field;
	field.setName("ProjectPeriod");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,4);
}
std::string VirtualMine::Bang_Database::CProjectFileFeature::getFieldProjectPeriod()
{
	if (this->mpPropertySet)
	{
		string projectPeriod = this->mpPropertySet->getFields().at(4).getVarient().toString();
		return projectPeriod;
	}
	return "";
}

void VirtualMine::Bang_Database::CProjectFileFeature::setFieldStartTime( const std::string& startTime )
{
	VirtualMine::Core::CVariant var(startTime);
	CField field;
	field.setName("StartTime");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,5);
}

std::string VirtualMine::Bang_Database::CProjectFileFeature::getFieldStartTime()
{
	if (this->mpPropertySet)
	{
		string startTime = this->mpPropertySet->getFields().at(5).getVarient().toString();
		return startTime;
	}
	return "";
}

void VirtualMine::Bang_Database::CProjectFileFeature::setFieldDesignerOrginazation( const std::string& designerOrginazation )
{
	VirtualMine::Core::CVariant var(designerOrginazation);
	CField field;
	field.setName("DesignerOrginazation");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,6);
}

std::string VirtualMine::Bang_Database::CProjectFileFeature::getFieldDesignerOrginazation()
{
	if (this->mpPropertySet)
	{
		string designerOrginazation = this->mpPropertySet->getFields().at(6).getVarient().toString();
		return designerOrginazation;
	}
	return "";
}

void VirtualMine::Bang_Database::CProjectFileFeature::setFieldDesigner( const std::string& designer )
{
	VirtualMine::Core::CVariant var(designer);
	CField field;
	field.setName("Designer");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,7);
}

std::string VirtualMine::Bang_Database::CProjectFileFeature::getFieldDesigner()
{
	if (this->mpPropertySet)
	{
		string designer = this->mpPropertySet->getFields().at(7).getVarient().toString();
		return designer;
	}
	return "";
}

void VirtualMine::Bang_Database::CProjectFileFeature::setFieldLanewaySectionType( const std::string& sectionType )
{
	VirtualMine::Core::CVariant var(sectionType);
	CField field;
	field.setName("SectionType");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,8);
}

std::string VirtualMine::Bang_Database::CProjectFileFeature::getFieldLanewaySectionType()
{
	if (this->mpPropertySet)
	{
		string sectionType = this->mpPropertySet->getFields().at(8).getVarient().toString();
		return sectionType;
	}
	return "";
}

