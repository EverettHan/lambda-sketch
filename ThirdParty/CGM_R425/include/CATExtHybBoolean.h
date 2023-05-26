#ifndef CATExtHybBoolean_h_
#define CATExtHybBoolean_h_

//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
#include "CATHybDef.h"
#include "CATExtHybOperatorImp.h"
#include "CATHybBoolean.h"
#include "ListPOfListPOfCATCell.h"

class CATSubdContextForFastRunExt;
class CATCellHashTable;


class ExportedByPBELight CATExtHybBoolean : public CATExtHybOperatorImp
{
   
   friend class CATHybBoolean;
   
   
protected:
   
   //-------------------------------------------------------------------------------------------------------
   // Constructeur 
   //   iOperateur peut etre NULL,  mais ca doit etre reserver au cas tres particuliers sous constructeur
   //   il faut dans ce cas s'empresser de retablir la definition avec la methode SetOperator
   //-------------------------------------------------------------------------------------------------------
   CATExtHybBoolean(CATGeoFactory* iFactory, CATTopData* iData, CATHybBoolean* iOperateur = NULL);
   
public:
   
   // Destructor
   virtual ~CATExtHybBoolean();
   
   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;

   void SetRemoveBody(CATBody* iRemoveBody);
   
   void SetErrorBody(CATBody* iErrorBody);
   
   // treatment with Extrapolation On Support (to use before run)
   void SetExtrapolMode(int yes_or_no=1);
   int  GetExtrapolMode() const;
   
   void SetKeepConfusion(CATBoolean iKeep);
   CATBoolean GetKeepConfusion();

   void SetSewingSelection(CATBoolean iSewingSelection);
  
   // Analyze result cells positionning 
   int  GetNbAmbiguousCells();
   int  GetAmbiguousCells(ListPOfCATCell& oListOfCells);
   int  GetNbConfusionCells();
   int  GetConfusionCells(ListPOfCATCell& oListOfCells);
   
   // Analyze result according Tangent Design
   void  SetWarningOnTangentDesign(int yes_or_no=1);
   int  GetTangentDesignMode() const;
   int  IsResultTangentDesign() const;
   int  GetTangentDesignCells(ListPOfCATCell& oListOfCells) const;
   
   
   /**
   * Specifies the cells to be kept and removed in the operation.
   * @param iCellsToRemove
   * The list of cells to be removed.
   * @param iCellsToKeep
   * The list of cells to be kept.
   */
   void SetSelectedCells (CATLISTP(CATCell) & iCellsToRemove, 
      CATLISTP(CATCell) & iCellsToKeep);
   
   // treatment if the Selected Cells do not belong to inputs bodies
   // the selected area is obtain by LayDown (to use before run)
   // default is 0 : the cells are not LayDown and must belong to input
   void SetSelectedCellsByLayDownMode(int yes_or_no=1);
   int  GetSelectedCellsByLayDownMode() const;
   
   // treatment with Wire Positionning (to use before run)
   void SetWirePositionningMode(int yes_or_no=1);
   int  GetWirePositionningMode() const;

   // Gestion de la simplification des Edge Curves
   void  SetIsECSimplificationAuthorized(short iIsECSimplificationAuthorized);  
   short GetIsECSimplificationAuthorized() const;

   //  Simplification des geometries sous-jacentes des edges de la cicatrice
   void MakeSimplifEcrvs();  
   
   virtual CATBody* GetResult();

   /** @nodoc @nocgmitf */
   int IsKeepRemoveActive() const;
   /** @nodoc @nocgmitf */
   void SetKeepRemoveActive(int iKeepRemoveActive = 0);
   /** @nodoc @nocgmitf */
   void GetSelectedCells(CATLISTP(CATCell) & ioCellsToRemove, CATLISTP(CATCell) & ioCellsToKeep);
   /** @nodoc @nocgmitf */
   void CleanSelectedCells();

   /** @nodoc @nocgmitf INTERNAL USE ONLY */
   void GetCellPacks(ListPOfListPOfCATCell & oAllPacks);

   /** @nodoc @nocgmitf */
   virtual void WriteNonBodyInputs(CATCGMStream & Str);

   /** @nodoc @nocgmitf */
   virtual void ReadNonBodyInputs(CATCGMStream & Str);

protected:

   //========================================================================
   //  Trim de Shell
   //========================================================================
   /**
   * Constructs an operator that trims a CATShell domain by a CATShell  domain.
   * <br>The body to trim and the triming body must only contain 
   * one shell domain and one (shell or wire) domain respectively.
   * <br><b>Orientation</b>: The orientation of the resulting body is the orientation
   * of the body to cut.
   * <br><b>Journal</b>:
   * <ul>
   * <li>The faces that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
   * <li>The faces that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
   * <li>The new edges are written as <tt>CATCGMJournal::Creation</tt>
   * <li>The faces that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
   * </ul>
   * @param iFactory
   * A pointer to the factory of the resulting body.
   * @param iData
   * A pointer to the topological data.
   * @param iBodyToTrim
   * A pointer to the body to cut. It must only contain one shell
   * domain.
   * @param iSideToKeep1
   * Side to keep of the resulting parts of Body to trim.
   * @param iCuttingBody
   * A pointer to the cutting body. It must only contain one (wire or shell)
   * domain
   * @param iSideToKeep2
   * Side to keep of the resulting parts of Body .
   * @param iExtrapolMode
   * The way of extrapolation if the cutting body does not cut right along the body to cut.
   */

   CATBody * CATHybTrimShellInitial(CATGeoFactory           *  iFactory,
                                    CATTopData              *  iData,
                                    CATBody                 *& iBodyToTrim,
                                    CATBody                 *  iTrimmingBody,
                                    CATHybExtrapolationMode    iExtrapolMode,
                                    CATBody                 *  iCuttingBody,
                                    CATTopOpInError         *& iInternalWarning,
                                    int                        iBooleanOperationWillFollow);
   
   void CleanUp();
   void CleanUp_1();
   void CleanUp_2();
   
   void RemoveErrorBodies();

   void RemoveBodies();
   virtual void BodyWillBeDeleted(CATBody* iBody);
   
   virtual int GetBooleanType();
   
   void CheckTangentDesignWire();      

   CATBody* CreateDiagnosisBody(ListPOfCATCell &iWarningCells);
   void FilterCellListByPositionType( CATLocation iLocation, ListPOfCATCell& ioCellList );
   void ComputeWarningAmbiguousCells();
   void ComputeWarningConfusionCells();

   void SetWireClosureDiagnosis(CATWire * DisconnectWire);
   void ComputeWarningTangentDesignCells();

   virtual int CheckCellVsKeepRemove(CATCell* iCell);
   virtual CATCell* GetCellVsKeepRemoveAndLayDown(CATCell* iCell, CATBody* iBodySupport);
   
   void ThrowInvalidKeepRemoveInput(CATCell* iCell);
   void ThrowWithErrorBodies(CATTopOpInError* Error=NULL);
   void ThrowAmbiguousKeepRemoveError(CATCell* iCell_To_Keep_Or_Remove);
   
   // commom methods for Trim/Split Operator
   int  CheckCuttingBodyValidity(CATBody* aCuttingBody);
   int  CheckCuttingVertexValidity(CATBody* aCuttingBody, CATVertex* VertexToCheck); 
   void SmartDuplicateCutting(CATBody* aCuttingBody);
   void SmartDuplicateOperandes(CATBody* BodyOp1, CATBody* BodyOp2=NULL);
   void SmartDuplicateOperande(CATBody* BodyOp);
   
   CATShell* MakeDisconnection(CATBody* ShellBody, CATShell* shell);
   CATWire*  MakeDisconnection(CATBody* WireBody, CATWire* wire);
   CATWire*  MakeDisconnectionWithSigns(CATBody* WireBody, CATWire* wire, int throwifnontoucheddomain=0);
   
   int SeparateDomains(CATShell* shell, short SideToKeep, short KeepConfusion, CATBody* PositionBody, 
      CATLISTP(CATCell)& oSetOfCells, CATListOfInt& oSetOfOris);
   
   int SeparateDomains(CATWire* wire, short SideToKeep, short KeepConfusion, CATBody* PositionBody,  
      CATLISTP(CATCell)& oSetOfCells, CATListOfInt& oSetOfOris);
   
   int SeparateDomainsWithSigns(CATWire* wire, short SideToKeep, short KeepConfusion, CATBody* PositionBody,  
      CATLISTP(CATCell)& oSetOfCells, CATListOfInt& oSetOfOris);
   
   int SeparateDomainsWithDisconnect(CATShell* shell, short computeMode, CATBody* PositionBody, 
      CATLISTP(CATCell)& oSetOfCells, CATListOfInt& oSetOfOris);
   
   int SeparateDomainsWithDisconnect(CATWire* wire, short computeMode, CATBody* PositionBody,  
      CATLISTP(CATCell)& oSetOfCells, CATListOfInt& oSetOfOris);
   
   int SeparateDomainsWithKeepRemove(CATShell* shell, int OperandeNumber,  
      CATLISTP(CATCell)& oSetOfCells, CATListOfInt& oSetOfOris);
   
   int SeparateDomainsWithKeepRemove(CATWire* wire, int OperandeNumber,  
      CATLISTP(CATCell)& oSetOfCells, CATListOfInt& oSetOfOris, CATBoolean iThrowExceptionOnInconsistentPosition = TRUE);
   
   int SelectWithKeepRemoveCriteria(int OperandeNumber,  
      CATLISTP(CATCell)& oSetOfCells, CATListOfInt& oSetOfOris);
   
   void InitializeKeepRemoveAttribute();
   
   void SetKeepAttributeOnPack(int iPackNumber);
   
   void SetRemoveAttributeOnPack(int iPackNumber);
   
   void EliminateRemovePack();
   
   void FindContainingPacks( CATListOfInt& ioPackList, int iOperandeNumber, ListPOfCATCell& iCellImageList, int iDim, CATCellHashTable* iBorderCells[]);
   void FindPacksIncludingCell(CATCell* iCell_To_Keep_Or_Remove, int iOperandeNumber, int NumberOfExtremity, CATLISTP(CATCell) * ExtremityCells[], CATCellHashTable* iBorderCells[],CATListOfInt& oPackList);
   
   void DumpSeparateListsAndKeepRemove();   
   
   void DumpKeepRemoveCells();   
   
   CATCell* GetCellThruLaydown(CATCell* CellToLay, CATBody* BodySupport);   
   
   void ComputeSelectedCellsThruLaydown(CATBody* BodySupport);   
   
   CATBody* ComputeSplitByExtrapol(CATBody* Body1, CATBody* Body2, CATBody* BodyS, int side);
   
   // Store cells and associated data
   void StoreCell(CATCell* CellToAdd, int OriToAdd, int PackNumberToAdd, int OpNumberToAdd, int iKeepRemoveAtt=0);   
   void StoreCell(CATCell* CellToAdd, int SideToAdd, int PackNumberToAdd);   
   
   // Dump SeparateLists contents
   void DumpSeparateLists();   
   
   // Find a Side in SeparateList
   int FindCorrespondingSide(CATCell* CellToFind);
   
   // Find a Pack Number in SeparateList
   int FindCorrespondingPackNumber(CATCell* CellToFind);
   
   void SetCurrentOperandeNumber(int iNum);
   int  GetCurrentOperandeNumber() const;
   
   CATCGMJournalList* GetCurrentOpReport() const;     // Get the topological report on Current Operande

   virtual CATBoolean GetReportInternalEdges() { return FALSE;}; // Only currently possible in Disconnect
   
   void ReportDeletion(CATCGMJournalList* report, CATCell* cell);
   
   CATSmartBodyDuplicator* GetCurrentOpDuplicator() const; // Get the SmartDuplication Op. on Current Operande
   void SetCurrentOpDuplicator(CATSmartBodyDuplicator* DuplicOp); // Set the SmartDuplication Op. on Current Operande

   void JournalDisconnectBoundary(CATCGMJournalList * &iJournalDisconnect,CATCGMJournalList * iJournalDuplicate,CATBody * iBodyToOper);
   
   // Data
   CATBody*                _DuplicatedCuttingBody;   // the CuttingBody after SmartDuplication
   CATBody*                _DisconnectBody;          // the body containing the shell after disconnection
   CATSmartBodyDuplicator* _SmartDuplicatorOp;       // for the operands
   CATSmartBodyDuplicator* _SmartDuplicatorOp1;      // for the operands 1
   CATSmartBodyDuplicator* _SmartDuplicatorOp2;      // for the operands 2
   CATSmartBodyDuplicator* _SmartDuplicatorCut;      // for the body Cutting
   CATCGMJournalList*      _ReportOp1;               // the topological report on Operande 1
   CATCGMJournalList*      _ReportOp2;               // the topological report on Operande 2
   ListPOfCATCell          _ConfusedCells;
   ListPOfCATCell          _TangentDesignCells;
   ListPOfCATCell          _KeepCells;               // Keep Cells
   ListPOfCATCell          _RemoveCells;             // Remove Cells
   ListPOfCATCell          _SeparateCells;           // resulting cells 
   CATListOfInt            _SeparateOris;            // Orientation of Result Cells
   CATListOfInt            _SeparateSides;           // Side of the resulting cells
   CATListOfInt            _SeparatePackNumbers;     // Pack Number of the resulting cells
   CATListOfInt            _SeparateOperandeNumbers; // Operande Number of the resulting cells
   CATListOfInt            _KeepRemoveAttribute;      // Keep Remove Attribute
   // 0 : Initialisation
   // 1 : Keep (thru input)
   // 2 : Remove (thru input)
   // 3 : Auto Keep (no specific order on same operand) 
   // 4 : Auto Remove (Keep input on same operand) 
   ListPOfCATBody          _RemoveBodies;
   ListPOfCATBody          _ErrorBodies;
   short                   _PackNumber;              // Pack Number (to query identical sub-domain !)
   int                     _ExtrapolMode;            // Extrapolation On Support management
   int                     _KeepRemoveMode;          // Result selection by Keep Remove management
   int                     _WirePositionningMode;    // Wire Positionning management
   int                     _SelectedCellsByLayDownMode; 
   int                     _CurrentOperande;         // Operande Number : 1 or 2 
   int                     _TangentDesignMode;       // Tangent Design Warning ? 
   short                   _IsECSimplificationAuthorized; 
   CATBoolean              _KeepConfusion;
   CATBoolean              _SewingSelection;

   void CreateInitialFlattenedFacesTable(int iEstimatedSize);
   void RemoveInitialFlattenedFacesTable();
   void AddToInitialFlattenedFacesTable(CATFace * iFace);
   CATBoolean IsInInitialFlattenedFacesTable(CATFace * iFace);

   int SelectShell(CATShell* InitialShell, short SideToKeep, short KeepConfusion,
                                      CATLISTP(CATCell)& oSetOfCells, CATListOfInt& oSetOfOris, CATLISTP(CATCell)& oUnknownCells, CATListOfInt& oSetOfPacks, CATBoolean iAddDeletionOrders = TRUE);
   void FinalizePositioningOfShell(CATShell* InitialShell, CATBody* PositionBody);

   virtual CATSubdContextForFastRunExt * GetSubdContextIfStatusNotImpossible();

private:

   void ComputeWarningIncompleteSelection(const CATListOfInt & iPacksToSelect, int iSelectedPack);

   CATCGMHashTable *       _InitialFlattenedFaces;
  
};
#endif
