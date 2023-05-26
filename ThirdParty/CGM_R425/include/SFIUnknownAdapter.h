#ifndef SFIUnknownAdapter_h
#define SFIUnknownAdapter_h

// System
#include "IUnknown.h"

// Mathematics
#include "CATMathPoint.h"

// ScalarFields
#include "ScalarFields.h"
#include "ScalarFieldUtils.h"
#include "SFTypes.h"
#include "SFSWContext.h"

// STD
#include <atomic>
#include <iostream>
#include <memory>
#include <vector>

namespace SF
{
  template<typename T>
  class SFIUnknownAdapter : public IUnknown, public T
  {
  public:
    SFIUnknownAdapter() : _refCount(0)
      {
      }

    SFIUnknownAdapter(const SFSWContext& iCtx) : T(iCtx), _refCount(0)
      {
      }

    virtual ~SFIUnknownAdapter()
      {
      }

    virtual ULONG __stdcall AddRef()
      {
        return _refCount.fetch_add(1) + 1;
      }

    virtual ULONG __stdcall Release()
      {
        CATINT32 rc = _refCount.fetch_sub(1) - 1;
        if (rc <= 0)
        {
          delete this;
        }
        return rc;
      }

    virtual HRESULT __stdcall QueryInterface(const IID &iIID, void **oPPV)
      {
        HRESULT hr = E_FAIL;

        if(SF::GUIDCmp(iIID, GetIID(this))==0) {
          *oPPV = this;
          hr = S_OK;
        }

        return hr;
      }

  private:
    std::atomic<CATINT32>               _refCount;
  };
};

#endif // SFIUnknownAdapter_h
