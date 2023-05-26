#ifndef CATCkeDataTypes_h
#define CATCkeDataTypes_h
#ifdef CATCkeDataTypesActive
/** @CAA2Required */

/*  CAA2Reviewed by FRH */

//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************
//////////////////////////////////////////////////////////////////////////
// Copyright (C) 1996 Dassault-Systemes 
//
// Cke data types definitions

// primary data types



typedef CATUnicodeString String;
typedef double Real;
typedef int    Integer;

// boolean data type definition
#define CATCkeBooleanActive
#include "CATCkeBoolean.h"

#endif
#endif


