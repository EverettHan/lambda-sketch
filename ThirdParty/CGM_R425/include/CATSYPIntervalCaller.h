// COPYRIGHT Dassault Systemes 2019
//===================================================================
//
// CATSYPIntervalCaller.h
// Header definition of CATSYPIntervalCaller
//
//===================================================================

#ifndef CATSYPIntervalCaller_H
#define CATSYPIntervalCaller_H

#include <IntroInfra.h>
#include <CATBaseUnknown.h>
#include <CATBoolean.h>
#include <CATSYPDuration.h>
#include <CATSYPRepeatBehavior.h>
#include <CATBaseUnknown_WR.h>
#include <CATUnicodeString.h>
//----------------------------------------------------------------
// Class CATSYPIntervalCaller             
//----------------------------------------------------------------
/**
 * Base class for timelines.
 * <b>Role</b>:
 * Provides base functionnalities (duration, begin time, repeat behaviour, ...) for both animations and group of animations.
 * <br/>
 * A timeline can be an animation or a group of animations.
 *
 * <b>Wiki article :</b>
 * <a href="http://codewiki/codewiki/index.php/New_V6_Animation_Infrastructure"><b>CodeWiki -> Animations</b></a>
 *
 * @ingroup groupCIDIntrospection
 * @htmlinclude CATSYPTimeline.sypintro.html
 */
class ExportedByIntroInfra CATSYPIntervalCaller : public CATBaseUnknown
{
	CATDeclareClass;

public:
	/**
	* Standard constructor.
	*/
	CATSYPIntervalCaller(const CATBaseUnknown_var& i_spCallee, const CATUnicodeString& i_methodName, float i_period);
	virtual void SetElapsedTimeInSec(float i_elapsedTimeInSec);

protected:
	/**
	* Destructor.
	*/
	virtual ~CATSYPIntervalCaller();
	

private:
	CATBaseUnknown_var _callee;
	CATUnicodeString _methodName;
	float _period;
	int _currentLoop;
	CATSYPDuration _beginTime;
};
//-----------------------------------------------------------------------

#endif
