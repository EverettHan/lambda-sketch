/* -*-c++-*- */
#ifndef CATTopSweepWireSkinCircle_h
#define CATTopSweepWireSkinCircle_h

// COPYRIGHT DASSAULT SYSTEMES 2001

/**
 * @level Protected
 * @usage U1
 */ 

#include <Fillet.h>

#include "CATTopSweepWireSkin.h"
#include "CATLaw.h"

/**
 * Class defining the topological operator that creates a sweep between a skin body and a wire body.
 *<br>The sweep is defined by
 * <ul>
 * <li>a skin body, to which the generated sweep is tangent and defining the first extremity of the sweep.
 * <li>a wire guide, defining the second extremity.
 * <li>a spine wire body:  defines the moving plane (orthogonal to the spine) that is
 * swept along the spine. In this moving plane, the sweep is an arc of circle tangent to the skin body 
 * and limited by the wire body.
 * </ul>
 * As several solutions can be found, signatures are defined to distinguish them
 * <ul>
 * <li>signature with regards to the skin orientation: the solution is on the semi-space defined by the
 * normal to the skin, or in the opposite semi-space, or in both.
 * <li>signature with respect to the wire orientation: the wire, the normal to the skin and the tangent
 * to the profile are counter clockwise or not.
 * <li>for a same skin and wire signatures, the rank of the solution.
 * </ul>
 * This operator follows the general scheme of the topological operators producing several resulting bodies:
 * <ul>
 *<li> Create the operator with the global function <tt>CATTopCreateSweepWireSkinCircle</tt>,
 *<li> Set the parameters,
 *<li> Run,
 *<li> Get the resulting bodies (in this case, use the iterator on the resulting bodies, because
 * several bodies can be solution of the computation).
 *<li> Delete the operator.
 *</ul>
 * Sample:
 * <pre> 
 * CATTopSweepWireSkinCircle * pOp =  CATCreateTopSweepWireSkinCircleVariable(factory, Skin, Wire, Spine, Law);
 * pOp->Run();
 * pOp->BeginningResult();
 * int nbBodies = pOp->GetNumberOfResults();
 * for (int iBody = 1 ; iBody <= nbBodies ; iBody ++)
 * {
 *   pOp->NextResult();
 *   CATBody * pCurBody = pOp->GetResult();
 * }  
 * delete pOp;
 *</pre>
 */

class CATTopSweepWireSkinCircle : public CATTopSweepWireSkin
{
  CATCGMVirtualDeclareClass(CATTopSweepWireSkinCircle);
public:

/*
 * @nodoc 
 *
 * WARNING: DO NOT USE this deprecated constructor
 * USE CATCreateTopSweepWireSkinCircle to create class object
 *
 */
  CATTopSweepWireSkinCircle(CATGeoFactory   * iFactory,
                            CATTopData      * iData,
                            CATBody         * iSupportShell,
                            CATBody         * iGuide,
                            CATBody         * iSpine,
                            double            iRadius);

/*
 * @nodoc 
 *
 * WARNING: DO NOT USE this deprecated constructor
 * USE CATCreateTopSweepWireSkinCircle to create class object
 *
 */
  CATTopSweepWireSkinCircle(CATGeoFactory   * iFactory,
                            CATTopData      * iData,
                            CATBody         * iSupportShell,
                            CATBody         * iGuide,
                            CATBody         * iSpine,
                            CATLaw          * iRadiusLaw,
                            CATBoolean        iRemoveGuide=FALSE, 
                            CATBoolean        iRemoveSpine=FALSE);

/** @nodoc */
  ~CATTopSweepWireSkinCircle();

/** @nodoc */
  int Run();

/** @nodoc */
  CATSweepProfileInfo * GetProfileInfo();

/** @nodoc @nocgmitf */
  const CATString * GetOperatorId();

/** @nodoc @nocgmitf */
  static const CATString * GetDefaultOperatorId() { return & _OperatorId; };

private:
  double _Radius;
  CATLaw * _RadiusLaw;
  CATBoolean _RemoveGuide;
  CATBoolean _RemoveSpine;

protected:
  //For CGMReplay : SOU 
/** @nodoc */
  static CATString _OperatorId;

/** @nodoc */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);

/** @nodoc */
  void WriteInput(CATCGMStream  & ioStream);

/** @nodoc */
  void Dump( CATCGMOutput& os ) ;

/** @nodoc */
  int RunOperator();

/** @nodoc */
  void RequireDefinitionOfInputAndOutputObjects();

/** @nodoc */
  void DumpOutput( CATCGMOutput& os ) ;

/** @nodoc */
  CATCGMOperator::CATCheckDiagnostic  CheckOutput(CATCGMOutput & os);

};

/** @nodoc */
ExportedByFillet 
CATTopSweepWireSkinCircle *
CATCreateTopSweepWireSkinCircle (CATGeoFactory * iFactory,
                                 CATTopData *    iData,
                                 CATBody *       iSupportShell,
                                 CATBody *       iGuide,
                                 CATBody *       iSpine,
                                 double          iRadius);

/** @nodoc */
ExportedByFillet 
CATTopSweepWireSkinCircle *
CATCreateTopSweepWireSkinCircle (CATGeoFactory * iFactory,
                                 CATTopData *    iData,
                                 CATBody *       iSupportShell,
                                 CATBody *       iGuide,
                                 CATBody *       iSpine,
                                 CATLaw  *       iRadiusLaw,
                                 CATBoolean      iRemoveGuide=FALSE, 
                                 CATBoolean      iRemoveSpine=FALSE
);


#endif
