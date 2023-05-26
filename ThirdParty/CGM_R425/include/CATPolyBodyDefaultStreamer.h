// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyDefaultStreamer.h
//
//===================================================================
// February 2010 Creation: NDO
//===================================================================
#ifndef CATPolyBodyDefaultStreamer_H
#define CATPolyBodyDefaultStreamer_H

#include "PolyStream.h"
#include "CATIPolyBodyStreamer.h"
#include "CATPolyStreamOptions.h"
#include "CATErrorDef.h"

#include "CATPolySurfaceList.h"
#include "CATPolyCurveList.h"
#include "CATPolyPointList.h"
#include "CATSetOfPtr.h"

class CATMathStream;
class CATPolyBody;
class CATPolyStreamerRegistry;
class CATPolyStreamRecord;
class CATPolySurfaceCompactVertexIndexMapper;
class CATPolySurfaceCompactFacetIndexMapper;
class CATMapOfPolySurfaceToVertexMapper;
class CATMapOfPolySurfaceToFacetMapper;


/*
 * Default implementation of CATIPolyBodyStreamer.
 * This is a plain streaming of the geometrical entities (CATIPolySurface, CATIPolyCurve and CATIPolyPoint)
 * and of the CATPolyBody topology.
 */
class ExportedByPolyStream CATPolyBodyDefaultStreamer : public CATIPolyBodyStreamer
{

public:

  CATPolyBodyDefaultStreamer ();
  ~CATPolyBodyDefaultStreamer ();

public:

  const char* GetLibraryName () const;

public:

  /**
   * Default is no compression.
   * @see CATIPolyBodyStreamer
   */
  void SetCompression (CATULONG32 c);

  /**
   * Default is all layers.
   * @see CATIPolyBodyStreamer
   */
  void SetLayerFilter (unsigned int f);

public:

  HRESULT Stream (CATMathStream& iStream, const CATPolyBody& iPolyBody,
    CATPolyStreamRecord* ioStreamRecord);

  HRESULT Stream (CATMathStream& iStream, const CATPolyBody& iPolyBody,
    const CATPolyStreamerRegistry& iRegistry, CATPolyStreamRecord* ioStreamRecord);

  HRESULT Stream (CATMathStream& iStream, const CATPolyBody& iPolyBody,
    CATIPolySurfaceStreamer* iSurfaceStreamer, CATIPolyCurveStreamer* iCurveStreamer, CATIPolyPointStreamer* iPointStreamer,
    CATPolyStreamRecord* ioStreamRecord);

private:

  CATULONG32 _CompressionMode;
  unsigned int _LayerFilter;

private:

  HRESULT GetPolySurfaceStreamer (const CATPolyStreamRecord* iStreamRecord, CATIPolySurfaceStreamer*& oSurfaceStreamer) const;

  HRESULT GetPolyCurveStreamer (const CATPolyStreamRecord* iStreamRecord, CATIPolyCurveStreamer*& oCurveStreamer) const;

  HRESULT GetPolyPointStreamer (const CATPolyStreamRecord* iStreamRecord, CATIPolyPointStreamer*& oPointStreamer) const;

protected:

  friend class CATPolyBodyDefaultUnstreamer;

  enum Attributes
  {
    /** No attributes streamed. */                                eNoAttributes = 0x0000,
    /** Basic attributes streamed. */                             eBasicAttributes = 0x0001
  };

private:
  HRESULT RegisterSurfaces(CATIPolySurface & surface,
                           CATPolyStreamRecord & ioStreamRecord,
                           CATSetOfPtr & setOfSurfaces,
                           CATPolySurfaceList & surfaces);

  HRESULT RegisterCurves(CATIPolyCurve & curve,
                         CATPolyStreamRecord & ioStreamRecord,
                         CATSetOfPtr & setOfCurves,
                         CATPolyCurveList & curves);


  HRESULT StreamPrivate (CATMathStream& iStream, const CATPolyBody& iPolyBody,
    CATIPolySurfaceStreamer* iSurfaceStreamer, CATIPolyCurveStreamer* iCurveStreamer, CATIPolyPointStreamer* iPointStreamer,
    const CATPolyStreamerRegistry& iRegistry, CATPolyStreamRecord& ioStreamRecord);

  HRESULT StreamPolySurfaces (CATMathStream& iStream, const CATPolySurfaceList& iSurfaces,
    CATIPolySurfaceStreamer* iSurfaceStreamer,
    const CATPolyStreamerRegistry& iRegistry, CATPolyStreamRecord& ioStreamRecord);

  HRESULT StreamPolyCurves (CATMathStream& iStream, const CATPolyCurveList& iCurves,
    CATIPolyCurveStreamer* iCurveStreamer,
    const CATPolyStreamerRegistry& iRegistry, CATPolyStreamRecord& ioStreamRecord);

  HRESULT StreamPolyPoints (CATMathStream& iStream, const CATPolyPointList& iPoints,
    CATIPolyPointStreamer* iPointStreamer,
    const CATPolyStreamerRegistry& iRegistry, CATPolyStreamRecord& ioStreamRecord);

  HRESULT StreamPolyBody (CATMathStream& iStream, const CATPolyBody& iPolyBody,
    CATPolyStreamRecord& ioStreamRecord, bool iWithObsoleteFaceOrientations = false);

  HRESULT StreamAttributes (CATMathStream& iStream, const CATPolyBody& iPolyBody);

};

#endif
