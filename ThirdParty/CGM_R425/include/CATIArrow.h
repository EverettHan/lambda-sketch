/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef _CATIArrow_h
#define _CATIArrow_h

#include "CATISymbol.h"
#include "CATBooleanDef.h"


/**
 * Interface to create an symbol arrow.
 * <b>Role</b>: Call this interface on a CATIISO object.
 */
#include "UIModelInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIArrow;
#else
extern "C" const IID IID_CATIArrow;
#endif 

class ExportedByUIModelInterfaces CATIArrow : public CATISymbol
{
public:
  CATDeclareInterface;

  /**
  * Reverses the CATIArrow
  * Call Draw method to visualize the modification
  * @param iReverse
  * Reverse the arrow
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT Reverse() = 0;


  /**
  * Reverses the CATIArrow
  * @param oIsReversed
  * TRUE if the arrow is reversed according to its initial direction , else FALSE
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT IsReversed(CATBoolean& oIsReversed) = 0;

  /**
  * Allow the arrow to be reversed by the user
  * @param iAllowReverse
  * TRUE if the arrow can be reversed else FALSE (default is FALSE)
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT AllowReverse(const CATBoolean iAllowReverse) = 0;

  /**
  * Retrieves the notification that the arrow has been reversed.
  * @return
  * The reverse notification
  */
  virtual CATNotification* GetModifyNotification()=0;
};

#endif
