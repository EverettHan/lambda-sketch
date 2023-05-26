#ifndef CATTopSimplifyOptions_h
#define CATTopSimplifyOptions_h

#include "BOTOPOPE.h"
#include "CATBoolean.h"

class CATTopSimplify;

class ExportedByBOTOPOPE CATTopSimplifyOptions
{
public:

  /**	@nodoc @nocgmitf
  * HandleRemoteEdgesWithSameGeometry :
  *  - Set a flag to have the simplify operator to attempt simplification of edge(s)
  *  - in the equivalence class that share the same underlying geometry with edge(s)
  *  - outside of the given equivalence class (e.g. topologically disconnected edges)
  */
  static void HandleRemoteEdgesWithSameGeometry(CATTopSimplify * iOperator, CATBoolean iHandleRemoteEdgesWithSameGeometry);
};

#endif
