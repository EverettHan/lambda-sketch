#ifndef CATCVMTransfoUV_h
#define CATCVMTransfoUV_h

#include "CATCVMGeoObjects.h"

//-------------------------------------------------------------------------------------------
// Service to Update UV Texture mapping (TextureAxis) with new complex surface 
//    
//      Starter :  Reparametrization Plan -> Nurbs
//
//(Rq : For exhaustive of new UV Texture mapping management NXG_MATERIAL_UV_MAPPING=1)
//-------------------------------------------------------------------------------------------

class CATFace;
class CATCVMAttribute;
class CATCVMCopy;
class CATCVMGeometry;
class CATCVMTexture;

#include "CATMathTransformation2D.h"
#include "CATSurface.h"
#include "CATCVMTexture.h"

class CATCVMBody;

/**
 * CATCVMTransfoUV 
 */
class ExportedByCATCVMGeoObjects  CATCVMTransfoUV 
{
public:
  CATCVMTransfoUV();
  virtual ~CATCVMTransfoUV();

  
 /**
  * IsTextureManagedByTransfoUV :  
  *     
  *    @param iGeometry
  *               Geometry to Check about direct Texture management
  *
  *    @param oManagedByTranfoUV
  *               Result management
  *  
  * return
  *    E_FAIL if insuffient information or abnomaly is detected
  *    S_OK   otherwise analysis Okay
  */
  static HRESULT  IsTextureManagedByTransfoUV(CATCVMGeometry *iGeometry, CATBoolean & oManagedByTranfoUV);

  
 /**
  * IsBodyContainsUVMappingTexture :  
  *     
  *    @param iBody
  *               Body to Check if it contains Faces with Texture managed by UV mapping
  *
  *    @param oContainsUVMappingTexture
  *               Result management
  *  
  * return
  *    E_FAIL abnomaly detected
  *    S_OK   analysis okay
  */
  static HRESULT  IsBodyContainsUVMappingTexture(CATCVMBody *iBody, CATBoolean & oContainsUVMappingTexture);
 
  
  
 /**
  * IsActivated : Managed initial Impact under activation
  * return TRUE (if activated) FALSE (otherwise)
  */
  static CATBoolean  IsActivated();

 /**
  * UpdateOnCanonicityChange
  *   Integration of UV Mapping Sur changement de canonicite du support
  *    @param iKeptCVMGeometry
  *    @param iTexture
  *    @param iNewFace
  */
  HRESULT  UpdateTransfoUV(CATCVMGeometry  *iKeptCVMGeometry, 
                                            CATCVMTexture   *iTexture,
                                            CATFace         *iNewFace) ;
 


 };


#endif

