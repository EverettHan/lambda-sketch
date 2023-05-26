// COPYRIGHT DASSAULT SYSTEMES  2004

/**
* @level Protected
* @usage U1
*/

#ifndef CATTopSimilarCurve_h
#define CATTopSimilarCurve_h

#include "CATFreeFormDef.h"
#include "FrFTopologicalOpe.h"
#include "CATTopOperator.h"
#include "CATIACGMLevel.h"
/**
 * Class defining the topological operator that connects two wires with 
 * the "Base Curve" option.
 *<ul>
 * <li>A CATTopSimilarCurve operator is created with the <tt>CATCreateTopSimilarCurve</tt> global function;
 * it must be directly deleted with the usual C++ <tt>delete</tt> operator after use. 
 * It is is not streamable. 
 *<li>Options such as the start and end points must be 
 * precised with the <tt>SetXxx</tt> methods, before
 * asking for the computation with the <tt>Run</tt> method. 
 *<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory.Although several sucessive 
 * <tt>Run</tt>s with different inputs
 * are possible, it is strongly recommended to <tt>Run</tt> it only once.
 *</ul>
 */

class ExportedByFrFTopologicalOpe CATTopSimilarCurve : public CATTopOperator
{

  CATCGMVirtualDeclareClass(CATTopSimilarCurve);
  public:
/**
 * @nodoc
 * Constructor. 
 */
                                  CATTopSimilarCurve       (     CATGeoFactory           *  iFactory                  ,
                                                                 CATTopData              *  iData                     );
  virtual                        ~CATTopSimilarCurve();

  /**
  * Defines the start point.
  * @param iStartPoint
  * The start point. It must be laid down on <tt>iCurve1</tt>
  * @param iCurve
  * The first curve. If iCurve1 is NULL the point is free.
  */
  virtual int                     SetStartPoint            (      CATBody                *  iStartPoint              ,
                                                                  CATBody                *  iCurve1                  )=0;

  /**
  * Defines the end point.
  * @param iEndPoint
  * The endpoint. It must be laid down on <tt>iCurve2</tt>
  * @param iCurve2
  * The second curve. If iCurve2 is NULL the point is free.
  */
  virtual int                     SetEndPoint              (       CATBody               *  iEndPoint                ,
                                                                   CATBody               *  iCurve2                  )=0;

  /**
  * Defines whether the input bodies must be trimmed.
  * @param iWire
  * The first (1) or the second (2) wire body.
  * If not precised and if iTrimmingMode is set to ON,
  * the two wire bodies are trimmed.
  * @param iTrimmingMode
  * trim ON (1), trim OFF (0)
  */
  virtual void                    SetTrimmingMode           (const CATLONG32                iWire                    ,
                                                             const CATLONG32                iTrimmingMode            ) = 0;

  /**
  * @nodoc
  */
  virtual void                    SetContinuity             (const CATLONG32                iWire                    ,
                                                                   CATFrFContinuity         iContinuity              ) = 0;

  /**
  * Runs <tt>this</tt> operator.
  */
  virtual int                     Run                       ()                                                         = 0;

  /**
  * Returns the result of <tt>this</tt> operator.
  * @return
  * The pointer to the created body. You must delete it with the @href CATICGMContainer#Remove 
  * method if you do not want to keep it.
  */
  virtual CATBody               * GetResult                 ()                                                         = 0;
  
 /**
 * @nodoc
 */
  virtual CATBody               * GetResult                 (      CATCGMJournalList     *  iJournal                 ) = 0;

};
 
/**
 * Creates a topological operator that connects to curves according to the
 * specification of a base curve.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * @param iBaseCurve
 * The base curve.
 * @param iInputCurve1
 * One of the wire to be connected. The start/end point must be laid down on iInputCurve1. 
 * If NULL is specified, the start/end point is free.
 * @param iInputCurve2
 * The other wire to be connected. The end/start point must be laid down on iInputCurve2.
 * If NULL is specified, the end/start point is free.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator afer use.
 */
ExportedByFrFTopologicalOpe 
CATTopSimilarCurve * CATCreateTopSimilarCurve(CATGeoFactory * iFactory     ,
                                              CATTopData    * iData        ,
                                              CATBody       * iBaseCurve   ,
                                              CATBody       * iInputCurve1 = NULL,
                                              CATBody       * iInputCurve2 = NULL);
#endif 


