// COPYRIGHT DASSAULT SYSTEMES 2019, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuPlayRepBuilder.h
//
//===================================================================
// Sep 2019 Creation: JXO
//===================================================================

#ifndef CATPolyVisuPlayRepBuilder_H
#define CATPolyVisuPlayRepBuilder_H

#include "CATPolyVisuDistiller.h"

// Poly
#include "CATPolyObserver.h"

// Visu
#include "CATCgrHeader.h"

// Math
#include "CATCGMScaleCategoryDef.h"

// System
#include "CATIAV5Level.h"
#include "CATErrorDef.h" // HRESULT.
#include "CATBoolean.h"

// Forwards
class CATRep;
class CATSoftwareConfiguration;
class CATPolyVisuPlayRepBuilderObserver;
class CATPolyBody;
class CAT4x4Matrix;
class CATUnicodeString;

class ExportedByPolyVisuDistiller CATPolyVisuPlayRepBuilder
{
public:

  /**
  * Constructor. If no SoftwareConfiguration is provided, latest version is used.
  */
  CATPolyVisuPlayRepBuilder(CATSoftwareConfiguration * iSoftwareConfiguration = 0);

  /**
  * Destructor
  */
  ~CATPolyVisuPlayRepBuilder();

public:

  /**
  * @param iRep
  *        The rep for which we build a navigation representation.
  */
  HRESULT Init(CATRep & iRep);

  /**
  * @param oResultRep
  *        The output representation.
  */
  HRESULT Run(CATRep*& oResultRep);

  /**
  * Default is 1mm.
  */
  HRESULT SetDeviation(double iFaceDeviation, double iEdgeDeviation);

  /**
  * Set the scale category. Large scale will multipy deviation by 100. Small scale will divide deviation by 100.
  * @param iScaleCategory
  *        scale category
  * @param iActivateCoarsePrecision
  *        If set to TRUE, for each terminal rep whose bounding sphere has a radius bigger than 1/100th of
  *        the model size (1 000 000 mm in normal scale), we will multiply the deviation by 10.
  */
  HRESULT SetScaleCategory(CATCGMScaleCategory iScaleCategory, CATBoolean iActivateCoarsePrecision = FALSE);

  /**
  * Use existing LODs (Level Of Details), when available in the Surfacic Rep.
  * Default is off.
  */
  HRESULT UseLODs(CATBoolean iLODs = TRUE);

  /**
  * Do not remove the edges.
  * Default behaviour is to mimic old navrep builder, that means the navrep result has NO edges.
  * Call this method to have edges in the result.
  * Warning: this option is not compatible with DoEnableGroupedDecimation.
  */
  HRESULT DoAddEdges(CATBoolean iEdges = TRUE);

  /**
  * Copy the CATGraphicMaterials.
  * Default behaviour is to mimic old navrep builder, that means the navrep result has NO materials.
  * Call this method to have the CATGraphicMaterial in the result.
  */
  HRESULT DoCopyMaterials(CATBoolean iMat);

  /**
  * If enabled, the builder will try to decimate sub-groups of reps together.
  * This allows for better control over output topology (mainly fewer holes)
  * Warning: this option is not compatible with DoAddEgdges.
  */
  HRESULT DoEnableGroupedDecimation(CATBoolean iGrouped = TRUE);

  /**
  * If enabled, the playrep operator will attempt to detect smooth edges by finding edges that have moved too far away from their initial location.
  * When a smooth edge is detected, normals around this edge are recomputed in the output playerep.
  */
  HRESULT DoDetectSmoothEdgesAndRecomputeNormalsAroundThem(CATBoolean iDoDectect = TRUE);

  /**
  * Warning: DoDetectSmoothEdgesAndRecomputeNormalsAroundThem must have been enabled for this to work.
  * If enabled, The playrep operator will attempt to merge faces around smooth edges.
  */
  HRESULT DoMergeFacesAroundSmoothEdges(CATBoolean iDoMergeFacesAroundSmoothEdges = TRUE);

  /**
   * Register an observer
   */
  void RegisterObserver(CATPolyVisuPlayRepBuilderObserver * obs);

  /**
   * Unregister an observer
   */
  void UnregisterObserver(CATPolyVisuPlayRepBuilderObserver * obs);

#ifdef CATIAR423
  /**
   * Masks to be passed as option
   */
  enum eOptionMasks
  {
    eQuantBBoxPerGP = 0x01,
    eBBoxPerRep = 0x02,
    ePositionBoxCompression = 0x04,
    eNormalOct16Compression = 0x08,
    eNormalOct24Compression = 0x10
  };
  /**
   * Saves a cgr with the PLAYREP header.
   */
  static HRESULT WritePlayRep(const CATUnicodeString& localPath, CATRep* rep,
    const int sagMode, const double sag, const double sagCurve,
    const double deviation,
    CATBoolean iNewVersion = FALSE, int iOptions = eQuantBBoxPerGP | ePositionBoxCompression | eNormalOct16Compression /* Use enums with | */);
  /**
   * Reads a cgr with header.
   */
  static CATRep * ReadCGR(const CATUnicodeString& localPathAV1,
    int& sagMode, double& sag, double& sagCurve,
    CATCgrHeader::CGRType & cgrType);
#endif

private:
  class Impl;
  Impl * m_impl;
};


class ExportedByPolyVisuDistiller CATPolyVisuPlayRepBuilderObserver : public CATPolyObserver<CATPolyVisuPlayRepBuilderObserver>
{
public:
  CATPolyVisuPlayRepBuilderObserver();
  ~CATPolyVisuPlayRepBuilderObserver();
  enum ErrorCode
  {
    eNotSet = 0,
    eOK,
    eTooSmall,
    eWire,
    eMarker,
    eNotSupported, // Should be suppoted one day (VisPrimitiveGroupRep for example)
    eNotSurfacic, // Will probably never be supported
    eUnexpected
  };
  virtual void Begin(CATRep & inputRep, const CAT4x4Matrix* pMat) = 0;

  virtual void BeginAdapter(CATRep & inputRep);
  virtual void EndAdapter(HRESULT oHr, CATPolyBody * pBody = 0);
  virtual void BeginAddPolyBody(unsigned int iRepIdx);
  virtual void EndAddPolyBody(HRESULT oHr);
  virtual void BeginRun();
  virtual void BeginInitialize();
  virtual void EndInitialize(HRESULT oHr);
  virtual void BeginSteps();
  virtual void EndSteps(HRESULT oHr);
  virtual void BeginBuildPolyBodies();
  virtual void EndBuildPolyBodies(HRESULT oHr);
  virtual void EndRun(HRESULT oHr);
  virtual void BeginExport(unsigned int iRepIdx);
  virtual void EndExport(HRESULT oHr);
  virtual void BeginBuildDeferredRep(unsigned int iRepIdx);
  virtual void EndBuildDeferredRep(CATRep *oOutputRep, HRESULT oHr, ErrorCode oLocalErrorCode);
  virtual void IgnoreDeferredRep(CATRep *inputRep, ErrorCode oLocalErrorCode);
  virtual void DoneReleaseOutputBody(unsigned int iRepIdx);
  virtual void DoneReleaseInputBody(unsigned int iRepIdx);

  virtual void End(CATRep *oOutputRep, HRESULT oHr, ErrorCode oGlobalErrorCode) = 0;
};

#endif
