#ifndef CATPLMCommunicationStreamFactory_h
#define CATPLMCommunicationStreamFactory_h

#include "CATOMYCommunication.h"
#include "CATIComSidlOutputStream.h"
#include "CATIComSidlInputStream.h"
#include "CATUnicodeString.h"

class CATOmyStreamHandler;
class ExportedByCATOMYCommunication CATPLMCommunicationStreamFactory
{
public:
  /** 
  * Create an output stream that write data in the 2 given output stream
  *
  * @param iFirstStream [in]
  *   The first output stream where to write data
  * @param iSecondStream [in]
  *   The second output stream where to write data
  *
  * @return
  *   The wrapping output stream
  *
  */
  static CATIComSidlOutputStream_var CreateOutputStreamDuplicator(
    CATIComSidlOutputStream * iFirstStream, CATIComSidlOutputStream * iSecondStream);

  /** 
  * Create an input stream that reads data from the given input stream and copy
  * it in the given output stream
  *
  * @param iStreamToRead [in]
  *   The input stream to read
  * @param iTraceStream [in]
  *   The output stream where to write
  *
  * @return
  *   The wrapped input stream
  *
  */
  static CATIComSidlInputStream_var  CreateInputStreamDuplicator(
    CATIComSidlInputStream * iStreamToRead, CATIComSidlOutputStream * iStreamWhereToWrite);

  /** 
  * Short role of the method.
  *
  * <br><b>Role</b>: Explain what this method does.
  *
  * @param iStreamWhereToPutTheData [in]
  *   The parameter role...
  *
  * @return
  *   Explain return values
  *
  */
  static CATIComSidlOutputStream_var CreateOutputStreamToCATStream(
    CATOmyStreamHandler * iStreamWhereToPutTheData);


  /** 
  * Open a stream from a file (plmql, dataset)
  *
  * <br><b>Role</b>: In order to pass an output stream to a tube, this method shall be used.
  *
  * @param iFileName [in]
  *   The file to open
  *
  * @return
  *   The stream
  *
  */
  static CATIComSidlInputStream_var CreateInputStreamFromFile(
    const CATUnicodeString &iDatasetFileName);

  /** 
  * Open a stream from an unicode string
  * <br><b>Role</b>: In order to pass an output stream to a tube, this method shall be used.
  *
  * @param iFileName [in]
  *   The file to open
  *
  * @return
  *   The stream
  *
  */
  static CATIComSidlInputStream_var CreateInputStreamFromUnicodeString(
    const CATUnicodeString &iString);

  /** 
  * Short role of the method.
  *
  * <br><b>Role</b>: Explain what this method does.
  *
  * @param iStreamWhereToFindTheData [in]
  *   The parameter role...
  *
  * @return
  *   Explain return values
  *
  */

  
  static CATIComSidlInputStream_var CreateInputStreamFromCATStream(
    CATOmyStreamHandler * iStreamWhereToFindTheData);

  /** 
  * Creates an output stream that will write the data on a dump file.
  * Those traces can't be used for input data.
  *
  * @param iPathToFile [in]
  *   The file path where to put the traces.
  *
  * @return
  *   The ouput stream
  */
  static CATIComSidlOutputStream_var CreateOutputStreamToTextFile(
    const CATUnicodeString & iPathToFile);

  /** 
  * Separates the given output stream in two streams, one containing the 
  * VPLMSession data, the other one containing the PLMQL data
  *
  * @param iVPLMSessionStream [in]
  *   The stream where to put the VPLMSession data
  * @param iPLMQLStream [in]
  *   The stream where to put the PLMQL data
  *
  * @return
  *   The ouput stream
  */
  static CATIComSidlOutputStream_var CreateOutputStreamToExtractVPLMSessionFromPLMQL(
    CATIComSidlOutputStream * iVPLMSessionStream, CATIComSidlOutputStream * iPLMQLStream);

  /** 
  * Create an input stream from a buffer
  *
  * @param iHandler [out]
  *   The stream where to find the data
  *
  * @return
  *   The input stream
  */
  static CATIComSidlInputStream_var CreateStreamToBufferInputStream(CATOmyStreamHandler *iHandler);
};
#endif
