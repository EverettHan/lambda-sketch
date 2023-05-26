#ifndef CATToolsForColors_H
#define CATToolsForColors_H

//******************************************************************************
// VERSION 5 RELEASE 16
// COPYRIGHT DASSAULT SYSTEMES 2005
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
 * @quickReview YWG 05:03:17 Move the ToolsForColors code from Visualization to VisualizationBase
 **/

#include "SGInfra.h"

extern "C" 
{
   /* Convert RGB / HSL
   * int RGB each in [0, 255] - float RGB each in [0., 1.]
   * int HSL each in [0, 255] - float HSL each in [0., 1.]
   *          if S equal 0 ==> H = 0
   */
   void ExportedBySGInfra CATConvertFloatRGBToFloatHSL(float,float,float,float*,float*,float*); 
   void ExportedBySGInfra CATConvertFloatHSLToFloatRGB(float,float,float,float*,float*,float*); 

   void ExportedBySGInfra CATConvertIntRGBToIntHSL(int,int,int,int*,int*,int*); 
   void ExportedBySGInfra CATConvertIntHSLToIntRGB(int,int,int,int*,int*,int*); 

   void ExportedBySGInfra CATConvertIntRGBToFloatHSL(int,int,int,float*,float*,float*); 
   void ExportedBySGInfra CATConvertFloatHSLToIntRGB(float,float,float,int*,int*,int*); 

   void ExportedBySGInfra CATConvertFloatRGBToIntHSL(float,float,float,int*,int*,int*); 
   void ExportedBySGInfra CATConvertIntHSLToFloatRGB(int,int,int,float*,float*,float*); 

   /* Convert RBG to HSV
   * input  : RGB each in [0, 255]
   * output : H in [0,2*PI], S in [0.1], V in [0,1] 
   *          if S equal 0 ==> H = 0
   */
   void  ExportedBySGInfra CATConvertIntRBGToFloatHSV(int iR, int iG, int iB, float *oH, float *oS, float *oV);

   /* Convert RGB / HSV
   * int RGB each in [0, 255] - float RGB each in [0., 1.]
   * int HSV each in [0, 255] - float HSV each in [0., 1.]
   *          if S equal 0 ==> H = 0
   */
   void ExportedBySGInfra CATConvertFloatRGBToFloatHSV(float, float, float, float*, float*, float*); 
   void ExportedBySGInfra CATConvertFloatHSVToFloatRGB(float, float, float, float*, float*, float*); 

   void ExportedBySGInfra CATConvertIntRGBToIntHSV(int, int, int, int*, int*, int*); 
   void ExportedBySGInfra CATConvertIntHSVToIntRGB(int, int, int, int*, int*, int*); 

   void ExportedBySGInfra CATConvertIntRGBToFloatHSV(int, int, int, float*, float*, float*); 
   void ExportedBySGInfra CATConvertFloatHSVToIntRGB(float, float, float, int*, int*, int*); 

   void ExportedBySGInfra CATConvertFloatRGBToIntHSV(float, float, float, int*, int*, int*); 
   void ExportedBySGInfra CATConvertIntHSVToFloatRGB(int, int, int, float*, float*, float*); 
}
#endif
