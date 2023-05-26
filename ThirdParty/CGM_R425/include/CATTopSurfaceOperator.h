/* -*-c++-*- */
#ifndef CATTopSurfaceOperator_h
#define CATTopSurfaceOperator_h
//COPYRIGHT DASSAULT SYSTEMES 1998
//===================================================================
//     Author : JEL
//     Date   : 17 / 06 / 1999
// Class CATTopSurfaceOperator :
// Operator offers the Topological build of a surface :
//
//-------------------------------------------------------------------
// Notes :
// -----
// The Run() method is mandatory.
// The result Body will be frozen by default.
// Report can be done on operator.
//-------------------------------------------------------------------
//-------------------------------------------------------------------
// Usage Notes :
// -----------
//  basic class : no direct use.
//===================================================================
#include "CATTopOperator.h"
#include "BasicTopology.h"


class ExportedByBasicTopology CATTopSurfaceOperator :public CATTopOperator
{
//-------------------------------------------------------------------
  CATCGMVirtualDeclareClass(CATTopSurfaceOperator);
public:
//-------------------------------------------------------------------

/**  
 * @nodoc 
 * do not use
 */
  CATTopSurfaceOperator(CATGeoFactory* iFactory, CATTopData* iTopData);

// deletes a surface operator
 virtual ~CATTopSurfaceOperator();

//
// Set Methods
//
 /**  
 * @nodoc 
 */
 virtual CATLONG32 SetClosure(CATLONG32 iclosed);  // 1 ferme, 0 ouvert

//
// Get Methods
//
 /**  
 * @nodoc 
 */
 virtual CATLONG32 GetClosure(CATLONG32 &oClosed); // 1 ferme, 0 ouvert

protected :

  CATLONG32 _Closed;

};


#endif
