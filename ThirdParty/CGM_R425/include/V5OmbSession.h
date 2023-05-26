// COPYRIGHT DASSAULT SYSTEMES 2003

#ifndef V5OmbSession_H_
#define V5OmbSession_H_

/**
 * @level Private
 * @usage U1
 */

#include "AC0XXLNK.h"
#include "CATUnicodeString.h"

class V5OmbCacheDataSession ;
class V5OmbServices ;
class V5OmbTransactionMgr ;

class ExportedByAC0XXLNK V5OmbSession
{
 public :
 
  ~V5OmbSession() ;

  static V5OmbSession* GetSession(const char* session_name) ;
  static void close_Session(const char* session_name) ;
  // on devrait avoir un call de list

  V5OmbCacheDataSession* GetCacheDataSession() ;
  V5OmbServices* GetServices() ;
  V5OmbTransactionMgr* GetTransactionMgr() ;

  CATBoolean isFeatureActive(const char* featureName) ;
  
	inline void ToggleLinkCreationBehavior() {
		_bindSequenceBeforeLinkCreation = 
			!_bindSequenceBeforeLinkCreation;
	}

	inline CATBoolean BindSequenceBeforeLinkCreation() {
		return _bindSequenceBeforeLinkCreation;
	}

 private :

   V5OmbSession() ;
   static V5OmbSession* _instance ;

   int GetEnvironmentVariable(const char* envVar) ;
   CATBoolean CalculateEnvironmentVariable(int variable) ;

   V5OmbCacheDataSession* cacheDataSession ;
   V5OmbServices* services;
   V5OmbTransactionMgr* transactionMgr ;
  
   int varOMB_RESOLUTION_LINK_CACHING ;
   int varOMB_MONITORING_ENABLED ;
   int varOMB_PROXY_RESOLUTION_ON_LAST_MODIFTS_ENABLED ;
   int varOMB_EXTENDED_MEMORY_ENABLED ;
   int varOMB_STREAM_SLAVES;   
   int varOMB_VVS_DONT_CLONE;
   // BHG: Use CuteIO Component
   int varOMY_CUTEIO_ACTIVE;
	 CATBoolean _bindSequenceBeforeLinkCreation;

} ;
#endif
