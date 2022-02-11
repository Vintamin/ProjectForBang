
# ifndef _VR_SQLDATABASEHELPERCONFIG_H
#define _VR_SQLDATABASEHELPERCONFIG_H

#ifndef VR_SQLDATABASEHELPER_EXPORTS
#define VR_SQLDBHELPER_DLL _declspec(dllimport)
#else
#define VR_SQLDBHELPER_DLL _declspec(dllexport)
#endif
#endif
