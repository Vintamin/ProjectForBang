
# ifndef _VR_SPATIALLAYER_CONFIG_H
#define _VR_SPATIALLAYER_CONFIG_H

#ifndef VR_SPATIALLAYER_EXPORTS
#define VR_SPATIALLAYER_DLL _declspec(dllimport)
#else
#define VR_SPATIALLAYER_DLL _declspec(dllexport)
#endif
#endif
