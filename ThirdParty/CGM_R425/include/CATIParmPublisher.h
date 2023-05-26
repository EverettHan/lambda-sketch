#ifndef CATIParmPublisher_h
#define CATIParmPublisher_h

// COPYRIGHT DASSAULT SYSTEMES 1999
   
/** 
 * @CAA2Level L1
 * @CAA2Usage U4 CATParmPublisherAdapter 
 */

/*  CAA2Reviewed by FRH */

// inherited from
#include "CATBaseUnknown.h"

// export load module
#include "CATLifSpecs.h"

// forward declaration
#include "CATICkeRelationForwards.h"
#include "CATIVisitor.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIParmPublisher;
#else
extern "C" const IID IID_CATIParmPublisher;
#endif

#include "CATICkeParmFactory.h"

/**   
 * Interface dedicated to parameters publishing.
 * <b>Role</b>: This interface is to be implemented by objects that want to publish<br>
 * their own parameters to F(x) and KnowledgeAdvisor.<br>
 * This interface has 2 goals:<br>
 * <li>the AppendElement and RemoveElement are used by Knowledgeware to add KBware features 
 * to the root (example : user parameters or relations).</li>
 * <li>the VistChildren is used to find from the root object,
 * objects that are important for Knowledgeware such as parameters and relations.</li>
 * This interface must at least be implemented by Root Features (ex: Part).<br>
 * Other applications features may implement this interface to answer more locally 
 * (and so to filter) to VisitChildren methods. It corresponds
 * to the parameters that are known by this feature or that belong to this feature.<br>
 *
 * <p><b>BOA information</b>: this interface CAN be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page.
 * Click Middleware at the bottom left, then click the Object Modeler tab page.
 * Several articles deal with the BOA.</p>
 *
 */
//-----------------------------------------------------------------------------
class ExportedByCATLifSpecs CATIParmPublisher : public CATBaseUnknown
{

 public:
  
/**
 * Appends user parameters and relations to the current object.
 * The object is the Application Root Feature that implements the current interface
 * @param iKBwareObject knowledgeware object to append to the root object.
 * The object implementing CATIParmPublisher and the object to append must be in the same container.
 * This will be enforced in the future to allow only authorized data model.
 */
  virtual void AppendElement  (const CATBaseUnknown_var & iKBwareObject )  = 0    ;

/**
 * Removes user parameters and relations from this object.
 * The object is the Application Root Feature that implements the current interface
 * @param iKBwareObject knowledgeware object to remove from the root object.
 */
  virtual void RemoveElement  (const CATBaseUnknown_var & iKBwareObject )  = 0    ;



/**
 * Indicates if this publisher allow the use of Append (and RemoveChild) method.
 * It is mostly used to prevent those operations if the object implementing the
 * interface isn't able to manage it.
 * @return <b>Legal values</b>:
 * <tt>TRUE</tt> Append and Remove of objects are authorized
 * <tt>FALSE</tt> Append and Remove of objects are not authorized.
 */
  virtual boolean AllowUserAppend ( ) const =0;

  /** 
  * This method has to return the associated container of the publisher : in different contexts, the system needs a container when using a CATIParmPublisher.
  * This interface can be implemented on different type of objects
  * (specs, container, documents, and non persistent objects), so container retrieval can be different depending on this type.
  * The default implementation on CATCkeInstanceAdapter asserts that the object implementing CATIParmPublisher also implements CATISpecObject.
  * If it is not the case for your object, you must overload this method.
  * @return the container
  */
  virtual CATICkeParmFactory_var GetFactory() = 0;

  /** 
  * This method is another one to browse publishers hierarchy (recursively or not). The choice of good instances is delegated to the given visitor 
  * (it can put good instances in a list, or keep only one, depending on the goal of the "visit").<br>
  * The default implementation (in CATCkeInstanceAdapter) doesn't handle new litterals (based on spec attributes). If you want your publisher to publish such litterals, you have to
  * overload this method. The principle is to visit each published instance and if the visit is recursive, to call VisitChildren on each instance implementing CATIParmPublisher. 
  * Remember that if the method Visit doesn't succeed, it means that the visit can end.
  * @param iVisitor visitor to call during the visit
  * @param recur 1 is the visit is recursive, 0 instead
  */
  virtual void VisitChildren(CATIVisitor* iVisitor, const int recur = 0) = 0;

  private :
     
    CATDeclareInterface;
  
};

CATDeclareHandler(CATIParmPublisher,CATBaseUnknown);

#endif


