#ifndef CATDynTrimSew_H
#define CATDynTrimSew_H

// COPYRIGHT DASSAULT SYSTEMES  2002

#include "CATDynOperator.h"
#include "CATTopDefine.h"
#include "CATMathDef.h"
#include "CATBodyFreezeMode.h"
#include "ListPOfCATBody.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATVertex.h"
#include "CATDynValidShell.h"
#include "CATDynTrimSewDef.h"

class CATGeoFactory;
class CATBody;
class CATSurface;
class CATPlane;
class CATShell;


/**
* @nodoc
* Class defining the operator to trim and sew a skin for replacing faces of a 3D body.
* <ul>
* <li>A CATDynTrimSew operator is created with the <tt>CATCreateDynTrimSew</tt> global function:
* It must be directly deleted with the usual C++ <tt>delete</tt> operator after use. It is not streamable. 
*<li>Options can be precised (such as the domain to draft) with the <tt>SetXxx</tt> and <tt>Add</tt> 
* methods, before
* asking for the computation with the <tt>Run</tt> method. The <tt>Add</tt> method can only be called once
* for a draft operation.
*<li>In both cases, the result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory.
*/
class ExportedByBODYNOPE CATDynTrimSew : public CATDynOperator
{
  CATCGMVirtualDeclareClass(CATDynTrimSew);
public:
	/**
  * @nodoc
  * Virtual constructor of a CATDynTrimSew operator.<br>
  * Cannot be called. Use the <tt>CATDynCreateTrimSew </tt> global function
  * to create a CATDynTrimSew operator.
  */
  CATDynTrimSew (CATGeoFactory*     iContainer,
                 CATTopData*        iData,
                 CATExtTopOperator* iExtensible);

  virtual ~CATDynTrimSew();

	/**
	* @nodoc
	* Asks for the computation of the trimmed shell only. To be used for debug purpose.
	* @param iMode
	* CATDynTrimmedSkinShellPreview is the only mode.
	*/
	virtual void SetPreviewMode(CATDynTrimSewPreviewMode iMode) = 0;
	

  /**
  * @nodoc
	* Defines the parameters of the sewing operation.
	* @param iListOfFacesCovered
	* The list of faces belonging to the solid body on which the
	* skin is stiched.
	* @param iTrimBody
	* The solid body on which the skin is stiched.
	* @param iTrimShell
	* The shell underlying the solid body.
	* @param iSkinBody
	* The skin to be stiched onto the solid body.
	* @param iSkinShell
	* The shell underlying the skin body and corresponding to the part to be stiched.
	* @param iSkinOrient
	* The orientation of the skin with respect to the solid shell.
	*/
  virtual void Add (ListPOfCATFace       &iListOfFacesCovered,
		CATBody *iTrimBody,
		CATShell *iTrimShell,
		CATBody *iSkinBody,
		CATShell *iSkinShell,
		CATOrientation iSkinOrient) = 0;

	/**
  * @nocgmitf
	* @nodoc
	* Defines the list of skin faces covering the solid body.
	* If you call this method, an automatic extrapolation of the set of skin faces will be tried. <br>
	* WARNING: This capability is not implemented for all cases.
	* @iListOfSkinFacesCovering
	* The list of faces (to be possibly extrapolated) covering the solid body.
	*/
  virtual void AddSkinFaces (ListPOfCATFace &iListOfSkinFacesCovering) = 0;

	/**
	* @nodoc
	* Defines the initialization mode. Specifying this mode is a way 
	* to optimize the algorithm behavior. There is a default mode (CATDynTrimSewLaydownAndInterInitMode), this
	* is the one which is activated if you do not call this API. With no indication, the algorithm 
	* performs a "laydown" and then an intersection which may not be necessary. Unless you have no
	* indication on the way the two input bodies intersects.
	* @param iMode
	* <ul>
	* <li>CATDynTrimSewLaydownInitMode: to be used if some edges of the skin are "laid down" on the solid.
	* If a PCurve of the skin to be sewn relies on the solid, you must use 
	* the OnlyUseExistingGeometryForLayDown API in addition to the SetInitMode(CATDynTrimSewLaydownInitMode) 
	* method.
	* <li>CATDynTrimSewIntersectionInitMode: to be used when the covering faces intersect the faces to be covered 
	* and when you are sure that you will never have to "lay down" an edge onto the solid body. 
	* </ul>
	*/
	virtual void SetInitMode(CATDynTrimInitMode iMode) = 0;


	/**
  * @nocgmitf
  * @nodoc
  * Defines the relimitation mode of the free borders.
  * So this method is useless if you haven't a sheet body.
  * There is a default mode (CATDynTrimSewDefaultRelimMode), this
  * is the one which is activated if you do not call this API.   
  * @param iMode
  * <ul>
  * <li>CATDynTrimSewDefaultRelimMode: free borders are not relimited, journal reports for free border edges 
  * may be missing. It's the caller's responsability to handle this.
  * <li>CATDynTrimSewNoneRelimMode: free borders are not relimited, but journal is checked 
  * to ensure all free borders are followed, except those specified with the SetListOfFreeEdges API.
  * </ul>
  */
  virtual void SetFreeBorderRelimMode(CATDynTrimRelimMode iMode) = 0; 

	/**
	* @nodoc
	* Defines the Align mode.
	* @param iAlign
	* Asks for an extrapolation when there is no intersection between the 
	* skin to be sewn and the solid.
	*/
	virtual void SetAlignMode(CATBoolean iAlign) = 0;

	/**
  * @nocgmitf
	* @nodoc
	* Defines the face filter mode.
	*/
	virtual void SetFaceTypeFilter(CATBoolean iFaceTypeFilter) = 0;

	/**
	* @nodoc
	* Set one (or more) list of edges already laid on the skin.
	* This list will initialize the relimitation.
	*/
  virtual void SetListOfAlreadyLaidOnEdges(int iNumberOfList,
    ListPOfCATEdge * iListOfEdges,
		CATListOfInt *iSideSkinOnListOfEdge) = 0;

	/**
  * @nocgmitf
	* @nodoc
	* Set a list of free border edges lying on the skin and a list of
	* side to keep on the skin.
	* These lists will be used to disconnect the skin.
	*/
  virtual void SetListOfFreeEdges(const ListPOfCATEdge & iListOfEdges,
    const CATListOfInt & iSideSkinOnListOfEdge) = 0;

	/**
	* @nodoc
	* Mode without simplification if iNoSimplif = TRUE
	*/
	virtual void SetNoSimplif(CATBoolean iNoSimplif) = 0;

	/**
  * @nocgmitf
	* @nodoc
	* DO NOT USE. ONLY FOR CATIA LIVE SHAPE<br>
	* Mode with simplification only for Covering Faces 
	* Of course not compatible with SetNoSimplif mode
	*/
	virtual void SetCoveringFacesSimplifOnly() = 0;

	/**
  * @nocgmitf
	* @nodoc
	* DO NOT USE. ONLY FOR CATIA LIVE SHAPE<br>
	* Mode without simplification of the sewed skin
	* Not compatible with SetNoSimplif or SetCoveringFacesSimplifOnly
	*/
	virtual void SetNoSkinSimplif() = 0;

	/**
	* @nodoc
	* Mode without keep feature mode  if iNoKeepFeature = TRUE
	*/
	virtual void SetNoKeepFeature(CATBoolean iNoKeepFeature) = 0;

	/**
	* @nodoc
	* If the CATDynTrimSewLaydownInitMode option is specified in the SetInitMode method,
	* calling OnlyUseExistingGeometryForLayDown is a means to specify the use
	* of a pre-existing geometry on the solid to be sewn (the skin edge which is on the solid must have a PCurve
	* relying on the solid surface).
	* @param iUseExistingGeometryForLayDown
	* Specifies the use of a pre-existing geometry if  iUseExistingGeometryForLayDown=TRUE.
	*/
  virtual void OnlyUseExistingGeometryForLayDown(CATBoolean iUseExistingGeometryForLayDown) = 0;

	/**
  * @nocgmitf
	* @nodoc
  * AUTOFILLET USE ONLY.
	* This method specifies some non-relimiting faces on the relimiting body.
	*/
  virtual void SetNonRelimitingFaces(ListPOfCATFace &iListOfNonRelimitingFaces) = 0;

	/**
  * @nocgmitf
	* @nodoc
	* AUTOFILLET USE ONLY.
	* This method specifies some relimiting faces on the relimiting body.
*/
  virtual void SetRelimitingFaces(ListPOfCATFace &iListOfRelimitingFaces) = 0;

	/**
  * @nocgmitf
	* @nodoc
	* AUTOFILLET USE ONLY.<br>
	* This method specifies skin faces that have high priority in relimitation propagation,
	* i.e. they take precedence over other skin faces whenever there's a choice.
	*/
	virtual void SetHighPrioritySkinFaces(
		CATLISTP(CATFace) &iListOfHighPrioritySkinFaces) = 0;

	/**
  * @nocgmitf
	* @nodoc
	* AUTOFILLET USE ONLY.<br>
	* This method specifies vertices used for removing the ribbons containing them.
*/
  virtual void SetVerticesForRibbonRemoval(ListPOfCATVertex& iVertexList) = 0;

	/**
  * @nocgmitf
	* @nodoc
	* This method specifies the type of error bodies attached to diagnostic and is 
	* ony used in the Autofillet capability.
	* @param iType
	* <ul>
	* <li> 1 : To get the faces supporting free end relimitation ribbons.
	* The faces are those on the original skin to sew.
	* <li> 1  : to get a throw.
	* </ul>
	*/
	virtual void SetErrorDiagType(int iType) = 0;

	/**
  * @nocgmitf
	* @nodoc
	* DO NOT USE. ONLY FOR CATIA LIVE SHAPE<br>
	* Mode where restricted relimitation is performed in order to not impact the
	* faces that would be "covered" by the skin to sew. 
	* Those impact faces must be :
	* <ul>
	* <li> the faces adjacent to covered faces with concave edges for concave relimitation
	* <li> the faces which are not selected as covered faces.
	* </ul>
	*/
	virtual void SetNoTangencyPropag() = 0;

	/**
  * @nocgmitf
	* @nodoc
	* DO NOT USE. ONLY FOR CATIA LIVE SHAPE<br>
	* Mode where restricted relimitation is performed in order not to impact
	* faces that would be "covered" by the skin to sew. 
	* Those impact faces must be :
	* <ul>
	* <li> the faces adjacent to covered faces with concave edges for concave relimitation
	* <li> the faces which are not selected as covered faces.
	* </ul>
	*/
	virtual void SetNoConcavePropag() = 0;

	/**
  * @nocgmitf
	* @nodoc
	* DO NOT USE. ONLY FOR CATIA LIVE SHAPE<br>
	* Mode where no Creation Order is reported in the journal.
	*/
	virtual void SetNoJournalCreationOrder() = 0;

	/**
	* @nodoc
	* DO NOT USE. ONLY FOR CATIA LIVE SHAPE<br>
	* Set the correspondance between the replacing faces and the faces to replace.
	* The lists are synchroneous (there must be a bijection between the faces).
	* @param iToReplaceFaces
	* List of faces to be replaced.
  * @param iReplacingFaces
	* List of replacing faces.
	*/
  virtual void SetReplacingFacesBijection(ListPOfCATFace& iToReplaceFaces, ListPOfCATFace& iReplacingFaces) = 0;

	/**
  * @nocgmitf
  * @nodoc
  * Do not use
  * Perform additionnal check for auto-intersection detection in the result body
  * Caution : High performance cost and suspicious detection.
  * Only for CATIA Live Shape!
  */
  virtual void CheckAutoIntersections(int iKey) = 0;

  /**
  * @nocgmitf
  * @nodoc
  * Do not use
  * Very specific usage 
  */
  virtual void SetSimpleCorner(CATVertex* iCornerVertex) = 0;

  /**
  * @nocgmitf
  * @nodoc
  * Do not use
  * Very specific usage 
  */
  virtual void DoNotPerformCompletionInCaseOfError() = 0;

  /**
  * @nocgmitf
  * @nodoc
  * Do not use
  * Very specific usage 
  */
  virtual void DoJCHL(short iOpt) = 0;

  /**
  * @nocgmitf
  * @nodoc
  * Do not use
  * Very specific usage 
  */
  virtual void SetBorderEdgesForFollow(ListPOfCATEdge &iLBrdEdgs, ListPOfCATEdge &iLNtrEdgs, ListPOfCATEdge &iLLayEdgs) = 0;

  /**
  * @nocgmitf
  * @nodoc
  * Do not use
  * Very specific usage 
  */
  virtual void CheckForAlign(short iOpt) = 0;

};

/**
* @nodoc
* Creates a CATDynTrimSew operator.
* @param iFactory
* The factory of the geometry. 
* @param iData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iPart
* The pointer to the body.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
*/
ExportedByBODYNOPE CATDynTrimSew* CATCreateDynTrimSew (CATGeoFactory*        iContainer,
	CATTopData *iData,
	CATBody *iPart);


#endif
