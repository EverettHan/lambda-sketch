// (C) Copyright Dassault Systemes - 2006
// -----------------------------------------------------------------------
// Interface declaration: PLMIPosSecurityStreamWriter
// -----------------------------------------------------------------------
// Creation: 2006-06-13
// -----------------------------------------------------------------------
/**
 * @level Protected
 * @usage U3
 */

#ifndef _PLMIPosSecurityStreamWriter_H_
#define _PLMIPosSecurityStreamWriter_H_

#include "CATBaseUnknown.h"

#include "ExportedByGUIDPLMPosBaseInterfaces.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDPLMPosBaseInterfaces IID IID_PLMIPosSecurityStreamWriter;
#else
extern "C" const IID IID_PLMIPosSecurityStreamWriter;
#endif



/** @nodoc */
class PLMIStreamWriter;
/** @nodoc */
class PLMIStreamReader;

/** @nodoc */
class ExportedByGUIDPLMPosBaseInterfaces PLMIPosSecurityStreamWriter : public CATBaseUnknown
{
    CATDeclareInterface;
public:
    /**
     * Write security engine's cache to StreamWriter (binary).
     * returns:
     * S_OK      when the cache could be sent to writer
     * FAILED()  when an error occured
     */
    virtual HRESULT Write(PLMIStreamWriter * ivWriter) = 0;
    /**
     * Read security engine's cache from StreamReader (binary).
     * returns:
     * S_OK      when the cache could be sent to writer
     * FAILED()  when an error occured
     */
    virtual HRESULT Read(PLMIStreamReader * ivReader) = 0;
    /**
     * Write security engine's cache to StreamWriter (binary).
     * Only data required by the index server are sent.
     * returns:
     * S_OK      when the cache could be sent to writer
     * FAILED()  when an error occured
     */
    virtual HRESULT WriteToIndexServer(PLMIStreamWriter * ivWriter) = 0;
};

/** @nodoc */
CATDeclareHandler(PLMIPosSecurityStreamWriter,CATBaseUnknown);

#endif
