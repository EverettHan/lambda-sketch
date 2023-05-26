#ifndef CAT3DCustomRep_H
#define CAT3DCustomRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//******************************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 1996   -  FMN  -
//******************************************************************************
//  Abstract:
//  ---------
//    This class contains a list of graphical primitives each of them being
//    associated to a graphical attribute. This means that the CAT3DCustomRep
//    can be used for almost any geometric description.
//
//******************************************************************************
//  Usage:
//  ------
//    It should be created empty, and then Graphical primitives are to be added,
//    with their corresponding Graphical Attribute. Nevertheless, construction
//    with a single primitive with it's attribute is provided.
//    
//    The primitives that are being added to the representation are not copied
//    within it. The graphical attributes are copied inside the representation.
//
//    Warning: Show/NoShow attribute is not handled at Graphical primitive level
//    (ie. you can not mix shown and hidden primitives). Therefore, always add
//    shown primitives, and use the rep's graphic attribute to show/hide
//    the entire rep.
//
//  Memory behavior:
//  ----------------
//    During object life, removed or replaced primitives are never destroyed by
//    the object. The user has to ensure the memory management of it's primi-
//    tives.
//    Object deletion causes the destruction of every primitives it contains.
//
//******************************************************************************
//  Inheritance:
//  ------------
//                CAT3DCustomRep
//                  CAT3DRep
//                    CATRep
//                      CATExtend (SYSTEM Framework).
//
//******************************************************************************
//  Main Methods:
//  -------------
//    Drawing.
//    Graphical attributes management.
//    GP list management.
//
//******************************************************************************

#include "SGInfra.h"
#include "CAT3DRep.h"

class CATGraphicPrimitive;
class CATGraphicAttributeSet;
class vDrawInformation;

//++ SGCAAPlan
#include "CATVisMacroForInterfaces.h"
class IVisSG3DPrimitiveGroup;
class CAT3DCustomRepIVisSG3DPrimitiveGroupBOAImpl;
//-- SGCAAPlan

/** Class to manage a collection of graphic primitives with different graphic attributes. */
class ExportedBySGInfra CAT3DCustomRep : public CAT3DRep
{
  friend class CATVrmlMaker3DCustomRep;
  friend class CATVrml2Maker3DCustomRep;
  friend class CATMarshallable3DCustomRep;
  friend class CATDmuStream3DCustomRep;
  friend class SGCGRStreamerFor3DCustomRep;
  CATDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT3DCustomRep, IVisSG3DPrimitiveGroup, CAT3DCustomRepIVisSG3DPrimitiveGroupBOAImpl);

public:

  // Construction and destruction methods:
  // -------------------------------------
  //   The primitive argument is not copied inside the representation,
  //   The attribute argument is duplicated inside the representation.
    
  virtual ~CAT3DCustomRep ();

  /** Contructs an empty custom representation. */
  static CAT3DCustomRep* CreateRep();
  
  /** Contructs a custom representation with one graphic primitive.
   * @param iGraphicPrimitive
   * Do not delete this graphic primitive.
   * @param iGraphicAttribut
   * The graphic attributes of <tt>iGraphicPrimitive</tt>.
   *
   * Warning: Show/NoShow attribute is not handled at Graphical primitive level
   * (ie. you can not mix shown and hidden primitives). Therefore, always add
   * shown primitives, and use the rep's graphic attribute to show/hide the entire rep.
   */
  static CAT3DCustomRep* CreateRep(CATGraphicPrimitive          * iGraphicPrimitive,
                                   const CATGraphicAttributeSet & iGraphicAttribut);
  
protected:

  /** @nodoc : deprecated R417 : Use CreateRep instead.*/
  CAT3DCustomRep();

  /** @nodoc : deprecated R417 : Use CreateRep instead.*/
  CAT3DCustomRep (CATGraphicPrimitive          * iGraphicPrimitive,
                  const CATGraphicAttributeSet & iGraphicAttribut);

  /** @nodoc : deprecated constructor. */
  CAT3DCustomRep (CATGraphicPrimitive *gp, const CATGraphicAttributeSet &att,
                  CATModelIdentificator &id,void *ctrl=NULL);

public:
  
  /** Deletes the representation. Do not use the <tt>delete</tt> operator for this purpose. */
  virtual void Destroy();

  /** Adds a graphic primitive to the list of managed graphic primitives.
   * @param iGraphicPrimitive
   * Do not delete this graphic primitive.
   * @param iGraphicAttribut
   * The graphic attributes of <tt>iGraphicPrimitive</tt>.
   * @return
   *  S_OK if the GraphicPrimitive was successfully added to the Rep
   *  E_FAIL otherwise. Failure can happen if the pointer is NULL, or if the GraphicPrimitive is in edition.
   *
   * Warning: Show/NoShow attribute is not handled at Graphical primitive level
   * (ie. you can not mix shown and hidden primitives). Therefore, always add
   * shown primitives, and use the rep's graphic attribute to show/hide the entire rep.
   */
  virtual HRESULT AddGP(CATGraphicPrimitive          * iGraphicPrimitive,
                     const CATGraphicAttributeSet & iGraphicAttribut);

  /**
  * Adds a list of GPs to the CustomRep.
  * @param iListOfGPs
  *    The list of GPs to be added to the CustomRep.
  *    Each GP pointer must not be null and the GP must not be in edition.
  *    No AddRef is done on this element and it will be released in destructor.
  * @param iListOfAtt
  *    The list of GP's GraphicAttribute.
  *    Each GP's GraphicAttribute pointer must not be null.
  *    It will be released in destructor.
  * @param iListSize
  *    The number of elements in <tt>iListOfGPs</tt> and <tt>iListOfAtt</tt>.
  * @return
  *    S_OK if everything went fine, E_FAIL if something went wrong and E_OUTOFMEMORY if no more memory was
  *    available to allocate internal data to hold the GPs<br>
  */
  HRESULT AddListOfGPs(CATGraphicPrimitive ** iListOfGPs, CATGraphicAttributeSet** iListOfAtt, unsigned int iListSize);

  /** Removes a graphic primitive from the list of managed graphic primitives.
   * @param iGraphicPrimitive
   * The caller must delete the graphic primitive.
   * @return
   *  S_OK if the GraphicPrimitive was successfully removed from the Rep
   *  E_FAIL otherwise. Failure can happen if the pointer is NULL, or if the GraphicPrimitive is in edition.
   */
  virtual HRESULT RemoveGP(CATGraphicPrimitive * iGraphicPrimitive);

  // Management of the list of Graphical Primitives:
  // -----------------------------------------------
  //   - AddGP: New primitive is added in last position in the primitive list.
  //   - RemoveGP: The removed primitive is not destroyed by the method.
  //   - Modify: Changes the <num_gp> gp with <new_gp>, which has <new_att>
  //     for graphical attribute. If <new_att> is NULL, the old graphical
  //     attribute is kept. If <new_att> is valid it is duplicated inside the
  //     representation. Deletion of the method parameter is to be made by the
  //     user. The <old_gp> is not destroyed by the method.

  /** Replaces a graphic primitive in the list of managed graphic primitives.
   * @param iOldGraphicPrimitive
   * The graphic primitive to be removed.
   * The caller must delete the graphic primitive.
   * @param iNewGraphicPrimitive
   * The graphic primitive to be inserted.
   * The caller must not delete the graphic primitive.
   * @param iNewGraphicAttribut
   * The graphic attributes of <tt>iNewGraphicAttribut</tt>.
   * If NULL, the graphic attributes of <tt>iOldGraphicPrimitive</tt> are kept unchanged.
   * If not, the caller must delete the the graphic attributes.
   * @return
   *  S_OK if the modification was performed
   *  E_FAIL otherwise. Failure can happen if the GP pointers are NULL, or if any of the GraphicPrimitive are in edition.
   *
   * Warning: Show/NoShow attribute is not handled at Graphical primitive level
   * (ie. you can not mix shown and hidden primitives). Therefore, always use 
   * shown primitives, and use the rep's graphic attribute to show/hide the entire rep.
   */
  virtual HRESULT Modify(CATGraphicPrimitive    * iOldGraphicPrimitive,
                         CATGraphicPrimitive    * iNewGraphicPrimitive,
                         CATGraphicAttributeSet * iNewGraphicAttribut);

  
  /** Returns the number of managed graphic primitives. */
  virtual int GetGPSize() const;

  /** Returns a graphic primitive from the list of managed graphic primitives.
   * @param iIndex
   * Index value in the list of managed graphic primitives.
   * Legal values are [0,<tt>GetGPSize()</tt>-1].
   */
  virtual CATGraphicPrimitive * GetGP(const int iIndex) const;

  /** Returns the graphic attributes associated with a managed graphic primitive.
   * @param iIndex
   * Index value in the list of managed graphic primitives.
   * Legal values are [0,<tt>GetGPSize()</tt>-1].
   * @param oGAS
   * Reference to a CATGraphicAttributeSet that will hold the result
   */
  virtual void GetAttribut(const int iIndex,CATGraphicAttributeSet& oGAS) const;

  /** Set the graphic attributes associated with a managed graphic primitive.
   * @param iIndex
   * Index value in the list of managed graphic primitives.
   * Legal values are [0,<tt>GetGPSize()</tt>-1].
   * @param iGAS
   * Reference to a CATGraphicAttributeSet
   */
  virtual void SetAttribut(const int iIndex,CATGraphicAttributeSet const& iGAS);

  /** Sets the pick mode of the representation.
   *<br><b>Role</b>:
   * the pick mode is propagated to the enclosed graphical primitives.
   * @param iPickMode
   * <ol>
   *<li> 0 : representation is pickable </li>
   *<li> 1 : representation is not pickable </li>
   * </ol>
   */
  virtual void SetPickMode(unsigned int iPickMode);

  /** @nodoc */
  virtual void UpdateTextureCoordinates(CATMappingOperator* iOperator = NULL);
    
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
#endif
  /** @nodoc */
  virtual void DrawShading (CATRender & iRender, int iInside) FUNC_OVERRIDE_FINAL;

  /** @nodoc */
  virtual void DrawPath    (CATRender & iRender, int iInside, CATRepPath & iRepPath) FUNC_OVERRIDE_FINAL;
  
#ifdef CATIAR426
  /** @nodoc */
  virtual void Draw(CATRender& iRender, int iInside) FUNC_OVERRIDE_FINAL;
  /** @nodoc */
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) FUNC_OVERRIDE_FINAL;
#endif

  /** @nodoc */
  const vDrawInformation* GetDrawInformation();
  
  /**
   * @nodoc
   *Returns the outline builder of the representation.
   * The representation retains ownership of the outline builder. Do not delete it.
   */
  virtual CATOutlineBuilder * GetOutlineBuilder(); 

  /** @nodoc */
  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

  /** @nodoc */
  virtual int GetGeomIndex(const CATGraphicPrimitive * gp);
    
  /** @nodoc */
  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

protected:

  /**
   * @nodoc
   */
  inline CATGraphicAttributeSet const& GetAttribut(const int iIndex) const;

  /** @nodoc */
  void IncreaseLists(int iSizeIncrement);
  
  /** @nodoc */
  static unsigned int GetKey(void*);
  
  /** @nodoc */
  static int Compare(void*, void*);
    
  int _mem_size;                  // size increment.
  int _size;                      // size of list of graphic primitives.
  CATGraphicPrimitive    ** _gp;  // the list of graphic primitives.

  CATOutlineBuilder *_builder;

private:
  CATGraphicAttributeSet ** _att; // the list of associated graphic attributes.	
};

inline CATGraphicAttributeSet const& CAT3DCustomRep::GetAttribut(const int iIndex) const
{
  return *_att[iIndex];
}

#endif // CAT3DCustomRep_H
