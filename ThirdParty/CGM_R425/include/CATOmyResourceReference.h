/**
* @level Protected
* @usage U1
*/

#ifndef CATOmyResourceReference_h
#define CATOmyResourceReference_h

#include "CATOMY.h"

#include "CATVVSUrl.h"
#include "CATUnicodeString.h"
#include "CATOmxCollecManager.h"
#include "CATOmxArray.h"
#include "CATWOmxBinaryStream.h"
#include "CATOmxOSet.h"

#define URL_ID_SIZE      32
struct ExportedByCATOMY CATOmyStreamId
{  
  unsigned char _ID[URL_ID_SIZE]; 
  CATOmyStreamId                       ()                                  {memset(_ID,0,URL_ID_SIZE);}
  inline CATBoolean operator==         (const CATOmyStreamId & iId) const  {return 0==memcmp(iId._ID,_ID,URL_ID_SIZE);}
  inline CATBoolean operator!=         (const CATOmyStreamId & iId) const  {return 0!=memcmp(iId._ID,_ID,URL_ID_SIZE);}
  CATWOmxBinaryStream & WriteInStream  (CATWOmxBinaryStream &iSW) const    {return iSW.WriteBytes((const void*)_ID,sizeof(_ID));}
  CATWOmxBinaryStream & ReadFromStream (CATWOmxBinaryStream &iSW)          {return iSW.ReadBytes((void*)_ID,sizeof(_ID));}
  CATUnicodeString      DumpStreamId   () const;  
};

template <> CATOmxCollecManager & CATOmxDefaultCollecManager <CATOmyStreamId>::manager();  
template <> CATOmxCollecManager & CATOmxDefaultCollecManager <CATOmxArray<CATOmyStreamId> >::manager () ;
template <> CATOmxCollecManager & CATOmxDefaultCollecManager <CATOmxOSet<CATOmyStreamId> >::manager () ;

class ExportedByCATOMY CATOmyResourceReference
{  
  public:
    
    CATOmyResourceReference(const CATOmyResourceReference& iToCopy);
    CATOmyResourceReference(const CATVVSUrl& iSrcUrl,int iWaterMarkstamp,const CATUnicodeString& iLateType);      
    CATOmyResourceReference()                                          {}
    virtual ~CATOmyResourceReference()                                 {}        
        
    const CATBoolean IsSet() const                                     {return _ContextUrl.IsSet();}
    
    CATOmyResourceReference& operator=(const CATOmyResourceReference& iRght);
    inline int operator==(const CATOmyResourceReference& iRR) const    {return (_ContextUrl==iRR._ContextUrl && _WMStamp==iRR._WMStamp && _LateType==iRR._LateType) ? (1) : (0); }
    inline int operator!=(const CATOmyResourceReference& iRR) const    {return !this->operator==(iRR);}                                                    
    
    const CATOmyStreamId &   GetStreamId() const;
    const CATVVSUrl&         GetVVSUrl()   const                       {return _ContextUrl;} 
    const int                GetWMStamp()  const                       {return _WMStamp;} 
    const CATUnicodeString&  GetLateType() const                       {return _LateType;}
    
    CATUnicodeString         Dump(CATBoolean iWithSha=FALSE) const;
    
  private:
      
    void _SetStreamId(CATOmyStreamId & iComputedStreamId);
    
    CATVVSUrl        _ContextUrl;
    int              _WMStamp;
    CATUnicodeString _LateType; 
    CATOmyStreamId   _AssocStreamId;
    CATBoolean       _StreamIdComputed;
};

template <> CATOmxCollecManager & CATOmxDefaultCollecManager <CATOmyResourceReference>::manager();  

#endif
