/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2003
#ifndef CATDocumentPersistancyServices_H
#define CATDocumentPersistancyServices_H


/**
 * @level Private
 * @usage U1
 */

#include "AC0XXLNK.h"

#include "CATFile.h"
class CATIOmxBinaryStream;

class ExportedByAC0XXLNK CATDocumentPersistancyServices
{
 friend class CATPartCGRVisuAccess ;
 friend class OMBStreamAsStorageTest ;
 friend class CATOmbInternalDocCompositeServices;
 // BHG, for Document Debug Tool. (See composite structure in a storage graph).
 friend class CATOmbDebugStgServices;

 private:

  static HRESULT UseStreamAsAStorageWithModeAndCopyMode(CATStream& iStream,CATStorage*& oStorage,DWORD Open_Mode,int iCopy=1);
  static HRESULT UseStreamAsAStorageWithModeAndCopyMode(CATIOmxBinaryStream& iStream, CATStorage*& oStorage, DWORD Open_Mode, int iCopy = 1);
  
};
#endif
