#ifndef CATVisClippingProfile_H
#define CATVisClippingProfile_H

/*******************************************************************************************************/
/*  CATVisClippingProfile defines a profile on a plane used as clipping filter.                        */
/*                                                                                                     */
/*      iPoint: the point of the plane on which the profile is defined                                 */
/*      iNormal: the normal of the plane opn which the profile is defined                              */
/*      iClippingOrientation:  = 0 => no clipping                                                      */
/*                             > 0 => normal create a direct triedre with                              */
/*                                      -    _NormalToProfileSectionPlan (x)                           */
/*                                      -    p1-p2                       (y)                           */
/*                                      -    normal to section in the plane(z)                         */
/*                             < 0 => normal create a indirect triedre                                 */
/*      iNbVertex: the vertices count defining the clipping profile                                    */
/*      ipVertices: the vertices coordinates defining the clipping profile                             */
/*******************************************************************************************************/

// Local Framework
#include "CATVisClippingGeom.h"
// Local Framework
class l_CATVisClippingProfile;
class CATVisPolyhedronVertex;
class CATVisTetrahedron;
// Mathematical Framework
class CATMathPlane;
class CATMathVector;
class CATMathPointf;
class CATMathDirectionf;

class ExportedBySGInfra CATVisClippingProfile : public CATVisClippingGeom 
{

public :

  static CATVisClippingProfile* Create(  const CATMathPointf& iPoint,
                                         const CATMathDirectionf& iNormal,
                                         const int iClippingOrientation);

  void SetPolygon(const int iNbVertex, const float *ipVertices);
  void GetPolygon(int *opNbVertex, float **opVertices) const;

  void SetClippingOrientation(int iClippingOrientation);
  int GetClippingOrientation() const;
	
	HRESULT GetSectionCount(int& oSectionCount) const;
  HRESULT GetSectionPlane(int iClippingSectionIndex, CATMathPlane& oPlane, CATMathVector& oClippingOrientation) const;

	int IsTetrahedronIntersectingSection(int iClippingSectionIndex, const CATVisTetrahedron* ipTetrahedron, double& oD0, double& oD1, double& oD2, double& oD3) const;
	int AreIntersectionPointsInsideSection(int iClippingSectionIndex, const CATVisPolyhedronVertex* ipIntersectionPoint[4]) const;
	int IsTriangleInsideSection(int iClippingGeomIndex, int iClippingSectionIndex, const CATVisPolyhedronVertex* ipTetraVertex0, const CATVisPolyhedronVertex* ipTetraVertex1, const CATVisPolyhedronVertex* ipTetraVertex2) const;

	unsigned int GetBiggestCoordinate() const;

protected :

  CATVisClippingProfile(const CATMathPointf& iPoint,
                        const CATMathDirectionf& iNormal,
                        const int iClippingOrientation);

  virtual ~CATVisClippingProfile();

};
#endif 
  
  
