//
//===================================================================
// Copyright Dassault Systemes Provence 2009-2014, all rights reserved
//===================================================================
// Usage notes:
//
//===================================================================
// 26/06/14 : HLN ; Add CATFrFFSWarning structure
// 02/07/09 : MWE ; Creation d'apres CATClassATopoOperators\ProtectedInterfaces\CATCltError.h
//===================================================================
#ifndef CATFrFFSError_H
#define CATFrFFSError_H

struct CATFrFFSError
{
public :
  typedef enum 
  {
    NoError,
    NothingSelected,
    ActionRejected,
    SendMessageFailed,
    UnSpecifiedError,
    SelectionIncomplete,
    TrimmingIncompleteOrFailed,
    TrimmingIncomplete,
    TrimmingFailed,
    ProbablyDistortedSurface,
    FoldedOrTwistedOrUselessFilletSurface,
    WireIsNotOnShellBoundary,
    ApproxTolNotRespected,
    ActionInterrupted
  } 
  Error;
};

struct CATFrFFSWarning
{
public :
  typedef  enum 
  {
    NoWarning,
    TwistedSurface,
    PointedSurface
  } 
  Warning;
};
#endif
