// N.B il faut definir toute nouvelle methode appelable par l'appli aussi dans 
// CATTopSweep.h ou CATTopExtrude.h,
// ainsi que dans CATExtTopSweepImp.h

/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATTopSweepImp: 
// Basic Class For Sweep Operators Implementation 
//
//=============================================================================
// Usage notes:
//
//=============================================================================
//      Jan. 99 CFT Creation                                   C. Foucart
// 03/03/99 NLD Migration vers CATFrFTopologicalSweep 
//              (INACTIVE)
// 10/03/99 NLD Activation de la migration vers CATFrFTopologicalSweep 
// 22/04/99 NLD Ajout _Factory, _ImplicitFactory, _Journal, _LaidCenter
// 16/06/99 LMH Check des operandes
// 10 11 99 NLD doc restriction des supports a CATSurface et CATBody
// 07 12 99 NLD SetPullingDirection(), _PullingDirection
// 16 12 99 ALM Nouvelle methode de check : CheckOperands
// 06/01/00 NLD la pullingdirection recue devient un CATMathVector (pour CAA2)
// 17 08 00 ALM Branchement du CATSweep2 via CATGetEnv dans le cpp
// 28 02 01 ALM SetDiscontinuityTreatment
// 08 03 01 NLD SetTwistDetection()
// 08 03 01 NLD _TopDataReceived
// 19 03 01 ALM SetCuspTreatment
// 08 11 01 NLD Init() _CenterSupport
// 05 11 03 NLD SetTwistReduction()
// 05 11 03 NLD Ajout GetInternalSweep2()
//              Ajout _ResultModeSpecified, _BothResultRequired
// 03 12 03 NLD Ajout de GetWarning()
// 04 12 03 NLD Ajout de _Warning
// 02 01 04 NLD on differe, pour gestion de la compatibilité, l'envoi des options
//              recues via SetTwistReduction(), SetCuspTreatment, SetDiscontinuityTreatment().
//              Ajout de ApplyTwistReduction(), CreateTopologicalSweep(), CreateIntermediateProfileBody()
//              _CuspTreatment, _DiscontinuityTreatment, _TwistReduction, _RecoilDistance,
//              _IntermediateProfileBody
// 18 12 04 NLD Ajout de _TwistDetection
// 12 01 06 NLD Ajout de GetInternalSweep2Internal()
// 26 10 06 NLD Ajout ForceMultipleViewingDirMode() et _ForcedMultipleViewingDirMode
// 15 12 06 NLD Ajout BooleanReduction()
// 18 12 06 NLD Ajout ForceFillTwistMode() et _ForcedFillTwistMode
//              Ajout SetTwistReductionPrivate()
//              Ajout _UseLocalBoolean
// 18 03 10 THM Use Extensible (CATExtTopSweepImp. Also add SetExtrudeLimit() interface to replace SetLimit()
// 15/06/10 NLD Les donnees membres sont definies dans CATTopSweepImpData.h
//              Shunt des methodes internes necessaires seulement dans l'extension en R21
// 17/06/11 NLD Deflaggage de la migration d'architecture R20/R21
//              et suppression de #define CATTopSweepImp_ShuntInternalMethods
// 20/09/11 NLD Ajout RunOperator() pour passage éventuel par CATCGMOperator::Run()
// 08/02/12 NLD Suppression CATCreateTopSweepImp() et CATTopCreateSweepImp() qui n'ont aucune raison d'etre
//=============================================================================

//=============================================================================
// Classes definition
//=============================================================================

#ifndef CATTopSweepImp_H
#define CATTopSweepImp_H

#include <FrFTopologicalOpe.h>
#include <CATTopSweep.h>
#include <CATBooleanType.h>
#include <CATMathDirection.h>
#include <CATThrowForNullPointer.h>

#ifndef NULL
#define NULL 0
#endif

class CATBody;
class CATCGMJournalList;
class CATFrFTopologicalSweep;
class CATSweep;
class CATSweep2;
class CATIPGMSweep2;
class CATGeometry;

class CATExtTopSweepImp;

//-----------------------------------------------------------------------------
/**
 * Internal implementation of the basic behavior of the topological Sweep operator
 */
class ExportedByFrFTopologicalOpe CATTopSweepImp : public CATTopSweep
{
  public:
/** 
 * Constructor
 * @param iContainer
 * The factory of the resulting body.
 * @param iData
 * ...
 * @param iCenterBody
 * The center curve of the sweep: curve along which the profile is swept.
 * @param iCenterSupport
 * Where the center curve is laying on:
 * (valid types are CATSurface and CATBody (containing a shell or a lump))
 * @param iSpineBody
 * The spine curve of the sweep: the curve that handles the normal to the profile plane.
 * @param iProfBody
 * The profile of the sweep.
 */
    CATTopSweepImp (CATGeoFactory      * iGeoFactory,
                    CATTopData         * iData,
                    CATBody            * iCenterBody,
                    CATGeometry        * iCenterSupport,
                    CATBody            * iSpineBody,
                    CATBody            * iProfBody,
                    CATExtTopSweepImp  * iExtensible);
/** 
 * Constructor
 * @param iContainer
 * The factory of the resulting body.
 * @param iCenterBody
 * The center curve of the sweep: curve along which the profile is swept.
 * @param iCenterSupport
 * Where the center curve is laying on:
 * (valid types are CATSurface and CATBody (containing a shell or a lump))
 * @param iSpineBody
 * The spine curve of the sweep: the curve that handles the normal to the profile plane.
 * @param iProfBody
 * The profile of the sweep.
 * @param iJournal
 * If not <tt>NULL</tt>, pointer to the topological journal corresponding to this operation.
 */
    CATTopSweepImp (CATGeoFactory      * iGeoFactory,
                    CATBody            * iCenterBody,
                    CATGeometry        * iCenterSupport,
                    CATBody            * iSpineBody,
                    CATBody            * iProfBody,
                    CATCGMJournalList  * iJournal,
                    CATExtTopSweepImp  * iExtensible);
/**
 * Destructor.
 */
    ~CATTopSweepImp ();

    //-------------------------------------------------------------------------
    // Data Modification
    //-------------------------------------------------------------------------

/**
 * Defines the type of limitation of each extremity of the profile.
 * @param iOffset
 * value of offset if <tt>iType</tt> is valued to <tt>CatLimOffsetFromProfile</tt> 
 * <br> the value of the the thickness if <tt>iIsThickness</tt> is valued to <tt>CATBoolean(1)</tt> 
 * @param iLimit
 * The geometry which stops the extrusion.
 * @param iPropagationBody
 * The body which stops the extrusion 
 * <br> if <tt>iType</tt> is valued to <tt>CatLimUntil</tt> and
 * <tt>iPropagationFlag</tt> is valued to <tt>CatPropagClosing</tt> 
 * <br> or if <tt>iType</tt> is valued to <tt>CatLimNextAlongAxis</tt> or <tt>CatLimLastAlongAxis</tt> 
 * @param iIsThickness
 * value of the thickness to be applied to the considering relimitation
 */
    void SetExtrudeLimit (CATTopLimit             iId,
                          CATTopLimitType         iType,
                          CATBoolean              iIsAxisReverted,
                          CATLength               iOffset,
                          CATGeometry           * iLimit,
                          CATBody               * iPropagationBody,
                          CATTopPropagationType   iPropagationFlag,
                          CATLength               iThickness = CATLength(0.0));


/**
 * Defines the type of limitation of each extremity of the profile.
 * @param iOffset
 * value of offset if <tt>iType</tt> is valued to <tt>CatLimOffsetFromProfile</tt> 
 * <br> the value of the the thickness if <tt>iIsThickness</tt> is valued to <tt>CATBoolean(1)</tt> 
 * @param iLimit
 * The geometry which stops the extrusion.
 * @param iPropagationBody
 * The body which stops the extrusion 
 * <br> if <tt>iType</tt> is valued to <tt>CatLimUntil</tt> and
 * <tt>iPropagationFlag</tt> is valued to <tt>CatPropagClosing</tt> 
 * <br> or if <tt>iType</tt> is valued to <tt>CatLimNextAlongAxis</tt> or <tt>CatLimLastAlongAxis</tt> 
 * @param iIsThickness
 * defines whether a thickness must be applied to the considering relimitation
 * <br> the value of the the thickness is <tt>iOffset</tt>
 */
    void SetLimit (CATTopLimit             iId,
                   CATTopLimitType         iType,
                   CATBoolean              iIsAxisReverted,
                   CATLength               iOffset,
                   CATGeometry           * iLimit,
                   CATBody               * iPropagationBody,
                   CATTopPropagationType   iPropagationFlag,
                   CATBoolean              iIsThickness = CATBoolean (0));
/**
 * Defines the pulling direction
 * (previously defined Spine will then be ignored)
 * @param iPullingDirection
 * defines an implicit spine that is the projection of the guide in a plane
 * normal to this direction
 */
    void SetPullingDirection(CATMathVector * iPullingDirection = 0) ;

/**
 * @nodoc
 */
    void SetDiscontinuityTreatment(CATLONG32 iMode = 0);
/**
 * @nodoc
 */
    void SetCuspTreatment(CATLONG32 iMode = 0);
/**
 * @nodoc
 */
    void SetTwistDetection(CATBoolean iTwistDetection=TRUE);
/**
 * @nodoc
 */
    void SetTwistReduction(CATBoolean iTwistReduction, double iRecoilDistance=0.0);
/**
 * Asks for the closure of the profile 
 * <br>And defines the associated triming body.
 */
    void SetProfileClosure ();
/**
 * Asks for a boolean operation within the extrude operation 
 * <br>And defines the boolean operand.
 */
    void SetOperation (CATTopBooleanType iBoolType=CatBoolNone);
/**
 * Defines the associated triming body . 
 * <br>associated to the profile closure, if required.
 * <br>associated to the boolean operation, if required.
 */
    void SetTrim (CATBody * iTrimBody=NULL);
/**
 * Defines the type of result which is to be output.
 * <br> iBothResultRequired==CATBoolean(0)   : Only the relimitated shaped is output by GetResult().
 * <br> iBothResultRequired==CATBoolean(1)   : 
 * <br>                 - the relimitated shaped is output by GetResult().
 * <br>                 - the boolean Result is output by GetBooleanResult(). 
 */
    void SetResultMode (CATBoolean iBothResultRequired=CATBoolean(0));
/**
 * Checks the consistency of the input operandes. OLD METHOD
 */
    CATBoolean HasConsistentOperandes (CATLONG32 &oNbError, CATError **&oErrors);
/**
 * Checks the consistency of the input operands. NEW METHOD
 */
    CATBoolean CheckOperands (CATLONG32 &oNbError, CATError **&oErrors);
    
/**
 * Forces the multiple viewing direction mode
 */
    void ForceMultipleViewingDirMode() ;
/**
 * Forces the fill twist mode
 */
    void ForceFillTwistMode() ;
/**
 * nodoc
 * access to warnings
 */
/*
   CATTopOpInError* GetWarning();
*/
    //-------------------------------------------------------------------------
    // Run
    //-------------------------------------------------------------------------
    int Run ();
    int RunOperator();



  private:
/**
 * @nodoc
 */

    inline CATExtTopSweepImp* GetTopSweepImpExtensible() const;
};

inline CATExtTopSweepImp* CATTopSweepImp::GetTopSweepImpExtensible() const
{
   if (!_Extensible) CATThrowForNullPointerReturnValue(NULL);
   return (CATExtTopSweepImp*) _Extensible;
}
#endif
