#ifndef CAT3DXMReader_H_
#define CAT3DXMReader_H_

#include <sys/types.h>
#include <vector>
#include "CAT3DXM.h"
#include "CATExportTo3DXM.h"
#include <memory>


class CATRep;
class CATUnicodeString;
class CATVisAmbiance;
class CAT3DViewpoint;
class CAT2DViewpoint;
class CAT3DLightSourceRep;
class CATVisPostEffects; // Added in 3.2 PostEffects 3DXM ++ --
class l_Vis3DXMReader;
class VisJSONValue;

class ExportedByCAT3DXM CAT3DXMReader
{
public:

  // Default 3DXM reader ctor
  CAT3DXMReader();
  ~CAT3DXMReader();

  // Opens the archive/concatenated 3DXM file (*.3dx|*.3dxc) given by filename
  CAT3DXMReader(const char* name, CATRep*& root);

  bool Open(const char* name, CATRep*& root);

  bool Open(CATUnicodeString* fileNames, char** ppFileBuffer, size_t* pFilesSize, unsigned int nbFiles, CATRep*& root);

  bool Open(char* pFileBuffer, size_t filesSize, CATRep*& root);

  bool Open(const char* name, CATRep*& root, CATVisAmbiance*& ambiance, CAT3DViewpoint*& camera);

  bool Open(const char* name, CATRep*& root, CATVisAmbiance*& ambiance, CAT3DViewpoint*& camera, CATVisPostEffects*& oPostEffect);
  // Added in 3.2 PostEffects 3DXM --

  bool Open(CATUnicodeString* fileNames, char** ppFileBuffer, size_t* pFilesSize, unsigned int nbFiles, CATRep*& root, CATVisAmbiance*& ambiance, CAT3DViewpoint*& camera);

  // Opens the concatenated 3DXM file (*.3dxc) given by file buffer
  // pFileBuffer is untouched, caller is responsible for deleting this object
  bool Open(char* pFileBuffer, size_t filesSize, CATRep*& root, CATVisAmbiance*& ambiance, CAT3DViewpoint*& camera);

  bool LoadLight(const char* iPath, std::vector<CAT3DLightSourceRep*>& oLights);
  bool LoadLight(std::vector<CAT3DLightSourceRep*>& oLights, const CATUnicodeString& iLightString);
  bool LoadLight(std::vector<CAT3DLightSourceRep*>& oLights, const VisJSONValue& iLightJSON );

  bool LoadCamera(const char* iPath, std::vector<CAT3DViewpoint*>& oViewPoints);
  bool LoadCamera(std::vector<CAT3DViewpoint*>& oViewPoints, const CATUnicodeString& iCameraString);
  bool LoadCamera(std::vector<CAT3DViewpoint*>& oViewPoints, const VisJSONValue& iCameraJSON);

  bool LoadCamera(std::vector<CAT2DViewpoint*>& oViewPoints, const CATUnicodeString& iCameraString);
  bool LoadCamera(std::vector<CAT2DViewpoint*>& oViewPoints, const VisJSONValue& iCameraJSON);

  bool LoadTexture(std::vector<IVisTexturePtr>& oTexture, const CATUnicodeString& iString, const std::vector<CATExportTo3DXM::BinaryBuffer>& iBuffers);

  bool LoadMaterials(std::vector<CATMaterialApplication*>& oMatApp, const CATUnicodeString& iString, const std::vector<CATExportTo3DXM::BinaryBuffer>& iBuffers);

  CATI3DXMHandler* GetObserver() const;
  bool RegisterCallBack(CATI3DXMHandler& cb);
  bool DeregisterCallBack(CATI3DXMHandler& cb);

protected:
  void SetAmbiance(CATVisAmbiance* iAmbiance);
  void SetViewpoint(CAT3DViewpoint* iViewpoint);
  // Opens the concatenated 3DXM file (*.3dxc)
  bool OpenC(const char* name, CATRep*& root);
private:
  CAT3DXMReader(const CAT3DXMReader&);
  const CAT3DXMReader& operator = (const CAT3DXMReader&);
  bool OpenFile(const char* name, CATRep*& root, CATUnicodeString*& fileNames, char**& ppFileBuffer, size_t*& pFilesSize, unsigned int& nbFiles);

protected:
  CATVisAmbiance* m_pAmbiance;
  CAT3DViewpoint* m_pVp;
  CATVisPostEffects* m_pPostEffect; // Added in 3.2 PostEffects 3DXM ++ --
  CATI3DXMHandler* m_pObserver;
};


#endif
