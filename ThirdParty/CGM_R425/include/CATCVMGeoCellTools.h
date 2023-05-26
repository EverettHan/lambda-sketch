/* -*-C++-*- */

#ifndef CATCVMGeoCellTools_H
#define CATCVMGeoCellTools_H

// COPYRIGHT DASSAULT SYSTEMES 2007


#include "CATCVMGeoObjects.h"
#include "CATCVMGeoDef.h"
#include "CATBoolean.h"

class CATCVMGeometry;
class CATMathPoint;
class CATMathPlane;
class CATMathVector;
class CATCVMInstancePath;
class CATGeometry;
class CATBody;
class CATFace;

class ExportedByCATCVMGeoObjects CATCVMGeoCellTools
{
public:
  static CATCVMCanonicity GetCanonicity(CATCVMGeometry * iCVMGeometry);

  // To prefer rather than a combinaition of GetCenter + GetNormal 

  static CATBoolean GetFaceCenterAndNormal(CATCVMGeometry * iCVMFace, CATMathPoint & oCenter,
                              CATMathVector & oNormal, CATBoolean iNormalToFaceInBody = FALSE);

  static CATBoolean GetFaceCenterAndNormal(CATBody * iBody,  CATFace * iFace, CATMathPoint & oCenter,
                              CATMathVector & oNormal);


  static CATBoolean GetCenter(CATCVMGeometry * iCVMGeometry, CATMathPoint & oCenter);
  static CATBoolean GetCenter(CATCVMInstancePath * iInstancePath, CATCVMGeometry * iCVMGeometry, CATMathPoint & oCenter);

  static CATBoolean GetEdgeExtremities(CATCVMGeometry * iCVMEdge, CATMathPoint oExtremities[2]);
  static CATBoolean GetEdgeExtremities(CATCVMInstancePath * iInstancePath, CATCVMGeometry * iCVMEdge, CATMathPoint oExtremities[2]);

  static CATBoolean GetNormal(CATCVMGeometry * iCVMFace, CATMathPoint & iPointOnFace,
                              CATMathVector & oNormal, CATBoolean iNormalToFaceInBody = FALSE);

  static CATBoolean GetNormal(CATCVMInstancePath * iInstancePath, 
                              CATCVMGeometry * iCVMFace, CATMathPoint & iPointOnFace,
                              CATMathVector & oNormal, CATBoolean iNormalToFaceInBody = FALSE);

  static CATBoolean GetNormalToCircle(CATCVMGeometry * iCVMEdge, CATMathPoint & iPointOnEdge, CATMathVector & oNormal);
  static CATBoolean GetNormalToCircle(CATCVMInstancePath * iInstancePath,
                                      CATCVMGeometry * iCVMEdge, CATMathPoint & iPointOnEdge, CATMathVector & oNormal);

  // GetAxis : Methode qui renvoie l'axe du cylindre + un point sur cet axe dans le cas 
  //           d'une face avec surface cylindrique. La methode renvoie FALSE dans les autres cas.
  static CATBoolean GetAxis(CATCVMGeometry * iCVMFace,
                            CATMathPoint   & oOrigin,
                            CATMathVector  & oDirection);
  static CATBoolean GetAxis(CATCVMInstancePath * iInstancePath,
                            CATCVMGeometry * iCVMFace,
                            CATMathPoint   & oOrigin,
                            CATMathVector  & oDirection);

  // GetAxis : Methode qui renvoie l'axe du cylindre + un point sur cet axe dans le cas 
  //           d'une face avec surface cylindrique. La methode renvoie FALSE dans les autres cas.
  static CATBoolean GetAxis(CATCVMGeometry * iCVMFace,  
                            CATMathVector  &oU, 
                            CATMathVector  &oV, 
                            CATMathVector  & oDirection,
                            CATMathPoint   & oOrigin);
  static CATBoolean GetAxis(CATCVMInstancePath * iInstancePath,
                            CATCVMGeometry * iCVMFace,  
                            CATMathVector  &oU, 
                            CATMathVector  &oV, 
                            CATMathVector  & oDirection,
                            CATMathPoint   & oOrigin);

  // if CVMFace is a Sphere returns the sphere center 
  // else returns the orgin of the revolution axis
  static CATBoolean GetOrigin(CATCVMGeometry * iCVMFace,  CATMathPoint &oOrigin);

  static CATBoolean GetRadius(CATCVMGeometry * iCVMFace,  double &oRadius);

  static CATBoolean GetMinorAndMajorTorusRadii(CATCVMGeometry * iCVMFace,  double &oMinorRadius, double &oMajorRadius);
  static CATBoolean GetTangentPlaneAtCenter(CATCVMGeometry * iCVMGeometry, CATMathPlane & oPlane);


  // GetCanonicity : same as  CATCVMGeometry
  static CATCVMCanonicity GetCanonicity(CATGeometry * iGeometry);

private:
  CATCVMGeoCellTools();
  CATCVMGeoCellTools(const CATCVMGeoCellTools &);//Necessary to prevent unwanted automatic creation by compiler
  void operator = (const CATCVMGeoCellTools &);

};
#endif
