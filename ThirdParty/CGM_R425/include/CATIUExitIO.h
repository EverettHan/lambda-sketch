/* COPYRIGHT DASSAULT SYSTEMES 2000 */
/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

#ifndef CATIUExitIO_H 
#define CATIUExitIO_H
#include "IUnknown.h"
#include "CATTypesForFileExit.h"
#include "JS0FILEEXIT.h"


 
extern "C" const IID IID_CATIUExitIO;
class CATUnicodeString;
     
  /**
   *  Interface to enable some user specific manipulations on the files.
   *  <b>Role</b>: This interface is a user exit, that allows an user to perform
   *  some specific operations in order to control the opening, the closing and the
   *  creation of the files 
   *  <br>You should implement it on the <tt>CATUExitIO</tt> component by creating
   *  a data extension.
   **/


class ExportedByJS0FILEEXIT CATIUExitIO : public IUnknown
{
public:

  /**
   * Allows the user to perform some operations on the file to open.
   * <br><b>Role</b>: This method allows the user to perform same operations on the 
   * file that will be opened, such as changing its rights and controling the access
   * right of the current user.
   * @param iFileName
   *  The filename to open.
   * @param iMode 
   *  The requested mode for the opening.
   * @param  oGranted
   *  Says if the opening is possible
   *  <br><b>Legal values:  </b>
   *  <dl>
   *    <dt>S_OK     <dd> It is allowed to open the file. 
   *    <dt>S_FALSE <dd> It's not allowed to open the file.
   *  </dl>
   * @param oError
   *  The system error that has occured in case of failure, valuated with CATERRNO
   * @return
   *  S_OK  If no problem has occured during the processing
   *  E_FAIL If any problem has occured. In this cas the method must set oError 
   *         with CATERRNO
   */

  virtual HRESULT OnOpen (const CATUnicodeString *iFileName,CATAccessRight iMode,
			  HRESULT *oGranted, CATFileSystemError *oError)=0;

  /**
   * Allows the user to set a creation mask.
   * <br><b>Role</b>: This method allows the user to set a specific creation mask for 
   * the file to be created, for example the right of the current directory.
   * @param iFileName
   *  The filename to create.
   * @param oMode 
   *  The desired mask to be used for the file creation.
   * @param oError
   *  The system error that has occured in case of failure, valuated with CATERRNO
   * @return
   *  <br>S_OK   ,If no problem has occured during the processing and oMode is valuated.
   *  <br>E_NOTIMPL , The method is not implemented.
   *  <br>E_FAIL If any problem has occured. In this cas the method must set oError 
   *         with CATERRNO
   */
  virtual HRESULT CreationMask (const CATUnicodeString *iFileName, DWORD *oMode,
				CATFileSystemError *oError)=0;


  /**
   * Allows the user to process some operations on the file to close.
   * <br><b>Role</b>: This method allows the user to perform same operations on the 
   * file that has just been closed. It's the reverse methode of OnOpen.
   * right of the current user.
   * @param iFileName
   *  The name of the closed file .
   * @param oError
   *  The system error that has occured in case of failure, valuated with CATERRNO
   * @return
   *  S_OK  If no problem has occured during the processing
   *  E_FAIL If any problem has occured. In this cas the method must set oError 
   *         with CATERRNO
   */
  virtual HRESULT OnClose (const CATUnicodeString *iFileName,
			   CATFileSystemError *oError)=0;
  
};

#endif
