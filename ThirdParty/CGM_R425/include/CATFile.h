//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 1996                                          *
//*===========================================================================*
//*                                                                           *
//*  CATFile                                                                  *
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation mai 97                                         adt              *
//*===========================================================================*
//*	      avril 99                                       adt	      *
//*===========================================================================*
#ifndef __CATFILE
#define __CATFILE
#include "CATDataType.h"
#include "JS0COMP.h"
#include "CATWTypes.h"
#include "CATIStorage.h"
#include "CATIFStream.h"
#include "CATIEnumSTATSTG.h"


#define CATSTRDIR 1
#define CATSTRBUF 2

class CATStream;
class CATStgData;
class CATStrData;
class CATILockBytes;
class CATILockBytes2;
class CATUnicodeString;


class ExportedByJS0COMP CATStorage 
{
public:
  //------------------------------------------------------
  //  Mode =  STGM_READ -  STGM_WRITE  -   STGM_READWRITE
  //------------------------------------------------------

  //--------------------------------------
  // Opening/Creation of a Compound File
  //-------------------------------------
  static HRESULT OpenRootStg( CATILockBytes FAR* iPath, DWORD Open_Mode, 
			      CATStorage FAR* &Root, int iCopy=1);

  static HRESULT OpenRootStg( CATILockBytes2 FAR* iPath, DWORD Open_Mode, 
			      CATStorage FAR* &Root, int iCopy=1);
  static HRESULT OpenRootStg( const CATUnicodeString & iPath, DWORD Open_Mode, CATStorage FAR* &Root, int iCopy=1);
  static HRESULT OpenRootStg( const CATUC2Bytes FAR* iPath, DWORD Open_Mode, 
			      CATStorage FAR* &Root, int iCopy=1);
#if defined(_WINDOWS_SOURCE)
  static HRESULT OpenRootStg( const WCHAR FAR* iPath, DWORD Open_Mode, 
			      CATStorage FAR* &Root, int iCopy=1);
#endif
  
  HRESULT  Close(int iFlag=0);
  
  //-----------------------------------------------
  // Opening/Creation of a Stream inside a Storage
  //-----------------------------------------------
  HRESULT OpenStream (const CATUnicodeString & iName, DWORD iMode, CATStream FAR* &oStream);
  HRESULT OpenStream (const CATUC2Bytes FAR* iName,   DWORD iMode, CATStream FAR* &oStream);
  //-----------------------------------------------------
  // Opening/Creation of a SubStorage inside a Storage
  //----------------------------------------------------
  HRESULT OpenStorage ( const CATUnicodeString & iName, DWORD iMode, CATStorage FAR* &oStorage);
  HRESULT OpenStorage ( const CATUC2Bytes FAR* iName,   DWORD iMode, CATStorage FAR* &oStorage);

  HRESULT DestroyElement (const CATUnicodeString & iName);
  HRESULT DestroyElement (const CATUC2Bytes FAR* iName);
  HRESULT RenameElement (const CATUnicodeString & iOldName, const CATUnicodeString & iNewName);
  HRESULT RenameElement (const CATUC2Bytes FAR* iOldName, const CATUC2Bytes FAR* iNewName);
#if defined(_WINDOWS_SOURCE)
  HRESULT OpenStream (const WCHAR FAR* iName, DWORD iMode, CATStream FAR* &oStream);
  HRESULT OpenStorage ( const WCHAR FAR* iName, DWORD iMode, CATStorage FAR* &oStorage);
  HRESULT DestroyElement (const WCHAR FAR* iName) ;
  HRESULT RenameElement (const WCHAR FAR* iOldName, const WCHAR FAR* iNewName);
#endif
  
  //---------------------------------------------------------
  // Validation or Cancellation  from the last modifications
  //--------------------------------------------------------
  HRESULT Commit ( );
  HRESULT Revert ( );

  //-----------------------------
  // Listing of a CATStorage
  //-----------------------------
  HRESULT EnumElements(STATSTG * oStgEnt, short iReset =0) ; 
  // Returns S_OK until the last element of the storage is reached
  // iReset=1 in order to restart the listing from the begining
  HRESULT Stat( STATSTG FAR* Stat, DWORD iStatFlag=0) ;

  
  //--------------------------------------------
  // Getting a pointer on Storages Interface
  //--------------------------------------------
  CATIStorage FAR* GetPtrToStgInf ();
  //----------------------------------------
  // RootStorage Opening on a given pointer
  //----------------------------------------
  static HRESULT OpenRootStg( CATIStorage FAR*iptr, CATStorage FAR* &Root);

  //---------------------------------------
  // Copyto
  //---------------------------------------
  HRESULT CopyTo ( DWORD iCiidExclude, const IID FAR* iRgiidExclude,
		   SNB iSnbExclude, CATStorage FAR*iStgDest);
  


private:
  CATStorage ();
  virtual ~CATStorage ();
  CATStgData * _Dt;
  
};



class ExportedByJS0COMP CATStream 
{
  friend class CATStorage;
  friend class CATStreamLockBytes;
  
public:
  
  HRESULT  Close();
                                                 
  HRESULT Write ( const char *buffer_data, ULONG long_data, 
		  ULONG *long_ecrite);
  HRESULT  Read ( char *buffer_data, ULONG long_data, 
		  ULONG *long_lue);
  
  HRESULT Seek    ( CATLONG64 iOffset, DWORD iOrigin,
		    CATULONG64* oNewPos);
  HRESULT SetSize ( CATULONG64 iNewSize );
  
  HRESULT Stat( STATSTG FAR* Stat,  DWORD iStatFlag =0) ;
  
  HRESULT SetType ( DWORD iMode, ULONG iBuffSize=0);
  HRESULT GetType ( DWORD *oMode, ULONG *oBuffSize=0);
  
private:
  CATStream();
  ~CATStream();
  CATStrData *_Dt;
};


#if defined(_WINDOWS_SOURCE)
inline HRESULT CATStorage::OpenRootStg ( const WCHAR FAR* iFilePath, DWORD iMode, CATStorage FAR* &Nouveau, int iCopie)
{
    return OpenRootStg(reinterpret_cast<const CATUC2Bytes FAR*>(iFilePath), iMode, Nouveau, iCopie);
}

inline HRESULT CATStorage::OpenStream (const WCHAR FAR* iName, DWORD iMode, CATStream FAR* &oStream)
{
    return OpenStream(reinterpret_cast<const CATUC2Bytes FAR*>(iName), iMode, oStream);
}

inline HRESULT CATStorage::OpenStorage ( const WCHAR FAR* iName, DWORD iMode, CATStorage FAR* &oStorage)
{
    return OpenStorage(reinterpret_cast<const CATUC2Bytes FAR*>(iName), iMode, oStorage);
}

inline HRESULT CATStorage::DestroyElement (const WCHAR FAR* iName)
{
    return DestroyElement(reinterpret_cast<const CATUC2Bytes FAR*>(iName));
}

inline HRESULT CATStorage::RenameElement (const WCHAR FAR* iOldName, const WCHAR FAR* iNewName)
{
    return RenameElement(reinterpret_cast<const CATUC2Bytes FAR*>(iOldName), reinterpret_cast<const CATUC2Bytes FAR*>(iNewName));
}
#endif


#endif
