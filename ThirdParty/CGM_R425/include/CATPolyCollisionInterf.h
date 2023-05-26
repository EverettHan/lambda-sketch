// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCollisionInterf.h
//
//===================================================================
//
// Usage notes:
// Interface describing a clash.
//
//===================================================================
//
// 2010-04-19 Creation: XXC
//===================================================================

#ifndef CATPolyCollisionInterf_h
#define CATPolyCollisionInterf_h

#include "CATErrorDef.h"

// System
class CATMathVector;
#include "CATLISTV_CATMathPoint.h"
#include "CATBoolean.h"
#include "CATMathDirection.h"
#include "CATMathPoint.h"

// Interference
#include "CATPolyInterferenceImpl.h"

/**
 * Interface describing a clash.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyCollisionInterf : public CATPolyInterferenceImpl
{
public:
  class ID
  {
  public:
    static const int _size = 2;
  public:
    ID(int idx0, int idx1)
    {
      _Idx[0] = idx0, _Idx[1] = idx1;
    }
    ID(const ID & id)
    {
      _Idx[0] = id._Idx[0], _Idx[1] = id._Idx[1];
    }

    ~ID(){}

    const int * Get() const {
      return _Idx;
    }
    
    bool operator == (const ID & iIndex) const {
      return (!memcmp((const void *) _Idx, (const void *) iIndex._Idx, sizeof(int) * ID::_size));
    }
    bool operator != (const ID & iIndex) const {
      return (!!memcmp((const void *) _Idx, (const void *) iIndex._Idx, sizeof(int) * ID::_size));
    }
    bool operator < (const ID & iIndex) const {
      return (memcmp((const void *) _Idx, (const void *) iIndex._Idx, sizeof(int) * ID::_size) < 0);
    }
    bool operator > (const ID & iIndex) const {
      return (memcmp((const void *) _Idx, (const void *) iIndex._Idx, sizeof(int) * ID::_size) > 0);
    }

    INLINE void Swap()
    {
      int i, ii, tmp, size = ID::_size/2;
      for (i = 0; i < size; i++) {
        ii       = size+i  ;
        tmp      = _Idx[i ];
        _Idx[i ] = _Idx[ii];
        _Idx[ii] = tmp     ;
      }
    }

  private:
    int _Idx[ID::_size];
  };

  struct ContactPoint
  {
    ContactPoint(CATPolyCollisionInterf::ID id, double x, double y, double z, const CATMathVector & iNormal, double iDepth)
      : _Id(id), _Point(x,y,z), _Normal(iNormal), _Depth(iDepth) {}
    ContactPoint(CATPolyCollisionInterf::ID id, const CATMathPoint & point, const CATMathVector & iNormal, double iDepth)
      : _Id(id), _Point(point), _Normal(iNormal), _Depth(iDepth) {}
    const ContactPoint & operator = (const ContactPoint & point) {
      _Id = point._Id;
      _Point = point._Point;
      return *this;
    }
    ID _Id;
    CATMathPoint _Point;
    CATMathVector _Normal;
    double _Depth;
  };

public:

  /**
   * Constructor and destructor
   */
  CATPolyCollisionInterf(int firstObjId, int secondObjId,
                         double firstObjectAccuracy, double secondObjectAccuracy);
  virtual ~CATPolyCollisionInterf();

  /**
   * Get the type of interference. Might be used to cast the interference to its actual
   * implementing class.
   */
  virtual InterferenceType GetInterferenceType() const;

  /**
   * Set whether the collision is caused by an inclusion
   * or a surfacic clash.
   */
  void SetIsInclusionCollision(CATBoolean isInclusion);

  /**
   * To know whether the collision is due to an inclusion
   * or because surfaces intersect.
   */
  CATBoolean IsInclusionCollision() const;

  /**
   * Get the number of contact points in the interference.
   */
  unsigned int NumberOfContactPoints() const;

  unsigned int NumberOfWarningPoints() const;

  /**
   * Get the contact point with the given index. Valid indices are in
   * the range 1 to NumberOfContactPoints() included.
   * @return E_FAIL if the point does not exist, S_OK otherwise.
   */
  HRESULT GetContactPoint(const unsigned int iIndex, const ContactPoint *& point) const;
  HRESULT GetContactPoint(const unsigned int iIndex, CATMathPoint & point) const;

  HRESULT GetWarningPoint(const unsigned int iIndex, const ContactPoint *& point) const;
  HRESULT GetWarningPoint(const unsigned int iIndex, CATMathPoint & point) const;

  /**
   * Add a contact point to the collision data. Only supposed to be
   * used inside the collision detection operator, during the
   * interference computation process. Note that the contact point
   * lifecycle is managed by the interference itself as the point has
   * been added into it.
   */
  void AddContactPoint(ContactPoint * iContactPoint);

  void AddWarningPoint(ContactPoint * iContactPoint);

  /**
   * Get Penetration values
   */
  void GetPenetrationData(double & oPenetrationValue, CATMathVector & oPenetrationVector) const;

  virtual void SwapInterferingObjects();

private:

  friend class CATPolyCollisionInterfBuilder;

private:
  double _Depth;
  CATBoolean _open2read;
  CATMathVector _Penetration;

  //--------------------------------------------------------
  CATBoolean _IsInclusion;
  CATListPV _ContactPoints;
  CATListPV _WarningPoints;
};

#endif // CATPolyCollisionInterf_h

