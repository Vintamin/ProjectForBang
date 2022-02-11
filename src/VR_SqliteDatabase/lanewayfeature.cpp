#include "vrmine//vr_sqlitedatabase/sqlitedatabase/lanewayfeature.h"
#include "vrmine/vr_core/variant.h"

using namespace std;
using namespace VirtualMine::SQLiteDatabase;
using namespace VirtualMine::Database;


CLanewayFeature::CLanewayFeature()
{
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
	field2.setSize(sizeof(string));
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


	string fieldname6 = "Geometry";  
	CField field6;
	field6.setName(fieldname6);
	field6.setSize(sizeof(float));
	field6.setType(VirtualMine::Core::ValueType::VT_Blob);
	//this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname4,field4));
	//this->getPropertySet().getFields().push_back(field5);
    //this->mPropertySet.getFields().push_back(field5);
	this->mpPropertySet->insertFields(field6);


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

}

std::string CLanewayFeature::getName()
{
	return this->mName;
}

void CLanewayFeature::setName(const std::string& name)
{
	this->mName = name;
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

void CLanewayFeature::setFieldBlob(char* blob)
{
	/*CField* pField = &(this->getPropertySet().getFields().at(4));
	VirtualMine::Core::CVariant var(blob);

	pField->setVarient(blob);*/
	/*VirtualMine::Core::CVariant var(blob);
	this->getPropertySet().getFields().at(4).setVarient(var);*/
	VirtualMine::Core::CVariant var(blob);
	CField field;
	field.setName("Geometry");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,4);

}

void CLanewayFeature::addField(VirtualMine::Database::CField& field)
{
	//this->mPropertySet.getFields().push_back(field);
	this->mpPropertySet->insertFields(field);
}

VirtualMine::Database::CField CLanewayFeature::getValue(const int& index)
{
	return this->mpPropertySet->getFields().at(index);
}


VirtualMine::Database::CPropertySet* CLanewayFeature::getPropertySet()
{
	return this->mpPropertySet;
}
