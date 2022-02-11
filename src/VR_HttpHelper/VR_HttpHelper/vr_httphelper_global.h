#ifndef VR_HTTPHELPER_GLOBAL_H
#define VR_HTTPHELPER_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef VR_HTTPHELPER_LIB
# define VR_HTTPHELPER_EXPORT Q_DECL_EXPORT
#else
# define VR_HTTPHELPER_EXPORT Q_DECL_IMPORT
#endif

#endif // VR_HTTPHELPER_GLOBAL_H
