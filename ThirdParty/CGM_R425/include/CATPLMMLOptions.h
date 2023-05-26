// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATPLMMLOptions.h
// Header definition of CATPLMMLOptions
//
//===================================================================
//
// Usage notes:
// difference between CATPLMMLEngineParameters and CATPLMMLParsingOptions:
// CATPLMMLEngineParameters dedicated to manage PLM (custo, plmids, filter).
// CATPLMMLOptions dedicated to ML engine.
//
//===================================================================
// October 2011  Creation: EPB
//===================================================================


#ifndef CATPLMMLOptions_H
#define CATPLMMLOptions_H

#include "CATPLMModelerLanguage.h"          // CATPLMModelerLanguage ProtectedInterfaces

#include "CATPLMMLSrLoadingOptions.h"       // CATPLMModelerLanguage ProtectedInterfaces
#include "CATPLMMLParsingOptions.h"         // CATPLMModelerLanguage ProtectedInterfaces
#include "CATPLMMLNavInGraphOptions.h"      // CATPLMModelerLanguage ProtectedInterfaces
#include "CATPLMMLOptionsSimple.h"

class ExportedByCATPLMModelerLanguage CATPLMMLOptions : public CATPLMMLOptionsSimple
{
public:
CATPLMMLOptions();

virtual ~CATPLMMLOptions();

CATPLMMLOptions(const CATPLMMLOptions& opt);

CATPLMMLOptions(const CATPLMMLOptionsSimple& opt);

CATPLMMLOptions & operator=(const CATPLMMLOptions& opt);

/**
* <br><b>Role</b>: 
* @param iOpt
*/
void SpecifyNavInGraphOptions(CATPLMMLNavInGraphOptions iOpt);

CATPLMMLNavInGraphOptions GetNavInGraphOptions() const;

private:
CATPLMMLNavInGraphOptions _navInGraphOption;
};

#endif
