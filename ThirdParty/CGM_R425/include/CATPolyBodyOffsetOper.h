// COPYRIGHT Dassault Systemes 2009
//==============================================================================
//
// CATPolyBodyOffsetOper.h
// Header definition of CATPolyBodyOffsetOper
//
//==============================================================================
//
// Usage notes: 
//       Use to apply an offset to a CATIPolyMesh CGM Model. A new 
//       representation will be created.
//
//==============================================================================
//
//  Jul 2009  Creation: TG2
//==============================================================================
#ifndef CATPolyBodyOffsetOper_H
#define CATPolyBodyOffsetOper_H


#include "PolyBodySweptAndThickness.h"

#include "CATPolyBodyVOCOper.h"
#include "CATPolyBuildMeshOper.h"


class CATIPolyMesh;


/**
 * TODO:
 * Class representing Swept Volumes.
 *
 * <br><b>Role</b>: Class used to compute Swept Volume based on CATIPolyMesh CGM model
 * <p>
 * Do not use the @href CATPolyBodyOffsetOper constructor to
 * do such and such but instead...
 *
 */
class ExportedByPolyBodySweptAndThickness CATPolyBodyOffsetOper : public CATPolyBodyVOCOper
{
  friend class CATPolyBodyThicknessOper;

    public:

        //======================================================================
        // Constructor
        //======================================================================
        CATPolyBodyOffsetOper();

        //======================================================================
        // Destructor
        //======================================================================
        virtual ~CATPolyBodyOffsetOper();

        
        //======================================================================
        // Run
        //======================================================================
        /**
         * Run the operator to calculate the resulting poly mesh.
         * IMPORTANT: Upon calling Run, if no external result poly mesh was set 
         *            via SetWorkingResult, an empty poly mesh will be created 
         *            for the result.
         *
         * @return S_OK   The calculation was completed successfully.
         *         E_FAIL The calculation failed.
         */
        HRESULT Run();

        //======================================================================
        // SetOffsetValue
        //======================================================================
        /**
         * Set the value of the offset to apply.
         *
         * @param iOffsetValue Value of the offset. Can be any value.
         *
         */
        void SetOffsetValue(double iOffsetValue);
        /**
         * Get the value of the offset.
         */
        double GetOffsetValue(){return _offsetValue;}

        /**
         * Get operator name
         */
        virtual const char * GetOperatorName();



    protected:
        HRESULT ProtectedRun();

    private:
        
        //======================================================================
        // ComputeOffset
        //======================================================================
        /**
         * Calculate the offset itself.
         *
         * @return S_OK   The calculation was completed successfully.
         *         E_FAIL The calculation failed.
         */
        HRESULT ComputeOffset();

        //======================================================================
        // GetAngle
        //======================================================================
        /**
         * Calculate the the angle in the triangle for a given vertex.
         *
         * @param iTriangleIndex Index of the triangle.
         * @param iVertexIndex   Index of the vertex.
         * @param oAngle         Resulting angle.
         *
         * @return S_OK   The calculation was completed successfully.
         *         E_FAIL The calculation failed or the supplied vertex index or
         *                triangle index is invalid, or the vertex does not 
         *                belong to the supplied triangle.
         */
        HRESULT GetAngle(int iTriangleIndex, int iVertexIndex, double &oAngle);
        
        //======================================================================
        // Member Variables
        //======================================================================

        /*
         * Value of the offset to apply. 
         */
        double _offsetValue;
};

//-----------------------------------------------------------------------

#endif
