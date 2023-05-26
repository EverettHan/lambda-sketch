// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATProtocolXMLStream_H
#define CATProtocolXMLStream_H

#include "CATVisInteropXMLMesh.h"
#include "CATVizBaseCodeExtension.h"
#include "CATBoolean.h"

class CATVizXMLStreamOptions;
class CATVizXMLStreamer;
class CATISAXAttributes_var;
class CATRep;
class CATUnicodeString;
class CATIXMLPPWriter_var;

class ExportedByCATVisInteropXMLMesh CATProtocolXMLStream : public CATVizBaseCodeExtension
{
   CATVizDeclareProtocol(CATProtocolXMLStream);

public:  

   virtual HRESULT Stream  ( CATIXMLPPWriter_var & oWriter, CATVizXMLStreamer & iStreamer, CATVizXMLStreamOptions & iStreamOptions) = 0;

   virtual CATBoolean IsFiltered ( CATVizXMLStreamOptions & iStreamOptions ) = 0;

protected:

   CATProtocolXMLStream();
   virtual ~CATProtocolXMLStream();
};

#endif
