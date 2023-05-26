#ifndef __CATOmxStructDescriptionBuilder_H
#define __CATOmxStructDescriptionBuilder_H

// ObjectModelerCollection
#include "CATOmxAny.h"
#include "CATOmxCollectionType.h"
#include "CATOmxKernel.h"
#include "CATOmxKeyString.h"
#include "CATOmxKind.h"
#include "CATOmxOrderedSet.h"
#include "CATOmxSR.h"

class CATOmxStructDescription;
class CATOmxStructDescriptionInternal;
class CATOmxStructDescriptionAttribute;
class CATOmxStructDescriptionAttributeInternal;
template<>
CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmxStructDescriptionAttributeInternal*>::manager();

#define OMX_NO_CONVERSION            0x0 
#define OMX_LOWER_HEX_STRING_AS_UUID 0x1
#define OMX_UPPER_HEX_STRING_AS_UUID 0x2

/**
 * Description of an attribute (@see CATOmxStructDescriptionBuilder::AddAttribute)
 */
class CATOmxStructDescriptionAttributeBuilder
{
public:
  /**
   * Declaration of mandatory fields.
   * Note for iExtendedKind:
   * Kind will initialized with the same value as iExtendedKind except for
   *  iExtendedKind=omx_time => Kind=omx_int64) 
   *  iExtendedKind=omx_enum => Kind=omx_IUnknown
   */
  ExportedByCATOmxKernel CATOmxStructDescriptionAttributeBuilder(const CATOmxKeyString& iName,CATOmxCollectionType iCollectionType,CATOmxKind iExtendedKind);

  CATOmxKeyString Name;
  CATOmxCollectionType CollectionType;
  CATOmxKind Kind;
  CATOmxKind ExtendedKind;
  //apply global sharing on the string
  unsigned int ShareValues:1;
  //use a specific storage representation (OMX_LOWER_HEX_STRING_AS_UUID, OMX_UPPER_HEX_STRING_AS_UUID)
  unsigned int StorageConversion:2;
  void* m_padding[3];
};

/**
 * This class allows to create CATOmxStructDescription objects
 */
class ExportedByCATOmxKernel CATOmxStructDescriptionBuilder
{
  CATOmxKeyString m_namespace;
  CATOmxKeyString m_name;
  CATOmxSR<CATOmxStructDescriptionInternal> m_parent;
  CATOmxOrderedSet<CATOmxStructDescriptionAttributeInternal> m_attributes;
public:
  CATOmxStructDescriptionBuilder(const CATOmxKeyString& iNamespace,const CATOmxKeyString& iName,const CATOmxStructDescription* iParent = NULL);

  HRESULT AddAttribute(const CATOmxStructDescriptionAttributeBuilder& iAttribute);

  CATOmxSR<CATOmxStructDescription> BuildDescription();
};

#endif
