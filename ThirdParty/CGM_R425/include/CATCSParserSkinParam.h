// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSParserSkinParam.h
// Header definition of CATCSParserSkinParam
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//  Jan 2006  Creation                      Roman LAVROV
//===================================================================

#ifndef CATCSParserSkinParam_h
#define CATCSParserSkinParam_h

#include "CATCSSkinParam.h"

class ExportedBySolverInterface CATCSParserSkinParam : public CATCSSkinParam {
public:
  virtual ~CATCSParserSkinParam() {};

  virtual unsigned int GetNbOfParameters() = 0;
  virtual void SetParameters(const double* iaParams) = 0;
  virtual void GetParameters(double* oaParams) = 0;
  virtual CATCSSkinParam* GetStreamParam() {return 0;}

protected:
  CATCSParserSkinParam(CATCSSkin* ipSkin);

private:
  void operator=(const CATCSParserSkinParam&);
};

#endif
