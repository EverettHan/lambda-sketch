/* -*-C++-*- */

#ifndef CATPointOnNuplet_H
#define CATPointOnNuplet_H

// COPYRIGHT DASSAULT SYSTEMES 1997

//===================================================================
//===================================================================
//
// CATPointOnNuplet
// Class defining a point on each track of an N-uplet
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// July. 97    Creation                         A. State
//===================================================================
//===================================================================

#include "CATMathDef.h"
#include "CATCGMNewArray.h"
#include "CATCrvParam.h"
#include "ListPOfCATPointOnNuplet.h"
#include "ExportedByRIBLight.h"

class CATCurve;
class CATEdgeCurve;

class CATVertex;
class CATEdge;
class CATFace;

class CATTopRibSupport;
class CATTopRibGeoNuplet;
class CATArrayOfPointOnSupport;

class ExportedByRIBLight CATPointOnNuplet
{
 public:

  //------------------------------------------------------------------------------
  // Default constructor
  //------------------------------------------------------------------------------
  CATPointOnNuplet();

  CATCGMNewClassArrayDeclare; // Pool allocation

  // copy constructor not implemented
  private:
  CATPointOnNuplet(CATPointOnNuplet &iPointOnNuplet);  

  // Affectation operator. Not implemented
  private:
  CATPointOnNuplet& operator=(const CATPointOnNuplet &iPointOnNuplet);

  //------------------------------------------------------------------------------
  // Constructor with PointOnSupport array
  //------------------------------------------------------------------------------
  public:
  CATPointOnNuplet(CATLONG32                      iNbSupp,
                   CATArrayOfPointOnSupport *iPointOnSupportArray,
                   CATLONG32                      iPointIndex,
                   CATTopRibGeoNuplet       *iGeoNuplet);

  //------------------------------------------------------------------------------
  // Merge
  //------------------------------------------------------------------------------
  // CATPointOnNuplet(CATPointOnNuplet *iFirstPointOnNuplet, CATPointOnNuplet *iSecondPointOnNuplet);

  void MergeWith(CATPointOnNuplet &SecondPointOnNuplet);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  virtual ~CATPointOnNuplet();

  //------------------------------------------------------------------------------
  // Write data in a PointOnNuplet
  //------------------------------------------------------------------------------

  /*
  Unused methods!!!
  virtual void SetCrvParamOnTrack (CATCrvParam             iCrvParamOnTrack);

  virtual void SetPointOnSupport  (CATTopRibSupport       *iSupport,
                                   CATLONG32                    iSupportIndex,
                                   CATCurve               *iCurve,
                                   CATVertex              *iVertex,
                                   CATEdge                *iEdgeToCut);
  */

  //------------------------------------------------------------------------------
  // Set a point on support
  //
  // Please note: 1) iSupportIndex varies between 1 and _NbSupp
  //              2) iLeftEdge and iRightEdge are such that the vertex
  //                 to store is at the start of iRightEdge and at the
  //                 end of iLeftEdge
  //              3) One of the two edges may be NULL
  //------------------------------------------------------------------------------
  virtual void SetPointOnSupport (CATTopRibSupport       *iSupport,
                                  CATLONG32                    iSupportIndex,
                                  CATEdge                *iLeftEdge,
                                  CATEdge                *iRightEdge,
                                  CATEdgeCurve           *iCurve);

  //------------------------------------------------------------------------------
  // Set a vertex on a support
  //
  // Please note: iSupportIndex varies between 1 and _NbSupp
  //------------------------------------------------------------------------------
  void SetVertex (CATLONG32       iSupportIndex,
                  CATVertex *iVertex);

  //------------------------------------------------------------------------------
  // Set an Edge to be cut on a support
  //
  // Please note: iSupportIndex varies between 1 and _NbSupp
  //------------------------------------------------------------------------------
  void SetEdgeToCut (CATLONG32     iSupportIndex,
                     CATEdge *iEdgeToCut);

  //------------------------------------------------------------------------------
  // Set the next Edge after the point ("next" meaning in the sense of
  // growing parameter values)
  //
  // Please note: iSupportIndex varies between 1 and _NbSupp
  //------------------------------------------------------------------------------
  void SetNextEdge (CATLONG32     iSupportIndex,
                    CATEdge *iNextEdge);

  //------------------------------------------------------------------------------
  // Set a Support
  //
  // Please note: iSupportIndex varies between 1 and _NbSupp
  //------------------------------------------------------------------------------
  void SetSupport (CATLONG32              iSupportIndex,
                   CATTopRibSupport *iSupport);

  //------------------------------------------------------------------------------
  // Get a vertex on a support
  //
  // Please note: iSupportIndex varies between 1 and _NbSupp
  //------------------------------------------------------------------------------
  CATVertex *GetVertex (CATLONG32 iSupportIndex);

  //------------------------------------------------------------------------------
  // Get an Edge to be cut on a support
  //
  // Please note: iSupportIndex varies between 1 and _NbSupp
  //------------------------------------------------------------------------------
  CATEdge *GetEdgeToCut (CATLONG32 iSupportIndex);

  //------------------------------------------------------------------------------
  // Get the next Edge after the point ("next" meaning in the sense of
  // growing parameter values)
  //
  // Please note: iSupportIndex varies between 1 and _NbSupp
  //------------------------------------------------------------------------------
  CATEdge *GetNextEdge (CATLONG32 iSupportIndex);

  //------------------------------------------------------------------------------
  // Get a Support
  //
  // Please note: iSupportIndex varies between 1 and _NbSupp
  //------------------------------------------------------------------------------
  CATTopRibSupport *GetSupport (CATLONG32 iSupportIndex);

  //------------------------------------------------------------------------------
  // Get the number of supports
  //------------------------------------------------------------------------------
  CATLONG32 GetNumberOfSupports ();

  //------------------------------------------------------------------------------
  // Get the index of the support on which the point is defined
  //------------------------------------------------------------------------------
  CATLONG32 GetSupportIndex ();

  void GetCrvParamOnTrack(CATCrvParam &oCrvParamOnTrack) const;

  void SetCrvParamOnTrack(const CATCrvParam &iCrvParamOnTrack);

  //------------------------------------------------------------------------------
  // Global method for comparison of two PointOnNuplet objects
  //------------------------------------------------------------------------------
  static int Compare2PointOnNuplet ( CATPointOnNuplet *iFirstPointOnNuplet, CATPointOnNuplet *iSecondPointOnNuplet);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------

  private: 

    CATLONG32                      _NbSupp;
    CATArrayOfPointOnSupport      *_PointOnSupportArray;
    CATLONG32                      _PointIndex;
    CATLONG32                      _SupportIndex;
    // NB: _SupportIndex indicates where the support on which the vertex was
    //     created is stored in the _Support list (i.e. between 1 and _NbSupp);
    //     a PointOnNuplet resulting from the merge of two different Nuplets will
    //     therefore always have _SupportIndex = 0

  CATCrvParam          _CrvParamOnTrack;
  CATTopRibGeoNuplet * _GeoNuplet; 

};


//------------------------------------------------------------------------------
// Global function for the merge of a given number of points in a list of
// points on N-uplet into only one point on N-uplet
//------------------------------------------------------------------------------
ExportedByRIBLight void MergePointsIntoOne (ListPOfCATPointOnNuplet  &PointOnNuplet,
			                                      int                       InitialIndex,
                                            int                       NumberOfPointsToMerge);

#endif
