//* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1998
//-----------------------------------------------------------------------------
//
// CATIAPrjEntityCommon.h
//
//-----------------------------------------------------------------------------
// Usage Notes:
//   
//   Definition of common variables and structures used to manipulate a
//   CATIAPrjEntity instance.
//
//-----------------------------------------------------------------------------
// Creation by LJH - September 1998
//-----------------------------------------------------------------------------
/**
* @level Protected 
* @usage U1
*/
#ifndef CATIAPrjEntityCommon_h
#define CATIAPrjEntityCommon_h

//
// Definition des index de tableaux
#define TAB_INDEX_ATTRIB     0
#define TAB_INDEX_CLASS      1
#define TAB_INDEX_TCDES      2
#define TAB_INDEX_TCSTD      3
#define TAB_INDEX_PATDES     4
#define TAB_INDEX_PATID      5
#define TAB_INDEX_PATMOT     6

//
// Definition des masks pour definir les acces aux tables du PRJ
#define TAB_ATTRIB      0x0001
#define TAB_CLASS       0x0002
#define TAB_TCDES       0x0004
#define TAB_TCSTD       0x0008
#define TAB_PATDES      0x0010
#define TAB_PATID       0x0020
#define TAB_PATMOT      0x0040

#endif
