/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2006
//=============================================================================


#ifndef CATVVSStreamSize_HH
#define CATVVSStreamSize_HH

#include "VVSCoreStructure.h"
#include "CATBaseUnknown.h"
#include "CATVVSUrl.h"

/**
 * This object is couple of Url and the size of the stream pointed by this URL.
 * This object can be inserted in a CATSysSimpleHashTable. The key is determined by the Url.
 */
class ExportedByVVSCoreStructure CATVVSStreamSize: public CATBaseUnknown
{
public:
  
  // Constructs this object with a size in Kbyte  
  CATVVSStreamSize(const CATVVSUrl& iUrl, unsigned int iNbKo);
  // Constructs this object with a size in Byte
  CATVVSStreamSize(CATLONG64 iNbByte, const CATVVSUrl& iUrl, CATBoolean iSizeIsExact);
  
  // Destructor
  ~CATVVSStreamSize();

  // Gets the Url of this object.   
  void GetUrl(CATVVSUrl& oUrl) const;

  // Gets the size in Ko of the stream pointed by the internal URL.   
  void GetSize(unsigned int& oNbKo) const;

  // Gets the size int byte of the stream pointed by the internal URL.  
  void GetSizeByte(CATLONG64& oNbBytes, CATBoolean * oIsExactSize=NULL) const;
  
  /** 
  * Computes Hash key method of this element.
  * <B>Role</B>: This method is used by a CATSysSimpleHashtable, if this object is inserted inside.
  */
  static unsigned int Hash(void * iObj);
 
  /** 
  * Comparison method to put this element in a Hashtable.
  * <B>Role</B>: This method is used by a CATSysSimpleHashtable, if this object is inserted inside.
  */
  static int Compare(void *iObj1, void *iObj2);

private:
  
  // Url of the stream
  CATVVSUrl _Url;
  // Size in Byte
  CATLONG64 _SizeInByte;
  // Indicates if the size is exact
  CATBoolean _IsExactSize;
  
  // Hash Key
  unsigned int _HashKey;  
};

#endif //CATVVSStreamSize_HH
