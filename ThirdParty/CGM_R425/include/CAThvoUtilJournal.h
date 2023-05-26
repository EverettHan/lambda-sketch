/* -*-C++-*- */

#ifndef CAThvoUtilJournal_H
#define CAThvoUtilJournal_H
/*  
=============================================================================

RESPONSABLE  : L Marini

DESCRIPTION  : Classe sans membre de donnees regroupant des methodes
               publiques d'interet general pour l'offset variable hybride
               (evite d'en faire des fonctions avec une portee globale)
               
=============================================================================
*/


#include "CATCGMJournal.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "CATBasicTopologicalOpe.h"
#include "CATBoolean.h"

class CATCGMJournalList;
class CATCell;
class CATBody;
class CAThvoContext;

//--------------------------------------------------------------------------


class ExportedByCATBasicTopologicalOpe CAThvoUtilJournal
{

public:

  //-----------------------------------------------------------------------------
  // ChangeJournalType1ToType2
  //-----------------------------------------------------------------------------
  static void ChangeJournalType1ToType2(CATCGMJournalList * iJournal, CATCGMJournal::Type iType1, CATCGMJournal::Type iType2);

  //-----------------------------------------------------------------------------
  // SuppressVertexJournalItem
  //-----------------------------------------------------------------------------
  static void SuppressVertexJournalItem(CATCGMJournalList * iJournal, short iOnlyAfter = 0);
  static void SuppressVertexJournalItemFromBeforeObjects(CATCGMJournalList * iJournal);

  //-----------------------------------------------------------------------------
  // SuppressEdgeJournalItem
  //-----------------------------------------------------------------------------
  static void SuppressEdgeJournalItem(CATCGMJournalList * iJournal, short iOnlyAfter = 0);


  //-----------------------------------------------------------------------------
  // SuppressJournalInfo
  //-----------------------------------------------------------------------------
  static void SuppressJournalInfo(CATCGMJournalList * iJournal);

  //-----------------------------------------------------------------------------
  // GetAfterCellsFromJournal
  // CheckMode : 0 -> if the BeforeCell doesn't exit in the Journal, it's return the BeforeCell as AfterCell.
  // CheckMode : 1 -> if the BeforeCell doesn't exit in the Journal, it throws an internalError
  //-----------------------------------------------------------------------------
  static void GetAfterCellsFromJournal(CATCGMJournalList * iJournal,
                                       CATCell * iBeforeCell,
                                       CATLISTP(CATCell) & oAfterCellsList,
                                       short iSameGeometryTypeOnly=1,
                                       short iCheckMode=0);

  //-----------------------------------------------------------------------------
  // GetBeforeCellsFromJournal
  // CheckMode : 0 -> if the BeforeCell doesn't exit in the Journal, it's return the BeforeCell as AfterCell.
  // CheckMode : 1 -> if the BeforeCell doesn't exit in the Journal, it throws an internalError
  //-----------------------------------------------------------------------------
  static void GetBeforeCellsFromJournal(CATCGMJournalList * iJournal,
                                        CATCell * iAfterCell,
                                        CATLISTP(CATCell) & oBeforeCellsList,
                                        short iSameGeometryTypeOnly=1,
                                        short iCheckMode=0);

  //-----------------------------------------------------------------------------
  // SuppresGeometricTypeFromJournalItem
  //-----------------------------------------------------------------------------
  // methode codée mais non utlisée
  // static void SuppressGeometricTypeFromJournalItem(CATCGMJournalList * iJournal,const CATGeometricType iGeometricType)

  static void SuppressJournalItemIfFaceNotInBody(CATCGMJournalList * iJournal, CATBody * iBody);

  //-----------------------------------------------------------------------------
  // SearchReportDeletedFromJournal
  //-----------------------------------------------------------------------------
  static CATBoolean SearchReportDeletedFromJournal(CATCGMJournalList * iJournal,
                                                   CATCell * iCell);

  static void FillListFromJournal(CATCGMJournalList * iJournal, CATLISTP(CATFace) &oBottomFaceList, CATLISTP(CATFace) &oTopFaceList, CATLISTP(CATFace) &oLateralFaceList);

  static void ReplaceFaceListFromJournal(CATCGMJournalList * iJournal, CATBody *iBody, CATLISTP(CATFace) &ioFaceList);

  static void ReplaceCellListFromJournal(CATCGMJournalList * iJournal, CATBody *iBody, CATLISTP(CATCell) &iInputCellList, CATLISTP(CATCell) &oOutputCellList);
                                                   
  static void PutInfoOnJournal(CATCGMJournalList *&ioJournal, CATBody *iBody, CATLISTP(CATFace) &iBottomFaceList, CATLISTP(CATFace) &iLateralFaceList);

  static void VisualDebugForJournal(CATCGMJournalList * iJournal);

  static void GetCreatedEdgeListFromJournal(CATCGMJournalList * iJournal, CATLISTP(CATEdge) &oCreatedEdgeList);

  static void GetDeletedEdgeListFromJournal(CATCGMJournalList * iJournal, CATLISTP(CATEdge) &oDeletedEdgeList);

};


#endif
