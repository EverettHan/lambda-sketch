// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATVizPrimitiveSet.h
// Header definition of CATVizPrimitiveSet
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Nov 2003  Creation: Code generated by the CAA wizard  svq
//===================================================================
#ifndef CATVizPrimitiveSet_H
#define CATVizPrimitiveSet_H

#include "SGInfra.h"
#include "CATVizAllocator.h"
#include "CATVizPrimitive.h"
#include "CATBoolean.h"

class CATGraphicAttributeSet;
class CATStreamer;
class CATGraphicMaterial;
class CATMappingOperator;

//++ E8C : Multi Materials
class CATVisAppliedMaterial;
class CATGroupOfFacesWithMaterials;
//-- E8C : Multi Materials

#define SIMPLESET						(0x01)
#define EXTENDEDSET					(0x02)
#define EXTENDEDSETWITHMAT	(0x03)//extendedset with material (for face set only)

#ifndef NULL
#define NULL 0
#endif

//-----------------------------------------------------------------------

/**
* Describe your class here.
* <p>
* Using this prefered syntax will enable mkdoc to document your class.
*/

class ExportedBySGInfra CATVizPrimitiveSet
{
public:

   /** @nodoc */
   friend class CATCacheOfDestroyedElements;
   friend class SGCGRNodesFactoryA;

   // Standard constructors and destructors
   // -------------------------------------
   CATVizPrimitiveSet();
   CATVizPrimitiveSet (unsigned int nbPrimitives, CATVizPrimitive **primitives, CATVizGeomType type, CATBoolean poolAllocated = FALSE);
   virtual ~CATVizPrimitiveSet ();
   
   virtual void Stream(CATStreamer &oStr, int savetype = 0);
   virtual void UnStream(CATStreamer &iStr);
   
   INLINE CATVizGeomType GetGeomType();
   INLINE unsigned int GetNumberOfPrimitives();
   INLINE CATVizPrimitive *GetPrimitive(unsigned int i);

   //++ VBO UV
   INLINE unsigned int GetNumberOfVBOPrimitives();
   INLINE CATVizPrimitive *GetVBOPrimitive(unsigned int i);
   virtual const CATGraphicAttributeSet *GetVBOGraphicAttributeSet(unsigned int i);
   virtual CATGraphicMaterial *GetVBOGraphicMaterial(unsigned int i);
   virtual void AllocateVBOPrimitives(unsigned int nbPrimitives);
   virtual void SetVBOPrimitive(unsigned int i, CATVizPrimitive * iFace, CATGraphicAttributeSet * iGAS=NULL, CATGraphicMaterial * iMat=NULL);
   //--

   virtual void SetPrimitive(unsigned int i, CATVizPrimitive* iPrimitive);
   virtual const CATGraphicAttributeSet *GetGraphicAttributeSet(unsigned int i);
   virtual const CATGraphicAttributeSet *GetGraphicAttributeSet();
   INLINE void SetAllocMode(int allocMode);
   INLINE int  GetAllocMode();
   virtual CATBoolean WithGAS();
   virtual CATBoolean WithVertexBuffer();
   virtual CATVizVertexBuffer *GetVertexBuffer(unsigned int i);
   virtual CATBoolean WithGraphicMaterial();

   virtual CATGraphicMaterial *GetGraphicMaterial(unsigned int i);
   virtual CATMappingOperator *GetMappingOperator(unsigned int i);

   virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);
   /** @nodoc */
   void Destroy();
protected:

   CATVizGeomType _type : 5;
   unsigned int _allocMode : 1;
   unsigned int _poolAllocated : 1;
   unsigned int _nbPrimitives : 25;

   CATVizPrimitive **_primitives;

   //++ VBO UV
   unsigned int _nbVBOPrimitives;
   //--
   
public:
   CATVizDeclarePagedNewOverride(CATVizPrimitiveSet)

	 virtual CATBoolean WithGroupsOfFacesWithMaterials() const;
	 virtual CATVisAppliedMaterial* GetVisAppliedMaterial( unsigned int i ) const;
	 virtual CATGroupOfFacesWithMaterials* GetGroupOfFacesWithMaterials( unsigned int i ) const;
	 virtual unsigned int GetNumberOfGroups() const;
};

//-----------------------------------------------------------------------

INLINE unsigned int CATVizPrimitiveSet::GetNumberOfPrimitives()
{
   return _nbPrimitives;
}


INLINE CATVizGeomType CATVizPrimitiveSet::GetGeomType()
{
   return _type;
}

INLINE CATVizPrimitive *CATVizPrimitiveSet::GetPrimitive(unsigned int i)
{
   if (_primitives && i<_nbPrimitives)
      return _primitives[i];

   return NULL;
}

INLINE void CATVizPrimitiveSet::SetAllocMode(int allocMode)
{
   _allocMode = allocMode;
}

INLINE int CATVizPrimitiveSet::GetAllocMode()
{
   return _allocMode;
}

//++ VBO UV
INLINE unsigned int CATVizPrimitiveSet::GetNumberOfVBOPrimitives()
{
  return _nbVBOPrimitives;
}

INLINE CATVizPrimitive * CATVizPrimitiveSet::GetVBOPrimitive(unsigned int i)
{
  if (i<0 || i>=_nbVBOPrimitives) return NULL;

  return _primitives[_nbPrimitives + i];
}
//--

#endif