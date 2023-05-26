// COPYRIGHT Dassault Systemes 2020
//-------------------------------------------------------------------------------------------------

#ifndef CATIParmManipulatorProtected_H
#define CATIParmManipulatorProtected_H

#include "KnowledgeItf.h"
#include "CATBaseUnknown.h"

extern ExportedByKnowledgeItf  IID IID_CATIParmManipulatorProtected;

/**
*
* This interface is implemented on parameter manipulator which contain some protected APIs
* In order to use this Interface, refer following sample code :
* CATIParmManipulator_var spParmManip;
* // Code to retrieve parm manipulator ie. spParmManip
* CATIParmManipulatorProtected_var spParmManipProtected = spParmManip
*
*/

class ExportedByKnowledgeItf CATIParmManipulatorProtected : public CATBaseUnknown
{
    CATDeclareInterface;

public:

    /**
    *@no doc
    * Refer CATIParmManipulator.h for this API
    */
    //virtual HRESULT IsManipPersistent(CATBoolean &  oManipIsPersistent) const = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler(CATIParmManipulatorProtected, CATBaseUnknown);

#endif
