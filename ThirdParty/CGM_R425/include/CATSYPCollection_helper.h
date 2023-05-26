#ifndef CATSYPCollectionAdapter_H
#define CATSYPCollectionAdapter_H

#include <IntroInfra.h>
#include <CATLISTV_CATBaseUnknown.h>

class CATISYPCollection_var;

/** @ingroup groupCIDIntrospection
 * Make easier to implement CATISYPCollection.
 */
class ExportedByIntroInfra CATSYPCollection_helper
{
public:
	/** @see CATISYPCollection#AppendList */
	static void Append(const CATISYPCollection_var& i_spCollection,  const CATBaseUnknown_var &i_spObject );
	///** @see CATISYPCollection#RemoveList */
	//static void RemoveList(const CATISYPCollection_var& i_spCollection,  const CATSYPConstArray<CATBaseUnknown_var> &i_list );
	/** @see CATISYPCollection#Remove */
	static void Remove(const CATISYPCollection_var& i_spCollection,  const CATBaseUnknown_var &i_spObject );
	/** @see CATISYPCollection#Contains */
  static int Contains(const CATISYPCollection_var& i_spCollection,  const CATBaseUnknown_var &i_spObject );
	/** @see CATISYPCollection#Clear */
  static void Clear(const CATISYPCollection_var& i_spCollection);
	/** @see CATISYPCollection#Append */
	static void Append(const CATISYPCollection_var& i_spCollection, const CATLISTV(CATBaseUnknown_var) &i_list );
};

#endif

