// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
// CATProtocolDmuStream
// 
//=============================================================================
// Usage Notes:
// 
//=============================================================================
// Created :
//	December, 09th 2002 :	JQT
//=============================================================================

#ifndef CATProtocolDmuStream_H
#define CATProtocolDmuStream_H

#include "SGInfra.h"
#include "CATVizBaseCodeExtension.h"

#include "CATStreamer.h"

class CATCGRSetting;

class ExportedBySGInfra CATProtocolDmuStream : public CATVizBaseCodeExtension
{
  CATVizDeclareProtocol(CATProtocolDmuStream);

  public:  

    CATProtocolDmuStream();
    virtual ~CATProtocolDmuStream();

    virtual void Stream(CATStreamer& str, CATCGRSetting * iSetting, int savetype=0) = 0;
    virtual void UnStream(CATStreamer& str,void *&iopt) = 0;
};

#endif
