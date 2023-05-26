#ifndef CATGenericHealing_H_
#define CATGenericHealing_H_

// COPYRIGHT DASSAULT SYSTEMES  2005

/**
 * Tags CAA :  a voir... 
 */ 

//
#include "BODYNOPE.h"
#include "GenHeal.h"
#include "CATTopOperator.h"
#include "CATExtCGMReplay.h"

//
#ifndef NULL
#define NULL 0
#endif

//
class CATBody;
class CATShell;
class CATFace;
class CATEdge;
class CATVertex;

//
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"

//
class CATBaseHealing;


//class CATCGMJournalList;
//class CATGeoFactory;
//class CATTopData;



/**
* Class defining the Healing operator on body with given scars or G1 discontinuities
* to be treated.
*<br>
* The CATGenericHealing operator follows the global frame of the topological operators 
* and satisfies the smart mechanism: the input bodies are not modified. A new resulting body 
* is created, possibly sharing data with the input body.
* The Healing operator failed in case of non-manifold topology detected on an edge impacted
* by the Healing.
*<ul>
* <li>A CATGenericHealing operator is created with the <tt>CATCreateGenericHealing</tt> global function:
* It must be directly deleted after use with the usual C++ <tt>delete</tt> operator. It is not streamable. 
*<li>Options can be precised with the <tt>SetXxx</tt> methods, before
* asking for the computation with the <tt>Run</tt> method. In particular, an optimized mode
* allows you to do some local operations in union mode.
*<li>In both cases, the result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory. 
*</ul>
*/



class ExportedByBODYNOPE CATGenericHealing	: public	CATTopOperator
{

public:

/**
 * @nodoc
 * Virtual constructor of a CATGenericHealing operator.<br>
 * Cannot be called. Use the <tt>CATCreateGenericHealing</tt> global function
 * to create a CATGenericHealing operator.
 */
  CATGenericHealing (CATGeoFactory*     iContainer,
                     CATTopData*        iData,
                     CATExtTopOperator* iExtensible = NULL);

/**
 * Destructor.
 */
  virtual ~CATGenericHealing();


/**
 * Set a CATBaseHealing allowing surface deformations.
 * Not to be used if this is a CATAdvGenericHealing
 * @param iBaseHealing
 * The pointer to a CATBaseHealing.
 * This pointer will be deleted in ~CATGenericHealing().
 * Please note : iBaseHealing must not refer to a body to heal - 
 *               The operator will set the body to heal by iBaseHealing (since it may be an intermediate body).
 * @param iJournalCreated
 * if iJourCreated is TRUE, then a journal has been created for iBaseHealing and
 * it's now the responsability of CATGenericHealing to delete it.
 */
  virtual void SetBaseHealing( CATBaseHealing*    iBaseHealing,
                               CATBoolean         iJournalCreated = FALSE);

/** 
 * Appends the body to heal. Can be used when the body to heal has not been
 * initialized in the constructor
 * @param iBodyToHeal
 * The Body to heal
 */
	virtual void SetBodyToHeal(CATBody * iBodyToHeal);

/** 
 * Appends the shell to heal. Can be used when the shell to heal has not been
 * initialized in the constructor
 * @param iShellToHeal
 * The Shell to heal
 */
	virtual void SetShellToHeal(CATShell * iShellToHeal);


/**
 * Method to call in order to invalid the Freeze normally performed on the result Body.
 */
  virtual void SetFreezeOff();


/**
 * Add a scar edge to heal with G0 objectives.
 * @param iScarEdge
 * The pointer to the scar edge. This edge must belong to the input shell.
 * An error "Invalid input data" is thrown if not.
 */
  virtual void AddG0ScarEdge( CATEdge* iScarEdge );

/**
 * Add a scar edge to heal with G1 objectives.
 * Please note : G1 objectives include G0 ones.
 * @param iScarEdge
 * The pointer to the scar edge. This edge must belong to the input shell.
 * An error "Invalid input data" is thrown if not.
 */
  virtual void AddG1ScarEdge( CATEdge* iScarEdge );

/**
 * Add a scar vertex to heal with G0 objectives.
 * @param iScarVertex
 * The pointer to the scar vertex. This vertex must belong to the input shell.
 * An error "Invalid input data" is thrown if not.
 */
  virtual void AddG0ScarVertex( CATVertex* iScarVertex );

/**
 * @nodoc : don't use, will throw an error
 *
 * Add a frozen edge.
 * @param iFrozenEdge
 * The pointer to the frozen edge. A frozen edge must not be affected by the healing operator.
 * This edge must belong to the input shell. An error "Invalid input data" is thrown if not.
 */
  virtual void AddFrozenEdge( CATEdge* iFrozenEdge );

/**
 * Keep the initial sharpness of an edge.
 * @param iKeepEdge
 * The pointer to the keep edge. A keep edge may only be slightly deformed by the healing operator.
 * The sharpness of initial edge will be kept.
 * This edge must belong to the input shell. An error "Invalid input data" is thrown if not.
 */
  virtual void KeepEdgeSharpness( CATEdge* iKeepEdge );


/**
 * @nodoc : don't use, will throw an error
 *
 *
 *          Est-ce que G1 => G0 pour le HG?? A tester, meme si semble clair!!
 */
  virtual void SetGlobalHealing(const short iOrder);


/**
 * @nodoc
 * Method to call in order to filter the input edges to Heal.
 * @param iTriggerGapValue 
 * The edges added with the AddG0ScarEdge method are not healed 
 * if their Gap is smaller than iGapValue.
 * The TriggerValue has to be greater than the resolution, otherwise
 * an error is thrown.
 */
  virtual void SetEdgeGapTriggerValue(double iTriggerGapValue);

/**
 * @nodoc
 * Method to call in order to keep foreign PCurves included in 
  EdgeCurve of Border edges. 
  The PCurve(s) on the surface of the bounding face will be replaced
  by a new one, all other PCurves will remain in the new EdgeCurve.
  // Voir avec JEP si on peut faire de meme en HG!
 */
  //virtual void KeepForeignPCurvesOfBorderEdges();



  //==============================================================================================================================//
  //==============================================================================================================================//
  //==============================         Base  Healing                                       ===================================//
  //==============================================================================================================================//
  //==============================================================================================================================//

    
/** 
 * Set the body to heal. Can be used after the Reset method
 * @param iBodyToHeal
 * The Body to heal
 */
  // Voir comment se comporte l'operateur ds un cas multi-shells!!
  //virtual int SetBodyToHeal(CATBody * iBodyToHeal);
  
/**
 * @nodoc : don't use, will throw an error
 *
 *
 * Defines the maximum G0 default for selecting the edges to be healed 
 * @param iTolG0Max
 * The G0 Maximum continuity tolerance. 
 * The Healing only applies to the edges whose initial default 
 * is lower than this tolerance.
 */ 
  // On peut le garder, mais n'existe pas aujourd'hui sur le HT [on a la methode inverse: 
  // SetEdgeGapTriggerValue.
  // + Voir comment ca agit avec les trous de vertex!!
  virtual	void SetMaxG0Tolerance ( const double iTolG0Max);	


/** 
 * Defines the maximum G1 default for selecting the edges to be healed 
 * for G1 Healing only.
 * @param iTolAngular
 * The G1 continuity tolerance. 
 * The Healing only applies to the edges whose initial default 
 * is lower than this tolerance. By default (when the method is not called), 
 * <tt>iTolAngular</tt> is set to 3 degrees. The maximum value is 5 degrees.    // zarbi :  je pensais 10deg!
 */ 
  virtual	void SetMaxG1Tolerance ( const double iTolAngular);	

  
/**
 * @nodoc : don't use, will throw an error
 *
 *
 * Defines the global default for the G1 continuity tolerance.
 * @param iTolAngular
 * The G1 continuity tolerance in degree.
 * default value is 0.5.
 */
  // On peut garder, mais ne semble pas super-utile!
  virtual	void SetG1Tolerance ( const double iTolAngular );
  
/**
 * @nodoc : don't use, will throw an error
 *
 *
 * Defines the Sharpness tolerance.
 * @param iTolSharpness
 * The Sharpness tolerance in degree.
 * default value is 0.5.
 */
  // Pas bien compris : quelle difference avec la methode SetG1Tolerance? Liee a une
  // shapness logique? A verifier.
  virtual void SetSharpnessTolerance ( const double iTolSharpness);


  // les 4 qui suivent : on peut les laisser, dans la mesure ou le HT preserve tout
  // On peut donc se contenter de rappeler les mm options sur le HG sans se poser de question

  /**
 * Defines the constraints on the geometry of a face.
 * <br>By default
 * <ul>
 * <li>Canonical faces are not free: <tt>iIsTypeFree == FALSE</tt>, <tt>iIsGeomFree == FALSE</tt>.
 * <li>All non-canonical faces are free: <tt>iIsTypeFree == TRUE</tt>, <tt>iIsGeomFree == TRUE</tt>.
 * </ul>
 * @param iF
 * The pointer to the face.
 * @param iIsGeomFree
 * The status of the modification of the face geometry.
 * <br><b>Legal values</b>: <tt>FALSE</tt> if its geometry cannot be changed, <tt>TRUE</tt>
 * if it can.
 * @param iIsTypeFree
 * The status of the preservation of the face geometry type (if <tt>TRUE == iIsGeomFree</tt>).
 * <br><b>Legal values</b>: <tt>FALSE</tt> if the canonicity must be kept (a cylinder
 * cannot become a Nurbs surface), <tt>TRUE</tt>
 */
  virtual	int SetFace(CATFace * iF, const CATBoolean iIsGeomFree, const CATBoolean iIsTypeFree);

/**
 * Defines the constraints on the geometry of faces.
 * <br>By default
 * <ul>
 * <li>Canonical faces are not free: <tt>iIsTypeFree == FALSE</tt>, <tt>iIsGeomFree == FALSE</tt>.
 * <li>All non-canonical faces are free: <tt>iIsTypeFree == TRUE</tt>, <tt>iIsGeomFree == TRUE</tt>.
 * </ul>
 * @param iListOfFaces
 * The list of the face pointers. 
 * @param iIsGeomFree
 * The status of the modification of the face geometry.
 * <br><b>Legal values</b>: <tt>FALSE</tt> if its geometry cannot be changed, <tt>TRUE</tt>
 * if it can.
 * @param iIsTypeFree
 * The status of the preservation of the face geometry type (if <tt>TRUE == iIsGeomFree</tt>).
 * <br><b>Legal values</b>: <tt>FALSE</tt> if the canonicity must be kept (a cylinder
 * cannot become a Nurbs surface), <tt>TRUE</tt>
 */
	virtual	int SetFace(const ListPOfCATFace &iListOfFaces, const CATBoolean iIsGeomFree, const CATBoolean iIsTypeFree);

/**
 * Defines the constraints on the geometry of faces of a given type.
 * <br>By default
 * <ul>
 * <li>Canonical faces are not free: <tt>iIsTypeFree == FALSE</tt>, <tt>iIsGeomFree == FALSE</tt>.
 * <li>All non-canonical faces are free: <tt>iIsTypeFree == TRUE</tt>, <tt>iIsGeomFree == TRUE</tt>.
 * </ul>
 * @param iType
 * The geometric type of the faces.
 * @param iIsGeomFree
 * The status of the modification of the face geometry.
 * <br><b>Legal values</b>: <tt>FALSE</tt> if its geometry cannot be changed, <tt>TRUE</tt>
 * if it can.
 * @param iIsTypeFree
 * The status of the preservation of the face geometry type (if <tt>TRUE == iIsGeomFree</tt>).
 * <br><b>Legal values</b>: <tt>FALSE</tt> if the canonicity must be kept (a cylinder
 * cannot become a Nurbs surface), <tt>TRUE</tt>
 */
  virtual	int SetFace(const CATGeometricType iType, const CATBoolean iIsGeomFree, const CATBoolean iIsTypeFree);

/**
 * Defines the constraints on the geometry of faces of a given type.
 * <br>By default
 * <ul>
 * <li>Canonical faces are not free: <tt>iIsTypeFree == FALSE</tt>, <tt>iIsGeomFree == FALSE</tt>.
 * <li>All non-canonical faces are free: <tt>iIsTypeFree == TRUE</tt>, <tt>iIsGeomFree == TRUE</tt>.
 * </ul>
 * @param iType
 * The geometric type of the faces.
 * @param iIsGeomFree
 * The status of the modification of the face geometry.
 * <br><b>Legal values</b>: <tt>FALSE</tt> if its geometry cannot be changed, <tt>TRUE</tt>
 * if it can.
 * @param iIsTypeFree
 * The status of the preservation of the face geometry type (if <tt>TRUE == iIsGeomFree</tt>).
 * <br><b>Legal values</b>: <tt>FALSE</tt> if the canonicity must be kept (a cylinder
 * cannot become a Nurbs surface), <tt>TRUE</tt>
 */
  virtual	int SetCanonic(const CATBoolean iIsGeomFree, const CATBoolean iIsTypeFree);

/**
 * @nodoc : don't use, will throw an error
 *
 *
 * Defines the constraints on the geometry of an edge.
 * @param iE
 * The pointer to the edge.
 * @param iOrder
 * <br>By default an edge can be modified.
 * It is possible to keep the initial gap of an edge or to minimize the deformation
 * of an edge.
 * <br>By default the G1 continuity of an edge can be modified.
 * It is possible to keep the initial sharpness of an edge.
 * The angle between the 2 surfaces will be kept relatively to the G1 Tolerance
 * <tt>0</tt> for a G0 continuity.
 * <tt>1</tt> for a G1 continuity.
 */ 
  // SetEdge = AddScarEdge ou AddFrozenEdge? Plutot Frozen!!
  //virtual int SetEdge(CATEdge * iE, const short iOrder);	 Remplace par le KeepEdgeSharpness + haut

/**
 * @nodoc : don't use, will throw an error
 *
 *
 * Defines the constraints on the geometry of a list of edges.
 * <br>By default an edge can be modified.
 * It is possible to keep the initial gap of an edge or to minimize the deformation
 * of an edge.
 * By default the G1 continuity of an edge can be modified.
 * It is possible to keep the initial sharpness of an edge.
 * The angle between the 2 surfaces will be kept relatively to the G1 Tolerance
 * <tt>0</tt> for a G0 continuity.
 * <tt>1</tt> for a G1 continuity.
 */ 
  // La meme en liste!
  //virtual int SetEdge(const ListPOfCATEdge &iListOfEdges , const short iOrder);	

  
/**
 * @nodoc : don't use, will throw an error
 *
 *
 * Defines an option for adjusting PCurves when there is a hole between them.
 * <br>By default the PCurves are adjusted only if their adjacent vertex belongs
 * to an edge to heal.
 * It is possible to adjust the PCurves on other kind of vertex.
 * <tt>0</tt> adjust PCurves adjacent to a vertex of an edge to heal.
 * <tt>1</tt> adjust also PCurves if the vertex belongs to the shell boundary.
 *				for G1 healing only, the vertex will be adjusted in tangency.
 */  
  // Pas clair! Quelle difference avec SetGlobalContinuity?
  // Lie aux bords libres? Oui, remplace maintenant par les AddVertex
  // Cf. au depart, les vertex ne sont pas soignes par le HG
  // Ensuite, en mode global on peut soigner les bords libres [le Sdjust ci-dessous]
  // Enfin, avec le Add(Vertex, ), on peut soigner un vtx precis [a priori, sans toucher
  // a la surface ni a des edges internes]

  virtual int SetAdjustPCurve(const short iAdjustPCurve);	


/**
 * @nodoc : don't use, will throw an error
 *
 *
 * Appends a vertex to be healed.(Healing Local G0 only)
 * @param iVertexToHeal
 * The pointer to the vertex to be healed.
 * @param iEdgeToFix
 * The pointer to the edge to be fixed if needed. The vertex must belong to the edge.
 * @param iOrder
 * The associated continuity objective (G0 only).
 */
  // Tester le iOrder [cf. "G0 only : pas clair]
	virtual int Add(CATVertex * iVertexToHeal, CATEdge * iEdgeToFix=0, const short iOrder=0);

  
/**
 * @nodoc : don't use, will throw an error
 *
 *
 * Defines the constraints on the geometry of a vertex.(Healing Local G0 only)
 * @param iVertexToFix
 * The pointer to the vertex to be fixed. Warning : a vertex to heal can not be fixed.
 * @param iEdge
 * The pointer to the edge with tangency constraint. The vertex must belong to the edge.
 * @param iOrder
 * The associated continuity objective (G1 only).
 */
  // zarbi : G0 ou G1?????
	virtual int SetVertex(CATVertex * iVertexToFix, CATEdge * iEdge, const short iOrder);

/** 
 * Updates the operator's journal
 * @param iJournal
 * The pointer to the new journal. Old journal will just be replaced, not destroyed or released.
 */
  virtual void UpdateJournalIfSafe(CATCGMJournalList* iJournal);

    
	//---------
	// Results
	//---------    

/**
 * @nodoc : don't use, will throw an error
 */
  virtual double G0MaxError();

/**
 * Returns the global maximum G1 deviation.
 * @return
 * The maximum G1 gap on the whole body.
 */
  virtual double G1MaxError(); 

/**
 * @nodoc : don't use, will throw an error
 */
  virtual CATBoolean IsSatisfied();

/**
 * @nodoc : don't use, will throw an error
 */
  virtual  int G0MaxError(CATEdge * iE , double &ioG0Error);

/**
 * @nodoc : don't use, will throw an error
 */
  virtual int G1MaxError(CATEdge * iE , double &ioG1Error); 

/**
 * @nodoc : don't use, will throw an error
 */
  virtual int IsSatisfied(CATEdge * iE , CATBoolean & ioIsSatisfied);

/**
 * @nodoc : don't use, will throw an error
 */
  virtual	int GetSharpEdges(ListPOfCATEdge & ioListOfEdges);

/**
 * @nodoc : don't use, will throw an error
 */
  virtual	int GetMaxDeformationOnEdge(CATEdge * iE, double &oMaxDef);


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
  virtual CATCGMOperator::CATCheckDiagnostic CheckOutput(CATCGMOutput & os);
};


/**
 * Creates a CATGenericHealing operator.
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
ExportedByGenHeal CATGenericHealing* CATCreateGenericHealing (CATGeoFactory*     iFactory,
                                                              CATTopData*        iData,
                                                              CATBody*           iPart,
                                                              CATShell*          iShell    );


#endif
