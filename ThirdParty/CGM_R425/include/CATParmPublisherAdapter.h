#ifndef CATParmPublisherAdapter_H
#define CATParmPublisherAdapter_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U2 
 */


/*  CAA2Reviewed by FRH */

// Export Module 
#include "CATLifSpecs.h"

// inherit from
#include "CATBaseUnknown.h"

//Forwards
#include "CATICkeRelationForwards.h"


#include "CATIParmPublisher.h"
class CATIVisitor;
class CATICkeObject_var;



/**   
 * CAA Adapter to CATIParmPublisher Interface.
 * <b>Role</b>: This class should be derived to implement features extension to CATIParmPublisher.<br>
 * CATIParmPublisher is the interface used by Knowledgeware to have access to all the parameters<br>
 * and relations of a feature.<br>
 * It is also used on some objects to add user parameters and relations to features<br>
 * The intent of this adapter is not to provide a default implementation: in fact the default implementation is usually to do nothing.<br>
 * We provide an adapter to enable the introduction of new methods in the future on the CATIParmPublisher interface without breaking the 
 * buildtime of our CAA customers.<br>
 * @see CATIParmPublisher
 */
class ExportedByCATLifSpecs CATParmPublisherAdapter : public CATIParmPublisher
{
public:

   /** 
    * Constructs the extension.
    */ 
    CATParmPublisherAdapter();

   /** 
    * Deletes the extension.
    */ 
    virtual ~CATParmPublisherAdapter();


  //-------------------------------------------
  // Interface CATIParmPublisher implementation
  //-------------------------------------------

  /**
   * Appends a user parameter or a relation to this feature.
   * You must implement this method if you have answered TRUE to the AllowUserAppend method.
   * The SpecObject passed as argument must have been created in the container returned by the Container method.
   * Default implementation does nothing.<br>
   * @param  iFeatureToAppend relation or parameter to append 
   */
   virtual void AppendElement  (const CATBaseUnknown_var & iFeatureToAppend ) ;


  /**
   * Removes a user parameter or a relation from this feature.
   * Default implementation does nothing.<br>
   * You must implement this method if you have answered TRUE to the AllowUserAppend method.
   * @param  iFeatureToRemove relation or parameter to remove 
   */
   virtual void RemoveElement  (const CATBaseUnknown_var & iFeatureToRemove ) ;


  /**
   * Indicates if this publisher allows the use of Append (and RemoveChild) method.<br>
   * It is mostly used to prevent those operations if the object implementing the
   * interface isn't able to manage it.
   * Default implementation is FALSE.
   * @return <b>Legal values</b>:
   * <tt>TRUE</tt> Append and Remove of objects are authorized
   * <tt>FALSE</tt> Append and Remove of objects are not authorized.
   */
  virtual boolean AllowUserAppend ( ) const ;

  /** 
   * This method has to return the associated container of the publisher.
   * It is used to create the user parameters when AllowUserAppend returns True.
   * In this case, you should implement this method.
   * Default implementation returns NULL.
   * @return The container
   */
  virtual CATICkeParmFactory_var GetFactory();

  /** 
  * This method is another one to browse publishers hierarchy (recursively or not). The choice of good instances is delegated to the given visitor 
  * (it can put good instances in a list, or keep only one, depending on the goal of the "visit").<br>
  * The default implementation does nothing.<br>
  * To implement this method, you must scan your local parameters, scan your components and ask the Visit on them.
  * If the recur=1, you must call VisitChildren recursively on your components.<br>
  * Remember that if the method Visit doesn't succeed, it means that the visit can end.
  * @param iVisitor object to call during the visit
  * @param recur 1 if we want the visit to be recursive, 0 instead
  */
  virtual void VisitChildren(CATIVisitor* iVisitor, const int recur = 0);

  //-------------------------------------------
  // Interface CATIChildrenAccess implementation (new in R1.X)
  // This interface is an alternative to CATIParmPublisher to manage composition, for objects that do not have parameters.
  //-------------------------------------------
  
  /**
   * Indicates if this object allow the use of AddComponent (and RemoveComponent) method.
   * It is mostly used to prevent those operations if the object implementing the
   * interface isn't able to manage it.
   * Default implementation is FALSE.
   * @return <b>Legal values</b>:
   * <tt>TRUE</tt> Add and Remove of objects are authorized
   * <tt>FALSE</tt> Add and Remove of objects are not authorized.
   */
  virtual boolean AllowAppend ( ) const ;

  /** 
  * This method is another one to browse publishers hierarchy (recursively or not). The choice of good instances is delegated to the given visitor 
  * (it can put good instances in a list, or keep only one, depending on the goal of the "visit").<br>
  * The default implementation does nothing.<br>
  * To implement this method, you must scan your components and ask the Visit on them.
  * If the recur=1, you must call VisitChildren recursively on your components.<br>
  * Remember that if the method Visit doesn't succeed, it means that the visit can end.<br>
  * Default implementation calls the VisitChildren method.
  * @param iVisitor object to call during the visit
  * @param recur 1 if we want the visit to be recursive, 0 instead
  * @return classic HRESULT
   */
  virtual HRESULT VisitComponents(CATIVisitor* iVisitor, const int recur = 0);
	  
  /**
   * Appends components under the object.
   * @param iKBwareObject object to be appended
   * Default implementation returns E_FAIL.
   * @return E_FAIL if your object does not accept this kind of object.
  */
  virtual HRESULT AddComponent      (const CATICkeObject_var & iKBwareObject )    ;

  /**
   * Removes components under the object.
   * @param iKBwareObject knowledgeware object to be removed.
   * Default implementation returns E_FAIL.
   * @return E_FAIL if the remove operation has failed.
   */
  virtual HRESULT RemoveComponent   (const CATICkeObject_var & iKBwareObject )   ;

  //-------------------------------------------
  // Interface CATIParmDirectAccess
  //-------------------------------------------

  /**
   * Retrieves the list of components from the outside.
   * @param  iIntfName name of the interface asked. 
   * @param  iListToFill list filled with the components
   * @return classic HRESULT
   * Default implementation returns E_FAIL.
   */
  virtual HRESULT RetrieveDirectChildren (CATClassId iIntfName,CATLISTV(CATBaseUnknown_var) &iListToFill)   const     ;

private:
 
  /**
   * copy constructor
   */
   CATParmPublisherAdapter(const CATParmPublisherAdapter&);
};


#endif
