#ifndef	CAT_HashTable_CATRep_h
#define	CAT_HashTable_CATRep_h
//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//----------------------------------------------------------------
// Abstract : Generate a non-template collection-class with MACROS
//            (documentation on "Hash-Coding Tables")
// ----------------------------------------------------------------
//  Usage :   Hash-Table : instances of class CATRep
// ----------------------------------------------------------------
//  Inheritance : 
//                  
// ----------------------------------------------------------------
//  Main Methods :
//
//----------------------------------------------------------------------------
//
// clean previous functions requests
#include  <CATHTAB_Clean.h>

// require needed functions
//#include  <CATHTAB_AllFunct.h>
#define	CATHTAB_Locate
#define	CATHTAB_KeyLocate
#define	CATHTAB_Next
#define	CATHTAB_NextPosition
#define	CATHTAB_Remove
#define	CATHTAB_RemoveAll
#define	CATHTAB_Dimension
#define	CATHTAB_Collisions
#define	CATHTAB_PrintStats
//#define	CATHTAB_ostreamOP

// get macros
#include  <CATHTAB_Declare.h>

//													   
// generate interface of collection-class
// (functions declarations)
//
#undef CATCOLLEC_ExportedBy 
#define CATCOLLEC_ExportedBy 
CATHTAB_DECLARE( CATRep )

#endif
