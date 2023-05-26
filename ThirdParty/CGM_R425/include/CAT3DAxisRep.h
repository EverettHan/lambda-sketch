#ifndef CAT3DAxisRep_H
#define CAT3DAxisRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CAT3DRep.h"
#include "SGInfra.h"
#include "CATVisMacroForInterfaces.h"

class CAT3DAnnotationTextGP;
class CAT3DFixedArrowGP;
class CAT4x4Matrix;
class CATVisuController;

class IVisSG3DPrimitiveIterator;
class CAT3DAxisRepIVisSG3DPrimitiveIteratorBOAImpl;
  
/**
 * Class to create the representation of an axis system.
 * <b>Role</b>: view an axis system, possibly with arrow tips and labels.
 */
class ExportedBySGInfra CAT3DAxisRep : public CAT3DRep
{
  friend class CATMarshallable3DAxisRep;
  friend class CATDmuStream3DAxisRep;
  friend class SGCGRStreamerForAxisRep;
  friend class SGCGRNodesFactoryA;
  CATDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT3DAxisRep, IVisSG3DPrimitiveIterator, CAT3DAxisRepIVisSG3DPrimitiveIteratorBOAImpl);

public :

  virtual ~CAT3DAxisRep();

  /** Constructs the representation of an axis system. */
  static CAT3DAxisRep* CreateRep();

protected:

  /** @nodoc : deprecated R417 : Use CreateRep instead.*/
  CAT3DAxisRep();

  /** @nodoc */
  CAT3DAxisRep (CATModelIdentificator & one_ident,CATVisuController *iCntl);

public:


  /** Constructs the representation of an axis system.
   *  @param iMatrix
   *  The matrix defining the origin and the three directions of the axis system.
   *  @param iArrowShaftLength
   *  The length of the arrow shaft in mm.
   *  @param iArrowTipLength
   *  The length of the arrow tip in mm.
   */
  static CAT3DAxisRep* CreateRep(CAT4x4Matrix & iMatrix, int iArrowShaftLength, int iArrowTipLength = 5);

  /** @nodoc : deprecated R417 : Use CreateRep instead.*/
  CAT3DAxisRep(CAT4x4Matrix & iMatrix, int iArrowShaftLength, int iArrowTipLength = 5);

  /** Constructs the representation of an axis system.
   *  @param iMatrix
   *  The matrix defining the origin and the three directions of the axis system.
   *  @param iXArrowShaftLength
   *  The length (in mm) of the shaft of the first arrow. 
   *  @param iXLabel
   *  The text of the label of the first arrow.
   *  @param iYArrowShaftLength
   *  The length (in mm) of the shaft of the second arrow. 
   *  @param iYLabel
   *  The text of the label of the second arrow.
   *  @param iZArrowShaftLength
   *  The length (in mm) of the shaft of the third arrow. 
   *  @param iZLabel
   *  The text of the label of the third arrow.
   */
  static CAT3DAxisRep* CreateRep(CAT4x4Matrix & iMatrix,
                                 int iXArrowShaftLength, char * iXLabel,
                                 int iYArrowShaftLength, char * iYLabel,
                                 int iZArrowShaftLength, char * iZLabel);

  /** @nodoc : deprecated R417 : Use CreateRep instead.*/
  CAT3DAxisRep(CAT4x4Matrix & iMatrix,
               int iXArrowShaftLength, char * iXLabel,
               int iYArrowShaftLength, char * iYLabel,
               int iZArrowShaftLength, char * iZLabel);

  

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
#endif

  /** @nodoc */
  virtual void DrawShading(CATRender&, int) FUNC_OVERRIDE_FINAL;
#ifdef CATIAR426
  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) FUNC_OVERRIDE_FINAL;
  virtual void Draw(CATRender& iRender, int iInside) FUNC_OVERRIDE_FINAL;
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) FUNC_OVERRIDE_FINAL;
#endif

  /** @nodoc */
  virtual CAT4x4Matrix * GetMatrix();

  /** Get the CAT3DFixedArrowGPs and the CAT3DAnnotationTextGPs which compose the axis.<br>
   *  Do not delete the return pointers.
   *  @param oAxis[3]
   *  Return the 3 @href CAT3DFixedArrowGP pointers which compose the axis.
   *  @param oText[3]
   *  Return the 3 @href CAT3DAnnotationTextGP pointers which compose the axis.  
   */

  virtual void Get (CAT3DFixedArrowGP * oAxis[3], CAT3DAnnotationTextGP * oText[3]);

  /** @nodoc */
  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

  /** @nodoc */
  virtual int GetGeomIndex(const CATGraphicPrimitive * gp);

protected :
  /** @nodoc */
  virtual const vDrawInformation* GetDrawInformation();

  CAT3DFixedArrowGP     * _axis_x, * _axis_y, * _axis_z; 
  CAT3DAnnotationTextGP * _x,       * _y,      * _z;
  CAT4x4Matrix          *_matrix;
};

#endif // CAT3DAxisRep_H
