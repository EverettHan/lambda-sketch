/**
 * @level Protected
 * @usage U1
 */

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES  
//=============================================================================

#ifndef CATIANamingContext_H
#define CATIANamingContext_H

#include "CATOmcBase.h"
#include "CATINamingContextAdapter.h"
#include "CATAssert.h"

class CATManageIndexGN ;
class CATIAOmcAbstractDriver;
class ExportedByCATOmcBase CATIANamingContext : public CATINamingContextAdapter
{
  public :
    CATDeclareClass ;

    CATIANamingContext() ;
    virtual ~CATIANamingContext() ;
	friend class CATIAOmcDriver; //pour acces à la donnée private _Index 
	

    virtual CATBaseUnknown*                 GetObject_B( const SEQUENCE(octet)& name,
                                                        CATIBindParameters*    params,
                                                        const CATIdent         interfaceID ) ;

    virtual HRESULT                         GetObject_B( const SEQUENCE(octet)& name,
                                                         CATIBindParameters*    params,
                                                         const CATIdent         interfaceID,
                                                         CATBaseUnknown*&       oObject ) ;

    virtual CATBaseUnknown*                 GetObject( const char*         printableName,
                                                      CATIBindParameters* params,
                                                      const CATIdent      interfaceID ) ;

    virtual SEQUENCE(CATBaseUnknown_ptr)    ListNamedObjects( const CATIdent interfaceID ) ;

    virtual CATLONG32                       ListNamedObjectsHere( const CATIdent                interfaceID,
                                                                  SEQUENCE(CATBaseUnknown_ptr)& list ) ;

    virtual SEQUENCE(octet)                 GetRelativeName_B( const CATBaseUnknown_var& object,
                                                                const CATUnicodeString&   context ) ;

    virtual boolean                         CreateIndex() ;
    virtual boolean                         UnsetIndex() ;

  private :
    CATManageIndexGN*                       _Index ;
	short                              _IsV4;
   CATIAOmcAbstractDriver &GetDriver();
} ;

#endif
