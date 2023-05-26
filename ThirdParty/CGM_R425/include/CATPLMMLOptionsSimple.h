// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATPLMMLOptionsSimple.h
// Header definition of CATPLMMLOptionsSimple
//
//===================================================================
//
// Usage notes:
// difference between CATPLMMLEngineParameters and CATPLMMLParsingOptions:
// CATPLMMLEngineParameters dedicated to manage PLM (custo, plmids, filter).
// CATPLMMLOptionsSimple dedicated to ML engine.
//
//===================================================================
// October 2011  Creation: EPB
//===================================================================


#ifndef CATPLMMLOptionsSimple_H
#define CATPLMMLOptionsSimple_H

#include "CATPLMModelerLanguage.h"          // CATPLMModelerLanguage ProtectedInterfaces

#include "CATPLMMLSrLoadingOptions.h"       // CATPLMModelerLanguage ProtectedInterfaces
#include "CATPLMMLParsingOptions.h"         // CATPLMModelerLanguage ProtectedInterfaces
#include "CATPLMMLOptionsSimple.h"          // CATPLMModelerLanguage ProtectedInterfaces

class ExportedByCATPLMModelerLanguage CATPLMMLOptionsSimple
{
public:
CATPLMMLOptionsSimple();

virtual ~CATPLMMLOptionsSimple();

CATPLMMLOptionsSimple(const CATPLMMLOptionsSimple& opt);

CATPLMMLOptionsSimple & operator=(const CATPLMMLOptionsSimple& opt);

/**
* @deprecated V6R214x
* Please migrate on SpecifyParsingOptions
*/
void Specify(CATPLMMLParsingOptions iOpt);

/**
* <br><b>Role</b>: 
* @param iOpt
*/
void SpecifyParsingOptions(CATPLMMLParsingOptions iOpt);

/**
* <br><b>Role</b>: 
* @param iOpt
*/
void SpecifySrLoadingOptions(CATPLMMLSrLoadingOptions iOpt);

virtual CATPLMMLParsingOptions GetParsingOptions() const;

virtual CATPLMMLSrLoadingOptions GetSrLoadingOptions() const;

protected:
CATPLMMLSrLoadingOptions _srLoadingOption;
CATPLMMLParsingOptions _parsingOption;
};

#endif
