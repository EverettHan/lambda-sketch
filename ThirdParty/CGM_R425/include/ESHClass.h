//======================================================================
// COPYRIGHT DASSAULT SYSTEMES 2014
//======================================================================
#ifndef  ESHClass_H  
#define  ESHClass_H  

//ES
#include "ESKernelLib.h"
#include "ESNamespace.h"

class ESKERNEL_API ESHClass
{
public:
  ESHClass();
  virtual ~ESHClass();

  virtual void StdGetLine(CATUnicodeString & resu);
  int Run(int argc, char** argv);

protected:
  void PrintError(ES::Exception & ex);
  void PrintHelp();
  void AtExit();
  //bool InstrumentationPre(CATUnicodeString & ioScriptURI, CATUnicodeString & ioScriptSource);
  //void InstrumentationPost(ES::World & world);
  int ComputeReturnCode(ES::Value & v);
  int InteractiveLoop(ES::World & world);

protected:
    bool _fullmode;
    bool _verbose;
    bool _print_help;
    bool _dorun;
    bool _interactive;
};

#endif
