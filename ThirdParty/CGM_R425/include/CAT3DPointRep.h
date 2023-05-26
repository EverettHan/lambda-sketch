#ifndef CAT3DPointRep_H
#define CAT3DPointRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CAT3DRep.h"
#include "CAT3DMarkerGP.h"
#include "CATMathPointf.h"
#include "SGInfra.h"
#include "CATVisMacroForInterfaces.h"

class IVisSG3DPrimitiveIterator;
class CAT3DPointRepIVisSG3DPrimitiveIteratorBOAImpl;

/**
 * Class to create the representation of a point.
 * <b>Role</b>: This class is used to represent a point. Different symbols are available.
 * 
 */
class ExportedBySGInfra CAT3DPointRep : public CAT3DRep
{
 friend class CATMarshallable3DPointRep;
 friend class CATDmuStream3DPointRep;
 friend class CATVrmlMaker3DPointRep;
 friend class CATVrml2Maker3DPointRep;
 friend class SGCGRStreamerForPointRep;
 friend class SGCGRNodesFactoryA;
 CATDeclareClass;
 CATVisDeclarePublicInterfaceAdhesion(CAT3DPointRep, IVisSG3DPrimitiveIterator, CAT3DPointRepIVisSG3DPrimitiveIteratorBOAImpl);

 public:

  virtual ~CAT3DPointRep();

  /** Constructs the representation of a point. */
  static CAT3DPointRep* CreateRep(); 

  /** Constructs the representation of a point.
   * @param iCoordinates
   * The point to be represented.
   * @param iSymbol
   * The symbol used to visualize the point.
   */
  static CAT3DPointRep* CreateRep(const CATMathPointf & iPoint,
                                  CATSymbolType         iSymbol = CROSS);

protected:

  /** @nodoc : deprecated R417 : Use CreateRep instead.*/
  CAT3DPointRep (); 

  /** @nodoc : deprecated R417 : Use CreateRep instead.*/
  CAT3DPointRep (const CATMathPointf & iPoint,
                 CATSymbolType         iSymbol = CROSS);

  /** @nodoc : deprecated constructor. */
  CAT3DPointRep (CATModelIdentificator & iModelId,
                 void     * iController);
  
  /** @nodoc : deprecated constructor. */
  CAT3DPointRep (const CATMathPointf   & iPoint,
                 CATSymbolType           iSymbol,
                 CATModelIdentificator & iModelId,
                 void     * iController = NULL);

public:

  /** Returns the coordinates of the point. */
  CATMathPointf GetPoint() const;

  /** Modifies the coordinates of the representation of a point.
   * @param iPoint
   * The new coordinates of the point.
   */
  void Modify (const CATMathPointf & iPoint);

  /** Modifies the symbol of the represented of a point.
   * @param iSymbol
   * The new symbol to be used.
   */
  void SetSymbol (CATSymbolType iSymbol);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
#endif
  /** @nodoc */
  virtual void DrawShading (CATRender & iRender, int iInside) FUNC_OVERRIDE_FINAL;

#ifdef CATIAR426
  /** @nodoc */
  virtual void DrawPath(CATRender& render, int inside, CATRepPath& path) FUNC_OVERRIDE_FINAL;
  /** @nodoc */
  virtual void Draw(CATRender& iRender, int iInside) FUNC_OVERRIDE_FINAL;
  /** @nodoc */
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) FUNC_OVERRIDE_FINAL;
#endif


  /** @nodoc */
  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

  /** @nodoc */
  virtual int GetGeomIndex(const CATGraphicPrimitive * gp);

 protected:

  /* @nodoc */
  void BuildPoint (const CATMathPointf &point, CATSymbolType symbol);

  /** @nodoc */
  virtual const vDrawInformation* GetDrawInformation();

  // data
  CAT3DMarkerGP *_geometrie;
};

#endif // CAT3DPointRep_H
