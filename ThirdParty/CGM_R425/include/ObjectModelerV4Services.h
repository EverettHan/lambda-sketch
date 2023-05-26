/**
 * @level Protected
 * @usage U1
 */
/* -*-c++-*- */

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1997  
//-----------------------------------------------------------------------------
// ObjectModelerCATIA Global Functions
// 
//-----------------------------------------------------------------------------
// Usage Notes:
//
//
// Global functions for general CATElement and CATContainer services
//-----------------------------------------------------------------------------
// Creation by JDY - April 2009 Operation Architecture
// OGM le 07/04/2003 :
//   En vue du passage en 64 bits, je mets en place les fonctions necessaires
//   pour eviter le passage de int à CATIAModel*
//-----------------------------------------------------------------------------

#ifndef CATIA_ObjectModelerServices_h
#define CATIA_ObjectModelerServices_h

#include "AC0CATPL.h"
#include "CATBooleanDef.h"
//#include "CATIA_ObjectModelerServices.h"   

class CATIAModel ;
class CATIAEntity ;
class CATDocument;
 

//
//  Those methods are used to get an interface from a V4 element
//  A V4 element can be specified by 3 ways :
//   jele / mnum : MUST DISAPPEAR !!
//   jele / CATIAModel*
//   CATIAEntity*

ExportedByAC0CATPL CATBaseUnknown*      CATIABindInterface( int         iJele,
                                                            CATClassId  iInterfaceID,
                                                            int   iMnum=1 ) ;

ExportedByAC0CATPL CATBaseUnknown*      CATIABindInterface( int         iJele,
                                                            CATClassId  iInterfaceID,
                                                            CATIAModel* iModel ) ;

ExportedByAC0CATPL CATBaseUnknown*      CATIABindInterface( CATIAEntity* iEntity,
                                                            CATClassId   iInterfaceID ) ;

// The same with GUID instead of CATClassId
ExportedByAC0CATPL CATBaseUnknown*      CATIABindInterface( int         iJele,
                                                            const GUID& iid,
                                                            int   iMnum=1 ) ;

ExportedByAC0CATPL CATBaseUnknown*      CATIABindInterface( int         iJele,
                                                            const GUID& iid,
                                                            CATIAModel* iModel ) ;

ExportedByAC0CATPL CATBaseUnknown*      CATIABindInterface( CATIAEntity* iEntity,
                                                            const GUID&  iid ) ;


ExportedByAC0CATPL int                  GetCATIAMnum( const CATBaseUnknown* iElement ) ;
ExportedByAC0CATPL CATIAModel*          GetCATIAModel( const CATBaseUnknown* iElement ) ;

ExportedByAC0CATPL int                  GetCATIAJele( const CATBaseUnknown* iElement ) ;

ExportedByAC0CATPL HRESULT              GetCATIAModel( const CATDocument* iDocument,
                                                       CATIAModel*&       oCATIAModel ) ;

// WARNING
// The following methods are to load old models (backward compatibility)
// CATIALoadRootContainer loads a model as a RootContainer
// if the model is an old V4 one, its WS Master's CATIContainer is returned
// if not, the model's CATIContainer is returned

ExportedByAC0CATPL CATBaseUnknown*   CATIALoadRootContainer( CATDocument* doc,
                                                             const char*  storagePrintableName, 
                                                             boolean      readOnly,
                                                             CATClassId   interfaceID ) ;


enum SearchPolicy
{
  DoNotCkeckFileExistence,
  DoNotUseSessionParameters,
  CheckLastSessionParameters,
  CheckFirstSessionParameters
} ;

ExportedByAC0CATPL int               CATIAGetModelOrigin( const char*  printableName,
                                                          char*        org,
                                                          SearchPolicy priority=DoNotUseSessionParameters ) ;

ExportedByAC0CATPL void              CATIASearchMemberInFileLinkPath( const CATUnicodeString& member,
                                                                      CATUnicodeString&       theDirectoryPath ) ;

ExportedByAC0CATPL void              substitute_special_characters( const char* oldMember,
                                                                    char*       newMember ) ;


// ----------------------------------------------------------------------------
// Compound Document: en attendant que la methode soit implementee sur le document
class CATIContainer_var;

ExportedByAC0CATPL CATIContainer_var FindCompoundContainer( CATDocument* doc ) ;

//QBE 21/11/07 Methode deplacee dans ObjectModelerContBase
//ExportedByAC0CATPL HRESULT           CATResetContainer( const CATIContainer_var& iContainer ) ;

#endif
