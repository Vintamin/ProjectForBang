#include "vrmine/vr_databaseengine/database/faultlayerfeature.h"
#include "vrmine/vr_core/variant.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace std;
using namespace VirtualMine::Database;


CFaultLayerFeature::CFaultLayerFeature()
{
	this->setType(VirtualMine::Core::GeoDataType::GDT_FAULT);
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

	string fieldname3 = "DipAngle";
	CField field3;
	field3.setName(fieldname3);
	field3.setSize(sizeof(double));
	field3.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field3);

	string fieldname4 = "UpLength";
	CField field4;
	field4.setName(fieldname4);
	field4.setSize(sizeof(double));
	field4.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field4);

	string fieldname5 = "DownLength";
	CField field5;
	field5.setName(fieldname5);
	field5.setSize(sizeof(double));
	field5.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field5);


	string fieldname6 = "Geometry";
	CField field6;
	field6.setName(fieldname6);
	field6.setType(VirtualMine::Core::ValueType::VT_Blob);
	this->mpPropertySet->insertFields(field6);
}

CFaultLayerFeature::~CFaultLayerFeature()
{
	delete mpPropertySet;
	mpPropertySet = NULL;
}

std::string CFaultLayerFeature::getName()
{
	return mName;
}

void CFaultLayerFeature::setName(const std::string& name)
{
	this->mName = name;
}

void CFaultLayerFeature::setFieldID(const int& id)
{
	VirtualMine::Core::CVariant var(id);
	CField field;
	field.setName("ID");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,0);
}

void CFaultLayerFeature::setFieldName(const std::string& name)
{
	VirtualMine::Core::CVariant var(name);
	CField field;
	field.setName("Name");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,1);
}

void CFaultLayerFeature::setFieldDipAngle(const double& dipAngle)
{
	VirtualMine::Core::CVariant var(dipAngle);
	CField field;
	field.setName("DipAngle");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,2);
}

void CFaultLayerFeature::setFieldUpLength(const double& upLength)
{
	VirtualMine::Core::CVariant var(upLength);
	CField field;
	field.setName("UpLength");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,3);
}

void CFaultLayerFeature::setFieldDownLength(const double& downLength)
{
	VirtualMine::Core::CVariant var(downLength);
	CField field;
	field.setName("DownLength");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,4);
}

void CFaultLayerFeature::setFieldBlob(Ogre::uchar* blob,int length)
{
	VirtualMine::Core::CVariant var(blob,length);
	CField field;
	field.setName("Geometry");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,5);
}

void CFaultLayerFeature::setFieldBlob( VirtualMine::Core::CVRDataStream& datastream)
{
	VirtualMine::Core::CVariant var(datastream);
	CField field;
	field.setName("Geometry");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,5);
}

void CFaultLayerFeature::addField(VirtualMine::Database::CField& field)
{
	this->mpPropertySet->insertFields(field);
}

VirtualMine::Database::CField CFaultLayerFeature::getValue(const int& index)
{
    return this->mpPropertySet->getFields().at(index);
}


VirtualMine::Database::CPropertySet* CFaultLayerFeature::getPropertySet()
{
	return this->mpPropertySet;
} 

int CFaultLayerFeature::getFieldID()
{
	if (this->mpPropertySet)
	{
		/*float name = this->mpPropertySet->getFields().at(3).getName();
		return name;*/
		int height =  this->mpPropertySet->getValue(0).getVarient().toInt32();
		return height;
	}
	return 0;
}

std::string CFaultLayerFeature::getFieldName()
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

double CFaultLayerFeature::getFieldDipAngle()
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

double CFaultLayerFeature::getFieldUpLength()
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

double CFaultLayerFeature::getFieldDownLength()
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
