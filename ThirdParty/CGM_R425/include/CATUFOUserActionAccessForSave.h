#ifndef CATUFOUserActionAccessForSave_H
#define CATUFOUserActionAccessForSave_H
/**
 * @level Protected
 * @usage U1
 */

#include "ExportedByCATPLMIdentification.h"
#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATOmxVector.h"
#include "CATOmxIter.h"
#include "CATUFOUserActionCategories.h"
#include "CATOmxSharable.h"
#include "CATOmxKeyString.h"

class CATUFOActionAccessForSave;
class CATUFOLogSimpleEntry;

/**
* UFO User Action access for save.
*/
class CATUFOUserActionAccessForSave : public CATOmxSharable
{
public:

  /*
  * Get iterator on elementary actions
  */
  inline CATOmxIter<CATUFOActionAccessForSave> GetIterator() const { return _ElementaryActions.Iterator(); }

  /*
  * Get the User Action category
  */
  inline CATUFOUserActionCategories GetCategory() const { return _Category; }

  /*
  * Check if the User Action has been initiated
  */
  inline CATBoolean IsValid() const { return  GetCategory() != CATUFOUserActionCategories_Invalid; }

  /*/Get and Set the ordering key
  */
  inline int GetOrderingKey() const { return _OrderingKey; }
  inline void SetOrderingKey(const int & iOrderingKey) { _OrderingKey = iOrderingKey; }

  /*iOrderingKey
  * Get the date
  */
  inline CATLONG64 GetDate() const { return _Date; }

  /**
  * Get the configured delete information
  */
  inline CATBoolean IsConfiguredDelete() const { return _isConfiguredDelete; }

  /**
* Get the operation information
*/
  inline CATOmxKeyString GetOperation() const { return _Operation; }

  friend class CATPLMUFOLogSaver;
  friend class CATUFOLogAccessForSave;

  CATUFOUserActionAccessForSave(CATUFOLogSimpleEntry * iSimpleEntry = NULL);
  ~CATUFOUserActionAccessForSave();

  virtual CATHashKey Hash() const;
  virtual int Cmp(const CATOmxSharable & ipComp) const;

  static CATBoolean CCMReplaceER();
  static CATBoolean CCMSplitER();

private:
  CATOmxVector<CATUFOActionAccessForSave> _ElementaryActions;
  CATUFOUserActionCategories _Category;
  int _OrderingKey;
  CATLONG64 _Date;
  CATBoolean _isConfiguredDelete;
  CATOmxKeyString _Operation;
};

#endif

