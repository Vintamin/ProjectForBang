# ifndef _VR_SQLSERVERDATABASE_CONFIG_H
#define _VR_SQLSERVERDATABASE_CONFIG_H

#ifndef VR_SQLSERVERDATABASE_EXPORTS
#define VR_SQLSERVERDATABASE_DLL _declspec(dllimport)
#else
#define VR_SQLSERVERDATABASE_DLL _declspec(dllexport)
#endif
#endif