

# ifndef _VR_SCENECONTROL_CONFIG_H
#define _VR_SCENECONTROL_CONFIG_H

#ifndef VR_SCENECONTROL_EXPORTS
#define VR_SCENECONTROL_DLL _declspec(dllimport)
#else
#define VR_SCENECONTROL_DLL _declspec(dllexport)
#endif
#endif
