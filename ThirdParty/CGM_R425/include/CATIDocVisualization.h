/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1998  
//-----------------------------------------------------------------------------
//  This interface enables to launch a document visualization inside the 
//    CNEXT Frame. It should not be implemented by "typed" document because
//    the default implementation uses the CATIEditor interface (cf FileMenu)
// 
//-----------------------------------------------------------------------------
//  (March.98)
//-----------------------------------------------------------------------------
#ifndef CATIDocVisualization_H_
#define CATIDocVisualization_H_

#include "CATIObjVisualization.h"
#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIDocVisualization ;

class ExportedByAD0XXBAS CATIDocVisualization : public CATIObjVisualization
{
  CATDeclareInterface;

 public:
  virtual HRESULT UpdateVisuData () = 0 ;
  virtual HRESULT SavePreviewData () = 0;
};


// Macro for Handlers  //
//======================

CATDeclareHandler( CATIDocVisualization, CATIObjVisualization );

#endif
