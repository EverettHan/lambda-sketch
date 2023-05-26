#ifndef CATLayDownOperator_h
#define CATLayDownOperator_h

// COPYRIGHT DASSAULT SYSTEMES  2004

/**
* @CAA2Level L1
* @CAA2Usage U1
*/ 

//#include "AnalysisTools.h"
#include "AnalysisToolsLight.h"
#include "ListPOfCATCell.h"
#include "CATCGMJournal.h"
#include "CATTopOperator.h"
#include "CATString.h"
#include "CATIACGMLevel.h"
#include "CATLayDownOperatorDef.h"

class CATGeoFactory;
class CATTopologicalOperator;
class CATHybOperator;
class CATBody;
class CATDomain;
class CATShell;
class CATCell;
class CATCGMJournalList;
class CATTopData;

/**
*  ***********************************************************************
*  *******                         WARNING                         *******
*  ***********************************************************************
*  *******
*  *******  This class is Not supported any longer.
*  *******  it has been replaced by CATICGMLayDownOperator
*  *******
*  *******
*  ***********************************************************************
*  ***********************************************************************
*  CATLayDownOperator class has been removed from CAA in 3DEXPERIENCE level and
*  has been replaced by CATICGMLayDownOperator.
*  We recommend you to use only CATICGMLayDownOperator, in order you will  be  
*  able to easily migrate   your CAA code from  V5 to 3DEXPERIENCE level
*
*  **************************************************************************
*
* Class defining the operator that projects a body onto another one referred to as the support and returns a solution
* only if the distance is lower than the factory resolution. If the body to be projected
* is lying on the support, the operator returns the input body (the body to be projeceted).
* The body to be projected and the support body (on which the projection is made) can contain 
* several domains.
* <br><b>Orientation</b>:(In case of the projection of a wire on a shell).
* The orientation of two points on the resulting wire is the same as
* the orientation of the points from which they are projected.
* <br><b>Journal</b>: 
*<ul>
* <li>Edges are written as <tt>CATCGMJournal::Creation</tt> from their corresponding
* edge (in the body to be projected project) and face (on the body support).
* <li>The first and last vertices are written as  <tt>CATCGMJournal::Creation</tt>.
* </ul>
* It follows the general frame of all operator and satisfies to the smart mechanism: the
* input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*<ul>
* <li>CATLayDown is created with the <tt>CATCreateTopLaydown</tt> global function.
* It must be
* directly deleted with the usual C++ <tt>delete</tt> operator after use.
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory.
*</ul>
* @see CATCreateTopLayDown
*/
//-----------------------------------------------------------------------------
class ExportedByAnalysisToolsLight CATLayDownOperator : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATLayDownOperator);
public :
    /** @nodoc */
	CATLayDownOperator(CATGeoFactory* iFactory,
		CATTopData* iData,
		CATBody* iBodyWireOrVertex,
		CATBody* iBodyShellOrWire
    ,CATBoolean YouHaveToUseCATCreate=TRUE
);
	
    /** @nodoc */
	CATLayDownOperator(CATGeoFactory *iFactory,
		CATBody *iBodyWireOrVertex,
		CATBody *iBodyShellOrWire,
		CATCGMJournalList *iReport=NULL
    ,CATBoolean YouHaveToUseCATCreate=TRUE
);
	
	virtual ~CATLayDownOperator();     
	
	
	/** 
	* @nodoc 
	* Sets the type of journal items 
	* (CATCGMJournal::Creation or CATCGMJournal::Modification)
	* default is Creation
	*/
	void SetJournalType(CATCGMJournal::Type);
	
	/**  
	* Runs the operator.
	*/
	int Run();
	
	/**  
	* Returns the projected body or the initial body.
	* @return
    * The result Body.
	*/
	CATBody *  GetResult();
	
	
	// ======================================================
	// NOT CAA
	// ======================================================
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
	CATLayDownDiagnostic  GetDiagnostic();

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
	CATLayDownAnalysis    GetAnalysis();

    /** @nodoc
	* Change default tolerance for operation.
	* To be called before running operator.
	* @param iTol
    * The tolerance value to set.
	*/
	void SetTolerance(double iTol);

    /** @nodoc
	* Get current tolerance for operation.
	* @return
    * Value of tolerance for operator.
	*/
	double GetTolerance() const;

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

    /** @nodoc
	* Get simplification mode.
	* @return
    * Simplication mode.
	* <br><b>Legal values</b>:
    * <dl><dt><tt>FALSE</tt> <dd> No wire simplification on Result.
    *     <dt><tt>TRUE</tt> <dd> Apply wire simplification on Result.
    *</dl>
	*/
	CATBoolean GetSimplificationMode() const;
#ifdef CATIACGMR417CAA
    /** @nodoc
	* Remove cusp and other artefacts from the result.
	* @param iRemoveArtefacts
   * 0 to keep artefacts, 1 to remove them.
   */
   void SetRemoveArtefacts(int iRemoveArtefacts);
#endif

#ifdef CATIACGMR418CAA
	/** @nodoc */
   void SetCheckReport(int i_yes_or_no);
    /** @nodoc */
   int GetCheckReport();
    /** @nodoc */
   void SetSuppressFlattenDomainMode(CATBoolean sfdm);
    /** @nodoc */
   CATBoolean GetSuppressFlattenDomainMode();
#endif
	/** @nodoc @nocgmitf */
	static const CATString * GetDefaultOperatorId() { return & _OperatorId; };
	/** @nodoc */
  virtual void ActivateOldJournal();
	
protected:
	/** @nodoc */
	const CATString * GetOperatorId();
	/** @nodoc */
	CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
	/** @nodoc */
	void WriteInput(CATCGMStream  & ioStream);
	/** @nodoc */
	void WriteOutput(CATCGMStream & ioStream);
	/** @nodoc */
	CATBoolean ValidateOutput(CATCGMStream& ioStream, CATCGMOutput& os);
	/** @nodoc */
	void Dump( CATCGMOutput& os ) ;
	/** @nodoc */
	virtual void DumpOutput(CATCGMOutput &os);
	/** @nodoc */
	virtual void DumpOutput(CATCGMStream& ioStream, CATCGMOutput& os,int VersionNumber=1);
	/** @nodoc */
	void RequireDefinitionOfInputAndOutputObjects();
	/** @nodoc */
	int RunOperator();
	
#ifdef CATIACGMR419CAA   
  /** @nodoc @nocgmitf */
  virtual int RunExactOperator();
  /** @nodoc @nocgmitf */
  virtual int RunPolyOperator();
#endif

	
private:
	
	static CATString _OperatorId;
	
	// Private Data
	CATBody                 * _input_to_put;
	CATBody                 * _input_support;
	CATBody                 * _b_domains;
	CATBody                 * _b_supports;
	CATBody                 * _result;
	CATLayDownDiagnostic      _diagnostic;
	CATLayDownAnalysis        _analysis;
	short                     _result_done;
	CATCGMJournal::Type       _jtp;
	short                     _diagnostic_already_computed;
	double                    _toler;
	CATBoolean                _SimplificationMode;
  CATBoolean                _CompletelyLaidDown;
  CATBoolean                _CATCreateNotUsed;
  CATBoolean                _ActivateOldJournal;
#ifdef CATIACGMR417CAA
  int                       _RemoveArtefacts;
#endif
#ifdef CATIACGMR418CAA
  int                      _CheckReport;
  CATBoolean               _SuppressFlattenDomainMode;
#endif

  
	/** @nodoc */
	CATBody * IsolateDomains(CATBody *iBody,short iDimension);
	/** @nodoc */
	void InsertCellInBody(CATCell *iCell,CATBody *iBody);
	/** @nodoc */
	void MergeBodies(CATBody *iBody, CATBody *&oBody, short erase=1);
	/** @nodoc */
	void CleanBody(CATBody *&oBody);
	/** @nodoc */
	void ComputeDiagnostic();
	/** @nodoc */
	void ComputeDiagnosticVsExtremities();
};
#endif
