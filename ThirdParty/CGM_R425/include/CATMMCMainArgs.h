#ifndef CATMMCMAINARGS_H
#define CATMMCMAINARGS_H

#include "CATMMediaPixelImage.h"

#include "CATListOfInt.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

/**
 * @ingroup groupPotentialSysInfra
 * class CATMMCMainArgs
 * Service to anaylse arguments given to an executable.
 * Allow, while using "LOCAL_LDFLAGS = setargv.obj" in Imakefile, to use "*" in passing argument file naming in order to let the system replace with the list of found files.
 * @brief Service to anaylse arguments given to an executable.
*/
class ExportedByCATMMediaPixelImage CATMMCMainArgs
{
public:
  CATMMCMainArgs();
  
//CATMMCMainArgs(CATString iParameterDeclarator, CATString iArgValueSeparator, CATString iParameterSeparator);//@todo
// Sample                        "-"           ,                 " "         ,                    " "

  enum {hv_no=0, hv_one=1, hv_many=2} argValues;//Expected number arguments for a given parameter.


  /** @name Step 1 : Prepare input data and information.*/
  /**@{*/ 
  void AddArg(const CATUnicodeString &iArg, int iMayHaveValue);
  bool InitializeArgs(int argc, char* argv[]);
  /**@}*/


  /** @name Step 2 : Analyse given inputs before any parameters request*/
  /**@{*/ 
  bool Run();
  /**@}*/


  /** @name Step 3 : Request service for parameters information*/
  /**@{*/ 
  bool IsArgSet(const CATUnicodeString iArg, int &oHasValues);
  bool GetArgValues(const CATUnicodeString iArg, CATListOfCATUnicodeString &oValues);
  bool GetUnclassifiedArgs(CATListOfCATUnicodeString &oArgs);
  /**@}*/


  /** @name Dump services*/
  /**@{*/ 
  CATUnicodeString DumpList(CATListOfCATUnicodeString &values);
  CATUnicodeString DumpArg(CATUnicodeString iArg);
  /**@}*/

private:
  enum aaInfo {aaI_Declared   =1,             //at least one argument has been declarded
               aaI_Initialized=2,             //argc and argv have been given.
               aaI_Analyzed   =4,
               aaI_Retrieved  =8 } _aaInfos;

  bool AreArgs(aaInfo iInfo);
  void ClearResults();

  CATString                 _argDecl;
  CATString                 _argValSep;
  CATString                 _ValuesSep;

  CATListOfCATUnicodeString _lstArgs;
  CATListOfInt              _hasValue;
  CATListOfInt              _isArgSet;
  CATListOfCATUnicodeString _argsValues;
  CATListOfCATUnicodeString _unclassified;

  int                       _argc;
  char**                    _argv;

  int                       _info;
};
#endif
