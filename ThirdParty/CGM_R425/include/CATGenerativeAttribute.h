#ifndef CATGenerativeAttribute_H
#define CATGenerativeAttribute_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1 
 * @CAA2Usage U1
 */


/** 
 *  Attribute allowing to generate a path.
 * <b>Role</b>:These attributes are used in the @href CATVisManager#GenerateRepPathFromPathElement
 * @param csoOperation
 * Used for highlight and prehighlight operations. When csoOperation is used,
 * the method @href CATVisManager#BuildHighLightLook is called. It can be overloaded to highlight
 * a specific rep defined by the user
 * @param pathManipulatorOperation
 * Used for manipulation operations. When pathManipulatorOperation is used,
 * the method @href CATVisManager#BuildRepPath is called
 */

enum CATGenerativeAttribute { csoOperation, pathManipulatorOperation, drillOperation };



#endif
