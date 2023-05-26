//====================================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved 
//====================================================================
//
// CATFrFConvertCCVToNurbsMultiForm :
// conversion d un CATCompositeCurve en une NurbsMultiform
//======================================================================
//
// Usage notes:
// 1/
// Attention : on suppose que la CCV est C2. L utilisateur
// doit donc effectuer les verifications les continuites
// C2 entre les sous-elements de sa CCV.
//
// 2/ 
// La multiform est creee par le constructeur
// est accessible par le GetResult(),
// mais doit etre detruite par l appelant
//
//============================================================================
// April,   2005 : ANR/FZA : Creation (D'apres  CATConvertCCVToNurbsMultiForm) 
//============================================================================

#ifndef CATFrFConvertCCVToNurbsMultiForm_H
#define CATFrFConvertCCVToNurbsMultiForm_H

#include "CATFrFNetSurface.h"

class CATFrFCompositeCurve;
class CATFrFNurbsMultiForm;
class CATGeoFactory;
class CATSoftwareConfiguration;

//----------------------------------------------------------------------
class ExportedByCATFrFNetSurface CATFrFConvertCCVToNurbsMultiForm
{
  public :
    CATFrFConvertCCVToNurbsMultiForm(CATGeoFactory            * iFactory,                       
                                     CATSoftwareConfiguration * iconfig,
                                     CATFrFCompositeCurve     * CCV);

    ~CATFrFConvertCCVToNurbsMultiForm(){};
    
    CATFrFNurbsMultiForm* GetResult() {return _resultingNurbsMultiForm;};
  
  private :
    CATFrFNurbsMultiForm* _resultingNurbsMultiForm;
};
#endif
