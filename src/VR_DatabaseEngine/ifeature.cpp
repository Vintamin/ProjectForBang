//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : ifeature.cpp
//  @ Date : 2014/7/6
//  @ Author : ʢ����
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
//  @ Copyright:  2014-2020
//  @ Description : 

#include "vrmine\vr_databaseengine\database\ifeature.h"
#include "vrmine\vr_databaseengine\database\propertyset.h"

using namespace std;
using namespace VirtualMine::Database;

IFeature::IFeature()
{

}

//void IFeature::createFields()
//{
//
//}
//
//VirtualMine::Database::IFields IFeature::getFields()
//{
//	IFields fields;
//	return fields;
//}

void IFeature::setName(const string& name)
{

}

string IFeature::getName()
{
	return "";
}

std::string IFeature::getType()
{
	return "";
}

void IFeature::setType(const std::string& type)
{

}

void IFeature::setID(const int& id)
{

}
int IFeature::getID()
{
	return -1;
}
// void IFeature::setFieldID(const int& id,const int& index)
// {
//
// }
// void IFeature::setFieldName(const std::string& name,const int& index)
// {
//
// }
//void IFeature::setFieldWidth(const float& width,const int& index)
//{
//
//}
// void IFeature::setFieldBlob(Ogre::uchar* blob,const int& index)
// {
//
// }


void IFeature::addField(CField* field)
{

}

void IFeature::deleteField(CField* field)
{

}

 void IFeature::setFieldID(const int& id)
 {

 }

 void IFeature::setFieldName(const std::string& name)
 {

 }

 void IFeature::setFieldWidth(const float& width)
 {

 }

 void IFeature::setFieldBlob(Ogre::uchar* blob,int length)
 {

 }

 int IFeature::getFieldBlobLength()
 {
	 return -1;
 }

 void IFeature::setFieldTexture(Ogre::uchar* blob,int length)
 {

 }

 void IFeature::setFieldHeight(const float& height)
 {

 }

 void IFeature::setFieldType(const std::string& type)
 {

 }

 CPropertySet* IFeature::getPropertySet()
 {
	 return NULL;
 }

 void  IFeature::setFieldSectionType(const int& sectionType)
 {

 }

 void  IFeature::setFieldHeightSupportType(const int& supportType)
 {

 }

 void IFeature::setFieldLanewayWindType(const int& lanewayWindType)
 {

 }



 int IFeature::getFieldID()
 {
	 return 0;
 }

 std::string IFeature::getFieldName()
 {
	 return "";
 }

 float IFeature::getFieldWidth()
 {
	 return 0;
 }

 float IFeature::getFieldHeight()
 {
	 return 0;
 }

 Ogre::uchar* IFeature::getFieldBlob()
 {
	 return NULL;
 }

 Ogre::uchar* IFeature::getFieldTexture()
 {
	 return NULL;
 }

 std::string IFeature::getFieldType()
 {
	 return "";
 }

int IFeature::getFieldSectionType()
 {
	 return -1;
 }

 int IFeature::getFieldHeightSupportType()
 {
	 return -1;
 }

 int IFeature::getFieldLanewayWindType()
 {
     return -1;
 }