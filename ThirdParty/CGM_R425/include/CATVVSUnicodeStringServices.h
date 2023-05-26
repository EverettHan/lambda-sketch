/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2004
//=============================================================================
#ifndef CATVVSUnicodeStringServices_H
#define CATVVSUnicodeStringServices_H

#include "VVSUtils.h"
#include "CATUnicodeString.h"

/**
 * Class supplying enhanced services on CATUnicodeString
 * <b>Role</b>: Purpose of this class is to supply 
 * Services that not supported by the CATUnicodeString class
 * for example StartsWith
 * This class is private to the VirtualVaultSystem
 */
class ExportedByVVSUtils CATVVSUnicodeStringServices
{
  public:
    

    /**
	 * Tells if a string is beginning by another string
	 * @param iWhereToLook
	 * The CATUnicodeString where we are looking to know if it is beginning by another CATUnicodeString
	 * @param iLookStartString
	 * The CATUnicodeString we are looking for in the iWhereToLook
	 * @return 
	 * TRUE if the iWhereToLook starts with iLookStartString , FALSE in other cases
	 */
    static CATBoolean CATUnicodeString_StartsWith(const CATUnicodeString&  iWhereToLook,const CATUnicodeString& iLookStartString) ;

    /**
	 * Tells if a string is ending by another string
	 * @param iWhereToLook
	 * The CATUnicodeString where we are looking to know if it is ending by another CATUnicodeString
	 * @param iLookEndString
	 * The CATUnicodeString we are looking for in the iWhereToLook
	 * @return 
	 * TRUE if the iWhereToLook ends with iLookEndString , FALSE in other cases
 	 */
    static CATBoolean CATUnicodeString_EndsWith(const CATUnicodeString&  iWhereToLook,const CATUnicodeString& iLookEndString) ;

    /**
	 * Tells if we can find a  string beginning at a position in another string
	 * @param iWhereToLook
	 * The CATUnicodeString where we are looking 
	 * @param iLookString
	 * The CATUnicodeString we are looking at the position...
	 * @param iPos
	 * The Position where the iLookstring has to start
	 * @return
	 * TRUE if the iLookString has been found at the pos iPos in the String iWhereToLook, FALSE in other cases
	 */
    static CATBoolean CATUnicodeString_IsStringAt(const CATUnicodeString&  iWhereToLook,const CATUnicodeString& iLookString,int iPos) ;

    /**
	 * Extracts a substring from a string knowing the begin of the substring and the end of the substring
	 * @param iWhereToLook
	 * The CATUnicodeString from which we will extract the substring
	 * @param iBegin
	 * The begin of the substring
	 * @param iEnd
	 * The end of the substring
	 * @param oResultingString
	 * The substring
	 * The iBegin and iEnd are excluded of the resulting string
	 * @return
	 * S_OK if we have found the ResultingString , E_FAIL in other cases
	 */
    static HRESULT CATUnicodeString_ExtractString(const CATUnicodeString&  iWhereToLook,const CATUnicodeString&  iBegin,const CATUnicodeString& iEnd,CATUnicodeString& oResultingString) ;

    /**
	 * Extracts a substring from a string beginning at the begin of the string and finishing where we find the iEnd string
	 * @param iWhereToLook
	 * The CATUnicodeString from which we will extract the substring
	 * @param iEnd
	 * The end of the substring
	 * @param oResultingString
	 * The substring
	 * The iEnd string is excluded of the resulting string
	 * @return
	 * S_OK if we have found the ResultingString , E_FAIL in other cases
	 */
    static HRESULT CATUnicodeString_ExtractString(const CATUnicodeString&  iWhereToLook,const CATUnicodeString& iEnd,CATUnicodeString& oResultingString) ;

};

#endif


