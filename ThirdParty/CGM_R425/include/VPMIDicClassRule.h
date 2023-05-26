//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2012
//=============================================================================
/**
* @level Private
* @usage U3
*/
#ifndef _VPMIDicClassRule_h
#define _VPMIDicClassRule_h

#include "VPMIDicInterfaces.h"

#include "CATString.h"
#include "IUnknown.h"
#include "VPMIDicElement.h"

#include "CATLISTV_VPMIDicClassPatternConstraint_var.h"
#include "CATLISTV_VPMIDicSemanticRelation_var.h"
#include "CATLISTV_VPMIDicSRPatternConstraint_var.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicClassRule;
#else
extern "C" const IID IID_VPMIDicClassRule;
#endif

class VPMIDicClassPatternConstraint;
class VPMIDicClassPatternConstraint_var;
class VPMIDicSemanticRelation;
class VPMIDicSemanticRelation_var;
class VPMIDicSRPatternConstraint;
class VPMIDicSRPatternConstraint_var;

/**
* Interface to manage the VPMIDicClassRule.
*/

class ExportedByVPMIDicInterfaces VPMIDicClassRule : public VPMIDicElement
{
  CATDeclareInterface;
public:

  /* @deprecated */  virtual HRESULT GetClassPatternConstraint     ( const CATString & iName, VPMIDicClassPatternConstraint ** oDicClassPatternConstraint ) = 0; 
  /* @deprecated */  virtual HRESULT GetClassPatternConstraintList ( CATLISTP(IUnknown) * oClassPatternConstraintList ) = 0; 
  virtual HRESULT GetClassPatternConstraint     ( const CATString & iName, VPMIDicClassPatternConstraint_var & oDicClassPatternConstraint ) = 0;
  virtual HRESULT GetClassPatternConstraintList ( CATLISTV_VPMIDicClassPatternConstraint_var & oClassPatternConstraintList ) = 0;

  /* @deprecated */  virtual HRESULT GetSemanticRelation     ( const CATString & iName, VPMIDicSemanticRelation ** oDicSemanticRelation ) = 0;
  /* @deprecated */  virtual HRESULT GetSemanticRelationList ( CATLISTP(IUnknown) * oSemanticRelationList ) = 0;
  virtual HRESULT GetSemanticRelation     ( const CATString & iName, VPMIDicSemanticRelation_var & oDicSemanticRelation ) = 0;
  virtual HRESULT GetSemanticRelationList ( CATLISTV_VPMIDicSemanticRelation_var & oSemanticRelationList ) = 0;

  /* @deprecated */  virtual HRESULT GetPatternConstraint     ( const CATString & iName, VPMIDicSRPatternConstraint ** oDicSRPatternConstraint ) = 0;
  /* @deprecated */  virtual HRESULT GetPatternConstraintList ( CATLISTP(IUnknown) * oPatternConstraintList ) = 0;
  virtual HRESULT GetPatternConstraint     ( const CATString & iName, VPMIDicSRPatternConstraint_var & oDicSRPatternConstraint ) = 0;
  virtual HRESULT GetPatternConstraintList ( CATLISTV_VPMIDicSRPatternConstraint_var & oPatternConstraintList ) = 0;

};

CATDeclareHandler( VPMIDicClassRule, VPMIDicElement );

#endif
