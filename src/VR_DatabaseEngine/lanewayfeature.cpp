#include "vrmine/vr_databaseengine/database/lanewayfeature.h"
#include "vrmine/vr_core/variant.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace std;
using namespace VirtualMine::Database;
using namespace VirtualMine::Core;


CLanewayFeature::CLanewayFeature()
{
	this->mType = VirtualMine::Core::GeoDataType::GDT_LANWAY;

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
	//this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname2,field2));
	//this->getPropertySet().getFields().push_back(field2);
	//this->mPropertySet.getFields().push_back(field2);
	this->mpPropertySet->insertFields(field2);
	
	string fieldname3 = "Type";
	CField field3;
	field3.setName(fieldname3);
	field3.setSize(sizeof(string));
	field3.setType(VirtualMine::Core::ValueType::VT_String);
	//this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname2,field2));
	//this->getPropertySet().getFields().push_back(field3);
	//this->mPropertySet.getFields().push_back(field3);
	this->mpPropertySet->insertFields(field3);

	string fieldname4 = "Width";
	CField field4;
	field4.setName(fieldname4);
	field4.setSize(sizeof(float));
	field4.setType(VirtualMine::Core::ValueType::VT_Float);
	//this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname3,field3));
	//this->getPropertySet().getFields().push_back(field4);
	//this->mPropertySet.getFields().push_back(field4);
	this->mpPropertySet->insertFields(field4);

	string fieldname5 = "Height";
	CField field5;
	field5.setName(fieldname5);
	field5.setSize(sizeof(float));
	field5.setType(VirtualMine::Core::ValueType::VT_Float);
	//this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname3,field3));
	//this->getPropertySet().getFields().push_back(field4);
	//this->mPropertySet.getFields().push_back(field4);
	this->mpPropertySet->insertFields(field5);

	string fieldname7 = "SectionType";
	CField field7;
	field5.setName(fieldname7);
	field5.setSize(sizeof(int));
	field5.setType(VirtualMine::Core::ValueType::VT_Int32);
	//this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname3,field3));
	//this->getPropertySet().getFields().push_back(field4);
	//this->mPropertySet.getFields().push_back(field4);
	this->mpPropertySet->insertFields(field7);

	string fieldname8 = "SupportType";
	CField field8;
	field5.setName(fieldname8);
	field5.setSize(sizeof(int));
	field5.setType(VirtualMine::Core::ValueType::VT_Int32);
	//this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname3,field3));
	//this->getPropertySet().getFields().push_back(field4);
	//this->mPropertySet.getFields().push_back(field4);
	this->mpPropertySet->insertFields(field8);

	

	string fieldname6 = "Geometry";
	CField field6;
	field6.setName(fieldname6);
	//field6.setSize(sizeof(float));
	field6.setType(VirtualMine::Core::ValueType::VT_Blob);
	//this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname4,field4));
	//this->getPropertySet().getFields().push_back(field5);
    //this->mPropertySet.getFields().push_back(field5);
	this->mpPropertySet->insertFields(field6);


	string fieldname9 = "LanewayWindType";
	CField field9;
	field9.setName(fieldname9);
	field9.setSize(sizeof(int));
	field9.setType(VirtualMine::Core::ValueType::VT_Int32);
	//this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname3,field3));
	//this->getPropertySet().getFields().push_back(field4);
	//this->mPropertySet.getFields().push_back(field4);
	this->mpPropertySet->insertFields(field9);

	

	///附加属性
	//string fieldname7 = "Tag";
	//CField field7;
	//field7.setName(fieldname7);
	//field7.setSize(sizeof(float));
	//field7.setType(VirtualMine::Core::ValueType::VT_Blob);
	////this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname4,field4));
	////this->getPropertySet().getFields().push_back(field5);
	////this->mPropertySet.getFields().push_back(field5);
	//this->mpPropertySet->insertFields(field7);
}


CLanewayFeature::~CLanewayFeature()
{
	delete this->mpPropertySet;
	this->mpPropertySet = NULL;
}


//void CLanewayFeature::addField( std::string name,std::string type)
//{
//
//}
//
//void CLanewayFeature::addField(CField field)
//{
//
//}
//VirtualMine::Database::CPropertySet CLanewayFeature::getPropertySet()
//{
//	return this->mPropertySet;
//}
//
//VirtualMine::Database::CField getValue(const std::string& fieldName)
//{
//
//}




void CLanewayFeature::setFieldID(const int& id)
{
	////CField tmp = this->getPropertySet().getFields().at(0);
	//CField* pField = &(this->getPropertySet().getFields().at(0));
	//VirtualMine::Core::CVariant var(id);
	//pField->setVarient(id);
	/*VirtualMine::Core::CVariant var(id);
	this->getPropertySet().getFields().at(0).setVarient(var);*/
	
	//返回的vector不能改变值 

	//this->mpPropertSet->setFieldID(id);

	VirtualMine::Core::CVariant var(id);
	CField field;
	field.setName("ID");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,0);

}


void CLanewayFeature::setFieldName(const std::string& name)
{
	/*CField* pField = &(this->getPropertySet().getFields().at(1));
	VirtualMine::Core::CVariant var(name);
	pField->setVarient(name);*/
	//VirtualMine::Core::CVariant var(name);
	//this->getPropertySet().getFields().at(1).setVarient(var);
	
	VirtualMine::Core::CVariant var(name);
	CField field;
	field.setName("Name");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,1);
}

void CLanewayFeature::setFieldType(const std::string& type)
{
	/*CField* pField = &(this->getPropertySet().getFields().at(1));
	VirtualMine::Core::CVariant var(name);
	pField->setVarient(name);*/
	/*VirtualMine::Core::CVariant var(type);
	this->getPropertySet().getFields().at(2).setVarient(var);*/
	VirtualMine::Core::CVariant var(type);
	CField field;
	field.setName("Type");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,2);
}

void CLanewayFeature::setFieldWidth(const float& width)
{
	//CField* pField = &(this->getPropertySet().getFields().at(2));
	//VirtualMine::Core::CVariant var(width);
	//pField->setVarient(width);

	//VirtualMine::Core::CVariant var(width);
	//this->getPropertySet().getFields().at(3).setVarient(var);
	VirtualMine::Core::CVariant var(width);
	CField field;
	field.setName("Width");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,3);
}

void CLanewayFeature::setFieldHeight(const float& height)
{
	VirtualMine::Core::CVariant var(height);
	CField field;
	field.setName("Height");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,4);
}

void CLanewayFeature::setFieldSectionType(const int& sectionType)
{
	VirtualMine::Core::CVariant var(sectionType);
	CField field;
	field.setName("SectionType");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,5);
}

void CLanewayFeature::setFieldHeightSupportType(const int& supportType)
{
	VirtualMine::Core::CVariant var(supportType);
	CField field;
	field.setName("SupportType");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,6);
}


void CLanewayFeature::setFieldBlob(Ogre::uchar* blob,int length)
{
	/*CField* pField = &(this->getPropertySet().getFields().at(4));
	VirtualMine::Core::CVariant var(blob);

	pField->setVarient(blob);*/
	/*VirtualMine::Core::CVariant var(blob);
	this->getPropertySet().getFields().at(4).setVarient(var);*/
	VirtualMine::Core::CVariant var(blob,length);
	CField field;
	field.setName("Geometry");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,7);

}
void CLanewayFeature::setFieldBlob(CVRDataStream& datastream)
{
	datastream.reseek(0);
	VirtualMine::Core::CVariant var(datastream);
	CField field;
	field.setName("Geometry");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,7);
}


void CLanewayFeature::setFieldLanewayWindType(const int& lanewayWindType)
{
	VirtualMine::Core::CVariant var(lanewayWindType);
	CField field;
	field.setName("LanewayWindType");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,8);
}


int CLanewayFeature::getFieldID()
{
	if (this->mpPropertySet)
	{
		int id = this->mpPropertySet->getValue(0).getVarient().toInt32();
		return id;
	}
	return 0;
}

std::string  CLanewayFeature::getFieldName()
{
	if (this->mpPropertySet)
	{
		std::string name = this->mpPropertySet->getValue(1).getVarient().toString();
		return name;
	}
	return "";
}

std::string  CLanewayFeature::getFieldType()
{
	if (this->mpPropertySet)
	{
		std::string type = this->mpPropertySet->getValue(2).getVarient().toString();
		return type;
	}
	return "";
}

float  CLanewayFeature::getFieldWidth()
{
	if (this->mpPropertySet)
	{
		/*float name = this->mpPropertySet->getFields().at(3).getName();
		return name;*/
		float width =  this->mpPropertySet->getValue(3).getVarient().toFloat();
		return width;
	}
	return 0;
}

float  CLanewayFeature::getFieldHeight()
{
	if (this->mpPropertySet)
	{
		/*float name = this->mpPropertySet->getFields().at(3).getName();
		return name;*/
		float height =  this->mpPropertySet->getValue(4).getVarient().toFloat();
		return height;
	}
	return 0;
}

int  CLanewayFeature::getFieldSectionType()
{
	if (this->mpPropertySet)
	{
		/*float name = this->mpPropertySet->getFields().at(3).getName();
		return name;*/
		float sectionType =  this->mpPropertySet->getValue(5).getVarient().toInt32();
		return sectionType;
	}
	return 0;
}

int  CLanewayFeature::getFieldHeightSupportType()
{
	if (this->mpPropertySet)
	{
		/*float name = this->mpPropertySet->getFields().at(3).getName();
		return name;*/
		float supportType =  this->mpPropertySet->getValue(6).getVarient().toInt32();
		return supportType;
	}
	return 0;
}

void*  CLanewayFeature::getFieldGeometryBlob()
{
	if (this->mpPropertySet)
	{		
		void* blobData =  this->mpPropertySet->getValue(7).getVarient().data();
		/*char* pData = static_cast<char*>(blobData);
		Ogre::uchar*  pGeometry = static_cast<Ogre::uchar*>(pData);*/
		return blobData;
	}
	return NULL;
}

int  CLanewayFeature::getFieldLanewayWindType()
{
	if (this->mpPropertySet)
	{
		/*float name = this->mpPropertySet->getFields().at(3).getName();
		return name;*/
		float windType =  this->mpPropertySet->getValue(8).getVarient().toInt32();
		return windType;
	}
	return 0;
}

void CLanewayFeature::addField(VirtualMine::Database::CField& field)
{
	//this->mPropertySet.getFields().push_back(field); 
	if (mpPropertySet)
	{
    	this->mpPropertySet->insertFields(field);
	}

}

VirtualMine::Database::CField CLanewayFeature::getValue(const int& index)
{
	if (mpPropertySet)
	{
		return this->mpPropertySet->getFields().at(index);
	}

}



int VirtualMine::Database::CLanewayFeature::getFieldGeometryBlobLength()
{
	if (this->mpPropertySet)
	{				
		int len =this->mpPropertySet->getValue(7).getVarient().getLength();
		return len;
	}
    return 0;
}
