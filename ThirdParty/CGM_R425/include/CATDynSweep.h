#ifndef CATDynSweep_H_
#define CATDynSweep_H_

// COPYRIGHT DASSAULT SYSTEMES  1999



#include "CATDynOperator.h"
#include <CATMathDef.h>
#include <CATListOfCATCurves.h>



class CATMathDirection;
class CATBody;
class CATPlane;
class CATGeometry;
class CATBody;

/**
 * Interface representing the topological operator of creation of a swept body.
 * <br> This body is created by the sweep of a <b>profile</b> (that must lay on a plane) along
 * a curve called <b>center curve</b>. The <b>spine</b> curve manages the normal to the plane
 * of the profile: the spine tangent is the normal to the profile plane. If you want that
 * the profile must be swept perpendicular to the center curve, put center curve= spine curve.
 * <br>Two cases are taken into account: the profile is closed and the profile is not closed.
 * <ul><li><i>The profile is closed</i>: the resulting body contains a volume, that may be operated
 * in the same operation with another body (<tt>SetTrim</tt>) in a boolean operation
 * (<tt>SetOperation</tt>).
 * <li><i>The profile is not closed</i>: the resulting body contains a shell domain, and 
 * cannot be operated with another body in the same operation. However, it is possible 
 * to ask for the closure of the profile (<tt>SetClosure (CATBoolean(0))</tt>) on another
 * body (<tt>SetTrim</tt>). In this case, the resulting body can also by operated in a 
 * boolean operation (<tt>SetOperation</tt>) with the body on which it has been closed.
 * </ul>
 * If a boolean operation has been asked within the operator, you can ask for both result
 * (without and with the boolean operation) with the <tt>SetBothResult</tt> method.
 *<br>As all the topological operators, the input bodies are not modified. The resulting body is
 * a new one, that you can retrieve, using the <tt>CATDynOperator::GetResult</tt> method.<br>
 */
class ExportedByBODYNOPE CATDynSweep : public CATDynOperator
{
 public:
 /** Virtual constructor of a CATDynSweep operator.<br>
 * Can never be called. Use the <tt>CATDynCreateSweep</tt> global function
 * to create a CATDynSweep operator.
 */
  CATDynSweep (CATGeoFactory*     iContainer,
	       CATCGMJournalList* journal=NULL);
  virtual ~CATDynSweep();

/**
 * Defines the type of limitation of each extremity of the center curve.
 * @param iId
 * The extremity for which the limit is defined.
 * <dl> <dt>CATLimStart<dd>The first extremity of the center curve: 
 *<ul><li>if the center curve has several curves: the free extremity
 * of the first curve of the center curve.
 * <li> If the center curve only contains one curve: the first
 * extremity in the natural parameterization of the curve.
 *</ul>
 * <dt>CATLimEnd<dd>The last extremity of the center curve: 
 *<ul><li>if the center curve has several curves: the free extremity
 * of the last curve of the center curve.
 * <li> If the center curve only contains one curve: the last
 * extremity in the natural parameterization of the curve.
 *</ul>
 * </dl>
 * @param iType
 * <dl> <dt>CATLimOffsetFromProfile<dd>No extrapolation for the
 * extremity <tt>iId</tt>
 * <dt>CATLimUntil<dd>The extrapolation of <tt>iId</tt> is done
 * <ul><li>until a given surface: in this case, <tt>iInit</tt> is this surface
 * and <tt>iLimit=0</tt>
 * <li>until a given face of a body: in this case, <tt>iInit</tt> is the
 * face and <tt>iLimit</tt> is the body.
 * </ul>
 * <dt>CATLimNextAlongAxis<dd>The extrapolation of <tt>iId</tt> is done
 * until the first face of the body <tt>iLimit</tt>. In this case,
 * <tt>iLimit=iInit</tt>
 * <dt>CATLimLastAlongAxis<dd>The extrapolation of <tt>iId</tt> is done
 * until the last face of the body <tt>iLimit</tt>. In this case,
 * <tt>iLimit=iInit</tt>
 *</dl>
 * @param iInit
 * The face or body which stops the extrapolation.
 * @param iLimit
 * The body which stops the extrapolation.
 * @param CATDynPropagationType
 *<dl><dt>CATPropagSingle<dd>
 * <dt>CATPropagExtrapolated<dd>
 * <dt>CATPropagClosing<dd>
 *</dl>
 */
  virtual void SetLimit(CATDynLimit iId,
			CATDynLimitType iType,
			CATBoolean IsAxisReverted,
			CATLength iOffset,
			CATGeometry* Init,              // Initialisation de la Propagation
			CATGeometry* Limit,             // Domaine de Propagation
			CATDynPropagationType ) = 0 ;
 
/**
 * Asks for a boolean operation within <tt>this</tt> CATDynSweep operator.
 *<br>In case of a close profile, or an open profile that must be closed within
 * the operation (<tt>SetClosure</tt>).
 */ 
  virtual void SetOperation ( CATDynBooleanType Operation = CATBoolNone ) = 0;
/**
 * Defines the body for the boolean operation to perform within <tt>this</tt> 
 * CATDynSweep operator. 
 * <br>Defines also the closure of the profile.
 */
  virtual void SetTrim      ( CATBody* iTrim = NULL ) = 0;  
  /**
  * Asks for the closure of the profile within <tt>this</tt> CATDynSweep operator.
   */
  virtual void SetClosure   ( CATBoolean isprofile_closed ) = 0; 

/**
 * Asks for the resulting bodies before and after the boolean operation of 
 * <tt>this</tt> CATDynSweep operator. 
 * <br>To be called if <tt>SetOperation</tt> and <tt>SetTrim</tt> have been already called.
 */
  virtual void SetBothResult   (CATBoolean   iBothResultRequired) =0 ; 
};


/** 
 * Global function for the creation of a CATDynSweep operator.
 * @param iContainer
 * The factory of the resulting body.
 * @param iCenter
 * The center curve of the sweep: curve along which the profile is swept.
 * @param iCenterSupport
 * Where the center curve is laying on: must be a plane in a first version.
 * @param iSpine
 * The spine curve of the sweep: the curve that handles the normal to the profile plane.
 * @param iSpineSupport
 * The plane on which the spine curve is laying on.
 * @param iProfile
 * The profile of the sweep.
 * @param iProfileSupport
 * The plane on which the profile is laying on.
 * @param iJournal
 * If not <tt>NULL</tt>, pointer to the topological journal corresponding to this operation.
 */
ExportedByBODYNOPE CATDynSweep* CATDynCreateSweep (CATGeoFactory*     iContainer,
						   const CATLISTP(CATCurve)&           iCenter,
						   CATGeometry*       iCenterSupport,
						   const CATLISTP(CATCurve)&           iSpine,
						   CATPlane*          iSpineSupport,
						   const CATLISTP(CATCurve)&           iProfile,
						   CATPlane*          iProfileSupport,
						   CATCGMJournalList* iJournal=NULL) ;    

#endif
