/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================

#ifndef CATDocId_H
#define CATDocId_H

/**
* @level Private
* @usage U1
*/

#include "AC0XXLNK.h"
#include "CATIDocId.h"
#include "CATUnicodeString.h"
class CATIDocEnvironment;
class CATComponentId;

/**
* Class to define the document's identifier in a specific environment.
* @see CATIDocId, CATIDocEnvironment
*/
class ExportedByAC0XXLNK CATDocId : public CATIDocId
{
public:

  CATDeclareClass;

  /** @nodoc */
  CATDocId ();

  /** 
  * Constructs a new identifier.
  * @param iEnvironment 
  * The environment
  * @param iIdentifier 
  * The identifier of the document in this environment
  * @param iType 
  * Type of the document ( CATPart, CATProduct ...)
  */
  CATDocId (CATIDocEnvironment * iEnvironment, const CATUnicodeString& iIdentifier, const CATUnicodeString& iType="");

  /** @nodoc */
  CATDocId (const CATDocId& iDocId);

  /** @nodoc */
  CATDocId (const CATIDocId& iDocId);


  virtual ~CATDocId() ;

  //------------------------------
  // CATIDocId bindings
  //------------------------------
  /** @nodoc */
  virtual HRESULT GetDocEnvironment(CATIDocEnvironment ** oEnvironment);
  /** @nodoc */
  virtual HRESULT GetIdentifier(CATUnicodeString& oIdentifier);
  /** @nodoc */
  virtual HRESULT GetType(CATUnicodeString& oType);

  /** @nodoc */
  virtual HRESULT SetIdentifier(const CATUnicodeString& iIdentifier);

  //---------------------------------------------------------
  // DocId++ Drop 16 : easier PLM Integration associativity
  //---------------------------------------------------------

  /** @nodoc */
  virtual HRESULT SetHandle(const CATComponentId& iHandle);

  /** @nodoc */
  virtual HRESULT GetHandle(CATComponentId& oHandle);

  //MLK tracker integration
  virtual ULONG __stdcall AddRef();
  virtual ULONG __stdcall Release();

protected :
  CATIDocEnvironment * _Environment;
  CATUnicodeString     _Identifier;
  CATUnicodeString     _Type;

};

#endif
