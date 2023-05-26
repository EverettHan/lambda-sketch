#ifndef _PLMPosTrace_h_
#define _PLMPosTrace_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

/**
 * @level Protected
 * @usage U1
 */

#undef  VPM_PROFILING
#define VPM_PROFILING

/** @nodoc */
#define POS_DEBUG_NEWDEL

// System
#include "CATErrors.h"
#include "CATTrace.h"

// PLM POS base
#include "ExportedByPLMPosBasTrace.h"


// Forward class declarations
class CATBaseUnknown;
class CATString;
class CATUnicodeString;
class PLMPosInfo;
class PLMPosTraceStep;


/**
* @nodoc
*/
class ExportedByPLMPosBasTrace PLMPosTrace : public CATTrace
{
public:

    /**
     * @nodoc
     * Constructor.
     */
    PLMPosTrace(char const*,char const*,char const*,int LoD = 1024, CATTraMode iMode = CATTraUnactivated);

    /**
     * @nodoc
     * Destructor.
     */
    ~PLMPosTrace();

    /** @nodoc */
    void    FunctionBegin(const char*);

    /** @nodoc */
    void    FunctionEnd(CATLONG32 iStartTime = 0);

    /**
     * @nodoc
     * Display any kind of pointer.
     */
    PLMPosTrace&    operator << (const void*);

    /**
     * @nodoc
     * Display a CATBaseUnknown handler.
     */
    PLMPosTrace&    operator << (const CATBaseUnknown_var &);

    /**
     * @nodoc
     * Display a CATBaseUnknown pointer.
     */
    PLMPosTrace&    operator << (const CATBaseUnknown*);

    /**
     * @nodoc
     * Display a char*.
     */
    PLMPosTrace&    operator << (const char*);

    /**
     * @nodoc
     * Display a CATString.
     */
    PLMPosTrace&    operator << (const CATString &);

    /**
     * @nodoc
     * Display a CATUnicodeString.
     */
    PLMPosTrace&    operator << (const CATUnicodeString &);

    /**
     * @nodoc
     * Display a char.
     */
    PLMPosTrace&    operator << (const char);

    /**
     * @nodoc
     * Display an integer.
     */
    PLMPosTrace&    operator << (const int);

    /**
     * @nodoc
     * Display a long integer.
     */
    PLMPosTrace&    operator << (const long);

    /**
     * @nodoc
     * Display an unsigned long integer.
     */
    PLMPosTrace&    operator << (const unsigned long);

    /**
     * @nodoc
     * Display a double.
     */
    PLMPosTrace&    operator << (const double);

    /**
     * @nodoc
     * Display a PLMPosInfo.
     */
    PLMPosTrace&    operator << (PLMPosInfo &);

    /**
     * @nodoc
     * Manipulator.
     */
    PLMPosTrace&    operator << (PLMPosTrace& (*)(PLMPosTrace&));

    /**
     * @nodoc
     * Display a formatted message.
     */
    void printf( const char *format, ...) ;

    /** @nodoc */
    static    PLMPosTrace*    Current();
    /** @nodoc */
    char const *_Alias;
    /** @nodoc */
    static    void SetExternalIndentationPtr(int *ipLevel);
    /**
     * @nodoc
     * Internal use only.
     */
    static void cleanup();
private:
    /** @nodoc */
    static int end(int iRc);
    // donnees relative a chaque trace
    /** @nodoc */
    int                _LngName;
    /** @nodoc */
    int                _Show;
    /** @nodoc */
    int                _NewLine;
    /** @nodoc */
    int                _Level;
    /** @nodoc */
    int                _DetailLevel;
    /** @nodoc */
    int                _MaxDetailLevel;
    /** @nodoc */
    PLMPosTrace&    Header();
    /** @nodoc */
    int                IsShown();

    // donnees relative au mecanisme de traces
    /** @nodoc */
    static int            _gInit;          // flag d'init des Vpm Traces
    /** @nodoc */
    static int            _gLevel;         // niveau courant (indentation)
    /** @nodoc */
    static int *          _gExternalLevel; // niveau courant externe (indentation)
    /** @nodoc */
    static PLMPosTrace*    _gTrace;    // trace courante

public:
    /** @nodoc */
    static const char *STDOUT; // the canonical "STDOUT" string used to initialize PLMPosTrace objects: using
    // this saves quite a lot of space used by static string data.

private:
    /** @nodoc */
    PLMPosTrace(const PLMPosTrace&);
    /** @nodoc */
    PLMPosTrace& operator=(const PLMPosTrace&);
    
};


/*--------------------------------------------------------------------------*/
/* IsShown()                                                                */
/*--------------------------------------------------------------------------*/
inline int PLMPosTrace::IsShown() // this method is the 3rd most called in the Enovia server..
{
    return (_Show && (_DetailLevel <= _MaxDetailLevel));
}



//============================================================================
// PLMPosTraceStep
//============================================================================
/**
 * @nodoc
 */
class ExportedByPLMPosBasTrace PLMPosTraceStep
{
    /** @nodoc */
    PLMPosTraceStep(const PLMPosTraceStep&);
    /** @nodoc */
    PLMPosTraceStep& operator=(const PLMPosTraceStep&);
public:
    /** @nodoc */
    PLMPosTraceStep(PLMPosTrace*,const char*);
    /** @nodoc */
    ~PLMPosTraceStep();
#ifdef VPM_PROFILING
    /** @nodoc */
    const char        * _name;
#endif
    /** @nodoc */
    PLMPosTrace * _trace;
    /** @nodoc */
    CATLONG32          _time;
    /** @nodoc */
    CATLONG32          _elapsed;
};


//============================================================================
// Internal defines
//============================================================================
/**
 * @nodoc
 */
ExportedByPLMPosBasTrace PLMPosTrace& endl(PLMPosTrace&);

/**
 * @nodoc
 */
#define        POS_TRACE2(alias,os,max_level) \
static PLMPosTrace pos_trace_##alias(#alias,#alias,os,max_level)

/**
 * @nodoc
 */
#define        POS_TRACE(alias,os) \
POS_TRACE2(alias,os,1024) \

/**
 * @nodoc
 */

# define        POS_TRACE_IN(alias,func_name) \
PLMPosTraceStep __pos_trace_step(&pos_trace_##alias,func_name)

/**
 * @nodoc
 */
# define        POS_TRACE_OUT \
PLMPosTrace::Current()



//============================================================================
// Macro definition to use ...
//============================================================================


/*--------------------------------------------------------------------------*/
/* Standard traces                                                            */
/*--------------------------------------------------------------------------*/
#undef      TRACE
#undef      TRACEON
#undef      TRACEL
#undef      TRACEF
//
#undef      ZETRACEON
#undef      ZETRACEF
/**
 * @nodoc
 */
# define        TRACE         *(__pos_trace_step._trace)
/**
 * @nodoc
 */
# define        TRACEON       (__pos_trace_step._trace)->IsActive()
/**
 * @nodoc
 */
# define        TRACEL(level) ((__pos_trace_step._trace)->SetDetailLevel(level))
/**
 * @nodoc
 */
# define        TRACEF (__pos_trace_step._trace)->printf

#ifdef ZETRACE
/**
 * @nodoc
 */
# define ZETRACEON ZETRACE.IsActive()
/**
 * @nodoc
 */
# define ZETRACEF ZETRACE.printf
#endif

/**
 *--------------------------------------------------------------------------
 * Macros d'affichage de traces new/del
 * Usage interne seulement, et hors CNEXT_CLIENT
 *--------------------------------------------------------------------------
 */
#if defined(POS_DEBUG_NEWDEL) && !defined(CNEXT_CLIENT)
/** @nodoc */
# define POS_DEBUG_NEWDEL_print(classe,newdel) { if (CATDevelopmentStage()) { printf("DBG ::%s %s %p\n",newdel,classe,(void*)this); fflush(stdout); } }
#else
/** @nodoc */
# define POS_DEBUG_NEWDEL_print(classe,newdel)
#endif
/** @nodoc */
#define POS_DEBUG_NEWDEL_new(classe) POS_DEBUG_NEWDEL_print(classe,"new")
/** @nodoc */
#define POS_DEBUG_NEWDEL_del(classe) POS_DEBUG_NEWDEL_print(classe,"delete")


/*--------------------------------------------------------------------------*/
/* TRY / CATCH / THROW macro defintions                                        */
/*--------------------------------------------------------------------------*/

// try bloc
#undef CATVpmTry
#undef CATVpmEndTry
#undef CATVpmThrow
#undef CATVpmRethrow
#undef CATVpmCatch
#undef CATVpmCatchOther
#undef CATVpmReturn
#undef TRACERR
/**
 * @nodoc
 */
#define CATVpmTry(alias,func_name) \
POS_TRACE_IN(alias,func_name); \
CATTry

// throw
/**
 * @nodoc
 */
#define        CATVpmThrow(err) \
TRACE << "<- throw (" << err->GetName() << ")" << endl;\
CATThrow(err)

// catch
/**
 * @nodoc
 */
#define CATVpmCatch(classe,err)    \
CATCatch(classe,err)

// trace error (in catch bloc)
/**
 * @nodoc
 */
#define        TRACERR(err)            \
TRACE << "-> catch "<< err->GetName() << "(" << err->GetMessageText(1) << ")" << '\n';

// catch other
/**
 * @nodoc
 */
#define        CATVpmCatchOther        \
CATCatchOthers {        \
CATRethrow;             \
}

// rethrow
/**
 * @nodoc
 */
#define        CATVpmRethrow            \
CATRethrow

// end try bloc
/**
 * @nodoc
 */
#define CATVpmEndTry            \
CATEndTry

// return
/**
 * @nodoc
 */
extern ExportedByPLMPosBasTrace const char *PLMPosTrace_returns;
/** @nodoc */
extern ExportedByPLMPosBasTrace const char *PLMPosTrace_nl;

/** @nodoc */
# define        POS_TRACE_RETURN(value) \
do {*(__pos_trace_step._trace)<<PLMPosTrace_returns<<value<<PLMPosTrace_nl; \
        return value; } while(0)
/**
 * @nodoc
 */
# define        CATVpmReturn return


#ifdef _CATPOSTrace_
#ifndef CNEXT_CLIENT
// System
#include "CATTrace.h"


/** 
 * @nodoc
 * define trace name
 */
#define CATPOSTraceDefine(a) static CATTrace CATPOSTrace(#a,"CATPOSTrace",CATTraUnactivated);
/**
 * @nodoc
 * string
 */
#define POSTRACE_PUT(Message)      do {CATPOSTrace.TraPut(Message);} while (0)
/**
 * @nodoc
 * string + crlf
 */
#define POSTRACE_PUTLN(Message)    do {CATPOSTrace.TraPutLN(Message);} while (0)
/**
 * @nodoc
 * string + string + crlf
 */
#define POSTRACE_PUTLN2(Message1, Message2)    do {CATPOSTrace.TraPut(Message1);CATPOSTrace.TraPutLN(Message2);} while (0)
/**
 * @nodoc
 * string + hexa + crlf 
 */
#define POSTRACE_PUTXLN(Message,var)    do {CATPOSTrace.TraPutXLN(Message,var);} while (0)
/** 
 * @nodoc
 * string + float + crlf
 */
#define POSTRACE_PUTFLN(Message,var)    do {CATPOSTrace.TraPutFLN(Message,var);} while (0)
/** 
 * @nodoc
 * string + long + crlf
 */
#define POSTRACE_PUTLLN(Message,var)    do {CATPOSTrace.TraPutLN(Message,var);} while (0)
#else
/** nodoc */
#define CATPOSTraceDefine(a)
/** nodoc */
#define POSTRACE_PUT(Message)    
/** nodoc */
#define POSTRACE_PUTLN(Message) 
/** nodoc */
#define POSTRACE_PUTLN2(Message1, Message2) 
/** nodoc */
#define POSTRACE_PUTXLN(Message,var) 
/** nodoc */
#define POSTRACE_PUTFLN(Message,var)
/** nodoc */
#define POSTRACE_PUTLLN(Message,var)
#endif

/** nodoc */
#define PLMPosTraceDefine CATPOSTraceDefine
#endif

#endif
