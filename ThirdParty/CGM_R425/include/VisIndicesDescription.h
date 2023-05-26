#ifndef VISINDICESDESCRIPTION_H
#define VISINDICESDESCRIPTION_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "VisCore.h"

#include "IUnknown.h"

#include "VisDataType.h"

#include "CATSysErrorDef.h"

class VisRawBuffer;

class ExportedByVisCore VisIndicesDescription : public IUnknown
{
public:

  /**
   * Destructor.
   */
  virtual ~VisIndicesDescription();

  virtual HRESULT SetIndices( VisRawBuffer* ipRawBuffer,
                              VisSize iNbIndices,
                              VisDataType iDataFormat = VIS_UNSIGNED_INT,
                              VisSize iOffset = 0) = 0;

  virtual HRESULT GetIndices( VisRawBuffer*& opRawBuffer,
                              VisSize& oNbIndices,
                              VisDataType& oDataFormat,
                              VisSize& oOffset) = 0;
protected:

  /**
   * Builds an empty indices description.
   */
  VisIndicesDescription();

private:

  VisIndicesDescription(const VisIndicesDescription&);
  VisIndicesDescription & operator=(const VisIndicesDescription&);

};

#endif // VISINDICESDESCRIPTION_H
