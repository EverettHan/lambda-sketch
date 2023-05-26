#ifndef CATSysStsBaseCmd_H
#define CATSysStsBaseCmd_H

// COPYRIGHT  DASSAULT SYSTEMES 2003

#include "CATLib.h"
#include "CATCommand.h"

#define CATSysStsCommandType -1
//===================================================================
// Base class for Status Commands Serviceability class
//===================================================================
class ExportedByJS0FM  CATSysStsBaseCmd : public CATCommand
{
  //===================================
  public:
  //= public methods ==================
  void Toggle(int iBegin, int iReal) ;
  float GetMem(){return _MemoryUse ;};
  float GetFrag(){ return _FragRisk;};
  virtual void Idle(){} ;
  virtual void SelectTypeForMemoryIcon( int i){return ;};

  static CATSysStsBaseCmd *GetMain(int iMainBasis=CATSysStsCommandType) ;
  static void S_TimeOut(CATSysStsBaseCmd *ToClient,int iTime,void *Data);

  int SetFilterFunction(int (*iFunc)( float iEla, float iCpu, 
                                       float *oEla , float *oCpu) );


  //===================================
  protected:
  //= protected methods ===============
  CATSysStsBaseCmd();
  virtual ~CATSysStsBaseCmd();
  void ActivateCallback();
  void DeactivateCallback();

  //= protected data  =================
  static CATSysStsBaseCmd *S_Command;


  //===================================
  protected:
  //= private data  ===================
  float _CurELA;
  float _CurCPU;
  float _OldELA;
  float _OldCPU;
  float _FragRisk;
  float _MemoryUse;
  float _OldMemory;
  int   (*_FilterFunc)(float,float,float *,float *);
  float _OldFrag;
  private:
  float _TotalELA;
  int _InTimeOut;
  int _Subscribed;
  CATTimerId _TimerId;
};

#endif
