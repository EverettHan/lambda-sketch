//===================================================================
// COPYRIGHT DS SolidWorks Corporation 2011/09/23
//===================================================================
// SWXUtUserInterrupt.cpp
// Header definition of class SWXUtUserInterrupt
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/09/23 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef SWXUtUserInterrupt_H
#define SWXUtUserInterrupt_H

#include "SWXUtGeneral.h"
#include "CATBoolean.h"

//-----------------------------------------------------------------------
class SWXUtUserInterrupt;

class ExportedBySWXUtGeneral SWXUtUserInterrupt
{
public:
	static void StartTimer() {mStartTime=GetCurrentTime(); mWasInterrupted=false;}
	static void StopTimer() {mStartTime=0;}

	static CATBoolean CGMCallBackForIntrrupt(int iProgress, int iRange);
	static bool WasInterrupted();

	static bool CheckForUserInterrupts();
	static bool EscapeKeyPressed();

private:
	// Standard constructors and destructors
	// -------------------------------------
	SWXUtUserInterrupt();//private ctor
	virtual ~SWXUtUserInterrupt();

	// Copy constructor and equal operator
	// -----------------------------------
	SWXUtUserInterrupt (SWXUtUserInterrupt &); // prevent copy ctor
	SWXUtUserInterrupt& operator=(SWXUtUserInterrupt&);// prevent assignment

	static bool PeekMessageLocal();
	static int GetCurrentTime();

	static int mStartTime;
	static int mBase;
	static bool mWasInterrupted;
};

//-----------------------------------------------------------------------

#endif