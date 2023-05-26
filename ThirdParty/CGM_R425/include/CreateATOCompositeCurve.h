// COPYRIGHT DASSAULT SYSTEMES 1990
//=============================================================================
//
// CreateATOCompositeCurve :
// Declaration of global functions used to create an instance of the CompositeCurve operator
//
// See also included CATAdvancedCompositeCurveCreator class for easy composite curve creation
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// 14/01/99 CPL Creation
//    02/99 TPG Modification
//    03/99 ALM Modification
// 10/01/00 NLD Autorisation eventuelle de wires non connexes
// 14/11/00 NLD CATTopData
// 11/1/1   NLD Autorisation eventuelle de wires non connexes dans le
//              cas avec support
// 21 03 02 NLD Argument iIgnoreOutsideEdgeParts pour les createurs avec body support
//              Suppression des constructeurs sans TopData
// 17 05 02 NLD Introduction du mode hybride, et de l'argument iHybrid3D2DMode
//              aux createurs avec support
// 02 06 05 NLD Ajout iTopOperator en argument optionnel pour warnings
// 23 10 08 JSX Ajout de l'argument WarningNotOnShellBoundary afin de detecter aussi les edges internes "smooth". 
// 03 11 09 NLD Deplacement de PrivateInterfaces en ProtectedInterfaces pour SolidWorks
//              (avait-il ete un jour deja en ProtectedInterfaces? En fait on a CATFrFConvertWireToCCV,
//              qui est en protected, et qui grosso modo suffit, signature avec wire et support)
// 10 11 09 NLD Export de la creation de composite curve
//              Classe CATAdvancedCompositeCurveCreator
//              Ajout CreateATOCompositeCurve_UnSpecifiedIndex
// 09 06 10 NLD Migration de CATAdvancedCompositeCurveCreator sur CATTopOperator
//              pour infrastructure CGMReplay
//              GetResult() est renommée GetCompositeCurve()
//              Separation Run()/RunOperator()
//              Ajout de Dump(), GetOperatorId() et GetDefaultOperatorId(), IsRecordable,
//              RequireDefinitionOfInputAndOutputObjects()
//              Ajout GetBodyWireBack(), _BodyResultBack, DumpOutput()
// 16 07 10 NLD Ajout ValidateTopOutput()
// 17/09/10 NLD Migration sur CATCGMOperatorDebugDeclareRun() pour instrumentation perfos
// 22/09/10 NLD Ajout _IsUnderReplay et SetUnderReplay() dans CATAdvancedCompositeCurveCreator()
// 23/09/10 NLD Ajout necessaire du GetResult() avec journal, pouvant etre appelé par le AfterRun topologique,
//              afin d'eviter les sorties en erreur de l'implementation par defaut
// 16/03/17 NLD Smart indent
//=============================================================================

#ifndef CreateATOCompositeCurve_H
#define CreateATOCompositeCurve_H

//
#include <AdvTopoUtil.h>
#include <CATTopData.h>
#include <CATMathDef.h>
#include <CATTopDef.h>
#include <CATCollec.h>
#include <CATTopOperator.h>
#include <CATCGMOperatorDebug.h>
//
class CATGeoFactory;
//class CATCurve;
//class CATCrvLimits;
class CATFrFCompositeCurve;
class CATBody;
class CATFace;
class CATEdge;
class CATTopData;
class CATTopOperator;
//class CATEdgeCurve;
class CATTopCheckJournal;

// Attention: valeur a ne pas changer (utilisee aussi par CreateATOListOfEdges())
#define CreateATOCompositeCurve_UnSpecifiedIndex -1
//---------------------------------------------------------------------------------------------------------------------------------------
class ExportedByAdvTopoUtil CATAdvancedCompositeCurveCreator : public CATTopOperator
{
 public:

             CATAdvancedCompositeCurveCreator(CATGeoFactory * iFactory,
                                              CATTopData    * iTopData,
                                        const CATBody       * iWire   ) ;
            ~CATAdvancedCompositeCurveCreator();

   // Limits management for creation from sub wire
   // (iStartIndex and iEndIndex starting from 0)
   // not compatible with Support management
   void      SetLimits                   (      CATLONG32       iStartIndex ,
                                                CATLONG32       iEndIndex   );

   // Support management
   // ------------------
   void      SetSupport                  (const CATBody       * iBodySupport);
   
   // Specific support management options
   // -----------------------------------
   //
   // Hybrid3D2DMode allows creation of composite curve with combines 3D 2D management when
   // wire is composed of PCurves or MergedCurves containing PCurves linked to support
   void      SetHybrid3D2DMode           (      CATBoolean      iHybrid3D2DMode);
   // Allows edge parts to be outside the support (may be necessary for a cleaned wire)
   void      SetIgnoreOutsideEdgeParts   (      CATBoolean      iIgnoreOutsideEdgeParts);
   // Generates a warning, if warning mode active on current topological operator,
   // if some edges of the wire are not on the shell boundary
   void      SetWarningNotOnShellBoundary(      CATBoolean      iWarningNotOnShellBoundary);
   // Allows multidomain management on the input wire
   void      SetNonConnexWireSupport     (      CATBoolean      iNonConnexWireSupport);

   // Define current topological operator for warning management
   void      SetTopOperator              (      CATTopOperator* iTopOperator);

   //@nodoc @nocgmitf (internal)
   void      PrivateForceRunNumber       (      int             iForcedRunNumber=0);

   //@nodoc @nocgmitf (internal)
   void      ForceComputeEdges           ();

   //@nodoc @nocgmitf (internal)
   CATEdge** PrivateGetEdges             ();
   //@nodoc @nocgmitf (internal)
 //CATFace** PrivateGetFaces             ();
   //
   //@nodoc @nocgmitf (internal)
   CATCGMOperatorDebugDeclareRun(CATAdvancedCompositeCurveCreator,CATTopOperator);

   int       RunOperator();

   CATFrFCompositeCurve* GetCompositeCurve();

   //@nodoc @nocgmitf (internal)
   void                  Dump(CATCGMOutput &os);
   //@nodoc @nocgmitf (internal)
   void                  DumpOutput(CATCGMOutput &os);

// N.B je ne fais pas dependre GetOperatorId() de la derivation de CATTopOperator
   //@nodoc @nocgmitf (internal)
   const  CATString *GetOperatorId();
   //@nodoc @nocgmitf (internal)
   static const CATString *GetDefaultOperatorId();

   //@nodoc @nocgmitf (internal)
   CATBody          * GetResult(); // Bidon! le resultat est la composite curve
   //@nodoc @nocgmitf (internal)
   CATBody          * GetResult(CATCGMJournalList* iJournal); // Bidon! le resultat est la composite curve
   //@nodoc @nocgmitf (internal)
   CATExtCGMReplay  * IsRecordable(short &LevelOfRuntime, short &VersionOfStream);
   //@nodoc @nocgmitf (internal)
   void               WriteInput(CATCGMStream &ioStream);
   //@nodoc @nocgmitf (internal)
   void               RequireDefinitionOfInputAndOutputObjects();
   //@nodoc @nocgmitf (internal)
   CATBoolean         ValidateTopOutput(CATTopCheckJournal* iEquivalent, CATCGMOutput& os);
   //@nodoc @nocgmitf (internal)
   void               SetUnderReplay(int iUnderReplay);


 private:

   // Private methods
   // ---------------
   // Nettoyage
   void               Clear();
   // Rend le body retour issu de la composite curve
   CATBody          * GetBodyWireBack();


 private:
   static CATString  _OperatorId;// identificateur de la classe generale
   // Input
       CATGeoFactory       * _Factory;
       CATTopData            _TopData;
 const CATBody             * _WireBody;
 const CATBody             * _SupportBody;
   // Result
       CATFrFCompositeCurve* _ResultCCV;
       CATBody             * _BodyResultBack;
       int                   _IsUnderReplay;

   // Options
      CATLONG32              _StartIndex;
      CATLONG32              _EndIndex;
      int                    _ForcedIndex;
      int                    _ForcedRunNumber;
      int                    _ForcedComputeEdges;
      CATTopOperator       * _TopOperator;
   
      // Support options
      CATBoolean             _NonConnexWireSupport;
      CATBoolean             _IgnoreOutsideEdgeParts;
      CATBoolean             _Hybrid3D2DMode;
      CATBoolean             _WarningNotOnShellBoundary;

   // Data management
      int                    _DeleteOutputEdges;
      CATEdge             ** _OutputEdges;
    //int                    _DeleteOutputFaces;
    //CATFace             ** _OutputFaces;


} ;

//---------------------------------------------------------------------------------------------------------------------------------------
// iNonConnexWireSupport a mettre a TRUE si on autorise
// les wires non connexes
// dans ce cas, malgre tout, la CCV est vue comme un seul 
// assemblage de courbes, sans notion de domaine; à charge
// pour l'utilisateur de gerer correctement les continuites
//   Nicolas, 10/01/00
//---------------------------------------------------------------------------------------------------------------------------------------
//@nodoc @nocgmitf (internal)
ExportedByAdvTopoUtil
CATFrFCompositeCurve * CreateATOCompositeCurve(CATTopData    * iTopData              ,
                                         const CATBody       * iWire                 ,
                                               CATBoolean      iNonConnexWireSupport = FALSE,
                                               CATLONG32       iStartIndex           = CreateATOCompositeCurve_UnSpecifiedIndex,
                                               CATLONG32       iEndIndex             = CreateATOCompositeCurve_UnSpecifiedIndex,
                                               CATTopOperator* iTopOperator          = NULL);

//---------------------------------------------------------------------------------------------------------------------------------------
//@nodoc @nocgmitf (internal)
ExportedByAdvTopoUtil
CATFrFCompositeCurve * CreateATOCompositeCurve(CATTopData     *  iTopData              ,
                                         const CATBody        *  iWire                 ,
                                               CATEdge       **& oEdges               ,
                                               CATBoolean        iNonConnexWireSupport = FALSE,
                                               CATLONG32         iStartIndex           = CreateATOCompositeCurve_UnSpecifiedIndex,
                                               CATLONG32         iEndIndex             = CreateATOCompositeCurve_UnSpecifiedIndex,
                                               CATTopOperator *  iTopOperator          = NULL);

//---------------------------------------------------------------------------------------------------------------------------------------
// le mode Hybride 3d 2d cree une composite curve a partir d'un wire
// dont les edges contiennent soit des PCurves soit des MergedCurves sur des PCurves;
// les courbes 3D sont utilisees pour les evaluations, et les PCurves sont
// utilisees pour les evaluations de normales
//@nodoc @nocgmitf (internal)
ExportedByAdvTopoUtil
CATFrFCompositeCurve * CreateATOCompositeCurve(CATGeoFactory *   iFactory                   ,
                                               CATTopData    *   iTopData                   ,
                                         const CATBody       *   iBodyWire                  ,
                                         const CATBody       *   iBodySupport               = 0,
                                               CATBoolean        iNonConnexWireSupport      = FALSE,
                                               CATBoolean        iIgnoreOutsideEdgeParts    = FALSE,
                                               CATBoolean        iHybrid3D2DMode            = FALSE,
                                               CATTopOperator*   iTopOperator               = NULL,
                                               CATBoolean        iWarningNotOnShellBoundary = FALSE);

//---------------------------------------------------------------------------------------------------------------------------------------
//@nodoc @nocgmitf (internal)
ExportedByAdvTopoUtil
CATFrFCompositeCurve * CreateATOCompositeCurve(CATGeoFactory *   iFactory,
                                               CATTopData    *   iTopData, 
                                         const CATBody       *   iBodyWire,
                                         const CATBody       *   iBodySupport,
                                               CATEdge       **& oEdges,
                                               CATFace       **& oDummy, // oFaces 
                                               CATBoolean        iNonConnexWireSupport      = FALSE,
                                               CATBoolean        iIgnoreOutsideEdgeParts    = FALSE,
                                               CATBoolean        iHybrid3D2DMode            = FALSE,
                                               CATTopOperator*   iTopOperator               = NULL,
                                               CATBoolean        iWarningNotOnShellBoundary = FALSE) ;

//---------------------------------------------------------------------------------------------------------------------------------------
#endif // CreateATOCompositeCurve
