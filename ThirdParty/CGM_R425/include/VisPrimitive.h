#ifndef VisPrimitive_H
#define VisPrimitive_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "SGInfra.h"

#include "IUnknown.h"
#include "VisDataType.h"
#include "VisConnectivityType.h"
#include <stdio.h>

class VisVerticesDescription;
class VisIndicesDescription;
class CATRender;
class CATViewpoint;
class CAT3DViewpoint;
class CATViewport;
class CAT3DViewport;
class VisComputeDrawIndirect;
class VisRawBuffer;

//++ SGCAAPlan
#include "CATVisMacroForInterfaces.h"
class IVisSGCustomPrimitive;
class VisSGPrimitiveItem;
class VisPrimitiveIVisSGPrimitiveBOAImpl;
//-- SGCAAPlan



typedef struct _IndicesDescriptionAndConnectivityType
{
  VisIndicesDescription *indices;
  VisConnectivityType type;
} VisIndicesDescriptionAndConnectivityType;

class ExportedBySGInfra VisPrimitive : public IUnknown
{
  /** @nodoc */
 // CATDeclareClass;
  friend class CATCacheOfDestroyedElements;

public:

  //++ SGCAAPlan
  /** @nodoc */
  CATVisDeclarePublicInterfaceAdhesion(VisPrimitive, IVisSGCustomPrimitive, VisPrimitiveIVisSGPrimitiveBOAImpl);

  HRESULT StartIteration(void*& ioContext, VisConnectivityType handledPrimitiveItemTypes);
  HRESULT GetNext(void*& ioContext, VisSGPrimitiveItem * & oItem);
  HRESULT EndIteration(void*& ioContext);
  unsigned int GetId();
  //-- SGCAAPlan

  VisPrimitive();

  HRESULT GetVerticesDescription(VisVerticesDescription*& opDescription);
  HRESULT SetVerticesDescription(VisVerticesDescription* ipDescription);

  HRESULT GetNumberOfIndicesDescription(VisSize& oNbIndicesDescription);
  HRESULT RetrieveIndicesDescription(VisSize iIndex, VisIndicesDescription*& opDescription, VisConnectivityType& oConnectivityType);
  HRESULT StoreIndicesDescription(VisIndicesDescription* ipDescription, VisConnectivityType iConnectivityType);

  int DetailCulling(CATRender *iRender);
  void Empty();
  void ResetDLs();
  void Destroy();
  ULONG __stdcall AddRef();
  ULONG __stdcall Release();
  virtual void Draw(CATRender &iRender);
  virtual void AddToGPGPU(CATRender &iRender);
  virtual void ImmediateDraw(CATRender &iRender);

  inline unsigned int GetStorageID() const;
  inline void SetStorageID(unsigned int iStorageID);

  inline unsigned int GetLastVersionID() const;
  inline void SetVersionID(unsigned int iVersionID);
  
  struct DrawIndirectInfo
  {
    unsigned int   drawCount; ///< Is used in the multiDraw call. It represents the number of different objects.
    VisRawBuffer * buffer;    ///< The indirect buffer.
  };

  /** Return informations in case of DrawIndirect use.
   *  Only for internal use.
   *  @return NULL if no DrawIndirect else a filled structure.
   */
  virtual const DrawIndirectInfo * GetDrawIndirectInfo () const;
  
  enum VizGeomType
  {
    Regular,
    GPGPU
  };

  virtual VizGeomType GetGeomType() const;
protected:

  virtual ~VisPrimitive();

  VisVerticesDescription* _pVerticesDescription;
  VisIndicesDescriptionAndConnectivityType* _pIndicesDescriptionAndConnectivityTypes;
  
  unsigned int _nbVisIndicesDescriptionAndConnectivityType;
  unsigned int _uiRefCounter;

  unsigned int _storageID;
  unsigned int _versionID;
};

inline unsigned int VisPrimitive::GetStorageID() const
{
  return _storageID;
}

inline void VisPrimitive::SetStorageID(unsigned int iStorageID)
{
  _storageID = iStorageID;
}

inline unsigned int VisPrimitive::GetLastVersionID() const
{
  return _versionID;
}

inline void VisPrimitive::SetVersionID(unsigned int iVersionID)
{
  _versionID = iVersionID;
}

#endif // VisPrimitive_H
