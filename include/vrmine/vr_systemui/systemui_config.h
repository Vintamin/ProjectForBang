
# ifndef _VR_SYSTEMUI_CONFIG_H
#define _VR_SYSTEMUI_CONFIG_H

#ifndef VR_SYSTEMUI_EXPORTS
#define VR_SYSTEMUI_DLL _declspec(dllimport)
#else
#define VR_SYSTEMUI_DLL _declspec(dllexport)
#endif
#endif
