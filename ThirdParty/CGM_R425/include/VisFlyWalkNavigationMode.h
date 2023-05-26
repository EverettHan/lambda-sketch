#ifndef VisFlyWalkNavigationMode_H
#define VisFlyWalkNavigationMode_H
//
// CATIA Version 6 Release 1 Framework VisualizationFoundation
// Copyright Dassault Systemes 2010
//------------------------------------------------------------------------------
// Abstract : 	Define the basic Fly and Walk navigation modes
//------------------------------------------------------------------------------
// Usage : 
//------------------------------------------------------------------------------
// Class :	VisFlyWalkNavigationMode
//------------------------------------------------------------------------------
#include "CATKeybdEventType.h"

#define Fly_Stopped             (0x0)
#define Fly_Forward             (0x1)
#define Fly_Backward            (0x2)
#define Fly_Turn_Left           (0x4)
#define Fly_Turn_Right          (0x8)
#define Fly_Turn_Up             (0x10)
#define Fly_Turn_Down           (0x20)
#define Fly_Translate_accel     (0x40)
#define Fly_Translate_decel     (0x80)
#define Fly_Rotate_accel        (0x100)
#define Fly_Rotate_decel        (0x200)

struct FlyKeyMap
{
   CATUINT32 Fly_Forward_Key;
   CATUINT32 Fly_Backward_Key;
   CATUINT32 Fly_Turn_Left_Key;
   CATUINT32 Fly_Turn_Right_Key;
   CATUINT32 Fly_Turn_Up_Key;
   CATUINT32 Fly_Turn_Down_Key;

   FlyKeyMap()
   {
      // initialize for US English keyboard (QWERTY)
      Fly_Forward_Key    = CATKeyCode_W; //"w"
      Fly_Backward_Key   = CATKeyCode_S; //"s"
      Fly_Turn_Left_Key  = CATKeyCode_A; //"a"
      Fly_Turn_Right_Key = CATKeyCode_D; //"d"
      Fly_Turn_Up_Key    = CATKeyCode_Q; //"q"
      Fly_Turn_Down_Key  = CATKeyCode_E; //"e"
   }
} ;

#define Walk_Stopped             (0x0)
#define Walk_Forward             (0x1)
#define Walk_Backward            (0x2)
#define Walk_Side_Left           (0x4)
#define Walk_Side_Right          (0x8)
#define Walk_Vertical_Up         (0x10)
#define Walk_Vertical_Down       (0x20)
#define Walk_Translate_accel     (0x40)
#define Walk_Translate_decel     (0x80)
#define Walk_Rotate_accel        (0x100)
#define Walk_Rotate_decel        (0x200)

struct WalkKeyMap
{
   CATUINT32 Walk_Forward_Key;
   CATUINT32 Walk_Backward_Key;
   CATUINT32 Walk_Side_Left_Key;
   CATUINT32 Walk_Side_Right_Key;
   CATUINT32 Walk_Vertical_Up_Key;
   CATUINT32 Walk_Vertical_Down_Key;

   WalkKeyMap()
   {
      // initialize for US English keyboard (QWERTY)
      Walk_Forward_Key       = CATKeyCode_W; //"w"
      Walk_Backward_Key      = CATKeyCode_S; //"s"
      Walk_Side_Left_Key     = CATKeyCode_A; //"a"
      Walk_Side_Right_Key    = CATKeyCode_D; //"d"
      Walk_Vertical_Up_Key   = CATKeyCode_Q; //"q"
      Walk_Vertical_Down_Key = CATKeyCode_E; //"e"
   }
} ;

enum  NavigType {FLY_MODE, WALK_MODE};

#define NO_DEVICE             (0x0)
#define KeyBoard              (0x1)
#define SpaceMouse            (0x2)

#endif

