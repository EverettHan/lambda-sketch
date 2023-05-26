/* -*-C++-*- */
/* COPYRIGHT DASSAULT SYSTEMES 1997                                      */
/*=======================================================================*/

#ifndef __CATIUnknown
#define __CATIUnknown

#include "JS0CORBA.h"
#include "CATBaseUnknown.h"
#include "CATMetaClass.h"

// Do not use after migration

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByJS0CORBA IID IID_CATIUnknown;
#else
extern "C" const IID IID_CATIUnknown;
#endif


/**
 * A convenient interface for all classes that derive from CATBaseUnknown.
 */
class ExportedByJS0CORBA CATIUnknown : public CATBaseUnknown
{
   CATDeclareInterface;
   public :
/**
 * Returns the class name for which the given implementation is an instance.
 */
      virtual CATClassId GetName() const = 0;
/**
 * Determines whether the given implementation's class derives from a given one.
 * @param iName
 *   The class name from which the given object's class is supposed to derive.
 * @return 0 if the given object's class doesn't derive from <tt>iName</tt>
 * and a non null value otherwise.
 */
      virtual int GetKindOf(CATClassId iName) const = 0;

/**
 * Returns the class name for the base class of the given implementation.
 */
      virtual CATClassId GetNameOfBaseClass() const = 0;

/**
 * Returns the class type ( should return Implementation ).
 */
      virtual TypeOfClass GetTypeOfClass() const = 0;
};

CATDeclareHandler(CATIUnknown,CATBaseUnknown);

#endif
