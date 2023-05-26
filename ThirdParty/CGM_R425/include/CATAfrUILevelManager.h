/* -*-c++-*- */
#ifndef CATAfrUILevelManager_H
#define CATAfrUILevelManager_H
// -------------------------------------------------------------------
// Copyright Dassault Systemes 2006
//---------------------------------------------------------------------

#include "CATAfrFoundation.h"
#include "CATBoolean.h"


class ExportedByCATAfrFoundation CATAfrUILevelManager
{
public:

   //---------------------------------------------------------------
   /**
    * Check if we are in 3DXML Player
    */
   static CATBoolean Is3DXMLPlayerOn();
  
   //---------------------------------------------------------------
   /**
    * Check if we are in 3DLive Player
    */
   static CATBoolean Is3DLivePlayerOn();

   //---------------------------------------------------------------
   /**
    * Check new ergonomy phase 2 project is active
    */
   //static CATBoolean IsErgoPhase2On();
   
   //---------------------------------------------------------------
   /**
    * Check if 3DPLM Navigator is active
    */
   static CATBoolean Is3DPLMNavOn();
   
   //---------------------------------------------------------------
   /**
    * Check if PLM R2.1 UI is activated (no more File)
    */
   static int IsPhase2UILevelOn();
   
   /**
    * Check if PLM debug tools are available (Query, Open, Save...)
    */
   static int IsPLMDebugToolsOn();
};

#endif





