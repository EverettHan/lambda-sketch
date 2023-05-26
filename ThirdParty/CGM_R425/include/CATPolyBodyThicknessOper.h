// COPYRIGHT Dassault Systemes 2009
//==============================================================================
//
// CATPolyBodyThicknessOper.h
// Header definition of CATPolyBodyThicknessOper
//
//==============================================================================
//
// Usage notes: 
//       Use to apply the Thickness operator to a CATIPolyMesh CGM Model. A new 
//       representation will be created.
//
//==============================================================================
//
//  Jul 2009  Creation: TG2
//==============================================================================
#ifndef CATPolyBodyThicknessOper_H
#define CATPolyBodyThicknessOper_H


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
 * Do not use the @href CATPolyBodyThicknessOper constructor to
 * do such and such but instead...
 *
 */
class ExportedByPolyBodySweptAndThickness CATPolyBodyThicknessOper : public CATPolyBodyVOCOper
{
    public:

        //======================================================================
        // Constructor
        //======================================================================
        CATPolyBodyThicknessOper();

        //======================================================================
        // Destructor
        //======================================================================
        virtual ~CATPolyBodyThicknessOper();

        
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
        // SetThicknessValue
        //======================================================================
        /**
         * Set the Thickness values to apply.
         *
         * @param iThicknessValue1 First Thickness value, which is the offset 
         *                         applied in the direction of the surface 
         *                         normals. Can be any value.
         * @param iThicknessValue2 First Thickness value, which is the offset 
         *                         applied in the opposite direction of the 
         *                         surface normals. Can be any value.
         */
        void SetThicknessValues(double iThicknessValue1, 
                                double iThicknessValue2);
        /**
         * Get the Thickness values
         */
        void GetThicknessValues(double & iThicknessValue1, 
                                double & iThicknessValue2);


        /**
         * Get operator name
         */
        virtual const char * GetOperatorName();
    private:

        //======================================================================
        // ComputeThickness
        //======================================================================
        /**
         * Calculate the Thickness itself.
         *
         * @return S_OK   The calculation was completed successfully.
         *         E_FAIL The calculation failed.
         */
        HRESULT ComputeThickness();

        //======================================================================
        // Member Variables
        //======================================================================

        /*
         * First Thickness value to apply. This is the offset in the direction
         * of the surface normals.
         */
        double _thicknessValue1;

        /*
         * First Thickness value to apply. This is the offset in the direction
         * of the surface normals.
         */
        double _thicknessValue2;
};

//-----------------------------------------------------------------------

#endif
