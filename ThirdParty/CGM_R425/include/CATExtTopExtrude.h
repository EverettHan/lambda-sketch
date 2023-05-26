#ifndef CATExtTopExtrude_h_
#define CATExtTopExtrude_h_

//=============================================================================
// LD2 09 01 2015  Data members "_TrimBody", "_MustRattrapJournal" and method "SetTrim"
//                 are moved from CATExtTopSweepImp/CATExtTopRevolImp/CATExtTopPrismImp
// G5S 19 03 2015  Integrate CATContextForFastRun into CGMReplay recording.
// G5S 20 03 2015  SetResultModes take advantage of the C++ class inheritance mechanism
//                 and uses the base class, CATExtTopExtrude.
// G5S 07 09 2015  New method SetAllContextResults, which is called by CATExtTopOperator::
//                 ODTGenerateFastRunContextFromFirstRun().   New methodd to set and get 
//                 profile body.  These changes enable Fast Update Stress tests for Extrude 
//                 operators.  SetProfile shouldn't be used for any other reason.
// THM 10 12 2015  Add Set/Get for silhouette creation function. Used for Revol GetAngles.
//=============================================================================

//#include ""
#include "CATExtTopOperator.h"
#include "BOIMPOPE.h"
#include "CATTopExtrude.h"
#include "CATSweep2DataConverter.h"
#include "CATContextForFastRun.h"

class CATBody;
class CATTopExtrudeContextForFastRunExt;
class CATTopSilhouette;

typedef CATTopSilhouette* (*CreateTopSilhouetteFunction)( CATGeoFactory * iFactory, 
                                                          CATTopData * iTopData, 
                                                          CATBody * iBody); 

//#define TESTANGLE - Required for prototype of GetAngle for Revol

//ExportedByBOTOPOPE is unlikely to be correct?
class ExportedByBOIMPOPE CATExtTopExtrude : public CATExtTopOperator
{
	friend class CATTopExtrude;

protected:
	
	CATExtTopExtrude(CATGeoFactory* iGeoFactory, CATTopData* iData, CATTopExtrude* iOperateur = NULL);
	CATExtTopExtrude(CATGeoFactory * iGeoFactory, CATCGMJournalList * iJournal, CATTopExtrude* iOperateur = NULL);
public:
	//Destructor
	virtual ~CATExtTopExtrude();
	CATCGMNewClassArrayDeclare;

	CATContextForFastRun * GetContextForFastRun();

   virtual void SetSilhouetteCreateFunction(CreateTopSilhouetteFunction iFunction) {};
   virtual CreateTopSilhouetteFunction GetSilhouetteCreateFunction() const { return NULL; }

   // Only valid for Revol; provided here for test access. Hide behind R420 #ifdef, to prevent unnecessary use...?
   virtual void SetExtrudeLimitAngleOffset ( CATTopLimit iId,
     CATAngle    iOffset ) { CATThrowForNullPointer(); }
  /**
  * @nodoc
  * Defines the associated trimming body . 
  * <br>associated to the profile closure, if required.
  * <br>associated to the boolean operation, if required.
  */
  void SetTrim (CATBody * iTrimBody=NULL);

	// Find out whether the extrusion direction has been automatically inverted.
	virtual CATBoolean GetAxisWasAutoInverted();

  /**
  * Defines the type of result which is to be output.
  * <br>	 iBothResultRequired==CATBoolean(0)   : Only the relimitated shaped is output by GetResult().
  * <br>	 iBothResultRequired==CATBoolean(1)   : 
  * <br>	                 - the relimitated shaped is output by GetResult().
  * <br>	                 - the boolean Result is output by GetBooleanResult(). 
  */
  //virtual void SetResultMode (CATBoolean iBothResultRequired=CATBoolean(0)) = 0;
/**
 * @nodoc
 * Enables or disables the CXR1 shape selection mode.
 */
    void SetOldShapeRequested (CATBoolean iOldShapeOn = CATBoolean(1));

/**
 * @nodoc
 * Enables the choice of the limitation algorithm.
 * @param iMode
 * Mode 1 just as Mode 2 plus SetOldShapeRequested(1).
 * Mode 2 is the first enabled mode.
 * Mode 3 has been enabled since the V5R6.
 * Mode 4 has been enabled since the V5R7.
 * Mode 5 has been enabled since the V5R10.
 * Mode 6 has been enabled since the V5R11.
 * @param iAutomaticDirectionInversion
 * This parameter has an effect when one of the limit is a offset value and the second one is the contextual limit ( UP TO .. )
 * Mode 0 : the contextual limit is searched according only to the extrusion direction.
 * Mode 1 : enable to automatic revert the extrusion direction when no limit was found in the extrusion direction ( default mode ).
 */
    void SetRelimitationMode(short iMode = 2, short iAutomaticDirectionInversion = 1);

/**
 * @nodoc
 * @param iPolarity
 * CATBoolean(0) indicates a normal body polarity, an union operation adds matter and a
 *               substract removes matter.
 * CATBoolean(1) indicates a reversed body polarity, an union operation removes matter and a
 *               substract adds matter.
 */
    void SetReversePolarity(CATBoolean iPolarity = CATBoolean(1));


/**
 * @nodoc
 */
    void SetJournalMode(short iJournalMode);

/**
 * @nodoc
 */
    void UnsetCheckTopoTwist(CATBoolean iUnsetCheckTopoTwist = CATBoolean(1));


/**
 * @nodoc
 */
    void SetThinSolidMode ( const CATBoolean   iThinSolidMode                           ,
                            const CATBoolean   iIsNeutralFiber                          ,
                            const double       iThinSolidThickness[2]                   ,
                            ListPOfCATDomain * iWireListWithReverseThinSolidSide = NULL );

/**
 * Defines the simplication mode.
 * @param iSimplify
 * The simplication mode.
 * <br><b>Legal values</b>: <tt>CATBoolean(1)</tt> to simplify as much as possible the faces of the 
 * resulting body, <tt>CATBoolean(0)</tt> otherwise. By default, no simplication is done.
 */
    void SetSimplification(CATBoolean iSimplify = CATBoolean(1));

#ifdef  TEMP_CATFREEZEMODE
/**
 * Defines the state of the resulting body.
 * @param iOnOrOff
 * The state of the resulting body. 
 */
  void SetFreezeMode(CATBodyFreezeMode iOnOrOff);

/**
 * Returns the mode in which the resulting body is created.
 * @return
 * The state of the resulting body.
 */
  CATBodyFreezeMode GetFreezeMode()const;
#endif

    
/**
 * @nodoc
 * get the CXR1 shape selection mode.
 */
    CATBoolean GetOldShapeRequested ();

    void GetRelimitationMode(short &oMode, short &oAutomaticDirectionInversion);
/**
 * @nodoc
 * @return Polarity
 * CATBoolean(0) indicates a normal body polarity, an union operation adds matter and a
 *               substract removes matter.
 * CATBoolean(1) indicates a reversed body polarity, an union operation removes matter and a
 *               substract adds matter.
 */
    CATBoolean GetReversePolarity();

/**
 * @nodoc
 */
    CATBoolean GetCheckTopoTwist();

/**
 * Returns a pointer to a body equivalent to that which will be used by extrude after
 * extrapolating, if the limit is an extrapolated 'until' limit.
 * @param iLimit
 * The limit for which the extrapolation is to be done
 * @return
 * The pointer to the created body. If the limit is not an extrapolated 'until' limit, the return will be NULL.
 * If you do not want to keep this body, 
 * use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory.
 */
    virtual CATBody * GetExtrapolatedLimitBody(CATTopLimit iLimit);

/**
 * @nodoc
 */
    void GetThinSolidMode ( CATBoolean   & oThinSolidMode                           ,
                            CATBoolean   & oIsNeutralFiber                          ,
                            double         oThinSolidThickness[2]                   ,
                            ListPOfCATDomain * iWireListWithReverseThinSolidSide);

/**
 * Get the simplication mode.
 * @return iSimplify
 * The simplication mode.
 * <br><b>Legal values</b>: <tt>CATBoolean(1)</tt> to simplify as much as possible the faces of the 
 * resulting body, <tt>CATBoolean(0)</tt> otherwise. By default, no simplication is done.
 */
    CATBoolean GetSimplification();

/**
 * Returns a pointer to the profile body.
 */
 virtual CATBody * GetProfile();

 /**
  * Set the profile body.  WARNING: This should only be used for Fast Run Stress tests.
  */
 virtual void SetProfile (CATBody * iProfile);

/**
 * Returns a pointer to the body resulting from the Boolean operation between the extrusion and a trimming body. 
 * <br>Available if <tt>SetResultMode(CATBoolean(1))</tt> has been invoked.
 * @return
 * The pointer to the created body. 
 * If you do not want to keep this body, 
 * use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory, after the operator deletion.
 */
    CATBody * GetBooleanResult() const;

/**
 * Returns a pointer to the topological Boolean journal dedicated to 
 * <tt>this</tt> CATTopExtrude.
 * <br>The journal only contains the items relative to the Boolean operation. Available 
 * if <tt>SetResultMode(CATBoolean(1)) </tt> has been invoked.
 * @return
 * The pointer to the topological journal.
 * The user has now in charge the lifecycle of the journal
 */
    CATCGMJournalList * GetBooleanJournal() const;

/**
 * Returns a pointer to the topological Boolean journal dedicated to 
 * <tt>this</tt> CATTopExtrude.
 * <br>The journal only contains the items relative to the Boolean operation. Available 
 * if <tt>SetResultMode(CATBoolean(1)) </tt> has been invoked.
 * @return
 * The pointer to the topological journal.
 * The operator will erase the journal if no GetBooleanJournal has been done
 * use for CGMReplay of derived classes
 */
    CATCGMJournalList* GetLocallyBooleanJournal() const;

/**
 * Tests whether the trimming body is touched by the Boolean operation. 
 * @return
 * The result of the test.
 * <br><b>Legal values</b>: <tt>TRUE</tt> if it is touched, <tt>FALSE</tt> otherwise.
 */
    CATBoolean IsResultInvariant() const;

    CATBoolean IsNamingLimitRequested () const;

/** @nodoc
 * In case of contextual Limit and if there are several possible disconnecting intersections
 * between the extrusion and a contextual limit:
 * @param iIsRequested
 * if set to TRUE, it enables to get a list of possible naming after a first run. 
 */
    virtual void SetNamingLimitRequested (CATBoolean iIsRequested);

 /** @nodoc @nocgmitf
 * In case of contextual Limit and if case of surfacic limitation
 * between the extrusion and a contextual limit:
 * @param iWireLimitationAccepted
 * if set to TRUE, it enables to accept a wire as limit. 
 */
    virtual void SetWireLimitationAccepted (CATBoolean iWireLimitationAccepted);

   /** @nodoc @nocgmitf CATCGMReplay */
    static void LoadInOutput(CATCGMStream            &ioStream,
                             CATGeoFactory*          &iFactory,
                             CATTopData              &ioTopData,
                             CATBodyFreezeMode       &iFreezeMode,
                             //CATBoolean              &iInvariantResult,
                             CATBoolean              &iOldShapeRequested,
                             short                   &iRelimitationMode,
                             short                   &iAutomaticDirectionInversion,
                             short                   &iJournalMode,
                             CATBoolean              &iReversePolarity,
                             CATBoolean              &iUnsetCheckTopoTwist,
                             CATBoolean              &iSimplify,
                             CATLISTP(CATICGMObject) &ioInputCopy,
                             CATLISTP(CATICGMObject) &ioInputNoCopy,
                             CATBody*                &ioOutputBody,
							 CATBoolean				 *iThinSolidMode,
							 CATBoolean				 *iIsNeutralFiber,
							 double					 *iThinSolidThickness,
							 ListPOfCATDomain		 *iWireListWithReverseThinSolidSide,
                             CATCGMODTScaleManager   *iODTScaleManager,
                             CATContextForFastRunExt* iopCtxExt);

/** @nodoc
 * Do smartification for both results and update the member variables for the result and Boolean result and
 * the journals.  
 * The Boolean journal is the journal showing the process Result->BooleanResult, not Input->BooleanResult.
 * We have to pass in the Non-Boolean Journal because this is stored in different places for the Prism,
 * Revol and Sweep operators.
 */
#ifdef FASTRUN_InternalContexts
    virtual void DoSmartificationBothResultsAndUpdate (CATCGMJournalList * ioNonBooleanJournal);
#endif
    virtual void GetAngles(double& oStartAngle, double& oEndAngle); 
#ifdef TESTANGLE    
    virtual CATBoolean ProfileTouchesAxis() { return FALSE; }
#endif
  protected:
		CATTopExtrudeContextForFastRunExt * GetTopExtrudeContextForFastRun();

    // Set both results from iCurOpe in the context from this operator, ioContext.
    virtual void SetAllContextResults(CATContextForFastRun* ioContext, CATTopOperator * iCurOpe);

    /** @nodoc */
    void Init();

    /** @nodoc CATCGMReplay */
    void WriteInput(CATCGMStream &ioStream);
    /** @nodoc CATCGMReplay */
    void RequireDefinitionOfInputAndOutputObjects();
    /** @nodoc CATCGMReplay */
    void Dump(CATCGMOutput &os);
    /** @nodoc CATCGMReplay */
    void DumpOutput(CATCGMOutput &os);
    /** @nodoc CATCGMReplay */
    CATCGMOperator::CATCheckDiagnostic CheckOutput(CATCGMOutput & os);
    /** @nodoc CATCGMReplay */
    CATBoolean ValidateOutput(CATCGMStream &Str, CATCGMOutput &os, int VersionNumber=1);

    /** @nodoc */
    CATBody                 *_TrimBody;
    /** @nodoc */
    int                      _MustRattrapJournal;

    /** @nodoc */
    int GetMaxProfileDim(CATBody* iProfile);

    /** @nodoc */
    void SetBooleanResult (CATBody * iBooleanResult);
    /** @nodoc */
    void SetBooleanJournal (CATCGMJournalList* iBooleanJournal);
    /** @nodoc */
    void SetInvariantResult (CATBoolean iInvariant);
/** @nodoc */
    CATCGMActivateDebug  *_AssociatedBreakPoint;
    /** @nodoc Journal for the process _Result -> _BooleanResult.*/
    CATCGMJournalList    *_BooleanJournal;
    /** @nodoc */
    CATCGMJournalList    *_UnusedToDelete;
    /** @nodoc */
    CATBody              *_BooleanResult;
    /** @nodoc */
    CATBoolean            _InvariantResult;
    /** @nodoc */
    CATBoolean            _OldShapeRequested;
    /** @nodoc */
    short                 _RelimitationMode;
    /** @nodoc */
    short                 _AutomaticDirectionInversion;
    /** @nodoc */
    CATBoolean            _ReversePolarity;
    /** @nodoc */
    CATBoolean            _UnsetCheckTopoTwist;
    /** @nodoc */
    CATBoolean            _Simplify;

#ifdef  TEMP_CATFREEZEMODE
    /** @nodoc */
    CATBodyFreezeMode     _freezemode;
#endif

    /** @nodoc */
    CATBoolean            _ThinSolidMode;
    /** @nodoc */
    CATBoolean            _IsNeutralFiber;
    /** @nodoc */
    double                _ThinSolidThickness[2];
    /** @nodoc */
    ListPOfCATDomain      _WireListWithReverseThinSolidSide; 
    /** @nodoc */
    short                 _JournalMode;
    /** @nodoc */
    CATBoolean            _ExtrudeLimitNamingRequested;
    /** @nodoc */
    CATBoolean            _IsWireLimitationAccepted;

};

#endif

