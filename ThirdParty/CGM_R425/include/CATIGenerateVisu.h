#ifndef CATIGenerateVisu_H
#define CATIGenerateVisu_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "CATIVisu.h"
#include "CATVisItf.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIGenerateVisu;
#else
extern "C" const IID IID_CATIGenerateVisu;
#endif

/** 
 * @nodoc
 * Specialized interface to allow the generation of a Visualization representation.
 * This interface is meant to be used in conjunction with the CATVisMananger.
 * <p><b>BOA information</b>: this interface CANNOT be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page.
 * Click Middleware at the bottom left, then click the Object Modeler tab page.
 * Several articles deal with the BOA.</p>
 * @see CATIVisu
 */
class ExportedByCATVisItf CATIGenerateVisu : public CATIVisu
{
  /** @nodoc */
  CATDeclareInterface;

  public :

} ; 

#endif
