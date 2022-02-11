
# ifndef _VR_GEOMETRY_CONFIG_H
#define _VR_GEOMETRY_CONFIG_H

#ifndef VR_GEOMETRY_EXPORTS
#define VR_GEOMETRY_DLL _declspec(dllimport)
#else
#define VR_GEOMETRY_DLL _declspec(dllexport)
#endif
#endif
