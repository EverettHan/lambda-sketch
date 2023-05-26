/** ================================================================================ **/
/** WARNING: YWE 17:03:16 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
/** ================================================================================ **/
//-*-Mode: C++;-*-
#if __GNUG__ >= 2
#  pragma interface
#endif
# ifndef CoexContextTrace_H
# define CoexContextTrace_H
//
// COPYRIGHT DASSAULT SYSTEMES 2001
//
//======================================================================
// Identification:
// -------------- 
//    Owner    : YWE
//    Function : Headers of the procedures used for errors and traces
//    Use      : CATIA - Batch
//
//======================================================================
// Function:  Headers of procedures used for debug
// --------
//
/** 
 *  @level Protected 
 *  @usage U1
 */

#include "ExportedByCATDbProvider.h"
#include <stdio.h>
#include "CATTrace.h"
#include <string.h>

/**
 * Manages the CoexContextTrace Positional Count.<br>
 * @param iIncrementBy
 *			The incremental value.
 * @return 
 *			The incremented Positional Count.
 */
ExportedByCATDbProvider int CoexCtxRgIncr(int iIncrementBy);

extern ExportedByCATDbProvider CATTrace CoexContextTrace;

ExportedByCATDbProvider void _CDCCoexTraceEnter(const char* format,...);
ExportedByCATDbProvider void _CDCCoexTraceLeave(const char* format,...);
ExportedByCATDbProvider void _CDCCoexTraceWarning(const char* format,...);
ExportedByCATDbProvider void _CDCCoexTraceError(const char* format,...);
ExportedByCATDbProvider void _CDCCoexTraceLog(const char* format,...);


/**
 * Notice that all these macros are wrong (basic macro rule violation)
 * they should use  do { ... } while(0) pattern to force ';' and avoid macros hell bugs like:
 * if(a)
 * __ENTREE_COEXCTX(2,"toto")
 * else
 *  something
 * which does crazy things due to the invalid if in the macro expansion:
 *  if(a)
 *   if(CoexContextTrace.IsActive()) {...}
 *   else something
 */
#define __ENTREE_COEXCTX0(Level,Msg,...) if(CoexContextTrace.IsActive()) {_CDCCoexTraceEnter(Msg);}
#define __SORTIE_COEXCTX0(Level,Msg,...) if(CoexContextTrace.IsActive()) {_CDCCoexTraceLeave(Msg);}
#define __ERREUR_COEXCTX0(Level,Msg,...) if(CoexContextTrace.IsActive()) {_CDCCoexTraceError(Msg);}
#define __WARNING_COEXCTX0(Level,Msg,...) if(CoexContextTrace.IsActive()) {_CDCCoexTraceWarning(Msg);}
#define __PASSAGE_COEXCTX0(Level,Msg,...) if(CoexContextTrace.IsActive()) {_CDCCoexTraceLog(Msg);}

#define __ENTREE_COEXCTXX(Level,Msg,...) if(CoexContextTrace.IsActive()) {_CDCCoexTraceEnter(Msg,__VA_ARGS__);}
#define __SORTIE_COEXCTXX(Level,Msg,...) if(CoexContextTrace.IsActive()) {_CDCCoexTraceLeave(Msg,__VA_ARGS__);}
#define __ERREUR_COEXCTXX(Level,Msg,...) if(CoexContextTrace.IsActive()) {_CDCCoexTraceError(Msg,__VA_ARGS__);}
#define __WARNING_COEXCTXX(Level,Msg,...) if(CoexContextTrace.IsActive()) {_CDCCoexTraceWarning(Msg,__VA_ARGS__);}
#define __PASSAGE_COEXCTXX(Level,Msg,...) if(CoexContextTrace.IsActive()) {_CDCCoexTraceLog(Msg,__VA_ARGS__);}

/**
 * Prints the CoexContextTrace Message at function entry.
 * <br>Prints the CoexContextTrace Message 'Msg' at 'Level' while entering the function.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define ENTREE_COEXCTX( Level, Msg )    __ENTREE_COEXCTX0(Level,Msg)

/**
 * Prints the CoexContextTrace Message with one argument at function entry.
 * <br>Prints the CoexContextTrace Message 'Msg' at 'Level' while entering the function.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define ENTREE_COEXCTX_1( Level, Msg, Arg ) __ENTREE_COEXCTXX(Level,Msg,Arg)

/**
 * Prints the CoexContextTrace Message with two argument at function entry.
 * <br>Prints the CoexContextTrace Message 'Msg' at 'Level' while entering the function.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 * @param Arg2
 *   The additional argument to print with Message.
 */
#define ENTREE_COEXCTX_2( Level, Msg, Arg, Arg2 ) __ENTREE_COEXCTXX(Level,Msg,Arg,Arg2)

/**
 * Prints the CoexContextTrace Message with three argument at function entry.
 * <br>Prints the CoexContextTrace Message 'Msg' at 'Level' while entering the function.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 * @param Arg2
 *   The additional argument to print with Message.
 * @param Arg3
 *   The additional argument to print with Message.
 */
#define ENTREE_COEXCTX_3( Level, Msg, Arg, Arg2,Arg3 ) __ENTREE_COEXCTXX(Level,Msg,Arg,Arg2,Arg3)

/**
 * Prints the CoexContextTrace Message at function exit.
 * <br>Prints the CoexContextTrace Message 'Msg' at 'Level' while leaving the function.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define SORTIE_COEXCTX( Level, Msg ) __SORTIE_COEXCTX0(Level,Msg)


/**
 * Prints the CoexContextTrace Message with one argument at function exit.
 * <br>Prints the CoexContextTrace Message 'Msg' at 'Level' while leaving the function.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define SORTIE_COEXCTX_1( Level, Msg, Arg ) __SORTIE_COEXCTXX(Level,Msg,Arg)

/**
 * Prints the CoexContextTrace Message with two argument at function exit.
 * <br>Prints the CoexContextTrace Message 'Msg' at 'Level' while leaving the function.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 * @param Arg2
 *   The additional argument to print with Message.
 */
#define SORTIE_COEXCTX_2( Level, Msg, Arg, Arg2 ) __SORTIE_COEXCTXX(Level,Msg,Arg,Arg2)

/**
 * Prints the CoexContextTrace Message with two argument at function exit.
 * <br>Prints the CoexContextTrace Message 'Msg' at 'Level' while leaving the function.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 * @param Arg2
 *   The additional argument to print with Message.
 * @param Arg3
 *   Third argument to print with Message.
 */
#define SORTIE_COEXCTX_3( Level, Msg, Arg, Arg2, Arg3 ) __SORTIE_COEXCTXX(Level,Msg,Arg,Arg2, Arg3)

/**
 * Prints the CoexContextTrace ErrorMessage.
 * <br>Prints the CoexContextTrace ErrorMessage 'Msg' at 'Level'.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define ERREUR_COEXCTX( Level, Msg ) __ERREUR_COEXCTX0(Level, Msg)

/**
 * Prints the CoexContextTrace ErrorMessage with one argument.
 * <br>Prints the CoexContextTrace ErrorMessage 'Msg' at 'Level'.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define ERREUR_COEXCTX_1( Level, Msg, Arg ) __ERREUR_COEXCTXX(Level, Msg,Arg)


/**
 * Prints the CoexContextTrace ErrorMessage with two argument.
 * <br>Prints the CoexContextTrace ErrorMessage 'Msg' at 'Level'.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 * @param Arg2
 *   The additional argument to print with Message.
 */
#define ERREUR_COEXCTX_2( Level, Msg, Arg, Arg2 ) __ERREUR_COEXCTXX(Level, Msg,Arg,Arg2)


/**
 * Prints the CoexContextTrace Message in the function body.
 * <br>Prints the CoexContextTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define PASSAGE_COEXCTX( Level, Msg )  __PASSAGE_COEXCTX0(Level, Msg)


/**
 * Prints the CoexContextTrace Message with one argument in the function body.
 * <br>Prints the CoexContextTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define PASSAGE_COEXCTX_1( Level, Msg, Arg ) __PASSAGE_COEXCTXX(Level, Msg,Arg)


/**
 * Prints the CoexContextTrace Message with two arguments in the function body.
 * <br>Prints the CoexContextTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 * @param Arg2
 *   The additional argument to print with Message.
 */
#define PASSAGE_COEXCTX_2( Level, Msg, Arg, Arg2 ) __PASSAGE_COEXCTXX(Level, Msg,Arg,Arg2)


/**
 * Prints the CoexContextTrace Message with three arguments in the function body.
 * <br>Prints the CoexContextTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 * @param Arg2
 *   The additional argument to print with Message.
 * @param Arg3
 *   The additional argument to print with Message.
 */
#define PASSAGE_COEXCTX_3( Level, Msg, Arg, Arg2, Arg3 ) __PASSAGE_COEXCTXX(Level, Msg,Arg,Arg2,Arg3)

/**
 * Prints the CoexContextTrace Message with four arguments in the function body.
 * <br>Prints the CoexContextTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 * @param Arg2
 *   The additional argument to print with Message.
 * @param Arg3
 *   The additional argument to print with Message.
 * @param Arg4
 *   The additional argument to print with Message.
 */
#define PASSAGE_COEXCTX_4( Level, Msg, Arg, Arg2, Arg3, Arg4 ) __PASSAGE_COEXCTXX(Level, Msg,Arg,Arg2,Arg3,Arg4)


/**
 * Prints the CoexContextTrace WarningMessage.
 * <br>Prints the CoexContextTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define WARNING_COEXCTX( Level, Msg ) __WARNING_COEXCTX0(Level, Msg)

/**
 * Prints the CoexContextTrace WarningMessage with one argument.
 * <br>Prints the CoexContextTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define WARNING_COEXCTX_1( Level, Msg, Arg ) __WARNING_COEXCTXX(Level, Msg,Arg)


/**
 * Prints the CoexContextTrace WarningMessage with two argument.
 * <br>Prints the CoexContextTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 * @param Arg2
 *   The additional argument to print with Message.
 */
#define WARNING_COEXCTX_2( Level, Msg, Arg, Arg2 ) __WARNING_COEXCTXX(Level, Msg,Arg,Arg2)


/**
 * Prints the CoexContextTrace WarningMessage with three argument.
 * <br>Prints the CoexContextTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 * @param Arg2
 *   The additional argument to print with Message.
 * @param Arg3
 *   The additional argument to print with Message.
 */
#define WARNING_COEXCTX_3( Level, Msg, Arg, Arg2, Arg3 ) __WARNING_COEXCTXX(Level, Msg,Arg,Arg2,Arg3)
/**
 * Prints the CoexContextTrace WarningMessage with four argument.
 * <br>Prints the CoexContextTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CoexContextTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 * @param Arg2
 *   The additional argument to print with Message.
 * @param Arg3
 *   The additional argument to print with Message.
 */
#define WARNING_COEXCTX_4( Level, Msg, Arg, Arg2, Arg3, Arg4 ) __WARNING_COEXCTXX(Level, Msg,Arg,Arg2,Arg3,Arg4)

 /**
 * Dump the stack
 */
# endif
