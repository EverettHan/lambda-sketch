// Copyright Dassault Systemes 2000
#ifndef CATCkeSignature_h
#define CATCkeSignature_h
//////////////////////////////////////////////////////////////////////////
// 
//  Classe interne de Signature: Implementation C++ de CATICkeSignature (mono implementee)
// 	Internal signature class.
//////////////////////////////////////////////////////////////////////////
//
#include "CATLifExpressions.h"
#include "CATICkeType.h"
#include "CATCkeExprComponent.h"
#include "CATICkeSignature.h"
#include "CATICkeSignature.h"
#include "CATICkeEvaluator.h"
#include "CATICkeEvalFunction.h"

class CATICkeTerm_var;


typedef   HRESULT (*CATCkeParseSubExpression) (const CATICkeTerm_var &,CATCke::Boolean &oBool);


class ExportedByCATLifExpressions CATCkeSignature: public CATICkeSignature
{
	//	CATDeclareMLKDebug
	CATDeclareClass;
public :
	
	CATCkeSignature (const CATICkeType_var &, CATUnicodeString, const CATICkeEvalFunction_var &);
	virtual ~CATCkeSignature();
	
	CATCke::Boolean       IsRunnable () const;
	CATICkeSignature::Mode Notation   () const { return _mode; }
	virtual CATICkeEvaluator_var      Evaluator  () const { return _eval; }
	CATUnicodeString        Family     () const { return "";/*_family ;*/}
	
	// prototype
	int     PrototypeSize () const { return _proto->Size(); }
	CATCkeListOfArg  Prototype     () const { return _proto; }
	CATICkeArg_var     ReturnedArg   () const { return _out; }
	CATCke::Boolean     IsUnary       () const;
	
	void        AddArgument   (const CATICkeArg_var);
	void        SetPrototype  (const CATCkeListOfArg iListOfArguments);
	void        SetReturnedArg(const CATICkeArg_var&);
	void        SetNotation   (CATICkeSignature::Mode);
	void        SetNotation   (CATICkeSignature::Mode,CATCkeShowExpression);
	void	      SetEvaluator  (const CATICkeEvalFunction_var &e) { _eval = e; }
	void        SetFamily     (CATUnicodeString s) {/* _family = s; */} 
	
	// Object inherited services
	CATUnicodeString  Show    () const { return ShowIt(); }
	HRESULT DisplayForSignatureEditors(CATUnicodeString & oSigToDisplay) const;
	
	// montre la signature
	CATCkeShowExpression   ShowExprFct    () const {return _showFct; }

	// Show non NLS
	CATUnicodeString  InternalShow    () const { return ShowIt(CATCke::False, CATCke::False); }
	
	//--------------------------------------
	// variable number of argument
	//--------------------------------------
	CATCke::Boolean  HasVariableArgNb () const { return (_varnb == 1) ? CATCke::True : CATCke::False; }
	void SetVariableArgNb (const CATCke::Boolean &b)  { _varnb = (b == CATCke::True) ? 1 : 0; };
	
	void SetUserVisibility (const CATCke::Boolean &iVariable) { _isUserVisible = (iVariable == CATCke::True) ? 1 : 0; };
	CATCke::Boolean IsUserVisible () { return (_isUserVisible == 1) ? CATCke::True : CATCke::False; };

	// set and get informations on signatures
	void SetInformation (const CATCkeSignatureInfo info,CATCkeParseSubExpression fct);
	void SetInformation (const CATCkeSignatureInfo info);
	CATCkeSignatureInfo GetInformation () const;
	
	// get description
	CATICkeSignature_var GetDescription () const;
    
	
	// direct evaluation CATICkeFunction interface
	virtual void Run (CATCkeListOfParm plist,const CATICkeParm_var &,const CATCkeEvalContext *pevalcontext=NULL) const; 
	
	void SetAllowedEditionContext(short context);
	
	short GetAllowedEditionContext();

	void SetFunctionQuality(short Quality) ;

	void SetRankOfOptionalArguments (const int iRankForOptionalArguments) ;

	int  RankOfOptionalArguments () const ;	

	HRESULT ParseSubExpression (const CATICkeTerm_var &term,CATCke::Boolean &oBool) const;

	virtual CATICkeEvalFunction_var      EvalFunction  () const { return _eval; }

	CATUnicodeString GetLibraryIfReusable() const;

	void SetLibraryForReusable(const CATUnicodeString &iLibName) ;

	void SetHTMLDescription(const CATUnicodeString &iDescr);

	void SetPlainDescription(const CATUnicodeString &iDescr);

	CATUnicodeString GetHTMLDescription();

	CATUnicodeString GetPlainDescription();

	CATUnicodeString  Name() const;

	void Rename    (const CATUnicodeString &iNewName);

protected:
	
	// not exported
	CATUnicodeString  ShowIt    (CATCke::Boolean = CATCke::False, CATCke::Boolean = CATCke::True) const;
	CATICkeEvalFunction_var	  _eval;
	
	CATUnicodeString   _name;
	CATICkeType_var _type;

private:
	CATCkeSignature (const CATCkeSignature&);
	void operator=(const CATCkeSignature&);

	void Supprime (short);
	
	CATCkeListOfArg _proto;
	CATCkeShowExpression  _showFct;
	CATCkeParseSubExpression _parseSubFct; // Ajout qui va avoir une empreinte PCS... A regler plus tard
	
	CATCkeSignatureInfo _siginfo;
	
	CATICkeSignature::Mode   _mode;
	
	CATICkeArg_var     	  _out;
	
	
	short _EditionContext;
	unsigned int _varnb:1;
	unsigned int _isUserVisible:1;
	int _RankOfOptionalArguments;
	CATUnicodeString _LibNameForReusable;
	CATUnicodeString _HTMLDescription;
	CATUnicodeString _Description;
}; 

#endif

