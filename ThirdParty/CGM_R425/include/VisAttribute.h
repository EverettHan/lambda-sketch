#ifndef VisAttribute_H
#define VisAttribute_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "SGInfra.h"

#include "VisSGAttribute.h"
#include "VisDataType.h"
#include "VisAttributeID.h"
#include "IUnknown.h"
#include <stdlib.h>

class CATGraphicAttributeSet;
class CAT4x4Matrix;

namespace Vis {
  class AttributeCSIStreamer;
  class CSIVisAttributeCSIStreamer;
  class CSIVisAttribute_Impl;
}

class ExportedBySGInfra VisAttribute : public VisSGAttribute
{
  friend class VisPrimitiveGroupRep;
  friend class Vis3DNodeGroupRep;
  friend class CATSGV6Attribute;
  friend class Vis::AttributeCSIStreamer;
  friend class Vis::CSIVisAttribute_Impl;
  friend class Vis::CSIVisAttributeCSIStreamer;
  friend class CSISceneGraphObserverVisRawBufferSuscriber;

public:

   // Constructor
  VisAttribute();
 
  virtual HRESULT GetValue(const VisAttributeID iAttributeID, const VisDataType iType, void *oValue) const;
  
  virtual HRESULT SetValue(const VisAttributeID iAttributeID, const VisDataType iType, void *iValue);

  ULONG __stdcall AddRef();

  ULONG __stdcall Release();

  // If GAS is not alaready set, GetGAS creates and sets it to default
  const CATGraphicAttributeSet* GetGAS();
  void SetGAS(CATGraphicAttributeSet iGAS);

protected:

  virtual ~VisAttribute();
  unsigned int GetArrayLength() const;
  unsigned int GetArrayIndice(unsigned int mask) const;
  unsigned int GetMaskFromArrayIndice(unsigned int indice) const;
  void AddAttributeArray(unsigned int mask, void *obj);
  void GetAttributeArray(unsigned int mask, void * & obj) const;
  const CAT4x4Matrix* GetTextureMatrix();

  unsigned int _uiRefCounter;
  unsigned int _attributeFlag;
  void **_pAttributeArray;

private:

  VisAttribute(const VisAttribute&);
  VisAttribute & operator=(const VisAttribute&);

  CATGraphicAttributeSet* _GetGAS();
};

#endif // VisAttribute_H
