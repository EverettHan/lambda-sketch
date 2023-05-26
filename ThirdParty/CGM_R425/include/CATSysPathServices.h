#ifndef CATSysPathServices_H
#define CATSysPathServices_H

// COPYRIGHT DASSAULT SYSTEMES 2002
#include "JS0STDLIB.h"

#include "IUnknown.h" //pour HRESULT
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

ExportedByJS0STDLIB HRESULT CATSysCreateConcatenatedPath(const CATListOfCATUnicodeString& iPathList,
                                                       CATUnicodeString& oPath);

ExportedByJS0STDLIB HRESULT CATSysDecomposeConcatenatedPath(const CATUnicodeString& iPath,
                                                          CATListOfCATUnicodeString& oListOfPathes);


#endif
