////
////
////  Generated by StarUML(tm) C++ Add-In
////
////  @ Project : 三维数字矿山平台
////  @ File Name : coordinatecalculator.cpp
////  @ Date : 2014/7/6
////  @ Author : 盛佳良
////  @ Implement : 
////  @ Company : 中国矿业大学(北京)
////  @ Copyright:  2014-2020
////  @ Description : 
//
//
//#include "vrmine\vr_coordinatesystem\coordinatesystem\coordinatecalculator.h"
//
//namespace VirtualMine
//{
//	namespace CoordinateSystem
//	{
//		void CoordinateCalculator::transformCoordinate()
//		{
//
//		}
//
//	}
//}





//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : 三维数字矿山平台
//  @ File Name : coordinatecalculator.cpp
//  @ Date : 2015/7/6
//  @ Author : 王向上
//  @ Implement : 
//  @ Company : 中国矿业大学(北京)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine\vr_coordinatesystem\coordinatesystem\coordinatecalculator.h"

#include "iomanip"
//#include "ogr_spatialref.h"

#define PI 3.1415926535
const double krass_a=6378245;
const double krass_b=6356863.0188;
const double krass_f=298.2997381;
const double IAG75_a=6378140;
const double IAG75_b=6356755.2882;
const double IAG75_f =298.257;
const double WGS84_a = 6378137;
const double WGS84_b =6356752.3142;
const double WGS84_f =298.257;


namespace VirtualMine
{
	namespace CoordinateSystem
	{
		void CoordinateCalculator::transformCoordinate()
		{
		
		}

		Ogre::Vector3 CoordinateCalculator::Xian80toWGS84(Ogre::Vector3& in_point,sevenPara& inPara)
		{
			double e2 = (IAG75_a*IAG75_a-IAG75_b*IAG75_b)/(IAG75_a*IAG75_a);
			double B2,L2,H2;
			double X,Y,Z;
			double X2,Y2,Z2;

			double B=in_point.x/180*PI;
			double L=in_point.y/180*PI;
			double H=in_point.z/180*PI;

			double N=IAG75_a/sqrt(1-e2*sin(B)*sin(B));
			X=(N+H)*cos(B)*cos(L);
			Y=(N+H)*cos(B)*sin(L);
			Z=(N*(1-e2)+H)*sin(B);
			//cout<<X<<"   "<<Y<<endl;
			X2=inPara.dx+(1+inPara.m)*X-Z*inPara.wy+Y*inPara.wz;
			Y2=inPara.dy+(1+inPara.m)*Y+Z*inPara.wx-X*inPara.wz;
			Z2=inPara.dz+(1+inPara.m)*Z-Y*inPara.wx+X*inPara.wz;

			B2=atan(Z2*(N+H)/(sqrt(X2*X2+Y2*Y2)*(N*(1-e2)+H)));

			L2=atan(Y2/X2);

			double d1,d2;
			d1=B2/PI*180;
			d2=L2/PI*180+180;
			Ogre::Vector3 latlon;
			latlon.x=d2;
			latlon.y=d1;

			return latlon;

		}
		Ogre::Vector3 CoordinateCalculator::WGS84toXian80(Ogre::Vector3& in_point,sevenPara& inPara)
		{
			double e2 = (WGS84_a*WGS84_a-WGS84_b*WGS84_b)/(WGS84_a*WGS84_a);
			double B2,L2,H2;
			double X,Y,Z;
			double X2,Y2,Z2;

			double B=in_point.x/180*PI;
			double L=in_point.y/180*PI;
			double H=in_point.z/180*PI;

			double N=WGS84_a/sqrt(1-e2*sin(B)*sin(B));
			X=(N+H)*cos(B)*cos(L);
			Y=(N+H)*cos(B)*sin(L);
			Z=(N*(1-e2)+H)*sin(B);
			//cout<<X<<"   "<<Y<<endl;
			X2=inPara.dx+(1+inPara.m)*X-Z*inPara.wy+Y*inPara.wz;
			Y2=inPara.dy+(1+inPara.m)*Y+Z*inPara.wx-X*inPara.wz;
			Z2=inPara.dz+(1+inPara.m)*Z-Y*inPara.wx+X*inPara.wz;

			B2=atan(Z2*(N+H)/(sqrt(X2*X2+Y2*Y2)*(N*(1-e2)+H)));

			L2=atan(Y2/X2);

			double d1,d2;
			d1=B2/PI*180;
			d2=L2/PI*180+180;
			Ogre::Vector3 latlon;
			latlon.x=d2;
			latlon.y=d1;
			return latlon;
		}

		Ogre::Vector3 CoordinateCalculator::BJ54toWGS84(Ogre::Vector3& in_point,sevenPara& inPara)
		{
			double e2 = (krass_a*krass_a-krass_b*krass_b)/(krass_a*krass_a);
			double B2,L2,H2;
			double X,Y,Z;
			double X2,Y2,Z2;

			double B=in_point.x/180*PI;
			double L=in_point.y/180*PI;
			double H=in_point.z/180*PI;

			double N=krass_a/sqrt(1-e2*sin(B)*sin(B));
			X=(N+H)*cos(B)*cos(L);
			Y=(N+H)*cos(B)*sin(L);
			Z=(N*(1-e2)+H)*sin(B);
			//cout<<X<<"   "<<Y<<endl;
			X2=inPara.dx+(1+inPara.m)*X-Z*inPara.wy+Y*inPara.wz;
			Y2=inPara.dy+(1+inPara.m)*Y+Z*inPara.wx-X*inPara.wz;
			Z2=inPara.dz+(1+inPara.m)*Z-Y*inPara.wx+X*inPara.wz;

			B2=atan(Z2*(N+H)/(sqrt(X2*X2+Y2*Y2)*(N*(1-e2)+H)));

			L2=atan(Y2/X2);

			double d1,d2;
			d1=B2/PI*180;
			d2=L2/PI*180+180;
			Ogre::Vector3 latlon;
			latlon.x=d2;
			latlon.y=d1;

			return latlon;
		}

		Ogre::Vector3 CoordinateCalculator::WGS84toBJ54(Ogre::Vector3& in_point,sevenPara& inPara)
		{
			double e2 = (WGS84_a*WGS84_a-WGS84_b*WGS84_b)/(WGS84_a*WGS84_a);
			double B2,L2,H2;
			double X,Y,Z;
			double X2,Y2,Z2;

			double B=in_point.x/180*PI;
			double L=in_point.y/180*PI;
			double H=in_point.z/180*PI;


			double N=WGS84_a/sqrt(1-e2*sin(B)*sin(B));
			X=(N+H)*cos(B)*cos(L);
			Y=(N+H)*cos(B)*sin(L);
			Z=(N*(1-e2)+H)*sin(B);
			//cout<<X<<"   "<<Y<<endl;
			X2=inPara.dx+(1+inPara.m)*X-Z*inPara.wy+Y*inPara.wz;
			Y2=inPara.dy+(1+inPara.m)*Y+Z*inPara.wx-X*inPara.wz;
			Z2=inPara.dz+(1+inPara.m)*Z-Y*inPara.wx+X*inPara.wz;

			B2=atan(Z2*(N+H)/(sqrt(X2*X2+Y2*Y2)*(N*(1-e2)+H)));

			L2=atan(Y2/X2);

			double d1,d2;
			d1=B2/PI*180;
			d2=L2/PI*180+180;
			Ogre::Vector3 latlon;
			latlon.x=d2;
			latlon.y=d1;
			return latlon;
		}

		Ogre::Vector3 CoordinateCalculator::BJ54toXian80(Ogre::Vector3& in_point,sevenPara& inPara)
		{
			double e2 = (krass_a*krass_a-krass_b*krass_b)/(krass_a*krass_a);
			double B2,L2,H2;
			double X,Y,Z;
			double X2,Y2,Z2;

			double B=in_point.x/180*PI;
			double L=in_point.y/180*PI;
			double H=in_point.z/180*PI;

			double N=krass_a/sqrt(1-e2*sin(B)*sin(B));
			X=(N+H)*cos(B)*cos(L);
			Y=(N+H)*cos(B)*sin(L);
			Z=(N*(1-e2)+H)*sin(B);
			//cout<<X<<"   "<<Y<<endl;
			X2=inPara.dx+(1+inPara.m)*X-Z*inPara.wy+Y*inPara.wz;
			Y2=inPara.dy+(1+inPara.m)*Y+Z*inPara.wx-X*inPara.wz;
			Z2=inPara.dz+(1+inPara.m)*Z-Y*inPara.wx+X*inPara.wz;

			B2=atan(Z2*(N+H)/(sqrt(X2*X2+Y2*Y2)*(N*(1-e2)+H)));

			L2=atan(Y2/X2);

			double d1,d2;
			d1=B2/PI*180;
			d2=L2/PI*180+180;
			Ogre::Vector3 latlon;
			latlon.x=d2;
			latlon.y=d1;
			return latlon;
		}

		Ogre::Vector3 CoordinateCalculator::Xian80toBJ54(Ogre::Vector3& in_point,sevenPara& inPara)
		{
			double e2 = (IAG75_a*IAG75_a-IAG75_b*IAG75_b)/(IAG75_a*IAG75_a);
			double B2,L2,H2;
			double X,Y,Z;
			double X2,Y2,Z2;

			double B=in_point.x/180*PI;
			double L=in_point.y/180*PI;
			double H=in_point.z/180*PI;

			double N=IAG75_a/sqrt(1-e2*sin(B)*sin(B));
			X=(N+H)*cos(B)*cos(L);
			Y=(N+H)*cos(B)*sin(L);
			Z=(N*(1-e2)+H)*sin(B);
			//cout<<X<<"   "<<Y<<endl;
			X2=inPara.dx+(1+inPara.m)*X-Z*inPara.wy+Y*inPara.wz;
			Y2=inPara.dy+(1+inPara.m)*Y+Z*inPara.wx-X*inPara.wz;
			Z2=inPara.dz+(1+inPara.m)*Z-Y*inPara.wx+X*inPara.wz;

			B2=atan(Z2*(N+H)/(sqrt(X2*X2+Y2*Y2)*(N*(1-e2)+H)));

			L2=atan(Y2/X2);

			double d1,d2;
			d1=B2/PI*180;
			d2=L2/PI*180+180;
			Ogre::Vector3 latlon;
			latlon.x=d2;
			latlon.y=d1;

			return latlon;

		}


		std::string  CoordinateCalculator::int2str(int n) {

			char t[24];
			int i = 0;

			while (n) {
				t[i++] = (n % 10) + '0';
				n /= 10;
			}
			t[i] = 0;

			return std::string(strrev(t));
		}
		//projUV  CoordinateCalculator::Xian80_GridtoLL(KGrid& grid,int band)
		//{
		//	std::string s1="+proj=tmerc +lat_0=0 +lon_0=";
		//	std::string s4 = int2str(band);
		//	if (band<=23)
		//		band=band*6-3;
		//	else band*=3;

		//	std::string s2 = int2str(band);
		//	std::string s3=" +k=1 +x_0=";
		//	std::string s5="500000 +y_0=0 +ellps=IAU76 +units=m +no_defs";
		//	std::string str=s1+s2+s3+s4+s5;
		//	//cout<<str<<endl;
		//	const char* psz=str.c_str();

		//	//const char* pszXian80="+proj=tmerc +lat_0=0 +lon_0=111 +k=1 +x_0=37500000 +y_0=0 +ellps=IAU76 +units=m +no_defs";
		//	//
		//	projUV p;
		//	projPJ pj;

		//	if (!(pj = pj_init_plus(psz))) exit(1);


		//	p.u = grid.X;
		//	p.v = grid.Y;
		//	p=pj_inv(p,pj);
		//	//cout.setf(ios_base::fixed);
		//	p.u/=DEG_TO_RAD;
		//	p.v/=DEG_TO_RAD;
		//	//cout<<"Xian_80:    "<<grid.X<<"    "<<grid.Y <<endl;
		//	//cout<<"pj_inv result:    "<<p.u<<"    "<<p.v<<endl;
		//	pj_free(pj);

		//	return p;
		//}
		projUV  CoordinateCalculator::Xian80_LLtoGrid(double lon,double lat,int band)
		{
			//const char* pszXian80="+proj=tmerc +lat_0=0 +lon_0=111 +k=1 +x_0=37500000 +y_0=0 +ellps=IAU76 +units=m +no_defs";
			int a;
			std::string s1="+proj=tmerc +lat_0=0 +lon_0=";
			std::string s3=" +k=1 +x_0=";
			std::string s5="500000 +y_0=0 +ellps=IAU76 +units=m +no_defs";
			std::string str;
			if (band==6)
			{
				a=lon/6+1;
				int b=a*6-3;

				std::string s2 = int2str(b);

				std::string s4 = int2str(a);

				str=s1+s2+s3+s4+s5;}

			else 
			{
				band=3;
				a=lon/3+0.5;
				int b=a*3;
				std::string s2 = int2str(b);

				std::string s4 = int2str(a);

				str=s1+s2+s3+s4+s5;
			}
			
			//cout<<str<<endl;
			const char* psz=str.c_str();

			projUV p;
			projPJ pj;
			if (!(pj = pj_init_plus(psz))) exit(1);
			p.u=lon*DEG_TO_RAD;
			p.v=lat*DEG_TO_RAD;
			p=pj_fwd(p,pj);
			
			pj_free(pj);

			return p;
			
		}

		projUV  CoordinateCalculator::WGS84_GridtoLL(double lon,double lat,int band)
		{
			std::string s1="+proj=tmerc +lat_0=0 +lon_0=";
			std::string s4 = int2str(band);
			if (band<=23)
				band=band*6-3;
			else band*=3;

			std::string s2 = int2str(band);
			std::string s3=" +k=1 +x_0=";
			std::string s5="500000 +y_0=0 +ellps=WGS84 +units=m +no_defs";
			std::string str=s1+s2+s3+s4+s5;
			//cout<<str<<endl;
			const char* psz=str.c_str();

			//const char* pszXian80="+proj=tmerc +lat_0=0 +lon_0=111 +k=1 +x_0=37500000 +y_0=0 +ellps=IAU76 +units=m +no_defs";
			//
			projUV p;
			projPJ pj;

			if (!(pj = pj_init_plus(psz))) exit(1);


			p.u = lon;
			p.v = lat;
			p=pj_inv(p,pj);
			//cout.setf(ios_base::fixed);
			p.u/=DEG_TO_RAD;
			p.v/=DEG_TO_RAD;
			//cout<<"Xian_80:    "<<grid.X<<"    "<<grid.Y <<endl;
			//cout<<"pj_inv result:    "<<p.u<<"    "<<p.v<<endl;
			pj_free(pj);

			return p;
		}

		//projUV  CoordinateCalculator::WGS84_LLtoGrid(Latlon& latlon,int band)
		//{
		//	//const char* pszXian80="+proj=tmerc +lat_0=0 +lon_0=111 +k=1 +x_0=37500000 +y_0=0 +ellps=WGS84 +units=m +no_defs";
		//	int a;
		//	std::string s1="+proj=tmerc +lat_0=0 +lon_0=";
		//	std::string s3=" +k=1 +x_0=";
		//	std::string s5="500000 +y_0=0 +ellps=WGS84 +units=m +no_defs";
		//	std::string str;
		//	if (band==6)
		//	{
		//		a=latlon.lon/6+1;
		//		int b=a*6-3;

		//		std::string s2 = int2str(b);

		//		std::string s4 = int2str(a);

		//		str=s1+s2+s3+s4+s5;}

		//	else 
		//	{
		//		band=3;
		//		a=latlon.lon/3+0.5;
		//		int b=a*3;
		//		std::string s2 = int2str(b);

		//		std::string s4 = int2str(a);

		//		str=s1+s2+s3+s4+s5;
		//	}

		//	//cout<<str<<endl;
		//	const char* psz=str.c_str();

		//	projUV p;
		//	projPJ pj;
		//	if (!(pj = pj_init_plus(psz))) exit(1);
		//	p.u=latlon.lon*DEG_TO_RAD;
		//	p.v=latlon.lat*DEG_TO_RAD;
		//	p=pj_fwd(p,pj);

		//	pj_free(pj);

		//	return p;

		//}
}
}
