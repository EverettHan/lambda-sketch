//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2007
//=============================================================================
//
// CATCVMGeoCreateSpline :
//
//=============================================================================
// Usage notes:
// sample of use :
//
//=============================================================================
// 2007  Creation                     ???     
// 2010/10/28    PKC        Ajout imposition des tangentes   
//                          Methodes : SetTangent, ResetTangent
// 2014/09/10    FCX        CloseSpline option updateLastPoint
//=============================================================================

#ifndef CATCVMGeoCreateSpline_H
#define CATCVMGeoCreateSpline_H

#include "CATCVMGeoOperator.h"
#include "ListPOfCATCVMBody.h"

class CATCVMGeometry;
class CATSplineCurve;
class CATCVMComponent;
class CATCVMInstancePath;

class ExportedByCATCVMGeoOperators CATCVMGeoCreateSpline : public CATCVMGeoOperator
{
public:

  //------------------------------------------------------------------------------
  // Create a CATCVMGeoCreateSpline operator
  //------------------------------------------------------------------------------
  static CATCVMGeoCreateSpline * Create(CATCVMGeoContainer * iCVMGeoContainer,
                                        CATTopData         * iTopData);
  static CATCVMGeoCreateSpline * Create(CATCVMInstancePath * iCVMInstancePath,
                                        CATTopData         * iTopData);

protected:

	// Constructor
  CATCVMGeoCreateSpline(CATCVMGeoContainer   *iCVMGeoContainer,
                        CATTopData           *iTopData,
                        CATCVMGeoOperatorExt *iExtensible);
  CATCVMGeoCreateSpline(CATTopData           *iTopData,
                        CATCVMGeoOperatorExt *iExtensible);
  
public:

	// Destructor
  virtual ~CATCVMGeoCreateSpline();

  //------------------------------------------------------------------------------
  // Parameters and modes
  //------------------------------------------------------------------------------

  /**
  /* Define the bodies with which the result body will be merged (optional)
  */
  virtual void SetBodiesToMerge(ListPOfCATCVMBody & iListBodies);

  /**
  /* Set the host component (optional)
  */
  virtual void SetHostComponent(CATCVMComponent *iComponent);

  /**
  /* Set the creation mode of closed splines :
  /* iSurfacic = FALSE (default) : resulting CVM geometry is wireframe
  /* iSurfacic = TRUE            : resulting CVM geometry is surfacic
  */
  virtual void SetSurfacic(CATBoolean iSurfacic);

  //------------------------------------------------------------------------------
  // Construction & edition methods
  //------------------------------------------------------------------------------

  /**
  * Add a point at the end of the spline 
  */
  virtual void AddPoint(const double * iPoint, CATCVMGeometry * iSupportGeometry = 0);

  /**
  * Update the coordinates of the last point of the spline
  */
  virtual void UpdateLastPoint(const double * iPoint, CATCVMGeometry * iSupportGeometry = 0);

  /**
  * Update the coordinates of a point of the spline
  * iIndex : index from 0 to  NumberOfPoints-1
  */
  virtual void UpdatePoint(int iIndex, const double * iPoint, CATCVMGeometry * iSupportGeometry = 0);

  /**
  * Insert a point at a specific position
  * iIndex : index from 0 to  NumberOfPoints-1
  */
  virtual void InsertPoint(int iIndex, const double * iPoint, CATCVMGeometry * iSupportGeometry = 0);

  /**
  * Get the number of points of the spline 
  */
  virtual int GetNumberOfPoints() const;

  /**
  * Remove a point from the spline
  * iIndex : index from 0 to  NumberOfPoints-1
  */
  virtual void RemovePoint(int iIndex);
  
  /**
  * Close the spline (add an end point confused to the first point if needed)
  * iUpdateLastPoint : if TRUE, no point is added but the last point coordinates are updated to match the first point
  * Any modification of the spline after calling this method will cancel the closure of the spline :
  * AddPoint, UpdateLastPoint, UpdatePoint, InsertPoint and RemovePoint
  * return TRUE if successful, FALSE otherwise
  */
  virtual CATBoolean CloseSpline(CATBoolean iUpdateLastPoint = FALSE);

  /**
  * return TRUE if the spline is closed, FALSE otherwise
  */
  virtual CATBoolean IsClosed();

  /**
  * Impose a 3D tangent direction at a definition point
  * iIndex : index of the definition point
  * iIndex : index from 0 to  NumberOfPoints-1
  */
  virtual void SetTangent(int iIndex, const double * iTangent);

  /**
  * Remove tangent imposition at a definition point
  * iIndex : index of the definition point
  * iIndex : index from 0 to  NumberOfPoints-1
  */
  virtual void ResetTangent(int iIndex);

  //------------------------------------------------------------------------------
  // Previsualization methods
  //------------------------------------------------------------------------------

  /**
  * Get the previsualization 3D spline curve
  * return a pointer to the CATSplineCurve if preview is available, FALSE otherwise
  * this object is removed from the factory by the CATCVMGeoCreateSpline operator
  */
  virtual CATSplineCurve* GetPreviewCurve() const;

  //------------------------------------------------------------------------------
  // CVM geometry creation
  //------------------------------------------------------------------------------

  /**
  * -> Use RunSafe
  * Compute the CVM geometry. After calling this method, only GetResultingCVMBody can be used
  * (any other method will have no effect)
  */
  
  //------------------------------------------------------------------------------
  // Get CVM geometry data
  //------------------------------------------------------------------------------

  /**
  * Get the resulting CVMBody (To call after the Run)
  * Return NULL if the Run has not been called or has failed
  */
  virtual CATCVMBody *GetResultingCVMBody();
  
};
#endif
