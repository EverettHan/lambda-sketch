#ifndef EvalConvexityAndSharpnessLight_H
#define EvalConvexityAndSharpnessLight_H


// COPYRIGHT DASSAULT SYSTEMES 1999
#include "TopUtilLight.h"

#include "CATTopDef.h"

#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"

class CATBody;
class CATEdge;
class CATFace;
class CATShell;
class CATCrvParam;
class CATSoftwareConfiguration;


//------------------------------------------------------------------------------  
// Indique si l'arete donnee en entree est morte ou non
//------------------------------------------------------------------------------  
ExportedByTopUtilLight CATBoolean IsSmoothEdge (CATSoftwareConfiguration *iConfig,
                                                CATEdge                  *iEdge,
                                                CATFace                  *iFace,
                                                CATBody                  *iBody, 
                                                CATShell                 *iShell=NULL);

//---------------------------------------------------------------------------
// Encapsulation de EvalGlobalSharpness avec un minimum d'arguments
//---------------------------------------------------------------------------
ExportedByTopUtilLight CATTopSharpness GetGlobalSharpness (CATSoftwareConfiguration *iConfig,
                                                           CATEdge                  *iEdge,
                                                           CATFace                  *iFace,
                                                           CATBody                  *iBody, 
                                                           CATShell                 *iShell=NULL);

//---------------------------------------------------------------------------
// Fast Sharpness Evaluation (cache)
//---------------------------------------------------------------------------
ExportedByTopUtilLight void GetGlobalSharpness (CATSoftwareConfiguration *iConfig,
                                                CATEdge                  *iEdge,
                                                CATFace                  *iFace1,
                                                CATFace                  *iFace2,
                                                CATTopSharpness          &oSharpness,
                                                CATOrientation           *oOrientation = NULL,
                                                CATShell                 *iShellOwningTheTwoFaces = NULL);

#endif
