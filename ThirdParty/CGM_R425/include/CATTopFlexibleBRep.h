#ifndef CATTopFlexibleBRep_H_
#define CATTopFlexibleBRep_H_

// COPYRIGHT DASSAULT SYSTEMES  2006

/**
 * Tags CAA :  a voir... 
 */ 

/**
 * @nocgmitf (do not create phase 2 interface)
 */ 

//
#include "TopExtLight.h"
#include "FlexibleBRep.h"
#include "CATTopFlexMac.h"
#include "CATTopOperator.h"
#include "CATExtCGMReplay.h"

//
#ifndef NULL
#define NULL 0
#endif
#include "CATTopDefine.h"

//
class CATBody;
class CATFace;
class CATEdge;
class CATVertex;

class CATEdgeCurve;
class CATPointOnEdgeCurve;
class CATMathPoint;
class CATSurface;

#include "ListPOfCATFace.h"

/**
* Class defining the Flexible BRep operator on body with given replacing surfaces.
*<br>
* The CATTopFlexibleBRep operator follows the global frame of the topological operators 
* and satisfies the smart mechanism: the input bodies are not modified. A new resulting body 
* is created, possibly sharing data with the input body.
*<ul>
* <li>A CATTopFlexibleBRep operator is created with the <tt>CATCreateFlexibleBRepOperator</tt> global function:
* It must be directly deleted after use with the usual C++ <tt>delete</tt> operator. It is not streamable. 
*<li>Options can be precised with the <tt>SetXxx</tt> methods, before
* asking for the computation with the <tt>Run</tt> method. In particular, an optimized mode
* allows you to do some local operations in union mode.
*<li>In both cases, the result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory. 
*</ul>
*/

/*
* The CATTopFlexibleBRep operator ...
*/
//class ExportedByTopExtLight CATTopFlexibleBRep : public CATTopOperator
class CATTopFlexibleBRep : public CATTopOperator
{

 public:

/**
 * @nodoc
 * Virtual constructor of a CATTopFlexibleBRep operator.<br>
 * Cannot be called. Use the <tt>CATCreateFlexibleBRepOperator</tt> global function
 * to create a CATTopFlexibleBRep operator.
 */
  CATTopFlexibleBRep (CATGeoFactory*     iContainer,
                      CATTopData*        iData,
                      CATExtTopOperator* iExtensible = NULL);

/**
 * Destructor.
 */
  virtual ~CATTopFlexibleBRep();

/**
 * @nodoc
 * Method to call in order to specify the surface to be changed in the input body
 * and the replacing surface which will appear in the result body.
 * Please note : ReplaceWith( CATSurface* iOldSurf, ..) and
 *               ReplaceWith( CATFace*    iOldFace, ..)     can't be used in the same time
 */
  virtual void ReplaceWith( CATSurface* iOldSurf, 
                            CATSurface* iNewSurf);

/**
 * @nodoc
 * Method to call in order to specify the surface to be changed in the input body
 * for a specific Face, and the replacing surface which will appear in the result body
 * for this Face only.
 * Please note : ReplaceWith( CATSurface* iOldSurf, ..) and
 *               ReplaceWith( CATFace*    iOldFace, ..)     can't be used in the same time
 */
  virtual void ReplaceWith( CATFace*        iOldFace, 
                            CATSurface*     iNewSurf,
                            CATSurLimits*   iWorkingDomain = NULL,
                            CATOrientation* iOrientation   = NULL);

/**
 * @nodoc
 * Proto not yet implemented: do not use
 */
  virtual void Remove        ( CATFace*        iOldFace);

  /**
 * @nodoc
 * Proto not yet implemented: do not use
 */
  virtual void RemoveRibbon  ( ListPOfCATFace& iRibbonFaces,
                               double          iFilletRadius);

  
/**
 * @nodoc
 * Method to call in order to specify a Curve for a given edge.
 * Please note : this method is not compatible with the method
 * ReplaceWith( CATSurface* iOldSurf, 
 *              CATSurface* iNewSurf);
 * (but it' ok with  ReplaceWith( CATFace*    iOldFace, ..)
 */
  virtual void SetResCurve( CATEdge*              iEdge, 
                            CATEdgeCurve*         iEC,
                            CATPointOnEdgeCurve*  iStPoec = NULL,
                            CATPointOnEdgeCurve*  iEnPoec = NULL);

/**
 * @nodoc
 * Method to call in order to specify a Curve for a given edge.
 * Please note : this method is not compatible with the method
 * ReplaceWith( CATSurface* iOldSurf, 
 *              CATSurface* iNewSurf);
 * (but it's ok with  ReplaceWith( CATFace*    iOldFace, ..)
 * If iWorkingDomain is once given, it should be given with iOrientation
 * and for all edges specified with SetResCurve.
 */
  virtual void SetResCurve( CATEdge*              iEdge, 
                            CATEdgeCurve*         iEC,
                            CATCrvLimits&         iWorkingDomain,
                        	  CATOrientation        iOrientation);

/**
 * @nodoc
 * Method to call in order to specify that the new curve for the given edge
 * will be tangent to its two surfaces.
 * The two surfaces have to be canonical ones (Plane/Cylinder/Cone/Sphere/Torus). 
 */
  virtual void SetCanonicalTangentEdge( CATEdge*              iEdge);

/**
 * @nodoc
 */
  virtual void SetIsoParametricCurve  ( CATEdge*              iEdge);

/**
 * @nodoc
 */
  virtual void SetLaydownEdge(CATEdge*       iEdge, 
                              CATCurve*      iCurve, 
                              CATCrvLimits&  iWorkingDomain);

/**
 * @nodoc
 * Method to call in order to specify a TargetPoint for a given vertex.
 */
  virtual void SetTargetPoint( CATVertex*    iVertex, 
                               CATMathPoint& iTargetPoint);

/**
 * @nodoc
 * Method to call in order to invalid the Freeze normally performed on the result Body.
 */
  virtual void SetFreezeOff();

/** 
 * @nodoc
 * Internal use only
 */
  //virtual void SetWorkingBody(CATBody* iWorkingBody);

/**
 * @nodoc 
 * Method to call in order to get a full journaling of the modified cells of the input body
 */
  //virtual void SetFullReportMode();
  
/**
 * @nodoc 
 * do not call
 */
  //virtual void SetNonManifoldMode();

/**
 * @nodoc 
 * do not call
 */
  virtual void Set3DSketcherMode();

/**
 * @nodoc 
 * do not call
 */
  virtual void SetCheckResult(short iCheckResult);

/**
 * @nodoc 
 * do not call
 */
  virtual void SetAllowAccessToInvalidCheckedResult();


/**
 * @nodoc 
 * do not call
 */
  virtual void SetSimplifEdgeMode(CATBoolean iSimplif);

/**
 * @nodoc 
 * do not call
 */
  virtual void SetSimplifFaceMode(CATBoolean iSimplif);

/**
 * @nodoc 
 * do not call
 */
 // virtual void SetIsoParametricLevel(short iLevel);

  /**
  * @nodoc
  * Use only for CATIA Switch Geometry
  * Throw an error if SetIsoParametricCurve is not called 
  */
  virtual void SetGapCreationTolerance(double iTol) ;

  /**
  * @nodoc
  * Use only for CATIA Switch Geometry
  * Throw an error if SetIsoParametricCurve is not called 
  */
  virtual void SetErrorDiagnosisLevel(CATFlxDiagLevel iLevel) ;

  /**
  * @nodoc
  */
  virtual void SetEdgeMoveOnly(CATEdge* iEdge);

  /**
  * @nodoc
  */
  virtual void LaydownAllSmoothBorderEdges(CATBoolean iConfusionCase = FALSE,
                                           CATBoolean iReplacingCase = FALSE);


/**
 * @nodoc
 * Method to call in order to get the new faces that have been
 * associated to the input faces
 * NOTE : oInitialFaces is the list of faces given by the ReplaceWith( CATFace*    iOldFace, ..)
 *        method.
 *        oModifiedFaces are the corresponding faces of oInitialFaces in the result body
 *        Faces that have been modified through the ReplaceWith( CATSurface* iOldSurf, ..) method
 *        are not taken in account.
 * Throw an error if called before the Run method.
 */
  virtual void GetModifiedInputFaces( ListPOfCATFace& oModifiedFaces,
                                      ListPOfCATFace& oInitialFaces);

/**
  * @nodoc
  * @nocgmitf (do not create phase 2 interface)  
  * Throw an error if iOldEdge has no image or more than one image
  * in the result body
  * Method for result access : Throw an error if called before the Run method. 
  */
  virtual void GetModifiedEdge(CATEdge*   iOldEdge,
                               CATEdge*&  oNewEdge);

/**
 * @nodoc
 * Method for result's access :  to call afte Run method, an error is thrown otherwise
 * This method provides the invalid body (seen like that with the check method
 * called via SetCheckResult()
 * An error is thrown if SetCheckResult() was not called or has not detected a problem.
 * The body and the journal are given to the caller. Hence their lifecycle has to
 * be managed by the caller.
 * SetAllowAccessToInvalidCheckedResult has to be called in order to sue this method.
 */
  virtual CATBody* GetInvalidResult(CATCGMJournalList*& oJournalForInvalidResult);

  /**
  * @nodoc
  * @nocgmitf (do not create phase 2 interface)  
  * Method for result access : Throw an error if called before the Run method. 
  * Method for result's access :  to call afte Run method, an error is thrown otherwise
  * This method provides help for error diagnosis, correponding to the level set with
  * SetErrorDiagnosisLevel. 
  * An error is thrown if SetErrorDiagnosisLevel() was not called with an appropriate level.
  */
  virtual   void GetUncomputedCells(ListPOfCATCell& oPbCells);


 // -----------------------------------------------------------------------------------
 // CGM Internal Use
 // -----------------------------------------------------------------------------------

private:

/** 
 * @nodoc 
 */
  virtual int RunOperator();

/** 
 * @nodoc 
 */
  virtual CATExtCGMReplay * IsRecordable(short & LevelOfRuntime, short &VersionOfStream);

/** 
 * @nodoc 
 */
  virtual const CATString * GetOperatorId();

/** 
 * @nodoc 
 */
  virtual const CATString * GetDefaultOperatorId();

/** 
 * @nodoc 
 */
  virtual void RequireDefinitionOfInputAndOutputObjects();
  
/** 
 * @nodoc 
 */
  virtual void WriteInput(CATCGMStream &Str);
  
/** 
 * @nodoc 
 */
  virtual void Dump( CATCGMOutput& os );

/** 
 * @nodoc 
 */
  //virtual CATCGMOperator::CATCheckDiagnostic CheckOutput(CATCGMOutput & os);

};



/**
 * Creates a CATTopFlexibleBRep operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * @param iPart
 * The pointer to the body to heal.
 * @return
 * The pointer to the created operator. To delete after use with the usual C++ <tt>delete</tt> operator.
 */
ExportedByFlexibleBRep CATTopFlexibleBRep* CATCreateFlexibleBRepOperator (CATGeoFactory*     iFactory,
                                                                          CATTopData*        iData,
                                                                          CATBody*           iPart);

#endif

