#include "bang/rocklayerfeature.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace VirtualMine::Core;
using namespace VirtualMine::Database;
using namespace std;
VirtualMine::Bang_Database::CRockLayerFeature::CRockLayerFeature()
{
	this->setType(VirtualMine::Core::GeoDataType::GDT_TERRANE);

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
	field3.setName(fieldname3);
	field3.setType(VirtualMine::Core::ValueType::VT_Blob);
	this->mpPropertySet->insertFields(field3);

	///Ãº²ãÍ¼Æ¬
	string fieldname4 = "Texture";
	CField field4;
	field4.setName(fieldname4);
	field4.setType(VirtualMine::Core::ValueType::VT_String);
	this->mpPropertySet->insertFields(field4);
}

VirtualMine::Bang_Database::CRockLayerFeature::~CRockLayerFeature()
{

}

std::string VirtualMine::Bang_Database::CRockLayerFeature::getName()
{
	return this->mName;
}

void VirtualMine::Bang_Database::CRockLayerFeature::setName( const std::string& name )
{
	this->mName = name;
}

void VirtualMine::Bang_Database::CRockLayerFeature::addField( CField field )
{
	this->mpPropertySet->insertFields(field);
}

VirtualMine::Database::CField VirtualMine::Bang_Database::CRockLayerFeature::getValue( const int& index )
{
	return this->mpPropertySet->getFields().at(index);
}

VirtualMine::Database::CPropertySet* VirtualMine::Bang_Database::CRockLayerFeature::getPropertySet()
{
	return this->mpPropertySet;
}

void VirtualMine::Bang_Database::CRockLayerFeature::setFieldID( const int& id )
{
	VirtualMine::Core::CVariant var(id);
	CField field;
	field.setName("ID");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,0);
}

void VirtualMine::Bang_Database::CRockLayerFeature::setFieldName( const std::string& name )
{
	VirtualMine::Core::CVariant var(name);
	CField field;
	field.setName("Name");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,1);
}

void VirtualMine::Bang_Database::CRockLayerFeature::setFieldBlob( Ogre::uchar* blob,int length )
{
	VirtualMine::Core::CVariant var(blob,length);
	CField field;
	field.setName("Geometry");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,2);
}

void VirtualMine::Bang_Database::CRockLayerFeature::setFieldBlob( VirtualMine::Core::CVRDataStream& datastream )
{
	datastream.reseek(0);
	VirtualMine::Core::CVariant var(datastream);
	CField field;
	field.setName("Geometry");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,2);
}

void VirtualMine::Bang_Database::CRockLayerFeature::setFieldTextureName(const std::string& texture)
{
	VirtualMine::Core::CVariant var(texture);
	CField field;
	field.setName("Texture");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,3);
}



int VirtualMine::Bang_Database::CRockLayerFeature::getFieldID()
{
	int id = this->mpPropertySet->getFields().at(0).getVarient().toInt32();
    return id;
}

std::string VirtualMine::Bang_Database::CRockLayerFeature::getFieldName()
{
	string name = this->mpPropertySet->getFields().at(1).getVarient().toString();
	return name;
}

std::string VirtualMine::Bang_Database::CRockLayerFeature::getFieldTextureName()
{
	string texture = this->mpPropertySet->getFields().at(3).getVarient().toString();
	return texture;
}
