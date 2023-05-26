// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterferenceImpl.h
//
//===================================================================
//
// Usage notes:
// Class implementing some of the functions of CATIPolyInterference.
//
//===================================================================
//
// Sep 2009 Creation: JS9
//===================================================================

#ifndef CATPolyInterferenceImpl_h
#define CATPolyInterferenceImpl_h

#include "CATIPolyInterference.h"
#include "CATPolyBoundingVolumeOperators.h"

/**
 * Class implementing some of the functions of CATIPolyInterference.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyInterferenceImpl : public CATIPolyInterference
{
public:

  virtual ~CATPolyInterferenceImpl();

  /**
   * Get the type of interference. Might be used to cast the interference to its actual
   * implementing class.
   */
  virtual InterferenceType GetInterferenceType() const;

  /**
   * Get the object from the input which is involved in the interference.
   */
  virtual int GetFirstInterferingObjectId() const;

  /**
   * Get the other object from the input involved in the interference.
   */
  virtual int GetSecondInterferingObjectId() const;

  /**
   * @return the sag of the first object.
   */
  virtual double GetFirstObjectAccuracy() const;

  /**
   * @return the sag of the second object.
   */
  virtual double GetSecondObjectAccuracy() const;

  /**
   * Swap the data of the two interfering objects.
   * First object id become second object id, accuracy are inverted and
   * so are the associated data.
   */
  virtual void SwapInterferingObjects();

  virtual CATMapOfBodyFaceToMesh* GetFirstInterferingTriangles();
  virtual CATMapOfBodyFaceToMesh* GetSecondInterferingTriangles();
  void SetFirstInterferingTriangles(CATMapOfBodyFaceToMesh* pMap);
  void SetSecondInterferingTriangles(CATMapOfBodyFaceToMesh* pMap);

protected:

  /**
   * Constructor
   */
  CATPolyInterferenceImpl(int firstObjId, int secondObjId,
                          double firstObjectAccuracy, double secondObjectAccuracy);

  // Update the accuracies of the interference
  // by getting the max of the current ones and the given ont
  void UpdateAccuracy(CATIPolyInterference & otherInterf);

private:

  int _iFirstObjId;
  int _iSecondObjId;
  double _dFirstObjAccuracy;
  double _dSecondObjAccuracy;
  
  CATMapOfBodyFaceToMesh* m_Map1;
  CATMapOfBodyFaceToMesh* m_Map2;
};

#endif // CATPolyInterferenceImpl_h

