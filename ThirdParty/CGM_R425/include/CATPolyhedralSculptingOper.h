/* -*-C++-*-*/
#ifndef CATPolyhedralSculptingOper_H
#define CATPolyhedralSculptingOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2018
//
// CATPolyhedralSculptingOper
//
// DESCRIPTION :
// 
// Topological operator that aims to sew a surfacic body to a target body, adding and/or removing matter if necessary.
//
// The target body may be surfacic or volumic.
// If surfacic, its orientation is considered to be pointing in the outwards direction.
// If volumic, its orientation is considered to be pointing inwards.
//
// The body to sew may be oriented in any way.
// The mandatory input orientation specifies how to consider this body relatively to the outwards direction.
//
// If the boundaries of the body to sew are not lying on the target,
// two optional bodies can be provided, extending the body to sew from its boundaries.
//
// Optional iCuttingBody will define the semi space where any part of the target will be removed.
// Optional iFillingBody will define the semi space where any void between target and input will be filled.
//
// Computations are done by calling the Run method.
// Main result (target body modified and including body to sew) is obtained by calling GetResult method.
//
// If requested, volumic "cut" and "fill" bodies can be obtained by calling GetCutBody and GetFillBody.
//
// History
//
// 20180308 WMN Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h"     // derivation
#include "GMPolyAdvancedBool.h"     // ExportedBy
#include "CATTopDefine.h"

class CATGeoFactory;
class CATTopData;
class CATBody;

class ExportedByGMPolyAdvancedBool CATPolyhedralSculptingOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATPolyhedralSculptingOper);

public:
  
  /**
  * Destructor
  */
  virtual ~CATPolyhedralSculptingOper();
  
  //=============================================================================
  // Inputs
  //=============================================================================
  /**
  * Define a new Body to be sewn to the BodyToSculpt with optionally a Cutting and/or a Filling Body
  * @param iBodyToSew
  * The pointer to the body to be sewn to the target.
  * @param iOutwardOrientation
  * The relative orientation of the body to sew in regards to outward orientation.
  * @param iCuttingBody
  * input surfacic body as an extension of the body to sew, beyond the target body
  * Joined with the body to sew, this shape will define the semi space where any part of the target will be removed.
  * it can be NULL
  * @param iFillingBody
  * input surfacic body as an extension of the body to sew, beyond the target body
  * Joined with the body to sew, this shape will define the semi space where any any void between target and body to sew will be filled.
  * it can be NULL
  * @return
  * The integer value associated to the new BodyToSew definition, equals to the number of recorded bodies including this one.
  */
  virtual int AddBodyToSew(CATBody & iBodyToSew, CATOrientation iOutwardOrientation, CATBody * iCuttingBody, CATBody * iFillingBody) = 0;

  /**
  * "bas-relief" specification
  * @param iCutOnlyForInlay
  * if FALSE, option allowing the cut everywhere, potentially far from the inlay area
  * else (if TRUE) option limiting the cut of the target in the inlay area, in contact with the sewn body (default behavior)
  */
  virtual void SetCuttingSpecification(CATBoolean iCutOnlyForInlay) = 0;

  /**
  * "high relief" specification
  * @param iFillOnlyForInlay
  * if FALSE, option allowing the fill everywhere, potentially far from the inlay area
  * else (if TRUE) option limiting the fill of the target in the inlay area, in contact with the sewn body (default behavior)
  */
  virtual void SetFillingSpecification(CATBoolean iFillOnlyForInlay) = 0;

  /**
  * "bas-relief" specification
  * @param iCuttingBody
  * input surfacic body as an extension of the body to sew, beyond the target body
  * Joined with the body to sew, this shape will define the semi space where any part of the target will be removed.
  * @param iCutOnlyForInlay
  * if FALSE (default value), option allowing the cut everywhere, potentially far from the inlay area
  * else (if TRUE) option limiting the cut of the target in the inlay area
  */
  virtual void SetCuttingBody(CATBody * iCuttingBody, CATBoolean iCutOnlyForInlay = FALSE)=0;

  /**
  * "high relief" specification
  * @param iFillingBody
  * input surfacic body as an extension of the body to sew, beyond the target body
  * Joined with the body to sew, this shape will define the semi space where any any void between target and body to sew will be filled.
  * @param iFillOnlyForInlay
  * if FALSE (default value), option allowing the fill everywhere, potentially far from the inlay area
  * else (if TRUE) option limiting the fill of the target in the inlay area
  */
  virtual void SetFillingBody(CATBody * iFillingBody, CATBoolean iFillOnlyForInlay = FALSE)=0;

  /**
  * Option allowing the caller to split the BodyToSew (and Fill/Cut if specified) without sewing to the BodyToSculpt (default behaviour)
  * @param iSplitBodyToSculpt
  * if TRUE, option limiting the result body to the split BodyToSculpt by BodyToSew (and Fill/Cut if specified)
  * else (if FALSE (default value)) option limiting the result body to the split BodyToSew (and Fill/Cut if specified) by BodyToSculpt
  */
  virtual void EnableSplitMode(CATBoolean iSplitBodyToSculpt = FALSE)=0;


  /**
  * Option allowing the caller to follow the impact of the sculpting operation on a specific body supposed to represent a part of the matter
  * @param iMatterBody
  * body representing a part of the matter
  * This body has to be an homogeneous set of volumes (dimension==3)
  * This body is supposed to respect the following rule (inward location) :
  * if the body to sculpt is a volume, the matter body has to be contained by it
  * if the body to sculpt is surface, the matter body has to be in its negative half-space
  * This specification is under the responsibility of the caller, and is not checked by this method
  * @param iKeepBodyJournal
  * Journal to report the events from iMatterBody to the result Body to keep
  * The default behavior is CATCGMJournal::Copy
  * @param iRemoveBodyJournal
  * Journal to report the events from iMatterBody to the result Body to remove
  * The default behavior is CATCGMJournal::Copy
  * @return
  * The integer value associated to the new iMatterBody,
  * equal to 0 in case of invalid input (null pointer or unexpected dimension), else unique and strictly greater than 0
  */
  virtual int AddMatterBody(CATBody* iMatterBody, CATCGMJournalList* iKeepBodyJournal = NULL, CATCGMJournalList* iRemoveBodyJournal = NULL) = 0;

  /**
* Option allowing the caller to
* @param iMatterBody
* body representing the body to imprint to the BodyToSculpt
* This body has to be an homogeneous set of volumes (dimension==3) or shell (dimension==2)
* This body is supposed to intersect the BodyToSculpt
* If not, then it should be a closed shell or a volume
* This specification is under the responsibility of the caller, and is not checked by this method
* @param iOutwardOrientation
* @param iFillingMode
* By default it is FALSE - then the BodyToImprint is considered as Cutting Body
* else volume created will be added to the Filling volume result
* @param iStopperBody
* By default it is FALSE - no impact on Cutting and Filling volumes
* else this body will stop impact of Cutting and Filling on BodyToSculpt
* @return
* The integer value associated to the new iBodyToImprint,
* equal to 0 in case of invalid input (null pointer or unexpected dimension), else unique and strictly greater than 0
*/

  virtual int AddBodyToImprint(CATBody& iBodyToImprint, CATOrientation iOutwardOrientation, CATBoolean iFillingMode = FALSE, CATBoolean iStopperBody = FALSE) = 0;


  //=============================================================================
  // Settings
  //=============================================================================

  /**
  * Request volumic cut body computation.
  * This method must be called before Run for GetCutBody (see below) to return a body.
  */
  virtual void RequestCutBody(CATCGMJournalList * iJournal=NULL, CATBoolean iIgnoreLumpsNotConnectedToCuttingBody = FALSE)=0;

  /**
  * Request volumic fill body computation.
  * This method must be called before Run for GetFillBody (see below) to return a body.
  */
  virtual void RequestFillBody(CATCGMJournalList * iJournal=NULL, CATBoolean iIgnoreLumpsNotConnectedToFillingBody = FALSE)=0;

  /**
  * Request scar body computation.
  * This method must be called before Run for GetScarBody (see below) to return a body.
  * All operands are in NoCopy mode for this journal
  */
  virtual void RequestScarBody(CATCGMJournalList * iJournal = NULL)=0;

  //=============================================================================
  // Outputs
  //=============================================================================

  /**
  * Retrieve the body representing matter to be removed from the target.
  * RequestCutBody must be called before running the operator.
  */
  virtual CATBody * GetCutBody()=0;

  /**
  * Retrieve the body representing matter to be added to the target.
  * RequestFillBody must be called before running the operator.
  */
  virtual CATBody * GetFillBody()=0;

  /**
  * Retrieve the body representing the scars on both operands of the sculpting.
  * RequestScarBody must be called before running the operator.
  * @param SculptedBodyMatterSide
  * return the side (regarding the outward orientation) where is the kept matter of BodyToSculpt afer sculpting,
  * when walking along ScarBody in the direction of its own orientation.
  * @param SewedBodyMatterSide
  * return the side (regarding the outward orientation) where is the BodyToSew after sewing,
  * when walking along ScarBody in the direction of its own orientation.
  * These 2 sides should never be the same
  */
  virtual CATBody * GetScarBody(CATSide & SculptedBodyMatterSide, CATSide & SewedBodyMatterSide)=0;

  /**
* Retrieve the 2 result bodies associated to an input matter body
* @param iMatterBodyID
* The integer value returned by AddMatterBody, associated to iMatterBody
* @param oResultBodyToKeep
* The result body repesenting the part of matter to keep after sculpting
* @param oResultBodyToRemove
* The result body repesenting the part of matter to remove after sculpting
*
* 3 different configurations are possible here:
* 1/ The input matter body is impacted by the sculpting operation, crossed by a body to sew (extended to its cut / fill bodies)
* The operation splits the matter body into 2 different bodies
* 2/ The input body is entirely kept after sculpting:
* iMatterBody is duplicated in oResultBodyToKeep, oResultBodyToRemove==NULL
* 3/ The input body is entirely removed because contained by CutBody after sculpting:
* oResultBodyToKeep==NULL, iMatterBody is duplicated in oResultBodyToRemove
*
* @return
* return S_OK if this request succeeded, else E_FAIL (if no Matter body has been defined, or any other error during computation)
*/
  virtual HRESULT GetMatterBodyResults(int iMatterBodyID, CATBody*& oResultBodyToKeep, CATBody*& oResultBodyToRemove) = 0;




protected:

  /*
  * @nodoc 
  * @nocgmitf
  * cannot be called, constructor for derived classes only
  */
  CATPolyhedralSculptingOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOperTopExt & iExtension);

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  /** @nodoc @nocgmitf */
  CATPolyhedralSculptingOper();
  /** @nodoc @nocgmitf */
  CATPolyhedralSculptingOper(const CATPolyhedralSculptingOper& iOneOf); 
  /** @nodoc @nocgmitf */
  CATPolyhedralSculptingOper& operator =(const CATPolyhedralSculptingOper& iOneOf);

};

/**
 * Creates a CATPolyhedralSculptingOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBodyToSculpt
 * The pointer to the target body which might be modified by either adding or removing matter.
 * @param iBodyToSew
 * The pointer to the body to be sewn to the target.
 * @param iOutwardOrientation
 * The relative orientation of the body to sew in regards to outward orientation.
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyAdvancedBool CATPolyhedralSculptingOper * CATCreatePolyhedralSculptingOper(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iBodyToSculpt, CATBody * iBodyToSew, CATOrientation iOutwardOrientation);

///**
// * Creates a CATGMPolySculptingTopOper operator.
// * CALL AddBodyToSew to be able to compute the operation
// * @param iFactory
// * The factory of the geometry. 
// * @param iTopData
// * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
// * is <tt>NULL</tt>, it is not filled. 
// * @param iBodyToSculpt
// * The pointer to the target body which might be modified by either adding or removing matter.
// * @return [out, IUnknown#Release]
// * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
// */
ExportedByGMPolyAdvancedBool CATPolyhedralSculptingOper * CATCreatePolyhedralSculptingOper(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iBodyToSculpt);

#endif
