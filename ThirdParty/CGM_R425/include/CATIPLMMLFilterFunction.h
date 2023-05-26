//===================================================================
// COPYRIGHT  Dassault  Systemes  2011
//===================================================================
//
//  CATIPLMMLFilterFunction.h
//  Define  the  CATIPLMMLFilterFunction interface
//
//===================================================================
// http://osmwebdsy/wiki/index.php/1-Modeler_Language_ML_or_MeuL:_Navigation
//===================================================================
//
// Usage  notes:
// Ability given to reduce size of the table (and free memory...) using the current object
// and using method void SetFilter(...) on class CATPLMMLEngineParameters.
// This function is called for each line of the table. Then the line is kept or not.
//
// You can post-filter the table using the current object
// and using  method HRESULT ApplyPostFiltering(...) on class interface CATIPLMMLEngine
// This function is called for each line of the table. Then the line is kept or not.
//
// here is an example of class that implements this interface
// class ClashOnly : public CATIPLMMLFilterFunction
// {
// public:
//   ClashOnly():CATIPLMMLFilterFunction(){}
//   ~ClashOnly(){}
//
//   HRESULT FilterFunction(CATIPLMMLLine* ipLine,CATBoolean & oIsLineToBeDeleted)
//   {
//     oIsLineToBeDeleted = TRUE;
//     if(ipLine == NULL){cout<<"*** ERROR *** ipLine == NULL"<<endl;return E_FAIL;}
//
//     CATOmxKeyString attrKey;
//     CATOmxAny attrValue;
//     int mask;
//     HRESULT rc = ipLine->GetAttributeValue("METRIC.V_Itf_Type",1,attrKey,attrValue,mask);
//     if(FAILED(rc)){cout<<"*** ERROR *** CATIPLMMLLine::GetValue()"<<endl;return E_FAIL;}
//
//     int valueI;
//     CATOmxKeyString valueS;
//     rc = attrValue.GetEnum(valueS,valueI);
//     if(FAILED(rc)){cout<<"*** ERROR *** CATOmxAny::GetEnum()"<<endl;return E_FAIL;}
//     if(valueI != 1)
//       oIsLineToBeDeleted = TRUE;
//     else
//       oIsLineToBeDeleted = FALSE;
//     return S_OK;
//   }
// };
//===================================================================
// March 2011    Creation:  EPB
//=================================================================== 

#ifndef CATIPLMMLFilterFunction_H
#define CATIPLMMLFilterFunction_H

#include "CATPLMModelerLanguage.h"

#include "CATBoolean.h"
#include "CATOmxSharable.h"

class CATIPLMMLLine;

// -------------------------------------------
// C++ INTERFACE that uses CATBaseUnknown (lifecycle managed with AddRef and Release)
// You have to INHERIT from this C++ interface
// It is a C++ interface so don't use CATDeclareClass, CATImplementClass...
// -------------------------------------------
class ExportedByCATPLMModelerLanguage CATIPLMMLFilterFunction : public CATOmxSharable
{
public:
  CATIPLMMLFilterFunction();

  /**
  * Function used to filter or post-filter the table.
  *
  * <br><b>Role</b>: Function used to filter or post-filter the table.
  * This function is called for each line of the table. Then the line is kept or not.
  *
  * @param ipLine
  *   a line of the table.
  * @param oIsLineToBeDeleted
  *   line is kept...or not.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT FilterFunction(CATIPLMMLLine* ipLine,CATBoolean & oIsLineToBeDeleted)=0;

  virtual ~CATIPLMMLFilterFunction();

private:
  CATIPLMMLFilterFunction(const CATIPLMMLFilterFunction&);

  CATIPLMMLFilterFunction& operator=(const CATIPLMMLFilterFunction&);
};
#endif

