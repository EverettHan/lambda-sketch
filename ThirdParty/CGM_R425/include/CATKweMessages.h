/**
 * @level Protected
 * @usage U1
 */

// Copyright Dassault Systemes 2000

// SOC - oct 2001 : ajout de CATAskConfirmation()

#ifndef __CATKweMessages__
#define __CATKweMessages__

#include "CATMsgCatalog.h"
#include "CATLifDictionary.h"

#define AnswerOK 1
#define AnswerCancel 2
#define AnswerYes 3
#define AnswerNo 4
#define AnswerRetry 5
#define AnswerAbort 6
#define AnswerIgnore 7

/* Gets a nls string indexed by string argument in the nls file given as an argument
* @return the computed string or an empty one if it is not found or if the catalog doesn't exist
* @param catalog
* name of the nls catalog
* @param string
* name of the index of the string to be searched
* @param arguments
* array of CATUnicodeString that are used as nls string argument
*/
ExportedByCATLifDictionary CATUnicodeString CATGetNlsString(const  char* catalog, const char* string, CATUnicodeString arguments[] = NULL);

ExportedByCATLifDictionary int CATShowWarning(const CATUnicodeString &message, const CATUnicodeString &title, const char* name = "Warning");
ExportedByCATLifDictionary int CATShowInformation(const CATUnicodeString &message, const CATUnicodeString &title, const char* name = "Info");
ExportedByCATLifDictionary int CATShowError(const CATUnicodeString &message, const CATUnicodeString &title, const char* name = "Error");
ExportedByCATLifDictionary int CATAskQuestion(const CATUnicodeString &message, const CATUnicodeString &title, const char* name = "Question");
ExportedByCATLifDictionary int CATAskQuestionWithCancel(const CATUnicodeString &message, const CATUnicodeString &title, const char* name = "QuestionCancel");


ExportedByCATLifDictionary int CATAskConfirmation(const CATUnicodeString &message, const CATUnicodeString &title, const char* name = "Question");

//ExportedByCATLifDictionary int CATShowWarningNB(const CATUnicodeString &message, const CATUnicodeString &title, const char* name = "Warning");
//ExportedByCATLifDictionary int CATShowInformationNB(const CATUnicodeString &message, const CATUnicodeString &title, const char* name = "Info");
//ExportedByCATLifDictionary int CATShowErrorNB(const CATUnicodeString &message, const CATUnicodeString &title, const char* name = "Error");
//
//
//class ExportedByCATLifDictionary CATKweNotify : public CATFrmNotify
//{
//	CATDeclareClass;
//public:
//	CATKweNotify(CATDialog * pParent,
//	       const CATString & rObjectName,
//	       CATDlgStyle nStyle = NULL);
//
//private:
//	void Close(CATCommand *, CATNotification* , CATCommandClientData data);
//
//};

#endif
