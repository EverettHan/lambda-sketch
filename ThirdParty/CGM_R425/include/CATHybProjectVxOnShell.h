/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1999
//------------------------------------------------------------------------------
//      
// class for Hybrid Projection Vertex On Shell
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
//
#ifndef CATHybProjectVxOnShell_h
#define CATHybProjectVxOnShell_h

#include "CATHybProject.h"
#include "CATExtHybProject.h"
//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
class CATCGMJournal;
class CATProjectionPtSur;
#include "CATString.h"

class ExportedByPBELight CATHybProjectVxOnShell : public CATExtHybProject
{
public :
   
   //  Constructor
   CATHybProjectVxOnShell(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBody1, CATBody* iBody2, CATMathDirection* iDir);	
   
   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;

   //  Destructor
   ~CATHybProjectVxOnShell();
   
   //  Methods
   int Run();                               // Execution of the operator
   
   
  /** @nodoc CATCGMReplay ...*/
   static const CATString * GetDefaultOperatorId() { return & _OperatorId; };

protected :

  /** @nodoc CATCGMReplay ...*/
  const CATString * GetOperatorId() const;
  
  /** @nodoc CATCGMReplay ...*/
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  
  /** @nodoc CATCGMReplay ...*/
  int RunOperator();

  
   int ComputeProjection(CATVertexInVolume* VxVol, CATShell* Shell);   
   int ComputeProjection(CATVertex* Vx, CATFace* Face); 
   
   // Trim the geometrical result according to the topology
   int TopologicalTrimming(CATVertex* Vx, CATFace* Face, CATPointOnSurface* PtOnSur); 
   
   // Datas
   CATProjectionPtSur*   _GeomPtSurOperator; // the Geometrical point/surface Projection Operator

private:

   static CATString _OperatorId;
};
#endif
