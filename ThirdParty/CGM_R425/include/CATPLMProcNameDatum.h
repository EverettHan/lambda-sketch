//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/04/26
//===================================================================
// CATPLMProcNameDatum.cpp
// Header definition of class CATPLMProcNameDatum
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2010/04/26 Creation: Code generated by the 3DS wizard
//===================================================================

/**
 * @level Protected
 * @usage U1
 */

#ifndef CATPLMProcNameDatum_H
#define CATPLMProcNameDatum_H

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATLISTV_CATPLMID.h"
#include "CATListOfCATUnicodeString.h"
#include "CATPLMIntegration.h"
//-----------------------------------------------------------------------

class ExportedByCATPLMIntegration CATPLMProcNameDatum: public CATBaseUnknown
{
public:
// Standard constructors and destructors
// -------------------------------------
CATPLMProcNameDatum (const CATListOfCATUnicodeString &iProcedures);
virtual ~CATPLMProcNameDatum ();

HRESULT GetProcedureNames(CATListOfCATUnicodeString &oProcedures) const;
//Ajouter des noms de procedure secondaires
//HRESULT AddProcedureName(const CATUnicodeString &iProcedure);
HRESULT GetPLMIDs(CATPLMIDs &oPLMIDs) const;
HRESULT AddPLMID(const CATPLMID &iPLMID);
HRESULT SetPLMIDs(const CATPLMIDs &iPLMID);

int operator== (const CATPLMProcNameDatum& other) const;
int operator!= (const CATPLMProcNameDatum& other) const;
private:
// Copy constructor and equal operator
// -----------------------------------
/*  CATPLMProcNameDatum (CATPLMProcNameDatum &iCopy) { _Procedure = iCopy._Procedure;
                                                _AssociatedPLMIDs = iCopy._AssociatedPLMIDs;};
  CATPLMProcNameDatum& operator=(CATPLMProcNameDatum& iCopy) { _Procedure = iCopy._Procedure;
                                                               _AssociatedPLMIDs = iCopy._AssociatedPLMIDs;
                                                               return *this;};
*/

CATListOfCATUnicodeString _Procedures;
CATPLMIDs _AssociatedPLMIDs;

};

//-----------------------------------------------------------------------

#include "CATLISTV_Clean.h"
#define CATLISTV_Locate
#define CATLISTV_Append
#include "CATLISTV_Declare.h"

// Generate interface of collection-class
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMIntegration

CATLISTV_DECLARE(CATPLMProcNameDatum)

typedef CATLISTV(CATPLMProcNameDatum) CATPLMProcNameData;


#endif
