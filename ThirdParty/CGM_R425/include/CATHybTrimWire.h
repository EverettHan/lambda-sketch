/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1999
//------------------------------------------------------------------------------
//
// CATHybTrimWire : base class for Hybrid TrimWire Operators
//
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance:
//------------------------------------------------------------------------------
//
#ifndef CATHybTrimWire_h
#define CATHybTrimWire_h

#include "CATHybTrim.h"
#include "CATExtHybTrim.h"
#include "ExportedByPBELight.h"
#include "CATString.h"
#include "CATIAV5Level.h"

class ExportedByPBELight CATHybTrimWire : public CATExtHybTrim
{
public :

   //  Constructor
   CATHybTrimWire(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBodyToCut1, short iSideToKeep1, CATBody* iBodyToCut2, short iSideToKeep2, CATBody* iCuttingBody);

   CATHybTrimWire(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBodyToCut1, CATBody* iBodyToCut2, CATBody* iCuttingBody);

   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;

   //  Destructor
   ~CATHybTrimWire();

   // Execution of the operator
   int Run();

#ifdef CATIAR419
   // Poly/Exact Config Management 
   virtual CATBoolean Is_PolyInputs_Allowed();
   virtual CATBoolean Is_MixedPolyExactInputs_Allowed();
#endif

   // Force Activation du nouveau BuildBody (usage JHN only !)
   void ForceNewBuildBody();

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

#ifdef CATIAR419
  //============================
  // Poly/Exact Config Management 
  //============================
  virtual int RunPolyOperator();

#endif

   virtual void GenerateCuttingBody();

private:

   void MakeReport();
   void MakeSelectBySides();
   void MakeSelectByKeepRemove();
   void MakeSimplify();

   // Datas
   int    _NbSeparateCells1;
   int    _NbSeparateCells2;


  /** @nodoc CATCGMReplay ...*/
   static CATString _OperatorId;
};
#endif
