// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyOverlayDebugStreamer.cpp
//
//===================================================================
// January 2017 Creation: ndo
//===================================================================
#ifndef CATPolyBodyOverlayDebugStreamer_h
#define CATPolyBodyOverlayDebugStreamer_h

#include "PolyBodyBoolean.h"
#include "CATPolyBodyOverlayDebug.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"

class CATPolyBody;

#include "CATIAV5Level.h"
#if defined(_AIX_SOURCE)||(!defined(CATIAR419))
#define override
#endif

class ExportedByPolyBodyBoolean CATPolyBodyOverlayDebugStreamer : public CATPolyBodyOverlayDebug::Callbacks
{

public:

  CATPolyBodyOverlayDebugStreamer (const CATUnicodeString& baseName);

  ~CATPolyBodyOverlayDebugStreamer () {}

  /**
   * Set a range of number of calls where capture is activated.
   * If the range is not set, capture will not be activated.
   */
  void SetRange (unsigned int minStep, unsigned int maxStep);

  /**
   * Returns true or false to turn on or off capture and streaming of overlay operands and bodies
   * constructed from the overlay at various stages of the processing.
   * May be overriden in a derived class.
   */
  virtual CATBoolean DebugStage (Poly::Overlay::Debug::OperationType opType,
                                 unsigned int Stage);

public:

  CATBoolean DoBuildOperandBodies (Poly::Overlay::Debug::OperationType opType,
                                   unsigned int Stage) override;

  void OverlayOperandBody (unsigned int index, CATPolyBody& iOperand) override;

public:

  CATBoolean DoBuildSegmentBodies (Poly::Overlay::Debug::OperationType opType,
                                   unsigned int Stage) override;

  void OverlaySegmentBody (unsigned int index, CATPolyBody& body) override;

public:

  CATBoolean DoBuildPatchBodies (Poly::Overlay::Debug::OperationType opType,
                                 unsigned int Stage) override;

  void OverlayPatchBody (unsigned int index, CATPolyBody& body) override;

public:

  void Done () override;

private:

  const CATUnicodeString _BaseName;
  CATUnicodeString _StageName;
  bool _StreamOperands;
  bool _StreamSegmentBodies;
  bool _StreamPatchBodies;

  unsigned int _Count;
  unsigned int _CountMin;
  unsigned int _CountMax;

private:

  void GetDebugFileName (CATUnicodeString& fileName) const;

  void StreamOperand (unsigned int index, const CATPolyBody& iPolyBody);
  void StreamSegmentPolyBody (unsigned int index, const CATPolyBody& iPolyBody);
  void StreamPatchPolyBody (unsigned int index, const CATPolyBody& iPolyBody);

};

#endif
