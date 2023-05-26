/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef _CATISymbol_h
#define _CATISymbol_h

#include "CATBaseUnknown.h"
#include "CATBooleanDef.h"

class CATNotification;
class CATUnicodeString;
class CATCommand;

/**
 * Interface to create an indicaot.
 * <b>Role</b>: Call this interface on a CATIISO obejct.
 */

#include "UIModelInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATISymbol;
#else
extern "C" const IID IID_CATISymbol;
#endif

class ExportedByUIModelInterfaces CATISymbol : public CATBaseUnknown
{
public:
  CATDeclareInterface;

  /**
  * Draw the CATISymbol.
  * To call after CATISymbol creation or attribute modification
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT Draw() = 0;  

  /**
  * Retrieves the reference of the CATISymbol.
  * @return
  * The reference. To be released.
  */
  virtual CATBaseUnknown* GetReference() = 0;  

  /**
  * Set the text associated to the CATIIndicator.
  * Call Draw method to visualize the modification
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT SetText(const CATUnicodeString& iText) = 0;

  /**
  * Set the CATISymbol as selected.
  * Call Draw method to visualize the modification
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT SetSelected(const CATBoolean iHl) = 0;

  /**
  * Set the color of the CATISymbol.
  * Call Draw method to visualize the modification
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT SetColor(const unsigned int color) = 0;

  /**
  * Set the thickness of the CATISymbol.
  * Call Draw method to visualize the modification
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT SetThickness(const unsigned int iThickness) = 0;

  /**
  * Retrieves the event publisher of the CATISymbol.
  * @return
  * The event publisher
  */
  virtual CATCommand* GetEventPublisher() = 0;

  /**
  * Set the CATCommand father of the CATISymbol.
  * @param iFather
  * The father.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT SetFather(CATCommand * iFather) = 0;
  
};

#endif
