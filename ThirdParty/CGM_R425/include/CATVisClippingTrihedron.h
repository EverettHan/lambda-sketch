#ifndef CATVisClippingTrihedron_H
#define CATVisClippingTrihedron_H

/*******************************************************************************************************/
/*  CATVisClippingTrihedron defines a trihedron used as clipping filter.                               */
/*                                                                                                     */
/*      iOrigin:     the intersection of the three planes                                              */
/*      iFirstAxis:  the normal to the first plane                                                     */
/*      iSecondAxis: the normal to the second plane                                                    */
/*      iThirdAxis:  the normal to the third plane                                                     */
/*      iClippingOrientation:  = 0 => no clipping                                                      */
/*                             > 0 => clipping on with the 1/8 of the space                            */
/*                             < 0 => clipping on with the 7/8 of the space                            */
/*******************************************************************************************************/

// Local Framework
#include "CATVisFoundation.h"
#include "CATVisClippingGeom.h"
// Local Framework
class l_CATVisClippingTrihedron;
class CATVisPolyhedronVertex;
class CATVisTetrahedron;
// Mathematical Framework
class CATMathPlane;
class CATMathVector;
class CATMathPointf;
class CATMathDirectionf;

class ExportedByCATVisFoundation CATVisClippingTrihedron : public CATVisClippingGeom 
{
public :

  static CATVisClippingTrihedron* Create(const CATMathPointf& iOrigin,
                                         const CATMathDirectionf& iFirstAxis,
                                         const CATMathDirectionf& iSecondAxis,
                                         const CATMathDirectionf& iThirdAxis,
                                         const int iClippingOrientation);

  void SetOrigin(const CATMathPointf& iOrigin);
  void GetOrigin(CATMathPointf& oOrigin) const;

  void SetAxis(const CATMathDirectionf& iFirstAxis, const CATMathDirectionf& iSecondAxis, const CATMathDirectionf& iThirdAxis);
  void GetAxis(CATMathDirectionf& oFirstAxis, CATMathDirectionf& oSecondAxis, CATMathDirectionf& oThirdAxis) const;

	void SetClippingOrientation(int iClippingOrientation);
  int GetClippingOrientation() const;
	
  HRESULT GetSectionCount(int& oSectionCount) const;
  HRESULT GetSectionPlane(int iClippingSectionIndex, CATMathPlane& oPlane, CATMathVector& oClippingOrientation) const;

	int IsTetrahedronIntersectingSection(int iClippingSectionIndex, const CATVisTetrahedron* ipTetrahedron, double& oD0, double& oD1, double& oD2, double& oD3) const;
	int AreIntersectionPointsInsideSection(int iClippingSectionIndex, const CATVisPolyhedronVertex* ipIntersectionPoint[4]) const;
	int IsTriangleInsideSection(int iClippingGeomIndex, int iClippingSectionIndex, const CATVisPolyhedronVertex* ipTetraVertex0, const CATVisPolyhedronVertex* ipTetraVertex1, const CATVisPolyhedronVertex* ipTetraVertex2) const;

protected :

  CATVisClippingTrihedron(const CATMathPointf& iOrigin,
                          const CATMathDirectionf& iFirstAxis,
                          const CATMathDirectionf& iSecondAxis,
                          const CATMathDirectionf& iThirdAxis,
                          const int iClippingOrientation);

  virtual ~CATVisClippingTrihedron();
};
#endif 
  
  
