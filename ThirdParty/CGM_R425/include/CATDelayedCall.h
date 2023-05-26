// This structure anable delayed calls managmnent
#ifndef DelayedCall_H
#define DelayedCall_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#ifdef _WINDOWS_SOURCE

// astuce pour by-passer un bug (?) des MFCs
// et permettre a un source de referencer a la fois
// iostream.h et afxwin.h meme indirectement.
 
#ifdef _WINDOWS_
#define _WINDOWS_AUX
#undef _WINDOWS_
#endif 

#include <afxwin.h>

#ifdef _WINDOWS_AUX
#define _WINDOWS_
#undef _WINDOWS_AUX
#endif

#endif // fin _WINDOWS_SOURCE

#if !defined (_WINDOWS_SOURCE)
#include <sys/time.h>
#include <sys/types.h>
#endif

#if !defined (_NO_X11_SOURCE) && (defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE))
#include <X11/Xlib.h>
#include <X11/extensions/XInput.h>
#include <Xm/Xm.h>
#endif

#if defined (_COCOA_SOURCE) || defined (_ANDROID_SOURCE) || defined (_GTK_SOURCE)
// memcpy
#include <string.h>
#endif
#include "CATBaseUnknown.h"
#include "CATDataType.h"

#if defined (_WINDOWS_SOURCE) || defined (_COCOA_SOURCE) || defined (_ANDROID_SOURCE)
#define DelayedId CATUINTPTR
#elif defined (_LINUX_SOURCE) && defined (_GTK_SOURCE)
// should be guint32, but avoids including glib headers...
#define DelayedId CATUINT32
#else
#define DelayedId XtIntervalId
#endif

#define CATDelayedData   void*
typedef  void (CATBaseUnknown::*CATDelayedMethod)(CATDelayedData);

class CATGraphicWindow;


struct DelayedCall
{
  CATBaseUnknown*  _instance;
  CATDelayedMethod _method;
  CATDelayedData   _data;

  DelayedCall(CATBaseUnknown* inst , CATDelayedMethod method, CATDelayedData data);
  ~DelayedCall();
};

struct CallId;

struct TimeOutData
{
  CATGraphicWindow* _setter;
  DelayedCall*      _call;
  TimeOutData (CATGraphicWindow*,DelayedCall*);
  ~TimeOutData();

  void SetId (DelayedId id);
  static CallId* Cancel(DelayedId id);
  static CallId* CancelLast(  CATGraphicWindow* setter);
  
  static CallId* _IdManager;
  static unsigned int _count;
};

struct CallId
{
  DelayedId    _id;
  TimeOutData* _tod;
};

struct stack
{
  unsigned int size;
  unsigned int maxsize;
  DelayedId *array;
  inline  void push (DelayedId id);
  inline  DelayedId pop ( void);

  inline  stack ( void);
  inline ~stack ( void);
};


// inline stack definition

inline stack::stack (void)
{
  array = new DelayedId[16];
  size  = 0;
  maxsize = 0;
}

inline stack::~stack (void)
{
  delete[] array; // array is never null
}

inline void stack::push (DelayedId id)
{
  if (size == maxsize)
    {
      maxsize++;
      if ((size % 16) == 1) // just one is free
	{
	  DelayedId *tmp = new DelayedId[size+17];
	  memcpy ((void*)tmp, (void*)array, size * sizeof(DelayedId));
	  delete[] array;
      array = tmp;
	}
    }
  array[size] = id;
  size++;
}

inline DelayedId stack::pop ( void)
{
  maxsize = (size > maxsize) ? size : maxsize;
  return (size) ? array[--size] : (DelayedId)NULL;
}

#endif
