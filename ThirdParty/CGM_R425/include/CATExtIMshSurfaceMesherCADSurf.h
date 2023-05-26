#ifndef CATExtIMshSurfaceMesherCADSurf_h
#define CATExtIMshSurfaceMesherCADSurf_h

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// CATExtIMshSurfaceMesherCADSurf :
// Object that manage the use of MG-CADSurf, suitable for CSM
//
//=============================================================================
// February 2022  Creation                          Fabien Noblet (FNT1)
//=============================================================================

#include "CATMshCSMCommonExport.h"

extern "C" {
#include <meshgems/meshgems.h>
#include <meshgems/cadsurf.h>
#include <meshgems/cadsurf_short_names.h>
#include <key/meshgems_key_all.h>
#include <meshgems_common/banner.h>
}

#include "CATMshCallbacksMG.h"
#include "CATIMshSurfaceMesher.h"
#include "CATMshInterrupt.h"
#include "CATMshThreads.h"

class CATBody;
class CATIMshMesh;
class CATIMshSurfaceMesher;
class CATMshSpecTranslator;
class CATMshMeshMG2D;
class CATMshMeshAssociativity;
class CATIMshSpec;
class CATMshCSMParameters;
class CATMshMeshAndSpecTranslator;

class ExportedByCATMshCSMCommon CATExtIMshSurfaceMesherCADSurf : public CATIMshSurfaceMesher
{

public:

  /* Constructeur */
  CATExtIMshSurfaceMesherCADSurf();

  /* Destructeur */
  virtual ~CATExtIMshSurfaceMesherCADSurf();

  /**
  * Sets the support to be meshed - case of a discrete CAD
  * @return
  *   An HRESULT.
  *   <br><b>Legal values</b>:
  *   <dl><dt>S_OK</dt><dd>The Compute is OK.
  *   <dt>E_FAIL</dt><dd>The Compute failed.
  *   </dl>
  */
  virtual HRESULT SetSupport(CATIMshMesh *iMesh);

  /**
  * Sets the support to be meshed - case of a MeshGems cad_t
  * @return
  *   An HRESULT.
  *   <br><b>Legal values</b>:
  *   <dl><dt>S_OK</dt><dd>The Compute is OK.
  *   <dt>E_FAIL</dt><dd>The Compute failed.
  *   </dl>
  */
  virtual HRESULT SetSupport(cad_t *iCad);

  /**
  * Sets the support to be meshed - case of a CATBody
  * @return
  *   An HRESULT.
  *   <br><b>Legal values</b>:
  *   <dl><dt>S_OK</dt><dd>The Compute is OK.
  *   <dt>E_FAIL</dt><dd>The Compute failed.
  *   </dl>
  */
  virtual HRESULT SetSupport(int iBodyCount, CATBody **iBodies);

 
  /**
  * Set all the CSM parameters to the surface mesher
  * @param iParam
  *   The CATMshCSMParameters object corresponding to the global parameters of CSM.
  * @return
  *   An HRESULT.
  *   <br><b>Legal values</b>:
  *   <dl><dt>S_OK</dt><dd>The Compute is OK.
  *   <dt>E_FAIL</dt><dd>The Compute failed.
  *   </dl>
  */
  virtual HRESULT SetParameters(CATMshCSMParameters *iParam);

  
  /**
  * Set the interrupt callback function.
  * @param iCallback (in)
  *   The interrupt callback (or nullptr to remove any previous callback)
  * @param iUserData (in)
  *   The user pointer which will be given to iCallback as a parameter
  */
  virtual HRESULT SetInterruptCallback(CATMshInterruptCB iCallback, void *iUserData);

  /**
  * Set the message callback function.
  * @param iCallback (in)
  *   The message callback (or nullptr to remove any previous callback)
  * @param iUserData (in) 
  *   The user pointer which will be given to iCallback as a parameter
  * @return an error code
  */
  virtual HRESULT SetMessageCallback(CATMshMessageCB iCallback, void *iUserData);


    /**
    * Set the callback to be called by the cadsurf_session on thread creation.
    * @param iCallback (in)
	*   The callback
    * @param iUserData (in)
	*   The user data pointer to be provided as argument to the iCallback callback.
    */
  virtual HRESULT SetStartThreadCallback(CATMshStartThreadCB iCallback, void *iUserData);

  /**
    * Set the callback to be called by the cadsurf_session on thread deletion.
    * @param iCallback (in)
	*   The callback
    * @param iUserData (in)
	*   The user data pointer to be provided as argument to the iCallback callback.
    */
  virtual HRESULT SetStopThreadCallback(CATMshStopThreadCB iCallback, void *iUserData);

  
  /**
    * Set all the specifications set for this mesh
    * @param iCount (in)
    *   The number of specification set
    * @param iSpec (in)
	  *   An array of size iCount of specification to be use to mesh the support
    * @return
    *   An HRESULT.
    */
  virtual HRESULT SetLocalSpecification(int iCount, CATIMshSpec **iSpec);


  /**
   * Generate the mesh
   * @return
   *   An HRESULT.
   */
  virtual HRESULT Mesh();


  /**
   * Returns the generated mesh
   * @return
   *   The surface mesh.
   */
  virtual CATIMshMesh * GetMesh();
  
  
  /**
    * Get the CAD / mesh associativity of the generated mesh 
	* @return
    *   The CAD / mesh associativity, or nullptr if an error occurs, or if the MeshAssociativity is not available.
    */
  virtual CATMshMeshAssociativity * GetMeshAssociativity();
  
  
  /**
    * Get some information on the generated surface mesh.
    * @param iSpecType (in)
	*   The type of data requested
	* @return
    *   The corresponding data on mesh, or nullptr if the type is not handled by the mesher.
    */
  virtual CATIMshDataOnMesh * GetDataOnMesh(CATMshDataOnMeshType iDataType);

  protected :
  
    /* Input geometry */
    CATIMshMesh *_iMsh;
    context_t *_Ctx;
    cad_t *_Cadt;

    std::multimap<int, int> _TopoID2ID;

    int _ContextToBeDelete;
    int _CadToBeDelete;
    int _HasMMap;

private:

  /* Constructeur recopie */
  CATExtIMshSurfaceMesherCADSurf(const CATExtIMshSurfaceMesherCADSurf & Source);

  /* Operateur d'affectation */
  CATExtIMshSurfaceMesherCADSurf& operator=(const CATExtIMshSurfaceMesherCADSurf & Source);

  HRESULT CreateMGInputCont();
  HRESULT CreateMGInputDisc();
  HRESULT CreateMGInput();
  HRESULT UpdateMGInputCont();
  HRESULT UpdateMGInputDisc();
  HRESULT UpdateMGInput();
  virtual HRESULT SetCADSurfCallbacks();
  virtual HRESULT SetCADSurfGeom();
  virtual HRESULT SetCADSurfGlobalParameters();
  virtual HRESULT SetCADSurfLocalParameters();
  virtual HRESULT UpdateCADSurfLocalParameters();

  virtual HRESULT BuildLocalSizeOnMeshFromCADSurf(CATIMshDataOnMesh **DataOnMesh);
  virtual HRESULT BuildIntersectingEntitiesOnMeshFromCADSurf(CATIMshDataOnMesh **DataOnMesh);
  virtual HRESULT BuildMeshMatchingOnMeshFromCADSurf(CATIMshDataOnMesh **DataOnMesh);
  virtual HRESULT BuildRequiredEntitiesOnMeshFromCADSurf(CATIMshDataOnMesh **DataOnMesh);

  CATMshCSMParameters *_Param;
  CATIMshSpec **_Specs;
  CATMshSpecTranslator *_CadTranslator;
  CATMshMeshAndSpecTranslator *_MeshTranslator;
  DataForComponentCB_t _CBs;
  CATMshMeshMG2D *_oMsh;

  sizemap_t **_Sizemaps;
  element_generation_map_t *_EltMap;
  mesh_t *_iMsht;
  dcad_t *_Dcadt;
  cadsurf_session_t *_Css;
  mesh_t *_oMsht;

  int _SpecCount;
  int _SizemapCount;
  int _LastSizemapSet;

};

#endif
