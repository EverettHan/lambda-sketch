
#ifndef __DataCommonProtocolCCPServices_h__
#define __DataCommonProtocolCCPServices_h__

// COPYRIGHT DASSAULT SYSTEMES 2009  

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

 // DataCommonProtocolUse forwards and headers.
#include "DataCommonProtocolUse.h" // ExportedByDataCommonProtocolUse

// Other forwards and headers.
class CATBaseUnknown;
class CATUnicodeString;
#include "CATCollec.h" // CATListOfCATUnicodeString
#include "CATSysErrorDef.h" // HRESULT
#include "CATLISTV_CATBaseUnknown.h"

/**
 * Services related to the Copy and Paste protocol.
 * For more specific details, please refer to the documentation of each entity.
 * These services provide the same functionalities as the Edit -> Copy, Edit -> Paste and
 * Edit -> Paste special in interactive application. They use the clipboard like the interactive commands,
 * but flush the clipboard when done. Consequently, all data present in the clipboard is lost when one of
 * theses services is called.
 */
class ExportedByDataCommonProtocolUse DataCommonProtocolCCPServices
{
public:
  /**
   * Copy and Paste of entities.
   * <br><b>Role:</b> copies entities like Edit -> Paste in interactive applications.
   * @param iEntitiesToCopy
   *   The list of entities to copy (would be the selected objects when using Edit -> Copy interactively).
   * @param iPasteTarget
   *   A path representing the target of the paste operation (equivalent to the path of the selected object when using Edit -> Paste interactively).
   * @param oNewEntities
   *   The copies (new objects).
   *   The list will contain some objects linked to the format and to the copy itself
   * @return
   *  <ul><li><tt>S_OK</tt>: the operation completed sucessfully.</li>
   *      <li><tt>E_POINTER</tt>: an input parameter (at least) is null or invalid.</li>
   *      <li><tt>E_NOTIMPL</tt>: an input parameter (at least) does not support the Copy and Paste protocol.</li>
   *      <li><tt>E_FAIL</tt>: the operation could not be completed.<br>
   *              More information may be available via <tt>CATError::CATGetLastError</tt>.</li></ul>
   */
  static HRESULT CopyAndPasteTo(const CATListValCATBaseUnknown_var & iEntitiesToCopy, CATBaseUnknown * iPasteTarget, CATListValCATBaseUnknown_var & oNewEntities);

  /**
   * Returns the list of available Paste special Formats.
   * <br><b>Role:</b> provides the list of Copy Paste Formats (as in Edit -> Paste special interactively)
   * that can be used when copying iEntitiesToCopy to iPasteTarget.
   * <br>The first Format in the list is the default Format, i.e. the Format used by Paste (not Paste special).
   * @param iEntitiesToCopy
   *   The entity on which the paste is done (the selected object when using Edit -> Paste interactively).
   * @param iPasteTarget
   *   A path representing the target of the paste operation (equivalent to the path of the selected object when using Edit -> Paste interactively).
   * @param oAvailableFormats
   *   The list of available Paste special Formats.
   * @return
   *  <ul><li><tt>S_OK</tt>: the operation completed sucessfully.</li>
   *      <li><tt>E_POINTER</tt>: an input parameter (at least) is null or invalid.</li>
   *      <li><tt>E_NOTIMPL</tt>: an input parameter (at least) does not support the Copy and Paste protocol.</li>
   *      <li><tt>E_FAIL</tt>: the operation could not be completed.<br>
   *              More information may be available via <tt>CATError::CATGetLastError</tt>.</li></ul>
   */
  static HRESULT GetAvailableFormats(const CATListValCATBaseUnknown_var & iEntitiesToCopy, CATBaseUnknown * iPasteTarget, CATListOfCATUnicodeString & oAvailableFormats);

  /**
   * Copy and Paste special of entities.
   * <br><b>Role:</b> copies entities like Edit -> Paste special in interactive applications.
   * <br>If the first Format in the list of available Paste special Formats (i.e. default the Format) is used
   * this service will behave exactly as @href #CopyAndPasteTo service.
   * @param iEntitiesToCopy
   *   The entity on which the paste is done (the selected object when using Edit -> Paste interactively).
   * @param iPasteTarget
   *   A path representing the target of the paste operation (equivalent to the path of the selected object when using Edit -> Paste interactively).
   * @param iFormat
   *   the Paste Format (the Format to select in Edit -> Paste special dialog box  interactively).
   * @param oNewEntities
   *   the copies (new objects).
   *   The list will contain some objects linked to the format and to the copy itself
   * @return
   *  <ul><li><tt>S_OK</tt>: the operation completed sucessfully.</li>
   *      <li><tt>E_POINTER</tt>: an input parameter (at least) is null or invalid.</li>
   *      <li><tt>E_NOTIMPL</tt>: an input parameter (at least) does not support the Copy and Paste protocol.</li>
   *      <li><tt>E_FAIL</tt>: the operation could not be completed.<br>
   *              More information may be available via <tt>CATError::CATGetLastError</tt>.</li></ul>
   */
  static HRESULT CopyAndPasteSpecialTo(const CATListValCATBaseUnknown_var & iEntitiesToCopy, CATBaseUnknown * iPasteTarget, const CATUnicodeString & iFormat, CATListValCATBaseUnknown_var & oNewEntities);

};


#endif // __DataCommonProtocolCCPServices_h__
