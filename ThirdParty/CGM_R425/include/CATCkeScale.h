// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATCkeScale.h
// Definition of the list of scales
//
//===================================================================

#ifndef CATCkeScale_H
#define CATCkeScale_H

/** 
* @CAA2Level L1
* @CAA2Usage U1 
*/

/*  CAA2Reviewed by FRH */

/**
* List of scales supported in CATIA. Some may not be activated.
*/
enum CATCkeScale
{
	CATNormalScale = 1,
	CATLargeScale = 2,
	CATExtraLargeScale = 3,
	CATSmallScale = 4,
	CATExtraSmallScale = 5,
	CATNanometricScale = 6

};

#endif

