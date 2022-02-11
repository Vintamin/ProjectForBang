# ifndef _VR_SQLITEDATABASE_CONFIG_H
#define _VR_SQLITEDATABASE_CONFIG_H

#ifndef VR_SQLITEDATABASE_EXPORTS
#define VR_SQLITEDATABASE_DLL _declspec(dllimport)
#else
#define VR_SQLITEDATABASE_DLL _declspec(dllexport)
#endif
#endif
