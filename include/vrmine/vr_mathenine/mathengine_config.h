# ifndef _VR_MATHENGINE_CONFIG_H
#define _VR_MATHENGINE_CONFIG_H

#ifndef VR_MATHENGINE_EXPORTS
#define VR_MATHENGINE_DLL _declspec(dllimport)
#else
#define VR_MATHENGINE_DLL _declspec(dllexport)
#endif
#endif
