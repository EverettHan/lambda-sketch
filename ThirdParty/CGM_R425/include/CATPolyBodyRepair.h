
#pragma once

#include "CATErrorDef.h"

// PolyhedralObjects
class CATPolyBody;
class CATPolyBodyNaryObserver;
class CATMathTransformation;
class CATProgressCallback;

// PolyhedralBodyOperators
#include "PolyBodyBoolean.h"

class ExportedByPolyBodyBoolean CATPolyBodyRepair
{
public:
  enum class Mode : unsigned int
  {
    eFromGeneralBodyToBodyReady = 0, // Generic workflow of healing
    eFromTesselationToBodyReady = 1 // Dedicated workflow of healing for data from tesselation
  };

public:

  template<Mode M>
  class Options;

  template<Mode M>
  CATPolyBodyRepair(const Options<M> & iOptions);

  ~CATPolyBodyRepair();

  void SetProgressCallback(CATProgressCallback * iProgress);
  HRESULT Run(const CATPolyBody & iBody,
              const CATMathTransformation * iTransfo = nullptr,
              CATPolyBodyNaryObserver * ioObserver = nullptr);

  HRESULT GetResult(CATPolyBody *& oResult);

private:
  class ImplItf
  {
  public:
    ImplItf() {};
    virtual ~ImplItf() {};

    virtual void SetProgressCallback(CATProgressCallback * iProgress) = 0;

    virtual HRESULT Run(const CATPolyBody & iBody,
                        const CATMathTransformation * iTransfo = nullptr,
                        CATPolyBodyNaryObserver * ioObserver = nullptr) = 0;

	// @param oResult
	// To be released with the <tt>Release</tt> method after use.
    virtual HRESULT GetResult(CATPolyBody *& oResult) = 0;
  };

  template<Mode M>
  class Impl;
  
  ImplItf * _ope;
};
