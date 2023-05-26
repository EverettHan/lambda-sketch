#ifndef CATLISTP_CATV4ATTRIBUTES_H
#define CATLISTP_CATV4ATTRIBUTES_H
///////////////////////////////////////////////////////////////////////////////
// COPYRIGHT DASSAULT SYSTEMES  2003                                         //
// ========================================================================= //
//                                                                           //
// CATLISTV :                                                                //
//                                                                           //
// Base class for CATLISTP of  CATV4Attributes                               //
// ========================================================================= //
///////////////////////////////////////////////////////////////////////////////
/**
* @level Protected 
* @usage U1
*/
//
// --------------------------------------------------------------------------
//                              Exported by module
// --------------------------------------------------------------------------
//
#include "ExportedByCATV4Attributes.h"
//
// --------------------------------------------------------------------------
//                       Clean previous functions requests
// --------------------------------------------------------------------------
//
#include "CATLISTP_Clean.h"
//
// --------------------------------------------------------------------------
//                           Require needed functions
// --------------------------------------------------------------------------
//
#define  CATLISTP_Append
#define  CATLISTP_Locate
#define  CATLISTP_RemoveValue
#define  CATLISTP_RemovePosition
#define  CATLISTP_RemoveAll
//
// --------------------------------------------------------------------------
//                                  Get macros
// --------------------------------------------------------------------------
//
#include "CATLISTP_Declare.h"
//
// --------------------------------------------------------------------------
//                       Generate interface of collection-class
// --------------------------------------------------------------------------
//
class CATV4Attributes;
 
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATV4Attributes

CATLISTP_DECLARE( CATV4Attributes )
 
#endif
