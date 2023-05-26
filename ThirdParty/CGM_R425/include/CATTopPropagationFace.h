/**
 * @COPYRIGHT DASSAULT SYSTEMES 2001
 * @fullReview  HCN 02:01:11
 */

/* -*-C++-*- */

#ifndef __CATTopPropagationFace_H__
#define __CATTopPropagationFace_H__

// COPYRIGHT DASSAULT SYSTEMES 2002

//===========================================================================
// Operator for face propagation on a body as a replacement for the
// following CATBody method :
//
// CATLISTP(CATFace) CATFacePropagate(CATLISTP(CATFace) * iInitialFaces)
//
// Jan. 02  Creation              HCN
// Jan. 04  Practical comments    CBK
// Feb. 06  Changes               EQT
//          1/ Point continuity propagation mode and no propagation mode available.
//            Look at SetContinuityMode function.
//          2/ GetResult: body made of shell as output
//            -> built with the propagated faces,
//            -> or built with the initial body, propagated faces being removed.
//            For this last option, one must set the complementary mode.
//            Look at SetComplementaryMode function.
//===========================================================================

#include "ExportedByCATTopologicalObjects.h"
#include "CATTopOperator.h"
#include "CATCGMNewArray.h"

#include "CATListOfInt.h"
#include "CATTopDef.h"
#include "CATTopPropagationFaceDiagnosis.h"
#include "CATBoolean.h"

class CATFace;
class CATShell;
class CATLISTP(CATFace);
class CATLISTP(CATEdge);
class CATLISTP(CATBody);
class CATMathBox;

/**
 * Class representing the topological operator which performs face propagation on a body.
 * <ul>
 * <li>Create it with the CATCreateTopPropagationFace global function.
 * <li>Tune it with appropriate options, using the Setxxx methods. 
 * <li>Run it ( only one time ).
 * <li>Get the resulting body with the GetResult method. 
 * This body is made of shells which contain either the result of the propagation 
 * or its complement.
 * If you do not want to keep this resulting body, 
 * use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory, after the operator deletion.
 * <li>Optionally get the two propagation diagnoses with the GetDiagnosisList method.
 * <li>Delete it after use  with the usual C++ delete operator. 
 * </ul>
*/
class ExportedByCATTopologicalObjects CATTopPropagationFace: public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopPropagationFace);
protected:
  
  /**
  * @nodoc
  * Constructor. Do not use. Use <tt>CATCreateTopPropagationFace</tt> to create an
  * <tt>CATTopPropagationFace</tt>.
  */
  CATTopPropagationFace(CATGeoFactory     * iFactory,
                        CATTopData        * iTopData,
                        CATBody           * iBody);

public:

  /**
  * Destructor.
  */
  virtual ~CATTopPropagationFace();

  CATCGMNewClassArrayDeclare;

  /**
  * Defines the continuity propagation mode on shell.
  * @param iContinuity
  * The list of continuity choices to be applied at the border of each face of the initial list.
  * The size of iContinuity must be the same than the size of iInitialFaces.
  * Each integer value is of type CATResolutionType.
  * <br><b>Legal values for each integer</b>:
  * <dl>
  * <dt><tt>-1</tt></dt><dd> No propagation. 
  * <dt><tt>0</tt></dt><dd> Point propagation (== CatC0 value of CATResolutionType ).
  * <dt><tt>1</tt></dt><dd> Tangency propagation (== CATC1 value of CATResolutionType).
  * For compatibility reasons, the default value for each face is CATC1.
  */
  virtual void SetContinuityMode ( const CATListOfInt * iContinuity ) = 0;

  /** 
  * Defines the complementary mode.
  * @param iComplMode 
  * <br><b>Legal values</b>:
  * <dl>
  * <dt><tt>TRUE</tt></dt><dd> Selection of the body made of the initial body, propagated faces being excluded.
  * <dt><tt>FALSE</tt></dt><dd> Selection of the body made of the propagated faces.
  * For compatibility reasons, the default mode is FALSE.
  */
  virtual void SetComplementaryMode ( const CATBoolean iComplMode ) = 0;

  /*
  * Calling this method will make the operator propagate on
  * sharp edges with wanted convexity (in addition to smooth edge)
  * @param iConvexity
  * Convexity of sharp edges on which we wish to propagate.
  */
  virtual void PropagateOnSharpEdgesWithSpecificConvexity(CATTopConvexity iConvexity) = 0;

  /*
  * Specifies faces on which propagation should be stopped.
  * @param iStoppingFaces
  * List of stopping faces
  */
  virtual void SetStoppingFaces(CATLISTP(CATFace) &iStoppingFaces) = 0;

  /*
  * Specifies edges on which propagation should be stopped.
  * @param iStoppingEdges
  * List of stopping edges
  */
  virtual void SetStoppingEdges(CATLISTP(CATEdge) &iStoppingEdges) = 0;

  /*
  * Specifies faces on which propagation can be done.
  * Complementary to SetStoppingFaces, maybe usefull for performance issue
  * @param iAllowedFaces
  * List of allowed faces
  */
  virtual void SetAllowedFaces(CATLISTP(CATFace) &iAllowedFaces) = 0;

  /*
  * Specifies if we want an error to be thrown
  * at the encounter of a non-manifold face
  * @param iDoThrow
  * Whether or not an error is to be thrown in that situation
  */
  virtual void SetThrowErrorOnNonManifoldFaces(CATBoolean iDoThrow) = 0;

  /*
  * Specifies a working box. No propagation outside this box.
  * Maybe usefull for performance issue
  * @param iWorkingBox
  * Box not to propagate outside it
  */
  virtual void SetWorkingBox(CATMathBox& iWorkingBox) = 0;

  /*
  * Specifies the shell on which propagation should be computed.
  * If the shell is set all initial faces should belong to specified shell
  * @param iShell
  * Shell on which propagation should be computed
  */
  virtual void SetShell(CATShell* iShell) = 0;

  /**
   * Returns the list of propagated faces, initial faces being excluded from this list.
   * Old method, no more to be used, use GetResult() virtual method instead.
   * @param ioListFaces 
   * List of propagated faces.
   */
  virtual void GetResultListFaces(CATLISTP(CATFace) & ioListFaces) = 0;

  /*
  * Returns the propagation diagnosis at each propagation end. 
  * @param oDiagnoses
  * Diagnoses corresponding to the end of propagation.
  * @param oDiagnosesBodies
  * List of bodies. Each body is made of a wire, and is associated to a diagnosis.
  * This method is to be called after the GetResult method
  */
  virtual void GetDiagnosisList ( CATListOfInt      & oDiagnoses , 
	                              CATLISTP(CATBody) & oDiagnosesBodies ) = 0;

  /*
  * nodoc
  * special mode for CATIALiveShape
  * @param iCellManifoldPropagationRule
  *           - If value 0          : Tangency Propagation on the same Reference Surface
  *           - If value 1 (default): Same as Rule 0, but not propagation when planar Reference Surface
  */
  virtual void SetCellManifoldCreationRule(CATBoolean iCellManifoldCreationRule, short iCellManifoldPropagationRule=1) = 0;

  /*
  * nodoc
  * Imprint Edges stop propagation
  */
  virtual void SetStoppedByImprintEdge(const CATBoolean iStoppedByImprintEdge) = 0;

};

#endif
