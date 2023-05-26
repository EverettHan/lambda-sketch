#ifndef  CATGMLiveStepFilletEdgeAttr_H
#define  CATGMLiveStepFilletEdgeAttr_H
//===================================================================
// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
//  CATGMLiveStepFilletEdgeAttr.h
// 		
//===================================================================
//  Oct 2008  Creation: CWM
//===================================================================

#include "CATCGMAttribute.h"

class  CATGMLiveStepFilletEdgeAttr : public CATCGMAttribute
{
public:
  enum Type {G0=0, G1, G2};

  CATCGMDeclareAttribute(CATGMLiveStepFilletEdgeAttr, CATCGMAttribute);

  CATGMLiveStepFilletEdgeAttr();
  CATGMLiveStepFilletEdgeAttr(Type iContinuityType);
  virtual ~CATGMLiveStepFilletEdgeAttr();

  Type GetContinuityType();

private:
  Type _ContinuityType;
};

#endif
