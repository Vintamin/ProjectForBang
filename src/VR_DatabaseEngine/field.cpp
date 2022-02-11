#include "vrmine/vr_databaseengine/database/field.h"

using namespace std;
using namespace VirtualMine::Database;
using namespace VirtualMine::Core;

CField::CField()
	:IField()
{
	this->mName = "Name";
	this->mSize = VT_Int32;
}

CField::CField(string name,VirtualMine::Core::ValueType type)
{
	this->mName = name;
	this->mType = type;
}

CField::~CField()
{

}

string CField::getName()
{
	return this->mName;
}

void CField::setName(const string& name)
{
	this->mName = name;
}

VirtualMine::Core::ValueType CField::getType()
{
  return this->mType;
}

void CField::setType(const VirtualMine::Core::ValueType& type)
{
	this->mType = type;
}

int CField::getSize()
{
	return this->mSize;
}

void CField::setSize(const int& size)
{ 
	this->mSize = size;
}

VirtualMine::Core::CVariant CField::getVarient()
{
	return this->mVarient;
}

void CField::setVarient(const VirtualMine::Core::CVariant& vareint)
{
	this->mVarient = vareint;
}
