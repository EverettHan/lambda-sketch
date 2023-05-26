#ifndef CATShowAttribut_h
#define CATShowAttribut_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


/**
 * Graphical show attribut of model.
 * @param CATShowAttr
 *   The model is in show state.
 * @param CATNoShowAttr
 *   The model is in noshow state.
 * @param CATNeutralAttr
 *   The model has no defined state.
 * @param CATPermanentShowAttr
 *   The model is always in the show state.
 * @param CATInvisibleAttr
 *   The model is neither in show state, nor in noshow state : it is invisible.
 * @see CATIVisProperties, CATVisPropertiesValues
 */
enum CATShowAttribut { CATShowAttr, CATNoShowAttr, CATPermanentShowAttr, CATInvisibleAttr }; 
    
#endif
