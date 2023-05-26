#ifndef CATTransientPathElementRep_h_
#define CATTransientPathElementRep_h_

#include "SGInfra.h"

// SGInfra (PublicInterfaces)
#include "CATVizBasePathElementRep.h"

/**
* The purpose of this class is to allow 1 meta-CATRepPath to represent multiple actual CATRepPaths.
* Indeed, a CATRepPath containing multiple CATTransientPathElementRep will be considered a meta-CATRepPath.
* Each CATTransientPathElementRep in the path can contain 1 actual CATRepPath.
*
* A CATTransientPathElementRep can be instanciated and added into a CATRepPath, then it will be automatically
* processed and destroyed in l_CATVisManager::i_BuildGraphicalRepFromModel.
*
*
* Example of a CATIVisu::BuildHighlightLook implementation to highlight multiple CATRepPaths:
*
* HRESULT ModelVisuExample::BuildHighlightLook(const CATPathElement& iModelPath, CATRepPath& ioRepPath)
* {
*     // 1- generate all the CATRepPaths that you want to highlight
*     CATRepPath* subRepPath1 = new CATRepPath(ioRepPath); // <- use the current contents of ioRepPath as a common prefix
*     CATRepPath* subRepPath2 = new CATRepPath(ioRepPath); // <- use the current contents of ioRepPath as a common prefix
*     // ...continue to add reps into the CATRepPaths
*
*     // 2- create a CATTransientPathElementRep for each CATRepPath
*     CATTransientPathElementRep* transientRep1 = CATTransientPathElementRep::CreateRep(subRepPath1);
*     CATTransientPathElementRep* transientRep2 = CATTransientPathElementRep::CreateRep(subRepPath2);
*
*     // 3- empty ioRepPath that will now become a meta-CATRepPath
*     ioRepPath.Empty();
*
*     // 4- add the CATTransientPathElementReps into the meta-CATRepPath
*     ioRepPath.AddRep(*transientRep1);
*     ioRepPath.AddRep(*transientRep2);
*
*     return S_OK;
* }
*/
class ExportedBySGInfra CATTransientPathElementRep : public CATVizBasePathElementRep
{
    /** @nodoc */
    CATDeclareClass;

public:
    /** Creates a new CATTransientPathElementRep that can be added into a meta-CATRepPath. */
    static CATTransientPathElementRep* CreateRep(CATRepPath* iPathOfRep, int iForHighlight = 1);

    /** @deprecated Please use CreateRep method to instanciate an object of this class. */
    CATTransientPathElementRep(CATRepPath* iPathOfRep, int iForHighlight = 1);

    /** @nodoc */
    virtual ~CATTransientPathElementRep();

protected:
    /** Copy constructor */
    CATTransientPathElementRep(const CATTransientPathElementRep& iRep);
};

#endif // !CATTransientPathElementRep_h_
