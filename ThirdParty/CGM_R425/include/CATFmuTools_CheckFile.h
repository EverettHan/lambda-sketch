/**
 * @level Protected
 * @usage U1
 */
#ifndef CATFmuTools_CheckFile_H
#define CATFmuTools_CheckFile_H

#include "ExportedByCATFmuTools.h"
#include "IUnknown.h"

class CATUnicodeString;
class CATTrace;
/**
 * This class is used for varifying various attributes like Name,StorageName,ReadOnly,Overwriting etc 
 * related to file. It has only one function Verify.
 */
class ExportedByCATFmuTools CATFmuTools_CheckFile
{
public:

   enum VerificationType
   {
      VALIDNAME,
      READONLY,
      OVERWRITE
   };
   /**
    * This funciton is used to:
	* 1. check the name used is of valid characters.
	* 2. check for verificationType iType which gives option for overwrite allowed or not.
	* 3. check for overwrite if file name with iFile already exits.
	* 4. 
	*/
   static HRESULT Verify ( const CATFmuTools_CheckFile::VerificationType iType, const CATUnicodeString iFile );

private:
   CATFmuTools_CheckFile ();
   ~CATFmuTools_CheckFile ();
   
   static CATTrace * _t;

};
#endif
