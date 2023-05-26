#ifndef CATEXTRAPOLATEBODY_H
#define CATEXTRAPOLATEBODY_H

// COPYRIGHT DASSAULT SYSTEMES 1999
/**
* @level Protected
* @usage U1
*/

//=============================================================================
// Extrapolation in tangency of a single wire body on one or both extremites with imposed lengths or targets
//=============================================================================
//
#include <CATIACGMLevel.h>
#define CATExtrapolateBody_CGMReplayImplementation
#define CATExtrapolateBody_CGMReplayImplementationWithLimitType
#define CATExtrapolateBody_NewR21SP2Methods "ajout autorisé methodes non virtuelles"

#include <BO0SWEEP.h>
#include <CATTopOperator.h>

#ifdef CATExtrapolateBody_CGMReplayImplementation
#include <CATCGMStream.h>
// pb architecture; ramené indirectement par une astuce #include <CATCGMOutput.h>
#endif

// #define  CATExtrapolateBody_TestComputeExtrapolation


class CATGeoFactory;
class CATBody;
class CATDomain;
class CATEdge;
class CATSurface;
class CATCurve;
class CATFace;
class CATCell;
class CATCGMJournalList;
class CATLoop;
class CATCrvParam;
class CATMathBox;
class CATMathPlane;
class CATMathDirection;
class CATMathLine;
class CATMathPoint;
class CATMathVector;
#ifndef NULL
#define NULL 0
#endif

/**
* Class representing an operator that extrapolates 1D body (CATWire).
*<br>The wire can be extrapolated on a planar support (optional).
*<br>The extrapolation gives a result that is continuous in tangency.
* To use it:
* <ul>
* <li>Create it with the <tt>CATCreateExtrapolateBody</tt> global function.
* <li>Tune it with appropriate options, using the <tt>SetXxx</tt> methods.
* <li>Run it
* <li>Get the resulting body, using the <tt>GetResult</tt> method. If you do not want
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the
* geometric factory, after the operator deletion.
*<li>Delete it after use  with the usual C++ <tt>delete</tt> operator.
*</ul> 
*/ 

class ExportedByBO0SWEEP CATExtrapolateBody : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATExtrapolateBody);
public:
    /** @nodoc */
    CATExtrapolateBody (CATGeoFactory     * iGeoFactory,
        CATBody           * iBodyToExtrapol,
        CATSurface        * iSupport=NULL,
        CATCGMJournalList * iReport=NULL,
        double              iMinimumGap=0.);

    /** @nodoc */
    CATExtrapolateBody (CATGeoFactory     * iGeoFactory,
        CATBody           * iBodyToExtrapol,
        CATTopData        * iTopData,
        CATSurface        * iSupport=NULL,
        double              iMinimumGap=0.);

    /**
    * Destructor.
    */
    virtual ~CATExtrapolateBody();

    /**
    * Runs <tt>this</tt> operator.
    */
    int Run() ;

    /**
    * @nodoc
    *<p>Extrapolates the wire to a CATMathBox limit.
    *<br>The target.
    *<xmp>
    *                                   --------- (*iTargetBox)
    *                                   !       !
    *      .....                        !       !
    *   ...                             !       !
    * ..                                ---------
    *</xmp>
    *<br>The wire after extrapolation.
    *<xmp>
    *                                   --------- (*iTargetBox)
    *                                   !       !
    *      .............................!.......!.
    *   ...                             !       !
    * ..                                ---------
    * </xmp>
    * @param iEndCell
    * The pointer to the cell to be extrapolated.
    * @param iTargetBox
    * The pointer to the CATMathBox to be used as an extrapolation limit.
    */
    void SetLimitToExtrapolate
        (CATCell          * iEndCell,
        CATMathBox       * iTargetBox);

    /**
        * @nodoc
        *<p>Extrapolates the wire to a CATBody limit. A CATMathBox is used
        * to refine the computation.
        *<br>The target.
        *<xmp>
        *                                   --------- (*iTargetBody)
        *                                   !       !
        *      .....                        !       !
        *   ...                             !       !
        * ..                                ---------
        *</xmp>
        *<br>The wire after extrapolation.
        * <xmp>
        *                                   --------- (*iTargetBody)
        *                                   !       !
        *      .............................!       !
        *   ...                             !       !
        * ..                                ---------
        * </xmp>
        * @param iEndCell
        * The pointer to the cell to be extrapolated.
        * @param iTargetBox
        * The pointer to the CATMathBox to be used in order to refine the computation.
        * @param iTargetBody
        * The pointer to the body to be used as an extrapolation limit.
    */
    void SetLimitToExtrapolate
       (CATCell          * iEndCell,
        CATMathBox       * iTargetBox,
        CATBody          * iTargetBody);
        /** 
        * Specifies the extrapolation length.
        * @param iEndCell
        * The pointer to the cell to be extrapolated.
        * @param iLength
        * The extrapolation length.
    */
    void SetLimitToExtrapolate
       (CATCell          * iEndCell,
        double             iLength );

    /** 
        * @nodoc
        *<p>Specifies a target CATMathBox plus another CATMathBox to be translated to
        * the extrapolation end.
        *                                   ---------
        *         ---- (*iSourceBox)        !       !
        *  .......!.*!                      !       !
        *         ----                      !       !
        *                                   ---------
        * After extrapolation
        *                                   --------- (*iTargetBox)
        *                                   !       !----
        *      .............................!.......!!  ! (*iSourceBox translated to extrapolation end)
        *   ...                             !       !----
        *                                   ---------
        * @param iEndCell
        * The pointer to the cell to be extrapolated.
        * @param iSourceBox
        * The CATMathBox to be translated.
        * @param iTargetBox
        * The target box.
    */
    void SetLimitToExtrapolate
       (CATCell          * iEndCell,
        CATMathBox       * iSourceBox,
        CATMathBox       * iTargetBox);

    /**
        * @nodoc
        * Specifies a target plane. The input CATMathPlane can be of any orientation
        * (the normal to the plane
        * is defined so that the scalar product with the extrapolation direction is positive).
        *<xmp>
        *    --                                !
        *   !  !  ------------->               !->
        *    --                                !
        * </xmp>
        * <p> After extrapolation
        *<xmp>
        * 
        *                                       ! --
        *                                       !!  !
        *                                       ! --
        * </xmp>
        * In addition, the source box which is translated can be rotated around
        * the optional revolution axis. See below:
        * <xmp>
        *            * !  * (points resulting from the revolution)
        *          P   !     *
        *         *    C     M : End point translated by the source box 
        *         . *  !  *
        *              !      . <-- tg: end tangent
        * tgP--> .     !
        *              !       .
        *       .      !           * <-- targetplane
        *              !       *
        *      .       !   *
        *              O
        *     .    *    .
        *       *         . (. : plane normal)
        *</xmp>
        */
    void SetLimitToExtrapolate
       (CATCell          * iEndCell,
        CATMathBox       * iSourceBox,
        CATMathPlane     * iTargetPlane,
        CATMathLine      * iRevolutionAxis = NULL);

    /**
     * @nodoc
     * Specifies a CATMathDirection in addition to the CATMathBox.
     * The translated plane relimits the extrapolation after the CATMathBox.
    *<xmp>
    *            *              --
    * ............* -->        !  !
    *              *            --
    *               * (plane)
    *</xmp>
    *<p> After extrapolation
    *<xmp>
    *                           -- *
    * .........................!..!.* 
    *                           --   *
    *                                 * (translated plane)
    *</xmp>
    */
    void SetLimitToExtrapolate 
       (CATCell          * iEndCell,
        CATMathDirection * iSourcePlaneDirection,
        CATMathBox       * iTargetBox);

    /**
        * Returns the pointer to the resulting body.
    */
    CATBody* GetResult() ;
    
    /**
    @nodoc
    Returns the topological journal.
    */
    CATCGMJournalList * GetTopReport ();

    /** @nodoc
    * Enables the replacement of internal edge and vertex in the case of a line 
    * extrapolation.
    * By default, there is no replacement.
    */
    void SetReplaceMode();

public:
   /**   @nodoc @nocgmitf */
   static const  CATString  *GetDefaultOperatorId();

protected:
   /**   @nodoc @nocgmitf */
   int RunOperator();

   /**   @nodoc @nocgmitf */
   static  CATString  _OperatorId;
   /**   @nodoc @nocgmitf */
   const  CATString  *GetOperatorId();
   /**  
   @nodoc @nocgmitf 
   pour le flaggage definitif de la definition complete des donnees Input/Output de l'operateur
   */
   void   RequireDefinitionOfInputAndOutputObjects();

#ifdef CATExtrapolateBody_CGMReplayImplementation
   /**   @nodoc @nocgmitf */
   void WriteInput(CATCGMStream& Str);
   /**   @nodoc @nocgmitf */
   void Dump      (CATCGMOutput &os);
   /**   @nodoc @nocgmitf */
   CATExtCGMReplay* IsRecordable(short& oLevelOfRuntime, short& oVersionOfStream);
#endif


protected:

    #ifdef CATExtrapolateBody_NewR21SP2Methods
    /** @nodoc nocgmitf */
     void Init();
    /** @nodoc nocgmitf */
     void RattrapReport(int dbgReport);
    #endif
    /** @nodoc */
    double ComputeExtrapolationLength
       (CATMathPoint     & iPointExtr,
        CATMathVector    & iTgExtr  ,
        CATMathBox       * iSourceBox,
        CATMathDirection * iSourcePlaneDirection,
        CATMathBox       * iTargetBox,
        CATMathPlane     * iTargetPlane,
        CATMathLine      * iRevolutionAxis);
    /** @nodoc */
    void DefLimitToExtrapolate
       (int                iLimitType,
        CATCell          * iEndCell,
        CATMathBox       * iSourceBox,
        CATMathDirection * iSourcePlaneDirection,
        CATMathBox       * iTargetBox,
        CATMathPlane     * iTargetPlane,
        CATMathLine      * iRevolutionAxis,
        CATBody          * iTargetBody,
        double             iSpecifiedLength
       );
    /** @nodoc */
    void TrimWireOnBody(
        CATGeoFactory            * iGeoFactory,
        CATSoftwareConfiguration * iConfig,
        CATCurve                 * iCurve,
        CATBody                  * iTargetBody,
        CATCrvParam              & oCrvParam );

#ifdef  CATExtrapolateBody_TestComputeExtrapolation
    /** @nodoc */
    void TestComputeExtrapolation ();
#endif

    /** @nodoc */
    CATGeoFactory*    _GeoFactory;
    /** @nodoc */
    CATGeoFactory*    _ImplFactory;
    /** @nodoc */
    CATSurface*       _InputSupport;
    /** @nodoc */
    CATBody *         _InputBody;
    /** @nodoc */
    double            _MinimumGap;
    /** @nodoc */
    CATBody *         _ResultBody;
    /** @nodoc */
    CATCGMJournalList* _Report;
    /** @nodoc */
    CATCGMJournalList* _TmpReport;
    /** @nodoc */
    CATLONG32          _ReplaceMode; // 1 for Replace mode
    /** @nodoc */
    short              _JournalJuste; // 1 if end vertex OK
    /** @nodoc */
    int               _NbEndToExtrapolate ;
#define             CATExtrapolateBody_MaxEndToExtrapolate 2
    /** @nodoc */
    CATCell*          _EndCells    [CATExtrapolateBody_MaxEndToExtrapolate];
    /** @nodoc */
    CATMathBox*       _TargetBoxes [CATExtrapolateBody_MaxEndToExtrapolate];
    /** @nodoc */
    CATMathPlane*     _TargetPlanes[CATExtrapolateBody_MaxEndToExtrapolate];
    /** @nodoc */
    CATMathBox*       _SourceBoxes [CATExtrapolateBody_MaxEndToExtrapolate];
    /** @nodoc */
    CATMathDirection* _SourcePlaneDirections [CATExtrapolateBody_MaxEndToExtrapolate];
    /** @nodoc */
    CATMathLine*      _RevolutionAxis [CATExtrapolateBody_MaxEndToExtrapolate];
   /** @nodoc */
    CATBody *         _TargetBodies[CATExtrapolateBody_MaxEndToExtrapolate];
   /** @nodoc */
    double            _Lengths     [CATExtrapolateBody_MaxEndToExtrapolate];
   #ifdef CATExtrapolateBody_CGMReplayImplementationWithLimitType
   /** @nodoc */
    int               _LimitType   [CATExtrapolateBody_MaxEndToExtrapolate];
   #endif
};

/**
 * Creates a CATExtrapolateBody operator.
 * @param iFactory
 * The factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt>
 * is <tt>NULL</tt>, it is not filled.
 * @param iBodyToExtrapol
 * The CATWire to be extrapolated.
 * @param iSupport
 * The surfacic support on which the CATWire is to be extrapolated. This option is
 * only available for planar supports.
 * @param iMinimumGap
 * The minimum gap. 
 * @return
 * The pointer to the created operator. To delete after use with the usual C++ <tt>delete</tt> operator.
 */
ExportedByBO0SWEEP CATExtrapolateBody * CATCreateExtrapolateBody( CATGeoFactory     * iGeoFactory,
                                                                  CATTopData        * iTopData,
                                                                  CATBody           * iBodyToExtrapol,
                                                                  CATSurface        * iSupport=NULL,
                                                                  double              iMinimumGap=0.);

#ifdef CATExtrapolateBody_CGMReplayImplementation
/**   @nodoc @nocgmitf */
/**
 * Creates a CATExtrapolateBody operator from a CGMReplay file.
 */
extern "C"
ExportedByBO0SWEEP CATCGMOperator* CATLoadCATExtrapolateBody(CATCGMStream &Str, const short LevelOfRuntime, const short VersionOfStream);
#endif

#endif
