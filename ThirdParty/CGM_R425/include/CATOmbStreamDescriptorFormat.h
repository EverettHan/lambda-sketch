// COPYRIGHT Dassault Systemes 2005
//===================================================================
//  Mar 2005  Creation: Code generated by the CAA wizard  phb
//===================================================================
#ifndef CATOmbStreamDescriptorFormat_H
#define CATOmbStreamDescriptorFormat_H

/**
* @level  Protected
* @usage   U1
*/

#include "CATOmbSelectiveLoading.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATOmxKeyString.h"


//Horrible Hack, PLM3DSNavOpenServices and CATVPMExpandBuilder use CATOmbStreamDescriptorFormat but without linking on CATObjectModelerBase.dll
//=> while waiting them to add dependency, hack by keeping previous definition
#define OMB_CATOmbStreamDescriptorFormat_BUILD_HACK 0

#ifndef OMB_DISABLE_CATOmbStreamDescriptorFormat_BUILD_HACK
#if defined(_PLM3DSNavOpenServices_H) || defined(CATVPMExpandBuilder_H)
#define ProblematicModule 999
#define CATImmVPMRefreshExpand ProblematicModule
#define PLM3DNavOpenServices ProblematicModule
#if _MK_MODNAME_ == ProblematicModule
#undef OMB_CATOmbStreamDescriptorFormat_BUILD_HACK
#define OMB_CATOmbStreamDescriptorFormat_BUILD_HACK 1
#ifdef _WINDOWS_SOURCE
#pragma message("CATOmbStreamDescriptorFormat.h: inside PLM3DSNavOpenServices.cpp or CATVPMExpandBuilder.cpp, using enum definition")
#endif
#undef CATImmVPMRefreshExpand
#undef PLM3DNavOpenServices
#undef ProblematicModule
#endif
#endif



#endif

#if OMB_CATOmbStreamDescriptorFormat_BUILD_HACK == 0
class CATUnicodeString;
#define OMB_MAX_CATOmbStreamDescriptorFormat 9
/**
 * class repesenting a stream descriptor format.
 */
class ExportedByCATOmbSelectiveLoading CATOmbStreamDescriptorFormat: public CATOmxKeyString
{
public:
  /**ctor*/
  inline CATOmbStreamDescriptorFormat() {}

  /**ctor*/
  inline CATOmbStreamDescriptorFormat(const CATOmxKeyString& iName):CATOmxKeyString(iName) {}

  /** 
   * Converts this object to an integer value.
   * works only on legacy values CATOmbStreamDescriptorFormat_Unknown, CATOmbStreamDescriptorFormat_Authoring...
   */
  HRESULT ToInteger(int& oValue) const;

  /** 
   * Builds this object from integer value.
   * works only on legacy values CATOmbStreamDescriptorFormat_Unknown, CATOmbStreamDescriptorFormat_Authoring...
   */
  HRESULT FromInteger(int iValue);

  /**
   * Casts this object to an integer value, asserts if conversion is not possible.
   */
  operator int() const;

  /**
   * Builds this object from an integer value, asserts if conversion is not possible.
   */
  CATOmbStreamDescriptorFormat(int iValue);

};

/**
* Legacy formats for a Stream Descriptor.
*/
extern ExportedByCATOmbSelectiveLoading const CATOmbStreamDescriptorFormat CATOmbStreamDescriptorFormat_Unknown;
extern ExportedByCATOmbSelectiveLoading const CATOmbStreamDescriptorFormat CATOmbStreamDescriptorFormat_Authoring;
extern ExportedByCATOmbSelectiveLoading const CATOmbStreamDescriptorFormat CATOmbStreamDescriptorFormat_AuthoringVisu;
extern ExportedByCATOmbSelectiveLoading const CATOmbStreamDescriptorFormat CATOmbStreamDescriptorFormat_VisuRep;
extern ExportedByCATOmbSelectiveLoading const CATOmbStreamDescriptorFormat CATOmbStreamDescriptorFormat_NavRep;
extern ExportedByCATOmbSelectiveLoading const CATOmbStreamDescriptorFormat CATOmbStreamDescriptorFormat_IndexRep;
extern ExportedByCATOmbSelectiveLoading const CATOmbStreamDescriptorFormat CATOmbStreamDescriptorFormat_JpegThumbnail;
extern ExportedByCATOmbSelectiveLoading const CATOmbStreamDescriptorFormat CATOmbStreamDescriptorFormat_RCA;
extern ExportedByCATOmbSelectiveLoading const CATOmbStreamDescriptorFormat CATOmbStreamDescriptorFormat_AuthoringVisu2;
extern ExportedByCATOmbSelectiveLoading const CATOmbStreamDescriptorFormat CATOmbStreamDescriptorFormat_Similar;

/**
 * return TRUE for values inside [CATOmbStreamDescriptorFormat_Authoring,CATOmbStreamDescriptorFormat_AuthoringVisu2]
 */
ExportedByCATOmbSelectiveLoading CATBoolean	CATOmbIsValidStreamDescriptorFormat	( const CATOmbStreamDescriptorFormat&	iCandidateFormat );

/**
 * Converts a format to a string.
 *   CATOmbStreamDescriptorFormat_Authoring     => "Authoring"
 *   CATOmbStreamDescriptorFormat_AuthoringVisu => "AuthoringVisu" 
 *   ...
 */
ExportedByCATOmbSelectiveLoading HRESULT	CATOmbGetFormatAsString(const CATOmbStreamDescriptorFormat& iFormat,CATUnicodeString&	oFormatAsAtring);

/**
 * Builds a format from a string.
 *   CATOmbStreamDescriptorFormat_Authoring     <= "Authoring"
 *   CATOmbStreamDescriptorFormat_AuthoringVisu <= "AuthoringVisu" 
 *   ...
 */
ExportedByCATOmbSelectiveLoading HRESULT	CATOmbGetFormatFromString(const CATUnicodeString&	iFormatAsAtring,CATOmbStreamDescriptorFormat& oFormat);

#else

enum CATOmbStreamDescriptorFormat
{
	CATOmbStreamDescriptorFormat_Unknown = 0
	, CATOmbStreamDescriptorFormat_Authoring
	, CATOmbStreamDescriptorFormat_AuthoringVisu
	, CATOmbStreamDescriptorFormat_VisuRep
	, CATOmbStreamDescriptorFormat_NavRep
	, CATOmbStreamDescriptorFormat_IndexRep
  , CATOmbStreamDescriptorFormat_JpegThumbnail
  , CATOmbStreamDescriptorFormat_RCA
  , CATOmbStreamDescriptorFormat_AuthoringVisu2
  , CATOmbStreamDescriptorFormat_Similar
};

#endif

#endif
