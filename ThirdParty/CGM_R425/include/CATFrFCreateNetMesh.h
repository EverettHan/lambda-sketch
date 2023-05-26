//====================================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved 
//====================================================================
// We have defined 3 steps in the creation of the profiled surfaces 
// thanks to the fkv method - curves based approach method. 
// We usually have 2 sets of curves
// - the first set is longitudinal, we call it the guide curves.
// - the second set is transversal, we call it the base curves.
// These 3 steps :
//    - mesh : preparation of the curves
//             It consists of many various computations on the curves
//             These sub-steps can be :
//              - reordering of the curves to know what their relative
//              positions are.
//              - extrapolation of these curves
//              - relimitations of the curves
//              - homogenization of the curves in a same direction
//              - adaptation, to shift or deform the bases onto the guides
//              (for the loft surface for instance)
//              - positions computation to know the relative position
//              of the profiles regarding the guide in the case of the
//              profiled surface for instance.  
//    - fill :
//              the mesh of curves is now ready for surface creation.
//              Now we have to compute intermediate bases to fill
//              this mesh and create our surface.
//    - creation of the topology onto the the surfaces.
// This global function enables us to perform the mesh each kind of surfaces
// built thanks to the fkv-method.
// 
// CATCreateFrFNetMesh :
// global function that creates a CATFrFNetMesh object :
// Achieve the mesh step for the net feature :
// It includes three steps :
//    - Trim (reordering, trim and extrapolation)
//    - Homogenization of the bases and of the guides
//    - Adaptation of the bases on the guides.
// 
// There extist several options :
//    - iOpt equals 1 : we just do the trim step.
//    _             2 : we do the trim and the homogenizations of
//                      the guides and of the bases.
//    -             3 : we do both previous steps as well as the 
//                      adaptation of the bases onto the guides.
// The default option is 3. It means we perform the whole treatment.
// 
// CATCreateFrFNetMonoGuideMesh :
// global function that creates the mesh for the net with only one guide :
// It includes several steps :
//    - orientations of the bases (should be provided by the user),
//    - reordering of the bases to know their relative order according to
//      the guide
//    - computation  of the positions ofthe bases on the guide
//    - computation of the C0 guide to assure that bases will belong
//      to the resulting surfaces
//    - Homogenization of the bases with imposed points (positions on the guide)
//    - adaptation of the bases onto the guide.
//
// CATCreateFrFNetMonoBaseMesh :
// global function that creates the mesh for the net with only one base :
// It includes several steps :
//    - orientations of the guides (should be provided by the user),
//    - reordering of the bases to know their relative order according to
//      the guide
//    - computation  of the positions of the guides on the base
//    - computation of the C0 base to assure that guides will belong
//      to the resulting surfaces
//    - Homogenization of the guides with imposed points (positions of the bases)
//    - adaptation of the base onto the guides.
//
// CATCreateFrFProfiledSurfacesMesh - This is a kind of Sweep.
// We use the same way to define the surface locally : with mixing laws.
// The guide is actually a spine to determine the position of the local frame.
// There is no deformation of the profiles to adapt the profiles onto the guides.
// Here, we provide a global function that creates the mesh for profiled surfaces:
// It includes several steps :
//    - orientations of the profiles (or bases),
//    - reordering of the bases to know their relative order according to
//      the guide
//    - computation  of the positions of the bases on the guide
//    - computation of the C0 guide to assure that profiles will belong
//      to the resulting surfaces
//    - Homogenization of the bases
//
//==========================================================================
// April,   2005 : ANR/FZA : Creation          (D'apres  CreateLoftMesh )          
//==========================================================================

#ifndef CATFrFCreateNetMesh_H
#define CATFrFCreateNetMesh_H 

#include "CATFrFNetSurface.h"

#include "CATFrFNetMesh.h"
#include "CATSkillValue.h"

#include "CATMovingFrameType.h"
                          

class CATGeoFactory;
class CATFrFCompositeCurve;


ExportedByCATFrFNetSurface
CATFrFNetMesh* CATFrFCreateNetMesh(CATGeoFactory            * ifactory,
                                   CATSoftwareConfiguration * iConfig,
                                   CATLONG32                       inbOfGuides,
                                   CATFrFCompositeCurve    ** iguideCCVs,
                                   CATLONG32                       iNumGuideDom,
                                   CATLONG32                       inbOfBases,
                                   CATFrFCompositeCurve    ** ibaseCCVs,
                                   CATLONG32                       iNumBaseDom,
                                   CATLONG32                       iOpt=3,
                                   CATSkillValue              iMode=BASIC);

ExportedByCATFrFNetSurface
CATFrFNetMesh* CATFrFCreateNetMonoGuideMesh (CATGeoFactory            * ifactory,
                                             CATSoftwareConfiguration * iConfig,
                                             CATFrFCompositeCurve     * iguideCCV,
                                             CATLONG32                       inbOfBases,
                                             CATFrFCompositeCurve    ** ibaseCCVs,
                                             CATLONG32                       iNumBaseDom,
                                             CATLONG32                       iOpt=3,
                                             CATSkillValue              iMode=BASIC);

ExportedByCATFrFNetSurface
CATFrFNetMesh* CATFrFCreateNetMonoBaseMesh(CATGeoFactory            * ifactory,
                                           CATSoftwareConfiguration * iConfig,
                                           CATLONG32                       inbOfGuides,
                                           CATFrFCompositeCurve    ** iguideCCVs,
                                           CATLONG32                       iNumDomG,
                                           CATFrFCompositeCurve     * ibaseCCV,
                                           CATLONG32                       iOpt,
                                           CATSkillValue              iMode=BASIC);

ExportedByCATFrFNetSurface
CATFrFNetMesh* CATFrFCreateProfiledSurfacesMesh(CATGeoFactory            * ifactory,
                                                 CATSoftwareConfiguration * iConfig,
                                                 CATFrFCompositeCurve     * iguideCCV,
                                                 CATLONG32                       inbOfBases,
                                                 CATFrFCompositeCurve    ** ibaseCCVs,
                                                 CATLONG32                       iNumBaseDom,
                                                 CATMovingFrameType         iMvFOption,
                                                 CATLONG32                       iOpt=3,
                                                 CATSkillValue              iMode=BASIC);

ExportedByCATFrFNetSurface
void Remove(CATFrFNetMesh *&iLoftMesh);
#endif

