/**
 * @level Protected
 * @usage U1
 */

/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//===============================================================
//
// CATLifParseError.h
//
//===============================================================
//
// Usage Notes:
//===============================================================
//
// version 0.1
// author FRH
// Date creation March. 1999
// 
//===============================================================
#ifndef CATKWELifMKSError_h
#define CATKWELifMKSError_h

#include "CATLifDictionary.h"

#include "CATUnicodeString.h"
#include "CATLifError.h"
#include "CATKWEError.h"
#include "CATCkeParseError.h"

#include "CATLifErrorManager.h"

#define _ERRORLINEATTRIBUTEDEFINED_ 1

/** The CATKWELifParseError class from the module CATLifToolKit.<br>
*
* An error is defined by four characteristics:<br>
* <br>
* <ol>
* 1. Error type set by its classname.<p>
* 2. Error source (Any object deriving from CATBaseUnknown.<p>
* 3. Error message (A string ).<p>
* 4. Error severity (typdedef in this class. enum Severity { Message, Warning, Error } ).<p>
* </ol>
*	@see CATLifErrorManager
*	@see KnowledgeCommunication.CATKWEError
*/
class ExportedByCATLifDictionary CATCkeParseException : public CATLifError
{
	
	CATDeclareClass;
	
public:

	CATCkeParseException(const CATCkeParseException& h);
	CATCkeParseException(CATCkeParseError*,const CATKWEErrorSeverity::Severity iS = CATKWEErrorSeverity::Error);
	virtual ~CATCkeParseException();
	virtual CATKWEError* Clone() const;	

        CATCkeParseError *GetParseError() const;

		int GetLineNo()
		{
			return _LineNo;
		}

protected:   
	void SetMsg ();
        void SetMsg (const CATUnicodeString *ps);
        CATUnicodeString errmsg (CATCkeParseError*);
        CATCkeParseError *pe_;

		int _LineNo;
	
};


class ExportedByCATLifDictionary CATCkeErrorMKS : public CATCkeParseException
{
    public:
      CATCkeErrorMKS(CATCkeParseError*);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifDictionary CATCkeAssignMKS : public CATCkeErrorMKS
{
    public:
      CATCkeAssignMKS(const CATUnicodeString &vin,const CATUnicodeString &vto, const CATUnicodeString &fct = "");
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifDictionary CATCkeCompareMKS : public CATCkeErrorMKS
{
    public:
      CATCkeCompareMKS(const CATUnicodeString &v1,const CATUnicodeString &v2,const CATUnicodeString &ope);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};


#endif





