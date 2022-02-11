//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ��ά���ֿ�ɽƽ̨
//  @ File Name : ispatialreference.cpp
//  @ Date : 2014/7/6
//  @ Author : ʢ����
//  @ Implement : 
//  @ Company : �й���ҵ��ѧ(����)
//  @ Copyright:  2014-2020
//  @ Description : 


#include "vrmine\vr_spatialinterface\ispatialreference.h"
#include "OGRE\OgreMath.h"
#include <math.h>

using namespace Ogre;

namespace VirtualMine
{
	namespace SpatialInterface
	{
		CGaussPrjBase::CGaussPrjBase()
		{
			_zoneWide = 6;
			_a = 0;
			_f = 0;
		}

		CGaussPrjBase::~CGaussPrjBase()
		{

		}

		void CGaussPrjBase::DD2DMS(double DecimalDegree, int& Degree, int& Minute, double& Second)
		{
			Degree = (int)DecimalDegree;
			Minute = (int)((DecimalDegree - Degree) * 60.0);
			
			//Second = Round((DecimalDegree * 60 - Degree * 60 - Minute) * 60 * 100) / 100.0;
			Second = ((DecimalDegree * 60 - Degree * 60 - Minute) * 60 * 100) / 100.0;

		}

		double CGaussPrjBase::DistanceOfTwoPoints(double lng1, double lat1, double lng2, double lat2, Spheroid gs)
		{
			double radLat1 = Rad(lat1);
			double radLat2 = Rad(lat2);
			double a = radLat1 - radLat2;
			double b = Rad(lng1) - Rad(lng2);
			double s = 2 * Ogre::Math::ASin(Math::Sqrt(Math::Pow(Math::Sin(a / 2), 2) +
				Math::Cos(radLat1) * Math::Cos(radLat2) * Math::Pow(Math::Sin(b / 2), 2))).valueRadians();
			s = s * (gs == Spheroid::WGS84 ? 6378137.0 : (gs == Spheroid::Xian80 ? 6378140.0 : 6378245.0));
			s = s * 10000 / 10000;//????
			return s;
		}      

		double CGaussPrjBase::Rad(double d)
		{
			return d * Math::PI / 180.0;
		}

		void CGaussPrjBase::DMS2DD(int Degree, int Minute, double Second, double& DecimalDegree)
		{
			DecimalDegree = Degree + Minute / 60.0 + Second / 60.0 / 60.0;
		}

		void CGaussPrjBase::GaussPrjCalculate(double longitude, double latitude, double& X, double& Y)
		{           
			int ProjNo = 0;
			double longitude1, latitude1, longitude0, latitude0, X0, Y0, xval, yval;
			double e2, ee, NN, T, C, A, M, iPI;
			iPI = 0.0174532925199433; //3.1415926535898/180.0; 
			//_zoneWide = 6; //6�ȴ��� 
			_zoneWide = 3;
			ProjNo = (int)((longitude + 1.5) / _zoneWide);
			//ProjNo = ProjNo >= 38 ? ProjNo - 1 : ProjNo;//edited by sjl
			//longitude0 = ProjNo * _zoneWide + _zoneWide / 2;
			longitude0 = ProjNo * _zoneWide;//js�޸�
			//longitude0 = ProjNo * _zoneWide + _zoneWide;//js�޸�
			longitude0 = longitude0 * iPI;
			latitude0 = 0;
			longitude1 = longitude * iPI; //����ת��Ϊ����
			latitude1 = latitude * iPI; //γ��ת��Ϊ����
			e2 = 2 * _f - _f * _f;
			ee = e2 * (1.0 - e2);
			NN = _a / Math::Sqrt(1.0 - e2 * Math::Sin(latitude1) * Math::Sin(latitude1));
			T = Math::Tan(latitude1) * Math::Tan(latitude1);
			C = ee * Math::Cos(latitude1) * Math::Cos(latitude1);
			A = (longitude1 - longitude0) * Math::Cos(latitude1);
			M = _a * ((1 - e2 / 4 - 3 * e2 * e2 / 64 - 5 * e2 * e2 * e2 / 256) * latitude1 - (3 * e2 / 8 + 3 * e2 * e2 / 32 + 45 * e2 * e2 * e2 / 1024) * Math::Sin(2 * latitude1) + (15 * e2 * e2 / 256 + 45 * e2 * e2 * e2 / 1024) * Math::Sin(4 * latitude1) - (35 * e2 * e2 * e2 / 3072) * Math::Sin(6 * latitude1));
			xval = NN * (A + (1 - T + C) * A * A * A / 6 + (5 - 18 * T + T * T + 72 * C - 58 * ee) * A * A * A * A * A / 120);
			yval = M + NN * Math::Tan(latitude1) * (A * A / 2 + (5 - T + 9 * C + 4 * C * C) * A * A * A * A / 24 + (61 - 58 * T + T * T + 600 * C - 330 * ee) * A * A * A * A * A * A / 720);
			//X0 = 1000000L * (ProjNo + 1) + 500000L;
			X0 = 1000000L * (ProjNo) + 500000L;
			Y0 = 0;
			X = (xval + X0) * 100 / 100.0;
			Y = (yval + Y0) * 100 / 100.0;
			//X = xval + X0;
			//Y = yval + Y0;
		}

		void CGaussPrjBase::GaussPrjInvCalculate(double X, double Y, double& longitude, double& latitude)
		{
			int ProjNo;
			double longitude1, latitude1, longitude0, latitude0, X0, Y0, xval, yval;
			double e1, e2, ee, NN, T, C, M, D, R, u, fai, iPI;
			iPI = 0.0174532925199433; //3.1415926535898/180.0; 
			ProjNo = (int)(X / 1000000L); //���Ҵ���
			//longitude0 = (ProjNo - 1) * _zoneWide + _zoneWide / 2;
			longitude0 = ProjNo * _zoneWide;//js�޸�
			longitude0 = longitude0 * iPI; //���뾭��
			X0 = ProjNo * 1000000L + 500000L;
			Y0 = 0;
			xval = X - X0;
			yval = Y - Y0; //���ڴ������
			e2 = 2 * _f - _f * _f;
			e1 = (1.0 - Math::Sqrt(1 - e2)) / (1.0 + Math::Sqrt(1 - e2));
			ee = e2 / (1 - e2);
			M = yval;
			u = M / (_a * (1 - e2 / 4 - 3 * e2 * e2 / 64 - 5 * e2 * e2 * e2 / 256));
			fai = u + (3 * e1 / 2 - 27 * e1 * e1 * e1 / 32) * Math::Sin(2 * u) + (21 * e1 * e1 / 16 - 55 * e1 * e1 * e1 * e1 / 32) * Math::Sin(4 * u)+ (151 * e1 * e1 * e1 / 96) * Math::Sin(6 * u) + (1097 * e1 * e1 * e1 * e1 / 512) * Math::Sin(8 * u);
			C = ee * Math::Cos(fai) * Math::Cos(fai);
			T = Math::Tan(fai) * Math::Tan(fai);
			NN = _a / Math::Sqrt(1.0 - e2 * Math::Sin(fai) * Math::Sin(fai));
			R = _a * (1 - e2) / Math::Sqrt((1 - e2 * Math::Sin(fai) * Math::Sin(fai)) * (1 - e2 * Math::Sin(fai) * Math::Sin(fai)) * (1 - e2 * Math::Sin(fai) * Math::Sin(fai)));
			D = xval / NN;
			//���㾭��(Longitude) γ��(Latitude)
			longitude1 = longitude0 + (D - (1 + 2 * T + C) * D * D * D / 6 + (5 - 2 * C + 28 * T - 3 * C * C + 8 * ee + 24 * T * T) * D * D * D * D * D / 120) / Math::Cos(fai);
			latitude1 = fai - (NN * Math::Tan(fai) / R) * (D * D / 2 - (5 + 3 * T + 10 * C - 4 * C * C - 9 * ee) * D * D * D * D / 24 + (61 + 90 * T + 298 * C + 45 * T * T - 256 * ee - 3 * C * C) * D * D * D * D * D * D / 720);
			//ת��Ϊ�� DD
			//longitude = Math::Round((longitude1 / iPI) * 1000000) / 1000000.0;
			//latitude = Math::Round((latitude1 / iPI) * 1000000) / 1000000.0; 
			longitude = longitude1 / iPI;
			latitude = latitude1 / iPI;
		}
	}
}