//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//==========================================================================
//
// 
//
//==========================================================================
// Usage Notes 
//==========================================================================
//
//========================================================================== 
#ifndef CATGlobdefCommand_H
#define CATGlobdefCommand_H

#include "FrFObjects.h"
#include "CATDataType.h"
#include "CATCGMVirtual.h"


class ExportedByFrFObjects CATGlobdefCommand  : public CATCGMVirtual
{
public:
  
  //=============                           
  CATGlobdefCommand() ;
  virtual  ~CATGlobdefCommand();
  
  
  void  SetKeepAnalysisNormalForSynth() ;
    
  
  void  ResetKeepAnalysisNormalForSynth() ;
  
  CATLONG32 IsAnalysisNormalKeptForSynth() ;
  
  

    
    
  private :
   CATLONG32 _AnalysisNormalKept ; 
   
};
#endif
