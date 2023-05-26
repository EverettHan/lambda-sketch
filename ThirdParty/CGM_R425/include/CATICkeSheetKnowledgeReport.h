// COPYRIGHT DASSAULT SYSTEMES  1998
//=============================================================================
//
// CATICkeSheetKnowledgeReport.h:
//
//=============================================================================
// Usage Notes:
//
// Header of interface of sheet object.
//
// 
//
//
//=============================================================================
// 08/06/98   Creation                                   T. Videcoq
//=============================================================================

/*  CAA2Reviewed by FRH */

/**
 * This interface is an encapsulation of an array of arrays (a sheet) of strings contained in a file.
 *
 * This file can be an excel sheet, or a tabulated text file.The format of the text file
 * has to be :
 * <table>
 * <tr><td>string<sub>1,1</sub></td><td>TAB</td><td>string<sub>1,2</sub></td><td>...</td></tr>
 * <tr><td colspan="3">(n-2 lines)</td></tr>
 * <tr><td>string<sub>n,1</sub></td><td>TAB</td><td>string<sub>n,2</sub></td><td>...</td></tr>
 * </table><br>
 * Empty strings are allowed, but not in the first row because the number of columns is computed using the first row.
 * For design table use, the file is parsed until its end or until the first empty row is found.
 * If you use sheets of format Excel , be careful not to leave Excel process resident in memory (take care of SetCell arguments).
 * <br>
 * A sheet feature has a link to a file. This link has a direction, and this direction is impacting the way links between files (CATIA model and external file)
 * are shown in Impact Graph in LCA.
 * @see CATIDesignTable, CATICkeRelationFactory
*/

#ifndef CATICkeSheetKnowledgeReport_H
#define CATICkeSheetKnowledgeReport_H

#include "KnowledgeItf.h"
#include "CATICkeSheet.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATICkeSheetKnowledgeReport;
#else
extern "C" const IID IID_CATICkeSheetKnowledgeReport;
#endif



class ExportedByKnowledgeItf CATICkeSheetKnowledgeReport : public CATICkeSheet
{
	CATDeclareInterface;

public:

	/**
	* Sets the content of the cell (r,c) in the sheet and saves the sheet if lastCell = True.
	* WARNING : for text files, this method has strong performance problems. Use CATICkeSheetKnowledgeReport::AddRow instead of SetCell to fix them
	* @param r (1-based index)
	* row parameter
	* @param c (1-based index)
	* column parameter
	* @param s
	* cell content 
	* @param firstCell
	* this flag has to be set to True if the SetCell function is called for the first time since UpdateLocalCopy method was called
	* @param lastCell
	* this flag  has to be set to True if the SetCell function is called for the last time until UpdateLocalCopy method is called
	* @return  CATCke::True if the function succeded, CATCke::False else<br>
	*/
	virtual CATCke::Boolean SetCell(const int r, const int c, const CATUnicodeString& s, const CATUnicodeString& type, CATCke::Boolean firstCell=1, CATCke::Boolean lastCell=1) = 0;

};
CATDeclareHandler(CATICkeSheetKnowledgeReport,CATBaseUnknown);

#endif
