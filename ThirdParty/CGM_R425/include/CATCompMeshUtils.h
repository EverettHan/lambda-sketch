#ifndef CATCompMeshUtils_h_
#define CATCompMeshUtils_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "SGComposites.h"

#include "CAT3DCuboidRep.h"
#include "CAT3DCurvedPipeRep.h"
#include "CAT3DCustomRep.h"
#include "CAT3DCylinderRep.h"
#include "CATCompMesh.h"
#include "CATIOBuffer.h"
#include "CATRep.h"
#include "CATSurfacicRep.h"
#include "CAT3DCanonicalRep.h"

/**
 * Utility class providing
 * <ul>
 * <li>Methods to convert reps into CATCompMesh</li>
 * <li>Methods to dump CATCompMesh into file formats (OBJ, PLY)</li>
 * </ul>
 */
class ExportedBySGComposites CATCompMeshUtils
{
    public:
        /**
         * Imports a CATRep into a CATCompMesh. The supported reps are :
         * <ul>
         * <li>CAT3DCuboidRep</li>
         * <li>CAT3DCurvedPipeRep</li>
         * <li>CAT3DCylinderRep</li>
         * <li>CATSurfacicRep</li>
         * <li>CAT3DCanonicalRep</li>
         * </ul>
         * If you want to import a CAT3DCustomRep, use ImportRep(CATRep*, std::vector<CATCompMeshPtr>&).
         *
         * @param  iRep   The rep to import
         * @param  ioMesh The output CATCompMesh
         * @return S_OK if the import succeeded, E_* otherwise
         */
        static HRESULT ImportRep(CATRep* iRep, CATCompMeshPtr& ioMesh);

        /**
         * Imports a CATRep into an array of CATCompMesh. The supported reps are :
         * <ul>
         * <li>CAT3DCuboidRep</li>
         * <li>CAT3DCurvedPipeRep</li>
         * <li>CAT3DCustomRep</li>
         * <li>CAT3DCylinderRep</li>
         * <li>CATSurfacicRep</li>
         * <li>CAT3DCanonicalRep</li>
         * </ul>
         *
         * @param  iRep     The rep to import
         * @param  ioMeshes The output array of CATCompMesh
         * @return S_OK if the import succeeded, E_* otherwise
         */
        static HRESULT ImportRep(CATRep* iRep, std::vector<CATCompMeshPtr>& ioMeshes);

        /**
         * Imports a CAT3DCuboidRep into a CATCompMesh.
         * @param  iCuboidRep The CAT3DCuboidRep to import
         * @param  ioMesh     The output CATCompMesh
         * @return S_OK if the import succeeded, E_* otherwise
         */
        static HRESULT ImportCuboidRep(CAT3DCuboidRep* iCuboidRep, CATCompMeshPtr& ioMesh);

        /**
         * Imports a CAT3DCurvedPipeRep into a CATCompMesh.
         * @param  iCurvedPipeRep The CAT3DCurvedPipeRep to import
         * @param  ioMesh         The output CATCompMesh
         * @return S_OK if the import succeeded, E_* otherwise
         */
        static HRESULT ImportCurvedPipeRep(CAT3DCurvedPipeRep* iCurvedPipeRep, CATCompMeshPtr& ioMesh);

        /**
         * Imports a CAT3DCuboidRep into a CATCompMesh.
         * @param  iCuboidRep The CAT3DCuboidRep to import
         * @param  ioMesh     The output CATCompMesh
         * @return S_OK if the import succeeded, E_* otherwise
         */
        static HRESULT ImportCustomRep(CAT3DCustomRep* iCustomRep, std::vector<CATCompMeshPtr>& ioMeshes);

        /**
         * Imports a CAT3DCylinderRep into a CATCompMesh.
         * @param  iCylinderRep The CAT3DCylinderRep to import
         * @param  ioMesh       The output CATCompMesh
         * @return S_OK if the import succeeded, E_* otherwise
         */
        static HRESULT ImportCylinderRep(CAT3DCylinderRep* iCylinderRep, CATCompMeshPtr& ioMesh);

        /**
         * Imports a CATSurfacicRep into a CATCompMesh.
         * @param  iSurfacicRep The CATSurfacicRep to import
         * @param  ioMesh       The output CATCompMesh
         * @return S_OK if the import succeeded, E_* otherwise
         */
        static HRESULT ImportSurfacicRep(CATSurfacicRep* iSurfacicRep, CATCompMeshPtr& ioMesh);

        /**
         * Imports a CAT3DCanonicalRep into a CATCompMesh.
         * @param  iCanonicalRep The CAT3DCanonicalRep to import
         * @param  ioMesh        The output CATCompMesh
         * @return S_OK if the import succeeded, E_* otherwise
         */
        static HRESULT ImportCanonicalRep(CAT3DCanonicalRep* iCanonicalRep, CATCompMeshPtr& ioMesh);

        /**
         * Dumps a CATCompMesh into an .obj file.
         * @param  iMesh The CATCompMesh to dump
         * @param  ioBuffer The output buffer
         * @return S_OK if the operation succeeded, E_* otherwise
         */
        static HRESULT DumpAsObjFile(CATCompMeshPtr& iMesh, CATIOBufferPtr& ioBuffer);

        /**
         * Dumps a CATCompMesh into an .ply file.
         * @param  iMesh The CATCompMesh to dump
         * @param  ioBuffer The output buffer
         * @return S_OK if the operation succeeded, E_* otherwise
         */
        static HRESULT DumpAsPLYFile(CATCompMeshPtr& iMesh, CATIOBufferPtr& ioBuffer);
};

#endif // SG_COMPOSITES_MULTIOS

#endif // !CATCompMeshUtils_h_
