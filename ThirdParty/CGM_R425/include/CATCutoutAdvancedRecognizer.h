/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2013
//===================================================================
//===================================================================
//
// CATCutoutAdvancedRecognizer
// BRepToDRep Agent dedicated to Cutout Recognition
//
//===================================================================
//===================================================================
// December 2013    Creation                         R. Rorato
//===================================================================
#ifndef CATCutoutAdvancedRecognizer_H
#define CATCutoutAdvancedRecognizer_H

#include "CATDeclarativeManifoldAgent.h"
#include "AdvOpeInfra.h"
#include "CATCGMNewArray.h"

class CATGeoFactory;
class CATBody;

class ExportedByAdvOpeInfra CATCutoutAdvancedRecognizer : public CATDeclarativeManifoldAgent
{
public:

  CATCGMDeclareManifoldAgent(CATCutoutAdvancedRecognizer, CATDeclarativeManifoldAgent);

  // Constructor
  CATCutoutAdvancedRecognizer();

  // Destructor
  virtual ~CATCutoutAdvancedRecognizer();

private:

  // -------------------------------------------------------------------------------------------------------------------------------------
  // Integration into Agent architecture
  // -------------------------------------------------------------------------------------------------------------------------------------
  HRESULT CreateImageManifolds();
  int GetPriority();
  CATBoolean IsAllowedToWorkOnCellManifoldWithoutAdvancedParentDeclarativeManifold();
  CATDeclarativeManifoldAgent* Clone();
  void Dump(CATCGMOutput &os);

  // -------------------------------------------------------------------------------------------------------------------------------------
  // CGMReplay
  // -------------------------------------------------------------------------------------------------------------------------------------
  virtual void Stream(CATCGMStream& Str) const;  
  virtual void UnStream(CATCGMStream& Str, CATGeoFactory* iFactory, CATSoftwareConfiguration * ipConfig);  

  // -------------------------------------------------------------------------------------------------------------------------------------
  // Internal Utilities
  // -------------------------------------------------------------------------------------------------------------------------------------
  void AppendExtractToResBody(CATGeoFactory * ipGeoFactory, CATBody *& ipExtractBody, CATBody  *& iopResultBody, CATBoolean & oRemoveExtractBody);
  void ColorResBody(CATBody  *& iopResultBody);

  // -------------------------------------------------------------------------------------------------------------------------------------
  // Data
  // -------------------------------------------------------------------------------------------------------------------------------------
};

#endif
