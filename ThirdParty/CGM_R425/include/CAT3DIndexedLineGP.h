#ifndef CAT3DIndexedLineGP_H
#define CAT3DIndexedLineGP_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//------------------------------------------------------------------------------
// Inheritance: CAT3DIndexedLineGP
//                 CATGraphicPrimitive
//                    CATBaseUnknown (SYSTEM framework)
//------------------------------------------------------------------------------

#include "SGInfra.h"
#include "CATGraphicPrimitive.h"
#include "CATVizMacForMetaClass.h"
#include "CATVizGlobals.h"

class CATStreamer;

//++ SGCAAPlan
#include "CATVisMacroForInterfaces.h"
class IVisSG3DPolyline;
class CAT3DIndexedLineGPIVisSG3DPolylineBOAImpl;
//-- SGCAAPlan

#include "CAT3DLineGP.h"
#include "CATVizIndexType.h"
#include "CATBoolean.h"

class ExportedBySGInfra CAT3DIndexedLineGP : public CATGraphicPrimitive
{
   CATDeclareClass;

public :

  //++ SGCAAPlan
  /** @nodoc */
  CATVisDeclarePublicInterfaceAdhesion(CAT3DIndexedLineGP, IVisSG3DPolyline, CAT3DIndexedLineGPIVisSG3DPolylineBOAImpl);
  //-- SGCAAPlan

   CAT3DIndexedLineGP ();
   CAT3DIndexedLineGP (const float iVertices[], const unsigned int iNbVertices, const unsigned int iNbIndices, const unsigned int * iIndices, const CATBoolean iIsPacked = FALSE, const int iLineType = LINES, const int iAllocMode = ALLOCATE_VERTICES);

   virtual void Stream(CATStreamer& oStr,int iSavetype=0);
   virtual void UnStream(CATStreamer& iStr);

   void GetVertices(float * & oVertices, unsigned int & oNbVertices) const;
   void GetIndices (void * & oIndices, unsigned int & oNbIndices, CATBoolean & oPacked, CATVizIndexType & oIndexType) const;

   inline int GetLineType() const;
   inline int IsPacked() const;

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbiden to override Draw function.")
#endif
   virtual void Draw (CATRender & iRender) GP_FUNC_OVERRIDE_FINAL;

   virtual inline void SetStorageIDVBO(const unsigned int iStorageID);
   virtual inline const unsigned int GetStorageIDVBO() const;

   virtual inline void SetStorageIDIBO(const unsigned int iStorageID);
   virtual inline const unsigned int GetStorageIDIBO() const;

   virtual inline unsigned int StorageIDVBOisValid() const;
   virtual inline unsigned int StorageIDIBOisValid() const;

   virtual void Visit(CATIGPVisitor& iVisitor) const final;

protected :

   virtual ~CAT3DIndexedLineGP();  
   float        * _vertices;
   unsigned int * _indices;

private :
   unsigned int   _nbVertices : 30;
   unsigned int   _nbIndices  : 29;
   unsigned int   _lineType   :  2;
   unsigned int   _allocMode  :  2;
   unsigned int   _packed     :  1;

   CAT3DIndexedLineGP( const CAT3DIndexedLineGP & );
   CAT3DIndexedLineGP & operator = ( const CAT3DIndexedLineGP & );

};


class ExportedBySGInfra CAT3DIndexedLineGPIterator
{
public :
   
   CAT3DIndexedLineGPIterator(CAT3DIndexedLineGP & iLine);
   virtual ~CAT3DIndexedLineGPIterator();

   void SetVerticesIndicesAsPosInArray(int iOnOff);
   int  AreVerticesIndicesAsPosInArray();

   unsigned int GetNbIndices();
   unsigned int GetIndex(unsigned int iIndex);
   //void         SetIndex(unsigned int iIndex, unsigned int iValue);

protected :

   void InitDataFromLine();
   void CheckIndexType(unsigned int iValue);

   void *            _indices;
   unsigned int      _nbIndices;
   CATVizIndexType   _indexType; /** @win64 fbq : 64-bit structure padding **/

   CAT3DIndexedLineGP & _line;

   unsigned int      _isPacked:1;
   unsigned int      _verticesIndicesAsPosInArray:1;

private :

   CAT3DIndexedLineGPIterator(const CAT3DIndexedLineGPIterator &);
   CAT3DIndexedLineGPIterator & operator = (const CAT3DIndexedLineGPIterator &);
};

inline int CAT3DIndexedLineGP::GetLineType() const
{
   return (int)_lineType;
}

inline int CAT3DIndexedLineGP::IsPacked() const
{
   return _packed;
}

inline void CAT3DIndexedLineGP::SetStorageIDVBO(const unsigned int iStorageID)
{}

inline const unsigned int CAT3DIndexedLineGP::GetStorageIDVBO() const
{
  return INVALID_STORAGEID;
}

inline void CAT3DIndexedLineGP::SetStorageIDIBO(const unsigned int iStorageID)
{}

inline const unsigned int CAT3DIndexedLineGP::GetStorageIDIBO() const
{
 return INVALID_STORAGEID;
}

inline unsigned int CAT3DIndexedLineGP::StorageIDVBOisValid() const
{
  return 0;
}

inline unsigned int CAT3DIndexedLineGP::StorageIDIBOisValid() const
{
  return 0;
}

#endif

