
# ifndef _COMMON_CONFIG_H
#define _COMMON_CONFIG_H

#ifndef VR_CORE_EXPORTS
#define VR_CORE_DLL _declspec(dllimport)
#else
#define VR_CORE_DLL _declspec(dllexport)
#endif
#endif
