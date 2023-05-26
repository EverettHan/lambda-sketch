//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2005 
//-----------------------------------------------------------------------------
// class CATOmcContainer 
//-----------------------------------------------------------------------------
/**
 * @level Protected
 * @usage U2
 */
/* -*-c++-*- */
#ifndef CATOmcContainer_H
#define CATOmcContainer_H

// COPYRIGHT DASSAULT SYSTEMES 2005

#include "CATObject.h"
#include "CATOmcBase.h"
#include "CATBaseUnknown.h"
#include "CATLISTP_CATBaseUnknown.h"
#include "CATUuid.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATIOmbPlug.h"
#include "CATOmxSR.h"
#include "CATOmxVector.h"
class CATIAEntity;
class CATStorageProperty;
/**
  * Class to construct objects that corresponds to a container.
  * <br><b>Role:</b> This object is able to retrieve informations about 
  * the container. 
  * This informations concern the corresponding element in the V4 Data Structure.
  * The member data are the following:
  * <ul> 
  * <li> The Uuid of the corresponding V4 Element</li>
  * <li> The list of the container's sons</li>
  * <li> The CATIAEntity* corresponding to the V4 Element</li>
  * </ul>
  * The methods are the following:
  * <ul> 
  * <li> SetUUID</li>
  * <li> GetUUID</li>
  * <li> AddContainer</li>
  * <li> RemoveContainer</li>
  * <li> GetContainerList</li>
  * <li> SetContainerList</li>
  * <li> GetV4Element</li>
  * <li> SetV4Element</li>
	* <li> Internal services for UUID management</li> 
  * </ul>
  */
class ExportedByCATOmcBase CATOmcContainer : public CATIOmbPlug
{
public:
  CATOmcContainer(const char* iType,const char* iSuperType,CATOmcContainer* iParent,CATDocument* iDocument) ;
  virtual ~CATOmcContainer() ; 


  virtual HRESULT __stdcall QueryInterface(const IID& iIID,void** oPPV);
  virtual CATBaseUnknown* QueryInterface(CATClassId iInterface) const;
  virtual CATDocument* GetDocument() const;
  virtual HRESULT SetDocument(CATDocument* iDoc);
  virtual CATIOmbPlug_var GetParentContainer();
  virtual LoadState GetLoadState() const;
  virtual CATOmxIter<CATIOmbPlug> GetSubContainers() const;
  inline virtual CATBoolean IsUnderRemove() const {return FALSE;} // not impl
  inline virtual HRESULT OnDocumentStreamStart(){return E_NOTIMPL;};
  inline virtual HRESULT OnDocumentStreamEnd(CATBoolean iErrorOccurred){return E_NOTIMPL;}
  

/**
 * Sets the value of the UUID.
 * <br><b>Role</b>: Method to Valuate the iUuid that corresponds to the V4 element
 *                  which represents the container.
 * @param iUuid
 *  The iUuid that corresponds to the V4 element which represents
 *  the container.
 * @return
 *  <b>Legal values</b>:
 *  <br><tt>S_OK :</tt>   on Success
 *  <br><tt>E_FAIL:</tt>  on failure
*/
  HRESULT SetUUID( CATUuid iUuid );
/**
 * Retrieves the value of the UUID.
 * <br><b>Role</b>: Method to get the iUuid that corresponds to the V4 element
 *                  which represents the container.
 * @param oUuid
 *  The oUuid that corresponds to the V4 element which represents
 *  the container.
 * @return
 *  <b>Legal values</b>:
 *  <br><tt>S_OK :</tt>   on Success
 *  <br><tt>E_FAIL:</tt>  on failure
*/
  HRESULT GetUUID( CATUuid& oUuid ) const ;

  inline const CATUuid* _GetUuid() const {return &_Uuid;}

/**
 * Adds a son container.
 * <br><b>Role</b>: Method to adds a container in the son container list.
 * @param iNewContainer
 *  The iNewContainer that corresponds to the son container.
 * @return
 *  <b>Legal values</b>:
 *  <br><tt>S_OK :</tt>   on Success
 *  <br><tt>E_FAIL:</tt>  on failure
*/
  HRESULT AddContainer( CATOmcContainer* iNewContainer );

  CATOmxIter<CATOmcContainer> GetAggregatedContainers() const {return _SonContainerList.Iterator();}
  CATOmcContainer* GetFather() const {return const_cast<CATOmcContainer*>(m_father.Ref());}

  //FIXME, used only by ObjectSpecsModeler
  HRESULT  GetRootContainer( CATBaseUnknown*& oRootCont ) ;

  /**
 * Init the StorageProperty
 * <br><b>Role</b>: Method to init the StorageProperty 
 * @return
 *  <b>Legal values</b>:
 *  <br><tt>S_OK :</tt>   on Success
 *  <br><tt>E_FAIL:</tt>  on failure
*/  
	HRESULT  InitStorage(  ) ;
/**
 * Init the ResetStorage
 * <br><b>Role</b>: Method to init the StorageProperty 
 * @return
 *  <b>Legal values</b>:
 *  <br><tt>S_OK :</tt>   on Success
 *  <br><tt>E_FAIL:</tt>  on failure
*/  
	void  ResetStorage(  ) ;
/**
 * Set the StorageProperty
 * <br><b>Role</b>: Method to set the StorageProperty 
 * @param iStorage
 *  The storage property corresponding to the CATOmcContainer.
 * @return
 *  <b>Legal values</b>:
 *  <br><tt>S_OK :</tt>   on Success
 *  <br><tt>E_FAIL:</tt>  on failure
*/  
	HRESULT  SetStorage( CATStorageProperty * iStorage ) ;
/**
 * Gets the StorageProperty
 * <br><b>Role</b>: Method to set the StorageProperty 
 * @param oStorage
 *  The storage property corresponding to the CATOmcContainer.
 * @return
 *  <b>Legal values</b>:
 *  <br><tt>S_OK :</tt>   on Success
 *  <br><tt>E_FAIL:</tt>  on failure
*/  
	HRESULT  GetStorage( CATStorageProperty * &oStorage ) ;

/**
 * Internal services for UUID management.
 * <br><b>Role</b>: Methods to manage a static table of CATOmcContainer 
 *									and corresponding UUID.
*/ 	
	static void                   UUID_Cont_dump() ;

	static CATOmxVector<CATIOmbPlug> UUID_Cont_locate(const CATUuid& iName,CATBoolean onlyOne=FALSE) ;

  void Remove();

protected:
	void                          UUID_Cont_recovery( CATUuid iName ) ;
	void                          UUID_Cont_delete() ;

private:
  
  CATOmcContainer( const CATOmcContainer& );  
  CATOmcContainer& operator=( const CATOmcContainer& ); 


  unsigned char                 _withUUID     : 1;				// determine si porteur d'UUID

/**
 *	Each CATOmcContainer has an unique identifiant which is the Uuid. 
 *	This description is registered in the DATA of the corresponding V4Structure, 
 *  when it exists.
*/ 
	CATUuid _Uuid ;
/**
 *	The use of a pointer is better as the "Leaf" containers do not have any son. 
 *  Their List will then be set to NULL. 
*/ 
  CATOmxVector<CATOmcContainer> _SonContainerList;

  CATOmxSR<CATOmcContainer> m_father;  

  CATDocument* m_document;
/**
 *  Archi of CATContainerStgExt
 */
  CATOmxSR<CATStorageProperty> _StorageProperty;

} ;   
#endif


