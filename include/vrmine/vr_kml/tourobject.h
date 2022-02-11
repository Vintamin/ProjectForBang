#ifndef CTOUROBJECT_H_
#define CTOUROBJECT_H_
#include "vrmine/vr_kml/kml_config.h"
#include "vrmine/vr_kml/kmlobject.h"


namespace VirtualMine
{
	namespace Kml
	{
		class CCameraTourChangedListener;
		class CTourRecord_Private;
		class CTourObject;
		class CTourPlayListener : public Ogre::FrameListener
		{
		public:
			CTourPlayListener(CTourRecord_Private* ref_pOperator);
			~CTourPlayListener();
			bool frameStarted(const Ogre::FrameEvent& evt);

		public:
			CTourRecord_Private* ref_mpOperator; 
		};

		enum TourState
		{
			//��ʼ¼��
			TS_RECORD_R,
			
			//����¼��
			TS_END_R,

			//��ʼ����
			TS_PLAY_P,

			//��ͣ����
			TS_PAUSE_P,

			//ֹͣ����
			TS_STOP_P,

			//
			TS_NONE,
		};

		class VR_KML_DLL CTourObject : public CKmlObject
		{
			friend class CCameraTourChangedListener;
			friend class CTourPlayListener;
			friend class CTourRecord_Private;
		public:
			CTourObject(VirtualMine::Scene::CGeoSpatialControl* ref_pControl);
			virtual ~CTourObject();
			virtual bool startRecord();
			virtual bool stopRecord();
			virtual bool startPlay();
			virtual bool pausePlay();
			virtual bool stopPlay();
			virtual TourState getState();
			virtual void fromFile(const std::string& path);
			virtual void toFile(const std::string& path);
			virtual std::string getPath();
		protected:
			CTourRecord_Private* mpPrivate;
		};

	}
}


#endif