#ifndef CATOmbUpdateOnCCMVariantsAdapter_H
#define CATOmbUpdateOnCCMVariantsAdapter_H

/**
* @level Private
* @usage U3
*/
#include "CATIOmbUpdateOnCCMVariants.h"
/**
* @nodoc
* For internal use only.
*/
class ExportedByCATObjectModelerBase CATOmbUpdateOnCCMVariantsAdapter : public CATIOmbUpdateOnCCMVariants
{
public :

    // Standard constructors and destructors for an implementation class
    // -----------------------------------------------------------------
    CATOmbUpdateOnCCMVariantsAdapter ();
    virtual ~CATOmbUpdateOnCCMVariantsAdapter ();

    virtual CATBoolean IsActivated();

    virtual HRESULT Do(CATListValCATComponentId & iOldCIDs, CATListValCATComponentId & iNewCIDs);

private:
    // The copy constructor and the equal operator must not be implemented
    // -------------------------------------------------------------------
    CATOmbUpdateOnCCMVariantsAdapter(CATOmbUpdateOnCCMVariantsAdapter&);
    CATOmbUpdateOnCCMVariantsAdapter& operator=(CATOmbUpdateOnCCMVariantsAdapter&);

} ;

#endif

