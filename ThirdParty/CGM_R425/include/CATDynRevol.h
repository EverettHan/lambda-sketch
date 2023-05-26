#ifndef CATDynRevol_H_
#define CATDynRevol_H_

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATDynOperator.h"
#include <CATMathDef.h>
#include <CATListOfCATCurves.h>
#include "CATMathAxis.h"


class CATMathDirection;
class CATBody;
class CATPlane;
class CATGeometry;
class CATBody;
class CATTopData;


struct ExportedByBODYNOPE CATDynRevolLimit
{   
  CATDynLimitType        Type;
  CATLength              Offset;
  CATGeometry*           Init;
  CATGeometry*           Limit;
  CATDynPropagationType  Propag;
};

/**
 * Interface representing the topological operator of creation of a revolution body.
 * As all the topological operators, the input bodies are not modified. The resulting body is
 * a new one, that you can get by using the <tt>CATDynOperator::GetResult</tt> method.<br>
 */

class ExportedByBODYNOPE CATDynRevol : public CATDynOperator
{
 public:
	 /**
 * Virtual constructor of a CATDynRevol operator.<br>
 * Can never be called. Use the <tt>CATDynCreateRevol</tt> global function
 * to create a CATDynRevol operator.
 */
  CATDynRevol(CATGeoFactory * iFactory, CATCGMJournalList* journal=NULL);
  CATDynRevol(CATGeoFactory * iFactory, CATTopData * iTopData);
  virtual ~CATDynRevol();
/**
 * Defines the type of limitation of each extremity of the profile.
 * @param iId
 * The extremity for which the limit is defined.
 * <dl> <dt>CATLimStart<dd>The first extremity of the profile: 
 *<ul><li>if the profile has several curves: the free extremity
 * of the first curve of the profile.
 * <li> If the profile only contains one curve: the first
 * extremity in the natural parameterization of the curve.
 *</ul>
 * <dt>CATLimEnd<dd>The last extremity of the profile: 
 *<ul><li>if the profile has several curves: the free extremity
 * of the last curve of the profile.
 * <li> If the profile only contains one curve: the last
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
 * ...
 *<dl><dt>CATPropagSingle<dd>
 * <dt>CATPropagExtrapolated<dd>
 * <dt>CATPropagClosing<dd>
 *</dl>
 */
  virtual void SetLimit(CATDynLimit           iId,
                        CATDynLimitType       iType,
			               CATLength             iOffset,
                        CATGeometry*          iInit,        // Initialisation de la Propagation
                        CATGeometry*          iLimit,       // Domaine de Propagation
                        CATDynPropagationType iPropag)   = 0;
 
  virtual void SetOperation (CATDynBooleanType iOperation = CATBoolNone ) = 0;
  virtual void SetTrim      (CATBody*          iTrim = NULL )      = 0;  
  virtual void SetClosure   (CATBoolean        isprofile_closed )  = 0;
  virtual void SetBothResult(CATBoolean        iBothResultRequired) =0 ; 
};


// Creation EntryPoints
/**
 * Creates a CATDynBoolean operator.
 * @param iForResultingBody
 * Where to create the resulting CATBody. 
 * @param iProfile
 * The list of curves for the definition of the profile of the revolution. The curves must
 * be contiguous. They are projected on the <tt>iSupport</tt> plane.
 * @param iAxis
 * The axis (C, x, y, z) of the revolution. The revolution rotates around the third 
 * direction of <tt>iAxis</tt>.
 * @param iStartAngle
 * The start angle, measured on the <tt>Cxy</tt> plane, from the <tt>Cx</tt> axis.
 * @param iEndAngle
 * The end angle, measured on the <tt>Cxy</tt> plane, from the <tt>Cx</tt> axis.
 * <tt>iStartAngle < iEndAngle </tt>.
 * @param iSupport
 * The plane on which the curves of <tt>iProfile</tt> are projected. This plane
 * must pass through the <tt>Cz</tt> line.
 * @param iJournal
 * A pointer to the topological journal. If NULL, no line will be writen.
 */
ExportedByBODYNOPE CATDynRevol* CATDynCreateRevol(CATGeoFactory            * iFactory,
						                                const CATLISTP(CATCurve) & iProfile,
						                                CATMathAxis&               iAxis,
						                                CATAngle                   iStartAngle,
						                                CATAngle                   iEndAngle,
						                                CATPlane*                  iSupport,
                                                  CATCGMJournalList*         iJournal=NULL);    

ExportedByBODYNOPE CATDynRevol* CATDynCreateRevol(CATGeoFactory            * iFactory,
                                                  CATTopData               * iTopData,
						                                const CATLISTP(CATCurve) & iProfile,
						                                CATMathAxis&               iAxis,
						                                CATAngle                   iStartAngle,
						                                CATAngle                   iEndAngle,
						                                CATPlane*                  iSupport);    

#endif
