#ifndef __CATForce_h_
#define __CATForce_h_

#include "CATVisFoundation.h"
#include "CATEventSubscriber.h"
#include "CATMathVectorf.h"
#include "CATMathVector2Df.h"
#include "CATRender.h"

class CATGraphicPrimitive;
class CAT3DFixedArrowGP;
class VisRawBuffer;
class IVisSG3DPrimitiveGroup;

class ExportedByCATVisFoundation CATForce : public CATEventSubscriber
{
public:

  enum PropVec3
  {
    eAcceleration,    //!< Accelaration of the force
    ePosition,        //!< Position of the force
    ePropVec3Count
  };

  enum PropFloat
  {
    eRadius,        //!< Influence Radius, if radius = -1 the force is apply everywhere
    ePropFloatCount
  };

  /** Constructor
  */
  CATForce();

  /** Copy constructor
  */
  CATForce(const CATForce& iForce);

  /** Destructor
  */
  virtual ~CATForce();
 
  /** Set float Properties
  *@param iType: properties to set
  *@param iValue: the float value to set
  */
  void SetParameter(PropFloat iType, float iValue);
  
  /** Set Vec3 Properties
  *@param iType: properties to set
  *@param iValue: the CATMathPointf value to set
  */
  void SetParameter(PropVec3 iType, const CATMathPointf& iValue);
 
  /** Get float Properties
  *@param iType: properties to get
  *@param oValue: the return value
  */
  void GetParameter(PropFloat iType, float& oValue) const;

  /** Get CATMathPointf Properties
  *@param iType: properties to get
  *@param oValue: the return value
  */
  void GetParameter(PropVec3 iType, CATMathPointf& oValue) const;


  bool NeedUpdate() const
  {
    return m_NeedUpdate;
  }

  void ResetUpdate()
  {
    m_NeedUpdate = false;
  }

private:

  /** @nodoc */
  void _Copy(const CATForce& iForce);
 
  CATMathPointf m_PropVec3[ePropVec3Count];
  float         m_PropFloat[ePropFloatCount];

  bool m_NeedUpdate;

};

#endif
