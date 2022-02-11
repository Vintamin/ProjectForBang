#include "vrmine/vr_databaseengine/database/logicfeature.h"

using namespace std;
using namespace VirtualMine::Database;

CLogicFeature::CLogicFeature()
{
	mpPropertySet = NULL;
	string fieldname1 = "ID";
	CField field1;
	field1.setName(fieldname1);
	field1.setSize(sizeof(int));
	field1.setType(VirtualMine::Core::ValueType::VT_Int32);
	if (mpPropertySet == NULL)
	{
		mpPropertySet = new VirtualMine::Database::CPropertySet();
	}
	//this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname1,field1));
	this->mpPropertySet->insertFields(field1);
	
	string fieldname2 = "Name";
	CField field2;
	field2.setName(fieldname2);
	//field2.setSize(sizeof(string));
	field2.setType(VirtualMine::Core::ValueType::VT_String);
	//this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname2,field2));
	this->mpPropertySet->insertFields(field2);

	string fieldname3 = "Type";
	CField field3;
	field3.setName(fieldname3);
	field3.setSize(sizeof(string));
	field3.setType(VirtualMine::Core::ValueType::VT_String);
	//this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname2,field2));
	this->mpPropertySet->insertFields(field3);

	string fieldname4 = "minRangeX";
	CField field4;
	field4.setName(fieldname4);
	field4.setSize(sizeof(double));
	field4.setType(VirtualMine::Core::ValueType::VT_Double);
	//this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname2,field2));
	this->mpPropertySet->insertFields(field4);

	string fieldname5 = "minRangeY";
	CField field5;
	field5.setName(fieldname5);
	field5.setSize(sizeof(double));
	field5.setType(VirtualMine::Core::ValueType::VT_Double);
	//this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname2,field2));
	this->mpPropertySet->insertFields(field5);

	string fieldname6 = "minRangeZ";
	CField field6;
	field6.setName(fieldname6);
	field6.setSize(sizeof(double));
	field6.setType(VirtualMine::Core::ValueType::VT_Double);
	//this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname2,field2));
	this->mpPropertySet->insertFields(field6);

	string fieldname7 = "maxRangeX";
	CField field7;
	field7.setName(fieldname7);
	field7.setSize(sizeof(double));
	field7.setType(VirtualMine::Core::ValueType::VT_Double);
	//this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname2,field2));
	this->mpPropertySet->insertFields(field7);

	string fieldname8 = "maxRangeY";
	CField field8;
	field8.setName(fieldname8);
	field8.setSize(sizeof(double));
	field8.setType(VirtualMine::Core::ValueType::VT_Double);
	//this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname2,field2));
	this->mpPropertySet->insertFields(field8);

	string fieldname9 = "maxRangeZ";
	CField field9;
	field9.setName(fieldname9);
	field9.setSize(sizeof(double));
	field9.setType(VirtualMine::Core::ValueType::VT_Double);
	//this->getPropertySet().getFields().insert(map<string,VirtualMine::Database::CField>::value_type(fieldname2,field2));
	this->mpPropertySet->insertFields(field9);
}

CLogicFeature::~CLogicFeature()
{
	delete this->mpPropertySet;
	this->mpPropertySet = NULL;
}

//void CLogicFeature::setFieldID(const int& id,const int& index)
//{
//	/*map<string,CField>::iterator itr = this->getPropertySet().getFields().find("ID");	
//	CField field = itr->second;
//	void* pData = field.getVarient().data();
//	int* pRealData = static_cast<int*>(pData);
//	if(pRealData)
//	{
//		*pRealData = id;
//	}*/
//}
//
//void CLogicFeature::setFieldName(const std::string& name,const int& index)
//{
//	/*map<string,CField>::iterator itr = this->getPropertySet().getFields().find("Name");	
//	CField field = itr->second;
//	void* pData = field.getVarient().data();
//	string* pRealData = static_cast<string*>(pData);
//	if(pRealData)
//	{
//		*pRealData = name;
//	}*/
//}
//
//void CLogicFeature::setFieldType(const std::string& type,const int& index)
//{
//	/*map<string,CField>::iterator itr = this->getPropertySet().getFields().find("Type");	
//	CField field = itr->second;
//	void* pData = field.getVarient().data();
//	string* pRealData = static_cast<string*>(pData);
//	if(pRealData)
//	{
//		*pRealData = type;
//	}*/
//}


void CLogicFeature::setFieldID(const int& id)
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


void CLogicFeature::setFieldName(const std::string& name)
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

std::string CLogicFeature::getFieldName()
{
	if (this->mpPropertySet)
	{
		std::string name = this->mpPropertySet->getFields().at(1).getVarient().toString();
		return name;
	}
	return "";
}

std::string CLogicFeature::getFieldType()
{
	if (this->mpPropertySet)
	{
		std::string type = this->mpPropertySet->getFields().at(2).getVarient().toString();
		return type;
	}
	return "";

}

void CLogicFeature::setFieldType(const std::string& type)
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


double CLogicFeature::getFieldminRangeX()
{
	if (this->mpPropertySet)
	{
	    double x = this->mpPropertySet->getFields().at(3).getVarient().toDouble();
		return x;
	}
	return 0;
}

double CLogicFeature::getFieldminRangeY()
{
	if (this->mpPropertySet)
	{
		double y = this->mpPropertySet->getFields().at(4).getVarient().toDouble();
		return y;
	}
	return 0;
}

double CLogicFeature::getFieldminRangeZ()
{
	if (this->mpPropertySet)
	{
		double z = this->mpPropertySet->getFields().at(5).getVarient().toDouble();
		return z;
	}
	return 0;
}

double CLogicFeature::getFieldmaxRangeX()
{
	if (this->mpPropertySet)
	{
		double x = this->mpPropertySet->getFields().at(6).getVarient().toDouble();
		return x;
	}
	return 0;
}

double CLogicFeature::getFieldmaxRangeY()
{
	if (this->mpPropertySet)
	{
		double y = this->mpPropertySet->getFields().at(7).getVarient().toDouble();
		return y;
	}
	return 0;
}

double CLogicFeature::getFieldmaxRangeZ()
{
	if (this->mpPropertySet)
	{
		double z = this->mpPropertySet->getFields().at(8).getVarient().toDouble();
		return z;
	}
	return 0;
}


void CLogicFeature::setFieldminRangeX(const double& rangeX)
{
	VirtualMine::Core::CVariant var(rangeX);
	CField field;
	field.setName("minRangeX");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,3);
}

void CLogicFeature::setFieldminRangeY(const double& rangeY)
{
	VirtualMine::Core::CVariant var(rangeY);
	CField field;
	field.setName("minRangeY");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,4);
}

void CLogicFeature::setFieldminRangeZ(const double& rangeZ)
{
	VirtualMine::Core::CVariant var(rangeZ);
	CField field;
	field.setName("minRangeZ");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,5);
}

void CLogicFeature::setFieldmaxRangeX(const double& rangeX)
{
	VirtualMine::Core::CVariant var(rangeX);
	CField field;
	field.setName("maxRangeX");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,6);
}

void CLogicFeature::setFieldmaxRangeY(const double& rangeY)
{
	VirtualMine::Core::CVariant var(rangeY);
	CField field;
	field.setName("maxRangeY");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,7);
}

void CLogicFeature::setFieldmaxRangeZ(const double& rangeZ)
{
	VirtualMine::Core::CVariant var(rangeZ);
	CField field;
	field.setName("maxRangeZ");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,8);
}


VirtualMine::Database::CPropertySet* CLogicFeature::getPropertySet()
{
	return this->mpPropertySet;
}
