// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATA5AttrNoDfltAbstractProcessor.h
//
//===================================================================
//
// Usage notes:
// THIS CODE IS EXECUTED IN A SECONDARY THREAD.
// IT MEANS THAT YOU SHOULD WRITE THREAD SAFE CODE.
// IT IS FORBIDDEN TO USE CLASSES THAT INHERIT FROM CATBASEUNKNOWN.
// ACCESS TO DICTIONARY IS FORBIDDEN.
// FOR PATH TYPE, USE CATPLMPathDataH_TS IN SECONDARY THREAD.
// FOR PATH TYPE, USE CATPLMPathDataH_TS IN SECONDARY THREAD.
// FOR PLMID TYPE, USE CATPLMID_TS IN SECONDARY THREAD.
//
//===================================================================
//  Oct 2013  Creation
//===================================================================
/**
* @level Protected
* @usage U1
*/
#ifndef CATA5AttrNoDfltAbstractProcessor_H
#define CATA5AttrNoDfltAbstractProcessor_H

#include "CATA5ParserExport.h"
#include "CATOmxSharable.h"
#include "CATOmxPair.h"
#include "CATOmxAny.h"
#include "CATOmxTextStream.h"
#include "CATOMYPairAnyToBool.h"

namespace CATA5
{
  class CsvRow;
}

class ExportedByCATA5Parser CATA5AttrNoDfltAbstractProcessor : public CATOmxSharable
{
public:
  // Constructor/Destructor
  CATA5AttrNoDfltAbstractProcessor(const CATOmxKeyString& iTypeName, const CATOmxKeyString& iAttrName, int iClassification);
  virtual ~CATA5AttrNoDfltAbstractProcessor();

  /*
  * Processes the input csv row and output a CATOmxAny
  */
  virtual HRESULT ProcessCsvRow(CATA5::CsvRow &ioRow, CATOMYPairAnyToBool& oResult) = 0;

  /*
  * Shifts columns indexes.
  * Used when two row definitions are merged (for expand: reference and instance definitions are merged)
  */
  virtual void ShiftColumns(int iShift) = 0;

  /*
  * Adds the given error on the given row, for the current processor.
  */
  void HandleError(CATA5::CsvRow& ioRow, const CATUnicodeString& iErrorMessage);

  inline const CATOmxKeyString& GetTypeName() const{
    return _TypeName;
  }

  inline const CATOmxKeyString& GetAttrName() const {
    return _AttrName;
  }

  inline int GetClassification() const {
    return _Classification;
  }

private:
  const CATOmxKeyString _TypeName, _AttrName;
  int _Classification; // optional: in expand query the row contains data for the reference and instance. recordReadTargetId can be used to segregate data for each built recordread. Default value: 0
};

template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATA5AttrNoDfltAbstractProcessor*>::manager();

#endif
