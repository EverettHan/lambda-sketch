#ifndef CATPolyComparPerfo_H
#define CATPolyComparPerfo_H
//====================================================================
// Copyright Dassault Systemes Provence 2010, All Rights Reserved 
//====================================================================
// DESCRIPTION : Classe permettant d'emregister et accumuler les stats et suivi perfos
//
//=============================================================================
// HISTORIQUE :
//  19/03/2013 : RNO : Big Update Automatic Add and count with STL
//  15/10/2010 : RNO   : Creation !! 
//=============================================================================
#include "ExportedByCATPolyComparOperators.h"

#include "CATPolyComparTimer.h"
#include "CATDataType.h"
//#include "CATMathInline.h"
#include <vector>
#include <map>
#include <iosfwd>
#include <iomanip.h>
#include <string>
#include <vector>
#include <functional>
#include <array>



const float OneDay=86400000.f;
class ExportedByCATPolyComparOperators CATPolyComparPerfoTimer
{
public:
  CATPolyComparPerfoTimer(int iTimeLogger=0):m_MinTimer(OneDay),m_MaxTime(0.f),m_TotalTime(0.f),m_NbCall(0), m_MaxTimeCallNum(0), m_LogTime(iTimeLogger){}
  virtual ~CATPolyComparPerfoTimer(){};
  //void Initialize(){m_MinTimer=OneDay;m_MaxTime=m_TotalTime=0.; m_NbCall=0;}
  inline void Start(){ m_Timer.Start();}
  inline void Stop()
  {
    m_NbCall++;
    float NewTime= m_Timer.Stop();
    if(NewTime<m_MinTimer) m_MinTimer=NewTime;
    if(NewTime > m_MaxTime)
    {
      m_MaxTime = NewTime;
      m_MaxTimeCallNum = m_NbCall;
    }
    m_TotalTime+=NewTime;
    if(m_LogTime)
      m_LoggedTime.push_back(NewTime);
  }

  float GetMinTime() const {return(m_MinTimer);}
  float GetMaxTime() const {return(m_MaxTime);}
  float GetTotalTime()const {return(m_TotalTime);}
  CATLONG32 GetNbCall()const {return(m_NbCall);}
  int GetLogTimeMode() const { return (m_LogTime); }
  inline const std::vector<float> & GetLogTime() const { return m_LoggedTime; }
private:
  std::vector<float> m_LoggedTime;
  CATPolyComparTimer m_Timer;
  float m_MinTimer,m_MaxTime, m_TotalTime;
  CATLONG32   m_NbCall,m_MaxTimeCallNum;
  int m_LogTime;
};


class ExportedByCATPolyComparOperators CATPolyComparPerfo
{
public:
  typedef std::function<double(const double & lhs, const double& rhs)> DoubleDataUpdaterFunc_t;
  typedef std::function<double(const int & lhs, const int& rhs)> IntDataUpdaterFunc_t;
  typedef std::array<std::string, 2> CATPolyComparPerfoDoubleKey_t;
  enum LogType
  {
    Timer,
    Memory,
    IntegerValue,
    DoubleValue
  };
  typedef std::pair<LogType, CATPolyComparPerfoDoubleKey_t> JournalItem_t;
  typedef std::vector<JournalItem_t> JournalResume_t;
  CATPolyComparPerfo();
  CATPolyComparPerfo(std::string && NameExt);
  CATPolyComparPerfo(const std::string & NameExt);
 // CATPolyComparPerfo(const std::string & iBasePathName) :m_BasePathName(iBasePathName),m_MaxMemUsed(0),m_MemNbCall(0), m_MaxMemPos(0) {}
  ~CATPolyComparPerfo();
  
  static CATULONG64 GetUsedMem();

  void StartTimer(const std::string & FirstKey, const std::string & SecondKey, int iKeepLog=0);
  void StopTimer(const std::string & FirstKey, const std::string & SecondKey);
  
  // add a given value to a given counter
  
  void UpdateCounterDouble( const std::string & FirstKey, const std::string & SecondKey, double d, DoubleDataUpdaterFunc_t Functor=std::plus<double>());
  void UpdateCounterInt( const std::string & FirstKey, const std::string & SecondKey, int i, IntDataUpdaterFunc_t Functor = std::plus<int>());

  

  //Suivi conso Memoire : Log la memoire max Utilisee
  void UpdateMaxMemUsed(const std::string & Key, int iLogMem=0);

  //void InitializeTimer(const std::string & FirstKey, const std::string & SecondKey);


  void DumpTimers(ostream * myStream) const;

  //Dump a Resume in a csv 
  void DumpResume(const JournalResume_t & iResume) const;

  //Log every value in a Separatefile
  void AddCounterValue(const std::string & FirstKey, const std::string & SecondKey, int iVal);
  void ResetAllTimers();//Will Empty the map !!!
private:
  std::string m_BasePathName;
  class CATPolyComparPerfoSecondKeys
  {
  public:

    CATPolyComparPerfoSecondKeys(){};
    ~CATPolyComparPerfoSecondKeys(){};
    
    void StartTimer(const std::string & MyTimer,  int KeepLog);
    void StopTimer(const std::string & MyTimer);

    //void Initialize(const std::string & MyTimer)){m_PerfoTimers[MyTimer].Initialize();}
    std::map <std::string, CATPolyComparPerfoTimer> m_PerfoTimers;
  };

  std::map <std::string, CATPolyComparPerfoSecondKeys> m_AllPerfoTimers;

  struct MemStats
  {
    inline MemStats() :m_MaxMemUsed(0), m_MemNbCall(0), m_MaxMemPos(0) {}
    std::vector<CATULONG64> m_LogMem;
    CATULONG64 m_MaxMemUsed;
    CATLONG32   m_MemNbCall, m_MaxMemPos;
  };
  std::map <std::string, MemStats> m_MemStats;


  std::map <CATPolyComparPerfoDoubleKey_t, double> m_DoubleCounters;
  std::map <CATPolyComparPerfoDoubleKey_t, int> m_IntegerCounters;
  std::map <std::string, std::map<std::string, std::vector<int>>> m_LoggedIntegerVals;
};  


//class ExportedByCATPolyComparOperators CATPolyComparPerfoScopedTimer
//{
//public:
//	inline CATPolyComparPerfoScopedTimer(CATPolyComparPerfo * Spy, const std::string && FirstKey, const std::string && SecondKey, int iKeepLog = 0)
//		:m_Spy(Spy), m_FirstKey(FirstKey), m_SecondKey(SecondKey)
//	{
//		if(m_Spy) m_Spy->StartTimer(FirstKey, SecondKey, iKeepLog);
//	}
//	inline ~CATPolyComparPerfoScopedTimer()
//	{
//		if(m_Spy) m_Spy->StopTimer(m_FirstKey, m_SecondKey);
//	}
//private:
//	CATPolyComparPerfo * m_Spy;
//  std::string  m_FirstKey;
//	std::string  m_SecondKey;
//};

#endif
