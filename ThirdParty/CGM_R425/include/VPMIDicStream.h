//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2011/02/01
//===================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef VPMIDicStream_H
#define VPMIDicStream_H

#include "VPMIDicInterfaces.h"
#include "CATBaseUnknown.h"

extern ExportedByVPMIDicInterfaces IID IID_VPMIDicStream;

class CATISAXContentHandler_var;
class CATISAXErrorHandler_var;

class ExportedByVPMIDicInterfaces VPMIDicStream : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual HRESULT LoadMetadataStream   ( const CATISAXContentHandler_var& iContent,
                                         const CATISAXErrorHandler_var& iError ) = 0;
  virtual HRESULT LoadEnvironmentStream( const CATISAXContentHandler_var& iContent,
                                         const CATISAXErrorHandler_var& iError ) = 0;
};

#endif /*VPMIDicStream_H*/
