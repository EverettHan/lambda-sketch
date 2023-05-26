/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 2001
//------------------------------------------------------------------------------
//      
// CATHybTrimWireOnSupport : base class for Hybrid TrimWireOnSupport Operators 
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
//
#ifndef CATHybTrimWireOnSupport_h
#define CATHybTrimWireOnSupport_h

#include "CATHybTrim.h"
#include "CATExtHybTrim.h"
//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
#include "CATString.h"

class ExportedByPBELight CATHybTrimWireOnSupport : public CATExtHybTrim
{
public :
   
   //  Constructor
   CATHybTrimWireOnSupport(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBodyToCut1, short iSideToKeep1, CATBody* iBodyToCut2, short iSideToKeep2, CATBody* iBodySupport);

   CATHybTrimWireOnSupport(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBodyToCut1, CATBody* iBodyToCut2, CATBody* iBodySupport);
   
   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;
   
   //  Destructor
   ~CATHybTrimWireOnSupport();     
   
   // Execution of the operator
   int Run();         
   
      /** @nodoc CATCGMReplay ...*/
   virtual short GetCATHybTrimType() const;
   
   
  /** @nodoc CATCGMReplay ...*/
   static const CATString * GetDefaultOperatorId() { return & _OperatorId; };

   /** @nodoc @nocgmitf */
   virtual void WriteInput(CATCGMStream  & ioStream);

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
  int RunOperator();

private:
   
   void SetInputsToReportChecker();
 
   void MakeRunWithSigns();                       
   void MakeRunWithExtrapol();                       
   void MakeReport();                       
   void MakeSimplify();
   
   void CleanUp();
   void CheckInputs();
   void Assemble();

   // Datas
   int _NbSeparateCells1;  
   int _NbSeparateCells2;   
   int _PropagateDiag1;  
   int _PropagateDiag2;  


  /** @nodoc CATCGMReplay ...*/
   static CATString _OperatorId;
};
#endif
