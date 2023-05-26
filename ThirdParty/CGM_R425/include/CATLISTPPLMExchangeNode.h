//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2014x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
#ifndef INCL_CATLISTPPLMExchangeNode_h
#define INCL_CATLISTPPLMExchangeNode_h
// COPYRIGHT DASSAULT SYSTEMES 2012
//
// *****************************************************************
//
//   Identification :
//   ---------------
//
//      RESPONSIBLE : Jean-Luc MEDIONI
//      FUNCTION    : Exchange Experience 
//      USE         : ENOVIA
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    To generate code to support list of PLMExchangeNode pointer
//
// *****************************************************************
//
//   Story :
//   -------
//
//   Revision 1.0  March 2007     (JLM) Initial Revision from PLMExchangeNode
//   Revision 2.0  December 2012  (JLM) Duplication to implement Exchange Experience Model 
//
// ****************************************************************
//
// INSIDE class:
// -------------
//
//
//
// ****************************************************************
// Abstract class    : No
// Template code     : No
// Ilined   Function : No
// ****************************************************************

/**
 * @collection CATLISTP(PLMExchangeNode)
 * Collection class for pointers to <tt>PLMExchangeNode</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 *
 * @see PLMExchangeNode
 */

// --- Clean previous functions requests

#include "CATLISTP_Clean.h"

// --- Specify the function to take into account.

//#include <CATLISTP_AllFunct.h>  // --- To include all methods

//#define	CATLISTP_CtorFromArrayPtrs
#define	CATLISTP_Append
#define	CATLISTP_AppendList
//#define	CATLISTP_InsertAt
#define	CATLISTP_ReSize
#define	CATLISTP_Locate
#define	CATLISTP_RemoveValue
//#define	CATLISTP_RemoveList
#define	CATLISTP_RemovePosition
#define	CATLISTP_RemoveAll
//#define	CATLISTP_RemoveNulls
#define	CATLISTP_RemoveDuplicates
//#define	CATLISTP_Compare
//#define	CATLISTP_Swap
//#define	CATLISTP_QuickSort
//#define	CATLISTP_FillArrayPtrs
//#define	CATLISTP_NbOccur
//#define	CATLISTP_Intersection

// --- Get macros

#include "CATLISTP_Declare.h"

// --- Define the NT DLL export macro

#include "PLMExchangeModel.h"

#undef   CATCOLLEC_ExportedBy
#define  CATCOLLEC_ExportedBy ExportedByPLMExchangeModel

// --- Declare the CATLISTP(PLMExchangeNode) type.

#include "PLMExchangeNode.h"

CATLISTP_DECLARE(PLMExchangeNode)

typedef  CATLISTP(PLMExchangeNode) CATListOfPLMExchangeNode ;

#endif
 
