// COPYRIGHT DASSAULT SYSTEMES  2021

#ifndef CATTopTearEdges_h
#define CATTopTearEdges_h

#include "CATTopOperator.h"
#include "CATIsoParameter.h"
#include "CATCGMJournal.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATFace.h"
#include "ExportedByPBELight.h"
#include "CATSysBoolean.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATCGMJournalList;
class CATSmartBodyDuplicator;

class ExportedByPBELight CATTopTearEdges : public CATTopOperator
{
public:

  struct InputToOutputTearEdgesMap
  {
    CATEdge* pEdgeToTear;
    CATLISTP(CATEdge) OutputEdges;
    CATLISTP(CATFace) ModifiedFaces;
  };

  struct InputToOutputTearVerticesMap
  {
    CATVertex* pVertexToTear;
    CATLISTP(CATVertex) OutputVertices;
  };

  CATTopTearEdges(CATGeoFactory * iFactory,
                  CATTopData    * iTopData,
                  CATBody       * iBodyToTear,
                  CATLISTP(CATEdge) *iEdgesToTear = NULL);
  virtual ~CATTopTearEdges();

  virtual int RunOperator();
  virtual CATBody * GetResult();

  inline void SetUnfoldType(short iUnfoldType)
  {
    _UnfoldType = iUnfoldType;
  }

  inline void SetJournalOptions(const CATBoolean iDifferentiateTearedEdges, const CATCGMJournal::Type iItemType)
  {
    _JournalDifferentiateTearedEdges = iDifferentiateTearedEdges;
    _JournalItemType = iItemType;
  }

  inline void SetLocalJournal(CATCGMJournalList* iLocalJournal)
  {
    _JournalLocal = iLocalJournal;
  }

  inline CATCGMJournalList* GetJournalLocal()
  {
    return _JournalLocal; //after Run and GetResult, _JournalLocal will be available with parent journal if any
  }

  inline void GetInputToOutputTearEdgesMap(CATTopTearEdges::InputToOutputTearEdgesMap *& ioTearEdgesMap)
  {
    ioTearEdgesMap = _InputToOutputTearEdges;
  }

  inline void GetInputToOutputTearVerticesMap(CATTopTearEdges::InputToOutputTearVerticesMap*& ioTearVerticesMap)
  {
    ioTearVerticesMap = _InputToOutputTearVertices;
  }
     
  /** 
  * Updates all data members using iBodyDuplicator
  * Ownership of iBodyDuplicator remains with caller only
  */
  void SetNewBodyToTearAndUpdateAllData(CATSmartBodyDuplicator* iBodyDuplicator); 

  inline void SetBodyToTear(CATBody* iBodyToTear)  //Note: it will not update other data members
  {
    _BodyToTear = iBodyToTear;
  }

  inline void SetInputFaceList(const CATLISTP(CATFace)& inputFaceList) //Note: it will not update other data members
  {
    _inputFaceList = inputFaceList;
  }

  void SetEdgesToTearList(const CATLISTP(CATEdge)& iEdgesToTear); //Note: it will trigger SetEdgesToTear full computation and update all members

  inline void TreatEdgesToTearAsCluster(int iMakeCluster)
  {
    _MakeCluster = iMakeCluster;
  }

  inline void SetOrigRuleDirList(CATListOfInt & iOrigRuleDirList)
  {
    _OrigRuleDirList = iOrigRuleDirList;
  }

  // Find edge to tear candidates
  CATLISTP(CATEdge) FindCandidateEdgesToTear(const CATLONG32 iMust = 0);

  CATBoolean SetEdgesToTear(const CATLISTP(CATEdge)& iEdgesToTear,
                            CATLONG32& oNbAmbiguities,
                            CATLISTP(CATEdge)& oCandidateEdgesToTear,
                            CATLISTP(CATEdge)& oInvalidInputEdges,
                            CATLISTP(CATEdge)* ioMandatoryCandidates,
                            CATLISTP(CATEdge)* ioOptionalCandidates);

  inline CATLISTP(CATEdge)  GetEdgesToTearList() { return _EdgesToTearList; }
  inline CATLISTP(CATEdge)  GetEdgesMustToTear() { return _edgesMustToTear; }
  inline CATLISTP(CATEdge)  GetEdgesCanTear() { return _edgesCanTear; }
  inline CATLONG32  GetNbCommonEdges() { return _NbCommonEdges; }
  inline CATLISTP(CATCell)  GetCommonEdgesCluster() { return _CommonEdgesCluster; }
  inline int  GetCorrectionForNbAmbiguities() { return _CorrectionForNbAmbiguities; }
  inline CATLISTP(CATFace)  GetFacesInAsslyOrder() { return _FacesInAsslyOrder; }
  inline CATLISTP(CATFace)  GetBaseFacesForAssly() { return _BaseFacesForAssly; }
  inline CATLISTP(CATCell)  GetCommEdgesForAssly() { return _CommEdgesForAssly; }

private:

  CATBoolean SetEdgesToTearOld(const CATLISTP(CATEdge)& iEdgesToTear,
                               CATLONG32& oNbAmbiguities,
                               CATLISTP(CATEdge)& oCandidateEdgesToTear,
                               CATLISTP(CATEdge)& oInvalidInputEdges);
  CATBoolean CheckEdgeLinearity(CATCell* iEdge, CATFace* iFace, const CATIsoParameter iRuleDir);
  void ClusterTheEdgesIfPossible(const CATLISTP(CATCell)& commonEdges);
  CATBoolean AreEdgesToTear(CATLISTP(CATEdge)& iEdgeList,     
                            CATBoolean iUpdateAsslyOrder = 0);
  void ClubClusterEdges(CATLISTP(CATEdge)& iEdges);
  void FindSharpCorners(CATLISTP(CATCell)& oSharpCorners);
  void RegroupEdgesToTear(const CATLISTP(CATEdge)& iCandidateEdges,
                          CATLISTP(CATEdge)* ioMandatoryCandidates,
                          CATLISTP(CATEdge)* ioOptionalCandidates);

  template <class CATLISTP, class T>
  void UpdateDataWithBodyDuplicator(CATSmartBodyDuplicator* iBodyDuplicator, CATLISTP & ioListToUpdate);

  void UpdateTearEdgeAmbiguityForHoleCases(CATLONG32& ioNbAmbiguities);
  CATBoolean AreEdgesCollinear(CATEdge* piEd1, CATEdge* piEd2);

  CATGeoFactory*                  _Factory;
  CATBody*                        _BodyToTear;
  CATCGMJournal::Type             _JournalItemType;
  CATLISTP(CATEdge)               _EdgesToTearList;
  CATCGMJournalList*              _JournalLocal;
  CATBoolean                      _JournalDifferentiateTearedEdges;
  InputToOutputTearEdgesMap*      _InputToOutputTearEdges;
  InputToOutputTearVerticesMap *  _InputToOutputTearVertices;
  short                           _UnfoldType; //1=RuledUnfold, 2=FrfshellUnfold

  CATLISTP(CATEdge)               _edgesMustToTear;
  CATLISTP(CATEdge)               _edgesCanTear; //initial edges to tear, less must to tear
  //selected face list
  CATLISTP(CATFace)               _inputFaceList;
  //list of Rule Dir'n of faces in _inputFaceList order
  CATListOfInt                    _OrigRuleDirList;
  //total number of common edges
  CATLONG32                       _NbCommonEdges; 
  CATLISTP(CATCell)               _CommonEdgesCluster; 
  int                             _CorrectionForNbAmbiguities;

  CATLISTP(CATFace)               _FacesInAsslyOrder;
  //faces as reference face for each above, to calculate transformation
  CATLISTP(CATFace)               _BaseFacesForAssly; //useful only for Ruled Unfold
  //common edges between above faces
  CATLISTP(CATCell)               _CommEdgesForAssly; //useful only for Ruled Unfold

  short                           _CurLevel;
  int                             _MakeCluster;
  CATLISTP(CATEdge)               _InnerEdgesInFaceToTear;
  CATLISTP(CATFace)               _FacesToTearWithInnerEdges;
};

#endif

