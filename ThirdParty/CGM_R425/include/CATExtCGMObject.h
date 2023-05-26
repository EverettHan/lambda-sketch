/* -*-c++-*- */
#ifndef CATExtCGMObject_H_
#define CATExtCGMObject_H_
//============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1997  
//============================================================================
// class CATExtCGMObject : extension of CGMObjects
// providing Implementation for ObjectModelerBase adhesion
//============================================================================
// Mar. 05 _DummyUUID                                                    HCN
//============================================================================
#include "CATIACGMLevel.h"

#include "CATExtensionAdapter.h"
#include "CATCGMNewArray.h"
#include "CATIGenericNamed.h"
#include "CGMV5Interop.h"

class CATGeoFactory;
class CATGeometry;
class CATISymbolicLink;
class CATDocument;
class CATCGMObject;
class CATExtCGMGeom;
class CATUuid;
class CATICGMObject;

#include "CATCGMBOAObject.h" 
#if defined ( CATCGMBOAObject )
#include "CATICGMUnknown.h"
#endif

class ExportedByCGMV5Interop CATExtCGMObject: public CATExtensionAdapter
{
 public:
  CATExtCGMObject();
  ~CATExtCGMObject();
  CATDeclareKindOf;   // basics ObjectModelerBase
  CATCGMNewClassArrayDeclare; // Surcharge new/delete ...

  // Acces implementation
  inline CATCGMObject * GetCGMObject();

  // INTERFACE CATILinkableObject
  CATISymbolicLink*   GetSymbolicLink();
  CATBaseUnknown*     GetNamingContext (CATIdent interfaceID);
  void                GetIdentifier(SEQUENCE(octet) & identifier, boolean  & IsAnUuid);
  SEQUENCE(octet)     GetLastModificationId();
  CATDocument*        GetDocument ();
    
  // INTERFACE LifeCycleObject
  void remove(int ForCloseContext=0);

  // INTERFACE CATIGenericNamed
  void Warn(const CATIGenericNamed::CATWarning& event = CATIGenericNamed::linked );

  // ChangeComponentState
  HRESULT ChangeComponentState(	ComponentState iFromState,
                                ComponentState iToState,
                                const CATSysChangeComponentStateContext * iContext);
  

#if defined(CATIACGMR417Code_EB) 
 //-----------------------------------------------------------------------
  //  Surcharge de methodes  de CATBaseUnknown pour DEBUG
  //    AddRef, Release, QueryInterface 
  //----------------------------------------------------------------------
  virtual ULONG           __stdcall AddRef();
  virtual ULONG           __stdcall Release();  
#endif
  
  private :
  
  static void  cachebrep( CATICGMObject * iBRepCache );
  static void  criteriaDisk( CATICGMObject * iBRepCache );
  static void  IdentifierForStackTraces( const CATIGenericNamed::CATWarning TheContext,  CATICGMObject * iBRepCache );
 
 
  CATExtCGMObject *_PrevObj;
  CATExtCGMObject *_NextObj;

  CATUuid         *_DummyUUID;

  friend class CATExtCGMGeom;

  //---------------------------------------------------------------------------
  // Not Available
  //---------------------------------------------------------------------------
  CATExtCGMObject(const CATExtCGMObject& copy);
  CATExtCGMObject& operator= (const CATExtCGMObject&);
};

//============================================================================
// GetCGMObject
//============================================================================
inline CATCGMObject *  CATExtCGMObject::GetCGMObject()
{
#if defined ( CATCGMBOAObject )
  CATICGMUnknown *itfCGM = (CATICGMUnknown *)  GetImpl();
  CATCGMObject* implCGM = itfCGM ? (CATCGMObject*) itfCGM->IsCGMV5() : NULL;
#else
  CATCGMObject* implCGM = (CATCGMObject*) GetImpl();
#endif
  return implCGM;
}

#endif


