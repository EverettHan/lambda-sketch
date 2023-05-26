#ifndef CATGPUSkinningServices_H
#define CATGPUSkinningServices_H
#include "CATSGUtil.h"

class VisPrimitiveGroupRep;
class VisRawBuffer;

class ExportedBySGInfra CATGPUSkinningServices
{
public:
  HRESULT AddSkeleton(VisPrimitiveGroupRep* iRep, VisRawBuffer* iBones, VisRawBuffer* iBonesWeight);
  HRESULT AddAnimation(VisPrimitiveGroupRep* iRep, VisRawBuffer* iBoneMatrices, unsigned int iNbBone = 0, VisRawBuffer* iPositionMatrices = NULL, unsigned int iNbInstance = 1);
  HRESULT RemoveAnimation(VisPrimitiveGroupRep* iRep);
  HRESULT RemoveSkeleton(VisPrimitiveGroupRep* iRep);
};

#endif // CATGPUSkinningServices_H
