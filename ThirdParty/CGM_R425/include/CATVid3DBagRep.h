#ifndef CATVid3DBagRep_H
#define CATVid3DBagRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//******************************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 1996
//******************************************************************************
//  Abstract:
//  ---------
//    This object is the main tool for the definition of a representation tree.
//    It manages a list of children representations, and a position matrix, thus
//    defining a complete spatial graph node.
//
//******************************************************************************
//  Usage:
//  ------
//    The CATVid3DBagRep has to be created empty, then children can be added or
//    removed using the AddChild and RemoveChild methods. There's no control on
//    the way children are being added or removed. Caution has to be taken in
//    order to avoid the definition of cycles.
//
//******************************************************************************
//  Inheritance:
//  ------------
//                CATVid3DBagRep
//                  CAT3DRep
//                    CATRep
//                      CATExtend (SYSTEM Framework).
//
//******************************************************************************
//  Main Methods:
//  -------------
//    Drawing.
//    Graphical attributes management.
//
//******************************************************************************

#include "CAT3DRep.h"
#include "SGInfra.h"

class CAT4x4Matrix;
class CATVisFilter;

/** Class to create a collection (bag) of representations. */
class ExportedBySGInfra CATVid3DBagRep : public CAT3DRep
{

  // Marshalling information:
  // ------------------------

  friend class CATMarshallable3DBagRep;
  friend class CATVrmlMaker3DBagRep;
  friend class CATVrml2Maker3DBagRep;
  friend class CATDmuStream3DBagRep;
  friend class CATDmuStream2DTo3DRep;
  CATDeclareClass;


public:
  virtual ~CATVid3DBagRep();

  /** Removes (not deletes) all the children of the bag. */
  virtual void Empty();

  /** Deletes the bag as well as children not referenced by other bags. */
  virtual void Destroy();

  void ClearChildren();

  /** Constructs an empty 3D bag representation. */
  CATVid3DBagRep();

  /** Recalculates the bounding element.
  * @param iShowSpace
  */
  virtual void ComputeBoundingElement(int iShowSpace=1);

  /** Get the position and orientation of the bag.
  * @return The orientation matrix of the bag.
  */
  const CAT4x4Matrix * GetMatrix () const;

  /** Sets the position and orientation of the bag.
  * @param iMatrix
  * Orientation matrix of the bag.
  */
  void SetMatrix(const CAT4x4Matrix & iMatrix);

  /** Sets the matrix of the bag to the identity matrix. */
  void ResetMatrix();

  /** Adds a child representation to the bag.
  * The bounding element of the bag is updated.
  * @param iRep
  * Child representation to be added.
  */
  virtual HRESULT AddChild(CATRep &iRep);

  /**
  * Adds a child graphic representation to the bag.
  * The bounding element of the bag is not updated. 
  * @param iRep
  * Child representation to be added.
  */
  virtual HRESULT AddChildren(CATRep & iRep);

  /** Removes a child representation from the bag.
  * The bounding element of the bag is updated.
  * @param iRep
  * Child representation to be removed.
  */
  virtual void RemoveChild(CATRep &iRep);

  /** Removes a child representation from the bag.
  * The bounding element of the bag is not updated.
  * @param iRep
  * Child representation to be removed.
  */
  virtual void RemoveChildren(CATRep &iRep);

  /** Returns the list of children representations. */
  list<CATRep> *GetChildren ();

  /** Invalidates the bounding element of the representation.
  * The visualization manager will recompute the bounding element of the representation. */
  virtual void SetInvalid();

  /** @nodoc */
  virtual void Draw(CATRender & iRender, int iInside);

  /** @nodoc */
  virtual void DrawShading(CATRender &ioRender, int iInside);

  /** @nodoc */
  virtual void DrawPath(CATRender &ioRender, int iInside, CATRepPath &ioPath); 

  virtual int  IsOkToDraw(CATRender &ioRender, int ioInside);
  virtual int OkToDraw (CATRender &render, int *inside);

  /*DO NOTHING IN FOLLOWING METHOD*/
  virtual void SetHighlightMode(int iHighlightMode, int iPropagationMode=0){};

  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

  // ajout d'un filtre
  // (AddRef est appele sur "filter")
  HRESULT AddFilter(CATVisFilter* filter);

  // retrait d'un filtre
  // (Release est appele sur "filter")
  HRESULT RemoveFilter(CATVisFilter* filter);

  // retrait de tous les filtres
  // (Release est appele sur tous les filtres)
  void EmptyFilters();

protected:

  /** Updates the bounding element of the bag with regards to <tt>iBoundingSphere</tt>. */
  void UpdateBoundingElement(const CAT3DBoundingSphere & iBoundingSphere); 

  CAT4x4Matrix *_the_MatPosi;      // position and orientation of the bag.
  list<CATRep>  _the_Son_List;     // the list of children representations.    
  list<CATVisFilter> _filters;
};

#endif // CATVid3DBagRep_H
