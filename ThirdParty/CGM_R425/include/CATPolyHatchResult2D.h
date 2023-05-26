#ifndef CATPolyHatchResult2D_h
#define CATPolyHatchResult2D_h

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2011
//
// CATPolyHatchResult2D
//
// DESCRIPTION :
//
//               Hatching result containing all the dots & dashes
//               computed from a HatchPattern inside a polygonal face
//
//=============================================================================
// Abstract Class     : No
//
// History
//
// December. 2011   Dominique PREVOST (DPS)    Creation    
//
//=============================================================================

#include "PolygonalHatching.h"          // ExportedBy


class CATMathPoint2D;
class CATPolyHatchSubResult2D;
class CATPolyHatchResultIter2D;


/**
* Class defining the polyhedral Hatching result 2D as a set of segments and dots
*<ul>
* <li>CATPolyHatchResult2D is instanciated through the <tt>CATPolyOffsetOper2D::Run</tt> method.
* @see CATPolyOffsetOper2D
* It can be kept by the user even if the operator is removed, but it must be directly removed with the <tt>delete</tt> method after use.
* It is not streamable.
* @see CATPolyHatchResultIter2D
*/

class ExportedByPolygonalHatching CATPolyHatchResult2D
{

public:

 /**
  *  Life Cycle Management
  */
  CATPolyHatchResult2D(int iNbSubResult);
  virtual ~CATPolyHatchResult2D();

  
public:

 /**
  *  nodoc
  */
  void AttachSubResult(unsigned int iSubResultIdx, CATPolyHatchSubResult2D * iSubResult);



private :

  // Internal Data
  // -------------

  friend class CATPolyHatchResultIter2D;

  CATPolyHatchSubResult2D    ** _SubResultTab;
  unsigned int                  _NbSubResult;

};

#endif
