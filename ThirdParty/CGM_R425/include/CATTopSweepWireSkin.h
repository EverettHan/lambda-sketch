#ifndef CATTopSweepWireSkin_h
#define CATTopSweepWireSkin_h

// COPYRIGHT DASSAULT SYSTEMES 2001
/**
 * @level Protected
 * @usage U1
 */ 

#include <Fillet.h>

#include "CATTopMultiResult.h"
#include "CATIAV5Level.h"
#include "CATFilletReconfigFillFunction.h"

class CATSweepProfileInfo;

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
 *<li> Create the operator with the global function @href CATCreateTopSweepWireSkinCircle 
 *<li> Set the parameters,
 *<li> Run,
 *<li> Get the resulting bodies (in this case, use the iterator on the resulting bodies, because
 * several bodies can be solution of the computation).
 *<li> Delete the operator with the usual C++ <tt>delete</tt> operator.
 *</ul>
 * Sample:
 * <pre> 
 * CATTopSweepWireSkinCircle * pOp =  CATCreateTopSweepWireSkinCircle(factory,Skin,Wire,Spine);
 * pOp->Run();
 * pOp->BeginningResult();
 * int nbBodies = pOp->GetNumberOfResults();
 * for (int iBody = 1 ; iBody <= nbBodies ; iBody ++)
 * {
 *   pOp->NextResult();
 *   CATBody * pCurBody = pOp->GetResult(pReport);
 * }  
 * delete pOp;
 *</pre>
 */

class ExportedByFillet CATTopSweepWireSkin : public CATTopMultiResult
{
  CATCGMVirtualDeclareClass(CATTopSweepWireSkin);
 public:

  virtual ~CATTopSweepWireSkin();

/**
 * Defines the signature of the desired results with regards to the skin orientation.
 * @param iOrientation
 * The semi-space to which the solution belongs.
 *<br><b>Legal values</b>:
 * <dl>
 * <dt> <tt>1</tt></dt><dd> The results are in the semi-space defined by the normal to the skin.
 * <dt><tt>-1</tt></dt><dd> The results are in the semi-space defined by the opposite to the normal to the skin.
 * <dt> <tt>0</tt></dt><dd> All the results must be output (<tt>1</tt>, <tt>-1</tt>, <tt>2</tt> cases all together).
 * <dt> <tt>2</tt></dt><dd> The results change of semi-space along the spine. 
 * </dl>
 */
  virtual void SetShellOrientation(const int iOrientation);

/**
 * Defines the signature of the desired results with regards to the wire orientation.
 * @param iOrientation
 * The orientation of the trihedron defined by the the wire, the normal to the skin and
 * the tangent to the profile.
 *<br><b>Legal values</b>:
 * <dl>
 * <dt> <tt>1</tt></dt><dd> The output results are such that the triedron is counter clockwise.
 * <dt><tt>-1</tt></dt><dd> The output results are such that the triedron is clockwise.
 * <dt> <tt>0</tt></dt><dd> All the results must be output (<tt>1</tt>, <tt>-1</tt>, <tt>2</tt> cases all together).
 * <dt> <tt>2</tt></dt><dd> The orientation of the trihedron changes along the spine. 
 * </dl>
 */
  virtual void SetGuideOrientation(const int iOrientation);

/**
 * Retrieves the signature relative to the current resulting body.
 * @param ioShellOrientation
 * The signature with regards to the skin orientation.
 *<br><b>Legal values</b>:
 * <dl>
 * <dt> <tt>1</tt></dt><dd> The results are in the semi-space defined by the normal to the skin.
 * <dt><tt>-1</tt></dt><dd> The results are in the semi-space defined by the opposite to the normal to the skin.
 * <dt> <tt>0</tt></dt><dd> All the results must be output (<tt>1</tt>, <tt>-1</tt>, <tt>2</tt> cases all together).
 * <dt> <tt>2</tt></dt><dd> The results change of semi-space along the spine. 
 * </dl>
 * @param ioWireOrientation
 * The signature with regards to the wire orientation.
 *<br><b>Legal values</b>:
 * <dl>
 * <dt> <tt>1</tt></dt><dd> The output results are such that the triedron is counter clockwise.
 * <dt><tt>-1</tt></dt><dd> The output results are such that the triedron is clockwise.
 * <dt> <tt>0</tt></dt><dd> All the results must be output (<tt>1</tt>, <tt>-1</tt>, <tt>2</tt> cases all together).
 * <dt> <tt>2</tt></dt><dd> The orientation of the trihedron changes along the spine. 
 * </dl>
 * @param ioIndex
 * The rank (beginning at <tt>1</tt>) of the current body inside 
 * a given couple (<tt>ioShellOrientation, ioWireOrientation</tt>)
 */ 
  virtual void GetResultInformation(int & ioShellOrientation,
                                    int & ioWireOrientation,
                                    int & ioIndex);


/**
 * Runs <tt>this</tt> operator.
 * <br>To retrieve the resulting bodies, use the iterator on the bodies provided by @href CATTopMultiResult.
 */
  virtual int Run();

/** @nodoc */
  virtual CATSweepProfileInfo * GetProfileInfo();

/**
 * @nodoc
 *
 * WARNING: DO NOT USE this deprecated constructor
 * USE CATCreateTopSweepWireSkinSegment to create class object
 * 
 * Constructs a CATTopSweepWireSkin operator.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iSkin
 * The pointer to the skin body, to which the created sweep is tangent.
 * @param iWire
 * The pointer to the wire body, second extremity of the sweep.
 * @param iSpine
 * The pointer to the spine wire body, defining the moving plane.
 */
  CATTopSweepWireSkin(CATGeoFactory   * iFactory,
                      CATTopData      * iData,
                      CATBody         * iSupportShell,
                      CATBody         * iGuide,
                      CATBody         * iSpine);

/** 
 * @nodoc 
 *
 * WARNING: DO NOT USE this deprecated constructor
 * USE CATCreateTopSweepWireSkinSegment to create class object
 *
 * Use now the signature with CATTopData.
 */
  CATTopSweepWireSkin(CATGeoFactory   * iFactory,
                      CATBody         * iSupportShell,
                      CATBody         * iGuide,
                      CATBody         * iSpine);

/** @nodoc 
 * Defines the mode chosen:trim or no trim
 * @param iMode
 *<br><b>Legal values</b>:
 * <dl>
 * <dt> <tt>1</tt></dt><dd> for Trim.
 * <dt> <tt>0</tt></dt><dd> for No Trim
 * </dl>
 */
  void SetModeTrim(const int iMode);

/** @nodoc 
 * Set function for untwist capability
 */
  void SetReconfigFillFunction (CATFilletReconfigFillFunction iFillFct);

/** @nodoc 
 * Get function for untwist capability
 */
  CATFilletReconfigFillFunction GetFilletReconfigFillFunction () const;

/** @nodoc @nocgmitf */
  const CATString * GetOperatorId();
  
 protected:

/** @nodoc */
  CATSweepProfileInfo * _ProfileInfo;
/** @nodoc */
  CATBody             * _SupportShell;
/** @nodoc */
  int                   _ShellOrientation;
/** @nodoc */
  CATBody             * _Guide;
/** @nodoc */
  int                   _GuideOrientation;
/** @nodoc */
  CATBody             * _Spine;
/** 
 * @nodoc 
 * Array of 3 int per result, giving the index and the orientations.
 */
  int * _info;  
/** 
 * @nodoc 
 * Variable for mode Trim(1) or NoTrim(0)
 */
  int _Trim;

/** 
 * @nodoc 
 * Function for untwist
 */
  CATFilletReconfigFillFunction   _ReconfigFillFct;

  // For CGMReplay : SOU
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


#endif
