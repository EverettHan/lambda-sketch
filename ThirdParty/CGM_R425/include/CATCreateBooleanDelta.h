#ifndef CATCreateBooleanDelta_h
#define CATCreateBooleanDelta_h

#include "BODYNOPE.h"

class CATDynBoolean;
class CATGeoFactory;
class CATTopData;
class CATBody;

  /**
  * @nodoc
  *
  * Create boolean delta
  * @param ipContainer
  *   The geometrical factory.
  * @param ipData
  *   The pointer to the data defining the software configuration and the journal. If the journal inside <tt>ipData</tt> 
  *   is <tt>NULL</tt>, it is not filled.
  * @param ipPart
  *   The pointer to the first body.
  * @param ipTool
  *   The pointer to the second body.
  */
ExportedByBODYNOPE CATDynBoolean* CATCreateBooleanDelta (
  CATGeoFactory*     ipContainer,
  CATTopData*        ipData,
  CATBody*           ipPart,
  CATBody*           ipTool);

#endif
