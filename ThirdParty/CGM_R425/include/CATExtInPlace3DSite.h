#ifndef __CATExtInPlace3DSite_h
#define __CATExtInPlace3DSite_h

// COPYRIGHT DASSAULT SYSTEMES 2000


#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"
#include "CATInPlace3DSite.h"
#include "CATMathTransformation.h"


class ExportedByCATAfrFoundation CATExtInPlace3DSite : public CATBaseUnknown {
 
  CATDeclareClass;

public:

  CATExtInPlace3DSite();
  virtual ~CATExtInPlace3DSite ();

  virtual HRESULT   GetModelMatrix      (CATMathTransformation *);

  virtual HRESULT   GetLocalTransfo     (CATMathTransformation * oTransfo,
                                         CATBaseUnknown        * iFatherSite);

  virtual HRESULT   ComputeModelMatrix  (CATInPlace3DSite      * iFatherSite);

  virtual HRESULT   CanDrawBoundingBox  (CATBaseUnknown        * iActiveObject);

protected:

  CATMathTransformation     _modelMatrix;

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATExtInPlace3DSite (const CATExtInPlace3DSite &);
  CATExtInPlace3DSite & operator= (const CATExtInPlace3DSite &);
};

#endif//__CATExtInPlace3DSite_h
