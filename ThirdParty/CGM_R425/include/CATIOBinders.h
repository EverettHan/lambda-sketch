#ifndef CATIOBinders_H
#define CATIOBinders_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATIOFuture.h"

enum CATECleanArguments {
    CATENoCleanAfterCall = 0,
    CATECleanAfterCall = 1 //Detach is called on the LifeCyclePolicies associated with arguments (_ar0, _arg1, _arg2) of the binder inside operator()() 
};

//see IsRepPtr<CATRep*> specialization below
template <typename T>
struct IsRepPtr
{
    static bool value()
    {
        return false;
    }
};

//used to produce a compilation time error if raw CATRep* is used in a binder:
//since reps are managed by counting their parents (and not direct refcount) 
//and we managed them in rings by giving full ownership to the classicRep composite
//putting raw CATRep* in binder is unsafe because the corresponding future may not take ownership of the result before its destruction
//which would make the job leak the CATRep*
template <>
struct IsRepPtr<CATRep*>
{
        //no value(), so that it generates a compilation time error if used.
};


// When we can use C++11 revisit binders as more elegant options
// will be available.
template<typename T, typename R, template <class> class LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy>
class CATIOBinderNoArg
{
public:
	typedef R 	(T::*MethodNoArgAddrType)() ;

	CATIOBinderNoArg() : _this(NULL), _method(NULL)
	{

	}

	CATIOBinderNoArg( R (T::*iMethod)(), T* iThis) : _method(iMethod), _this(iThis)
	{
		LifeCyclePolicy<T>::Attach(*_this, _this);
	}

	CATIOBinderNoArg(CATIOBinderNoArg& iOther)
	{
		_this 	= iOther.GetThis();
		_method = iOther.GetMethod();
		int dummy;
		_result	= iOther.GetResult(dummy);
		LifeCyclePolicy<T>::Attach(*_this, _this);
	}

	virtual ~CATIOBinderNoArg() 
	{
		LifeCyclePolicy<T>::Detach(*_this, _this);
        IsRepPtr<R>::value();//used to produce a compilation time error if CATRep* is used (see def of IsRepPtr)
	}

	HRESULT ReadyDependencies() { return S_OK; }

	R& operator()() 
	{
		_result = (_this->*_method)();
		return _result;
	}

	R& GetResult(int& oSize) 
    {	
        oSize = sizeof(R); 
        return _result;	
    }

	T*									GetThis() { return _this; }
	MethodNoArgAddrType					GetMethod() { return _method; }
private:
	T* 	_this;
	R 	_result;
	R 	(T::*_method)();	
};

template<typename T, typename A0, typename R, template <class> class LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy, 
                                              template <class> class Arg0LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy, CATECleanArguments CleanArgs = CATENoCleanAfterCall>
class CATIOBinder1Arg
{
public:
	typedef R 	(T::*Method1ArgAddrType)(A0) ;
	typedef A0	A0Type;
	typedef R	RType;

	CATIOBinder1Arg() : _this(NULL), _method(NULL), _cleaned(0)
	{

	}

	CATIOBinder1Arg( R (T::*iMethod)(A0), T* iThis, A0 iArg0) : 	_method(iMethod),
																_this(iThis),
																_arg0(iArg0),
                                                                _cleaned(0)
	{
		LifeCyclePolicy<T>::Attach(*_this, _this);
        Arg0LifeCyclePolicy<A0>::Attach(_arg0, &_arg0);
	}

	CATIOBinder1Arg(CATIOBinder1Arg& iOther) : _arg0(iOther.GetArg0()), _cleaned(0)
	{
		_this 	= iOther.GetThis();
		_method = iOther.GetMethod();
		int dummy;
		_result	= iOther.GetResult(dummy);
		LifeCyclePolicy<T>::Attach(*_this, _this);
        Arg0LifeCyclePolicy<A0>::Attach(_arg0, &_arg0);
	}

	virtual ~CATIOBinder1Arg() 
	{
		LifeCyclePolicy<T>::Detach(*_this, _this);

        if((_cleaned&1) == 0)
        {
            Arg0LifeCyclePolicy<A0>::Detach(_arg0, &_arg0);
        }
        IsRepPtr<R>::value();//used to produce a compilation time error if CATRep* is used (see def of IsRepPtr)
        IsRepPtr<A0>::value();//used to produce a compilation time error if CATRep* is used (see def of IsRepPtr)
	}

	HRESULT ReadyDependencies() { return S_OK; }

	R& operator()() 
	{
		_result = (_this->*_method)(_arg0);

        if(CleanArgs == CATECleanAfterCall)
        {
            Arg0LifeCyclePolicy<A0>::Detach(_arg0, &_arg0);
            _cleaned = 1;
        }

		return _result;
	}

    //unused and risky
    //don't forget Arg*LifeCyclePolicy if uncomment
	/*void BindArg0(const A0& iA0) 
	{
		_arg0 = iA0;
	}*/

	R&	GetResult(int& oSize) 
    {	
        oSize = sizeof(R); 
        return _result;	
    }

	T*									GetThis() { return _this; }
	Method1ArgAddrType					GetMethod() { return _method; }
	A0 									GetArg0() { return _arg0; }
private:
	T* 	_this;
	A0 	_arg0;
	R 	_result;
	R 	(T::*_method)(A0);	
    char _cleaned; //flags set to one on detach of arguments, to avoid double detach (_cleaned&1 is for _arg0)
};

/** 
 * Could have been merged with CATIOBinder1Arg as basically it can support both usage but 
 * we don't want to impact the performances of jobs that don't need to handle their arguments as
 * futures. Might need to reconsider this decision after profiling the difference.
 */
template<typename T, typename A0, typename R, template <class> class LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy,
                                              template <class> class Arg0LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy, CATECleanArguments CleanArgs = CATENoCleanAfterCall>
class CATIOBinderF1Arg
{
public:
	typedef R 	(T::*Method1ArgAddrType)(A0) ;
	typedef A0	A0Type;
	typedef R	RType;

	CATIOBinderF1Arg() : _this(NULL), _method(NULL), _cleaned(0)
	{

	}

	CATIOBinderF1Arg( R (T::*iMethod)(A0), T* iThis, CATIOFuture<A0> iArg0) :
        _method(iMethod),
		_this(iThis),
		_arg0(iArg0),
        _cleaned(0)
	{
		LifeCyclePolicy<T>::Attach(_this);
        Arg0LifeCyclePolicy<A0>::Attach(_arg0, &_arg0);
	}

	CATIOBinderF1Arg(CATIOBinder1Arg<T, A0, R, LifeCyclePolicy, Arg0LifeCyclePolicy, CleanArgs>& iOther) :
        _arg0(iOther.GetArg0()),
        _cleaned(0)
	{
		_this 	= iOther.GetThis();
		_method = iOther.GetMethod();
		int dummy;
		_result	= iOther.GetResult(dummy);
		LifeCyclePolicy<T>::Attach(_this);
        Arg0LifeCyclePolicy<A0>::Attach(_arg0, &_arg0);
	}

	virtual ~CATIOBinderF1Arg() 
	{
		LifeCyclePolicy<T>::Detach(_this);

        if((_cleaned&1) == 0)
        {
            Arg0LifeCyclePolicy<A0>::Detach(_arg0, &_arg0);
        }
        IsRepPtr<R>::value();//used to produce a compilation time error if CATRep* is used (see def of IsRepPtr)
        IsRepPtr<A0>::value();//used to produce a compilation time error if CATRep* is used (see def of IsRepPtr)
	}

	HRESULT ReadyDependencies()
	{
		HRESULT hr = E_FAIL;
		A0 arg0;
		if(!_arg0.TryGet(arg0)) {
			// Let's do the best we can do !
			// There is 
            CATIOJob* job = _arg0.GetAssociatedJob();
			hr = job->Schedule();
            job->Release();//GetAssociatedJob does an addRef : CATIOJob
            job = NULL;
			if(hr==S_OK) {
				// Ok we have been able to schedule it,
				// but we are not ready yet
				hr = E_INVALIDSTATE;
			}
		} else {
			hr = S_OK;
		}
	}

	R& operator()() 
	{
		// Let's do the best we can do block until value
		// is available. Users should use ReadyDependencies
		// to take appropriate actions if dependencies are not ready yet!
		_result = (_this->*_method)(_arg0.Get());

        if(CleanArgs == CATECleanAfterCall)
        {
            Arg0LifeCyclePolicy<A0>::Detach(_arg0, &_arg0);
            _cleaned = 1;
        }

		return _result;
	}

    //unused and risky
    //don't forget Arg*LifeCyclePolicy if uncomment
	/*void BindArg0(const CATIOFuture<A0>& iA0) 
	{
		_arg0 = iA0;
	}*/

	R& GetResult(int& oSize) 
    {	
        oSize = sizeof(R); 
        return _result;	
    }

	T*									GetThis() { return _this; }
	Method1ArgAddrType					GetMethod() { return _method; }
	CATIOFuture<A0>						GetArg0() { return _arg0; }
private:
	T* 					_this;
	CATIOFuture<A0> 	_arg0;
	R 					_result;
	R 	(T::*_method)(A0);	
    char _cleaned; //flags set to one on detach of arguments, to avoid double detach (_cleaned&1 is for _arg0)
};

template<typename T, typename A0, typename A1, typename R, template <class> class LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy, 
                                               template <class> class Arg0LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy,
                                               template <class> class Arg1LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy, CATECleanArguments CleanArgs = CATENoCleanAfterCall>
class CATIOBinder2Arg
{
public:
	typedef R 	(T::*Method2ArgAddrType)(A0, A1) ;

	CATIOBinder2Arg() : _this(NULL), _method(NULL), _cleaned(0)
	{

	}

	CATIOBinder2Arg( R (T::*iMethod)(A0, A1), T* iThis, A0 iArg0, A1 iArg1) : 	_method(iMethod),
																			_this(iThis),
																			_arg0(iArg0),
																			_arg1(iArg1),
                                                                            _cleaned(0)
	{
		LifeCyclePolicy<T>::Attach(*_this, _this);
        Arg0LifeCyclePolicy<A0>::Attach(_arg0, &_arg0);
        Arg1LifeCyclePolicy<A1>::Attach(_arg1, &_arg1);
	}

	CATIOBinder2Arg(CATIOBinder2Arg& iOther) : _cleaned(0)
	{
		_this 	= iOther.GetThis();
		_method = iOther.GetMethod();
		_arg0 	= iOther.GetArg0();
		_arg1 	= iOther.GetArg1();
		int dummy;
		_result	= iOther.GetResult(dummy);
		LifeCyclePolicy<T>::Attach(*_this, _this);

        Arg0LifeCyclePolicy<A0>::Attach(_arg0, &_arg0);
        Arg1LifeCyclePolicy<A1>::Attach(_arg1, &_arg1);
	}

	virtual ~CATIOBinder2Arg() 
	{
		LifeCyclePolicy<T>::Detach(*_this, _this);

        if((_cleaned&1) == 0)
        {
            Arg0LifeCyclePolicy<A0>::Detach(_arg0, &_arg0);
        }

        if((_cleaned&2) == 0)
        {
            Arg1LifeCyclePolicy<A1>::Detach(_arg1, &_arg1);
        }

        IsRepPtr<R>::value();//used to produce a compilation time error if CATRep* is used (see def of IsRepPtr)
        IsRepPtr<A0>::value();//used to produce a compilation time error if CATRep* is used (see def of IsRepPtr)
        IsRepPtr<A1>::value();//used to produce a compilation time error if CATRep* is used (see def of IsRepPtr)
	}

	HRESULT ReadyDependencies() { return S_OK; }

	R& operator()() 
	{
		_result = (_this->*_method)(_arg0, _arg1);
	
        if(CleanArgs == CATECleanAfterCall)
        {
            Arg0LifeCyclePolicy<A0>::Detach(_arg0, &_arg0);
            Arg1LifeCyclePolicy<A1>::Detach(_arg1, &_arg1);

            _cleaned = 3; // 0b11 to indicate that both args are detached
        }
        
        return _result;
	}

	R& GetResult(int& oSize) 
    {	
        oSize = sizeof(R); return _result;	
    }

	T* GetThis() 
    { 
        return _this; 
    }

	Method2ArgAddrType GetMethod() 
    { 
        return _method; 
    }

	A0 GetArg0() 
    { 
        return _arg0; 
    }

	A1 GetArg1() 
    { 
        return _arg1; 
    }

    //unused and risky
    //don't forget Arg*LifeCyclePolicy if uncomment
	/*void BindArg0(const A0& iA0) 
	{
		_arg0 = iA0;
	}

	void BindArg1(const A1& iA1) 
	{
		_arg1 = iA1;
	}*/
private:
	T* 	_this;
	A0 	_arg0;
	A1 	_arg1;
	R 	_result;
	R 	(T::*_method)(A0, A1);	
    char _cleaned; //flags set to one on detach of arguments, to avoid double detach (_cleaned&1 is for _arg0)
};

template<typename T, typename A0, typename A1, typename A2, typename R, template <class> class LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy,
         template <class> class Arg0LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy, template <class> class Arg1LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy,
         template <class> class Arg2LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy, CATECleanArguments CleanArgs = CATENoCleanAfterCall>
class CATIOBinder3Arg
{
public:
	typedef R 	(T::*Method3ArgAddrType)(A0, A1, A2);

	CATIOBinder3Arg() : _this(NULL), _method(NULL), _cleaned(0)
	{

	}

	CATIOBinder3Arg( R (T::*iMethod)(A0, A1, A2), T* iThis, A0 iArg0, A1 iArg1, A2 iArg2) : 	_method(iMethod),
																			_this(iThis),
																			_arg0(iArg0),
																			_arg1(iArg1),
																			_arg2(iArg2),
                                                                            _cleaned(0)
	{
		LifeCyclePolicy<T>::Attach(*_this, _this);
        Arg0LifeCyclePolicy<A0>::Attach(_arg0, &_arg0);
        Arg1LifeCyclePolicy<A1>::Attach(_arg1, &_arg1);
        Arg2LifeCyclePolicy<A2>::Attach(_arg2, &_arg2);
	}

	CATIOBinder3Arg(CATIOBinder3Arg& iOther) : _cleaned(0)
	{
		_this 	= iOther.GetThis();
		_method = iOther.GetMethod();
		_arg0 	= iOther.GetArg0();
		_arg1 	= iOther.GetArg1();
		_arg2 	= iOther.GetArg2();
		int dummy;
		_result	= iOther.GetResult(dummy);
		LifeCyclePolicy<T>::Attach(*_this, _this);
        Arg0LifeCyclePolicy<A0>::Attach(_arg0, &_arg0);
        Arg1LifeCyclePolicy<A1>::Attach(_arg1, &_arg1);
        Arg2LifeCyclePolicy<A2>::Attach(_arg2, &_arg2);
	}

	virtual ~CATIOBinder3Arg() 
	{
		LifeCyclePolicy<T>::Detach(*_this, _this);

        if((_cleaned&1) == 0)
        {
            Arg0LifeCyclePolicy<A0>::Detach(_arg0, &_arg0);
        }

        if((_cleaned&2) == 0)
        {
            Arg1LifeCyclePolicy<A1>::Detach(_arg1, &_arg1);
        }

        if((_cleaned&4) == 0)
        {
            Arg2LifeCyclePolicy<A2>::Detach(_arg2, &_arg2);
        }

        IsRepPtr<R>::value();//used to produce a compilation time error if CATRep* is used (see def of IsRepPtr)
        IsRepPtr<A0>::value();//used to produce a compilation time error if CATRep* is used (see def of IsRepPtr)
        IsRepPtr<A1>::value();//used to produce a compilation time error if CATRep* is used (see def of IsRepPtr)
        IsRepPtr<A2>::value();//used to produce a compilation time error if CATRep* is used (see def of IsRepPtr)
	}

	HRESULT ReadyDependencies() { return S_OK; }

	R& operator()() 
	{
		_result = (_this->*_method)(_arg0, _arg1, _arg2);

        if(CleanArgs == CATECleanAfterCall)
        {
            Arg0LifeCyclePolicy<A0>::Detach(_arg0, &_arg0);
            Arg1LifeCyclePolicy<A1>::Detach(_arg1, &_arg1);
            Arg2LifeCyclePolicy<A2>::Detach(_arg2, &_arg2);

            _cleaned = 7; // 0b111 to indicate that all 3 args are detached
        }

		return _result;
	}

	R& GetResult(int& oSize) 
    {	
        oSize = sizeof(R); 
        return _result;	
    }

	Method3ArgAddrType					GetMethod() { return _method; }
	T*									GetThis() { return _this; }
	A0 									GetArg0() { return _arg0; }
	A1 									GetArg1() { return _arg1; }
	A2 									GetArg2() { return _arg2; }

    //unused and risky
    //don't forget Arg*LifeCyclePolicy if uncomment
	/*void BindArg0(const A0& iA0) 
	{
		_arg0 = iA0;
	}

	void BindArg1(const A1& iA1) 
	{
		_arg1 = iA1;
	}

	void BindArg2(const A2& iA2)
	{
		_arg2 = iA2;
	}*/

private:
	T* 	_this;
	A0 	_arg0;
	A1 	_arg1;
	A2 	_arg2;
	R 	_result;
	R 	(T::*_method)(A0, A1, A2);	
    char _cleaned; //flags set to one on detach of arguments, to avoid double detach (_cleaned&1 is for _arg0)
};

#endif // SG_COMPOSITES_MULTIOS
#endif // CATIOBinders_H
