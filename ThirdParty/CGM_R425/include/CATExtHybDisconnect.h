#ifndef CATExtHybDisconnect_h_
#define CATExtHybDisconnect_h_

#include "ExportedByPBELight.h"
#include "CATMapOfPtrToPtr.h"
#include "CATHybDef.h"
#include "CATExtHybBoolean.h"
#include "CATHybDisconnect.h"

class CellHashTableAssocList;

class ExportedByPBELight CATExtHybDisconnect : public CATExtHybBoolean
{

   friend class CATHybDisconnect;


protected:

   //-------------------------------------------------------------------------------------------------------
   // Constructeur
   //   iOperateur peut etre NULL,  mais ca doit etre reserver au cas tres particuliers sous constructeur
   //   il faut dans ce cas s'empresser de retablir la definition avec la methode SetOperator
   //-------------------------------------------------------------------------------------------------------
   CATExtHybDisconnect(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBodyToDisconnect,
                      CATBody* iDisconnecttingBody, CATBody* iCuttingBody, CATHybDisconnect* iOperateur = NULL);

public:

   // Destructor
   virtual ~CATExtHybDisconnect();

   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;

   /**
   * Activates the query mode.
   * <br>To be called before the <tt>Run</tt> method.
   * @param iQueryMode
   * The activation of the query mode.
   * <br><b>Legal values</b>: 1 for rank + location activated (default value), 2 for rank activated, 0 for deactivated.
   * The deactivation gives better performance.
   */
   void SetQueryMode(int iQueryMode=1);
   /**
   * Returns the state of the query mode.
   * @return
   * The activation of the query mode.
   * <br><b>Legal values</b>: 1 for rank + location activated (default value), 2 for rank activated, 0 for deactivated.
   */
   int  GetQueryMode() const;

   /**
   * Returns the location of the created cell.
   * <br>To be called after the <tt>Run</tt> method, if the query mode is activated.
   * @param iCell
   * The pointer to a created cell.
   * @return
   * The location of the cell with regards to the cutting body.
   * <br><b>Legal values</b>: <tt>1</tt> if it is at the left side,
   * <tt>-1</tt> if it is at the right side.
   */
   int GetCorrespondingSide(CATCell* iCell);

   /**
   * Returns the rank of a created cell.
   * <br>To be called after the <tt>Run</tt> method, if the query mode is activated.
   * @param iCell
   * The pointer to a created cell.
   * @return
   * The corresponding rank. It may happen that several cells are generated on the same side of the
   * cutting object. If these cells are not directly connected, they are labelled by this method.
   */
   int GetCorrespondingPackNumber(CATCell* iCell);

   /**
   * Query to the operator (internal use only).
   */
   CATCell* GetCorrespondingCell(CATCell* OriginalCell);

   /**
   * To be called before the <tt>Run</tt> method.
   * Activate the internal edges report (internal use only).
   */
   virtual void ReportInternalEdges();

   virtual CATBody* GetResult();

   /** @nodoc **/
   static CATHybDisconnect *Load(CATCGMStream &Str, const short LevelOfRuntime, const short VersionOfStream);

   /** @nodoc CATIA Live Shape  */
   virtual void ReadInputBodies(ListPOfCATBody &oListOfCopyInputBodies, ListPOfCATBody &oListOfNoCopyInputBodies);
     /** @nodoc CATIA Live Shape  */
   virtual void AddDeclarativeManifoldAgents(CATCellManifoldsManager& iCellManifoldsManager,
                                             ListPOfCATBody &iListOfInputBodies,
                                             ListPOfCATBody &iListOfNoCopyInputBodies,
                                             CATBody * iOutputBody,
                                             CATCGMJournalList* iTopOpJournal);

   /** @nodoc @nocgmitf */
   virtual void GenerateCuttingBody();

   /** @nodoc @nocgmitf */
   virtual void SetTrackDisconnectingCells(CATBoolean iTrackDisconnectingCells);

   /**
   * @nodoc
   * This option is available only for the disconnect shell
   * and should be called before the <tt>Run</tt> method.
   *
   *   @param iResultCleaning
   *     Input flag to activate the disconnect result cleaning.
   *   @param iTolerance
   *     Input tolerance used in the cleaning.
   */
   virtual void SetResultCleaning(CATBoolean iResultCleaning, double iTolerance) = 0;

   /**
   * @nodoc
   * Activate or deactivate  the imprint follow up mode.
   */
   virtual void SetImprintFollowUpMode(CATBoolean iImprintFollowUpMode);

   /**
   * @nodoc
   * Check if the imprint follow up mode is active or not.
   */
   virtual CATBoolean GetImprintFollowUpMode() const;

   /** @nodoc @nocgmitf */
   virtual void GetDisconnectingCells(CATCell * iResultCell, ListPOfCATCell & oDisconnectingCells);

   /** @nodoc @nocgmitf */
   void GetResultCells(CATCell * iDisconnectingCell, ListPOfCATCell & oResultCells);

protected :

   void SetInputsToReportChecker();

   void Select();

   void BodyWillBeDeleted(CATBody* iBody);

   int CheckCellVsKeepRemove(CATCell* iCell);
   int GetBooleanType();

   CATCell* GetCellVsKeepRemoveAndLayDown(CATCell* iCell, CATBody* iBodySupport);

   virtual CATBoolean GetTrackDisconnectingCells();

   virtual CATBoolean GetReportInternalEdges();

   CATCGMJournalList * GetCuttingJournal();
   void SetCuttingJournal(CATCGMJournalList * iCuttingJournal);
   CATCGMJournalList * _CuttingJournal;

   static void DiscoJournalAnalysis(CATLISTP(CATCGMJournal) & iItemList,
                                    CATBody * iResultBody,
                                    CATListPtrCATGeometry & oCellsNotInBody,
                                    CATListPtrCATGeometry * oInternalEdgesInBody = NULL,
                                    CATListPtrCATGeometry * oInternalVerticesInBody = NULL);

   static void CreateTrackers(CATLISTP(CATCGMJournal) & iItemList,
                              CATBody * iDisconnectingBody,
                              CellHashTableAssocList ** oForwardDisconnectingCellsTracker,
                              CellHashTableAssocList ** oBackwardDisconnectingCellsTracker);

   // KY1 (19/11/2010)
   /** @nodoc @nocgmitf */
   void RequireDefinitionOfInputAndOutputObjects();
   void WriteInput(CATCGMStream  & Str);
   void Dump( CATCGMOutput& os );
   virtual void DumpOutput(CATCGMOutput &os);
   CATBody *GetInputCuttingBody() const;

   // Data
   CATBody*                  _BodyToDisconnect;      // the Body operande to Disconnect
   CATBody*                  _DisconnecttingBody;    // the Disconnectting Body operand
   CATBody*                  _CuttingBody;           // the Cutting Body operand
   CATBody*                  _UserCuttingBody;       // Cutting Body supplied by the caller (if any)
   CATBody*                  _LocalTargetBody;       // Local Link To Target Body
   int                       _QueryMode;             // query management :  0 for deactivated
                                                     //                     1 for rank + location activated (default value)
                                                     //                     2 for rank activated only (no location)

   CellHashTableAssocList * _ForwardDisconnectingCellsTracker;
   CellHashTableAssocList * _BackwardDisconnectingCellsTracker;

   CATMapOfPtrToPtr         _MapOfOriDiscCellsToImages;

   CATBoolean               _TrackDisconnectingCells;
   CATBoolean               _CleanResult;
   double                   _ResultCleaningTolerance;
};
#endif
