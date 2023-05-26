#ifndef CATVisPLMRenderingStyleData_H
#define CATVisPLMRenderingStyleData_H

// COPYRIGHT DASSAULT SYSTEMES 2005

#include "SGInfra.h"

#include "CATGraphicAttributeSet.h"

class CATGraphicMaterial;
class ExportedBySGInfra CATVisPLMRenderingStyleData
{
public:
    CATVisPLMRenderingStyleData();
    CATVisPLMRenderingStyleData(CATGraphicMaterial* iMat, 
					const CATGraphicAttributeSet& iAtt,
                    int iEdgeVisibility = 0, 
                    int iFilter = 0);
    ~CATVisPLMRenderingStyleData();
    CATVisPLMRenderingStyleData(const CATVisPLMRenderingStyleData& iValue);
    CATVisPLMRenderingStyleData& operator= (const CATVisPLMRenderingStyleData& iValue);

    void SetMeshMaterial(CATGraphicMaterial* iMat);
    inline CATGraphicMaterial* GetMeshMaterial() const;
    
    void SetEdgeAtt(const CATGraphicAttributeSet& iAtt);
    inline const CATGraphicAttributeSet& GetEdgeAtt() const;

    void SetEdgeVisibility(int iOnOff);
    inline int GetEdgeVisibility() const;

    void SetFilterMode(int iOnOff);
    inline int GetFilterMode() const;

private :
    CATGraphicMaterial* _meshMat; 
	CATGraphicAttributeSet _edgeAtt;
    unsigned int _edgeVisibility : 1; 
    unsigned int _filtered  : 1;

};


inline CATGraphicMaterial* CATVisPLMRenderingStyleData::GetMeshMaterial() const
{
    return _meshMat;
}

inline const CATGraphicAttributeSet& CATVisPLMRenderingStyleData::GetEdgeAtt() const
{
    return _edgeAtt;
}

inline int CATVisPLMRenderingStyleData::GetEdgeVisibility() const
{
    return _edgeVisibility;
}

inline int CATVisPLMRenderingStyleData::GetFilterMode() const
{
    return _filtered;
}

#endif
