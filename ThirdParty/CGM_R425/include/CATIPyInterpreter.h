#ifndef _CATIPyInterpreter_
#define _CATIPyInterpreter_

//===================================================================
// CATIPyInterpreter
// Header definition of the interface CATIPyInterpreter
//
// Associated adapter : CATPyInterpreterAdapter
// In case of a new component implementation,
// inherit from the CATPyInterpreterAdaptor class.
//===================================================================
//  01/09/2021 Creation KJD
//===================================================================
#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"
#include "DSYString.h"
#include "CATListOfCATUnicodeString.h"

class CATCkeEvalContext;
class CATICkeParm_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIPyInterpreter;
#else
extern "C" const IID IID_CATIPyInterpreter;
#endif


class ExportedByCATLifSpecs CATIPyInterpreter : public CATBaseUnknown
{
public:
  CATDeclareInterface;
  virtual void Finalize() = 0;

  //Once declared, the errors will be managed by the CATLifErrorManager.
  //WARNING : The interpreter doesn't open or close the error session. It throws only the encountered errors.
  virtual void StartLifErrorMngt(const CATBaseUnknown_var& ihSource) = 0;
  //The interpreter is shared by everybody during all the session
  //=> LifErrorManagement has to be stopped for the next user
  virtual void StopLifErrorMngt() = 0;
  //methods devoted to configs with EKL binding
  virtual void SetEKLContext(CATCkeEvalContext* ipContext) = 0;
  virtual void SetEKLParam(const CATUnicodeString& iName, const CATICkeParm_var& ipCkeParm) = 0;
  virtual void GetEKLParam(const CATUnicodeString& iName, CATICkeParm_var& opCkeParm) = 0;
  virtual void EKLExec(const CATUnicodeString& iStr) = 0;
  virtual void InitEKLOutput() = 0;
  virtual void GetEKLOutput(CATUnicodeString& oOutput, int InputLineNb) = 0;
  virtual void ComputeEKLPackageToLoad(const CATUnicodeString& iScript, CATListOfCATUnicodeString& oListOfPackages) = 0;
  virtual HRESULT LoadEKLPackage(const CATUnicodeString& iusPackageName) = 0;

};

CATDeclareHandler(CATIPyInterpreter, CATBaseUnknown);

#endif
