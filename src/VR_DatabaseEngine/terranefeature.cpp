#include "vrmine/vr_databaseengine/database/terranefeature.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace VirtualMine::Core;
using namespace VirtualMine::Database;
using namespace std;

VirtualMine::Database::CTerraneFeature::CTerraneFeature()
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

	string fieldname3 = "RockType";
	CField field3;
	field3.setName(fieldname3);
	field3.setType(VirtualMine::Core::ValueType::VT_String);
	this->mpPropertySet->insertFields(field3);

	string fieldname4 = "Geometry";
	CField field4;
	field4.setName(fieldname4);
	field4.setType(VirtualMine::Core::ValueType::VT_Blob);
	this->mpPropertySet->insertFields(field4);

	
}

VirtualMine::Database::CTerraneFeature::~CTerraneFeature()
{

}

std::string VirtualMine::Database::CTerraneFeature::getName()
{
	return this->mName;
}

void VirtualMine::Database::CTerraneFeature::setName( const std::string& name )
{
	this->mName = name;
}

void VirtualMine::Database::CTerraneFeature::addField( CField field )
{
	this->mpPropertySet->insertFields(field);
}

VirtualMine::Database::CField VirtualMine::Database::CTerraneFeature::getValue( const int& index )
{
	return this->mpPropertySet->getFields().at(index);
}

VirtualMine::Database::CPropertySet* VirtualMine::Database::CTerraneFeature::getPropertySet()
{
	return this->mpPropertySet;
}

void VirtualMine::Database::CTerraneFeature::setFieldID( const int& id )
{
	VirtualMine::Core::CVariant var(id);
	CField field;
	field.setName("ID");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,0);
}

void VirtualMine::Database::CTerraneFeature::setFieldName( const std::string& name )
{
	VirtualMine::Core::CVariant var(name);
	CField field;
	field.setName("Name");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,1);
}

void VirtualMine::Database::CTerraneFeature::setFieldBlob( Ogre::uchar* blob,int length )
{
	VirtualMine::Core::CVariant var(blob,length);
	CField field;
	field.setName("Geometry");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,3);
}

void VirtualMine::Database::CTerraneFeature::setFieldBlob( VirtualMine::Core::CVRDataStream& datastream )
{
	datastream.reseek(0);
	VirtualMine::Core::CVariant var(datastream);
	CField field;
	field.setName("Geometry");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,3);
}


int VirtualMine::Database::CTerraneFeature::getFieldID()
{
	int id = this->mpPropertySet->getFields().at(0).getVarient().toInt32();
	return id;
}

std::string VirtualMine::Database::CTerraneFeature::getFieldName()
{
	std::string name = this->mpPropertySet->getFields().at(1).getVarient().toString();
	return name;
}

std::string VirtualMine::Database::CTerraneFeature::getRockType()
{
	return mRockType;
}

void VirtualMine::Database::CTerraneFeature::setRockType( const std::string& rockType )
{
	this->mRockType = rockType;
}

void VirtualMine::Database::CTerraneFeature::setFieldRockType( const std::string& rockType )
{
	VirtualMine::Core::CVariant var(rockType);
	CField field;
	field.setName("RockType");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,2);
}

std::string VirtualMine::Database::CTerraneFeature::getFieldRockType()
{
	std::string rocktype = this->mpPropertySet->getFields().at(2).getVarient().toString();
	return rocktype;
}


