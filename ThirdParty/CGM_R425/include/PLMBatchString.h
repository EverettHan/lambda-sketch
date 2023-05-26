/** ******************************************************************************** **/
/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
/** ******************************************************************************** **/
#ifndef PLMBatchString_H
#define PLMBatchString_H

/** 
 *  @level Protected 
 *  @usage U1
 */
#include "ExportedByPLMBatchInfraServices.h"
#include "CATListOfCATUnicodeString.h"
#include "CATUnicodeString.h"

/**
 * Class to manipulate PLMBatch strings composed with a list of attributes name and a separator.
 * This list can be defined by end user while using the ObjectNamingCusto object.
*/

class ExportedByPLMBatchInfraServices PLMBatchString
{
public:
/**
 * Split a complexe string
 * <BR>Split the PLMBatch string saved in an XML file into the list of attributes and the separator character
 * @param icPattern
 * The string to split
 * @param ocSplited
 * The list of attributes
 * @param ocParator
 * The separator character
 * @return <UL>
 * <LI>E_FAIL when can not split the cPattern string (because empty string, or string with an invalid format)
 * </UL>
*/

static HRESULT SplitaString(CATUnicodeString & icPattern ,  CATUnicodeString & icParator, CATListOfCATUnicodeString & ocSplited );

/**
* Clean an XML string
* <BR>clean an XML string while removing all &lt;xx> tags 
* <BR>&lt;BR> and &lt;P> tags leads to new lines
* <BR>Remove duplicates lines in the string
* @param ilString
* The string to clean
* @param olString
* The resulting string
* @return <UL>
* <LI>the size of the resulting olString string
* </UL>
*/
static int CleanXMLString(CATListOfCATUnicodeString & ilString, CATListOfCATUnicodeString & olString);


/**
 * Split a complexe string
 * <BR>Split the PLMBatch string saved in an XML file into the list of attributes and the separator character
 * @param icPattern
 * The string to split
 * @param ocSplited
 * The list of attributes
 * @param ocParator
 * The separator character
 * @return <UL>
 * <LI>E_FAIL when can not split the cPattern string (because empty string, or string with an invalid format)
 * </UL>
*/

static HRESULT SplitComplexeString(CATUnicodeString & icPattern , CATListOfCATUnicodeString & ocSplited , CATUnicodeString & ocParator );

/**
 * Compute a complexe string
 * <BR>Compute the PLMBatch string according to selected attribute list and separator character
 * @param icAttr
 * The list of selected attributes for string computation
 * @param icParator
 * The separator character
 * @param ocPattern
 * The computed string 
*/
static void BuildComplexeString(CATListOfCATUnicodeString & icAttr , CATUnicodeString & icParator, CATUnicodeString & ocPattern);

/**
 * Retrieve the Separator of a complexe string
 * <BR>Retrieve the Separator string
 * @param icPattern
 * @param ocParator
 * The separator character
*/

static void GetComplexeStringSeparator(CATUnicodeString & icPattern, CATUnicodeString &ocSeparator  );

	
	/**
	* Unmarshall a string 
	*/
static HRESULT UnMarshallDbBinary(const char * stringToConvert, int length, unsigned char * weight);

	/**
	* Marshall a string 
	*/
static char * MarshallDbBinary( char * p, const unsigned char *data, short sz );

};
#endif
