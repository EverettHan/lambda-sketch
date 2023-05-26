/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATCommandDispatchCreate                                             */
/*                                                                       */
/*  Usage Notes:                                                         */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                   jpl          */
/*=======================================================================*/
#ifndef __CATCommandDispatchCreate
#define __CATCommandDispatchCreate

#include "CATCallbackManager.h"
#include "JS0FM.h"

class ExportedByJS0FM CATCommandDispatchCreate : public CATCallbackManager
{


   public :

      //===================================================
      // Methods
      //===================================================

      // Instanciation
      //--------------
      CATCommandDispatchCreate ( );
      virtual ~CATCommandDispatchCreate () ;

      // CATCommandDispatchCreate instance
      //----------------------------------
      static  CATCommandDispatchCreate *GetMain() ;

      // Event dispath by CallbackManager
      // --------------------------------
      CATDeclareCBEvent(Create);

      static void StartDispatch();
      static void StopDispatch();
      static void Dispatch();

   private :


      //===================================================
      // Data
      //===================================================

      // CATCommandDispatchCreate Instance
      //-------------------------
      static CATCommandDispatchCreate* _First;


};

#endif
