/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1999
//------------------------------------------------------------------------------
//      
// class for Hybrid Projection VertexInVolume On Wire
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
//
#ifndef CATHybProjectVxOnWire_h
#define CATHybProjectVxOnWire_h

#include "CATHybProject.h"
#include "CATExtHybProject.h"
//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
class CATCGMJournal;
class CATProjectionPtCrv;
#include "CATString.h"

class ExportedByPBELight CATHybProjectVxOnWire : public CATExtHybProject
{
public :
   
   //  Constructor
   CATHybProjectVxOnWire(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBody1, CATBody* iBody2, CATMathDirection* iDir);	
   
   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;

   //  Destructor
   ~CATHybProjectVxOnWire();
   
   //  Methods
   int Run();                               // Execution of the operator
   
   
  /** @nodoc CATCGMReplay ...*/
   static const CATString * GetDefaultOperatorId() { return & _OperatorId; };
   
protected:
  
  /** @nodoc CATCGMReplay ...*/
  const CATString * GetOperatorId() const;
  
  /** @nodoc CATCGMReplay ...*/
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  
  /** @nodoc CATCGMReplay ...*/
  int RunOperator();
  
   int ComputeProjection(CATVertexInVolume* VxVol, CATWire* Wire);   
   int ComputeProjection(CATVertex* Vx, CATEdge* Edge); 
   
   // Trim the geometrical result according to the topology
   int TopologicalTrimming(CATVertex* Vx, CATEdge* Edge, CATPointOnCurve* PtOnCrv, double iDistance); 
   
   // calcul de la distance entre l'edge a projeter et son resultat
   double ComputeDistance(CATVertex* Vx, CATPointOnCurve* PtOnCrv);
   
   // Datas
   CATVertex*                  _VxToProject; // the current cell to project
   CATEdge*                    _EdgeSupport; // the current cell support
   CATPoint*                _PointToProject; // the geometry to project
   CATCurve*                  _CurveSupport; // the geometry support

private:

   static CATString _OperatorId;
};
#endif
