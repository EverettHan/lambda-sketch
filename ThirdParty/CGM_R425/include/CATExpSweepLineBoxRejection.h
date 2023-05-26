//==============================================================================================================
// Copyright Dassault Systemes Provence 2013-2016, All Rights Reserved 
//==============================================================================================================
// Usage notes:
//==============================================================================================================
// 2020-04-10 - rno : Controle que les vecteurs d'entrées sont non vide pour appeler begin dessus
// 2016-08-18 - MMO : Ajout de #include <iterator>  pour corriger l'erreur de compilation VS2015
// 2014-09-02 - T6L : Sweep line for box rejection;
// 2014-06-23 - T6L : Pixellization of box rejection;
//==============================================================================================================


#ifndef CATExpSweepLineBoxRejection_H
#define CATExpSweepLineBoxRejection_H

#include "CATExpBoundingBox.h"

#include <vector>
#include <deque>
#include <set>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <functional>
#include <iterator> 
#include <iostream>

/**
* @pre We can iterate over Input1 deterministically.
*/
template <class Object1, class Input1, class Output1, class Object2>
class CATExpSweepLineHelper
{
  template <class, class, class> friend class CATExpSweepLineBoxRejection;
  template <class, class, class, class, class, class> friend class CATExpSweepLineDualBoxRejection;

  static void RecordBoundingBoxes( const Input1 &input, const std::function<const CATExpBoundingBox * (const Object1 &)> &bounding_box_getter,
							      std::vector<std::pair<double, Object1>> &min_x,  std::vector<std::pair<double, Object1>> &max_x, 
								   std::vector<std::pair<double, Object1>> &min_y,  std::vector<std::pair<double, Object1>> &max_y )
  {
    auto const size = input.size();
    min_x.reserve(size);
    max_x.reserve(size);
    min_y.reserve(size);
    max_y.reserve(size);
    for (const auto &object : input)
    {
      auto bb = bounding_box_getter(object);
      min_x.push_back(std::make_pair(bb->x_lb, object));
      max_x.push_back(std::make_pair(bb->x_ub, object));
      min_y.push_back(std::make_pair(bb->y_lb, object));
      max_y.push_back(std::make_pair(bb->y_ub, object));
    }

    std::sort(min_x.begin(), min_x.end());
    std::sort(max_x.begin(), max_x.end());
    std::sort(min_y.begin(), min_y.end());
    std::sort(max_y.begin(), max_y.end());
  }

  static void Record
  (
    typename std::vector<std::pair<double, Object1>>::const_iterator &min1,
    std::set<Object1> &active_objects1, std::set<Object2> &active_objects2,
    std::unordered_map<Object1, std::deque<Object2> > &candidates1, std::unordered_map<Object2, std::deque<Object1> > &candidates2
  )
  {
    for (const auto &object2 : active_objects2)
    { 
      candidates2[object2].push_back(min1->second);
      candidates1[min1->second].push_back(object2);
    }
    active_objects1.insert(min1->second);
    ++min1;
  }

  static void Erase (typename std::vector<std::pair<double, Object1>>::const_iterator &max1, std::set<Object1> &active_objects1)
  {
    active_objects1.erase(max1->second);
    ++max1;
  }

  static void IntersectCandidates
    (const Input1 &input, std::unordered_map<Object1, std::deque<Object2> > &x_candidates, std::unordered_map<Object1, std::deque<Object2> > &y_candidates, Output1 &result)
  {
    for (const auto &element : input)
    {
      std::sort(x_candidates[element].begin(), x_candidates[element].end());
      std::sort(y_candidates[element].begin(), y_candidates[element].end());
      std::set_intersection(x_candidates[element].begin(), x_candidates[element].end(),
        y_candidates[element].begin(), y_candidates[element].end(), std::back_inserter(result[element]));
    }
  }
};

/**
* @pre We can iterate over Input deterministically.
* @pre result is allocated: result[i] is an empty sequential container for all i in input.
*/
template <class Object, class Input, class Output>
class CATExpSweepLineBoxRejection
{
public:
  static void Compute
  (
    const Input &input,
    const std::function<const CATExpBoundingBox * (const Object &)> &bounding_box_getter,
    Output &result
  )
  {
    std::vector<std::pair<double, Object> > min_x, max_x, min_y, max_y;
    std::unordered_map<Object, std::deque<Object> > x_candidates, y_candidates;

    CATExpSweepLineHelper<Object, Input, Output, Object>::RecordBoundingBoxes
      (input, bounding_box_getter, min_x, max_x, min_y, max_y);

    CATExpSweepLineBoxRejection<Object,Input,Output>::ComputeCandidatesAlongOneCoordinate(min_x, max_x, x_candidates);
    CATExpSweepLineBoxRejection<Object,Input,Output>::ComputeCandidatesAlongOneCoordinate(min_y, max_y, y_candidates);

    return CATExpSweepLineHelper<Object, Input, Output, Object>::IntersectCandidates
      (input, x_candidates, y_candidates, result);
  }
  
private:
  static void ComputeCandidatesAlongOneCoordinate
    (const std::vector<std::pair<double, Object> > &min_vector, const std::vector<std::pair<double, Object> > &max_vector, std::unordered_map<Object, std::deque<Object> > &map)
  {
	   //std::cout << "CATExpSweepLineBoxRejection::ComputeCandidatesAlongOneCoordinate"<< std::endl;
    if (min_vector.empty() || max_vector.empty()){       std::cout << "CATExpSweepLineBoxRejection::ComputeCandidatesAlongOneCoordinate empty input vectors " << std::endl;    return;}
    std::set<Object> active_objects;
    auto min = min_vector.begin(), max = max_vector.begin();
    const auto min_end = min_vector.end();

    while (min < min_end)
    {
      if (min->first <= max->first) CATExpSweepLineHelper<Object, Input, Output, Object>::Record
        (min, active_objects, active_objects, map, map);
      else CATExpSweepLineHelper<Object, Input, Output, Object>::Erase(max, active_objects);
    }
  }

};


/**
* @pre We can iterate over Input deterministically.
* @pre result is allocated: result[i] is an empty sequential container for all i in input.
*/
template <class Object1, class Input1, class Output1, class Object2, class Input2, class Output2>
class CATExpSweepLineDualBoxRejection
{
public:
  static void Compute
  (
    const Input1 &input1,
    const std::function<const CATExpBoundingBox * (const Object1 &)> &bounding_box_getter1,
    Output1 &result1,
    const Input2 &input2,
    const std::function<const CATExpBoundingBox * (const Object2 &)> &bounding_box_getter2,
    Output2 &result2
  )
  {
    std::vector<std::pair<double, Object1> > min_x1, max_x1, min_y1, max_y1;
    std::vector<std::pair<double, Object2> >  min_x2, max_x2, min_y2, max_y2;
    std::unordered_map<Object1, std::deque<Object2> > x_candidates1, y_candidates1;
    std::unordered_map<Object2, std::deque<Object1> > x_candidates2, y_candidates2;

    CATExpSweepLineHelper<Object1, Input1, Output1, Object2>::RecordBoundingBoxes
      (input1, bounding_box_getter1, min_x1, max_x1, min_y1, max_y1);
    CATExpSweepLineHelper<Object2, Input2, Output2, Object1>::RecordBoundingBoxes
      (input2, bounding_box_getter2, min_x2, max_x2, min_y2, max_y2);

    ComputeCandidatesAlongOneCoordinate(min_x1, max_x1, min_x2, max_x2, x_candidates1, x_candidates2);
    ComputeCandidatesAlongOneCoordinate(min_y1, max_y1, min_y2, max_y2, y_candidates1, y_candidates2);

    CATExpSweepLineHelper<Object1, Input1, Output1, Object2>::IntersectCandidates
      (input1, x_candidates1, y_candidates1, result1);
    CATExpSweepLineHelper<Object2, Input2, Output2, Object1>::IntersectCandidates
      (input2, x_candidates2, y_candidates2, result2);
  }
  
private:
  static void ComputeCandidatesAlongOneCoordinate
  (
    const std::vector<std::pair<double, Object1> > &min_vector1, const std::vector<std::pair<double, Object1> > &max_vector1,
    const std::vector<std::pair<double, Object2> >  &min_vector2, const std::vector<std::pair<double, Object2> >  &max_vector2,
    std::unordered_map<Object1, std::deque<Object2> > &map1, std::unordered_map<Object2, std::deque<Object1> > &map2
  )
  {
    if (min_vector1.empty() || max_vector1.empty() || min_vector2.empty() || max_vector2.empty()) 
      return;

    std::set<Object1> active_objects1;
    std::set<Object2> active_objects2;
    auto min1 = min_vector1.begin(), max1 = max_vector1.begin();
    auto min2 = min_vector2.begin(), max2 = max_vector2.begin();
    const auto min_end1 = min_vector1.end(), max_end1 = max_vector1.end();
    const auto min_end2 = min_vector2.end(), max_end2 = max_vector2.end();

    while (min1 < min_end1 || min2 < min_end2)
    {
      double min_coord = DBL_MAX;
      if (min1 < min_end1) min_coord = std::min<double>(min_coord, min1->first);
      if (max1 < max_end1) min_coord = std::min<double>(min_coord, max1->first);
      if (min2 < min_end2) min_coord = std::min<double>(min_coord, min2->first);
      if (max2 < max_end2) min_coord = std::min<double>(min_coord, max2->first);
      
      bool insertion = false;

      if (min1 < min_end1 && min_coord == min1->first)
      {
        CATExpSweepLineHelper<Object1, Input1, Output1, Object2>::Record
          (min1, active_objects1, active_objects2, map1, map2);
        insertion = true;
      }

      if (min2 < min_end2 && min_coord == min2->first)
      {
        CATExpSweepLineHelper<Object2, Input2, Output2, Object1>::Record
          (min2, active_objects2, active_objects1, map2, map1);
        insertion = true;
      }

      if (! insertion)
      {
        if (max1 < max_end1 && min_coord == max1->first)
          CATExpSweepLineHelper<Object1, Input1, Output1, Object2>::Erase (max1, active_objects1);

        if (max2 < max_end2 && min_coord == max2->first)
          CATExpSweepLineHelper<Object2, Input2, Output2, Object1>::Erase (max2, active_objects2);
      }
    }
  }
};

#endif
