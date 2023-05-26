#ifndef CATOmyListUtils_H
#define CATOmyListUtils_H
/**
* @level Protected
* @usage U3
*/

#include "IUnknown.h"

/** @nodoc
 * Template function to release and set to null a reference to a pointer
 */
template <typename T>
void CATSysReleasePtr_TemplateFunct(T*& iPtr) {
    if (iPtr) iPtr->Release();
    iPtr = static_cast<T*>(0);
}

#ifndef  CATLISTP_APPLY_RELEASE
/** @nodoc
 * Macro to release a list of Object Modeler classes
 */
#define CATLISTP_APPLY_RELEASE( LP )                   \
  CATLISTP_FORWARD_LOOP( (LP), itr_ind )               \
  CATSysReleasePtr_TemplateFunct( (LP)[itr_ind] );     \
  CATLISTP_END_LOOP
#endif

/** @nodoc
* Macro to AddRef every elements from a list of Object Modeler classes
*/
#define CATLISTP_APPLY_ADDREF( LP )                                      \
      {                                                                  \
        int CATLISTP_LoopLimit = (LP).Size();                            \
        int ITR ;                                                        \
        for ( ITR = 1 ; ITR <=CATLISTP_LoopLimit ; ITR++ )               \
        {                                                                \
          IUnknown*& PV = (IUnknown*&) (LP)[ITR] ;                       \
          if(PV) PV->AddRef() ;                                          \
        }                                                                \
      }

#endif
