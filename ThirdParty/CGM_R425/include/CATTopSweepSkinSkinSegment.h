#ifndef CATTopSweepSkinSkinSegment_H
#define CATTopSweepSkinSkinSegment_H

// COPYRIGHT DASSAULT SYSTEMES 2001
/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */ 

#include <Fillet.h>

#include "CATDynFilletRibbon.h"
#include "CATTopMultiResult.h"
#include "CATIACGMLevel.h"
#include "CATFilletReconfigFillFunction.h"

#ifndef CATIACGMR422CAA
#include "ListPOfCATBody.h"
#endif

class CATShell;
class CATWire;
class CATSweepInit;
class CATSweepTopOp;
class CATSweepProfileInfo;
class CATTopSweepSkinSkinSegment;

/**
*  ***********************************************************************
*  *******                         WARNING                         *******
*  ***********************************************************************
*  *******
*  *******  This class is Not supported any longer.
*  *******  it has been replaced by CATICGMTopSweepSkinSkinSegment
*  *******
*  *******
*  ***********************************************************************
*  ***********************************************************************
*  CATTopSweepSkinSkinSegment class has been removed from CAA in 3DEXPERIENCE level and
*  has been replaced by CATICGMTopSweepSkinSkinSegment.
*  We recommend you to use only CATICGMTopSweepSkinSkinSegment, in order you will  be
*  able to easily migrate   your CAA code from  V5 to 3DEXPERIENCE level
*
*  **************************************************************************
*
 * Creates a CATTopSweepSkinSkinSegment operator.
 * @param iFactory
 * The pointer to the geometry factory that creates the result bodies.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * @param iFirstSupportShell
 * The pointer to the first skin body.
 * @param iSecondSupportShell
 * The pointer to the second skin body.
 * @param iSpine
 * The pointer to the spine body. Each segment section is in the plane normal to this spine curve.
 * @return
 * The pointer to the created operator. To delete after use, with the usual C++ <tt>delete</tt>
 * operator.
 */
ExportedByFillet 
CATTopSweepSkinSkinSegment* 
CATCreateTopSweepSkinSkinSegment (CATGeoFactory * iFactory,
                                  CATTopData *    iData,
                                  CATBody *       iFirstSupportShell,
                                  CATBody *       iSecondSupportShell,
                                  CATBody *       iSpine);

/**
 * Class defining the topological operator that creates a sweep between a two skin bodies.
 *<br>The sweep is defined by
 * <ul>
 * <li>a skin body, to which the generated sweep is tangent and defining the first extremity of the sweep.
 * <li>a skin body, to which the generated sweep is tangent and defining the second extremity of the sweep..
 * <li>a spine wire body:  defines the moving plane (orthogonal to the spine) that is
 * swept along the spine. 
 * </ul>
 * As several solutions can be found, signatures are defined to distinguish them
 * <ul>
 * <li>signature with regards to the skin orientation: the solution is on the semi-space defined by the
 * normal to the skin, or in the opposite semi-space, or in both.
 * <li>for a same skin1 and skin2 signatures, the rank of the solution.
 * </ul>
 * This operator follows the general scheme of the topological operators producing several resulting bodies:
 * <ul>
 *<li> Create the operator with the global function @href CATCreateTopSweepSkinSkinSegment 
 *<li> Set the parameters,
 *<li> Run,
 *<li> Get the resulting bodies (in this case, use the iterator on the resulting bodies, because
 * several bodies can be solution of the computation).
 *<li> Delete the operator with the usual C++ <tt>delete</tt> operator.
 *</ul>
 * Sample:
 * <pre> 
 * CATTopSweepSkinSkinSegment * pOp =  CATCreateTopSweepSkinSkinSegment(factory,Skin1,Skin2,Spine);
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
class ExportedByFillet CATTopSweepSkinSkinSegment : public CATTopMultiResult
{
  CATCGMVirtualDeclareClass(CATTopSweepSkinSkinSegment);
 public:

  virtual ~CATTopSweepSkinSkinSegment();

/**
 * Defines the signature of the desired results with regards to the first skin orientation.
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
#ifndef CATIACGMR422CAA
  virtual void SetFirstShellOrientation(const int iOrientation);
#else 
  virtual void SetFirstShellOrientation(const int iOrientation) = 0;
#endif
/**
 * Defines the signature of the desired results with regards to the second skin orientation.
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
#ifndef CATIACGMR422CAA
  virtual void SetSecondShellOrientation(const int iOrientation);
#else
  virtual void SetSecondShellOrientation(const int iOrientation) = 0;
#endif
/**
 * Defines the signature of the desired results with regards to the first coulped orientation.
 * @param iOrientation
 * The orientation of the trihedron defined by the the spine, the normal to the first skin and
 * the tangent to the profile.
 *<br><b>Legal values</b>:
 * <dl>
 * <dt> <tt>1</tt></dt><dd> The output results are such that the triedron is counter clockwise.
 * <dt><tt>-1</tt></dt><dd> The output results are such that the triedron is clockwise.
 * <dt> <tt>0</tt></dt><dd> All the results must be output (<tt>1</tt>, <tt>-1</tt>, <tt>2</tt> cases all together).
 * <dt> <tt>2</tt></dt><dd> The orientation of the trihedron changes along the spine. 
 * </dl>
 */
#ifndef CATIACGMR422CAA
  virtual void SetFirstCoupledOrientation(const int iOrientation);
#else 
  virtual void SetFirstCoupledOrientation(const int iOrientation) = 0;
#endif
/**
 * Defines the signature of the desired results with regards to the second coulped orientation.
 * @param iOrientation
 * The orientation of the trihedron defined by the the spine, the normal to the second skin and
 * the tangent to the profile.
 *<br><b>Legal values</b>:
 * <dl>
 * <dt> <tt>1</tt></dt><dd> The output results are such that the triedron is counter clockwise.
 * <dt><tt>-1</tt></dt><dd> The output results are such that the triedron is clockwise.
 * <dt> <tt>0</tt></dt><dd> All the results must be output (<tt>1</tt>, <tt>-1</tt>, <tt>2</tt> cases all together).
 * <dt> <tt>2</tt></dt><dd> The orientation of the trihedron changes along the spine. 
 * </dl>
 */
#ifndef CATIACGMR422CAA
  virtual void SetSecondCoupledOrientation(const int iOrientation);
#else 
  virtual void SetSecondCoupledOrientation(const int iOrientation) = 0;
#endif
 /** @nodoc 
 * Set function for untwist capability
 */
#ifndef CATIACGMR422CAA
  void SetReconfigFillFunction (CATFilletReconfigFillFunction iFillFct);
#else 
  virtual void SetReconfigFillFunction (CATFilletReconfigFillFunction iFillFct) = 0;
#endif
/** @nodoc 
 * Get function for untwist capability
 */
#ifndef CATIACGMR422CAA
  CATFilletReconfigFillFunction GetFilletReconfigFillFunction () const;
#else 
  virtual CATFilletReconfigFillFunction GetFilletReconfigFillFunction () const = 0;
#endif
/**
 * Retrieves the signature relative to the current resulting body.
 * @param ioFirstShellOrientation
 * The signature with regards to the first skin orientation.
 *<br><b>Legal values</b>:
 * <dl>
 * <dt> <tt>1</tt></dt><dd> The results are in the semi-space defined by the normal to the skin.
 * <dt><tt>-1</tt></dt><dd> The results are in the semi-space defined by the opposite to the normal to the skin.
 * <dt> <tt>0</tt></dt><dd> All the results must be output (<tt>1</tt>, <tt>-1</tt>, <tt>2</tt> cases all together).
 * <dt> <tt>2</tt></dt><dd> The results change of semi-space along the spine. 
 * </dl>
 * @param ioSecondShellOrientation
 * The signature with regards to the second skin orientation.
 *<br><b>Legal values</b>:
 * <dl>
 * <dt> <tt>1</tt></dt><dd> The results are in the semi-space defined by the normal to the skin.
 * <dt><tt>-1</tt></dt><dd> The results are in the semi-space defined by the opposite to the normal to the skin.
 * <dt> <tt>0</tt></dt><dd> All the results must be output (<tt>1</tt>, <tt>-1</tt>, <tt>2</tt> cases all together).
 * <dt> <tt>2</tt></dt><dd> The results change of semi-space along the spine. 
 * </dl>
 * @param oCoupledFirstOrientation
 * The orientation of the trihedron defined by the the spine, the normal to the first skin and
 * the tangent to the profile.
 *<br><b>Legal values</b>:
 * <dl>
 * <dt> <tt>1</tt></dt><dd> The output results are such that the triedron is counter clockwise.
 * <dt><tt>-1</tt></dt><dd> The output results are such that the triedron is clockwise.
 * <dt> <tt>0</tt></dt><dd> All the results must be output (<tt>1</tt>, <tt>-1</tt>, <tt>2</tt> cases all together).
 * <dt> <tt>2</tt></dt><dd> The orientation of the trihedron changes along the spine. 
 * </dl>
 * @param oCoupledSecondOrientation
 * The orientation of the trihedron defined by the the spine, the normal to the second skin and
 * the tangent to the profile.
 *<br><b>Legal values</b>:
 * <dl>
 * <dt> <tt>1</tt></dt><dd> The output results are such that the triedron is counter clockwise.
 * <dt><tt>-1</tt></dt><dd> The output results are such that the triedron is clockwise.
 * <dt> <tt>0</tt></dt><dd> All the results must be output (<tt>1</tt>, <tt>-1</tt>, <tt>2</tt> cases all together).
 * <dt> <tt>2</tt></dt><dd> The orientation of the trihedron changes along the spine. 
 * </dl>
 * @param ioIndex
 * The rank (beginning at <tt>1</tt>) of the current body inside a given quadruple 
 * (<tt>ioFirstShellOrientation, ioSecondShellOrientation, oCoupledFirstOrientation, oCoupledSecondOrientation</tt>)
 */ 
#ifndef CATIACGMR422CAA
  virtual void GetResultInformation(int & ioFirstShellOrientation,
                                    int & ioSecondShellOrientation,
                                    int & oCoupledFirstOrientation,
                                    int & oCoupledSecondOrientation,
                                    int & ioIndex);
#else
  virtual void GetResultInformation(int & ioFirstShellOrientation,
                                    int & ioSecondShellOrientation,
                                    int & oCoupledFirstOrientation,
                                    int & oCoupledSecondOrientation,
                                    int & ioIndex) = 0;
#endif

/**
 * Runs <tt>this</tt> operator.
 * <br>To retrieve the resulting bodies, use the iterator on the bodies provided by @href CATTopMultiResult.
 */
#ifndef CATIACGMR422CAA
  virtual int Run();
#else 
  virtual int Run() = 0;
#endif

/** @nodoc */
#ifndef CATIACGMR422CAA
  virtual CATSweepProfileInfo * GetProfileInfo();
#else
  virtual CATSweepProfileInfo * GetProfileInfo() = 0;
#endif

/**
 * @nodoc
 *
 * WARNING: DO NOT USE this deprecated constructor
 * USE CATCreateTopSweepSkinSkinSegment to create class object
 *
 * Constructs a CATTopSweepSkinSkinSegment operator.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iFirstSupportShell
 * The pointer to the first skin body
 * @param iSecondSupportShell
 * The pointer to the second skin body
  * @param iSpine
 * The pointer to the spine wire body, defining the moving plane.
 */
  CATTopSweepSkinSkinSegment(CATGeoFactory   * iFactory,
                      CATTopData      * iData,
                      CATBody         * iFirstSupportShell,
                      CATBody         * iSecondSupportShell,
                      CATBody         * iSpine);
					  
#ifdef CATIACGMR422CAA
/**
 * @nodoc
 * Constructs a CATTopSweepSkinSkinSegment operator.
 * @param iFactory
 * The pointer to the factory of the geometry.
 */					  
  CATTopSweepSkinSkinSegment(CATGeoFactory   * iFactory,
                      CATTopData      * iData);
#endif

/** 
 * Defines the mode chosen for first skin
 * @param iMode
 * The segmentation mode (trim - no trim - trim on support)
 */
#ifndef CATIACGMR422CAA
  void SetFirstShellModeTrim(CATDynSegmentationMode iMode);
#else 
  virtual void SetFirstShellModeTrim(CATDynSegmentationMode iMode) = 0;
#endif

/** 
 * Defines the mode chosen for second skin
 * @param iMode
 * The segmentation mode (trim - no trim - trim on support)
 */
#ifndef CATIACGMR422CAA
  void SetSecondShellModeTrim(CATDynSegmentationMode iMode);
#else 
  virtual void SetSecondShellModeTrim(CATDynSegmentationMode iMode) = 0;
#endif

#ifndef CATIACGMR422Code
  /** @nodoc @nocgmitf */
  static const CATString * GetDefaultOperatorId() { return & _OperatorId; };
#endif

#ifndef CATIACGMR422CAA

 protected:

/** @nodoc */
  CATSweepProfileInfo * _ProfileInfo;
/** @nodoc */
  CATBody             * _FirstSupportShell;
/** @nodoc */
  int                   _FirstShellOrientation;
/** @nodoc */
  CATBody             * _SecondSupportShell;
/** @nodoc */
  int                   _SecondShellOrientation;

/** @nodoc */
  int                   _FirstCoupledOrientation;
/** @nodoc */
  int                   _SecondCoupledOrientation;
/** @nodoc */
  CATFilletReconfigFillFunction   _ReconfigFillFct;

/** @nodoc */
  CATBody             * _Spine;
/** 
 * @nodoc 
 * Array of 3 int per result, giving the index and the orientations.
 */
  int * _info;  
  
/** @nodoc */
  static CATString _OperatorId;

/** @nodoc */
  const CATString * GetOperatorId();

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

/** 
 * @nodoc 
 * Variable for first shell mode
 */
  CATDynSegmentationMode _Trim1;

/** 
 * @nodoc 
 * Variable for second shell mode
 */
  CATDynSegmentationMode _Trim2;
#endif // CATIACGMR422CAA
};

#endif

