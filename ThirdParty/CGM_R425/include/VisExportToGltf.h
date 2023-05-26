#ifndef VisExportToGltf_H_
#define VisExportToGltf_H_

#include "VisGltf.h"
#include "CATErrorDef.h"
#include "CATUnicodeString.h"
#include <vector>
#include "IVisTexturePtr.h"

#include <functional>
#include <memory>
#include <map>

class CATRep;
class CATSupport;
class CATGraphicMaterial;
class CATPixelImage;
class CATVisAmbiance;
class CATMaterialApplication;
class CAT3DViewpoint;
class l_VisExportToGltf;

struct ExportedByVisGltf VisGltfImageExportSettings
{
  enum LdrExportFormat
  {
    Png,
    Basis, // using KTX2 container
    Jpg
  };

  LdrExportFormat ldrExportFormat = LdrExportFormat::Jpg;

  int basisQuality = 128;        // 1-255
  int basisMaxThreads = -1; // -1 == use all available threads
  int uastcCompressionLevel = 2; // 1-4; High quality compression mode for normal maps
  bool generateBasisMipMaps = false;
  bool forcePNGNormalMap = false; // Exports normal maps as PNG, ignoring ldrExportFormat
};

enum class SceneUnit {
  Meter,
  Millimeter
};

struct ExportedByVisGltf VisGltfExportSettings
{
  VisGltfExportSettings();
  bool m_ExportBinary;
  bool m_EmbedImages;
  bool m_EmbedBuffers;

  bool m_UseDracoCompression;
  int m_DracoPosQuantizationBits;
  int m_DracoTexCoordsQuantizationBits;
  int m_DracoNormalsQuantizationBits;
  int m_DracoGenericQuantizationBits;
  int m_DracoCompressionLevel;

  int m_MaxThreads = -1; // -1 == use all available threads

  VisGltfImageExportSettings m_ImageExportSettings;

  SceneUnit m_InputSceneUnit = SceneUnit::Millimeter;

  // KHR_materials_volume defines a thicknessFactor that helps external rasterizers to determine th ephysical thickness of a closed geometric object (volume). We do not define such a parameter on our material model. Therefore, we set it to a configurable default that can be adjusted to best fit the scene dimensions. We expect external rasterizers to evolve to a point where they are able to calculate sufficient approximations to a real thickness, so that this parameter becomes obsolete.
  float m_DefaultThicknessFactor = 0.001f;
};

class ExportedByVisGltf VisExportToGltf
{
public:
  VisExportToGltf();
  ~VisExportToGltf();

  /**
  Write the assembly to a zipped file at iPath location.
  */
  HRESULT Export(CATUnicodeString const &iPath, CATRep &iAssembly, VisGltfExportSettings const &iParams);

  HRESULT Export(CATUnicodeString const &iPath, CATRep &iAssembly, CATSupport &iSupport,
                 VisGltfExportSettings const &iParams = VisGltfExportSettings());

  /**
  Export to an in-memory representation of GLTF without writing to disk.
  iName is used as a base-name for naming the various output buffers.
  oBinaries contains name-buffer pairs for all the files created by the GLTF export,
  stored in-memory instead of written to disk.
  */
  HRESULT Export(CATUnicodeString const &iName, CATRep &iAssembly, CATSupport &iSupport,
                 VisGltfExportSettings const &iParams,
                 std::map<CATUnicodeString, std::vector<unsigned char>> &oBinaries);

  void RegisterImageExportSettingCallback(std::function<void(const CATGraphicMaterial*, VisGltfImageExportSettings& ioImageExportSettings)> cb);


protected:
  CATSupport *m_pSupport;

private:
  std::unique_ptr<l_VisExportToGltf> m_pLetter;
};

#endif
