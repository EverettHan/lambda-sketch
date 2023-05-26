// COPYRIGHT DASSAULT SYSTEMES  1998
//=============================================================================
//
// CATICkeTextSheet.h:
//
//=============================================================================
// Usage Notes:
//
// See below
//
// 
//
//
//=============================================================================
// 08/06/98   Creation                                   T. Videcoq
//=============================================================================

/** 
* @CAA2Level L1
* @CAA2Usage U3 
*/

/*  CAA2Reviewed by FRH */

/**
 * This interface is an encapsulation of an array of arrays (a sheet) of strings contained in a file.
 *
 * The file has to be a tabulated text file. Its format has to be :
 * <table>
 * <tr><td>string<sub>1,1</sub></td><td>TAB</td><td>string<sub>1,2</sub></td><td>...</td></tr>
 * <tr><td colspan="3">(n-2 lines)</td></tr>
 * <tr><td>string<sub>n,1</sub></td><td>TAB</td><td>string<sub>n,2</sub></td><td>...</td></tr>
 * </table><br>
 * Empty strings are allowed, but not in the first row because the number of
 * columns is computed using the first row, except if you use the forceWidth
 * argument of the the @href CATICkeSheet#UpdateLocalCopy method.<br>
 *
 * To create a CATICkeTextSheet, use the @href CATICkeParmFactory#CreateSheet method
 * with a text file path as argument.
 * @see CATIDesignTable, CATICkeSheet
*/

#ifndef CATICkeTextSheet_H
#define CATICkeTextSheet_H

#include "KnowledgeItf.h"
#include "CATICkeSheet.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATICkeTextSheet;
#else
extern "C" const IID IID_CATICkeTextSheet;
#endif

class ExportedByKnowledgeItf CATICkeTextSheet : public CATICkeSheet
{
	CATDeclareInterface;
public:
	/**
	* This methods adds a row in the text file.
	* For vertical sheets, this method is much more effective than several calls to SetCell
	* @param row
	* the list of strings to add at the end of the file.
	* @param init
	* opens the file if equal to CATCke::True
	* @param save
	* saves the file if equal to CATCke::True
	* @return
	* CATCke::True if the operations succeeds, CATCke::False else
	*/
	virtual CATCke::Boolean AddRow(CATListOfCATUnicodeString &row, CATCke::Boolean init, CATCke::Boolean save) = 0;
};
CATDeclareHandler(CATICkeTextSheet,CATICkeSheet);

#endif
