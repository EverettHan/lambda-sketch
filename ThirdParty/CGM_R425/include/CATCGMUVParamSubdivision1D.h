#ifndef CATCGMUVParamSubdivision1D_H
#define CATCGMUVParamSubdivision1D_H

#include "ExportedByTessellateCommon.h"
#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATListOfDouble.h"

class CATEdge;

class ExportedByTessellateCommon CATCGMUVParamSubdivision1D
{
public:
  inline CATCGMUVParamSubdivision1D();
  inline ~CATCGMUVParamSubdivision1D();
  inline void Reset();


public:
  ////////////////////////////////////
  // Query (read-only) methods
  ////////////////////////////////////

  inline const unsigned char* GetBuffer() const;
  inline CATULONG32 GetBufferSize() const;

  HRESULT GetLocalParams(CATEdge& iEdge, CATListOfDouble& oLocalParams) const;

  
public:

  ////////////////////////////////////
  // Allocation methods
  ////////////////////////////////////

  // For allocation, either use "Set" or "Allocate" method, whichever convenient

  // Sets buffer to the given memory pointer, 
  // which should to be pre-alloacted on heap by caller.
  // ioBuffer will be set to NULL by this method, which is to indicate
  // the memory will now belong to this class, which can be 
  // accessed using "GetBuffer" method.
  void Set(CATULONG32 iBufferSize, unsigned char*& ioBuffer);

  // allocates buffer memory (owned by class)
  HRESULT Allocate(CATULONG32 iBufferSize);

  void GiveAwayOwnership(CATULONG32& oBufferSize, unsigned char*& ioBuffer);

public:

  ////////////////////////////////////
  // Modification methods
  ////////////////////////////////////

  // access to allocated buffer
  inline unsigned char* GetBuffer_ForUpdate();

  virtual HRESULT CopyFrom(const CATCGMUVParamSubdivision1D& iFrom);
  virtual HRESULT CopyFrom(CATULONG32 iBufferSize, const unsigned char* iBuffer);


protected:
  CATULONG32 _BufferSize;
  unsigned char* _Buffer;
};

inline 
CATCGMUVParamSubdivision1D::CATCGMUVParamSubdivision1D()
{
  _BufferSize = 0;
  _Buffer = 0;
}

inline 
CATCGMUVParamSubdivision1D::~CATCGMUVParamSubdivision1D()
{
  Reset();
}

inline const unsigned char* 
CATCGMUVParamSubdivision1D::GetBuffer() const
{
  return _Buffer;
}

inline CATULONG32 
CATCGMUVParamSubdivision1D::GetBufferSize() const
{
  return _BufferSize;
}

inline unsigned char* 
CATCGMUVParamSubdivision1D::GetBuffer_ForUpdate()
{
  return _Buffer;
}

inline void
CATCGMUVParamSubdivision1D::Reset()
{
  _BufferSize = 0;
  delete [] _Buffer; _Buffer = 0;
}

#endif 

