// COPYRIGHT DASSAULT SYSTEMES 2005
//==========================================================================
//
// CATVariableFilletSpineTools
//
//==========================================================================
//
// Usage notes:
// Virtual class dedicated to variable fillet spine creation.
//
//========================================================================== 
// Nov05     Creation                       Melina Skouras (CWM)
//========================================================================== 

#ifndef CATVariableFilletSpineTools_h
#define CATVariableFilletSpineTools_h

#include "CATCGMVirtual.h"
#include "Fillet.h"

#include "CATMathDef.h"
#include "ListPOfCATCell.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATBody;

class ExportedByFillet CATVariableFilletSpineTools : public CATCGMVirtual
{
public:
  /**
  * Constructor/Destructor
  */
  CATVariableFilletSpineTools(CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig); 
  virtual ~CATVariableFilletSpineTools();

 /**
 * Create a body of a C2 spine
 * @param iMacroEdgeBody
 * Body containing the macroedge wire to smooth
 * @param iClose
 * iClose = TRUE for a closed spine
 * @param iTol
 * Allowed deviation between the initial macroedge and the resulting spine
 * @return
 * The pointer to the created spine body. Use @href CATICGMContainer#Remove if you do not want to keep it.
 */
  virtual CATBody * CreateSpineBody(CATBody *iMacroEdgeBody, CATBoolean iClose, double iTol) = 0;

  virtual void SetCellsToFix(CATLISTP(CATCell) &iCellsToFix) = 0;

protected:
  CATGeoFactory * _Factory;
  CATSoftwareConfiguration * _Config;
};

#endif 
