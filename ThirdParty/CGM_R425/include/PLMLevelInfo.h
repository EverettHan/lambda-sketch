#ifndef _PLMLevelInfo_h
#define _PLMLevelInfo_h

/**
* @level Protected
* @usage U3
*/

#include "CATPLMLevelInfo.h"
#include "IUnknown.h"
#include "CATSysTSDataType.h"

/**
* Class to deal with official PLM levels between client and server.
* Note : Used to lower client behavior if server is from an older version.
*/
class ExportedByCATPLMLevelInfo PLMLevelInfo 
{
friend class CATPLMCompConnectionInstance;
friend class CATPLMREMarshallingServices;

public:
  /**
  * Get current client PLMLevelInfo.
  * @param oClientLevelInfo
  *   The official level of the client (regardless of any connected server).
	*/
	static PLMLevelInfo GetClientLevelInfo();

  /**
  * Get a PLMLevelInfo invalid.
  * Note : Will be used as an input/output for other methods to retreive a correct PLMLevelInfo.
	*/
	static PLMLevelInfo GetInvalidLevelInfo();

  /**
  * Returns the major release value.
  * Note : Returns 0 if PLMLevelInfo is invalid.
  */
  int getMajorReleaseLevel() const;

  /**
  * Returns the minor release value.
  * Note : Returns 0 if PLMLevelInfo is invalid.
  */
  int getMinorReleaseLevel() const;

	/**
	 * This method compares the two release levels.
   * Note : X.x (this object) and Y.y (otherLevelInfo)
   * @param otherLevelInfo
   *  The level to compare
   * @param oCmpResult
   *   Let's take an example of MLC major and minor releases
   *    -----------------------------------------------------------------------------------> time
   *           1        2        3           4          5         6           7        8                           
   *          Maj      Min      Min         Min        Maj       Min         Maj      Maj
   * 
   *   Valid list of X.x is (and only these) : 1.1 / 1.2 / 1.3 / 1.4 / 5.5 / 5.6 / 7.7 / 8.8
   *   A part of invalid X.x are : 1.5 / 5.4 / 2.3 / 7.8 / etc...
   * 
   *  The resulting comparaison if comparaison is possible
   *    oCmpResult = -3 :  All invalid or incompatible comparisons (will return E_FAIL)
   *    oCmpResult = -2 :  X < Y and x<Y (the major Release level is smaller then the one in otherLevelInfo and LevelInfo are not overlapping)
   *    oCmpResult = -1 :  X == Y and x < y (the major Release levels are equal but the minor release level is smaller than the one in otherLevelInfo)
   *    oCmpResult = 0  :  X == Y and x == y (the two release levels are equal)
   *    oCmpResult = 1 	:	 X == Y and x > y (the major Release levels are equal but the minor release level is greater than the one in otherLevelInfo)
   *    oCmpResult = 2  :  X > Y (the major Release level is greater then the one in otherLevelInfo)
   *  
   * @result
   *   S_OK   : The level info can be compared
   *   E_FAIL : The level info can not be compared ( X<Y but x>=Y  or Y<X but y>=X ).
   *            One Level Info is invalid (if major release > minor release).
	*/
	HRESULT Compare(const PLMLevelInfo & otherLevelInfo,int & result) const;

private:
  // majorReleaseLevel must be lower or egal than minorReleaseLevel
  PLMLevelInfo(int majorReleaseLevel,int minorReleaseLevel);
	int _minorReleaseLevel;
	int _majorReleaseLevel;
	int _ValidLevelInfo;
};


#endif

