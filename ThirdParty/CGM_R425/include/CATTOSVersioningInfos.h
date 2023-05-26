#ifndef CATTOSVersioningInfos_H 
#define CATTOSVersioningInfos_H
//
// COPYRIGHT DASSAULT SYSTEMES 2009

/**
* @level Private
* @usage U1
*/
// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMTos                         AuthorizedModule
#define CATOxiVersioningInfos             AuthorizedModule
#define CATDCInfraMappingTbl              AuthorizedModule
#define DWCFileConverter                  AuthorizedModule
#define CoexServices                      AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule 
#else
#error Forbidden access to CATTOSVersioningInfos from a non-authorized module
@error 
#endif
#undef CATPLMTos
#undef CATOxiVersioningInfos
#undef CATDCInfraMappingTbl
#undef DWCFileConverter
#undef CoexServices
// -----------------------------------------------------------------------------------------------

#include "ExportedByCATPLMTos.h"
#include "IUnknown.h"
#include "CATDataType.h"

class CATComponentId;
class CATBinary;

/**
* Usage is restricted.
*/
class ExportedByCATPLMTos CATTOSVersioningInfos
{
public:

  /**
  * Returns VersionID on a simple component
  * 
  * @param iSimpleComponent
  *        Simple component to work on
  * @param oVersionID
  *        The associated VersionID
  * @return
  *        S_OK     : if VersionID is available
  *        S_FALSE  : if VersionID is not available
  *        E_FAIL   : if failure
  */
  static HRESULT GetVersionID (const CATComponentId & iSimpleComponent, CATBinary & oVersionID) ;

};

#endif
