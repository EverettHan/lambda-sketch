#ifndef __CATLengthFromBodyOnWireImpl_h__
#define __CATLengthFromBodyOnWireImpl_h__

#include "CATLengthFromBodyOnWire.h"

//=============================================================================
// Creation YL3   02 2011
//
// Protected Interface de l'Operator LengthFromBodyOnWire pour CGMReplay 
//=============================================================================

class CATLengthFromBodyOnWireImpl : public CATLengthFromBodyOnWire
{
public:

  //============================
  // Constucteur et destructeurs
  //============================
  CATLengthFromBodyOnWireImpl( CATGeoFactory      * iFactory,
                               CATTopData         * iData,
                               CATVertex          * iVertex1, 
                               CATVertex          * iVertex2,
                               CATWire            * iWire);

   CATLengthFromBodyOnWireImpl( CATGeoFactory     * iFactory,
                               CATVertex          * iVertex1, 
                               CATVertex          * iVertex2,
                               CATWire            * iWire);

   CATLengthFromBodyOnWireImpl( CATGeoFactory     * iFactory,
                               CATTopData         * iData,
                               CATBody            * iVertex1, 
                               CATBody            * iVertex2,
                               CATBody            * iWire);

   CATLengthFromBodyOnWireImpl( CATGeoFactory     * iFactory,
                               CATBody            * iVertex1, 
                               CATBody            * iVertex2,
                               CATBody            * iWire);

  ~CATLengthFromBodyOnWireImpl();

  static const  CATString  *GetDefaultOperatorId();

  int RunOperator();
  int Run();


// Move the methodes of CATLengthFromBodyOnWire here! 
//--------------------------------------------------------
#if  defined  (  CATIACGMV5R21  )

// Methodes de CAA
  CATLength   GetDistance( CATMathPoint * iMathPoint1 = NULL, CATMathPoint *iMathPoint2 = NULL) const;
  void        SetVertices( CATVertex    * iNewVertex1, CATVertex * iNewVertex2 );
  void        SetVertices( CATBody      * iNewVertex1, CATBody   * iNewVertex2 );
  void        SetEdge    ( CATEdge      * iNewEdge );
  void        SetEdge    ( CATBody      * iNewEdge );

// Methodes private
  CATVertex * GetVertexFromBody  ( CATBody  **iBody );
  void        FillEdgesAndOrientationsFromWire( CATWire **iEdge );
  void        RunNoEdge          ();
  void        RunWithEdges       ();
  void        GetVertexOnEdge    ( CATVertex    * iVertex,
                                   CATMathPoint & oTheResultingPoint,
                                   CATCrvParam  & oTheResultingParam,
                                   int          & EdgePos );
  void        GetEdgeLimits      ( int            iEdgePos, 
                                   CATCrvParam &StartParam, 
                                   CATCrvParam &EndParam );

  int         MoveToNextEdge     ( int         & oEdgePos  );
  double      ComputeLengthOnEdge( int         & oEdgePos  ,
                                   CATCrvParam & StartParam,
                                   CATCrvParam & EndParam  );
  void SetInternalData();

#endif

protected:
   const  CATString                *  GetOperatorId      ();
   void                               RequireDefinitionOfInputAndOutputObjects();
  CATExtCGMReplay                  *  IsRecordable       (short &LevelOfRuntime, short &VersionOfStream);
  void                                WriteInput         (CATCGMStream  & Str);
  CATBoolean                          ValidateTopOutput  (CATTopCheckJournal* iEquivalent,CATCGMOutput& os);
  void                                WriteOutput        (CATCGMStream &Str);
  CATBoolean                          ReadReferenceOutput(CATCGMStream &Str);
  void                                DumpOutput         (CATCGMStream &Str, CATCGMOutput &os, int VersionNumber);
  CATBoolean                          ValidateOutput     (CATCGMStream &Str, CATCGMOutput &os, int VersionNumber);
  CATCGMOperator::CATCheckDiagnostic  CheckOutput        (CATCGMOutput &os);

  static  CATString     _OperatorId;
  short                 _itp;
  short                 _NbInput; // pour le cas : _Wire est NULL

  // reference result
  CATLength             _RefResult;
  CATMathPoint          _RefMPt1;
  CATMathPoint          _RefMPt2;
  CATBody             * _BodyVertex1;
  CATBody             * _BodyVertex2;
  CATBody             * _BodyWire;
 
#if  defined  (  CATIACGMV5R21  )
  //- Input data
  CATTopData            _TopData;
  CATGeoFactory       * _Factory;
  CATVertex           * _Vertex1,
                      * _Vertex2;
  CATWire             * _Wire;
  CATLISTP(CATEdge)     _Edge;
  CATSide             * _EdgeSides;

  //- Internal Data;
  CATCrvParam          _StartParam;
  int                  _StartEdgePos;
  CATCrvParam          _EndParam;
  int                  _EndEdgePos;

  //- _Direction must have the values : 
  //-  "1" : for increasing;
  //-  "-1": for decreasing:
  //-  "0" " for vertex on same edge or closed wire.
  int                  _Direction;

  

  //- Computed data
  CATLength           _Result;
  CATMathPoint        _MPt1;
  CATMathPoint        _MPt2;
#endif
};

#endif

