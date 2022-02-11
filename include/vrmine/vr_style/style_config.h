
# ifndef _VR_STYLE_CONFIG_H
#define _VR_STYLE_CONFIG_H

#ifndef VR_STYLE_EXPORTS
#define VR_STYLE_DLL _declspec(dllimport)
#else
#define VR_STYLE_DLL _declspec(dllexport)
#endif
#endif
