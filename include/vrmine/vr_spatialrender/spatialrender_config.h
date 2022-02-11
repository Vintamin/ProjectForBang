
# ifndef _VR_SPATIALRENDER_CONFIG_H
#define _VR_SPATIALRENDER_CONFIG_H

#ifndef VR_SPATIALRENDER_EXPORTS
#define VR_SPATIALRENDER_DLL _declspec(dllimport)
#else
#define VR_SPATIALRENDER_DLL _declspec(dllexport)
#endif
#endif
