/* -*-C++-*-*/
#ifndef CATGMPolyLayDownTopOper_H
#define CATGMPolyLayDownTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2016
//
// CATGMPolyLayDownTopOper
//
// DESCRIPTION :
// Lay Down a polyhedral wire or point, on the 2D-shape or 1D-wire of a polyhedral body
// The input body will be overlaid with the vertices and edges that are within the tolerance of the target CATBody.
//
//
// History
//
// June. 2016 DPS Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h"  // derivation
#include "GMPolyProject.h"         // ExportedBy
#include "CATLayDownOperatorDef.h" // CATLayDownAnalysis & CATLayDownDiagnostic

#include "CATDataType.h"           // HRESULT
#include "CATTopDefine.h"          // CATSide
#include "CATMathInline.h"         // inline Methods

#include "ListPOfCATDomain.h"
#include "ListPOfCATCell.h"
#include "CATListOfCATCells.h"
#include "CATCGMJournal.h"

#include "CATBoolean.h"
#include "CATSysBoolean.h"


class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyLayDownTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyProject CATGMPolyLayDownTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyLayDownTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyLayDownTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreatePolyLayDownTopOper() method to create an instance
  static CATGMPolyLayDownTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyLayDownTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================

  /** 
  * Defines the tolerance of the geometrically coincident elements to be taken 
  * into acccount by the LayDown operator.
  * <br>Very sensitive point. The default value is the factory resolution (0.001 mm in NormalScale context), 
  * and it is strongly recommended to not increase it above the LargeResolutionForLengthTest 
  * (100 times the resolution which is the threshold of CATBody invalidity for gaps & overlaps)
  * @param iLayDownTolerance
  * The tolerance.
  */
  void SetTolerance(double iLayDownTolerance);

  /** 
  * Force to enable or disable the duplication of cells before adding the LyingOn links
  * if no cell is duplicated, if no cell is cut and if all cells are lying on, 
  * then the operator will be return the input BodyToLayDown as result
  * else a smart duplicator will be launched and the input body will be cloned
  * @param iDuplicateCells
  * The boolean order to demande the duplication or not.
  * The mode is internally set to TRUE by default
  */
  void SetDuplicationMode(CATBoolean iDuplicateCells);

  	
  /** 
	* @nodoc 
	* Sets the type of journal items 
	* (CATCGMJournal::Creation or CATCGMJournal::Modification)
	* default is Creation
	*/
	void SetJournalType(CATCGMJournal::Type iJournalType);

  /** @nodoc
  * Set simplification mode.
  * To be called before running operator.
  * @param iMode
  * Simplification mode.
  * <br><b>Legal values</b>:
  * <dl><dt><tt>FALSE</tt> <dd> No wire simplification on Result (default value).
  *     <dt><tt>TRUE</tt> <dd> Apply wire simplification on Result.
  *</dl>
  */
  void SetSimplificationMode(CATBoolean iMode);


  /** 
  * Compute the matching information of the result body versus the input body to lay down
  * returns TRUE if the complete input body has been reported in the result body
  * returns FALSE if at least one part of at least one initial edge is missing in the result body
  * @nodoc * @nocgmitf  *
  */
  CATBoolean IsResultFullyCoveringInitialBody();


  /** 
  * Compute the disconnectability of the target body by the result body lying on it
  * If the result body contains at least one open wire whose at least one extremity is not lying on the target boundary
  * then the target body will be considered as not disconnectable by the result
  * @param oInnerBoundingCells
  * The list of cells bounded open wires bu not lying on the target boundary
  * @param oInnerOpenDomains
  * The list of domains bounded by the cells of the first list
  * The 2 lists have the same size and match each other for any given index
  * That means a domain can be repeated if bounded by several cells not lying on the target boundary
  * @nodoc * @nocgmitf  *
  */
  CATBoolean IsResultDisconnectingTargetBody(ListPOfCATCell & oInnerBoundingCells, ListPOfCATDomain & oInnerOpenDomains);

  /** @nodoc
  * Get diagnostic after running operator.
  * @return
  * LayDown operation diagnostic.
  * <br><b>Legal values</b>:
  * <dl><dt><tt>NoLayDown</tt> <dd> 
  *     <dt><tt>BodyIsLyingOn</tt> <dd>
  *     <dt><tt>BodyHasBeenLaidDown</tt> <dd>
  *     <dt><tt>BodyPartiallyLaid</tt> <dd></dl>
  */
  CATLayDownDiagnostic GetDiagnostic();

  /** @nodoc 
  * Get result analysis after running operator.
  * @return
  * LayDown operation analysis.
  * <br><b>Legal values</b>:
  * <dl><dt><tt>EmptyResult</tt> <dd> The Result Body is empty: Diagnostic is NoLayDown.
  *     <dt><tt>AlreadyLyingOn</tt> <dd> The Input Body is already LyingOn: Diagnosis is BodyIsLyingOn.
  *     <dt><tt>AfterComputationResultIsLayDown</tt> <dd> The Result Body is correctly Layed Down: Diagnostic is BodyHasBeenLaidDown.
  *     <dt><tt>TooMuchResultDomain</tt> <dd> The Result Body has more domains than Input Body: Diagnostic is BodyPartiallyLaid.
  *     <dt><tt>NotEnoughResultDomain</tt> <dd> The Result Body has less domains than Input Body: Diagnostic is BodyPartiallyLaid.
  *     <dt><tt>DifferentExtremity</tt> <dd> The Extremities of Result Body are different from Input Body: Diagnostic is BodyPartiallyLaid.
  *     <dt><tt>DifferentExtremityRelimitation</tt> <dd>idem DifferentExtremity and the reason is Relimitation. </dl>
  */
  CATLayDownAnalysis GetAnalysis();


  // ------------------
  // CGMReplay Methods
  // ------------------
  /** @nodoc
   * @nocgmitf
  */
  static const CATString * GetDefaultOperatorId();

protected:

  /** @nodoc 
  * cannot be called
  */
  // Constructor
  // Please, call CATCreatePolyLayDownTopOper() method to create an instance
  CATGMPolyLayDownTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyLayDownTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyLayDownTopOper();
  CATGMPolyLayDownTopOper(const CATGMPolyLayDownTopOper& iOneOf); 
  CATGMPolyLayDownTopOper& operator =(const CATGMPolyLayDownTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyLayDownTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBodyToLayDown
 * The pointer to the body (wire of point) to project
 * @param iTargetBody
 * The pointer to the body on which the projection has to be computed
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyProject CATGMPolyLayDownTopOper * CATCreatePolyLayDownTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iBodyToLayDown, CATBody * iTargetBody); 


#endif
