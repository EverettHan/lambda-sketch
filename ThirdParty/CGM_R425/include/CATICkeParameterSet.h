#ifndef  CATICkeParameterSet_H
#define  CATICkeParameterSet_H
// COPYRIGHT DASSAULT SYSTEMES  1999


/** 
* @CAA2Level L1
* @CAA2Usage U3 
*/

/*  CAA2Reviewed by FRH */

#include "KnowledgeItf.h"
#include "CATICkeNaming.h"
#include "CATICkeRelationForwards.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATICkeParameterSet;
#else
extern "C" const IID IID_CATICkeParameterSet;
#endif




/**   
* Interface dedicated to parametersets management.
* <b>Role</b>: access the list of parameters stored in the parameter set.
* @see CATIParmPublisher
*/
class ExportedByKnowledgeItf CATICkeParameterSet : public CATICkeNaming
{
    
    CATDeclareInterface;
    
public:
    /**
    *   Returns the list of parameters that were appended to this object using the Append method of the interface CATIParmPublisher. <p>
    *  CATCkeListOfParm is a pointer that must be deallocated.<br>
    *  Example of usage: <br>
    *  CATCkeListOParm pl = hParmSet->Parameters(); <br>
    *  if (pl) <br>
    *     delete pl;

    */
    virtual CATCkeListOfParm    Parameters () const = 0;
    
};

CATDeclareHandler(CATICkeParameterSet,CATICkeNaming);


#endif
