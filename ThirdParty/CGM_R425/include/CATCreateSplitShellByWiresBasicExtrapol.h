#ifndef __CATCreateSplitShellByWiresBasicExtrapol_h__ 
#define __CATCreateSplitShellByWiresBasicExtrapol_h__ 

#include "HybOper.h"
#include "ListPOfCATBody.h"

class CATTopSplitShellByWires; // forward necessaire
class CATGeoFactory;
class CATTopData;
class CATBody;


/**
 * Creates a CATTopSplitShellByWires operator.
 * @param iFactory
 * The pointer to the geometry factory. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * @param iSplittingBodies
 * A list of bodies containing only one wire.
 * @param iSkinBody
 * The skin body to be split by iSplittingBodies. 
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */

extern "C" ExportedByHybOper CATTopSplitShellByWires*
CATCreateSplitShellByWiresBasicExtrapol(CATGeoFactory     * iFactory,
                            CATTopData        * iTopData,
                            CATLISTP(CATBody) * iSplittingBodies,
                            CATBody           * iSkinBody);
#endif






