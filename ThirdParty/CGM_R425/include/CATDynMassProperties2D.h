#ifndef CATDynMassProperties2D_H
#define CATDynMassProperties2D_H
//==========================================================================================
//
// COPYRIGHT   : DASSAULT SYSTEMES 1997
//
// DESCRIPTION : CATDynMassProperties2D  class declaration
//
// ************* This operator is deprecated , use CATDynMassProperties3D instead **********
//
//==========================================================================================
#include "BODYNOPE.h"
#include "CATTopOperator.h"

class CATFace;
class CATMathPoint;
class CATTopData;
#include "ListPOfCATFace.h"
#include "CATMathDef.h"

class ExportedByBODYNOPE CATDynMassProperties2D : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATDynMassProperties2D);
public :   
  CATDynMassProperties2D();
  CATDynMassProperties2D( CATTopData * iTopData);
  virtual ~CATDynMassProperties2D() ;

  virtual CATPositiveLength GetArea() = 0;
  virtual void              GetCenterOfGravity(CATMathPoint& oResult)  = 0;

protected : 
  CATTopData * _CreatedTopData;
};

ExportedByBODYNOPE CATDynMassProperties2D *CATDynCreateMassProperties2D (const CATFace*);  
ExportedByBODYNOPE CATDynMassProperties2D *CATDynCreateMassProperties2D (const CATLISTP(CATFace)&);  

ExportedByBODYNOPE CATDynMassProperties2D * CATDynCreateMassProperties2D( CATTopData              * iTopData, 
                                                                          const CATLISTP(CATFace) & iFaces  );

#endif 
