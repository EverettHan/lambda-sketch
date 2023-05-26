# !!! WARNING CAA: cannot be included safely as-is for modules exposed in CAA !!!
# Regroup specific build options for the C++/CLI langage (Windows)
# Inherit from the C++ template:
##########################################################################
#include "SystemTS/PublicInterfaces/DSYSysMakeFileCxx.mk"
##########################################################################
CLR = YES

#if os Windows

BUILD = YES
CPP_EXCEPT=/EHa   # Need to override Native exceptions option for CLR modules
# Unfortunetaly, "C++/CLI mode does not support C++ versions newer than C++17", dixit Microsoft
# Moreover, at this time, Mkmk does not support the "CXX_NOPERMISSIVE" directive for managed C++ code (cf. _MKBT_MANAGED), 
# hence the need for the explicit flag "/permissive-"
LOCAL_POST_CCFLAGS = $(DSY_SYS_LOCAL_POST_CCFLAGS) /permissive- /Zc:twoPhase-

#else
BUILD = NO
#endif
