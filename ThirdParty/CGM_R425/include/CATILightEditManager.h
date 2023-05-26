/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2001
#ifndef _CATILightEditManager_h
#define _CATILightEditManager_h

#include "CATBaseUnknown.h"
class CATPathElement;
class CATListValCATBaseUnknown_var;

/**
 * Interface to retrieve allowed light edit command on a pathelement
 * This interface should be implemented on workench
 */
#include "CATInteractiveInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATInteractiveInterfaces IID IID_CATILightEditManager;
#else
extern "C" const IID IID_CATILightEditManager;
#endif

class ExportedByCATInteractiveInterfaces CATILightEditManager : public CATBaseUnknown
{
public:
  CATDeclareInterface;

  /**
   * Retrieve light edit object
   * @param iPath
   *    path of selected element
   * @param oLightEditObject
   *    object to light edit
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL
   */
  virtual HRESULT FindLightEditObject(const CATPathElement* iPath,
         CATBaseUnknown** oLightEditObject) = 0;

  /**
   * Retrieve light edit interfaces
   * @param iObject
   *    lighteditobject
   * @param oListOfLightEditInterfaces
   *    list of CATILightEdit interface (or derivated interface) which could be call on this path
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL
   */
  virtual HRESULT FindLightEdit(const CATBaseUnknown* iObject,
         CATListValCATBaseUnknown_var** oListOfLightEditInterfaces) = 0;

};

#endif
