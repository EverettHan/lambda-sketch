#ifndef CATCDSVersMacros_H
#define CATCDSVersMacros_H

#define VERSIONING_V2
#ifdef VERSIONING_V2

// internel level = <external level>*65536 + <external hf level> (on 4 bytes)
// 2 high bytes -> external CDS level
// 2 low bytes  -> external CDS HF level
#define CDS_INTERNAL_LEVEL(X,Y)   ((((unsigned int)(X)<<16) & 0xFFFF0000) + ((unsigned int)(Y) & 0xFFFF))
#define CDS_EXTERNAL_LEVEL(X)     (((unsigned int)(X)>>16) & 0xFFFF)
#define CDS_EXTERNAL_HF_LEVEL(X)  ((unsigned int)(X) & 0xFFFF)

#else // old version

// internal level = external level (no hf level)
#define CDS_INTERNAL_LEVEL(X,Y)   X
#define CDS_EXTERNAL_LEVEL(X)     X
#define CDS_EXTERNAL_HF_LEVEL(X)  0

#endif

#define CDS_INTERNAL_OPEN_LEVEL   GetGlobalParameters().GetCDSFullOpenConfigurationLevel()

#endif
