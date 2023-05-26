#ifndef __CATEmitter_h_
#define __CATEmitter_h_

#include "CATVisFoundation.h"
#include "CATEventSubscriber.h"
#include "CATMathVectorf.h"
#include "CATMathVector2Df.h"
#include "CATRender.h"
#include "CATUnicodeString.h"
#include "CAT4x4Matrix.h"
#include "list.h"

class CATGraphicPrimitive;
class CAT3DFixedArrowGP;
class VisRawBuffer;
class IVisSG3DPrimitiveGroup;
class IVisSG3DNodeGroup;
class VisParticleProgram;
class VisVerticesDescription;
class VisRawBuffer;
class IVisSGGPGPUPrimitive;
class CATForce;

/**
*@class Describes a Particles Emitter that you can use a CATParticleSystemRep
*/
class ExportedByCATVisFoundation CATEmitter : public CATEventSubscriber
{
  friend class VisParticleProgram;
public:

  enum PropVec3
  {
    eSpawnColor,                    //!< the particle Color at the emission
    ePropVec3Count
  };

  enum RandomPropVec3
  {
    eSpawnPosition,                 //!< the particle position at the emission
    eSpawnVelocity,                 //!< the particle velocity at the emission
    eRandomPropVec3Count
  };

  enum PropInt
  {
    eMaxParticle,                   //!< the max particle number of the emitter
    eIsLoop,                        //!< if 1 the emitter always emit, else the emitter runs between eSpawnTime and eSpawnTime + eSpawnDuration
    eIsLocal,                       //!< if 1 the particle position is transform by the ParticleSystem matrix
    ePropIntCount
  };

  enum RandomPropInt
  {
    eSpawnFrequency,                //!< the number of particle emit in 1 second
    eRandomPropIntCount
  };

  enum PropFloat
  {
    eSpawnTime,                     //!< the time in second when the emitter begin to run        
    eSpawnDuration,                 //!< the running duration in second     
    eSpawnTransparency,             //!< the particle transparency at the emission
    ePropFloatCount
  };

  enum RandomPropFloat
  {
    eLifeTime,                     //!< the particle lifetime
    eSize,                         //!< the particle size at the emission
    eRandomPropFloatCount
  };

  /** Constructs an Emitter for a CATParticleSystemRep.
  */
  CATEmitter();

  /** Copy constructor
  */
  CATEmitter( const CATEmitter& iEmitter);

  /** Destructor
  *@brief don't call the destructor directly use Release()
  */
  virtual ~CATEmitter();

  /** Set a texture on particles
  *@param iTexture: Path to the texture
  */
  void SetTexture(const char* iTexture);

  /** Set the transformation Matrix
  *@param iMatrix: the transformation Matrix
  */
  void SetTransformMatrix(CAT4x4Matrix& iMatrix);

  /**
  *@return the path to the texture
  */
  const char* GetTexture() const;

  /** Update the Emitter
  *@param iRender: The render use to draw
  *@param iTime: the elapsed time from the start of the animation
  *@param iTick: the time from the last frame
  */
  virtual void Update(CATRender& iRender, float iTime, float iTick);

  /** Reset the start time
  */
  virtual void ResetStartTime();


  /** Set Emitter Parameter
  *@param iType: RandomPropInt Parameter
  *@param iMin: Minimum integer Value 
  *@param iMax: Maximun integer value 
  */
  void SetParameter(RandomPropInt iType, int iMin, int iMax);

  /** Set Emitter Parameter
  *@param iType: PropInt Parameter
  *@param iValue: Minimum  and Maximum integer Value 
  */
  void SetParameter(PropInt iType, int iValue);

  /** Set Emitter Parameter
  *@param iType: RandomPropFloat Parameter
  *@param iMin: Minimum float Value 
  *@param iMax: Maximum float value Default Value 0.0f
  */
  void SetParameter(RandomPropFloat iType, float iMin, float iMax);

   /** Set Emitter Parameter
  *@param iType: PropFloat Parameter
  *@param iValue: Minimum and Maximum float Value 
  */
  void SetParameter(PropFloat iType, float iValue);

  /** Set Emitter Parameter
  *@param iType: RandomPropVec3 Parameter
  *@param iMin: Minimum CATMathVectorf value
  *@param iMax: Maximum CATMathVectorf value
  */
  void SetParameter(RandomPropVec3 iType, const CATMathVectorf& iMin, const CATMathVectorf& iMax);

  /** Set Emitter Parameter
  *@param iType: PropVec3 Parameter
  *@param iValue: Minimum  and Maximum CATMathVectorf value
  */
  void SetParameter(PropVec3 iType, const CATMathVectorf& iValue);

  /**
  *@param iType: RandomPropInt properties to get
  *@param oMin: return the min value
  *@param oMax: return the max value
  *@return S_OK if the parameter is set else E_FAIL
  */
  void GetParameter(RandomPropInt iType, int& oMin, int& oMax) const;

  /**
  *@param iType: PropInt properties to get
  *@param oValue: return the value
  *@return S_OK if the parameter is set else E_FAIL
  */
  void GetParameter(PropInt iType, int& oValue) const;

  /**
  *@param iType: RandomPropFloat properties to get
  *@param oMin: return the min value
  *@param oMax: return the max value
  *@return S_OK if the parameter is set else E_FAIL
  */
  void GetParameter(RandomPropFloat iType, float& oMin, float& oMax) const;

  /**
  *@param iType: PropFloat properties to get
  *@param oValue: return the value
  *@return S_OK if the parameter is set else E_FAIL
  */
  void GetParameter(PropFloat iType, float& oValue) const;

  /**
  *@param iType: RandomPropVec3 properties to gets
  *@param oMin: return the min value
  *@param oMax: return the max value
  *@return S_OK if the parameter is set else E_FAIL
  */
  void GetParameter(RandomPropVec3 iType, CATMathVectorf& oMin, CATMathVectorf& oMax) const;

  /**
  *@param iType: PropVec3 properties to gets
  *@param oValue: return the value
  *@return S_OK if the parameter is set else E_FAIL
  */
  void GetParameter(PropVec3 iType, CATMathVectorf& oValue) const;

  /**
  *@param iForce: the force to add
  */
  void AddForce(CATForce* iForce);

  /**
  *@param iForce: the force to remove
  */
  void RemoveForce(CATForce* iForce);

private:

  /**
  *@ return the current Time
  */
  float _GetTime() const
  {
    return m_Time;
  }

  /**
  *@return the current tick
  */
  float _GetTick() const
  {
    return m_Tick;
  }

  /**
  *@return get the start time
  */
  float _GetStartAtTime() const
  {
    return m_StartAt;
  }


  static const unsigned int _kNumberOfVerticesPerParticle;
  static const unsigned int _kNumberOfComponentsPerParticle;
  static const unsigned int _kNumerOfIndicesPerParticle;

  template <typename T> 
  struct _Interval { 
    T Min; 
    T Max; 

    _Interval(T iMin, T iMax):
      Min(iMin), Max(iMax)
    {

    }

    _Interval()
    {

    }
  }; 

  typedef _Interval<CATMathVectorf>  VEC3;
  typedef _Interval<int>  INT;
  typedef _Interval<float>  FLOAT;

  enum EmitterUpdate
  {
    eEUNoUpdate,
    eEUFullUpdate,
    eEUMaterialUpdate,
    eEUCount
  };

  /** @nodoc */
  void _InitData();

  /** @nodoc */
  void _UpdateMaterial();

  /** @nodoc */
  void _Copy(const CATEmitter& iEmit);
     
  float                   m_Duration;
  bool                    m_IsLoop;
  float                   m_Tick;
  float                   m_Time;
  EmitterUpdate           m_EmitterUpdate;
  bool                    m_IsStarted;
  float                   m_StartAt;
  bool                    m_IsMatChanged;
  CATUnicodeString        m_Texture;
  bool                    m_HaveTexture;
  VEC3                    m_PropVec3[eRandomPropVec3Count + ePropVec3Count];
  INT                     m_PropInt[eRandomPropIntCount + ePropIntCount];
  FLOAT                   m_PropFloat[eRandomPropFloatCount + ePropFloatCount];
  IVisSG3DPrimitiveGroup* m_PrimitiveGroup;
  VisParticleProgram*     m_Program;
  CATGraphicMaterial*     m_Material;
  list<CATForce>          m_Forces;
  CAT4x4Matrix            m_TransformMatrix;
};

#endif
