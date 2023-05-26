//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 1999                                         *
//*===========================================================================*
//*                                                                           *
//*  CATFile                                                                  *
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation decembre 99                                    adt              *
//*===========================================================================*
#ifndef __CATSIGTIMER
#define __CATSIGTIMER
#include "JS0ERROR.h"

class CATIntTimer;

class ExportedByJS0ERROR CATSigTimer
{
public:
  CATSigTimer(int  (*iFct)(void*));
  ~CATSigTimer();
  
  void SetTimer ( unsigned int iTime);
  void SetmsTimer ( unsigned int iTime);
  
private:
  CATIntTimer *_Timer;
};
#endif
