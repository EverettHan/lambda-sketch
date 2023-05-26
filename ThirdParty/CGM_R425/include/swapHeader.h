
/**
 * @level Private
 * @usage U1
 */

#ifndef swapHeader_h
#define swapHeader_h

#include "ExportedByCATIAEntity.h"
#include "IUnknown.h"

ExportedByCATIAEntity enum TYPE_DATA {LIBRARY=0, MODEL=1};
extern "C" ExportedByCATIAEntity void swapHeader(const TYPE_DATA data);

// Ajout OGM d'une methode avec un code de retour !!
//  return code can be S_OK, or E_FAIL ;
ExportedByCATIAEntity HRESULT swapV4Data( const TYPE_DATA data ) ;

#endif
