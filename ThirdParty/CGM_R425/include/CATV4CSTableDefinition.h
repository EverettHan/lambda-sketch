/**
* @level Private 
* @usage U1
*/
/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//								   
// CATV4CSTableDefinition :
//  Definition of V4 Code Set structure.
//  Class for definition and management of table of V4 Code Sets.
//
//=============================================================================
//
// Considerations of usage:								   
//								   
//=============================================================================
//								   
// July 1998                                                      Creation LJH
//								   
//=============================================================================
#ifndef CATV4CSTableDefinition_H
#define CATV4CSTableDefinition_H

#include "CATAIXServices.h"

#include "CATV4CSCommon.h"
#include "CATV4CSStructDefinition.h"


class ExportedByCATAIXServices CATV4CSTableDefinition
{
public :
  //--------
  // Methods
  //--------

  //
  // The following methods return informations about V4 code set
  //

/**
 * Returns if a V4 code set is available from its number.
 * @param iV4CSNum
 *   Number of the V4 code set.
 * @returns 1 if V4 code set is active,
 *          0 otherwise.
 */
  static int IsAvailable( const int iV4CSNum );

/**
 * Retrieve the Name of a V4 code set from its number.
 * @param iV4CSNum
 *   Number of the V4 code set.
 * @returns the Name of the V4 code set if successfull,
 *          0 otherwise.
 */
  static const char * GetNameFromNum( const int iV4CSNum );

/**
 * Retrieve the type (SBCS/DBCS) of a V4 code set from its number.
 * @param iV4CSNum
 *   Number of the V4 code set.
 * @returns the type of the V4 code set if successfull,
 *          0 otherwise.
 */
  static int GetTypeFromNum( const int iV4CSNum );

/**
 * Retrieve the coding base (ASCII, EBCDIC,...) of a V4 code set from its number.
 * @param iV4CSNum
 *   Number of the V4 code set.
 * @returns the coding base of the V4 code set if successfull,
 *          0 otherwise.
 */
  static int GetBaseFromNum( const int iV4CSNum );

/**
 * Retrieve, if exists, the SBCS code set associated to a V4 code set from its number.
 * @param iV4CSNum
 *   Number of the V4 code set.
 * @returns the SBCS code set associated the V4 code set if successfull,
 *          0 otherwise.
 */
  static int GetSBCSFromNum( const int iV4CSNum );

/**
 * Retrieve the file associated to the V4 code set from its number.
 * @param iV4CSNum
 *   Number of the V4 code set.
 * @returns the name of the V4 code set if successfull,
 *          NULL otherwise.
 */
  static const char * GetFileFromNum( const int iV4CSNum );


private :
  CATV4CSTableDefinition();

/**
 * Static table of V4 code sets
 */
  static CATV4CSDefinitionStruct _CATV4CSTable[ MAX_NB_CS ];

};

#endif
