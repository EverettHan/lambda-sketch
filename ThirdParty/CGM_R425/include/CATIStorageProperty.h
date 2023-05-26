/* -*-c++-*- */
#ifndef CATIStorageProperty_h
#define CATIStorageProperty_h

/**
  * @level Private
  * @usage U3
  */

//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
/*
 *
 *  CATIStorageProperty :
 *     - interface supported by CATStorageProperty
 *     - used get a storage property
 */
//================================================================
//  Usage notes :
//
//
//		05/98		slg/lbf
//================================================================

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"
//
class CATUnicodeString;
class CATUuid;
class CATIPointedSymbols_var;
class CATIProperty;


extern ExportedByAC0XXLNK IID IID_CATIStorageProperty ;

enum CATStorageType 
{
  UndefType = -1, CATIAType = 1, DocumentType = 2, 
  AppliContType = 3, EmbeddedDocType = 4
};



class ExportedByAC0XXLNK CATIStorageProperty : public CATBaseUnknown
{
  CATDeclareInterface;

  public:
  
  /*
   * BASIC INFORMATION ACCESS
   * ------------------------
   */
   virtual
    CATStorageType GetStorageType( ) = 0;
   virtual
    CATUnicodeString GetObjectType( ) = 0;
   virtual
    CATUnicodeString GetObjectUserId () = 0;
   virtual
     CATUuid	GetObjectUuid () = 0;
    // Valid For CATDocument Only
    virtual
      HRESULT GetRootContainerUuid( CATUuid& RootContUUid) = 0;
    virtual
      HRESULT GetDocumentProperty( CATIPointedSymbols_var& DocProperty)=0;

 /*
   * PROPERTY SET MANAGEMENT
   * -----------------------
   */
   virtual
    HRESULT CreatePropertySet ( const CATUnicodeString& Name, CATIProperty*& oProperty) = 0;
   virtual
    HRESULT GetPropertySet ( const CATUnicodeString& Name, CATIProperty*& oProperty) = 0;
   virtual
    HRESULT RemovePropertySet ( const CATUnicodeString& Name) = 0;
   virtual
    HRESULT ListPropertySets ( CATListOfCATUnicodeString& Names
			    , CATListValCATBaseUnknown_var& Properties) = 0;
		
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIStorageProperty, CATBaseUnknown ) ;


#endif
