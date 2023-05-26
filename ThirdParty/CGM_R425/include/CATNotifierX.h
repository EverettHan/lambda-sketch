/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATNotifier                                                          */
/*                                                                       */
/*  Usage Notes:                                                         */
/*                                                                       */
/*   CATNotifier dispatch :                                              */
/*      - SendNotification                                               */
/*      - Callbacks on Idle, Endtransaction, File Descriptor, Timer      */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                   jpl-sgt      */
/*=======================================================================*/
#ifndef __CATNotifierX
#define __CATNotifierX
#ifndef _WINDOWS_SOURCE

#include "CATDataType.h"
#include "CATCommand.h"




class CATNotification;
class CATString;
class CATCleaner;
class CATAppBaseList;
class CATNotificationET;
class CATNotificationFd;
class CATNotificationIdle;
class CATNotifier;
class CATNotifierListTime;
class CATNotifierListFd;


#define _DebugNotifierCode
#define CATSysFMKeepId 0x02



#define NotInit(a) (a ? !(a->_Init) : ((a=CATNotifierX::CreateNotifier())!=NULL))



class ExportedByJS0FM CATNotifierX
{
  friend class CATNotifier;
 public :
  
  //===================================================
  // Methodes
  //===================================================
  
  // Instanciation
  //--------------
  //CATNotifierX (){};
  virtual ~CATNotifierX (){} ;
  
  
  static CATNotifierX * CreateNotifier();

  void virtual Init( void* graph)=0;

    
  //===================================================
  // Datas
  //===================================================
  int virtual AddIdleHandler(void *pt=NULL)=0;
  int virtual RemoveIdleHandler()=0;

  int virtual AddTimeOut ( CATNotifierListTime *pt,int Time, CATCommand* ToClient,
			   void* clientdata, void (*UserStaticMeth)(), 
			   int *oIdSub=NULL, int iReserved=0)=0;


  int virtual RemoveTimeOut ( CATNotifierListTime *pt) =0;

  int virtual AddFileDescriptor( int fd, CATCommand* ToClient,
			  void* clientdata, void (*UserStaticMeth)() ,
			  int *oIdSub=NULL,int iReserved=0)=0;
  
  int virtual RemoveFileDescriptor( CATNotifierListFd* pt)=0;
  

  void virtual GetWindowsInfo(CATNotifierX* iObj, CATNotifier *iNewNot)=0;
  


 protected:

  int _Init;
  CATNotifier * _RootNotifier;
};


#endif
#endif
