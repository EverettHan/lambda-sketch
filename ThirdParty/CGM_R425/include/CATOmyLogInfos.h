#ifndef CATOmyLogInfos_h
#define CATOmyLogInfos_h

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATTime.h"
#include "CATOMYBaseSession.h"
#include "CATOmyLogInfos.h"

/**
* Class representing a line of informations in the audit log that
* is saved inside the CATMaintenance file.
*/
class ExportedByCATOMYBaseSession CATOmyLogInfos
{
public:
  /** 
  * Creates an information bundle to be saved inside the audit log.
  *
  * @param iThem [in]
  *   A distinctive parameter that may be used for easy search in the audit log
  * @param iOperation [in]
  *   The executed operation
  * @param iInfos [in]
  *   All additional informations that may be necessary to type the logged operation.
  *   They are expected to be (key,value) pairs, where each key is directly followed
  *   by its corresponding value.
  * @param iTime [in]
  *   Optional parameter to specify the time you want to use to flag this operation.
  *   If null, current time will be used.
  *
  */
  CATOmyLogInfos(const CATUnicodeString& iThem, const CATUnicodeString& iOperation,
    const CATListValCATUnicodeString &iInfos, CATTime * iTime=NULL);

  /** 
  * Creates an information bundle to be saved inside the audit log.
  *
  * @param iThem [in]
  *   A distinctive parameter that may be used for easy search in the audit log
  * @param iOperation [in]
  *   The executed operation
  * @param iInfos [in]
  *   All additional informations that may be necessary to type the logged operation.
  *   They are expected to be (key,value) pairs, where each key is directly followed
  *   by its corresponding value.
  * @param iTime [in]
  *   Optional parameter to specify the time you want to use to flag this operation.
  *   If null, current time will be used.
  *
  */
  CATOmyLogInfos(CATListValCATUnicodeString &iInfos);

  /** 
  * Creates an information bundle from an audit log entry line. 
  *
  * @param iLogInfosString [in]
  *   The audit log entry line. It is expected to follow the parttern
  *   <key>=<value>;<key>=<value>;...;<key>=<value>\n
  *   Not following this parttern will lead to unexpected results.
  *
  */
  CATOmyLogInfos(const CATUnicodeString & iLogInfosString);

  /** 
  * Convert the datas into an audit log file line.
  *
  * @return
  *   The data as an audit log entry, following the pattern
  *   Them=<them>;Time=MM.DD.YYYY-hh:mm:ss AM;Operation=<operation>;<key1>=<value1>;...\n
  *
  */
  CATUnicodeString ConvertToString();

  /** 
  * Extract the datas as (key,value) pairs, where each key is directly followed by its
  * corresponding value. "Them", "Time" and "Operation" are used as classic keys and
  * are always the 3 first ones to appear in the list
  *
  * @return
  *   The extracted datas
  *
  */
  CATListValCATUnicodeString ExtractInfos();
private:
  CATUnicodeString _converted;
  CATListValCATUnicodeString _infos;

  void ComputeConvertToString();
  void ComputeExtractInfos();
};
#endif
