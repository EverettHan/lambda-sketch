//===================================================================
// COPYRIGHT Dassault Systemes 2016/12/19
//===================================================================
// CATIIVSelectMove3D.cpp
// Header definition of class CATIIVSelectMove3D
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2016/12/19 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIIVSelectMove3D_H
#define CATIIVSelectMove3D_H

#include "IVInterfaces.h"
#include "CATBaseUnknown.h"


extern ExportedByIVInterfaces  IID IID_CATIIVSelectMove3D ;


class ExportedByIVInterfaces CATIIVSelectMove3D: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * @nodoc
  * Initialize manipulators on object representations, or anything needed
  * to be able to move object. This method is called just after object
  * has been selected.
  */
  virtual HRESULT Init(CATBaseUnknown ** ioMoveAgent) = 0;

  /**
  * @nodoc
  * This method removes manipulators on object representation or anything
  * needed after object has been moved. This method is called just after object
  * has been unselected.
  */
  virtual HRESULT End() = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIIVSelectMove3D, CATBaseUnknown );

#endif