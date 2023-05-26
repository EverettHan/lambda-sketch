
#ifndef CATSysEnvTool_h
#define CATSysEnvTool_h
//-----------------------------------------------------------------------
//COPYRIGHT DASSAULT SYSTEMES 2004
//-----------------------------------------------------------------------
#include "JS0LIB.h"  // exported by..

#include "CATListOfCATUnicodeString.h"
#include "CATUnicodeString.h"

//=================================================================================
class ExportedByJS0LIB CATSysEnvTool
//=================================================================================
{
  public:
    CATSysEnvTool();
    ~CATSysEnvTool();
    
    CATSysEnvTool (   CATSysEnvTool &A); 
    
    void SetName       (CATUnicodeString iName);
    void SetLabel      (CATUnicodeString iLabel);
    void SetProductLine(CATUnicodeString iProductLine);
    void SetOptions    (CATUnicodeString iOptions);
    void SetIcon       (CATUnicodeString iIcon);
    void SetCATSTART_Flag(CATUnicodeString f);
    void SetConditions (CATUnicodeString Cd);
    void ResetPrdLines ( );
 
    CATUnicodeString   GetName ();
    CATUnicodeString   GetLabel();
    CATUnicodeString   GetOptions();
    CATUnicodeString   GetIcon();
    CATUnicodeString   GetConditions();
    CATListOfCATUnicodeString GetListOfProductLines();
    CATSysEnvTool &operator = (  CATSysEnvTool &A); 
    int					IsLaunchedByCATSTART();	
    
  private:
    CATUnicodeString Name;
    CATUnicodeString Label;
    CATListOfCATUnicodeString ProductLines;
    CATUnicodeString Options;
    CATUnicodeString Icon;
    CATUnicodeString Conditions;
    int CATSTART_Flag;
                
};
#endif
