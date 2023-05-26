/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1999
//------------------------------------------------------------------------------
//      
// CATHybTrimShell : base class for Hybrid TrimShell Operators 
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
//
#ifndef CATHybTrimShell_h
#define CATHybTrimShell_h

#include "CATHybTrim.h"
#include "CATExtHybTrim.h"
//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATShell.h"
#include "CATString.h"
#include "CATIAV5Level.h"
#include "CATMathInline.h"

class CATHybTrimContextForFastRun;
class CATSubdContextForFastRunExt;
class CATContextForFastRun;
class CATFaceOrder;

class ExportedByPBELight CATHybTrimShell : public CATExtHybTrim
{
public :
   
   //  Constructor
   CATHybTrimShell(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBodyToCut1, short iSideToKeep1, CATBody* iBodyToCut2, short iSideToKeep2, CATBody* iCuttingBody);	
   
   CATHybTrimShell(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBodyToCut1, CATBody* iBodyToCut2, CATBody* iCuttingBody);	
   
   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;
   
   //  Destructor
   ~CATHybTrimShell();     
   
   // Execution of the operator
   int Run();    

#ifdef CATIAR419
   // Poly/Exact Config Management 
   virtual CATBoolean Is_PolyInputs_Allowed();
#endif

   /** @nodoc @nocgmitf */
   void RetrieveShellsConsideringDuplication(short iWhichBody, ListPOfCATShell & oShells);
   
   /** @nodoc CATCGMReplay ...*/
   virtual short GetCATHybTrimType() const;
   
   /** @nodoc CATCGMReplay ...*/
   virtual void RequireDefinitionOfInputAndOutputObjects();
   
   /** @nodoc CATCGMReplay ...*/
   virtual void WriteInput(CATCGMStream  & ioStream);
   
  /** @nodoc CATCGMReplay ...*/
   static const CATString * GetDefaultOperatorId() { return & _OperatorId; };

   //===================================================
   // Methodes FastRun
   //===================================================

   /** @nodoc @nocgmitf */
   CATFastRunStatus PrepareOrExecuteFastRun();

   /** @nodoc @nocgmitf */
   CATContextForFastRun * GetContextForFastRun();

   /** @nodoc @nocgmitf */
   CATContextForFastRun * GetOrCreateContextForFastRun();

   /** @nodoc @nocgmitf */
   CATHybTrimContextForFastRun * GetNoCreateHybTrimContextForFastRun();

   /** @nodoc @nocgmitf */
   CATHybTrimContextForFastRun * GetOrCreateHybTrimContextForFastRun();

   /** @nodoc @nocgmitf */
   virtual void WriteNonBodyInputs(CATCGMStream & Str);

   /** @nodoc @nocgmitf */
   virtual void ReadNonBodyInputs(CATCGMStream & Str);

protected :

  /** @nodoc CATCGMReplay ...*/
  const CATString * GetOperatorId() const;
  
  /** @nodoc CATCGMReplay ...*/
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);

  /** @nodoc CATCGMReplay ...*/
  void MakeSeparateBySides_New();

  /** @nodoc CATCGMReplay ...*/
  int RunOperator();

#ifdef CATIAR419
  //============================
  // Poly/Exact Config Management 
  //============================
  virtual int RunPolyOperator();
#endif

  virtual CATSubdContextForFastRunExt * GetSubdContextIfStatusNotImpossible();

  INLINE void SetFaceOrderOperator(CATFaceOrder * iFaceOrderOperator) {_FaceOrderOperator = iFaceOrderOperator;}
  INLINE CATFaceOrder * GetFaceOrderOperator() {return _FaceOrderOperator;}

private:

   void FinalizePositioning(CATBody * iBody);
   int GetNbFacesAfterDisconnection(CATBody * iBody);
   
   void MakeReport(); 
   void MakeSelect();  
   void MakeSeparateBySides();                       
   void MakeSeparateByKeepRemove();                       
   void MakeSimplify();  

   // Datas
   int    _NbSeparateCells1;  
   int    _NbSeparateCells2;   

  /** @nodoc CATCGMReplay ...*/
   static CATString _OperatorId;

   CATBoolean _DeprecatedCGMReplayMode;

   CATFaceOrder * _FaceOrderOperator;
};
#endif
