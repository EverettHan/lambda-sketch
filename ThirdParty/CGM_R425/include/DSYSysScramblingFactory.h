#ifndef DSYSysScramblingFactory_H
#define DSYSysScramblingFactory_H

#include "DSYSysScramble.h"
#include "DSYSysScrambling.h"

/*
  The scrambling factory. 
  This class must be used in order to get an instance of a scrambling object. 
*/

class ExportedByDSYSysScramble DSYSysScramblingFactory {

  public: 

  /**
   * Creates a scrambling object.
   *   Param oScrambler
   *     After the call, this parameter contains the created scrambling object in case of success or NULL in case of failure
   *   Param iExpectedVersion
   *     The expected version number for the scrambling algorithm. 
   *     If this number is higher than the max version number, the method returns E_FAIL
   *     The default value of this parameter corresponds to the first algorithm version.
   *   Return
   *     S_OK if the scrambling object has been created, E_FAIL otherwise
   */
   static HRESULT GetInstance( DSYSysScrambling **oScrambler , unsigned int iExpectedVersion = 1);

   /**
    * Returns the number of the higher version of scrambling algorithm that factory can create.
	* All Scrambling objects of algorithm version between 1 and oMaxVersionNumber can be created by this factory using
	* the method GetInstance.
	**/
   static HRESULT GetMaxVersionNumber ( unsigned int &oMaxVersionNumber ); 

   /** DO NOT USE **/ /** SOON REMOVAL **/
   static HRESULT Get( unsigned int iVersion, DSYSysScrambling **oObj );
   /** DO NOT USE **/ /** SOON REMOVAL **/
   static HRESULT GetCurrentVersion ( unsigned int &oCurrentVersion );
   /** DO NOT USE **/ /** SOON REMOVAL **/
   static HRESULT GetNegociatedVersion ( const CATUnicodeString &iServerVersion , CATUnicodeString &oScrNegociatedVersion );  
};
#endif   

