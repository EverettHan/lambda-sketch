#ifndef CATI2DGeoVisu_H
#define CATI2DGeoVisu_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U4 CATExtIVisu
 */


#include "CATIVisu.h"
#include "CATVisItf.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATI2DGeoVisu;
#else
extern "C" const IID IID_CATI2DGeoVisu;
#endif

/** 
 * Specialized 2D Visualization interface to make objects have a 2D representation.
 * <p><b>BOA information</b>: this interface CANNOT be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page.
 * Click Middleware at the bottom left, then click the Object Modeler tab page.
 * Several articles deal with the BOA.</p>
 * @see CATIVisu
 */
class ExportedByCATVisItf CATI2DGeoVisu : public CATIVisu
{
    /** @nodoc */
  CATDeclareInterface;

  public :

} ; 

/** @nodoc */
CATDeclareHandler(CATI2DGeoVisu,CATBaseUnknown);

#endif
