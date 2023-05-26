#ifndef __CATParticleSystemRep_h_
#define __CATParticleSystemRep_h_

#include "CAT3DRep.h"
#include "CATRender.h"
#include "CATVisFoundation.h"
#include "CATEmitter.h"
#include <ctime>

#include "list.h"

class CATForce;
/**
*@class CATParticleSystemRep
*@brief Represent a GPGPU particle system
*       The particle system is composed of CATEmitter and CATForce.
*       CATForce can be global of the particle system (apply on all CATEmitter) or local to a CATEmitter
*       You need to call the Method UpdateTime to animate the Particle System
*       The Bounding Element of the Particle System is infinite and the Picking is deactivated
*/
class ExportedByCATVisFoundation CATParticleSystemRep : public CAT3DRep
{
  CATDeclareClass;

public:
  typedef list<CATEmitter> EmitterList;
  typedef list<CATForce> ForceList;

  /**
  * Class constructor.
  */
  static CATParticleSystemRep* CreateRep();

  /**
  * Destructor
  */
  virtual ~CATParticleSystemRep (void);

  /**
  * From CATRep
  */
  virtual void DrawShading(CATRender& iRender, int iInside) override final;

  // AZX: (A2X migration) Making draw functions final 
  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) override final;
  virtual void Draw(CATRender& iRender, int iInside) override final;
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

  /**
  *@brief Update the time of the Particle System
  *@param iElapsedTime: The time from the start of the animation
  *@param iTick: the time from the last frame
  */
  void UpdateTime(float iElapsedTime, float iTick);

  /**
  *@brief Reset the internal time of the Particle System (Reset the animation)
  */
  void ResetTime();

  /**
  *@brief Add an CATEmitter to the Particle System
  *@param iEmitter: The CATEmitter to add
  */
  void AddEmitter(CATEmitter* iEmitter);

  /**
  *@brief Remove an CATEmitter to the Particle System
  *@param iEmitter: The CATEmitter to Remove
  */
  void RemoveEmitter(CATEmitter* iEmitter);

  /**
  *@return the number of CATEmitter in the Particle System
  */
  int GetNumberOfEmitter()
  {
    return m_Emitters.length();
  }

  /**
  *@return the list of CATEmitter
  */
  EmitterList const & GetEmitters() const
  {
    return m_Emitters;
  }

  /**
  *@brief Add a global force to the Particle System. 
  *       This force is applied on all Emitter
  *@param iForce: The CATForce to add
  */
  void AddForce(CATForce* iForce);

  /**
  *@brief Remove a global force to the Particle System
  *@param iForce: The CATForce to remove
  */
  void RemoveForce(CATForce* iForce);

  /**
  *@return the number of global CATForce
  */
  int GetNumberOfForce()
  {
    return m_Forces.length();
  }

  /**
  *@return the list of CATForce
  */
  ForceList const & GetForces() const
  {
    return m_Forces;
  }
  
private:
  CATParticleSystemRep();

  double            m_Tick;
  double            m_Time;
  
  EmitterList m_Emitters;
  ForceList   m_Forces;

};

#endif
