#ifndef DSYSysScrambling_H
#define DSYSysScrambling_H

#include "CATUnicodeString.h"
/**
   Scrambling and unscrambling operations **/

class DSYSysScrambling{

public:

  /** DO NOT USE **/ /** SOON REMOVAL **/
  virtual HRESULT Scramble( unsigned char *ioBuffer, unsigned int iLenBuffer,  unsigned int iKey ) = 0;
  /** DO NOT USE **/ /** SOON REMOVAL **/
  virtual HRESULT Unscramble( unsigned char *ioBuffer, unsigned int iLenBuffer, unsigned int iKey ) = 0;
  /** DO NOT USE **/ /** SOON REMOVAL **/
  virtual void GetNewKey ( unsigned int &oKey)= 0;
		
  /**
   *  Returns the scrambling Version
   */
  virtual void GetVersion ( unsigned int &oVersion )= 0; 

  /**
   * Returns a new key that can be used to scramble or unscramble.
   */
  virtual HRESULT GetNewKey ( CATUnicodeString &oNewKey)= 0;

  /**
   * Set the default key used by the scrambling operator to scramble or unscramble data
   * 
   */
  virtual HRESULT SetDefaultKey ( CATUnicodeString &iKey)= 0;	

  /**
   *  Scrambles the given array of char. 
   *  ioBuffer   : The data to scramble. The result of the scrambling operation is written in ioBuffer.
   *  iLenBuffer : The number of char from the given array to scramble 
   *  iKey : The scrambling key 
   *         If a null pointer is passed, the default key (set by the method SetDefaultKey) is used
   *         If a null pointer is passed and the method SetKey has not been called, this method returns E_FAIL
   */
  virtual HRESULT Scramble( unsigned char *ioBuffer, unsigned int iLenBuffer, CATUnicodeString * iKey=0 ) = 0;

  /**
   *  Unscrambles the given array of char. 
   *  ioBuffer   : The data to unscramble. The result of the unscrambling operation is written in ioBuffer.
   *  iLenBuffer : The number of char from the given array to unscramble 
   *  iKey : The scrambling key 
   *         If a null pointer is passed, the default key (set by the method SetDefaultKey) is used
   *         If a null pointer is passed and the method SetKey has not been called, this method returns E_FAIL
   */
  virtual HRESULT Unscramble( unsigned char *ioBuffer, unsigned int iLenBuffer, CATUnicodeString * iKey=0 ) = 0;

};
#endif   // DSYSysScrambling_H

