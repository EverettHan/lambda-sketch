#ifndef CATTopHealOperator_H_
#define CATTopHealOperator_H_

// COPYRIGHT DASSAULT SYSTEMES  2004

/**
 */ 

/**
 * Tags CAA :  a voir... 
 */ 

//
#include "TopExtLight.h"
#include "TopHeal.h"
#include "CATTopOperator.h"
#include "CATExtCGMReplay.h"

//
#ifndef NULL
#define NULL 0
#endif

//
class CATBody;
class CATShell;
class CATEdge;
class CATVertex;

//
class CATMathPoint;
class CATCurve;
class CATGeoFactory;
class CATTopData;

//
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "CATListOfCATSurfaces.h"

/**
* Class defining the Topological Healing operator on body with given scars to be treated.
* Topological Healing will not modify the input surfaces, only the curves will be recomputed.
* Hence, only the tangency component gap will be healed, and the normal component will remain.
* Please use the Geometrical Healing in order to modify the surfaces and heal all components of the gaps.
*<br>
* The CATTopHealOperator operator follows the global frame of the topological operators 
* and satisfies the smart mechanism: the input bodies are not modified. A new resulting body 
* is created, possibly sharing data with the input body.
*<ul>
* <li>A CATTopHealOperator operator is created with the <tt>CATCreateTopHealOperator</tt> global function:
* It must be directly deleted after use with the usual C++ <tt>delete</tt> operator. It is not streamable. 
*<li>Options can be precised with the <tt>SetXxx</tt> methods, before
* asking for the computation with the <tt>Run</tt> method.
*<li>In both cases, the result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory. 
*</ul>
*/

/*
* The CATTopHealOperator operator doesn't support cutting information :
* it will throw an error if cutting information are detected on 
* CATCells to be healed.
* The CATTopHealOperator operator doesn't support LyingOn information.
* There is no check of such a situation, it is the caller responsability to avoid this.
*/
//class ExportedByTopExtLight CATTopHealOperator : public CATTopOperator
class CATTopHealOperator : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopHealOperator);
 public:

/**
 * @nodoc
 * Virtual constructor of a CATTopHealOperator operator.<br>
 * Cannot be called. Use the <tt>CATCreateTopHealOperator</tt> global function
 * to create a CATTopHealOperator operator.
 */
/* @nodoc @nocgmitf */
  CATTopHealOperator (CATGeoFactory*     iContainer,
                      CATTopData*        iData,
                      CATExtTopOperator* iExtensible = NULL);

/**
 * Destructor.
 */
  virtual ~CATTopHealOperator();

/**
 * Add a scar edge to heal.
 * @param iScarEdge
 * The pointer to the scar edge. This edge must belong to the input shell.
 * An error "Invalid imput data" is thrown if not.
 */
  virtual void AddScarEdge( CATEdge* iScarEdge );

/**
 * Add a scar vertex to heal.
 * @param iScarVertex
 * The pointer to the scar vertex. This vertex must belong to the input shell.
 * An error "Invalid imput data" is thrown if not.
 */
  virtual void AddScarVertex( CATVertex* iScarVertex );


/**
 * Add a frozen edge.
 * @param iFrozenEdge
 * The pointer to the frozen edge. A frozen edge must not be affected by the healing operator.
 * This edge must belong to the input shell. An error "Invalid input data" is thrown if not.
 */
  virtual void AddFrozenEdge( CATEdge* iFrozenEdge );

/**
 * @nodoc
 * Method to call in order to heal the initial shell.
 * @param iFullJournal
 *   TRUE  for the full journal (as in CATSmartBodyDuplicator)
 *   FALSE for reduced journal (for faces and free border edges)
 */
/* @nodoc @nocgmitf */
  virtual void SetGlobalHealing(CATBoolean iFullJournal = TRUE);

/**
 * @nodoc
 * Method to call in order to invalid the Freeze normally performed on the result Body.
 */
/* @nodoc @nocgmitf */
  virtual void SetFreezeOff();

/**
 * Method to call in order to filter the input edges to Heal.
 * @param iTriggerGapValue 
 * The edges added with the AddScarEdge method are not healed 
 * if their Gap is smaller than iGapValue.
 * The TriggerValue has to be greater than the resolution, otherwise
 * an error is thrown.
 */
  virtual void SetEdgeGapTriggerValue(double iTriggerGapValue);

/**
 * Method to call in order to filter the input vertices to Heal.
 * @param iTriggerGapValue 
 * The vertices added with the AddScarVertex method are not healed 
 * if their Gap is smaller than iGapValue.
 * With the SetGlobalHealing method, the vertices are not healed 
 * if their Gap is smaller than iGapValue.
 * The TriggerValue has to be greater than the resolution, otherwise
 * an error is thrown.
 */
  virtual void SetVertexGapTriggerValue(double iTriggerGapValue);

/**
 * Method to call in order to allow more surface extrapolation
 * This method should not be called by users who care for model data size
 * @param iLevelExtrapol 
 * Only iLevel == 1 is acceptable today.
 */
  virtual void SetSurfaceExtrapolationLevel(short iLevel);

/**
 * @nodoc
 * Method to call in order to keep foreign PCurves included in 
 * EdgeCurve of Border edges. 
 * The PCurve(s) on the surface of the bounding face will be replaced
 * by a new one, all other PCurves will remain in the new EdgeCurve.
 */
/* @nodoc @nocgmitf */
  virtual void KeepForeignPCurvesOfBorderEdges();

/**
 * @nodoc 
 * do not call
 */
/* @nodoc @nocgmitf */
  virtual void SetNoHealForFreeBorders();

/**
 * @nodoc 
 * do not call
 */
/* @nodoc @nocgmitf */
  virtual void SetHealEdgesOnly();

/**
 * @nodoc 
 * do not call
 */
/* @nodoc @nocgmitf */
  virtual void SetSharpAndSmoothMode();

/**
 * @nodoc 
 * do not call
 */
/* @nodoc @nocgmitf */
  virtual void SetExternalDataMode();

/**
 * @nodoc 
 * do not call
 */
/* @nodoc @nocgmitf */
  virtual void SetGenHealMode();

/**
 * @nodoc 
 * do not call
 */
/* @nodoc @nocgmitf */
  virtual void SetFrsLevel(short iLevel);

/**
 * @nodoc
 * Method to call in order to get the list of the recomputed edges [EdgeCurve
 * has been recalculated] by the operator.
 * There may be redundancies in the lists if the operator is no more isotopological.
 * Throws an error if not called after RunOperator is succesfull.
 * @param oRecomputedEdges
 * The edges recomputed by the operator.
 * @param oIsIsotopologicalForEdges
 * TRUE if the result body is isotopological with the input body concerning the edges.
 * if TRUE, there is a bijection between oRecomputedEdges and oOrigEdges.
 * @param oOrigEdges
 * The synchronised list of original edges.
 * @param oNewGaps
 * The synchronised list of oModifiedEdges gaps.
 * @param oOrigGaps
 * The synchronised list of oOrigEdges gaps.  
 */
/* @nodoc @nocgmitf */
  virtual void GetRecomputedEdges(CATBoolean&      oIsIsotopologicalForEdges,
                                  ListPOfCATEdge&  oRecomputedEdges,
                                  ListPOfCATEdge*  oOrigEdges = NULL,
                                  CATListOfDouble* oNewGaps   = NULL,
                                  CATListOfDouble* oOrigGaps  = NULL  ); 

/**
 * @nodoc
 * Method to call in order to get the list of the modifed edges [created
 * by the smartduplication].
 * There may be redundancies in the lists if the operator is no more isotopological.
 * Throws an error if not called after RunOperator is succesfull.
* @param oIsIsotopologicalForEdges
 * TRUE if the result body is isotopological with the input body concerning the edges.
 * if TRUE, there is a bijection between oNewEdges and oOrigEdges.
 * @param oNewEdges
 * The edges created by the operator.
 * @param oOrigEdges
 * The synchronised list of original edges. 
 */
/* @nodoc @nocgmitf */
  virtual void GetModifiedEdges(CATBoolean&      oIsIsotopologicalForEdges,
                                ListPOfCATEdge&  oNewEdges,
                                ListPOfCATEdge*  oOrigEdges = NULL );

  /**
 * @nodoc
 * Method to call in order to get the list of the modifed faces [created
 * by the smartduplication].
 * There may be redundancies in the lists if the operator is no more isotopological.
 * Throws an error if not called after RunOperator is succesfull.
 * @param oIsIsotopologicalForFaces
 * TRUE if the result body is isotopological with the input body concerning the faces.
 * if TRUE, there is a bijection between oNewFaces and oOrigFaces (but there is eventually
 * no more bijection for the edges of these faces).
 * @param oNewFaces
 * The faces created by the operator.
 * @param oOrigFaces
 * The synchronised list of original faces. 
 */
/* @nodoc @nocgmitf */
  virtual void GetModifiedFaces(CATBoolean&      oIsIsotopologicalForFaces,
                                ListPOfCATFace&  oNewFaces,
                                ListPOfCATFace*  oOrigFaces = NULL );

/**
 * @nodoc
 * Throws an error if not called after RunOperator is succesfull.
 * Method to call in order to get the number of edges not fully healed
 */
/* @nodoc @nocgmitf */
  virtual int GetNbResidualGapEdges();

/**
 * @nodoc
 * Method to call in order to get the list of the edges not fully healed
 * Throws an error if not called after RunOperator is succesfull.
 * @param oEdgesWithGap
 * The list of edges in the result body that hat are still with normal gaps - they may
 * may have not been specified to be healed (Global mode).
 * @param oOrigEdges
 * The synchronised list of original edges (in the input body).
 * @param oGloGaps
 * The synchronised list of the resulting global gaps. 
 * @param oNorGaps
 * The synchronised list of the resulting normal gaps. 
 */
/* @nodoc @nocgmitf */
  virtual void GetResidualGapEdges(ListPOfCATEdge&  oEdgesWithGap,
                                   ListPOfCATEdge*  oOrigEdges = NULL,
                                   CATListOfDouble* oGloGaps   = NULL,
                                   CATListOfDouble* oNorGaps   = NULL  );  
/**
 * @nodoc
 * Throws an error if not called after RunOperator is succesfull.
 * Method to call in order to get the number of edges with remaining normal gaps.
 */
/* @nodoc @nocgmitf */
  virtual int GetNbResidualNormalGapEdges();
  
/**
 * @nodoc
 * Throws an error if not called after RunOperator is succesfull.
 * Method to call in order to get the list of the edges with remaining normal gaps.
 * @param oEdgesWithGap
 * The list of edges in the result body that are still with normal gaps - they may
 * may have not been specified to be healed (Global mode).
 * @param oOrigEdges
 * The synchronised list of original edges (in the input body).
 */
/* @nodoc @nocgmitf */
  virtual void GetResidualNormalGapEdges(ListPOfCATEdge&  oEdgesWithGap,
                                         ListPOfCATEdge*  oOrigEdges = NULL);

/**
 * @nodoc
 * Throws an error if not called after RunOperator is succesfull. 
 * Get old and new faces that have been set with SetNewSurfsOfFaces
 */
  //virtual void GetFlexibleFaces(ListPOfCATFace& oInputFlexFaces,
  //                              ListPOfCATFace& oNewFlexFaces);


 // -----------------------------------------------------------------------------------
 // CGM Internal Use
 // -----------------------------------------------------------------------------------

  private:

/* @nodoc @nocgmitf */
  virtual int RunOperator();

/* @nodoc @nocgmitf */
  virtual CATExtCGMReplay * IsRecordable(short & LevelOfRuntime, short &VersionOfStream);

/* @nodoc @nocgmitf */
  virtual const CATString * GetOperatorId();

/* @nodoc @nocgmitf */
  virtual const CATString * GetDefaultOperatorId();

/* @nodoc @nocgmitf */
  virtual void RequireDefinitionOfInputAndOutputObjects();

/* @nodoc @nocgmitf */
  virtual void WriteInput(CATCGMStream &Str);
  
/* @nodoc @nocgmitf */
  virtual void Dump( CATCGMOutput& os );

/* @nodoc @nocgmitf */
  virtual CATCGMOperator::CATCheckDiagnostic CheckOutput(CATCGMOutput & os);

};


/**
 * Creates a CATTopHealOperator operator with one shell to heal
 * @param iFactory
 * The factory of the geometry. 
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * @param iPart
 * The pointer to the body to heal.
 * @param iShell
 * The pointer to the shell to heal.
 * @return
 * The pointer to the created operator. To delete after use with the usual C++ <tt>delete</tt> operator.
 */
ExportedByTopHeal CATTopHealOperator* CATCreateTopologicalHealing ( CATGeoFactory*     iFactory,
                                                                    CATTopData*        iData,
                                                                    CATBody*           iPart,
                                                                    CATShell*          iShell      );


/**
 * Creates a CATTopHealOperator operator with one shell to heal
 * @param iFactory
 * The factory of the geometry. 
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * @param iPart
 * The pointer to the body to heal.
 * @param iShell
 * The pointer to the shell to heal.
 * @return
 * The pointer to the created operator. To delete after use with the usual C++ <tt>delete</tt> operator.
 */
/* @nodoc @nocgmitf */
ExportedByTopHeal CATTopHealOperator* CATCreateTopHealOperator ( CATGeoFactory*     iFactory,
                                                                 CATTopData*        iData,
                                                                 CATBody*           iPart,
                                                                 CATShell*          iShell      );

/**
 * Creates a CATTopHealOperator operator with one body to heal
 * All shells will be healed, globally
 * Whean this function is called, following methods are forbidden: AddScarEdge, AddScarVertex, AddFrozenEdge
 * @param iFactory
 * The factory of the geometry. 
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * @param iPart
 * The pointer to the body to heal.
 * @param iShell
 * The pointer to the shell to heal.
 * @return
 * The pointer to the created operator. To delete after use with the usual C++ <tt>delete</tt> operator.
 */
/* @nodoc @nocgmitf */
ExportedByTopHeal CATTopHealOperator* CATCreateTopHealOperator ( CATGeoFactory*     iFactory,
                                                                 CATTopData*        iData,
                                                                 CATBody*           iPart       );

#endif

