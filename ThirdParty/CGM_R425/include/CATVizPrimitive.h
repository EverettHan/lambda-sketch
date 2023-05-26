/* COPYRIGHT DASSAULT SYSTEMES 2003 */

//===================================================================
//
// CATVizPrimitive.h
// Header definition of CATVizPrimitive
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Nov 2003  Creation: Code generated by the CAA wizard  svq
//===================================================================
#ifndef CATVizPrimitive_H
#define CATVizPrimitive_H

#include "IUnknown.h"
#include "SGInfra.h"
#include "CATVizAllocator.h"
#include "CATVizIndexType.h"
#include "CATVizMacForMetaClass.h"

#include "CATVizGarbageCollector.h"

/** @nodoc */
enum CATVizGeomType {
   CATVizBoundaryEdge,
   CATVizInternalSharpEdge,
   CATVizInternalSmoothEdge,
   CATVizBoundaryPoint,
   CATVizInternalSharpPoint,
   CATVizInternalSmoothPoint,
   CATVizSurfacicPoint,
   CATVizFreePoint,
   CATVizWireEdge,
   CATVizInfiniteFace,
   CATVizFace,
   CATVizEdge,
   CATVizIsopar,
   CATVizUnknownType
};

// Streaming IDs
#define VIZFACE      (0x01)
#define VIZEDGE      (0x02)
#define VIZLINE      (0x03)
#define VIZLODFACE   (0x04)
#define VIZMARKER    (0x05)
#define VIZFIXEDPLAN (0x06)

// Allocation Modes
#define CATVizAllocMode unsigned int
#define CATVizAllocModeGet 0
#define CATVizAllocModeAllocate 1

class CATStreamer;
class CATRender;
class CATVizVertexBuffer;
class CAT3DViewpoint;
class CAT3DViewport;
class CATUVGeometry;

//-----------------------------------------------------------------------

/**
* Describe your class here.
* <p>
* Using this prefered syntax will enable mkdoc to document your class.
*/
class ExportedBySGInfra CATVizPrimitive
{
   CATVizDeclareClass;

public:

   /** @nodoc */
   friend class CATCacheOfDestroyedElements;
   
   // Standard constructors and destructors
   // -------------------------------------
   /** @nodoc */
   CATVizPrimitive ();

   /** @nodoc */
   virtual CATVizPrimitive * Duplicate() = 0;

   /** @nodoc */
   virtual void Draw(CATRender &iRender) = 0;

   /** @nodoc */
   virtual void Draw(CATRender &iRender, CAT3DViewpoint *viewpoint, CAT3DViewport *viewport);

	/** @nodoc */
   virtual int DetailCulling(CATRender *render);

   /** @nodoc */
   virtual void Stream(CATStreamer& oStr,int iSavetype=0);
   
   /** @nodoc */
   virtual void UnStream(CATStreamer& iStr);
   
   /** @nodoc */
   virtual void Empty();

   /** @nodoc */
   virtual void ResetDLs();

   /** @nodoc */
   virtual void SetAllocMode(CATVizAllocMode iAllocMode);

   /** @nodoc */
   virtual CATVizAllocMode GetAllocMode();

   /** @nodoc */
   virtual unsigned int GetId();
   virtual unsigned char GetStreamId() const;

   /** @nodoc */
   virtual CATUVGeometry * GetGeometry();

   /** @nodoc */
   virtual unsigned int AddRef();

   /** @nodoc */
   virtual unsigned int Release();

   /** @nodoc */
   virtual unsigned int GetRefCount();

   /** @nodoc */
   void Destroy();

   // Little helper function in order to compute the available compression
   /** @nodoc */
   static CATVizIndexType ComputeUnStreamIndexType(CATStreamer &iStr);
   /** @nodoc */
   static CATVizIndexType ComputePackedUnStreamIndexType(CATStreamer &iStr);
   /** @nodoc */
	virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

  virtual HRESULT __stdcall QueryInterface(const IID& iIID, void** oPPV);

protected :

   /** @nodoc */
   virtual ~CATVizPrimitive ();

public:
   CATVizDeclarePagedNewOverride(CATVizPrimitive)
};

//-----------------------------------------------------------------------

#endif