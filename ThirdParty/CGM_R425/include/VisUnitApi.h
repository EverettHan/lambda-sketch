
#ifdef __VisUnitApi
#define ExportedByVisUnitApi DSYExport
#else
#define ExportedByVisUnitApi DSYImport
#endif
#include "DSYExport.h"

#ifndef VISUNITAPI_H_
#define VISUNITAPI_H_

#include "CATUnicodeString.h"
#include "IVisTexturePtr.h"

#include <functional>
#include <vector>
#include <string>

class CATRep;
class CATSupport;
class CAT3DViewpoint;
class CAT2DViewpoint;
class CATMaterialApplication;
class CAT3DLightSourceRep;
class CATVisAmbiance;
class CATGraphicMaterial;

namespace vis::unit
{

  class CallbackHandler;

#pragma region Common
  enum class ApiVersion
  {
    v3_2,
    v4_0
  };

  struct ExportedByVisUnitApi BinaryBuffer
  {
    std::string name;
    uint8_t *data = nullptr;
    size_t size = 0;
  };

  /**
   * @brief A data object that wraps a 3dxm manifest encoded as string and a list of BinaryBuffer objects
   *
   */
  struct ExportedByVisUnitApi SerializedData
  {
    CATUnicodeString json;
    std::vector<BinaryBuffer> binaries;
  };

#pragma endregion

#pragma region Export

  struct ExportedByVisUnitApi ImageExportSettings
  {
    enum LdrExportFormat
    {
      Png,
      Basis, // using KTX2 container
      Jpg
    };

    LdrExportFormat ldrExportFormat = LdrExportFormat::Png;

    int basisQuality = 128;        // 1-255
    int uastcCompressionLevel = 2; // 1-4; Used or normal map compression
    int jpgQuality = 80;
    bool generateBasisMipMaps = false;
    bool forceLdr = false;          // exports 32-/16bit float HDR material parameter textures as 8-bit LDR
    bool forcePNGNormalMap = false; // Exports normal maps as PNG, ignoring ldrExportFormat
  };

  // Controls whether a zip archive (3dx) or concatenated file (3dc) will be exported
  enum class FileExportMode
  {
    Archive,
    Concatenated
  };

  struct ExportedByVisUnitApi ExportSettings
  {

    ApiVersion version = ApiVersion::v4_0;
    bool exportPreIbl = false;

    unsigned int preIblSppLamb = 4096; // Number of samples per pixel to be calculated during preconvolved IBL export for
                                       // the Lambert distribution (diffuse)
    unsigned int preIblSppGgx = 1024;  // Number of samples per pixel to be calculated during preconvolved IBL export for
                                       // the GGX distribution (specular)

    ImageExportSettings imageExportSettings;
  };

  ExportedByVisUnitApi HRESULT To3DXM(
      std::vector<CAT2DViewpoint *>::const_iterator begin, std::vector<CAT2DViewpoint *>::const_iterator end,
      SerializedData &o3DXM, const ExportSettings &iParams = ExportSettings());

  ExportedByVisUnitApi HRESULT To3DXM(
      std::vector<CAT3DViewpoint *>::const_iterator begin, std::vector<CAT3DViewpoint *>::const_iterator end,
      const CATSupport &iSupport, SerializedData &o3DXM, CallbackHandler *iCallbackHandler = nullptr, const ExportSettings &iParams = ExportSettings());

  ExportedByVisUnitApi HRESULT To3DXM(
      std::vector<CAT3DLightSourceRep *>::const_iterator begin, std::vector<CAT3DLightSourceRep *>::const_iterator end,
      SerializedData &o3DXM, const ExportSettings &iParams = ExportSettings());

  ExportedByVisUnitApi HRESULT To3DXM(
      std::vector<IVisTexturePtr>::const_iterator begin, std::vector<IVisTexturePtr>::const_iterator end,
      SerializedData &o3DXM, CallbackHandler *iCallbackHandler = nullptr,
      const ExportSettings &iParams = ExportSettings());

  ExportedByVisUnitApi HRESULT To3DXM(
      std::vector<CATMaterialApplication *>::const_iterator begin,
      std::vector<CATMaterialApplication *>::const_iterator end, SerializedData &o3DXM,
      CallbackHandler *iCallbackHandler = nullptr,
      const ExportSettings &iParams = ExportSettings());

  ExportedByVisUnitApi HRESULT
  To3DXM(const CATVisAmbiance &iAmbiance, SerializedData &o3DXM,
         CallbackHandler *iCallbackHandler = nullptr, const ExportSettings &iParams = ExportSettings());

#pragma endregion

#pragma region Import
  ExportedByVisUnitApi HRESULT From3DXM(const SerializedData &i3DXM, std::vector<CAT3DViewpoint *> &oViewpoints);

  ExportedByVisUnitApi HRESULT From3DXM(const SerializedData &i3DXM, std::vector<CAT2DViewpoint *> &oViewpoints);

  ExportedByVisUnitApi HRESULT From3DXM(const SerializedData &i3DXM, std::vector<CAT3DLightSourceRep *> &oLights);

  ExportedByVisUnitApi HRESULT From3DXM(const SerializedData &i3DXM, std::vector<IVisTexturePtr> &oTextures, CallbackHandler *iCallbackHandler = nullptr);

  ExportedByVisUnitApi HRESULT From3DXM(const SerializedData &i3DXM, std::vector<CATMaterialApplication *> &oMaterials, CallbackHandler *iCallbackHandler = nullptr);

  ExportedByVisUnitApi HRESULT From3DXM(const SerializedData &i3DXM, CATVisAmbiance *&iAmbiance, CallbackHandler *iCallbackHandler = nullptr);
#pragma endregion

#pragma region Callbacks

  class CallbackHandler
  {
  public:
    /**

    * @brief A callback function that is triggered before export of an IVisTexturePtr
    *
    * @param The texture that is about to be exported
    * @param The texture's parameter name (required by 3DEXCITE indexed material loading)
    * @return The uid of the cached texture, empty string otherwise
    */
    virtual uint32_t OnExportTextureCachePtrQuery(const IVisTexturePtr &, const std::string &) { return 0; }

    /**
     * @brief A callback function that is triggered before export of a IVisTexturePtr, but after
     * TextureCachePtrQuery (in case it didn't hit a cache entry)
     *
     * @param The UID of the texture that is about to be exported
     * @return A boolean that indicates whether the texture is in the cache
     */
    virtual bool OnExportTextureCacheUidQuery(const uint32_t, const IVisTexturePtr &) { return false; }

    /**
     * @brief A callback function that is triggered before import of an image object
     *
     * @param The uid that is about to be imported
     * @return The IVisTexturePtr of the cached texture, invalid ptr otherwise
     */
    virtual IVisTexturePtr OnImportTextureCacheQuery(const std::string &) { return IVisTexturePtr(); }

    /**
     * @brief A callback function that is triggered on texture import, after IVisTexturePtr creation
     *
     * @param The created texture object
     */
    virtual void OnImportTextureCreation(const IVisTexturePtr &) {}

    /**
     * @brief A callback function that is triggered on texture import, after IVisTexturePtr creation
     *
     * @param The created texture object
     */
    virtual BinaryBuffer ResolveBinaryHandler(const std::string &) { return BinaryBuffer(); }

    /**
     * @brief A callback function that is triggered on material export. Enabling image export settings on a per material level.
     *
     * @param The material to be exported
     * #param The image export settings to be modified by callback handler
     */
    virtual void OnMaterialExport(const CATGraphicMaterial *, ImageExportSettings &) {}
  };

#pragma endregion

  ExportedByVisUnitApi HRESULT Write3DXMStreamToFile(const SerializedData &i3DXM, const CATUnicodeString &iPath,
                                                     const FileExportMode &iExportMode = FileExportMode::Archive);

} // namespace vis::unit
#endif // VISUNITAPI_H_
