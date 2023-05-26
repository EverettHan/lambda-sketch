#ifndef _CATStandard_SStream_HeaderFile
#define _CATStandard_SStream_HeaderFile

/*#ifdef WNT
#include <strstrea.h>
#else
#include <strstream.h>
#endif*/ 

/*#ifndef _CATStandard_Macro_HeaderFile
# include <CATStandard_Macro.hxx>
#endif  // _CATStandard_Macro_HeaderFile

class Handle_CATStandard_Type;
/*
#ifndef ExportedBySysCascade 
# ifdef WNT
#  ifdef __CATStandard_DLL
#   define ExportedBySysCascade  __declspec( dllexport )
#  else
#   define ExportedBySysCascade  __declspec( dllimport )
#  endif  // __CATStandard_DLL
# else
#  define ExportedBySysCascade 
# endif  // WNT
#endif  // ExportedBySysCascade 
*/

#include "SysCascade.h"
/*
ExportedBySysCascade  Handle_CATStandard_Type& CATStandard_SStream_Type_();
#ifndef WNT
class CATStandard_SStream : public strstreambase, public ostream {
#else
class CATStandard_SStream : public strstream {
#endif
  public:
    ExportedBySysCascade  CATStandard_SStream();
  //  ExportedBySysCascade  CATStandard_SStream(ostream& );

    ExportedBySysCascade  ~CATStandard_SStream();
};*/
#endif
