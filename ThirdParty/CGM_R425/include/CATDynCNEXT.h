/* -*-c++-*- */
#ifndef CATDynCNEXT_H
#define CATDynCNEXT_H
//=============================================================================
// 12/09/00 EDS Integration capacite de versionning (CATTopData)
// 02/10/19 NLD Detabulation et mise au propre
//              Deflaggage
//              Ajout CATCreateDynShellBodyCNEXT() avec CATTopData  (hyper tardif!)
//=============================================================================
#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
//=============================================================================
#include "BONEWOPE.h"
//#include "AnalysisTools.h"
#include "AnalysisToolsLight.h"
#include "CATDynCNEXTLight.h"

#include "CATDynBoolean.h"
#include "CATDynBooleanTrim.h"
#include "CATDynSplit.h"
#include "CATDynPrism.h"
#include "CATDynRevol.h"
#include "CATDynTransformation.h"
#include "CATDynShellBody.h"
#include "CATDynThickness.h"
#include "CATDynIntersectionSurBody.h"
#include "CATDynIntersectionCrvBody.h"
#include "CATDynShell.h"
#include "CATDynMassProperties1DOnEdge.h"
#include "CATDynMassProperties2D.h"
#include "CATDynMassProperties3D.h"

//=============================================================================
extern "C"
{
ExportedByBONEWOPE CATDynBoolean            * CATCreateDynBooleanCNEXT             (CATGeoFactory*             iContainer,
                                                                                    CATTopData*                iData,
                                                                                    CATDynBooleanType          iOperation,
                                                                                    CATBody*                   iPart,
                                                                                    CATBody*                   iTool);

ExportedByBONEWOPE CATDynBoolean            * CATDynCreateBooleanCNEXT             (CATGeoFactory*             iContainer,
                                                                                    CATDynBooleanType          iOperation,
                                                                                    CATBody*                   iPart,
                                                                                    CATBody*                   iTool,
                                                                                    CATCGMJournalList*         journal = NULL);

ExportedByBONEWOPE CATDynSplit              * CATCreateDynSplitCNEXT               (CATGeoFactory*             Container,
                                                                                    CATTopData*                iData,
                                                                                    CATBody*                   iBody,
                                                                                    CATDynSplitType            SplitType);

ExportedByBONEWOPE CATDynSplit              * CATDynCreateSplitCNEXT               (CATGeoFactory*             Container,
                                                                                    CATBody*                   iBody,
                                                                                    CATDynSplitType            SplitType,
                                                                                    CATCGMJournalList*         iJournal);

ExportedByBONEWOPE CATDynBooleanTrim        * CATCreateDynBooleanTrimCNEXT         (CATGeoFactory*             iContainer,
                                                                                    CATTopData*                iData,
                                                                                    CATBody*                   iPart,
                                                                                    CATBody*                   iTool);

ExportedByBONEWOPE CATDynPrism              * CATDynCreatePrismCNEXT               (CATGeoFactory*             Container,
                                                                                    CATMathDirection*          iDirection,
                                                                                    const CATLISTP(CATCurve)&  iProfile,
                                                                                    CATPlane*                  iSupport, 
                                                                                    CATCGMJournalList*         iJournal = NULL);

ExportedByBONEWOPE CATDynPrism              * CATCreateDynPrismCNEXT               (CATGeoFactory*             Container,
                                                                                    CATTopData *               iData,
                                                                                    CATMathDirection*          iDirection,
                                                                                    const CATLISTP(CATCurve)&  iProfile,
                                                                                    CATPlane*                  iSupport);

ExportedByBONEWOPE CATDynRevol              * CATDynCreateRevolCNEXT               (CATGeoFactory            * iFactory,
                                                                                    const CATLISTP(CATCurve) & iProfile,
                                                                                    CATMathAxis              & iAxis,
                                                                                    CATAngle                   iStartAngle,
                                                                                    CATAngle                   iEndAngle,
                                                                                    CATPlane                 * iSupport,
                                                                                    CATCGMJournalList        * iJournal);

ExportedByBONEWOPE CATDynTransformation     * CATDynCreateTransformationCNEXT      (CATGeoFactory*             iContainer,
                                                                                    CATBody*                   iBody,
                                                                                    CATCGMJournalList*         iJournal = NULL) ;


ExportedByBONEWOPE CATDynThickness          * CATDynCreateThicknessCNEXT           (CATGeoFactory            * iContainer,
                                                                                    CATBody                  * iPart,
                                                                                    CATCGMJournalList        * journal = NULL);

//cbk-ri0296310A-debut
ExportedByBONEWOPE CATDynIntersectionCrvBody* CATCreateDynIntersectionCrvBodyCNEXT (CATGeoFactory*             iContainer,
                                                                                    CATTopData*                iData,
                                                                                    CATCurve*                  iCurve,
                                                                                    CATBody*                   iPart);
////////////////cbk-ri0296310A-fin
ExportedByBONEWOPE CATDynIntersectionCrvBody* CATDynCreateIntersectionCrvBodyCNEXT (CATGeoFactory*             iContainer,
                                                                                    CATCurve*                  iCurve,
                                                                                    CATBody*                   iPart,
                                                                                    CATCGMJournalList*         iJournal = NULL);

ExportedByBONEWOPE CATDynShellBody          * CATDynCreateShellBodyCNEXT           (CATGeoFactory*             iContainer,
                                                                                    const CATLISTP(CATFace)&   iFaces,
                                                                                    CATCGMJournalList*         iJournal);

#ifdef CATDynShellBody_WithTopData
ExportedByBONEWOPE CATDynShellBody          * CATCreateDynShellBodyCNEXT           (CATGeoFactory*             iContainer,
                                                                                    CATTopData*                iTopData  ,
                                                                                    const CATLISTP(CATFace)&   iFaces    );
#endif

//cbk-ri0296310A-debut
ExportedByBONEWOPE CATDynIntersectionSurBody* CATCreateDynIntersectionSurBodyCNEXT (CATGeoFactory*             iContainer,
                                                                                    CATTopData*                iData,
                                                                                    CATSurface*                iSurface,
                                                                                    CATBody*                   iPart);
////////////////cbk-ri0296310A-fin

ExportedByBONEWOPE CATDynIntersectionSurBody* CATDynCreateIntersectionSurBodyCNEXT (CATGeoFactory*     iContainer,
                                                                                    CATSurface*        iSurface,
                                                                                    CATBody*           iPart,
                                                                                    CATCGMJournalList* iJournal = NULL);

ExportedByBONEWOPE CATDynShell              * CATDynCreateShellCNEXT               (
                                                                                    CATGeoFactory     * iContainer,
                                                                                    CATBody           * iPart,
                                                                                    CATLength           iInternal,
                                                                                    CATLength           iExternal,
                                                                                    CATCGMJournalList * journal = NULL);

ExportedByBONEWOPE CATDynMassProperties2D*       CreateMassProperties2DCNEXT        (const CATLISTP(CATFace)&);

ExportedByBONEWOPE CATDynMassProperties2D*       CreateMassProperties2D             (CATTopData    * iTopData,
                                                                                     const CATLISTP(CATFace)&);

ExportedByBONEWOPE CATDynMassProperties3D*       CreateMassProperties3DCNEXT        (const CATBody*);

ExportedByBONEWOPE CATDynMassProperties3D*       CreateMassProperties3DCNEXTTData   (CATTopData * iTopData, const CATBody*);



CATDynIntersectionCrvBody*
CATDynCreateIntersectionCrvBodyCGM(CATGeoFactory * iFactory,
                                   CATTopData    * iData,
                                   CATCurve      * iCurve,
                                   CATBody       * iBody);

CATDynIntersectionSurBody*
CATDynCreateIntersectionSurBodyCGM(CATGeoFactory * iFactory,
                                   CATTopData    * iData,
                                   CATSurface    * iSurface,
                                   CATBody       * iBody);


};


#endif
