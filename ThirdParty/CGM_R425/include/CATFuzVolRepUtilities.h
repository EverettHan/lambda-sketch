// COPYRIGHT DASSAULT SYSTEMES 2003-2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATFuzVolRepUtilities.h
// Header definition of CATFuzVolRepUtilities
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2003  Creation: Code generated by the CAA wizard  JXV+MQP
//===================================================================
#ifndef CATFuzVolRepUtilities_H
#define CATFuzVolRepUtilities_H

//----------------------------------------------------------------------------------
/**
* Macro enabling <TT>CATFuzVolRepGraphicRepOperator</TT> usage.
*/
#define ENABLE_CATFuzVolRepGraphicRepOperator


//----------------------------------------------------------------------------------
/**
* Constant representing a distance value which has not been set yet.
*/
#define UNKNOWN_VALUE 1000000.0


//----------------------------------------------------------------------------------
/**
* The three space axis.
*
* <P><B>Note:</B> <TT>CATFuzVolRepAxisX</TT>, <TT>CATFuzVolRepAxisY</TT> and
* <TT>CATFuzVolRepAxisZ</TT> are aliases for <TT>CATFuzVolRepAxisI</TT>,
* <TT>CATFuzVolRepAxisJ</TT> and <TT>CATFuzVolRepAxisK</TT>.</P>
*/
typedef enum enum_CATFuzVolRepAxis
{
	CATFuzVolRepAxisI = 0,
	CATFuzVolRepAxisJ = 1,
	CATFuzVolRepAxisK = 2,
	CATFuzVolRepAxisX = 0,
	CATFuzVolRepAxisY = 1,
	CATFuzVolRepAxisZ = 2
} CATFuzVolRepAxis;

/**
* Constant array making conversion from int to <TT>CATFuzVolRepAxisI</TT>,
* <TT>CATFuzVolRepAxisJ</TT> and <TT>CATFuzVolRepAxisK</TT> easier.
*/
const CATFuzVolRepAxis intToCATFuzVolRepAxisIJK[3] =
{
	CATFuzVolRepAxisI,
	CATFuzVolRepAxisJ,
	CATFuzVolRepAxisK
};

/**
* Constant array making conversion from int to <TT>CATFuzVolRepAxisX</TT>,
* <TT>CATFuzVolRepAxisY</TT> and <TT>CATFuzVolRepAxisZ</TT> easier.
*/
const CATFuzVolRepAxis intToCATFuzVolRepAxisXYZ[3] =
{
	CATFuzVolRepAxisX,
	CATFuzVolRepAxisY,
	CATFuzVolRepAxisZ
};


//----------------------------------------------------------------------------------
/**
* Constant array storing voxel vertices position on I axis.
*/
const int deltaI[8] = {0, 0, 0, 0, 1, 1, 1, 1};

/**
* Constant array storing voxel vertices position on J axis.
*/
const int deltaJ[8] = {0, 0, 1, 1, 0, 0, 1, 1};

/**
* Constant array storing voxel vertices position on K axis.
*/
const int deltaK[8] = {0, 1, 0, 1, 0, 1, 0, 1};

#endif
