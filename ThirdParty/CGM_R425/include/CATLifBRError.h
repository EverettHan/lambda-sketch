#ifndef CATLifBRError_H
#define CATLifBRError_H

#include "CATLifBRules.h"
#include "CATLifError.h"
#include "CATIKweErrorManager.h"
#include "CATListPV.h"
#include "CATCkeAttributeValuationFailing.h"
#include "CATListValCATCkeAttributeValuationFailing.h"
#include "CATListOfCATUnicodeString.h"

//------------------------------------------------------------
// Classe regroupant les differentes erreurs qui peuvent
// survenir lors de l'execution d'un service de CATIBRExecutionServices
//------------------------------------------------------------
class ExportedByCATLifBRules CATLifBRError : public CATLifError
{
	CATUnicodeString _opening_id;
	CATListPV _simple_errors;

	void clean();

public:
	//------------------------------------------------------------
	// Classe decrivant une erreur de base (file/parse/eval)
	//------------------------------------------------------------
	class ExportedByCATLifBRules CATLifBRError_Simple {
		CATCkeAttributeValuationFailing *_pValuationFailing;
		CATUnicodeString _typename;
		int _error_type;
		CATUnicodeString _catrule_filename;
		CATUnicodeString _message;
		int _line_number;
		CATIKweErrorManager::Severity _severity;
		CATListValCATUnicodeString _conflicting_catrule_names;

	public:
		CATLifBRError_Simple(const CATUnicodeString& iTypeName,
			int iErrorType /* 0 : script not found or not readable, 1 : parse error, 2 : eval error, 3 : conflict between scripts */,
			const CATUnicodeString& iRuleFileName,
			const CATUnicodeString& iMessage,
			int iLineNumber,
			CATIKweErrorManager::Severity iSeverity,
			CATCkeAttributeValuationFailing *pValuationFailing=NULL);

		/* getErrorType() ==  3 : conflict between scripts */
		CATLifBRError_Simple(const CATUnicodeString& iTypeName,
			const CATListValCATUnicodeString& iRuleFileNames,
			const CATUnicodeString& iMessage,
			CATIKweErrorManager::Severity iSeverity);

		CATLifBRError_Simple(const CATLifBRError_Simple& iTypeName);
		virtual ~CATLifBRError_Simple();
	
		const CATUnicodeString&	getTypeName() const						{ return _typename; };
		int						getErrorType() const					{ return _error_type; };
		const CATUnicodeString&	getRuleFileName() const					{ return _catrule_filename; };
		const CATUnicodeString&	getMessage() const						{ return _message; };
		int						getLineNumber() const					{ return _line_number; };
		CATIKweErrorManager::Severity getSeverity() const				{ return _severity; };
		CATCkeAttributeValuationFailing *getValuationFailing() const	{ return _pValuationFailing; };
		const CATListValCATUnicodeString& getConflictingRules() const	{ return _conflicting_catrule_names; };

		CATUnicodeString strDump() const;
	};

protected:
	// A faire en debut d'execution : fait une nettoyage
	void setOpenindId(const CATUnicodeString&);
	friend class CATBRuleImplementation;

public:
	CATLifBRError(const CATLifBRError&);
	CATLifBRError(const CATUnicodeString& iOpeningID);
	virtual ~CATLifBRError();

	void addSimpleError(CATLifBRError::CATLifBRError_Simple*);
	int getNbErrors() const;
	const CATLifBRError::CATLifBRError_Simple * const getError(int iPos) const;

	virtual CATKWEError* Clone() const;

	/**
	* This method returns a list of information about failing of attribute modification during the execution of the Business rule.<br>
	* It is used to treat the information afterwards if necessary.<br>
	*/
	HRESULT GetAttributeValuationFalingInformation (CATLISTV(CATCkeAttributeValuationFailing) &oList) ;
};

#endif
