#ifndef CATIsActiveLevel_H
#define CATIsActiveLevel_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATIAV5Level.h"
#include "JS0LIB.h"
/**
 * CATDEVFLAG_IF
 *
 * CAT Runtime Flag If ( development_id )
 */
#define  CATDEVFLAG_IF( a ) if ( CATIsActiveLevel( #a ) ) {

/**
 * CATDEVFLAG_ELSE
 *
 * CAT Runtime Flag Else
 * 
 */
#define  CATDEVFLAG_ELSE } else {

/**
 * 
 * CATDEVFLAG_ENDIF
 *
 * CAT Runtime Flag End If
 */
#define  CATDEVFLAG_ENDIF } 


/**
 *  int CATIsActiveLevel( const char *iTestedLevel );
 *  
 *  this service permits to know if a development is active or not
 *   
 *  iTestedLevel may receive as input :
 *             V5Rn (V5R4/V5R5/.. ) : in this case CATIsActiveLevel will
 *                   return -1   if the current level is superior or
 *                            equal to iTestedLevel
 *                   return 0     if it is not the case
 *
 *             a development name : in this case 3 options are possible
 *			1) iTestedLevel is in the authorized developments
 *                         table and the development is active (GA)
 *                          return TRUE
 *			2) iTestedLevel is in the authorized developments
 *                         table and the development  is conditional(LA)
 *                          return TRUE if the environment variable 
 *                          corresponding to iTestedLevel is set    
 *                          return FALSE in it is not set
 *			3) iTestedLevel is not in the authorized developments
 *                           return FALSE
 * 
 *             a development name is a string with no blanks 
 *
 * The environment variable corresponding to a development TestedLevel is
 *  CATDevTestedLevel
 *  Example : CATDevNewDrafting if iTestedLevel=="NewDrafting" 
 */
extern "C"
{
 ExportedByJS0LIB int CATIsActiveLevel( const char *iTestedLevel);
}

/**
 *  const char * CATGetActiveLevelName ();
 *  
 *  this service permits to know the Level Name for this session
 *   
 */
extern "C"
{
 ExportedByJS0LIB const char * CATGetActiveLevelName( );
}

/**
 *  const char * CATGetActiveLevelFileName ();
 *  
 *  this service permits to know the Level File Name for this session
 *   
 */
extern "C"
{
 ExportedByJS0LIB const char * CATGetActiveLevelFileName( );
}



#endif
