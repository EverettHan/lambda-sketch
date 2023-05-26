#ifndef CATImplicitBody_h
#define CATImplicitBody_h

// Export
#include "GMScalarFieldsObjects.h"

// Sys
#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"

// CGM
#include "CATCGMStreamAttribute.h"

// GMScalarFields
#include "CATImplicitVolumeGroup.h"

class CATBody;

class ExportedByGMScalarFieldsObjects CATImplicitBody : public CATCGMStreamAttribute
{
  CATCGMDeclareAttribute(CATImplicitBody, CATCGMStreamAttribute);

  public:

    CATImplicitBody();
    virtual ~CATImplicitBody();

    virtual int IsClonableAttribute();
    virtual void Stream(CATCGMStream &ioStream) const;
    virtual void UnStream(CATCGMStream &ioStream);

    static CATBoolean NeedToSaveAttr(const short& iSoftwareLevel);

    static HRESULT CreateImplicitBody(CATBody& iBody, CATImplicitBody*& oImplicitBody);
    static CATImplicitBody* GetImplicitBody(CATBody& iBody);

    HRESULT AddImplicitVolumeGroup(CATImplicitVolumeGroup* iImplicitVolumeGroup);
    HRESULT RemoveImplicitVolumeGroup(CATImplicitVolumeGroup* iImplicitVolumeGroup);
    const int GetVolumeGroupsCount() const;
    CATImplicitVolumeGroup* GetVolumeGroupByIndex(const int iVolumeGroupIndex);

  private:
    unsigned short                    _version;
    CATImplicitVolumeGroup::Ptrs      _volumeGroups;

    HRESULT CreateAssociation(CATImplicitVolumeGroup* iImplicitVolumeGroup);
    HRESULT RemoveAssociation(CATImplicitVolumeGroup* iImplicitVolumeGroup);
};
#endif
  
