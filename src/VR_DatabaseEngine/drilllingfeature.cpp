#include "vrmine/vr_databaseengine/database/drillingfeature.h"
#include "vrmine/vr_core/variant.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace std;
using namespace VirtualMine::Database;


CDrillingFeature::CDrillingFeature()
{ 
	this->setType(VirtualMine::Core::GeoDataType::GDT_DRILL);
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

	string fieldname3 = "PositionX";
	CField field3;
	field3.setName(fieldname3);
	field3.setSize(sizeof(double));
	field3.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field3);

	string fieldname4 = "PositionY";
	CField field4;
	field4.setName(fieldname4);
	field4.setSize(sizeof(double));
	field4.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field4);

	string fieldname5 = "PositionZ";
	CField field5;
	field5.setName(fieldname5);
	field5.setSize(sizeof(double));
	field5.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field5);

	string fieldname6 = "GeoLayerInfo";
	CField field6;
	field6.setName(fieldname6);
	//field6.setSize(sizeof(float));
	field6.setType(VirtualMine::Core::ValueType::VT_Blob);
	this->mpPropertySet->insertFields(field6);

}

CDrillingFeature::~CDrillingFeature()
{
	delete this->mpPropertySet;
	this->mpPropertySet = NULL;
}

std::string CDrillingFeature::getName()
{
	return this->mName;
}

void CDrillingFeature::setName(const std::string& name)
{
	this->mName = name;
}

void CDrillingFeature::addField(VirtualMine::Database::CField& field)
{
	this->mpPropertySet->insertFields(field);
}

VirtualMine::Database::CField CDrillingFeature::getValue(const int& index)
{
	return this->mpPropertySet->getFields().at(index);
}

VirtualMine::Database::CPropertySet* CDrillingFeature::getPropertySet()
{
	return this->mpPropertySet;
}

void CDrillingFeature::setFieldID(const int& id)
{
	VirtualMine::Core::CVariant var(id);
	CField field;
	field.setName("ID");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,0);
}

int  CDrillingFeature::getFieldID()
{
	if (this->mpPropertySet)
	{

		int height =  this->mpPropertySet->getValue(0).getVarient().toInt32();
		return height;
	}
	return 0;
}

std::string  CDrillingFeature::getFieldName( )
{
	if (this->mpPropertySet)
	{
		/*float name = this->mpPropertySet->getFields().at(3).getName();
		return name;*/
		std::string height =  this->mpPropertySet->getValue(1).getVarient().toString();
		return height;
	}
	return "";
}

double  CDrillingFeature::getFieldPositionX( )
{
	if (this->mpPropertySet)
	{
		/*float name = this->mpPropertySet->getFields().at(3).getName();
		return name;*/
		double height =  this->mpPropertySet->getValue(2).getVarient().toDouble();
		return height;
	}
	return 0;
}

double  CDrillingFeature::getFieldPositionY( )
{
	if (this->mpPropertySet)
	{
		/*float name = this->mpPropertySet->getFields().at(3).getName();
		return name;*/
		double height =  this->mpPropertySet->getValue(3).getVarient().toDouble();
		return height;
	}
	return 0;
}

double  CDrillingFeature::getFieldPositionZ( )
{
	if (this->mpPropertySet)
	{
		/*float name = this->mpPropertySet->getFields().at(3).getName();
		return name;*/
		double height =  this->mpPropertySet->getValue(4).getVarient().toDouble();
		return height;
	}
	return 0;
}


void CDrillingFeature::setFieldName(const std::string& name)
{
	VirtualMine::Core::CVariant var(name);
	CField field;
	field.setName("Name");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,1);
}


void CDrillingFeature::setFieldPositionX(const double& posX)
{
	VirtualMine::Core::CVariant var(posX);
	CField field;
	field.setName("PositionX");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,2);
}

void CDrillingFeature::setFieldPositionY(const double& posY)
{
	VirtualMine::Core::CVariant var(posY);
	CField field;
	field.setName("PositionY");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,3);
}

void CDrillingFeature::setFieldPositionZ(const double& posZ)
{
	VirtualMine::Core::CVariant var(posZ);
	CField field;
	field.setName("PositionZ");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,4);
}

void CDrillingFeature::setFieldBlob(Ogre::uchar* blob,int length)
{
	VirtualMine::Core::CVariant var(blob,length);
	CField field;
	field.setName("GeoLayerInfo");
	field.setVarient(var);
	this->mpPropertySet->setValue(field,5);

}