/* -*-c++-*- */
#ifndef CATBodyFromLengthOnWire_h
#define CATBodyFromLengthOnWire_h

// COPYRIGHT DASSAULT SYSTEMES 1999

//-------------------------------------------------------------------------
// Usage :  If You want to create a vertex at given distance on a Wire !!!
//-------------------------------------------------------------------------
//
// The Run method is mandatory. 
// ???? The Target Body can be provided it will be created in other cases
// ???? The Target body will be frozen by default and a report can be done. 
//
// Warning :
//----------
//    If the Wire is manifold, many answers may be possible.  An iteration
//    must be done with the Next() method until the correct Vertex is found.
//
// Example :
//----------
//    CATGetBodyFromLength  MyOperator(Wire, Vertex, A_Percentage, PERCENT, ADVANCED);
//    MyOperator.Run();
//    MyOperator.Begin();
//    MyOperator.Next();
//    CATBody* ResultBody = MyOperator.GetResult();
//
// 
//    CATGetBodyFromLength  MyOperator(Wire, Vertex, CATLength);
//    MyOperator.Begin();
//    MyOperator.Next();
//    CATBody* ResultBody = MyOperator.GetResult();
//
//
//- What does this method do ...
//-
//-  If the vertex is not on the wire,  then a point is computed
//-  from the input Vertex that is closest to the wire.  
//-  
//-  The length can be positive or negative. The sign of the length
//-  indicates the direction to traverse on the wire. If you want a specific
//-  direction when we traverse the edge, you should known the wire
//-  the indicate the proper length.
//-
//-  WARNING :
//-   Any null pointer given in input will cause a throw.
//-
//-
//  
//-------------------------------------------------------------------------

#include "YJ000GSM.h"
#include "ListPOfCATBody.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATVertex.h"
#include "CATSkillValue.h"
#include "CATTopOperator.h"
#include "CATMathDef.h"
#include "CATCGMJournalList.h"
#include "CATCrvParam.h"
#include "CATTopDef.h"
#include "CATExtrapolationMode.h"
#include "CATLengthType.h"
#include "CATListOfDouble.h"
#include "BasicTopology.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATLISTV_CATMathVector.h"
#include "CATCGMStream.h"
#include "CATIACGMLevel.h"
#include "CATBodyFromLengthOnWireMeasureType.h"

class CATWire;
class CATVertex;
class CATBody;
class CATPoint;
class CATPointOnEdgeCurve;
class CATGeoFactory;
class CATCGMJournalList;
class CATTopData;
//-class CATCrvParam;
class CATEdgeCurve;
class CATCrvLengths;
class CATExtTopOperator;
class CATExtBodyFromLengthOnWire;


//- class CATOrientation;

/**
* Class defining an operator to create a point or a series of points at given measures (arc lengths spacings or integrated turning angles) on a Wire.
* <br>
* <br>
* The <tt>CATBodyFromLengthOnWire</tt> operator follows the global frame of the topological
* operators and satisfies the smart mechanism: 
* the input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies. The follwing two integral measures are curently supported:
*<ul>
*<li> Arc length spacing specifies the curve length between sample points.
*<li> Integrated turning spacing specifies the total amount the tangent vector changes between sample points. Jumps in 
* the tangent vector between edges will be ignored. The expectation is that at vertices, edge pairs are G1 continuous.
*<li> The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory.
*</ul>
*/

class ExportedByYJ000GSM CATBodyFromLengthOnWire : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATBodyFromLengthOnWire);
  
public:

  //default constructor to be used by derived classes only
    CATBodyFromLengthOnWire( CATGeoFactory*  iFactory,
                     CATTopData*     iTopData,
                     CATWire*        iWire, 
                     CATVertex*      iVertex);

  // Prepares Vertex solution at given distance on a given Wire.

  //- ----------------------------------------
  //- ABSOLUTE_L = The distance is an absolute value, 
  //-              but the sign indecates the direction 
  //-              on the wire for finding the vertex.
  //- RELATIVE_L = The distance is a fraction of the 
  //-              total length of the wire.  Since 
  //-              its a fraction,  its value must be
  //-              equal to or between -1 and 1. 
  //-              A throw is made if that condition is 
  //-              not met.
  //- ----------------------------------------
  enum CATLengthType 
  { 
    ABSOLUTE_L = CATLengthType_ABSOLUTE_L, 
    RELATIVE_L = CATLengthType_RELATIVE_L 
  };

  //- ----------------------------------------
  // Constructor:  if type is RELATIVE, the ABSOLUTE value will be calculated.
  //- ----------------------------------------
  CATBodyFromLengthOnWire( CATGeoFactory*  iFactory,
                           CATTopData*     iTopData,
                           CATWire*        aWire, 
                           CATVertex*      aVertex,
                           CATLength       aDistance,
                           CATLengthType   type = ABSOLUTE_L,
                           CATSkillValue   modev = BASIC);

  /**
  * @nodoc
  * Deprecated
  */
  CATBodyFromLengthOnWire( CATGeoFactory     * iFactory,
                           CATWire           * aWire,
                           CATVertex         * aVertex,
                           CATLength           aDistance,
                           CATLengthType       type = ABSOLUTE_L,
                           CATSkillValue       modev = BASIC,
                           CATCGMJournalList * Journal = NULL);

  //- ----------------------------------------
  //- General method to compute the necessary data.
  //- If Run() was already used, all previous results will be lost
  //- ----------------------------------------
  /**
    * Runs the operator.
    * @return
    * <br><b>Legal values</b>: <tt>0</tt> if ok, <tt>1</tt> if failed
    */
  int Run();  
  
  //- ----------------------------------------
  //- Since there is only one possible result for a wire,
  //- those methods are useless.
  //- void Begin();
  //- void Next();
  //- ----------------------------------------
  /**
   * Activates or deactivates the lay-down operation.  If activated, the operator
   * projects the resulting point body upon the specified wire body 
   * if the distance between them is lower than the factory resolution.
   * @param iWireBody
   * The wire body that is the target of the lay-down operation.
   * @param ilaid
   * 0 to turn off lay-down, 1 to turn it on.
   */
  void SetLayDown(CATBody * iWireBody, int ilaid); //imposer le posage 1 pour avoir un resultat pose, 0(defaut) sinon

  /**
   * Returns the lay-down setting.
   * @param oLaid
   * 0 if lay-down is turned off, 1 if it is turned on.
   */
  void GetLayDown(int & oLaid); // lire les options de posage cf precedent
  
  
  //- ----------------------------------------
  // Returns the vertex computed by the run.
  //- If the ouput ( i.e. the CATBody or the CATVertex ) is 
  //- NULL, then the run has not been done.
  //- ----------------------------------------
 /**
  * Returns the point body computed by the run.  Call this method
  * after the <tt>Run</tt> method has been called.
  */
  CATBody * GetResult();

#ifdef CATIACGMR418CAA
  /**
  * Returns the resulting locations of point(s) in 3D.
  * The operator must be run prior to the use of this method
  * @return
  * The <tt>oLocations</tt> list of sampled points.
  */
  virtual void GetResult( CATLISTV(CATMathPoint) & oLocations ) const;
#endif /* CATIACGMR418CAA */


#ifdef CATIACGMR419CAA
  /**
  * Activates or deactivates the computation of tangents at the result vertices.  
  * If activated, the operator evaluates the tangent on the input wire, 
  * or at its extremity in case of extrapolation.
  * @param iActivateTangentMode
  * FALSE to turn off the option, TRUE to turn it on.
  */
  void SetTangentComputation(CATBoolean iActivateTangentMode);

  /**
  * Returns the result body with tangents (else returns NULL) associated to its vertices, according to the wire orientation.
  * SetTangentComputation(TRUE) then Run() has to be called prior to the use of this method
  * @return
  * The <tt>oResultVertices</tt> list of sampled vertices in the Result CATBody.
  * The <tt>oTangents</tt> list of normalized tangents associated to the vertices.
  * The <tt>oLocations</tt> optional list of vertices locations in 3D.
  * The pointer to the resulting body. Use @href CATICGMContainer#Remove if you do not want to keep it.
  */
  virtual CATBody * GetResultWithTangents(CATLISTP(CATVertex) &oResultVertices, CATLISTV(CATMathVector) &oTangents, CATLISTV(CATMathPoint) * oLocations=NULL);
#endif

  /** @nodoc */
  CATVertex * GetVertex() const;


  //- ----------------------------------------
  //- To use these, CATSkillValue must be declared 
  //- as ADVANCED when the operator is created.
  //- ----------------------------------------
  /** @nodoc */
  void SetExtrapolationMode  ( CATExtrapolationMode iExt = NoExtrapol );

  /** @nodoc */
  void SetWire    ( CATWire *     aNewWire );

  /** @nodoc */
  void SetVertex  ( CATVertex *   aNewVertex );

  /** @nodoc */
  void SetLength  ( CATLength     aNewDistance, 
                    CATLengthType aNewType = ABSOLUTE_L);

  // the new point is on the wire or not.
  // if the point is not on the wire it return the extrapoled distance
  /** @nodoc */
  CATBoolean IsOnWire(double &oExtrapolDistance);

  //- ----------------------------------------
  //- Destructor.
  //- ----------------------------------------
  ~CATBodyFromLengthOnWire();


  //- ----------------------------------------
  //- Protocoles Génériques .
  //- ----------------------------------------
  //KY1 : 10-12-2010
  /** @nodoc @nocgmitf*/ 
  static const  CATString  *GetDefaultOperatorId();

protected:

  //KY1 : 10-12-2010
  /** @nodoc*/
  int RunOperator();

#ifdef CATIACGMR419CAA   
  /** @nodoc @nocgmitf */
  virtual int RunExactOperator();
  /** @nodoc @nocgmitf */
  virtual int RunPolyOperator();
  /** @nodoc @nocgmitf */
  CATExtBodyFromLengthOnWire * GetBodyFromLengthOnWireExtensible();
  /** @nodoc @nocgmitf */
  virtual void PrepareExtensionBeforeRun(CATExtBodyFromLengthOnWire & iExtensible);
  /** @nodoc @nocgmitf */
  virtual void RetrieveOutputDataFromExtension(CATExtBodyFromLengthOnWire & iExtensible);
#endif


protected:
  /** @nodoc @nocgmitf */
  static  CATString  _OperatorId;
  /** @nodoc @nocgmitf */
  const  CATString  *GetOperatorId();
  /**  @nodoc @nocgmitf */
  void   RequireDefinitionOfInputAndOutputObjects();

  void               Dump(CATCGMOutput &os);

  CATLONG32 GetRankOfStartEdge( );

private:
 

  //- ----------------------------------------
  //- Internal methods .
  //- ----------------------------------------

  /** @nodoc @nocgmitf */
  void UpdateDistance();

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
                          CATLONG32 iOrientation, 
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
                           CATCrvParam &EndParam, CATPointOnEdgeCurve ** oPOEC );

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
  void SetFactory(CATGeoFactory *const iFactory );

  void Init( CATWire* iWire, CATVertex* iVertex );

  //- ----------------------------------------
  //- ----------------------------------------
  //- enum CATDirOfDistance 
  //- {
  //-  POSITVE,
  //-  NEGATIVE
  //- };
  

  protected:
  //- ----------------------------------------
  //- protected data.
  //- ----------------------------------------
  CATWire          *  _wire;
  CATVertex        *  _vertex;
  CATCGMJournalList * _journal;
  CATSoftwareConfiguration* _config;
  CATBoolean          _withTangent;

  private:

  //- ----------------------------------------
  //- input data.
  //- ----------------------------------------

  CATLength            _length;
  CATLengthType        _type;
  CATExtrapolationMode _extrapolMode;

  //- ----------------------------------------
  //- private data.
  //- ----------------------------------------

  CATBody          *  _WireBody;
  CATCrvParam         _vertexParam;
  CATLONG32           _rankofvertex;
  CATLength           _distance;
  CATLONG32           _DirOfDistance;
  CATLONG32           _IsRead;
  int                 _PoseSur;
  CATLISTP(CATBody)   _ListOfAnswers;
  CATLISTV(CATMathVector) _ListOfTangents; // conform to the wire orientation, parallel to _ListOfAnswers
  CATBoolean          _ResultIsOnWire;
  double              _DistanceToExtrapol;
  int                 _indexOfAnswers;
  CATLength         * _EdgesLength; 
  int               * _LengthComputed;
  int                 _NbComputeLength;
  
};

/**
 * Creates a CATICGMBodyFromLengthOnWire operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @return [out, IUnknown#Release]
 * The pointer to the created operator.  To be released with the <tt>Release</tt> method after use.
 */
ExportedByYJ000GSM 
CATBodyFromLengthOnWire* CATCreateBodyFromLengthOnWire(
    CATGeoFactory*  iFactory,
    CATTopData*     iTopData,
    CATWire*        aWire, 
    CATVertex*      aVertex,
    CATLength       aDistance,
    CATBodyFromLengthOnWire::CATLengthType type,
    CATSkillValue   modev);

/**
 * Creates a CATICGMBodyFromLengthOnWire operator.
 * @param iFactory
 *    The factory of the geometry. 
 * @param iTopData
 *    The pointer to the data defining the software configuration and the journal.
 *    If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
 * @param iSamplingArcLengths
 *    Variable arc lengths between the sample points on the wire. The wire will be sampled at
 *    consecutive increments defined in iSamplingArcLengths array starting from the 
 *    ReferenceVertex in the direction of wire orientation.
 * @param iWire
 *    The wire domain to be sampled.
 * @param iReferenceVertex
 *    The reference vertex where the sampling will start.
 * @param iReverseSamplingDirection
 *    Reverse the sampling direction (with respect to the wire orientation)
 * @param iRelativeTolerance
 *    Specifies the relative tolerance (a multiplicative factor of the factory resolution) 
 *    used internally in the integration scheme to determine sample point positions on the
      wire. Lower tolerance values may result in a higher precision of the computation at 
 *    the expense of a slower performance. The legal values are between 10^-4 and 1.
 * @return [out, IUnknown#Release]
 *    The pointer to the created operator.  To be released with the <tt>Release</tt> method after use.
 */
ExportedByYJ000GSM 
CATBodyFromLengthOnWire * CATCreateBodyFromLengthOnWire(
        CATGeoFactory   * iFactory,
        CATTopData      * iTopData,
  const CATListOfDouble & iSamplingArcLengths,
        CATWire         * iWire,
        CATVertex       * iReferenceVertex,
        CATBoolean        iReverseSamplingDirection = FALSE,
        double            iRelativeTolerance = 0.1 );

/**
 * Creates a CATICGMBodyFromLengthOnWire operator.
 * @param iFactory
 *    The factory of the geometry. 
 * @param iTopData
 *    The pointer to the data defining the software configuration and the journal.
 *    If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
  * @param iSamplingArcLength
 *    The arc length between the sample points on the wire. The wire will be sampled at 
 *    iSamplingArcLength increments starting from the ReferenceVertex in the direction of 
 *    wire orientation.
 * @param iWire
 *    The wire domain to be sampled.
 * @param iReferenceVertex
 *    The reference vertex where the sampling will start.
 * @param iReverseSamplingDirection
 *    Reverse the sampling direction (with respect to the wire orientation)
 * @param iRelativeTolerance
 *    Specifies the relative tolerance (a multiplicative factor of the factory resolution) 
 *    used internally in the integration scheme to determine sample point positions on the
      wire. Lower tolerance values may result in a higher precision of the computation at 
 *    the expense of a slower performance. The legal values are between 10^-4 and 1.
 * @return [out, IUnknown#Release]
 *    The pointer to the created operator.  To be released with the <tt>Release</tt> method after use.
 */
ExportedByYJ000GSM 
CATBodyFromLengthOnWire* CATCreateBodyFromLengthOnWire(
  CATGeoFactory* iFactory,
  CATTopData   * iTopData,
  double         iSamplingArcLength,
  CATWire      * iWire,
  CATVertex    * iReferenceVertex,
  CATBoolean     iReverseSamplingDirection = FALSE,
  double         iRelativeTolerance = 0.1 );

/**
 * Creates a CATICGMBodyFromLengthOnWire operator.
 * @param iFactory
 *    The factory of the geometry. 
 * @param iTopData
 *    The pointer to the data defining the software configuration and the journal.
 *    If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
 * @param iSamplingMeasures
 *    Variable measures (arc lengths spacings or integrated turning angles) between the sample points on the wire. 
 *    The wire will be sampled at consecutive increments defined in iSamplingArcMeasures array starting from the 
 *    ReferenceVertex in the direction of wire orientation.
 * @param iMeasureType
 *    Sampling measure type. Sets the operator to either use ArcLength or TurningAngle as the integral measure. 
 * @param iWire
 *    The wire domain to be sampled.
 * @param iReferenceVertex
 *    The reference vertex where the sampling will start.
 * @param iReverseSamplingDirection
 *    Reverse the sampling direction (with respect to the wire orientation)
 * @param iRelativeTolerance
 *    Specifies the relative tolerance, a multiplicative factor of factory length or factory angular resolution
 *    used by this operator internally in the integration scheme to determine sample point positions on the
 *    wire. Lower tolerance values may result in a higher precision of the computation at the expense of a 
 *    slower performance.
 * @return [out, IUnknown#Release]
 *    The pointer to the created operator.  To be released with the <tt>Release</tt> method after use.
 */
ExportedByYJ000GSM 
CATBodyFromLengthOnWire* CATCreateBodyFromLengthOnWire(
        CATGeoFactory                     * iFactory,
        CATTopData                        * iTopData,
  const CATListOfDouble                   & iSamplingMeasures,
        CATBodyFromLengthOnWireMeasureType iMeasureType,
        CATWire                           * iWire,
        CATVertex                         * iReferenceVertex,
        CATBoolean                          iReverseSamplingDirection = FALSE,
        double                              iRelativeTolerance = 0.1 );

/**
 * Creates a CATICGMBodyFromLengthOnWire operator.
 * @param iFactory
 *    The factory of the geometry. 
 * @param iTopData
 *    The pointer to the data defining the software configuration and the journal.
 *    If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
  * @param iSamplingMeasure
 *    Measure interval (arc lengths spacings or integrated turning angles) between the sample points on the wire. 
 *    The wire will be sampled at iSamplingMeasure increments starting from the ReferenceVertex in the direction of 
 *    wire orientation.
 * @param iMeasureType
 *    Sampling measure type. Sets the operator to either use ArcLength or TurningAngle as the integral measure. 
 * @param iWire
 *    The wire domain to be sampled.
 * @param iReferenceVertex
 *    The reference vertex where the sampling will start.
 * @param iReverseSamplingDirection
 *    Reverse the sampling direction (with respect to the wire orientation)
 * @param iRelativeTolerance
 *    Specifies the relative tolerance, a multiplicative factor of factory length or factory angular resolution
 *    used by this operator internally in the integration scheme to determine sample point positions on the
 *    wire. Lower tolerance values may result in a higher precision of the computation at the expense of a 
 *    slower performance.
 * @return [out, IUnknown#Release]
 *    The pointer to the created operator.  To be released with the <tt>Release</tt> method after use.
 */
ExportedByYJ000GSM 
CATBodyFromLengthOnWire* CATCreateBodyFromLengthOnWire(
  CATGeoFactory                     * iFactory,
  CATTopData                        * iTopData,
  double                              iSamplingMeasure,
  CATBodyFromLengthOnWireMeasureType  iMeasureType,
  CATWire                           * iWire,
  CATVertex                         * iReferenceVertex,
  CATBoolean                          iReverseSamplingDirection = FALSE,
  double                              iRelativeTolerance = 0.1 );

#endif
