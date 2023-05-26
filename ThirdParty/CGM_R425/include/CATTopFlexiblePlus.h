#ifndef CATTopFlexiblePlus_H_
#define CATTopFlexiblePlus_H_

// COPYRIGHT DASSAULT SYSTEMES  2008

/**
 * Tags CAA :  a voir... 
 */ 

/**
 * @nocgmitf (do not create phase 2 interface)
 */ 

//
#include "TopExtLight.h"
#include "FlexibleBRep.h"
#include "CATTopOperator.h"
#include "CATExtCGMReplay.h"

//
#ifndef NULL
#define NULL 0
#endif
#include "CATTopDefine.h"
#include "CATTopFlexMac.h"

//
class CATBody;
class CATFace;
class CATEdge;
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATVertex.h"

class CATMathTransformation;
class CATSurface;


/**
* Class defining the Flexible Plus operator on body with given replacing surfaces.
* Flexible Plus will perform "the most changes" it can in order to get a result: It
* may forget some of the specified surfaces' changes in order to get a partial result.
*<br>
* The CATTopFlexiblePlus operator follows the global frame of the topological operators 
* and satisfies the smart mechanism: the input bodies are not modified. A new resulting body 
* is created, possibly sharing data with the input body.
*<ul>
* <li>A CATTopFlexiblePlus operator is created with the <tt>CATCreateFlexiblePlusOperator</tt> global function:
* It must be directly deleted after use with the usual C++ <tt>delete</tt> operator. It is not streamable. 
*<li>Options can be precised with the <tt>SetXxx</tt> methods, before asking for the computation 
* with the <tt>Run</tt> method. 
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory. 
*</ul>
*/

/*
* The CATTopFlexiblePlus operator ...
*/
//class ExportedByTopExtLight CATTopFlexiblePlus : public CATTopOperator
class CATTopFlexiblePlus : public CATTopOperator
{

public:

/**
 * @nodoc
 */ 
  enum TransfoType
  {
    FlxMandatory = 0,
    FlxOptional
  };

public:

/**
 * @nodoc
 * Virtual constructor of a CATTopFlexiblePlus operator.<br>
 * Cannot be called. Use the <tt>CATCreateFlexiblePlusOperator</tt> global function
 * to create a CATTopFlexiblePlus operator.
 */
  CATTopFlexiblePlus (CATGeoFactory*     iContainer,
                      CATTopData*        iData,
                      CATExtTopOperator* iExtensible = NULL);

/**
 * Destructor.
 */
  virtual ~CATTopFlexiblePlus();
  
/**
 * @nodoc
 * Method to call in order to specify the tansformation to apply to a list of connex faces in the input body. 
 * An error is thrown in case of non connexity of thes faces in iListFaces.
 * @param iListFaces
 * The list of connex faces to be tranformed.
 * @param iTransfo
 * The 3D transformation to apply to theses faces.
 * @param iListType
 * The list of types that is synchronous with iListFaces
 * It says for each face if the associated transformation is mandatory (0) or optional (1).
 */
  virtual void ReplaceWith( ListPOfCATFace&        iListFaces, 
                            CATMathTransformation& iTransfo,
                            CATListOfInt*          iListType = NULL);

/**
 * @nodoc
 * Method to call in order to specify the surface to be changed in the input body
 * for a specific Face, when no Transformation can be defined otherwise. 
 * Use with caution
 * Please note : If not used in the context of CRT application, this API will Throw an error if iNewSurf 
                  is not a Torus.
 *               Obviously, iOldFace mustn't be present in a previous list of face 
 *               associated to a transformation.
 */
  virtual void ReplaceWith( CATFace*        iOldFace, 
                            CATSurface*     iNewSurf,
                            CATSurLimits*   iWorkingDomain,
                            CATOrientation  iOrientation);

/**
 * @nodoc
 * Method to call in order to specify the tansformation to apply to an edge of the input body.  
 * @param iEdge
 * The edge to be tranformed.
 * @param iTransfo
 * The 3D transformation to apply to the edge.
 * @param iType
 * The type of iTransfo (either FlxMandatory or FlxOptional)
 */
  virtual void ReplaceWith( CATEdge*               iEdge, 
                            CATMathTransformation& iTransfo,
                            TransfoType            iType = FlxMandatory);

/**
 * @nodoc
 * Method to call in order to specify the tansformation to apply to a list of edges of the input body.  
 * @param iListEdges
 * The edges to be tranformed.
 * @param iTransfo
 * The 3D transformation to apply to the edges.
 * @param iListType
 * The list of types that is synchronous with iListEdges
 * It says for each edge if the associated transformation is mandatory (0) or optional (1).
 */
  virtual void ReplaceWith( ListPOfCATEdge&        iListEdges,  
                            CATMathTransformation& iTransfo,
                            CATListOfInt*          iListType = NULL);

/**
 * @nodoc
 * Method to call in order to specify the tansformation to apply to a list of vertices of the input body.  
 * @param iListVertices
 * The vertices to be tranformed.
 * @param iTransfo
 * The 3D transformation to apply to the vertices.
 * @param iListType
 * The list of types that is synchronous with iListVertices
 * It says for each vertex if the associated transformation is mandatory (0) or optional (1).
 */
  virtual void ReplaceWith( ListPOfCATVertex&      iListVertices,  
                            CATMathTransformation& iTransfo,
                            CATListOfInt*          iListType = NULL);

/**
 * @nodoc
 * Method to call in order to specify the new position of a vertex of the input body.  
 * @param iVertex
 * The vertex of the input body.
 * @param iMathPoint
 * The new position of the vertex.
 * @param iType
 * The type that says for each vertex if the associated position is mandatory (0) or optional (1).
 */
  virtual void ReplaceWith( CATVertex*                       iVertex,  
                            CATMathPoint&                    iMathPoint,
                            CATTopFlexiblePlus::TransfoType  iType = CATTopFlexiblePlus::FlxMandatory);

/**
 * @nodoc
 * Method to call in order to compute the new EdgeCurve of the specified edge
 * with a canonical tangent intersection.
 * @param iOldEdge
 * The pointer of an existing edge in the input body.
 * iOldEdge must have two adjacent faces : Face1 and Face2 (Throw otherwise).
 * One of the adjacent face has to be fixed, the other one has to be associated
 * with a transformation.
 * iOldEdge shouldn't be used with ReplaceWith (Throw otherwise).
 * The result surfaces of Face1 and Face2 must be canonical (Plane/Cylinder/Cone/Sphere/Torus)
 * in the result body (Throw otherwise).
 * The result surfaces of Face1 and Face2 must be tangent (Throw otherwise). 
 * If there is an ambiguity in the result of the intersection (for example if the two
 * surfaces are confused, or if there are two 3D solution lines), the method
 * "ReplaceWith( CATVertex*     iOldVertex, CATMathPoint&  iTargetPoint) has to be
 * called for both vertices of iOldEdge (Throw otherwise).
 * There must be a new surface specified for at least one a these faces (Throw otherwise).
 */
  virtual void SetCanonicalTangentEdge(CATEdge* iOldEdge);

/**
 * @nodoc
 * Method dedicated to CRT application: Throw if used in other contexts
 */
  virtual void SetCRT(CATLONG32 iLevel);

/**
 * @nodoc
 * Method dedicated to CRT application: Throw if used in other contexts
 */
  virtual void SetResCurve( CATEdge*              iEdge, 
                            CATEdgeCurve*         iEC,
                            CATPointOnEdgeCurve*  iStPoec = NULL,
                            CATPointOnEdgeCurve*  iEnPoec = NULL);

/**
 * @nodoc
 * Method dedicated to CRT application: Throw if used in other contexts
 */
  virtual void SetLayTransfoBorderEdge(CATEdge*       iEdge);

/**
 * @nodoc
 * Method dedicated to CRT application: Throw if used in other contexts
 */
  virtual void SetLaydownEdge(CATEdge*       iEdge, 
                              CATCurve*      iCurve, 
                              CATCrvLimits&  iWorkingDomain);

/**
 * @nodoc
 * Methods dedicated to CRT application: Throw if used in other contexts:
 * Vanish methods (2), ChangeAdjFace, InflateFold methods (2)
 */
  virtual void Vanish         (CATFace*       iFace);
  
  virtual void Vanish         (CATEdge*       iEdge);  

  virtual void ChangeAdjFace  (CATEdge*       iEdge,
                               CATFace*       iCurAdjFace,
                               CATFace*       iNewAdjFace);

  virtual void InflateEdgFold (CATEdge*       iEdge,
                               CATFace*       iInflateFace,
                               CATEdge*       iNewEdge1,
                               CATFace*       iAdjFace1,                                                              
                               CATEdge*       iNewEdge2,
                               CATFace*       iAdjFace2);

  virtual void InflateEdgFold (CATEdge*       iEdge,
                               CATFace*       iInflateFace,
                               CATOrientation iOrientation,
                               CATEdge*       iNewEdge1,
                               CATFace*       iAdjFace1,                                                              
                               CATEdge*       iNewEdge2,
                               CATFace*       iAdjFace2);

  virtual void InflateVtxFold (CATVertex*     iVertex,
                               CATEdge*       iInflateEdge1,
                               CATFace*       iAdjFace1,
                               CATEdge*       iInflateEdge2 = NULL,
                               CATFace*       iAdjFace2     = NULL);

/**
 * @nodoc
 * Method to call in order to have a body attached to the error 
 */
  virtual void SetErrorBodyRequired();

/**
 * @nodoc
 * Method to call in order to invalid the Freeze normally performed on the result Body.
 */
  virtual void SetFreezeOff();

 /**
  * @nodoc
  * Forbidden usage
  * Use only for internal CGM debug soft only  
  */
  virtual void SetGapCreationTolerance(double iTol) ;


/**
 * @nodoc
 * Return TRUE if all transformations have been succesfully applied to the input body,
 *        FALSE otherwise
 */
  virtual CATBoolean ResultIsComplete();

/**
 * @nodoc
 * Return TRUE if all transformations have not been succesfully applied to the input body,
 *                and if at least one of the transformation has been successfull.
 *        FALSE otherwise
 */
  virtual CATBoolean ResultIsPartial();

/**
 * @nodoc
 * Method to call in order to get the faces that are still to transform.
 * Method to call after RunOperator.
 * @param oResidualFaces
 * The list of faces in the result body that are still to transform. 
 * @param oOrigFaces
 * The synchronized list of faces in the input body. 
 */
  virtual void GetResidualFaces( ListPOfCATFace& oResidualFaces,
                                 ListPOfCATFace& oInitialFaces);

/**
 * @nodoc
 * Method to call in order to get the result body when autocheck
 * has been interrupted during the validation process.
 * Method to call after RunOperator.
 * If there has been no interruption, method will throw an error.
 * @param oJournalForInterruptedCheckResult
 * The journal associated to the result body.  
 */    
  virtual CATBody* GetInterruptedCheckResult(CATCGMJournalList*& oJournalForInterruptedCheckResult);

/**
 * @nodoc 
 * @nocgmitf
 * do not call
 */
  virtual CATBody* GetInvalidResult(CATCGMJournalList*& oJournalForInvalidResult);

/**
 * @nodoc 
 * do not call
 */
  virtual void SetCheckResult(short iCheckResult);


 // -----------------------------------------------------------------------------------
 // CGM Internal Use
 // -----------------------------------------------------------------------------------

/**
 * @nodoc 
 * @nocgmitf
 * do not call
 */
  virtual void SetAATICR();

/**
 * @nodoc 
 * @nocgmitf
 * do not call
 */
  virtual void SetMeanDimension();

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
 * Creates a CATTopFlexiblePlus operator.
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
ExportedByFlexibleBRep CATTopFlexiblePlus* CATCreateFlexiblePlusOperator (CATGeoFactory*     iFactory,
                                                                          CATTopData*        iData,
                                                                          CATBody*           iPart);

#endif

