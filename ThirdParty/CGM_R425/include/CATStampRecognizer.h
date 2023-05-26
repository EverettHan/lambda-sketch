#ifndef CATStampRecognizer_H
#define CATStampRecognizer_H

#include "CATGroupRecognizerBase.h"
#include "AdvOpeInfra.h"

#include "CATWbrData.h"
#include "ListPOfCATWbrData.h"
#include "ListPOfCATCell.h"
#include "ListPOfListPOfCATCell.h"
//RL1
#include "CATCellManifoldBendNavigator.h"

class ExportedByAdvOpeInfra CATStampRecognizer : public CATGroupRecognizerBase
{
public:
  CATCGMDeclareManifoldAgent(CATStampRecognizer, CATDeclarativeManifoldAgent);

	// Constructor
  CATStampRecognizer();

  // Destructor
	virtual ~CATStampRecognizer();

  virtual int GetPriority();
  virtual CATDeclarativeManifoldAgent* Clone();
  virtual HRESULT CreateManifoldGroup();

  void SetReferenceFace(ListPOfCATFace RefFace);

  // -------------------------------------------------------------------------------------------------------------------------------------
  // CGMReplay
  // -------------------------------------------------------------------------------------------------------------------------------------
  virtual void Stream(CATCGMStream& Str) const;
  virtual void UnStream(CATCGMStream& Str, CATGeoFactory* iFactory, CATSoftwareConfiguration* ipConfig);

  virtual void Dump(CATCGMOutput& os);

protected:

private:
  
  ListPOfCATCellManifold _StampCells;
  // ListPOfCATFace _RefFace; RefFaceList now in base class 
 
};

#endif
