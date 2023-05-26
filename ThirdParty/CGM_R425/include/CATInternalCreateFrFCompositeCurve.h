// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateFrFCompositeCurve :
// Declaration of global functions used to create and destroy
// an instance of the CompositeCurve operator
//
//=============================================================================
// Usage notes:
// 
// *** Les Create prenant en entree une CompositeCurve en recopient la
// *** SoftwareConfiguration
// *** Si on utilise les autres, il est imperatif de faire un SetSoftwareConfiguration
// *** sur la CompositeCurve obtenue avant sa premiere utilisation
//
// sample of use :
// to provide
//
//=============================================================================
// December 97 CPL                                  Creation
// November 98 NLD/CPL  Ajout CreateCompositeCurve_PackCcv  
// 17/03/99 NLD Ajout CreateCompositeCurve_InvertCcv
// 04/11/03 MNA : Nouvelle signature de Pack_ccv avec Liste des crv issues d'occurences multiples  
//                en argument par defaut
// 04/11/03 MNA J'elimine l'ancienne signature de Pack_ccv
// 11/01/06 NLD Shunt des signatures sans implementation
// 11/01/06 NLD Ajout CreateCompositeCurve_Streamable()
// 20/07/10 NLD Suppression definitive des signatures sans implementation
//=============================================================================
#ifndef CATInternalCreateFrFCompositeCurve_H 
#define CATInternalCreateFrFCompositeCurve_H 
//
#include <FrFAdvancedObjects.h>
#include <CATMathDef.h>
#include <CATSkillValue.h>
#include <CATTopDef.h>
#include <CATListOfInt.h>

//
class CATCurve;
class CATCrvLimits;
class CATFrFCompositeCurve;
class CATBody;
class CATEdge;
class CATEdgeCurve;
class CATMergedCurve;
class CATPCurve;
class CATSoftwareConfiguration;


//
ExportedByFrFAdvancedObjects
CATFrFCompositeCurve * CATInternalCreateCompositeCurve(CATLONG32 iNumberOfCurves,
                                            CATCurve ** iCurves,
                                            CATCrvLimits * iCrvLimits,
                                            CATLONG32 * iCrvOrientation,
                                            CATLONG32 * iSupportOrientation);
//
ExportedByFrFAdvancedObjects
CATFrFCompositeCurve * CATInternalCreateCompositeCurve(CATLONG32 iNumberOfCurves,
                                                                        CATCurve ** iCurves);
//
ExportedByFrFAdvancedObjects
CATFrFCompositeCurve * CATInternalCreateCompositeCurve(CATLONG32 iNumberOfCurves,
                                            CATCrvLimits * iCrvLimits,
                                            CATLONG32 * iCrvOrientation,
                                            CATLONG32 * iSupportOrientation,
                                            CATEdgeCurve ** iMergedCurves,
                                            CATCurve ** iCurves,CATPCurve ** iPCurves);

ExportedByFrFAdvancedObjects
CATFrFCompositeCurve * CATInternalCreateCompositeCurve(CATCurve * iCurve,
                                            const CATCrvLimits &iCrvLimits);

//
ExportedByFrFAdvancedObjects
CATFrFCompositeCurve * CATInternalCreateCompositeCurve(CATCurve * iCurve);

//
ExportedByFrFAdvancedObjects
CATFrFCompositeCurve * CATInternalCreateCompositeCurve(const CATBody * iWire,
                                            CATLONG32 iStartIndex = -1,
                                            CATLONG32 iEndIndex = -1);

// Same Create as previous except it returns a list of Edge
// corresponding to the CCV
ExportedByFrFAdvancedObjects
CATFrFCompositeCurve * CATInternalCreateCompositeCurve(const CATBody *   iWire,
                                                  CATEdge **& oEdgeList,
                                                  CATLONG32        iStartIndex = -1,
                                                  CATLONG32        iEndIndex = -1);

// La methode suivante prend en entree une liste de Edge
// avec leur orientation associee et cree une CompositeCurve.
// Si les Edge pointent sur plusieurs Curve, il n y a pas de sortie
// en erreur et la premiere est choisie
ExportedByFrFAdvancedObjects
CATFrFCompositeCurve * CATInternalCreateCompositeCurve(const CATEdge ** iEdgeList,
                                            const CATOrientation *iListOfOrien,
                                                  CATLONG32 iNbOfEdgeCur);
//
ExportedByFrFAdvancedObjects
CATFrFCompositeCurve * CATInternalCreateConnexCompositeCurve(const CATBody * iWire,
                                                  double iResolution,
                                                  CATLONG32 iStartIndex = -1,
                                                  CATLONG32 iEndIndex = -1);
//
ExportedByFrFAdvancedObjects
CATFrFCompositeCurve * CATInternalCreateCompositeCurve(const CATFrFCompositeCurve* iToCopy);
//

// rend 0 si pack non necessaire
/*ExportedByFrFAdvancedObjects
void CATInternalCreateCompositeCurve_PackCcv(CATFrFCompositeCurve* iCcv,
                                  CATFrFCompositeCurve*& oCcv);*/

// rend 0 si pack non necessaire
//Nouvelle signature de Pack_ccv avec Liste des crv issues d'occurences multiples

ExportedByFrFAdvancedObjects
void CATInternalCreateCompositeCurve_PackCcv(CATFrFCompositeCurve* iCcv,
                                  CATFrFCompositeCurve*& oCcv, CATListOfInt * oListOfIndexPackcrv=NULL);

// rend une ccv inversee
ExportedByFrFAdvancedObjects
void CATInternalCreateCompositeCurve_InvertCcv(CATFrFCompositeCurve* iCcv,
                                    CATFrFCompositeCurve*& oCcv);

//
// rend une ccv streamable (sans foreign curve) (la meme eventuellement)
ExportedByFrFAdvancedObjects
void CATInternalCreateCompositeCurve_Streamable(CATFrFCompositeCurve* iCcv,
                                     CATFrFCompositeCurve*& oCcv,
                                     CATListOfInt* oListOfIndexNewCrv=NULL);

ExportedByFrFAdvancedObjects
void CATInternalRemove(CATFrFCompositeCurve *&ioCompositeCurve );


#endif






