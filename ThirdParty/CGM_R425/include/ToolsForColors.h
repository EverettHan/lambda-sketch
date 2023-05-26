#ifndef ToolsForColors_H
#define ToolsForColors_H

//******************************************************************************
// VERSION 5 RELEASE 1
// COPYRIGHT DASSAULT SYSTEMES 1996
//******************************************************************************
//
//  Abstract:
//  ---------
//    These functions convert RGB->HSL or HSL->RGB
//
//******************************************************************************
//
//  Usage:
//  ------
//
//******************************************************************************
//  Inheritance:
//  ------------
//
//******************************************************************************
//  Main Methods:
//  -------------
//
//******************************************************************************


/**
 * @quickReview CDT 02:12:06
 **/

#include "SceneGraphManager.h"

extern "C" 
{
void ExportedBySceneGraphManager ConvertFloatRGBToFloatHSL(float,float,float,float*,float*,float*); 
void ExportedBySceneGraphManager ConvertIntRGBToIntHSL(int,int,int,int*,int*,int*); 
void ExportedBySceneGraphManager ConvertIntRGBToFloatHSL(int,int,int,float*,float*,float*); 
void ExportedBySceneGraphManager ConvertFloatRGBToIntHSL(float,float,float,int*,int*,int*); 
void ExportedBySceneGraphManager ConvertFloatHSLToFloatRGB(float,float,float,float*,float*,float*); 
void ExportedBySceneGraphManager ConvertIntHSLToIntRGB(int,int,int,int*,int*,int*); 
void ExportedBySceneGraphManager ConvertIntHSLToFloatRGB(int,int,int,float*,float*,float*); 
void ExportedBySceneGraphManager ConvertFloatHSLToIntRGB(float,float,float,int*,int*,int*); 
float ExportedBySceneGraphManager Value(float,float,float);


/* Convert RBG to HSV
 * input  : RGB each in [0, 255]
 * output : H in [0,2*PI], S in [0.1], V in [0,1] 
 *          if S equal 0 ==> H = 0
 */
void  ExportedBySceneGraphManager ConvertIntRBGToFloatHSV(int iR, int iG, int iB, float *oH, float *oS, float *oV);


}


/*
 * H in [0,2*PI], S in [0.1], V in [0,1] 
 * if S equal 0 ==> H = 0
 */
class ExportedBySceneGraphManager HSVColor
{
public :
   float _H; /* Hue */
   float _S; /* Saturation */
   float _V; /* Value = Brightness */
} ;


class ExportedBySceneGraphManager CATRGBAColor
{
public :
  CATRGBAColor () {_R=0x00; _G=0x00; _B=0x00;_A=0x00;};
   unsigned char _R; /* Red Component   */
   unsigned char _G; /* Green Component */
   unsigned char _B; /* Blue Component  */
   unsigned char _A; /* Alpha Component */
} ;


#endif
