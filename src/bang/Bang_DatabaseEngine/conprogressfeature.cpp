#include "bang/conprogressfeature.h"
#include "vrmine/vr_core/geodatatype.h"
#include "vrmine/vr_databaseengine/database/field.h"


using namespace VirtualMine::Core;
using namespace VirtualMine::Database;
using namespace VirtualMine::Bang_Database;
using namespace std;


void VirtualMine::Bang_Database::CConProgressFeature::setFieldProjectID(const int& id)
{
	VirtualMine::Core::CVariant var(id);
	CField field;
	field.setName("ProjectID");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,0);
}

int VirtualMine::Bang_Database::CConProgressFeature::getFieldProjectID()
{
	if(this->mpPropertySet)
	{
		int id = this->mpPropertySet->getFields().at(0).getVarient().toInt32();
		return id;
	}
	return 0;
}

void VirtualMine::Bang_Database::CConProgressFeature::setFieldPointID(const int& id)
{
	VirtualMine::Core::CVariant var(id);
	CField field;
	field.setName("PointID");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,1);

}
int VirtualMine::Bang_Database::CConProgressFeature::getFieldPointID()
{
	if (this->mpPropertySet)
	{
		int id = this->mpPropertySet->getFields().at(1).getVarient().toInt32();
		return id;
	}
	return 0;
}


void VirtualMine::Bang_Database::CConProgressFeature::setFieldPositionX(const double& posX)
{
	VirtualMine::Core::CVariant var(posX);
	CField field;
	field.setName("PositionX");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,2);
}

void VirtualMine::Bang_Database::CConProgressFeature::setFieldPositionY(const double& posY)
{
	VirtualMine::Core::CVariant var(posY);
	CField field;
	field.setName("PositionY");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,3);
}

void VirtualMine::Bang_Database::CConProgressFeature::setFieldPositionZ(const double& posZ)
{
	VirtualMine::Core::CVariant var(posZ);
	CField field;
	field.setName("PositionZ");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,4);
}

double VirtualMine::Bang_Database::CConProgressFeature::getFieldPositionX()
{
	if (this->mpPropertySet)
	{
		double height =  this->mpPropertySet->getValue(2).getVarient().toDouble();
		return height;
	}
	return 0;
}

double VirtualMine::Bang_Database::CConProgressFeature::getFieldPositionY()
{
	if (this->mpPropertySet)
	{
		double height =  this->mpPropertySet->getValue(3).getVarient().toDouble();
		return height;
	}
	return 0;
}

double VirtualMine::Bang_Database::CConProgressFeature::getFieldPositionZ()
{
	if (this->mpPropertySet)
	{
		double height =  this->mpPropertySet->getValue(4).getVarient().toDouble();
		return height;
	}
	return 0;
}



VirtualMine::Bang_Database::CConProgressFeature::CConProgressFeature()
{
	this->setType(VirtualMine::Core::GeoDataType::GDT_CONPROGRESS);

	this->mpPropertySet = NULL;
	if(this->mpPropertySet == NULL)
	{
		this->mpPropertySet = new CPropertySet();
	}

	string fieldname1 = "ProjectID";
	CField field1;
	field1.setName(fieldname1);
	field1.setSize(sizeof(int));
	field1.setType(VirtualMine::Core::ValueType::VT_Int32);
	this->mpPropertySet->insertFields(field1);

	string fieldname2 = "PointID";
	CField field2;
	field2.setName(fieldname2);
	field2.setType(VirtualMine::Core::ValueType::VT_String);
	this->mpPropertySet->insertFields(field2);

	string fieldname3 = "PositionX";
	CField field3;
	field3.setName(fieldname3);
	field3.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field3);


	string fieldname4 = "PositionY";
	CField field4;
	field4.setName(fieldname4);
	field4.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field4);


	string fieldname5 = "PositionZ";
	CField field5;
	field5.setName(fieldname5);
	field5.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field5);
}

VirtualMine::Bang_Database::CConProgressFeature::~CConProgressFeature()
{

}



