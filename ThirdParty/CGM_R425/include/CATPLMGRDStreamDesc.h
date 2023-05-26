// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATPLMGRDStreamDesc.h
// Header definition of CATPLMGRDStreamDesc
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2005  Creation: Code generated by the CAA wizard  jvm
//===================================================================
/**
* @level Protected
* @usage U1
*/
#ifndef CATPLMGRDStreamDesc_H
#define CATPLMGRDStreamDesc_H

#include "CATPLMServicesItf.h"
#include "CATPLMStreamDescriptor.h"

//-----------------------------------------------------------------------

/**
* Stream Descriptor : provides description of Stream.
* Identifier of Stream is composed by Format and Role. these values provide the Stream UID for a PLM Component.
*/
class ExportedByCATPLMServicesItf CATPLMGRDStreamDesc: public CATPLMStreamDescriptor
{
  CATDeclareClass;
public:

  // Standard constructors and destructors
  // -------------------------------------
  CATPLMGRDStreamDesc (CATPLMStreamDescriptor *iStreamDesc, const CATUnicodeString & iVVSUrl);
  CATPLMGRDStreamDesc(const CATPLMSDProperties& iSD);

  CATPLMGRDStreamDesc ( int iFormat,
                        const CATUnicodeString &iRole,
                        const CATUnicodeString &iTypeLate,
                        int iMarkStamp,
                        const CATUnicodeString & iPersistancyType,
                        const CATUnicodeString & iVVSUrl );

  CATPLMGRDStreamDesc ( int iFormat,
                        const CATUnicodeString &iRole,
                        const CATUnicodeString &iTypeLate,
                        int iMarkStamp,
                        const CATUnicodeString & iPersistancyType,
                        const CATUnicodeString & iPersistancyName,
                        const CATUnicodeString & iVVSUrl );

  CATPLMGRDStreamDesc( int iFormat,
                       const CATUnicodeString & iRole,
                       const CATUnicodeString & iTypeLate,
                       const CATUnicodeString & iMarkStamp,
                       const CATUnicodeString & iSynchroStamp,
                       const CATUnicodeString & iPersistancyType,
                       const CATUnicodeString & iPersistancyName,
                       const CATUnicodeString & iVVSUrl);

  CATPLMGRDStreamDesc( int iFormat,
                       const CATUnicodeString & iRole,
                       const CATUnicodeString & iTypeLate,
                       const CATUnicodeString & iMarkStamp,
                       const CATUnicodeString & iSynchroStamp,
                       const CATUnicodeString & iPersistancyType,
                       const CATUnicodeString & iPersistancyName,
                       const CATBoolean & iIsLargeFile,
                       const CATUnicodeString & iVVSUrl);

  
  CATPLMGRDStreamDesc(const CATOmxKeyValueBlock& iBlock, const CATUnicodeString & iVVSUrl);
  CATPLMGRDStreamDesc(){}

	virtual ~CATPLMGRDStreamDesc ();

  /**
   *	Returns the Water MarkStamp. (unsigned int) Used to identified the iteration of the stream
   */
  HRESULT GetVVSUrl  ( CATUnicodeString &oVVSUrl) const;

};

//-----------------------------------------------------------------------

#endif
