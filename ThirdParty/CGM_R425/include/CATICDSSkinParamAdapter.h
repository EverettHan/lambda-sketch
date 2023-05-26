#ifndef CATICDSSkinParamAdapter_H
#define CATICDSSkinParamAdapter_H

// COPYRIGHT DASSAULT SYSTEMES  2013

#include "CATCDS.h"

#include "CATCDSBoolean.h"
#include "CATCDSEnums.h"

class CATCSSkinParam;

/**
 * @SKIP
 *
 * Abstract class that specifies an implementation
 * of black box skin parameter.
 */
class ExportedBySolverInterface CATICDSSkinParamAdapter
{
public:

  // TODO peut on cacher tout ca ?
  virtual CATCSParamType GetParamType() = 0;
  virtual CATCDSBoolean IsParamOnWire() = 0;
  virtual CATCDSBoolean IsParamOnVertex() = 0;
  virtual CATCDSBoolean IsParamOnBorder() = 0;
  virtual int GetInformationOnVertex(int& oNbOfWires, int& oNbOfFaces) = 0;
  virtual int GetNextParamOnWire(CATCSSkinParam* opPointOnSkin) = 0;
  virtual int GetNextParamOnFace(CATCSSkinParam* opPointOnSkin) = 0;
  virtual int GetNextParamOnVertex(CATCSSkinParam* opPointOnSkin) = 0;
  virtual CATCSContinuity GetContinuity() = 0;
};

#endif
