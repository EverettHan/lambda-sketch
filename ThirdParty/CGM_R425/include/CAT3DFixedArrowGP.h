#ifndef CAT3DFixedArrowGP_H
#define CAT3DFixedArrowGP_H

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

#include "CATUnicodeString.h"

class CATStreamer;
class IVisSG3DPrimitive;
class CAT3DFixedArrowGPIVisSG3DPrimitiveBOAImpl;

/**
 * Class to create the graphic primitive of a 3D fixed arrow.
 * <b>Role</b>: Graphic primitive to display a 3D arrow which
 * size remains constant on the screen (i.e., does not change with
 * zoom, etc...).
 */
class ExportedBySGInfra CAT3DFixedArrowGP : public CATDynamicGP
{
  friend class CATMarshallable3DFixedArrowGP;
  friend class SGCGRStreamerFor3DFixedArrowGP;
  friend class SGCGRNodesFactoryA;
  CATDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT3DFixedArrowGP, IVisSG3DPrimitive, CAT3DFixedArrowGPIVisSG3DPrimitiveBOAImpl);
  
 public :
  
  /**
   * Default constructor
   */
  CAT3DFixedArrowGP ();
  
  /**
   * Constructs a 3D fixed arrow from an origin, the arrow direction, the normal to
   * the plan containing the arrow head, the arrow total length, the arrow head height and
   * an lenght indicating the offset desired between the origin and the arrow start point.
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
   *                                           iLenghtIn_mm
   *                     <--------------------------------------------------------------->
   * </pre>
   * @param iOrigin
   *   The arrow origin. If no <tt>iBaseLength</tt> is specified, or if it is set to 0,
   *   <tt>iOrigin</tt> corresponds to the arrow start point.
   * @param iDirection
   *   The arrow direction.
   * @param iLengthIn_mm
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
  CAT3DFixedArrowGP (const CATMathPointf & iOrigin,
                     const CATMathDirectionf & iDirection,
                     const int iLengthIn_mm,
                     const int iArrowHeadHeight = 0,
                     const int iBaseLength = 0);
  
  /**
   * Constructs a 3D fixed arrow from a start point, a direction, the
   * normal to the plan containing this arrow, and its total length.
   * <pre>
   *
   *                                     /|\
   *                                      |
   *                                      |   iNormal 
   *                                      |
   *                                      ---------->
   *                                      iDirection 
   * 
   *                iStartPoint                                           XXXX
   *                                                                      XX XXX
   *                                                                      XX   XXX
   *                  X   X                                               XX     XXX
   *                   X X                                                XX       XXX
   *                    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX         XXX 
   *                   X X                                                XX       XXX
   *                  X   X                                               XX      XXX
   *                                                                      XX    XXX
   *                                                                      XX  XXX
   *                                                                      XXXX
   *                
   *
   *
   *                                           iLenghtIn_mm
   *                     <--------------------------------------------------------------->
   * </pre>
   * @param iStartPoint
   *   The 3D start point of the 3D arrow.
   * @param iDirection
   *   The arrow direction. 
   * @param iNormal
   *   The normal to the plan containing the arrow.
   * @param iLengthIn_mm
   *   The arrow total length, expressed in millimetres.
   */
  CAT3DFixedArrowGP (const CATMathPointf & iStartPoint,
                     const CATMathDirectionf & iDirection,
                     const CATMathDirectionf & iNormal,
                     const int iLengthIn_mm);
  
  /**
   * @nodoc
   */
  virtual void Stream(CATStreamer& oStr,int iSaveType=0);

  /**
   * @nodoc
   */
  virtual void UnStream(CATStreamer& iStr);

  /**
   * Associates some text to the 3D fixed arrow.
   * This text is displayed near the 3D fixed arrow.
   * @param iText
   *   The characters string containing the text to associate to the arrow.
   */
  void AssociateText (char * iText);

  /**
  * Associates some text to the 3D fixed arrow.
  * This text is displayed near the 3D fixed arrow.
  * @param iText
  *   The CATUnicodeString containing the text to associate to the arrow.
  */
  void AssociateUCText(const CATUnicodeString& iText);

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
   * Draws the 3D fixed arrow.
   * @param iRender
   *   The render through which the arrow is drawn.
   * @param iViewpoint
   *   The viewpoint through which the arrow is seen.
   * @param iViewport
   *   The viewport in which the arrow is located.
   */
  virtual void ImmediateDraw (CATRender &iRender, const CATViewpoint *iViewpoint, const CATViewport *iViewport) GP_FUNC_OVERRIDE_FINAL;
  
  
  /**
   * Retrieves the 3D fixed arrow parameters.
   * @param oBegin
   *   The 3D start point of the 3D arrow.
   * @param oDirection
   *   The arrow direction.
   * @param oNormal
   *   The normal to the plan containing the arrow.
   */
  
  virtual void Get (CATMathPointf& oBegin, CATMathDirectionf& oDirection, CATMathDirectionf& oNormal);

  /**
   * @nodoc
   */

  void Get (CATMathPointf& oBegin, CATMathDirectionf& oDirection, CATMathDirectionf& oNormal,
            int & oLengthInMM, int & oArrowHeadHeight, int & oBaseLength, char * & oText) const;
  
  /**
  * @nodoc
  */

  void Get(CATMathPointf& oBegin, CATMathDirectionf& oDirection, CATMathDirectionf& oNormal,
	  int & oLengthInMM, int & oArrowHeadHeight, int & oBaseLength, CATUnicodeString & oUCText) const;

  /**
   * @nodoc
   */
  virtual void ModifyDirection(CATMathDirectionf iDirection);

  /**
   * @nodoc
   */
  inline  void SetLengthInMM(const int iLengthInMM);
    
  /**
   * @nodoc
   */
  virtual int DetailCulling(CATRender *render);

 protected :

   virtual ~CAT3DFixedArrowGP();

 private :

   CATMathPointf _begin;
   CATMathDirectionf _direction, _normal;

   float _points[18];
   int _length_in_mm, _length_arrow, _length_base ;
   CATUnicodeString *_uctext;
};

inline void CAT3DFixedArrowGP::SetLengthInMM(const int iLengthInMM)
{
   _length_in_mm = iLengthInMM;
}

#endif
