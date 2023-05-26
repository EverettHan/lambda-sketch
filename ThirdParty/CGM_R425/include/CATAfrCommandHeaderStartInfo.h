// COPYRIGHT Dassault Systemes 2008

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#ifndef CATAfrCommandHeaderStartInfo_H
#define CATAfrCommandHeaderStartInfo_H

#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"
#include "CATAfrCommandHeaderArgs.h"
#include "CATString.h"

//-----------------------------------------------------------------------

/**
* Class containing informations to start a command.
*
* <br><b>Role</b>: An instance of this class contains a command header identifier and an argument list
* that may be used to start a command.
* <br>
* This is very useful for @href CATAfrCommandSequence class.
*/
class ExportedByCATAfrFoundation CATAfrCommandHeaderStartInfo: public CATBaseUnknown
{
  CATDeclareClass;

  public:

   /**
    * Constructs a command header start information. 
    */
    CATAfrCommandHeaderStartInfo ();

    virtual ~CATAfrCommandHeaderStartInfo ();

   /**
    * Constructs a command header start information from another one. 
    */
    CATAfrCommandHeaderStartInfo (const CATAfrCommandHeaderStartInfo &);
   /**
    * Enables equal operator between two ommand header start information instances. 
    */
    CATAfrCommandHeaderStartInfo& operator=(const CATAfrCommandHeaderStartInfo&);

    /**
     * Get the command header identifier.
     * @return 
     *  The identifier.
     */
    CATString & GetHeaderID ();

    /**
     * Set the command header identifier.
     * @param 
     *  The identifier.
     */
    void SetHeaderID (const CATString & iHeaderID);

    /**
     * Get the command header argument list.
     * @return 
     *  The argument list.
     */
    CATAfrCommandHeaderArgs & GetArgumentList ();

  private:

    CATString _HeaderID;
    CATAfrCommandHeaderArgs _ArgList;
};

//-----------------------------------------------------------------------

#endif
