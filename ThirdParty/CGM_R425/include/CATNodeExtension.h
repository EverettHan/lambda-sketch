/* -*-c++-*- */

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */
//
#ifndef CATNodeExtension_H_
#define CATNodeExtension_H_

#include <CATOmnExt.h>


#include  "CATBaseUnknown.h" 
#include "booleanDef.h"
#include  "CATUnicodeString.h"
#include  "CATListOfCATUnicodeString.h"
#include  "CATErrors.h"
#include  "CATEventSubscriberTypedefs.h"
#include  "CATLISTV_CATBaseUnknown.h"
#include "CATINavigNodeCtrl.h"
#include  "IUnknown.h"
#include  "CATBoolean.h"

class CATINavigContainer;
class CATNavigController;
class CATNavigInstance;
class CATIGraphNode_var;
class CATIGraphNode;

/**
 * Adapter class for CATINavigElement and CATINavigModify and CATINavigNodeCtrl interfaces.
 * <b>Role:</b> This class enables you to implement the @href CATINavigElement
 * and @href CATINavigModify and @href CATINavigNodeCtrl interfaces.<br>
 * BEWARE:<br>
 * - You must call a method through its interface. For example, if you want to call @href #GetExpansionMode ,
 *   first query the interface @href CATINavigNodeCtrl and then call its method @href CATINavigNodeCtrl#GetExpansionMode .<br>
 * - You must use the <tt>DataExtension</tt> mode.
 */

class ExportedByCATOmnExt CATNodeExtension : public CATBaseUnknown
{
public:
  /** @nodoc */
  friend class CATContainerExtension;

  CATDeclareClass;

  /**
   * Constructs a CATNodeExtension.
   */
  CATNodeExtension();

  /** @nodoc */
  virtual ~CATNodeExtension();

  // --------------------------------------------------------------------------
  // Interface CATINavigElement

  /**
   * Updates node.
   * <br><b>Role:</b>This method updates the text, the icon,
   * and the children nodes (creation/deletion).
   * @see CATINavigElement
   */
  virtual void Update();

  /**
   * Defines behavior after selection of this node.
   * <br><b>Role:</b>This method highlights the node.
   * @see CATINavigElement
   */
  virtual void ProcessAfterSelect();

  /**
   * Defines behavior after selection of several nodes.
   * <br><b>Role:</b>This method pre-highlights the node.
   * @see CATINavigElement
   */
  virtual void ProcessAfterExtSelect();

  /**
   * Defines behavior after double-click of this node.
   * <br><b>Role:</b>This method calls the @href #ProcessAfterExpand method.
   * @see CATINavigElement
   */
  virtual void ProcessAfterAction();

  /**
   * Defines behavior after expand of this node.
   * <br><b>Role:</b>This method expands or collapses the node.
   * @see CATINavigElement
   */
  virtual void ProcessAfterExpand();

  /**
   * Defines the contextual menu after selecting a node.
   * <br><b>Role:</b>This method does nothing.
   * @see CATINavigElement
   */
  virtual void ProcessAfterMethod();

  /**
	 * Retrieves the instance associated with the node.
   * <br><b>Role</b>: This method retrieves the object associated with the
   *  node.  
	 * @return 
   * The associated instance.
   * <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
   *  returned value.
   * @see CATINavigElement
	 */
  virtual CATNavigInstance* GetAssociatedInstance();

  /** @nodoc */
  virtual void SetMarked(int mark=1);
  /** @nodoc */
  virtual int  GetMarked();

  // --------------------------------------------------------------------------
  // Interface CATINavigNodeCtrl

  /**
   * @nodoc
   * Interface CATINavigNodeCtrl
   */
  virtual void Dereference(int depth);
  /**
   * @nodoc
   * Interface CATINavigNodeCtrl
   */
  virtual void Undereference();
  /**
   * @nodoc
   * Interface CATINavigNodeCtrl
   */
  virtual void PutAssociatedInstance(CATNavigInstance* inst);

  /**
   * Gets the expansion mode.<br>
   * The default is <tt>ExpandableIfWithChild</tt>. You may override this method in order to return your expansion mode.
   * @param oExpansionMode
   *   The expansion mode.
   */
  virtual void GetExpansionMode(CATINavigNodeCtrl::ExpansionMode &oExpansionMode) const;

  // --------------------------------------------------------------------------
  // Interface CATINavigModify

  /**
   * Defines node graphic representation.
   * <br><b>Role</b>:This method is empty.
   * @param iInst
   *   The navig instance associated with the node.
   * @see CATINavigModify
   */
  virtual void UpdateElem (CATNavigInstance* iInst);

  /**
   * Defines the node short help.
   * <br><b>Role</b>: This method defines the default behavior for the short help of a node.
   * When you pass over a node a short help is displayed whose the text
   * is either the name returned by the @href CATINavigateObject#GetIdentificators
   * method, or if defined, the text set thanks to the @href CATIGraphNode#SetText method.
   * @param ioText
   *   The short help of the node.
   *   <br>In input <tt>ioText</tt> is the text associated with the node.
   * @return
    *    The displaying state.
    *    <br><b>Legal values</b>: 
    *     <ul>
    *      <li>E_FAIL: no short help will be displayed</li>
    *      <li>S_OK : <tt>ioText</tt> will be displayed</li>
    *     </ul>
   * @see CATINavigModify
   */
  virtual HRESULT ModifyShortHelp(CATUnicodeString& ioText) ;

  /**
   * Defines whether the node is selectable or not.
	 * <br><b>Note:</b> This method enables you to control 
   *  the node selection. The default behavior brings the node selectionnable.
   * @param mode
   *   The selectable mode.
   * @see CATINavigModify
   */
  virtual void Select(int mode);

  /**
   * Defines whether the node has ever been selected.
   * @return
   *    The selecting state.
   *    <br><b>Legal values</b>: 
   *     <ul>
   *      <li>0: The node is not selected</li>
   *      <li>Otherwise : selected</li>
   *     </ul>
   * @see CATINavigModify
   */
  virtual int IsSelected();

  // --------------------------------------------------------------------------
  // Miscellaneous

  /**
   * @nodoc
   * Removes a node.
   * @param iIndex
   *    useless
   *
   */
  virtual void Remove(int iIndex);

  /**  
   *  Returns  the  father container.  
   *  Returned  pointer  must  be  released.  
   */
  virtual CATINavigContainer* GetFatherContainer();

  /**  
   *  Retrieves the tree controller.  
   *  @return    
   *  The tree controller.  
   *  <br><b>Lifecycle rules deviation</b>:  This method doesn't AddRef the    
   *   returned value.
   * @see CATINavigElement
   */  
  virtual const CATNavigController* GetController();

  /**
   * @nodoc
   * redraw services.
   */
  int UpdateText();

  /**
   * @nodoc
   */
  int UpdateIcon();

  /**
   * @nodoc
   */
  int UpdateChildren();

  /**
   * @nodoc
   * highlight management services.
   */
  int AddRefForSelect();
  /**
   * @nodoc
   * highlight management services.
   */
  int ReleaseForSelect();

private:
// ### AS SOON AS POSSIBLE!  CATNodeExtension(const CATNodeExtension &iObject); // Prohibited
// ### AS SOON AS POSSIBLE!  CATNodeExtension &operator=(const CATNodeExtension &iObject); // Prohibited

  void CreateNode(const CATIGraphNode_var& hFatherNode,CATNavigInstance* pFatherInst,CATNavigInstance* pChildInst, int depth);

  //JNV07082008NOTCONVERGED static HRESULT UpdateGraphNodeInTree(CATIGraphFactory* iGraphFactory, CATIGraphContainer* iGraphContainer, CATNavigController* iController, 
  //JNV07082008NOTCONVERGED                                      CATIGraphNode*    iGraphNode,    CATNavigInstance*   iNavigInstance);

  //JNV07082008NOTCONVERGED static HRESULT AppendGraphNodeInTree(CATIGraphFactory* iGraphFactory, CATIGraphContainer* iGraphContainer, CATIGraphNode* iGraphNode);

  //JNV07082008NOTCONVERGED static HRESULT ExpandGraphNodeInTree(CATNavigController* iController, const int iDepthBeforeUpdate, const int iDepthAfterUpdate,
  //JNV07082008NOTCONVERGED                                      CATINavigNodeCtrl*  iNodeCtrl, CATINavigElement* iNavigElem,  CATNavigInstance* iNavigInstance);

  //JNV07082008NOTCONVERGED static HRESULT ExpandGraphNodeInTreeWithoutUpdateElem(const int iDepth, CATINavigNodeCtrl* iNodeCtrl, CATINavigElement* iNavigElem);

  static void UpdateGraphNodeState(CATIGraphNode &ioGraphNode, CATBoolean iActivatorsVisibility,
                                   CATINavigNodeCtrl::ExpansionMode iExpansionMode, int iNbChildren, CATBoolean iNodeIsExpanded);

  int _for_updateelem:1;
  int _count_select:2;
  int _nb_children;
};

#endif
