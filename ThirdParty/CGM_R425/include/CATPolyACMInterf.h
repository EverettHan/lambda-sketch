// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyACMInterf.h
//
//===================================================================
//
// Usage notes:
// Interface describing an area contact model interference.
//
//===================================================================


#ifndef CATPolyACMInterf_h
#define CATPolyACMInterf_h

#include "CATErrorDef.h"

// System
class CATMathVector;
#include "CATLISTV_CATMathPoint.h"
#include "CATBoolean.h"
#include "CATMathDirection.h"
#include "CATMathPoint.h"

// Interference
#include "CATPolyInterferenceImpl.h"

class CATPolyBoxf;

/**
 * Interface describing a clash.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyACMInterf : public CATPolyInterferenceImpl
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

  struct Triangle
  {
    Triangle(double iX1, double iY1, double iZ1, 
            double iX2, double iY2, double iZ2, 
            double iX3, double iY3, double iZ3, CATBoolean iIsSplit = FALSE, int iMeshIdx = -1)
    {
      X[0] = iX1; X[1] = iX2; X[2] = iX3;
      Y[0] = iY1; Y[1] = iY2; Y[2] = iY3;
      Z[0] = iZ1; Z[1] = iZ2; Z[2] = iZ3;
      _IsSplit = iIsSplit;
      _meshIdx = iMeshIdx;
      ComputeArea();
    }
    Triangle(const Triangle& iT)
    {
      X[0] = iT.X[0]; X[1] = iT.X[1]; X[2] = iT.X[2];
      Y[0] = iT.Y[0]; Y[1] = iT.Y[1]; Y[2] = iT.Y[2];
      Z[0] = iT.Z[0]; Z[1] = iT.Z[1]; Z[2] = iT.Z[2];
      _Area = iT._Area;
      _IsSplit = iT._IsSplit;
      _meshIdx = iT._meshIdx;
    }
 
    void ComputeArea()
    {
      double R1[3];
      double R2[3];
      double Prod[3];
      R1[0] = X[1] - X[0];
      R1[1] = Y[1] - Y[0];
      R1[2] = Z[1] - Z[0];
      R2[0] = X[2] - X[0];
      R2[1] = Y[2] - Y[0];
      R2[2] = Z[2] - Z[0];

      Prod[0] = R1[1] * R2[2] - R1[2] * R2[1];
      Prod[1] = R1[0] * R2[2] - R1[2] * R2[0];
      Prod[2] = R1[0] * R2[1] - R1[1] * R2[0];

      _Area = 0.5*sqrt(Prod[0]*Prod[0] + Prod[1]*Prod[1] + Prod[2]*Prod[2]);

    }

    double X[3];
    double Y[3];
    double Z[3];
    double _Area;
    CATBoolean _IsSplit;
    int _meshIdx;

  };


public:

  /**
   * Constructor and destructor
   */
  CATPolyACMInterf(int firstObjId, int secondObjId,
                         double firstObjectAccuracy, double secondObjectAccuracy);
  virtual ~CATPolyACMInterf();

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
   * Get the number of triangles in the interference.
   */
  unsigned int NumberOfTrianglesFirstObject() const;
  unsigned int NumberOfTrianglesSecondObject() const;
  double GetAreaFirstObject() const;
  double GetAreaSecondObject() const;
  int GetNbGroupsFirstObject() const;
  int GetNbGroupsSecondObject() const;
  const CATPolyBoxf* GetGroupFirstObject(int iIdx) const;
  const CATPolyBoxf* GetGroupSecondObject(int iIdx) const;

  const Triangle* GetTriangleFirstObject(int iIdx) const;
  const Triangle* GetTriangleSecondObject(int iIdx) const;

  /**
   * Add triangles. Only supposed to be
   * used inside the collision detection operator, during the
   * interference computation process.
   */
  void AddTriangleFirstObject(const Triangle& iTri);

  void AddTriangleSecondObject(const Triangle& iTri);

  void AddGroupFirstObject(const CATPolyBoxf& iBox);
  void AddGroupSecondObject(const CATPolyBoxf& iBox);

  virtual void SwapInterferingObjects();

private:

  friend class CATPolyACMInterfBuilder;

private:
  double _AreaFirstObject;
  double _AreaSecondObject;

  //--------------------------------------------------------
  CATBoolean _IsInclusion;
  CATListPV _TrianglesFirstObject;
  CATListPV _TrianglesSecondObject;
  CATListPV _GroupsFirstObject;
  CATListPV _GroupsSecondObject;
};

#endif // CATPolyACMInterf_h

