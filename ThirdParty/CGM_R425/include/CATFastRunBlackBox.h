#ifndef CATFastRunBlackBox_h
#define CATFastRunBlackBox_h
/* -*-C++-*-*/
//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2009
//
//==========================================================================
// Nov.  09 JJ3 Creation                                                 JJ3
// 24/09/19 PKC Passage Config à FGSubdivision
// 03/10/19 NLD Mise au propre
//              - retour à un colonnage maximum admissible et autorisé
//==========================================================================

#include "CATCGMHashTableWithAssoc.h"
//#include "ListPOfCATFace.h"

class CATTopology;
class CATBody;
class CATContextForFastRunBoxSolutionExt;
class CATCGMHashTable;
class CATFace;
class CATEdge;
class CATCGMJournalList;
class CATLoop;
class CATListPtrCATGeometry;
class CATListPtrCATFace;
class CATListPtrCATDomain;
class CATListPtrCATEdge;
class CATTopologiesSetForFastRun;
class CATSoftwareConfiguration;

class CATFastRunBlackBox
{
  public:
                        CATFastRunBlackBox        ();
                       ~CATFastRunBlackBox        ();

    CATCGMHashTable   * GetFoG                    (CATContextForFastRunBoxSolutionExt * pCtxExt           ,
                                                   CATTopology                        * iTopo             ,
                                                   int                                  iLevel            ,
                                                   CATBody                            * curBody           ,
                                                   CATCGMJournalList                  * iNewJournal       ,
                                                   CATSoftwareConfiguration           * ipConfig          );

    CATCGMHashTable   * GetF                      (CATContextForFastRunBoxSolutionExt * pCtxExt           ,
                                                   CATTopology                        * iTopo             );

    CATFace           * CreateFGFace              (CATContextForFastRunBoxSolutionExt * pCtxExt           ,
                                                   CATFace                            * pOldInputFace     ,
                                                   CATFace                            * pOldResultFace    ,
                                                   CATFace                            * pNewInputFace     ,
                                                   CATBody                            * curBody           ,
                                                   CATListPtrCATGeometry               &iResultObjects    );

    CATFace           * CreateFGFace              (CATContextForFastRunBoxSolutionExt * pCtxExt           ,
                                                   CATListPtrCATFace                  * pOldInputFaceList ,
                                                   CATListPtrCATFace                  * pOldResultFaceList,
                                                   CATFace                            * pNewInputFace     ,
                                                   CATBody                            * curBody           ,
                                                   CATListPtrCATGeometry               &iResultObjects    );

    CATCGMJournalList * ChangeFacesNamesInJournal (CATContextForFastRunBoxSolutionExt * pCtxExt           ,
                                                   CATBody                            * ipPartialResult   );

    void                ComputeJournalForFastRun  (CATContextForFastRunBoxSolutionExt * pCtxExt           ,
                                                   CATCGMJournalList                  * curlst            ,
                                                   CATCGMJournalList                  * pTempJournal      ,
                                                   CATBody                            * ipPartialResult   );

    void                SuppressUncessaryOrders   (CATContextForFastRunBoxSolutionExt * pCtxExt           ,
                                                   CATCGMJournalList                  * iPartialJournal   ,
                                                   CATBody                            * iPartialResult    );

    void                CorrectEdgeOrders         (CATContextForFastRunBoxSolutionExt * pCtxExt           ,
                                                   CATCGMJournalList                  * iPartialJournal   ,
                                                   CATBody                            * iPartialResultBody);

  private :
    void                AddGLoopInFace            (CATContextForFastRunBoxSolutionExt * pCtxExt           ,
                                                   CATLoop                            * iLoop             ,
                                                   CATFace                            * pNewResultFace    ,
                                                   CATFace                            * pOldInputFace     ,
                                                   CATFace                            * pOldResultFace    ,
                                                   CATFace                            * pNewInputFace     ,
                                                   CATBody                            * curBody           );

    void                AddFLoopInFace            (CATContextForFastRunBoxSolutionExt * pCtxExt           ,
                                                   CATLoop                            * iLoop             ,
                                                   CATFace                            * pNewResultFace    ,
                                                   CATFace                            * pOldInputFace     ,
                                                   CATFace                            * pOldResultFace    ,
                                                   CATFace                            * pNewInputFace     ,
                                                   CATBody                            * curBody          );

    void                AddFGLoopInFace           (CATContextForFastRunBoxSolutionExt * pCtxExt           ,
                                                   CATLoop                            * iLoop             ,
                                                   CATFace                            * pNewResultFace    ,
                                                   CATFace                            * pOldInputFace     ,
                                                   CATFace                            * pOldResultFace    ,
                                                   CATFace                            * pNewInputFace     ,
                                                   CATBody                            * curBody           );

    CATLoop           * GetResultLoop             (CATContextForFastRunBoxSolutionExt * pCtxExt           ,
                                                   CATLoop                            * iLoop             ,
                                                   CATFace                            * pOldResultFace    );

    CATFace           * FGModification            (CATContextForFastRunBoxSolutionExt * pCtxExt           ,
                                                   CATFace                            * pOldInputFace     ,
                                                   CATFace                            * pOldResultFace    ,
                                                   CATFace                            * pNewInputFace     ,
                                                   CATBody                            * curBody           );
    void                FGSubdivision             (CATContextForFastRunBoxSolutionExt * pCtxExt           ,
                                                   CATListPtrCATGeometry               &iOldInputFaces    ,
                                                   CATListPtrCATGeometry               &iOldResultFaces   ,
                                                   CATListPtrCATGeometry               &iNewInputFaces    ,
                                                   CATListPtrCATGeometry               &oNewResultFaces   ,
                                                   CATBody                            * iBody             ,
                                                   CATSoftwareConfiguration           * ipConfig          ); // PKC 24/09/2019

    CATTopologiesSetForFastRun * GetResultElements(CATContextForFastRunBoxSolutionExt * pCtxExt           ,
                                                   CATTopologiesSetForFastRun         * pCfElements       ,
                                                   CATListPtrCATGeometry              & iOldResultFaces   ,
                                                   CATListPtrCATDomain                & ioInnerLoops      ,
                                                   CATListPtrCATEdge                  & ioCreatedEdges    );

    CATEdge           * CreateFGEdge              (CATContextForFastRunBoxSolutionExt * pCtxExt           ,
                                                   CATEdge                            * virtualOIEdge     ,
                                                   CATEdge                            * virtualOREdge     ,
                                                   CATBody                            * curBody           );

    CATCGMHashTableWithAssoc * _Relation_NIEdge_NREdge;
};

#endif
