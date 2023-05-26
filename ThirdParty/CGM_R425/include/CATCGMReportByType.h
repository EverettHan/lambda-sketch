#ifndef CATCGMReportByType_H
#define CATCGMReportByType_H
//------------------------------------------------------------------------------
// Outils de Validation massive a partir d'une reutilisation de Persistence
//   Progressivite dans les traitements sur une multitude de fichiers 
//   Ouverts pour des operations specialisees
//------------------------------------------------------------------------------
#include "CGMV5Interop.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATDataType.h"
#include "CATBoolean.h"
#include "CATMathInline.h" 
#include "CATCGMNoMoreMemory.h" 
#include "CATCGMStreamVersion.h" 

#include "CATBoolean.h" 
#include "CATCGMHashNames.h" 
#include "CATThrowForNullPointer.h" 
#include "CATListOfCATUnicodeString.h" 
 


typedef unsigned int CATCGMReportMask;
#define CatCGMReportNumber                    0x00000001
#define CatCGMReportDiskBytes                 0x00000002
 

class CATCGMStream;

typedef struct  
{
  CATULONG64 _NbInstances; 
  CATULONG64 _DiskBytes; 
  CATULONG64 _MemBytes; 
} FiguresForIndex;



/**
 * Representation d'un ensemble de documents
 */
class ExportedByCGMV5Interop  CATCGMReportByType 
{
public :

  /**
  * Ctor 
  */
  CATCGMReportByType(CATCGMReportMask iMask, CATCGMStreamVersion iWantingVersion );
 
  /**
  * Destructor 
  */
  ~CATCGMReportByType();

 
  /**
  * Get_StreamVersion : target version
  */
  INLINE  CATCGMStreamVersion  Get_StreamVersion() const;
 
  /**
  * Get_LastUnstreamVersion 
  */
  INLINE  CATCGMStreamVersion  Get_LastUnstreamVersion() const;


  /**
  * Set_LastUnstreamVersion 
  */
  INLINE void Set_LastUnstreamVersion(CATCGMStreamVersion iLastUnstreamVersion );

  //-----------------------------------------------------------------------------
  //  Type to Index (necessary for access/enumerate Report)
  //     GeometricObjectsCGM\ProtectedInterfaces\ObjectTypesCGM.h
  //-----------------------------------------------------------------------------

  /**
  * GetNbTypes 
  */
  INLINE  CATULONG32  GetNbTypes() const;  

  /**
  * GetType 
  */
  INLINE const char*  GetType( CATULONG32 iIndex ) const;

  /**
  * DeclareIndex 
  */
  CATULONG32  DeclareIndex( const char* iType );
 


  /**
  * Get_NbInstances 
  */
  INLINE CATULONG64   Get_NbInstances( CATULONG32 iIndex ) const;
 
  
  /**
  * Get_DiskBytes 
  */
  INLINE  CATULONG64  Get_DiskBytes( CATULONG32 iIndex ) const;
 
  /**
  * Get_MemBytes 
  */
  INLINE  CATULONG64      Get_MemBytes( CATULONG32 iIndex )  const;

  //-----------------------------------------------------------------------------
  // Fill Statistics
  //-----------------------------------------------------------------------------
 

  /**
  * Set_NbInstances 
  */
  INLINE void   Set_NbInstances( int iIndex , CATULONG64 iNbInstances );

  /**
  * Set_DiskBytes 
  */
  INLINE void   Set_DiskBytes(  int iIndex , CATULONG64 iDiskBytes );

  /**
  * Set_MemBytes 
  */
  INLINE void   Set_MemBytes( int iIndex , CATULONG64 iMemBytes );

 
  //-----------------------------------------------------------------------------
  //   Sum statistics 
  //-----------------------------------------------------------------------------

  /**
  * Sum 
  */
  void  Sum(const CATCGMReportByType & iReportByType );

  //-----------------------------------------------------------------------------
  //   Cumulate statistics 
  //-----------------------------------------------------------------------------

  /**
  * Get_CumulatedNbInstances 
  */
  CATULONG64        Get_CumulatedNbInstances();

  /**
  * Get_CumulatedDiskBytes 
  */
  CATULONG64  Get_CumulatedDiskBytes();


  /**
  * Get_CumulatedMemBytes 
  */
  CATULONG64  Get_CumulatedMemBytes();


 
  //-----------------------------------------------------------------------------
  // LastStreamBytes 
  //-----------------------------------------------------------------------------

  /**
  * Get_LastStreamBytes 
  */
  INLINE  CATULONG64  Get_LastStreamBytes();

  /**
  * Set_LastStreamBytes 
  */
  INLINE  void Set_LastStreamBytes(CATULONG64 iSize); 

  //-----------------------------------------------------------------------------
  // FileSize 
  //-----------------------------------------------------------------------------

  /**
  * Get_FileSize 
  */
  INLINE  CATULONG64  Get_FileSize();

  /**
  * Set_FileSize 
  */
  INLINE  void Set_FileSize(CATULONG64 iSize);


 //-----------------------------------------------------------------------------
  // CATCGMStream 
  //-----------------------------------------------------------------------------

  /**
  * ReadSite 
  */
  HRESULT   ReadSite(CATCGMStream & iStream);

  /**
  * WriteSite 
  */
  HRESULT   WriteSite(CATCGMStream & iStream);

private :

  
  /**
  * Compute_Cumulated 
  */
  void  Compute_Cumulated();

  CATListValCATUnicodeString   _TypeNames; 
  CATCGMHashNames            * _Types; 
  CATULONGPTR                  _TypesIndex; 

  /**
  * Private Data
  */
  CATCGMReportMask      _Mask;
  CATCGMStreamVersion   _Version;

  CATCGMStreamVersion   _LastUnstreamVersion;
 
  CATULONG32             _MaxIndex; 
  FiguresForIndex      * _Figures; 
 

  CATBoolean            _CumulatedStats;

  CATULONG64            _CumulatedNbInstances; 
  CATULONG64            _CumulatedDiskBytes;
  CATULONG64            _CumulatedMemBytes;

  CATULONG64            _LastStreamBytes;

  CATULONG64            _FileSize;
 
  //------------------------------------------------------------------------
  // Forbidden (Declared, Not Defined) : Constructor by copy  et   operator =
  //------------------------------------------------------------------------
  CATCGMReportByType(const CATCGMReportByType &iCopy);
  CATCGMReportByType& operator=(const CATCGMReportByType &iCopy);
};



/**
* GetNbTypes 
*/
INLINE  CATULONG32   CATCGMReportByType::GetNbTypes() const
{
  return (CATULONG32)_TypesIndex;
}

/**
* GetType 
*/
INLINE   const char*   CATCGMReportByType::GetType( CATULONG32 iIndex ) const
{
  if ( (iIndex < 0) || ( iIndex > (CATULONG32)_TypesIndex ) || ! _Types ) CATThrowForNullPointerReturnValue(NULL);
  if ( (iIndex+1) >  (CATULONG32)_TypeNames.Size() ) CATThrowForNullPointerReturnValue(NULL);
  CATULONGPTR DummyIndex = 0;
  const char* rc = _Types->Locate( _TypeNames[iIndex+1].ConvertToChar(),DummyIndex);
  return rc;
}



 


/**
* Set_NbInstances 
*/
INLINE void  CATCGMReportByType::Set_NbInstances( int iIndex ,  CATULONG64 iNbInstances ) 
{
  if ( (iIndex < 0) || ( iIndex > (int)_TypesIndex ) || ! _Figures ) CATThrowForNullPointer();
  _Figures[iIndex]._NbInstances = iNbInstances;
  _CumulatedStats = FALSE;

}

/**
* Set_DiskBytes 
*/
INLINE void    CATCGMReportByType::Set_DiskBytes(  int iIndex , CATULONG64 iDiskBytes ) 
{
  if ( (iIndex < 0) || ( iIndex > (int)_TypesIndex ) || ! _Figures ) CATThrowForNullPointer();
  _Figures[iIndex]._DiskBytes = iDiskBytes;
  _CumulatedStats = FALSE;
}

/**
* Set_MemBytes 
*/
INLINE void     CATCGMReportByType::Set_MemBytes( int iIndex , CATULONG64 iMemBytes ) 
{
  if ( (iIndex < 0) || ( iIndex > (int)_TypesIndex ) || ! _Figures ) CATThrowForNullPointer();
  _Figures[iIndex]._MemBytes = iMemBytes;
  _CumulatedStats = FALSE;
}


/**
* Get_StreamVersion 
*/
INLINE  CATCGMStreamVersion   CATCGMReportByType::Get_StreamVersion() const
{
  return _Version;
}

/**
* Get_LastUnstreamVersion 
*/
INLINE  CATCGMStreamVersion   CATCGMReportByType::Get_LastUnstreamVersion() const
{
  return _LastUnstreamVersion;
}

/**
* Set_LastUnstreamVersion 
*/
INLINE void CATCGMReportByType::Set_LastUnstreamVersion(CATCGMStreamVersion iLastUnstreamVersion ) 
{
  _LastUnstreamVersion = iLastUnstreamVersion ;
}

/**
* Get_NbInstances 
*/
INLINE CATULONG64  CATCGMReportByType::Get_NbInstances( CATULONG32 iIndex ) const
{
  if ( (iIndex < 0) || ( iIndex > (CATULONG32)_TypesIndex ) || ! _Figures ) CATThrowForNullPointerReturnValue(0);
  return _Figures[iIndex]._NbInstances;
}

/**
* Get_DiskBytes 
*/
INLINE CATULONG64  CATCGMReportByType::Get_DiskBytes( CATULONG32 iIndex ) const
{
  if ( (iIndex < 0) || ( iIndex > (CATULONG32)_TypesIndex ) || ! _Figures ) CATThrowForNullPointerReturnValue(0);
  return _Figures[iIndex]._DiskBytes;
}

/**
* Get_MemBytes 
*/
INLINE  CATULONG64  CATCGMReportByType::Get_MemBytes( CATULONG32 iIndex )  const 
{
  if ( (iIndex < 0) || ( iIndex > (CATULONG32)_TypesIndex ) || ! _Figures ) CATThrowForNullPointerReturnValue(0);
  return _Figures[iIndex]._MemBytes;
}

/**
* Get_LastStreamBytes 
*/
INLINE  CATULONG64    CATCGMReportByType::Get_LastStreamBytes()
{
  return  _LastStreamBytes;
}

/**
* Get_LastStreamBytes 
*/
INLINE  void   CATCGMReportByType::Set_LastStreamBytes(CATULONG64 iSize)
{
  _LastStreamBytes = iSize;
}

   
/**
* Get_FileSize 
*/
INLINE  CATULONG64    CATCGMReportByType::Get_FileSize()
{
  return  _FileSize;
}

/**
* Set_FileSize 
*/
INLINE  void   CATCGMReportByType::Set_FileSize(CATULONG64 iSize)
{
  _FileSize = iSize;
}

 


#endif
