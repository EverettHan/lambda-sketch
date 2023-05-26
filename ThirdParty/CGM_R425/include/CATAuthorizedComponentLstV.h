//-------------------------------------------------------------------------
//
// COMPOSANT : System
//
//-------------------------------------------------------------------------
//  HISTORIQUE :   
//    Creation  Feb 98                                           ADH
//-------------------------------------------------------------------------
// CATAuthorizedComponentLstP :
//    Classe liste de pointeurs sur CATAuthorizedComponent
//--------------------------------------------------------------------------

#ifndef CATAuthorizedComponentLstV_H
#define CATAuthorizedComponentLstV_H

// COPYRIGHT DASSAULT SYSTEMES 2000
//
// Exportation du module ** WINDOWS_NT
//
#if defined(__COMPONENTV2)
#define ExportedByCOMPONENTV2 DSYExport
#else
#define ExportedByCOMPONENTV2 DSYImport
#endif
#include "DSYExport.h"

//===================================================================
//                          IMPORT
//===================================================================

#ifdef _CAT_ANSI_STREAMS
/** @c++ansi aew 2004-08-02.20:04:48 [Replace forward declaration of standard streams with iosfwd.h] **/
 #include "iosfwd.h" 
#else //!_CAT_ANSI_STREAMS 
class ostream;
#endif //_CAT_ANSI_STREAMS

class CATAuthorizedComponent;

//===================================================================
//                          EXPORT
//===================================================================

#include "CATLISTV_Clean.h"

#define	CATLISTV_Append
#define	CATLISTV_AppendList
#define	CATLISTV_InsertAfter
#define	CATLISTV_InsertBefore
#define	CATLISTV_InsertAt
#define	CATLISTV_ReSize
#define	CATLISTV_Locate
#define	CATLISTV_RemoveValue
#define	CATLISTV_RemoveList
#define	CATLISTV_RemovePosition
#define	CATLISTV_RemoveAll
#define	CATLISTV_RemoveNulls
#define	CATLISTV_RemoveDuplicates
#define	CATLISTV_RemoveDuplicatesExtract
#define	CATLISTV_RemoveDuplicatesCount
#define	CATLISTV_Replace
#define	CATLISTV_Swap
#define	CATLISTV_QuickSort
#define	CATLISTV_NbOccur
#define	CATLISTV_Intersection
#define	CATLISTV_PrintAddr

#include "CATLISTV_Declare.h"

//
// exportation du module
//
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCOMPONENTV2

//
// declaration du type CATLISTVtrCATAuthorizedComponent
//
CATLISTV_DECLARE (CATAuthorizedComponent)

//
// type homonyme
//
typedef  CATLISTV(CATAuthorizedComponent)  CATAuthorizedComponentLstV;

#endif




