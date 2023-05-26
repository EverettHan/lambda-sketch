// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATIDTSemanticSheet.h
// Define the CATIDTSemanticSheet interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jun 2007  Creation: Code generated by the CAA wizard  BUD
//===================================================================
#ifndef CATIDTSemanticSheet_H
#define CATIDTSemanticSheet_H

#include "KnowledgeItf.h"
#include "CATBaseUnknown.h"
#include "CATIDesignTable.h"
class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByKnowledgeItf IID IID_CATIDTSemanticSheet;
#else
extern "C" const IID IID_CATIDTSemanticSheet ;
#endif

//------------------------------------------------------------------

/**
* Interface representing xxx.
*
* <br><b>Role</b>: Components that implement
* CATIDTSemanticSheet are ...
* <p>
* Do not use the CATIDTSemanticSheet interface for such and such

*
* @example
*  // example is optional
*  CATIDTSemanticSheet* currentDisplay = NULL;
*  rc = window-&gt;QueryInterface(IID_CATIDTSemanticSheet,
*                                     (void**) &amp;currentDisplay);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByKnowledgeItf CATIDTSemanticSheet: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

 	/**
	* Retrieves a string containing cell string + column unit extension.
	* if the cell string don't have an type extension and the column has one
	* @param iRow
	* index of the row of the cell
	* @param iColumn
	* index of the column of the cell
	* @param oCellWithColumnType
	* string containing cell string + column unit extension.
	* @return
	* - S_OK if the cell is valuated
	* - E_FAIL otherwise.
	*/
	virtual HRESULT CellWithColumnType(const int iRow, const int iColumn, CATUnicodeString & oCellWithColumnType) const = 0;


	/**
	* Retieves a double containing cell value converted in MKS.
	* If cell isn't numerical, returns 0
	* @param iRow
	* index of the row of the cell
	* @param iColumn
	* index of the column of the cell
	* @param oCellAsDouble
	* Double containing cell value converted in MKS
	* @return
	* - S_OK if the cell is numerical
	* - S_FALSE if the cell is not numerical but is valuated
	* - E_FAIL otherwise.
	*/
	virtual HRESULT CellAsDouble(const int iRow, const int iColumn, double & oCellAsDouble) const = 0;


	/**
    * Indicates if the column is numerical or not.<br>
	* @param iColumn
	* the index of the column
    * @param oIsANumericalColumn
	* boolean saying if the column is numerical or not.
    * (numerical means that all rows except the first one contains numerical
	* values optionnaly with unit extension)
	* @return
	* - S_OK if the column exists
	* - E_FAIL otherwise.
	*/
	virtual HRESULT IsANumericalColumn(const int iColumn, CATBoolean & oIsANumericalColumn) const = 0;


	/**
	* Retrieves the list of column names in the sheet
	* @param oColumnNames
	* List of column names in the sheet
	* @return
	* - S_OK if the column have been named
	* - E_FAIL otherwise.
	*/
	virtual HRESULT ColumnNames(const CATListOfCATUnicodeString *& oColumnNames) const = 0;


	/**
	* Updates column names
	* @param oColumnNames
	* - CATColumnNamesNotUnique if two columns have the same name
	* - CATIDesignTable::CATNoError otherwise.
	* @param oProblematicalColumnName
	* Name of the problematical column name (name used for several columns)
	* @return
	* - S_OK if the column names are corrects
	* - E_FAIL otherwise.
	*/
	virtual HRESULT UpdateColumnNames(CATIDesignTable::DTError & oDTError, 
		CATUnicodeString & oProblematicalColumnName) = 0;


	/**
	* Retrieves the list of unit extensions names in the sheet
	* @param oUnitExtensions
	* List of unit extensions in the sheet
	* @return
	* - S_OK if the column have been named and have units
	* - E_FAIL otherwise.
	*/
	virtual HRESULT UnitExtensions(const CATListOfCATUnicodeString *& oUnitExtensions) const = 0;

	/**
	* Looks for the most adapted type for the column.
	* @param iColumn
	* The column whose type is to search.
	* @param ospType
	* The most adapted type for the column. StringType if no other type is found.
	* @return
	* - S_OK if argument iColumn and context is good
	* - E_FAIL otherwise.
	*/
	virtual HRESULT ColumnSupposedType(const int iColumn, CATICkeType_var & ospType) = 0;
};
CATDeclareHandler(CATIDTSemanticSheet,CATBaseUnknown);

//------------------------------------------------------------------

#endif