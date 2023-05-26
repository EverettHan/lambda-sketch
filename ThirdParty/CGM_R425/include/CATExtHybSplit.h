#ifndef CATExtHybSplit_h_
#define CATExtHybSplit_h_

#include "ExportedByPBELight.h"

#include "CATHybDef.h"
#include "CATExtHybBoolean.h"
#include "CATHybSplit.h"


class ExportedByPBELight CATExtHybSplit : public CATExtHybBoolean
{

   friend class CATHybSplit;


protected:

   //-------------------------------------------------------------------------------------------------------
   // Constructeur
   //   iOperateur peut etre NULL,  mais ca doit etre reserver au cas tres particuliers sous constructeur
   //   il faut dans ce cas s'empresser de retablir la definition avec la methode SetOperator
   //-------------------------------------------------------------------------------------------------------
   CATExtHybSplit(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBodyToSplit, CATBody* iSplittingBody,
                  CATBody* iCuttingBody, CATBody* iBodySupport, short iSideToKeep, CATHybSplit* iOperateur = NULL);

public:

   // Destructor
   virtual ~CATExtHybSplit();

   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;

   // desactivation of Error on SplitClosedWireWithSingleVertex (to use before run)
   // default value is : 1 --> Error is throw in case of Split a ClosedWire With Single Vertex
   void SetThrowErrorForClosedWireWithSingleVertex(int yes_or_no=1);
   int  GetErrorForClosedWireWithSingleVertexMode() const;

   // treatment with Simplification of the Result (to use before run)
   void SetSimplifyMode(int yes_or_no=1);
   int  GetSimplifyMode() const;

   // LyingOn links from CuttingBody cells onto SplittingBody cells are not deleted if parameter value is 1
   void SetLyingOnLinksKept(int iLyingOnMode = 1);
   int  AreLyingOnLinksKept();

   CATBody * GetCuttingBodyToSimplify();
   void      SetCuttingBodyToSimplify(CATBody * iCuttingBody);

//#ifdef CATIACGMV5R18
     //rlad
     /**
     * Sets or unsets the ‘Keep elements in half space’ mode.
     *   @param iMode
     *      Mode on (TRUE) or off (FALSE)
     */
     void  SetKeepHalfSpaceMode(CATBoolean iMode=0);

     /**
     * Queries whether ‘Keep elements in half space’ mode is activated or not.
     *   @param oMode
     *      Mode on (TRUE) or off (FALSE)
     */
     void GetKeepHalfSpaceMode(CATBoolean & oMode);

     //rlaf
//#endif

   //#ifdef CATIACGMV5R18
     //rlad
     /**
     * Sets or unsets the ‘Extrapolation Domain by Domain of CuttingBody and Keep only single solution’ mode.
   * single solution without intersection beetween the others solutions
     *   @param iMode
     *      Mode on (TRUE) or off (FALSE)
     */
     void  SetSingleExtrapolMode(CATBoolean iMode=0);

     /**
     * Queries whether ‘Extrapolation Domain by Domain of CuttingBody and Keep only single solution’ mode is activated or not.
     * single solution without intersection beetween the others solutions
   *   @param oMode
     *      Mode on (TRUE) or off (FALSE)
     */
     void GetSingleExtrapolMode(CATBoolean & oMode);

     //rlaf
//#endif
   //===============================================================
   //Dec 2009 : gets pour acceder aux variables dans le run (netoyage du create)  RLA
   //===============================================================
   CATHybExtrapolationMode GetExtrapolHybMode() {return _ExtrapolHybMode;}
   double GetTolSplit() {return _TolSplit;}
   //CATTopOpInError  & oInternalWarning;
   short GetSideToKeep() {return _SideToKeep;}
   CATBody *  GetCuttingBody() { return _CuttingBody ;} //recuperer  la cicatrice


   void SetExtrapolHybMode(CATHybExtrapolationMode iExtrapolMode) { _ExtrapolHybMode=iExtrapolMode;}
   void SetTolSplit(double iTol) { _TolSplit = iTol;}
   //void GetInternalWarningSplit(CATTopOpInError  & oInternalWarning); A voir dans la classe mere
   void SetSideToKeep(short iSideToKeep) { _SideToKeep=iSideToKeep;}

   void SetCuttingBody(CATBody *iCuttingBody) { _CuttingBody = iCuttingBody;} //ajout de la cicatrice
   //==============

   static CATHybSplit *Load(CATCGMStream &Str,const short LevelOfRuntime, const short VersionOfStream);

   /** @nodoc CATIA Live Shape  */
   virtual void ReadInputBodies(ListPOfCATBody &oListOfCopyInputBodies, ListPOfCATBody &oListOfNoCopyInputBodies);

   /** @nodoc @nocgmitf */
   virtual void GenerateCuttingBody();

protected :

   virtual void SetInputsToReportChecker();

   void MakeResultOrientation();

   void CheckTangentDesignShell();

   void ComputeSplitByExtrapol_1();

   void BodyWillBeDeleted(CATBody* iBody);

   virtual int CheckCellVsKeepRemove(CATCell* iCell);

   int GetBooleanType();

   virtual CATCell* GetCellVsKeepRemoveAndLayDown(CATCell* iCell, CATBody* iBodySupport);

   virtual void RattrapJournal(CATCGMJournalList * ioJournal,CATBody *body,CATLISTP(CATBody)& InputBodies);

   void RequireDefinitionOfInputAndOutputObjects();

   void WriteInput(CATCGMStream  & ioStream);

   CATBody *GetInputCuttingBody() const;

   void Dump( CATCGMOutput& os ) ;

   CATBoolean      ValidateTopOutput(CATTopCheckJournal* iEquivalent,CATCGMOutput& os);

   virtual short GetCATHybSplitType() const = 0 ;

   // Data
   CATBody*                  _BodyToSplit;           // the Body operand to Split
   CATBody*                  _SplittingBody;         // the Splitting Body operand
   CATBody*                  _CuttingBody;           // the Cutting Body operand
   CATBody*                  _UserCuttingBody;       // Cutting Body supplied by the caller (if any)
   CATBody*                  _BodySupport;           // the Support Body operand
   CATBody*                  _ResultByExtrapol;
   CATShell*                 _ShellSupport;          // the single shell of Support Body operand
   short                     _SideToKeep;            // solution side to keep
   ListPOfCATCell            _ResultCellsOp1;        // Cells solution of the 1st Operand
   CATListOfInt              _ResultOrisOp1;         // Cell Orientations
   int                       _ErrorForClosedWireWithSingleVertexMode; // Error management
   int                       _SimplifyMode;          // Simplify management
   int                       _KeepLyingOnLinksOnSplittingBody; // LyingOn Links on splitting body
   double                    _TolSplit; //rla a implementer
   CATBody*                  _CuttingBodyToSimplify;
//#ifdef CATIACGMV5R18
   CATBoolean                _Mode_SemiSpace;
   CATBoolean                _Mode_SingleExtrapol;
   CATHybExtrapolationMode   _ExtrapolHybMode;
//#endif
private:
     //==============================================================================
     // calcul de cellules restantes apres decoupe par un plan infini et mise a jour
     // du journal pour les elements effaces
     //==============================================================================
     void LeftRightCells( CATLONG32                     iDimCell,
                          CATLISTP(CATCell)    & oLeftCell,
                          CATListOfInt             & oLeftOris,
                          CATCGMJournalList    & ioInternalReport);
};

#endif
