#ifndef IVISSGOBJECT_H
#define IVISSGOBJECT_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IUnknown.h"
#include "VisSceneGraph.h"

extern ExportedByVisSceneGraph IID IID_IVisSGObject;

#ifdef _WINDOWS_SOURCE
#define FASTCALL __fastcall
#else
#define FASTCALL
#endif

/** 
 * Basic class of any Scene Graph object.
 * <b>Role</b>: This is the basic class that any Scene Graph object has to C++ derive from.
 */
class ExportedByVisSceneGraph IVisSGObject : public IUnknown
{
public:

   /** @nodoc */
   virtual void* GetImplementation() const = 0;

  /**
   * The type accepted by all iteration methods defined on Scene Graph objects.
   */
   typedef void * IVisSGIterationContext;
};

#endif
