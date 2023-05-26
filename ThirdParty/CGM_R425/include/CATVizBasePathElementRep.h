#ifndef CATVizBasePathElementRep_h
#define CATVizBasePathElementRep_h

// COPYRIGHT DASSAULT SYSTEMES 2001

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "SGInfra.h"
#include "CAT3DRep.h"
#include "CATRepPath.h"
#include "CATMutex.h"
#include "CATColorPathElement.h"

class CATRender;
class CATModelIdentificator;
class CATSupportAlgoFactory;
class vREViewpoint;


/**
  * Class .
  *
  */
class ExportedBySGInfra CATVizBasePathElementRep : public CAT3DRep
{

  friend class CATSupportAlgoFactory;
  friend class vREViewpoint;
  /** @nodoc */
  CATDeclareClass;
public:
    
  /** @nodoc Shortcut used in vREViewpoint AND ONLY THERE*/
  using CATRep::SetObservable;

  /** @nodoc */
  CATVizBasePathElementRep(CATRepPath *iPathOfRep, int iForHighlight = 1);

  /** @nodoc */
  CATVizBasePathElementRep(const CATVizBasePathElementRep &iRep);

  virtual ~CATVizBasePathElementRep();
	 
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
#endif
  /** @nodoc */
  virtual void Draw          (CATRender &,int) FUNC_OVERRIDE_FINAL;
  /** @nodoc */
  virtual void DrawShading   (CATRender &, int) FUNC_OVERRIDE_FINAL;

#ifdef CATIAR426
  /** @nodoc */
  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) FUNC_OVERRIDE_FINAL;
  /** @nodoc */
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) FUNC_OVERRIDE_FINAL;
#endif

  /** @nodoc */
  CATRepPath & GetRepPath() ;

  /** @nodoc */
  void GetRepPath(CATRepPath *&oPath);
    
  /** @nodoc */
  void SetInvalidDraw();
   
  /** @nodoc */
  CATColorPathElement::eSlot GetMultiColorHighlightSlot() const;
  /** @nodoc */
  void SetColorSlot(const CATColorPathElement::eSlot iSlot);
  /** @nodoc */
  unsigned int IsForMultiColorHighlight() const;

  protected:

/**
 * Methode de mise a jour du reppath stocke dans _path.
 * Cette methode doit etre imperativement implementee par les classes derivee.
 * @return
 * Un <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> _path a bien ete regenere.
 * <dt> <tt>E_FAIL</tt>   <dd> La regeneration a echoue.
 * </dl>
 */
    virtual HRESULT UpdateRepPath( void );

  /** @nodoc */
  virtual const vDrawInformation* GetDrawInformation();

  /** @nodoc */
  CATRepPath* _path;

  /** @nodoc */
  void UpdateBoundingElement();

  //+++ multicolor highlight
  
  //Slot associated to a color (multicolor highlight feature)
  CATColorPathElement::eSlot _multicolorHighlightSlot;
  
  // Boolean which says if multicolor highlight is enabled (>0) or not (==0)
  // note: NEVER provides code a setter for this member in this class. (it's MANDATORY to let only CATColorPathElementRep to set this member to enable multicolor highlight)
  unsigned int _bMultiColorHighlight; 
  
  //--- multicolor highlight

  private:
  static CATMutex _mutexPathElementRep;
  int _invalidDraw;
  int _forHighlight;

};


#endif 
