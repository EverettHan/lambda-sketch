#ifndef CATSCRIPTSELECTIONSUBELEMENTSERVICES_H
#define CATSCRIPTSELECTIONSUBELEMENTSERVICES_H

// COPYRIGHT DASSAULT SYSTEMES 2001
//------------------------------------------------------------------------------
// Class  :     CATScriptSelectionSubElementServices
// Author :     bpt
// Date   :     05/12/01
//------------------------------------------------------------------------------

#include "CATScriptSelectionConstants.h" // described here in particular for calling methods,
                                             // to avoid them them to include this file
#include "CATBaseObject.h"
#include "CATIAV5Level.h"

#ifdef CATIAV5R10
#define BoundaryPreProcFlag
#endif

class CATIProduct;
class CATIAReference;
class CATIMfBRep;
class CATIScriptSelectionAppFrame;

class ExportedByCATScriptReplayInteractions CATScriptSelectionSubElementServices
{
 public:
 
 CATScriptSelectionSubElementServices();
 ~CATScriptSelectionSubElementServices();

 /* selection of a sub-element through SelectElement: determine if the input parameter corresponds 
    to a CATIAutoBoundary* or not. */
 /* Lifecycle rules: if oOldSpecParameterType is equal to false, the AddRef on the output interface will
    have been correctly done */ 
 static void sSpecTypeDetermination(CATIAReference* iSpecParameter, 
                                    int& oOldSpecParameterType,         /* boolean */
                                    CATScBoundaryType* oBoundaryType=NULL
                                                                        /* Filled only if 
                                                                           oOldSpecParameterType equals to 0.
                                                                           It gives the boundary type, so that
                                                                           several sDetermineBRepFeature call
                                                                           occurence can be done, depending on it
                                                                           (so that different occurences transmit
                                                                           different featurization options) */  
                                   ); 
 /* selection of a sub-element through SelectElement: check the feature supported boundary types and
    delivers a spec at the old supported format (reference) */
 /* first case: the specification given as input in the old format to the operator (reference) 
    is a CATIBRepAccess */  
 /* lifecycle rules: 
       . you must release oSelectionObject 
       . no AddRef has been made on any CATIProduct* of oProductSpec. Don't make any Release */
 static HRESULT sDetermineSelectionObject(CATIAReference* iAutoBoundary,/* object describing a sub-element
                                                                           for the automation 
                                                                           Selection.SelectElement method */   
                                          CATScBoundaryType iFeatureSupportedBoundaryTypes,
                                                                        /* to check the script input. Give to
                                                                           this parameter a combination of
                                                                           CATScBoundaryType 
                                                                           constants through logical or. 
                                                                           See CATAutomationSelectionConstants.h*/
                                          int iOperatorParameterIndex,  /* index of the sub-element parameter
                                                                           into the operator argument list.
                                                                           For the error message.
                                                                           1 for the first */     
                                          CATIAReference *& oSelectionObject
                                                                        /* this CATIAReference implements
                                                                           CATIBRepAccess.
                                                                           The calling operator must
                                                                           Release this interface pointer. */ 
                                         );
 /* second case: the specification given as input in the old format to the operator (reference) is a CATIMfBRep */  
 /* lifecycle rules: 
       . you must release oFeatureBRep 
       . no AddRef has been made on any CATIProduct* of oProductSpec. Don't make any Release */
 static HRESULT sDetermineBRepFeature(
     CATIAReference* iAutoBoundary,    /* object describing a sub-element for the automation 
                                          Selection.SelectElement method */      
     CATScBoundaryType iFeatureSupportedBoundaryTypes,
                                       /* to check the script input. Give to this parameter a combination of
                                          CATScBoundaryType constants through logical or. 
                                          See CATAutomationSelectionConstants.h*/
     int iOperatorParameterIndex,      /* index of the sub-element parameter into the operator argument list.
                                          For the error message. 
                                          1 for the first */    
     int iFeaturizationType,           /* Boolean: 
                                             0: functional
                                             1: relimited */
     int iSpecifySupport,              /* Relates only to the case where iFeaturizationType equals to 1. Boolean:
                                             0: we don't specify the support to the featurization software 
                                             1: we specify the support
                                          Note that if iSpecifySupport equals to 1 (and iFeaturizationType equals to 1),
                                          the support that will be used by the featurization software will be the
                                          result-out, which is correct */
     unsigned long iFeaturisationOptions,
                                       /* CATMfFeaturizeMode. see CATMfBRepDefs.h.
                                          If iFeaturisationOptions equals to 0:
                                            - case where iFeaturizationType equals to 0:
                                                . if iAutoBoundary is a Face, PlanarFace or CylindricalFace:
                                                     * the featurization will be a functional featurization
                                                     * options: MfTemporaryBody
                                                                MfWithoutBuildError
                                                                MfInitialFeatureSupport
                                                . if iAutoBoundary is a TriDimFeatEdge or RectilinearTriDimFeatEdge:
                                                     * the featurization will be a functional featurization
                                                     * options: MfTemporaryBody
                                                                MfWithoutBuildError
                                                                MfInitialFeatureSupport
                                                . if iAutoBoundary is a BiDimFeatEdge or RectilinearBiDimFeatEdge:
                                                     * the featurization will be a relimited featurization
                                                     * options: MfTemporaryBody
                                                                MfWithoutBuildError
                                                                MfSelectingFeatureSupport
                                                . if iAutoBoundary is a MonoDimFeatEdge or RectilinearMonoDimFeatEdge:
                                                     * the featurization will be a relimited featurization
                                                     * options: MfTemporaryBody
                                                                MfWithoutBuildError
                                                                MfSelectingFeatureSupport
                                                . if iAutoBoundary is a TriDimFeatVertexOrBiDimFeatVertex:
                                                     * the featurization will be a functional featurization
                                                     * options: MfTemporaryBody
                                                                MfWithoutBuildError
                                                                MfInitialFeatureSupport
                                                . if iAutoBoundary is a NotWireBoundaryMonoDimFeatVertex:
                                                     * the featurization will be a functional featurization
                                                     * options: MfTemporaryBody
                                                                MfWithoutBuildError
                                                                MfInitialFeatureSupport
                                                . if iAutoBoundary is a ZeroDimFeatVertexOrWireBoundaryMonoDimFeatVertex:
                                                     * the featurization will be a functional featurization
                                                     * options: MfTemporaryBody
                                                                MfWithoutBuildError
                                                                MfInitialFeatureSupport
                                            - case where iFeaturizationType equals to 1:
                                                . if iAutoBoundary is a Face, PlanarFace or CylindricalFace:
                                                     * the featurization will be a relimited featurization
                                                     * options: MfTemporaryBody
                                                                MfWithoutBuildError
                                                                MfSelectingFeatureSupport
                                                . if iAutoBoundary is a TriDimFeatEdge or RectilinearTriDimFeatEdge:
                                                     * the featurization will be a relimited featurization
                                                     * options: MfTemporaryBody
                                                                MfWithoutBuildError
                                                                MfSelectingFeatureSupport
                                                . if iAutoBoundary is a BiDimFeatEdge or RectilinearBiDimFeatEdge:
                                                     * the featurization will be a relimited featurization
                                                     * options: MfTemporaryBody
                                                                MfWithoutBuildError
                                                                MfSelectingFeatureSupport
                                                . if iAutoBoundary is a MonoDimFeatEdge or RectilinearMonoDimFeatEdge:
                                                     * the featurization will be a relimited featurization
                                                     * options: MfTemporaryBody
                                                                MfWithoutBuildError
                                                                MfSelectingFeatureSupport
                                                . if iAutoBoundary is a TriDimFeatVertexOrBiDimFeatVertex:
                                                     * the featurization will be a functional featurization
                                                     * options: MfTemporaryBody
                                                                MfWithoutBuildError
                                                                MfInitialFeatureSupport
                                                . if iAutoBoundary is a NotWireBoundaryMonoDimFeatVertex:
                                                     * the featurization will be a functional featurization
                                                     * options: MfTemporaryBody
                                                                MfWithoutBuildError
                                                                MfInitialFeatureSupport
                                                . if iAutoBoundary is a ZeroDimFeatVertexOrWireBoundaryMonoDimFeatVertex:
                                                     * the featurization will be a functional featurization
                                                     * options: MfTemporaryBody
                                                                MfWithoutBuildError
                                                                MfInitialFeatureSupport
                                       */
                                      CATIAReference*& oFeatureBRep  
                                       /* this CATIAReference implements CATIMfBRep.
                                          The calling operator must Release this interface pointer. */
                                      );
 /* third case: the specification given as input in the old format to the operator (reference) is a 
    CATIConnector */ 
 /* lifecycle rules: 
       . you must release oConnector
       . you must release the possible ioFeatureBRep 
       . no AddRef has been made on any CATIProduct* of oProductSpec. Don't make any Release */
 static HRESULT sDetermineConnector(CATIAReference* iAutoBoundary,      /* object describing a sub-element
                                                                           for the automation 
                                                                           Selection.SelectElement method */      
                                    CATScBoundaryType iFeatureSupportedBoundaryTypes,
                                                                        /* to check the script input. Give to
                                                                           this parameter a combination of
                                                                           CATScBoundaryType 
                                                                           constants through logical or. 
                                                                           See CATAutomationSelectionConstants.h*/ 
                                    int iOperatorParameterIndex,        /* index of the sub-element parameter
                                                                           into the operator argument list.
                                                                           For the error message.
                                                                           1 for the first */    
                                    int iSpecifySupport,                /* For the relimited case. Boolean:
                                                                               0: we don't specify the support to 
                                                                                  the featurization software 
                                                                               1: we specify the support */
                                    CATIAReference*& oConnector         /* this CATIAReference implements
                                                                           CATIConnector.
                                                                           The calling operator must
                                                                           Release this interface pointer. */
                                   );
// This macro must be called before GSMCHECK. If the call to GSMCHECK is going to return
// from the method, this macro releases the boundary delivered by the previous call to the
// CATScriptSelectionSubElementServices::sDetermineBRepFeature method
#define RELEASE_BOUNDARY(CurrentSubElementTypeFlag_xx,ReturnCode_xx,Boundary_xx) \
 if ((!CurrentSubElementTypeFlag_xx)&&(ReturnCode_xx!=S_OK)&&(Boundary_xx!=NULL))\
   {\
     Boundary_xx->Release();\
     Boundary_xx= NULL;\
   }
// This macro must be called before GSMCHECKvar. If the call to GSMCHECKvar is going to return
// from the method, this macro releases the boundary delivered by the previous call to the
// CATScriptSelectionSubElementServices::sDetermineBRepFeature method
#define RELEASE_BOUNDAR2(CurrentSubElementTypeFlag_xx,Handler_xx,Boundary_xx) \
 if ((!CurrentSubElementTypeFlag_xx)&&(Handler_xx==NULL_var)&&(Boundary_xx!=NULL))\
   {\
     Boundary_xx->Release();\
     Boundary_xx= NULL;\
   }


 private:

 static void sInitializeStaticData();

 /* object enabling, for sub-element selection through SelectElement, to call CATIAApplicationFrame services */
 static CATIScriptSelectionAppFrame* sWorkAppFrame;   
 /* object enabling that the static data be des-allocated */
 static CATScriptSelectionSubElementServices sWorkSubElementServices;
};
#endif
