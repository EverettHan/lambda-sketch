/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2013
//===================================================================
//===================================================================
//
// CATBRepCopyAdvancedRecognizer
// BRepToDRep Agent dedicated to BRep Copy Recognition
//
//===================================================================
//===================================================================
// January 2013    Creation                         R. Rorato
//===================================================================
#ifndef CATBRepCopyAdvancedRecognizer_H
#define CATBRepCopyAdvancedRecognizer_H

#include "CATDeclarativeManifoldAgent.h"
#include "AdvOpeInfra.h"
#include "CATCGMNewArray.h"
#include "ListPOfCATFace.h"

class CATPrContext;
class CATLiveBody;
class CATPrSet;
class CATLISTP(CATPrSet);

class ExportedByAdvOpeInfra CATBRepCopyAdvancedRecognizer : public CATDeclarativeManifoldAgent
{
public:

  CATCGMDeclareManifoldAgent(CATBRepCopyAdvancedRecognizer, CATCellManifoldPatternCreator);

  // Constructor
  CATBRepCopyAdvancedRecognizer();
  CATBRepCopyAdvancedRecognizer(ListPOfCATFace& iOnlyCopiesOf);

  // Destructor
  virtual ~CATBRepCopyAdvancedRecognizer();

  // -------------------------------------------------------------------------------------------------------------------------------------
  // Exposed for Twin selection
  // -------------------------------------------------------------------------------------------------------------------------------------
  static CATError* RecognizeBRepCopies(CATPrContext& iContext, CATLiveBody& LiveBody, CATLISTP(CATFace)& iOnlyCopyOf, CATLISTP(CATPrSet)& oAllBRepCopies);

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

  void CreateDRepGroup(CATLiveBody& iBody, CATPrSet& iBRepCopy);

  // -------------------------------------------------------------------------------------------------------------------------------------
  // Data
  // -------------------------------------------------------------------------------------------------------------------------------------
  CATLISTP(CATFace) _OnlyCopiesOf;
  CATGeoFactory*    _ReadFactory;
};

#endif
