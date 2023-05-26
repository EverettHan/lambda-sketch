#ifndef CATRemoveFace_H
#define CATRemoveFace_H

// COPYRIGHT DASSAULT SYSTEMES 2002 

/**
 * @CAA2Level L1
 * @CAA2Usage U3
*/

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "Thick.h"
#include "ListPOfCATFace.h"
#include "CATListOfInt.h"
#include "CATTopOperator.h"
#include "CATTopDefine.h"

class CATBody;
class CATFace;

/**
*
*  ***********************************************************************
*  *******                         WARNING                         *******
*  ***********************************************************************
*  *******
*  *******  This class is Not supported any longer.
*  *******  it has been replaced by CATICGMRemoveFace
*  *******
*  *******
*  ***********************************************************************
*  ***********************************************************************
*  CATRemoveFace class has been removed from CAA in 3DEXPERIENCE level and
*  has been replaced by CATICGMRemoveFace.
*  We recommend you to use only CATICGMRemoveFace, in order you will  be  
*  able to easily migrate   your CAA code from  V5 to 3DEXPERIENCE level
*
*  **************************************************************************
*
 * Class defining a topological operator which removes a set of faces from a volume or a skin.<br>
 * This operator does not change the dimension of the body: a volume remains a volume,
 * a skin remains a skin.<br>
 * Unlike in the Part Design interactive command, the specified faces to be removed are 
 * not propagated, so that in your application, you should either provide a consistent set of faces
 * or propagate the faces. The operation completes when the body can be closed by extrapolation 
 * of the faces which were adjacent to the ones removed but this extrapolation should not generate any 
 * tangency configuration.<br>
 * To use this operator, you must:
 * <ul>
 * <li>Create it with the CATCreateRemoveFace global function
 * <li>Tune it with appropriate options, using the <tt>SetXxx</tt> or <tt>Append</tt> methods.
 * <li>Run it
 * <li>Get the result with the <tt>GetResult</tt> method. If you do not want 
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory, after the operator deletion.
 * <li>Delete with the usual C++ <tt>delete</tt> operator after use.
 * </ul> 
 */
class ExportedByThick CATRemoveFace : public CATTopOperator
{

  CATCGMVirtualDeclareClass(CATRemoveFace);
public:
/**
   * Constructor
   */
  CATRemoveFace( CATTopData * iTopData, CATBody* iBody );

  // Destructor (memory is freed and model is cleaned, the resulting body is kept.
  virtual ~CATRemoveFace();

  /**
 * Appends a list of faces to be removed.
 * @param iFacesToRemove
 * The list of pointers to faces to remove.
 */
  virtual void Append(const CATLISTP(CATFace) &iFacesToRemove) = 0;

  /**
 * Restricts the removal of a face to a portion delimited by a single-face skin.
 * @param iFaceToRemove
 * The face to be removed.
 * @param iLimitingBody
 * The limiting body.
 * @param iOri
 * The orientation defining the portion of the face to be removed.
 */
  virtual void AppendLimiting(CATFace *iFaceToRelimit, CATBody *iLimitingBody, CATOrientation iOri) = 0;

#if defined (CATIACGMR215CAA)
  /**
  * Enables or disables twist detection.
  * @param iTwistDetection
  * <dl>
  * <dt><tt>0</tt></dt><dd> Twist detection is disabled : result body may lie on twisted surfaces.
  * This mode is used by default at the creation of the operator.</dd>
  * <dt><tt>1</tt></dt><dd> Twist detection is enabled : face removal fails if at least one of the extrapolated surfaces is twisted.</dd>
  * </dl>
  */
  virtual void SetTwistDetection(short iTwistDetection) = 0;
#endif

  /**
  * @nodoc
  * Roof Revit
  * @iRoofRevit = 1 to activate the option.
  */
  virtual void SetRoofRevit(short iRoofRevit=1) = 0;

  /**
  * @nodoc
  * Indicates that specified faces to remove are all fillets
  * @param iRemoveFilletsMode = 1 enables fillet dedicated treatments.
  * This mode is disabled by default.
  */
  virtual void SetRemoveFilletsMode(short iRemoveFilletsMode=1) = 0;

  /**
 * @nodoc
 * Appends a list of faces to be removed.
 * @param iFacesToRemove
 * The list of pointers to be removed.
 */
  virtual void AppendCandidate(const CATLISTP(CATFace) &iFacesToRemove) = 0;

 /**
 * Defines the "Freeze" mode of the resulting body.
 * @param iOnOrOff
 * The "Freeze" mode of the resulting body. 
 * <ul>
 * <li>CATBodyFreezeOff: the resulting body can be modified. 
 * <li>CATBodyFreezeOn: the resulting body cannot be modified. Any cell to be modified will have
 * to be duplicated.
 * </ul>
 */
 virtual void SetFreezeMode(CATBodyFreezeMode iOnOrOff) = 0;

 /**
  * @nodoc
  * Specifies whether matter is to be added or removed in order to generate 
  * the resulting body.
  * @param iMatterDirection
  * <ul>
  * <li> iMatterDirection = -1, the matter is removed
  * <li> iMatterDirection = 1 , the matter is added
  * </ul>
 */
 virtual void SetMatterDirection(short iMatterDirection) = 0;

  /**
  * @nodoc
  * DO NOT USE.
 */
 virtual void SetPartialRemoveFaceAllowed(int iPartialRemoveFaceAllowed) = 0;

/**
 * Runs <tt>this</tt> operator.
 */
 virtual int Run() = 0;

 /**
 * Returns the pointer to the resulting body.
 * @return
 * The pointer to the resulting body, <tt>NULL</tt> if the operation failed. 
 * If you do not want to keep the resulting body, 
 * use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory, after the operator deletion.
 */
 virtual CATBody* GetResult() = 0;

  /**
 * Returns the complete list of faces when the operation 
 * cannot complete. This method is mainly used by the interactive command to help the end-user
 * determine why the operator cannot complete. When the operation completes, this list is empty.
 * @param oAllTrickyFaces
 * The list of faces intended to be removed, but not removed.
 * @param oAllDiag
 * The list of diagnosis.
 */
 virtual void GetAllTrickyFaces(CATLISTP(CATFace) &oAllTrickyFaces, CATListOfInt &oAllDiag) = 0;

};
/**
* Creates a CATRemoveFace operator.
* @param iTopData
* A pointer to the topological data.
* @param iBody
* A pointer to the body.
* @param iFacesToRemove
* The list of faces to be removed.
* @return 
* The operator.
*/
ExportedByThick
CATRemoveFace * CATCreateRemoveFace(CATTopData * iTopData, CATBody* iBody,
                                    CATLISTP(CATFace) &iFacesToRemove);

#endif

