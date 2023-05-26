#ifndef CATISpecImport_h
#define CATISpecImport_h
// COPYRIGHT DASSAULT SYSTEMES   2000
/**
* @level Protected
* @usage U5
*/
#include "CATBaseUnknown.h"
class CATPathElement;
class CATMathTransformation;
class CATUnicodeString;

#include "CATImportSettingBehavior.h"

#include "UIModelInterfaces.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATISpecImport;
#else
extern "C" const IID IID_CATISpecImport;
#endif
/**
 * Interface used in interactive import to specify behavior of a specific object.
 * <br><b>Role</b>: interface may be implemented on any object to define import behavior
 * in assembly context or VPM Session. 
 * <br>A default behavior is defined for MechanicalFeature by the interface CATIDatumFactory.
 * <p>Do not call CATISpecImport interface. It is reserved to MechanicalModelerUI.
 * <p>It is recommended to implement at least @href #IsImportPossible and @href #ImportObject .
 *
 * @see CATISpecImportManager
 */
class ExportedByUIModelInterfaces CATISpecImport : public CATBaseUnknown
{
 CATDeclareInterface;

public:
 
/**
 * Checks the capability to copy an external object in the current part.
 * <br><b>Role</b>:
 * Verifies an entity can be imported in a part.
 * @param iSelectionPath
 *   The path of the selected element.
 * @param iObjectInWorkPath
 *   The path of the current UI Active object (returned by CATFrmEditor::GetUIActiveObject() method).
 * @param iSelectionElementType
 *   The type of the selected element.
 * @param iSettingBehavior
 *   The behavior regarding the 'Keep link with the selected object' setting.
 *   <br><b>Legal values</b>: <ul>
 *   <li><tt>UseSettingValue</tt>: the setting value is used for the treatment.</li>
 *   <li><tt>NoKeepLinkValue</tt>: overrides the setting value in order to create no link with the selected element.</li>
 *   <li><tt>KeepLinkValue</tt>: overrides the setting value in order to create the link with the selected element.</li></ul>
 * @param oNLSErrorMessage
 *   NLS message explaining why the element is not valide:
 *   <ul><li>The element is not a CATGeometry, neither a CATILinkableObject.</li>
 *   <li>The selected element is from an other instance of the current part.</li>
 *   <li>The current part is reference by the selected element part. (Cycle are not allowed.)</li></ul>
 *   @see CATImportSettingBehavior.h
 */
  virtual HRESULT IsImportPossible(CATPathElement *         iSelectionPath,
                                   CATPathElement *         iObjectInWorkPath,
                                   CATClassId               iSelectionElementType,
                                   CATImportSettingBehavior iSettingBehavior,
                                   CATUnicodeString &       oNLSErrorMessage) = 0 ; 

/**
 * Computes the transformation matrix from the selected element part to the current part.
 * <br><b>Role</b>:
 * Returns the positioning matrix.
 * @param iSelectionPath
 *   The path of the selected element.
 * @param iObjectInWorkPath
 *   The path of the current UI Active object (returned by CATFrmEditor::GetUIActiveObject() method).
 * @param oMathTransfo
 *   The computed transformation matrix.
 */
  virtual HRESULT GetPositioningMatrix(CATPathElement* iSelectionPath,
                                       CATPathElement * iActiveObjectPath,
                                       CATMathTransformation & oMathTransfo) = 0 ;

/**
 * Copies the result object of an external element in the current part
 * at the same contextual configuration.
 * <br><b>Role</b>:
 * Returns the result in the current part.
 * @param iSelectionPath
 *   The path of the selected element.
 * @param iActiveObjectPath
 *   The path of the current UI Active object (returned by CATFrmEditor::GetUIActiveObject() method).
 */
  virtual CATBaseUnknown_var CreateTemporaryImportResult(CATPathElement* iSelectionPath , 
                                                         CATPathElement* iActiveObjectPath ) = 0 ;

/**
 * Copy an external object in the UI active context.
 * <br><b>Role</b>:
 * Creates a copy of an external object in the current document.
 * <br><b>Warning</b>:
 * The imported object has no CATIDescendant father.
 * @param iSelectionPath
 *   The path of the selected element.
 * @param iActiveObjectPath
 *   The path of the current UI Active object (returned by CATFrmEditor::GetUIActiveObject() method).
 * @param iSelectionElementType
 *   The type of the selected element.
 * @param iSettingBehavior
 *   The behavior regarding the 'Keep link with the selected object' setting.
 *   <br><b>Legal values</b>: <ul>
 *   <li><tt>UseSettingValue</tt>: the setting value is used for the treatment.</li>
 *   <li><tt>NoKeepLinkValue</tt>: overrides the setting value in order to create no link with the selected element.</li>
 *   <li><tt>KeepLinkValue</tt>: overrides the setting value in order to create the link with the selected element.</li></ul>
 *   @see CATImportSettingBehavior.h
 * @param oNLSErrorMessage
 *   NLS message explaining why the element is not imported.
 * @param oNbElemNewlyCopied
 *   The number of element copied in the current context. 0 value is returned when the contexual element was already imported.
 */
   virtual CATBaseUnknown_var ImportObject (CATPathElement*          iSelectionPath,
                                            CATPathElement*          iActiveObjectPath,
                                            CATClassId               iSelectionElementType,
                                            CATImportSettingBehavior iSettingBehavior,
                                            CATUnicodeString &       oNLSErrorMessage,
                                            int*                     oNbElemNewlyCopied=NULL ) = 0 ; 

};

CATDeclareHandler(CATISpecImport, CATBaseUnknown);
#endif
