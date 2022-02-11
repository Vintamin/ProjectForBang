
# ifndef _VR_SPATIALENGINE_CONFIG_H
#define _VR_SPATIALENGINE_CONFIG_H

#ifndef VR_SPATIALENGINE_EXPORTS
#define VR_SPATIALENGINE_DLL _declspec(dllimport)
#else
#define VR_SPATIALENGINE_DLL _declspec(dllexport)
#endif
#endif
