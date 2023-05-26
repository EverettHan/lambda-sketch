// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuSectionResult.h
//
//===================================================================
// April 2009  Creation: NDO
//===================================================================
#pragma once

#include "PolyVisuClash.h"
#include "CATListPV.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATRep;
class CATRepPath;
class CATPolyPolygon2D;
class CATPolyPolygonVertex3DPositionLayer;
class CATPolyPolygonBarAttributeLayer;
class CATPolyPolygonBar3DBoundingGPLayer;
class CATPolyPolygonBarVizPrimitiveLayer;


// Class encapsulating the results of a planar section of a bag rep operand.
class ExportedByPolyVisuClash CATPolyVisuSectionResult
{

public:

  CATPolyVisuSectionResult ();

  ~CATPolyVisuSectionResult ();

public:

  enum ErrorCode
  {
    eMemoryError  = -1,
    eNoError      = 0,
    eVolumeIsOpen = 1
  };

  enum TypeOfRep
  {
    eRepUnknown = 0,
    eRepWithGraphicPrimitives,
    eRepWithVizPrimitives,
    eRepCanonical
  };

public:

  struct sSectionResult
  {
    const CATRep* _Rep;
    const CATRepPath* _RepPath;
    CATPolyPolygon2D* _Polygon;
    CATPolyPolygonVertex3DPositionLayer* _VertexPositionLayer;
    CATPolyPolygonBarAttributeLayer* _BarPrimitiveLayer;
    TypeOfRep _RepType;
    unsigned int _DomainDimension;
    int _BVHTreeID;
    HRESULT _ReturnedHRBoolean;
    float _GridRange;  // To set exact arithmetic.
  };

public:

  // Return the number of elements in the result.
  inline int GetNbElements () const;

  // Return the number of elements KO in the result.
  inline int GetNbElementsKO () const;

public:

  /*
   * Iterate through the reps and the polygons of the section result.
   */
  class ExportedByPolyVisuClash Iterator
  {
  public:

    inline Iterator (const CATPolyVisuSectionResult& iResult) :
      _Results (iResult._Results), _Count (1), _NbElements (iResult._Results.Size ()) {}

  private:

    inline const sSectionResult& SectionResult () const
    {return *((const CATPolyVisuSectionResult::sSectionResult*) _Results[_Count]);}

  public:

    inline const CATRepPath* GetRepPath () const
      {return SectionResult ()._RepPath;}

    inline const CATRep& GetRep () const
      {return *(SectionResult ()._Rep);}

    inline TypeOfRep GetTypeOfRep () const
      {return SectionResult ()._RepType;}

    // Return the dimension of the domains contained in the 3D rep:
    //   o Wire:  1
    //   o Skin:  2
    //   o Solid: 3
    inline unsigned int GetDomainDimension () const
      {return SectionResult ()._DomainDimension;}

    inline float GetGridRange () const
      {return SectionResult ()._GridRange;}

    inline CATPolyPolygon2D& GetPolygon () const 
      {return *(SectionResult ()._Polygon);}

    inline const CATPolyPolygonVertex3DPositionLayer& GetVertexPositionLayer () const 
      {return *(SectionResult ()._VertexPositionLayer);}

    const CATPolyPolygonBar3DBoundingGPLayer* GetBar3DBoundingGPLayer () const;

    const CATPolyPolygonBarVizPrimitiveLayer* GetBarVizPrimitiveLayer () const;

    inline CATBoolean IsSectionOK () const
      {return SUCCEEDED (SectionResult ()._ReturnedHRBoolean);}

    inline CATBoolean IsVolumeOpen () const
      {return SectionResult ()._ReturnedHRBoolean == E_FAIL;}

    inline int GetBVHTreeID () const
      {return SectionResult ()._BVHTreeID;}

    // DO NOT USE!
    inline const CATPolyPolygonVertex3DPositionLayer& GetPositionLayer () const 
      {return GetVertexPositionLayer ();}

  public:

    inline CATBoolean End () const {return _Count > _NbElements;}
    inline Iterator& operator++ () {++_Count; return *this;}

  private:

    const CATListPV& _Results;
    int _Count;
    int _NbElements;

  };

private:

  CATListPV _Results;
  int _NbKOs;

private:

  friend class CATPolyVisuPlanarSectionOper;

  void AbsorbResult (const CATRep* iRep,
                     const CATRepPath* iRepPath,
                     const int iBVHTreeID,
                     const unsigned int iDomainDimension,
                     const float iGridRange,
                     CATPolyPolygon2D* iPolygon, 
                     CATPolyPolygonVertex3DPositionLayer* iVertexPositionLayer,
                     CATPolyPolygonBar3DBoundingGPLayer* iBarGPPrimitiveLayer,
                     CATPolyPolygonBarVizPrimitiveLayer* iBarVizPrimitiveLayer,
                     const HRESULT iReturnCodeBooleanOper);

};

inline int CATPolyVisuSectionResult::GetNbElements () const
{
  return _Results.Size ();
}

int CATPolyVisuSectionResult::GetNbElementsKO () const
{
  return _NbKOs;
}

