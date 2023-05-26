// COPYRIGHT DASSAULT SYSTEMES 2010
//=============================================================================
//
// CATSweep2DataConverter: Utility for conversion of topological types from-to CATSweep2 types
//
//=============================================================================
//
//=============================================================================
// 16/06/10 NLD Creation de la classe CATSweep2DataConverter
// 27/06/10 NLD Isolation de la classe par extraction depuis CATFrFTopologicalSweepCx2
//              pour reutilisation
//              Ajout UnhandledValue()
//=============================================================================
#ifndef CATSweep2DataConverter_H
#define CATSweep2DataConverter_H

#include <CATTopBooleanType.h>
#include <CATBooleanType.h> // pour CATBoolType
#include <CATTopPropagationType.h>
#include <CATTopLimitType.h>
#include <CATTopLimit.h>
#include <CATSweepLimitDef.h> // pour CATLimitType CATLimit et CATPropagationType
#include <BO0SWEEP.h>

class ExportedByBO0SWEEP CATSweep2DataConverter
  {
   public:

   CATSweep2DataConverter();

   // CATLimitType       <==> CATTopLimitType
   CATLimitType ToCATLimitType(CATTopLimitType iType);
   CATTopLimitType ToCATTopLimitType(CATLimitType iType);

   // CATLimit           <==> CATTopLimit
   CATLimit ToCATLimit(CATTopLimit LimitId);
   CATTopLimit ToCATTopLimit(CATLimit LimitId);

   // CATPropagationType <==> CATTopPropagationType
   CATPropagationType ToCATPropagationType(CATTopPropagationType iPropagType);
   CATTopPropagationType ToCATTopPropagationType(CATPropagationType iPropagType);

   // CATBoolType        <==> CATTopBooleanType
   CATBoolType ToCATBoolType(CATTopBooleanType BooleanOperation);
   CATTopBooleanType ToCATTopBooleanType(CATBoolType BooleanOperation);

   private:

   void UnhandledValue();

  };
#endif

