# ifndef _VR_SPATIALANALYSE_CONFIG_H
#define _VR_SPATIALANALYSE_CONFIG_H

#ifndef VR_SPATIALANALYSE_EXPORTS
#define VR_SPATIALANALYSE_DLL _declspec(dllimport)
#else
#define VR_SPATIALANALYSE_DLL _declspec(dllexport)
#endif
#endif
