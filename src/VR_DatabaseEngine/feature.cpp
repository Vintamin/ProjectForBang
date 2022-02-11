#include "vrmine/vr_databaseengine/database/feature.h"
#include <utility>// pair

using namespace std;
using namespace VirtualMine::Database;

CFeature::CFeature()
{
	this->mpPropertySet = NULL;
}

CFeature::~CFeature()
{
	if(this->mpPropertySet)
	{
		delete this->mpPropertySet;
		mpPropertySet = NULL;
	}
}

string CFeature::getName()
{
	return this->mName;
}

void CFeature::setName(const string& name)
{
	this->mName = name;
}

void CFeature::addField(CField* field)
{
	this->mpPropertySet->insertFields(*field);
}

void CFeature::deleteField(CField* field)
{
	///判读fiel的类型，进行删除
	//this->mpPropertySet->getFields().pop_back()
}

std::string CFeature::getType()
{
	return this->mType;
}

void CFeature::setType(const std::string& type)
{
	this->mType = type;
}

//void CFeature::addField(string name,VirtualMine::Core::ValueType type)
//{
//	CField* field = new CField(name,type);
//	field->setName(name);
//	field->setType(type);
//	//this->mFields.addField(field);
//}

//void CFeature::addField(CField& field)
//{
//	//this->mFields.addField(field);
//	/*string fieldname = field.getName();
//	this->mPropertySet.getFields().insert(pair<string,CField>(fieldname,field));*/
//
//     //this->mPropertySet.getFields().push_back(field);
//}

//CField CFeature::getValue(const int& index)
//{
//	this->mPropertySet.getPropertySet().at(index)
//}

CField CFeature::getValue(const int& index)
{
	/*map<string,CField>::iterator itr = this->mPropertySet.getFields().find(fieldName);
	CField field = itr->second;
	return field;*/

	// return this->mPropertySet.getFields().at(index);

   return this->getPropertySet()->getFields().at(index);
}

CPropertySet* CFeature::getPropertySet()
{
	return this->mpPropertySet;
}

 /*void CFeature::setFieldID(const int& id,const int& index)
 {

 }
 void CFeature::setFieldName(const std::string& name,const int& index)
 {

 }
 void CFeature::setFieldWidth(const float& width,const int& index)
 {

 }
void CFeature::setFieldBlob(Ogre::uchar* blob,const int& index)
{

}*/

void CFeature::setFieldID(const int& id)
{

}

void CFeature::setFieldName(const std::string& name)
{

}

void CFeature::setFieldWidth(const float& width)
{

}

void CFeature::setFieldBlob(Ogre::uchar* blob,int length)
{

}

void CFeature::setFieldTexture(Ogre::uchar* blob,int length)
{

}

void CFeature::setFieldHeight(const float& height)
{

}

void CFeature::setFieldType(const std::string& type)
{

}
void  CFeature::setFieldSectionType(const int& sectionType)
 {

 }

void  CFeature::setFieldHeightSupportType(const int& supportType)
{

}

void CFeature::setFieldLanewayWindType(const int& lanewayWindType)
{

}

int CFeature::getFieldID()
{
	return 0;
}

std::string CFeature::getFieldName()
{
	return "";
}

float CFeature::getFieldWidth()
{
	return 0;
}

float CFeature::getFieldHeight()
{
	return 0;
}

Ogre::uchar* CFeature::getFieldBlob()
{
	return NULL;
}

int CFeature::getFieldBlobLength()
{
	return -1;
}
Ogre::uchar* CFeature::getFieldTexture()
{
	return NULL;
}

std::string CFeature::getFieldType()
{
	return "";
}

int CFeature::getFieldSectionType()
{
	return -1;
}

int CFeature::getFieldHeightSupportType()
{
	return -1;
}

int CFeature::getFieldLanewayWindType()
{
	return -1;
}