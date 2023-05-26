// COPYRIGHT DASSAULT SYSTEMES 2010

#ifndef CATPLMRelationSolveStatus_H
#define CATPLMRelationSolveStatus_H

/**
* @level Protected
* @usage U1
*/

/**
* Status of a relation.
*
* @param CATPLMRelationSolveStatus_Solved
*   The relation is solved in session (session status)
* @param CATPLMRelationSolveStatus_Broken_Session
*   The relation is not solved because it is broken because the target component has been deleted in the session (session status)
* @param CATPLMRelationSolveStatus_Broken_Remote
*   The relation is not solved because it is broken because the target component has been deleted in the remote persistency (database status at open)
* @param CATPLMRelationSolveStatus_NotOpened
*   The relation is not solved because the target component is not opened in session.
* @param CATPLMRelationSolveStatus_Undefined
*   The relation is not solved, but we are not able to understand why.
*/
enum CATPLMRelationSolveStatus
{
    CATPLMRelationSolveStatus_Solved = 0,
    CATPLMRelationSolveStatus_Broken_Session = 1,
    CATPLMRelationSolveStatus_Broken_Remote = 2,
    CATPLMRelationSolveStatus_NotOpened = 3,
    CATPLMRelationSolveStatus_Undefined = 4
} ;

#endif
