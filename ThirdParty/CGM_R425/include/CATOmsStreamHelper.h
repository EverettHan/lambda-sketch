/**
 * @level Private
 * @usage U1
 */
#ifndef CATOmsStreamHelper_H
#define CATOmsStreamHelper_H

#include "OMSCompositeStream.h"
#include "CATWOmxBinaryStream.h"

/**
 * obsolete, use CATWOmxBinaryStream directly.
 */
class ExportedByOMSCompositeStream CATOmsStreamHelper: public CATWOmxBinaryStream
{ 
public:
    CATOmsStreamHelper(CATStream *Stream);
    
    /**
    * <dl>
    * <dt><b>Read a char stored in a stream to determine the endian_ness of the stream</b>
    * <Role> This method should always be used first on any stream read. 
    *        It will check the endian_ness of the machine and the endian_ness of the stream and will decide 
    *        whether conversion is required
    * 
    * <pre>
    *   @return
    *     S_OK         : succeeded
    *     E_FAIL       : Unexplained failure
    * </pre>
    * </dl>
    */
    HRESULT ReadEndian();
    /**
    * <dl>
    * <dt><b>Write a char stored in a stream to store the endian_ness of the stream</b>
    * <Role> This method should always be used first on any stream written. 
    *        It will store the endian_ness used to create the stream
    * 
    * <pre>
    *   @return
    *     S_OK         : succeeded
    *     E_FAIL       : Unexplained failure
    * </pre>
    * </dl>
    */
    HRESULT WriteEndian();
};

#endif


