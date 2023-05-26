/* -*-c++-*- */
#ifndef CATDebugSweep_H_
#define CATDebugSweep_H_

//-----------------------------------------------------------
//  Sweep Debug controls
//-----------------------------------------------------------
#include "CATString.h"
#include "CATCGMVirtual.h"
#include "CATTrace.h"
#include "BO0SWEEPLight.h"
#include "CATDebugSweepMacros.h" // #define CATDEBUGSWEEP in this file


#define GetTagOrNULL(Geom)         (Geom ? Geom->GetPersistentTag():0)

#ifdef CATDEBUG
#include "CATCloneManager.h"
#include "CATBodyName.h"
#define GETCATDEBUGSWEEP(var)       CATDebugSweep * var = GetCATDebugSweep()
#define TraceLine(Text)             cgmout << Text << cgmendl
#define TraceLineNoRet(Text)        cgmout << Text
#define TraceLineCond(cond, Text)   if (cond)                         TraceLine(Text)
#define TraceNaming(Text)           if (tra->NamingActive())          TraceLine(Text)
#define TraceRelimit(Text)          if (tra->RelimitActive())         TraceLine(Text)
#define TraceRelimitNoRet(Text)     if (tra->RelimitActive())         TraceLineNoRet(Text)
#define TraceRelimitCond(cond,Text) if (cond && tra->RelimitActive()) TraceLine(Text)
#define TraceRelimitCondAlt(cond,Text,AlternateText)                                           \
                                    if (cond && tra->RelimitActive()) TraceLine(Text);         \
                                    else if (tra->RelimitActive())    TraceLine(AlternateText) //
#define TraceSweep(Text)            if (tra->SweepActive())           TraceLine(Text)
#define TraceSweepNoRet(Text)       if (tra->SweepActive())           TraceLineNoRet(Text)
#define TraceTSPC(Text)             if (tra->TspcActive())            TraceLine(Text)
#define RelimitTraceOn             (tra->RelimitActive())
#define GraphTraceOn               (tra->GraphActive())
#define SweepTraceOn               (tra->SweepActive())
#define TSPCTraceOn                (tra->TspcActive())
#define TraceGraph(Text)            if (tra->GraphActive())           TraceLine(Text)
#define TraceGraphNoRet(Text)       if (tra->GraphActive())           TraceLineNoRet(Text)
#define TraceSeparator "-----------------------------------------------------------"
#define TraceKeepNamedBody(factory, by, text)    {}                 \
    {                                                               \
        CATCloneManager  TMPCLONER(factory);                        \
        TMPCLONER.Add(by);                                          \
        TMPCLONER.Run();                                            \
        CATBody  *TMPCOPY = (CATBody *) TMPCLONER.ReadImage(by);    \
        CATUnicodeString   TMPNM(text);                             \
        CATBodyPutName(TMPCOPY, TMPNM);                             \
        TraceLine("Saving " << by->GetPersistentTag() << " to " <<  \
                  TMPCOPY->GetPersistentTag() << " (Name: " <<      \
                  text << " )" );                                   \
    }
#define NamingTraceOn (tra->NamingActive())
//#ifndef GetTagOrNULL(a)

//#endif
#define SAFEJOURNALDUMP(txt,jrl) {TraceLine(txt); (NULL==jrl) ? (cgmout << " NULL journal " << cgmendl) : jrl->Dump(cgmout);}

#define RelimitDumpList(list) {if (RelimitTraceOn) CATSweepRelimit2::Dump(list);}
// Method level trace. Uses data members defined by macros in CATDebugSweepMacros.h
// Cannot be used in static methods.

// This can result in a lot of trace, so certain trivial methods are not instrumented.
// Throws for null pointers are not instrumented either; the object generally gets 
// destroyed so the call levels are cleaned up that way.
#define BEGINFUNC(text) int _Count;                                      \
  if (_onForClass)                                                       \
  {  _CallLevel ++;                                                      \
     for (_Count=0;_Count<_CallLevel;_Count++) {cgmout << "-- ";}        \
     cgmout<<"> ("<<_CallLevel<<") "<<text<<" "<<cgmendl;                \
  }                                                                      \
  GETCATDEBUGSWEEP(tra);                                                //

// (Macro before return from a void-returning method. return to be done manually
//  add NLD191012 for special mkCheckSource issues in which software engineering tools must see "return" in subroutine, not hidden in macro)
#define ENDPROCNORETURN(text)                                            \
   {if (_onForClass)                                                     \
    {                                                                    \
      for (_Count=0;_Count<_CallLevel;_Count++) {cgmout << "-- ";}       \
      cgmout<<" ("<<_CallLevel<<") "<<text<<" "<<cgmendl;                \
      _CallLevel --;                                                     \
    }                                                                    \
  }                                                                      //

// Macro to return from a void-returning method
#define ENDPROC(text)                                                    \
   {ENDPROCNORETURN(text);                                               \
    return;}                                                             //

// Macro to return a value
#define ENDFUNC(returnvalue,text)                                        \
  {                                                                      \
   if (_onForClass)                                                      \
   {                                                                     \
      for (_Count=0;_Count<_CallLevel;_Count++) {cgmout << "-- ";}       \
      cgmout<<" ("<<_CallLevel<<") "<<text<<" "<<cgmendl;                \
      _CallLevel --;                                                     \
   }                                                                     \
  return returnvalue ;                                                   \
 }                                                                       //

// Macro to handle exceptions, and keep call levels OK. 
// THROWFUNC can cause mkCheckSource issues...
#define THROWFUNC(error,text)                                            \
   {if (_onForClass)                                                     \
    {                                                                    \
      for (_Count=0;_Count<_CallLevel;_Count++) {cgmout << "-- ";}       \
      cgmout<<" ("<<_CallLevel<<") "<<text<<" EXIT ON ERROR "<<cgmendl;  \
     _CallLevel --;                                                      \
    }                                                                    \
    CATThrow(error);                                                     \
   };                                                                    //

#else
#define GETCATDEBUGSWEEP(var) //CATDebugSweep* var = GetCATDebugSweep()
#define TraceLine(Text)                              {}
#define TraceLineCond(cond, Text)                    {}
#define TraceLineNoRet(Text)                         {}
#define TraceRelimit(Text)                           {}
#define TraceRelimitNoRet(Text)                      {}
#define TraceRelimitCond(cond,Text)                  {}
#define TraceRelimitCondAlt(cond,Text,AlternateText) {}
#define TraceSweep(Text)                             {}
#define TraceSweepNoRet(Text)                        {}
#define TraceTSPC(Text)                              {}
#define TraceKeepNamedBody(factory, by, text)        {}
#define TraceNaming(Text)                            {}
#define RelimitTraceOn                               0
#define GraphTraceOn                                 0
#define SweepTraceOn                                 0
#define TSPCTraceOn                                  0
#define NamingTraceOn                                0
#define TraceGraph(Text)                             {}
#define TraceGraphNoRet(Text)                        {}
#define TraceSeparator                               ""

#define SAFEJOURNALDUMP(txt,jrl)                     {}
#define RelimitDumpList(list)                        {}

#define BEGINFUNC(text)                             {}
#define ENDPROC(text)                               return;
#define ENDPROCNORETURN(text)                       //
#define ENDFUNC(returnvalue,text)                   return returnvalue;
#define THROWFUNC(error,text)                       CATThrow(error);
#endif

class  CATOldDebugSweep
{
  public :

  //=================================================================
  //   TRACING
  //
  //    => activation :
  //         export CATSWEEPTRACE=tracelevel    before launching process
  //       or
  //         SetTraceLevel(tracelevel)    (0=OFF)
  //=================================================================

  static void SetTraceLevel(int);
  static int  TraceOn;

};

#define CATDEBUGSWEEPNUMBER 7
class ExportedByBO0SWEEPLight CATDebugSweep : public CATCGMVirtual
{
public:
   //=============================================================================
   //  Methods
   //=============================================================================

   //  Constructors, Destructor
   //--------------------------
            CATDebugSweep            ();
            CATDebugSweep            (const CATDebugSweep &);
   virtual ~CATDebugSweep            ();
            CATDebugSweep & operator=(const CATDebugSweep &);

   //  Specific debug access
   //-----------------------
   short      SweepActive();     // Trace category 0
   short      RelimitActive();   // Trace category 1
   short      GraphActive();     // Trace category 2
   short      TspcActive();      // Trace category 3 (ThinSolidProfileClosure)
   short      TspcswActive();    // Trace category 4 (ThinSolidProfileClosure switch for alternative journal constructions)
   short      UseOtherRelimit(); // Trace category 5 (behaviour switch between Relimit2 and Relimit3)
   short      NamingActive();    // Trace category 6

   //  Enable access to strings used for reference
   //---------------------------------------------
   int        GetNumber();
   CATString  GetName(int);
   CATString  GetComment(int);

private:
   static const int _NumberCategories = CATDEBUGSWEEPNUMBER;
   CATTrace   _Traces  [CATDEBUGSWEEPNUMBER];
   CATString  _Names   [CATDEBUGSWEEPNUMBER];
   CATString  _Comments[CATDEBUGSWEEPNUMBER];
};
#undef CATDEBUGSWEEPNUMBER

#endif
