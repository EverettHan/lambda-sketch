
/**
* @level Protected
* @usage U1
*/

// --------------------------------------------------------
////////////////////////////////////////////////////////////////////////////
//
// COPYRIGHT DASSAULT SYSTEMES  2003
//
// Creation J Delaye March.03                                            
//
/////////////////////////////////////////////////////////////////////////////
#ifndef CATV4Attributes_H
#define CATV4Attributes_H

#include "ExportedByCATV4Attributes.h"
#include "CATUnicodeString.h"

/**
 * Type of V4 attributes.
 * @param Character
 *  The V4 attributes is a character
 * @param Discret
 *  The V4 attributes is a discrete value
 * @param Real
 *  The V4 attributes is a real value
 * @param Boolean
 *  The V4 attributes is a boolean value
 * @param Integer
 *  The V4 attributes is an integer value
 */
enum AttributFormat { Character=0, Discret=1 ,Real=2, Boolean=3, Integer=4 } ;

/**
 * Class representing a V4 attribute.
 * <p>
 * <b>Role</b>: This class gives access to some informations of a V4 attributes
 */
class ExportedByCATV4Attributes CATV4Attributes
{
  public :
   CATV4Attributes();
   virtual ~CATV4Attributes() ;

    /**
     * Copy constructor</br>
     * @param
     *   The CATV4Attributes to copy
     */
   CATV4Attributes(const CATV4Attributes *);

    /**
     * name of the V4 attribute
     */
   CATUnicodeString  Name ;

    /**
     * value of the V4 attribute
     */
   CATUnicodeString  Value ;

    /**
     * type of the V4 attribute
     */
   AttributFormat      Format ;
 } ;

#endif
