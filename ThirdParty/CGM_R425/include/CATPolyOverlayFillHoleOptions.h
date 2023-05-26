//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2023, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyOverlayFillHoleOptions.h
//
//===================================================================
//  Deb 2023 : F1Z : Creation (extraction from CATPolyBodyHealingWithOverlayOptions.h"
//===================================================================
#pragma once

#include "CATPolyBodyOverlayOptions.h"
#include "PolyBodyBoolean.h"
#include "Poly/Vector.h"
#include "CATPolyBody.h"

class ExportedByPolyBodyBoolean CATPolyOverlayFillHoleOptions
{
public:
  CATPolyOverlayFillHoleOptions();
  CATPolyOverlayFillHoleOptions(const CATPolyOverlayFillHoleOptions &);
  ~CATPolyOverlayFillHoleOptions();
  CATPolyOverlayFillHoleOptions & operator=(const CATPolyOverlayFillHoleOptions &);

public:
  enum class Method
  {
    eBasic, /// 2D fill hole of the border projected into a plane. Can fail but its cost is linear.
    eRobust /// Robust method. Cost in O(N^3), N the number of point on the border, so a protection can be provided to the options
    // it is possible to add a custom fill hole operator interface, contact us if you want it. (might be required if the fill method can not be put into our framework for instance)
  };

  void SetRobustMethodMode(bool iWithNormals); /// only used in case of oriented input or consistent oriented border detected.
  void SetRobustMethodLimit(int iMaxNumderOfBorderBars); /// <0 means no limits

  void SetActifMethod(Method iFirstMethod);
  template<typename... MethodName>
  void SetOrderAndActifMethod(Method iFirstMethod, MethodName ... iNextMethods)
  {
    _methodsOrder.clear();
    SetOrderAndActifMethodPriv(iFirstMethod, std::forward<MethodName>(iNextMethods)...);
    _methodsOrder.shrink_to_fit();
  }
  template<typename iteType>
  void SetOrderAndActifMethodFromIterator(iteType iBegin, iteType iEnd)
  {
    _methodsOrder.clear();
    for (iteType ite = iBegin; ite != iEnd; ++ite)
      SetOrderAndActifMethodPriv(*ite);
    _methodsOrder.shrink_to_fit();
  }

  inline const Poly::Vector<Method> & GetMethodOrder() const { return _methodsOrder; };

  inline bool RobustUseNormal() const { return _robustWithNormals; };
  inline int GetRobustMaxNumberOfBorderBars() const { return _robustMaxNumberOfBorderBars; };

public:
  // Set the max border length
  // The border with lower length will be filled, the others won't
  inline void SetMaxLength(double iMaxBorderLength) { _maxBorderLength = iMaxBorderLength; };
  inline double GetMaxLength() const { return _maxBorderLength; };

  // Set that we only want to fill the border outside a solid
  // This force the use of localClosure.
  inline void SetFillOutsideBorderOnly(bool fillOutsideBorderOnly = true) { _fillOutsideBorderOnly = fillOutsideBorderOnly; };
  inline bool DoFillOutsideBorderOnly() const { return _fillOutsideBorderOnly; };

  // When searching the cycle to fill, we can also
  // using the min geodesic path between two tips to close a cycle.
  // It leads to more local hole filling.
  inline void AllowLocalClosure(bool allowLocalClosure) { _allowLocalClosure = allowLocalClosure; };
  inline bool IsLocalClosureAllowed() const { return _allowLocalClosure; };

private:
  template<typename... MethodName>
  void SetOrderAndActifMethodPriv(Method iFirstMethod, MethodName... iNextMethods)
  {
    SetOrderAndActifMethodPriv(iFirstMethod);
    SetOrderAndActifMethodPriv(std::forward<MethodName>(iNextMethods)...);
  }
  void SetOrderAndActifMethodPriv(Method iNextMethod);

  /// Avalaible method and order
  Poly::Vector<Method> _methodsOrder;

  /// robust options
  bool _robustWithNormals;
  int _robustMaxNumberOfBorderBars;

  // filter&co
  bool _allowLocalClosure;
  double _maxBorderLength;
  bool _fillOutsideBorderOnly;
};
