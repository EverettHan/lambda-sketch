//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef EnoDicTimer_h
#define EnoDicTimer_h

#include "CATString.h"
#include "CATLib.h"
#include "ENODicTime.h"


class ExportedByENODicTime EnoDicTimer {
    public:
        EnoDicTimer     (const CATTimerId &iTimerId, const CATString &iLabel);
 virtual ~EnoDicTimer    ();

        /**
        * @nodoc
        * Resets the timer.
        */
        void Reset      ();

        /**
        * @nodoc
        * Starts the timer.
        */
        void Start      ();

        /**
        * @nodoc
        * Stops the timer.
        */
        void Stop       ();

        /**
        * @nodoc
        * Recovers the timer's string-like data (id, label, comment).
        */
        void GetValues    (CATTimerId &oTimerId, CATString &oLabel, CATString &oComment);

        /**
        * @nodoc
        * Recovers the timer's time-like data (cpu, elapsed, nb of calls).
        */
        void GetTime    (unsigned long &oCpu, unsigned long &oElapsed, int &oNbCalled);

        /**
        * @nodoc
        * Compares 2 timers.
        * @return
        *    <ul>
        *    <li>-1  T1 < T2.</li>
        *    <li>+1  T1 > T2.</li>
        *    <li>0   T1 = T2.</li>
        *    </ul>
        */
        static int Compare    (EnoDicTimer *iT1, EnoDicTimer *iT2);


    private:
        EnoDicTimer     (const EnoDicTimer &iTimer);

        int             _NbStart;
        CATTimerId      _TimerId;
        CATString       _Label;
        CATString       _Comment;
        unsigned long   _Cpu, _DeltaCpu;
        unsigned long   _Elapsed, _DeltaElapsed;
};

#endif
