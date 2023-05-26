#ifndef CATGraphicElementNormale_h
#define CATGraphicElementNormale_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CATBaseUnknown.h"
#include "SGInfra.h"

#include "CATMathDirection.h"

/**
* Class holding the normal coordinates of the intersection point.
* Used by @href CATGraphicPathElement to store information of the selection
* <br>normal point on a graphic element.
* <br>Uses the @href #direction variable to set/get normal values.
*
* @see CATGraphicPathElement
*/
class ExportedBySGInfra CATGraphicElementNormale : public CATBaseUnknown
{
  CATDeclareClass;
  
public :
  ////////
  
  /**
  * Constructor. 
  *
  * @param iDirection
  *        The normal at the intersection with graphic element.
  */
  CATGraphicElementNormale (CATMathDirection iDirection);

  virtual ~CATGraphicElementNormale ();
  
  /**
  * The normal at the intersection with graphic element.
  */
  CATMathDirection  direction;

};

#endif
