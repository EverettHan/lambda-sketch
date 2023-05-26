#ifndef CATIOThread_H
#define CATIOThread_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATThreads.h"
#include "CATIOJob.h"

class ExportedBySGComposites CATIOThread : public CATThreads 
{
public:
	CATIOThread(CATIOJob* iJob);
	virtual ~CATIOThread();
	virtual CATThreadsReturnCode Begin(void *iArg=NULL);
private:
	CATIOJob*	_associatedJob;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // CATIOThread_H
