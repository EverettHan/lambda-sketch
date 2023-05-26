//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1998                                          
//===========================================================================
//                                                                           
//  CATCacheManager                                                  
//                                                                           
//  Usage Notes: Class Definition                                             
//===========================================================================
//  Creation mars 1998                                 adt              
//===========================================================================
#ifndef __CATCACHEMANAGER
#define __CATCACHEMANAGER
#include "JS0MRSHL.h"
#include "CATWTypes.h"

class CATString;
class CATUnicodeString;
class CATSettingRepository;
class CATCacheSetting;
class CATFileMap;
class CATHashTabCATFileMap;
class CATIntCache;
class CATCacheManager;

extern ExportedByJS0MRSHL long  OpenToReadInCache(const char* iPath, 
						  const char* iCacheType, 
						  char *&oCachePath, 
						  unsigned int &oIsUpToDate, 
						  CATCacheManager *iObj=NULL);
  
extern ExportedByJS0MRSHL long OpenToWriteInCache(const char* iPath, 
						  const char* iCacheType, 
						  char *& oCachePath, 
						  CATCacheManager *iObj=NULL);

extern ExportedByJS0MRSHL long  OpenToReadInCache(const char* iPath, 
						  const char *iTS,
						  const char* iCacheType, 
						  char *&oCachePath, 
						  unsigned int &oIsUpToDate, 
						  CATCacheManager *iObj=NULL);
  
extern ExportedByJS0MRSHL long OpenToWriteInCache(const char* iPath, 
						  const char *iTS,
						  const char* iCacheType, 
						  char *& oCachePath, 
						  CATCacheManager *iObj=NULL);



extern ExportedByJS0MRSHL long OpenToReadInCache(CATUnicodeString* iPath, 
						 const char *iTS,
						 const char* iCacheType, 
						 CATUnicodeString **oCache, 
						 unsigned int &oIsUpToDate, 
						 CATCacheManager *iObj=0);

extern ExportedByJS0MRSHL long OpenToWriteInCache(CATUnicodeString* iPath, 
						  const char *iTS,
						  const char* iCacheType, 
						  CATUnicodeString **oCache, 
						  CATCacheManager *iObj=0);


extern ExportedByJS0MRSHL long ViewCache (const char *iCacheType, 
					  CATUnicodeString **&oReference,
					  CATUnicodeString **&oCachePath,
					  unsigned int &oNbElem,
					  CATCacheManager *iObj =NULL);

extern ExportedByJS0MRSHL long ViewCache (CATString *iDirectory, 
					  const char *iCacheType,
					  CATUnicodeString **&oReference,
					  CATUnicodeString **&oCachePath, 
					  unsigned int &oNbElem, 
					  CATCacheManager *iObj=NULL);

extern ExportedByJS0MRSHL HRESULT CATSysViewCache(CATUnicodeString *iDirectory,
						  const char *iCacheType,
						  CATUnicodeString **&oRef, 
						  CATUnicodeString **&oCache, 
						  CATUnicodeString **&oTS, 
						  unsigned int &oNbElem, 
						  CATCacheManager *iObj=NULL) ;


extern ExportedByJS0MRSHL long  SizeUsedInCache (const char* iCacheType , 
						 unsigned long &oUsed,
						 CATCacheManager *iObj=NULL);
  

extern ExportedByJS0MRSHL long  RemoveInCache ( const char* iPath, 
						const char* iCacheType, 
						CATCacheManager *iObj = NULL);

extern ExportedByJS0MRSHL HRESULT CloseInCache(const char* iPath, 
					       const char *iTS,
					       const char* iCacheType, 
					       int &oWarning );



// This class allows to define the cache management policy by derivation
// such as mapping of file names
//         coherency verification
class ExportedByJS0MRSHL CATCacheManager
{
public:
  //--------------------------------------------------------------------------
  //    Functions to retrieve the path in the cache of all files associated 
  //    to a give model
  //
  //             iPath :      path of the model file
  //             iCacheType:  type of file to get/create
  //                          ie its extension forexample "cgr"
  //             oCachePath:  path of the file to read/create in the cache
  //                          Null if nothing was found
  //             oIsUpToDate: for File Coherency
  //                          1 => Up to date
  //                          0 => The file must be regenerated
  //
  //    Return values:
  //                    0    Cache is Active
  //                   -1    Invalid Path ( unknown Object type or 
  //                         not an abolute Path given as argument)
  //                   -2    Cache not present 
  //--------------------------------------------------------------------------
  friend ExportedByJS0MRSHL long OpenToReadInCache(const char* iPath, 
						   const char* iCacheType, 
						   char *&oCachePath, 
						   unsigned int &oIsUpToDate, 
						   CATCacheManager *iObj);
  
  friend ExportedByJS0MRSHL long OpenToWriteInCache(const char* iPath, 
						    const char* iCacheType, 
						    char *& oCachePath, 
						    CATCacheManager *iObj);


  friend ExportedByJS0MRSHL long OpenToReadInCache(const char* iPath, 
						   const char *iTS,
						   const char* iCacheType, 
						   char *&oCachePath, 
						   unsigned int &oIsUpToDate, 
						   CATCacheManager *iObj);
  
  friend ExportedByJS0MRSHL long OpenToWriteInCache(const char* iPath, 
						    const char *iTS,
						    const char* iCacheType, 
						    char *& oCachePath, 
						    CATCacheManager *iObj);

  friend ExportedByJS0MRSHL HRESULT CloseInCache(const char* iPath, 
						 const char *iTS,
						 const char* iCacheType, 
						 int &oWarning );

  
  friend ExportedByJS0MRSHL long OpenToReadInCache(CATUnicodeString* iPath, 
						   const char *iTS,
						   const char* iCacheType, 
						   CATUnicodeString **oCache, 
						   unsigned int &oIsUpToDate, 
						   CATCacheManager *iObj);
  
  friend ExportedByJS0MRSHL long OpenToWriteInCache(CATUnicodeString* iPath, 
						    const char *iTS,
						    const char* iCacheType, 
						    CATUnicodeString **oCache, 
						    CATCacheManager *iObj);



  friend ExportedByJS0MRSHL long ViewCache(const char *iCacheType, 
					   CATUnicodeString **&oReference,
					   CATUnicodeString **&oCachePath,
					   unsigned int &oNbElem,
					   CATCacheManager *iObj);

  friend ExportedByJS0MRSHL long ViewCache(CATString *iDirectory, 
					   const char *iCacheType,
					   CATUnicodeString **&oReference,
					   CATUnicodeString **&oCachePath, 
					   unsigned int &oNbElem, 
					   CATCacheManager *iObj);

  friend ExportedByJS0MRSHL HRESULT CATSysViewCache(CATUnicodeString *iDir,
						    const char *iCacheType,
						    CATUnicodeString **&oRef, 
						    CATUnicodeString **&oCache,
						    CATUnicodeString **&oTS,
						    unsigned int &oNbElem, 
						    CATCacheManager *iObj);
  
  friend ExportedByJS0MRSHL long SizeUsedInCache(const char* iCacheType , 
						 unsigned long &oUsed,
						 CATCacheManager *iObj);
  

  friend ExportedByJS0MRSHL long RemoveInCache (const char* iPath, 
						const char* iCacheType, 
						CATCacheManager *iObj);
  
 


  // Factory for CacheManager
  static CATCacheManager *CreateManager(const char *iTypeToCache);
  
  //--------------------------------------------------------------------------
  // Transaction in Cache
  // Begin Transaction
  //    Return values:   0    OK
  //			-1   Already in a transaction
  static long BeginTransaction (const char *iTypeToCache);
  long BeginTransaction ();

  // Close Transaction
  //    Return values:  0    OK
  //			-1   No transaction opened
  static long CloseTransaction (const char *iTypeToCache);
  long CloseTransaction ();
  

  //--------------------------------------------------------------------------
  // methods to overwrite
  virtual long VerifTimeStamp (const char * iReferenceName, 
			       const char *iCacheName);
  
  virtual long GiveCacheFileName (const char * iReferenceName, 
				  const char * iCacheType,
				  char *& oCacheName );
  
  virtual long VerifTimeStamp (const char * iReferenceName,  const char *iTS,
			       const char *iCacheName);
  
  virtual long GiveCacheFileName (const char * iReferenceName,  
				  const char *iTS,
				  const char * iCacheType, char *&oCacheName);
  

  // Si iCacheDir=NULL alors on rend le path pour l'environnement de setting
  // courant, sinon on calcul le nom de l'objet en prenant iCacheDir comme
  // path du cache
  HRESULT GiveCacheFileName( CATUnicodeString *iCacheDir,
			     CATUnicodeString *iRefName,
			     const char *iTS, const char * iCacheType, 
			     CATUnicodeString **oCachePath);
  
  HRESULT GiveOriginalID( CATUnicodeString *iCacheDir,
			  CATUnicodeString *iCachePath,
			  const char * iCacheType, char *oTS,
			  CATUnicodeString **oCachePath);


  // iDir path du repertoire a checker
  // les retours sont les suivants 
  // S_OK Version = 5  UTC= 0  
  //             Cache R12(xml) en heure locale
  // S_OK Version = 5  UTC= 1  
  //             Cache R12(xml) en heure GMT
  // S_OK Version = 4 UTC =0
  //              Cache R11 (.dat) en heure locale
  // S_OK Version = 5  UTC= -1
  //		 repertoire vide pas d'xml ou de .dat
  // CATHRESULT(ERROR_PATH_NOT_FOUND, FACILITY_WIN32) Version=? UTC =?
  //             c'est quoi ce path ?

  HRESULT CheckDirectory(CATUnicodeString *iDir, int *Version, 
			 signed char *UTC);


  
  // alors la je seche pour savoir qd ecrire l'index... 
  // iVerif =1 force la verification de tous les fichiers references 
  // ds le cache
  // a n'utiliser qu'en sortie de session pour des raisons de perfos
  static long SaveCache (const char *iTypeToCache, int iVerif=0);
  static long ReleaseManager (const char *iTypeToCache);

  long CreateStructure( const char *iPath, const char *iTS,
			const char *iCacheType, 
			CATString *LocalPath, char *& oCachePath);

  HRESULT CreateStructure( CATUnicodeString *iPath, const char *iTS,
			   const char *iCacheType, 
			   CATUnicodeString *LocalPath, 
			   CATUnicodeString ** oCachePath);
  
protected:
  CATCacheManager(const char *iType) ;
  virtual ~CATCacheManager();
  
  CATIntCache *_Cache;
  
  
private:
  // Resizing of Local HashTable
  long ResizeTable();
  // Suppression of LRU Object when MaxSize is reached
  long CleanCache();
  
  
  // 
  void CheckCoherence ( CATFileMap *&iFileMap,  const char *iPath, 
			CATString *iDirectory, int iReleaseDirectory,
			char *& oCachePath, unsigned int &oIsUpToDate);

  void CheckCoherence ( CATFileMap *&iFileMap,  
			const char *iPath, const char *iTS,
			CATString *iDirectory, int iReleaseDirectory,
			char *& oCachePath, unsigned int &oIsUpToDate);

  void CheckCoherence ( CATFileMap *&iFileMap,  
			CATUnicodeString *iPath, const char *iTS,
			CATUnicodeString *iDirectory, int iReleaseDirectory,
			CATUnicodeString **oCachePath,
			unsigned int &oIsUpToDate);
  
  //
  long ScanHashTable( CATHashTabCATFileMap * iTable, unsigned int &oNbElem,
		      CATUnicodeString **oReference, 
		      CATUnicodeString **oCachePath);
  
  CATCacheManager *_Next;
  static CATCacheManager *_Init;
  


};

#endif
