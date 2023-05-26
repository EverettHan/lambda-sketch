#ifndef CATIsolateAnalysis_H
#define CATIsolateAnalysis_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "AnalysisTools.h"
#include "CATListOfCATICGMObjects.h"

//Mathematics libraries
#include "CATMathConstant.h"
#include "CATPGMIsolateAnalysis.h"

class CATBody;
class CATGeometry;

class ExportedByAnalysisTools CATIsolateAnalysis: public CATPGMIsolateAnalysis
{
public:
  //-------------------------------------------------------------------------------------
  //- Constructor 
  //-------------------------------------------------------------------------------------
  CATIsolateAnalysis(CATBody * iBody);
  
  //-------------------------------------------------------------------------------------
  //- Destructor 
  //-------------------------------------------------------------------------------------
  virtual ~CATIsolateAnalysis();

  //-------------------------------------------------------------------------------------
  //- Check whether the Body is isolated 
  //-------------------------------------------------------------------------------------
  CATBoolean IsBodyIsolated();

  //-------------------------------------------------------------------------------------
  //- Check whether a geometry is isolated 
  //-------------------------------------------------------------------------------------
  CATBoolean IsIsolated(CATGeometry * iGeometry);

private:
  //Initial datas
  CATBody * _Body;
  int       _AttrKey;
  int       _AttrLgth;

  //List of Geometry
  CATLISTP(CATICGMObject) _List;
  
  void FindLinks(CATGeometry * iIn);
};

#endif

