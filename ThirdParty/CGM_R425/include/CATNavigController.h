#ifndef CATNavigController_H_
#define CATNavigController_H_
// COPYRIGHT DASSAULT SYSTEMES  1999

/**
  * @CAA2Level L1
  * @CAA2Usage U1
  */
#include <CATOmnMain.h>


#include "CATEventSubscriber.h"
#include "CATINavigContainer.h"
#include "CATLISTP_CATBaseUnknown.h"
#include "CATIAV5Level.h"

#ifdef CATIAR418
class CATNavigControllerPrivateData;
#endif

class CATListValCATBaseUnknown_var;
class CATUnicodeString;
class CATHSO;
class CATPSO;
class CATNavigInstance;
class CATCommand;
class CATNavigSONotification;
class CATHashObject;
class CATHashTable;
class CATNavigInstance;

/** 
* Class used to control navigation. 
*/  

class ExportedByCATOmnMain CATNavigController:public CATEventSubscriber {
	CATDeclareClass;
#ifdef CATIAR418
  friend class CATNavigControllerPrivateData;
public:
  /** @nodoc */
  CATNavigControllerPrivateData* GetPvtData();
#endif
	
public:
  /** @nodoc */
	CATNavigController(const CATINavigContainer_var& container, CATCommand* cmd = NULL);

  /** @nodoc */
	virtual ~CATNavigController();
	
	/**
	* Retrieves nodes associated to an object.
  * <br><b>Role:</b>An object visualized in a tree, see @href CATINavigateObject ,
  * is represented by a node implementing @href CATIGraphNode , 
  * @href CATINavigElement , and @href CATINavigModify. This node is multi-
  * represented: there are as many nodes as tree instances. This method retrieves 
  * all the nodes associated with an object. 
	* @param iObject
	*    The object associated with the nodes.
  * @return 
  *    The list of nodes. A node is an object implementing @href CATINavigModify , 
  *    @href CATINavigElement , and @href CATIGraphNode.
  *    Returned pointer must be deleted.
	*/
	CATListValCATBaseUnknown_var* GetAssociatedElements(const CATBaseUnknown_var& iObject) const;

		/** @nodoc */
	void Spy();

	/**  
   *  Returns the container.  
   *  Returned pointer must be released.  
   */
	CATINavigContainer* GetContainer() const;

	/** 
	* Instances management.
	*  <br><b>Role:</b> Warning: Do not use this method if node already drawn in the graph. 
	*/
	void SetNoDuplicate();

		/** @nodoc */
	CATNavigInstance* GetFirstTwinInstance(CATNavigInstance*,CATIdent);
		/** @nodoc */
	CATBaseUnknown* GetAssociatedElement(CATNavigInstance* inst);
			
	/**
	* Sets the mode to manage the display of + and -  on arcs.
    * <br><b>Role:</b>This method sets the mode to manage the depth of representation.<br>
    *        <B>if mode =0 </B>: <BR>
	*         by default a + is always displayed on node. If you click on it,
    *          @href CATINavigateObject#GetChildren method is called on node and we try to
    *         display children.<br> 
    *         - If children exist, they are displayed and + is replace by a -.<br>
    *         - If there is no children, + disappear.<br>
    *         This behavior is same as windows explorer on network directory.
    *         Ergonomy is not perfect but it provides best performances.<br>
    *        <B>if mode =1 </B>: <BR>
	*         @href CATINavigateObject#GetChildren is always called once
    *         (even if children are not displayed) just to check if there are some children.<br>
    *          If there is no children, no sign is displayed on arc.<br>
    *          If there are some children a + is displayed on arc.<br>
    *         This behavior is same as windows explorer on local directory.<br>
    *         Ergonomy is better but it could impact performances if @href CATINavigateObject#GetChildren implementation is slow.
	* @param mode
	*    The mode value to manage the depth of representation.
	*/
	void SetDereferenceMode(int mode);
	/**
	* Retrieves the mode to manage the depth of representation.
	* <br><b>Role:</b>This method retrieves the mode to manage the depth of representation.
    * @return 
    *    The mode.
	*/
	int GetDereferenceMode() const;

	/** 
	 * @nodoc 
	 * management of the selection with CATPSO et CATHSO.
	 */
	void AttachToPSO(CATPSO* pso);
		/** @nodoc */
	void AttachToHSO(CATHSO* hso);

		/** @nodoc */
	CATListValCATBaseUnknown_var* GetSelectedObjects() const;

	/**
	* Sets expansion depth under a node.
	* @param iDepth
	*     if iDepth < 0, expand all children till there is no one left
	*/

	void SetDepth(int iDepth=1);
	/**
	* @nodoc
	*/
	int GetDepth() const;

	/**
	* Sets the +/- sign visibility.
	* <br><b>Role:</b> Warning: Do not use this method if node already drawn in the graph. 
	* @param mode
	*   Legal values:
	*   <ul>
	*  <li>0: Hide the +/- signs </li>
	*  <li>otherwise : show the +/- signs </li>
	*   </ul> 
	*/
	void SetActivatorsVisibility ( int mode );

	/** 
	* Retrieves the +/- sign visibility.
	* @return
	*   Legal values:
	*   <ul>
	*  <li>0: signs are hidden  </li>
	*  <li>otherwise   </li>
	*   </ul> 
	*/
	int GetActivatorsVisibility() const;

	/** 
	 * @nodoc 
	 * Order management.
	 */
	void SetOrderedList(int OrderedList=1);
		/** @nodoc */
	int GetOrderedList() const;
	
	/** 
	 * @nodoc 
	 * management of events for data creation.
	 */
	void SetDataCreateSubscribe(int DataCreateSubscribe=1);
		/** @nodoc */
	int GetDataCreateSubscribe() const;
	
	/** 
	* @nodoc 
	* Extended mode management.
	*/
	void SetExtensionMode(int ExtensionMode=1);
		/** @nodoc */
	int GetExtensionMode() const;
	
	
	
	/** @nodoc 
	* Management of model's events.
	*/
	void WakeMeOnDataCreate(	CATCallbackEvent evt,void* sender,
						CATNotification* notif, CATSubscriberData data,CATCallback cb);
										
		/** @nodoc */
	void WakeMeOnDataModify(	CATCallbackEvent evt,void* sender,
						CATNotification* notif, CATSubscriberData data,CATCallback cb);
										
		/** @nodoc */
	void WakeMeOnDataDelete(	CATCallbackEvent evt,void* sender,
						CATNotification* notif, CATSubscriberData data,CATCallback cb);

		/** @nodoc */
	void WakeMeOnRepDelete(		CATCallbackEvent evt,void* sender,
						CATNotification* notif, CATSubscriberData data,CATCallback cb);

		/** @nodoc */
	void WakeMeOnRepEdit(		CATCallbackEvent evt,void* sender,
						CATNotification* notif, CATSubscriberData data,CATCallback cb);

										
		/** @nodoc */
	void WakeMeOnRepSelect(CATCallbackEvent evt,void* sender,
						CATNotification* notif, CATSubscriberData data,CATCallback cb);
										
		/** @nodoc */
	void WakeMeOnRepExtSelect(CATCallbackEvent evt,void* sender,
						CATNotification* notif, CATSubscriberData data,CATCallback cb);
										
		/** @nodoc */
	void WakeMeOnRepAction(CATCallbackEvent evt,void* sender,
						CATNotification* notif, CATSubscriberData data,CATCallback cb);

		/** @nodoc */
    void WakeMeOnRepExpand(CATCallbackEvent evt,void* sender,
                        CATNotification* notif, CATSubscriberData data,CATCallback cb);

 		/** @nodoc */
    void WakeMeOnRepMethods(CATCallbackEvent evt,void* sender,
                        CATNotification* notif, CATSubscriberData data,CATCallback cb);

	    /** @nodoc 
	      * Deprecated R6. This method should not be used.
	      */
	void WakeMeOnRepMulti(CATCallbackEvent evt,void* sender,
						CATNotification* notif, CATSubscriberData data,CATCallback cb);

		/** @nodoc */
        void AddElement(CATNavigInstance* instance,const CATBaseUnknown_var& element,int mode=0);
		/** @nodoc */
        void Intersect (CATListOfCATUnicodeString*,const CATListOfCATUnicodeString*);

		/** @nodoc */
	static void EndTransaction (CATCommand* ToClient,int State,void* clientdata);
		/** @nodoc */
	CATHashObject*& GetInstancesList();
		/** @nodoc */
	CATHashObject*& GetElementsList();
		/** @nodoc */
	CATHashObject*& GetUpdateList();

		/** @nodoc */
	void PutInUpdateList ( CATBaseUnknown* obj );

	/** @nodoc 
	* Management of the list of expanded nodes.
	*/
	int AddExpandedNode(CATNavigInstance* Inst);
	/** @nodoc */
	int RemoveExpandedNode(CATNavigInstance* Inst);
	/** @nodoc */
	int ListedExpandedNode(CATNavigInstance* Inst);
	/** @nodoc */
	int GetNbExpandedNodes();
	/** @nodoc */
	void SetFixDepthMode(int FixMode);
	/** @nodoc */
	int GetFixDepthMode();

  /** @nodoc */
  static CATListPtrCATBaseUnknown* GetControllerList();

  /** @nodoc */
  inline CATOMNID_t GetId() const { return _ctrlId; }

  /** @nodoc */
  static CATBoolean IsRedrawLocked(); //JNV06082008++ : à supprimer sur GA

  /** @nodoc */
  CATBoolean IsControllerLockForRedraw(); //JNV15092008++

private:
	// Methodes d'ajout et de suppression de la liste de correspondance
//	int RemoveInstance(CATNavigInstance* instance);
	int RemoveElement(const CATBaseUnknown_var& element);
	int Locate(CATNavigInstance*);
	
	void AddDataSubscriptions(CATNavigInstance* instance,int mode);
	void RemoveDataSubscriptions(CATNavigInstance* instance);
	void AddRepSubscriptions(const CATBaseUnknown_var& element);
	void RemoveRepSubscriptions(const CATBaseUnknown_var& element);
	// ajout bpe
	void AddRedrawSubscription(CATNavigInstance* instance,int mode);
	void RemoveRedrawSubscription(CATNavigInstance* instance);
	// ajout bpe fin

  /** @nodoc */
  static void LockRedraw();     //JNV06082008++ : à supprimer sur GA
  /** @nodoc */
  static void UnlockRedraw();   //JNV06082008++ : à supprimer sur GA
  /** @nodoc */
  static void ThisRedrawIsForbidden(); //JNV06082008++ : à supprimer sur GA

  /** @nodoc */
  void LockControllerForRedraw(); //JNV15092008++

  /** @nodoc */
  void UnlockControllerForRedraw(); //JNV15092008++

	// Data

	CATINavigContainer_var _container;
	CATHashObject* _associated_reference;
	CATHashObject* _associated_instance;
	
	int _no_duplicate;
	int _depth;
public:
	/** @nodoc */
	void* _hso;
	/** @nodoc */
	void* _pso;
	/** @nodoc */
    CLSID* _controlID;
	/** @nodoc */
	static CATListPtrCATBaseUnknown* _ControllerList; //JNV06082008 : à passer en privé, faire migrer les applis sur GetControllerList()
private:
	int _OrderedList;
	int _ExtensionMode;
	int _activ_visibility;
	int _DataCreateSubscribe;

	CATCommand* _Cmd;
	
	CATHashObject*			_liste_update;
	CATNavigSONotification*		_navigso;

	// Table des noeuds expanses, pour la persistance de l'etat des noeuds
	// Gestion par le nom du chemin du noeud
	CATHashTable* _ExpandedNodes;
	int _FixDepthMode;
	int _dereference_mode; /** @win64 fbq : 64-bit structure padding **/
  CATOMNID_t _ctrlId;
  static CATBoolean _LockRedraw;            //JNV06082008++ : à supprimer sur GA
  static CATNavigController* _CtrlerInLock; //JNV15092008++ : enregistrement blocage/non blocage des Redraw 
#ifdef CATIAR418
  CATNavigControllerPrivateData* _privateData;
#endif
};


#endif
