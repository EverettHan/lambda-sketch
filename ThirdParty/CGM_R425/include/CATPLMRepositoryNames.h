#ifndef __CATPLMRepositoryNames_H
#define __CATPLMRepositoryNames_H

#include "CATPLMRepositoryName.h"

/**
 * Some known provider names.
 */
class CATPLMRepositoryNamesStruct
{
public:
  const CATPLMRepositoryName PLM1;  //CATPLMRepositoryName("PLM1")
  const CATPLMRepositoryName TST;   //CATPLMRepositoryName("TST")
  const CATPLMRepositoryName TSTV5; //CATPLMRepositoryName("TSTV5")
  const CATPLMRepositoryName PLMxT; //CATPLMRepositoryName("PLMxT")

  //@nodoc use CATPLMRepositoryNames()
  ExportedByCATPLMIdentificationAccess static const CATPLMRepositoryNamesStruct& Get();
private:
  CATPLMRepositoryNamesStruct();
  CATPLMRepositoryNamesStruct& operator=(const CATPLMRepositoryNamesStruct& );
  CATPLMRepositoryNamesStruct(const CATPLMRepositoryNamesStruct& );
};

//hack: CATPLMRepositoryNames is already known as a typedef for CATListValCATPLMRepositoryName
#ifndef CATLISTV_CATPLMRepositoryName_H
/**
 * Retrieve a set of known provider names.
 */
inline const CATPLMRepositoryNamesStruct& CATPLMRepositoryNames() {return CATPLMRepositoryNamesStruct::Get();}
#endif

#endif
