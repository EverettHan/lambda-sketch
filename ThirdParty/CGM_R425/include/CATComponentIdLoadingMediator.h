#ifndef _CATComponentIdLoadingMediator_H
#define _CATComponentIdLoadingMediator_H
// ----------------------------------------------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2007
/**
 * @level Private
 * @usage U1
 */
// ----------------------------------------------------------------------------------------------------------------------
//#define AuthorizedModule                  999
//#define CATPLMTos                         AuthorizedModule
//#define CATPLMIntegration                 AuthorizedModule
//#if _MK_MODNAME_ == AuthorizedModule
//#else
//	    #error Forbidden access to link services from a non-infrastructure module
//        @error 
//#endif
//#undef CATPLMTos   
//#undef CATPLMIntegration
//
//#include "ExportedByCATPLMTos.h"
//#include "CATTosMacros.h"
//
//class CATIPLMIntegRecordRead;
//
//class ExportedByCATPLMTos CATComponentIdLoadingMediator
//{
//public:
//
//  CATComponentIdLoadingMediator(){}
//  virtual ~CATComponentIdLoadingMediator(){}
//
//  /**
//  * Call factories for building entity
//  *
//  * @return 
//  *      S_OK   : if succeeded
//  *      E_FAIL : if failed
//  */
//  virtual HRESULT BuildEntity (CATBaseUnknown *& oEntity) = 0;
//
//  /**
//  * Returns Concurrent stamp to be registered at component level
//  * 
//  * @param oCEStamp
//  *      The concurrent stamp extracted from PLM message
//  * 
//  * @return 
//  *      S_OK   : if succeeded
//  *      S_FALSE: CEStamp not managed
//  *      E_FAIL : if failed
//  */
//  virtual HRESULT GetCEStamp (CATPLMCEStamp & oCEStamp) = 0;
//  
//  /**
//  * Returns owner to be registered at component level
//  * 
//  * @param oOwner
//  *      The owner extracted from PLM message
//  * 
//  * @return 
//  *      S_OK   : if succeeded
//  *      E_FAIL : if failed
//  */
//  virtual HRESULT GetOwner (CATComponentId & oOwner) = 0;
//
//  /**
//  * Returns reference to be registered at component level
//  * 
//  * @param oReference
//  *      The reference extracted from PLM message
//  * 
//  * @return 
//  *      S_OK   : if succeeded
//  *      E_FAIL : if failed
//  */
//  virtual HRESULT GetReference (CATComponentId & oReference) = 0;
//
//  /**
//  * Returns relational to be registered at component level
//  * 
//  * @param oRelations
//  *      The relations extracted from PLM message
//  * 
//  * @return 
//  *      S_OK   : if succeeded
//  *      E_FAIL : if failed
//  */
//  //virtual HRESULT GetRelations (CATPLMRelations & oRelations) = 0;
//
//private:
//
//  // Forbidden operators 
//  CATComponentIdLoadingMediator (CATComponentIdLoadingMediator&);
//  CATComponentIdLoadingMediator& operator=(CATComponentIdLoadingMediator&);
//  void * operator new(size_t, CATComponentIdLoadingMediator&);
//};

#endif
