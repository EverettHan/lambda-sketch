/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
/**
*  CATStorageProperty :
*      Property Of Storage
*/
//================================================================
//  Usage notes :
//
//  
//	May.98	lbf/slg
//================================================================
#ifndef CATStorageProperty_H
#define CATStorageProperty_H

/**
* @level Private
* @usage U1
*/

#include "AC0XXLNK.h"
#include "CATBaseClassProperty.h"
//
#include "CATIStorageProperty.h"
#include "CATUnicodeString.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"
#include "CATUuid.h"
#include "CATOmxPortability.h"
// Pour le path (hag)
#include "sequence_octet.h"
#include "CATOmxSR.h"

class CATPropertySet;
class CATStorage ;
class CATStream;
class CATOctetArray;
class CATIPointedSymbols_var;
class CATIProperty;
class CATIContainer_var;
class CATDocument;
class CATDocumentProperty;


class ExportedByAC0XXLNK CATStorageProperty : public CATBaseClassProperty
{
  friend class CATStorageData;
  friend class CATPropertySetExt;
  friend class CATStgPropertyExt;

public :

  CATDeclareClass;

  //
  //	'TORS
  //	-----

  CATStorageProperty ( const SEQUENCE(octet)* Name = NULL);

  virtual ~CATStorageProperty ();
  virtual void Dump ();

  virtual ULONG __stdcall AddRef();
  virtual ULONG __stdcall Release();

  /**
  *  CATIStorageProperty interface
  */     
  virtual CATStorageType GetStorageType( );
  virtual CATUnicodeString GetObjectType( );
  virtual CATUnicodeString GetObjectUserId ();
  virtual CATUuid	     GetObjectUuid ();
  // Valid For Document Only
  virtual HRESULT GetRootContainerUuid( CATUuid& RootContUUid); 
  virtual HRESULT GetDocumentProperty( CATIPointedSymbols_var& DocProperty);

  // Additional Property Management
  HRESULT CreatePropertySet ( const CATUnicodeString& Name, CATIProperty*& oProperty);
  HRESULT GetPropertySet ( const CATUnicodeString& Name, CATIProperty*& oProperty);
  HRESULT RemovePropertySet ( const CATUnicodeString& Name);
  HRESULT ListPropertySets ( CATListOfCATUnicodeString& Names, CATListValCATBaseUnknown_var& Properties);


  /**
  *  CATIPersistStorage interface
  */     
  // Main Services
  virtual HRESULT Load (CATStorage* pStg) ;
  virtual HRESULT Save (CATStorage* pStgSave, CATULONG32  fSameAsLoad, DWORD iRootStorageMode) ;


  CATStorageProperty* Duplicate( ); 

  /**
  *  LifeCycleObject interface
  */     
  void remove(int context=0); 

  /*
  *	Basic Properties Creation 
  */

  // document: (CATSummaryInformation + CATPreview)
  void CreateDocBasicProperties();
  // applicative containers
  static HRESULT CreateContBasicProperties (const CATIStorageProperty_var& StorageProperty, const CATIContainer_var& Cont);

  // Valuation of basic properties
  void SetStorageType ( const CATStorageType& StgType);
  void SetObjectType ( const CATUnicodeString& Type);
  void SetObjectUserId ( const CATUnicodeString& Type);
  void SetObjectUuid ( const CATUuid& Uuid);
  HRESULT  SetRootContainerUuid( const CATUuid& RootContUUid); 

  // Valuation of associated data
  void SetAssociatedData ( CATDocument * AssociatedData);

  void SetDocumentProperty( CATDocumentProperty *DocProp);
  void SetCurrentName(const SEQUENCE(octet) * Name);
protected:

  // Property Persistence
  HRESULT LoadProperties ( CATStorage* Stg);
  HRESULT SaveProperties ( CATStorage* Stg);
  int       GetStorageTypeInInt () const;
  void      SetStorageTypeAsInt(int va);

private:

  HRESULT InitPropertySet();

  //
  // DATA
  // -----
  CATStorageType        _StorageType:8;
  //
  unsigned short _IsRemoved:8;
  unsigned short _IsLoaded:8;
  char		  my_StorageTypeInInt;

  CATUnicodeString      _Type;
  CATUnicodeString      _UserId;

  CATUuid	  _Uuid;
  // For Document Only
  CATUuid*	  _RootContainerUuid;
  //
  CATOmxSR<CATDocumentProperty>  	  _DocProperty; // implementation of the document link property (cf link manager)
  // properties
  CATPropertySet* _pPropertySet;
  // Associated Data (In session only)
  CATDocument*	_AssociatedData; // CATDocument for instance    
#if OMX_CODE_PHASE == 1
  SEQUENCE(octet) *_CurrentName; 
#endif
private:
  CATStorageProperty ( const CATStorageProperty& StorageProperty);
  CATStorageProperty& operator =	( const CATStorageProperty& );
  CATDocumentProperty *GetDocumentProperty();
};

#endif
