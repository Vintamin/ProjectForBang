#include "vrmine/vr_databaseengine/database/imagefeature.h"
#include "vrmine/vr_core/variant.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace std;
using namespace VirtualMine::Database;


CImageFeature::CImageFeature()
{
	this->setType(VirtualMine::Core::GeoDataType::GDT_IMAGE);
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
	
	string fieldname3 = "Image";
	CField field3;
	field3.setName(fieldname3);
	//field6.setSize(sizeof(float));
	field3.setType(VirtualMine::Core::ValueType::VT_Blob);
	this->mpPropertySet->insertFields(field3);

	string fieldname4 = "MinPosX";
	CField field4;
	field4.setName(fieldname4);
	field4.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field4);

	string fieldname5 = "MinPosY";
	CField field5;
	field5.setName(fieldname5);
	field5.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field5);

	string fieldname6 = "MinPosZ";
	CField field6;
	field6.setName(fieldname6);
	field6.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field6);

	string fieldname7 = "MaxPosX";
	CField field7;
	field7.setName(fieldname7);
	field7.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field7);

	string fieldname8 = "MaxPosY";
	CField field8;
	field8.setName(fieldname8);
	field8.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field8);

	string fieldname9 = "MaxPosZ";
	CField field9;
	field9.setName(fieldname9);
	field9.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field9);

}

CImageFeature::~CImageFeature()
{
	delete this->mpPropertySet;
	this->mpPropertySet = NULL;
}

std::string CImageFeature::getName()
{
	return mName;
}

void CImageFeature::setName(const std::string& name)
{
	this->mName = name; 
}

void CImageFeature::setFieldID(const int& id)
{
	VirtualMine::Core::CVariant var(id);
	CField field;
	field.setName("ID");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,0);

}

int CImageFeature::getFieldID()
{
	if (this->mpPropertySet)
	{
		int id = this->mpPropertySet->getFields().at(0).getVarient().toInt32();
		return id;
	}
	return -1;
}


void CImageFeature::setFieldName(const std::string& name)
{
	VirtualMine::Core::CVariant var(name);
	CField field;
	field.setName("Name");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,1);
}

std::string CImageFeature::getFieldName()
{
	if (this->mpPropertySet)
	{
		std::string name = this->mpPropertySet->getFields().at(1).getVarient().toString();
		return name;
	}
	return "Name is not Exist";
}
void CImageFeature::setFieldType(const std::string& type)
{

}

void CImageFeature::setFieldWidth(const float& width)
{

}

void CImageFeature::setFieldHeight(const float& height)
{

}

void CImageFeature::setFieldBlob(Ogre::uchar* blob,int length)
{
	VirtualMine::Core::CVariant var(blob,length);
	CField field;
	field.setName("Image");
	field.setVarient(var);
	this->mpPropertySet->setValue(field,2);
}
Ogre::uchar* CImageFeature::getFieldBlob()
{
	if (this->mpPropertySet)
	{
		void* blo = this->mpPropertySet->getFields().at(2).getVarient().data();
		return (Ogre::uchar*)blo;
	}
	return NULL;
}

int CImageFeature::getFieldBlobLength()
{
	if (this->mpPropertySet)
	{
		int leg = this->mpPropertySet->getFields().at(2).getVarient().getLength();
		return leg;
	}
	return -1;
}

void CImageFeature::setFieldBlob( VirtualMine::Core::CVRDataStream& datastream)
{
	datastream.reseek(0);
	VirtualMine::Core::CVariant var(datastream);
	CField field;
	field.setName("Image");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,2);
}

void CImageFeature::addField(VirtualMine::Database::CField& field)
{
	this->mpPropertySet->insertFields(field);
}

VirtualMine::Database::CField CImageFeature::getValue(const int& index)
{
	return this->mpPropertySet->getFields().at(index);
}

VirtualMine::Database::CPropertySet* CImageFeature::getPropertySet()
{
	return this->mpPropertySet;
}

void VirtualMine::Database::CImageFeature::setFieldMinPosX( const double& pos )
{
	VirtualMine::Core::CVariant var(pos);
	CField field;
	field.setName("MinPosX");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,3);
}

void VirtualMine::Database::CImageFeature::setFieldMinPosY( const double& pos )
{
	VirtualMine::Core::CVariant var(pos);
	CField field;
	field.setName("MinPosY");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,4);
}

void VirtualMine::Database::CImageFeature::setFieldMinPosZ( const double& pos )
{
	VirtualMine::Core::CVariant var(pos);
	CField field;
	field.setName("MinPosZ");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,5);
}

void VirtualMine::Database::CImageFeature::setFieldMaxPosX( const double& pos )
{
	VirtualMine::Core::CVariant var(pos);
	CField field;
	field.setName("MaxPosX");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,6);
}

void VirtualMine::Database::CImageFeature::setFieldMaxPosY( const double& pos )
{
	VirtualMine::Core::CVariant var(pos);
	CField field;
	field.setName("MaxPosY");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,7);
}

void VirtualMine::Database::CImageFeature::setFieldMaxPosZ( const double& pos )
{
	VirtualMine::Core::CVariant var(pos);
	CField field;
	field.setName("MinPosZ");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,8);
}

double VirtualMine::Database::CImageFeature::getFieldMinPosX()
{
	if (this->mpPropertySet)
	{
		double id = this->mpPropertySet->getFields().at(3).getVarient().toDouble();
		return id;
	}
	return -1;
}

double VirtualMine::Database::CImageFeature::getFieldMinPosY()
{
	if (this->mpPropertySet)
	{
		double id = this->mpPropertySet->getFields().at(4).getVarient().toDouble();
		return id;
	}
	return -1;
}

double VirtualMine::Database::CImageFeature::getFieldMinPosZ()
{
	if (this->mpPropertySet)
	{
		double id = this->mpPropertySet->getFields().at(5).getVarient().toDouble();
		return id;
	}
	return -1;
}

double VirtualMine::Database::CImageFeature::getFieldMaxPosX()
{
	if (this->mpPropertySet)
	{
		double id = this->mpPropertySet->getFields().at(6).getVarient().toDouble();
		return id;
	}
	return -1;
}

double VirtualMine::Database::CImageFeature::getFieldMaxPosY()
{
	if (this->mpPropertySet)
	{
		double id = this->mpPropertySet->getFields().at(7).getVarient().toDouble();
		return id;
	}
	return -1;
}

double VirtualMine::Database::CImageFeature::getFieldMaxPosZ()
{
	if (this->mpPropertySet)
	{
		double id = this->mpPropertySet->getFields().at(8).getVarient().toDouble();
		return id;
	}
	return -1;
}
