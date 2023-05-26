#ifndef Visu3DSTilesManager_H
#define Visu3DSTilesManager_H

#include "CATCallbackManager.h"
#include "Visu3DSTiles.h"

#include <string>

class CAT3DBagRep;
class CATGraphicWindow;
class VisuTilesManager;

class ExportedByVisu3DSTiles Visu3DSTilesManager : public CATCallbackManager
{
  CATDeclareClass;
  CATDeclareCBEvent(VISU_3DSTILES_ROOT_LOADED);
  CATDeclareCBEvent(VISU_3DSTILES_ROOT_FAILED);

public:
  struct ExportedByVisu3DSTiles Configuration
  {
    friend class Visu3DSTilesManager;

    Configuration();

    enum class ExportedByVisu3DSTiles LoaderMode
    {
      eFile,  // tiles must be loaded from a file
      eHttp   // tiles must be loaded from a http request
    };

    LoaderMode loaderMode = LoaderMode::eHttp;  // loading mode
    bool useCache = true;                       // allows caching of a given number of unused rep
    unsigned int cacheCapacity = 100;           // maximum number of unused content rep in cache
    bool useFrustumCulling = true;              // contents outside the view will not be loaded
    bool allowBlanks = false;                   // allow blanks during refinement by replacement

  private:
    unsigned int nbThread = 1;  // number of worker to load tiles
  };

public:
  ~Visu3DSTilesManager();

  static Visu3DSTilesManager* CreateManager(CATGraphicWindow* iWindow, const Configuration& iConfig = Configuration());

  void Initialize(const std::string& iTilesetLocation);

  CAT3DBagRep* GetRootRep() const;

  void ShowMetricsOverlay(bool iEnable);

  void ShowTilesBoundingElement(bool iEnable);

private:
  Visu3DSTilesManager(CATGraphicWindow* iWindow, const Configuration& iConfig);

private:
  enum EDebugFlags : unsigned int
  {
    eStatOverlay = 1 << 0,
    eBoudingElement = 1 << 1
  };

private:
  unsigned int m_DebugFlags = 0x0;
  VisuTilesManager* m_Impl = nullptr;
};

#endif  // Visu3DSTilesManager_H
