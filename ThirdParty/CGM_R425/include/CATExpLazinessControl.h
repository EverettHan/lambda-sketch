//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2013
//==============================================================================================================
// Usage notes:
//==============================================================================================================
// 2013-07-22 - T6L : Creation
//==============================================================================================================


#ifndef CATExpLaziness_H
#define CATExpLaziness_H  


#include "CATExpIntersectionPredicates.h"


class CATExpLazinessControl
{
public:

  /// use them to ask for computations in the corresponding levels of precision
  CATExpLazinessControl(bool dynamic, bool interval, bool exact /*, bool fpexpansion = false*/);

  void ResetStatistics()
  {
    for (int i = 0; i < kNbLevels_; ++i)
      intersections_counter_[i] = crossings_counter_[i] = comparisons_counter_[i] = 0;
  }

  void IncrementIntersections (int level)
  { ++(intersections_counter_[level]); }

  void IncrementCrossings (int level)
  { ++(crossings_counter_[level]); }

  void IncrementComparisons (int level)
  { ++(comparisons_counter_[level]); }

  void ExportedByCATExpIntersectionPredicates PrintStatistics ();

  bool attempt_dynamic() const { return _attempt_dynamic; }
  bool attempt_interval() const { return _attempt_interval; }
  bool attempt_exact() const { return _attempt_exact; }
  //bool attempt_fpexpansion() const { return _attempt_fpexpansion; }

private:
  //static const int kNbLevels_ = 4;
  static const int kNbLevels_ = 3;

  /// use them to ask for computations in the corresponding level of precision
  bool _attempt_dynamic, _attempt_interval, _attempt_exact; // , _attempt_fpexpansion;

  unsigned intersections_counter_[kNbLevels_];
  unsigned crossings_counter_[kNbLevels_];
  unsigned comparisons_counter_[kNbLevels_];
};

inline CATExpLazinessControl::CATExpLazinessControl(bool dynamic, bool interval, bool exact/*, bool fpexpansion*/)
  : _attempt_dynamic(dynamic)
  , _attempt_interval(interval)
  , _attempt_exact(exact)
  //, _attempt_fpexpansion(fpexpansion)
{
  ResetStatistics();
}

#endif
