/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2004
//-----------------------------------------------------------------------------
// class CATOmbModification (implementation) :
// 
// This object implements the  Warm Start redo operation for document properties
//
//-----------------------------------------------------------------------------
// 10/03/2004 Creation V5R14                                                VCS
//-----------------------------------------------------------------------------

#ifndef CATOmbModification_H_
#define CATOmbModification_H_

#include "CATOmbWarmStart.h"
#include "CATBaseUnknown.h"

class ExportedByCATOmbWarmStart CATOmbModification : public CATBaseUnknown
{
public:
    CATDeclareClass;

    CATOmbModification();
    virtual ~CATOmbModification();
    
private :
    CATOmbModification( const CATOmbModification &);
    CATOmbModification& operator = (const CATOmbModification &);
};

#endif
