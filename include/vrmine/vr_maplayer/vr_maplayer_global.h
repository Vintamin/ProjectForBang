#ifndef VR_MAPLAYER_GLOBAL_H
#define VR_MAPLAYER_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef VR_MAPLAYER_DLLEXPORT
# define VR_MAPLAYER_EXPORT Q_DECL_EXPORT
#else
# define VR_MAPLAYER_EXPORT Q_DECL_IMPORT
#endif

#endif // VR_MAPLAYER_GLOBAL_H

