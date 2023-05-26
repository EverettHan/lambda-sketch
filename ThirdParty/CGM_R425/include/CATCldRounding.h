//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2010
//==============================================================================================================
// CATCldRounding : Changes / Reset the Rounding control mode. 
//==============================================================================================================
// Usage notes:
//==============================================================================================================
// 16-Jul-2010 - DNR - Creation.
//==============================================================================================================

#ifndef CATCldRounding_H
#define CATCldRounding_H

#include "ExportedByCATCloudExactPredicates.h"


//#define CheckRounding

class ExportedByCATCloudExactPredicates CATCldRounding
{

//==============================================================================================================
// Public Part.
//==============================================================================================================

public :


  /* 
   *constructeur / destructeur
   */
  CATCldRounding();
  virtual ~CATCldRounding();
  /*
  * Reset the rounding mode to its original one.
  **/
  void ResetOriginalMode();

  /*
  * Activate the rounding mode : Nearest, Toward Zero, Minus Infinity and Plus Infinty.
  * The Current rounding is read an saved in order to reset it by ResetOriginalMode.
  **/
  static void SetNearestMode();
  static void SetTowardZeroMode();
  static void SetMinusInfinityMode();
  static void SetPlusInfinityMode();
  /*
  * Reset the rounding mode to its original one.
  **/
  //static void ResetOriginalMode();

#ifdef CheckRounding
  static void CheckRoundingForInterval();
  static void CheckRoundingForRational();
#endif

private:

  enum RoundingMode {
    NearestMode,
    TowardZeroMode,
    MinusInfinityMode,
    PlusInfinityMode,
    UnknownMode
  };

  static void _SetNearestMode();
  static void _SetTowardZeroMode();
  static void _SetMinusInfinityMode();
  static void _SetPlusInfinityMode();
  static RoundingMode _GetRoundingMode();


  RoundingMode _OriginalRoundingMode;
  static RoundingMode _CurrentRoundingMode;
} ;


inline void CATCldRounding::SetNearestMode() {
  if (_CurrentRoundingMode != NearestMode) _SetNearestMode();
};

inline void CATCldRounding::SetTowardZeroMode() {
  if (_CurrentRoundingMode != TowardZeroMode) _SetTowardZeroMode();
};

inline void CATCldRounding::SetMinusInfinityMode() {
  if (_CurrentRoundingMode != MinusInfinityMode) _SetMinusInfinityMode();
};

inline void CATCldRounding::SetPlusInfinityMode() {
  if (_CurrentRoundingMode != PlusInfinityMode) _SetPlusInfinityMode();
};

#endif
