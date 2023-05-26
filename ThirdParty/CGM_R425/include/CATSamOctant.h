// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATSamOctant.h
// Header definition of CATSamOctant
//
//===================================================================
//
// Usage notes : base class for CATSamOctree node
//
//===================================================================
//
//  Feb 2003  Creation: Code generated by the CAA wizard  jup
//===================================================================
#ifndef CATSamOctant_H
#define CATSamOctant_H

#include "CATELFMathKernel.h"

// OS
#include "string.h"

// System
#include "CATBoolean.h"
#include "CATErrorDef.h"

// SpecialAPI
#include "CATDataType.h"

// CATELFMathKernel
class CATSamOctree;
class CATSamOctinfo;
class CATListPtrCAT3DRep;

// Visualization
//class CAT3DCuboidRep;

// VisualizationBase
//class CAT3DBagRep;
//class CAT3DCloudOfPointsRep;

class ExportedByCATELFMathKernel CATSamOctant
{

  friend class CATSamOctree;

public :

  inline const CATULONG32 * GetIndexes () const;
  inline CATULONG32 GetNbEntities () const;
  inline CATULONG32 GetCapacity () const;

  inline const CATSamOctree * GetTree () const;
  inline const CATSamOctant * const * GetChilds () const;
  inline CATULONG32 GetLevel () const;
  inline CATBoolean IsLeaf () const;

  void GetSizes ( double & oXsize, double & oYsize, double & oZsize ) const;
  inline void GetCenter ( double & oXcenter, double & oYcenter, double & oZcenter ) const;
  void GetBoundingBox ( double & oXmin, double & oYmin, double & oZmin,
                        double & oXmax, double & oYmax, double & oZmax ) const;

protected :

  CATSamOctant ();
  virtual ~CATSamOctant ();

  unsigned char GetChildIndex ( const double iX, const double iY, const double iZ ) const;

private :

  double               _Xcenter,
                       _Ycenter,
                       _Zcenter;
  const CATSamOctree * _Tree;
  CATSamOctant **      _Childs;
  CATULONG32 *         _Indexes;
  CATULONG32           _NbEntities; //in OR below this node
  CATULONG32           _Capacity;
  CATULONG32           _Level;

  void Init ( const CATSamOctree & iOctree, const CATSamOctinfo & iOctantInfo );
  void Reset ();

  HRESULT Add ( CATSamOctinfo & iEntityInfo );
  HRESULT AddIndex ( const CATULONG32 iIndex );
  HRESULT AddChild ( const CATSamOctinfo & iUsefulInfo );

  /*HRESULT GetOctantRep ( CAT3DBagRep *& opOctantRep,
                         CATListPtrCAT3DRep * const ipLeafPtReps = NULL,
                         CATListPtrCAT3DRep * const ipLeafBBReps = NULL,
                         CATListPtrCAT3DRep * const * const iapLevelReps = NULL );
  HRESULT GetOctantPtRep ( CAT3DCloudOfPointsRep *& opOctantPtRep ) const;
  HRESULT GetOctantBBRep ( CAT3DCuboidRep *& opOctantBBRep ) const;*/

  CATSamOctant ( const CATSamOctant & iOctant );
  CATSamOctant & operator= ( const CATSamOctant & iOctant );

};

inline const CATULONG32 * CATSamOctant::GetIndexes () const
{
  return ( (const CATULONG32 *) _Indexes );
}

inline CATULONG32 CATSamOctant::GetNbEntities () const
{
  return _NbEntities;
}

inline CATULONG32 CATSamOctant::GetCapacity () const
{
  return _Capacity;
}

inline const CATSamOctree * CATSamOctant::GetTree () const
{
  return ( (const CATSamOctree *) _Tree );
}

inline const CATSamOctant * const * CATSamOctant::GetChilds () const
{
  return ( (const CATSamOctant * const *) _Childs );
}

inline CATULONG32 CATSamOctant::GetLevel () const
{
  return _Level;
}

inline CATBoolean CATSamOctant::IsLeaf () const
{
  return ( NULL == _Childs );
}

inline void CATSamOctant::GetCenter ( double & oXcenter, double & oYcenter, double & oZcenter ) const
{
  oXcenter = _Xcenter; oYcenter = _Ycenter; oZcenter = _Zcenter; 
}

#endif