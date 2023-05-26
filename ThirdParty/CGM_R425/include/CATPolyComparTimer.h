/* -*-C++-*-*/
#ifndef CATPolyComparTimer_H
#define CATPolyComparTimer_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES PROVENCE 2009
//
// CATFineClock : Un timer plus precis (POur les temps <0.015secondes)quand il est dispo 
//
//
//==========================================================
// History
//==========================================================
// 14/10/2016 : RNO : Migration sur STL CHRONO
// 2015.01.08 : RNO : CATFINE TIMER AllINLINE et sans Export
// 2012.10.16 : RAQ : Ajout Reset dans Stop
// 22/01/2009 RNO : Creation
//==========================================================


//Pour Perfo

#include <ctime>
#include <ratio>
#include <chrono>

#include "CATMathInline.h"

class  CATPolyComparTimer 
{ 

public: 
  INLINE CATPolyComparTimer() :m_Start(std::chrono::high_resolution_clock::now()) {}
  INLINE ~CATPolyComparTimer(){}
  INLINE void Start()
  {
    m_Start = std::chrono::high_resolution_clock::now();
  }
  INLINE float Stop(const bool iReset = false)//Time in seconds
  {
    std::chrono::duration<float> time_span = std::chrono::duration_cast<std::chrono::duration<float>>(std::chrono::high_resolution_clock::now() - m_Start);
    if(iReset)
    {
      m_Start = std::chrono::high_resolution_clock::now();
    }
    return time_span.count();
  }
private: 
  
  std::chrono::high_resolution_clock::time_point m_Start;

}; 



#endif
