#include "vrmine/vr_databaseengine/database/roadfeature.h"


using namespace std;
using namespace VirtualMine::Database;
using namespace VirtualMine::Core;

CRoadFeature::CRoadFeature()
{
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

CRoadFeature::~CRoadFeature()
{
	delete this->mpPropertySet;
	mpPropertySet = NULL;
}

void CRoadFeature::addField( VirtualMine::Database::CField& field)
{
	this->mpPropertySet->insertFields(field);
}

CField CRoadFeature::getValue(const int& index)
{
   return this->mpPropertySet->getFields().at(index);
}

void CRoadFeature::setFieldID(const int& id)
{
	VirtualMine::Core::CVariant var(id);
	CField field;
	field.setName("ID");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,0);
}

void CRoadFeature::setFieldName(const std::string& name)
{
	VirtualMine::Core::CVariant var(name);
	CField field;
	field.setName("Name");
	field.setVarient(var);
	this->mpPropertySet->setValue(field,1);
}

void CRoadFeature::setFieldBlob(Ogre::uchar* blob,int length)
{
	VirtualMine::Core::CVariant var(blob,length);
	CField field;
	field.setName("Geometry");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,2);

}


