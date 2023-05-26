// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyGPAdapter.h
//
//===================================================================
//
// February 2009  Creation: NDO
//===================================================================
#ifndef CATPolyBodyGPAdapter_H
#define CATPolyBodyGPAdapter_H

#include "PolyVizAdapters.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CAT3DFaceGP;
class CAT3DEdgeGP;
class CAT3DLineGP;
class CAT3DMarkerGP;
class CAT3DBoundingGP;
class CAT3DFaceGP;
class CAT3DCylinderGP;
class CAT3DCurvedPipeGP;
class CAT3DFixedPlanGP;
class CAT4x4Matrix;

class CATGraphicPrimitive;

class CATPolyBody;
class CATPolyFace;
class CATPolyEdge;
class CATPolyPoint;
class CATPolyVertex;
class CATPolyCell;
class CATPolyBodyGPDiagnosis;

template <class T> class CATVizPtrList;


/*
This is an adapter that constructs a CATPolyBody view of lists of GP markers, lines, edges and faces, cylinders and 
curved-pipes.  The adapter makes new CATPolyCell's that encapsulate the GP primitives and adds them to 
the CATPolyBody. 

This adapter embeds a complete or partial list of GP primitives into a CATPolyBody.  For instance, if the list of 
CAT3DEdgeGP is empty, it provides a view of the CAT3DFaceGP without the edges.  It can process a single face 
or edge too.

Construction of the CATPolyCell's is CPU and memory efficient.  There is no duplication of the visu data.

The visu objects must remain valid during the whole lifecycle of the CATPolyBody.
*/
class ExportedByPolyVizAdapters CATPolyBodyGPAdapter
{

public:

  /*
   * Constructor.
   * The parameter is used to record the primitives whose data cannot be added to the CATPolyBody due
   * to some error.  It's basically used as a log of the primitives with error during call to Run ().
   */
  inline CATPolyBodyGPAdapter (CATPolyBodyGPDiagnosis* iDiagnosis = 0);
  inline ~CATPolyBodyGPAdapter ();

public:

  // Construct a CATPolyBody view of a list of CAT3DMarkerGP's.
  HRESULT Run (const CATVizPtrList<CAT3DMarkerGP>& iMarkers,
               CATPolyBody& ioPolyBody) const;

  // Construct a CATPolyBody view of a list of CAT3DLineGP's.
  HRESULT Run (const CATVizPtrList<CAT3DLineGP>& iLines,
               CATPolyBody& ioPolyBody) const;

  // Construct a CATPolyBody view of a list of CAT3DEdgeGP's and CAT3DFaceGP's.
  HRESULT Run (const CATVizPtrList<CAT3DEdgeGP>& iEdges, 
               const CATVizPtrList<CAT3DFaceGP>& iFaces,
               CATPolyBody& ioPolyBody) const;

public:

  // Construct a CATPolyBody view of a CAT3DMarkerGP.
  // Return the CATPolyCell's associated to the points of the CAT3DMarkerGP.
  HRESULT Run (CAT3DMarkerGP& iMarker,
               CATPolyBody& ioPolyBody) const;

  // Construct a CATPolyBody view of a CAT3DLineGP.
  // Return the CATPolyCell associated to the CAT3DLineGP.
  HRESULT Run (CAT3DLineGP& iLineGP, 
               CATPolyBody& ioPolyBody,
               CATPolyEdge*& oPolyEdge) const;

  // Construct a CATPolyBody view of a CAT3DEdgeGP.
  // Return the CATPolyCell associated to the CAT3DEdgeGP.
  HRESULT Run (CAT3DEdgeGP& iEdgeGP, 
               CATPolyBody& ioPolyBody,
               CATPolyEdge*& oPolyEdge) const;

  // Construct a CATPolyBody view of a CAT3DFaceGP.
  // Return the CATPolyCell associated to the CAT3DFaceGP.
  HRESULT Run (CAT3DFaceGP& iFaceGP,
               CATPolyBody& ioPolyBody,
               CATPolyFace*& oPolyFace) const;

  // Construct a CATPolyBody view of a CAT3DCylinderGP.
  // Return the CATPolyCell associated to the CAT3DCylinderGP.
  HRESULT Run (CAT3DCylinderGP& iCylinderGP,
               CATPolyBody& ioPolyBody,
               CATPolyFace*& oPolyFace) const;

  // Construct a CATPolyBody view of a CAT3DCurvedPipeGP.
  // Return the CATPolyCell associated to the CAT3DCurvedPipeGP.
  HRESULT Run (CAT3DCurvedPipeGP& iCurvedPipeGP,
               CATPolyBody& ioPolyBody,
               CATPolyFace*& oPolyFace) const;

  // Construct a CATPolyBody view of a CAT3DFixedPlanGP.
  // Return the CATPolyCell associated to the CAT3DFixedPlanGP.
  HRESULT Run (CAT3DFixedPlanGP& iFixedPlanGP,
               CATPolyBody& ioPolyBody,
               CATPolyFace*& oPolyFace) const;

public:

  // Construct a CATPolyBody view of a CAT3DBoundingGP.
  // Return the CATPolyCell associated to the CAT3DBoundingGP.
  HRESULT Run (CAT3DBoundingGP& iBoundingGP, 
               CATPolyBody& ioPolyBody,
               CATPolyFace*& oPolyFace) const;

  // Construct a CATPolyBody view of a CATGraphicPrimitive.
  // Return the CATPolyCell associated to the CATGraphicPrimitive.
  HRESULT Run (CATGraphicPrimitive& iGraphicPrimitive, 
               CATPolyBody& ioPolyBody,
               CATPolyCell*& oPolyCell) const;

private:

  CATPolyBodyGPDiagnosis* _Diagnosis;

};


inline CATPolyBodyGPAdapter::CATPolyBodyGPAdapter (CATPolyBodyGPDiagnosis* iDiagnosis) :
  _Diagnosis (iDiagnosis)
{
}


inline CATPolyBodyGPAdapter::~CATPolyBodyGPAdapter ()
{
  _Diagnosis = 0;
}


#endif // !CATPolyBodyGPAdapter_H
