#ifndef CATCDSAlgorithm_H
#define CATCDSAlgorithm_H

#include <algorithm>
#include <numeric>

namespace cds
{
  template<class Range, class UnaryOperation>
  void auto_transform(Range &&ioRange, UnaryOperation op)
  {
    std::transform(ioRange.begin(), ioRange.end(), ioRange.begin(), op);
  }

  template<class Range, class InputRange, class BinaryOperation>
  void auto_transform(Range &&ioRange, InputRange const &iInputRange, BinaryOperation op)
  {
    std::transform(ioRange.begin(), ioRange.end(), iInputRange.begin(), ioRange.begin(), op);
  }

  template<class InputRange, class OutputRange, class UnaryOperation>
  void transform(InputRange const &iRange, OutputRange &oRange, UnaryOperation op)
  {
    std::transform(iRange.begin(), iRange.end(), oRange.begin(), op);
  }

  template<class InputRange1, class InputRange2, class OutputRange, class BinaryOperation>
  void transform(InputRange1 const &iRange1, InputRange2 const &iRange2, OutputRange &oRange, BinaryOperation op)
  {
    std::transform(iRange1.begin(), iRange1.end(), iRange2.begin(), oRange.begin(), op);
  }

  template<class InputRange>
  void stable_sort(InputRange &&iRange)
  {
    std::stable_sort(iRange.begin(), iRange.end());
  }

  template<class InputRange, class Compare>
  void stable_sort(InputRange &&iRange, Compare const &compare)
  {
    std::stable_sort(iRange.begin(), iRange.end(), compare);
  }

  template<class InputRange>
  void sort(InputRange &&iRange)
  {
    std::sort(iRange.begin(), iRange.end());
  }

  template<class InputRange, class Compare>
  void sort(InputRange &&iRange, Compare const &compare)
  {
    std::sort(iRange.begin(), iRange.end(), compare);
  }

  template<class Range, class T>
  void iota(Range &&iRange, T val)
  {
    std::iota(iRange.begin(), iRange.end(), std::move(val));
  }

  template<class Range, class T>
  auto find(Range const &iRange, T const &val)
  {
    return std::find(iRange.begin(), iRange.end(), val);
  }

  template<class Range, class T>
  bool binary_search(Range const &iRange, T const &val)
  {
    return std::binary_search(iRange.begin(), iRange.end(), val);
  }

  template<class Range, class T, class Compare>
  bool binary_search(Range const &iRange, T const &val, Compare comp)
  {
    return std::binary_search(iRange.begin(), iRange.end(), val, std::move(comp));
  }

  template<class Range, class T>
  T accumulate(Range const &iRange, T init)
  {
    return std::accumulate(iRange.begin(), iRange.end(), std::move(init));
  }

  template<class Range, class T, class BinaryOperation>
  T accumulate(Range const &iRange, T init, BinaryOperation op)
  {
    return std::accumulate(iRange.begin(), iRange.end(), std::move(init), std::move(op));
  }

  template<class Range>
  auto min_element(Range &&iRange)
  {
    return std::min_element(iRange.begin(), iRange.end());
  }

  template<class Range, class Compare >
  auto min_element(Range &&iRange, Compare comp)
  {
    return std::min_element(iRange.begin(), iRange.end(), std::move(comp));
  }

  template<class Range>
  auto min_element_index(Range &&iRange)
  {
    return static_cast<int>(min_element(std::forward<Range>(iRange)) - iRange.begin());
  }

  template<class Range, class Compare >
  auto min_element_index(Range &&iRange, Compare comp)
  {
    return static_cast<int>(min_element(std::forward<Range>(iRange), std::move(comp)) - iRange.begin());
  }

  template<class Range>
  auto max_element(Range &&iRange)
  {
    return std::max_element(iRange.begin(), iRange.end());
  }

  template<class Range, class Compare >
  auto max_element(Range &&iRange, Compare comp)
  {
    return std::max_element(iRange.begin(), iRange.end(), std::move(comp));
  }

  template<class Range>
  auto max_element_index(Range &&iRange)
  {
    return static_cast<int>(max_element(std::forward<Range>(iRange)) - iRange.begin());
  }

  template<class Range, class Compare >
  auto max_element_index(Range &&iRange, Compare comp)
  {
    return static_cast<int>(max_element(std::forward<Range>(iRange), std::move(comp)) - iRange.begin());
  }

  template<class Range>
  auto minmax_element(Range &&iRange)
  {
    return std::minmax_element(iRange.begin(), iRange.end());
  }

  template<class Range, class Compare >
  auto minmax_element(Range &&iRange, Compare comp)
  {
    return std::minmax_element(iRange.begin(), iRange.end(), std::move(comp));
  }

  template<class Range, class UnaryPredicate>
  bool all_of(Range &&iRange, UnaryPredicate pred)
  {
    return std::all_of(iRange.begin(), iRange.end(), std::move(pred));
  }

  template<class Range, class UnaryPredicate>
  bool any_of(Range &&iRange, UnaryPredicate pred)
  {
    return std::any_of(iRange.begin(), iRange.end(), std::move(pred));
  }

  template<class Range, class UnaryPredicate>
  bool none_of(Range &&iRange, UnaryPredicate pred)
  {
    return std::none_of(iRange.begin(), iRange.end(), std::move(pred));
  }

  template<class Range, class Function>
  void for_each(Range &&iRange, Function fun)
  {
    std::for_each(iRange.begin(), iRange.end(), std::move(fun));
  }

  template<class Range>
  auto unique(Range &&iRange)
  {
    return std::unique(iRange.begin(), iRange.end());
  }

  template<class Range, class BinaryPred>
  auto unique(Range &&iRange, BinaryPred pred)
  {
    return std::unique(iRange.begin(), iRange.end(), std::move(pred));
  }

  template<class Range>
  bool is_sorted(Range const &iRange)
  {
    return std::is_sorted(iRange.begin(), iRange.end());
  }

  template<class Range, class Compare>
  bool is_sorted(Range const &iRange, Compare comp)
  {
    return std::is_sorted(iRange.begin(), iRange.end(), std::move(comp));
  }

  template<class Range, class T>
  auto lower_bound(Range &&iRange, T const &val)
  {
    return std::lower_bound(iRange.begin(), iRange.end(), val);
  }

  template<class Range, class T, class Compare>
  auto lower_bound(Range &&iRange, T const &val, Compare comp)
  {
    return std::lower_bound(iRange.begin(), iRange.end(), val, std::move(comp));
  }

  template<class Range, class T>
  int lower_bound_index(Range &&iRange, T const &val)
  {
    return static_cast<int>(std::lower_bound(iRange.begin(), iRange.end(), val) - iRange.begin());
  }

  template<class Range, class T, class Compare>
  int lower_bound_index(Range &&iRange, T const &val, Compare comp)
  {
    return static_cast<int>(std::lower_bound(iRange.begin(), iRange.end(), val, std::move(comp)) - iRange.begin());
  }

  template<class Range, class T>
  auto upper_bound(Range &&iRange, T const &val)
  {
    return std::upper_bound(iRange.begin(), iRange.end(), val);
  }

  template<class Range, class T, class Compare>
  auto upper_bound(Range &&iRange, T const &val, Compare comp)
  {
    return std::upper_bound(iRange.begin(), iRange.end(), val, std::move(comp));
  }

  template<class Range, class T>
  int upper_bound_index(Range &&iRange, T const &val)
  {
    return static_cast<int>(std::upper_bound(iRange.begin(), iRange.end(), val) - iRange.begin());
  }

  template<class Range, class T, class Compare>
  int upper_bound_index(Range &&iRange, T const &val, Compare comp)
  {
    return static_cast<int>(std::upper_bound(iRange.begin(), iRange.end(), val, std::move(comp)) - iRange.begin());
  }
}

#endif
