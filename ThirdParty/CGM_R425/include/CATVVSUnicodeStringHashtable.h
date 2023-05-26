/**
 * @level Private
 * @usage U1
 */
// COPYRIGHT DASSAULT SYSTEMES 2003

#ifndef CATVVSUnicodeStringHashTable_H_
#define CATVVSUnicodeStringHashTable_H_

#include "VVSUtils.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATOmxOHMap.h"
#include "CATIAV5Level.h"
class CATBaseUnknown;

class ExportedByVVSUtils CATVVSUnicodeStringHashtable
{
public :

  CATVVSUnicodeStringHashtable(int iSizeEstimate=0);
  ~CATVVSUnicodeStringHashtable()  {}
  /**
   * @deprecated
   */
  CATVVSUnicodeStringHashtable(const CATUnicodeString& name,int  SizeEstimate); // DEPRECATED


  /** 
  * Insert a CATUnicodeString in the hash table indexed by the given key.
  * @param ikey [in]
  *   The index of the object to insert.
  * @param iobj [in]
  *   The CATUnicodestring to insert.
  * @return
  *   <UL>
  *     <LI><code>S_OK</code> The object was successfully inserted.</LI>
  *     <LI><code>S_FALSE</code> There is already an entry indexed by the given key. The object is not inserted.</LI>
  *     <LI><code>E_FAIL</code> An error occured during the insertion.</LI>
  *   </UL>
  */
  HRESULT PutString(const CATUnicodeString& key,const CATUnicodeString& obj);

  /** 
  * Get the CATUnicodeString indexed by the given key.
  * @param ikey [in]
  *   The index of the object.
  * @param obj [out]
  *   The string stored in the hastable.
  * @return
  *   <UL>
  *     <LI><code>S_OK</code> The entry was found.</LI>
  *     <LI><code>S_FALSE</code> There is no enty indexed by the given key.</LI>
  *   </UL>
  */
  HRESULT GetString(const CATUnicodeString& key,CATUnicodeString& obj) const;

 /** 
  * Insert an object (CATBaseUnknown) in the hash table indexed by the given key.
  * @param ikey [in]
  *   The index of the object to insert.
  * @param iobj [in]
  *   The object (CATBaseUnknown) to insert. This object is Addreffed in the hash table.
  * @return
  *   <UL>
  *     <LI><code>S_OK</code> The object was successfully inserted.</LI>
  *     <LI><code>S_FALSE</code> There is already an entry indexed by the given key. The object is not inserted.</LI>
  *     <LI><code>E_FAIL</code> An error occured during the insertion.</LI>
  *   </UL>
  */
  HRESULT PutIUnknown(const CATUnicodeString& key,CATBaseUnknown* obj) ;

  /** 
  * Get the object (CATBaseUnknown) indexed by the given key.
  * @param ikey [in]
  *   The index of the object.
  * @param obj [out]
  *   The object (CATBaseUnknown) stored in the hastable. This object must be released.
  * @return
  *   <UL>
  *     <LI><code>S_OK</code> The entry was found.</LI>
  *     <LI><code>S_FALSE</code> There is no enty indexed by the given key.</LI>
  *   </UL>
  */
  HRESULT GetIUnknown(const CATUnicodeString& key,CATBaseUnknown*& obj) const;
  
  /** 
  * Checks that an item identified by the given key is in the hash table.
  * @param ikey [in]
  *   The index of the entry.
  *
  * @return
  *   <UL>
  *     <LI><code>TRUE</code> The entry was found.</LI>
  *     <LI><code>FALSE</code> The entry was not found.</LI>
  *   </UL>
  */
  CATBoolean ContainsKey(const CATUnicodeString& key) const;

  /** 
  * Removes the item indexed by a given key.
  * <br><b>Role</b>: Removes an entry in the hash table. Be careful, if the object indexed by the key is a CATBaseUnknown,
  * it is simply released
  *
  * @param ikey [in]
  *   The index of the entry.
  *
  * @return
  *   <UL>
  *     <LI><code>S_OK</code> The entry was identified, and successfully removed.</LI>
  *     <LI><code>S_FALSE</code> The entry was not found.</LI>
  *   </UL>
  */
  HRESULT RemoveKey(const CATUnicodeString& key);

  /** 
    * Removes all entries of the hash table
    */
  void Clear();

  /** 
    * Prints all contents of the Hash table.
    */
  void DumpEntries() const ;

  /** 
  * Lists all indexes of the table.
  * @param oValues [out]
  *   List of all the indexes.
  */
  void Keys(CATListOfCATUnicodeString& oValues) const ;
  
private :

  CATOmxOHMap<CATUnicodeString,CATUnicodeString>                                                                  _implUnicodeStringHash;
  CATOmxOHMap<CATUnicodeString,CATBaseUnknown*,CATOmxDefaultCollecManager<CATUnicodeString>::manager,com_manager> _implIUnknownHash;
  
} ;
#endif


