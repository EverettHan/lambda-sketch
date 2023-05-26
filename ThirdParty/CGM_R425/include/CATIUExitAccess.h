/* COPYRIGHT DASSAULT SYSTEMES 2000 */

#ifndef CATIUExitAccess_H 
#define CATIUExitAccess_H
#include "IUnknown.h"
#include "JS0FILEEXIT.h"
#include "CATTypesForFileExit.h"


 
extern "C" const IID IID_CATIUExitAccess;
class CATUnicodeString;

     
  /**
   * @nodoc
   **/


class ExportedByJS0FILEEXIT CATIUExitAccess : public IUnknown
{
public:

  /**
   *  @nodoc
   * Says if the requested rigths on a file are granted
   * @param iFileName
   *  The filename 
   * @param  iRequestedRight
   *  The requested rights on the file which is an ORing combination of the 
   *  following flags
   *  <br><b>Legal values:  </b>
   *  <dl>
   *    <dt>CATReadRight     <dd> Read Right for the user
   *    <dt>CATWriteRight <dd>Write right for the user 
   *    <dt>CATExecuteRight <dd>Execute right for the user
   *    <dt>CATDeleteRight <dd>Delete right for the user
   *    <dt>CATRenameRight <dd>Rename right for the user
   *    <dt>CATChangeStatusRight <dd>ChangeStatus right for the user
   *  </dl>
   * @return
   *  S_OK if the requested rights are granted 
   *  E_FAIL if the user, the application, or the attribute is unknown, and S_OK otherwise
     */

  virtual HRESULT GetRigths ( const CATUnicodeString *iFileName, 
			      CATAccessRight iRequestedRight)=0;
  /**
   * @nodoc
   */
  virtual HRESULT ListRigths ( const CATUnicodeString *iFileName, 
			       CATAccessRight *oGrantedRight)=0;
};

#endif
