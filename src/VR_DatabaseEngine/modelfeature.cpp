#include "vrmine/vr_databaseengine/database/modelfeature.h"
#include "vrmine/vr_core/geodatatype.h"

using namespace std;
using namespace VirtualMine::Database;
using namespace VirtualMine::Core;

CModelFeature::CModelFeature()
{
	this->setType(VirtualMine::Core::GeoDataType::GDT_MODEL);
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

	string fieldname3 = "Type";
	CField field3;
	field3.setName(fieldname3);

	field3.setType(VirtualMine::Core::ValueType::VT_String);
	this->mpPropertySet->insertFields(field3);
	

	string fieldname4 = "PosX";
	CField field4;
	field4.setName(fieldname4);	
	field4.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field4);

	string fieldname5 = "PosY";
	CField field5;
	field5.setName(fieldname5);	
	field5.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field5);

	string fieldname6 = "PosZ";
	CField field6;
	field6.setName(fieldname6);	
	field6.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field6);



	string fieldname7 = "ScaleX";
	CField field7;
	field7.setName(fieldname7);	
	field7.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field7);

	string fieldname8 = "ScaleY";
	CField field8;
	field8.setName(fieldname8);	
	field8.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field8);

	string fieldname9 = "ScaleZ";
	CField field9;
	field9.setName(fieldname9);	
	field9.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field9);


	string fieldname10 = "TransX";
	CField field10;
	field10.setName(fieldname10);	
	field10.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field10);

	string fieldname11 = "TransY";
	CField field11;
	field11.setName(fieldname11);	
	field11.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field11);

	string fieldname12 = "TransZ";
	CField field12;
	field12.setName(fieldname12);	
	field12.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field12);

	string fieldname13 = "RotateX";
	CField field13;
	field13.setName(fieldname13);	
	field13.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field13);

	string fieldname14 = "RotateY";
	CField field14;
	field14.setName(fieldname14);	
	field14.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field14);

	string fieldname15 = "RoteteZ";
	CField field15;
	field15.setName(fieldname15);	
	field15.setType(VirtualMine::Core::ValueType::VT_Double);
	this->mpPropertySet->insertFields(field15);

	///¸½¼ÓÊôÐÔ
	string fieldname16 = "Tag";
	CField field16;
	field16.setName(fieldname16);	
	field16.setType(VirtualMine::Core::ValueType::VT_Blob);
	this->mpPropertySet->insertFields(field16);

	string fieldname17 = "DeviceType";
	CField field17;
	field17.setName(fieldname17);	
	field17.setType(VirtualMine::Core::ValueType::VT_Int32);
	this->mpPropertySet->insertFields(field17);


}

CModelFeature::~CModelFeature()
{
	delete this->mpPropertySet;
	mpPropertySet = NULL;
}

std::string CModelFeature::getName()
{
	return this->mName;
}

void CModelFeature::setName(const std::string& name)
{
	this->mName = name;
}

void CModelFeature::addField(CField field)
{
	this->mpPropertySet->insertFields(field);
}

VirtualMine::Database::CField CModelFeature::getValue(const int& index)
{
	return this->mpPropertySet->getFields().at(index);
}

VirtualMine::Database::CPropertySet* CModelFeature::getPropertySet()
{
	return mpPropertySet;
}

void CModelFeature::setFieldID(const int& id)
{
	VirtualMine::Core::CVariant var(id);
	CField field;
	field.setName("ID");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,0);
}

void CModelFeature::setFieldName(const std::string& name)
{
	VirtualMine::Core::CVariant var(name);
	CField field;
	field.setName("Name");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,1);
}

std::string CModelFeature::getFieldName()
{
	if ( this->mpPropertySet)
	{
		void* pname =  this->mpPropertySet->getFields().at(1).getVarient().data();
		char* pna = (char*)pname;
		return pna;
	}
	return NULL;
}
std::string CModelFeature::getFieldType()
{
	if ( this->mpPropertySet)
	{
		void* ptype =  this->mpPropertySet->getFields().at(2).getVarient().data();
		char* type = (char*)ptype;
		return type;
	}
	return NULL;

}

void CModelFeature::setFieldType(const std::string& meshname)
{
	VirtualMine::Core::CVariant var(meshname);
	CField field;
	field.setName("Type");
	field.setVarient(var);
	//this->mpPropetetSet->setField(field,0);
	this->mpPropertySet->setValue(field,2);
}

/*void setFieldBlob(Ogre::uchar* blob,int length);

void setFieldBlob( VirtualMine::Core::CVRDataStream& datastream);

void setFieldTexture(Ogre::uchar* blob,int length);

void setFieldTexture( VirtualMine::Core::CVRDataStream& datastream);*/

void CModelFeature::setFieldPosX(const double& posX)
{
	VirtualMine::Core::CVariant var(posX);
	CField field;
	field.setName("PosX");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,3);
}

void CModelFeature::setFieldPosY(const double& posY)
{
	VirtualMine::Core::CVariant var(posY);
	CField field;
	field.setName("PosY");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,4);
}

void CModelFeature::setFieldPosZ(const double& posZ)
{
	VirtualMine::Core::CVariant var(posZ);
	CField field;
	field.setName("PosZ");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,5);
}


void CModelFeature::setFieldScaleX(const double& scaleX)
{
	VirtualMine::Core::CVariant var(scaleX);
	CField field;
	field.setName("ScaleX");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,6);
}

void CModelFeature::setFieldScaleY(const double& scaleY)
{
	VirtualMine::Core::CVariant var(scaleY);
	CField field;
	field.setName("ScaleY");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,7);
}

void CModelFeature::setFieldScaleZ(const double& scaleZ)
{
	VirtualMine::Core::CVariant var(scaleZ);
	CField field;
	field.setName("scaleZ");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,8);
}


void CModelFeature::setFieldTransX(const double& transX)
{
	VirtualMine::Core::CVariant var(transX);
	CField field;
	field.setName("TransX");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,9);
}

void CModelFeature::setFieldTransY(const double& transY)
{
	VirtualMine::Core::CVariant var(transY);
	CField field;
	field.setName("TransY");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,10);
}

void CModelFeature::setFieldTransZ(const double& transZ)
{
	VirtualMine::Core::CVariant var(transZ);
	CField field;
	field.setName("TransZ");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,11);
}
 


void CModelFeature::setFieldRotateX(const double& rotateX)
{
	VirtualMine::Core::CVariant var(rotateX);
	CField field;
	field.setName("rotateX");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,12);
}

void CModelFeature::setFieldRotateY(const double& rotateY)
{
	VirtualMine::Core::CVariant var(rotateY);
	CField field;
	field.setName("RotateY");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,13);
}

void CModelFeature::setFieldRotateZ(const double& rotateZ)
{
	VirtualMine::Core::CVariant var(rotateZ);
	CField field;
	field.setName("RotateZ");
	field.setVarient(var);

	this->mpPropertySet->setValue(field,14);
}

void CModelFeature::setFieldBlob(Ogre::uchar* blob,int length)
{
	VirtualMine::Core::CVariant var(blob,length);
	CField field;
	field.setName("Tag");
	field.setVarient(var);
	this->mpPropertySet->setValue(field,15);
}

void VirtualMine::Database::CModelFeature::setFieldDeviceType( const int& deviceType )
{
	VirtualMine::Core::CVariant var(deviceType);
	CField field;
	field.setName("DeviceType");
	field.setVarient(var);
	this->mpPropertySet->setValue(field,16);
}

int VirtualMine::Database::CModelFeature::getFieldDeviceType()
{
	if ( this->mpPropertySet)
	{
		void* pname =  this->mpPropertySet->getFields().at(16).getVarient().data();
		int* pna = (int*)pname;
		return  *pna;
	}
	return 0;
}



double VirtualMine::Database::CModelFeature::getFieldPosX()
{
	if ( this->mpPropertySet)
	{
		void* pname =  this->mpPropertySet->getFields().at(3).getVarient().data();
		double* pna = (double*)pname;
		return  *pna;
	}
	return 0;
}

double VirtualMine::Database::CModelFeature::getFieldPosY()
{
	if ( this->mpPropertySet)
	{
		void* pname =  this->mpPropertySet->getFields().at(4).getVarient().data();
		double* pna = (double*)pname;
		return  *pna;
	}
	return 0;
}

double VirtualMine::Database::CModelFeature::getFieldPosZ()
{
	if ( this->mpPropertySet)
	{
		void* pname =  this->mpPropertySet->getFields().at(5).getVarient().data();
		double* pna = (double*)pname;
		return  *pna;
	}
	return 0;
}

double VirtualMine::Database::CModelFeature::getFieldScaleX()
{
	if ( this->mpPropertySet)
	{
		void* pname =  this->mpPropertySet->getFields().at(6).getVarient().data();
		double* pna = (double*)pname;
		return  *pna;
	}
	return 0;
}

double VirtualMine::Database::CModelFeature::getFieldScaleY()
{
	if ( this->mpPropertySet)
	{
		void* pname =  this->mpPropertySet->getFields().at(7).getVarient().data();
		double* pna = (double*)pname;
		return  *pna;
	}
	return 0;
}

double VirtualMine::Database::CModelFeature::getFieldScaleZ()
{
	if ( this->mpPropertySet)
	{
		void* pname =  this->mpPropertySet->getFields().at(8).getVarient().data();
		double* pna = (double*)pname;
		return  *pna;
	}
	return 0;
}

double VirtualMine::Database::CModelFeature::getFieldTransX()
{
	if ( this->mpPropertySet)
	{
		void* pname =  this->mpPropertySet->getFields().at(9).getVarient().data();
		double* pna = (double*)pname;
		return  *pna;
	}
	return 0;
}

double VirtualMine::Database::CModelFeature::getFieldTransY()
{
	if ( this->mpPropertySet)
	{
		void* pname =  this->mpPropertySet->getFields().at(10).getVarient().data();
		double* pna = (double*)pname;
		return  *pna;
	}
	return 0;
}

double VirtualMine::Database::CModelFeature::getFieldTransZ()
{
	if ( this->mpPropertySet)
	{
		void* pname =  this->mpPropertySet->getFields().at(11).getVarient().data();
		double* pna = (double*)pname;
		return  *pna;
	}
	return 0;
}

double VirtualMine::Database::CModelFeature::getFieldRotateX()
{
	if ( this->mpPropertySet)
	{
		void* pname =  this->mpPropertySet->getFields().at(12).getVarient().data();
		double* pna = (double*)pname;
		return  *pna;
	}
	return 0;
}

double VirtualMine::Database::CModelFeature::getFieldRotateY()
{
	if ( this->mpPropertySet)
	{
		void* pname =  this->mpPropertySet->getFields().at(13).getVarient().data();
		double* pna = (double*)pname;
		return  *pna;
	}
	return 0;
}

double VirtualMine::Database::CModelFeature::getFieldRotateZ()
{
	if ( this->mpPropertySet)
	{
		void* pname =  this->mpPropertySet->getFields().at(14).getVarient().data();
		double* pna = (double*)pname;
		return  *pna;
	}
	return 0;
}



void VirtualMine::Database::CModelFeature::setDeviceType( const VirtualMine::Core::DeviceType& deviceType )
{
	this->mDeviceType = deviceType;
}

VirtualMine::Core::DeviceType VirtualMine::Database::CModelFeature::getDeviceType()
{
	return this->mDeviceType;
}
