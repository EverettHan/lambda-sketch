#ifndef CATDetectMicroHoles_H
#define CATDetectMicroHoles_H

#include "ListPOfCATEdge.h"
#include "CATGeometryType.h"
#include "CATListOfDouble.h"
#include "Thick.h"
class CATGeoFactory;
class CATBody;
class CATSoftwareConfiguration;

class ExportedByThick CATDetectMicroHoles
{
public:
  // Constructor
  CATDetectMicroHoles(CATGeoFactory &iFactory, CATSoftwareConfiguration & iConfig, CATBody &iInputBody, double iMicroTol);
  // Destructor
  virtual ~CATDetectMicroHoles();
  void SetListOfEdgesToAnalyze(CATLISTP(CATEdge) &iEdgesToAnalyze);
  void ComputeEdgesLenghts();
  int Run();

private:

  int DetectMicroHoleWith2Edges(CATLISTP(CATEdge)& iEdgesToAnalyze);
  int DetectMicroHoleWith3Edges();
  int DetectMicroHoleWith4Edges();

  double _MicroTol;
  CATGeoFactory & _Factory;
  CATSoftwareConfiguration &_Config;
  CATBody & _Body;
  CATLISTP(CATEdge) _EdgesToAnalyze;
  CATListOfDouble _EdgesLenghts;
  
};

#endif
