#include "vrmine/vr_sqlitedatabase/sqlitedatabase/field.h"

CField::CField()
{

}
~CField()
{

}
CField::string getName()
{
	return this->mName;
}
void CField::setName(string name)
{
	this->mName = name;
}
CField::string getType()
{
  return this->mType;
}
void setType(string type)
{
	this->mType = type;
}
int CField::getSize()
{
	return this->mSize;
}
void setSize(const int& fieldSize)
{ 
	this->mSize = fieldSize;
}