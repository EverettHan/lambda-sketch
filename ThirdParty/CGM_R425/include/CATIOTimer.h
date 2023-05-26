#ifndef CATIOTimer_H
#define CATIOTimer_H

#include "CATSGUtil.h"

namespace CATSG
{
    CATSGTickTime ExportedBySGComposites GetTickTime();
};

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGContext.h"

class ExportedBySGComposites CATIOTimer
{
protected:
	CATSGTickTime   _tickTime;
	const char*     _msg;
public:
	CATIOTimer(const char* iMsg) : _msg(iMsg) {
		_tickTime = CATSG::GetTickTime();
	}

	~CATIOTimer() {
		CATSGTickTime elapsed = CATSG::GetTickTime() - _tickTime;
		CATSGContext::Get(0).LogError(_msg, elapsed);
	}
};

class ExportedBySGComposites CATIOResumableTimer
{
protected:
	CATSGTickTime   _tickTime;
	CATSGTickTime	_accumulatedTime;
	CATSGTickTime	_tickCount;
	const char*     _msg;
public:
	CATIOResumableTimer(const char* iMsg) : _msg(iMsg), _accumulatedTime(0), _tickCount(0), _tickTime(0) {
	}

	~CATIOResumableTimer() {
		CATSGContext::Get(0).LogError(_msg, _accumulatedTime);
	}

	void Resume() {
		_tickTime = CATSG::GetTickTime();
	}

	void Pause() {
		CATSGTickTime current = CATSG::GetTickTime();
		_accumulatedTime += current - _tickTime;
		++_tickCount;

		_tickTime = 0;
	}

	void Reset() {
		bool needResume = false;
		if(_tickTime!=0) {
			Pause();
			needResume = true;
		}

		_accumulatedTime = 0;
		_tickCount = 0;
		_tickTime = 0;

		if(needResume)
			Resume();
	}

	double GetMean() {
		bool needResume = false;
		if(_tickTime!=0) {
			Pause();
			needResume = true;
		}

		double res = (double)_accumulatedTime/ (double)_tickCount;

		if(needResume)
			Resume();

		return res;
	}

	void FlushMean() {
		CATSGContext::Get(0).LogError(_msg, GetMean());
	}

	CATSGTickTime GetTotal() {
		bool needResume = false;
		if(_tickTime!=0) {
			Pause();
			needResume = true;
		}

		if(needResume)
			Resume();

		return _accumulatedTime;
	}

	void FlushTotal() {
		CATSGContext::Get(0).LogError(_msg, GetTotal());
	}
};

class ExportedBySGComposites CATIOTimerTicker
{
protected:
	CATSGTickTime		_flushTriggerCount;
	CATIOResumableTimer*	_timer;
public:
	CATIOTimerTicker(CATIOResumableTimer* iResumableTimer, CATSGTickTime iFlushTriggerCount) : _timer(iResumableTimer), _flushTriggerCount(iFlushTriggerCount) {
		_timer->Resume();
	}

	~CATIOTimerTicker() {
		_timer->Pause();
		if(_timer->GetTotal() > _flushTriggerCount) {
			_timer->FlushMean();
			_timer->Reset();
		}
	}
};

#endif //SG_COMPOSITES_MULTIOS
#endif // CATIOTimer_H
