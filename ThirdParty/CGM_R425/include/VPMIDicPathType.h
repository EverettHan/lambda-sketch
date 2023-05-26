//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2014
//=============================================================================
// Usage notes: used to introspect the different PathTypes
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicPathType_h
#define _VPMIDicPathType_h

#include "VPMIDicInterfaces.h"
#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"
#include "VPMIDicWithAttributes.h"
//#include "VPMDicTYPE.h"
#include "VPMDicSYNCHROSENSITIVITY.h"
#include "VPMDicORIENTATION.h"
#include "VPMDicPROTECTION.h"

class VPMIDicElement_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicPathType;
#else
extern "C" const IID IID_VPMIDicPathType;
#endif


/**
 * Interface to manage the PathTypes which are particular concepts of the dictionary. Also called Global Path types as opposed to Path
 */

class ExportedByVPMIDicInterfaces VPMIDicPathType : public VPMIDicWithAttributes 
{
  CATDeclareInterface;

public:

  /**
  * Generates the information for the persistence of the paths that will be created from this particular path type.
  * @param oPathTypeName : name of the path type
  * @param oRoleName : value to be put in the role attribute. May be empty, once it won't be mandatory anymore to declare role
  * @param oCategoryName : value to be put in the category attribute. . May be empty, once it won't be mandatory anymore to declare category
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetPathCharacteristics ( CATUnicodeString & oPathTypeName, CATUnicodeString & oRoleName, CATUnicodeString & oCategoryName ) const = 0;

  virtual boolean IsMultivaluated() const =0;
  virtual boolean IsAdaptativeToMinor() const =0;
  virtual boolean IsRerouteOnEffectivity() const =0;
  virtual HRESULT GetSynchroSensitivity(VPMDicSYNCHROSENSITIVITY & oSynchroSensitivity) const =0;
  virtual HRESULT GetOrientation(VPMDicORIENTATION & oOrientation) const =0;
  virtual HRESULT GetProtection(VPMDicPROTECTION & oProtection) const =0;

};

CATDeclareHandler( VPMIDicPathType, VPMIDicWithAttributes );

#endif
