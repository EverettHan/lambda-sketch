/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
//-*-Mode: C++;-*-
#if __GNUG__ >= 2
#  pragma interface
#endif
# ifndef BatchTrace_H
# define BatchTrace_H
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
 * Manages the BatchTrace Positional Count.<br>
 * @param iIncrementBy
 *			The incremental value.
 * @return 
 *			The incremented Positional Count.
 */
ExportedByDataAdmin int BatchRgIncr(int iIncrementBy);

extern ExportedByDataAdmin CATTrace BatchTrace;

ExportedByDataAdmin void _CDCBatchTraceEnter(const char* format,...);
ExportedByDataAdmin void _CDCBatchTraceLeave(const char* format,...);
ExportedByDataAdmin void _CDCBatchTraceWarning(const char* format,...);
ExportedByDataAdmin void _CDCBatchTraceError(const char* format,...);
ExportedByDataAdmin void _CDCBatchTraceLog(const char* format,...);


/**
 * Notice that all these macros are wrong (basic macro rule violation)
 * they should use  do { ... } while(0) pattern to force ';' and avoid macros hell bugs like:
 * if(a)
 * __ENTREE_SEQ(2,"toto")
 * else
 *  something
 * which does crazy things due to the invalid if in the macro expansion:
 *  if(a)
 *   if(BatchTrace.IsActive()) {...}
 *   else something
 */
#define __ENTREE_SEQ0(Level,Msg,...) if(BatchTrace.IsActive()) {_CDCBatchTraceEnter(Msg);}
#define __SORTIE_SEQ0(Level,Msg,...) if(BatchTrace.IsActive()) {_CDCBatchTraceLeave(Msg);}
#define __ERREUR_SEQ0(Level,Msg,...) if(BatchTrace.IsActive()) {_CDCBatchTraceError(Msg);}
#define __WARNING_SEQ0(Level,Msg,...) if(BatchTrace.IsActive()) {_CDCBatchTraceWarning(Msg);}
#define __PASSAGE_SEQ0(Level,Msg,...) if(BatchTrace.IsActive()) {_CDCBatchTraceLog(Msg);}

#define __ENTREE_SEQX(Level,Msg,...) if(BatchTrace.IsActive()) {_CDCBatchTraceEnter(Msg,__VA_ARGS__);}
#define __SORTIE_SEQX(Level,Msg,...) if(BatchTrace.IsActive()) {_CDCBatchTraceLeave(Msg,__VA_ARGS__);}
#define __ERREUR_SEQX(Level,Msg,...) if(BatchTrace.IsActive()) {_CDCBatchTraceError(Msg,__VA_ARGS__);}
#define __WARNING_SEQX(Level,Msg,...) if(BatchTrace.IsActive()) {_CDCBatchTraceWarning(Msg,__VA_ARGS__);}
#define __PASSAGE_SEQX(Level,Msg,...) if(BatchTrace.IsActive()) {_CDCBatchTraceLog(Msg,__VA_ARGS__);}

/**
 * Prints the BatchTrace Message at function entry.
 * <br>Prints the BatchTrace Message 'Msg' at 'Level' while entering the function.<br>
 * It also manages the BatchTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define ENTREE_SEQ( Level, Msg )    __ENTREE_SEQ0(Level,Msg)

/**
 * Prints the BatchTrace Message with one argument at function entry.
 * <br>Prints the BatchTrace Message 'Msg' at 'Level' while entering the function.<br>
 * It also manages the BatchTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define ENTREE_SEQ_1( Level, Msg, Arg ) __ENTREE_SEQX(Level,Msg,Arg)

/**
 * Prints the BatchTrace Message with two argument at function entry.
 * <br>Prints the BatchTrace Message 'Msg' at 'Level' while entering the function.<br>
 * It also manages the BatchTrace Counter.<br>
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
#define ENTREE_SEQ_2( Level, Msg, Arg, Arg2 ) __ENTREE_SEQX(Level,Msg,Arg,Arg2)

/**
 * Prints the BatchTrace Message with three argument at function entry.
 * <br>Prints the BatchTrace Message 'Msg' at 'Level' while entering the function.<br>
 * It also manages the BatchTrace Counter.<br>
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
#define ENTREE_SEQ_3( Level, Msg, Arg, Arg2,Arg3 ) __ENTREE_SEQX(Level,Msg,Arg,Arg2,Arg3)

/**
 * Prints the BatchTrace Message at function exit.
 * <br>Prints the BatchTrace Message 'Msg' at 'Level' while leaving the function.<br>
 * It also manages the BatchTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define SORTIE_SEQ( Level, Msg ) __SORTIE_SEQ0(Level,Msg)


/**
 * Prints the BatchTrace Message with one argument at function exit.
 * <br>Prints the BatchTrace Message 'Msg' at 'Level' while leaving the function.<br>
 * It also manages the BatchTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define SORTIE_SEQ_1( Level, Msg, Arg ) __SORTIE_SEQX(Level,Msg,Arg)

/**
 * Prints the BatchTrace Message with two argument at function exit.
 * <br>Prints the BatchTrace Message 'Msg' at 'Level' while leaving the function.<br>
 * It also manages the BatchTrace Counter.<br>
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
#define SORTIE_SEQ_2( Level, Msg, Arg, Arg2 ) __SORTIE_SEQX(Level,Msg,Arg,Arg2)


/**
 * Prints the BatchTrace ErrorMessage.
 * <br>Prints the BatchTrace ErrorMessage 'Msg' at 'Level'.<br>
 * It also manages the BatchTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define ERREUR_SEQ( Level, Msg ) __ERREUR_SEQ0(Level, Msg)

/**
 * Prints the BatchTrace ErrorMessage with one argument.
 * <br>Prints the BatchTrace ErrorMessage 'Msg' at 'Level'.<br>
 * It also manages the BatchTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define ERREUR_SEQ_1( Level, Msg, Arg ) __ERREUR_SEQX(Level, Msg,Arg)


/**
 * Prints the BatchTrace ErrorMessage with two argument.
 * <br>Prints the BatchTrace ErrorMessage 'Msg' at 'Level'.<br>
 * It also manages the BatchTrace Counter.<br>
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
#define ERREUR_SEQ_2( Level, Msg, Arg, Arg2 ) __ERREUR_SEQX(Level, Msg,Arg,Arg2)


/**
 * Prints the BatchTrace Message in the function body.
 * <br>Prints the BatchTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define PASSAGE_SEQ( Level, Msg )  __PASSAGE_SEQ0(Level, Msg)


/**
 * Prints the BatchTrace Message with one argument in the function body.
 * <br>Prints the BatchTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define PASSAGE_SEQ_1( Level, Msg, Arg ) __PASSAGE_SEQX(Level, Msg,Arg)


/**
 * Prints the BatchTrace Message with two arguments in the function body.
 * <br>Prints the BatchTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchTrace Counter.<br>
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
#define PASSAGE_SEQ_2( Level, Msg, Arg, Arg2 ) __PASSAGE_SEQX(Level, Msg,Arg,Arg2)


/**
 * Prints the BatchTrace Message with three arguments in the function body.
 * <br>Prints the BatchTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchTrace Counter.<br>
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
#define PASSAGE_SEQ_3( Level, Msg, Arg, Arg2, Arg3 ) __PASSAGE_SEQX(Level, Msg,Arg,Arg2,Arg3)

/**
 * Prints the BatchTrace Message with four arguments in the function body.
 * <br>Prints the BatchTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchTrace Counter.<br>
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
#define PASSAGE_SEQ_4( Level, Msg, Arg, Arg2, Arg3, Arg4 ) __PASSAGE_SEQX(Level, Msg,Arg,Arg2,Arg3,Arg4)


/**
 * Prints the BatchTrace WarningMessage.
 * <br>Prints the BatchTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define WARNING_SEQ( Level, Msg ) __WARNING_SEQ0(Level, Msg)

/**
 * Prints the BatchTrace WarningMessage with one argument.
 * <br>Prints the BatchTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define WARNING_SEQ_1( Level, Msg, Arg ) __WARNING_SEQX(Level, Msg,Arg)


/**
 * Prints the BatchTrace WarningMessage with two argument.
 * <br>Prints the BatchTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchTrace Counter.<br>
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
#define WARNING_SEQ_2( Level, Msg, Arg, Arg2 ) __WARNING_SEQX(Level, Msg,Arg,Arg2)


/**
 * Prints the BatchTrace WarningMessage with three argument.
 * <br>Prints the BatchTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchTrace Counter.<br>
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
#define WARNING_SEQ_3( Level, Msg, Arg, Arg2, Arg3 ) __WARNING_SEQX(Level, Msg,Arg,Arg2,Arg3)
/**
 * Prints the BatchTrace WarningMessage with four argument.
 * <br>Prints the BatchTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the BatchTrace Counter.<br>
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
#define WARNING_SEQ_4( Level, Msg, Arg, Arg2, Arg3, Arg4 ) __WARNING_SEQX(Level, Msg,Arg,Arg2,Arg3,Arg4)

 /**
 * Dump the stack
 */
 ExportedByDataAdmin void BatchStack() ;
# endif
