//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2018/07/17
//===================================================================

#ifndef CSICallbacks_H
#define CSICallbacks_H

#include "CSICommandBinderModule.h"

#include "CSIParameters.h"
#include "CATSysErrorDef.h"

#include <functional>

namespace CSI
{
class ExportedByCSIBinderModule OnSuccess
{
public:
  OnSuccess() = default;
  OnSuccess(std::function<HRESULT(const Parameters&)> onSuccess);

public:
  std::function<HRESULT(const Parameters&)> GetCallback() const;

private:
  std::function<HRESULT(const Parameters&)> onSuccess_ = nullptr;
};

class ExportedByCSIBinderModule OnError
{
public:
  OnError() = default;
  OnError(std::function<HRESULT(const Parameters&)> onError);

public:
  std::function<HRESULT(const Parameters&)> GetCallback() const;

private:
  std::function<HRESULT(const Parameters&)> onError_ = nullptr;
};

class ExportedByCSIBinderModule OnProgress
{
public:
  OnProgress() = default;
  OnProgress(std::function<HRESULT(const Parameters&)> onProgress);

public:
  std::function<HRESULT(const Parameters&)> GetCallback() const;

private:
  std::function<HRESULT(const Parameters&)> onProgress_ = nullptr;
};

class ExportedByCSIBinderModule Callbacks
{
public:
  Callbacks() = default;

  Callbacks(const OnSuccess& onSuccess);
  Callbacks(const OnProgress& onProgress);
  Callbacks(const OnError& onError);
  Callbacks(const OnSuccess& onSuccess, const OnError& onError);
  Callbacks(const OnSuccess& onSuccess, const OnError& onError, const OnProgress& onProgress);
  Callbacks(const OnSuccess& onSuccess, const OnProgress& onProgress);

public:
  std::function<HRESULT(const Parameters&)> GetOnSuccess() const;
  std::function<HRESULT(const Parameters&)> GetOnError() const;
  std::function<HRESULT(const Parameters&)> GetOnProgress() const;

private:
  OnSuccess onSuccess_;
  OnError onError_;
  OnProgress onProgress_;
};
}

#endif /*CSICallbacks_H*/
