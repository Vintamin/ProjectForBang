
# ifndef _VR_COORDINATESYSTEM_CONFIG_H
#define _VR_COORDINATESYSTEM_CONFIG_H

#ifndef VR_COORDINATESYSTEM_EXPORTS
#define VR_COORDINATESYSTEM_DLL _declspec(dllimport)
#else
#define VR_COORDINATESYSTEM_DLL _declspec(dllexport)
#endif
#endif
