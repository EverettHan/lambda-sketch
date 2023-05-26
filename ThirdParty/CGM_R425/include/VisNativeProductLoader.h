//===================================================================
// COPYRIGHT Dassault Systemes 2021/11/05
//===================================================================
// VisNativeProductLoader.cpp
// Header definition of class VisNativeProductLoader
//===================================================================
//
// Usage notes:
//
//===================================================================
//===================================================================

#ifndef VisNativeProductLoader_H
#define VisNativeProductLoader_H

#include "VisuProductLoaderManager.h"
#include "VisuProductLoaderHandle.h"
#include "CAT4x4Matrix.h"
#include "CATBaseUnknown.h"
#include "CATSGOptionManager.h"

#include <vector>
#include <memory>
#include <mutex>

class VisuProductLoader;
class VisuProductLoaderHandle;
class CAT3DBagRep;
class CATViewer;
class CATUnicodeString;
class CATRepPath;
class CATRep;



/**
* @class VisNativeProductLoader is an Helper to load products with the product loader.
* This wrapper is dedicated to the native 3DExperience.
*/
class ExportedByVisuProductLoaderManager VisNativeProductLoader : public CATBaseUnknown
{
  CATDeclareClass;
public: 
  typedef VisuProductLoaderHandle Handle;

public:
  /** 
  * @struct Parameters lists the different uses of @class VisNativeProductLoader
  * Only derivated structs which follow can be instanciated
  */
  struct Configuration {
    friend struct VisNativeProductLoader;
    void DownloadMaterial(bool downloadMaterial) { m_DownloadMaterial = downloadMaterial; }
    void DownloadPlayRep(bool downloadPlayRep) { m_DownloadPlayRep = downloadPlayRep; }
    void AddBoundingBox(bool addBoundingBox) { m_AddBoundingBox = addBoundingBox; }
    void SetOptionLDH(const CATSGOptionManagerPtr& iOptionLDH) { m_OptionLDH = iOptionLDH; }
    HRESULT CheckLicenses() const; // return S_OK if licensing is OK (used for PlayReps and Progressive expand)
  private:
    Configuration() = default;
  private:
    bool m_Partial = false; // download from server only visible products
    bool m_SequentialDownload = false; // block until LDH is runining or CGR fully loaded
    bool m_LDH = false;  // activate LDH
    bool m_DownloadPlayRep = false;  // load the playRep if available
    bool m_DownloadMaterial = false; // load the textures and apply them to the SG
    bool m_AddBoundingBox = false; // add a bounding box per root product until the expand is finished. I could slow down the display!
    CATSGOptionManagerPtr m_OptionLDH; // option for LDH
  };


  struct FromViewpoint : public Configuration {
    FromViewpoint() { m_LDH = true;  m_Partial = true; m_DownloadPlayRep = true; }
  };

  struct Synchronously : public Configuration {
    Synchronously() { m_LDH = true; m_SequentialDownload = true; m_DownloadPlayRep = true; }
  };

  struct Asynchronously : public Configuration {
    Asynchronously() { m_LDH = true; m_DownloadPlayRep = true; }
  };

public:
  /*!
  * \Brief Build an instance. A product loader is linked to a Window.
  * \param iViewer: The viewer where the model will be inserted
  * \param iParameters (optional). the way of loading the products.
  * If "Partial" is selected, only what is visible from the viewpoint will be loaded.
  * Warning: you cannot destroy the viewer before the product loader!
  */
  static VisNativeProductLoader* CreateProductLoader(CATViewer* iViewer, const Configuration& iConfiguration = Asynchronously());
  
  /*!
  * \Brief Register an occurrence of a Product. 
  * \param iRep: the CAT3DBagRep where to place the product content. Its ring must contain a "CATCompRepIdentifier" with the product Business Object ID. 
  * If you want to load annotations, the rep must inherit from CAT3DFilterBagRep.
  * \param iMatrix (optional) the position of the occurrence from the viewpoint. Useful if you want to priorize the loading. It loads in priority the most visible occurrences.
  * \param iFilterJsonObject optional. json string which describes the filter for the Expand V2
  * \warning The loading can be asynchronous. We don't add the rep inside the scenegraph. LDH is activated.
  */
  HRESULT RegisterOccurrence(CAT3DBagRep* iRep, const CAT4x4Matrix& iMatrix = CAT4x4Matrix(), const CATUnicodeString& iFilterJsonObject = "");

  /*!
  * \Brief Register an occurrence of a Product. This method might be used only with partial loading.
  * The handle allows to change the occurrence position (for animation).
  * \param iRep: the CAT3DBagRep where to place the product content. Its ring must contain a "CATCompRepIdentifier" with the product Business Object ID.
  * If you want to load annotations, the rep must inherit from CAT3DFilterBagRep.
  * \param iMatrix the position of the occurrence from the viewpoint. Used to priorize the loading and load only what is visible.
  * \param oHandle the handle of the current occurrence.
  * \warning The loading can be asynchronous. We don't add the rep inside the scenegraph. LDH is activated.
  * \warning A Product Business Object ID must be associated to a unique CATRep!
  */
  HRESULT RegisterOccurrence(CAT3DBagRep* iRep, const CAT4x4Matrix& iMatrix, std::shared_ptr<Handle>& oHandle);

  /*!
  * \Brief Register an occurrence of a Product. This method might be used only with partial loading.
  * The handle allows to change the occurrence position (for animation).
  * \param iRep: the CAT3DBagRep where to place the product content. Its ring must contain a "CATCompRepIdentifier" with the product Business Object ID.
  * If you want to load annotations, the rep must inherit from CAT3DFilterBagRep.
  * \param iMatrix the position of the occurrence from the viewpoint. Used to priorize the loading and load only what is visible.
   * \param iFilterJsonObject optional. json string which describes the filter for the Expand V2
 * \param oHandle the handle of the current occurrence.
  * \warning The loading can be asynchronous. We don't add the rep inside the scenegraph. LDH is activated.
  * \warning A Product Business Object ID must be associated to a unique CATRep!
  */
  HRESULT RegisterOccurrence(CAT3DBagRep* iRep, const CAT4x4Matrix& iMatrix, const CATUnicodeString& iFilterJsonObject, std::shared_ptr<Handle>& oHandle);

  /*!
  * \Brief search if a there is a rep already registered with a Business Object Id
  * thanks to the unique association between a BOID and a Rep.
  * \param iBOID the Business Object Id.
  * \return the associated Rep if any.
  */
  CAT3DBagRep* FindProductRep(const CATUnicodeString& iBOID);

  /*!
   * \Brief Compute a Rep path from list of product id. Useful for external annotations.
   * \param iPathId: List of Product ID
   * \param oRepPath: RepPath generated from the iPathID
   * \return E_FAIL if we don't find a product id( not loaded when progressive expand)
  */
  HRESULT ComputeRepPathFromPathID(const std::vector<CATUnicodeString>& iPathId, CATRepPath& oRepPath);

  /*!
  * \return true if the product loader has finished its work. It doesn't take into account the LDH work!
  * It means all the Product Structure (and eventually CGR) for a given viewpoint is loaded in the SceneGraph.
  * If no more SG update are needed then the product loader can be destroyed.
  */
  bool IsLoadFinished() const;

  /*!
  * \return true if LDH has finished to load what was visible.
  */
  bool IsLDHFinished() const;

  /*!
   * \Brief activate the view of debug info.
   * \param isActive: if true the info will be displayed.
   * \result S_OK
  */
  HRESULT SetDebugInfo(bool isActive);

  /*!
  * \Brief utility to retrieve a BOID from a rep.
  * \param iRep where is located the BOID
  * \param oBOID the retrieved Business Object Id
  * \result E_FAIL if there is no BOID or empty BOID. S_OK elsewhere
  */
  static HRESULT GetProductID(CATRep* iRep, CATUnicodeString& oBOID);

  /*!
  * \Brief utility to set a BOID on a rep
  * \param iRep where to set the BOID
  * \param iBOID the Business Object Id which cannot be empty
  * \result E_FAIL if there is already a BOID or trying to set an empty BOID. S_FALSE if the BOID was already set. S_OK elsewhere.
  * \warning a BOID must be set to a unique rep
  */
  static HRESULT SetProductID(CATRep* iRep, const CATUnicodeString& iBOID);

protected:
  /*!
   * \Brief Constuctor 
   */
  VisNativeProductLoader() = default;

  /*!
   * \Brief Initialize after creation
   */
  HRESULT Init(CATViewer* iViewer, const Configuration& iConfiguration);

  /*!
  *\Brief Destuctor
  */
  virtual ~VisNativeProductLoader();

private:
  VisNativeProductLoader(const VisNativeProductLoader&) = delete;
  VisNativeProductLoader& operator=(const VisNativeProductLoader&) = delete;


protected:
  VisuProductLoader* m_Impl;
  std::vector<std::shared_ptr<Handle>> m_Handles;
  std::mutex m_HandlesMutex;
};

//-----------------------------------------------------------------------

#endif
