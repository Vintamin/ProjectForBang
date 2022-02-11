//# ifndef _COREDEFINE_H
//#define _COREDEFINE_H
//
//
//#include "OGRE\OgrePrerequisites.h"
//#include <vector>
//#include <list>
//#include <string>
//
//typedef std::vector<Ogre::Real> RealVector;
//typedef std::vector<Ogre::uint> UIntVector;
//typedef std::vector<Ogre::int32> IntVector;
//typedef std::vector<Ogre::Vector3> CoorVector;
//typedef std::vector<double> DoubleVector;
//typedef std::vector<Ogre::String> StringVector;
//
//#define VR_TEMPLATE_CLASS template<class T> 
//#define  SAFE_DELETE(p) if (NULL != p)\
//{\
//	delete p;\
//}
//
//
//#endif


# ifndef _COREDEFINE_H
#define _COREDEFINE_H


#include "OGRE\OgrePrerequisites.h"
#include <vector>
#include <list>
#include <string>

typedef std::vector<Ogre::Real> RealVector;
typedef std::vector<Ogre::uint> UIntVector;
typedef std::vector<Ogre::int32> IntVector;
typedef std::vector<Ogre::Vector3> CoorVector;
typedef std::vector<double> DoubleVector;
typedef std::vector<Ogre::String> StringVector;

typedef struct{

	double X;
	double Y;
	double Z;
}De_point;

///投影七个参数

typedef struct{
	double dx;
	double dy;
	double dz;
	double wx;
	double wy;
	double wz;
	double m;
}sevenPara;

typedef struct point_2D 
{
	int X;
	int Y;

	bool operator <(const point_2D& other) const
	{
		if (X < other.X)        
		{
			return true;
		}
		else if (X == other.X)  
		{
			return Y < other.Y;
		}

		return false;
	}
};

#define VR_TEMPLATE_CLASS template<class T> 
#define  SAFE_DELETE(p) if (NULL != p)\
{\
	delete p;\
}


#endif