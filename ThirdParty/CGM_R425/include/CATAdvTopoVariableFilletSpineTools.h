// COPYRIGHT DASSAULT SYSTEMES 2005
//==========================================================================
//
// CATAdvTopoVariableFilletSpineTools
// Interface class of the CATAdvTopoVariableFilletSpineTools Object.
//
//==========================================================================
//
// Usage notes:
// This class is dedicated to variable fillet spine creation.
//
//========================================================================== 
// Nov05     Creation                       Melina Skouras (CWM)
//========================================================================== 

#ifndef CATAdvTopoVariableFilletSpineTools_h
#define CATAdvTopoVariableFilletSpineTools_h

#include "FrFTopologicalOpe.h"
#include "CATVariableFilletSpineTools.h"

class ExportedByFrFTopologicalOpe CATAdvTopoVariableFilletSpineTools : public CATVariableFilletSpineTools
{
public:
 /**
 * Virtual constructor of a CATAdvTopoVariableFilletSpineTools.
 * Do not call. Use the CATCreateAdvTopoVariableFilletSpineTools global function
 * to create a CATAdvTopoVariableFilletSpineTools.
 */
  CATAdvTopoVariableFilletSpineTools(CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig); 

 /**
 * Destructor.
 */
  virtual ~CATAdvTopoVariableFilletSpineTools();

 /**
 * Creates a CATAdvTopoVariableFilletSpineTools.
 * @param iFactory
 * The factory of the geometry. 
 * @param iConfig
 * The pointer to the the software configuration.
 * @return
 * The pointer to the created CATAdvTopoVariableFilletSpineTools. 
 * To delete after use with the usual C++ <tt>delete</tt> operator.
 */
  static CATAdvTopoVariableFilletSpineTools* CATCreateAdvTopoVariableFilletSpineTools(CATGeoFactory * iFactory, 
                                                                                      CATSoftwareConfiguration * iConfig); 

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
  CATBody * CreateSpineBody(CATBody *iMacroEdgeBody, CATBoolean iClose, double iTol);

  void SetCellsToFix(CATLISTP(CATCell) & iCellsToFix);

private:
  CATLISTP(CATCell) _CellsToFix;

};

// For dynamic creation of a CATAdvTopoVariableFilletSpineTools (Debug purpose only)
// extern "C" absolutely necessary here for method name used in dynamic load (comment NLD021020)
extern "C" ExportedByFrFTopologicalOpe 
CATAdvTopoVariableFilletSpineTools* CATAdvTopoVariableFilletSpineToolsCreate(CATGeoFactory            * iFactory, 
                                                                             CATSoftwareConfiguration * iConfig); 

#endif 



