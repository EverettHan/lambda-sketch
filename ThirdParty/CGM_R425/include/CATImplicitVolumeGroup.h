#ifndef CATImplicitVolumeGroup_h
#define CATImplicitVolumeGroup_h

// Export
#include "GMScalarFieldsObjects.h"

// STD
#include <iostream>
#include <memory>
#include <vector>

// Sys
#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"

// CGM
#include "CATCGMSharedPtr.h"
#include "CATCGMStreamAttribute.h"

class CATVolume;
class CATGeoImplicitSurface;

class CATImplicitBody;

class ExportedByGMScalarFieldsObjects CATImplicitVolumeGroup : public CATCGMStreamAttribute
{
  CATCGMDeclareAttribute(CATImplicitVolumeGroup, CATCGMStreamAttribute);

  public:
    CATImplicitVolumeGroup();
    virtual ~CATImplicitVolumeGroup();
    
    typedef CATCGMSharedPtr<CATImplicitVolumeGroup>      Ptr;
    typedef std::vector<CATImplicitVolumeGroup*>         RawPtrs;
    typedef std::vector<CATImplicitVolumeGroup::Ptr>     Ptrs;

    CATBoolean SetImplicitSurface(CATGeoImplicitSurface* iImplicitSurface);
    CATGeoImplicitSurface* GetImplicitSurface();

    virtual int IsClonableAttribute();
    virtual void Stream(CATCGMStream &ioStream) const;
    virtual void UnStream(CATCGMStream &ioStream);

    static CATBoolean NeedToSaveAttr(const short& iSoftwareLevel);

    HRESULT RemoveVolume(CATVolume* iVolume);
    HRESULT AddVolume(CATVolume* iVolume);
    const int GetVolumeCount();
    CATVolume* GetVolume(const int iVolumeIndex);

    void              SetImplicitBody(CATImplicitBody* iImplicitBodyOwner);
    CATImplicitBody*  GetImplicitBody();
    
  private:
    HRESULT     CreateAssociation(CATVolume* iVolume, CATGeoImplicitSurface* iImplicitSurface);
    CATBoolean  IsAssociationInPlace(CATVolume* iVolume, CATGeoImplicitSurface* iImplicitSurface);
    HRESULT     RemoveAssociation(CATVolume* iVolume, CATGeoImplicitSurface* iImplicitSurface);

    unsigned short                          _version;


    CATImplicitBody*                        _implicitBody;
    CATGeoImplicitSurface*                  _implicitSurface;
    bool                                    _attrOnVolumes;
    bool                                    _attrOnImplicitGeometry;
};


#endif
