// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
// CATProtocolHLRPlaneView
// 
//=============================================================================
// Usage Notes:
// 
//=============================================================================
// Created :
//	December, 12th 2002 :	JQT
//=============================================================================

#ifndef CATProtocolHLRPlaneView_H
#define CATProtocolHLRPlaneView_H

#include "SGInfra.h"
#include "CATVizBaseCodeExtension.h"

class CATHLRPlaneView;

class ExportedBySGInfra CATProtocolHLRPlaneView : public CATVizBaseCodeExtension
{
  CATVizDeclareProtocol(CATProtocolHLRPlaneView);

  public:  

    CATProtocolHLRPlaneView();
    virtual ~CATProtocolHLRPlaneView();

    virtual CATHLRPlaneView* GetPlaneView () = 0;
};

#endif

