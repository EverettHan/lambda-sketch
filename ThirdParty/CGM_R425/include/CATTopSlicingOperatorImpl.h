/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 2010
//------------------------------------------------------------------------------
//      
// class for Top Slicing multibody
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
//
#ifndef CATTopSlicingOperatorImpl_h
#define CATTopSlicingOperatorImpl_h

#include "CATTopSlicingOperator.h"

//#include "CATString.h"

class CATGeoFactory;
class CATTopData;
class CATCGMJournalList;
class CATBody;

class CATTopSlicingOperatorImpl :public CATTopSlicingOperator
{
  public:
  CATTopSlicingOperatorImpl(CATGeoFactory * iFactory, CATTopData * iTopData,CATExtTopOperator * iExtensible); 



  //  Destructor
  ~CATTopSlicingOperatorImpl();

protected:
  //===================================================================================================
  // Methods
  //===================================================================================================
  CATBody * GetResult(CATCGMJournalList * ioJournal);

  CATBody * GetResult();

   int  Run() ;

   int  RunOperator() ;

  //CATBody * GetResult(CATCGMJournalList * ioJournal);

  //CATBody * GetResult();

   void SetCheckJournal(CATBoolean iCheckMode);

   CATBoolean GetCheckJournal() const;

   //void  SetCheckReport(short mode=1);

   //short GetCheckReport() const;

  //===================================================================================================
  // Dump Method
  //===================================================================================================

  //void Dump(ostream & iOutStream) const;


public:

	void SetSliceCallback( CATSliceCallback iCallback);


   //=================================
      //  CGMReplay Methods
      //=================================

   public:

      static const CATString *GetDefaultOperatorId() { return &_OperatorId; }

   protected:

      const  CATString  *GetOperatorId();
      CATExtCGMReplay   *IsRecordable(short &LevelOfRuntime, short &VersionOfStream);
      void               RequireDefinitionOfInputAndOutputObjects();
      void               WriteInput(CATCGMStream &ioStream);
      void               WriteTopOutput(CATCGMStream &ioStream);
      CATBoolean         ValidateTopOutput(CATTopCheckJournal* iEquivalent,CATCGMOutput& os);


      //CATCheckDiagnostic CheckOutput(CATCGMOutput &os);

      static CATString   _OperatorId;
      

};
#endif
