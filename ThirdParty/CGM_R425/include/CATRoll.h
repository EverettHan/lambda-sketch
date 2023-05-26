/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATRoll                                                              */
/*                                                                       */
/*  Usage Notes: Roll                                                    */
/*                                                                       */
/*=======================================================================*/
/*  Creation septembre 1997                                 jpl          */
/*=======================================================================*/
#ifndef __CATRoll
#define __CATRoll

#include "JS0FM.h"

#define TAGCS ".CATTagcs"
#define TAGWS ".CATTagws" 

class ExportedByJS0FM CATRoll
{

   public :

      // Instanciation
      //--------------
      CATRoll ( );
      virtual ~CATRoll () ;

      static  CATRoll *GetMain() ;  // Get CATRoll instance

      const char* GetRollCS (); // get cold start path
      const char* GetRollWS (); // get warm start path
      
      int RollOutEnd( int istatusrollout);	 
      int AbnormalEnd();
      int SessionEnd();
      int GetStartMode( char **ofilecs, char **ofilews ); 
      

   private :

      int Create();    // Roll directory initialisation
      int Release();   // Roll directory destruction
      
      int TagCSCreate( char* ); // cold start tag creation
      int TagCSDelete( char* ); // cold start tag destruction
      int TagCSStatus( char* ); // cold start tag status 
      
      int TagWSCreate( char* ); // warm start tag creation
      int TagWSDelete( char* ); // warm start tag destruction
      int TagWSStatus( char* ); // warm start tag status 
      
      int IsRollActive(); //Indicate if the roll is active or inactive 

      char *_rollfileCS;       // Cold Start path
      char *_rollfileWS;       // Cold Start path

      int rettypstart;	       // start mode
      static CATRoll* _First;  // CATRoll Instance
      int _ActiveRoll ;        // Indicate if the roll is active
   
};

#endif
