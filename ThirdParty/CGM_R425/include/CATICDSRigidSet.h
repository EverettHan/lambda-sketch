#ifndef CATICDSRigidSet_H
#define CATICDSRigidSet_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeometry.h"

class CATICDSFactory;
class CATICDSGeometryLeaf;
class CATICDSSketch;

class ExportedByCDSInterface CATICDSRigidSet : public CATICDSGeometry
{
public:
  
  /**
   * Add a geometry in the rigid set.
   * @param ipGeometry.
   *     A pointer to the geometry to add
   * @return
   *   0 - if the function succeeded
   *   1 - if arguments are invalid
   */
  virtual int AddGeometry(CATICDSGeometryLeaf *ipGeometry) = 0;

  /**
   * Add a geometry from the rigid set.
   * @param ipGeometry
   *     A pointer to the geometry to remove.
   * @return
   *   0 - if the function succeeded
   *   1 - if arguments are invalid
   */
  virtual int RemoveGeometry(CATICDSGeometryLeaf *ipGeometry) = 0;

  /**
   * Get the list of geometries in the rigid set.
   * @param onGeometries
   *     The number of geometries in the rigid set.
   * @param oaGeometries
   *     The array of pointers to the geometries in the rigid set (allocated by this method).
   *
   * @SIZE oapGeometries onGeometries
   */
  virtual void GetGeometries(int &onGeometries, CATICDSGeometryLeaf **&oapGeometries) const = 0;

  /**
   * Get the number of geometries in the rigid set
   * @return
   *     The number of geometries in the rigid set
   */
  virtual int GetNbOfGeometries() const = 0;

  /**
   * Creates an instance of the CATICDSRigidSet constraint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   */
  static CATICDSRigidSet* Create(CATICDSFactory *ipFactory);
    
  virtual ~CATICDSRigidSet() {}
};

#endif
