//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005                                          
//===========================================================================
//                                                                           
//  CATISysTSPersistCache                                                    
//                                                                           
//  Usage Notes:                                                             
//===========================================================================
//  Creation mars 2005                                      adt              
//===========================================================================
#ifndef _CATSYSTSPERSISTCACHE
#define _CATSYSTSPERSISTCACHE

#include "IUnknown.h"

#include "JS0TSLIB.h"



class CATUnicodeString;
class CATSysTSURI;


extern ExportedByJS0TSLIB const IID IID_CATISysTSPersistCache;

/**
 * Interface used to manage inter-session persistent caches.
 * A CATSysVaultSite can decide to implement an inter-session cache
 */
class ExportedByJS0TSLIB CATISysTSPersistCache : public IUnknown
{
 public:
  
/**
 * Returns the URI of cached ressource.
 * <b>Role</b>:Returns the URI of cached ressource associated to the given URI
 * with a  given watermark. The watermark is used to determine if the cached 
 * ressource is still uptodate with the original object.
 * @param iURI
 *   The URI of the ressource for which the cached view is queried.
 * @param  iWaterMark
 *   The WaterMark of the URI
 * @param iType
 *   The StreamDesc type.
 * @param oCachedURI
 *    The URI of the cached view of the ressource if found.
 * @return
 *   S_OK on Success.
*/
  virtual HRESULT __stdcall GetCachedURI (CATSysTSURI &iURI, 
					  CATUnicodeString &iWaterMark,
					  CATUnicodeString & iType,
					  CATSysTSURI *&oCachedURL)=0;
  
/**
 * Returns the URI of cached ressource.
 * <b>Role</b>:Creates the URI of cached ressource associated to the given URI
 * with a given watermark, in order to create a new cached ressorce.
 * @param iURI
 *   The URI of the ressource for which the cached view is to be created.
 * @param  iWaterMark
 *   The WaterMark of the URI.
 * @param iType
 *   The StreamDesc type.
 * @param oCachedURI
 *    The URI of the cached view of the ressource.
 * @return
 *   S_OK on Success.
 */
  virtual HRESULT __stdcall CreateCachedURI (CATSysTSURI &iURI, 
					     CATUnicodeString &iWaterMark,
					     CATUnicodeString & iType,    
					     CATSysTSURI *&oCachedURL)=0;




/**
 * Close the URI of cached ressource.
 * <b>Role</b>:Indicates that the  cached ressource associated to the given URI
 * with a given watermark, has been properly created in the cache.
 * @param iURI
 *   The URI of the ressource for which the cached view is to be created.
 * @param  iWaterMark
 *   The WaterMark of the URI.
 * @param iType
 *   The StreamDesc type.
 * @param oWarning
 *    <b>Legal values</b> 1 the associated cache ressource has not been found;
 *    <b>Legal values</b> 2 the maximum size has been reached and place has 
 *			    been made in the cache.
 * @return
 *   S_OK on Success.
 */
  virtual HRESULT __stdcall CloseCachedURI (CATSysTSURI &iURI, 
					    CATUnicodeString &iWaterMark,
					    CATUnicodeString & iType,    
					    int &oWarning)=0;


 /**
 * Deletes a cached ressource.
 * <b>Role</b>:Deletes the cached ressource associated to the given URI with a 
 * given watermark. It will destroy the ressource.
 * @param iURI
 *   The URI of the ressource for which the cached view is to be created.
 * @param  iWaterMark
 *   The WaterMark of the URI
 * @param iType
 *   The StreamDesc type.
 * @return
 *   S_OK on Success.
 */
  virtual HRESULT __stdcall DeleteCachedURI (CATSysTSURI &iURI, 
					     CATUnicodeString &iWaterMark,
					     CATUnicodeString & iType)=0;

/**
 * Deletes a cached ressource.
 * <b>Role</b>:Deletes the cached ressource pointed by the given URI which has 
 * been previously returned by @href #CreateCachedURI or @href #GetCachedURI.
 * @param iURI
 *   The URI of the cached ressource.
 * @return
 *   S_OK on Success.
*/
  virtual HRESULT __stdcall DeleteCachedURI (CATSysTSURI &iCachedURI)=0;
};



HRESULT ExportedByJS0TSLIB  CATSysGetPersistentCache(
				 CATISysTSPersistCache **oCache,
				 const char *iName= 0);

#endif
 
