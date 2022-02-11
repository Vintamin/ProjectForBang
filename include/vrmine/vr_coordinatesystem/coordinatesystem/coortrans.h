#ifndef _COORTRANS_H_INCLUDED
#define _COORTRANS_H_INCLUDED


#include "vrmine\vr_coordinatesystem\coordinatesystem\coordinatesystem_config.h"

const double PI = 3.14159265353846;

namespace VirtualMine
{
	namespace CoordinateSystem
	{

		double Dms2Rad(double Dms);//�Ƕȵ����ȵ�ת��
		double Rad2Dms(double Rad);//���ȵ��Ƕȵ�ת��
		class  VR_COORDINATESYSTEM_DLL PrjPoint
		{
		private:
			double m_OriginLongitude; // ���������߾���
			double m_Lo, m_La; // ��γ������
			double x, y; // ��˹ͶӰƽ������
			double m_ZoneNum;//����������
			double m_ParaDegree;//�ֶζ���
			int m_CoordSysType;//��׼����(0Ϊ��³����˹����׼��1Ϊ����UGG1975��׼,2ΪWGS84������)
		private:
			bool SetOriginLongitude(double dOriginLongitude);// �������������߾���
			bool LoLaToxy();//��γ������תΪ�������
			bool xyToLoLa();//�������תΪ��γ������
			bool SetTempxy(double dx, double dy);//���ô������
		protected:
			double a,b,n, f, e2, e12; // �����������,a���뾶,b�̰뾶,n=(a-b)/(a+b),f����,e2��һƫ����ƽ��,e12�ڶ�ƫ����ƽ��
			double A1, A2, A3, A4; // ���ڼ���X���������
		public:
			PrjPoint();
			~PrjPoint();
		public:
			bool SetCoordSysType(int type);//���ñ�׼����������,Ĭ��Ϊ0(0Ϊ��³����˹�������壬1Ϊ����UGG1975������,2ΪWGS84������)
			bool SetAB(double da,double db);//��������������;da��dbΪ������ĳ��뾶�Ͷ̰뾶
			bool SetParaDegree(double ParaDegree);//���÷ֶζ���,Ĭ��Ϊ6��
			bool SetZoneNum(double ZoneNum);//���ù�������,Ĭ��Ϊ21��
			bool SetLoLa(double dLo, double dLa);//���þ�γ������
			bool GetLoLa(double *dLo, double *dLa);//�õ���γ������
			bool Setxy(double dx, double dy);//���ô������
			bool Getxy(double *dx, double *dy);//�õ��������
			bool GetSpaceCoord(double *dx, double *dy,double *dz);//�õ��ռ�����
		};
		
	}
}
#endif /* ndef _COORTRANS_H_INCLUDED */
