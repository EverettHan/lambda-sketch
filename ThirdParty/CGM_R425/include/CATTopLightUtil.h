#ifndef CATTopLightUtil_H
#define CATTopLightUtil_H


// ++++ Includes ++++
#include "TopPersistentLight.h"
#include "ListPOfCATPersistentFaces.h"
#include "ListPOfCATBody.h"
#include "ListPOfCATPersistentBodies.h"
#include "IUnknown.h" // For HRESULT
#include "CATBoolean.h"
#include "ListPOfCATCell.h"
#include "CATTopDefine.h"
#include "CATHybDef.h"
#include "ListPOfCATFace.h"
#include "CATListOfInt.h"
#include "ListPOfCATDomain.h"
#include "ListPOfListPOfCATCell.h"

#include "CATBodyFreezeMode.h"

// ++++ Predeclarations ++++
class CATPersistentCellInfra;
class CATGMBaseInfra;
class CATPersistentBody;
class CATlsoPersistentContext;
class CATCGMJournalList;
class CATMathVector;
class CATFace;
class CATSurface;
class CATSurParam;
class CATMathTransformation;
class CATMathPlane;
class CATBody;
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATCell;
class CATLine;
class CATPGMDRepBehavior;
class CATCellHashTable;
class CATCellHashTableCGM;
class CATHashTableWithIntAssoc;
class CATlsoContext;
class CATTopHealOperator;



//=============================================================================
// CATTopLightUtil
// 
// responsable: LAP
// 
// Classe utilitaire pour l'operateur ModifyFace. Elle ne contient que des methodes
// statiques.
//=============================================================================

class ExportedByTopPersistentLight CATTopLightUtil
{

public:

  //---------------------------------------------------------------------------
  // METHODES STATIC
  //---------------------------------------------------------------------------
  static CATPersistentBody * CreatePersistentBodyByMergingPersistentBodyList(const ListPOfCATPersistentBodies &iPersistentBodyList,
                                                                              CATlsoPersistentContext    &iContext,
                                                                              CATBoolean                  iManageManifold = FALSE,
                                                                              const CATPGMDRepBehavior *  ipDRepBehavior=NULL);


  static void GetBoundedDomains(CATCell   *iCell,  CATBody  * iBody, ListPOfCATDomain &oBnddDomainList, CATListOfInt *oOrientationList=NULL);

  static HRESULT CallPropagationFace(CATBody                *iBody, 
                                     CATlsoContext          &iContext, 
                                     const ListPOfCATFace   &iInputFaceList, 
                                     ListPOfCATFace         &oResultFaces, 
                                     const ListPOfCATCell   *iStoppintCells=NULL);

  static CATBody    * CallHybBoundary(CATBody *iBody, CATlsoContext &iContext);

  static CATPersistentBody * CallSplitShell(CATPersistentBody       * iPersistentBodyToSplit,
                                             CATPersistentBody       * iPersistentSplittingBody,
                                             CATHybSelectionMode       iSelectionMode,
                                             CATlsoPersistentContext & iContext,
                                             CATBoolean                iPersistentFaceCreation=FALSE,
                                             CATHybExtrapolationMode   iExtrapolationMode=NO_EXTRAPOLATION,
                                             double                  * iTolerance=NULL,
                                             CATCGMJournalList       * oReportJournal=NULL);

  static CATBody * CallSplitShell(CATBody                  * iBodyToSplit,
                                  CATBody                  * iSplittingBody,
                                  CATGeoFactory            * iFactory,
                                  CATSoftwareConfiguration * iConfig,
                                  CATHybSelectionMode        iSelectionMode,
                                  CATHybExtrapolationMode    iExtrapolationMode=NO_EXTRAPOLATION,
                                  double                   * iTolerance=NULL,
                                  CATCGMJournalList        * oReportJournal=NULL);

  static CATPersistentBody * CallHybSplit   (CATPersistentBody       * iPersistentBodyToSplit,
                                             CATPersistentBody       * iPersistentSplittingBody,
                                             CATlsoPersistentContext & iContext,
                                             const CATLISTP(CATCell) & iCellsToRemove,
                                             const CATLISTP(CATCell) & iCellsToKeep,                                             
                                             double                  * iTolerance=NULL,
                                             CATCGMJournalList       * oReportJournal=NULL);


  static CATBoolean CallIsIntersecting(CATPersistentBody       * iPersistentBody1,
                                       CATPersistentBody       * iPersistentBody2,
                                       CATlsoPersistentContext & iContext);

  static CATBoolean CallIsIntersecting(CATGeoFactory * iFactory,
                                       CATSoftwareConfiguration * iConfig,
                                       CATBody       * iBody1,
                                       CATBody       * iBody2);

  static CATPersistentBody * CallIntersect (CATPersistentBody       * iPersistentBody1,
                                           CATPersistentBody       * iPersistentBody2,
                                           CATlsoPersistentContext & iContext,
                                           CATCGMJournalList * oReportJournal=0,
                                           CATBoolean iCreateManifolds=FALSE);

	/*Call intersect w. bodies*/
	static CATBody * CallIntersect(CATBody           * iBody1,
																 CATBody           * iBody2,
																 CATlsoContext     * iContext,
																 CATGMBaseInfra    & iBaseInfra,
																 CATCGMJournalList * oReportJournal = 0,
																 CATBoolean          iCreateManifolds = FALSE);

  static CATPersistentBody * CallLayDown  (CATPersistentBody       * iPersistentBodyToLayDown,
                                           CATPersistentBody       * iPersistentBodySupport,
                                           CATlsoPersistentContext & iPersistentContext,
                                           CATCGMJournalList       * oReportJournal=0,
                                           double                  * iTolerance=NULL);

  // TopologicalOpe
  /*static CATPersistentBody * CallSmartProject  (CATPersistentBody       * iPersistentBodyToProject,
                                                CATPersistentBody       * iPersistentBodySupport,
                                                CATlsoPersistentContext & iPersistentContext,
                                                CATMathDirection        * iDirection=0,
                                                CATCGMJournalList       * oReportJournal=0,
                                                double                  * iTolerance=NULL);*/

  static CATPersistentBody * CallHybProject  (CATPersistentBody       * iPersistentBodyToProject,
                                                CATPersistentBody       * iPersistentBodySupport,
                                                CATlsoPersistentContext & iPersistentContext,
                                                CATMathDirection        * iDirection=0,
                                                CATCGMJournalList       * oReportJournal=0,
                                                double                  * iTolerance=NULL);
  
  static CATBody * CallHybProject  (CATBody       * iBodyToProject,
                                    CATBody       * iBodySupport,
                                    CATGeoFactory            * iFactory,
                                    CATSoftwareConfiguration * iConfig,
                                    CATMathDirection        * iDirection=0,
                                    CATCGMJournalList       * oReportJournal=0,
                                    double                  * iTolerance=NULL);

  static CATPersistentBody * CallDisconnect(CATPersistentBody       * iPBodyToDisconnect,
                                            CATPersistentBody       * iDisconnectingPBody,
                                            CATlsoPersistentContext & iPersistentContext,
                                            CATCGMJournalList       * oReportJournal=0,
                                            ListPOfListPOfCATCell   * oDisconnectedCellsGroups=0 /*group of disconneced cells*/,// allocated memory to be freed
                                            short                     iReportInternalEdges = 0);


  /*static CATPersistentBody * CallDisconnect(CATPersistentBody      * iPBodyToDisconnect,
                                            CATPersistentBody      * iDisconnectingPBody,
                                            CATlsoPersistentContext & iPersistentContext,
                                            CATCGMJournalList       * oReportJournal=0,
                                            ListPOfCATCell          * oLeftSideGroup=0);*/

  static CATPersistentBody * CallDisconnect(CATPersistentBody      * iPBodyToDisconnect,
                                            CATPersistentBody      * iDisconnectingPBody,
                                            CATlsoPersistentContext & iPersistentContext,
                                            ListPOfCATCell          * oRightSideGroup=0,
                                            ListPOfCATCell          * oLeftSideGroup=0);


  static CATBody * CallRemoveFacesInShell(CATBody                  * iBody,
                                          ListPOfCATFace           & iFacesToRemove,
                                          CATGeoFactory            * iFactory, 
                                          CATSoftwareConfiguration * iConfig,
                                          CATBoolean                 iUsingOrientationOFF=FALSE);


  static CATPersistentBody * CallRemoveFacesInShell(CATPersistentBody  * iPersistentBody,
                                                     ListPOfCATPersistentFaces & iPersistentFacesToRemove,
                                                     CATlsoPersistentContext   & iContext,
                                                     ListPOfCATFace            * iFacesToRemove=NULL,
                                                     CATBoolean                  iUsingOrientationOFF=FALSE);
  
  static CATPersistentBody * CallExtractCells(CATPersistentBody         * iPersistentBody,
                                              const ListPOfCATCell      & iInputCellList,
                                              CATlsoPersistentContext   & iContext,
                                              CATBoolean                  iComplementaryExtract=FALSE,
                                              const ListPOfCATDomain    * iOrientationPiorityDomains=NULL,
                                              CATCGMJournalList         * oReportJournal=NULL);

  static CATPersistentBody * CallExtractCells(CATPersistentBody         * iPersistentBody,
                                            const CATCellHashTableCGM   & iInputCellHT,
                                            CATlsoPersistentContext     & iContext,
                                            CATBoolean                    iComplementaryExtract=FALSE,
                                            const ListPOfCATDomain      * iOrientationPiorityDomains=NULL,
                                            CATCGMJournalList           * oReportJournal=NULL);


  static CATPersistentBody * CallFastExtractCells(CATPersistentBody     * iPersistentBody,
                                            const CATCellHashTable      & iInputCellHT,
                                            CATlsoPersistentContext     & iContext,
                                            CATBoolean                    iVolumicResult = FALSE,
                                            CATBoolean                    iComplementaryExtract=FALSE,
                                            CATCGMJournalList           * oReportJournal=NULL);

  static CATBody * CallFastAssemble(ListPOfCATBody           & iBodyList,
                                    CATlsoPersistentContext  & iContext);


  static CATBody * CallExtractCells(CATBody                   * iInputBody,
                                    const ListPOfCATCell      & iInputCellList,
                                    const CATlsoContext       & iContext,
                                    CATBoolean                  iComplementaryExtract=FALSE,
                                    const ListPOfCATDomain    * iOrientationPiorityDomains=NULL,
                                    CATCGMJournalList         * oReportJournal=NULL);

  static CATBody * CallExtractCells(CATSoftwareConfiguration  * iConfig,
                                    CATBody                   * iInputBody,
                                    const CATCellHashTableCGM & iInputCellHT,
                                    CATBoolean                  iComplementaryExtract=FALSE,
                                    const ListPOfCATDomain    * iOrientationPiorityDomains=NULL,
                                    CATCGMJournalList         * oReportJournal=NULL);

//-----------------------------------------------------------------------------
// CallTopExtractFace using BasicTopo operator CATTopExtractFace
// Creates new face with new underlying edges
//  @param iConvertCreationToModif
//          if TRUE, the Creation orders of result body 
//          from TopExtractFace operator are changed into Modification orders
//          to keep links with iPersistentBodiesList if the result of this method
//          is temporary.
//-----------------------------------------------------------------------------
  static CATPersistentBody * CallTopExtractFace(CATGeoFactory            * iFactory,
                                                CATSoftwareConfiguration * iConfig,
                                                CATlsoPersistentContext  & iContext,
                                                CATPersistentBody        * iPersistentBody,
                                                CATFace                  * iFace,
                                                CATBoolean                 iConvertCreationToModif=TRUE,
                                                CATBodyFreezeMode          iMode=CATBodyFreezeOff);

  //-----------------------------------------------------------------------------
  // CallTopExtractFace
  // Creates new assembled body with new underlying geometries
  //-----------------------------------------------------------------------------
  static CATPersistentBody * CallTopExtractFace(CATGeoFactory                    * iFactory,
                                                CATSoftwareConfiguration         * iConfig,
                                                CATlsoPersistentContext          & iContext,
                                                const ListPOfCATPersistentBodies & iPersistentBodiesList,
                                                CATLISTP(CATCell)                * iFaces,
                                                CATBoolean                         iConvertCreationToModif=TRUE,
                                                CATBodyFreezeMode                  iMode=CATBodyFreezeOff);

  static CATBody * CallFastCreateBody(CATGeoFactory * iFactory,
                                      CATBody * iBody,
                                      const CATCellHashTableCGM & iInputTable,
                                      CATBoolean iFrozeBody = FALSE,
                                      CATBoolean iVolume = FALSE,
                                      CATBoolean iCOmplementary = FALSE);


  static CATPersistentBody * CallAssembleShell ( CATPersistentBody       * iPersistentBody1,
                                                 CATPersistentBody       * iPersistentBody2,
                                                 CATlsoPersistentContext & iContext,
                                                 CATBoolean                iSetSimplify=FALSE,
                                                 double                  * iTolerance=NULL);

  static CATPersistentBody * CallAssembleShell ( const ListPOfCATPersistentBodies & iInputPersistentBodyList,
                                                 CATlsoPersistentContext    & iContext,
                                                 CATBoolean                   iSetSimplify=FALSE,
                                                 double                     * iTolerance=NULL,
                                                 CATBoolean                   iVolumeCreation=FALSE,
                                                 CATBoolean                   iNonManifoldTolerance=FALSE); // LAP 20201 : Do not used, only for PolymorphingOpe.

  // Note : Call CATHybNewAssemble
  //        Peut n'avoir qu'un body en entrée. Auquel cas, les shells seront simplifiés et un plusieurs volumes créés.
  //        Tres utilile pour fermer des bodies multi-shell non simplifiés.
  static CATBody          * CallAssembleShell  (const ListPOfCATBody    & iInputBodies, 
                                                CATlsoPersistentContext & iContext, 
                                                CATBoolean iSetSimplify     =TRUE, 
                                                CATBoolean iVolumeCreation  =TRUE,
                                                CATCGMJournalList * oReport = NULL);
  static CATBody * CreateShellsFromFaces(CATlsoPersistentContext & iContext, ListPOfCATCell & iCellList, CATListOfInt & iCellOriList, CATBoolean iMakeClosedShellAsIsolatedLump = FALSE);


  static CATPersistentBody * CallTrimShell ( CATPersistentBody      * iPersistentBody1,
                                            CATPersistentBody       * iPersistentBody2,
                                            CATlsoPersistentContext & iContext,
                                            CATBoolean                iSetSimplify=TRUE,
                                            CATHybSelectionMode       iSelectionMode=BOTH_SIDES);


  
  static CATBoolean CallClashFound(CATBody  *iBody1, CATBody  *iBody2, CATlsoPersistentContext & iContext, CATCGMJournalList * oReportJournal=0);

  static CATBoolean CallClashFound(const CATPersistentBody       * iPersistentBody1,
                                   const CATPersistentBody       * iPersistentBody2,
                                   CATlsoPersistentContext & iContext);


  static CATPersistentBody * CallRelimitByVolume(CATPersistentBody * iVolumicBody,
                                                 CATPersistentBody * iSurfacicPBody,
                                                 CATLONG32           iSelectionType,
                                                 CATlsoPersistentContext & iContext,
                                                 CATCGMJournalList *oReportJournal=NULL);

  static CATPersistentBody * CallSew(CATPersistentBody       * iSupportPBody,
                                     CATPersistentBody       * iSurfacicPBody,
                                     CATBoolean                iSimplification,
                                     CATlsoPersistentContext & iContext);


  // ----------------------
  // GeoSimplify
  // ----------------------
  static CATPersistentBody * CallGeoSimplify (CATPersistentBody *iPersistentBody, CATlsoPersistentContext   & iContext);

  // FlexiblePlus
  // ----------------------
  static CATPersistentBody * CallFlexiblePlus (CATPersistentBody         * iPersistentBody, 
                                               ListPOfCATPersistentFaces & iPersistentFaces,
                                               CATMathTransformation     & iMathTransfo,
                                               CATlsoPersistentContext   & iContext,
                                               ListPOfCATFace            * iFaceList=NULL);

  // -----------------------------------------------------------------------
  // Transfo Manager
  // -----------------------------------------------------------------------
  static int CallTransfoManager(const ListPOfCATPersistentBodies & iInputPersistentBodies,
                                const CATMathTransformation      & iTransformation,
                                const CATlsoPersistentContext    & iContext,
                                ListPOfCATPersistentBodies       & oImageResultPersistentBodies,
                                CATBoolean                         iCreationOrder = FALSE,
                                CATCGMJournalList                * oReportJournalList [] = NULL ); // if set, Tab size must be equal to iInputPersistentBodies.Size()

  // -----------------------
  // InvertShellOrientation
  // -----------------------
  static CATPersistentBody * CallInvertShellOrientation(CATPersistentBody        * iPersistentBody,
                                                        CATlsoPersistentContext  & iContext);

  // -----------------------
  // InvertFaceVsShellOrientation
  // -----------------------
  static CATPersistentBody * InvertFaceVsSurfaceOrientation(CATPersistentBody        * iPersistentBody,
                                                          CATlsoPersistentContext  & iContext);



  // -----------------------------------------------------------------
  // Healing Topo
  // -----------------------------------------------------------------
  static CATPersistentBody * CallHealingTopo(CATPersistentBody        * iPersistentBody,
                                              CATlsoPersistentContext & iContext,
                                              CATCGMJournalList       * oReportJournal=NULL,
                                              CATTopHealOperator     ** oGetHealingOpe=NULL);

  // -----------------------------------------------------------------
  // Distance Min
  // -----------------------------------------------------------------
  static double CallDistanceMin(CATBody *iBody1, CATBody *iBody2, const CATlsoContext & iContext);

  static double CallDistanceMin(const CATLISTP(CATCell) &iCellsList1, const CATLISTP(CATCell) &iCellsList2, const CATlsoContext & iContext);

  // -----------
  // AutoCheck
  // -----------
  // Return isValid
  static CATBoolean CheckResultWithAutoCheck(CATPersistentBody       * iResultPersistentBody,
                                             CATPersistentBody       * iInputPersistentBody,
                                             CATlsoPersistentContext & iContext,
                                             ListPOfCATCell          * oInvalidIntersectionCells = NULL,
                                             int                       iMode=0,
                                             ListPOfCATFace          * iResultFaceListFilter = NULL);

  static CATBoolean CheckResultWithAutoCheck(CATPersistentBody       * iResultPersistentBody,
                                             CATPersistentBody       * iInputPersistentBody,
                                             CATCGMJournalList       * iJournal,
                                             CATlsoPersistentContext & iContext,
                                             ListPOfCATCell         *& oInvalidIntersectionCells,
                                             int                       iMode=0,
                                             ListPOfCATFace          * iResultFaceListFilter = NULL);


  static CATBoolean CheckResultWithAutoCheck(CATPersistentBody       * iResultPersistentBody,
                                             CATPersistentBody       * iInputPersistentBody,
                                             CATlsoPersistentContext & iContext,
                                             ListPOfCATCell          & iCellListToCheck,
                                             ListPOfCATCell          * oInvalidIntersectionCells = NULL);


  // Simple Call to BodyCheckerOpe - Carefull, it can rise Exception ! Use Try - Catch
  // *
  // if iPreviousBody is set : check auto-intersection on all body (dominant option)
  // if iJournalReport is set : check auto-intersection only on modified and created cells
  // if oInvalidCells is set : activate exaustive check and return Intersected invalid cells
  // Return TRUE if result body is valid
  static CATBoolean CallBodyChecker(CATGeoFactory *iFactory, 
                                    CATSoftwareConfiguration * iConfig,
                                    CATBody *iBodyResultToCheck, 
                                    CATBody *iPreviousBody=NULL, 
                                    CATCGMJournalList *iJournalReport=NULL, 
                                    ListPOfCATCell *oInvalidCells=NULL); 

  static CATBoolean CallBodyChecker_DebugMode(CATGeoFactory            * iFactory, 
                                              CATSoftwareConfiguration * iConfig,
                                              CATBody                  * iBodyResultToCheck);
  
  static CATPersistentBody * ComputeBoundingWires(CATPersistentBody * iPersistentBody, CATlsoPersistentContext & iContext);

  static CATBody * CreateBodyFromMathPlane(CATGeoFactory *iFactory, CATSoftwareConfiguration *iConfig, CATMathPlane & iMathPlane, CATBody * iLimitingBody, CATBoolean iExtrapol=FALSE);
  static CATBody * CreateBodyFromMathPlane(CATGeoFactory *iFactory, CATSoftwareConfiguration *iConfig, CATMathPlane & iMathPlane);

  static CATBody *CreateBodyFromLine(CATGeoFactory *iFactory, CATSoftwareConfiguration *iConfig, CATLine *iLine);

  //=================================================================================
  // HashTable Management 
  //================================================================================= 

  // return Nb filled Cells.
  static int AddToHashTable  (const ListPOfCATCell &iCellList, CATCellHashTable &ioCellsHashTable); // avoid duplicates

  // returns an HT with coherent orientations for given ordered edge HT
  static void SetOrientationToOrderedEdgeHT(const CATCellHashTable &iOrderedEdgeHT, CATHashTableWithIntAssoc &oEdgeAndOrientationHT);

};

#endif /* CATTopLightUtil_H */
