/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1999
//------------------------------------------------------------------------------
//      
// class for Hybrid Intersection Wire Shell
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
//
#ifndef CATHybIntersectWireShell_h
#define CATHybIntersectWireShell_h

#include "CATHybIntersect.h"
#include "CATExtHybIntersect.h"
//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
class CATCGMJournal;

class ExportedByPBELight CATHybIntersectWireShell : public CATExtHybIntersect
{
public :
   
   //  Constructor
   CATHybIntersectWireShell(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBody1, CATBody* iBody2);
   
   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;
   
   //  Destructor
   ~CATHybIntersectWireShell();
   
   //  Methods
   int RunOperator();
   int Run();

#ifdef CATIAR419
   // Poly/Exact Config Management 
   virtual CATBoolean Is_PolyInputs_Allowed();
   virtual CATBoolean Is_MixedPolyExactInputs_Allowed();
#endif

   static const CATString* GetDefaultOperatorId() { return &_OperatorId; }

protected :

#ifdef CATIAR419
   //============================
   // Poly/Exact Config Management 
   //============================
   virtual int RunPolyOperator();
#endif

   const CATString * GetOperatorId() const;

   void ComputeIntersection();   
   void CheckTangentDesignWire();      

private :
   static CATString _OperatorId;

};
#endif
