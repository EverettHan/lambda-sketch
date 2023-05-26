#ifndef CATPLMSharedBehaviourServices_H
#define CATPLMSharedBehaviourServices_H
// COPYRIGHT DASSAULT SYSTEMES 2007

/**
* @level Protected
* @usage U1
*/

#include "CATPLMServicesItf.h"

#include "CATSysErrorDef.h"

class CATPLMTypeId;
class CATString;

/**
 * Toolbox for procedure/function access.
 */
class ExportedByCATPLMServicesItf CATPLMSharedBehaviourServices
{
public:

  /**
  * Retrieve a procedure name for a couple Type/Discipline.
  *
  * If a Discipline is given, the search will be made only on the discipline.
  * There will not have a default behavior on the type if the discipline is not found.
  *
  * @param iTypeId
  *   The type on which the procedure will be search.
  * @param iDiscipline
  *   The discipline on which the procedure will be search.
  * @param iMethodType
  *   The method type to search. Should not be empty.
  * @param iUsage
  *   If iUsage is not empty, the service will search the procedure based on iUsage.<BR>
  *   If iUsage is empty, the service will search the procedure based on iMethodType.
  * @param oProcName
  *   If output procedure name if found.
  * 
  * @return
  *   S_OK    : A ProcedureName has been returned based on inputs.
  *   S_FALSE : A procedure was not found on the Type/Discipline couple but the Type/Discipline is said to supports iMethodType.
  *   E_FAIL  : Possible reasons
  *      - The type is not found : Metadata initialisation problem or unknown type
  *      - MethodType is empty
  *      - A discipline was given, but either was not found or the Type was not associated to it
  *      - A procedure was not found and the Type/Discipline does not support iMethodType 
  */
  static HRESULT GetProcedureNameFromMethodeTypeAndUsage (const CATPLMTypeId &iTypeId,
                                                   const CATString &iDiscipline,
                                                   const CATString &iMethodType,
                                                   const CATString &iUsage,
                                                   CATString &oProcName);

  /**
  * Retrieve a procedure file name from a procedure name.
  * @param iProcName
  *   The procedure to search.
  * @param oProcFileName
  *   The output file name of the procedure (does not contain the path).
  * @param oProcLanguage
  *   The language of the procedure
  * @return
  *   S_OK : The procedure was found and only one implementation is declared.
  *   S_FALSE : The procedure was found but more than one implementation is declared. The first one is returned.
  *   E_FAIL : The procedure was not found.
  */
  static HRESULT GetProcedureSourceFileName (const CATString &iProcName,
                                      CATString &oProcFileName,
                                      CATString &oProcLanguage);

  /**
  * Retrieve a function file name from a function name and a package name.
  * @param iPackageName
  *   The package to look into.
  * @param iFunctionName
  *   The function to search.
  * @param oFuncFileName
  *   The output file name of the function (does not contain the path).
  * @param oFuncLanguage
  *   The language of the function
  * @return
  *   S_OK : The function was found and only one implementation is declared.
  *   S_FALSE : The function was found but more than one implementation is declared. The first one is returned.
  *   E_FAIL : The package does not exist or the function was not found inside.
  */
  static HRESULT GetFunctionSourceFileName (const CATString &iPackageName,
                                     const CATString &iFunctionName,
                                     CATString &oFuncFileName,
                                     CATString &oFuncLanguage);

};

#endif
