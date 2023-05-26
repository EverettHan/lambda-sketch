#ifndef CATV3DTriggerBox_H
#define CATV3DTriggerBox_H

#include <CATVidTriggerArea.h>
#include <CATMathPointf.h>

class CATV3DAdjustment;

class ExportedByVisuDialog CATVidTriggerBox : public CATVidTriggerArea {
public:
  /** Constructor*/
  CATVidTriggerBox();
  CATVidTriggerBox(const CATMathPointf& i_hitBoxOffsets);
  CATVidTriggerBox(float i_hitBoxOffset);
  CATVidTriggerBox(float i_hitBoxOffsetX, float i_hitBoxOffsetY, float i_hitBoxOffsetZ);
  /** Destructor */
  ~CATVidTriggerBox() {};

  /*Used for collision pick mode and collision test to know if the controller is in the trigger area*/
  virtual bool CollisionTest(const CAT4x4Matrix& i_absoluteToRelativeMatrix, const CATMathPoint2Df& i_dimension, const CATMathPoint& i_eyePosition, const CATMathVector& i_offset, CATMathPointf& o_pickPosition, double& o_distance) override;

  /*Used for laser and wand pick modes*/
  virtual bool LineTest(const CAT4x4Matrix& i_absoluteToRelativeMatrix, const CATMathPoint2Df& i_dimension, const CATMathPoint& i_eyePosition, const CATMathVector& i_offset, const CATMathLine& i_line, bool i_isWandMode, CATMathPointf& o_pickPosition, double& o_pickDistance) override;

  /*Create the points needed for displaying the hit area around the GP*/
  virtual double* DrawHitAreaDebug(CATVidWidget* i_associatedWidget, const CATMathVector& i_offset, int& arraySize) override;
  /*Create the points needed for displaying the trigger area around the V3D top widget*/
  virtual double* DrawTriggerAreaDebug(CATVidWidget* i_associatedWidget, const CATMathVector& i_offset, int& arraySize) override;
  /*Create the points needed for displaying the collision sphere around the controller*/
  virtual double* DrawCollisionDebug(int& arraySize) override;

  /*@return the hit box margins in x,y,z relative to the widget*/
  inline CATMathPointf GetHitBoxOffsets() { return _hitBoxOffsets; };
  /*Set the hit box margins in x,y,z relative to the widget*/
  inline void SetHitBoxOffsets(const CATMathPointf& i_hitBoxOffsets) { _hitBoxOffsets = i_hitBoxOffsets; };

protected:
  /*Main debug draw function, used by DrawHitAreaDebug and DrawTriggerAreaDebug
  * i_useCenteringOffset is used for centering the drawing because the origin is different between GPs and layouts
  */
  virtual double* DrawAreaDebug(bool i_useCenteringOffset, CATVidWidget* i_associatedWidget, const CATMathVector& i_offset, int& arraySize) override;

  /*The hit box margins in x,y,z relative to the widget*/
  CATMathPointf _hitBoxOffsets = CATMathPointf(-1, -1, -1);
};
#endif
