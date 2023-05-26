/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
//-*-Mode: C++;-*-
#if __GNUG__ >= 2
#  pragma interface
#endif
# ifndef CheckRepTrace_H
# define CheckRepTrace_H
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

#include "ExportedByCATClnBase.h"
#include <stdio.h>
#include "CATTrace.h"
#include <string.h>

/**
 * Manages the CheckRepTrace Positional Count.<br>
 * @param iIncrementBy
 *			The incremental value.
 * @return 
 *			The incremented Positional Count.
 */
ExportedByCATClnBase int ChkRepRgIncr(int iIncrementBy);

extern ExportedByCATClnBase CATTrace CheckRepTrace;

ExportedByCATClnBase void _CDCChkRepTraceEnter(const char* format,...);
ExportedByCATClnBase void _CDCChkRepTraceLeave(const char* format,...);
ExportedByCATClnBase void _CDCChkRepTraceWarning(const char* format,...);
ExportedByCATClnBase void _CDCChkRepTraceError(const char* format,...);
ExportedByCATClnBase void _CDCChkRepTraceLog(const char* format,...);


/**
 * Notice that all these macros are wrong (basic macro rule violation)
 * they should use  do { ... } while(0) pattern to force ';' and avoid macros hell bugs like:
 * if(a)
 * __ENTREE_CHKREP(2,"toto")
 * else
 *  something
 * which does crazy things due to the invalid if in the macro expansion:
 *  if(a)
 *   if(CheckRepTrace.IsActive()) {...}
 *   else something
 */
#define __ENTREE_CHKREP0(Level,Msg,...) if(CheckRepTrace.IsActive()) {_CDCChkRepTraceEnter(Msg);}
#define __SORTIE_CHKREP0(Level,Msg,...) if(CheckRepTrace.IsActive()) {_CDCChkRepTraceLeave(Msg);}
#define __ERREUR_CHKREP0(Level,Msg,...) if(CheckRepTrace.IsActive()) {_CDCChkRepTraceError(Msg);}
#define __WARNING_CHKREP0(Level,Msg,...) if(CheckRepTrace.IsActive()) {_CDCChkRepTraceWarning(Msg);}
#define __PASSAGE_CHKREP0(Level,Msg,...) if(CheckRepTrace.IsActive()) {_CDCChkRepTraceLog(Msg);}

#define __ENTREE_CHKREPX(Level,Msg,...) if(CheckRepTrace.IsActive()) {_CDCChkRepTraceEnter(Msg,__VA_ARGS__);}
#define __SORTIE_CHKREPX(Level,Msg,...) if(CheckRepTrace.IsActive()) {_CDCChkRepTraceLeave(Msg,__VA_ARGS__);}
#define __ERREUR_CHKREPX(Level,Msg,...) if(CheckRepTrace.IsActive()) {_CDCChkRepTraceError(Msg,__VA_ARGS__);}
#define __WARNING_CHKREPX(Level,Msg,...) if(CheckRepTrace.IsActive()) {_CDCChkRepTraceWarning(Msg,__VA_ARGS__);}
#define __PASSAGE_CHKREPX(Level,Msg,...) if(CheckRepTrace.IsActive()) {_CDCChkRepTraceLog(Msg,__VA_ARGS__);}

/**
 * Prints the CheckRepTrace Message at function entry.
 * <br>Prints the CheckRepTrace Message 'Msg' at 'Level' while entering the function.<br>
 * It also manages the CheckRepTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define ENTREE_CHKREP( Level, Msg )    __ENTREE_CHKREP0(Level,Msg)

/**
 * Prints the CheckRepTrace Message with one argument at function entry.
 * <br>Prints the CheckRepTrace Message 'Msg' at 'Level' while entering the function.<br>
 * It also manages the CheckRepTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define ENTREE_CHKREP_1( Level, Msg, Arg ) __ENTREE_CHKREPX(Level,Msg,Arg)

/**
 * Prints the CheckRepTrace Message with two argument at function entry.
 * <br>Prints the CheckRepTrace Message 'Msg' at 'Level' while entering the function.<br>
 * It also manages the CheckRepTrace Counter.<br>
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
#define ENTREE_CHKREP_2( Level, Msg, Arg, Arg2 ) __ENTREE_CHKREPX(Level,Msg,Arg,Arg2)

/**
 * Prints the CheckRepTrace Message with three argument at function entry.
 * <br>Prints the CheckRepTrace Message 'Msg' at 'Level' while entering the function.<br>
 * It also manages the CheckRepTrace Counter.<br>
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
#define ENTREE_CHKREP_3( Level, Msg, Arg, Arg2,Arg3 ) __ENTREE_CHKREPX(Level,Msg,Arg,Arg2,Arg3)

/**
 * Prints the CheckRepTrace Message at function exit.
 * <br>Prints the CheckRepTrace Message 'Msg' at 'Level' while leaving the function.<br>
 * It also manages the CheckRepTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define SORTIE_CHKREP( Level, Msg ) __SORTIE_CHKREP0(Level,Msg)


/**
 * Prints the CheckRepTrace Message with one argument at function exit.
 * <br>Prints the CheckRepTrace Message 'Msg' at 'Level' while leaving the function.<br>
 * It also manages the CheckRepTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define SORTIE_CHKREP_1( Level, Msg, Arg ) __SORTIE_CHKREPX(Level,Msg,Arg)

/**
 * Prints the CheckRepTrace Message with two argument at function exit.
 * <br>Prints the CheckRepTrace Message 'Msg' at 'Level' while leaving the function.<br>
 * It also manages the CheckRepTrace Counter.<br>
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
#define SORTIE_CHKREP_2( Level, Msg, Arg, Arg2 ) __SORTIE_CHKREPX(Level,Msg,Arg,Arg2)


/**
 * Prints the CheckRepTrace ErrorMessage.
 * <br>Prints the CheckRepTrace ErrorMessage 'Msg' at 'Level'.<br>
 * It also manages the CheckRepTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define ERREUR_CHKREP( Level, Msg ) __ERREUR_CHKREP0(Level, Msg)

/**
 * Prints the CheckRepTrace ErrorMessage with one argument.
 * <br>Prints the CheckRepTrace ErrorMessage 'Msg' at 'Level'.<br>
 * It also manages the CheckRepTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define ERREUR_CHKREP_1( Level, Msg, Arg ) __ERREUR_CHKREPX(Level, Msg,Arg)


/**
 * Prints the CheckRepTrace ErrorMessage with two argument.
 * <br>Prints the CheckRepTrace ErrorMessage 'Msg' at 'Level'.<br>
 * It also manages the CheckRepTrace Counter.<br>
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
#define ERREUR_CHKREP_2( Level, Msg, Arg, Arg2 ) __ERREUR_CHKREPX(Level, Msg,Arg,Arg2)


/**
 * Prints the CheckRepTrace Message in the function body.
 * <br>Prints the CheckRepTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CheckRepTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define PASSAGE_CHKREP( Level, Msg )  __PASSAGE_CHKREP0(Level, Msg)


/**
 * Prints the CheckRepTrace Message with one argument in the function body.
 * <br>Prints the CheckRepTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CheckRepTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define PASSAGE_CHKREP_1( Level, Msg, Arg ) __PASSAGE_CHKREPX(Level, Msg,Arg)


/**
 * Prints the CheckRepTrace Message with two arguments in the function body.
 * <br>Prints the CheckRepTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CheckRepTrace Counter.<br>
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
#define PASSAGE_CHKREP_2( Level, Msg, Arg, Arg2 ) __PASSAGE_CHKREPX(Level, Msg,Arg,Arg2)


/**
 * Prints the CheckRepTrace Message with three arguments in the function body.
 * <br>Prints the CheckRepTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CheckRepTrace Counter.<br>
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
#define PASSAGE_CHKREP_3( Level, Msg, Arg, Arg2, Arg3 ) __PASSAGE_CHKREPX(Level, Msg,Arg,Arg2,Arg3)

/**
 * Prints the CheckRepTrace Message with four arguments in the function body.
 * <br>Prints the CheckRepTrace Message 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CheckRepTrace Counter.<br>
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
#define PASSAGE_CHKREP_4( Level, Msg, Arg, Arg2, Arg3, Arg4 ) __PASSAGE_CHKREPX(Level, Msg,Arg,Arg2,Arg3,Arg4)


/**
 * Prints the CheckRepTrace WarningMessage.
 * <br>Prints the CheckRepTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CheckRepTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 */
#define WARNING_CHKREP( Level, Msg ) __WARNING_CHKREP0(Level, Msg)

/**
 * Prints the CheckRepTrace WarningMessage with one argument.
 * <br>Prints the CheckRepTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CheckRepTrace Counter.<br>
 * Use this macro in the class source (.cpp) file.<br>
 * Do not end it with a semicolon.<br>
 * @param Level
 *   The indicator for managing the positioning of Trace Message.
 * @param Msg
 *   The Message to print.
 * @param Arg
 *   The argument to print with Message.
 */
#define WARNING_CHKREP_1( Level, Msg, Arg ) __WARNING_CHKREPX(Level, Msg,Arg)


/**
 * Prints the CheckRepTrace WarningMessage with two argument.
 * <br>Prints the CheckRepTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CheckRepTrace Counter.<br>
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
#define WARNING_CHKREP_2( Level, Msg, Arg, Arg2 ) __WARNING_CHKREPX(Level, Msg,Arg,Arg2)


/**
 * Prints the CheckRepTrace WarningMessage with three argument.
 * <br>Prints the CheckRepTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CheckRepTrace Counter.<br>
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
#define WARNING_CHKREP_3( Level, Msg, Arg, Arg2, Arg3 ) __WARNING_CHKREPX(Level, Msg,Arg,Arg2,Arg3)
/**
 * Prints the CheckRepTrace WarningMessage with four argument.
 * <br>Prints the CheckRepTrace WarningMessage 'Msg' at 'Level' while passing through function.<br>
 * It also manages the CheckRepTrace Counter.<br>
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
#define WARNING_CHKREP_4( Level, Msg, Arg, Arg2, Arg3, Arg4 ) __WARNING_CHKREPX(Level, Msg,Arg,Arg2,Arg3,Arg4)

 /**
 * Dump the stack
 */
# endif
