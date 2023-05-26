/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2007  
//-----------------------------------------------------------------------------
// class CATContainerAdhesion :
//-----------------------------------------------------------------------------
// Usage Notes:
//
// To delete after the V5 container migration
//-----------------------------------------------------------------------------
/**
* @level Private 
* @usage U1
*/
#ifndef CATContainerAdhesion_h
#define CATContainerAdhesion_h

#ifndef TypeSDM
#define TypeSDM 14000
#endif

#include "CATOmcBase.h"
//#include "CATElementAdhesion.h"
#include "CATIContainer.h"
#include "CATIFactoryOfContainers.h"
#include "CATListOfCATUnicodeString.h"
#include "LifeCycleObject.h"
#include "booleanDef.h"
#include "CATStgAPI.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATExtensionAdapter.h"
#include "CATIBindParameters.h"
#include "sequence_octet.h"
#include "CATUuid.h"

class CATStreamArea ;
class CATUuid;
class CATIUuidTable;
class CATIComponent_var;
class CATSysSimpleHashTable;
class CATOmbExternalLinksComputingCache;

class ExportedByCATOmcBase CATContainerAdhesion : public  CATExtensionAdapter
{
public :
  CATDeclareClass ;

  //
  // CATIFactoryOfContainers
  //
  virtual CATBaseUnknown* CreateContainer (const CATIdent containerType,
    const CATIdent interfaceID, const CATIdent containerSuperType="") ;
  //
  // CATIContainer
  //
  virtual SEQUENCE(CATBaseUnknown_ptr) ListMembers (const CATIdent interfaceID) ;

  // Methode de scan intra DITTOS
  HRESULT ScanPenetrantInDitto(CATBaseUnknown* get_plug,SEQUENCE(CATBaseUnknown_ptr)& s, 
    int& maxSize, int& n,  const CATIdent interfaceID,CATListOfInt& PileDitto);

  virtual CATLONG32                             ListMembersHere (const CATIdent interfaceID,
    SEQUENCE(CATBaseUnknown_ptr)& list);

  //
  // CATIStream
  //
  virtual HRESULT Stream(CATStreamArea*& oStreamArea);
  virtual HRESULT UnStream(CATStreamArea* iWhere);

  CATContainerAdhesion() ;
  virtual ~CATContainerAdhesion () ;  


  //
  // CATIUuid
  //
  virtual const CATUuid* GetUuid ();
  virtual HRESULT RegenerateUuid () ;
  virtual HRESULT SetUuid (CATUuid* newUuid) ;

  //
  // CATIUUIDManager
  //
  virtual HRESULT RegenerateAndPublishUuids(CATIUuidTable* uuidTable);
  virtual HRESULT ChangeLinks(CATIUuidTable* uuidTable);
  virtual HRESULT ReplaceUuids(CATIUuidTable* uuidTable);
  virtual CATBaseUnknown* FindObject( const CATUuid*, int recurs) const;

  //FIXME, to remove but requires inheriting classes recompilation
  virtual HRESULT GetStoredFlags ( CATListOfCATUnicodeString& oStoredFlags );

  //
  // LifeCycleObject
  //
  void remove(int context) ;

private:
  CATContainerAdhesion (const CATContainerAdhesion& from);
  CATContainerAdhesion& operator= (const CATContainerAdhesion& from);

protected:
  // DATA
  CATUuid m_uuid;

  HRESULT ChangeComponentState(	ComponentState iFromState,ComponentState iToState,const CATSysChangeComponentStateContext * iContext);
} ;   


#endif 




