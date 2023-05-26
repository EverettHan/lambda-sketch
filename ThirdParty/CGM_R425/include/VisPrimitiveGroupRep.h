#ifndef VISPRIMITIVEGROUPREP_H
#define VISPRIMITIVEGROUPREP_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "SGInfra.h"
#include "CAT3DRep.h"


class VisPrimitive;
class VisAttribute;

//++ SGCAAPlan
#include "CATVisMacroForInterfaces.h"
class IVisSG3DPrimitiveGroup;
class IVisSG3DPrimitive;

class VisPickingAlgorithm;

class vDrawInformation;

class CATPolitnessHighlightCullingRender;

//-- SGCAAPlan

/** Class to manage a collection of graphic primitives with different graphic attributes. */
class ExportedBySGInfra VisPrimitiveGroupRep : public CAT3DRep
{
  CATDeclareClass;

 
  friend class vImplDrawable_VisPrimitiveGroupRep;
public:

  //++ SGCAAPlan
  /** @nodoc */
  CATVisDeclarePublicInterfaceAdhesion(VisPrimitiveGroupRep, IVisSG3DPrimitiveGroup, VisPrimitiveGroupRepIVisSG3DPrimitiveGroupBOAImpl);

  ULONG __stdcall Release( void);

  HRESULT StartIteration(void*& ioContext);

  HRESULT GetNext(void*& ioContext, void*& oPrimitiveKey);

  HRESULT EndIteration(void*& ioContext);

  HRESULT GetPrimitive(const void*& iPrimitiveKey, IVisSG3DPrimitive* & opPrimitive);

  HRESULT GetPrimitiveAttribute(const void*& iPrimitiveKey, const VisAttributeID iAttributeID, const VisDataType iType, void *oValue);

  HRESULT AddPrimitive(IVisSG3DPrimitive* ip3DPrimitive, void*& oPrimitiveKey);

  HRESULT SetPrimitiveAttribute(const void*& iPrimitiveKey, const VisAttributeID iAttributeID, const VisDataType iType, void *iValue);

  HRESULT RemovePrimitive(IVisSG3DPrimitive* ip3DPrimitive);

  //-- SGCAAPlan

protected:

  // Construction and destruction methods:
  // -------------------------------------
  //   The primitive argument is not copied inside the representation,
  //   The attribute argument is duplicated inside the representation.
    
  virtual ~VisPrimitiveGroupRep ();

public:

  /** Contructs an empty custom representation. */
  static VisPrimitiveGroupRep* CreateRep();

  /** Contructs a custom representation with one graphic primitive.
   * @param iVisPrimitive
   * Do not delete this graphic primitive.
   * @param iGraphicAttribut
   * The graphic attributes of <tt>iVisPrimitive</tt>.
   */
  static VisPrimitiveGroupRep* CreateRep(VisPrimitive * iVisPrimitive,
                                   const VisAttribute & iGraphicAttribut);

protected:

  /** @deprecated R417 : Use CreateRep instead.*/
  VisPrimitiveGroupRep();

  /** @deprecated R417 : Use CreateRep instead.*/
  VisPrimitiveGroupRep (VisPrimitive * iVisPrimitive,
                  const VisAttribute & iGraphicAttribut);

public:


  /** Deletes the representation. Do not use the <tt>delete</tt> operator for this purpose. */
  virtual void Destroy();

  /** Adds a graphic primitive to the list of managed graphic primitives.
   * @param iVisPrimitive
   * Do not delete this graphic primitive.
   * @param iGraphicAttribut
   * The graphic attributes of <tt>iVisPrimitive</tt>.
   */
  virtual void AddVisPrimitive(VisPrimitive * iVisPrimitive,
                     const VisAttribute & iGraphicAttribut);

  /** Removes a graphic primitive from the list of managed graphic primitives.
   * @param iVisPrimitive
   * The caller must delete the graphic primitive.
   */
  virtual void RemoveVisPrimitive(VisPrimitive * iVisPrimitive);


  /** Replaces a graphic primitive in the list of managed graphic primitives.
   * @param iOldVisPrimitive
   * The graphic primitive to be removed.
   * The caller must delete the graphic primitive.
   * @param iNewVisPrimitive
   * The graphic primitive to be inserted.
   * The caller must not delete the graphic primitive.
   * @param iNewGraphicAttribut
   * The graphic attributes of <tt>iNewGraphicAttribut</tt>.
   * If NULL, the graphic attributes of <tt>iOldVisPrimitive</tt> are kept unchanged.
   * If not, the caller must delete the the graphic attributes.
   */
  virtual void Modify(VisPrimitive * iOldVisPrimitive,
                      VisPrimitive * iNewVisPrimitive,
                      VisAttribute * iNewGraphicAttribut);

  
  /** Returns the number of managed graphic primitives. */
  virtual int GetVisPrimitiveSize() const;

  /** Returns a graphic primitive from the list of managed graphic primitives.
   * @param iIndex
   * Index value in the list of managed graphic primitives.
   * Legal values are [0,<tt>GetVisPrimitiveSize()</tt>-1].
   */
  virtual VisPrimitive * GetVisPrimitive(const int iIndex) const;

  /** Returns the graphic attributes associated with a managed graphic primitive.
   * Do not delete the returned graphic primitive.
   * @param iIndex
   * Index value in the list of managed graphic primitives.
   * Legal values are [0,<tt>GetVisPrimitiveSize()</tt>-1].
   */
  virtual VisAttribute & GetAttribut(const int iIndex) const;

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
    
  // AZX: (A2X migration) Making draw functions final 
  /** @nodoc */
  virtual void DrawShading (CATRender & iRender, int iInside) override final;

  /** @nodoc */
  virtual void DrawPath    (CATRender & iRender, int iInside, CATRepPath & iRepPath) override final;
   
  /** @nodoc */
  virtual void Draw(CATRender& iRender, int iInside) override final;
  /** @nodoc */
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

  /** 
   * @nodoc
   *Returns the outline builder of the representation.
   * The representation retains ownership of the outline builder. Do not delete it.
   */
  virtual CATOutlineBuilder * GetOutlineBuilder(); 

  /**
   * @nodoc
   */
  void SetPickingAlgorithm(VisPickingAlgorithm* pickingAlgorithm);
    
  /** @nodoc */
  virtual const vDrawInformation* GetDrawInformation();
    
  void ClearDrawInformation() { _ClearDrawInformation(); }; // XK7 GPU_SKINNING ++

  void SetBoundingElement(const CAT3DBoundingSphere & iBoundingSphere);

protected:

  /** @nodoc */
  void IncreaseLists(int iSizeIncrement);
  
  /** @nodoc */
  static unsigned int GetKey(void*);
  
  /** @nodoc */
  static int Compare(void*, void*);
    
  int _mem_size;                  // size increment.
  int _size;                      // size of list of graphic primitives.
  VisPrimitive ** _visPrimitive;  // the list of graphic primitives.
  VisAttribute ** _att; // the list of associated graphic attributes.

private:
  VisPickingAlgorithm* _pickingAlgorithm;

  const vDrawInformation* _GetDrawInformation(bool iForce);

  void _ClearDrawInformation();
  void _NotifyObservers();
  void _DestroyPrimitives();

};

#endif // VISPRIMITIVEGROUPREP_H
