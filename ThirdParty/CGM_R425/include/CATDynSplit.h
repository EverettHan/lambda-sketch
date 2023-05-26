#ifndef CATDynSplit_H_
#define CATDynSplit_H_

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
	* @level Protected
	* @usage U1
	*/ 

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATDynOperator.h"
class CATPlane;
class CATSurface;
class CATBody;
#include "ListPOfCATCell.h"
#include "ListPOfCATFace.h"

/**
	* Class defining the operator that splits a 3D body.
	*<br>
	* The CATDynSplit operator follows the global frame of the topological operators and satisfies the smart mechanism: 
	* the input bodies are not modified. A new resulting body is created, 
	* possibly sharing data with the input bodies.
	*<ul>
	* <li>A CATDynSplit operator is created with the <tt>CATCreateDynSplit</tt> global function:
	* It must be directly deleted after use with the usual C++ <tt>delete</tt> operator. It is not streamable. 
	*<li>Options can be precised (such as the splitting object) with the <tt>SetXxx</tt> methods, before
	* asking for the computation with the <tt>Run</tt> method. 
	*<li>In both cases, the result is accessed with the <tt>GetResult</tt> method. If you do not want 
	* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
	* geometric factory.
	*</ul>
	*/
class ExportedByBODYNOPE CATDynSplit : public CATDynOperator
{
  CATCGMVirtualDeclareClass(CATDynSplit);
public:
	
#ifdef CATIACGMR215CAA
  CATDynSplit (CATGeoFactory* iFactory, CATCGMJournalList* iJournal=NULL, CATExtTopOperator* iExtensible=NULL);
  CATDynSplit (CATGeoFactory* iFactory, CATTopData* iData, CATExtTopOperator* iExtensible = NULL);
#else
	/**
   * @nodoc
	* Virtual constructor of a CATDynSplit operator.<br>
	* Cannot be called. Use the <tt>CATDynCreateSplit</tt> global function
	* to create a CATDynSplit operator.
	*/
  CATDynSplit (CATGeoFactory* iFactory, CATCGMJournalList* iJournal=NULL);

   /**
   * @nodoc
	* Virtual constructor of a CATDynSplit operator.<br>
	* Cannot be called. Use the <tt>CATCreateDynSplit</tt> global function
	* to create a CATDynSplit operator.
	*/
  CATDynSplit (CATGeoFactory* iFactory, CATTopData* iData);
#endif
	
  virtual ~CATDynSplit();
	
	/**
	 * Defines the splitting plane.
	 * @param iSplittingPlane
	 * The pointer to the plane that splits the input body.
	 */
  virtual void SetSplit (CATPlane* iSplittingPlane)=0;
	
	/**
	 * Defines the splitting surface.
	 * @param iSplittingSurface
	 * The pointer to the surface that splits the input body.
	 */
  virtual void SetSplit (CATSurface* iSplittingSurface)=0;
	
	/**
	 * Defines the splitting body.
	 * @param iSplittingBody
	 * The pointer to the body that splits the input body. <tt>iSplittingBody</tt> can contain several
	 * shell domains if their orientations are compatible.
	 */
  virtual void SetSplit (CATBody* iSplittingBody)=0;

	/**
    * @nodoc
	 * Returns the cells of the Result Body which have been arbitrarily kept (not cut by the SplittingBody).
	 * Nota : if the SplittingBody is a planar skin, these cells are positionned versus the plane.
    * @param iUnknownPositionCells
	 */
  virtual void GetUnknownPositionCells(CATLISTP(CATCell)& iUnknownPositionCells)=0;
	/**
	 * Indicates whether the Split Operation has removed some material to the body or not.
	 * @return
     * <tt>TRUE</tt> if it has removed some material, <tt>FALSE</tt> otherwise.
    */
  virtual CATBoolean GetRelimitation()=0;

#ifdef CATIACGMR215CAA
  /**
  * @nodoc
  * Sets Extrapolation Mode. Used if the splitting body does not fully split the body to split.
  * The splitting body will be extrapolated according to the extrapolation mode set.
  * @param iExtrapolMode
  * The extrapolation mode. DYN_NO_EXTRAPOLATION by default.
  */
  virtual void SetExtrapolationMode(CATDynExtrapolationMode iExtrapolMode)=0;

  /**
  * Sets Selection Mode.
  * Allows to decide among 3 possible behaviors for the split operator
  * (CATDynPositionVsPlaneMode, CATDynKeepMode, CATDynRemoveMode)
  * @param iSelectionMode
  * The selection mode. CATDynPositionVsPlaneMode by default.
  */
  virtual void SetSelectionMode(CATDynSelectionMode iSelectionMode)=0;
#endif
#ifdef CATIACGMR420CAA
  /*
  * @nodoc
  * Sets Extrapolation Limit. Used if the splitting body does not fully split the body to split and we need to
  * extrapolate it.  
  * 
  * DYN_BODYBOUNDINGBOX - Extrapolate the splitting body to the oriented bounding box of the body to split.
  * DYN_THRUNEXTCONNECTED - Extrapolate the splitting body to the oriented bounding box, but only keep the 
  *                         parts of the extrapolated body that are inside the body to split and connected to
  *                         the original splitting body.   
  * The splitting body will be extrapolated according to the extrapolation mode set.
  * @param iExtrapolLimit
  * The extrapolation mode. DYN_THRUNEXTCONNECTED by default.
  */
  virtual void SetExtrapolationLimit(CATDynExtrapolationLimit iExtrapolLimit)=0;
#endif

#ifdef CATIACGMR425CAA
  /*
  * @nodoc
  * Set no volumic simplification mode, 2 volumes connected by common face will not be simplified to 1 volume
  * @param iNoVolumicSimplif
  * The NoVolumicSimplif mode, FALSE by default (i.e. simplify the volumes)
  */
  virtual void SetNoVolumicSimplif(CATBoolean iNoVolumicSimplif) = 0;

  /*
  * @nodoc
  * Set volume propagation mode inside the same lump
  * if volume in the same lump is connected (by face) with selected volum, it will be also selected
  * @param iLumpPropagation
  * The LumpPropagation mode, FALSE by default
  */
  virtual void SetLumpPropagation(CATBoolean iLumpPropagation) = 0;
#endif

};

/**
* Creates a CATDynSplit operator.
* @param iFactory
* The factory of the geometry. 
* @param iData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
* is <tt>NULL</tt>, it is not filled.
* @param iBody
* The pointer to the body to split.
* @param iSplitType
* The portion of <tt>iBody</tt> to keep. 
* <dl>
* <dt><tt>CATSplitPositiveSideOnly</tt></dt><dd>
* The portion of <tt>iBody</tt> on the positive side of the splitting object is kept.
* <dt><tt>CATSplitNegativeSideOnly</tt></dt><dd>
* The portion of <tt>iBody</tt> on the negative side of the splitting object is kept.
* </dl>
* @param iBody
* The pointer to the body to split.
* @return
* The pointer to the created operator. To delete after use with the usual C++ <tt>delete</tt> operator.
*/
ExportedByBODYNOPE CATDynSplit* CATCreateDynSplit (CATGeoFactory*     iFactory,
                                                   CATTopData*        iData,
                                                   CATBody*           iBody,
                                                   CATDynSplitType    iSplitType) ; 
/**
* @nodoc
* Deprecated. Use CATCreateDynSplit.
*/
ExportedByBODYNOPE CATDynSplit* CATDynCreateSplit (CATGeoFactory* iFactory,
                                                   CATBody*           iBody,
                                                   CATDynSplitType    iSplitType,
                                                   CATCGMJournalList* iJournal=NULL) ;    

#endif
