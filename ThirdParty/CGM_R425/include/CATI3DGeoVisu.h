#ifndef CATI3DGeoVisu_H
#define CATI3DGeoVisu_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U4 CATExtIVisu
 */


#include "CATIVisu.h"
#include "CATVisItf.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATI3DGeoVisu;
#else
extern "C" const IID IID_CATI3DGeoVisu;
#endif

/** 
 * Specialized 3D Visualization interface to make objects have a 3D representation.
 * <p><b>BOA information</b>: this interface CANNOT be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page.
 * Click Middleware at the bottom left, then click the Object Modeler tab page.
 * Several articles deal with the BOA.</p>
 * @see CATIVisu
 */
class ExportedByCATVisItf CATI3DGeoVisu : public CATIVisu
{
  /** @nodoc */
  CATDeclareInterface;

  public :

} ; 

/** @nodoc */
CATDeclareHandler(CATI3DGeoVisu,CATBaseUnknown);

#endif
