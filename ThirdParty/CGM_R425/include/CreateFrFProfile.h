// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateFrFProfile :
// Declaration of global functions used to create and destroy
// an instance of the Profile operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// December 97  Creation                          CPL
// September 98 Ajout ImplicitProfile Ctor        CPL
// March 99     Ajout ChoiceSolution dans Circle  CPL
// Oct   03     On passe la config en argument des implicitProfile      JSX
// 14/03/07 NLD Suppression du Create sans factory
// 11/05/10 JSX Suppression de iApproxTolerance dans le 
//              constructeur avec CATFrFNurbsMultiForm
//=============================================================================
#ifndef CreateFrFProfile_H
#define CreateFrFProfile_H
//
#include "FrFAdvancedObjects.h"
#include "CATMathDef.h"
#include "CATSkillValue.h"
#include "CATFreeFormDef.h"
//
class CATCurve;
class CATFrFCompositeCurve;
class CATNurbsCurve;
class CATFrFProfile;
class CATFrFGeneralizedProfile;
class CATFrFImplicitProfile;
class CATGeoFactory;
class CATMathAxis;
class CATFrFSetOfGuides;
class CATFrFMovingFrame;
class CATFrFCoupling;
class CATFrFShapeConstraint;
class CATSoftwareConfiguration;
#include "CATListOfCATFrFNurbsMultiForm.h"
//
ExportedByFrFAdvancedObjects 
CATFrFProfile * CreateProfile(CATGeoFactory* iFactory,
                              CATSoftwareConfiguration *iConfig,
                              CATFrFCompositeCurve* iSegments,
                              double iApproxTolerance = -1.,
                              CATFrFContinuity = CATFrFNoCont);

//
ExportedByFrFAdvancedObjects 
CATFrFProfile * CreateProfile(CATGeoFactory* iFactory,
                              CATSoftwareConfiguration *iConfig,
                              CATFrFCompositeCurve* iSegments,
                              CATLISTP(CATFrFNurbsMultiForm)* iNurbsSegments);

//
ExportedByFrFAdvancedObjects 
CATFrFProfile * CreateProfile(CATGeoFactory* iFactory,
                              CATSoftwareConfiguration *iConfig,
                              CATLONG32 iNumberOfSegments,
                              CATCurve** iSegments,
                              CATMathAxis* iAxis= 0 );
//
ExportedByFrFAdvancedObjects 
CATFrFProfile * CreateProfile(const CATFrFProfile* iToCopy);
//
ExportedByFrFAdvancedObjects 
CATFrFImplicitProfile * CreateSegmentProfile(CATGeoFactory *iFactory,
                                             CATSoftwareConfiguration *iConfig,
                                             CATFrFSetOfGuides * iGuides,
                                             CATFrFMovingFrame * iMovingFrame,
                                             CATFrFCoupling * iCoupling,
                                             CATFrFShapeConstraint** iConstraints=0,
                                             CATLONG32 iNumberOfConstraints= 0 );
//
ExportedByFrFAdvancedObjects 
CATFrFImplicitProfile * CreateCircleProfile(CATGeoFactory *iFactory,
                                            CATSoftwareConfiguration *iConfig,
                                            CATFrFSetOfGuides * iGuides,
                                            CATFrFMovingFrame * iMovingFrame,
                                            CATFrFCoupling * iCoupling,
                                            CATLONG32 iSolutionNumber,
                                            CATFrFShapeConstraint** iConstraints=0,
                                            CATLONG32 iNumberOfConstraints= 0 );
//
ExportedByFrFAdvancedObjects 
CATFrFImplicitProfile * CreateConicProfile(CATGeoFactory *iFactory,
                                           CATSoftwareConfiguration *iConfig,
                                           CATFrFSetOfGuides * iGuides,
                                           CATFrFMovingFrame * iMovingFrame,
                                           CATFrFCoupling * iCoupling,
                                           CATLONG32 iSolutionNumber,
                                           CATFrFShapeConstraint** iConstraints=0,
                                           CATLONG32 iNumberOfConstraints= 0 );
//
ExportedByFrFAdvancedObjects 
CATFrFImplicitProfile * CreateInterpolProfile(CATGeoFactory *iFactory,
                                              CATSoftwareConfiguration *iConfig,
                                              CATFrFSetOfGuides * iGuides,
                                              CATFrFMovingFrame * iMovingFrame,
                                              CATFrFCoupling * iCoupling,
                                              CATLONG32 iSolutionNumber,
                                              CATFrFShapeConstraint** iConstraints=0,
                                              CATLONG32 iNumberOfConstraints= 0 );

ExportedByFrFAdvancedObjects 
CATFrFImplicitProfile * CreateBlendProfile(CATGeoFactory *iFactory,
                                           CATSoftwareConfiguration *iConfig,
                                           CATFrFSetOfGuides * iGuides,
                                           CATFrFMovingFrame * iMovingFrame,
                                           CATFrFCoupling * iCoupling,
                                           CATLONG32 iSolutionNumber=0,
                                           CATFrFShapeConstraint** iConstraints=0,
                                           CATLONG32 iNumberOfConstraints= 0 );

//
ExportedByFrFAdvancedObjects 
CATFrFImplicitProfile * CreateProfile(const CATFrFImplicitProfile* iToCopy);
//
ExportedByFrFAdvancedObjects 
void Remove(CATFrFProfile *&ioProfile );
//
ExportedByFrFAdvancedObjects 
void Remove(CATFrFImplicitProfile *&ioProfile );

#endif


