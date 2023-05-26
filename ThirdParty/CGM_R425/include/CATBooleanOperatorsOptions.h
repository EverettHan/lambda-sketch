// COPYRIGHT DASSAULT SYSTEMES  <2006>
//=============================================================================
//
// CATBooleanOperatorsOptions.h:
//
//=============================================================================
// Usage Notes:
//
// services permettant d'augmenter les interfaces de l'operateur CATHybBoolean
// sans augmenter la vue CAA.
//
//=============================================================================
// Jul. 06   Creation                                             JBX
//=============================================================================
//

#ifndef CATBooleanOperatorsOptions_H
#define CATBooleanOperatorsOptions_H

#include "BOHYBOPE.h"

class CATHybBoolean;

// Indique a l'operateur de garder ses structures de donnee pour pouvoir
// repondre a des questions de type sur l'historique de l'operation
ExportedByBOHYBOPE void DesactiveFatEdgeTreatment(CATHybBoolean * iOperator);

#endif // CATBooleanOperatorsOptions_H
