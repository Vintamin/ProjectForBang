
# ifndef _KML_CONFIG_H
#define _KML_CONFIG_H

#ifndef VR_KML_EXPORTS
#define VR_KML_DLL _declspec(dllimport)
#else
#define VR_KML_DLL _declspec(dllexport)
#endif
#endif
