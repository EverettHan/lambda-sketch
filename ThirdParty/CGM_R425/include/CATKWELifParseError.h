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
#ifndef CATKWELifParseError_h
#define CATKWELifParseError_h

#include "CATLifExpressions.h"

#include "CATUnicodeString.h"
#include "CATKWELifMKSError.h"
#include "CATLifError.h"
#include "CATKWEError.h"
#include "CATCkeParseError.h"

#include "CATLifErrorManager.h"
#include "CATICkeSignature.h"



class ExportedByCATLifExpressions CATCkeNotParsable : public CATCkeParseException
{
    public:
      CATCkeNotParsable (const CATUnicodeString &s,const int line);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeNonExistingType : public CATCkeParseException
{
    public:
      // Last argument is equal to 0 if we want to raise a non existing message
	  // and 1 if we want to say only that it is a bad type
      CATCkeNonExistingType (const CATUnicodeString &s,const int line,const int Bad=0);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeNonExistingVariable : public CATCkeParseException
{
    public:
      CATCkeNonExistingVariable (const CATUnicodeString &s,const int line);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeDoublyDefinedVariable : public CATCkeParseException
{
    public:
      CATCkeDoublyDefinedVariable (const CATUnicodeString &s,const int line);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeNonExistingAttribute : public CATCkeParseException
{
    public:
      CATCkeNonExistingAttribute (const CATUnicodeString &s,const int line);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeNonExistingMethod : public CATCkeParseException
{
    public:
      CATCkeNonExistingMethod (const CATUnicodeString &kind,const CATUnicodeString &s,const int line);
      CATCkeNonExistingMethod (const CATUnicodeString &kind,const CATUnicodeString &s,const int line,const CATUnicodeString &,const CATUnicodeString &);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeNonExistingUnit : public CATCkeParseException
{
    public:
      CATCkeNonExistingUnit (const CATUnicodeString &s,const int line);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeUndeterminableUnit : public CATCkeParseException
{
    public:
      CATCkeUndeterminableUnit (const CATUnicodeString &s,const int line);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeTypeConflict : public CATCkeParseException
{
    public:
      CATCkeTypeConflict (const CATUnicodeString &s1,const CATUnicodeString &s2,const int line);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeInvalidExpression : public CATCkeParseException
{
    public:
      CATCkeInvalidExpression (const CATUnicodeString &s1,const int line);
      CATCkeInvalidExpression (const CATUnicodeString &sTypeFormula,const CATUnicodeString &sTypeParameter,const int line);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};


class ExportedByCATLifExpressions CATCkeBadNbArg : public CATCkeParseException
{
    public:
      CATCkeBadNbArg (const CATUnicodeString &kind,const CATUnicodeString &s1,const int,const int,const int line);
      CATCkeBadNbArg (const CATUnicodeString &kind,const CATUnicodeString &s1,const int line);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeBadKindOfArg : public CATCkeParseException
{
    public:
      // Pour differencier les messages d'erreurs proches, on joue uniquement sur les signatures des constructeurs
	  // C'est un peu pauvre...
      CATCkeBadKindOfArg         (const CATUnicodeString &kind,
                                  const CATUnicodeString &s1,
                                  const int,
                                  const CATUnicodeString &,
                                  const CATUnicodeString &,
                                  const int line);
      CATCkeBadKindOfArg         (const CATUnicodeString &kind,
                                  const CATUnicodeString &s1,
                                  const int,
                                  const CATUnicodeString &,
                                  const int line);
	  // bad comparison
      CATCkeBadKindOfArg         (const int line,
                                  const CATUnicodeString &,
                                  const CATUnicodeString &);
	  // Bad affectation
      CATCkeBadKindOfArg         (const CATUnicodeString &,
                                  const CATUnicodeString &,
								  const int line);
	  // Bad operation
      CATCkeBadKindOfArg         (const CATUnicodeString &,
								  const int line,
                                  const CATUnicodeString &,
                                  const CATUnicodeString &);

      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeConstantModified : public CATCkeParseException
{
    public:
      CATCkeConstantModified     (const CATUnicodeString &kind,
                                  const CATUnicodeString &s1,
                                  const int num,
                                  const int line);

      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeStringNotFinished : public CATCkeParseException
{
    public:
      CATCkeStringNotFinished (const CATUnicodeString &s,const int line);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeNameNotFinished : public CATCkeParseException
{
    public:
      CATCkeNameNotFinished (const CATUnicodeString &s,const int line);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeCommentNotFinished : public CATCkeParseException
{
    public:
      CATCkeCommentNotFinished (const CATUnicodeString &s,const int line);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeLexOverflow : public CATCkeParseException
{
    public:
      CATCkeLexOverflow (const CATUnicodeString &s);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};


class ExportedByCATLifExpressions CATCkeMeasureInProduct : public CATCkeParseException
{
    public:
      CATCkeMeasureInProduct (const CATUnicodeString &s,const int line);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeBadLawNbFormal : public CATCkeParseException
{
    public:
      CATCkeBadLawNbFormal();
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeNotFormalLawOutput : public CATCkeParseException
{
    public:
      CATCkeNotFormalLawOutput ();
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeLawBadFormalName : public CATCkeParseException
{
    public:
      CATCkeLawBadFormalName (const CATUnicodeString &name);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};


class ExportedByCATLifExpressions CATCkeTypeNeeded : public CATCkeParseException
{
    public:
      CATCkeTypeNeeded (const CATUnicodeString &name,const CATUnicodeString &typenam,const int linenb);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeParseMultiLevel : public CATCkeParseException
{
    public:
      CATCkeParseMultiLevel (const CATUnicodeString &Message,const int linenb);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeParseRestrictSignature : public CATCkeParseException
{
    public:
		CATCkeParseRestrictSignature (const CATUnicodeString &restrictionType,const CATUnicodeString &signatureName,const CATICkeSignature::Mode signatureNotation);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeParseRestrictType : public CATCkeParseException
{
    public:
		CATCkeParseRestrictType (const CATUnicodeString &restrictionType,const CATUnicodeString &type);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeRecoverableParseError : public CATCkeParseException
{

public:
    CATCkeRecoverableParseError (const CATUnicodeString &s,const int line);
    virtual CATKWEError* Clone() const;
private:
    CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeBadKindOfArgInMatrix : public CATCkeParseException
{
public:
	CATCkeBadKindOfArgInMatrix (const CATUnicodeString &s,const int line);
	virtual CATKWEError* Clone() const;
private:
	CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeBadElementNumberInMatrixLine : public CATCkeParseException
{
public:
	CATCkeBadElementNumberInMatrixLine (const CATUnicodeString &s,const int line);
	virtual CATKWEError* Clone() const;
private:
	CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeSubParsingDetected : public CATCkeParseException
{
public:
	CATCkeSubParsingDetected ();
	virtual CATKWEError* Clone() const;
private:
	CATDeclareClass;
};

class ExportedByCATLifExpressions CATCkeBadLibraryName : public CATCkeParseException
{
public:
	CATCkeBadLibraryName (const CATUnicodeString &s,const int line);
	virtual CATKWEError* Clone() const;
private:
	CATDeclareClass;
}; 

class ExportedByCATLifExpressions CATCkeBadReusableFunctionName : public CATCkeParseException
{
public:
	CATCkeBadReusableFunctionName (const CATUnicodeString &s,const int line);
	virtual CATKWEError* Clone() const;
private:
	CATDeclareClass;
}; 

class ExportedByCATLifExpressions CATCkeUnprotectedInteger : public CATCkeParseException
{
public:
	CATCkeUnprotectedInteger (const CATUnicodeString &s,const int line);
	virtual CATKWEError* Clone() const;
private:
	CATDeclareClass;
}; 

class ExportedByCATLifExpressions CATCkeGenericParseError : public CATCkeParseException
{
    public:
      CATCkeGenericParseError (const CATUnicodeString &s,const int line);
      virtual CATKWEError* Clone() const;	
    private: 
      CATDeclareClass;
};


#endif





