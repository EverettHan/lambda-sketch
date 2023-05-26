/** ******************************************************************************** **/
/** WARNING: YWE 21:08:17 SINGLE-CODE 2016x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
/** ******************************************************************************** **/
//-*-Mode: C++;-*-
#if __GNUG__ >= 2
#  pragma interface
#endif
# ifndef BatchVersionTrace_H
# define BatchVersionTrace_H
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

#include "ExportedByDataAdmin.h"
#include <stdio.h>
#include "CATTrace.h"
#include <string.h>

/**
 * Manages the BatchVersionTrace Positional Count.<br>
 * @param iIncrementBy
 *			The incremental value.
 * @return 
 *			The incremented Positional Count.
 */
ExportedByDataAdmin int BatchVersRgIncr(int iIncrementBy);

extern ExportedByDataAdmin CATTrace BatchVersionTrace;

ExportedByDataAdmin void _CDCBatchVersionTraceEnter(const char* format,...);
ExportedByDataAdmin void _CDCBatchVersionTraceLeave(const char* format,...);
ExportedByDataAdmin void _CDCBatchVersionTraceWarning(const char* format,...);
ExportedByDataAdmin void _CDCBatchVersionTraceError(const char* format,...);
ExportedByDataAdmin void _CDCBatchVersionTraceLog(const char* format,...);


/**
 * Notice that all these macros are wrong (basic macro rule violation)
 * they should use  do { ... } while(0) pattern to force ';' and avoid macros hell bugs like:
 * if(a)
 * __ENTREE_VERS(2,"toto")
 * else
 *  something
 * which does crazy things due to the invalid if in the macro expansion:
 *  if(a)
 *   if(BatchVersionTrace.IsActive()) {...}
 *   else something
 */
#define __ENTREE_VERS0(Level,Msg,...) if(BatchVersionTrace.IsActive()) {_CDCBatchVersionTraceEnter(Msg);}
#define __SORTIE_VERS0(Level,Msg,...) if(BatchVersionTrace.IsActive()) {_CDCBatchVersionTraceLeave(Msg);}
#define __ERREUR_VERS0(Level,Msg,...) if(BatchVersionTrace.IsActive()) {_CDCBatchVersionTraceError(Msg);}
#define __WARNING_VERS0(Level,Msg,...) if(BatchVersionTrace.IsActive()) {_CDCBatchVersionTraceWarning(Msg);}
#define __PASSAGE_VERS0(Level,Msg,...) if(BatchVersionTrace.IsActive()) {_CDCBatchVersionTraceLog(Msg);}

#define __ENTREE_VERSX(Level,Msg,...) if(BatchVersionTrace.IsActive()) {_CDCBatchVersionTraceEnter(Msg,__VA_ARGS__);}
#define __SORTIE_VERSX(Level,Msg,...) if(BatchVersionTrace.IsActive()) {_CDCBatchVersionTraceLeave(Msg,__VA_ARGS__);}
#define __ERREUR_VERSX(Level,Msg,...) if(BatchVersionTrace.IsActive()) {_CDCBatchVersionTraceError(Msg,__VA_ARGS__);}
#define __WARNING_VERSX(Level,Msg,...) if(BatchVersionTrace.IsActive()) {_CDCBatchVersionTraceWarning(Msg,__VA_ARGS__);}
#define __PASSAGE_VERSX(Level,Msg,...) if(BatchVersionTrace.IsActive()) {_CDCBatchVersionTraceLog(Msg,__VA_ARGS__);}

/**
 * Prints the BatchVersionTrace Message at function entry.
 * <br>Prints the BatchVersionTrace Message 'Msg' at 'Level' while entering the function.<br>
 * It also manages the BatchVersionTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define ENTREE_VERS( Level, Msg )    __ENTREE_VERS0(Level,Msg)

/**
 * Prints the BatchVersionTrace Message with one argument at function entry.
 * <br>Prints the BatchVersionTrace Message 'Msg' at 'Level' while entering the function.<br>
 * It also manages the BatchVersionTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define ENTREE_VERS_1( Level, Msg, Arg ) __ENTREE_VERSX(Level,Msg,Arg)

/**
 * Prints the BatchVersionTrace Message with two argument at function entry.
 * <br>Prints the BatchVersionTrace Message 'Msg' at 'Level' while entering the function.<br>
 * It also manages the BatchVersionTrace Counter.<br>
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
#define ENTREE_VERS_2( Level, Msg, Arg, Arg2 ) __ENTREE_VERSX(Level,Msg,Arg,Arg2)

/**
 * Prints the BatchVersionTrace Message with three argument at function entry.
 * <br>Prints the BatchVersionTrace Message 'Msg' at 'Level' while entering the function.<br>
 * It also manages the BatchVersionTrace Counter.<br>
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
#define ENTREE_VERS_3( Level, Msg, Arg, Arg2,Arg3 ) __ENTREE_VERSX(Level,Msg,Arg,Arg2,Arg3)

/**
 * Prints the BatchVersionTrace Message at function exit.
 * <br>Prints the BatchVersionTrace Message 'Msg' at 'Level' while leaving the function.<br>
 * It also manages the BatchVersionTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define SORTIE_VERS( Level, Msg ) __SORTIE_VERS0(Level,Msg)


/**
 * Prints the BatchVersionTrace Message with one argument at function exit.
 * <br>Prints the BatchVersionTrace Message 'Msg' at 'Level' while leaving the function.<br>
 * It also manages the BatchVersionTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define SORTIE_VERS_1( Level, Msg, Arg ) __SORTIE_VERSX(Level,Msg,Arg)

/**
 * Prints the BatchVersionTrace Message with two argument at function exit.
 * <br>Prints the BatchVersionTrace Message 'Msg' at 'Level' while leaving the function.<br>
 * It also manages the BatchVersionTrace Counter.<br>
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
#define SORTIE_VERS_2( Level, Msg, Arg, Arg2 ) __SORTIE_VERSX(Level,Msg,Arg,Arg2)


/**
 * Prints the BatchVersionTrace ErrorMessage.
 * <br>Prints the BatchVersionTrace ErrorMessage 'Msg' at 'Level'.<br>
 * It also manages the BatchVersionTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define ERREUR_VERS( Level, Msg ) __ERREUR_VERS0(Level, Msg)

/**
 * Prints the BatchVersionTrace ErrorMessage with one argument.
 * <br>Prints the BatchVersionTrace ErrorMessage 'Msg' at 'Level'.<br>
 * It also manages the BatchVersionTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define ERREUR_VERS_1( Level, Msg, Arg ) __ERREUR_VERSX(Level, Msg,Arg)


/**
 * Prints the BatchVersionTrace ErrorMessage with two argument.
 * <br>Prints the BatchVersionTrace ErrorMessage 'Msg' at 'Level'.<br>
 * It also manages the BatchVersionTrace Counter.<br>
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
#define ERREUR_VERS_2( Level, Msg, Arg, Arg2 ) __ERREUR_VERSX(Level, Msg,Arg,Arg2)


/**
 * Prints the BatchVersionTrace Message in the function body.
 * <br>Prints the BatchVersionTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchVersionTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define PASSAGE_VERS( Level, Msg )  __PASSAGE_VERS0(Level, Msg)


/**
 * Prints the BatchVersionTrace Message with one argument in the function body.
 * <br>Prints the BatchVersionTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchVersionTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define PASSAGE_VERS_1( Level, Msg, Arg ) __PASSAGE_VERSX(Level, Msg,Arg)


/**
 * Prints the BatchVersionTrace Message with two arguments in the function body.
 * <br>Prints the BatchVersionTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchVersionTrace Counter.<br>
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
#define PASSAGE_VERS_2( Level, Msg, Arg, Arg2 ) __PASSAGE_VERSX(Level, Msg,Arg,Arg2)


/**
 * Prints the BatchVersionTrace Message with three arguments in the function body.
 * <br>Prints the BatchVersionTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchVersionTrace Counter.<br>
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
#define PASSAGE_VERS_3( Level, Msg, Arg, Arg2, Arg3 ) __PASSAGE_VERSX(Level, Msg,Arg,Arg2,Arg3)

/**
 * Prints the BatchVersionTrace Message with four arguments in the function body.
 * <br>Prints the BatchVersionTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchVersionTrace Counter.<br>
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
#define PASSAGE_VERS_4( Level, Msg, Arg, Arg2, Arg3, Arg4 ) __PASSAGE_VERSX(Level, Msg,Arg,Arg2,Arg3,Arg4)


/**
 * Prints the BatchVersionTrace WarningMessage.
 * <br>Prints the BatchVersionTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchVersionTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define WARNING_VERS( Level, Msg ) __WARNING_VERS0(Level, Msg)

/**
 * Prints the BatchVersionTrace WarningMessage with one argument.
 * <br>Prints the BatchVersionTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchVersionTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define WARNING_VERS_1( Level, Msg, Arg ) __WARNING_VERSX(Level, Msg,Arg)


/**
 * Prints the BatchVersionTrace WarningMessage with two argument.
 * <br>Prints the BatchVersionTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchVersionTrace Counter.<br>
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
#define WARNING_VERS_2( Level, Msg, Arg, Arg2 ) __WARNING_VERSX(Level, Msg,Arg,Arg2)


/**
 * Prints the BatchVersionTrace WarningMessage with three argument.
 * <br>Prints the BatchVersionTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchVersionTrace Counter.<br>
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
#define WARNING_VERS_3( Level, Msg, Arg, Arg2, Arg3 ) __WARNING_VERSX(Level, Msg,Arg,Arg2,Arg3)
/**
 * Prints the BatchVersionTrace WarningMessage with four argument.
 * <br>Prints the BatchVersionTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchVersionTrace Counter.<br>
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
#define WARNING_VERS_4( Level, Msg, Arg, Arg2, Arg3, Arg4 ) __WARNING_VERSX(Level, Msg,Arg,Arg2,Arg3,Arg4)

 /**
 * Dump the stack
 */
# endif
