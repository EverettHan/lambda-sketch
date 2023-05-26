//#define KeepDeprecatedCreateMovingFrame
// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateFrFMovingFrame :
// Declaration of global functions used to create and destroy
// an instance of the MovingFrame operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// October. 97  Creation                          CPL
// May.     98  Modification:  Copy Constructor   CPL
// Feb.     99  Delete Creator with CATCurve      CPL
// Mar.     05  Add MeanTang                      JSX
// 12/03/07 NLD Ajout de CreateExtrapolShapeMovingFrame() pour eviter appel direct
//              au constructeur par la shape
//              Ajout des Create avec CATFrFObject; les anciens disparaitront
// 20/01/10 NLD Menage definitifs dans les anciens Create sans CATFrFObject
//=============================================================================
#ifndef CreateFrFMovingFrame_H
#define CreateFrFMovingFrame_H
//
#include "FrFAdvancedObjects.h"
#include "CATFrFObject.h"
#include "CATMathDef.h"
#include "CATSkillValue.h"
//
class CATCurve;
class CATFrFCompositeCurve;
class CATMathDirection;
class CATFrFCoupling;
class CATFrFMovingFrame;
class CATMovingFrameStruct;

// Copy constructor
ExportedByFrFAdvancedObjects
CATFrFMovingFrame * CreateMovingFrame(CATFrFObject& iFrFObject,
                                      CATFrFMovingFrame * iToCopy,
                                      CATBoolean iCopyMapping= TRUE);
//#ifdef KeepDeprecatedCreateMovingFrame
// deprecated
ExportedByFrFAdvancedObjects
CATFrFMovingFrame * CreateMovingFrame(CATFrFMovingFrame * iToCopy,
                                      CATBoolean iCopyMapping= TRUE);
//#endif

ExportedByFrFAdvancedObjects CATFrFMovingFrame*
CreateParallelToPlaneMovingFrame(CATFrFObject& iFrFObject,
                                 const CATFrFCompositeCurve* iSpine,
                                 const CATMathDirection*     iPlaneNormal,
                                 CATBoolean iComputeMapping= TRUE );
//
ExportedByFrFAdvancedObjects CATFrFMovingFrame*
CreateOrthoMovingFrame(CATFrFObject& iFrFObject,
                       const CATFrFCompositeCurve* iSpine,
                       CATBoolean iComputeMapping= TRUE );
//
ExportedByFrFAdvancedObjects CATFrFMovingFrame*
CreatePseudoOrthoMovingFrame (CATFrFObject& iFrFObject,
                              const CATFrFCompositeCurve* iSpine,
                              CATBoolean iComputeMapping= TRUE );
//
ExportedByFrFAdvancedObjects CATFrFMovingFrame*
CreateOrthoCrvCrvMovingFrame(CATFrFObject& iFrFObject,
                             const CATFrFCompositeCurve* iSpine,
                             const CATFrFCoupling*       iCoupling,
                             CATBoolean iComputeMapping= TRUE );

//
ExportedByFrFAdvancedObjects CATFrFMovingFrame*
CreatePseudoOrthoCrvCrvMovingFrame(CATFrFObject& iFrFObject,
                                   const CATFrFCompositeCurve* iSpine,
                                   const CATFrFCoupling*       iCoupling,
                                   CATBoolean iComputeMapping= TRUE );
//
ExportedByFrFAdvancedObjects CATFrFMovingFrame*
CreateMeanTangMovingFrame (CATFrFObject& iFrFObject,
                           CATFrFCoupling * iCoupling);

// Method to construct Ortho or PseudoOrtho MF
ExportedByFrFAdvancedObjects
CATFrFMovingFrame * CreateMovingFrame(CATFrFObject& iFrFObject,
                                      const CATFrFCompositeCurve* iSpine,
                                      const CATMovingFrameStruct& iMFDef);

// restricted use
ExportedByFrFAdvancedObjects
CATFrFMovingFrame * CreateExtrapolShapeMovingFrame(CATFrFObject& iFrFObject,
                                                   const CATFrFCompositeCurve* iSpine);
//=============================================================================
ExportedByFrFAdvancedObjects
void Remove(CATFrFMovingFrame *&ioMovingFrame );
//=============================================================================


#endif


