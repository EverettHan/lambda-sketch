#ifndef CATCompDrawInformations_H
#define CATCompDrawInformations_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGComposite.h"
#include "CATSGCompositeHost.h"
#include "CATCompositeTPtr.h"

class CATRep;
class vDrawInformation;
class vDrawableData;
class CAT4x4Matrix;

template <>
struct NAT<vDrawInformation*>
{
    static vDrawInformation* value()
    {
        return NULL;
    }
};

class ExportedBySGComposites CATCompDrawInformations : public CATSGComposite
{
public:
    struct BatchingParameters
    {
        BatchingParameters();
        unsigned int m_NumLODClasses;
        unsigned int m_MaxBufferSize;
        bool         m_ApplyTransforms;
        bool         m_KeepPolyLOD;
    };

    virtual ~CATCompDrawInformations() {}

    virtual HRESULT   AddVDrawInformation(vDrawInformation *iVDrawInfo, CAT4x4Matrix const &iMat, CAT3DBoundingSphere const &iBE) = 0;
    virtual HRESULT   SetVDrawInformation(unsigned int iNumGeom, vDrawInformation *iVDrawInfo) = 0;
    virtual HRESULT   GetVDrawInformation(unsigned int iNumGeom, vDrawInformation *&oVDrawInfo) const = 0;
    virtual void      ClearVDrawInformations() = 0;
    virtual unsigned int GetNumSubGeom() const = 0;
    virtual vDrawableData *GetIDrawableData() const = 0;
    virtual void SetIDrawableData(vDrawableData *) = 0;
    virtual BatchingParameters const *GetBatchingParameters() const = 0;

    virtual CAT4x4Matrix const *GetMatrixList() const = 0;
    virtual CAT3DBoundingSphere const *GetBoundingElementsList() const = 0;

protected:
};

// {6CF6CCE2-AAB7-4C8D-8303-CE63A09B5663}
static const IID GUID_CATCompDrawInformationsTrait =
{ 0x6cf6cce2, 0xaab7, 0x4c8d, { 0x83, 0x3, 0xce, 0x63, 0xa0, 0x9b, 0x56, 0x63 } };

template<>
class CATTraitInfo<CATCompDrawInformations>
{
public:
    static const GUID&             GetTraitGUID()
    {
        return GUID_CATCompDrawInformationsTrait;
    }
    static const int            GetTraitTag() {
        return CATECompositeTagDrawInformation;
    }
    static const CATECompositionMode    GetCompositeMode()
    {
        return CATECompositionModeExclusive;
    }
    static const CATTraitRawInfo         GetRaw()
    {
        DefaultGetRawImplementation;
    }
};

typedef CATCompositeTWeakPtr<CATCompDrawInformations>       CATCompDrawInformationsWeakPtr;
typedef CATCompositeTPtr<CATCompDrawInformations>           CATCompDrawInformationsPtr;
typedef CATOnStackBorrowPtr<CATCompDrawInformations>        CATCompDrawInformationsBorrowPtr;

class ExportedBySGComposites CATCompDrawInformationsImpl : public CATSGCompositeHost1NoListeners<CATCompDrawInformations, CATSGComposite>
{
 public:
    CATCompDrawInformationsImpl();
    virtual ~CATCompDrawInformationsImpl();
    HRESULT  AddVDrawInformation(vDrawInformation* iVDrawInfo, CAT4x4Matrix const& iMat, CAT3DBoundingSphere const& iRadius);
    HRESULT  SetVDrawInformation(unsigned int iNumGeom, vDrawInformation* iVDrawInfo);
    HRESULT  GetVDrawInformation(unsigned int iNumGeom, vDrawInformation*& oVDrawInfo) const;
    unsigned int GetNumSubGeom() const;
    void     ClearVDrawInformations();
    vDrawableData* GetIDrawableData() const;
    void SetIDrawableData(vDrawableData*);
    BatchingParameters const* GetBatchingParameters() const{return &m_BatchParams;}
    inline BatchingParameters& GetBatchingParameters() {return m_BatchParams;}

    CAT4x4Matrix const*        GetMatrixList() const;
    CAT3DBoundingSphere const* GetBoundingElementsList() const;

    unsigned int GetSizeInBytes(const int iIncludeStructuralSize = 1);

 private:
    std::vector<vDrawInformation*>   m_DI;
    std::vector<CAT4x4Matrix>        m_Matrices;
    std::vector<CAT3DBoundingSphere> m_BE;
    vDrawableData*                   m_IDrawableData;
    BatchingParameters               m_BatchParams;
};

class ExportedBySGComposites CATCompDrawInformationSingle : public CATSGCompositeHost1NoListeners<CATCompDrawInformations, CATSGComposite>
{
 public:
    CATCompDrawInformationSingle();
    virtual ~CATCompDrawInformationSingle();
    HRESULT  AddVDrawInformation(vDrawInformation* iVDrawInfo, CAT4x4Matrix const& iMat, CAT3DBoundingSphere const& iRadius);
    HRESULT  SetVDrawInformation(unsigned int iNumGeom, vDrawInformation* iVDrawInfo);
    HRESULT  GetVDrawInformation(unsigned int iNumGeom, vDrawInformation*& oVDrawInfo) const;
    unsigned int GetNumSubGeom() const;
    void     ClearVDrawInformations();
    vDrawableData* GetIDrawableData() const;
    void SetIDrawableData(vDrawableData*);
    BatchingParameters const* GetBatchingParameters() const {return NULL;}

    CAT4x4Matrix const*        GetMatrixList() const;
    CAT3DBoundingSphere const* GetBoundingElementsList() const;

    unsigned int GetSizeInBytes(const int iIncludeStructuralSize = 1);

 private:
   vDrawInformation*   m_DI;
   //CAT4x4Matrix        m_Matrices;
   CAT3DBoundingSphere m_BE;
   vDrawableData*     m_IDrawableData;
};
#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompDrawInformations_H
