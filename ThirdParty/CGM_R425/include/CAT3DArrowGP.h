#ifndef CAT3DArrowGP_H
#define CAT3DArrowGP_H


// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "SGInfra.h"

#include "CATDynamicGP.h"

#include "CATMathPointf.h"
#include "CATMathDirectionf.h"
#include "CATVisMacroForInterfaces.h"

class CATStreamer;

class IVisSG3DPrimitive;
class CAT3DArrowGPIVisSG3DPrimitiveBOAImpl;

/**
 * Class to create the graphic primitive of a 3D arrow.
 * <b>Role</b>: Graphic primitive to display a 3D arrow
 * 
 */
class ExportedBySGInfra CAT3DArrowGP : public CATDynamicGP
{
  //friend class CATMarshallable3DFixedArrowGP;
  CATDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT3DArrowGP, IVisSG3DPrimitive, CAT3DArrowGPIVisSG3DPrimitiveBOAImpl);
  
 public :
  
  /**
   * Default constructor
   */
  CAT3DArrowGP ();
  
  /**
   * Constructs a 3D arrow with parameters.
   * <br><b>Role:</b>
   * Constructs a 3D arrow from an origin, the arrow direction, 
   * the arrow total length, the arrow head height and
   * a lenght indicating the offset desired between the origin and the arrow start point.
   * <pre>
   *
   *                                      ---------->
   *                                      iDirection 
   * 
   *                                                                      XXXX
   *                                                                      XX XXX
   *                                                                      XX   XXX
   *                                                                      XX     XXX
   *     | iOrigin                                                        XX       XXX
   *   --|--             XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX         XXX 
   *     |                                                                XX       XXX
   *                                                                      XX      XXX
   *                                                                      XX    XXX
   *                                                                      XX  XXX
   *                                                                      XXXX
   *                
   *
   *       iBaseLength                                                    iArrowHeadHeight
   *      <----------->                                                    <------------>
   *
   *                                           iLenght
   *                     <--------------------------------------------------------------->
   * </pre>
   * @param iOrigin
   *   The arrow origin. If no <tt>iBaseLength</tt> is specified, or if it is set to 0,
   *   <tt>iOrigin</tt> corresponds to the arrow start point.
   * @param iDirection
   *   The arrow direction.
   * @param iLength
   *   The total arrow length, from start point to arrow head tip point, expressed in millimetres.
   * @param iArrowHeadHeight
   *   The height of the arrow head.
   *   If no value is specified, <tt>iArrowHeadHeight</tt> is set
   *   to 0, and the arrow head height to <tt>iLengthIn_mm/5</tt>.
   * @param iBaseLength
   *   An offset you can set to set the arrow start point at a certain
   *   distance from <tt>iOrigin</tt>.
   *   If no value is specified, the origin corresponds to the arrow
   *   start point.
   */
  CAT3DArrowGP (const CATMathPointf & iOrigin,
                     const CATMathDirectionf & iDirection,
                     const int iLength,
                     const int iArrowHeadHeight = 0,
                     const int iBaseLength = 0);
  
  
  /**
   * @nodoc
   */
  virtual void Stream(CATStreamer& oStr,int iSaveType=0);

  /**
   * @nodoc
   */
  virtual void UnStream(CATStreamer& iStr);

  /**
   * Associates a text to the 3D arrow.
   * @param iText
   *   The characters string containing the text to associate to the arrow.
   *   This text is displayed near the 3D arrow.
   */
  void AssociateText (char * iText);


#if defined(CATIAR426) || defined(REMOVE_USELESS_INCLUDE)
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbidden to override Draw function.")
#endif
  /** @nodoc */
  virtual void Draw(CATRender& iRender) GP_FUNC_OVERRIDE_FINAL;
#endif 

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbidden to override ImmediateDraw function.")
#endif
  /**
   * Draws the 3D arrow.
   * @param iRender
   *   The render through which the arrow is drawn.
   * @param iViewpoint
   *   The viewpoint through which the arrow is seen.
   * @param iViewport
   *   The viewport in which the arrow is located.
   */
  virtual void ImmediateDraw (CATRender &iRender, const CATViewpoint * iViewpoint, const CATViewport * iViewport) GP_FUNC_OVERRIDE_FINAL;   

  /**
   * @nodoc
   */

  void Get (CATMathPointf& oBegin, CATMathDirectionf& oDirection, CATMathDirectionf& oNormal,
            int & oLength, int & oArrowHeadHeight, int & oBaseLength, char * & oText) const;

  /**
   * @nodoc
   */
  virtual int DetailCulling(CATRender *render);



 protected :

   virtual ~CAT3DArrowGP();

 private :

   CATMathPointf _begin;
   CATMathDirectionf _direction, _normal;
   
   float _points[18];
   int  _length_arrow, _length_base , _length;
   int _size;
   char *_text;
};

#endif
