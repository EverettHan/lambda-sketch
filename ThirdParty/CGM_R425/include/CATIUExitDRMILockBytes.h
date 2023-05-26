/* COPYRIGHT DASSAULT SYSTEMES 2006 */
/**
 * @CAA2Level L0
 * @CAA2Usage U5
 */

#ifndef CATIUExitDRMILockBytes_H
#define CATIUExitDRMILockBytes_H

#include "CATWTypes.h"
#include "CATUnicodeString.h"
#include "CATILockBytes.h"
#include "CATErrorDef.h"

#ifdef __JS0DRMDOC

#define ExportedByJS0DRMDOC DSYExport
#else
#define ExportedByJS0DRMDOC DSYImport
#endif
#include "DSYExport.h"




extern "C" const IID IID_CATIUExitDRMILockBytes;


/**
 * Interface to enable customer specific actions on files.
 * <b>Role</b>: This interface is a user exit, that allows a customer in 
 * particular to audit files usage, manage data integrity or data 
 * confidentiality for all files manipulated by the V5-code. 
 * <br>You should implement it on the <tt>CATUExitDRMILockBytes</tt> 
 * component by creating a data extension.
 * This interface inherits from @href CATILockBytes. When implementing the 
 * inheritated methods note that :
 * <ol>
 * <li>All the given offsets and lengths are referring to those of  the document
 *     before taking any action. This is a key point in order to get a correct
 *     behaviour of the @href #ReadAt and @href #WriteAt methods with the V5
 *     composite documents.</li><p>
 *
 * <li>The size returned by the @href #Stat method must reflect the size of 
 *     the  document before taking any action.  This means if your 
 *     implementation is bufferized, that you must take into account the 
 *     current physical size of the array and the size of the unflushed memory
 *     buffers. This size is used to determine where the next write can occur.
 *     </li><p>
 *
 * <li>In addition to the already defined in @href CATILockBytes error codes 
 *     the reading and writing methods have to returned DRM_E_CRYPTCORRUPTION
 *     when the action has failed, or DRM_E_NOKEY if no valid information
 *     has been provided for initializing the action.</li><p>
 *
 **/
class ExportedByJS0DRMDOC  CATIUExitDRMILockBytes : public CATILockBytes
{
public:
/**
 * Defines the way to open the CATILockbytes 
 * <br><b>Role</b>:Defines the way to open the CATILockBytes. This method must
 * be thread safe. 
 * @param iILB
 *      Pointer to an ILockBytes object that is provided by the application. This
 *      object has to be used for the physical writing and reading. It is provided
 *      by the V5 code. The user exit should not make any assumption about the
 *      physical repository of the provided ILockBytes object.
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> STG_E_INVALIDHANDLE :</tt> invalid pointer
 *   <br><tt> STG_E_INSUFFICIENTMEMORY :</tt> no more memory to make the open.
 *   <br><tt> STG_E_UNKNOWN :</tt> unexpected error.
 *   <br><tt> DRM_E_NODLL :</tt> No DRM User Exit implementation is available.
*/
  virtual HRESULT  OpenOnILockBytes( CATILockBytes * iILB)=0;



/**
 * Closes the CATILockbytes 
 * <br><b>Role</b>:Closes the CATILockBytes. After this call, the ReadAt and
 * WriteAt will be no more possible. In the implementation of this method one 
 * had to Release the CATILockbytes that has been provide by through the call to
 * @href  #OpenOnILockBytes .
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> STG_E_INVALIDHANDLE :</tt> invalid pointer
 *   <br><tt> STG_E_UNKNOWN :</tt> unexpected error.
*/  
  virtual HRESULT Close()=0;

};

#endif



