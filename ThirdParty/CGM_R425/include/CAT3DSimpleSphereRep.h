#ifndef CAT3DSimpleSphereRep_H
#define CAT3DSimpleSphereRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CAT3DRep.h"
#include "SGInfra.h"
#include "CATRepPath.h"

class CATRender;
class CAT3DFaceGP;
class CATMathPointf;

/**
 * Class to create the representation of a sphere.
 * <b>Role</b>: View a sphere.
 */  
class ExportedBySGInfra CAT3DSimpleSphereRep : public CAT3DRep
{
  CATDeclareClass;

public:

  /**Constructs a CAT3DSimpleSphereRep representation. */
  static CAT3DSimpleSphereRep* CreateRep(const CATMathPointf & iCenter,
                                          float         iRadius,
                                          int           iFactor = 32);

  /**Constructs a CAT3DSimpleSphereRep representation. */
  static CAT3DSimpleSphereRep* CreateRep(const CATMathPointf & iCenter,
                                          float         iRadius,
                                          int           iFactor,
                                          int			 UpDown);

  ~CAT3DSimpleSphereRep();

  /** @deprecated R422 CAT3DSimpleSphereRep::CreateRep */
  CAT3DSimpleSphereRep(CATMathPointf iCenter,
                       float         iRadius,
                       int           iFactor = 32);

  /** @nodoc : deprecated constructor. */
  CAT3DSimpleSphereRep(CATMathPointf           iCenter,
                       float                   iRadius,
                       int                     iFactor,
                       CATModelIdentificator & iIdent,
                       CATVisuController     * iController = NULL);

  /** @deprecated R422 CAT3DSimpleSphereRep::CreateRep */
  CAT3DSimpleSphereRep(CATMathPointf iCenter,
                       float         iRadius,
                       int           iFactor,
					   int			 UpDown);

  virtual HRESULT __stdcall QueryInterface(const IID &iIID, void **oPPV);

  /** @nodoc */
  virtual void UpdateTextureCoordinates(CATMappingOperator* iOperator = NULL);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
#endif
  /** @nodoc */
  virtual void DrawShading(CATRender & iRender, int iInside) FUNC_OVERRIDE_FINAL;

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

  /** @nodoc */
  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

  /** @nodoc */
  virtual int GetGeomIndex(const CATGraphicPrimitive * gp);

protected:

  /** @nodoc */
  CAT3DFaceGP * BuildFaces(CATMathPointf iCenter, float iRadius, int iFactor = 32, int upDown = 0);

  virtual const vDrawInformation* GetDrawInformation();

private:
  CAT3DFaceGP  * sphere_;
};


#endif // CAT3DSimpleSphereRep_H
