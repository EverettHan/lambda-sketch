
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
// 
// CATELFTraceServices :
// 
//=============================================================================
// Usage Notes : Manage Traces for the listing
//=============================================================================
// Dec. 98       Creation                        Anne-Sophie Taillandier
//=============================================================================

#ifndef CATELFTraceServices_h
#define CATELFTraceServices_h

#include "CATTrace.h"
#include "CATTraMacro.h"
#include "CATELFMathKernel.h"
#include "CATElfListingServices.h"

// Definition de la trace pour le listing
extern ExportedByCATELFMathKernel CATTrace Tra_ELFPrint;
extern ExportedByCATELFMathKernel CATTrace Tra_ELFCompute;
extern ExportedByCATELFMathKernel CATTrace Tra_ELFDefine;
extern ExportedByCATELFMathKernel CATTrace Tra_ELFStorage;
extern ExportedByCATELFMathKernel CATTrace Tra_ELFAcquire;
extern ExportedByCATELFMathKernel CATTrace Tra_ELFOutput;
extern ExportedByCATELFMathKernel CATTrace Tra_ELFInfra;
extern ExportedByCATELFMathKernel CATTrace Tra_ELFStorageLink;
extern ExportedByCATELFMathKernel CATTrace Tra_ELFError;
extern ExportedByCATELFMathKernel CATTrace Tra_ELFCpuElapse; 


// Fonction de mise a jour de la trace (activated ou unactivated)
void ExportedByCATELFMathKernel CATELFTraceState(const char name[],int Etat);

// Fonction de localisation du fichier de trace
//void ExportedByCATELFMathKernel CATELFTraceFile(const char name[],const char* TraceFile);

// Fonction de localisation du directory du fichier de trace
//void ExportedByCATELFMathKernel CATELFTraceDirectory(const char name[],const char* TraceDir);

// Macro activation
#define CATELFACTIV(name, mode) CATELFTraceState(name, mode);

// JUP : Listing Redirection
// Macro pour ecrire une chaine de caractere
#define CATELFPRINT_ELFPrint( indent, msg ) \
{                                           \
  CATElfListingRedirDecl;                   \
  CATElfListingRedirStart;                  \
  TRA_LEVEL_IN_USED ( ELFPrint, indent );   \
  TRAWRITE ( ELFPrint, msg );               \
  CATElfListingRedirEnd;                    \
}

#ifndef CNEXT_CLIENT
#define CATELFPRINT_ELFOutput(indent, msg) \
{                                            \
   TRA_LEVEL_IN_USED(ELFOutput, indent);     \
   TRAWRITE(ELFOutput, msg);               \
}
#else
#define CATELFPRINT_ELFOutput(indent, msg)
#endif

#ifndef CNEXT_CLIENT
#define CATELFPRINT_ELFCompute(indent, msg) \
{                                            \
   TRA_LEVEL_IN_USED(ELFCompute, indent);     \
   TRAWRITE(ELFCompute, msg);               \
}
#else
#define CATELFPRINT_ELFCompute(indent, msg)
#endif

#ifndef CNEXT_CLIENT
#define CATELFPRINT_ELFDefine(indent, msg) \
{                                            \
   TRA_LEVEL_IN_USED(ELFDefine, indent);     \
   TRAWRITE(ELFDefine, msg);               \
}
#else
#define CATELFPRINT_ELFDefine(indent, msg)
#endif

#ifndef CNEXT_CLIENT
#define CATELFPRINT_ELFStorage(indent, msg) \
{                                            \
   TRA_LEVEL_IN_USED(ELFStorage, indent);     \
   TRAWRITE(ELFStorage, msg);               \
}
#else
#define CATELFPRINT_ELFStorage(indent, msg)
#endif

#ifndef CNEXT_CLIENT
#define CATELFPRINT_ELFAcquire(indent, msg) \
{                                            \
   TRA_LEVEL_IN_USED(ELFAcquire, indent);     \
   TRAWRITE(ELFAcquire, msg);               \
}
#else
#define CATELFPRINT_ELFAcquire(indent, msg)
#endif

#ifndef CNEXT_CLIENT
#define CATELFPRINT_ELFInfra(indent, msg) \
{                                            \
   TRA_LEVEL_IN_USED(ELFInfra, indent);     \
   TRAWRITE(ELFInfra, msg);               \
}
#else
#define CATELFPRINT_ELFInfra(indent, msg)
#endif

#ifndef CNEXT_CLIENT
#define CATELFPRINT_ELFStorageLink(indent, msg) \
{                                            \
   TRA_LEVEL_IN_USED(ELFStorageLink, indent);     \
   TRAWRITE(ELFStorageLink, msg);               \
}
#else
#define CATELFPRINT_ELFStorageLink(indent, msg)
#endif

#ifndef CNEXT_CLIENT
#define CATELFPRINT_ELFCpuElapse(indent, msg) \
{                                            \
   TRA_LEVEL_IN_USED(ELFCpuElapse, indent);     \
   TRAWRITE(ELFCpuElapse, msg);               \
}
#else
#define CATELFPRINT_ELFCpuElapse(indent, msg)
#endif

#ifndef CNEXT_CLIENT
#define CATELFPRINT_ELFError(indent, msg) \
{                                            \
   TRA_LEVEL_IN_USED(ELFError, indent);     \
   TRAWRITE(ELFError, msg);               \
} 
#else
#define CATELFPRINT_ELFError(indent, msg)
#endif

// Macro pour ecrire une chaine de caractere precedee d un passage a la ligne
#define CATELFPRINT(name,indent, msg) CATELFPRINT_##name(indent, msg)

// JUP : Listing Redirection
#ifndef CNEXT_CLIENT
#define CATELFPRINTI( name, indent, msg, var ) \
{                                              \
  if ( !strcmp ( #name, "ELFPrint" ) )         \
  {                                            \
    CATElfListingRedirDecl;                    \
    CATElfListingRedirStart;                   \
    TRA_LEVEL_IN_USED ( name, indent );        \
    TRAWRITEI ( name, msg, var );              \
    CATElfListingRedirEnd;                     \
  }                                            \
  else                                         \
  {                                            \
    TRA_LEVEL_IN_USED ( name, indent );        \
    TRAWRITEI ( name, msg, var );              \
  }                                            \
}
#else
#define CATELFPRINTI( name, indent, msg, var ) \
{                                              \
  if ( !strcmp ( #name, "ELFPrint" ) )         \
  {                                            \
    CATElfListingRedirDecl;                    \
    CATElfListingRedirStart;                   \
    TRA_LEVEL_IN_USED ( name, indent );        \
    TRAWRITEI ( name, msg, var );              \
    CATElfListingRedirEnd;                     \
  }                                            \
}
#endif

// JUP : Listing Redirection
#ifndef CNEXT_CLIENT
#define CATELFPRINTF( name, indent, msg, var ) \
{                                              \
  if ( !strcmp ( #name, "ELFPrint" ) )         \
  {                                            \
    CATElfListingRedirDecl;                    \
    CATElfListingRedirStart;                   \
    TRA_LEVEL_IN_USED ( name, indent );        \
    TRAWRITEF ( name, msg, var );              \
    CATElfListingRedirEnd;                     \
  }                                            \
  else                                         \
  {                                            \
    TRA_LEVEL_IN_USED ( name, indent );        \
    TRAWRITEF ( name, msg, var );              \
  }                                            \
}
#else
#define CATELFPRINTF( name, indent, msg, var ) \
{                                              \
  if ( !strcmp ( #name, "ELFPrint" ) )         \
  {                                            \
    CATElfListingRedirDecl;                    \
    CATElfListingRedirStart;                   \
    TRA_LEVEL_IN_USED ( name, indent );        \
    TRAWRITEF ( name, msg, var );              \
    CATElfListingRedirEnd;                     \
  }                                            \
}
#endif

// JUP : Listing Redirection
#ifndef CNEXT_CLIENT
#define CATELFPRINTFX( name, indent, msg, var ) \
{                                               \
  if ( !strcmp ( #name, "ELFPrint" ) )          \
  {                                             \
    CATElfListingRedirDecl;                     \
    CATElfListingRedirStart;                    \
    TRA_LEVEL_IN_USED ( name, indent );         \
    TRAWRITEX ( name, msg, var );               \
    CATElfListingRedirEnd;                      \
  }                                             \
  else                                          \
  {                                             \
    TRA_LEVEL_IN_USED ( name, indent );         \
    TRAWRITEX ( name, msg, var );               \
  }                                             \
}
#else
#define CATELFPRINTFX( name, indent, msg, var ) \
{                                               \
  if ( !strcmp ( #name, "ELFPrint" ) )          \
  {                                             \
    CATElfListingRedirDecl;                     \
    CATElfListingRedirStart;                    \
    TRA_LEVEL_IN_USED ( name, indent );         \
    TRAWRITEX ( name, msg, var );               \
    CATElfListingRedirEnd;                      \
  }                                             \
}
#endif

// JUP : Listing Redirection
#define CATELFPRINTLN_ELFPrint( indent, msg ) \
{                                             \
  CATElfListingRedirDecl;                     \
  CATElfListingRedirStart;                    \
  TRA_LEVEL_IN_USED ( ELFPrint, indent );     \
  TRAWRITELN ( ELFPrint, msg );               \
  CATElfListingRedirEnd;                      \
}

#ifndef CNEXT_CLIENT
#define CATELFPRINTLN_ELFOutput(indent, msg) \
{                                            \
   TRA_LEVEL_IN_USED(ELFOutput, indent);     \
   TRAWRITELN(ELFOutput, msg);               \
}
#else
#define CATELFPRINTLN_ELFOutput(indent, msg)
#endif

#ifndef CNEXT_CLIENT
#define CATELFPRINTLN_ELFCompute(indent, msg) \
{                                             \
   TRA_LEVEL_IN_USED(ELFCompute, indent);     \
   TRAWRITELN(ELFCompute, msg);               \
}
#else
#define CATELFPRINTLN_ELFCompute(indent, msg)
#endif

#ifndef CNEXT_CLIENT
#define CATELFPRINTLN_ELFDefine(indent, msg) \
{                                            \
   TRA_LEVEL_IN_USED(ELFDefine, indent);     \
   TRAWRITELN(ELFDefine, msg);               \
}
#else
#define CATELFPRINTLN_ELFDefine(indent, msg)
#endif

#ifndef CNEXT_CLIENT
#define CATELFPRINTLN_ELFStorage(indent, msg) \
{                                             \
   TRA_LEVEL_IN_USED(ELFStorage, indent);     \
   TRAWRITELN(ELFStorage, msg);               \
}
#else
#define CATELFPRINTLN_ELFStorage(indent, msg)
#endif

#ifndef CNEXT_CLIENT
#define CATELFPRINTLN_ELFAcquire(indent, msg) \
{                                             \
   TRA_LEVEL_IN_USED(ELFAcquire, indent);     \
   TRAWRITELN(ELFAcquire, msg);               \
}
#else
#define CATELFPRINTLN_ELFAcquire(indent, msg)
#endif

#ifndef CNEXT_CLIENT
#define CATELFPRINTLN_ELFInfra(indent, msg) \
{                                           \
   TRA_LEVEL_IN_USED(ELFInfra, indent);     \
   TRAWRITELN(ELFInfra, msg);               \
}
#else
#define CATELFPRINTLN_ELFInfra(indent, msg)
#endif

#ifndef CNEXT_CLIENT
#define CATELFPRINTLN_ELFStorageLink(indent, msg) \
{                                                 \
   TRA_LEVEL_IN_USED(ELFStorageLink, indent);     \
   TRAWRITELN(ELFStorageLink, msg);               \
}
#else
#define CATELFPRINTLN_ELFStorageLink(indent, msg)
#endif

#ifndef CNEXT_CLIENT
#define CATELFPRINTLN_ELFCpuElapse(indent, msg) \
{                                               \
   TRA_LEVEL_IN_USED(ELFCpuElapse, indent);     \
   TRAWRITELN(ELFCpuElapse, msg);               \
}
#else
#define CATELFPRINTLN_ELFCpuElapse(indent, msg)
#endif

#ifndef CNEXT_CLIENT
#define CATELFPRINTLN_ELFError(indent, msg) \
{                                           \
   TRA_LEVEL_IN_USED(ELFError, indent);     \
   TRAWRITELN(ELFError, msg);               \
}
#else
#define CATELFPRINTLN_ELFError(indent, msg)
#endif

// Macro pour ecrire une chaine de caractere precedee d un passage a la ligne
#define CATELFPRINTLN(name,indent, msg) CATELFPRINTLN_##name(indent, msg)
//#define CATELFPRINTLN(name,indent, msg) TRA_LEVEL_IN_USED(name, indent)  TRAWRITELN(name, msg)

// JUP : Listing Redirection
#ifndef CNEXT_CLIENT
#define CATELFPRINTILN( name, indent, msg, var ) \
{                                                \
  if ( !strcmp ( #name, "ELFPrint" ) )           \
  {                                              \
    CATElfListingRedirDecl;                      \
    CATElfListingRedirStart;                     \
    TRA_LEVEL_IN_USED ( name, indent );          \
    TRAWRITEILN ( name, msg, var );              \
    CATElfListingRedirEnd;                       \
  }                                              \
  else                                           \
  {                                              \
    TRA_LEVEL_IN_USED ( name, indent );          \
    TRAWRITEILN ( name, msg, var );              \
  }                                              \
}
#else
#define CATELFPRINTILN( name, indent, msg, var ) \
{                                                \
  if ( !strcmp ( #name, "ELFPrint" ) )           \
  {                                              \
    CATElfListingRedirDecl;                      \
    CATElfListingRedirStart;                     \
    TRA_LEVEL_IN_USED ( name, indent );          \
    TRAWRITEILN ( name, msg, var );              \
    CATElfListingRedirEnd;                       \
  }                                              \
}
#endif

// JUP : Listing Redirection
#ifndef CNEXT_CLIENT
#define CATELFPRINTFLN( name, indent, msg, var ) \
{                                                \
  if ( !strcmp ( #name, "ELFPrint" ) )           \
  {                                              \
    CATElfListingRedirDecl;                      \
    CATElfListingRedirStart;                     \
    TRA_LEVEL_IN_USED ( name, indent );          \
    TRAWRITEFLN ( name, msg, var );              \
    CATElfListingRedirEnd;                       \
  }                                              \
  else                                           \
  {                                              \
    TRA_LEVEL_IN_USED ( name, indent );          \
    TRAWRITEFLN ( name, msg, var );              \
  }                                              \
}
#else
#define CATELFPRINTFLN( name, indent, msg, var ) \
{                                                \
  if ( !strcmp ( #name, "ELFPrint" ) )           \
  {                                              \
    CATElfListingRedirDecl;                      \
    CATElfListingRedirStart;                     \
    TRA_LEVEL_IN_USED ( name, indent );          \
    TRAWRITEFLN ( name, msg, var );              \
    CATElfListingRedirEnd;                       \
  }                                              \
}
#endif

// JUP : Listing Redirection
#ifndef CNEXT_CLIENT
#define CATELFPRINTXLN( name, indent, msg, var ) \
{                                                \
  if ( !strcmp ( #name, "ELFPrint" ) )           \
  {                                              \
    CATElfListingRedirDecl;                      \
    CATElfListingRedirStart;                     \
    TRA_LEVEL_IN_USED ( name, indent );          \
    TRAWRITEXLN ( name, msg, var );              \
    CATElfListingRedirEnd;                       \
  }                                              \
  else                                           \
  {                                              \
    TRA_LEVEL_IN_USED ( name, indent );          \
    TRAWRITEXLN ( name, msg, var );              \
  }                                              \
}
#else
#define CATELFPRINTXLN( name, indent, msg, var ) \
{                                                \
  if ( !strcmp ( #name, "ELFPrint" ) )           \
  {                                              \
    CATElfListingRedirDecl;                      \
    CATElfListingRedirStart;                     \
    TRA_LEVEL_IN_USED ( name, indent );          \
    TRAWRITEXLN ( name, msg, var );              \
    CATElfListingRedirEnd;                       \
  }                                              \
}
#endif

// JUP : Listing Redirection
#define CATELFPRINTTITLE( name, msg ) \
{                                     \
  CATElfListingRedirDecl;             \
  CATElfListingRedirStart;            \
  TRAWRITELN ( ELFPrint, " " );       \
  TRA_LEVEL_IN_USED ( ELFPrint, 0 );  \
  TRAWRITE ( ELFPrint, msg );         \
  CATElfListingRedirEnd;              \
}

// JUP : Listing Redirection
#define CATELFWRITE( name, indent, msg, variable ) \
{                                                  \
  CATElfListingRedirDecl;                          \
  CATElfListingRedirStart;                         \
  Tra_ELFPrint.TraPrint ( indent, msg, variable ); \
  CATElfListingRedirEnd;                           \
}

// Macro pour ecrire une variable dans une chaine de caractere sur fichier trace
#define CATELFTRAWRITE(name,indent, msg, variable) Tra_ELFCpuElapse.TraPrint(indent,msg, variable)

// JUP : Listing Redirection
#define CATELFPRINTTIMER( name, cpu, elapsed )                                                                \
{                                                                                                             \
  CATElfListingRedirDecl;                                                                                     \
  CATElfListingRedirStart;                                                                                    \
  Tra_ELFPrint.TraPrint ( 4, "cpu = %10.2f sec     elapsed = %10.2f sec\n", (double) cpu, (double) elapsed ); \
  CATElfListingRedirEnd;                                                                                      \
}

// Macro pour afficher les temps cpu et elapsed sur fichier trace
#define CATELFPRITRATIMER(name,cpu, elapsed)  Tra_ELFCpuElapse.TraPrint(4, "cpu = %10.2f sec     elapsed = %10.2f sec\n", (double) cpu, (double) elapsed)

// JUP : Listing Redirection
#define CATELFPRINTTIMERM( name, cpu, elapsed, memory )                                                                                                         \
{                                                                                                                                                               \
  CATElfListingRedirDecl;                                                                                                                                       \
  CATElfListingRedirStart;                                                                                                                                      \
  Tra_ELFPrint.TraPrint ( 3, "cpu = %10.2f sec     elapsed = %10.2f sec     memory = %10.2f Mb\n", (double) cpu, (double) elapsed, (double) memory / 131072. ); \
  CATElfListingRedirEnd;                                                                                                                                        \
}

// JUP : Listing Redirection
#define CATELFPRINTTIMERT( name, cpu, elapsed )                                                                         \
{                                                                                                                       \
  CATElfListingRedirDecl;                                                                                               \
  CATElfListingRedirStart;                                                                                              \
  Tra_ELFPrint.TraPrint ( 4, "Total cpu = %10.2f sec   total elapsed = %10.2f sec\n", (double) cpu, (double) elapsed ); \
  CATElfListingRedirEnd;                                                                                                \
}

// JUP : Listing Redirection
// Macro pour afficher les temps cpu et elapsed totaux sur fichier trace
#define CATELFPRITRATIMERT(name,cpu, elapsed)  Tra_ELFCpuElapse.TraPrint(4, "Total cpu = %10.2f sec   total elapsed = %10.2f sec\n", (double) cpu, (double) elapsed)

// JUP : Listing Redirection
#define CATELFPRINTD( name, indent, msg, variable )         \
{                                                           \
  CATElfListingRedirDecl;                                   \
  CATElfListingRedirStart;                                  \
  Tra_ELFPrint.TraPrint ( indent, msg, (double) variable ); \
  CATElfListingRedirEnd;                                    \
}

// fonctions utilisant la trace de listing

extern "C" ExportedByCATELFMathKernel 
    void ehprint( char* message);
extern "C" ExportedByCATELFMathKernel 
    void ehprini( char* message, int* ival);
extern "C" ExportedByCATELFMathKernel 
    void ehprinr( char* message, double* rval);

// résurection des traces (après un Remove de document)
void ExportedByCATELFMathKernel SetElfTraces ();

#endif

