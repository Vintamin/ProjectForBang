
# ifndef _UTILITY_CONFIG_H
#define _UTILITY_CONFIG_H

#ifndef VR_UTILITY_EXPORTS
#define VR_UTILITY_DLL _declspec(dllimport)
#else
#define VR_UTILITY_DLL _declspec(dllexport)
#endif
#endif
