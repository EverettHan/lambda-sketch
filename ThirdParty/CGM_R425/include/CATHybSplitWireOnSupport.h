/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 2001
//------------------------------------------------------------------------------
//      
// CATHybSplitWireOnSupport : base class for Hybrid SplitWireOnSupport Operators 
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
//
#ifndef CATHybSplitWireOnSupport_h
#define CATHybSplitWireOnSupport_h

#include "CATHybSplit.h"
#include "CATExtHybSplit.h"
//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
#include "CATString.h"

class ExportedByPBELight CATHybSplitWireOnSupport : public CATExtHybSplit
{
public :
   
   //  Constructor
   CATHybSplitWireOnSupport(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBodyToSplit, short iSideToKeep, CATBody* iSplittingBody, CATBody* iBodySupport);
   
   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;

   //  Destructor
   ~CATHybSplitWireOnSupport();     
   
   // Execution of the operator
   int Run();                

   
   /** @nodoc CATCGMReplay ...*/
   virtual short GetCATHybSplitType() const;
   
   
  /** @nodoc CATCGMReplay ...*/
   static const CATString * GetDefaultOperatorId() { return & _OperatorId; };

   
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

   // Datas
   int _NbSeparateCells;  
   int _PropagateDiag;  

  /** @nodoc CATCGMReplay ...*/
   static CATString _OperatorId;
};
#endif
