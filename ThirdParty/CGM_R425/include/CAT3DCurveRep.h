#ifndef CAT3DCurveRep_H
#define CAT3DCurveRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CAT3DRep.h"
#include "CAT3DPolylineGP.h"
#include "SGInfra.h"

//class CATRender;
//class CATModelIdentificator;
//class CATGraphicPrimitive;

class CAT3DPolylineGP;
class CATVisuController;

/**
 * Class to create the representation of a curve.
 * <b>Role</b>: This representation is a collection of <tt>CAT3DLineGP</tt>,
 * each one representing a Level of Detail (LOD).
 * LOD should be added in the order of increasing tessellation accuracy factor.
 * Example :
 * <ul>
 * <li> lod 0 => sag = 0.10 </li>
 * <li> lod 1 => sag = 0.25 </li>
 * <li> lod 3 => sag = 0.50 </li>
 * </ul>
 */
class ExportedBySGInfra CAT3DCurveRep : public CAT3DRep
{
  friend class CATMarshallable3DCurveRep;
  friend class CATDmuStream3DCurveRep;
  friend class CATVrmlMaker3DCurveRep;
  friend class CATVrml2Maker3DCurveRep;
  friend class SGCGRStreamerForCurveRep;
  friend class SGCGRNodesFactoryA;
  CATDeclareClass;
  
  
public:

  virtual ~CAT3DCurveRep();

  /** Constructs an empty representation of a curve. */
  static CAT3DCurveRep* CreateRep();

protected:

  /** @nodoc : deprecated R417 : Use CreateRep instead.*/
  CAT3DCurveRep();

  /** @nodoc */
  CAT3DCurveRep (CATModelIdentificator &one_ident, CATVisuController *iCntl);

public:

  /** @nodoc */
  virtual HRESULT __stdcall QueryInterface(const IID &iIID, void **oPPV);

  /**
   * Adds a level of detail. <tt>iLODNumber</tt> and <tt>iSag</tt> must increase concurrently.
   * @param iLODNumber
   * This number identifies the LOD.
   * @param iGP
   * The graphic primitive associated to the LOD.
   * @param iSag
   * The tesselation accuracy used to create <tt>iGP</tt>
*/
  virtual void AddWireframeLOD (int               iLODNumber,
                                CAT3DPolylineGP * iGP,
                                float             iSag);
    
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
#endif
  /** @nodoc */
  virtual void DrawShading (CATRender & iRender, int iInside) FUNC_OVERRIDE_FINAL;

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
   * Retrieves the number of Wireframe LOD.
   */
  int  GetNbWireframeLODs();

  /** Retrieves one specific Wireframe LOD.
   * @param iLODNumber
   * This number identifies the LOD.
   * @param oGP
   * The graphic primitive associated to the LOD.
   * @param oSag
   * The tesselation accuracy used to create <tt>iGP</tt>
   */  
  void GetWireframeLOD(int iLODNumber, CAT3DPolylineGP * & oGP, float & oSag);

  /** @nodoc */
  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

  /** @nodoc */
  virtual int GetGeomIndex(const CATGraphicPrimitive * gp);

protected:
  /** @nodoc */
  virtual const vDrawInformation* GetDrawInformation();
    
  CAT3DPolylineGP ** _lodWireframe;          // list of CAT3DLineGP.  
  int                _nbLOD;                 // Number of levels of detail.
  float            * _fleches;               // Accuracies of levels of detail.
};

#endif // CAT3DCurveRep_H
