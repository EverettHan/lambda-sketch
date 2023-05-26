// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateFrFSection :
// Declaration of global functions used to create and destroy
// an instance of the Section operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// December 97  Creation                          CPL
//
// NLD 31 03 98 Spine optionnelle dans le createur avec triedre
//              de positionnement du profil
//=============================================================================
/*
#ifndef CreateFrFSection_H
#define CreateFrFSection_H
//
#include "FrFAdvancedObjects.h"
#include "CATMathDef.h"
#include "CATSkillValue.h"
//
class CATGeoFactory;
class CATFrFSetOfGuides;
class CATFrFMovingFrame;
class CATFrFSection;
class CATFrFProfile;
class CATMathPoint;
class CATMathDirection;
class CATMathAxis;
class CATCurve;
class CATFrFCompositeCurve;
class CATPCurve;
class CATFrFCoupling;
class CATFrFShapeConstraint;
//
ExportedByFrFAdvancedObjects
CATFrFSection * CreateCrvUnspecSection
                                (CATFrFCoupling * iCoupling,
                                 CATFrFSetOfGuides * iGuide,
                                 CATFrFMovingFrame * iMovingFrame,
                                 CATFrFShapeConstraint ** iConstraint,
                                 CATLONG32 iNbConstraints,
                                 CATFrFSection* iPreviousSection,
                                 CATFrFProfile * iProfile,
                                 CATBoolean iRemoveObjects= CATBoolean(0));
// avec composite curve mais profil en place
// dans le systeme d'axes de reference ou dans un systeme fourni
// en argument optionnel
// NLD 31 03 98 spine optionnelle
ExportedByFrFAdvancedObjects
CATFrFSection * CreateCrvUnspecSection
                                 (CATGeoFactory *iFactory,
                                  CATFrFCompositeCurve* iGuide,
                                  CATCurve** iSegments,
                                  CATLONG32 iNbSegments,
                                  CATMathAxis* iProfileAxis=0,
                                  CATFrFCompositeCurve* iSpine=0) ;
//
ExportedByFrFAdvancedObjects
CATFrFSection * CreateCrvUnspecSection
                                 (CATGeoFactory *iFactory,
                                  CATFrFCompositeCurve* iSpine,
                                  CATFrFCompositeCurve* iGuide,
                                  CATCurve** iSegments,
                                  CATLONG32 iNbSegments);
//
ExportedByFrFAdvancedObjects CATFrFSection * CreateCrvUnspecSectionSurC1
                               (CATGeoFactory* iFactory,
                                CATFrFSetOfGuides * iGuide,
                                CATFrFMovingFrame * iMovingFrame,
                                CATFrFShapeConstraint ** iConstraint,
                                CATLONG32 iNbConstraints,
                                CATFrFSection* iPreviousSection,
                                CATFrFProfile * iProfile,
                                CATMathPoint* iCenter,
                                CATMathDirection * iX,
                                CATMathDirection * iY,
                                CATBoolean iRemoveObjects= CATBoolean(0));
//
ExportedByFrFAdvancedObjects CATFrFSection * CreateCrvUnspecSectionSurC1
                               (CATGeoFactory *iFactory,
                                CATFrFCompositeCurve* iMasterGuide,//CATPCurve* iMasterGuide,
                                CATCurve** iSegments,
                                CATLONG32 iNbSegments);
//
ExportedByFrFAdvancedObjects
CATFrFSection * CreateUnspecSectionBiRail
                                 (CATGeoFactory *iFactory,
                                  CATFrFCompositeCurve* iGuide1, //CATCurve* iGuide1,
                                  CATFrFCompositeCurve* iGuide2, //CATCurve* iGuide2,
                                  CATCurve** iSegments,
                                  CATLONG32 iNbSegments);
//
ExportedByFrFAdvancedObjects
CATFrFSection * CreateUnspecSectionBiRail(CATFrFCoupling * iCoupling,
                                          CATFrFSetOfGuides * iGuide,
                                          CATFrFMovingFrame * iMovingFrame,
                                          CATFrFShapeConstraint ** iConstraint,
                                          CATLONG32 iNbConstraints,
                                          CATFrFSection* iPreviousSection,
                                          CATFrFProfile * iProfile,
                                          CATMathPoint& iPtStartProfile,
                                          CATMathPoint& iPtEndProfile,
                                          CATMathDirection& iNormalProfile,
                                          CATBoolean iRemoveObjects= CATBoolean(0));


//
ExportedByFrFAdvancedObjects
CATFrFSection * CreateUnspecSectionCrvC0SurC0(CATGeoFactory     *iFactory,
                                              CATFrFMovingFrame *iMovingFrame,
                                              CATFrFSetOfGuides *iGuide,
                                              CATCurve** iSegments,
                                              CATLONG32 iNbSegments);
//
ExportedByFrFAdvancedObjects void Remove(CATFrFSection *&ioSection );


//
ExportedByFrFAdvancedObjects
CATFrFSection * CreateCrvUnspecSection
                                 (CATGeoFactory *iFactory,
                                  CATCurve* iGuide,
                                  CATCurve** iSegments,
                                  CATLONG32 iNbSegments);

#endif




*/
