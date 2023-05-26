#ifndef CATAutoFilletMacroEdgeUtilities_H
#define CATAutoFilletMacroEdgeUtilities_H
//===================================================================
// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATAutoFilletMacroEdgeUtilities.h
// 		
//===================================================================
//  Nov 2008  Creation: CWM
//===================================================================

#include "CATCGMNewArray.h"

#include "CFSEngine.h"

#include "CATTopDefine.h"

class CATSoftwareConfiguration;
class CATGeoFactory;
class CATBody;
class CATSurParam;
class CATFace;
class CATEdge;

class ExportedByCFSEngine CATAutoFilletMacroEdgeUtilities
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation
 
  CATAutoFilletMacroEdgeUtilities(CATSoftwareConfiguration &iConfig,
                                  CATGeoFactory            &iFactory,
                                  CATBody                  &iInputBody);

  virtual ~CATAutoFilletMacroEdgeUtilities();

  CATEdge * GetMatchingEdge(CATSurParam     iParamOnSupports[2], 
                            CATFace        *iSupportFaces[2], 
                            CATTopConvexity iEdgeConvexity, 
                            CATFace       *&oLeftFace); //Premiere face adjacente traversee

private:
  CATSoftwareConfiguration &_Config;
  CATGeoFactory            &_Factory;

  CATBody                  &_InputBody;
};

#endif
