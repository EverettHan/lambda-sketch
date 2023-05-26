// COPYRIGHT DASSAULT SYSTEMES 2012
//=============================================================================
//
// CATAfrLoaderUtils.h
//   Loader related utilities.
//
//=============================================================================
//
// Usage notes:
//
//=============================================================================
//      ???     03/06/2012  original implementation
//=============================================================================

#ifndef CATAfrLoaderUtils_h
#define CATAfrLoaderUtils_h

#include <CATAfrFoundation.h>
#include <CATString.h>
#include <CATBaseUnknown.h>

class ExportedByCATAfrFoundation CATAfrLoaderUtils 
{
public:

    /**
     * Retrieves the workshop context from loader.
     * 
     * @param oCtxFromLoader
     *   context retrieved from loader
     *
     * @return 
     *   <b>Legal values</b>:
     *   <ul>
     *     <li>S_OK   : The method has succeeded</li>
     *     <li>E_FAIL : if an error occurs.</li>
     *   </ul>
     **/
    static HRESULT GetContextFromLoader( CATString& oCtxFromLoader );
    /**
     * Sets the workshop context from loader.
     * 
     * @param iCtxFromLoader
     *   context retrieved from loader
     *
     * @return 
     *   <b>Legal values</b>:
     *   <ul>
     *     <li>S_OK   : The method has succeeded</li>
     *     <li>E_FAIL : if an error occurs.</li>
     *   </ul>
     **/
    static HRESULT SetContextFromLoader( const CATString iCtxFromLoader );

private:

    static CATString   _spCtxFromLoader;

};

#endif
