#ifndef CATFrFFamilyDebug_H
#define CATFrFFamilyDebug_H
// COPYRIGHT DASSAULT SYSTEMES 2016
//=============================================================================
//
// CATFrFFamilyDebug: Debug infrastructure for software family
//
//=============================================================================
// Usage notes:
//
// Not to be used directly: use a specific derived class. See CATFrFCombDebug for example
// - implement a derived class
// - implement a breakpoint
// - implement declarative variables to initialize behaviour
//
//=============================================================================
// 22/11/11 NLD Création de CATFrFCombDebug
// 11/03/16 NLD Création de CATFrFFamilyDebug Generalisation/extension de CATFrFCombDebug
//              definition generale pour une famille de softs CATFrFFamilyDebug_Info
//              Ajout Usage notes
//=============================================================================

#include "FrFObjects.h"

#include "CATStaticCGM.h"
#include "CATCompactCallStackManager.h"

//=============================================================================
typedef enum {CATFrFFamilyDebug_Trace = 1,
              CATFrFFamilyDebug_Start = 2,
              CATFrFFamilyDebug_End   = 3
             }CATFrFFamilyDebug_Info;

//=============================================================================
// General family debug class definition
//=============================================================================
class CATFrFFamilyDebugStaticData : public CATStaticCGM
  {
   public:

   CATCompactCallStackManager _CallStackManager;
   int                        _ActiveTrace;
   int                        _ActiveCallStack;
   int                        _OKInitCallStack;
   int                        _Level;


                CATFrFFamilyDebugStaticData();
           //------------------------------------------------------------------
           void Init(int iActiveDebug);


           //------------------------------------------------------------------
           // faire plutot un GetOperatorId()?
   virtual void WritePrefix() = 0;
           //------------------------------------------------------------------

           //------------------------------------------------------------------
           void BreakPoint    (char                   *  iDebugText       ,
                               CATFrFFamilyDebug_Info    Info             ,
                               int                     & ioActiveTrace    , // (modifiable au debugger) Activation des traces
                               int                     & ioActiveCallStack  // (modifiable au debugger) Activation de la callstack
                              );
           //------------------------------------------------------------------
  };

#endif
