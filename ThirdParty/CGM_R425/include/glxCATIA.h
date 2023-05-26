#ifndef GLXCATIA_H
#define GLXCATIA_H

// COPYRIGHT DASSAULT SYSTEMES 2002

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xmd.h>
#include "glCATIA.h"
#include "glxtokensCATIA.h"

#ifdef __cplusplus
extern "C" {
#endif
/*
** GLX resources.
*/
typedef XID GLXContextID;

typedef XID GLXWindow;	
typedef XID GLXPixmap;
typedef XID GLXPbuffer;
typedef XID GLXDrawable;

/*
** GLXContext is a pointer to opaque data.
**/
typedef struct __glXContextRec *GLXContext;

/* Function Prototype */
#ifndef VISU_WITHORWITHOUT_CONTEXT_OSMESA
#define GLX_GLX_PROTOTYPES  1
#endif

/************************************************************************/

#ifdef GLX_GLX_PROTOTYPES
extern XVisualInfo * glXChooseVisual (Display *dpy, int screen, int *attribList);
extern void glXCopyContext (Display *dpy, GLXContext src, GLXContext dst, unsigned long mask);
extern GLXContext glXCreateContext (Display *dpy, XVisualInfo *vis, GLXContext shareList, Bool direct);
extern GLXPixmap glXCreateGLXPixmap (Display *dpy, XVisualInfo *vis, Pixmap pixmap);
extern void glXDestroyContext (Display *dpy, GLXContext ctx);
extern void glXDestroyGLXPixmap (Display *dpy, GLXPixmap pix);
extern int glXGetConfig (Display *dpy, XVisualInfo *vis, int attrib, int *value);
extern GLXContext glXGetCurrentContext (void);
extern GLXDrawable glXGetCurrentDrawable (void);
extern Bool glXIsDirect (Display *dpy, GLXContext ctx);
extern Bool glXMakeCurrent (Display *dpy, GLXDrawable drawable, GLXContext ctx);
extern Bool glXQueryExtension (Display *dpy, int *errorBase, int *eventBase);
extern Bool glXQueryVersion (Display *dpy, int *major, int *minor);
extern void glXSwapBuffers (Display *dpy, GLXDrawable drawable);
extern void glXUseXFont (Font font, int first, int count, int listBase);
extern void glXWaitGL (void);
extern void glXWaitX (void);
extern const char * glXGetClientString (Display *dpy, int name );
extern const char * glXQueryServerString (Display *dpy, int screen, int name );
extern const char * glXQueryExtensionsString (Display *dpy, int screen );
#endif /* GLX_GLX_PROTOTYPES */
typedef XVisualInfo* ( * PFNGLXCHOOSEVISUALPROC) (Display *dpy, int screen, int *attribList);
typedef void ( * PFNGLXCOPYCONTEXTPROC) (Display *dpy, GLXContext src, GLXContext dst, unsigned long mask);
typedef GLXContext ( * PFNGLXCREATECONTEXTPROC) (Display *dpy, XVisualInfo *vis, GLXContext shareList, Bool direct);
typedef GLXPixmap ( * PFNGLXCREATEGLXPIXMAPPROC) (Display *dpy, XVisualInfo *vis, Pixmap pixmap);
typedef void ( * PFNGLXDESTROYCONTEXTPROC) (Display *dpy, GLXContext ctx);
typedef void ( * PFNGLXDESTROYGLXPIXMAPPROC) (Display *dpy, GLXPixmap pix);
typedef int ( * PFNGLXGETCONFIGPROC) (Display *dpy, XVisualInfo *vis, int attrib, int *value);
typedef GLXContext ( * PFNGLXGETCURRENTCONTEXTPROC) (void);
typedef GLXDrawable ( * PFNGLXGETCURRENTDRAWABLEPROC) (void);
typedef Bool ( * PFNGLXISDIRECTPROC) (Display *dpy, GLXContext ctx);
typedef Bool ( * PFNGLXMAKECURRENTPROC) (Display *dpy, GLXDrawable drawable, GLXContext ctx);
typedef Bool ( * PFNGLXQUERYEXTENSIONPROC) (Display *dpy, int *errorBase, int *eventBase);
typedef Bool ( * PFNGLXQUERYVERSIONPROC) (Display *dpy, int *major, int *minor);
typedef void ( * PFNGLXSWAPBUFFERSPROC) (Display *dpy, GLXDrawable drawable);
typedef void ( * PFNGLXUSEXFONTPROC) (Font font, int first, int count, int listBase);
typedef void ( * PFNGLXWAITGLPROC) (void);
typedef void ( * PFNGLXWAITXPROC) (void);
typedef const char * ( * PFNGLXGETCLIENTSTRINPROC) (Display *dpy, int name );
typedef const char * ( * PFNGLXQUERYSERVERSTRINGPROC) (Display *dpy, int screen, int name );
typedef const char * ( * PFNGLXQUERYEXTENSIONSSTRINGPROC) (Display *dpy, int screen );

#ifdef __cplusplus
}
#endif

#endif /* GLXCATIA_H */
