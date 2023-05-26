#include "CATIAV5Level.h"
#ifdef CATIAV5R8
#ifndef CATIScriptSelectionAppFrame_h
#define CATIScriptSelectionAppFrame_h

// COPYRIGHT DASSAULT SYSTEMES 2001
    
//===========================================================================
//  Abstract of the class:
//  ----------------------
//
//  Interface which enables that, for the selection during script replay, the AutomationInterfaces
//  framework calls CATIAApplicationFrame services without any modification of IdentityCard.h
//
//===========================================================================
//  Inheritance:
//  ------------
//              CATBaseUnknown (System Framework)
//
//===========================================================================

#include "CATBaseUnknown.h"              // Needed to derive from CATBaseUnknown
#include "CATScriptReplayInteractions.h" // Needed to export the IID
#include "CATScriptSelectionConstants.h"
class CATPathElement;
class CATIBRepAccess;
class CATIAReference;
class CATIMfBRep;
class CATIProduct;
class CATIABase;

// Global Unique IDentifier defined in .cpp 
extern ExportedByCATScriptReplayInteractions IID IID_CATIScriptSelectionAppFrame;

class ExportedByCATScriptReplayInteractions CATIScriptSelectionAppFrame : public CATBaseUnknown
{
  // Used in conjunction with CATImplementInterface in the .cpp file
  CATDeclareInterface;

  public:

    virtual void SpecTypeDetermination(CATIAReference* iSpecParameter,int& oOldSpecParameterType,
                                       CATScBoundaryType* oBoundaryType)  = 0; 
    virtual HRESULT DetermineSelectionObject(CATIAReference* iAutoBoundary,   
                                     CATScBoundaryType iFeatureSupportedBoundaryTypes,
                                     int iOperatorParameterIndex,       
                                     CATIAReference *& oSelectionObject)  = 0;
    virtual HRESULT DetermineBRepFeature(CATIAReference* iAutoBoundary,          
                                      CATScBoundaryType iFeatureSupportedBoundaryTypes,
                                      int iOperatorParameterIndex,         
                                      int iFeaturizationType,           
                                      int iSpecifySupport,              
                                      unsigned long iFeaturisationOptions,
                                      CATIAReference*& oFeatureBRep)  = 0;
    virtual HRESULT DetermineConnector(CATIAReference* iAutoBoundary,           
                                    CATScBoundaryType iFeatureSupportedBoundaryTypes,
                                    int iOperatorParameterIndex,           
                                    int iSpecifySupport,                
                                    CATIAReference*& oConnector         
                                   )  = 0;
};

#endif // CATIScriptSelectionAppFrame_h
#endif // CATIAV5R8
