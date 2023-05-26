// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATIPolyAssemblyPathExtractor.h
// Header definition of CATIPolyAssemblyPathExtractor
//
//===================================================================
//
// Usage notes: To be derived from
//
//===================================================================
//
// August 2013 Creation: JXO
// January 2017 Modification JXO: Added new options:
//                                SmallStep, MinimumRadius, MaximumRadius, RandomMode, RotationMode
//                                and observers
// June    2018 Modification JXO: Angle in radian in code search
//===================================================================
#ifndef CATIPolyAssemblyPathExtractor_H
#define CATIPolyAssemblyPathExtractor_H

// ExportedBy
#include "PolyBodyBVHOperators.h"

// Poly
class CATBVHTreeSet;

// Math
class CATTolerance;
#include "CATMathTransformation.h"
#include "CATErrorDef.h"

class CATPolyAssemblyPathExtractorObserver;
class CATProgressCallback;

/**
 * Don't use as is
 */
class ExportedByPolyBodyBVHOperators CATIPolyAssemblyPathExtractor
{
public:
	//operation to ovveride
  virtual HRESULT ExtractFromPosition(const CATMathTransformation & iPos, CATMathTransformation & oPos) = 0;


	//getter/setter

  virtual void SetFirstOperand(CATBVHTreeSet * data1) ;
  virtual CATBVHTreeSet* GetFirstOperand() const ;
  virtual void SetSecondOperand(CATBVHTreeSet * data2) ;
  virtual CATBVHTreeSet* GetSecondOperand() const ;
  virtual void SetMaxNumberOfIterations(int iMaxIterations) ;
  virtual int GetMaxNumberOfIterations() const;
  virtual ~CATIPolyAssemblyPathExtractor();

  virtual HRESULT SetSmallStep(double iSmallStep) ;
  virtual double GetSmallStep() const ;
  virtual HRESULT SetMinimumRadius(double iMinimumRadius);
  virtual double GetMinimumRadius() const ;
  virtual HRESULT SetMaximumRadius(double iMaximumRadius);
  virtual double GetMaximumRadius() const ;
  
  enum RandomMode
  {
    eNoRandom,
    eLightRandom,
    eFullRandom
  };
  virtual HRESULT SetRandomMode(RandomMode iRandomMode) ;
  virtual RandomMode GetRandomMode() const ;
  /**
   * @param iRotationMode
   *        0. for no rotation
   *        0.5 for sharing rotations and translations
   *        1. for expanding rotations from translations
   *        Any values in between for a smooth transition
   */
  virtual HRESULT SetRotationMode(double iRotationMode) ;
  virtual double GetRotationMode() const ;
  /**
   * @param iDirection
   *        Search direction
   * @param iAngle
   *        Cone half angle, in radian
   */
  virtual HRESULT SetSearchCone(const CATMathVector & iDirection, double iAngle) ;
  virtual CATMathVector GetSearchConeDirection() const;
  virtual double GetSearchConeAngle() const;
  /**
   * Resets
   */
  virtual HRESULT ResetSearchCone() ;

  /**
   * Registers an observer for fine outputs.
   * And AddRef is done on obs, a Release will be done in destructor
   */
  virtual void RegisterObserver(CATPolyAssemblyPathExtractorObserver * obs) = 0;
  /** 
   * Unregisters obs. Release will be called.
   */
  virtual void UnregisterObserver(CATPolyAssemblyPathExtractorObserver * obs) = 0;
  /**
   * Set a progress bar.
   * @param iBar you can release it after this call.
   */
  virtual void SetProgressCallback(CATProgressCallback * iBar) = 0;

  /**
   * Debug only, don't use
   */
  virtual HRESULT SetBackAndForthFrequency(int iBackAndForth) ;
  virtual int GetBackAndForthFrequency() const ;
protected:
  CATIPolyAssemblyPathExtractor();

  //parameters of the operators

  CATBVHTreeSet *_FirstOperand = nullptr;
  CATBVHTreeSet *_SecondOperand = nullptr;
  int _MaxIterations=1;
  double _SmallStep=0;
  double _MinimumRadius=0;
  double _MaximumRadius=0;
  RandomMode _RandomMode= eNoRandom;
  double _RotationMode=0;
  int _BackAndForthFrequency = 0;

  CATMathVector _SearchConeDirection;
  double _SearchConeAngle=0;
};

#endif

