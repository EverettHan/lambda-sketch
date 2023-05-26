#ifndef __CATIOmbIncrementalStreamAdapter_H
#define __CATIOmbIncrementalStreamAdapter_H 1

/**
 * @level Protected 
 * @usage U1
 */

#include "CATIOmbIncrementalStream.h"



class ExportedByAD0XXBAS CATIOmbIncrementalStreamAdapter: public CATIOmbIncrementalStream
{
  CATDeclareInterface;
public:
  CATIOmbIncrementalStreamAdapter(){}
  virtual ~CATIOmbIncrementalStreamAdapter(){}

  virtual HRESULT QueryContainerForIncrementalStream(const CATUuid& iLastStreamStamp,StreamMode& ioStreamMode,CATOmxOMap<CATOmxKeyString,CATOmxAny>& ioInfos);

  virtual HRESULT IncrementalContainerStream(const CATUuid& iNewStreamStamp,StreamMode iStreamMode,CATIOmxBinaryStream& iStream);

  virtual HRESULT IncrementalContainerUnstream(const CATUuid& iStreamStamp,CATIOmxBinaryStream& iStream,CATLONG64 iStreamLength,int iIndex,int iLastIndex);

  virtual HRESULT OnDocumentStreamCompleted(CATBoolean iRollbackNecessary);
};

#endif
