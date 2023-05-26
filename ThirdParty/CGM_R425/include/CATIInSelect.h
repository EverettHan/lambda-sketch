#ifndef CATIInSelect_h
#define CATIInSelect_h

// COPYRIGHT DASSAULT SYSTEMES 2000
// Grégoire : à quoi sert cette interface ?

#include <UIModelInterfaces.h>
#include <CATBaseUnknown.h>

class CATFrmEditor;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIInSelect;
#else
extern "C" const IID IID_CATIInSelect;
#endif

class ExportedByUIModelInterfaces CATIInSelect : public CATBaseUnknown
{
  CATDeclareInterface;
  
public:
  
  virtual void InitSelect() = 0;
  virtual void ResetSelect() = 0;
  virtual void InitSelect(CATFrmEditor * iEditor) = 0;
  virtual void ResetSelect(CATFrmEditor * iEditor) = 0;
};

CATDeclareHandler(CATIInSelect, CATBaseUnknown);

#endif
