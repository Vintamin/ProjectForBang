# ifndef _VR_PROJECTMANAGER_CONFIG_H
#define _VR_PROJECTMANAGER_CONFIG_H

#ifndef VR_PROJECTMANAGER_EXPORTS
#define VR_PROJECTMANAGER_DLL _declspec(dllimport)
#else
#define VR_PROJECTMANAGER_DLL _declspec(dllexport)
#endif
#endif
