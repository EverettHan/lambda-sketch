/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2003  
//-----------------------------------------------------------------------------
// CATWSTraceServices :
// 
// Trace macros for Warm Start debug.
//
//-----------------------------------------------------------------------------
// Creation by User led
//-----------------------------------------------------------------------------



#ifndef CATWSTraceServices_H
#define CATWSTraceServices_H

/**
 * @level Private
 * @usage U1
 */

#include "CATOmbWarmStart.h"
#include "CATTrace.h"
#include "CATTraMacro.h"

extern ExportedByCATOmbWarmStart CATTrace Tra_WSDebug;
extern ExportedByCATOmbWarmStart CATTrace Tra_WSMarshal;

#ifndef CNEXT_CLIENT 

// Macro pour ecrire une chaine de caractere
#define CATWSPRINT(name,msg) TRAWRITE(name, msg)

// Macro pour ecrire un entier
#define CATWSPRINTI(name,msg, var) TRAWRITEI(name, msg, var)

// Macro pour ecrire un reel
#define CATWSPRINTF(name,msg, var)  TRAWRITEF(name, msg, var)

// Macro pour ecrire une adresse
#define CATWSPRINTFX(name, msg, var)  TRAWRITEX(name, msg, var)


// Macro pour ecrire une chaine de caractere precedee d un passage a la ligne
#define CATWSPRINTLN(name, msg)   TRAWRITELN(name, msg)

// Macro pour ecrire un entier precede d un passage a la ligne
#define CATWSPRINTILN(name, msg, var)  TRAWRITEILN(name, msg, var)

// Macro pour ecrire un reel precede d un passage a la ligne
#define CATWSPRINTFLN(name, msg, var)  TRAWRITEFLN(name, msg, var)

// Macro pour ecrire une adresse precedee d un passage a la ligne
#define CATWSPRINTXLN(name, msg, var)  TRAWRITEXLN(name, msg, var)

#else // si CNEXT_CLIENT .. pas de traces 
#define CATWSPRINT(name, msg)
#define CATWSPRINTI(name,msg, var) 
#define CATWSPRINTF(name,msg, var)
#define CATWSPRINTFX(name, msg, var)
#define CATWSPRINTLN(name, msg)
#define CATWSPRINTILN(name, msg, var)
#define CATWSPRINTFLN(name, msg, var)
#define CATWSPRINTXLN(name, msg, var)

#endif


#endif


   
