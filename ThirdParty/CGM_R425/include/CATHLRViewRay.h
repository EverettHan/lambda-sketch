/* -*-C++-*-*/
#ifndef CATHLRViewRay_H
#define CATHLRViewRay_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2008
//
// CATHLRViewRay
//
// DESCRIPTION :
//
//    Description of all 3D-points (lying on a set of edges)
//    which are intercepted by a common linear ray, 
//    -> from the observer view point in conical case
//    -> parallel to the view direction in cylindrical case
// 
//    This description allows to declare logical links between vertices,
//    which is very usefull to retrieve best quality of hermeticity
//    ( reconvergence of intersection between edges projections )
//    and leads to the creation of one only 2D-point after projection
//
//=============================================================================
// Abstract Class     : No
//=============================================================================
//
// History
//
// Dec. 2008   Dominique PREVOST (DPS)    Creation            
//
//=============================================================================

//============================================================
// Other includes
//------------------------------------------------------------ 

#include "HLREngine.h"                    // ExportedBy
#include "CATErrorDef.h"                  // define HRESULT

#include "CATMathPoint.h"                 // agregation


//============================================================
// Forward declarations
//------------------------------------------------------------ 
class CATHLRMemoryManager;


//============================================================
// CLASS DEFINITION
//------------------------------------------------------------ 
class ExportedByHLREngine CATHLRViewRay
{
public:

  //=============================================================================
  // CONSTRUCTORS AND DESTRUCTOR
  //=============================================================================
  
  static CATHLRViewRay * CreateViewRay(CATMathPoint &iRefPt3D, CATHLRMemoryManager &iMemoryManager);


  /**
  * No destructor : deallocated by CATHLRMemoryManager only
  */


  //=============================================================================
  // METHODS
  //=============================================================================
  

  // Merge between 2 instances of CATHLRViewRay
  // The first one absorbs the second one
  // After merge the second one is empty and its pointer is NULL
  void MergeViewRaysData(CATHLRViewRay * & ioViewRayToAbsorb);
  



  //=============================================================================
  // PROTECTED DATAS
  //=============================================================================

protected:

  // Default constructor (private use only)
  CATHLRViewRay(CATMathPoint &iRefPt3D);



  //=============================================================================
  // INTERNAL DATAS
  //=============================================================================

private:

  CATMathPoint              _RefPt3D;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================


#endif
