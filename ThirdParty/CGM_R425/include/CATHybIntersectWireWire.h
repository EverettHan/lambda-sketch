/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1999
//------------------------------------------------------------------------------
//      
// class for Hybrid Intersection Wire Wire
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
//
#ifndef CATHybIntersectWireWire_h
#define CATHybIntersectWireWire_h

#include "CATHybIntersect.h"
#include "CATExtHybIntersect.h"
//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
class CATCGMJournal;

class ExportedByPBELight CATHybIntersectWireWire : public CATExtHybIntersect
{
public :
   
   //  Constructor
   CATHybIntersectWireWire(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBody1, CATBody* iBody2);
   
   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;
   
   //  Destructor
   ~CATHybIntersectWireWire();
   
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
   
   int  ComputeIntersection(CATWire* Wire1, CATWire* Wire2);
   void CheckTangentDesignWire();      

private :
   static CATString _OperatorId;
};
#endif
