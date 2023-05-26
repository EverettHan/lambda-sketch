/* -*-C++-*- */

#ifndef CATlsoTransformFaceInputFaceList_H
#define CATlsoTransformFaceInputFaceList_H

#include "AdvTrimOpe.h"
#include "CATlsoTransformFaceInputCellList.h"
#include "CATMathTransformation.h"
#include "CATMathInline.h"
// Includes des listes d'objets
#include "ListPOfCATFace.h"
#include "ListPOfCATPersistentFaces.h"
#include "ListPOfListPOfCATFace.h"
#include "CATTopDefine.h"
#include "ListPOfCATPersistentBodies.h"
#include "CATTopFlexibleBRep.h"
#include "CATGMLiveShapeRevolPrismMode.h"
#include "CATlsoRevolPrismData.h"
#include "ListPOfCATEdge.h"

class CATBody;
class CATFace;
class CATlsoContext;
class CATlsoTransformFaceContext;
class CATSurface;
class CATlsoChainMaster;
class CATSurLimits;
class CATDeclarativeManifold;
class CATCGMJournalList;
class CATLiveBody;
class CATlsoDynMetaData;
class CATSoftwareConfiguration;


#define InputFaceListType                       CATlsoTransformFaceInputFaceList::InputType
#define InputFacesListSkinResultType            CATlsoTransformFaceInputFaceList::SKINRESULT
#define InputFacesListTransformationType        CATlsoTransformFaceInputFaceList::TRANSFORMATION
#define InputFacesListCATSurfaceType            CATlsoTransformFaceInputFaceList::CATSURFACE
#define InputFacesListCATSurfaceWithTranfoType  CATlsoTransformFaceInputFaceList::CATSURFACEWITHTRANSFORMATION // non encore utilisé

class ExportedByAdvTrimOpe CATlsoTransformFaceInputFaceList : public CATlsoTransformFaceInputCellList
{

public:

  // Constructor for CATlsoTransformFaceContext
  CATlsoTransformFaceInputFaceList(const ListPOfCATFace        & iInputFacesList,
                                   CATBody                     & iResultSkinBody,
                                   ListPOfCATFace              * iResultSkinFaceList,
                                   CATCGMJournalList           * iJournalFromInputBodyToSkinBody,
                                   CATlsoTransformFaceContext  * iContext,
                                   CATBoolean                    iOwnTheInfra);

  CATlsoTransformFaceInputFaceList(const ListPOfCATFace        & iInputFacesList,
                                   CATPersistentBody           & iResultSkinPBody,
                                   ListPOfCATFace              * iResultSkinFaceList,
                                   CATCGMJournalList           * iJournalFromInputBodyToSkinBody,
                                   CATlsoTransformFaceContext  * iContext,
                                   CATBoolean                    iOwnTheInfra);

  CATlsoTransformFaceInputFaceList(const ListPOfCATFace         & iInputFacesList,
                                   const CATMathTransformation  & iMathTransformation,
                                   CATlsoTransformFaceContext   * iContext);

  CATlsoTransformFaceInputFaceList(const ListPOfCATFace         & iInputFacesList,
                                   CATSurface                   & iSurface,
                                   CATSurLimits                 * iWorkingDomain,
                                   CATOrientation                 iOrientation,
                                   CATlsoTransformFaceContext   * iContext);

  // Constructor for CATlsoVariationalTransformCellContext
  CATlsoTransformFaceInputFaceList(const ListPOfCATFace         & iInputFacesList,
                                   const CATMathTransformation  & iMathTransformation,
                                   CATlsoPersistentContext      * iContext,
                                   CATlsoChainMaster            * iAdmin);

  CATlsoTransformFaceInputFaceList(const ListPOfCATFace   & iInputFacesList,
                                   CATSurface             & iSurface,
                                   CATSurLimits           * iWorkingDomain,
                                   CATOrientation           iOrientation,
                                   CATlsoPersistentContext* iContext,
                                   CATlsoChainMaster      * iAdmin);
 
  CATlsoTransformFaceInputFaceList (const ListPOfCATFace&        iInputFacesList,
                                    CATSurface&                  iSurface,
                                    CATSurLimits*                iWorkingDomain,
                                    CATOrientation               iOrientation,
                                    const CATMathTransformation& iMathTransformation,
                                    CATlsoPersistentContext*     iContext,
                                    CATlsoChainMaster*           iAdmin);

  // ------------------
  // ConfigurationType
  // ------------------
  enum InputType { UNKNOWN=0,
                   SKINRESULT,
                   TRANSFORMATION,
                   CATSURFACE,
                   CATSURFACEWITHTRANSFORMATION,
                   KNOWLEDGE};

  //-------------------------------------------------------------------------------------------------------
  // Surcharge du new/delete
  //-------------------------------------------------------------------------------------------------------
  CATCGMNewClassArrayDeclare;
  
  // Destructeur
  virtual ~CATlsoTransformFaceInputFaceList();

  CATBoolean SetInputToFlexibleBRepOpeFromInputSkin(CATTopFlexibleBRep       & iFlexOpe,
                                                    CATBody                  * iInputBody,
                                                    const CATBoolean           iInvertOrientation);
  void SetInputEdgesToFlexibleBRepOpeFromInputSkin(CATTopFlexibleBRep & iFlexOpe);

  // -----------------
  // Compute Methodes
  // -----------------
  void ComputeTransfoFromCATSurface();
  static void ComputeAllTransfoFromCATSurface(CATlsoTransformFaceContext  & iContext);
  CATBoolean IsSameSurface(CATSurface * iSurface);
  INLINE void SetType(InputFaceListType iType);

  static void ExtendInputFaceListToInvariant(CATlsoTransformFaceContext  & iContext);
  void ComputeNeighborInvariantFaceList();
  void New_ComputeNeighborInvariantFaceList();
  void ComputeDRepNeighborIgnoringRibbons(CATFace * iFace, CATLiveBody * iLiveBody, ListPOfCATFace &oComputedNeighborList);
  CATBoolean CheckIsContextualOfSelection(CATFace * iFace, CATLiveBody* iLiveBody);
  CATBoolean New_CheckIsContextualOfSelection(CATFace * iFace, CATLiveBody* iLiveBody, const ListPOfCATFace &iInputAndNeighborFaceList, ListPOfCATFace &oNewCandidateNeighborList);
  CATBoolean CheckIsPlanInnerSelection(CATFace * iFace, CATLiveBody * iLiveBody, ListPOfCATFace & iOtherCandidateSelectedFaceList, ListPOfCATFace * oAdjancentFaceList=NULL);
  CATBoolean New_CheckIsPlanInnerSelection(CATFace * iPlannarFace, CATLiveBody * iLiveBody, const ListPOfCATFace & iOtherCandidateSelectedFaceList, ListPOfCATFace * oAdjancentFaceList=NULL);                                                                       

  void AddInvariantFacesWithCheckNoCollision();
  CATBoolean CheckTopologicalInclusion(const ListPOfCATFace & iNeighborInvariantFaceList);
  CATBoolean Contains(const ListPOfCATFace & iFaceList);
  CATBoolean AreContainedIn(const ListPOfCATFace & iFaceList);
  void RemoveOtherFaceList(const ListPOfCATFace & iFaceListToKeep, ListPOfCATFace & oRemovedFaceList);

  // -------------
  // Get Methodes
  // -------------
  INLINE InputFaceListType GetType() const;

  INLINE const ListPOfCATFace & GetInputFacesList() const;
  INLINE void         GetInputFacesList(ListPOfCATFace & oInputFaceList) const;
  INLINE void         GetInvariantFaceList(ListPOfCATFace & oInvariantFaceList) const;
  INLINE void         GetExclusiveInvariantFaceList(ListPOfCATFace & oExclInvariantFaceList) const;
  INLINE void         GetInputFacesWithInnerFilletList(ListPOfCATFace & oInputFaceList) const;
  INLINE CATBoolean   GetResultSkinWithJournal() const;
  INLINE void         SetNbConnectedGroupBeforeNeighborInvariantPropagation(int iNbGroup);
  INLINE void         SetResultSkinPersistentBody(CATPersistentBody * iPBody);
  CATBody           * GetResultSkinBody();
  CATPersistentBody * GetResultSkinPersistentBody();
  ListPOfCATFace    * GetResultSkinFaceList() const;
  INLINE void         SetResultSkinFaceList(ListPOfCATFace * iFaceList);
  CATPersistentBody * GetGlobalPersistentBodyForResultSkin() const;
  void                GetSurface(CATSurface *& oSurface,CATSurLimits *& oSurLimits,CATOrientation & oSurfOrientation) const;
  const               CATMathTransformation & GetTransformation() const;
  void                GetInputPersistentFacesList(ListPOfCATPersistentFaces & oInputPersistentFaceList, CATListOfInt *oMandatoryStatus=NULL);
  void                GetInputAndCreatedPersistentFacesList(CATPersistentBody * iPersistentBody, ListPOfCATPersistentFaces & oInputPersistentFaceList, CATListOfInt *oMandatoryStatus=NULL);
  void                GetInputFacesListOnPersistentBodyForFlexiblePlus(CATPersistentBody * iPersistentBody,
                                                                       ListPOfCATFace    & oInputFacesList,
                                                                       CATListOfInt      & oMandatoryStatus,
                                                                       ListPOfCATEdge    & oInvariantNeighborSmoothEdgeList);
 const CATlsoRevolPrismData & GetRevolPrismData() const;

 virtual CATlsoTransformFaceInputFaceList * GetAsInputFaceList() const;

  // --------
  // Dump
  // --------
  void DumpObj(CATCGMOutput& s, short iLongDump=0, short iZtrNoDump=0) const;

  // -----------------
  // Static Methodes
  // ------------------

   // Balayage de tous les objets de la classe
  INLINE static CATlsoTransformFaceInputFaceList * Next(CATlsoChainMaster * iAdmin, 
                                        CATlsoTransformFaceInputFaceList* iCur, short iKey = 0);

  // RecordInputParameters
  static void RecordInputParameters(const ListPOfCATFace        & iInputFacesList,
                                    CATBody                     & iResultSkinBody,
                                    ListPOfCATFace              * iResultSkinFaceList,
                                    CATCGMJournalList           * iJournalFromInputBodyToSkinBody,
                                    CATlsoTransformFaceContext  & iContext,
                                    CATBoolean                    iOwnTheInfra);

  static void RecordInputParameters(const ListPOfCATFace        & iInputFacesList,
                                    CATPersistentBody           & iResultSkiPBody,
                                    ListPOfCATFace              * iResultSkinFaceList,
                                    CATCGMJournalList           * iJournalFromInputBodyToSkinBody,
                                    CATlsoTransformFaceContext  & iContext,
                                    CATBoolean                    iOwnTheInfra);

  // RecordInputParameters
  static void RecordInputParameters(const ListPOfCATFace        & iInputFacesList,
                                    const CATMathTransformation & iMathTransformation,
                                    const CATlsoRevolPrismData  & iRevolPrismData,
                                    CATlsoPersistentContext     & iContext,
                                    CATPersistentBody           * iUpToPersistentBody=NULL,
                                    CATlsoChainMaster           * iAdmin=NULL);

  // RecordInputParameters
  static CATlsoTransformFaceInputFaceList * RecordInputParameters(const ListPOfCATFace        & iInputFacesList,
                                                                  CATSurface                  & iSurface,
                                                                  CATSurLimits                * iWorkingDomain,
                                                                  CATOrientation                iOrientation,
                                                                  CATlsoPersistentContext     & iContext,
                                                                  CATlsoChainMaster           * iAdmin=NULL);

  static CATlsoTransformFaceInputFaceList* RecordInputParameters (const ListPOfCATFace&         iInputFacesList,
                                                                  CATSurface&                   iSurface,
                                                                  CATSurLimits*                 iWorkingDomain,
                                                                  CATOrientation                iOrientation,
                                                                  const CATMathTransformation&  iMathTransformation,
                                                                  const CATlsoRevolPrismData&   iRevolPrismData,
                                                                  CATlsoPersistentContext&      iContext,
                                                                  CATPersistentBody*            iUpToPersistentBody = NULL,
                                                                  CATlsoChainMaster*            iAdmin = NULL);

  static void RecordOriginType(const ListPOfCATFace  & iInputFaceList,
                               CATlsoPersistentContext& iContext,
                               CellOriginType          iOriginType);

  // RecordAdditionalData
  static int RecordAdditionalData(ListPOfCATFace & iInputFacesList, CATlsoTransformFaceContext & iContext, CATlsoDynMetaData & iOptionalData);
  

  // RecordOneInput
  static void RecordOneInput(CATFace                     & iFace,
                             const CATMathTransformation & iMathTransformation,
                             const CATlsoRevolPrismData  & iRevolPrismData,
                             CATBody                     * iInputBody,
                             CATlsoPersistentContext     & iContext,
                             CATlsoChainMaster           * iAdmin,
                             CATlsoDynMetaData           * iAdditionalData=NULL,
                             CATPersistentBody           * iUpToPersistentBody=NULL);

    // RecordOneInput 2
  static CATlsoTransformFaceInputFaceList * RecordOneInput(CATFace                                  & iFace,
                                                            const CATlsoTransformFaceInputFaceList  & iOtherTFInputFaceList, 
                                                            CATlsoPersistentContext                 & iContext,      
                                                            CATlsoChainMaster                       * iAdmin,
                                                            CATlsoDynMetaData                       * iAdditionalData=NULL);

  // GetAllInputFacesList

  static void GetAllInputFacesList(ListPOfCATPersistentFaces   & oInputPersistentFacesList,
                                   CATlsoTransformFaceContext  & iContext
                                   );

  static void GetAllInputFacesList(ListPOfCATFace              & oInputFacesList,
                                   CATlsoTransformFaceContext  & iContext,
                                   CATBoolean                  * oRemoveFeatureNeeded=NULL);

  static void GetListOfInputFacesList(ListPOfListPOfCATFace       & oListOfInputFacesList,
                                      CATlsoChainMaster           * iInputFacesListAdmin);

  static CATBoolean CheckListOfInputFacesListWithReference(ListPOfListPOfCATFace & oRefListOfMoveFaceList,
                                                           CATlsoChainMaster     * iInputFacesListAdmin);

  static void GetAllResultSkinPersistentBody(ListPOfCATPersistentBodies & oLocalInputPersistentBodyList,
                                             CATlsoTransformFaceContext & iContext);

  static CATBoolean OnlySurfaceWithEquivalentTransfo(CATlsoTransformFaceContext & iContext);
  static void CheckOnlySurfaceWithEquivalentTransfo(CATlsoTransformFaceContext & iContext);

  // New
  static CATlsoRevolPrismData GetRevolPrismData(const ListPOfCATPersistentFaces & iInputPersistentFaceList,
                                          CATlsoTransformFaceContext      & iContext);

  // Find TFInputFaceList
  static CATlsoTransformFaceInputFaceList * FindTFInputFaceListFromFace(CATFace                    * iFace,
                                                                        CATlsoTransformFaceContext & iContext);
  // Move Draft project Y2020-W33
  static CATBoolean ContainsOnlyInputDraftFaces(const CATlsoTransformFaceInputFaceList & iTFInputFaceList,
                                                CATLiveBody                            * iLiveBody);
  // SetTransformation
  // DO NOT USED public (debug only) : It's for incremental multin CGMReplay
  void SetTransformation(const CATMathTransformation & iMathTransformation);

  CATBoolean HasFreeBorderFaces() const;

  void GetPersistentBodiesNecessaryForNextRun(ListPOfCATPersistentBodies &oPersistentBodiesNecessaryForNextRun) const;

protected:
  // HasSameList
  CATBoolean HasSameList(const ListPOfCATFace & iInputFacesList) const;

  virtual void GetInputCellList(ListPOfCATCell & oInputCellList) const;

private: 

  // Copy-constructeur et affectation (ne compilera pas)  
  CATlsoTransformFaceInputFaceList (const CATlsoTransformFaceInputFaceList &iOrig);
  CATlsoTransformFaceInputFaceList& operator= (const CATlsoTransformFaceInputFaceList& iRight);

  // Should not be called from external class
  void  SetInputFacesList(const ListPOfCATFace &  iInputFaceList, CATListOfInt *iMandatoryStatus=NULL);

  // -------------------
  // Internal Methodes
  // -------------------

  // CleanAfterRun
  void CleanAfterRun();

  // AddFaceToList
  void AddFaceToList(CATFace & iFace, int  &iMandatoryStatus);
  int AddInnerRibbonsInInputFaceList(CATBoolean *AreInputFaceContextual=NULL);
  CATBoolean IsInnerRibbonsFace(CATDeclarativeManifold & iDeclMan, CATFace & iFace);
  CATBoolean AreInputFacesContextualTo(CATDeclarativeManifold & iDeclMan, CATFace & iFace) const;

  int ComputeNbBorderEdges(ListPOfCATFace &iListOfFaceList);
  void FilterFaceWithNbBorderEdges(ListPOfCATFace & ioCandidatNeighborFaceList,
                                   ListPOfCATFace & iContextualNeighborFaceList,
                                   ListPOfCATFace & iInputFace,
                                   ListPOfCATFace * iInnterInvariantFacesList=NULL);

  void FilterContextualInvariantFaceList(CATLiveBody * iLiveBody, const ListPOfCATFace &iInputAndInvariantFaceList, ListPOfCATFace &ioContextualNeighborFaceList);

  CATBoolean ThereAreSomeClosureEdge(const ListPOfCATFace & iNeighborInvariantFaceList);

  /*
  // SetResultSkinBody
  void SetResultSkinBody(CATBody & iResultSkinBody,
                         CATCGMJournalList * iJournalFromInputBodyToSkinBody,
                         CATBoolean iOwnTheInfra);
  */
  void SetGlobalPersistentBodyForResultSkin(CATBody & iGlobalBodyForResultSkin, ListPOfCATFace * iResultSkinFaceList, CATCGMJournalList * iJournalFromInputBodyToGlobalBody, CATBoolean iOwnTheInfra);
  void SetGlobalPersistentBodyForResultSkin(CATPersistentBody & iGlobalPBodyForResultSkin, ListPOfCATFace * iResultSkinFaceList, CATCGMJournalList * iJournalFromInputBodyToGlobalBody, CATBoolean iOwnTheInfra);
  void ComputeResultSkinPersistentBody();

  // SetCATSurface
  void SetCATSurface(CATSurface   & iSurface,
                     CATSurLimits * iSurLimits = NULL,
                     CATOrientation iSurfOrientation = CATOrientationUnknown);

  // ---------------------------------
  // Input Internal Data for Stream
  // ---------------------------------
  ListPOfCATFace           _InputFacesList;
  CATPersistentBody      * _GlobalPersistentBodyForResultSkin;//persistent body sur lequel on trouve la result skin
  ListPOfCATFace         * _ResultSkinFaceList;// liste de face de _GlobalPersistentBodyForResultSkin qui par extract forment _ResultSkinPersistentBody
  CATSurface             * _Surface;
  CATSurLimits           * _SurLimits;
  CATOrientation           _SurfOrientation;

  // ---------------
  // Internal Data
  // ---------------
  ListPOfCATFace           _InputFacesWithInnerFilletList;
  ListPOfCATFace           _NeighborInvariantFaceList;
  ListPOfCATFace           _ExclusiveNeighborInvariantFaceList; // New !
  int                      _NbConnectedGroupBeforeNeighborInvariantPropagation;
  CATBoolean               _ResultSkinWithJournal;
  CATPersistentBody      * _ResultSkinPersistentBody; // persistentbody de la resultskin finale a recoudre
  InputFaceListType        _Type;

  ListPOfCATEdge          _SmoothBorderEdgeList;
  ListPOfCATFace          _SmoothBorderNeighborFaceList;
  CATBody               * _SmoothBorderEdgeBody;
  

  ListPOfCATPersistentFaces    _InputPersistentFacesList;
  // CATlsoTransformFaceContext * _TFContext;
};

//----------------------------------------------------------------------------
// Implementations INLINE
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Next
//----------------------------------------------------------------------------
INLINE CATlsoTransformFaceInputFaceList * CATlsoTransformFaceInputFaceList::Next(CATlsoChainMaster * iAdmin,
                                                CATlsoTransformFaceInputFaceList * iCur, short iKey) {
  return (CATlsoTransformFaceInputFaceList*) CATlsoTransformFaceAlgoElt::Next(iAdmin, iCur, iKey); }


//----------------------------------------------------------------------------
// Type Methodes
//----------------------------------------------------------------------------

INLINE InputFaceListType CATlsoTransformFaceInputFaceList::GetType() const {
  return _Type; }

INLINE void CATlsoTransformFaceInputFaceList::SetType(InputFaceListType iType) {
  _Type = iType; }

//----------------------------------------------------------------------------
// GetInputFacesList
//----------------------------------------------------------------------------
INLINE const ListPOfCATFace & CATlsoTransformFaceInputFaceList::GetInputFacesList() const {
  return _InputFacesList; }

//----------------------------------------------------------------------------
// GetInputFacesList
//----------------------------------------------------------------------------
INLINE void CATlsoTransformFaceInputFaceList::GetInputFacesList(ListPOfCATFace & oInputFaceList) const {
  oInputFaceList.Append(_InputFacesList); }

//----------------------------------------------------------------------------
// GetInvariantFaceList
//----------------------------------------------------------------------------
INLINE void CATlsoTransformFaceInputFaceList::GetInvariantFaceList(ListPOfCATFace & oInvariantFaceList) const {
  oInvariantFaceList.Append(_NeighborInvariantFaceList); }

//----------------------------------------------------------------------------
// GetExclusiveInvariantFaceList
//----------------------------------------------------------------------------
INLINE void CATlsoTransformFaceInputFaceList::GetExclusiveInvariantFaceList(ListPOfCATFace & oExclInvariantFaceList) const {
  oExclInvariantFaceList.Append(_ExclusiveNeighborInvariantFaceList); }

//----------------------------------------------------------------------------
// GetInputFacesList
//----------------------------------------------------------------------------
INLINE void CATlsoTransformFaceInputFaceList::GetInputFacesWithInnerFilletList(ListPOfCATFace & oInputFaceList) const {
  oInputFaceList.Append(_InputFacesWithInnerFilletList); }

//----------------------------------------------------------------------------
// GetResultSkinWithJournal
//----------------------------------------------------------------------------
INLINE CATBoolean CATlsoTransformFaceInputFaceList::GetResultSkinWithJournal() const {
  return _ResultSkinWithJournal; }

INLINE void CATlsoTransformFaceInputFaceList::SetNbConnectedGroupBeforeNeighborInvariantPropagation(int iNbGroup) {
 _NbConnectedGroupBeforeNeighborInvariantPropagation = iNbGroup; }

INLINE void CATlsoTransformFaceInputFaceList::SetResultSkinPersistentBody(CATPersistentBody * iPBody) {
  _ResultSkinPersistentBody = iPBody; }

INLINE void CATlsoTransformFaceInputFaceList::SetResultSkinFaceList(ListPOfCATFace * iFaceList) {
  if(iFaceList)
  {
    _ResultSkinFaceList = new ListPOfCATFace();
    _ResultSkinFaceList->Append(*iFaceList);
  }
}

INLINE const CATlsoRevolPrismData & CATlsoTransformFaceInputFaceList::GetRevolPrismData() const {
  return CATlsoTransformFaceInputCellList::GetRevolPrismData(); }

#endif

