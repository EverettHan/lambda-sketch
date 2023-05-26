// COPYRIGHT Dassault Systemes 2009
//==============================================================================
//
// CATPolyBodyVOCOper.h
// Header definition of CATPolyBodyVOCOper
//
//==============================================================================
//
// Usage notes: 
//       Base class for VOC poly mesh operators.
//
//==============================================================================
//
//  Jul 2009  Creation: TG2
//==============================================================================
#ifndef CATPolyBodyVOCOper_H
#define CATPolyBodyVOCOper_H


#include "PolyBodySweptAndThickness.h"

#include "CATPolyModOper.h"
#include "CATPolyBuildMeshOper.h"


class CATIPolyMesh;
class CATechExt;

/**
 * TODO:
 * Class representing Swept Volumes.
 *
 * <br><b>Role</b>: Class used to compute Swept Volume based on CATIPolyMesh CGM model
 * <p>
 * Do not use the @href CATPolyBodyVOCOper constructor to
 * do such and such but instead...
 *
 */
class ExportedByPolyBodySweptAndThickness CATPolyBodyVOCOper : public CATPolyModOper
{
    public:

        //======================================================================
        // Constructor
        //======================================================================
        CATPolyBodyVOCOper();

        //======================================================================
        // Destructor
        //======================================================================
        virtual ~CATPolyBodyVOCOper();

        //======================================================================
        // GetResult
        //======================================================================
        /**
         * Get the result of the operator.
         *
         * @param opResultMesh Pointer to the resulting poly mesh. Must be NULL
         *                     when called.
         *
         * @return S_OK         Got the result without problem and opResultMesh 
         *                      is valid.
         *         S_FALSE      opResultMesh is not valid.
         *         E_INVALIDARG opResultMesh is not NULL when called.
         */
        HRESULT GetResult(CATIPolyMesh *& opResultMesh);

        //======================================================================
        // SetWorkingResult
        //======================================================================
        /**
         * Set the poly mesh in which the result of the operator will be 
         * created.
         * IMPORTANT: It is not compulsory to call this method before running 
         *            the operator. Upon calling Run, if no external result poly
         *            mesh was set, an empty poly mesh will be created for the
         *            result.
         *
         * @param ipResultMesh Pointer to the resulting poly mesh. Can already 
         * contain geaometry but must not be NULL when called. Will be AddRef'd.
         *
         * @return S_OK         The resulting poly mesh was set without problem.
         *         E_INVALIDARG ipResultMesh is NULL when called.
         */
        HRESULT SetWorkingResult(CATIPolyMesh *ipResultMesh);

        /**
         * Get the input mesh. Release it after use.
         */
        CATIPolyMesh * GetMesh();

        /**
         * Debug. Don't use.
         */
        void SetPhoenixExtension(CATechExt *iExtension);
        /**
         * Get version
         */
        int GetVersion(){return m_Version;}
        /**
         * Get operator name
         */
        virtual const char * GetOperatorName() = 0;

    protected:
              
        //======================================================================
        // CreateEmptyResult
        //======================================================================
        /**
         * Create empty result poly mesh.
         *
         * @return S_OK   The result mesh was created succesfully.
         *         E_FAIL Unable to create the result mesh. 
         */
        HRESULT CreateEmptyResult();
        
        //======================================================================
        // AddTriangleToResult
        //======================================================================
        /**
         * Add triangle made up of the supplied vertices to the result poly 
         * mesh. The vertices will be added to the poly mesh if they are not 
         * already present.
         *
         * @return S_OK   The triangle was added successfully.
         *         E_FAIL Unable to add the triangle. 
         */
        HRESULT AddTriangleToResult(const CATMathPoint& iVertex1, 
                                    const CATMathPoint& iVertex2, 
                                    const CATMathPoint& iVertex3);

        //======================================================================
        // AddTriangleToResult
        //======================================================================
        /**
         * Add triangle made up of the supplied vertices to the result poly 
         * mesh. The vertices will be added to the poly mesh if they are not 
         * already present.
         *
         * @return S_OK   The triangle was added successfully.
         *         E_FAIL Unable to add the triangle. 
         */
        HRESULT AddTriangleToResult(const CATMathPoint& iVertex1, 
                                    const CATMathPoint& iVertex2, 
                                    const CATMathPoint& iVertex3,
                                    int& oIdxVertex1,
                                    int& oIdxVertex2,
                                    int& oIdxVertex3,
                                    int& oIdxTriangle);

        //======================================================================
        // AddTriangleToResult
        //======================================================================
        /**
         * Add triangle made up of the supplied vertices to the result poly 
         * mesh. The vertices will be added to the poly mesh if they are not 
         * already present.
         *
         * @return S_OK   The triangle was added successfully.
         *         E_FAIL Unable to add the triangle. 
         */
        //HRESULT AddTriangleToResult(int& iIdxVertex1,
        //                            int& iIdxVertex2,
        //                            int& iIdxVertex3);


        //======================================================================
        // AddTriangleToResult
        //======================================================================
        /**
         * Add triangle made up of the supplied vertices to the result poly 
         * mesh. The vertices will be added to the poly mesh if they are not 
         * already present.
         *
         * @return S_OK   The triangle was added successfully.
         *         E_FAIL Unable to add the triangle. 
         */
        //HRESULT AddVerticesToResult(const CATMathPoint& iVertex1, 
        //                            const CATMathPoint& iVertex2, 
        //                            const CATMathPoint& iVertex3,
        //                            int& oIdx1,
        //                            int& oIdx2,
        //                            int& oIdx3);

        //======================================================================
        // AddTriangleToResult
        //======================================================================
        /**
         * Add triangle made up of the supplied vertices to the result poly 
         * mesh. The vertices will be added to the poly mesh if they are not 
         * already present.
         *
         * @return S_OK   The triangle was added successfully.
         *         E_FAIL Unable to add the triangle. 
         */
        HRESULT AddTriangleToResult(int& iIdxVertex1,
                                    int& iIdxVertex2,
                                    int& iIdxVertex3,
                                    CATPolyBuildMeshOper& triangleBuildOper);

        HRESULT AddVerticesToResult(const CATMathPoint& iVertex1, 
                                    const CATMathPoint& iVertex2, 
                                    const CATMathPoint& iVertex3,
                                    const CATMathPoint& iVertex4,
                                    int& oIdx1,
                                    int& oIdx2,
                                    int& oIdx3,
                                    int& oIdx4,
                                    CATPolyBuildMeshOper& triangleBuildOper);

        //HRESULT AddTriangleToResult(const CATMathPoint& iVertex1, 
        //                            const CATMathPoint& iVertex2, 
        //                            const CATMathPoint& iVertex3,
        //                            CATPolyBuildMeshOper& triangleBuildOper);


        //======================================================================
        // Member Variables
        //======================================================================

        /* 
         * BuildOper to construct the result poly mesh. 
         */
        CATPolyBuildMeshOper _buildOper;

        /* 
         * Result of the operator. 
         */
        CATIPolyMesh *_pResultMesh;

        int _nbVertices;
        
        int _nbTriangles;


  // Debug:
  CATechExt * m_Pegase;
  int m_Version;
};

//-----------------------------------------------------------------------

#endif
