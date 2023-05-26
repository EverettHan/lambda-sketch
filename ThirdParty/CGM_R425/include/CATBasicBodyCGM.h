/* -*-c++-*- */
#ifndef CATBasicBodyCGM_H
#define CATBasicBodyCGM_H

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATBasicBodyCGM:
// Base class for implementations of the CATBasicBodyCGM basic CATBody
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// June 98   Creation                                     M. Prince
//=============================================================================
#include "YJ000GSM.h"                  // For Windows
#include "CATBaseUnknown.h"
#include "CATIBasicBodyFactory.h"
#include "CATTopDef.h"

#include "ListPOfCATVertex.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATBody.h"
#include "CATListOfCATGeometries.h"

class CATBody;
class CATShell;
class CATWire;
class CATLoop;
class CATVertexInFace;
class CATVertexInVolume;
class CATCGMJournalList;

class CATFace;
class CATEdge;
class CATVertex;

class CATGeoFactory;
class CATPoint;
class CATCurve;
class CATSurface;
class CATPlane;
class CATSurParam;
class CATCrvParam;
class CATSoftwareConfiguration;

class CATMathDirection2D;

class CATMathSetOfVectors;
class CATTopData;
class CATError;

#define BasicBodyPolyCompliant // DPS, December 15th 2016 



class ExportedByYJ000GSM CATBasicBodyCGM : public CATBaseUnknown
{
  public:
  //-------------------------------------------------------------------------
  //- Constructors
  //-------------------------------------------------------------------------
  CATBasicBodyCGM ();
  virtual  ~CATBasicBodyCGM ();

/** 
 * @nodoc
 * Defines the Software configuration to be taken 
 * into acccount by <tt>this</tt> operator.
 * @param iConfig
 * The Software configuration.
 */
  virtual void SetSoftwareConfiguration(CATSoftwareConfiguration* iConfig);

/** 
 * @nodoc
 * Returns the Software configuration to be taken 
 * into acccount by <tt>this</tt> operator.
 * @return
 * The Software configuration.
 */
  virtual CATSoftwareConfiguration* GetSoftwareConfiguration() const;
  //-------------------------------------------------------------------------
  CATBasicBodyCGM ( const CATGeoFactory                             *Factory,
                    const CATVertex                                 *Origin,
                    const CATEdge                                   *Curve,
                    const CATFace                                   *Support,
                    const CATLength                                 *ParamValue,
                    const CATLength                                 *Start,
                    const CATLength                                 *End,
                    const CATOrientation                             Orientation,
                    const CATIBasicBodyFactory::CATIBasicBodyGeoType GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyCGM ( const CATGeoFactory                             *Factory,
                    const CATVertex                                 *StartPoint,
                    const CATVertex                                 *EndPoint,
                    const CATFace                                   *Support,
                    const CATLength                                 *ParamValue,
                    const CATLength                                 *Start,
                    const CATLength                                 *End,
                    const CATOrientation                             Orientation,
                    const CATIBasicBodyFactory::CATIBasicBodyGeoType GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyCGM ( const CATGeoFactory                             *Factory,
                    const CATVertex                                 *FirstPoint,
                    const CATVertex                                 *SecondPoint,
                    const CATVertex                                 *ThirdPoint,
                    const CATFace                                   *Support,
                    const CATLength                                 *ParamValue,
                    const CATLength                                 *Start,
                    const CATLength                                 *End,
                    const CATOrientation                             Orientation,
                    const CATIBasicBodyFactory::CATIBasicBodyGeoType GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyCGM ( const CATGeoFactory       *Factory,
                    const CATVertex           *Origin,
                    const CATEdge             *FirstCurve,
                    const CATEdge             *SecondCurve,
                    const CATLength           *ParamValue,
                    const CATOrientation       Orientation );

  //-------------------------------------------------------------------------
  CATBasicBodyCGM ( const CATGeoFactory                              *Factory,
                    const CATBody                                    *FirstBody,
                    const CATBody                                    *SecondBondy,
                    const CATBody                                    *ThirdBody,
                    const CATBody                                    *Support,
                    const CATLength                                  *ParamValue,
                    const CATLength                                  *Start,
                    const CATLength                                  *End,
                    const CATOrientation                              Orientation,
                    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyCGM ( const CATGeoFactory                              *Factory,
                    const CATBody                                    *FirstBody,
                    const CATBody                                    *SecondBondy,
                    const CATBody                                    *ThirdBody,
                    const CATLength                                  *ParamValue,
                    const CATLength                                  *Start,
                    const CATLength                                  *End,
                    const CATOrientation                              Orientation,
                    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyCGM ( const CATGeoFactory                              *Factory,
                    const CATLISTP(CATVertex)                        *Points,
                    const CATMathSetOfVectors                        *Vectors,
                    const CATFace                                    *Support,
                    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyCGM ( const CATGeoFactory                              *Factory,
                    const CATLISTP(CATBody)                          *Points,
                    const CATMathSetOfVectors                        *Vectors,
                    const CATBody                                    *Support,
                    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyCGM ( const CATGeoFactory       *Factory,
                    const CATLength            A,
                    const CATLength            B,
                    const CATLength            C,
                    const CATLength            D,
                    const CATOrientation       Orientation );

  //-------------------------------------------------------------------------
  //- Initialization
  //-------------------------------------------------------------------------
  void InitMembers();
  void InitBodies();
  void InitBodies( CATBody *iBody );
  void CheckInitialisation();

  //-------------------------------------------------------------------------
  //- CreateBasicBody
  //-------------------------------------------------------------------------

  virtual CATBody * CreateBasicBody( CATTopData * iTopData,
                                     CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType ) = 0;

  /** nodoc
  * Deprecated
  */
  virtual CATBody * CreateBasicBody( CATCGMJournalList *oJournal,
                                     CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType );

  //-------------------------------------------------------------------------
  //- Internal methodes
  //-------------------------------------------------------------------------
  protected:
  //=========================================================================
  //- Get vertices from higher topology 
  //=========================================================================
  void GetVertices ( const CATVertex *iVertex,
                     CATLISTP(CATVertex) *&oVertexList ) const;

  void GetVertices ( const CATBody *iBody,
                     CATLISTP(CATVertex) *&oVertexList ) const;

  //=========================================================================
  //- Get edges from the higher dimension topology
  //- The oSides specify the side of each edge according to the domain or body  
  //=========================================================================
  void GetEdges ( const CATEdge *iEdge, CATLISTP(CATEdge) *&oEdgeList,
                  CATSide *&oSides ) const;


  void GetEdges ( const CATBody *iBody, CATLISTP(CATEdge) *&oEdgeList,
                  CATSide *&oSides ) const;

  //=========================================================================
  //- Get faces from the higher dimension topology
  //- The oSides specify the side of each face according to the domain or body  
  //=========================================================================
  void GetFaces ( const CATFace *iFace, CATLISTP(CATFace) *&oFaceList,
                  CATSide *&oSides) const;
  void GetFaces ( const CATBody *iBody, CATLISTP(CATFace) *&oFaceList,
                  CATSide *&oSides) const;

  //=========================================================================
  //- Get directions from Vertex on Edge or Face
  //=========================================================================
  void GetTangentDirection ( CATLISTP(CATEdge) *iEdgeList,
    CATTopData * iData,
                             CATSide *iEdgeSides,
                             CATVertex *iVertex,
                             CATMathDirection &oTangent,
                             CATEdge *&oEdgeOn,
                             CATIBasicBodyFactory::CATIBasicBodyResultType *oResult = NULL,
                             CATMathPoint *oPointOnEdge = NULL,
                             CATCrvParam  *CrvParam = NULL );

  void GetNormalDirection ( CATTopData * iData, CATLISTP(CATFace) *iFaceList,
                            CATSide *iFaceSides,
                            CATVertex *iVertex,
                            CATMathDirection &oNormal,
                            CATFace *&oFaceOn,
                            CATIBasicBodyFactory::CATIBasicBodyResultType *oResult = NULL,
                            CATMathPoint *oPointOnFace = NULL,
                            CATSurParam *oSurParam = NULL );

  CATMathDirection2D Get2DVectorOnSurface( CATTopData * iData,
                                           const CATMathVector &iVector,
                                           const CATSurface *iSurface,
                                           const CATSurParam &iSurParam,
                                           double *o2DVector = NULL );

  //=========================================================================
  //- Create a body from a curve
  //=========================================================================
  CATBody * CreateBody ( CATCurve *iCurve,
                         CATCGMJournalList *Journal = NULL );

  CATBody * CreateBody ( CATCurve *iCurve,
                         CATTopData* iTopData);

  //=========================================================================
  //- Create a body from a Plane
  //=========================================================================
  CATBody * CreateBody ( CATPlane *iPlane,
                         CATCGMJournalList *Journal = NULL );

  CATBody * CreateBody ( CATPlane *iPlane,
                         CATTopData* iTopData);

  void ReportCreWire(CATBody*,CATCGMJournalList*);
  void FindReportCells(CATBody* iWireBody,CATLISTP(CATGeometry)& oEdges, 
                 CATGeometry*& oFreeStartVertex, CATGeometry*& oFreeEndVertex);

  //=========================================================================
  //- Clean up memory 
  //=========================================================================
  void CleanInternalData();

  //=========================================================================
  //- Internal Data 
  //=========================================================================
  CATGeoFactory                                *_Factory;
  CATError                                     *_StockErr;
  CATLISTP(CATVertex)                          *_Vertices;
  CATLISTP(CATBody)                            *_Bodies;
  CATMathSetOfVectors                          *_Vectors;
  CATLength                                    *_ParamValue;
  CATLength                                    *_Start;
  CATLength                                    *_End;
  CATLength                                    *_D;
  CATOrientation                                _Orientation;
  CATOrientation                                _Orientation2;
  CATIBasicBodyFactory::CATIBasicBodyGeoType    _GeoType;

  //- remplacement pour _Curve et _Support afin de prendre en compte les elements
  CATLISTP(CATVertex)                          *_VertexList1;
  CATLISTP(CATVertex)                          *_VertexList2;
  CATLISTP(CATVertex)                          *_VertexList3;
  CATLISTP(CATEdge)                            *_EdgeList1;
  CATSide                                      *_EdgeSides1;
  CATLISTP(CATEdge)                            *_EdgeList2;
  CATSide                                      *_EdgeSides2;
  CATLISTP(CATEdge)                            *_EdgeList3;
  CATSide                                      *_EdgeSides3;
  CATLISTP(CATFace)                            *_FaceList;
  CATSide                                      *_FaceSides;
  CATBody                                      *_SupportBody;
  CATBody                                      *_WireBody1;
  CATBody                                      *_WireBody2;
  CATBody                                      *_WireBody3;
  CATBody                                      *_VertexBody1;
  CATBody                                      *_VertexBody2;
  CATBody                                      *_VertexBody3;
  CATBody                                      *_ShellBody;
  CATSoftwareConfiguration * _CodeVersion;
		/** @nodoc */
  CATLONG32 _ImposedVersion;
		/** @nodoc */
  virtual CATSoftwareConfiguration* GetConfig();
};


#endif

