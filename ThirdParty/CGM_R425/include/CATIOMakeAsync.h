#ifndef CATIOMakeAsync_H
#define CATIOMakeAsync_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATIOJob.h"
#include "CATIOBinders.h"
#include "CATIOFuture.h"

template<typename T, typename R, template <class> class LifeCyclePolicy = CATSGRefCountedLifeCycleMgtPolicy>
struct CATIOMakeAsyncNoArg
{
	typedef CATIOBinderNoArg<T, R>	Binder;
	typedef CATIOBinderJob<Binder>	Job;
	typedef CATIOFuture<R>	 		Future;

	Future* operator()(typename Binder::MethodNoArgAddrType iMethod, T* iThis) {
		Binder binder(iMethod, iThis);
		Job* job = new Job(binder);
		job->ForceState(CATEIOJobStateNotScheduled);

		return new Future(job);
	}
};

template<typename T, typename A0, typename R, template <class> class LifeCyclePolicy = CATSGRefCountedLifeCycleMgtPolicy>
struct CATIOMakeAsync1Arg
{
	typedef CATIOBinder1Arg<T, A0, R>	Binder;
	typedef CATIOBinderF1Arg<T, A0, R>	FBinder;
	typedef CATIOBinderJob<Binder>		Job;
	typedef CATIOFuture<R>	 			Future;

	Future* operator()(typename Binder::Method1ArgAddrType iMethod, T* iThis, A0 iArg0) {
		Binder binder(iMethod, iThis, iArg0);
		Job* job = new Job(binder);
		job->ForceState(CATEIOJobStateNotScheduled);

		return new Future(job);
	}

	Future* operator()(typename Binder::Method1ArgAddrType iMethod, T* iThis, CATIOFuture<A0> iArg0) {
		FBinder binder(iMethod, iThis, iArg0);
		Job* job = new Job(binder);
		job->ForceState(CATEIOJobStateNotScheduled);

		return new Future(job);
	}
};

template<typename T, typename A0, typename A1, typename R, template <class> class LifeCyclePolicy = CATSGRefCountedLifeCycleMgtPolicy>
struct CATIOMakeAsync2Arg
{
	typedef CATIOBinder2Arg<T, A0, A1, R>	Binder;
	typedef CATIOBinderJob<Binder>			Job;
	typedef CATIOFuture<R>	 				Future;

	Future* operator()(typename Binder::Method2ArgAddrType iMethod, T* iThis, A0 iArg0, A1 iArg1) {
		Binder binder(iMethod, iThis, iArg0, iArg1);
		Job* job = new Job(binder);
		job->ForceState(CATEIOJobStateNotScheduled);

		return new Future(job);
	}
};

template<typename T, typename A0, typename A1, typename A2, typename R, template <class> class LifeCyclePolicy = CATSGRefCountedLifeCycleMgtPolicy>
struct CATIOMakeAsync3Arg
{
	typedef CATIOBinder3Arg<T, A0, A1, A2, R>	Binder;
	typedef CATIOBinderJob<Binder>				Job;
	typedef CATIOFuture<R>	 					Future;

	Future* operator()(typename Binder::Method3ArgAddrType iMethod, T* iThis, A0 iArg0, A1 iArg1, A2 iArg2) {
		Binder binder(iMethod, iThis, iArg0, iArg1, iArg2);
		Job* job = new Job(binder);
		job->ForceState(CATEIOJobStateNotScheduled);

		return new Future(job);
	}
};
#endif // SG_COMPOSITES_MULTIOS
#endif // CATIOMakeAsync_H
