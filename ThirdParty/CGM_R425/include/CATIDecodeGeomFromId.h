#ifndef CATIDecodeGeomFromId_H
#define CATIDecodeGeomFromId_H

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "SceneGraphManager.h"
#include "CATBaseUnknown.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySceneGraphManager IID IID_CATIDecodeGeomFromId;
#else
extern "C" const IID IID_CATIDecodeGeomFromId;
#endif


/** 
 * Specialized 3D Visualization interface to make objects have a 3D representation.
 * @see CATIVisu
 */
class ExportedBySceneGraphManager CATIDecodeGeomFromId : public CATBaseUnknown
{
  /** @nodoc */
  CATDeclareInterface;

  public :
	virtual CATBaseUnknown* DecodeGeomFromId(int indice) = 0;

} ; 

/** @nodoc */
CATDeclareHandler(CATIDecodeGeomFromId,CATBaseUnknown);

#endif
