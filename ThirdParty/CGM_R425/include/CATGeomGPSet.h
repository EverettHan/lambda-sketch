#ifndef CATGeomGPSet_H
#define CATGeomGPSet_H

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "SGInfra.h"
#include "CAT3DGeomRep.h"
#include "CATAssert.h"

class CATGraphicPrimitive;
class CATGraphicAttributeSet;
class CATSurfacicRep;

struct CATGPwithGAS
{
   CATGraphicPrimitive  *     m_gp;
   CATGraphicAttributeSet *   m_att;
};

class ExportedBySGInfra CATGeomGPSet
{
  friend class CATGeomGPSetWithNotStreamedGAS;
  friend class CATGeomGPSetWithoutGAS;
  friend class CATSurfacicRep;
public:
   
   virtual ~CATGeomGPSet() { };
   
   static CATGeomGPSet *   Allocate(int iSize, CATGeomType iType);
   virtual HRESULT         Reallocate(int iSize) = 0;

   CATGeomGPSet *          Get(const CATGeomType iType);

   /** @nodoc
   * insert a new GPSet in the sorted chained list and return the top chained element
   * @param toInsert describes the chained elements to insert. An element cannot be already in the chained list. if null pointer, it is ignored.
   * @return the top chained element after insertion.
   */
   CATGeomGPSet *          Insert(CATGeomGPSet * toInsert);

   inline unsigned         WithGAS();
   virtual unsigned        WithNotStreamedGas() { return 0;}
   inline unsigned         GetSize();
   inline unsigned         WithBuffer();
   inline void             SetBuffer( unsigned iBuffer);
   inline CATGeomType      GetType();
   inline CATGeomGPSet *   GetNext();
   
   virtual CATGraphicAttributeSet *  GetGAS() { return NULL; };
   virtual CATGraphicAttributeSet *  GetGAS(int index) { return NULL; };
   virtual CATGraphicPrimitive    *  GetGP(int index) { return NULL; };

   virtual HRESULT SetGAS(CATGraphicAttributeSet * iGAS) { return E_FAIL; }
   virtual HRESULT SetGAS(int index, CATGraphicAttributeSet * iGAS) { return E_FAIL; }
   virtual HRESULT SetGP(int index, CATGraphicPrimitive  * iGP) { return E_FAIL; }

   virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

protected:

   inline void SetNext(CATGeomGPSet* next);
   CATGeomGPSet() { };

   // 32-bit field containing size, type, GeomType
   unsigned m_size:25;
   unsigned m_withGAS:1;
   unsigned m_withBuffer:1;
   CATGeomType m_type:5;
   CATGeomGPSet * m_next;
   
};

class CATGeomGPSetWithGAS : public CATGeomGPSet
{

public:

   CATGeomGPSetWithGAS(int iSize, CATGeomType iType);
   virtual ~CATGeomGPSetWithGAS();

   virtual HRESULT                  Reallocate(int iSize);
   virtual CATGraphicAttributeSet * GetGAS(int index );
   virtual CATGraphicPrimitive  *   GetGP(int index);
   virtual HRESULT                  SetGAS(int index, CATGraphicAttributeSet * iGAS);
   virtual HRESULT                  SetGP(int index, CATGraphicPrimitive  * iGP);

   virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

private:

   CATGPwithGAS          * m_gpWithGAS;
};

class CATGeomGPSetWithNotStreamedGAS;

class CATGeomGPSetWithoutGAS : public CATGeomGPSet
{
  friend class CATGeomGPSetWithNotStreamedGAS;

public:

   CATGeomGPSetWithoutGAS(int iSize, CATGeomType iType);
   CATGeomGPSetWithoutGAS(CATGeomGPSetWithNotStreamedGAS& gpSetWithNotStreamedGAS,CATGeomGPSet* pPreviousSet); // remplace et detruit le set passe en parametre
   virtual ~CATGeomGPSetWithoutGAS();

   virtual HRESULT                  Reallocate(int iSize);
   virtual CATGraphicAttributeSet * GetGAS();
   virtual CATGraphicPrimitive  *   GetGP(int index);
   virtual HRESULT                  SetGAS(CATGraphicAttributeSet * iGAS);
   virtual HRESULT                  SetGP(int index, CATGraphicPrimitive  * iGP);

   virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

protected:

   CATGraphicAttributeSet * m_att;
   CATGraphicPrimitive **   m_gp;

};

// INLINED METHODS


inline unsigned CATGeomGPSet::WithGAS()
{ 
   return m_withGAS;
}

inline unsigned CATGeomGPSet::GetSize()
{ 
  if (m_withBuffer) return m_size-1;
  else              return m_size; 
}

inline unsigned CATGeomGPSet::WithBuffer()
{ 
   return m_withBuffer; 
}

inline void CATGeomGPSet::SetBuffer( unsigned iBuffer)
{ 
   m_withBuffer = iBuffer;
}

inline CATGeomType CATGeomGPSet::GetType()
{ 
   return m_type;
}

inline CATGeomGPSet * CATGeomGPSet::GetNext()
{ 
   return m_next;
}

inline void CATGeomGPSet::SetNext(CATGeomGPSet* next)
{
  m_next = next;
}


#endif
