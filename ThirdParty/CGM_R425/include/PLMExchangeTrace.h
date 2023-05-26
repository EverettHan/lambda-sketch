#ifndef PLMExchangeTrace_h
#define PLMExchangeTrace_h
// COPYRIGHT DASSAULT SYSTEMES 2013-2016
// *****************************************************************
//
//   Identification :
//   ---------------
//
//      RESPONSIBLE : Jean-Luc MEDIONI
//      FUNCTION    : Exchange Experience 
//      USE         : ENOVIA
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    Class enabling to ease trace management through CATTrace Exchange solutions.
//
// *****************************************************************
//
//   Remarks :
//   ---------
//
//    Code inspired by PLMExchangeTrace.
//
/**
  * @level Private
  * @usage U1
  */
//
// ****************************************************************
//
//   Story :
//   -------
//
//   Revision 1.0  July 2013           Author:  Jean-Luc MEDIONI  Objects: Initial Revision from PLMExchangeTrace
//   Revision 1.1  October 16th, 2015  Author:  Jean-Luc MEDIONI  Objects: Initial Revision to validate PLMExchangeTrace
//   Revision 1.2  July 21st, 2015     Author:  Jean-Luc MEDIONI  Objects: Define method to access to trace level for conditional traces.
//   Revision 1.3  January 6th, 2016   Author:  Jean-Luc MEDIONI  Objects: Add a solution to send activate traces outside context of method call
//
// ****************************************************************

// -- PLMExchangeServices
#include "PLMExchangeGlobalServices.h"

// -- System & SpecialAPI
#include "CATSysErrorDef.h"
#include "CATTrace.h"
#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATListOfInt.h"

class CATBaseUnknown             ;
class CATBinary                  ;
class CATTime                    ;
class CATDbBinary                ;
class CATPLMID                   ;
class CATIPLMComponent           ;
class CATListPtrCATIPLMComponent ;
class CATListValCATPLMID         ;
class CATLISTV_CATPLMID          ;

/**
  * Class for trace management.
  * <b>role</b>: Trace management.
  */
class ExportedByPLMExchangeGlobalServices PLMExchangeTrace : public CATTrace
{
   public:
    /**
      * Constructor.
      */
      PLMExchangeTrace( char* , char* , char* , CATTraMode iMode = CATTraUnactivated ) ;

    /**
      * Destructor.
      */
      ~PLMExchangeTrace() ;

    /**
      * method indirectly called by PLMSRM_TRACE_IN macro.
      */
      void FunctionBegin( const char * ) ;

    /**
      * method indirectly called when exiting a PLMSRM_TRACE_IN macro scope.
      */
      void FunctionEnd( const char * ) ;

      //-- operator << overloading for TRACE macro.

      PLMExchangeTrace & operator << (const void *) ;

      PLMExchangeTrace & operator << (const CATBaseUnknown_var& ) ;

      PLMExchangeTrace & operator << (const CATBaseUnknown* ) ;

      PLMExchangeTrace& operator<<(const char* );
      inline PLMExchangeTrace& operator<<(PLMExchangeTrace& (*functor)(PLMExchangeTrace&)) { return functor(*this); }

      PLMExchangeTrace & operator << (const CATString&) ;

      PLMExchangeTrace & operator << (const CATUnicodeString&) ;

      PLMExchangeTrace & operator << (const char ) ;

      PLMExchangeTrace & operator << (const int) ;

      PLMExchangeTrace & operator << (const long) ;

      PLMExchangeTrace & operator << (const unsigned long) ;

      PLMExchangeTrace & operator << (const double ) ;

#if defined (_MSC_VER) && (_MSC_VER >= 1400)
      PLMExchangeTrace & 	operator << (__int64 v ) { return PLMExchangeTrace::operator << ((const int)v) ;}
#endif

      PLMExchangeTrace & operator << (const CATTime &) ;

      PLMExchangeTrace & operator << (const CATDbBinary&) ;

      PLMExchangeTrace & operator << (const CATBinary& ) ;

      PLMExchangeTrace & operator << ( const CATPLMID& ) ;

      PLMExchangeTrace & operator << ( CATIPLMComponent* ) ;

      PLMExchangeTrace & operator << ( const CATListPtrCATIPLMComponent& ) ;

      PLMExchangeTrace & operator << ( const CATListValCATPLMID&  ) ;

      PLMExchangeTrace & operator << ( const CATListOfInt& ) ;

    /**
      * Enable to set trace level which condition if trace is displayed or not according level of detail expected.
      */
      int SetLevel( int nLevel ) ;

    /**
      * Display current trace level.
      */
      int GetLevel() const ;

      PLMExchangeTrace & _DumpPLMIds(const CATListValCATPLMID & );
      PLMExchangeTrace & _DumpCATIPLMComponents(const CATListPtrCATIPLMComponent & ) ;

   private :
      int    _Show      ;
      int    _NewLine   ;
      int    _Level     ;
      char   _Alias[17] ;
  
      PLMExchangeTrace & Header() ;

      int IsShown() ;

    /**
      * To manage indentation in relation to call hierarchy.
      */
      static int _gLevel ;

   public :
    /**
      * To manage trace output stream.
      */
      static const char * STDOUT                   ;

    /**
      * Trace message use at method return.
      */
      static const char * PLMExchangeTrace_Str_returns ;

    /**
      * For tracking Carriage return.
      */
      static const char   PLMExchangeTrace_Char_NewLine ;
      static const char * PLMExchangeTrace_Str_NewLine  ;

   private :
      PLMExchangeTrace( const PLMExchangeTrace & ) ;
      PLMExchangeTrace & operator=( const PLMExchangeTrace &) ;
} ;

inline int PLMExchangeTrace::IsShown()
{
  return (_Show ) ;
}

inline int PLMExchangeTrace::SetLevel( int nLevel )
{
  if( nLevel >= 2 ) _Level = nLevel ;
  return (_Level ) ;
}

inline int PLMExchangeTrace::GetLevel() const
{
  return (_Level ) ;
}

class ExportedByPLMExchangeGlobalServices PLMExchangeTraceStep 
{
   public :
      PLMExchangeTraceStep( PLMExchangeTrace* , const char * ) ;
      PLMExchangeTraceStep( PLMExchangeTrace* ) ;
      ~PLMExchangeTraceStep() ;

      PLMExchangeTrace * _trace ;
      const char       * _name  ;

   private :
      PLMExchangeTraceStep (const PLMExchangeTraceStep& );
      PLMExchangeTraceStep& operator = (const PLMExchangeTraceStep&) ;
} ;

//-- Trace declaration

#define PLMSRM_TRACE(alias,os) \
  static PLMExchangeTrace catplmsrm_trace_##alias(#alias,#alias,os)

//-- Beginning of a scope

#define PLMSRM_TRACE_IN(alias,func_name) \
  PLMExchangeTraceStep __catplmsrm_trace_step(&catplmsrm_trace_##alias,func_name)

#define PLMSRM_TRACE_INIT(alias) \
  PLMExchangeTraceStep __catplmsrm_trace_step(&catplmsrm_trace_##alias)

inline PLMExchangeTrace& endl(PLMExchangeTrace& out) {return out << "\n";}

#undef      TRACE
#undef      TRACEON

//-- Macro for trace printing.

#define TRACE *(__catplmsrm_trace_step._trace)

//-- Macro to check trace activation.

#define TRACEON (__catplmsrm_trace_step._trace)->IsActive() 

//-- Macro to get & set trace level.

#define TRACE_SET_LEVEL(nlevel)          (__catplmsrm_trace_step._trace)->SetLevel(nlevel) 
#define TRACE_GET_LEVEL(nlevel) nlevel = (__catplmsrm_trace_step._trace)->GetLevel() 

//-- Macro for printing return code.

#define PLMSRM_TRACE_RETURN(value) \
   {                 \
      *(__catplmsrm_trace_step._trace) << PLMExchangeTrace::PLMExchangeTrace_Str_returns << value ; \
      return value ; \
   }
#endif
