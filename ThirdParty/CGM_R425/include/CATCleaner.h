/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATCleaner                                                           */
/*                                                                       */
/*  Usage Notes: The Object KILLER                                       */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                   jpl-sgt      */
/*=======================================================================*/
#ifndef __CATCleaner
#define __CATCleaner

class CATNotifier ;
class CATNotification ;
class CATCommand ;
class CATAppBaseList ;
class CATAppBaseElt ;
#include "JS0FM.h"

class ExportedByJS0FM CATCleaner
{

   public :

      //===================================================
      // Methods
      //===================================================

      // Instanciation
      //--------------
      CATCleaner( CATNotifier *Suscriber );
      virtual ~CATCleaner ( ) ;
      void Empty( );
      static void DeleteOnTransactionEnd ( CATCommand * );
      static void DeleteOnTransactionEnd ( CATNotification * );
      static void DeleteOnTransactionEnd ( CATAppBaseElt *, CATAppBaseList * );

      static void DontDeleteOnTransactionEnd ( CATCommand * );
   private :

      //===================================================
      // Methods
      //===================================================

      void PutDeletableObject( CATCommand * );
      void PutDeletableObject( CATNotification * );
      void PutDeletableObject(CATAppBaseElt *,  CATAppBaseList * );
      void RemoveDeletableObject(CATCommand *);

      //===================================================
      // Data
      //===================================================

      CATAppBaseList *_ListOfDeadObjects;
      CATNotifier   *_Father ;
      static CATCleaner *_TheCleaner;

};
#endif
