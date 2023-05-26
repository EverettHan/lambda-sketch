/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/

#if !defined(__ESKernelLib_h)
#define __ESKernelLib_h

#include "DSYExport.h"

#ifdef __ECMAScriptKernel
# define ESKERNEL_API DSYExport
#else
# define ESKERNEL_API DSYImport
#endif

#define ESINLINE inline

#if defined(_MSC_VER) && (_MSC_VER >= 1500)
# define ES_DEPRECATED_IMPL(msg, decl) __declspec(deprecated(msg)) decl
#else
# define ES_DEPRECATED_IMPL(msg, decl) decl
#endif

#define ES_DEPRECATED(date, msg, decl) ES_DEPRECATED_IMPL("\n" \
                                                          "###############################################################################\n" \
                                                          "#############################  ECMAScriptEngine  ##############################\n" \
                                                          "################################  DEPRECATED  #################################\n" \
                                                          "###############################################################################\n" \
                                                          "#########################  please migrate your code  ##########################\n" \
                                                          "#######################  deprecated since " date "  #########################\n" \
                                                          "###############################################################################\n" \
                                                          "##\n" \
                                                          "## " msg "\n" \
                                                          "##\n" \
                                                          "###############################################################################\n" \
                                                          , decl)

#include <stdarg.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

#endif // __ESKernelLib_h



