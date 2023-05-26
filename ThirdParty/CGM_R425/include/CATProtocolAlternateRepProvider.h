// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
//
// CATProtocolAlternateRepProvider
// 
//=============================================================================
// Usage Notes:
// 
//=============================================================================
// Created :
//	April, 05th 2005 :	SVQ
//=============================================================================

#ifndef CATProtocolAlternateRepProvider_H
#define CATProtocolAlternateRepProvider_H

#include "CATVisFoundation.h"
#include "CATVizBaseCodeExtension.h"

class CATRep;

class ExportedByCATVisFoundation CATProtocolAlternateRepProvider : public CATVizBaseCodeExtension
{
  CATVizDeclareProtocol(CATProtocolAlternateRepProvider);

  public:  

    CATProtocolAlternateRepProvider();
    virtual ~CATProtocolAlternateRepProvider();

    virtual CATRep *BuildAternateRep();
    virtual CATRep *BuildAlternateRep() = 0;
    virtual void DestroyAlternateRep(CATRep *alternateRep) = 0;
};

#endif
