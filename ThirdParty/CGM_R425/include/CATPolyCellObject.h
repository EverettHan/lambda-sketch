// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCellObject.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// August 2010  Creation: XCZ
//===================================================================

#ifndef CATPolyCellObject_H
#define CATPolyCellObject_H

#include "CATBaseUnknown.h"
#include "PolyVizObject.h"

class CAT3DRep;
class CATPolyCell;
class CATIPolyMesh;
class CATIPolyCurve;
class CATGraphicPrimitive;
class CATGraphicAttributeSet;
class CATPolyBodyObject;
class CATMathTransformation;
class CATVizPrimitive;
class CATCell;


class ExportedByPolyVizObject CATPolyCellObject : public CATBaseUnknown
{
  CATDeclareClass;
public :
   CATPolyCellObject (CATPolyBodyObject* iParent);
   virtual ~ CATPolyCellObject ();

   // Get/Set CATPolyCell
  const CATPolyCell *GetPolyCell() const;
  CATPolyCell *GetPolyCell();
  void SetPolyCell(CATPolyCell *iCell);

  // Get/Set graphic attribute
  void SetGraphicAttribute(const CATGraphicAttributeSet& iGraphicAttr);
  HRESULT GetGraphicAttribute(CATGraphicAttributeSet& oAttr);

  //


  const CATIPolyMesh* GetPolyMesh() const;
  CATIPolyMesh* GetPolyMesh();
  
  const CATIPolyCurve* GetPolyCurve() const;
  CATIPolyCurve* GetPolyCurve();

  void GetTransformation(CATMathTransformation& oTransfo) const;

  // Get parent CATPolyBodyObject 
  CATPolyBodyObject* GetParent();
  const CATPolyBodyObject* GetParent()const ;

  void SetIndexAndRep(const int iIndex,CAT3DRep *iRep) 
  {
    _Index  = iIndex;
    _Rep = iRep;
  }

  void GetIndexAndRep(int &oIndex,CAT3DRep *&oRep)const
  {
    oIndex = _Index;
    oRep = _Rep;
  }

  //void InitVerticesProperties();
  //void InitTrianglesProperties();

  //VisPolyProperties* GetVerticesProperties(){return _VerticesProperties;}
  //const VisPolyProperties* GetVerticesProperties()const{return _VerticesProperties;}
  //VisPolyProperties* GetTrianglesProperties(){return _TrianglesProperties;}
  //const VisPolyProperties* GetTrianglesProperties()const{return _TrianglesProperties;}



private:
  CATPolyCell * _PolyCell;
  


  //ATTRIBUTES
  CATGraphicAttributeSet* _GraphicAttribute;
    
  //PARENT
  CATPolyBodyObject* _Parent;

  // Belonging rep and index
  int _Index;
  CAT3DRep *_Rep;

  ////properties
  //VisPolyProperties* _TrianglesProperties;
  //VisPolyProperties* _VerticesProperties;
  
};

#endif
