#ifndef CATTopTangentCurveOperator_h_
#define CATTopTangentCurveOperator_h_

//COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @level Protected
 * @usage U1
 */ 

#include "CATIACGMLevel.h"
#include "CATBaseUnknown.h"    
#include "Parallel.h"
#include "CATTopMultiResult.h"
#include "CATMathDef.h"
#include "CATTopDef.h"

class CATTopTangentCurveData;
/**
 * Class of the topological operators that create the bodies tangent to other bodies. 
 * This class is the base class for some supplied operators, but you must not derive it yourself.
 *<br>
 * This operator follows the general scheme of the topological operators producing several resulting bodies:
 * <ul>
 *<li> Create the operator with the appropriate global function 
 *<li> Set the parameters
 *<li> Run
 *<li> Get the resulting bodies (use the iterator on the resulting bodies, because
 * several line bodies can result from the computation)
 *<li> Delete the operator with the usual C++ <tt>delete</tt> operator.
 *</ul>
 * @see CATTopMultiResult
 */
class ExportedByParallel CATTopTangentCurveOperator : public CATTopMultiResult
{

  CATCGMVirtualDeclareClass(CATTopTangentCurveOperator);
public:

  /**
   * Defines the tangent orientation of the resulting line bodies to output.
   * <br>To call before the <tt>Run</tt> method.
   * @param iTangentOrientation
   * The tangent orientation with regards to the <tt>iRankWire</tt>-th input body.
   * <br><b>Legal values</b>: 
   * <dl><dt><tt>0</tt></dt><dd>All the resulting line bodies are output
   *     <dt><tt>1</tt></dt><dd>Are kept the resulting line bodies whose orientation is the same as  
   *                            the orientation of the <tt>iRankWire</tt>-th input body
   *     <dt><tt>-1</tt></dt><dd>Are kept the resulting line bodies whose orientation is opposite to 
   *                            the orientation of the <tt>iRankWire</tt>-th input body
   * </dl>
   * @param iRankWire
   * The rank of the input body to consider. 
   * <br>Legal values</b>: <tt>iRankWire=1</tt> in case of <tt>CATTopLineTangentPtCrvOperator</tt>,
   * <tt>1 <= iRankWire <= 2</tt> in case of <tt>CATTopLineTangentCrvCrvOperator</tt>.
   */
  void SetTangentOrientation(int iTangentOrientation,int iRankWire=1); 

  /**
   * Defines the curvature orientation of the resulting line bodies to output.
   * <br>To call before the <tt>Run</tt> method.
   * @param iTangentOrientation
   * The curvature orientation with regards to the <tt>iRankWire</tt>-th input body.
   * <br><b>Legal values</b>: 
   * <dl><dt><tt>0</tt></dt><dd>All the resulting line bodies are output
   *     <dt><tt>1</tt></dt><dd>Are kept the resulting line bodies that are on the side of the
   *                            vector product of the normal to the shell and the tangent to the resulting line body
   *     <dt><tt>-1</tt></dt><dd>Are kept the resulting line bodies that are on the opposite side of the
   *                            vector product of the normal to the shell and the tangent to the resulting line body
   * </dl>
   * @param iRankWire
   * The rank of the input body to consider. 
   * <br>Legal values</b>: <tt>iRankWire=1</tt> in case of <tt>CATTopLineTangentPtCrvOperator</tt>,
   * <tt>1 <= iRankWire <= 2</tt> in case of <tt>CATTopLineTangentCrvCrvOperator</tt>.
   */
  void SetCurvatureOrientation(int iCurvatureOrientation,int iIWire=1); 

  /**
   * Defines the orientation of the current resulting line body.
   * <br>To call after the <tt>Run</tt> method, 
   * during the iterative step of the result recovery, see @href CATTopMultiResult .
   * @param ioTangentOrient
   * The tangent orientation with regards to the <tt>iRankWire</tt>-th input body.
   * <br><b>Legal values</b>: 
   * <dl><dt><tt>0</tt></dt><dd>All the resulting line bodies are output
   *     <dt><tt>1</tt></dt><dd>Are kept the resulting line bodies whose orientation is the same as  
   *                            the orientation of the <tt>iRankWire</tt>-th input body
   *     <dt><tt>-1</tt></dt><dd>Are kept the resulting line bodies whose orientation is opposite to 
   *                            the orientation of the <tt>iRankWire</tt>-th input body
   * </dl>
   * @param ioCurvatureOrient
   * The curvature orientation with regards to the <tt>iRankWire</tt>-th input body.
   * <br><b>Legal values</b>: 
   * <dl><dt><tt>0</tt></dt><dd>All the resulting line bodies are output
   *     <dt><tt>1</tt></dt><dd>Are kept the resulting line bodies that are on the side of the
   *                            vector product of the normal to the shell and the tangent to the resulting line body
   *     <dt><tt>-1</tt></dt><dd>Are kept the resulting line bodies that are on the opposite side of the
   *                            vector product of the normal to the shell and the tangent to the resulting line body
   * </dl>
   * @param ioIdem
   * The test of whether the current resulting line body can be distinguished from another one.
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt></dt><dd>If the current resulting line body can be distinguished in terms of orientations from
   * the other resulting line bodies
   *     <dt><tt>2</tt></dt><dd>If the current resulting line body has the same orientations than another resulting line body
   *                            and its length is equal (at the factory resolution) 
   *                            to the length of at least one of them.
   * </dl>
   * @param iRankWire
   * The rank of the input body to consider. 
   * <br>Legal values</b>: <tt>iRankWire=1</tt> in case of <tt>CATTopLineTangentPtCrvOperator</tt>,
   * <tt>1 <= iRankWire <= 2</tt> in case of <tt>CATTopLineTangentCrvCrvOperator</tt>.
   */
  virtual void GetOrientationOnWire(int &ioTangentOrient,
                                    int &ioCurvatureOrient,
                                    int &ioIdem,
                                    int iRankWire=1);
 

  /**
   * Defines an index to distinguish the current resulting line body.
   * <br>To call after the <tt>Run</tt> method, 
   * during the iterative step of the result recovery, see @href CATTopMultiResult .
   * <br>Several resulting tangent line bodies produced by the operator can be same oriented
   * regarding to the input wire bodies. In such a case, they are sorted by length in order to
   * distinguish them.
   * @param ioIndex
   * The index value in the list of same oriented (in tangent and curvature) resulting line bodies.
   */
  virtual void GetDiscriminationIndex(int &ioIndex);

  /**
   * Returns the tangent orientation of the current resulting line body.
   * @return 
   * The tangent orientation with regards to the <tt>iRankWire</tt>-th input body.
   * <br><b>Legal values</b>: 
   * <dl>
   *     <dt><tt>1</tt></dt><dd>The resulting line body has the same orientation as  
   *                            the <tt>iRankWire</tt>-th input body
   *     <dt><tt>-1</tt></dt><dd>The resulting line body has the opposite orientation to 
   *                            the <tt>iRankWire</tt>-th input body
   * </dl>
   */
  int GetTangentOrientation(int iRankWire=1) const;

  /**
   * Returns the curvature orientation of the resulting line bodie.
   * @return 
   * The curvature orientation with regards to the <tt>iRankWire</tt>-th input body.
   * <br><b>Legal values</b>: 
   * <dl>
   *     <dt><tt>1</tt></dt><dd>The resulting line body is on the side of the
   *                            vector product of the normal to the shell and the tangent to the itself
   *     <dt><tt>-1</tt></dt><dd>The resulting line body is on the opposite side of the
   *                            vector product of the normal to the shell and the tangent to the itself
   * </dl>
   */
  int GetCurvatureOrientation(int iRankWire=1) const;

  /**
  * Creates the nearest line from conditions.
  * @param iCrvOr
  * The array of two curvature orientations for first and second input body.
  * Acceptables values: 0,-1,1. Use 0 if you don't want to use this condition.
  * @param iTngOr
  * The array of two tangent orientations between the line result and the first and second input body.
  * Acceptables values: 0,-1,1. Use 0 if you don't want to use this condition.
  * @iIndex 
  * iIndex = -1,0,1,2,... : The discrimination Index of the wanted solution, Use -1 if you don't want to use this condition.
  * @param oUseOrientationCondition
  * Return TRUE if the line solution use the orientation condition.
  * @param oUseIndexCondition
  * Return TRUE if the line solution use the index condition.
  * @param CurJourn
  * The pointer to the journal corresponding to the creation of the current line.
  * If <tt>NULL</tt>, the journal is not written.
  * @return
  * The pointer to the created body, or NULL if we cannot find it. If you do not want to keep it,
  * use the @CATICGMContainer#Remove method to remove it from the geometric factory, after the deletion
  * of <tt>this</tt> operator.
  * Put the iterator of the resulting lines on the solution.
  */ 
  CATBody * GetResultWithConditions(CATOrientation * iCrvOr, CATOrientation * iTngOr, int iIndex,
                                    CATBoolean &oUseOrientationCondition, CATBoolean &oUseIndexCondition,
                                    CATCGMJournalList * CurJourn=NULL);


  
protected :
  
/** @nodoc*/
  CATTopTangentCurveOperator(CATGeoFactory* iFactory,CATTopData * iTopData,int iNWires=1);
  /** @nodoc*/
  CATTopTangentCurveOperator(CATGeoFactory* iFactory,int iNWires=1);
/** @nodoc*/
  ~CATTopTangentCurveOperator();
/** @nodoc*/
  void ClearMembers();
  /** @nodoc*/
  void ClearTCurveData();
/** @nodoc*/
  void ClearTRank(int *iTRank=NULL);
/** @nodoc*/
  void ClearTSpecOrient();
/** @nodoc*/
  CATTopTangentCurveData* AddTangentCurveData(int &oIRank);
/** @nodoc*/
  void RemoveLastTangentCurveData();
/** @nodoc*/
  void ReplaceByLastTangentCurveData(int iIRank);
/** @nodoc*/
  CATTopTangentCurveData* GetTTangentCurveData(int &oNData);
  int _NWires; // number of input wires
  CATLONG32 CheckWireIndex(int iIWire) const;

private :

  CATLONG32 InitMembers();

  CATLONG32 DefineNumberOfWires(int iNWires);



  int _NData; // number of CATTopTangentCurveData in cells USED, [0.._NData[

  int _NDataAlloc; // number of CATTopTangentCurveData cells ALLOCATED ( _NDataAlloc >= _NData )

  CATTopTangentCurveData* _TTangentCurveData;

  int* _TRank; // rang en longueur pour chaque courbe-resultat [0.._NData[

  int* _TTngtOrient; // spec orientation en tangence [1.._NWires]

  int* _TCrvtOrient; // spec orientation en courbure [1.._NWires]

};

#endif
