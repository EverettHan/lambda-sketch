// COPYRIGHT DASSAULT SYSTEMES  <2005>
//=============================================================================
//
// CATAssembleOperatorOptions.h:
//
//=============================================================================
// Usage Notes:
//
// services permettant d'augmenter les interfaces de l'operateur CATHybAssemble
// sans augmenter la vue CAA.
//
// !!! Seulement avec la nouvelle version du Join (i.e. creee avec 
// CATCreateNewTopAssemble) !!!
//
//=============================================================================
// Aug. 05   Creation                                             JBX
//=============================================================================
//

#ifndef CATAssembleOperatorOptions_H
#define CATAssembleOperatorOptions_H

//DG
#include "BOHYBOPELight.h"
#include "ListPOfCATEdge.h"

class CATHybAssemble;

class CATBody;
class CATFace;
class CATEdge;

// Indique a l'operateur de garder ses structures de donnee pour pouvoir
// repondre a des questions de type sur l'historique de l'operation
ExportedByBOHYBOPELight void KeepInformationClasses(CATHybAssemble * iOperator);

// Si iInitEdge est bord, alors oImageEdges contient juste iInitEdge.
// Si iInitEdge est absorbée ou autre, alors oImageEdges est vide.
// iInitFace est un parametre facultatif, il peut etre nul dans ce cas.
ExportedByBOHYBOPELight void GetImageEdgesFromInitialEdge(CATHybAssemble * iOperator, CATEdge * iInitEdge, CATBody * iInitBody, CATFace * iInitFace, 
                                                     ListPOfCATEdge & oImageEdgeList);

ExportedByBOHYBOPELight void SetNonManifoldAllowed(CATHybAssemble * iOperator, short iValue);

ExportedByBOHYBOPELight void SetMergeInternalEdges(CATHybAssemble * iOperator, short iValue);


#endif // CATAssembleOperatorOptions_H
