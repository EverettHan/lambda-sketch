// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATCSGeometryLeaf.h
// Header definition of CATCSGeometryLeaf
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2002  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSGeometryLeaf_H
#define CATCSGeometryLeaf_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeometry.h"

class CATCSRigidSet;
class CATCDSBox;

//-----------------------------------------------------------------------

/**
 * A basic class for all geometries.
 */
class ExportedBySolverInterface CATCSGeometryLeaf : public CATCSGeometry
{
public:
  /**
   * Constructs an instance of the geometry.
   */
  CATCSGeometryLeaf();

  virtual ~CATCSGeometryLeaf();

  /**
   * Checks whether the geometry is matched to a specific type. The geometry
   * can be casted to a corresponding class if the matching is successful.
   * @param iType
   *   A specific type.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt> - if the matching is successful,
   *     <li><tt>FALSE</tt> - otherwise.
   *   </ul>
   */
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  /**
   * Retrieves a rigid set which includes the geometry.
   * @return
   *   Pointer to the rigid set.
   */
  virtual CATCSRigidSet *GetRigidSet();
  
  /**
   * Updates coordinates of the geometry. Length of the array depends on the
   * geometry type. Maximal length is equal to twelve.
   * @param iaCoord
   *   An array of coordinates.
   */
  virtual void UpdateCoordinates(const double iaCoord[]);

  /**
  * Get a bounding box for the geometry (of type AABB)
  * @param oBox
  *   the bounding box
  */
  virtual void GetBoundingBox(CATCDSBox *& oBox);

  /**
  * Regenerate curve from the coordinates
  * @return
  *    TRUE if the dependent curve is created successfully,
  *    FALSE if the curve can't be created.
  */
  virtual CATCDSBoolean Regenerate();

  /**
  * Get defining geometric objects and variables
  * @param oNodes
  *     depend entities
  */
  virtual void GetDependencies(CATCDSLISTP(CATCSEntity) &oNodes);

  /**
  * Check if the object is valid (particulary makes senses for dependent objects)
  * @return
  *    TRUE if the object is properly definied
  *    FALSE if the object is inconsistent, in this case will not be added to the solver by AddGeometry
  */
  virtual CATCDSBoolean IsValid() const;

  /**
   * Checks whether the object is a construction object.
   * @return
   *    TRUE if it is a construction object
   *    FALSE otherwise
   */
  CATCDSBoolean IsConstructionObject();

  /**
   * Set the type of the object (construction objet or not)
   * @param iConstrObj
   *    TRUE to specify construction object
   *    FALSE to specify normal object
   */
  void SetConstruction(CATCDSBoolean iConstrObj);
  
  /**
   * Retrieves a sketch which includes the geometry. There is no need to
   * redefine this method for 3D geometries, but 2D geometries have to
   * redefine it.
   * @return
   *   Pointer to the sketch.
   */
  virtual CATCSSketch const * GetSketch() const CATCDSOverride;
  virtual CATCSSketch * GetSketch() CATCDSOverride;
  
  /**
   * @nodoc
   */
  virtual void SetSketch(CATCSSketch* pSketch);

protected:
  CATCSSketch *_pSketch;
  CATCDSBox * _pBoundingBox;
  CATCDSBoolean _constructionObject;

};

CATCDSLISTP_DECLARE_EXPORTED(CATCSGeometryLeaf, ExportedBySolverInterface);

//-----------------------------------------------------------------------

#endif
