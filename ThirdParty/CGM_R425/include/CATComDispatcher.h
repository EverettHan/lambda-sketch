/*
 * ==============================================================
 * COPYRIGHT DASSAULT SYSTEMES 2009                               
 * ============================================================== 
 * CATComDispatcher
 *                                          
 * src: CATComBase.m/src/CATComDispatcher.cpp
 * ============================================================== 
 * Creation Jun 2009                     UZD                      
 * ============================================================== 
 */


#ifndef _CATComDispatcher
#define _CATComDispatcher


//include
#include "CATComBaseExps.h"  //module
#include "CATSysErrorDef.h"


//forward declarations
class CATHashDico;
class CATBaseUnknown;
class CATUnicodeString;


//function pointer handler
typedef HRESULT (*CATComFctPtr)(CATBaseUnknown*);


class ExportedByCATComBase CATComDispatcher
{
  public:
   
   //DTOR
   ~CATComDispatcher();
   
   //call this first
   static CATComDispatcher* GetDispatcher();
   
   //Handler methods
   HRESULT  AddHandler(const CATUnicodeString& iMessageType, 
					              CATComFctPtr iHandler);

   HRESULT  RemoveHandler(const CATUnicodeString& iMessageType);
   
   CATComFctPtr GetHandler(const CATUnicodeString& iMessageType);


  private: 

   //CTOR
   CATComDispatcher();
   
   //Memeber variables
   static CATComDispatcher * _singleton;
   CATHashDico * _handlerDico;
   
};


#endif
