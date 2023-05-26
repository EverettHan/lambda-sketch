/* -*-c++-*-*/
#ifndef CATDynMassProperties1DOnEdgeCGM_H
#define CATDynMassProperties1DOnEdgeCGM_H
//=============================================================================
//
// COPYRIGHT   : DASSAULT SYSTEMES 1998
//
// DESCRIPTION : CATDynMassProperties1DOnEdge  class declaration
//
//=============================================================================
#include "CATDynMassProperties1DOnEdge.h"
#include "AnalysisToolsLight.h"
#include "CATEdge.h"
#include "CATDynCNEXTLight.h"
#include "CATCrvParam.h"

#include "CATBoolean.h"

class ExportedByAnalysisToolsLight CATDynMassProperties1DOnEdgeCGM : public CATDynMassProperties1DOnEdge
{
public :
  // Constructor
  CATDynMassProperties1DOnEdgeCGM(const CATEdge *iBodyToAnalyse);
  CATDynMassProperties1DOnEdgeCGM(CATTopData * iData, const CATEdge *iBodyToAnalyse);


  // Destructor.

  ~CATDynMassProperties1DOnEdgeCGM() ;

  CATLength GetLengthFromParams(const CATCrvParam &iParam1,
				const CATCrvParam &iParam2) const;
  CATPositiveLength GetLength() const; 

  virtual HRESULT GetParamFromLength(const CATCrvParam &iParam, const CATLength & iLength, CATCrvParam & oParam) const;

  // *** TO BE REMOVED WHEN A CORRECTION IS AVAILABLE ***
  // cqi 02mar06 - Report of HF E0512255 correction for BOEING waiting improvements on CATMassProperties1D Integrate method.
  // Definition of a strong mode (with minimal recursivity)
  // for CATMassProperties1D geometric operator so as to be more robust on difficult parametric peaks 
  // to integrate.
  CATBoolean _StrongMode;
  // end cqi 02mar06
  // *** TO BE REMOVED WHEN A CORRECTION IS AVAILABLE ***

 protected :

 const CATEdge *_Solid ;
 const CATTopData * _Data;

private :

  CATLength GetLengthFromParamsPoly(const CATCrvParam & iParam1, const CATCrvParam & iParam2) const;
  HRESULT GetParamFromLengthPoly(const CATCrvParam &iParam, const CATLength & iLength, CATCrvParam & oParam) const;

  CATBoolean _IsInputPolyhedral;
};
  
  
#endif 
