#ifndef CATNavigInstance_H_
#define CATNavigInstance_H_

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @CAA2Level L1
  * @CAA2Usage U1
  */


#include <CATOmnMain.h>

#include "CATBaseUnknown.h"
#include "IUnknown.h"
#include "CATIAV5Level.h"

#ifdef CATIAR418
class CATNavigInstancePrivateData;
#endif

class CATListPtrCATNavigInstance;
class CATListValCATBaseUnknown_var;
class CATListValCATUnicodeString;

/** Class used to navigate through an instance. */ 
class ExportedByCATOmnMain CATNavigInstance {
#ifdef CATIAR418
  friend class CATNavigInstancePrivateData;
public:
  /** @nodoc */
  CATNavigInstancePrivateData* GetPvtData();
#endif
public:
	/** @nodoc */
	CATNavigInstance(const CATBaseUnknown_var& instance,CATNavigInstance* father=0);
	/** @nodoc */
	virtual ~CATNavigInstance();

public:
	/** @nodoc */
	CATNavigInstance* GetFather();

	/** 
     * Retrieves the component associated with the node.
     * <br><b>Role:</b> This method allows you to retrieve a pointer
     * on the component displayed in an object tree. It is the same
     * component which implements @href CATINavigateObject. 
     * <br>The @href CATINavigModify and the @href CATINavigElement
     * interfaces are implemented on a late type which is not the component itself. 
     * Thanks to the @href CATINavigElement#GetAssociatedInstance method and the current one, 
     * you have a pointer on the component.
     * @return 
     *   A component pointer.
     */
	const CATBaseUnknown_var& GetReference();

	//JNV31072008NOTUSED /** @nodoc */
	//JNV31072008NOTUSED const IUnknown*	GetIUnknown();
	//JNV02092008REPLACE /** @nodoc */
	//JNV02092008REPLACE void SetNULLFather();
	/** @nodoc */
  void SetFather( CATNavigInstance* new_father );

	/** @nodoc */
  CATListValCATUnicodeString* GetInformation(CLSID * guid);
	/** @nodoc */
	CATListPtrCATNavigInstance* Dereference(CLSID* guid);
	
	/** @nodoc */
	int _update_select;

	/** 
	* @nodoc 
	* Profondeur du noeud dans le graphe par rapport a la racine (valeur relative)
	*/
	int GetDepth();
	/** @nodoc */
	void SetDepth(int depth);

	/** @nodoc */
	unsigned int AddRef();
	/** @nodoc */
	unsigned int Release();
	/** @nodoc */
  inline void SetExpanded(unsigned iBool) { m_expanded = iBool; }
	/** @nodoc */
  inline unsigned IsExpanded() const { return m_expanded; }

private:

  /** @nodoc */
  void PrintRef(const char* iMessage, const char* iSep, unsigned int iRef); //JNV31072008++

	//JNV31072008NOTUSED IUnknown*	       _object;
	CATBaseUnknown_var _instance;
	CATNavigInstance*  _father;
	unsigned int	     _depth:31;
	unsigned int       m_expanded:1;
	unsigned int       _ref;
	//JNV02092008NOTUSED CATBaseUnknown*    m_element;
  CATOMNID_t         _instId;
#ifdef CATIAR418
  CATNavigInstancePrivateData* _privateData;
#endif

public:
	/** @nodoc */
  CATBaseUnknown *GetReferenceImpl();
	//JNV02092008NOTUSED /** @nodoc */
  //JNV02092008NOTUSED inline CATBaseUnknown *GetElement() { return m_element; }
	//JNV02092008NOTUSED /** @nodoc */
  //JNV02092008NOTUSED void SetElement(CATBaseUnknown *element);
  /** @nodoc */
  inline CATOMNID_t GetId() const { return _instId; }
  /** @nodoc */
  void SetUpdateSelect(const int iUpdateSelect);
  /** @nodoc */
  inline int GetUpdateSelect() const { return _update_select; }

};


#endif
