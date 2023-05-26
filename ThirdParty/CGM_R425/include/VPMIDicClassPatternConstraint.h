//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicClassPatternConstraint_h
#define _VPMIDicClassPatternConstraint_h

#include "VPMIDicInterfaces.h"

#include "CATString.h"
#include "CATBaseUnknown.h"
#include "VPMIDicElement.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicClassPatternConstraint;
#else
extern "C" const IID IID_VPMIDicClassPatternConstraint;
#endif

class VPMIDicSRContextConstraint;
class VPMIDicSRPatternConstraint;

/**
* Interface to manage the VPMIDicClassPatternConstraint.
*/

class  ExportedByVPMIDicInterfaces VPMIDicClassPatternConstraint: public VPMIDicElement
{
  CATDeclareInterface;
public:

  virtual HRESULT GetValidityCheck ( CATString &oValidityCheck ) const = 0;

  virtual HRESULT GetRelationsPattern ( CATString &oRelationsPattern ) const = 0;

  virtual HRESULT GetIdCode ( CATString & oIdCode ) const = 0;

};

CATDeclareHandler( VPMIDicClassPatternConstraint, VPMIDicElement );

#endif


