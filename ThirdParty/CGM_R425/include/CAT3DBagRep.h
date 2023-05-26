#ifndef CAT3DBagRep_H
#define CAT3DBagRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


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
//    The CAT3DBagRep has to be created empty, then children can be added or
//    removed using the AddChild and RemoveChild methods. There's no control on
//    the way children are being added or removed. Caution has to be taken in
//    order to avoid the definition of cycles.
//
//******************************************************************************
//  Inheritance:
//  ------------
//                CAT3DBagRep
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

#include "SGInfra.h"
#include "CAT3DRep.h"

class CAT4x4Matrix;
class CATVisuController;
class CATUuid;

//++ SGCAAPlan
#include "CATVisMacroForInterfaces.h"
class IVisSG3DNodeGroup;
class CAT3DBagRepIVisSG3DNodeGroupBOAImpl;
//-- SGCAAPlan

/** Class to create a collection (bag) of representations. */
class ExportedBySGInfra CAT3DBagRep : public CAT3DRep
{
  
  // Marshalling information:
  // ------------------------
  
  friend class CAT3DFinalBagRep;
  friend class CATMarshallable3DBagRep;
  friend class CATVrmlMaker3DBagRep;
  friend class CATVrml2Maker3DBagRep;
  friend class CATDmuStream3DBagRep;
  friend class CATDmuStream2DTo3DRep;
  friend class SGCGRNodesFactoryA;
  friend class CAT3DBagRepWithToleranceScale;
  friend class CATISO3DBagRep;
  friend class Vis3DBillboardRep;
  friend class CAT3DLodBagRep;
  friend class Vis3DNodeGroupRep;
  friend class CATCGRRep;
  friend class CAT3DScalePlaneRep;
  friend class CAT3DSemanticBagRep;
  friend class CATDebugCGRRep;
  friend class CAT3DFilterBagRep;
  friend class CAT2DTo3DRep;
  friend class CATSorted3DBagRep;
               
  CATDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT3DBagRep, IVisSG3DNodeGroup, CAT3DBagRepIVisSG3DNodeGroupBOAImpl);
  
public:
   
  //Rep lifecycle: Support AddRef Release (under variable CATRep_AddRef_Release: now activated since R422 B1)

  /** Increments the reference-count of this representation.
  * Note that if the root representation is AddRef'ed explicitly, then CATVisManager will not modify/update/delete the underlying structure.
  */
  virtual ULONG   __stdcall AddRef();

  /** Decrements the reference-count of this representation.
  * Deletes this rep (and also removes children & calls Release on them) if reference-count goes to zero.   
  */
  virtual ULONG   __stdcall Release();
   
  //++ SGCAAPlan
  /** @nodoc */
  virtual HRESULT StartIterationOnChildren  (void*& iContext);
  /** @nodoc */
  virtual HRESULT GetNextChild              (void*& iContext, CATRep*& opChildRep);
  /** @nodoc */
  virtual HRESULT EndIterationOnChildren    (void*& iContext);

  /** @nodoc */
  virtual HRESULT GetAttribute(const VisAttributeID iAttributeID, const VisDataType iType, void *oValue);
  /** @nodoc */
  virtual HRESULT SetAttribute(const VisAttributeID iAttributeID, const VisDataType iType, void *iValue);

  /** @nodoc */
  virtual HRESULT AddChild(CATRep* ipChildRep);
  /** @nodoc */
  virtual HRESULT RemoveChild(CATRep* ipChildRep);
  //-- SGCAAPlan

  virtual ~CAT3DBagRep();

  /** Removes (not deletes) all the children of the bag. 
 * Internally it calls Release on all the children (complimenting the AddRef done during AddChild). 
 */
  virtual void Empty();

 /** @deprecated R422 CATBaseUnknown::Release
 * Replaced by Release with the activation of AddRef-Release mechanism.
 * Destroy internally does Release but also removes itself from its parents, updates their bounding boxes and unreferences itself from VisuManager. Now all this is done in the destructor.
 * So if you just want to give back the hand you have on rep, call Release.
 * Else if you want to remove the rep completely from scene graph, then you can call RemoveChild on its parents and finally Release.
 */
  virtual void Destroy();

  /** Constructs an empty 3D bag representation. 
  * Reference-count of the returned rep is 1.
  * Use Release method to delete/disown the rep at the end of your operations.
  */
  static CAT3DBagRep* CreateRep();
    
protected:

  BEGIN_MIGRATE_REP_CTOR_PRIVATE
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Use CAT3DFinalBagRep if you want to derive this class" )
#endif
    /** @nodoc : deprecated R417 : Use CreateRep instead.*/
  CAT3DBagRep();

  /** @nodoc : deprecated constructor. */
  CAT3DBagRep (CATModelIdentificator &id,CATVisuController *ctrl=NULL);
  END_MIGRATE_REP_CTOR

public:
    
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
   * Internally it calls AddRef on child if child is successfully added. BUT you don't need to call Release explicitly (because child gets released during destruction of parent).
   */
  virtual HRESULT AddChild(CATRep &iRep);

  /**
   * Adds a child graphic representation to the bag.
   * The bounding element of the bag is not updated. 
   * @param iRep
   * Child representation to be added.
   * Internally it calls AddRef on child if child is successfully added. BUT you don't need to call Release explicitly (because child gets released during destruction of parent).
   */
  virtual HRESULT AddChildren(CATRep & iRep);

  /** Removes a child representation from the bag.
   * The bounding element of the bag is updated.
   * @param iRep
   * Child representation to be removed.
   * Internally it calls Release on child if child is successfully removed (complimenting the AddRef done during AddChild).
   */
  virtual void RemoveChild(CATRep &iRep);
  
  /** Removes a child representation from the bag.
   * The bounding element of the bag is not updated.
   * @param iRep
   * Child representation to be removed.
   * Internally it calls Release on child if child is successfully removed (complimenting the AddRef done during AddChild).
   */
  virtual void RemoveChildren(CATRep &iRep);

  /** Returns the list of children representations. */
  ::list<CATRep> *GetChildren ();

  /** @nodoc */
  virtual void Draw(CATRender & iRender, int iInside);

  /** @nodoc */
  virtual void DrawShading(CATRender &ioRender, int iInside);

  /** @nodoc */
  virtual void DrawPath(CATRender &ioRender, int iInside, CATRepPath &ioPath); 

  /** Tests whether the representation will draw its graphic primitives.
   * See CATRep::OkToDraw(CATRender & ioRender, int * ioInside)
   */
  virtual int  IsOkToDraw(CATRender &ioRender, int ioInside);

  /** @nodoc */
  virtual void SortGraphicAttributeSet();

  /** Sets the highlight mode of the bag.
   * @param iHighlightMode
   * <ul>
   * 0 : bag is not highlighted <li>
   * 1 : bag is highlighted <li>
   * </ul>
   * @param iPropagationMode
   * <ul>
   * 0 : highlight mode is not propagated to children representations <li>
   * 1 : highlight mode is propagated to children representations <li>
   * </ul>
   */
  virtual void SetHighlightMode(int iHighlightMode, int iPropagationMode=0);

  /** Sets the show mode of the bag.
   * @param iShowMode
   * <ul>
   * 0 : bag is not visible <li>
   * 1 : bag is visible <li>
   * </ul>
   * @param iPropagationMode
   * <ul>
   * 0 : show mode is not propagated to children representations <li>
   * 1 : show mode is propagated to children representations <li>
   * </ul>
   */
  virtual void SetShowMode(int iShowMode, int iPropagationMode=0);
    
  /** @nodoc */
  // Compute the BE for the Noshow space
  const CAT3DBoundingSphere &GetNoshowBoundingElement(int & ioIsOneRepNoshow);

  /** @nodoc */
  // Compute the BE for the Show space
  const CAT3DBoundingSphere &GetShowBoundingElement();

  /** @nodoc */
  virtual int IsUVMeshToCompute() const;

  /** @nodoc */
  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

  /** @nodoc */
  virtual HRESULT SetUuid(const CATUuid & uuid);

  /** @nodoc */
  virtual HRESULT GetUuid(CATUuid & uuid);

protected:

  /** Updates the bounding element of the bag with regards to <tt>iBoundingSphere</tt>. */
  void UpdateBoundingElement(const CAT3DBoundingSphere & iBoundingSphere); 

  /** @nodoc */
  void DrawPathWithoutFilter(CATRender &render, int ioInside, CATRepPath &ioPath);

  CAT4x4Matrix *_the_MatPosi;      // position and orientation of the bag.
  ::list<CATRep>  _the_Son_List;     // the list of children representations.    
  CATUuid *_uuid;

private:
  /** @nodoc */
  //CAT3DBagRep (const CAT3DBagRep &);
  /** @nodoc */
  //CAT3DBagRep & operator = (const CAT3DBagRep &);

  void DestroyInternal(); //Internal Clean up code

};

#endif // CAT3DBagRep_H
