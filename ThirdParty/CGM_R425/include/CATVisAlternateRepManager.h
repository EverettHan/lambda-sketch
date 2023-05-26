#ifndef CATVisAlternateRepManager_H
#define CATVisAlternateRepManager_H

#include "SGInfra.h"
#include "CATErrorDef.h"

class CATRep;
class CATSurfacicRep;

namespace CATVisAlternateRepManager
{
  /**
   * Define iAlternateRep as alternateRep to iRep. Use iAlternateRep = nullptr to remove current alternateRep attached to iRep.
   * Checks that iAlternateRep's geometry is consistant with iRep's (i.e. same number of faces, lods...)
   * 
   * \return: E_FAIL if geometry check or alternate rep definition fails, S_OK otherwise
   */
  ExportedBySGInfra HRESULT SetAlternateRep(CATRep* iRep, CATSurfacicRep* iAlternateRep);

  /**
   * Get iRep's currently defined alternate rep.
   * 
   * \return: iRep's current alternate rep, or nullptr if none is defined.
   */
  ExportedBySGInfra CATSurfacicRep* GetAlternateRep(CATRep* iRep);

  /**
   * Copy all graphic attributes, materials and material face groups from iRep to iAlternateRep.
   * /!\ CATSurfacicRep API limitation: CATMaterialApplication list set to a face using CATSurfacicRep::AddGeomFace(CAT3DFaceGP*, CATGraphicAttributeSet*, const ::list<CATMaterialApplication>&, CATMappingOperator*) 
   * will not be entirely copied to iAlternateRep: only the currently resolved material application (i.e. the last one) will be copied.
   *
   * \return HRESULT: E_FAIL if copy fails, S_OK otherwise 
   */
  ExportedBySGInfra HRESULT CopyGraphicAttributes(CATRep* iRep, CATSurfacicRep* iAlternateRep);

  void _NotifyObserverAlternateRep(CATRep* iRep);
  bool _CheckGeometry(CATRep* iRep, CATSurfacicRep* iAlternateRep);
}

#endif
