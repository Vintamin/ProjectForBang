#include "vrmine/vr_databaseengine/database/workingplanefeature.h"
#include "vrmine/vr_core/variant.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace std;
using namespace VirtualMine::Database;


CWorkingplaneFeature::CWorkingplaneFeature()
{
	this->setType(VirtualMine::Core::GeoDataType::GDT_WORKINGPLANE);
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

CWorkingplaneFeature::~CWorkingplaneFeature()
{
	delete mpPropertySet;
	mpPropertySet = NULL;
}

std::string CWorkingplaneFeature::getName()
{
	return mName;
}

void CWorkingplaneFeature::setName(const std::string& name)
{
	this->mName = name;
}

void CWorkingplaneFeature::setFieldID(const int& id)
{

	VirtualMine::Core::CVariant var(id);
	CField field;
	field.setName("ID");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,0);
}

void CWorkingplaneFeature::setFieldName(const std::string& name)
{
	VirtualMine::Core::CVariant var(name);
	CField field;
	field.setName("Name");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,1);
}

void CWorkingplaneFeature::setFieldType(const std::string& type)
{

}

void CWorkingplaneFeature::setFieldWidth(const float& width)
{

}

void CWorkingplaneFeature::setFieldHeight(const float& height)
{

}

void CWorkingplaneFeature::setFieldBlob(Ogre::uchar* blob,int length)
{
	VirtualMine::Core::CVariant var(blob,length);
	CField field;
	field.setName("Geometry");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,2);
}

void CWorkingplaneFeature::setFieldBlob( VirtualMine::Core::CVRDataStream& datastream)
{

}

void CWorkingplaneFeature::addField(VirtualMine::Database::CField& field)
{
	this->mpPropertySet->insertFields(field);
}


VirtualMine::Database::CField CWorkingplaneFeature::getValue(const int& index)
{
	return this->mpPropertySet->getFields().at(index);
}


VirtualMine::Database::CPropertySet* CWorkingplaneFeature::getPropertySet()
{
	return this->mpPropertySet;
}