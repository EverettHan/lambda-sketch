#ifndef CATExportTo3DXM_H_
#define CATExportTo3DXM_H_

#include "CAT3DXM.h"
#include "CATErrorDef.h"
#include "CATUnicodeString.h"
#include "IVisTexturePtr.h"
#include "VisUnitApi.h"
#include <vector>
#include <memory>

class CATRep;
class CATSupport;
class VisJSONValue;
class CATPixelImage;
class CATVisAmbiance;
class CATMaterialApplication;
class CAT3DViewpoint;
class CAT2DViewpoint;

struct ExportedByCAT3DXM CAT3DXMExportSettings
{
  CAT3DXMExportSettings();
  size_t m_DefaultBinarySize;
  bool m_Batch;
  bool m_Archive;               // If true -> 3dx will be exported, false -> 3dxc will be exported
  bool m_CompressVertices;      // Default: false
  bool m_CompressNormals;       // Default: false
  float m_Version;              // Default: 3.2
  bool m_ExportPreIbl;          // Default: false
  unsigned int m_PreIblSppLamb; // Number of samples per pixel to be calculated during preconvolved IBL export for the Lambert distribution (diffuse)
  unsigned int m_PreIblSppGgx;  // Number of samples per pixel to be calculated during preconvolved IBL export for the GGX distribution (specular)

  vis::unit::ImageExportSettings m_ImageExportSettings;
};

class CATI3DXMHandler;

// Base class for all 3DXM Notification
class CATI3DXMNotification
{
};

// 3DXM Image notifications
class CAT3DXMImageNotification : public CATI3DXMNotification
{
public:
  CATUnicodeString m_DirPath;         // If client wants to blob the image at their desired location, they should set this path. If NULL string, exporter will export images in BinaryBuffer
  IVisTexturePtr m_pTexture;          // Either m_pTexture or m_pPixelImage, the texture for which client being called
  const CATPixelImage *m_pPixelImage; // Either m_pTexture or m_pPixelImage, the texture for which client being called
  CATUnicodeString m_TextureName;     // ++ V2E : Texture name as requested

  bool forceJPGExport = false; // Overrides JPG as the default export format for LDR images

  unsigned int m_Uid = 0;
  bool m_IsInCache = false;
  CAT3DXMImageNotification();

  bool useExternalImage() const
  {
    return !m_DirPath.IsNull();
  }
};

struct ExportedByCAT3DXM CAT3DXMTextureNotification
{
  CATUnicodeString m_Name;
  int m_ByteOffset;
  int m_ByteLength;
  bool m_Transparent;
  IVisTexturePtr m_Texture;
};

class ExportedByCAT3DXM CATExportTo3DXM
{
public:
  CATExportTo3DXM();
  ~CATExportTo3DXM();
  struct BinaryBuffer
  {
    void *m_Data = nullptr;
    size_t m_Size = 0;
    CATUnicodeString m_Name;
  };

  /** Unit API for materials
   * If client wants to export the image at their desired location, they should derive their own handlder from CATI3DXMHandler, call RegisterCallBack()
   * In case of success, caller is responsible for freeing(with free) the buffer data contained in BinaryBuffer(m_Data)
   */
  HRESULT ExportMaterials(std::vector<CATMaterialApplication *> matList, CATUnicodeString &oJson, std::vector<BinaryBuffer> &oBuffers, CAT3DXMExportSettings const &iParams = CAT3DXMExportSettings());
  HRESULT ExportMaterial(CATUnicodeString const &iPath, CATMaterialApplication &mat, CAT3DXMExportSettings const &iParams = CAT3DXMExportSettings());

  CATI3DXMHandler *GetObserver() const;

  /** Unit API for ambiances
   * If client wants to export the image at their desired location, they should derive their own handlder from CATI3DXMHandler, call RegisterCallBack()
   * In case of success, caller is responsible for freeing(with free) the buffer data contained in BinaryBuffer(m_Data)
   */
  HRESULT ExportAmbiance(CATUnicodeString const &iPath, const CATVisAmbiance &iAmb, CAT3DXMExportSettings const &iParams = CAT3DXMExportSettings());
  HRESULT ExportAmbiance(const CATVisAmbiance &iAmb, VisJSONValue &oJsonRoot, std::vector<BinaryBuffer> &oBuffers, CAT3DXMExportSettings const &iParams = CAT3DXMExportSettings());
  HRESULT ExportAmbiance(const CATVisAmbiance &iAmb, CATUnicodeString &oJsonString, std::vector<BinaryBuffer> &oBuffers, CAT3DXMExportSettings const &iParams = CAT3DXMExportSettings());

  /**
   * Unit API to export Camera
   */
  HRESULT ExportCamera(CATUnicodeString const &iPath, std::vector<CAT3DViewpoint *> &iVP, CATSupport &iSupport, CAT3DXMExportSettings const &iParams = CAT3DXMExportSettings());
  HRESULT ExportCamera(std::vector<CAT3DViewpoint *> &iVP, CATSupport &iSupport, VisJSONValue &oJsonRoot, CAT3DXMExportSettings const &iParams = CAT3DXMExportSettings());
  HRESULT ExportCamera(std::vector<CAT3DViewpoint *> &iVP, CATSupport &iSupport, CATUnicodeString &oJsonString, CAT3DXMExportSettings const &iParams = CAT3DXMExportSettings());

  HRESULT ExportCamera(std::vector<CAT2DViewpoint *> &iVP, CATSupport &iSupport, VisJSONValue &oJsonRoot, CAT3DXMExportSettings const &iParams = CAT3DXMExportSettings());
  HRESULT ExportCamera(std::vector<CAT2DViewpoint *> &iVP, CATSupport &iSupport, CATUnicodeString &oJsonString, CAT3DXMExportSettings const &iParams = CAT3DXMExportSettings());

  /**
   * Unit API for Exporting Light
   */
  HRESULT ExportLight(CATUnicodeString const &iPath, std::vector<CATRep *> iRep, CAT3DXMExportSettings const &iParams = CAT3DXMExportSettings());
  HRESULT ExportLight(std::vector<CATRep *> iRep, VisJSONValue &oJsonRoot, CAT3DXMExportSettings const &iParams = CAT3DXMExportSettings());
  HRESULT ExportLight(std::vector<CATRep *> iRep, CATUnicodeString &oJsonString, CAT3DXMExportSettings const &iParams = CAT3DXMExportSettings());

  /**
   * Unit API for Texture
   * In case of success, caller is responsible for freeing(with free) the buffer data contained in BinaryBuffer(m_Data)
   */
  HRESULT ExportTexture(std::vector<IVisTexturePtr> &texList, CATUnicodeString &oString, std::vector<BinaryBuffer> &oBuffers, CAT3DXMExportSettings const &iParams = CAT3DXMExportSettings());
  HRESULT ExportTexture(const std::vector<const CATPixelImage *> &imgList, CATUnicodeString &oString, std::vector<BinaryBuffer> &oBuffers, CAT3DXMExportSettings const &iParams = CAT3DXMExportSettings());

  /**
   * Write BinaryBuffer and Manifest file in 3DX or 3DXC format at oPath.
   */
  HRESULT Export(CATUnicodeString const &oPath, const VisJSONValue &iJsonRoot, const std::vector<BinaryBuffer> &iBuffers, CAT3DXMExportSettings const &iParams = CAT3DXMExportSettings());

  HRESULT Export(CATUnicodeString const &oPath, const CATUnicodeString &iString, const std::vector<BinaryBuffer> &iBuffers, CAT3DXMExportSettings const &iParams = CAT3DXMExportSettings());

  bool RegisterCallBack(CATI3DXMHandler &cb);
  bool DeregisterCallBack(CATI3DXMHandler &cb);

  /**
   * **DEPRECATED, DO NOT USE!**
   * This function is going to be removed from this protected interface in the near future.
   * For deprecation purposes, it will continue to be available through `VisLegacy3DXM/PrivateInterfaces/VisPrivateExportTo3DXM.h' with controlled access.
   * Please note, that export of mesh data using 3DXM is no longer a valid usage scenario for the 3DXM format.
   * There's no guarantee that this function will continue to work as expected and there won't be any maintainance whatsoever.
   *
   * Return the json manifest for the assembly, along with all the associated binary buffers.
   * In case of success, you are responsible for freeing (with free) the memory contained in the buffers (m_Data),
   * the buffer array (with delete[]) and the string (with delete[]).
   */
  HRESULT Export(CATRep &iAssembly, CAT3DXMExportSettings const &iParams, char *&oJsonString, BinaryBuffer *&oBuffers, unsigned int &oNumBuffers);

  /**
   ***DEPRECATED, DO NOT USE!**
   * This function is going to be removed from this protected interface in the near future.
   * For deprecation purposes, it will continue to be available through `VisLegacy3DXM/PrivateInterfaces/VisPrivateExportTo3DXM.h' with controlled access.
   * Please note, that export of mesh data using 3DXM is no longer a valid usage scenario for the 3DXM format.
   * There's no guarantee that this function will continue to work as expected and there won't be any maintainance whatsoever.
   *
   * Returns the whole 3dxc in oBuffer. Caller is responsible for delete []oBuffer
   * If iSupport is provided, it will export camera, ambiance, lights too
   */
  HRESULT Export(CATRep &iAssembly, CATSupport *iSupport, CAT3DXMExportSettings const &iParams, char *&oBuffer, unsigned int &oBufSize);

  /**
   * **DEPRECATED, DO NOT USE!**
   * This function is going to be removed from this protected interface in the near future.
   * For deprecation purposes, it will continue to be available through `VisLegacy3DXM/PrivateInterfaces/VisPrivateExportTo3DXM.h' with controlled access.
   * Please note, that export of mesh data using 3DXM is no longer a valid usage scenario for the 3DXM format.
   * There's no guarantee that this function will continue to work as expected and there won't be any maintainance whatsoever.
   *
   * Write the assembly to a zipped file at iPath location.
   */
  HRESULT Export(CATUnicodeString const &iPath, CATRep &iAssembly, CAT3DXMExportSettings const &iParams);

  /**
   * **DEPRECATED, DO NOT USE!**
   * This function is going to be removed from this protected interface in the near future.
   * For deprecation purposes, it will continue to be available through `VisLegacy3DXM/PrivateInterfaces/VisPrivateExportTo3DXM.h' with controlled access.
   * Please note, that export of mesh data using 3DXM is no longer a valid usage scenario for the 3DXM format.
   * There's no guarantee that this function will continue to work as expected and there won't be any maintainance whatsoever.
   */
  HRESULT Export(CATUnicodeString const &iPath, CATRep &iAssembly);

  /**
   * **DEPRECATED, DO NOT USE!**
   * This function is going to be removed from this protected interface in the near future.
   * For deprecation purposes, it will continue to be available through `VisLegacy3DXM/PrivateInterfaces/VisPrivateExportTo3DXM.h' with controlled access.
   * Please note, that export of mesh data using 3DXM is no longer a valid usage scenario for the 3DXM format.
   * There's no guarantee that this function will continue to work as expected and there won't be any maintainance whatsoever.
   */
  HRESULT Export(CATUnicodeString const &iPath, CATRep &iAssembly, CATSupport &iSupport, CAT3DXMExportSettings const &iParams = CAT3DXMExportSettings());

protected:
  CATSupport *m_pSupport;
  CATI3DXMHandler *m_pObserver;
};

// The base class for all callback functions
// One must derive from this class if they are interested in particular handler
class CATI3DXMHandler
{
public:
  // These functions will get called if a CATI3DXMHandler derived class is registered on exporter or importer via RegisterCallBack

  // will get called for every image found on export
  virtual void OnImageExporting(CAT3DXMImageNotification &notif) {}

  // will get called for every texture created on import
  virtual void OnTextureCreating(CAT3DXMTextureNotification &notif) {}

  // will get called for every binary found on import
  virtual void OnTextureImporting(CAT3DXMTextureNotification &notif) {}

  // will get called for every binary found on import
  virtual void OnBinaryImporting(CATExportTo3DXM::BinaryBuffer &buffer) {}
};

class VisUnitApiCallbackHandler : public vis::unit::CallbackHandler
{
public:
  VisUnitApiCallbackHandler(CATI3DXMHandler *ipObserver) : m_pObserver(ipObserver)
  {
  }

  uint32_t OnExportTextureCachePtrQuery(const IVisTexturePtr &ipTex, const std::string &iParamName)
  {
    CAT3DXMImageNotification notif;
    notif.m_TextureName = iParamName.c_str();
    notif.m_pTexture = ipTex;
    m_pObserver->OnImageExporting(notif);
    return notif.m_IsInCache ? notif.m_Uid : 0;
  }

  bool OnExportTextureCacheUidQuery(uint32_t iUid, const IVisTexturePtr &ipTex)
  {
    CAT3DXMImageNotification notif;
    notif.m_Uid = iUid;
    notif.m_pTexture = ipTex;
    m_pObserver->OnImageExporting(notif);
    return notif.m_IsInCache;
  }

  IVisTexturePtr OnImportTextureCacheQuery(const std::string &iIdentifier) override
  {
    CAT3DXMTextureNotification notif;
    notif.m_Name = iIdentifier.c_str();
    m_pObserver->OnTextureImporting(notif);
    return notif.m_Texture;
  }

  void OnImportTextureCreation(const IVisTexturePtr &iTex) override
  {
    CAT3DXMTextureNotification notif;
    notif.m_Texture = iTex;
    m_pObserver->OnTextureCreating(notif);
  }

  vis::unit::BinaryBuffer ResolveBinaryHandler(const std::string &iIdentifier) override
  {
    CATExportTo3DXM::BinaryBuffer externalBuffer;
    externalBuffer.m_Name = iIdentifier.c_str();
    m_pObserver->OnBinaryImporting(externalBuffer);

    vis::unit::BinaryBuffer oBuffer;
    oBuffer.name = externalBuffer.m_Name.ConvertToChar();
    oBuffer.size = externalBuffer.m_Size;
    oBuffer.data = (uint8_t *)externalBuffer.m_Data;
    return oBuffer;
  }

private:
  CATI3DXMHandler *m_pObserver = nullptr;
};

#endif
