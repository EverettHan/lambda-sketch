#ifndef CATSysSwpZone_H
#define CATSysSwpZone_H

// COPYRIGHT DASSAULT SYSTEMES 2002
#include "CATSysSwappable.h"

//=======================================================================================================
// CATSysSwpZone is a variable sized swappable object
// it permits to create swappable zones of variable size and gives access method to this  zone
// a CATSysSwpZone must never be greater than the memory window
// a CATSysSwpZone cannot be resized
// a CATSysSwpZone is atomic in terms of swapping
//=======================================================================================================

class CATSysSwpZone_hdl;

// for Seek method 
#define CATSysSwpZoneStart     0
#define CATSysSwpZoneEnd       1
#define CATSysSwpZoneHere      2



class CATSysSwpZone : public CATSysSwappable
{
  
  private:
  CATSysSwpZone( CATSysSwapFile *iFile , int iRule,size_t iSize);
  public:
  static CATSysSwpZone_hdl *Create ( CATSysSwapFile *iFile,size_t iSize,CATSysSwpZone_hdl *iHandle=NULL,int iRules=0 );  
  void *operator new ( size_t iSize, void *iAllocType,
                      void *iAddr,int iReservedSize=0) ;
  CATSysSwpZone_hdl *GetNewHandle();                        
  // appele lors d'un swap-out
  virtual HRESULT SwappedOut( );
  // appele lors d'un swap-in
  virtual HRESULT SwappedIn();

  // Services
  public :
  HRESULT MemSet(  char iVal , size_t iSize, size_t iFrom=0);
  HRESULT MemPut(  void   *iOrigine , size_t iSize,size_t iFrom=0);
  HRESULT MemGet(  size_t iDelta, void   *iDestinat , size_t iSize);
  HRESULT Seek(  off_t iDelta , int iFrom=CATSysSwpZoneStart);
  size_t  Tell();
  size_t  GetSize();
  HRESULT RelativeSeek(  off_t iDelta);
  HRESULT RelativeMemPut(  void   *iOrigin , size_t iSize);
  HRESULT RelativeMemGet(  void   *iDestinat , size_t iSize);

  private:
  size_t  m_Size;
  char *  m_Zone;
  size_t  m_Current;

};
class CATSysSwpZone_hdl :public CATSysSwappable_hdl 
{
  friend class CATSysSwpZone;
  public:        \
  CATSysSwpZone_hdl( CATSysSwappable *i1=NULL, CATSysSwapFile *i2=NULL)  : CATSysSwappable_hdl(i1){}; 
  CATSysSwpZone_hdl * operator =(CATSysSwpZone *iSwpObj) { SetObject( (CATSysSwappable*)iSwpObj); return this; };
  CATSysSwpZone_hdl * operator =(CATSysSwpZone_hdl &iSwp_h) { SetObject( iSwp_h); return this; }; 
  CATSysSwpZone *operator ->(){ CATSysSwappable *p=  GetObject()  ;if(p)p->IsUsed(); return (CATSysSwpZone*)p;};
};
#endif
