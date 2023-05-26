#ifndef CATPyInterpreterAdapter_H
#define CATPyInterpreterAdapter_H

#include "CATLifSpecs.h"
#include "CATIPyInterpreter.h"
#include "DSYString.h"
#include "CATListOfCATUnicodeString.h"

class CATCkeEvalContext;
class CATICkeParm_var;
/**
 * Adapter for the interface CATIPyInterpreter
 */
class  ExportedByCATLifSpecs CATPyInterpreterAdapter : public CATIPyInterpreter
{
  //CATDeclareClass;

public:
  CATPyInterpreterAdapter();
  ~CATPyInterpreterAdapter();

  virtual void Finalize();

  void StartLifErrorMngt(const CATBaseUnknown_var& ihSource);
  void StopLifErrorMngt();
  //methods devoted to configs with EKL binding
  void SetEKLContext(CATCkeEvalContext* ipContext);
  void SetEKLParam(const CATUnicodeString& iName, const CATICkeParm_var& ipCkeParm);
  void GetEKLParam(const CATUnicodeString& iName, CATICkeParm_var& opCkeParm);
  void EKLExec(const CATUnicodeString& iStr);
  void GetEKLOutput(CATUnicodeString& oOutput);
  void ComputeEKLPackageToLoad(const CATUnicodeString& iScript, CATListOfCATUnicodeString& oListOfPackages);
  HRESULT LoadEKLPackage(const CATUnicodeString& iusPackageName);
};

#endif
