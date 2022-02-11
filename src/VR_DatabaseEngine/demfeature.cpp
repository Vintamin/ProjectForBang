#include "vrmine/vr_databaseengine/database/demfeature.h"
#include "vrmine/vr_core/variant.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace std;
using namespace VirtualMine::Database;


CDEMFeature::CDEMFeature()
{
	this->setType(VirtualMine::Core::GeoDataType::GDT_DEM);

	mpPropertySet = NULL;
	this->mpPropertySet = NULL;

	string fieldname1 = "ID";
	CField field1;
	field1.setName(fieldname1);
	field1.setSize(sizeof(int));
	field1.setType(VirtualMine::Core::ValueType::VT_Int32);
	if(this->mpPropertySet == NULL)
	{
		this->mpPropertySet = new CPropertySet();
	}
	this->mpPropertySet->insertFields(field1);


	string fieldname2 = "Name";
	CField field2;
	field2.setName(fieldname2);
	//field2.setSize(sizeof(string));
	field2.setType(VirtualMine::Core::ValueType::VT_String);
	this->mpPropertySet->insertFields(field2);

	string fieldname3 = "Geometry";
	CField field3;
	field2.setName(fieldname3);
	field2.setType(VirtualMine::Core::ValueType::VT_Blob);
	this->mpPropertySet->insertFields(field3);
}

CDEMFeature::~CDEMFeature()
{

}

//std::string CDEMFeature::getName()
//{
//  return mName;
//}
//
//void CDEMFeature::setName(const std::string& name)
//{
//	this->mName = name;
//}
//
//std::string getType()
//{
//
//}
//
// void setType(const std::string& type)
//{
//
//}con
void CDEMFeature::addField(CField* field)
{
	this->mpPropertySet->insertFields(*field);
}

void CDEMFeature::deleteField(CField* field)
{
	//this->mpPropertySet->getFields().erase(field);
}

void CDEMFeature::setFieldID(const int& id)
{

	VirtualMine::Core::CVariant var(id);
	CField field;
	field.setName("ID");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,0);
}

void CDEMFeature::setFieldName(const std::string& name)
{
	VirtualMine::Core::CVariant var(name);
	CField field;
	field.setName("Name");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,1);
}

void CDEMFeature::setFieldType(const std::string& type)
{

}

void CDEMFeature::setFieldWidth(const float& width)
{

}

void CDEMFeature::setFieldHeight(const float& height)
{

}

void CDEMFeature::setFieldBlob(Ogre::uchar* blob,int length)
{
	VirtualMine::Core::CVariant var(blob,length);
	CField field;
	field.setName("Geometry");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,2);
}

void CDEMFeature::setFieldBlob( VirtualMine::Core::CVRDataStream& datastream)
{

}

void CDEMFeature::addField(VirtualMine::Database::CField& field)
{
	this->mpPropertySet->insertFields(field);
}


VirtualMine::Database::CField CDEMFeature::getValue(const int& index)
{
	return this->mpPropertySet->getFields().at(index);
}


VirtualMine::Database::CPropertySet* CDEMFeature::getPropertySet()
{
	return this->mpPropertySet;
}