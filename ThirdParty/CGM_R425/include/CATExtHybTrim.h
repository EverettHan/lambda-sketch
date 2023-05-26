#ifndef CATExtHybTrim_h_
#define CATExtHybTrim_h_

#include "ExportedByPBELight.h"
#include "CATHybDef.h"
#include "CATExtHybBoolean.h"
#include "CATHybTrim.h"
#include "CATMathInline.h"
#include "CATUnicodeString.h"

class CATHybTrimContextForFastRun;


class ExportedByPBELight CATExtHybTrim : public CATExtHybBoolean
{

   friend class CATHybTrim;


protected:

   //-------------------------------------------------------------------------------------------------------
   // Constructeur
   //   iOperateur peut etre NULL,  mais ca doit etre reserver au cas tres particuliers sous constructeur
   //   il faut dans ce cas s'empresser de retablir la definition avec la methode SetOperator
   //-------------------------------------------------------------------------------------------------------

   CATExtHybTrim(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBodyToCut1, short iSideToKeep1, CATBody* iBodyToCut2, short iSideToKeep2, CATBody* iCuttingBody, CATHybTrim* iOperateur = NULL);

   CATExtHybTrim(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBodySupport, CATBody* iBodyToCut1, short iSideToKeep1, CATBody* iBodyToCut2, short iSideToKeep2, CATHybTrim* iOperateur = NULL);

   CATExtHybTrim(CATGeoFactory* iFactory, CATTopData* iData);

   CATExtHybTrim(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBodyToCut1, CATBody* iBodyToCut2, CATBody* iCuttingBody, CATHybTrim* iOperateur = NULL);

public:

   // Destructor
   virtual ~CATExtHybTrim();

   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;

   // treatment with Simplification of the Result (to use before run)
   void SetSimplifyMode(int yes_or_no=1);
   int  GetSimplifyMode() const;

   // desactivation of Error on SplitClosedWireWithSingleVertex (to use before run)
   // default value is : 1 --> Error is throw in case of Split a ClosedWire With Single Vertex
   void SetThrowErrorForClosedWireWithSingleVertex(int yes_or_no=1);
   int  GetErrorForClosedWireWithSingleVertexMode() const;

   //===============================================================
   //Avril 2010 : gets pour acceder aux variables dans le run (netoyage du create)  RLA
   //===============================================================
   CATHybExtrapolationMode GetExtrapolHybMode() {return _ExtrapolHybMode;}
   double GetTolTrim() {return _TolTrim;}
   //CATTopOpInError  & oInternalWarning;
   short GetSideToKeep1() {return _Side1ToKeep;}
   short GetSideToKeep2() {return _Side2ToKeep;}
   CATBody *  GetCuttingBody() { return _CuttingBody ;} //recuperer  la cicatrice

   void DefineHybSelectionMode(CATHybSelectionMode iSelectMode);
   CATHybSelectionMode RetrieveHybSelectionMode();
   CATUnicodeString RetrieveHybSelectionMode_String();

   void SetExtrapolHybMode(CATHybExtrapolationMode iExtrapolMode) { _ExtrapolHybMode=iExtrapolMode;}
   void SetTolTrim(double iTol) { _TolTrim = iTol;}
   //void GetInternalWarningSplit(CATTopOpInError  & oInternalWarning); A voir dans la classe mere
   void SetSideToKeep1(short iSideToKeep1) { _Side1ToKeep=iSideToKeep1;}
   void SetSideToKeep2(short iSideToKeep2) { _Side2ToKeep=iSideToKeep2;}

   void SetCuttingBody(CATBody *iCuttingBody) { _CuttingBody = iCuttingBody;} //ajout de la cicatrice

   /** @nodoc @nocgmitf */
   void SetUserCuttingBody(CATBody *iUserCuttingBody) { _UserCuttingBody = iUserCuttingBody;}

   /** @nodoc @nocgmitf */
   CATBody * GetUserCuttingBody() {return _UserCuttingBody;}

   //==============

   /** @nodoc @nocgmitf */
   virtual CATHybTrimContextForFastRun * GetNoCreateHybTrimContextForFastRun();

   /** @nodoc @nocgmitf */
   virtual CATHybTrimContextForFastRun * GetOrCreateHybTrimContextForFastRun();

   /** @nodoc @nocgmitf */
   INLINE CATBody * GetBody1ToCut() {return _Body1ToCut;}

   /** @nodoc @nocgmitf */
   INLINE CATBody * GetBody2ToCut() {return _Body2ToCut;}

   /** @nodoc @nocgmitf */
   INLINE void SetBody1ToCut(CATBody * iBody1ToCut) {_Body1ToCut = iBody1ToCut; _Body1ToCutCopy = iBody1ToCut;}

   /** @nodoc @nocgmitf */
   INLINE void SetBody2ToCut(CATBody * iBody2ToCut) {_Body2ToCut = iBody2ToCut;}

   /** @nodoc @nocgmitf */
   INLINE void SetBodySupport(CATBody * iBodySupport) {_BodySupport = iBodySupport;}

   /** @nodoc @nocgmitf */
   static CATHybTrim * LoadFromVersion(CATCGMStream & Str,
                                       const short LevelOfRuntime,
                                       const short VersionOfStream,
                                       CATContextForFastRunExt * iopCtxExt,
                                       CATGeoFactory * iFactory,
                                       CATTopData & iData,
                                       CATBodyFreezeMode & iFreezeMode,
                                       CATLISTP(CATICGMObject) & InputCopy,
                                       CATLISTP(CATICGMObject) & InputNoCopy,
                                       CATBody * OutputBody,
                                       size_t whereOutputBegin,
                                       short levelOutput,
                                       const CATBoolean iForExternalWeakLinks,
                                       short iVersion);

   /** @nodoc @nocgmitf */
   virtual void WriteNonBodyInputs(CATCGMStream & Str);

   /** @nodoc @nocgmitf */
   virtual void ReadNonBodyInputs(CATCGMStream & Str);

   /** @nodoc @nocgmitf */
   virtual void GenerateCuttingBody();

   // VoB
   virtual CATBoolean IsVoBSupported();
   virtual void AdaptVoBOptions();

protected :

   virtual void SetInputsToReportChecker();

   void MakeResultOrientation();

   void CheckTangentDesignShell();

   void ComputeSplitByExtrapol_1();

   void ComputeSplitByExtrapol_2();

   void BodyWillBeDeleted(CATBody* iBody);

   virtual int CheckCellVsKeepRemove(CATCell* iCell);

   int GetBooleanType();

   virtual CATCell* GetCellVsKeepRemoveAndLayDown(CATCell* iCell, CATBody* iBodySupport);

   virtual void RequireDefinitionOfInputAndOutputObjects();

   virtual void Dump( CATCGMOutput& os ) ;

   CATBody *GetInputCuttingBody() const;

   virtual CATBoolean      ValidateTopOutput(CATTopCheckJournal* iEquivalent,CATCGMOutput& os);

   virtual short GetCATHybTrimType() const = 0 ;

   // Data
   CATBody*                  _Body1ToCut;            // the First Body operande to Cut
   CATBody*                  _Body1ToCutCopy;
   CATBody*                  _Body2ToCut;            // the Second Body operande to Cut
   CATBody*                  _CuttingBody;           // the Cutting Body operand
   CATBody*                  _UserCuttingBody;
   CATBody*                  _BodySupport;           // the Support Body operand
   CATBody*                  _ResultByExtrapol1;
   CATBody*                  _ResultByExtrapol2;
   CATShell*                 _ShellSupport;          // the single shell of Support Body operand
   short                     _Side1ToKeep;           // solution side to keep on First Body
   short                     _Side2ToKeep;           // solution side to keep on Second Body
   ListPOfCATCell            _ResultCellsOp1;        // Cells solution of the 1st Operand
   ListPOfCATCell            _ResultCellsOp2;        // Cells solution of the 2nd Operand
   CATListOfInt              _ResultOrisOp1;         // Cell Orientations
   CATListOfInt              _ResultOrisOp2;         // Cell Orientations
   int                       _ForceNewBuildBody;     // Activate New BuildBody
   int                       _SimplifyMode;          // Simplify management
   int                       _ErrorForClosedWireWithSingleVertexMode; // Error management
   double                _TolTrim;                  // tol fact
   CATHybExtrapolationMode   _ExtrapolHybMode;

};
#endif
