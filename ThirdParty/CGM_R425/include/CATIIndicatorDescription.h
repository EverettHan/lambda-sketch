/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef _CATIIndicatorDescription_h
#define _CATIIndicatorDescription_h

#include "CATBaseUnknown.h"

class CATMathDirection;
class CATMathPoint;
class CATMathVector;
class CATUnicodeString;
class CATPathElement;
/**
 * Interface to describe an indicator.
 * <b>Role</b>: 
 */
#include "CATVisItf.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIIndicatorDescription;
#else
extern "C" const IID IID_CATIIndicatorDescription;
#endif
 
class ExportedByCATVisItf CATIIndicatorDescription : public CATBaseUnknown
{
public:
  CATDeclareInterface;

  /**
  * Retrieves the direction of the indicator.
  * Implementation is mandatory to be able to
  * create a CATIIndicator on your object
  * @param oDirection
  * The direction.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetDirection(CATMathDirection& oDirection) = 0;

  /**
  * Retrieves the anchor point of the indicator.
  * Implementation is mandatory to be able to
  * create a CATIIndicator on your object.
  * @param oPoint
  * The anchor point.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetPoint(CATMathPoint& oPoint) = 0;  

  /**
  * Retrieves the default name of the indicator.
  * Implementation not mandatory. 
  * If not implemented, CATIAlias is used.
  * @param oName
  * The default name.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetName(CATUnicodeString& oName) = 0;

  /**
  * Retrieves the gap of the indicator.
  * Implementation not mandatory. 
  * Used for specific objects (Sub-element of Axis system).
  * @param oGap
  * The gap.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetGap(CATMathVector& oGap) = 0;

  /**
  * Retrieves the direction of the arrow.
  * Implementation is mandatory to be able to
  * create a CATIArrow on your object
  * @param oDirection
  * The direction.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetArrowDirection(CATMathDirection& oDirection) = 0;

  /**
  * Sets the path of the element if it belongs to an assembly.
  * It allows to apply the transformation of the part in order to locate correctly the indicator 
  * @param iAssemblyContext
  * The path of the element in the assembly context. 
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT SetAssemblyContext(CATPathElement* const iAssemblyContext) = 0;
};

#endif
