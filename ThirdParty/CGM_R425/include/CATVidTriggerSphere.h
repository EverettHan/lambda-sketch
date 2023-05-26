#ifndef CATV3DTriggerSphere_H
#define CATV3DTriggerSphere_H

#include <CATVidTriggerArea.h>

class ExportedByVisuDialog CATVidTriggerSphere : public CATVidTriggerArea {
public:
  /** Constructor*/
  CATVidTriggerSphere();
  CATVidTriggerSphere(float i_sphereRadius);
  /** Destructor */
  ~CATVidTriggerSphere() {};

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

  /*@return the hit sphere radius relative to the widget size*/
  inline float GetSphereRadius() { return _sphereRadius; };
  /*Set the hit sphere radius relative to the widget size*/
  inline void SetSphereRadius(float i_sphereRadius) { _sphereRadius = i_sphereRadius; };

protected:
  /*Main debug draw function, used by DrawHitAreaDebug and DrawTriggerAreaDebug
  * i_useCenteringOffset is used for centering the drawing because the origin is different between GPs and layouts
  */
  virtual double* DrawAreaDebug(bool i_useCenteringOffset, CATVidWidget* i_associatedWidget, const CATMathVector& i_offset, int& arraySize) override;

  /*The hit sphere radius relative to the widget size*/
  float _sphereRadius = -1.f;
};
#endif
