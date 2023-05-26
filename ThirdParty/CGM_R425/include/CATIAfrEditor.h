#ifndef CATIAfrEditor_H
#define CATIAfrEditor_H

// COPYRIGHT DASSAULT SYSTEMES 2008

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

class CATBaseUnknown;
class CATCommandSelector;
class CATCSO;
class CATHSO;
class CATISO;
class CATPSO;
class CATPathElement;


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIAfrEditor;
#else
extern "C" const IID IID_CATIAfrEditor;
#endif


class ExportedByCATAfrItf CATIAfrEditor : public CATBaseUnknown
{
  CATDeclareInterface;
  
public:

  /**
   * Returns a handle on the edited data.
   * <br><b>Role</b>: The edited data should give access to the model root object controlled by the editor.
   * <br>The CATFrmEditor class has no knowledge of model management, it only keeps this pointer.
   * Each CATFrmEditor instance sets this pointer and gives the model knowledge to the pointed object.
   * <br>If this object is a PLM component, it should implement @href CATIPLMComponent behaviors.
   * <br>If this object is a PLM component set, it should implement @href CATIPLMComponentsSet behaviors.
   * <br><b>Lifecycle rules deviation</b>: No AddRef is performed on the returned value.
   */
  virtual CATBaseUnknown * GetEditedContents()=0;
 
  
  /**
   * Returns the Current Selection of Objects.
   * <br><b>Lifecycle rules deviation</b>: No AddRef is performed 
   * on the returned value.
   * @see CATCSO
   */

  virtual CATCSO * GetCSO()=0;
  /**
   * Returns the Highlighted Set of Objects.
   * <br><b>Lifecycle rules deviation</b>: No AddRef is performed 
   * on the returned value.
   * @see CATHSO
   */
  virtual CATHSO * GetHSO()=0;

  /**
   * Returns the Preselected Set of Objets.
   * <br><b>Lifecycle rules deviation</b>: No AddRef is performed 
   * on the returned value.
   * @see CATPSO
   */
  virtual CATPSO * GetPSO()=0;

  /**
   * Returns the Interactive Set of Objects.
   * <br><b>Lifecycle rules deviation</b>: No AddRef is performed 
   * on the returned value.
   * @see CATISO
   */
  virtual CATISO * GetISO()=0;

  /**
   * Returns the Furtive Interactive Set of Objects.
   * <br><b>Role</b>: Objects added to the Furtive Interactive
   * Set of Objects are displayed in XOR mode.
   * <br><b>Lifecycle rules deviation</b>: No AddRef is performed 
   * on the returned value.
   * @see CATISO
   */
  virtual CATISO * GetFurtiveISO()=0;

  /**
   * Returns the command selector created by the editor.
   * <br><b>Role:</b>This command selector receives all the notifications
   * from the graphic representation. You use it in the <tt>AttachTo</tt> method
   * method of the @href CATVisManager . 
   */
  virtual CATCommandSelector  * GetCommandSelector()=0;

  /**
   * Unsets the repeated command .
   * <br><b>Role</b>:When the end user double clicks on an icon in a toolbar, 
   * the command is set in repeat mode. It means that when the command is canceled,
   * the command is relaunched by the editor. This method enables a command 
   * to unset this repeat mode. It can be useful when the end user clicks on a Close 
   * Button or a Cancel Button to unset the repeat mode.
   */
  virtual void UnsetRepeatedCommand()=0;

  /**
   * Activates an element of the given path.
   * <br><b>Role</b>: Actives the workshop of the first UI activable element
   * found from the leaf of the path <tt>iPathElement</tt>.
	 * @param iPathElement
   * A pointer to the path to UI activate.
   * @param iObjectEdition
   *   <ul>
   *   <li>TRUE if the path change corresponds to an object edition.
   *       After the edition, all the actions done during this edition
   *       will be committed in one action. This is important for undo/redo.</li>
   *   <li>FALSE if the path change does not correspond to an object edition.
   *       The actions done after calling SetActivePath will be considered as separate undo/redo steps.</li></ul>
   * @return
   * Returns S_OK on success. On failure, it returns one of the following
   * error codes :
   * <ul>
   * <li>SAP_INVALID_ARG if the given argument is invalid (null)</li>
   * <li>SAP_REFUSED_BY_SITE if one of the @href CATInPlaceSite object of the
   * given path returned 0 on a call to its @href CATInPlaceSite#CanInPlaceActivate
   * method </li>
   * <li>SAP_OBJECT_IN_USE if one of the @href CATIUIActivate object of the 
   * given path is already ui-active in an other editor </li>
   * <li>SAP_NO_LICENSE if there is no license for one of the @href CATIUIActivate 
   * object's implementation of the given path</li>
   * </ul>
   * @see CATIUIActivate
   *
   */
  virtual HRESULT SetActivePath (CATPathElement * iPathElement, CATBoolean iObjectEdition=TRUE)=0;

  /**
   * Returns the current UI-activated element.
   * <br><b>Lifecycle rules deviation</b>: No AddRef is performed 
   * on the returned value.
   * @see CATIUIActivate
   */
  virtual CATPathElement & GetUIActiveObject()=0;

  /**
   * Returns the compass.
   * @param iCompassVersion
   * The compass version number.
   * <br><b>Legal values</b>: Parameter must be left to default value.
   * @return
   *   A pointer to an object that implements the CATI3DCompass interface.
   * <br><b>Lifecycle rules deviation:</b>This method does not AddRef the
   * returned pointer.
   * @see CATI3DCompass
   */
  virtual CATBaseUnknown * GetCompass(const int iCompassVersion = 0)=0;

  /**
   * Returns the number of window of the editor.
   */
  virtual int GetWindowCount()=0;


};


//-----------------------------------------------------------------------------
//                             Handler
//-----------------------------------------------------------------------------

CATDeclareHandler(CATIAfrEditor, CATBaseUnknown);

#endif
