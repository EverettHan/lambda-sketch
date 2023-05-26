#ifndef CATPickAttribut_h
#define CATPickAttribut_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
* Mode type for the picking of graphic representation.
*
* @param CATNoPickAttr  
*   The representation is not pickable, the user cannot interact
*   with it using the mouse
* @param CATPickAttr    
*   The repersentation is pickable, the user can interact with it
*
* @see CATVisPropertiesValues
*/

enum CATPickAttribut { CATNoPickAttr, CATPickAttr}; 
    
#endif
