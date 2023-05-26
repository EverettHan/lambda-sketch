// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2001
//


#ifndef CATMarshHandle_h
#define CATMarshHandle_h

#include "CATCGMOutput.h"

//class CATMath3x3Matrix; //future use...rotation handle...
// class CATMathTransformation;
// class CATMathVector;	//future use...rotation handle...

class CATMarshHandle
{
public:
	
	CATMarshHandle()
	{
		//cgmout << "CATMarshHandle : Handle Construction this = " << this << cgmendl;
		_Count = 0;
	};
	
	virtual ~CATMarshHandle()
	{
		//cgmout << "CATMarshHandle : Handle Destruction this = " << this << cgmendl;
	};

	virtual void AddRef()
	{
		//cgmout << "CATMarshHandle : Handle Addref this = " << this << cgmendl;
		_Count++;
	};

	virtual void Release()
	{

		//cgmout << "CATMarshHandle : Handle Release this = " << this << cgmendl;
		
		_Count--; 
		if (_Count <=0 )
		{
			delete this;
		}
	}

	virtual void SetValue(const double &val)=0;
	virtual void GetValue(double &val)=0;

private:
	CATLONG32 _Count;
};

#endif
