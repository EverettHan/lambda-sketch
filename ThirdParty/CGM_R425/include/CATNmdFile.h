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
#ifndef __CATNMDFILE
#define __CATNMDFILE

#include "JS0NMDCOMP.h"
#include "CATWTypes.h"
#include "CATIStorage.h"
#include "CATIFStream.h"
#include "CATIEnumSTATSTG.h"


class CATNmdStream;
class CATNmdStgData;
class CATNmdStrData;
class CATILockBytes;


class ExportedByCATSysCompFile CATNmdStorage 
{
public:
  //------------------------------------------------------
  //  Mode =  STGM_READ -  STGM_WRITE  -   STGM_READWRITE
  //------------------------------------------------------

  //--------------------------------------
  // Opening/Creation of a Compound File
  //-------------------------------------
  static HRESULT OpenRootStg( const WCHAR FAR* iPath, DWORD Open_Mode, 
			      CATNmdStorage FAR* &Root, int iCopy=1);
  static HRESULT OpenRootStg( CATILockBytes FAR* iPath, DWORD Open_Mode, 
			      CATNmdStorage FAR* &Root, int iCopy=1);
  HRESULT  Close(int iFlag=0);
  
  //-----------------------------------------------
  // Opening/Creation of a Stream inside a Storage
  //-----------------------------------------------
  HRESULT OpenStream (const WCHAR FAR* iName, DWORD iMode, CATNmdStream FAR* &oStream);
  //-----------------------------------------------------
  // Opening/Creation of a SubStorage inside a Storage
  //----------------------------------------------------
  HRESULT OpenStorage ( const WCHAR FAR* iName, DWORD iMode, 
			CATNmdStorage FAR* &oStorage);

  HRESULT DestroyElement (const WCHAR FAR* iName) ;
  HRESULT RenameElement (const WCHAR FAR* iOldName, const WCHAR FAR* iNewName); 
  
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
  static HRESULT OpenRootStg( CATIStorage FAR*iptr, CATNmdStorage FAR* &Root);

  //---------------------------------------
  // Copyto
  //---------------------------------------
  HRESULT CopyTo ( DWORD iCiidExclude, const IID FAR* iRgiidExclude,
		   SNB iSnbExclude, CATNmdStorage FAR*iStgDest);
  


private:
  CATNmdStorage ();
  virtual ~CATNmdStorage ();
  CATNmdStgData * _Dt;
  
};



class ExportedByCATSysCompFile CATNmdStream 
{
friend class CATNmdStorage;
public:
  
  HRESULT  Close();

                                                 
  HRESULT Write ( char *buffer_data, ULONG long_data, ULONG *long_ecrite);
  HRESULT  Read ( char *buffer_data, ULONG long_data, ULONG *long_lue);
  HRESULT Stat( STATSTG FAR* Stat,  DWORD iStatFlag =0) ;

private:
  CATNmdStream();
  ~CATNmdStream();
  CATNmdStrData *_Dt;
};


#endif
