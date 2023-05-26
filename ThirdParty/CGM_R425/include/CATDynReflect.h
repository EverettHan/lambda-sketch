#ifndef CATDynReflect_H_
#define CATDynReflect_H_

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATDynOperator.h"
#include "CATMathDef.h"
#include "CATSkillValue.h"

class CATFace;
class CATGeoFactory;
class CATMathDirection;
class CATCurve;
class CATPCurve;


class ExportedByBODYNOPE CATDynReflect : public CATDynOperator
{
 public:
  CATDynReflect (CATGeoFactory*     iContainer);
  virtual ~CATDynReflect();

  virtual void       BeginningCurve() = 0;
  virtual CATBoolean NextCurve()      = 0;
  virtual CATPCurve* GetPCurve()      = 0;
  virtual CATCurve*  GetCurve()       = 0; 
};


// Creation EntryPoints
ExportedByBODYNOPE CATDynReflect* CATDynCreateReflect (CATGeoFactory*          iContainer,
						       CATFace*                iFace,
						       const CATMathDirection& iViewPoint,
						       CATAngle                iReflectAngle,
						       CATSkillValue           iMode = BASIC);

#endif


