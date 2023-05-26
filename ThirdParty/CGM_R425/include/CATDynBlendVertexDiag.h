#ifndef CATDynBlendVertexDiag_h_
#define CATDynBlendVertexDiag_h_
/** @CAA2Required */

// ---------------------------------------------------------------------
//
// VertexBlend Diagnosis
//
// ---------------------------------------------------------------------

#include "BODYNOPE.h"
#include "CATDynOperator.h"

class CATBody;

class ExportedByBODYNOPE CATDynBlendVertexDiag
{
public:
  CATDynBlendVertexDiag();

  virtual ~CATDynBlendVertexDiag();

  virtual double GetG0Deviation();
  virtual double GetG1Deviation();
  virtual CATBoolean GetIsOffsetabilityAcceptable();

  // returns non zero value if the corner has been created
  virtual int HasBeenCreated();

  // returns border of a non created corner
  virtual CATBody *GetBody(int iOption = 0);
};

#endif
