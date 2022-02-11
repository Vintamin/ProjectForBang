#include "vrmine/vr_databaseengine/database/coallayerfeature.h"
#include "vrmine/vr_core/geodatatype.h"


using namespace VirtualMine::Database;
using namespace VirtualMine::Core;
using namespace std;

CCoalLayerFeature::CCoalLayerFeature()
{
	this->setType(VirtualMine::Core::GeoDataType::GDT_COALSEAM);

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
	field4.setType(VirtualMine::Core::ValueType::VT_Blob);
	this->mpPropertySet->insertFields(field4);


}

CCoalLayerFeature::~CCoalLayerFeature()
{
	delete this->mpPropertySet;
	this->mpPropertySet = NULL;
}

std::string CCoalLayerFeature::getName()
{
	return this->mName;
}

void CCoalLayerFeature::setName(const std::string& name)
{
	this->mName = name;
}

void CCoalLayerFeature::addField( CField field)
{
	this->mpPropertySet->insertFields(field);
}

CField CCoalLayerFeature::getValue(const int& index )
{
	return this->mpPropertySet->getFields().at(index);
}

VirtualMine::Database::CPropertySet* CCoalLayerFeature::getPropertySet()
{
	return this->mpPropertySet;
}

void CCoalLayerFeature::setFieldID(const int& id)
{
	VirtualMine::Core::CVariant var(id);
	CField field;
	field.setName("ID");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,0);

}

void CCoalLayerFeature::setFieldName(const std::string& name)
{
	VirtualMine::Core::CVariant var(name);
	CField field;
	field.setName("Name");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,1);

}

void CCoalLayerFeature::setFieldBlob(Ogre::uchar* blob,int length)
{
	VirtualMine::Core::CVariant var(blob,length);
	CField field;
	field.setName("Geometry");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,2);

}


void CCoalLayerFeature::setFieldTexture(Ogre::uchar* blob,int length)
{
	VirtualMine::Core::CVariant var(blob,length);
	CField field;
	field.setName("Texture");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,3);

}

void CCoalLayerFeature::setFieldTexture(CVRDataStream& datastream)
{
	datastream.reseek(0);
	VirtualMine::Core::CVariant var(datastream);
	CField field;
	field.setName("Texture");
	field.setVarient(var);
	
	this->mpPropertySet->setValue(field,3);
}


void CCoalLayerFeature::setFieldBlob(CVRDataStream& datastream)
{
	datastream.reseek(0);
	VirtualMine::Core::CVariant var(datastream);
	CField field;
	field.setName("Geometry");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,2);
}