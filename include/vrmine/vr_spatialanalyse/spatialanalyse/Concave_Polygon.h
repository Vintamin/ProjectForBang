
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : Concave_Polygon.h
//  @ Date : 2015/6/21
//  @ Author : 王向上
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 



#if !defined(_CONCAVE_POLYGON_H)
#define _CONCAVE_POLYGON_H


#include <GL/glut.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <iterator>

#include "vrmine/vr_spatialanalyse/spatialanalyse_config.h"
#include "ogre/OgreRenderOperation.h"
using std::stringstream;
//using std::cout;
//using std::cerr;
//using std::endl;
//using std::ends;




namespace VirtualMine
{
	namespace SpatialAnalyse
	{
		#ifndef CALLBACK
		#define CALLBACK
		#endif

		typedef struct{

			GLdouble X;
			GLdouble Y;
			GLdouble Z;
		}GLPoint;

		class VR_SPATIALANALYSE_DLL Concave_Polygon
		{
		public:
			Concave_Polygon();
			~Concave_Polygon();

		private:
			GLenum mEnum;
			// global variables ///////////////////////////////////////////////////////////
			//void *font = GLUT_BITMAP_8_BY_13;
			void *font;
			//int drawMode = 0;
			int drawMode;
			GLuint listId1;       // IDs of display lists
			GLdouble vertices[64][6];               // arrary to store newly created vertices (x,y,z,r,g,b) by combine callback
			//int vertexIndex = 0;                    // array index for above array incremented inside combine callback
			int vertexIndex;
			// DEBUG //
//			stringstream ss;
		public:
			std::vector<GLPoint> GLPoints;
			std::vector<std::vector<GLPoint>> GLPointsset;
			std::vector<GLPoint> GLPoints2;
			std::vector<std::vector<GLPoint>> GLPointsset2;
			std::vector<int> count;
			std::vector<GLPoint> PointSet;

			// CALLBACK functions for GLU_TESS ////////////////////////////////////////////
			// NOTE: must be declared with CALLBACK directive
			static	 void CALLBACK tessBeginCB(GLenum which);
			static	 void CALLBACK tessEndCB();
			static void CALLBACK tessErrorCB(GLenum errorCode);
			static void CALLBACK tessVertexCB(const GLvoid *data);
			void CALLBACK tessVertexCB2(const GLvoid *data);
			void CALLBACK tessCombineCB(const GLdouble newVertex[3], const GLdouble *neighborVertex[4],
				const GLfloat neighborWeight[4], GLdouble **outData);


			void idleCB();
			Ogre::RenderOperation::OperationType getPrimitiveType(int j);
			GLuint tessellate1();
		public:
			int creatTri(std::vector<GLPoint>& a,std::vector<int>& b,std::vector<std::vector<GLPoint>>& c);

		};
}
}
#endif