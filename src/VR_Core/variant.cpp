#include "vrmine/vr_core/variant.h"
#include "OGRE/OgreMemoryAllocatorConfig.h"

using namespace std;
using namespace VirtualMine::Core;



CVRDataStream::CVRDataStream()
	:MemoryDataStream(2000,true,false),//mSize不固定
	mVarSizeStep(2000)
{

}



CVRDataStream::~CVRDataStream()
{
	
}

CVariant::CVariant()
{
	this->mType = VirtualMine::Core::ValueType::VT_Int32;
	this->mLength = sizeof(int);
	this->mpData = NULL;
}

CVariant::CVariant(const int& value)
{
	this->mType = VT_Int32;
	this->mLength = sizeof(int);
	int* pData = new int;
	*pData = value;
	this->mpData = (void*)(pData);
}

CVariant::CVariant(const float& value)
{
	this->mType = VT_Float;
	this->mLength = sizeof(float);
	float* pData = new float;
	*pData = value;
	this->mpData = (void*)(pData);
}

CVariant::CVariant(const double& value)
{
	this->mType = VT_Double;
	this->mLength = sizeof(double);
	double* pData = new double;
	*pData = value;
	this->mpData = (void*)(pData);
}

CVariant::CVariant(const char& value)
{
	this->mType = VT_Char;
	this->mLength = sizeof(char);
	char* pData = new char;
	*pData = value;
	this->mpData = (void*)(pData);
}

CVariant::CVariant(const std::string& value)
{
	this->mType = VT_String;
	this->mLength = value.length() + 1;
	const char* pData = value.c_str();

	this->mpData = new char[this->mLength];
	memcpy(this->mpData,pData,this->mLength);
}

CVariant::CVariant(const bool& value)
{
	this->mType = VT_Bool;
	this->mLength = sizeof(bool);
	bool* pData = new bool;
	*pData = value;
	this->mpData = (void*)(pData);
}

CVariant::CVariant(void* value,const int& length)
{
	this->mType = VT_Blob;
	//this->mpData = value;
	this->mpData = new Ogre::uchar[length];
	memcpy(this->mpData,value,length);
	this->mLength = length;
}
 
CVariant::CVariant( CVRDataStream& datastream)
{
	this->mType = VT_Blob;
	//this->mpData = static_cast<void*>(datastream.getData());
	this->mpData = new Ogre::uchar[datastream.getLength()];
	memcpy(mpData,datastream.getData(),datastream.getLength());
	this->mLength = datastream.getLength();
}

int CVariant::toInt32()
{
	void* pData  = this->data();
	int* pInt = (int*)pData;
	int var = *pInt;
	return var;

}

float CVariant::toFloat()
{
	void* pData  = this->data();
	float* pInt = (float*)pData;
	float var = *pInt;
	return var;
}

std::string CVariant::toString()
{
	void* pData  = this->data();
	char* pInt = (char*)pData;
	std::string var(pInt);
	return var;
}

double CVariant::toDouble()
{
	void* pData  = this->data();
	double* pInt = (double*)pData;
	double var = *pInt;
	return var;
}


CVariant::~CVariant()
{

}


ValueType CVariant::getType()
{
  return this->mType;
}

void CVariant::setType(const ValueType& type)
{
	this->mType = type; 
}

void*& CVariant::data()
{
	return this->mpData;
}

void CVariant::getValue(std::string& value)
{
	char* data  = static_cast<char*>(this->mpData);
	value = std::string(data);   
}

void CVariant::getValue(double& value)
{
	double* data  = static_cast<double*>(this->mpData);
	value = *data; 
}

void CVariant::getValue(float& value)
{
	float* data  = static_cast<float*>(this->mpData);
	value = *data; 
}

void CVariant::getValue(int& value)
{
	int* data  = static_cast<int*>(this->mpData);
	value = *data; 
}


int CVariant::getLength()
{
	return this->mLength; 
}

void CVRDataStream::wirteInt16( const short& value )
{
	int length = sizeof(short);
	//byte* b = new byte[length];
	//char* b
	Ogre::uchar* b = new Ogre::uchar[length];
	//char* b = new char[length];
	memcpy(b,&value,length);

	wirteBlob(b,sizeof(short));


}

void CVRDataStream::wirteInt32( const int& value )
{
	//int 转为 二进制流 
	
	int length = sizeof(int);
 //   //byte* b = new byte[length];	
	Ogre::uchar* b = new Ogre::uchar[length];
	memcpy(b,&value,length);
	
	wirteBlob(b,sizeof(int));

	//write(&value,sizeof(int));

}

void CVRDataStream::wirteReal( const float& value )
{
	int length = sizeof(float);
	//byte* b = new byte[length];
	//Ogre::uchar* b = new Ogre::uchar[length];
    //char* b = new char[length];
	Ogre::uchar* b = new Ogre::uchar[length];
	memcpy(b,&value,length);

	wirteBlob(b,sizeof(float));
}

void CVRDataStream::wirteReal( const double& value )
{
	int length = sizeof(double);
	//byte* b = new byte[length];
	Ogre::uchar* b = new Ogre::uchar[length];
	//char* b = new char[length];
	memcpy(b,&value,length);

	wirteBlob(b,sizeof(double));
}

void CVRDataStream::wirteBool( const bool& value )
{
	int length = sizeof(bool);
	//byte* b = new byte[length];
	Ogre::uchar* b = new Ogre::uchar[length];
	//char* b = new char[length];
	memcpy(b,&value,length);

	wirteBlob(b,sizeof(bool));
}

void CVRDataStream::wirteChar(const char& value )
{
	int length = sizeof(char);
	//byte* b = new byte[length];
	Ogre::uchar* b = new Ogre::uchar[length];
	//char* b = new char[length];
	memcpy(b,&value,length);

	wirteBlob(b,sizeof(char));
}

void CVRDataStream::wirteString( const std::string& value )
{
#if 0
	int length = value.length();
	//byte* b = new byte[length];
	Ogre::uchar* b = new Ogre::uchar[length];
	Ogre::uchar* startPos = b;
	for (size_t i = 0 ; i < length; ++i)
	{
		*b++ = value[i];
	}
	b -= length;
	b = startPos;
	//memcpy(b,&value,length);

	wirteInt32(length);
	wirteBlob(b,length);

#else
	int length0 = value.length();
	int length = strlen(value.c_str());

	Ogre::uchar* b = new Ogre::uchar[length + 1];
	b[length] = '\0';
	memcpy(b,value.c_str(),length);
	//memcpy(b,&value,length);

	wirteInt32(length);
	wirteBlob(b,value.length());
	//wirteChar('\0');



	/*int length = value.length();
	write((const void*)&length,sizeof(int));
	write((const void*)&value,value.length());
*/
	//char c(0);
	//write((const void*)&c, 1);


#endif
}

void CVRDataStream::wirteBlob( const void* value ,const int& length)
{
	//write(value,length); 
	size_t written = 0;
	if (isWriteable())
	{
		written = length;	

		if (mPos + written > mEnd)
		{
			int deltaSize = mEnd - mPos;
			int curDataSize = this->mSize - deltaSize;
			int newSize = this->mSize + this->mVarSizeStep;			
			if (newSize < written)
			{
				newSize = written + this->mSize;
				//newSize = written;
			}
			Ogre::uchar* pTempData = OGRE_ALLOC_T(Ogre::uchar, newSize, Ogre::MemoryCategory::MEMCATEGORY_GENERAL);			
			memcpy(pTempData,this->mData,curDataSize);
			this->close();
			Ogre::uchar* pOriginData = pTempData;
			pTempData = pTempData + curDataSize;
			memcpy(pTempData, value, written);
			this->mData = pOriginData;
			this->mSize = newSize;
			this->mPos = this->mData + curDataSize + written;
			mEnd = mData + mSize;

		}
		else
		{
				
			memcpy(mPos, value, written);
			mPos += written;
			
		}

	/*	written = mEnd - mPos;
		if (written == 0)
			return ;*/

	/*	memcpy(mPos, value, written);
		mPos += written;*/
	}
}

//
void CVRDataStream::readInt16( short& value)
 {
	 int length = sizeof(short);
	 //byte* b = new byte[length];
	 Ogre::uchar* b = new Ogre::uchar[length];
	 //char* b = new char[length];
	// memcpy(b,&value,length);
	 read(b,length);
	 const char* tmp = (char*)b; 
	 value = atoi(tmp);

 }

void CVRDataStream::readInt32(int& value)
{
	int length = sizeof(int);
	////byte* b = new byte[length];	
	//Ogre::uchar* b = new Ogre::uchar[length];
	////char* b = new char[length];
	//read(b,sizeof(int));
	//const char* tmp = (char*)b; 
	//value = atoi(tmp);
	read(&value,length);
	/*void* data = new Ogre::uchar[length];
	read(data,length);
	value = *static_cast<int*>(data);*/

}
void CVRDataStream::readReal( float& value)
{
	int length = sizeof(float);
	//char* b = new char[length];
	/*Ogre::uchar* b = new Ogre::uchar[length];
	read(b,length);
	const char* tmp = (char*)b; 
	value = atof(tmp);*/
	read(&value,length);
}
void CVRDataStream::readReal(double& value)
{
	int length = sizeof(double);
	////char* b = new char[length];
	//Ogre::uchar* b = new Ogre::uchar[length];
	//read(b,length);
	//const char* tmp = (char*)b; 
	//value = atof(tmp);
	read(&value,length);
}
void CVRDataStream::readBool(bool& value)
{
	int length = sizeof(bool);
	//Ogre::uchar* b = new Ogre::uchar[length];
	//char* b = new char[length];
	read(&value,length);
	
	//const char* tmp = (char*)b;
	//value = bool(tmp);
}
void CVRDataStream::readChar(char& value)
{
	int length = sizeof(char);
	//char* b = new char[length];
	Ogre::uchar* b = new Ogre::uchar[length];
	read(b,length);

	value = *b;
}
void CVRDataStream::readString(std::string& value)
{
	int length = 0;
	readInt32(length);

	Ogre::uchar* b = new Ogre::uchar[length + 1];
	b[length] = '\0';
	read(b,length);

	
	char* tmp = (char*)b;
	value = tmp;
	//value[length] = '\0';
	//value.append('\0');



	/*while(!this->eof())
	{
	char c;
	read(&c, 1);
	if(c == 0)
	{
	break;
	}
	value.append(1,c);*/
	//}



}
void CVRDataStream::readBlob( void* value,const int& length)
{
    read(value,length);
}

void CVRDataStream::reseek(size_t pos)
{
	Ogre::MemoryDataStream::seek(pos);
}

Ogre::uchar* CVRDataStream::getData()
{
	return mData;

}

int CVRDataStream::getLength()
{
   return mSize;
}