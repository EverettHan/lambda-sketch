#ifndef VisWintabData_H
#define VisWintabData_H
//
// CATIA Version 6 Release 1 Framework VisualizationFoundation
// Copyright Dassault Systemes 2012
//------------------------------------------------------------------------------
// Abstract : 	Define the basic data for Wintab packet
//------------------------------------------------------------------------------
// Usage : 
//------------------------------------------------------------------------------
// Class :	VisWintabData
//------------------------------------------------------------------------------

#define WT_NPressure            (0x0001)
#define WT_TPressure            (0x0002)
#define WT_Orientation          (0x0004)
#define WT_Rotation             (0x0008)

struct WintabPacket
{
   CATUINT32 WintabMode;

   float NPressure;//normal pressure
   float TPressure;//tangent pressure (airbrush fingerwheel)

   float OrAzimuth; //clockwise rotation of the cursor about the z axis
   float OrAltitude;//angle with the x-y plane
   float OrTwist;   //clockwise rotation of the cursor about its own major axis

   CATUINT32 Eraser;

   //Default constructor
   WintabPacket()
   {
      WintabMode = 0;

      NPressure  = 0.f;
      TPressure  = 0.f;

      OrAzimuth  = 0.f;
      OrAltitude = 0.f;
      OrTwist    = 0.f;

      Eraser = 0;
   }
} ;


//enum  NavigType {FLY_MODE, WALK_MODE};

#endif

