#ifndef CATSysErrContext_H
#define CATSysErrContext_H
#include "JS0ERROR.h"
#include "CATErrorDef.h"
class CATError;
class CATSysErrCx;

/***
 ** this enum is meant to be used in the methods PushNewContext & PopContext
 ** in PushNewContext, only CATErrCtxPopKeepInUpperCtx or CATErrCxtPopDelete
 ** should be used ( in PushNewContext, using CATErrCtxPopUsePushDefault is 
 **                  equivalent to CATErrCtxPopKeep )
 ***/
enum CATErrContextErrorPolicy 
{
  CATErrCtxPopKeepInUpperCtx=0, // the errors will be moved to upper context 
  CATErrCtxPopDelete=1,         // the errors will be removed and ignored
  CATErrCtxPopUsePushDefault=2  // the errors will be removed and ignored
				// this value MUST be used only in Pop
				// it must not be used in Push-
                                // if used in Push it will mean the same
                                // as  CATErrCtxErrPopKeep
};
class ExportedByJS0ERROR CATSysErrContext
{
   public:
     /***
 	Allows to create a new  context   on top of the preceding one .  The caller  can decide at this time what will happen  by default to the error contained by the context at the time of the PopContext
        Arguments :
 	oKey : cle permettant l appel de PopContext
 	iPolicyForPop  : permet de specifier ce qui  arrivera par defaut  aux erreurs du context lors du Pop.
     ***/
     static HRESULT PushNewContext( int &oKey , enum CATErrContextErrorPolicy iPolicyForPop) ; 


    /***
•	PopContext	
 	PopContext allows to suppress the current context and restore the previous one.
 	The caller may decide to transfer the errors  from the current context to the previous one at this time or to throw them away
 	Arguments
 	iKey : clé rendue par PushNewContext
 	iPolicyForPop  : permet de specifier ce qui  arrivera aux erreurs du context
     ***/
     static HRESULT PopContext ( int iKey, enum CATErrContextErrorPolicy iPolicyForPop ) ;
 

     /***
      ** PushErrorToContext
      ** Pushes on error on top of the current context
     ***/
     static HRESULT PushErrorToContext( CATError *);


    /**
     ** PopErrorFromContext
     ** Allows to get the last error pushed on the context at the same time that it suppress it from the context
    ***/
    static HRESULT PopErrorFromContext( CATError **);


    /***
•	Get	NextContextError
 	Allows to list all the errors  in the current context
 	Caller can  pass  NULL as  value  of   iFrom to get the first error of the list
 	The returned CATError is not removed from the list  and it is add-refed before to be returned
    ***/
    static HRESULT GetNextContextError( CATError *iFrom , CATError **oNextError) ;


   /**
    ** RemoveErrorFromContext
    ** Removes the error iErr from the current context
    **/
    static HRESULT RemoveErrorFromContext ( CATError *iErr ) ;

    /**
    ** Reset
    ** remove all errors from the current context
    **/
    static HRESULT Reset( ) ;
   
   /**
    ** IsEmpty
    ** return -1 if there is no error in the current context 
    **          or if there is no current context 
    ** return 0  if there is  a current context and this context contains at least 1 error
    **/
    static int IsEmpty() ;
   
    /**
     ** SERVER SIDE ONLY
     **
     ** The current content of the Error context is added to the error set
     **
     ** it fails if not in the context of a server command
     **
     ** on client side this method does NOTHING and fails
     **
     **/
    static HRESULT AddToErrorSet();

    private :
    static CATSysErrCx *CreateNewContext( CATErrContextErrorPolicy iPolicy );
    static CATSysErrCx *GetSpecificContext( int iKey );
    static CATSysErrCx *GetCurrentContext( );

};
#endif
