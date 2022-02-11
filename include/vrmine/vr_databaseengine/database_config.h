
# ifndef _VR_DATABASEENGINE_CONFIG_H
#define _VR_DATABASEENGINE_CONFIG_H

#ifndef VR_DATABASEENGINE_EXPORTS
#define VR_DATABASEENGINE_DLL _declspec(dllimport)
#else
#define VR_DATABASEENGINE_DLL _declspec(dllexport)
#endif
#endif
