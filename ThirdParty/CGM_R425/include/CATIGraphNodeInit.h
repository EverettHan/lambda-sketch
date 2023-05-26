//===================================================================
// COPYRIGHT Microsoft 2011/10/12
//===================================================================
// CATIGraphNodeInit.cpp
// Header definition of class CATIGraphNodeInit
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/10/12 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIGraphNodeInit_H
#define CATIGraphNodeInit_H

#include "CATOmnMain.h"
#include "CATBaseUnknown.h"


extern ExportedByCATOmnMain  IID IID_CATIGraphNodeInit ;

class CATNavigInstance;
/*
 * Interface to compute any data before the addition of the current node to the CATNavigController.
 * The method SetInstance is called before this addition, it allows a DataExtension on the node to make data members initialisations before the usage of the node.
 */
class ExportedByCATOmnMain CATIGraphNodeInit : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /*
   * Called before the addition of the node in the CATNavigController
   */
  virtual void SetInstance(CATNavigInstance* inst)=0;

};

//-----------------------------------------------------------------------

#endif