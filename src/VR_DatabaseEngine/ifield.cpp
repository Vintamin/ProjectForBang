//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : ifield.cpp
//  @ Date : 2014/7/6
//  @ Author : 盛佳良
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine\vr_databaseengine\database\ifield.h"
#include "vrmine\vr_core\valuetype.h"

using namespace std;
using namespace VirtualMine::Database;
using namespace VirtualMine::Core;


void IField::setType(const VirtualMine::Core::ValueType& type)
{

}

ValueType IField::getType()
{
   return VT_Unkown;
}


//void IField::setValue()
//{
//
//}
//
//void IField::getValue()
//{
//
//}

void IField::setLength(const int& length)
{

}

int IField::getLength()
{
	return -1;
}

void IField::setName(const string& name)
{

}

string IField::getName()
{
	return "";
}

