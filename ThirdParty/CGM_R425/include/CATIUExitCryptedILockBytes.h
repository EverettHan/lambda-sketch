/* COPYRIGHT DASSAULT SYSTEMES 2004 */

#ifndef CATIUExitCryptLockBytes_H
#define CATIUExitCryptLockBytes_H

#include "CATWTypes.h"
#include "CATILockBytes.h"
#include "CATErrorDef.h"
#include "CATTSLib.h"


class CATUnicodeString;

extern "C" const IID IID_CATIUExitCryptedILockBytes;


/**
 * Interface to enable customer specific actions on files.
 * <b>Role</b>: This interface is a user exit, that allows a customer in 
 * particular to audit files usage, manage data integrity or data 
 * confidentiality for all files manipulated by the V5-code. 
 * <br>You should implement it on the <tt>CATUExitCryptedILockBytes</tt> 
 * component by creating a data extension.
 * This interface inherits from @href CATILockBytes. When implementing the 
 * inheritated methods note that :
 * <ol>
 * <li>All the given offsets and lengths are those of the document before taking
 *     any action. This is a key point in order to get a correct
 *     behaviour of the @href #ReadAt and @href #WriteAt methods with the V5
 *     composite documents.</li><p>
 *
 * <li>The size returned by the @href #Stat method must reflect the size of the
 *     document before taking any action. This means if your 
 *     implementation is bufferized, that you must take into account the 
 *     current physical size of the array and the size of the unflushed memory
 *     buffers. This size is used to determine where the next write can occur.
 *     </li><p>
 *
 * <li>In addition to the already defined in @href CATILockBytes error codes 
 *     the reading and writing methods have to returned STG_E_DOCFILECORRUPT
 *     when the action has failed.</li><p>
 *
 * <li>From the methods that are not inheritated from @href CATILockBytes only
 *     @href #Open and @href #Close will be used for manipulating V5 documents.
 * </li><p>
 *
 * <li>As the sharing mode of the array is specified in the @href #Open, it
 *     is not necessary to implement the @href #LockRegion and 
 *     @href #UnlockRegion.</li><p>
 * 
 **/
class  CATIUExitCryptedILockBytes : public CATILockBytes
{
public:
/**
 * Defines the way to open the CATILockbytes
 * <br><b>Role</b>:Defines the way to open the CATILockBytes.
 * @param iMode
 *      The global opening mode used by the V5 documents. This mode is not to
 *      be analysed, but should be stored to be returned in the grfMode field
 *      of a STATSTG structure upon a call to the Stat method.
 *      For non V5-documents it will be 0 and never used.
 * @param iOpenMode 
 *      Opening mode 
 * @param iSharingMode
 *      Sharing mode
  * @param  iOpenFlag 
 *       flag for specifying the open processing 
 * @param  iSpecialFlag
 *       flag for specifying special behavior.
 *	<b>Legal values</b>:
 *	<br><tt>1 :</tt> the file is deleted on close.
 *	 <br><tt>0 :</tt> Nothing
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> STG_E_INVALIDNAME :</tt> invalid name for the document.
 *   <br><tt> STG_E_ACCESSDENIED:</tt> access to the document not granted.
 *   <br><tt> STG_E_LOCKVIOLATION :</tt> document locked by another process.
 *   <br><tt> STG_E_NOMOREFILES :</tt> too many opened files
 *   <br><tt> STG_E_INVALIDPARAMETER :</tt> arguments incorrect.
 *   <br><tt> STG_E_DOCFILECORRUPT :</tt> document can not be read.
 *   <br><tt> STG_E_FILENOTFOUND :</tt> document can not be found.
 *   <br><tt> STG_E_PATHNOTFOUND :</tt> The path of the document could 
 *                                      not be found.
 *   <br><tt> STG_E_INSUFFICIENTMEMORY :</tt> no more memory to make the open.
 *   <br><tt>STG_E_DISKISWRITEPROTECTED:</tt> open in write impossible on a 
 *					      write-protected disk.
 *   <br><tt> STG_E_UNKNOWN :</tt> unexpected error.
*/
virtual HRESULT  Open( const CATUnicodeString *iPath, 
		       DWORD iMode,
		       CATSysOpenMode iOpenMode, 
		       CATSysSharing iSharingMode, 
		       CATSysCreateMode iOpenFlag, 
		       CATSysCloseMode iCloseFlag= CATSys_Close)=0;


/**
 * Defines the way to open the CATILockbytes
 * <br><b>Role</b>:Defines the way to open the CATILockBytes. This method must
 * be thread safe. The other open method with @href CATUnicodeString argument
 * can not be used in a threading context.
 * @param iPath
 *      Pointer to the wide char string null terminated defining the path.
 * @param iMode
 *      The global opening mode used by the V5 documents. This mode is not to
 *      be analysed, but should be stored to be returned in the grfMode field
 *      of a STATSTG structure upon a call to the Stat method.
 *      For non V5-documents it will be 0 and never used.
 * @param iOpenMode 
 *      Opening mode 
 * @param iSharingMode
 *      Sharing mode
  * @param  iOpenFlag 
 *       flag for specifying the open processing 
 * @param  iSpecialFlag
 *       flag for specifying special behavior.
 *	<b>Legal values</b>:
 *	<br><tt>1 :</tt> the file is deleted on close.
 *	 <br><tt>0 :</tt> Nothing
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> STG_E_INVALIDNAME :</tt> invalid name for the document.
 *   <br><tt> STG_E_ACCESSDENIED:</tt> access to the document not granted.
 *   <br><tt> STG_E_LOCKVIOLATION :</tt> document locked by another process.
 *   <br><tt> STG_E_NOMOREFILES :</tt> too many opened files
 *   <br><tt> STG_E_INVALIDPARAMETER :</tt> arguments incorrect.
 *   <br><tt> STG_E_DOCFILECORRUPT :</tt> document can not be read.
 *   <br><tt> STG_E_FILENOTFOUND :</tt> document can not be found.
 *   <br><tt> STG_E_PATHNOTFOUND :</tt> The path of the document could 
 *                                      not be found.
 *   <br><tt> STG_E_INSUFFICIENTMEMORY :</tt> no more memory to make the open.
 *   <br><tt>STG_E_DISKISWRITEPROTECTED:</tt> open in write impossible on a 
 *					      write-protected disk.
 *   <br><tt> STG_E_UNKNOWN :</tt> unexpected error.
*/
virtual HRESULT  OpenW( const CATUC2Bytes * iPath, 
			DWORD iMode,
			CATSysOpenMode iOpenMode, 
			CATSysSharing iSharingMode, 
			CATSysCreateMode iOpenFlag, 
			CATSysCloseMode iCloseFlag= CATSys_Close)=0;



/**
 * Closes the CATILockBytes.
 * <br><b>Role</b>: Closes the CATILockBytes.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
*/
  virtual HRESULT Close() = 0;




/**
 * Reads and retrieves a block of data.
 * <br><b>Role</b>: Reads a block of data in a  ILockBytes from the 
 * current offset in the file and returns the intial data before action.
 * This method will be only used for non V5 documents.
 * @param  iBuff [in]
 *  Buffer where the modified data where will be stored.
 * @param iLengthToRead [i]
 *   the size of of the requested data.
 * @param oLengthRead [out]
 *   the actual length of read data.
 * @return
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> STG_E_READFAULT :</tt> problem while reading.
 *   <br><tt> STG_E_INVALIDPARAMETER :</tt> arguments incorrects.
 *   <br><tt> STG_E_DOCFILECORRUPT  :</tt> document can not be retrieved.
 *   <br><tt> STG_E_UNKNOWN :</tt> unexpected error.
*/    
  virtual  HRESULT Read(   void  *iBuff,
			   ULONG iLengthToRead,
			   ULONG *oLengthRead) = 0;


/**
 * Applies action and writes a block of data.
 * <br><b>Role</b>: Writes a block of data at the current offset, after applying
 * the action. This method  will be only used for non V5 documents.
 * @param  iDataSource [in]
 *  Buffer of not initial data to write.
 * @param iLengthToWrite [in]
 *   the size of of the data to write.
 * @param oLengthWriten [out]
 *   the actual length of written data. Should be equal to iLengthToWrite if 
 *   no problem has occurred.
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> STG_E_WRITEFAULT :</tt> problem while writing.
 *   <br><tt> STG_E_MEDIUMFULL :</tt> disk full error.
 *   <br><tt> STG_E_INVALIDPARAMETER :</tt> arguments incorrects.
 *   <br><tt> STG_E_DISKISWRITEPROTECTED :</tt> disk write protected.
 *   <br><tt> STG_E_INVALIDFUNCTION:</tt> unable to apply action on data.
 *   <br><tt> STG_E_UNKNOWN :</tt> unexpected error.
*/          
  virtual  HRESULT Write( const void *iDataSource,
			  ULONG iLengthToWrite,
			  ULONG  *LengthWritten) = 0;


/**
 * Reads in the file and returns a line.
 * <br><b>Role</b>: Reads in file and return data as before applying the action
 * up to the number of bytes specified by iNb parameter minus 1, or until a 
 * new-line character and transfers that character to the ioLine parameter, or 
 * until it encounters an end-of-file condition. The method then build a 
 * CATUnicodeString.
 * This method will never be called for V5 documents. 
 * @param  ioLine [inout]
 *  line Buffer of at least iNb size.
 * @param iNb [i]
 *   max number of character to read.
 * @param oEof[o]
 *   to indicate if the end of the file as been reached.
 *   <br><tt> 1 :</tt> End of file has been reached. In this case the return
 *   is S_OK.
 *   <br><tt> 0 :</tt> End of file has not been reached
 * @return
 *   <br><tt> S_OK :</tt>on Success .
 *   <br><tt> STG_E_READFAULT :</tt> problem while reading.
 *   <br><tt> STG_E_INVALIDPARAMETER :</tt> arguments incorrects.
 *   <br><tt> STG_E_DOCFILECORRUPT  :</tt> document can not be retrieved.
 *   <br><tt> STG_E_UNKNOWN :</tt> unexpected error.
 */
  virtual HRESULT ReadLine ( char * ioLine,  ULONG iNb, int &oEof)=0;



/**
 * Applies action and writes a line for text files.
 * <br><b>Role</b>: Applies action and writes the null-terminated string pointed
 * to by the iBuff parameter. The method does not apply action and write the 
 * terminating null character.
 * This method  will be only used for non V5 documents.
 * @param iBuff [in]
 *  initial Line to write.
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> STG_E_WRITEFAULT :</tt> problem while writing.
 *   <br><tt> STG_E_MEDIUMFULL :</tt> disk full error.
 *   <br><tt> STG_E_INVALIDPARAMETER :</tt> arguments incorrects.
 *   <br><tt> STG_E_DISKISWRITEPROTECTED :</tt> disk write protected.
 *   <br><tt> STG_E_INVALIDFUNCTION:</tt> unable to apply action on data.
 *   <br><tt> STG_E_UNKNOWN :</tt> unexpected error.
*/          
   virtual HRESULT WriteLine ( const char * iBuff)=0;



/**
 * Reads in the file and returns a line of unicode characters.
 * <br><b>Role</b>: Reads in file and return data as before applying the action
 * up to the number of bytes specified by iNb parameter minus 1, or until a 
 * new-line character and transfers that character to the ioLine parameter, or 
 * until it encounters an end-of-file condition. The method then build a 
 * CATUnicodeString.
 * This method will never be called for V5 documents. 
 * @param  ioLine [inout]
 *  line Buffer of at least iNb size.
 * @param iNb [i]
 *   max number of character to read.
 * @param oEof[o]
 *   to indicate if the end of the file as been reached.
 *   <br><tt> 1 :</tt> End of file has been reached. In this case the return
 *   is S_OK.
 *   <br><tt> 0 :</tt> End of file has not been reached
 * @return
 *   <br><tt> S_OK :</tt>on Success .
 *   <br><tt> STG_E_READFAULT :</tt> problem while reading.
 *   <br><tt> STG_E_INVALIDPARAMETER :</tt> incorrect arguments.
 *   <br><tt> STG_E_DOCFILECORRUPT  :</tt> document can not be retrieved.
 *   <br><tt> STG_E_UNKNOWN :</tt> unexpected error.
 */
  virtual HRESULT ReadLineW ( CATUnicodeString * ioLine,  ULONG iNb, 
			      int &oEof)=0;

/**
 * Reads in the file and returns a line of unicode characters.
 * <br><b>Role</b>: Reads in the file and return data as before applying the 
 * action up to the number of bytes specified by iNb parameter minus 1, or until
 * a new-line character and transfers that character to the ioLine parameter, or
 * until it encounters an end-of-file condition. 
 * This method will never be called for V5 documents. 
 * @param  ioLine [inout]
 *  line Buffer of at least iNb size.
 * @param iNb [i]
 *   max number of character to read.
 * @param oEof[o]
 *   to indicate if the end of the file as been reached.
 *   <br><tt> 1 :</tt> End of file has been reached. In this case the return
 *   is S_OK.
 *   <br><tt> 0 :</tt> End of file has not been reached
 * @return
 *   <br><tt> S_OK :</tt>on Success .
 *   <br><tt> STG_E_READFAULT :</tt> problem while reading.
 *   <br><tt> STG_E_INVALIDPARAMETER :</tt> incorrect arguments.
 *   <br><tt> STG_E_DOCFILECORRUPT  :</tt> document can not be retrieved.
 *   <br><tt> STG_E_UNKNOWN :</tt> unexpected error.
 */
  virtual HRESULT ReadLineWchar ( CATUC2Bytes * ioLine,  ULONG iNb, 
				  int &oEof)=0;

/**
 * Applies action and writes a line of unicode characters.
 * <br><b>Role</b>: Applies action  and writes the null-terminated string 
 * pointed to  by the iBuff parameter. The method does not apply action and 
 * write the terminating null character.
 * This method  will be only used for non V5 documents.
 * @param iBuff [in]
 *  initial Line to write.
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> STG_E_WRITEFAULT :</tt> problem while writing.
 *   <br><tt> STG_E_MEDIUMFULL :</tt> disk full error.
 *   <br><tt> STG_E_INVALIDPARAMETER :</tt> arguments incorrects.
 *   <br><tt> STG_E_DISKISWRITEPROTECTED :</tt> disk write protected.
 *   <br><tt> STG_E_INVALIDFUNCTION:</tt> unable to apply action on data.
 *   <br><tt> STG_E_UNKNOWN :</tt> unexpected error.
*/          
   virtual HRESULT WriteLineW ( const CATUnicodeString * iBuff)=0;

/**
 * Applies action and writes a line of unicode characters.
 * <br><b>Role</b>: Applies action  and writes the null-terminated string 
 * pointed to  by the iBuff parameter. The method does not apply action and 
 * write the terminating null character.
 * This method  will be only used for non V5 documents.
 * @param iBuff [in]
 *  initial Line to write.
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> STG_E_WRITEFAULT :</tt> problem while writing.
 *   <br><tt> STG_E_MEDIUMFULL :</tt> disk full error.
 *   <br><tt> STG_E_INVALIDPARAMETER :</tt> arguments incorrects.
 *   <br><tt> STG_E_DISKISWRITEPROTECTED :</tt> disk write protected.
 *   <br><tt> STG_E_INVALIDFUNCTION:</tt> unable to appliy action on  data.
 *   <br><tt> STG_E_UNKNOWN :</tt> unexpected error.
*/          
   virtual HRESULT WriteLineWchar ( const  CATUC2Bytes* iBuff)=0;
};

#endif



