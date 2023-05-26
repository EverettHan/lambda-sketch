#ifndef CAT2DBagRep_H
#define CAT2DBagRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */




#include "SGInfra.h"
#include "CAT2DRep.h"

class CAT3x3Matrix;

//++ SGCAAPlan
#include "CATVisMacroForInterfaces.h"
class IVisSG2DNodeGroup;
class CAT2DBagRepIVisSG2DNodeGroupBOAImpl;
//-- SGCAAPlan

/**
* Class to create a representation of a 2D bag.
* <b>Role</b>:
* This object is the main tool for the definition of a representation tree.
* It manages a list of children representations, and a position matrix, thus
* defining a complete spatial graph node.<br>
* The CAT2DBagRep has to be created empty, then children can be added or
* removed using the AddChild and RemoveChild methods. There's no control on
* the way children are being added or removed. Caution has to be taken in
* order to avoid the definition of cycles.
*/
class ExportedBySGInfra CAT2DBagRep : public CAT2DRep
{

  friend class CATDmuStream2DBagRep;
  friend class CATVrml2Maker2DBagRep;
  friend class CATVrml2Maker2DBagRep;
  friend class SGCGRNodesFactoryA;
  friend class CAT2DFilterBagRep;
  friend class CAT2DFinalBagRep;
  friend class CAT2DScissorBagRep;
  friend class CAT2DBagRepWithToleranceScale;
  friend class Vis2DFixedSizeNodeGroupRep;

  CATDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT2DBagRep, IVisSG2DNodeGroup, CAT2DBagRepIVisSG2DNodeGroupBOAImpl);

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
  virtual HRESULT StartIterationOnChildren(void*& iContext);
  /** @nodoc */
  virtual HRESULT GetNextChild(void*& iContext, CATRep*& opChildRep);
  /** @nodoc */
  virtual HRESULT EndIterationOnChildren(void*& iContext);

  /** @nodoc */
  virtual HRESULT AddChild(CATRep* ipChildRep);
  /** @nodoc */
  virtual HRESULT RemoveChild(CATRep* ipChildRep);
  //-- SGCAAPlan

  /** Constructs an empty 2D bag representation.
  * Reference-count of the returned rep is 1.
  * Use Release method to delete/disown the rep at the end of your operations.
  */
  static CAT2DBagRep* CreateRep();

  /**
  * @nodoc : deprecated constructor.
  */
  static CAT2DBagRep* CreateRep(CATModelIdentificator& iId, CATVisuController* ctrl = NULL);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 08042022 " __FILE__ " Use CreateRep to instantiate the class OR CAT2DFinalBagRep to derive" )
#endif
  BEGIN_MIGRATE_REP_CTOR_PRIVATE
  /**
  * @deprecated R422
  * Use @href CAT2DBagRep#CreateRep
  */
  CAT2DBagRep(void);

  /**
  * @nodoc : deprecated constructor.
  */
  CAT2DBagRep(CATModelIdentificator& iId, CATVisuController* ctrl = NULL);
  END_MIGRATE_REP_CTOR

  virtual ~CAT2DBagRep(void);

  /** Removes (not deletes) all the children of the bag.
  * Internally it calls Release on all the children (complimenting the AddRef done during AddChild).
  */
  virtual void Empty();

  /** @deprecated R422 CATBaseUnknown::Release
  * Replaced by Release with the activation of AddRef-Release mechanism.
  * Destroy internally does Release but also removes itself from its parents, updates their bounding boxes and unreferences itself from VisuManager. Now all this is done in the destructor.
  * So if you just want to give back the hand you have on rep, call Release
  * Else if you want to remove the rep completely from scene graph, then you can call RemoveChild on its parents and finally Release
  */
  virtual void Destroy(void);

  /**
  * Computes the bounding element of the bag rep.
  * With this method, bounding elements of father's bagreps are computed too.
  */
  virtual void ComputeBoundingElement(int iShowSpace = 1);


  /**
  * Returns the matrix of the 2D bag representation.
  */
  const CAT3x3Matrix* GetMatrix(void) const;

  /**
  * Sets the matrix of the 2D bag representation.
  */
  void SetMatrix(const CAT3x3Matrix& iMath);

  /**
  * Resets the matrix of the 2D bag representation.
  */
  void ResetMatrix(void);


  /**
  * Adds a 2D representation in the 2D bag representation.
  *	@param iRep
  *		The 2D representation to add in the bag representation.
  * Internally it calls AddRef on child if child is added successfully. BUT you don't need to call Release explicitly (because child gets released during destruction of parent).
  */
  virtual HRESULT AddChild(CATRep& iRep);

  /**
  * Removes a representation in the 2D bag representation.
  *	@param iRep
  *		The representation to remove in the bag representation.
  * Internally it calls Release on child if child is removed successfully (complimenting the AddRef done during AddChild).
  */
  virtual void RemoveChild(CATRep& iRep);

  /**
  * Removes a representation in the 2D bag representation but does not compute the new bounding element.
  *	@param iRep
  *		The representation to remove in the bag representation.
  * Internally it calls Release on child if child is removed successfully (complimenting the AddRef done during AddChild).
  */
  virtual void RemoveChildren(CATRep& iRep);

  /**
  * Returns a list of representations which are in the 2D bag represenation.
  */
  ::list<CATRep>* GetChildren(void);


  /**
  * @nodoc .
  */
  virtual void Draw(CATRender& render, int inside);
  /**
  * @nodoc .
  */
  virtual void DrawShading(CATRender& ioRender, int iInside);
  /**
  * @nodoc .
  */
  virtual void DrawPath(CATRender& ioRender, int, CATRepPath& ioPath);
  /**
  * @nodoc .
  */
  virtual int  IsOkToDraw(CATRender& ioRender, int iInside);

  /** @nodoc : deprecated method. */
  virtual void SortGraphicAttributeSet(void);

  /**
  * Sets the highlight mode of the representation.
  * @param iHighlightMode
  * <br><b><Legal Values</b>:
  * <ol>
  *<li> 0 :  none</li>
  *<li> 1 :  highlight</li>
  * </ol>
  * @param iPropagationMode
  * <br><b><Legal Values</b>:
  * <ol>
  *<li> 0 :  just sets the highlight mode of the 2D bag representation </li>
  *<li> 1 :  sets the highlight mode of the 2D bag representation and
  *		   propagates this highlight mode to all representations which are in the bag
  *		   representation.</li>
  * </ol>
  * The default value is 0;
  */
  virtual void SetHighlightMode(int iHighlightmode, int iPropagationmode = 0);

  /**
  * Sets the show mode of the representation.
  * @param iShowmode
  * <br><b><Legal Values</b>:
  * <ol>
  *<li> 0 :  show</li>
  *<li> 1 :  noshow</li>
  * </ol>
  * @param iPropagationMode
  * <br><b><Legal Values</b>:
  * <ol>
  *<li> 0 :  just sets the show mode of the 2D bag representation </li>
  *<li> 1 :  sets the show mode of the 2D bag representation and
  *		   propagates this show mode to all representations which are in the bag
  *		   representation.</li>
  * </ol>
  * The default value is 0;
  */
  virtual void SetShowMode(int iShowmode, int iPropagationmode = 0);



  /** @nodoc */
  // Compute the BE for the Noshow space
  const CAT2DBoundingBox& GetNoshowBoundingElement(int& ioIsOneRepNoshow);

  /** @nodoc */
  // Compute the BE for the Show space
  const CAT2DBoundingBox& GetShowBoundingElement();

protected:

  /**
  * Updates the bounding element of the bag rep when one son bounding element has changed.
  * @param iBe
  *	the bounding element to update tba bagrep's bouding element.
  */
  virtual void UpdateBoundingElement(const CAT2DBoundingBox& iBe);

  /** @nodoc */
  virtual const vDrawInformation* GetDrawInformation();

  CAT3x3Matrix* _the_MatPosi;
  ::list<CATRep>  _the_Son_List;

private:

  /** @nodoc */
  //CAT2DBagRep (const CAT2DBagRep &);
  /** @nodoc */
  //CAT2DBagRep & operator = (const CAT2DBagRep &);

  void DestroyInternal(); //Internal Clean up code
  bool _legacy_destroy; //This is needed to avoid failure in legacy behavior (Legacy code doesn't destroy children in destructor). 
                                           //New API of CreateRep will have new behavior (deprecating constructor): With this, it will be similar to CAT3DBagRep
};

#endif
