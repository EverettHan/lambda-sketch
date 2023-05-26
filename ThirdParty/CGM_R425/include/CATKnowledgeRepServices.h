//===================================================================
// COPYRIGHT Dassault Systemes 2018/03/20
//===================================================================
// CATKnowledgeRepServices.cpp
// Header definition of class CATKnowledgeRepServices
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2018/03/20 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATKnowledgeRepServices_H
#define CATKnowledgeRepServices_H

#include "CATExpressionEngine.h"
#include "IUnknown.h"
#include "CATListOfCATUnicodeString.h"
#include "CATBaseUnknown.h"

class CATIPLMNavReference_var;
class CATIPLMNavRepReference_var;
class CATIPLMNavEntity_var;
//-----------------------------------------------------------------------

class ExportedByCATExpressionEngine CATKnowledgeRepServices
{
public:
/**
* Service de passage de la Reference Racine � la 1er RepRef (En particulier 3DPart � 3DShape)
*/
static CATIPLMNavRepReference_var RecoverRepRefFromRoot(const CATBaseUnknown_var &spRepEntity,const CATListOfCATUnicodeString &listUsages, const CATBoolean &applyFilter = TRUE);


/**
* Service de passage d'une RepInstance ou RepRef � la Reference Racine
*/
static CATIPLMNavReference_var FromRepToTopReference(CATIPLMNavEntity_var spRepEntity);

};

//-----------------------------------------------------------------------

#endif
