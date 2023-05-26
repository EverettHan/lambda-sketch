/* -*-c++-*- */
#ifndef CATISpecImportManager_h
#define CATISpecImportManager_h
// COPYRIGHT DASSAULT SYSTEMES   2000

#include "CATBaseUnknown.h"
class CATPathElement;
class CATMathTransformation;
class CATUnicodeString;
#include "CATListOfCATString.h"

#include "CATImportSettingBehavior.h"
#include "CATImportContextType.h"

#include "UIModelInterfaces.h"

/**
 * Interface to manage import capabilities of an object for an UI active object context (e.g. Sketch, Part, ...)
 * <b>Role:</b> Check and provide object import capabilities in the UI active object context.
 */

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATISpecImportManager;
#else
extern "C" const IID IID_CATISpecImportManager;
#endif
class ExportedByUIModelInterfaces CATISpecImportManager : public CATBaseUnknown
{
 CATDeclareInterface;

public:
 
/**
 * Returns the context status for a selection.
 * @param iSelectionPath
 *   The path of the selected element.
 * @param iActiveObjectPath
 *   The path of the current UI Active object (returned by CATFrmEditor::GetUIActiveObject() method).
 * @return
 *   The context status value.
 *   <br><b>Legal values</b>: <ul>
 *   <li><tt>CATSelectionInCurrentContext</tt>: the selected element is in the current editor context (Part, Sketch...).</li>
 *   <li><tt>CATSelectionInPassiveContext</tt>: the selected element is in another editor context which is not active for a complete selection.</li>
 *   <li><tt>CATSelectionInOtherDocument</tt>: the selected element is in another mechanical part.</li>
 *   <li><tt>CATSelectionInOtherSketch</tt>: the selected element is in another mechanical sketch.</li></ul>
 *   For example, the status can be <tt>CATSelectionInOtherDocument | CATSelectionInOtherSketch</tt>.
 *   @see CATImportContextType.h
 */
  virtual CATULong IsElementInContext(CATPathElement * iSelectionPath,
                                      CATPathElement * iActiveObjectPath ) = 0 ;
 
/**
 * Allows selection of a element on a passive context.
 * @param iSelectionPath
 *   The path of the selected element.
 * @param iActiveObjectPath
 *   The path of the current UI Active object (returned by CATFrmEditor::GetUIActiveObject() method).
 * @param iElementTypeList
 *   The list of list of the object types expected by the dialog agent.
 * @return
 *   The ability status.
 *   <br><b>Legal values</b>: <ul>
 *   <li><tt>1</tt>: the pre-selected element is allowed.</li>
 *   <li><tt>0</tt>: the pre-selected element is not allowed.</li></ul>
 */
  virtual int AllowSelectionInPassiveContext(CATPathElement *     iSelectionPath,
                                             CATPathElement *     iActiveObjectPath,
                                             CATListOfCATString & iElementTypeList) = 0 ;
 
/**
 * Activate the context of a selected element.
 * @param iSelectionPath
 *   The path of the selected element.
 */
  virtual HRESULT ActivateSelectionContext(CATPathElement * iSelectionPath) = 0 ;

/**
 * Checks the capability to copy an external object in the current document.
 * <b>Role</b>:
 * Verifies an entity can be imported in a document.
 * @param iSelectionPath
 *   The path of the selected element.
 * @param iActiveObjectPath
 *   The path of the current document (returned by CATFrmEditor::GetUIActiveObject() method).
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
 *   NLS message explaining why the element is not valide:
 *   <ul><li>The element is not a CATGeometry, neither a CATILinkableObject.</li>
 *   <li>The selected element is from an other instance of the current part.</li>
 *   <li>The current part is reference by the selected element part. (Cycle are not allowed.)</li></ul>
 */
  virtual HRESULT IsImportPossible(CATPathElement *         iSelectionPath,
                                   CATPathElement *         iActiveObjectPath,
                                   CATClassId               iSelectionElementType,
                                   CATImportSettingBehavior iSettingBehavior,
                                   CATUnicodeString &       oNLSErrorMessage) = 0 ; 

/**
 * Computes the transformation matrix from the selected element document to the current document.
 * <b>Role</b>:
 * Returns the positioning matrix.
 * @param iSelectionPath
 *   The path of the selected element.
 * @param iActiveObjectPath
 *   The path of the current UI Active object (returned by CATFrmEditor::GetUIActiveObject() method).
 * @param oMathTransfo
 *   The computed transformation matrix.
 */
  virtual HRESULT GetPositioningMatrix(CATPathElement *        iSelectionPath,
                                       CATPathElement *        iActiveObjectPath,
                                       CATMathTransformation & oMathTransfo) = 0 ;

/**
 * Copies the result object of an external element in the current document
 * at the same contextual configuration.
 * <b>Role</b>:
 * Returns the result object in the current document.
 * <br>This result object must be deleted after use.
 * @param iSelectionPath
 *   The path of the selected element.
 * @param iActiveObjectPath
 *   The path of the current UI Active object (returned by CATFrmEditor::GetUIActiveObject() method).
 */
  virtual CATBaseUnknown_var CreateTemporaryImportResult(CATPathElement * iSelectionPath,
                                                         CATPathElement * iActiveObjectPath ) = 0 ;

/**
 * Copy an external object in the current document.
 * <b>Role</b>:
 * Returns the path of the external object copy in the current document.
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
 *   The number of element newly copied in the current context. 0 value is returned when the contexual element was already imported.
 */
   virtual CATPathElement * ImportObject (CATPathElement *         iSelectionPath,
                                          CATPathElement *         iActiveObjectPath,
                                          CATClassId               iSelectionElementType,
                                          CATImportSettingBehavior iSettingBehavior,
                                          CATUnicodeString &       oNLSErrorMessage,
                                          int*                     oNbElemNewlyCopied=NULL ) = 0 ; 

/**
 * Compare two CATPathElement.
 * <b>Role</b>:
 * Returns the status between twoCATPathElement.
 * @param iPath1
 *   The path of the given element.
 * @param iPath2
 *   The path of the given element.
 * @return
 *   The status.
 *   <br><b>Legal values</b>: <ul>
 *   <li><tt>0</tt>: the two CATPathElement are identical.</li>
 *   <li><tt>1</tt>: the two CATPathElement are different.</li></ul>
 */
  virtual int ComparePathElement (CATPathElement * iPath1,
                                  CATPathElement * iPath2 ) = 0 ;

/**
 * Give the CATISpecObject of an object.
 * <b>Role</b>:
 * Returns the path of the CATISpecObject of the given object.
 * @param iSelectionPath
 *   The path of the selected object.
 * @param iMode
 *   The information mode to operate the selected object.
 *   (e.g.: For a Mechanical application, iMode is 
 *   the featurization mode to featurized the selected geometry.
 *   See CATMfBRepDefs.h).
 * @param iSupport
 *   The support of the selected object.
 *   (e.g.: For a Mechanical application,
 *   <b>Legal values</b>: NULL_var when <tt>iMode</tt> is MfNoFeaturization or MfFunctionalFeaturization.
 *   Or the support feature if it is required by the featurization option and known).
 * @return
 *   The path of the CATISpecObject
 *   <br><b>Warning:</b><br>
 *   If you use such capabilities, the returned CATISpecObject (within the path) 
 *   has no CATIDescendants parent which manage its automatic deletion.
 */
  virtual CATPathElement * GiveSpecFromObject (CATPathElement *           iSelectionPath,
                                               CATULong                   iMode,
                                               const CATBaseUnknown_var & iSupport=NULL_var) = 0;

/**
 * Update the selection path.
 * <b>Role</b>:
 * Removes unuseful geometrical element according to the selection element type. 
 * @param ioSelectionPath
 *   The path of the selected object.
 * @param iSelectionElementType
 *   The type of the selected element.
 */
 virtual HRESULT UpdateSelectionPath (CATPathElement * ioSelectionPath,
                                      CATClassId       iSelectionElementType) = 0;

 /**
 * Allows selection of a element on a passive context.
 * @param iSelectionPath
 *   The path of the selected element.
 * @param iActiveObjectPath
 *   The path of the current UI Active object (returned by CATFrmEditor::GetUIActiveObject() method).
 * @param iElementTypeList
 *   The list of list of the object types expected by the dialog agent.
 * @return
 *   The ability status.
 *   <br><b>Legal values</b>: <ul>
 *   <li><tt>1</tt>: the pre-selected element is allowed.</li>
 *   <li><tt>0</tt>: the pre-selected element is not allowed.</li></ul>
 */
  virtual int AllowSelectionInPassiveContext(CATPathElement *     iSelectionPath,
                                             CATPathElement *     iActiveObjectPath,
                                             CATListOfCATString & iElementTypeList,
                                             CATUnicodeString   & iLoadMode) = 0 ;

  /**
 * Activate the context of a selected element.
 * @param iSelectionPath
 *   The path of the selected element.
 */
  virtual HRESULT ActivateSelectionContext(CATPathElement   * iSelectionPath,
                                           CATUnicodeString & iLoadMode) = 0 ;

/**
 * Update and filter the selection path.
 * <b>Role</b>:
 * Removes unuseful geometrical element according to the selection element type
 * and filters path according to ShapeBody rules.
 * @param ioSelectionPath
 *   The path of the selected object.
 * @param iSelectionElementType
 *   The type of the selected element.
 * @param iActiveObjectPath
 *   The path of the  of the active object.
 * @param iActivePath
 *   The path of the editing or current object.
 * @param oUpdatedSelectionPath
 *   The updated returned path
 * @param oNLSErrorMessage
 *   The NLS error message if filtered.
 */
  virtual HRESULT UpdateSelectionPath(CATPathElement  * iSelectionPath,
                                      CATClassId        iSelectionElementType,
                                      CATPathElement  * iActiveObjectPath,
                                      CATPathElement  * iActivePath,
                                      CATPathElement*&  oUpdatedSelectionPath,
                                      CATUnicodeString& oNLSErrorMessage) = 0;
};

CATDeclareHandler(CATISpecImportManager, CATBaseUnknown);
#endif
