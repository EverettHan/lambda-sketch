// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATIPolyInterference.h
//
//===================================================================
//
// Usage notes:
// Interface describing an interference.
//
//===================================================================
//
// Jul 2009 Creation: JS9
//===================================================================

#ifndef CATIPolyInterference_h
#define CATIPolyInterference_h

#include "CATPolyBoundingVolumeOperators.h"

class CATMapOfBodyFaceToMesh;

/**
 * Interface describing an interference.
 */
class ExportedByCATPolyBoundingVolumeOperators CATIPolyInterference
{
public:

  enum InterferenceType
  {
    NONE,
    CLASH,
    CONTACT,
    CLEARANCE,
    BAND_ANALYSIS,
    COLLISION,
    AREA_CONTACT_MODEL
  };

  virtual ~CATIPolyInterference() {}

  /**
   * Get the type of interference. Might be used to cast the interference to its actual
   * implementing class.
   */
  virtual InterferenceType GetInterferenceType() const = 0;

  /**
   * Get the object from the input which is involved in the interference.
   */
  virtual int GetFirstInterferingObjectId() const = 0;

  /**
   * Get the other object from the input involved in the interference.
   */
  virtual int GetSecondInterferingObjectId() const = 0;

  /**
   * @return the sag of the first object.
   */
  virtual double GetFirstObjectAccuracy() const = 0;

  /**
   * @return the sag of the second object.
   */
  virtual double GetSecondObjectAccuracy() const = 0;

  /**
   * Swap the data of the two interfering objects.
   * First object id become second object id, accuracy are inverted and
   * so are the associated data.
   */
  virtual void SwapInterferingObjects() = 0;

  /**
   * Returns the full list of triangle indices associated with this interference, for first interfering object.
   */
  virtual CATMapOfBodyFaceToMesh* GetFirstInterferingTriangles() = 0;
  /**
   * Returns the full list of triangle indices associated with this interference, for second interfering object.
   */
  virtual CATMapOfBodyFaceToMesh* GetSecondInterferingTriangles() = 0;

protected:

  /**
   * Constructor
   */
  CATIPolyInterference() {}
  
};

#endif // CATIPolyInterference_h

