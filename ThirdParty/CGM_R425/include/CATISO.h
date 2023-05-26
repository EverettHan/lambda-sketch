#ifndef CATISO_H_
#define CATISO_H_

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATAfrFoundation.h"
#include "CATCallbackManager.h"
#include "CATLISTP_CATBaseUnknown.h"
#include "CATDisplayType.h"
#include "DefineCst.h"
#include "list.h"
#include "CATPathElement.h"
#include "CATLISTV_CATBaseUnknown.h"

class CATListPtrCATViewer;
class CAT3DViewer;
class CAT2DViewer;
class CATFrmEditor;
class CAT4x4Matrix;
class CATViewpoint;
class CATViewer;
class CATRep;

/**
 * Class for visualizing temporary objects in given viewers.
 * <b>Role</b>: Usually you put into the Interactive Set Objects (ISO), objects that are related
 * to the current command. Thus it allows you to give temporaries information to the end-user.
 * <br>The object, to set into the ISO, are components which implement either @href CATI3DGeoVisu 
 * either @href CATI2DGeoVisu, two default interfaces of the Visualization Framework. 
 * <br>To avoid to create a new component, you can use a @href CATModelForRep2D or 
 * or a @href CATModelForRep3D. These 2 components already implement the visualization 
 * interfaces.
 *<p>
 * There are three default CATISO in every editor:
 *<ol>
 *<li> a normal   CATISO</li>
 *<li> a furtive  CATISO</li>
 *<li> a background CATISO</li>
 *</ol>
 *@see CATDisplayType
 */


class ExportedByCATAfrFoundation CATISO: public CATCallbackManager
{
  /** @nodoc */
  CATDeclareClass ;

   public:
   
  /**
   * @nodoc 
   * Constructs the class.
   * @param iEditor
   *    Editor attached to this Set of objects
   * @param iLayout
   *    Type of the Display. @href CATDisplayType . 
   *    The default value is <tt>CATNormal</tt>
   */
  CATISO (CATFrmEditor * iEditor, CATDisplayType iLayout=CATNormal);

  virtual ~CATISO ();
  
  
  /**
   * Empties the Interactive Set Of Objects.
   * <br><b>Role</b>: Empties every object put into it from any viewer. 
   * The result is that all the
   * graphical representations of the objects added into it are destroyed, and each object referenced in the current set
   * is released.
   */
  void Empty ();

  /**
   * @nodoc : deprecated V5R14 Empty
   * Cleans the Interactive Set Of Objects.
   * <br><b>Role</b>: Empties every object put into it from any viewer and detaches all the viewers.
   * The result is that all the
   * graphical representations of the objects added into it are destroyed, that it empties the 
   * list of viewer as well as the list of objects referenced into the current set.
   */
  void Clean ();

    
  /**
   * Sets the cursor at the begining of the Interactive Set Of Objects.
   * <br><b>Role</b>: 
   * In order to get the first object of the set, you need call the <tt>InitElementList()</tt>
   * method then call the @href #GetNextElement() method.
   */
  void InitElementList();
  
  /**
   * Returns the next object of the the Interactive Set Of Objects.
   * <br><b>Role</b>: 
   * It is useful when you want to go through all the objects that are hold in the set.
   * Notice that the internal cursor is updated to the new position. When this method returns
   * NULL, it means that you are at the end of the list.
   */
  CATBaseUnknown * GetNextElement();
  
  /**
   * Adds an object to the Interactive Set Of Objects.
   * @param iObject
   *  The object to add.
   * This object must NOT be a graphical representation.
   * A CATCreate is sent to build the representation of iObject.
   * <br><b>Lifecycle rules deviation</b>: An AddRef is done on iObject.
   * 
   */
  virtual void AddElement( CATBaseUnknown * iObject );
  /**
   * Removes an object from the Interactive Set Of Objects.
   * @param iObject
   *  The object to remove.
   * @param ToRemove
   *   if NoDestroying=0, default behaviour, the representation associated to 
   *                  iObject is destroyed by sending a CATDelete.
   *   if NoDestroying=1, then the representation associated to 
   *                  iObject is not destroyed. It is simply removed from the 
   *				  BagRep of CATISO.
   * <br><b>Lifecycle rules deviation</b>: A Release is done on iObject.
   */
  
  virtual void RemoveElement( CATBaseUnknown *iObject, int NoDestroying=0 );

  /**
   * Modifies a given object hold in the Interactive Set Of Objects.
   * @param iObject
   *  The object to modifie
   * @param iMat
   *   This matrix represents the tranformation to perform onto the object.If NULL
   *   (the default value), the object is not modified. 
   * @see CAT4x4Matrix
   */
  virtual void UpdateElement( CATBaseUnknown *iObject  , CAT4x4Matrix *iMat=NULL);
   
  /**
   * Checks if an object is in the Interactive Set Of Objects.
   *
   * @param iObject
   *  the object.
   * @return an integer value
   *<ol>
   * <li> 1 if the given object is already there </li>
   * <li> 0 otherwise </li>
   *</ol>
   *
   */
  int IsMember ( CATBaseUnknown * iObject);
 
  /**
   * Adds a 3D viewer to the Interactive Set Of Objects.
   *
   * @param iViewer
   * the 3D viewer to add.
   * @see CAT3DViewer
   */
  void AddViewer (CAT3DViewer *iViewer);
  
  /**
   *  Adds a 2D viewer to the Interactive Set Of Objects.
   *
   * @param iViewer
   * the 2D viewer to add.
   * @see CAT2DViewer
   */
  void AddViewer (CAT2DViewer *iViewer);
  
  /**
   * @nodoc
   */
  void AddCtlViewer (CATBaseUnknown *i_pCtlViewer, int i_3DFlag, ::list<CATRep>* i_pList);    

    /**
   * @nodoc
   */
  void AddCtlViewer (CATBaseUnknown* i_pCtlViewer, ::list<CATRep>* i_pList, ::list<IID>& iListIID);

  /**
   * @nodoc
   */
  void RemoveCtlViewer (CATBaseUnknown *i_pCtlViewer, int i_3DFlag);    
  /**
   * @nodoc
   *  Adds a viewer to the Interactive Set Of Objects.
   *
   * @param iViewer
   * the viewer to add.
   * @param VisuType
   *  
   * @see CATViewer
   */
  void AddViewer (CATViewer *iViewer, VisuType iType);
    
  /**
   * Removes a 3D viewer from the Interactive Set Of Objects.
   *
   * @param iViewer
   * the 3D viewer to remove.
   * @see CAT3DViewer
   */
  void RemoveViewer (CAT3DViewer *iViewer);
  
  /**
   * Removes a 2D viewer from the Interactive Set Of Objects.
   * @param iViewer
   * the 2D viewer to remove.
   * @see CAT2DViewer
   */
  void RemoveViewer (CAT2DViewer *iViewer);
  
  /**
   * @nodoc
   * Removes a viewer from the Interactive Set Of Objects.
   *
   * @param iViewer
   * The viewer to remove.
   * @param VisuType
   * @see CATViewer
   */
  void RemoveViewer (CATViewer *iViewer, VisuType iType);
  

  /**
   * @nodoc
   * Adds a viewpoint and a list of Visualization interfaces.
   * @param iViewpoint
   *    the viewpoint.
   * @param iListIID
   *   the list of IID.
   * @see CATViewpoint
   */
  void AddViewpoint (CATViewpoint* iViewpoint, ::list<IID>& iListIID);
  
  /**
   * @nodoc
   * Removes a viewpoint and a list of Visualization interfaces.
   * @param iViewpoint
   *    the viewpoint.
   * @param iListIID
   *   the list of IID.
   * @see CATViewpoint
   */
  void RemoveViewpoint (CATViewpoint* iViewpoint, ::list<IID>& iListIID);
  
  /**
   * @nodoc
   * Sets the internal cursor at the beginning of the list of 2D viewer hold by the ISO
   *<br><b>Role</b>: 
   * in order to get the first 2D viewer hold in the list, you need to call the
   * @href #GetNext2DViewer() method  after the @href #Init2DViewerList() method.
   */
  void Init2DViewerList();
  
  /**
   * @nodoc
   * Returns the next 2D viewer hold in the list of the ISO
   * <br><b>Role</b> : when it returns NULL, that means that you are at the end of the list.
   */
  CAT2DViewer * GetNext2DViewer();
  
  /**
   * @nodoc
   * Sets the internal cursor at the beginning of the list of 3D viewer hold in the CATISO.
   *<br><b>Role</b>: 
   * in order to get the first 3D viewer hold in the list, you need to call the
   * @href #GetNext3DViewer() method  after the @href #Init3DViewerList() method.
   */
  void Init3DViewerList();

  /**  
   * @nodoc
   *  Returns the next 3D viewer hold in the list of the CATISO.
   * <br><b>Role</b> : when it returns NULL, that means that you are at the end of the list.
   */
  CAT3DViewer * GetNext3DViewer();
  
   /**
   * @nodoc
   * Sets the internal cursor at the beginning of the list of 2D viewer hold in the CATISO.
   *<br><b>Role</b>: 
   * in order to get the first 2D viewer hold in the list, you need to call the
   * @href #GetNext2DViewer() method  after the @href #Init2DViewerList() method.
   */
  void InitViewerFor2DList();

   /**
   * @nodoc
   * Returns the next 2D viewer hold in the list of the  CATISO.
   * <br><b>Role</b> : when it returns NULL, that means that you are at the end of the list.
   */
  CATViewer * GetNextViewerFor2D();

   /**
   * @nodoc
   * Sets the internal cursor at the beginning of the list of 3D viewer hold in the  CATISO.
   *<br><b>Role</b>: 
   * in order to get the first 3D viewer hold in the list, you need to call the
   * @href #GetNext3DViewer() method  after the @href #Init3DViewerList() method.
   */
  void InitViewerFor3DList();


   /**  
   * @nodoc
   *  Returns the next 3D viewer hold in the list of the CATISO.
   * <br><b>Role</b> : when it returns NULL, that means that you are at the end of the list.
   */
  CATViewer * GetNextViewerFor3D();
  
  /** @nodoc */
  CATDisplayType GetDisplayType() const;

private:
  
     CATLISTP (CATBaseUnknown) _liste;
     CATListValCATBaseUnknown_var   _ctlViewerList; 
     CATListPtrCATViewer       * _3DViewers;
     CATListPtrCATViewer       * _2DViewers;
     CATListPtrCATViewer       * _ViewersFor3D;
     CATListPtrCATViewer       * _ViewersFor2D;
     int                         _ListPosition;
     int                         _3DViewerPosition;
     int                         _2DViewerPosition;
     int                         _ViewerFor3DPosition;
     int                         _ViewerFor2DPosition ;
     CATFrmEditor              * _Editor;
     CATDisplayType              _layout;
     CATPathElement _TreeRoot;
     
};
#endif

