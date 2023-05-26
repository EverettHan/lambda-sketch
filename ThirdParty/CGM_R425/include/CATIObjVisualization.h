/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1998  
//-----------------------------------------------------------------------------
/**
  * @CAA2Level L1
  * @CAA2Usage U3
  */

#ifndef CATIObjVisualization_H_
#define CATIObjVisualization_H_

#include "CATBaseUnknown.h"
#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIObjVisualization ;

/**
  * Interface to enable the editing of an object.
  */

class ExportedByAD0XXBAS CATIObjVisualization : public CATBaseUnknown
{
  CATDeclareInterface;

 public:
 /**
   * Enables the editing of an object.
   */
  virtual HRESULT Show() = 0;
};


// Macro for Handlers  //
//======================

CATDeclareHandler( CATIObjVisualization, CATBaseUnknown );

#endif
