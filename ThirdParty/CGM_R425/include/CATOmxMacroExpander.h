#ifndef __CATOmxMacroExpander_h__
#define __CATOmxMacroExpander_h__

/** Make the macro stringization operator (#) work with macro. */
#define CATOmxMacroExpandString(a) CATOmxMacroExpandStringAgain(a)
/** Make the macro stringization operator (#) work with macro. */
#define CATOmxMacroExpandStringAgain(a) #a

/** Module name _MK_MODNAME_ as a c-string. */
#define CATOmxModuleString CATOmxMacroExpandString(_MK_MODNAME_)
/** Framework name _MK_FWNAME_ as a c-string. */
#define CATOmxFWString CATOmxMacroExpandString(_MK_FWNAME_)

#endif
