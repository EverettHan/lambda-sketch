#ifndef CATVisStyleFactory_H
#define CATVisStyleFactory_H

// COPYRIGHT Dassault Systemes 2012

#include "SGInfra.h"
#include "CATListOfCATString.h"

class CATString;
class CATVisStyle;
class ExportedBySGInfra CATVisStyleFactory
{
public:
  static CATVisStyle* Create(const CATString& iEnvID);

  static const CATListOfCATString& GetPredefinedList(const CATString& iListName);

private:
  CATVisStyleFactory();
  ~CATVisStyleFactory();

  static void Init();

  static int _init;
  static CATListOfCATString _CATIA;
  static CATListOfCATString _Visu;
  static CATListOfCATString _All;
  static CATListOfCATString _Default;
};

//-----------------------------------------------------------------------

#endif
