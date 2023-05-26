/**
* @level Protected 
* @usage U1
*/
/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//								   
// CATV4CSInstance :
//  Class for conversion of texts from V4 code set to Unicode or V5 code set.
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
#ifndef CATV4CSInstance_H
#define CATV4CSInstance_H

#include "CATAIXServices.h"

#include "CATI18NTypes.h"


class CATUnicodeString;
class CATV4CSFile;

class ExportedByCATAIXServices CATV4CSInstance
{
public :
  //--------
  // Methods
  //--------

  // Conversion of a V4 text
/**
 * Converts the text from V4 code set to UNICODE.
 *
 * @param iV4CSFile
 *   File name associated to a V4 code set used to encode the text.
 * @param iV4Text
 *   Text to convert.
 * @param oCATUCSText
 *   CATUnicodeString representing the Unicode text.
 * @returns 1 if conversion succeeds and 0 otherwise.
 */
  static int ConvertV4TextToUnicodeText ( const char * iV4CSFile,
					  const char * iV4Text, 
					  CATUnicodeString& oCATUCSText );

/**
 * Converts the text from V4 code set to V5 code set.
 * The V4 text can contained of sub-texts separated 
 * by nul charaters.
 *
 * @param iV4CSNum
 *   Number of the V4 code set used to encode the text.
 * @param iV4Text
 *   The text to convert.
 * @param iV4Length
 *   Length of text to convert.
 * @param oV5Text
 *   The converted text.
 * @param iV5Length
 *   Desired Length of the converted text (IT IS AN INPUT).
 * @returns 1 if conversion succeeds and 0 otherwise.
 */
  static int ConvertV4TextToV5Text ( const int     iV4CSNum,
				     const char *  iV4Text,
				     int           iV4Length,
				     char       *& oV5Text,
				     int           iV5Length );

/**
 * Converts the text from V5 code set to V4 code set.
 *
 * @param iV4CSNum
 *   Number of the V4 code set used to encode the text.
 * @param iV5Text
 *   The text to convert.
 * @param iV5Length
 *   Length of text to convert.
 * @param oV4Text
 *   The converted text.
 * @param iV4Length
 *   Desired Length of the converted text (IT IS AN INPUT).
 * @returns 1 if conversion succeeds and 0 otherwise.
 */
  static int ConvertV5TextToV4Text ( const int     iV4CSNum,
				     const char *  iV5Text,
				     int           iV5Length,
				     char       *& oV4Text,
				     int           iV4Length );

private :
  CATV4CSInstance();

  static int  FindSOorSI   ( const char * iSrc, const int iSrcSize, int & ioPos );
  static int  V4CStoUCS2   ( const char * iSrc, const int iSrcSize, CATUC2Bytes *& oDest, int & oDestSize );
  static int  UCS2toV4CS   ( const CATUC2Bytes * iSrc, const int iSrcSize ,
			    char *& oDest, int & oDestSize, int & oDestType );

  static void ReallocUCS2  ( CATUC2Bytes *& ioUCString, int & ioOldSize );
  static void ReallocChar  ( char * &ioString, int & ioOldSize );
  static int  FindSubString( const char *& ioSrc, int & ioSrcSize, int & oInterval );
 
  static int              _TransTableRank;

  static unsigned short * _TransTable;
  static int              _TransTableSize;
  static unsigned char  * _TransTableInvers;
  static int              _TransTableInversSize;                 

  static int _V4CSSRCNByteMax;   // Nombre d'octets MAX par caracteres a considerer pour le CP SOURCE.
  static int _V4CSSRCBaseCoding; // Base de codage du Code Page concerne (CP SOURCE).

  static int _V4CSKeepKATAKANA;  // Indicateur pour savoir s'il faut ou non conserver
		                 // les KATAKANA SBCS Japonais (cf. CATCpSession).

  // Flags pour les conversions CPV4->UCS2.
  static int _ISO646Only;        // Indicateur pour dire si on ne conserve que les 
                                 // caracteres definis dans la plage ISO646.

  // Flags pour les conversions UCS2->CPV4.
  static int _NODBCS;            // Indicateur pour conserver ou non les caracteres DBCS.
};

#endif




