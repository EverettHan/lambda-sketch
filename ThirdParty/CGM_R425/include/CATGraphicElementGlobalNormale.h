#ifndef CATGraphicElementGlobalNormale_h
#define CATGraphicElementGlobalNormale_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATGraphicElementNormale.h"
#include "SGInfra.h"

#include "CATMathDirection.h"

/**
* Class holding the normal coordinates of the intersection point given in the global coordinary system.
* Used by @href CATGraphicPathElement to store information of the selection
* <br>normal point on a graphic element.
* <br>Uses the @href #direction variable to set/get normal values.
*
* @see CATGraphicPathElement
*/
class ExportedBySGInfra CATGraphicElementGlobalNormale : public CATGraphicElementNormale
{
  CATDeclareClass;
  
public :
  ////////
  
  /**
  * Constructor. 
  *
  * @param iDirection
  *        The normal at the intersection with graphic element given in the global coordinary system.
  */
  CATGraphicElementGlobalNormale (CATMathDirection iDirection);

  virtual ~CATGraphicElementGlobalNormale ();
  
  /**
  * The normal at the intersection with graphic element given in the global coordinary system.
  */
  CATMathDirection  direction;
  
};

#endif
