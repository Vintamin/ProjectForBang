#include "vrmine/vr_sqlitedatabase/sqlitedatabase/dataset.h"

CDataset::CDataset()
{

}

CDataset::~CDataset()
{

}

void CDataset::createFeature()
{

}

void CDataset::destroyFeature()
{

}

VirtualMine::SQLiteDatabase::CFeature CDataset::getFeature()
{
	return this->mFeature;
	
}

void CDataset::setName(const string& name)
{
	this->mName = name;
}

string CDataset::getName()
{
	return this->mName;
} 