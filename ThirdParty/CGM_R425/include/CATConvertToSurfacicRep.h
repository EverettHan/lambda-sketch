#ifndef CATConvertToSurfacicRep_H
#define CATConvertToSurfacicRep_H

#include "CATVisFoundation.h"

class CATSurfacicRep;
class CAT3DCylinderRep;
class CAT3DCurvedPipeRep;
class CAT3DCanonicalRep;

class ExportedByCATVisFoundation CATConvertToSurfacicRep
{
public:
  CATConvertToSurfacicRep();
  ~CATConvertToSurfacicRep();

  static CATSurfacicRep* GetSurfacicRep(CAT3DCylinderRep* rep);
  static CATSurfacicRep* GetSurfacicRep(CAT3DCurvedPipeRep* rep);
  static CATSurfacicRep* GetSurfacicRep(CAT3DCanonicalRep* rep, const bool iWithEdges = false);
};

#endif
