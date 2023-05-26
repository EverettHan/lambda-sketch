/*
 * This is a PLMAdapter view of the CATIPLMXMLWriter interface
 * This should not be viewed by client of Adapter
 * only provider can use this kind of element
 * Class Description:
 * This class is the actual view of the CATIPLMXMLWriter view
*/

/**
* @level Protected
* @usage U3
*/

#ifndef CATIPLMMsgWriter_H
#define CATIPLMMsgWriter_H

#include "CATPLMImplAdapterItf.h"
#include "CATBaseUnknown.h"

class CATPLMID;
class CATUnicodeString;
class CATPLMCEStamp;

/**
 * This class defines the interface for the CATIPLMMsgWriter streamer.
 * It provides the service for writing XML stream and PLMIDs.
 */

class  ExportedByCATPLMImplAdapterItf CATIPLMMsgWriter : public CATBaseUnknown
{
public:
  virtual ~CATIPLMMsgWriter();

  /**
   * Close the streamer.
   * This is the place to store any streamer-specific deallocation.
   */
  virtual void Close() = 0;

  /**
   * Write a CATUnicodeString in the Stream
   * @param iStr the string to be written
   * Specific encoding such as UTF8 or UTF16 are used so that characters encoding is platform independent
   * The corresponding Reader must be used to properly decode the data
   * E_FAILED may be returned if the underlying stream is in a state that do not permit to do the operation
   */
  virtual HRESULT Write(const CATUnicodeString &iStr) = 0;

  /**
  * This call will write the ID using a compression like algorithm at the current position in the XML stream.
  * @param iID the CATPLMID that is to be written in the stream
  * * The corresponding Reader ( ENOVIPLMXMLReader on LCA server or CATIPLMXMLReader in CATIA ) must be used to properly decode the information
  * E_FAILED may be returned if the underlying stream is in a state that do not permit to do the operation or if the link is incorrect
  */
  virtual HRESULT WriteIdentifier(const CATPLMID & iID) = 0;

  /**
  * This call will write the CATPLMCEStamp using a compression like algorithm at the current position in the XML stream.
  * @param iCEStamp the CATPLMCEStamp that is to be written in the stream
  * The corresponding Reader ( ENOVIPLMXMLReader on LCA server or CATIPLMXMLReader in CATIA ) must be used to properly decode the information
  * E_FAILED may be returned if the underlying stream is in a state that do not permit to do the operation or if the link is incorrect
  */
  virtual HRESULT WriteCEStamp(const CATPLMCEStamp & iCEStamp) = 0;

};

#endif
