#ifndef CATPickMode_h
#define CATPickMode_h
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 1999


/**
* @nodoc 
* Mode type for the picking of graphic representation.
*
* @param CATNoPick  
*   The representation is not pickable, the user cannot interact
*   with it using the mouse
* @param CATPick    
*   The repersentation is pickable, the user can interact with it
*
* @see CATPickAttribut
*/

enum CATPickMode { CATNoPick, CATPick };
    
#endif
