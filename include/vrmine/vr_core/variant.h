#if !defined(_VARIANT_H)
#define _VARIANT_H

#include <string>
#include "vrmine/vr_core/common_config.h"
#include "vrmine/vr_core/valuetype.h"
#include "OGRE/OgreDataStream.h"


namespace VirtualMine
{
	namespace Core
	{
		class VR_CORE_DLL CVRDataStream : Ogre::MemoryDataStream
		{
		public:
			CVRDataStream();

			~CVRDataStream();

			virtual void wirteInt16(const short& value);

			virtual void wirteInt32(const int& value);

			virtual void wirteReal(const float& value);

			virtual void wirteReal(const double& value);

			virtual void wirteBool(const bool& value);

			virtual void wirteChar(const char& value);

			virtual void wirteString(const std::string& value);

			virtual void wirteBlob(const void* value,const int& length); 

			virtual void readInt16( short& value);

			virtual void readInt32( int& value);

			virtual void readReal( float& value);

			virtual void readReal( double& value);

			virtual void readBool( bool& value);

			virtual void readChar( char& value);

			virtual void readString( std::string& value);

			virtual void readBlob( void* value,const int& length); 

			virtual void reseek(size_t pos);

			virtual Ogre::uchar* getData();

			virtual int getLength();

		private:
			int mVarSizeStep;
		};

		class VR_CORE_DLL CVariant 
		{

		public:
			CVariant();

			CVariant(const int& value);

			CVariant(const float& value);

			CVariant(const double& value);

			CVariant(const char& value);

			CVariant(const std::string& value);

			CVariant(const bool& value);

			CVariant(void* value,const int& length);

			CVariant(CVRDataStream& datastream);

			~CVariant();

			VirtualMine::Core::ValueType getType();

			void setType(const VirtualMine::Core::ValueType& type);

			int getLength();

			void*& data();

			void getValue(std::string& value);

			void getValue(double& value);

			void getValue(float& value);

			void getValue(int& value);
			 
			int toInt32();

			float toFloat();

			std::string toString();

			double toDouble();


		private:

			VirtualMine::Core::ValueType mType;

			int mLength;

			void* mpData;
		};
	}
}

#endif //