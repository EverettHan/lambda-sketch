#ifndef IntrospectionUtils_H
#define IntrospectionUtils_H

#include "JS0CTYP.h"
#include "CATVariant.h"


enum Direction {IN_ARG=0, OUT_ARG=1};

class  Interface;

typedef HRESULT (*StubFunctionType)(CATBaseUnknown * , CATVariant [] , int , HRESULT &);
typedef HRESULT (*ItfIntrospectionCreatorFunctionType)(Interface *& oItf);




class ExportedByJS0CTYP Argument
{
	public:
	Argument(VARTYPE,Direction );
	virtual ~Argument();
	
	VARTYPE getType() {return _ArgType;};
	Direction getDirection() {return _dir;};
	
	private:
	Argument();
	VARTYPE _ArgType;
	Direction _dir;
};


class ExportedByJS0CTYP Method
{
	public:
	Method(const char * iName);
	virtual ~Method();
	
	void AddArgument(Argument * iArg);
	const char * getName();
	int getArgsList(Argument  **& oArgs, int & oArgNb);
	
	private:
	
	const char * _name;
	Argument ** _arguments;
	int _nbArgs;
	int _maxNbArgs;
	VARTYPE _returnType;
	ItfIntrospectionCreatorFunctionType _mCall;
};



class ExportedByJS0CTYP Interface
{
	public:
	Interface(const char *iName);
	virtual ~Interface();
	
	void AddMethod(Method * iMethodToAdd);
	
	int SetParentInterface(Interface * iParent);
	Interface * getParentInterface();
	
	int FindMethod(const char * iName, Method *& oM);
	
	static int Compare ( void *zi1, void *zi2);
	static unsigned int  Hash ( void * iZi);
	
	private:
	
	
	
	const char * _name;
	Method ** _methods;
	int _nbMethods;
	int _maxNbMethods;
	Interface * _parent;
};






#endif


