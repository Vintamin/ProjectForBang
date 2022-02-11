
# ifndef _BANG_RENDER_STYLE_CONFIG_H
#define _BANG_RENDER_STYLE_CONFIG_H

#ifndef VR_BANG_STYLE_EXPORTS
#define BANG_RENDER_DLL _declspec(dllimport)
#else
#define BANG_RENDER_DLL _declspec(dllexport)
#endif
#endif
