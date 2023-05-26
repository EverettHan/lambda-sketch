#ifndef CATUFOUserActionCategories_H
#define CATUFOUserActionCategories_H

/**
* @level Private
* @usage U2
*/
#include "CATOmxCollecManager.h"
#include "ExportedByCATPLMIdentification.h"

// user action types.
enum CATUFOUserActionCategories
{
  CATUFOUserActionCategories_Invalid,
  CATUFOUserActionCategories_Move,
  CATUFOUserActionCategories_Insert,
  CATUFOUserActionCategories_Duplicate,
  CATUFOUserActionCategories_SubstitutionInUsageContext,
  CATUFOUserActionCategories_Replace,
  CATUFOUserActionCategories_Split,
  CATUFOUserActionCategories_LogicalClone,
  CATUFOUserActionCategories_Modify,
  CATUFOUserActionCategories_ModifyApplicability,
  CATUFOUserActionCategories_MoveMatrix,
  CATUFOUserActionCategories_Clone,
  CATUFOUserActionCategories_ReplaceER,
  CATUFOUserActionCategories_SplitER
};

ExportedByCATPLMIdentification const char* CATUFODumpCategory(CATUFOUserActionCategories iCategory);

#endif
