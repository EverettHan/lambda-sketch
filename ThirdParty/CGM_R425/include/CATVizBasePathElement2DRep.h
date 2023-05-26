#ifndef CATVizBasePathElement2DRep_h
#define CATVizBasePathElement2DRep_h

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "SGInfra.h"
#include "CAT2DRep.h"
#include "CATRepPath.h"
#include "CATMutex.h"

class CATRender;
class CATModelIdentificator;
class CATSupportAlgoFactory;
class vREViewpoint;

/**
  * Class .
  *
  */
class ExportedBySGInfra CATVizBasePathElement2DRep : public CAT2DRep
{
  friend class CATSupportAlgoFactory;
  friend class vREViewpoint;
  /** @nodoc */
  CATDeclareClass;

  public:
    
  /** @nodoc */
  CATVizBasePathElement2DRep(CATRepPath *iPathOfRep);

  /** @nodoc */
  CATVizBasePathElement2DRep(const CATVizBasePathElement2DRep &iRep);

  virtual ~CATVizBasePathElement2DRep();
	 
  // AZX: (A2X migration) Making draw functions final 
  /**
   * @see CAT2DRep#Draw
   */
  virtual void Draw          (CATRender &,int) override final; 
  /**
   * @see CAT2DRep#DrawShading
   */
  virtual void DrawShading( CATRender &, int) override final;

  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) override final;
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

  /** @nodoc */
  CATRepPath & GetRepPath() ;

  /**
   * Returns the @href CATRepPath associated to the CATPathElement2DRep.
   * @param <tt>CATRepPath *& oPath</tt>
   * [out] A pointer on the @href CATRepPath associated to the rep. AddRef is done on the pointer.
   * @return
   * Un <tt>HRESULT</tt>
   * <dl>
   * <dt> <tt>S_OK</tt>     <dd> The pointer was succesfully valuated.
   * <dt> <tt>E_FAIL</tt>   <dd> There is no @href CATRepPath associated to this rep.
   * </dl>
   */
  HRESULT GetRepPath( CATRepPath *& oPath );

  /** @nodoc */
  void SetInvalidDraw();

  protected:

  /**
   * This method is set to be called in order to update the CATRepPath associated to the rep.
   * Currently, it is called when an invalid reppath is detected in a highlight context.
   * @return
   * Un <tt>HRESULT</tt>
   * <dl>
   * <dt> <tt>S_OK</tt>     <dd> The reppath was successfully updated.
   * <dt> <tt>E_FAIL</tt>   <dd> The regeneration of the reppath failed.
   * </dl>
   */
    virtual HRESULT UpdateRepPath(void) //= 0; UO4 2022.07.01 Removed pure virtual
    {
      return E_FAIL;
    }

  virtual const vDrawInformation* GetDrawInformation();

  /** @nodoc */
  CATRepPath* _path;

  private:

  static CATMutex _mutexPathElement2DRep;
  int _invalidDraw;

};

#endif 
