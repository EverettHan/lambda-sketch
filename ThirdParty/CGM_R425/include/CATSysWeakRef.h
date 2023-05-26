#ifndef CATSysWeakRef_h
#define CATSysWeakRef_h
#include "JS0CORBA.h"

// COPYRIGHT DASSAULT SYSTEMES 2001


/**
 * Class to represent a weak reference on a component.
 * The weak reference is obtained by the @href CATBaseUnknown#GetComponentWeakRef method
 */

class CATBaseUnknown;
struct DataForImpl;

class ExportedByJS0CORBA CATSysWeakRef {
  friend class CATBaseUnknown;
  friend  struct DataForImpl;

public: 
 /**
  * Adds a Reference to weak reference.
  */
  void AddRef() ;

  /**
  * Removes a reference to weak reference.
  */
 void Release(); 
 
 /** 
   * Returns an addrefed component.
   * return can be null
   */
  CATBaseUnknown *GetComponent();
 
  /** 
   * @nodoc
   * Internal use only 
   * return can be null
   * used for compatibility with CATISpecObject_ARH
   */
  inline CATBaseUnknown *GiveComponent() { return m_component; }
  
		
protected:

  unsigned int m_cref;
  CATBaseUnknown *m_component;
  
  /**
    * Only used by CATBaseUnknown::GetComponentWeakRef()
    */  
  CATSysWeakRef(CATBaseUnknown *component);
  
  /**
    * Only used by CATSysWeakRef::Release()
    */  
  
  ~CATSysWeakRef();
   /**
    * Only used by CATBaseUnknown::Release() / CATBaseUnknown::~CATBaseUnknown()
    */  
  void KillRef();

};
#endif //CATSysWeakRef_h
