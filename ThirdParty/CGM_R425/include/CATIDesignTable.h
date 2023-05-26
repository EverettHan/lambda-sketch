#ifndef CATIDesignTable_H
#define CATIDesignTable_H

// COPYRIGHT DASSAULT SYSTEMES  1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3 
 */

/*  CAA2Reviewed by FRH */


#include "KnowledgeItf.h"

#include "CATICkeRelationForwards.h"

#include "CATICkeParm.h"

class CATIParmPublisher_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATIDesignTable;
#else
extern "C" const IID IID_CATIDesignTable;
#endif

/**   
 * Interface dedicated to design table management.
 * <b>Role</b>: It allows to drive parameters of CATIA Model with values taken from an Excel sheet or from a tabulated text file<br>
 * A design table is a relation, thus it also implements CATICkeRelation.<br>
 * The principle of use of this interface is the following:<br>
 * <ol>
 * Creation of a sheet (<pre>factory->CreateSheet()</pre>)
 * Creation of a design table (<pre>factory->CreateDesignTable()</pre>)
 * Attachment of the sheet in the design table (<pre>design->SetSheet(sheet)</pre>)
 * Creation of associations between columns of the sheet and parameters of the model (<pre>design->AddAssociation("column", parameter)</pre>)
 * Choice of a row as configuration of the design table (<pre>design->SetConfigurationRow(n)</pre>)
 * </ol>
 *
 * This interface is mono implemented.
 * @see CATICkeRelation
*/
class ExportedByKnowledgeItf CATIDesignTable : public CATBaseUnknown
{
	CATDeclareInterface;

public:

    /**
     * Errors produced by Design table.
	 * @param NoError is returned by methods if no error occured.
	 * @param NotAMagnitude is returned by @href #AddAssociation or @href #ManageSheetModifications if given parameter has no magnitude and if the associated column has one in column title.
	 * @param BadCellType is returned by @href #AddAssociation or @href #ManageSheetModifications if the type of one of the cell of the column isn't compliant with associated parameter.
	 * @param BadColumnType is returned if the unit extension in column use a unit that doesn't exist.
	 * @param BadConfiguration is returned by @href #SetCurrentConfiguration is the given integer in less than 0 and greater than the number of configurations in the sheet.
	 * @param ParseSheetError is returned by @href #ManageSheetModifications when the parse operation of the sheet failed.
	 * @param ParameterAlreadyAssociated is returned by @href #AddAssociation or @href #ManageSheetModifications if the given parameter is already associated.
	 * @param ColumnAlreadyAssociated is returned by @href #AddAssociation or @href #ManageSheetModifications if the given column is already associated.
	 * @param ColumnDoesntExist is returned by @href #AddAssociation or @href #ManageSheetModifications if the given column doesn't exist.
	 * @param MiscellaneousError is returned by methods when other errors are encountered.
     */
  	enum DTError 
	{
		NoError,
		ColumnNamesNotUnique,
		BadCellType,
		BadColumnType,
		NotAMagnitude,
		BadConfiguration,
		ParseSheetError,
		ParameterAlreadyAssociated,
		ColumnAlreadyAssociated,
		ColumnDoesntExist,
		MiscellaneousError
	};

	/**
	* Returns the configuration parameter.
	*/
	virtual CATICkeParm_var ConfigurationParameter() = 0;

	/**
	* Modifies the configuration parameter (and by consequence all others) to the value of the row rowNb (rowNb has to be > 1).
	* @return  NoError if the configuration row is valid, otherwise BadConfiguration.
	* @param iRowNb
	* the row choosen as configuration (has to be > 1 and <= to the number of rows in the design table, the column names row excluded)
	*/
	virtual CATIDesignTable::DTError SetCurrentConfiguration(const int iRowNb) = 0;

	/**
	* Returns the configuration row index.
	*/
	virtual int ConfigurationRow() const = 0;

	/**
	* Gets the list of associations between columns of the sheet defining the design table and the parameters driven by those columns. <br>
	* The first string is associated with the first out-parameter, and so on
	* @return the list of associations
	*/
	virtual const CATListOfCATUnicodeString* Associations() const = 0;

	/**
	* Adds an association between the column of name iColumnName and the parameter iParameter.
	* @return CATNoError if the method succeeds. If the method fails, it can return CATColumnAlreadyAssociated if the column is already associated, 
	* CATParameterAlreadyAssociated if the parameter is already associated, CATColumnDoesntExist if the column doesn't exist, CATNotAMagnitude if the 
	* parameter isn't typed and the column has a unit extension, CATBadCellType if a cell of the sheet doesn't fit parameter's type and CATBadColumnType 
	* if a cell of the sheet doesn't fit parameter's type
	* @param iColumnName
	* the name of the column (without the column's type if there is one)
	* @param iParameter
	* the parameter to be associated
	*/
	virtual CATIDesignTable::DTError AddAssociation(const CATUnicodeString& iColumnName,
												const CATICkeParm_var &iParameter) = 0;

   /**
	* Removes the association with column iColumnName.
	* @return CATCke::True if the method succeeds, CATCke::False else
	* @param iColumnName
	* The name of the column in the association
	*/
	virtual CATCke::Boolean RemoveAssociation(const CATUnicodeString& iColumnName) = 0;

   /**
	* Returns the associated sheet.
	*/
	virtual const CATICkeSheet_var Sheet() const = 0;

   /**
	* Sets the associated sheet.
	* @param sheet
	* the sheet defining the content of the design table
	*/
	virtual void SetSheet(const CATICkeSheet_var &sheet) = 0;

   /**
	* Returns the list of column names in the sheet.
	*/
	virtual const CATListOfCATUnicodeString* ColumnNames() const = 0;

	/**
	* Gets the index (1-based) of the column associated with the parameter.
	* @return 0 if the column isn't associated (or doesn't exist)
	* @param iParameter
	* the parameter
	*/
	virtual int ParameterColumn(const CATICkeParm_var &iParameter) = 0;

	/**
	* Gets the parameter associated with the column whose index is columnNb or whose name is iColumnName.
	* @return NULL_var if the column doesn't exist or isn't associated
	* @param iColumnNb
	* the index of the column. If it is equal to 0, this method uses the second argument
	* @param iColumnName
	* a pointer on the name of the column (can be NULL if columnNb <> 0
	*/
	virtual CATICkeParm_var ColumnParameter(int iColumnNb, CATUnicodeString *iColumnName = NULL ) = 0;
	
	/**
	* Returns a string containing cell string + column unit extension.
	* if the cell string don't have an type extension and the column has one
	* @param iRow
	* index of the row of the cell
	* @param iColumn
	* index of the column of the cell
	* @return string computed
	*/
	virtual CATUnicodeString CellWithColumnType(const int iRow, const int iColumn) const = 0;

	/**
	* Returns a double containing cell value converted in MKS.
	* If cell isn't numerical, returns 0
	* @param iRow
	* index of the row of the cell
	* @param iColumn
	* index of the column of the cell
	* @return double value computed
	*/
	virtual double CellAsDouble(const int iRow, const int iColumn) const = 0;

	/**
    * Indicates if the column is numerical or not.<br>
    * @return a boolean saying if the column is numerical or not.
    * (numerical means that all rows except the first one contains numerical
	* values optionnaly with unit extension)
	* @param iColumn
	* the index of the column
	*/
	virtual CATCke::Boolean IsANumericalColumn(const int iColumn) const = 0;

	/**
	* Called when a subscriber receives modification notification.
	* from the sheet imbed in the design table.
	* It parses the new sheet, updates column names, update associations
	* @return CATParseSheetError if the sheet could'nt be parsed, CATColumnNamesNotUnique if two or more columns have the same name, CATNoError else
	* @param iInteractively
	* informs if the caller wants messages and questions, or default operations
	*/
	virtual CATIDesignTable::DTError ManageSheetModifications(const CATCke::Boolean iInteractively = 0) = 0;

	/**
	* Looks for the most adapted type for the column.
	* @return StringType if no other type is found.<br>
	* Returns NULL_var if argument column isn't good
	* @param iColumn
	* the column whose type is to search
	*/
	virtual CATICkeType_var ColumnSupposedType(const int iColumn) = 0;

	/**
	* Checks that no relations are in conflict with the design table (this mean, no relations valuate the parameters associated to the design table).
	* @return False if the design table has to be not activated
	* @param iWithMessage
	* This boolean says if the method has to send a question about removing association or deactivating conflicting relations to screen, or to take default actions (not to activate the design table)
	*/
	virtual CATCke::Boolean ManageRelationsConflicts(const CATCke::Boolean iWithMessage) = 0;

	/**
	* Adds a new row in the sheet with current values of associated parameters.
	* ##### Since V5R14 ##### 
	* If the file contains at least one empty row between two not empty rows,
	* the behavior of this method is the same for Excel and Text files :
	* => the new row containing the current parameters values replaces the first
	*    empty row found from the beginning of the file.
	* RQ : before R14, for text files, the new row was appended at the end of the file.
	*      The empty rows were never filed by this way, so that the new row was not
	*      visible in Design Table dialog.
	* ######################
	* @param withUpdate
	* if == 0, don't call the sheet update (that reads the file) -> for optimization purpose
	* @return CATCke::True if the method succeeds, CATCke::False else
	*/
	virtual CATCke::Boolean AddRowWithParmValues(const int withUpdate = 1) = 0;

	/**
	* Checks that the design table doesn't generate cycles.
	* @return CATCke::True if the activation of the design table doesn't generate cycles,
	* CATCke::False else
	* @param iWithMessage
	* Set this parameter to True if you want a message saying there is a cycle
	*/
	virtual CATCke::Boolean ManageCycles(const CATCke::Boolean iWithMessage) const = 0;

	/**
	* Tries to associate automatically parameters and columns of same name.
	* @param iRoot
	* the root from which the naming has to begin
	* @param iFeature
	* if not NULL, the feature where parameters are searched. 
	* @param iParameters
	* if first argument is NULL, use this list of parameters to
	* look for potential associations
	* @return the number of associations created
	*/
	virtual int AutomaticAssociations(const CATIParmPublisher_var &iRoot, const CATIParmPublisher_var &iFeature, const CATLISTV(CATBaseUnknown_var) *iParameters) = 0;

	/**
	* Activates the callback reacting to the source file modification. When this callback is raised.
	* the design table is synchronized. If source data is copied into model, the synchronization
	* is optionnal
	* @param iMode
	* 0 : Message and update if the design table data isn't embedded, Question and eventually update
	* if the design table data is embedded<p>
	* 1 : Update
	* 2 : No update
	*/
	virtual void ActivateSheetUpdateMessage(int iMode = 0) = 0;

	/**
	* Deactivates the callback reacting to the source file modification.
	*/
	virtual void DeactivateSheetUpdateMessage() = 0;


	/**
	* Allows to retrieve the configurations that are not valid according to design table filter.
	* <br><b>Role</b>: returns the list of invalid configurations according to design table filter
	* @param iForceUpdate
	* says if this list has to be updated (if value is not 0) or not. 0 is advised.
	* @return
	* the list of invalid configurations. This list is index 1-based : the first configuration has index 1. 
	*/
	virtual const CATListOfInt * GetInvalidConfigurations(const int iForceUpdate = 0) = 0;

	/**
	* This method allows to retrieve the expression that filters design table configurations.
	* <br><b>Role</b>: returns the design table configurations filter
	* @return
	* the relation used to filter the available configurations.<br>
	* It is a "check" involving associated parameters. For a given configuration, 
	* if its result is False, the configuration is invalid.
	*/
	virtual CATICkeRelationExp_var GetConfigurationsFilter() = 0;

	/**
	* This method allows to specify the expression that allows to filter design table configurations.
	* This filter has to be a KnowledgeAdvisor check. If check result is False for a given configuration, the configuration is not valid.
	* <br><b>Role</b>: Allows the caller to set the configurations filter
	* @param filter the relation that will be used to filter the available configurations.<br>
	* It has to be a "check" involving associated parameters. For a given configuration, 
	* if its result is False, the configuration is invalid.
	*/
	virtual void SetConfigurationsFilter(const CATICkeRelationExp_var &filter) = 0;


	/**
	* This methods checks if the parameter is seen as read only (cell not empty, or containing ranges or default value) for the current configuration.
	* @param parm parameter to check.
	* @return result of the test
	*/
	virtual int IsParamReadOnly(const CATICkeParm_var &parm) = 0;

	/**
	* This methods returns the icon mask depending on status of design table (synchronize, broken, etc....
	* @return icon mask name
	*/
	virtual const char *GetIconMaskName() const = 0;



};
CATDeclareHandler(CATIDesignTable,CATBaseUnknown);

#endif
