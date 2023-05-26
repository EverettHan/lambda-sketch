#ifndef __CATPrintf_h
#define __CATPrintf_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#ifdef DLG_OLD_VERSION
#define CATPrintf(trace)            \
  if (Tra_## trace ##.IsActive ())  \
    Tra_## trace ##.TraPrint
#else
#define CATPrintf(trace)            \
  if (Tra_##trace.IsActive ())  \
    Tra_##trace.TraPrint
#endif

#endif//__CATPrintf_h
