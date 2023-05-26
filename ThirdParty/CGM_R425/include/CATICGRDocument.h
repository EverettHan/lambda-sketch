// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATICGRDocument.h
// Define the CATICGRDocument interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Mar 2003  Creation: Code generated by the CAA wizard  jut
//===================================================================
#ifndef CATICGRDocument_H
#define CATICGRDocument_H

#include "SGInfra.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySGInfra IID IID_CATICGRDocument;
#else
extern "C" const IID IID_CATICGRDocument ;
#endif

class CATUnicodeString;
class CATCGRContainer;
class CATCGRContainerPath;

//------------------------------------------------------------------

/**
 * Describe the functionality of your interface here
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 */
class ExportedBySGInfra CATICGRDocument: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
     * Remember that interfaces define only virtual pure methods.
     * Dont forget to document your methods.
     * <dl>
     * <dt><b>Example:</b>
     * <pre>
     *       
           *   MyFunction does this and that
           *   @param Arg1
           *      The first argument of MyFunction.
           *   @return
           *      Error code of function.
           * 
     * virtual int MyFunction (int Arg1) = 0;
     * </pre>
     * </dl>
     */
     virtual CATCGRContainer * GetCGRContainer(const CATUnicodeString & iName, int recursiveUnstreaming = 1) = 0;
     virtual CATCGRContainer * GetCGRContainer(const CATCGRContainerPath & iPath, int recursiveUnstreaming = 1) = 0;

    /**
     * Fetch the CGR stream into a buffer
     * !!! This METHOD is currently for MechMod product only.
     * @return
     * <br /><strong>Legal values</strong>:
     *   <li><code>S_OK</code>
     *      when the cgr document stream has be succesfully fecthed into a buffer.</li>
     *   <li><code>E_FAIL</code>
     *      when the cgr document stream couldn't have been fetched into a buffer. Generic Error</li>
     *   <li><code>E_OUTOFMEMORY</code>
     *      when the cgr document stream couldn't have been fetched into a buffer. there is nont enough memory to allocate the buffer</li>
     * @param oBuffer
     *   The buffer containing the cgr document stream.
     *   The buffer is allocated by the method but its lifecycle is UP TO THE CALLER (must be destroyed trough free statement)
     * @param oBuffer
     *   The buffer size in bytes
     */
     virtual HRESULT FetchIntoCGRBuffer(char *&oBuffer, int &oLBuffer) = 0;
};

//------------------------------------------------------------------

CATDeclareHandler( CATICGRDocument, CATBaseUnknown );

#endif
