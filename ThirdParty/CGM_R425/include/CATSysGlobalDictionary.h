/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2001
//=============================================================================
//
// Class CATSysGlobalDictionary :
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// Oct 2001   Creation                                    
//=============================================================================

#ifndef CATSysGlobalDictionary_H
#define CATSysGlobalDictionary_H

#include "CO0HDICO.h"
#include "CATHashDico.h"
#include "IUnknown.h"

class ExportedByCO0HDICO CATSysGlobalDictionary
{
public:
      /** Add a (key,item) pair to the dictionary.
          @param iKey
            The name of the key to be added. If the key already exists, its value is updated.
          @param iItem
            The item associated to the key.
          @return
            S_OK if the (key,item) has been added, E_FAIL otherwise.
      */
      static HRESULT Add(const CATUnicodeString& iKey, int iItem);    
  
      /** Remove a (key,item) pair from the dictionary.
          @param iKey
            The name of the key to be removed.
          @return
            S_OK if the (key,item) has been removed, E_FAIL if the key does not exist.
      */
      static HRESULT Remove(const CATUnicodeString& iKey);    
      
      /** Check if a key exists in the dictionary.
          @param iKey
            The name of the key to be checked.
          @return
            S_OK if the key exists, E_FAIL otherwise.
      */
      static HRESULT Exists(const CATUnicodeString& iKey);    
      
      /** Get the value associated to a key.
          @param iKey
            The name of the key to be read..
          @return
            S_OK if the key exists, E_FAIL otherwise.
      */
      static HRESULT GetItem(const CATUnicodeString& iKey, int& oItem);    

      /** Constructor
      */
      CATSysGlobalDictionary();
      
      /** Destructor
      */
      ~CATSysGlobalDictionary();

private:
     /**
      * @nodoc 
      */
      static int Cleanup(int);

      CATHashDico _dico;
} ;

#endif


