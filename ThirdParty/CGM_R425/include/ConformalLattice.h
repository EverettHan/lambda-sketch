#pragma once

#ifndef ConformalLattice_H
#define ConformalLattice_H

#include "ExportedByLatticePolyOperators.h"

// Sys
#include "CATSysErrorDef.h"

// CGM 
#include "CATGeoFactory.h"
#include "CATTopData.h"
#include "CATCGMScaleCategoryDef.h"
#include "CATMathTransformation.h"

// Poly 
#include "CATPolyBody.h"
#include "CATIPolyMesh.h"

// Lattice
#include "LatticeNBModel.h"
#include "LatticeFrameFields.h"

// Standard lib
#include <vector>
#include <array>

namespace lattice
{
  namespace poly {
    /**
    * @brief Generates a LatticeFrameField (oFrameField) from a surface geometry given by iPolyMesh inside the box iAABox
    */
    ExportedByLatticePolyOperators HRESULT CreateConformalFrameField(CATCGMScaleCategory iScale, const CATMathBox& iAABox, const CATIPolyMesh& iPolyMesh, LatticeFrameFields& oFrameFields);
    
    /**
    * @brief Generates a dense (uniform grid based) LatticeNBModel oLattice from a box iAAbox
    * @param iConnectivityMode : 0, 1 or 2 for 6, 18 and 28-neighborhood respectively.
    * @param iNodeDensityFactor : resolution of grid relative to the resolution of the scalar field.
    * It is suggested to use iConnectivityMode= 1 and iNodeDensityFactor= 1.0 by default and
    * subsequently increase the node density factor if needed to create denser structures.
    * @param dimX, dimY, dimZ : number of desired subdivisions over each direction
    * @param iBarRadius : desired lattice bar radius 
    * @param oLattice : resulting lattice
    */
    ExportedByLatticePolyOperators HRESULT GenerateInitialBarGraph(      
      const CATMathBox& iAABox,
      const int dimX, const int dimY, const int dimZ, const double iBarRadius,
      LatticeNBModel& oLattice,
      const int iConnectivityMode = 1, const double iNodeDensityFactor = 1.0);

    /**
    * @brief Preconditionate a LatticeFrameField by averaging their node values a
    * given number of times and rescaling the node FrameField values if iMinVoxelSize
    * and iMaxVoxelSize are both set to non-zero values
    * @param ioFrameFields : a LatticeFrameFields structure containing the input/output
    * density field and a smoothed and rescaled frame fields
    * @param nbSmoothIter : number of Smooth iterations applied
    * This method smoothes the tensor field by averaging each voxel with its
    * 7 neighbors weighted by the scalar field values. Running a few iterations
    * of smoothing (e.g. 10 iterations) helps suppressing fast variations in
    * the orientation and scalings, thus reducing the number of singularities
    * that will be in the resulting hex-dominant optimized lattice structure.
    * @param iMinSizeInNbVoxels : is the desired minimum length of the lattice members.
    * @param iMaxSizeInNbVoxels : is the desired maximum length of the lattice members. 
    * iMinSizeInNbVoxels= 1.2 and iMaxSizeInNbVoxels= 1.8 leads to a hex dominant
    * lattice structure with shortest and longest bars aiming for a length
    * of 1.2 and 1.8 respectively, while also aligning with the orthogonal basis.
    * Typically the lengths should be slightly longer than the average length of the
    * bars in the initial unoptimized graph to achieve good results.
    * i.e. 1.2 < iMinSizeInNbVoxels <= iMaxSizeInNbVoxels < 2.0
    * If the lengths are too short, holes will appear in the lattice structure.
    * If the lengths are too large, convergence will be slower and have large clusters.
    */
    ExportedByLatticePolyOperators HRESULT LatticeFrameFieldsPreConditioner(      
      LatticeFrameFields& ioFrameFields, 
      const int nbSmoothIter, 
      const double iMinSizeInNbVoxels = 0.0, const double iMaxSizeInNbVoxels = 0.0);

    /**
    * @brief Rescale LatticeFrameField's density field by mapping their node values using 
    * logistic distribution such that initial points of space with densities in 
    * (density_min - density_max) range have now values over (0.5 - 1.0) range
    * @param ioFrameFields : a LatticeFrameFields structure containing the input/output
    * density field and a smoothed and rescaled frame fields
    * @param densityMin : minimal density field value.
    * @param densityMax : maximal density field value.    
    */
    ExportedByLatticePolyOperators HRESULT LatticeFrameFieldsRescaleDensityOverRange(
      LatticeFrameFields& ioFrameField,
      const double densityMin, const double densityMax);

    /**
    * @brief Deprecated methods to generate a LatticeFrameField (oFrameField) from a surface geometry given by iPolyMesh inside the box iAABox
    */
    // Deprecated FrameField builder (non-rigid grid)
    ExportedByLatticePolyOperators HRESULT CreateConformalDistanceGradientBasedFieldOld(CATCGMScaleCategory iScale, const CATMathBox& iAABox, CATPolyBody& iPolyBody, LatticeFrameFields& oFrameFields);
    // Deprecated FrameField builder based on a rigid grid
    ExportedByLatticePolyOperators HRESULT CreateConformalDistanceGradientBasedField(CATCGMScaleCategory iScale, const CATMathBox& iAABox, CATPolyBody& iPolyBody, LatticeFrameFields& oFrameFields);

    /**
    * @brief Generates a LatticeFrameField from the geometry of a given CATPolyBody
    * @param iPolyBody : CATPolyBody representing a cavity defined by its surface 
    * @param oFrameFields : the resulting frame field
    * This method creates a FrameField representing a rigid grid, where for each point
    * Density field is computed based on the surface's signed distance field evaluated 
    * on each of the rigid grid nodes. Each value is then normalized to obtain a scalar
    * field where points with density values between 0.0 and 0.5 are considered outside
    * the cavity and points with density values between 0.5 and 1.0 are considered inside.
    * Frame field is computed based on the signed distance field gradient.
    */    
    ExportedByLatticePolyOperators HRESULT CreateConformalDistanceGradientBasedField(
      CATCGMScaleCategory iScale, CATPolyBody& iPolyBody, 
      LatticeFrameFields& oFrameFields);
    
    /**
    * @brief Generates an optimized lattice from a surface geometry given by iCavityPolyBody.
    * @param iScale : the cavity's scale category 
    * @param iCavityPolyBody : polyBody containing the cavity's geometry
    * @param iBarLength : desired lattice average bar length
    * @param iBarRadius : desired lattice bar radius
    * @param oLattice : optimized lattice
    * @param nbIterations_gauss_seidel : optional parameter to use the Gausse-Seidel optimizer
    * mode a given number of iterations
    * @param nbIterations_jacobi : optional parameter to use the Jacobi optimizer mode a given
    * number of iterations
    * @param density_cutoff : optional parameter to override the distance field threshold value 
    * defining the cavity's inside/outside used to optimize an initial lattice which covers the
    * cavity's bounding box.
    * By definition, 0.5 represents the cavity's surface, therefore a 0.0 threshold value means
    * that we will optimize the full lattice covering the cavity's bounding box while a 0.2
    * threshold value means we optimize only a lattice subdomain covering the cavity.
    */
    ExportedByLatticePolyOperators HRESULT CreateGeometryMeshOptimizedLattice(
      CATCGMScaleCategory iScale, CATPolyBody& iCavityPolyBody,
      const double iBarLength, const double iBarRadius,
      LatticeNBModel* oLattice,
      const int nbIterations_gauss_seidel = 0, const int nbIterations_jacobi = 1000, const double density_cutoff = 0.0);

    /**
    * @brief Generates an optimized lattice which orientation is adapted to a given frame field.
    * @param iFrameField : LatticeFrameField data structure containing the Frame and density fields
    * @param iBarRadius : desired lattice bar radius
    * @param oLattice : optimized lattice
    * @param nbIterations_gauss_seidel : optional parameter to use the Gausse-Seidel optimizer
    * mode a given number of iterations
    * @param nbIterations_jacobi : optional parameter to use the Jacobi optimizer mode a given
    * number of iterations
    * @param density_cutoff : optional parameter to override the density field threshold value 
    * defining the cavity's inside/outside used to optimize an initial lattice which covers the
    * cavity's bounding box.
    * By definition a 0.0 threshold value means that we will optimize the full lattice covering
    * the cavity's bounding box.
    */
    ExportedByLatticePolyOperators HRESULT CreateFrameFieldOptimizedLattice(
      const LatticeFrameFields& iFrameField,
      const double iBarRadius,
      LatticeNBModel* oLattice,
      const int nbIterations_gauss_seidel = 0, const int nbIterations_jacobi = 1000, const double density_cutoff = 0.0);

    /**
    * @brief Generates an optimized lattice which orientation is adapted to a given frame field.
    * Thist alternative method allows the user to re-define the optimizable lattice domain by defining 
    * two limit density values.
    * @param iFrameField : LatticeFrameField data structure containing the Frame and density fields
    * @param iBarRadius : desired lattice bar radius
    * @param oLattice : optimized lattice
    * @param nbIterations_gauss_seidel : optional parameter to use the Gausse-Seidel optimizer
    * mode a given number of iterations
    * @param nbIterations_jacobi : optional parameter to use the Jacobi optimizer mode a given
    * number of iterations
    * @param density_min : parameter to define the density field lower bound value defining the 
    * optimizable domain
    * @param density_min : parameter to define the density field upper bound value defining the 
    * optimizable domain
    * By definition, 0.0 to 1.0 bound values means that we will optimize the full lattice covering
    * the cavity's bounding box.
    */
    ExportedByLatticePolyOperators HRESULT CreateFrameFieldOptimizedLatticeOnDensityRange(
      LatticeFrameFields& iFrameField,
      const double iBarRadius,
      LatticeNBModel* oLattice,
      const int nbIterations_gauss_seidel = 0, const int nbIterations_jacobi = 1000,
      const double density_min = 0.0, const double density_max = 1.0);

    /**
    * @brief Optimizes a given lattice to follow the local orientations given by a frame field.
    * @param iFrameField : LatticeFrameField data structure containing the Frame and density fields    
    * @param iLattice : input lattice
    * @param nbIterations_gauss_seidel : optional parameter to use the Gausse-Seidel optimizer
    * mode a given number of iterations
    * @param nbIterations_jacobi : optional parameter to use the Jacobi optimizer mode a given
    * number of iterations
    * @param density_cutoff : value used to update the node positions of parameterization points with high density only
    * @iMergeDistance : distance threshold used to merge all nodes having a smaller pairwise distance
    * @param oLattice : optimized lattice
    * This method takes as Input the parameterization at the current step and update the positions of
    * the lattice nodes to minimize the misalignment energy with a relaxation method.
    * The relaxation can be applied in sequential/cascading (Gauss Seidel mode)
    * or in parallel (Jacobi mode). A good baseline is to run at least ~200 iterations
    * in Gauss Seidel mode followed by ~100 iterations in Jacobi mode to achieve a
    * good convergence of the solution. The number of iterations needed is generally
    * higher for complex geometries with highly varying orientation fields. Gauss-Seidel mode
    * can introduce a numerical node displacement tendencies consecuence of the cascading approach
    * and they can produce loss of symmetry.
    */
    ExportedByLatticePolyOperators HRESULT FieldOrientedBarGraphOptimization(
      const LatticeFrameFields& iFrameFields,
      const LatticeNBModel& iLattice,
      const int iGauss_seidel_iteration_count,
      const int iJacobi_iteration_count,
      const double iDensity_cutoff,
      double iMergeDistance,
      LatticeNBModel& oLattice);

    /**
    * @brief Generates an conformal lattice from a surface geometry given by iBody.
    * @param iScale : the cavity's scale category 
    * @param iPolyBody : polyBody containing the cavity's geometry
    * @param iTBody : CATMathTransformation associated to the polyBody
    * @param iGeoFactory : GeoFactory containing the cavity
    * @param iTopData : CATTopData associated to the cavity
    * @param iBarLength : desired lattice average bar length
    * @param iBarRadius : desired lattice bar radius
    * @param oLattice : optimized lattice
    * The final lattice is trimmed and clamped to be contained inside the cavity
    */
    ExportedByLatticePolyOperators HRESULT CreateConformalLatticeFromPolyBody(
      CATCGMScaleCategory iScale, CATPolyBody& iPolyBody, const CATMathTransformation* iTBody, 
      CATGeoFactory* iGeoFactory, CATTopData* iTopData, 
      const double iBarLength, const double iBarRadius, 
      LatticeNBModel*& oLattice);

  }
}

#endif

