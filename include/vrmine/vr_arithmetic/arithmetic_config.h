
# ifndef _VR_ARITHMETIC_CONFIG_H
#define _VR_ARITHMETIC_CONFIG_H

#ifndef VR_ARITHMETIC_EXPORTS
#define VR_ARITHMETIC_DLL _declspec(dllimport)
#else
#define VR_ARITHMETIC_DLL _declspec(dllexport)
#endif
#endif
