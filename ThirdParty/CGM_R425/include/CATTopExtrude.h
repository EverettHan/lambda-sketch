#ifndef CATTopExtrude_H
#define CATTopExtrude_H

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 
#include "CATIACGMLevel.h"

#include "BOTOPOPE.h"
#include "CATTopOperator.h"
#include "CATTopBooleanType.h"
#include "CATTopLimit.h"
#include "CATTopLimitType.h"
#include "CATTopPropagationType.h"
#include "CATMathDef.h"
#include "ListPOfCATDomain.h"

class CATBody;
class CATCGMJournalList;
class CATGeoFactory;
class CATCGMActivateDebug;
class CATGeometry;
class CATError;
class CATExtTopExtrude;

#include "CATThrowForNullPointer.h"

#ifndef NULL
#define NULL 0
#endif

#define TEMP_CATFREEZEMODE
#ifdef  TEMP_CATFREEZEMODE
#include "CATGeoToTopOperator.h"
#endif

class CATTopData;

/**
 * Base class for of all the topological operators doing extrusions. 
 * <br>Extrusion operators deriving 
 * from this base class are used to build a prism, to revolve a profile about an axis 
 * or to sweep a profile along a guide.
 * <br> In addition to the extrusion creation, these operators provide the capability
 * to use a Boolean operation between a body (called trimming body), and the 
 * created extrusion. To obtain such result, use the <tt>SetOperation</tt>
 * and <tt>SetTrim</tt> methods. In this case, <tt>GetResult</tt> returns the
 * created extrusion limited by the trimming body, while <tt>GetBooleanResult</tt> returns the result of
 * the Boolean operation between the trimming body and the extrusion.
 */  
class ExportedByBOTOPOPE CATTopExtrude : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopExtrude);
  
  public:
/** @nodoc */
    CATTopExtrude (CATGeoFactory * iGeoFactory, CATTopData * iData, CATExtTopOperator* iExtensible=NULL);

/** @nodoc */
    CATTopExtrude (CATGeoFactory * iGeoFactory, CATCGMJournalList * iJournal=NULL, CATExtTopOperator* iExtensible=NULL);

/**
 * Destructor.
 */
    virtual ~CATTopExtrude ();

/**
 * Asks for the closure of the profile on a given body.
 * <br>The <tt>SetTrim</tt> method must then be called to define the triming body.
 */
    virtual void SetProfileClosure () = 0;

/**
 * Asks for a Boolean operation between the extruded body and another (called trimming) body. 
 * @param iBoolType
 * The type of Boolean operation to perform after the extrusion. By default,
 * no Boolean operation is done.
 */
    virtual void SetOperation (CATTopBooleanType iBoolType=CatBoolNone) = 0;

/**
 * Defines the triming body.
 * <br>The trimming body defines the body on which the profil must be closed.
 * Moreover, it defines the body used in the Boolean operation, if any.
 * Hence, this method must be called after either a <tt>SetProfileClosure</tt>,
 * or a <tt>SetOperation</tt> call. If both are invoked, only one trimming body
 * can be set.
 * @param iTrimBody
 * The pointer to the trimming body. 
 */
    virtual void SetTrim (CATBody * iTrimBody=NULL) = 0;

/**
 * Defines the type of result to be output for <tt>this</tt> 
 * CATTopExtrude operator.
 * @param iBothResultRequired
 * The type of result.
 * <dl><dt> <tt>CATBoolean(0)</tt></dt><dd> <tt>GetResult</tt> only returns the relimitated shape
 * <dt><tt>CATBoolean(1) </tt> </dt><dd> <ul>
 *                    <li> <tt>GetResult</tt> returns the relimitated shape
 *                      <li> <tt>GetBooleanResult</tt> returns the result of the Boolean operation
 *                                                     between the relimited shape and the trimming body.
 *                       </ul>
 * </dl>
 */
    virtual void SetResultMode        (CATBoolean   iBothResultRequired=CATBoolean(0)) = 0;

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
    void UnsetCheckTopoTwist(CATBoolean iUnsetCheckTopoTwist = CATBoolean(1));

#ifdef CATIACGMV5R23
/**
 * @nodoc
 */
    virtual CATBoolean GetAxisWasAutoInverted();
#endif

/**
 * Enables or disables the operator's thin-solid mode.  This mode allows you to input a
 * wire-body profile that will be automatically thickened in a direction normal
 * to the extrusion during the operation.  The result body will therefore be a solid.
 * @param iThinSolidMode
 * A value of TRUE enables thin-solid mode.
 * @param iIsNeutralFiber
 * A value of TRUE directs the operator to thicken equally on both sides of the profile.
 * @param iThinSolidThickness
 * The distance to thicken on each side of the profile.
 * @param
 * A list of wires within the profile for which the iThinSolidThickness values are used
 * in the reverse order.
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
 * Do not use. 
 */
    virtual CATBoolean HasConsistentOperandes (CATLONG32 &oNbError, CATError **&oErrors) = 0;
/**
 * Checks the consistency of the input operands.
 * @param ioNbError
 * The number of detected problems.
 * @param oErrors
 * The array of the pointers to the detected errors. 
 * <br>To delete by the caller, as well as the created errors. 
 * @return
 * The result of the test.
 * <br><b>Legal values</b> <tt>0</tt> if a problem is detected, <tt>1</tt> otherwise.
 */
    virtual CATBoolean CheckOperands (CATLONG32 &oNbError, CATError **&oErrors) = 0;
    

#ifdef CATIACGMR215CAA
/**
 * @nodoc
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
 * Sets journal behaviour. If set to 1, the profile face will be added as a parent of faces involved in 
 * contextual limits. Also, CATCGMJournalInfoItem data will be added for faces for the start and end limits.
 * @param iJournalMode
 * New value of the journal mode
 */

    void SetJournalMode(short iJournalMode);
#endif

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
 */
    CATCGMJournalList * GetBooleanJournal() const;

/**
 * Tests whether the trimming body is touched by the Boolean operation. 
 * @return
 * The result of the test.
 * <br><b>Legal values</b>: <tt>TRUE</tt> if it is touched, <tt>FALSE</tt> otherwise.
 */
    CATBoolean IsResultInvariant() const;

#ifndef CATIACGMR215CAA
   /** @nodoc @nocgmitf CATCGMReplay */
    static void LoadInOutput(CATCGMStream            &ioStream,
                             CATGeoFactory*          &iFactory,
                             CATTopData              &ioTopData,
                             CATBodyFreezeMode       &iFreezeMode,
                             //CATBoolean              &iInvariantResult,
                             CATBoolean              &iOldShapeRequested,
                             short                   &iRelimitationMode,
                             short                   &iAutomaticDirectionInversion,
                             CATBoolean              &iReversePolarity,
                             CATBoolean              &iUnsetCheckTopoTwist,
                             CATBoolean              &iSimplify,
                             CATLISTP(CATICGMObject) &ioInputCopy,
                             CATLISTP(CATICGMObject) &ioInputNoCopy,
                             CATBody*                &ioOutputBody,
                             CATBoolean                 *iThinSolidMode,
                             CATBoolean                 *iIsNeutralFiber,
                             double                     *iThinSolidThickness,
                             ListPOfCATDomain         *iWireListWithReverseThinSolidSide);
#endif
  protected:
    /** @nodoc CATCGMReplay */
    void WriteInput(CATCGMStream &ioStream);

    /** @nodoc CATCGMReplay */
    void RequireDefinitionOfInputAndOutputObjects();

    /** @nodoc CATCGMReplay */
    void WriteOutput(CATCGMStream &ioStream);

    /** @nodoc CATCGMReplay */
    void Dump(CATCGMOutput &os);

    /** @nodoc CATCGMReplay */
    void DumpOutput(CATCGMOutput &os);

    /** @nodoc CATCGMReplay */
    CATCheckDiagnostic CheckOutput(CATCGMOutput & os);

    /** @nodoc CATCGMReplay */
    CATBoolean ValidateOutput(CATCGMStream &Str, CATCGMOutput &os, int VersionNumber=1);

    /** @nodoc */
    void SetBooleanResult (CATBody * iBooleanResult);

    /** @nodoc */
    void SetBooleanJournal (CATCGMJournalList* iBooleanJournal);

    /** @nodoc */
    void SetInvariantResult (CATBoolean iInvariant);

    /** @nodoc */
    inline CATExtTopExtrude* GetTopExtrudeExtensible() const;
};

/** @nodoc */
inline CATExtTopExtrude* CATTopExtrude::GetTopExtrudeExtensible() const
{
    if (!_Extensible) CATThrowForNullPointerReturnValue(NULL);
    return (CATExtTopExtrude*) _Extensible;
}
#endif
