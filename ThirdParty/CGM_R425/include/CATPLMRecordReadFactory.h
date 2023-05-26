// COPYRIGHT Dassault Systemes 2020
//===================================================================
// CATPLMRecordReadFactory.h
// Header definition of CATPLMRecordReadFactory
//===================================================================
// Usage notes:
// Objects (bo/rel) returned by server (3DSpace) or by index (Cloud View)
// are access in memory using CATIPLMRecordRead.
//
// WARNING, WARNING, WARNING!
// Component implementing CATIPLMRecordRead can change at any time
//===================================================================
//  June 2020  Creation: EPB
//===================================================================

#ifndef CATPLMRecordReadFactory_H
#define CATPLMRecordReadFactory_H

#if defined (private) || defined(friend) || defined (protected)
#error Forbidden re-define of 'private', 'friend' or 'protected'
// Fatal error on solaris
@error
#endif

#define AuthorizedModule     999

// List of authorized infrastructure modules 
#define CATPLMServicesItf                     AuthorizedModule
#define CATImmVPMRefreshExpand                AuthorizedModule
// odt
#define TSTCATPLMOM                           AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else
#error Forbidden Access To CATPLMRecordReadFactory Services from a non-authorized module
  // Fatal error on solaris
  @error
#endif

#undef AuthorizedModule

  // List of authorized infrastructure modules 
#undef CATPLMServicesItf
#undef CATImmVPMRefreshExpand
// odt
#undef TSTCATPLMOM

#if defined(__CATPLMServicesItf)
#define ExportedByCATPLMServicesItf DSYExport
#else
#define ExportedByCATPLMServicesItf DSYImport
#endif
#include "DSYExport.h"

#include "CATPLMStrongRelationshipId.h"

#include "CATOmxAutoPtr.h"

class CATIPLMRecordRead;
class CATBinary;
class CATPLMID;
class CATIPLMRecordReadAdapterImplExposed;

class ExportedByCATPLMServicesItf CATPLMRecordReadFactory
{
public:
  CATPLMRecordReadFactory();
  ~CATPLMRecordReadFactory();

  /**
   * Create.
  * Usage restricted to BusinessObject (RelationType, Port and Connection are refused)
  * @return CATBaseUnknown#Release
  */
  CATIPLMRecordRead* Create(const CATPLMID& iPlmid, const CATBinary& iCestampAsBin);

  /**
   * Create.
  * Usage restricted to RelationType (BusinessObject, Port and Connection are refused)
  * @return CATBaseUnknown#Release
  */
  CATIPLMRecordRead* Create(const CATPLMID& iPlmid, const CATBinary& iCestampAsBin,
    CATPLMStrongRelationshipId::eStrongRelId iParentStrongRelId, const CATPLMID& iParentPlmid,
    CATPLMStrongRelationshipId::eStrongRelId iChildStrongRelId, const CATPLMID& iChildPlmid);
private:
  CATIPLMRecordReadAdapterImplExposed* _GetToolsFactory();

  CATOmxAutoPtr<CATIPLMRecordReadAdapterImplExposed> _sp;

  // Copy constructor and equal operator
  // -----------------------------------
  CATPLMRecordReadFactory(const CATPLMRecordReadFactory &);
  CATPLMRecordReadFactory& operator=(const CATPLMRecordReadFactory&);
};

#endif
