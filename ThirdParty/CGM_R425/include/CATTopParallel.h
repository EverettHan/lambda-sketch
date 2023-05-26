#ifndef CATTopParallel_H
#define CATTopParallel_H

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 


#include "ParallelLight.h"
#include "CATTopOperator.h"
#include "CATMathDef.h"
#include "CATTopDef.h"
#include "CATIACGMLevel.h"
//
class CATWire;
class CATBody;
class CATDistanceTool;
class CATExtrapolParallelTool;
class CATICGMExtrapolParallelTool;
class CATICGMDistanceTool;

/**
* Class representing the operator that computes a wire parallel to another one on a skin body.
* <br>The CATTopParallel operator follows the global frame of the topological operators
* and satisfies the smart mechanism: the
* input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*<ul>
* <li>A CATTopParallel operator is created with the <tt>CATCreateTopParallel</tt> global function.
* It must be directly deleted with the usual C++ <tt>delete</tt> operator after use. It is not streamable. 
*<li>The computation is done by the <tt>Run</tt> method. 
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory, after the operator deletion.
*</ul>
*/
class ExportedByParallelLight CATTopParallel : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopParallel);
  public :
  /** @nodoc*/
  CATTopParallel(CATGeoFactory* iFactory, CATCGMJournalList* iJournal=0);
  /** @nodoc */
  CATTopParallel(CATGeoFactory* iFactory, CATTopData* iData);

  virtual ~CATTopParallel();
  /** @nodoc */
  virtual void GetSide(CATOrientation & oOri) = 0;
  /** @nodoc */
  virtual void SetSide (CATOrientation iOri) = 0;

/** @nodoc */
  virtual void SetPLineSimplif(CATLONG32 simplif) = 0;  // 1 = PLine simplification 
                                                   // 0 = No PLine simplification
  /** @nodoc */
  virtual void GetPLineSimplif(CATLONG32 & simplif) = 0;  // 1 = PLine simplification
                                                     // 0 = No PLine simplification
    
#ifdef CATIACGMR424CAA
  /**
  * Set the extrapolation mode 
  * for the extrapolation of the parallel result wire on the support shell
  * @param iExtrapolationMode
  * <br><b>Legal values</b>:
  * <dl><dt><tt>0</tt><dd> No Extrapolation. 
  *     <dt><tt>1</tt><dd> Extrapolation in tangency continuity. 
  *     <dt><tt>2</tt><dd> Extrapolation in curvature continuity. </dl>
  */
  virtual void SetExtrapolationMode(short iExtrapolationMode = 0) = 0;

  /** 
  * Get the extrapolation mode
  * for the extrapolation of the parallel result wire on the support shell
  * @param oExtrapolationMode
  * <br><b>Legal values</b>:
  * <dl><dt><tt>0</tt><dd> No Extrapolation.
  *     <dt><tt>1</tt><dd> Extrapolation in tangency continuity. 
  *     <dt><tt>2</tt><dd> Extrapolation in curvature continuity. </dl>
  */
  virtual void GetExtrapolationMode(short &oExtrapolationMode) = 0;
#endif

  /**
   * Returns the pointer to the resulting body.
   * @return
   * The pointer to the resulting body. If you do not want to keep it, 
   * use the @href CATICGMContainer#Remove method to remove it from the 
   * geometric factory, after the operator deletion.
   */
    virtual CATBody *    GetResult()=0;
};

/**
* Creates a CATTopParallel operator that computes a wire parallel 
* (according to a given law) to another one on a shell.
* <b>Orientation</b>: The resulting wire is oriented as the input one.<br>
* <b>Journal</b>: If the distance is null, a new body is created and 
* the edges are written as kept. If not, the new body contains the new edges, written
* as created.
* @param iOption
* The definition of the parameters for the operation.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
*/

ExportedByParallelLight
CATTopParallel * CATCreateTopParallel(CATExtrapolParallelTool * iOption,
									  CATBody * iCurve);

/**
* @nocgmitf
* Creates a CATTopParallel operator that computes a wire parallel 
* (according to a given law) to another one on a shell.
* <b>Orientation</b>: The resulting wire is oriented as the input one.<br>
* <b>Journal</b>: If the distance is null, a new body is created and 
* the edges are written as kept. If not, the new body contains the new edges, written
* as created.
* @param iOption
* The definition of the parameters for the operation.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
*/

ExportedByParallelLight
CATTopParallel * CATCreateTopParallel(CATICGMExtrapolParallelTool * iOption,
                                      CATBody * iCurve);

/**
* @nodoc
* Creates a CATTopParallel operator that computes a wire parallel 
* (according to a given law) to another one on a shell.
* <br>
* <b>Orientation</b>: The resulting wire is oriented as the input one.<br>
* <b>Journal</b>: If the distance is null, a new body is created and 
* the edges are written as kept. If not, the new body contains the new edges, written
* as created.
* @param iFactory
* The pointer to the factory of the resulting body.
* @param iData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
* is <tt>NULL</tt>, it is not filled.
* @param iCurve
* The pointer to the body defining the wire. 
* @param iSupport
* The pointer to the body defining the support of the input (and output) wire.
* @param iDistance
* The type of parallel computation.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
*/
ExportedByParallelLight
CATTopParallel * CATCreateTopParallel (CATGeoFactory     * iFactory,
										CATTopData        * iData,
										CATBody      * iCurve,
										CATBody       * iSupport,
										CATDistanceTool * iDistance);

/**
* @nodoc @nocgmitf
* Creates a CATTopParallel operator that computes a wire parallel 
* (according to a given law) to another one on a shell.
* <br>
* <b>Orientation</b>: The resulting wire is oriented as the input one.<br>
* <b>Journal</b>: If the distance is null, a new body is created and 
* the edges are written as kept. If not, the new body contains the new edges, written
* as created.
* @param iFactory
* The pointer to the factory of the resulting body.
* @param iData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
* is <tt>NULL</tt>, it is not filled.
* @param iCurve
* The pointer to the body defining the wire. 
* @param iSupport
* The pointer to the body defining the support of the input (and output) wire.
* @param iDistance
* The type of parallel computation.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
*/
ExportedByParallelLight
CATTopParallel * CATCreateTopParallel (CATGeoFactory     * iFactory,
										CATTopData        * iData,
										CATBody      * iCurve,
										CATBody       * iSupport,
										CATICGMDistanceTool * iDistance);

/**
* @nodoc @nocgmitf
* Use CATCreateTopParallel.
*/
ExportedByParallelLight
CATTopParallel * CreateTopOpAllParallel (CATGeoFactory     * iFactory,
										CATTopData        * iData,
										CATBody      * iCurve,
										CATBody       * iSupport,
										CATDistanceTool * iDistance);

/**
* @nodoc @nocgmitf
* Use CATCreateTopParallel.
*/
ExportedByParallelLight
CATTopParallel * CreateTopOpAllParallel (CATGeoFactory     * iFactory,
										CATTopData        * iData,
										CATBody      * iCurve,
										CATBody       * iSupport,
										CATICGMDistanceTool * iDistance);

/** @nodoc @nocgmitf */
ExportedByParallelLight
CATTopParallel * CreateTopOpParallel(CATExtrapolParallelTool * iOption,
									CATBody * iCurve);


#endif
