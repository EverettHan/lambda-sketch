#ifndef CATVisClippingGeom_H
#define CATVisClippingGeom_H

/*******************************************************************************************************/
/*  CATVisClippingGeom defines the base class for geometry used as clipping filter.                    */
/*                                                                                                     */
/*      GetSectionCount: returns the clipping section count                                            */
/*      GetSectionPlane: returns the plane equation of the clipping section i                          */
/*      IsTetrahedronIntersectingSection: is tetrahedron cutted by the section plane and is this       */
/*                                        intersection in the section limits                           */
/*      AreIntersectionPointsInsideSection: are intersection points inside the section limits          */
/*      IsTriangleInsideSection: is the triangle inside the clipping section i                         */
/*      GetBiggestCoordinate: returns the bounding if the clipping geometry                            */
/*******************************************************************************************************/

// Local Framework
#include "SGInfra.h"
// System Framework
#include "IUnknown.h"
// Local Framework
class CATGraphicAttributeSet;
class l_CATVisClippingGeom;
class CATVisTetrahedron;
class CATVisPolyhedronVertex;
// Mathematical Framework
class CATMathPlane;
class CATMathVector;
class CATMathPointf;
class CATMathDirectionf;

class ExportedBySGInfra CATVisClippingGeom 
{
public :

  void AddRef(); 
  void Release();

	virtual HRESULT GetSectionCount(int& oSectionCount) const = 0;
  virtual HRESULT GetSectionPlane(int iClippingSectionIndex, CATMathPlane& oPlane, CATMathVector& oClippingOrientation) const = 0;

	virtual int IsTetrahedronIntersectingSection(int iClippingSectionIndex, const CATVisTetrahedron* ipTetrahedron, double& oD0, double& oD1, double& oD2, double& oD3) const = 0;
	virtual int AreIntersectionPointsInsideSection(int iClippingSectionIndex, const CATVisPolyhedronVertex* ipIntersectionPoint[4]) const = 0;
	virtual int IsTriangleInsideSection(int iClippingGeomIndex, int iClippingSectionIndex, const CATVisPolyhedronVertex* ipTetraVertex0, const CATVisPolyhedronVertex* ipTetraVertex1, const CATVisPolyhedronVertex* ipTetraVertex2) const = 0;

	virtual unsigned int GetBiggestCoordinate() const;

protected :

	CATVisClippingGeom();
	virtual ~CATVisClippingGeom();

	void SetLetter(l_CATVisClippingGeom* ipLetter);
	l_CATVisClippingGeom* GetLetter() const;

private:

	l_CATVisClippingGeom* _pLetter;
	unsigned int _nRef;
};
#endif 
  
  
