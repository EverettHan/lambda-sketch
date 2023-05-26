#ifndef CATBodyFromLength_h
#define CATBodyFromLength_h

// COPYRIGHT DASSAULT SYSTEMES  1999


/*#include "YJ000GSM.h"
#include "CATBaseUnknown.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATEdge.h"
#include "CATSkillValue.h"
#include "CATMathDef.h"
#include "CATCGMJournalList.h"
#include "CATCrvParam.h"
#include "CATTopDef.h"

class CATWire;
class CATVertex;
class CATBody;
class CATPoint;
class CATGeoFactory;
class CATCGMJournalList;
class CATTopData;

//-class CATCrvParam;
class CATEdgeCurve;
//- class CATOrientation; */
/**
 * Use @href CATTopPointOperator.
 */
/*class ExportedByYJ000GSM CATBodyFromLength :public CATBaseUnknown
{
public:
 
  enum CATLengthType 
  { 
    ABSOLUTE_L = 0, 
    RELATIVE_L = 1 
  };

 
  CATBodyFromLength( CATGeoFactory*  iFactory,
                     CATTopData*     iTopData,
                     CATWire*        aWire, 
                     CATVertex*      aVertex,
                     CATLength       aDistance,
                     CATLengthType   type = ABSOLUTE_L,
                     CATSkillValue   modev = BASIC);
*/
  /**
   * @nodoc
   * Deprecated
   */
  /*CATBodyFromLength( CATGeoFactory*  iFactory,
                     CATWire*        aWire, 
                     CATVertex*      aVertex,
                     CATLength       aDistance,
                     CATLengthType   type = ABSOLUTE_L,
                     CATSkillValue   modev = BASIC,
                     CATCGMJournalList* Journal = NULL);
 
  int Run();  
  
  CATBody * GetResult() ;
  CATVertex * GetVertex() const;

  void SetWire    ( CATWire *     aNewWire );
  void SetVertex  ( CATVertex *   aNewVertex );
  void SetLength  ( CATLength     aNewDistance, 
                    CATLengthType aNewType = ABSOLUTE_L);
  //- ----------------------------------------
  //- Destructor.
  //- ----------------------------------------
  ~CATBodyFromLength();

private: 

  //- ----------------------------------------
  //- Internal methods .
  //- ----------------------------------------
  CATLONG32 GetRankOfStartEdge( );

  //- ----------------------------------------
  //- ----------------------------------------
  double ComputeDistance( CATLONG32 iIndex, 
			  double iDistance );

  //- ----------------------------------------
  //- ----------------------------------------
  void GetEdgeData( CATLONG32 iIndex, 
                    CATEdgeCurve **oEdgeCurve,
		    CATCrvParam &oStartParam, 
		    CATCrvParam &oEndParam,
                    CATOrientation &oOrientation );

  //- ----------------------------------------
  //- ----------------------------------------
  void ComputeEdgeVertex( CATEdge **iEdge,
			  CATLONG32 iOrientatino, 
			  CATVertex **oStartVertex,
			  CATVertex **oEndVertex );

  //- ----------------------------------------
  //- ----------------------------------------
  int  TestDistanceToEnd( double iDistance ) const;

  //- ----------------------------------------
  //- ----------------------------------------
  int  TestEdgeIndex( CATLONG32 iIndex ) const;

  //- ----------------------------------------
  //- ----------------------------------------
  void MoveToNextEdge( CATLONG32 &ioIndex ); 

  //- ----------------------------------------
  //- ----------------------------------------
  int IsLastEdge( CATLONG32 &iIndex );

  //- ----------------------------------------
  //- ----------------------------------------
  void SetResultToAVertex( CATEdgeCurve **EdgeCurve,
			   CATCrvParam &EndParam );

  //- ----------------------------------------
  //- ----------------------------------------
  double ComputeAbsoluteDistance( double RelativeDistance );

  //- ----------------------------------------
  //- ----------------------------------------
  double ComputeWireEntireLength();

  //- ----------------------------------------
  //- ----------------------------------------
  void ExtrapolVertex( CATEdgeCurve **EdgeCurve,
		       CATCrvParam &EndParam,
		       CATOrientation &Orientation,
		       double DistanceFromEnd );
  //- ----------------------------------------
  //- ----------------------------------------
  void CreateTheVertex( CATPoint *iThePoint );
  //- ----------------------------------------
  //- ----------------------------------------
  void SetFactory( CATGeoFactory *iFactory );



  //- ----------------------------------------
  //- ----------------------------------------
  //- enum CATDirOfDistance 
  //- {
  //-  POSITVE,
  //-  NEGATIVE
  //- };
  


  //- ----------------------------------------
  //- private data.
  //- ----------------------------------------

  CATGeoFactory*     _factory;
  CATWire*           _wire;
  CATVertex*         _vertex;
  CATCrvParam        _vertexParam;
  CATLONG32               _rankofvertex;
  CATLength          _distance;
  CATLONG32               _DirOfDistance;
  CATCGMJournalList* _journal;
  CATTopData*        _TopData;

  CATLISTP(CATVertex) _ListOfAnswers;

  int _indexOfAnswers;
  
};*/
#endif
