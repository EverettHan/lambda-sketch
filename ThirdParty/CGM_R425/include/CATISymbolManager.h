/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef _CATISymbolManager_h
#define _CATISymbolManager_h

#include "CATBaseUnknown.h"

class CATISymbol;
class CATIIndicator;
class CATIArrow;
class CATPathElement;
/**
 * Interface to create a symbol.
 * <b>Role</b>: Call this interface on a CATIISO object.
 */
#include "UIModelInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATISymbolManager;
#else
extern "C" const IID IID_CATISymbolManager;
#endif
 
class ExportedByUIModelInterfaces CATISymbolManager : public CATBaseUnknown
{
public:

  CATDeclareInterface;

  /**
  * Creates an indicator corresponding to an object.
  * Call CATIIndicator::Draw method to visualize the CATIIndicator.
  * Use RemoveIndicator or RemoveAllIndicators to destroy this indicator.
  * Release oIndicator after call to AddIndicator.
  * @param iElement
  * The reference of the indicator.
  * It must implement the interface CATIIndicatorDescription to be able to return
  * the position and the direction of the indicator.
  * Notice: CATBRepAccessImpl and GeometricalElement already implements CATIIndicatorDescription.
  * @param iAssemblyContext
  * The path of the element if it belongs to an assembly.  
  * @param oIndicator
  * The created indicator.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT AddIndicator(CATBaseUnknown* iElement, CATIIndicator** oIndicator,
     CATPathElement* iAssemblyContext=NULL) = 0;

   /**
  * Creates an arrow corresponding to an object.
  * Call CATISymbol::Draw method to visualize the CATISymbol.
  * Use RemoveSymbol or RemoveAllarrows to destroy this arrow.
  * Release oArrow after call to AddArrow.
  * @param iElement
  * The reference of the arrow.
  * It must implement the interface CATIIndicatorDescription to be able to return the position and the direction
  * of the arrow.
  * Notice: CATBRepAccessImpl and GeometricalElement already implements CATIIndicatorDescription.
  * @param iAssemblyContext
  * The path of the element if it belongs to an assembly.  
  * @param oArrow
  * The created arrow.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT AddArrow(CATBaseUnknown* iElement, CATIArrow** oArrow,
     CATPathElement* iAssemblyContext=NULL) = 0;

  /**
  * Removes a symbol from the CATISO - Destroys it if not user by any other CATISO
  * @param iSymbol
  * The symbol.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT RemoveSymbol(CATISymbol* iSymbol) = 0;  

  /**
  * Removes a symbol from the CATISO - Destroys them if not used by any other CATISO.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT RemoveAllSymbols() = 0;  

  /**
  * Add a symbol created on another CATISO
  * @param iSymbol
  * The symbol.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT AddSymbol(CATISymbol* iSymbol) = 0;  

};

#endif
