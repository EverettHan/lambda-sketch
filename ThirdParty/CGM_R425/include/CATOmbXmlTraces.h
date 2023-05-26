/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2007

/**
 * @level Private
 * @usage U1
 */


#ifndef CATOmbXmlTraces_H
#define CATOmbXmlTraces_H


#include "CATOmsXmlTraces.h"

#include "AC0XXLNK.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATCollec.h"
#include "CATLib.h"
#include "CATOmxOMap.h" 
#include "CATThreads.h"
#include "CATOmxSR.h"
#include "CATOmxMapIter.h"
#include "CATTime.h"
#include "CATOmxAutoPtr.h"

#pragma warning (push)
#pragma warning (disable : 4099)
#pragma warning (disable : 4251)


class CATBaseUnknown;
class CATDocument;
class CATIOmbStreamDescriptor;
class CATVVSURLConnection;
class CATStorage;
class CATComponentId;

/**
* Dump a debug mesage dedicated to a RepRef
*/
class ExportedByAC0XXLNK ComponentMessage : public TraceMessage
{
public :
  ComponentMessage(CATBaseUnknown* ipRepRef);  
  virtual ~ComponentMessage();
  virtual void Dump() const; 

  //FIXME: required on macos_a64/linux_a64...but not on win_* or linux_b64
  ComponentMessage(const ComponentMessage& iMsg):TraceMessage(iMsg),_pRepRef(iMsg._pRepRef),_pMessage(const_cast<ComponentMessage&>(iMsg)._pMessage.GiveBack()) {}

private : 
  CATOmxSR<CATBaseUnknown> _pRepRef;  
  CATOmxAutoPtr<TraceMessage> _pMessage;
};

/**
* Dump a debug mesage dedicated to a StreamDescriptor
*/
class ExportedByAC0XXLNK SDMessage : public TraceMessage
{
public :
  SDMessage(CATBaseUnknown& ipSD, CATBaseUnknown& ipRepRef, CATDocument* pDoc=NULL);
  SDMessage(const CATBaseUnknown* ipSD);
  virtual ~SDMessage();
  virtual void Dump() const; 

  //FIXME: required on macos_a64/linux_a64...but not on win_* or linux_b64
  SDMessage(const SDMessage& iMsg):TraceMessage(iMsg),_pSD(iMsg._pSD),_pMessage(const_cast<SDMessage&>(iMsg)._pMessage.GiveBack()),_pDoc(iMsg._pDoc) {}

private : 
  CATOmxSR<CATBaseUnknown> _pSD;  
  CATOmxAutoPtr<TraceMessage> _pMessage;
  CATOmxSR<CATDocument> _pDoc;
};

/**
* Dump a debug mesage dedicated to a document
*/
class ExportedByAC0XXLNK DocumentMessage : public TraceMessage
{
public :
  DocumentMessage(CATDocument& iDoc);
  // The constructeur is only here to ease integration of the code
  DocumentMessage(CATDocument* ipDoc);
  virtual ~DocumentMessage();
  virtual void Dump() const;   

  //FIXME: required on macos_a64/linux_a64...but not on win_* or linux_b64
  DocumentMessage(const DocumentMessage& iMsg):TraceMessage(iMsg),_pMessage(const_cast<DocumentMessage&>(iMsg)._pMessage.GiveBack()),_pDoc(iMsg._pDoc) {}

private :
  CATOmxAutoPtr<TraceMessage> _pMessage;
  CATOmxSR<CATDocument> _pDoc;
};

/**
* Dump a debug mesage dedicated to a container
*/
class ExportedByAC0XXLNK ContainerMessage : public TraceMessage
{
public :
  ContainerMessage(CATBaseUnknown& iCont, CATDocument* ipDoc=NULL);
  virtual ~ContainerMessage();
  virtual void Dump() const;   

  //FIXME: required on macos_a64/linux_a64...but not on win_* or linux_b64
  ContainerMessage(const ContainerMessage& iMsg):TraceMessage(iMsg),_pMessage(const_cast<ContainerMessage&>(iMsg)._pMessage.GiveBack()),_pCont(iMsg._pCont) {}

private :   
  CATOmxAutoPtr<TraceMessage> _pMessage;
  CATOmxSR<CATBaseUnknown> _pCont;
};


class ExportedByAC0XXLNK CATOmbXmlTraces : public CATOmsXmlTraces
{
public:
  CATOmbXmlTraces();
  ~CATOmbXmlTraces();

  static CATOmxSR<CATOmbXmlElement> GetOmbXmlTracer(const CATUnicodeString& iMessageTag,const CATUnicodeString& iMessageType, const TraceMessage& Message=InfoMessage(), int iLevel=0,const CATUnicodeString& iOwner="DEPRECATED" );  
  static CATOmxSR<CATOmbXmlElement> GetOmbXmlTracer(int increment, const CATUnicodeString& iMessageTag,const CATUnicodeString& iMessageType, const TraceMessage& Message=InfoMessage(), int iLevel=0,const CATUnicodeString& iOwner="DEPRECATED" );  
  static CATOmxSR<CATOmbXmlElement> GetOmbXmlTracer(int increment, const CATUnicodeString& iMessageTag,HRESULT iHR, const TraceMessage& Message=InfoMessage(), int iLevel=0,const CATUnicodeString& iOwner="DEPRECATED" );  

  /**
  /* Dumps the binary header bytes structure of a loaded stream.
  /* Dumps also the hierarchy structure skeleton in terms of containers
  /* Dump request is to be specified by the specific keyword STREAM_HEADER into the .conf file
  /* iMessageTag : the message tag referencing the traces associated to the dump into the resulting trace file
  /* ipILBStream : The CATILockBytes2 object handling the binary stream to be partially dumped
  */
  static HRESULT DumpStreamStructure(const CATUnicodeString& iMessageTag, CATILockBytes2 * ipILBStream);
  static HRESULT DumpAsCATIAStructure(const CATUnicodeString& iMessageTag, CATStorage* ipStorage, CATUnicodeString& iDumpFilePath, int NbLevels=0);
  static CATUnicodeString ReturnPhysicalIdFromComponentId(const CATComponentId& iCID);

private:

 static unsigned int _DumpFileDesc;
 static CATUnicodeString _StructureInfo;
 
};

#pragma warning(pop)

#endif


