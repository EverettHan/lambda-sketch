############################################################################
# @CAA2Required                                                            #
# DON T DIRECTLY INCLUDE THIS IMAKEFILE IN YOUR APPLICATION                #
# IT IS REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME #
############################################################################
# !!! DO NOT MOVE THIS HEADER OUT OF THE PUBLIC INTERFACES FOLDER !!! 

# Regroup System build options for the C++ langage
# !!! WARNING !!! DO NOT USE OS sections in this file (OS = XXX), which is designed to be included in other Imakefiles
# Directives can be overriden in sub-Imakefiles (for e.g. LOCAL_CCFLAGS etc)

# Enable C++ exceptions (if not already the default setting)
CXX_EXCEPTION =
# CXX_NOPERMISSIVE: enforce C++ standard conformance. Do not remove!!!
CXX_NOPERMISSIVE = YES

# Warning promote: promote a set of warnings to compile errors
# There has been compiler warnings false positives due to Sanitizer instrumentation (especially when different Sanitizers are combined)
# Solution: DO NOT USE CATSystemWarningPromote on Sanitized builds! (currently asan_linux_a64 & tsan_linux_a64)
# set CXX_WARNINGPROMOTE only if ( MKMK_GCC_SANITIZER does not exist or is empty )
CXX_WARNINGPROMOTE=$(MKMK_GCC_SANITIZER:%-"CATSystemWarningPromote.h")
# CXX_WARNINGPROMOTE = CATSystemWarningPromote.h

#if os Windows
# DSY_SYS_LOCAL_CCFLAGS =
DSY_SYS_LOCAL_POST_CCFLAGS = /D "NOMINMAX"
# DSY_SYS_LOCAL_LDFLAGS = 

#if (defined MK_MSCVER)
#if (MK_MSCVER >= 1932)
# Visual Studio 2022

# Turn specific linker warnings into errors:
#  - LNK4006: disallow multiple symbol definitions that can lead to Undefined Behavior and cause tricky runtime bugs, 
#    for e.g., attempts to register different functions for the same "CATImplementCondition"...
#    (matches default GCC behavior on Linux)
# Syntax: /WX:warning[,warning]
DSY_SYS_LOCAL_LDFLAGS = /WX:4006

#endif
#endif


# if intel_a
#   32 bits Windows
# else 
#   64 bits Windows: win_b64 / win_csa64 etc
# endif

#else

# DSY_SYS_LOCAL_CCFLAGS =
# DSY_SYS_LOCAL_POST_CCFLAGS = 
# DSY_SYS_LOCAL_LDFLAGS = 

# if os Linux
# elif os Android
# elif os iOS
# endif

#endif


# At this point, our custom variables have been set, with potential per-OS customizations
LOCAL_CCFLAGS = $(DSY_SYS_LOCAL_CCFLAGS)
LOCAL_POST_CCFLAGS = $(DSY_SYS_LOCAL_POST_CCFLAGS)
LOCAL_LDFLAGS = $(DSY_SYS_LOCAL_LDFLAGS)
