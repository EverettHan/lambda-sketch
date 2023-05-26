#ifndef CAT2DCustomRep_H
#define CAT2DCustomRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "SGInfra.h"
#include "CAT2DRep.h"

class CATGraphicPrimitive;
class CATGraphicAttributeSet;

//++ SGCAAPlan
#include "CATVisMacroForInterfaces.h"
class IVisSG2DPrimitiveGroup;
class CAT2DCustomRepIVisSG2DPrimitiveGroupBOAImpl;
//-- SGCAAPlan

/**
 * Class to manage a collection of 2D graphic primitives with different graphic attributes.
 * <b>Role</b>:
 *	The primitives that are being added to the representation are not copied
 *	within it. The graphical attributes are copied inside the representation.
 */
class ExportedBySGInfra CAT2DCustomRep : public CAT2DRep
{
  friend class CATDmuStream2DCustomRep;
  friend class CATVrml2Maker2DCustomRep;
  friend class CATVrmlMaker2DCustomRep;
  friend class SGCGRStreamerFor2DCustomRep;
  CATDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT2DCustomRep, IVisSG2DPrimitiveGroup, CAT2DCustomRepIVisSG2DPrimitiveGroupBOAImpl);

public:

  /**
  * Contructs an empty 2D custom representation.
  */
  static CAT2DCustomRep* CreateRep(void);

  /** Contructs a 2D custom representation with one graphic primitive.
    * @param iGraphicPrimitive
    * The primitive
    * (It is not copied inside the representation).
    * @param iGraphicAttribut
    * The graphic attributes of <tt>iGraphicPrimitive</tt>.
  */
  static CAT2DCustomRep* CreateRep(CATGraphicPrimitive* iGraphicPrimitive, const CATGraphicAttributeSet& iGraphicAttribut);

  /**
 * @nodoc : deprecated constructor.
 */
  static CAT2DCustomRep* CreateRep(list<CATGraphicPrimitive>& gp, list<CATGraphicAttributeSet>& att);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 08042022 " __FILE__ " Use CreateRep to instantiate the class " )
#endif
  BEGIN_MIGRATE_REP_CTOR_PROTECTED
  /**
  * @nodoc : deprecated R422 CAT2DCustomRep::CreateRep
   * Contructs an empty 2D custom representation.
   */
  CAT2DCustomRep(void);

  /**
  * @deprecated R422 CAT2DCustomRep::CreateRep
  * Contructs a 2D custom representation with one graphic primitive.
   * @param iGraphicPrimitive
   * The primitive
   * (It is not copied inside the representation).
   * @param iGraphicAttribut
   * The graphic attributes of <tt>iGraphicPrimitive</tt>.
   */
  CAT2DCustomRep(CATGraphicPrimitive* iGraphicPrimitive, const CATGraphicAttributeSet& iGraphicAttribut);
  END_MIGRATE_REP_CTOR

  virtual ~CAT2DCustomRep(void);

  /**
   * @nodoc : deprecated constructor.
   */
  CAT2DCustomRep(list<CATGraphicPrimitive>& gp, list<CATGraphicAttributeSet>& att);


  /** Adds a graphic primitive to the list of managed graphic primitives.
   * @param iGraphicPrimitive
   * The primitive to be added.
   * (It is not copied inside the representation).
   * @param iGraphicAttribut
   * The graphic attributes of <tt>iGraphicPrimitive</tt>.
   */
  virtual void AddGP(CATGraphicPrimitive* iGraphicPrimitive, const CATGraphicAttributeSet& iGraphicAttribut);

  /**
  * Adds a list of GPs to the CustomRep.
  * @param iListOfGPs
  *    The list of GPs to be added to the CustomRep.
  *    Each GP pointer must not be null.
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
  HRESULT AddListOfGPs(CATGraphicPrimitive** iListOfGPs, CATGraphicAttributeSet** iListOfAtt, unsigned int iListSize);

  /** Removes a graphic primitive from the list of managed graphic primitives.
   * @param iGraphicPrimitive
   * The primitive to be removed. The caller must delete the graphic primitive.
   */
  virtual void RemoveGP(CATGraphicPrimitive* iGraphicPrimitive);

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
   */
  virtual void Modify(CATGraphicPrimitive* iOldGraphicPrimitive,
    CATGraphicPrimitive* iNewGraphicPrimitive,
    CATGraphicAttributeSet* iNewGraphicAttribut);


  /** Returns a graphic primitive from the list of managed graphic primitives.
   * @param iIndex
   *	Index value in the list of managed graphic primitives.
   *	Legal values are [0,<tt>GetGPSize()</tt>-1].
   */
  virtual CATGraphicPrimitive* GetGP(const int iIndex) const;


  /** Returns the graphic attributes associated with a managed graphic primitive.
   * @param iIndex
   * Index value in the list of managed graphic primitives.
   * Legal values are [0,<tt>GetGPSize()</tt>-1].
   * @param oGAS
   * Reference to a CATGraphicAttributeSet that will hold the result
   */
  virtual void GetAttribut(const int iIndex, CATGraphicAttributeSet& oGAS) const;

  /** Set the graphic attributes associated with a managed graphic primitive.
   * @param iIndex
   * Index value in the list of managed graphic primitives.
   * Legal values are [0,<tt>GetGPSize()</tt>-1].
   * @param iGAS
   * Reference to a CATGraphicAttributeSet
   */
  virtual void SetAttribut(const int iIndex, CATGraphicAttributeSet const& iGAS);

  /** Returns the number of managed graphic primitives. */
  virtual int GetGPSize(void) const;

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
#endif
  /**
   * @nodoc .
   */
  virtual void DrawShading(CATRender&, int) FUNC_OVERRIDE_FINAL;

#ifdef CATIAR426
  /**
  * @nodoc
  */
  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) FUNC_OVERRIDE_FINAL;
  /**
  * @nodoc
  */
  virtual void Draw(CATRender& iRender, int iInside) FUNC_OVERRIDE_FINAL;
  /**
  * @nodoc
  */
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) FUNC_OVERRIDE_FINAL;
#endif

  /**
   * @nodoc .
   */
  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

protected:

  /**
   * @nodoc .
   */
  void IncreaseLists(int size_to_add);

  /** @nodoc */
  virtual const vDrawInformation* GetDrawInformation();

  /** @nodoc */
  int _mem_size;
  /** @nodoc */
  int _size;
  /** @nodoc */
  CATGraphicPrimitive** _gp;
  /** @nodoc */

private:
  CATGraphicAttributeSet** _att;
};


#endif 









