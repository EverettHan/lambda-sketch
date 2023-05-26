#ifndef CATIOmiSet_H
#define CATIOmiSet_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @level Protected 
 * @usage U3
 */

#include "IUnknown.h"
#include "CATBooleanDef.h"
#include "CATOmiClusterItf.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOmiClusterItf IID IID_CATIOmiSet;
#else
extern "C" const IID IID_CATIOmiSet ;
#endif
 
class CATUnicodeString;
//class CATIOmiCluster;
class CATBaseUnknown;

/**   
 * Cluster set data access. 
 * <b>Role</b>:
 * The set is a subdivision of the cluster private area.<br> 
 * Sets can be retrieved using @href CATIOmiCluster#ListSets. <br>
 * <li>The set is characterized by attributes that can be accessed using this interface. 
 * The type and role attributes are internal text labels given to the set by the applicative code creating it.
 * Those attributes can lated be used to retrieve a given set among all sets within a cluster.</li>
 * <li>The set is a handler to an associated session object that holds all the applicative data created using this set.</li>
 * <li>The set data is not necessarily loaded in memory. This can be tested using @href IsSessionObjectLoaded .</li>
 * <li>Add-refing this interface does not prevent the session object from being unloaded from memory.</li>
 * <li>Some methods of this interface will trigger the load of the corresponding cluster if necessary.</li>
 * <br>
 * <i>NOTE: This is an @href IUnknown interface. Do not try to cast it to a @href CATBaseUnknown !</i>
 *
 *  @see CATIOmiClusterPlug
 *  @see CATIOmiCluster
 */
class ExportedByCATOmiClusterItf CATIOmiSet: public IUnknown
{
//#ifndef REMOVE_USELESS_INCLUDE
public:

  /**
  * Sets the cluster set role attribute.
  * <br><b>Role:</b>This method changes the set "role" attribute (see the class description for further detail)<br>
  * It can afterwards be retrieved using @href GetRole .<br>
  * <br><i>NOTE: The cluster data will be loaded if not already in memory.</i>
  *
  * @param iRole
  *     The role attribute value to be used.
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The role was succesfully set.</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>Test error code with @href CATTestClusterError </dd>
  *   </dl>
  * @error CATOmbClusterInternalError Internal_ClusterDataRetrievalFailed
  *     The cluster data could not be retrieved in memory nor loaded. 
  * @error CATOmbClusterInternalError Internal_InvalidClusterData
  *     Integrity problem with the cluster data. 
  **/

  virtual HRESULT SetRole( const CATUnicodeString &iRole ) = 0;

 /**
  * Retrieves the cluster set role attribute.
  * <br><b>Role:</b>This method retrieves the cluster set "role" attribute. (see the class description for further detail)<br>
  * The set role is specified when the set is created. It can be changed using @href SetRole .<br>
  * <br><i>NOTE: The cluster data will be loaded if not already in memory.</i>
  *
  * @see CATIOmiSet#SetRole
  *
  * @param oRole
  *     The role attribute value.
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The role was successfully retrieved.</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>Test error code with @href CATTestClusterError </dd>
  *   </dl>
  * @error CATOmbClusterInternalError Internal_ClusterDataRetrievalFailed
  *     The cluster data could not be retrieved in memory nor loaded. 
  * @error CATOmbClusterInternalError Internal_InvalidClusterData
  *     Integrity problem with the cluster data. 
  **/
 
  virtual HRESULT GetRole( CATUnicodeString &oRole ) const = 0;

 /**
  * Retrieves the cluster set type.
  * <br><b>Role:</b>This method retrieves the set "type" attribute.<br> 
  * This attribute is read-only and is populated when the cluster set is created.<br>
  * <br><i>NOTE: The cluster data will be loaded if not already in memory.</i>
  *
  * @param oRole
  *     The role attribute value.
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The role was succesfully retrieved.</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>Test error code with @href CATTestClusterError </dd>
  *   </dl>
  * @error CATOmbClusterInternalError Internal_ClusterDataRetrievalFailed
  *     The cluster data could not be retrieved in memory nor loaded. 
  * @error CATOmbClusterInternalError Internal_InvalidClusterData
  *     Integrity problem with the cluster data.   **/

  virtual HRESULT GetType( CATUnicodeString &oType ) const = 0;

 /**
  * Retrieves the set's cluster.
  * <br><b>Role:</b>This method retrieves the cluster this set is included in.<br> 
  * <i>Note: the cluster data doesn't need to be loaded in memory.</i>
  *  
  * @param opCluster
  *   A CATIOmiCluster interface pointer on the corresponding cluster.
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The cluster was succesfully retrieved.</dd>
  *   </dl>
  **/

  //virtual HRESULT GetCluster( CATIOmiCluster* &opCluster ) const = 0;

 /**
  * Retrieves the set's associated session object. 
  *
  * @deprecated V5R201 CATIOmiContBasedSet::GetContainer() 
  *
  * <br><b>Role:</b>This method retrieves the session object corresponding to the set. 
  * The session object will be loaded if not already in memory. It is add-refed before being returned.
  *  
  * @param opObject
  *   A CATBaseUnknown pointer to the corresponding memory object.
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The session object was succesfully retrieved.</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>Test error code with @href CATTestClusterError </dd>
  *   </dl>
  * @error CATOmbClusterInternalError Internal_ClusterDataRetrievalFailed
  *     The cluster data could not be retrieved in memory nor loaded. 
  * @error CATOmbClusterInternalError Internal_InvalidClusterData
  *     Integrity problem with the cluster data. 
  * @error CATOmbClusterInternalError Internal_ContainerLoadFailed
  *     Could not load container. 
  **/

  virtual HRESULT GetSessionObject( CATBaseUnknown* &opObject ) const = 0;

 /**
  * Tests if two cluster sets are equal.
  * <br><b>Role:</b>.This methods tests if the provided object is a cluster set referencing
  * the same object as "this".
  *
  * @return
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The two sets are equal.</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>The two sets are not equal.</dd>
  *   </dl>  
  **/  	

  virtual HRESULT IsEqual( const IUnknown *ipSet ) const = 0;
//#else
//#pragma  message  ("BADREM : YCM 070215 "  __FILE__  " Stop Using CATIOmiClusterPlug")  
//#endif
};


#endif
