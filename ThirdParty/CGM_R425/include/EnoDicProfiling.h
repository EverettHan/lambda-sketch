//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef EnoDicProfiling_h
#define EnoDicProfiling_h

#include "ENODicTime.h"
#include "CATListOfEnoDicTimer.h"

class EnoDicTimer;

class ExportedByENODicTime EnoDicProfiling
{
    public:
        /**
        * @nodoc
        * Resets all timers.
        */
        static void          ResetAll   ();

        /**
        * @nodoc
        * Resets a given timer.
        * @param iLabel Timer label
        */
        static void          Reset      (const CATString & iLabel);
//        static void          AddComment (const CATString & iLabel, const CATString & iComment);

        /**
        * @nodoc
        * Starts a given timer.
        * @param iLabel Timer label
        */
        static void          StepIn     (const CATString & iLabel);

        /**
        * @nodoc
        * Stops a given timer.
        * @param iLabel Timer label
        */
        static void          StepOut    (const CATString & iLabel);

        /**
        * @nodoc
        * Recovers a given timer.
        * @param iLabel Timer label
        */
        static EnoDicTimer * Locate     (const CATString & iLabel);

        /**
        * @nodoc
        * Prints all timers data.
        */
        //static void          DumpAll();
        static void          DumpAll(const CATString & iCaller);

        /**
        * @nodoc
        * Prints a given timer data.
        * @param iLabel Timer label
        */
        //static void          Dump(const CATString & iLabel);
        static void          Dump(const CATString & iLabel, const CATString & iCaller);


        /**
        * @nodoc
        * Gets Cpu and Elapased values of a given timer data.
        * @param iLabel Timer label
        */
        static void          GetTimeValues ( const CATString &iLabel, unsigned long * oCpu, unsigned long * oElapsed );


    private:
        static CATListOfEnoDicTimer _ListTimer;
};

#endif
