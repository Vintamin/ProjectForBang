#include "bang/shotholefeature.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace VirtualMine::Core;
using namespace VirtualMine::Database;
using namespace std;

VirtualMine::Bang_Database::CShotHoleFeature::CShotHoleFeature()
{
	this->setType(VirtualMine::Core::GeoDataType::GDT_SHOTHOLE);
	this->mpPropertySet = NULL;

	string fieldname1 = "ProjectID";
	CField field1;
	field1.setName(fieldname1);
	field1.setSize(sizeof(int));
	field1.setType(VirtualMine::Core::ValueType::VT_Int32);
	if(this->mpPropertySet == NULL)
	{
		this->mpPropertySet = new CPropertySet();
	}
	this->mpPropertySet->insertFields(field1);

	string fieldname9 = "HoleID";
	CField field9;
	field9.setName(fieldname9);
	field9.setSize(sizeof(int));
	field9.setType(VirtualMine::Core::ValueType::VT_Int32);
	this->mpPropertySet->insertFields(field9);

	string fieldname2 = "Type";
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

	string fieldname6 = "EndPositionX";
	CField field6;
	field6.setName(fieldname6);
	field6.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field6);

	string fieldname7 = "EndPositionY";
	CField field7;
	field7.setName(fieldname7);
	field7.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field7);

	string fieldname8 = "EndPositionZ";
	CField field8;
	field8.setName(fieldname8);
	field8.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field8);

	string fieldname10 = "BangOrder";
	CField field10;
	field10.setName(fieldname10);
	//field2.setSize(sizeof(string));
	field10.setType(VirtualMine::Core::ValueType::VT_Int32);
	this->mpPropertySet->insertFields(field10);

	string fieldname11 = "ZhuangyaoLength";
	CField field11;
	field11.setName(fieldname11);
	field11.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field11);

	string fieldname12 = "ShuipaoniLength";
	CField field12;
	field12.setName(fieldname12);
	field12.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field12);

	string fieldname13 = "FengniLength";
	CField field13;
	field13.setName(fieldname13);
	field13.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field13);

	string fieldname14 = "ShotHoleDepth";
	CField field14;
	field14.setName(fieldname14);
	field14.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field14);

	string fieldname15 = "ShotHoleInterLength";
	CField field15;
	field15.setName(fieldname15);
	field15.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field15);

	string fieldname16 = "SmallResistLine";
	CField field16;
	field16.setName(fieldname16);
	field16.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field16);

}

VirtualMine::Bang_Database::CShotHoleFeature::~CShotHoleFeature()
{

}

std::string VirtualMine::Bang_Database::CShotHoleFeature::getName()
{
	return this->mName;
}

void VirtualMine::Bang_Database::CShotHoleFeature::setName(const std::string& name)
{
	this->mName = name;
}

void VirtualMine::Bang_Database::CShotHoleFeature::addField(VirtualMine::Database::CField field)
{
	if (this->mpPropertySet)
	{
		this->mpPropertySet->insertFields(field);
	}

}

VirtualMine::Database::CField VirtualMine::Bang_Database::CShotHoleFeature::getValue(const int& index)
{
	if (this->mpPropertySet)
	{
		return this->mpPropertySet->getFields().at(index);
	}
	
}


VirtualMine::Database::CPropertySet* VirtualMine::Bang_Database::CShotHoleFeature::getPropertySet()
{
	return this->mpPropertySet;
}

void VirtualMine::Bang_Database::CShotHoleFeature::setFieldProjectID(const int& id)
{
	VirtualMine::Core::CVariant var(id);
	CField field;
	field.setName("ID");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,0);
}

int VirtualMine::Bang_Database::CShotHoleFeature::getFieldProjectID()
{
	if (this->mpPropertySet)
	{
		int id = this->mpPropertySet->getFields().at(0).getVarient().toInt32();
		return id;
	}
	return 0;
}

void VirtualMine::Bang_Database::CShotHoleFeature::setFieldType(const std::string& type)
{
	VirtualMine::Core::CVariant var(type);
	CField field;
	field.setName("Type");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,2);
}
std::string VirtualMine::Bang_Database::CShotHoleFeature::getFieldType()
{
	if (this->mpPropertySet)
	{
		string type = this->mpPropertySet->getFields().at(2).getVarient().toString();
		return type;
	}
	return "";

}

void VirtualMine::Bang_Database::CShotHoleFeature::setFieldPositionX(const double& posX)
{
	VirtualMine::Core::CVariant var(posX);
	CField field;
	field.setName("PositionX");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,3);
}

void VirtualMine::Bang_Database::CShotHoleFeature::setFieldPositionY(const double& posY)
{
	VirtualMine::Core::CVariant var(posY);
	CField field;
	field.setName("PositionY");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,4);
}

void VirtualMine::Bang_Database::CShotHoleFeature::setFieldPositionZ(const double& posZ)
{
	VirtualMine::Core::CVariant var(posZ);
	CField field;
	field.setName("PositionZ");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,5);
}

double VirtualMine::Bang_Database::CShotHoleFeature::getFieldPositionX()
{
	if (this->mpPropertySet)
	{
		double height =  this->mpPropertySet->getValue(3).getVarient().toDouble();
		return height;
	}
	return 0;
}

double VirtualMine::Bang_Database::CShotHoleFeature::getFieldPositionY()
{
	if (this->mpPropertySet)
	{
		double height =  this->mpPropertySet->getValue(4).getVarient().toDouble();
		return height;
	}
	return 0;
}

double VirtualMine::Bang_Database::CShotHoleFeature::getFieldPositionZ()
{
	if (this->mpPropertySet)
	{
		double height =  this->mpPropertySet->getValue(5).getVarient().toDouble();
		return height;
	}
	return 0;
}

void VirtualMine::Bang_Database::CShotHoleFeature::setFieldPositionEndX( const double& posX )
{
	VirtualMine::Core::CVariant var(posX);
	CField field;
	field.setName("PositionEndX");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,6);
}

void VirtualMine::Bang_Database::CShotHoleFeature::setFieldPositionEndY( const double& posY )
{
	VirtualMine::Core::CVariant var(posY);
	CField field;
	field.setName("PositionEndY");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,7);
}

void VirtualMine::Bang_Database::CShotHoleFeature::setFieldPositionEndZ( const double& posZ )
{
	VirtualMine::Core::CVariant var(posZ);
	CField field;
	field.setName("PositionEndZ");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,8);
}

double VirtualMine::Bang_Database::CShotHoleFeature::getFieldPositionEndX()
{
	if (this->mpPropertySet)
	{
		double height =  this->mpPropertySet->getValue(6).getVarient().toDouble();
		return height;
	}
	return 0;
}

double VirtualMine::Bang_Database::CShotHoleFeature::getFieldPositionEndY()
{
	if (this->mpPropertySet)
	{
		double height =  this->mpPropertySet->getValue(7).getVarient().toDouble();
		return height;
	}
	return 0;
}

double VirtualMine::Bang_Database::CShotHoleFeature::getFieldPositionEndZ()
{
	if (this->mpPropertySet)
	{
		double height =  this->mpPropertySet->getValue(8).getVarient().toDouble();
		return height;
	}
	return 0;
}

void VirtualMine::Bang_Database::CShotHoleFeature::setFieldHoleID( const int& id )
{
	VirtualMine::Core::CVariant var(id);
	CField field;
	field.setName("ID");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,1);
}

int VirtualMine::Bang_Database::CShotHoleFeature::getFieldHoleID()
{
	if (this->mpPropertySet)
	{
		int id =  this->mpPropertySet->getValue(1).getVarient().toInt32();
		return id;
	}
	return 0;
}

int VirtualMine::Bang_Database::CShotHoleFeature::getFieldBangOrder()
{
	if (this->mpPropertySet)
	{
		int order =  this->mpPropertySet->getValue(9).getVarient().toInt32();
		return order;
	}
	return 0;
}

void VirtualMine::Bang_Database::CShotHoleFeature::setFieldBangOrder(const int& order)
{
	VirtualMine::Core::CVariant var(order);
	CField field;
	field.setName("BangOrder");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,9);
}

void VirtualMine::Bang_Database::CShotHoleFeature::setFieldZhuangyaoLength(const double& length)
{
	VirtualMine::Core::CVariant var(length);
	CField field;
	field.setName("ZhuangyaoLength");
	field.setVarient(var);
	this->mpPropertySet->setValue(field,10);
}
double VirtualMine::Bang_Database::CShotHoleFeature::getFieldZhuangyaoLength()
{
	if (this->mpPropertySet)
	{
		double length =  this->mpPropertySet->getValue(10).getVarient().toDouble();
		return length;
	}
	return 0;
}

void VirtualMine::Bang_Database::CShotHoleFeature::setFieldShuipaoniLength(const double& length)
{
	VirtualMine::Core::CVariant var(length);
	CField field;
	field.setName("ShuipaoniLength");
	field.setVarient(var);
	this->mpPropertySet->setValue(field,11);
}
double VirtualMine::Bang_Database::CShotHoleFeature::getFieldShuipaoniLength()
{
	if (this->mpPropertySet)
	{
		double length =  this->mpPropertySet->getValue(11).getVarient().toDouble();
		return length;
	}
	return 0;
}

void VirtualMine::Bang_Database::CShotHoleFeature::setFieldFengniLength(const double& length)
{
	VirtualMine::Core::CVariant var(length);
	CField field;
	field.setName("FengniLength");
	field.setVarient(var);
	this->mpPropertySet->setValue(field,12);
}
double VirtualMine::Bang_Database::CShotHoleFeature::getFieldFengniLength()
{
	if (this->mpPropertySet)
	{
		double length =  this->mpPropertySet->getValue(12).getVarient().toDouble();
		return length;
	}
	return 0;
}

void VirtualMine::Bang_Database::CShotHoleFeature::setFieldShotHoleDepth( const double& length )
{
	VirtualMine::Core::CVariant var(length);
	CField field;
	field.setName("ShotHoleDepth");
	field.setVarient(var);
	this->mpPropertySet->setValue(field,13);
}

double VirtualMine::Bang_Database::CShotHoleFeature::getFieldShotHoleDepth()
{
	if (this->mpPropertySet)
	{
		double length =  this->mpPropertySet->getValue(13).getVarient().toDouble();
		return length;
	}
	return 0;
}

void VirtualMine::Bang_Database::CShotHoleFeature::setFieldShotHoleInterLength( const double& length )
{
	VirtualMine::Core::CVariant var(length);
	CField field;
	field.setName("ShotHoleInterLength");
	field.setVarient(var);
	this->mpPropertySet->setValue(field,14);
}

double VirtualMine::Bang_Database::CShotHoleFeature::getFieldShotHoleInterLength()
{
	if (this->mpPropertySet)
	{
		double length =  this->mpPropertySet->getValue(14).getVarient().toDouble();
		return length;
	}
	return 0;
}

void VirtualMine::Bang_Database::CShotHoleFeature::setFieldSmallResistLine( const double& length )
{
	VirtualMine::Core::CVariant var(length);
	CField field;
	field.setName("SmallResistLine");
	field.setVarient(var);
	this->mpPropertySet->setValue(field,15);
}

double VirtualMine::Bang_Database::CShotHoleFeature::getFieldSmallResistLine()
{
	if (this->mpPropertySet)
	{
		double length = this->mpPropertySet->getValue(15).getVarient().toDouble();
		return length;
	}
	return 0;
}
