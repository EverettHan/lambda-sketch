// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATVizNormalServices.h
// Header definition of CATVizNormalServices
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Sep 2003  Creation: Code generated by the CAA wizard  svq
//===================================================================
#ifndef CATVizNormalServices_H
#define CATVizNormalServices_H

#include "SGInfra.h"

unsigned short ExportedBySGInfra CATVizCompressNormal(float nx, float ny, float nz);
void ExportedBySGInfra CATVizUnCompressNormal(unsigned short normal, float & nx, float & ny, float & nz);

void ExportedBySGInfra CATVizCompressNormal36(float nx, float ny, float nz, short & cmp1, short & cmp2, unsigned char & flags);
//void ExportedBySGInfra CATVizCompressNormal36New(float nx, float ny, float nz, short & cmp1, short & cmp2, unsigned char & flags);
void ExportedBySGInfra CATVizUnCompressNormal36(short cmp1, short cmp2, unsigned char flags, short & nx, short & ny, short & nz);
void ExportedBySGInfra CATVizUnCompressNormal36(short cmp1, short cmp2, unsigned char flags, float & nx, float & ny, float & nz);
void ExportedBySGInfra CATVizUnCompressNormal36(short cmp1, short cmp2, unsigned char flags, double & nx, double & ny, double & nz);
//void ExportedBySGInfra CATVizUnCompressNormal36New(short cmp1, short cmp2, unsigned char flags, float & nx, float & ny, float & nz);
//void ExportedBySGInfra CATVizUnCompressNormal36New(short cmp1, short cmp2, unsigned char flags, double & nx, double & ny, double & nz);

void ExportedBySGInfra CATVizSimulateNormalCompression36(float iNx, float iNy, float iNz, short & oNx, short & oNz, short & oNy);
void ExportedBySGInfra CATVizSimulateNormalCompression36(float iNx, float iNy, float iNz, float & oNx, float & oNz, float & oNy);

void ExportedBySGInfra DecodePolarVectors35(unsigned char flagsIn, unsigned short angle1, unsigned short angle2, float *out, int normalize);
void ExportedBySGInfra DecodePolarVectors35(unsigned char flagsIn, unsigned short angle1, unsigned short angle2, double *out);
void ExportedBySGInfra DecodePolarVectors35(unsigned int nbVectors, unsigned char *flagsIn, unsigned short *anglesIn, float *out, int normalize = 0);
void ExportedBySGInfra DecodePolarVectors35(unsigned int nbVectors, unsigned char *flagsIn, unsigned short *anglesIn, double *out);
void ExportedBySGInfra EncodePolarVector35(float *in, unsigned char *flagsOut, unsigned short *anglesOut);
void ExportedBySGInfra EncodePolarVector35(unsigned int nbVectors, float *in, unsigned char *flagsOut, unsigned short *anglesOut);


void ExportedBySGInfra DecodePolarVectors32(unsigned int nbVectors, unsigned short *in, float *out);
void ExportedBySGInfra DecodePolarVectors32(unsigned int nbVectors, unsigned short *in, double *out);
void ExportedBySGInfra EncodePolarVector32(double *in, unsigned short *out);
//void ExportedBySGInfra DecodePolarVectors32bis(unsigned int nbVectors, unsigned short *in, float *out);
//void ExportedBySGInfra DecodePolarVectors32bis(unsigned int nbVectors, unsigned short *in, double *out);
//void ExportedBySGInfra EncodePolarVector32bis(float *in, unsigned short *out);


//-----------------------------------------------------------------------

#endif
