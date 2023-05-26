#ifndef CATMMCSTATCOUNTER_H
#define CATMMCSTATCOUNTER_H

#include "CATUnicodeString.h"
#include "CATMMCTraces.h"
#include "CATMMCTableDump.h"
#include "CATCollec.h"
#include "CATListOfDouble.h"
#include "CATAssert.h"
#include <new>
#include "CATMMCThreadSrv.h"
#include "CATSYPMutexLocker.h"

#include "CATMMediaCore2.h"

#ifdef _WINDOWS_SOURCE
#include <intrin.h>
#endif

/**
 * @nodoc
 * @ingroup groupPotentialSysInfra
 * @class CATMMCStatCount
 * Service that offers to return some statistics between the load and unload of a dll :
 * - the total number of class instances created (and deleted).
 * - the peak number of class instances during the session.
 * And for both, the amount of memory used for a class.
 * 
 * If environment variable CAT_MMC_COUNTER_DEBUG_POINTERS=1, traces are added to check remaining classes not destroyed at dll unload.
 * 
 * It is possible to agregate the results of multiple classes to find the maximum amount of memory used by the different classes at a time.
 * On this aggregator, the aggregated instance counters fill the information, and it is possible to add and remove manually some amount of memory.
 *
 * e.g.:
 *      
 *      Preceded by creation and desctruction
        all along the scenario  : can be activated by "set CAT_MMC_STAT_COUNTER=Full"
 *        ...
 *        Add: [Idx:1]0x000001D556612950 [CATPixelImage.{512x512,L}]                 ----------------------------------|
 *        Add: [Idx:1]0x000001D54149A490 [lCATPixelImage]              ----------------------------------------------- | -------|
 *        Add: [Idx:1]0x000001D545318420 [CATMMPIPixelColorSpec]                                                       |        |
 *        Add: [Idx:1]0x000001D553CC1D00 [CATMMPIColorSpace]                                                           |        |
 *        Add: [Idx:1]0x000001D554256CD0 [CATMMPISpec]            ---------------------------------------------------- | ---|   |
 *        Add: [Idx:2]0x000001D556658350 [CATMMPIPixelColorSpec]                                                       |    |   |
 *        Add: [Idx:2]0x000001D553CC1040 [CATMMPIColorSpace]                                                           |    |   |
 *        Add: 0x000001D556AD7800 sz: 256 Ko                 ----------------------------|                             |    |   |
 *        Add: [Idx:1]0x000001D553ABEC60 [CATMMPIBuffer]                                 |                             |    |   |
 *        Rm : 0x000001D553ABEC60 [CATMMPIBuffer]                                        |                             |    |   |
 *        Add: [Idx:2]0x000001D556611990 [CATPixelImage.{7x8,L}]                         |                             |    |   |
 *        Add: [Idx:2]0x000001D553ABE9A0 [lCATPixelImage]                                |                             |    |   |
 *        Add: [Idx:2]0x000001D554256F70 [CATMMPISpec]                                   |                             |    |   |
 *        Add: [Idx:3]0x000001D5566584C0 [CATMMPIPixelColorSpec]                         |                             |    |   |
 *        Add: [Idx:3]0x000001D553CC0920 [CATMMPIColorSpace]                             |                             |    |   |
 *        Add: 0x000001D553ABE420 sz: 56  o                                              |                             |    |   |
 *        Rm : 0x000001D56AADC2F0 [CATMMPIBuffer]                                        |                             |    |   |
 *        Rm : 0x000001D556612950 [CATPixelImage]                ----------------------- | ----------------------------|    |   |
 *        Rm : 0x000001D556AD7800                  --------------------------------------|                                  |   |
 *        Rm : 0x000001D554256CD0 [CATMMPISpec]         --------------------------------------------------------------------|   |
 *        Rm : 0x000001D54149A490 [lCATPixelImage]                --------------------------------------------------------------|
 *        ...
 *
 *  At destruction of counter aggregator :
 *      #############################################################################MMCStatCounter##
 *      #### Class name            # Peak count / total session # Peak size # Leak ##MMCStatCounter##       \
 *      #### CATMMPIPixelColorSpec #                    / 8             #              0  o #    8 ##MMCStatCounter##        |
 *      #### CATMMPIColorSpace     #                    / 8             #              0  o #    8 ##MMCStatCounter##        |
 *      #### CATMMPIBuffer         #                    /               #              0  o #      ##MMCStatCounter##        |
 *      #### CATMMPISpec           #                  8 / 25            #            320  o #    5 ##MMCStatCounter##         > Followed classes           : DefineCATCOUNTANDSIZE(CATPixelImage,__CATPixelImageCounter,__StatAgreg); +                 __CATPixelImageCounter.Add() + __CATPixelImageCounter.Rm()            
 *      #### CATImageBuffer        #                    /               #              0  o #      ##MMCStatCounter##        |                                                                                                                                                       OR 
 *      #### lCATPixelImage        #                  3 / 20            #             96  o #      ##MMCStatCounter##        |                                                                                                          CATMMCStatCounterADD(__CATPixelImageCounter) + CATMMCStatCounterRM(__CATPixelImageCounter)
 *      #### CATPixelImage         #                  3 / 20            #            408  o #      ##MMCStatCounter##       /                   
 *      #### PixelImage stats      #            /               #   5403 Ko #      ##MMCStatCounter##  <= Aggregation of memory consumption : DefineDBLCOUNTER(__StatAgreg,"PixelImage stats");                 (    + xxx_Tra_CountSzNew(__StatAgreg,Class,Size,Pointer,AdditionalTraces) + yyy_CountSzDel(__StatAgreg,Pointer)    )
 *      #############################################################################MMCStatCounter##
 *
 *      Followed by creation and desctruction all along the scenario  : can be activated by "set CAT_MMC_STAT_COUNTER=Full"
 *
 *
 * Threadsafe : No.
 *                
 * Prereqs    :   IdentityCard requires MultimeidaPixelImage
 *                Imakefile.mk requires to LINK_WITH to CATMMediaCore2
 *               *The results are available only when compiling using the **-dev** command line option of mkmk.*
 *                
 * Limitations:   Size information requires DefineDBLCOUNTER agregator.
 * 
 * To follow up leaks of a class, you can set the variable 
 *     set CAT_MMC_STAT_COUNTER=myClassName1 myClassName2 ...           to dump construction and destruction of classes.
 *     set CAT_MMC_STAT_COUNTER=Full                                    to dump all construction and destruction.
 *     set CAT_MMC_STAT_COUNTER=No                                      No process at all.
 *     set CAT_MMC_STAT_COUNTER=NoDump                                  Process but does not to dump the table.
 *     set CAT_MMC_STAT_COUNTER=NoErr                                   Dump resulting table but removes errors.
 *
 *   Instance kept in static variable may ont be considered as leak (by mkCheckSource?).
 *
 * @brief Service for instance counter, leaks, statistics of count and memory size of instances.
*/

enum CATMMCStatCounterDbg {
  DBG_No          ,
                            DBG_HideErrors   ,
                            DBG_Yes          ,
                            DBG_NoDump       ,
  DBG_MemoryCheck ,
                            DBG_WithPointers
                          };
ExportedByCATMMediaCore2 CATMMCStatCounterDbg GetDebugOptions(CATUnicodeString specificValue = CATUnicodeString(""));
ExportedByCATMMediaCore2 const char* DumpDebugOptions();

#ifndef CNEXT_CLIENT

#include <iostream>

class CATMMCStatCounterItf
{
public:
  /**
   * To declare the derivated counter to be added.
   */
  virtual void AddClient(CATMMCStatCounterItf*iptr)           = 0;
  /**
   * Manage the trigger of finalization of all global and derivated counters and from either the global or the derivated counters.
   */
  virtual void CloseStat(CATMMCStatCounterItf* ipClient=NULL) = 0;
  /**
  * Request the counter to build the report.
  */
  virtual void AddSummary()                                   = 0;
  /**
   * Building the report.
   */
  virtual void AddSummary(const CATUnicodeString &classname, const CATUnicodeString &otherStaticInfo, CATUnicodeString maxSimultaneousInstance, const CATUnicodeString &totalCreatedInstance, const CATUnicodeString &maxSimultaneousUsedMemory, const CATUnicodeString &uNbLeaked) = 0;
};

template<typename T>
class CATMMCStatCounter : public CATMMCStatCounterItf {
public:
  enum DoneActions { DA_Summary, DA_Close };
  virtual void AddClient(CATMMCStatCounterItf*iptr) {
    if(GetDebugOptions() == DBG_No)
      return;
    _lstClients.Append(iptr);
    _hasClient=true;
  };
  virtual void CloseStat(CATMMCStatCounterItf* ipClient=NULL) {
    if(GetDebugOptions() == DBG_No)
      return;
    if(!(_done&DA_Close))
    {
      if(_pSizeCounter)
      {
        AddSummary();
        _pSizeCounter->CloseStat(this);
      }

      if(_lstClients.Size())
      {
        if(ipClient)
          _lstClients.RemoveValue(ipClient);

        int i=_lstClients.Size();
        for(i=_lstClients.Size(); i>=1; i--)
        {
          CATMMCStatCounterItf* pSCter = (CATMMCStatCounterItf*)(_lstClients[i]);
          if (pSCter)
          {
            pSCter->AddSummary();
            _lstClients.RemoveValue(pSCter);
          }
        }
        AddSummary();
      }

      if(!_pSizeCounter)
      {
        if(GetDebugOptions()!=DBG_NoDump)
        {
          std::cout << "########################################################################################MMCStatCounter##" << std::endl;
          std::cout << _tbl.Dump().ConvertToChar() << std::endl;
          std::cout << "########################################################################################MMCStatCounter##" << std::endl;
        }
        int i = _lstPtr.Size();
        if (GetDebugOptions()!=DBG_WithPointers)
          i = 0;
        for (; i>0; i--)
        {
          _lstErr.Append(CATMMCTraces::DumpPointer(_lstPtr[i])).Append("[").Append(_counterName).Append("]");
          _lstErr.Append("   <=== Error: Remaining pointer.\n");
        }
        if(GetDebugOptions()!=DBG_NoDump)
        {
          if (GetDebugOptions() != DBG_HideErrors)
            std::cout << _lstErr.ConvertToChar() ;
        }
      }

      _pSizeCounter = NULL;
      _done|=DA_Close;
    }
  };
  virtual void AddSummary() {
    if(GetDebugOptions() == DBG_No)
      return;
    if (!(_done&DA_Summary))
    {
      CATUnicodeString                 classname(_counterName);
      CATUnicodeString                 otherStaticInfo(_counterStaticInfo);
      CATUnicodeString   maxSimultaneousInstance;if(!_hasClient&&_ConcurrentMax) maxSimultaneousInstance.BuildFromNum(_ConcurrentMax);
      CATUnicodeString      totalCreatedInstance;if(!_hasClient&&_TotalUse)         totalCreatedInstance.BuildFromNum(_TotalUse);
      CATUnicodeString maxSimultaneousUsedMemory(CATMMCTraces::GetSizeWithUnit(_ConcurrentMax * _unitsize));
      CATUnicodeString                 uNbLeaked;if(!_hasClient&&_Concurrent)                  uNbLeaked.BuildFromNum(_Concurrent);
      if (_pSizeCounter)
        _pSizeCounter->AddSummary(classname, otherStaticInfo, maxSimultaneousInstance, totalCreatedInstance, maxSimultaneousUsedMemory,uNbLeaked);
      else
        AddSummary(classname, otherStaticInfo, maxSimultaneousInstance, totalCreatedInstance, maxSimultaneousUsedMemory,uNbLeaked);
      _done |= DA_Summary;
    }
  };
  virtual void AddSummary(const CATUnicodeString &classname, const CATUnicodeString &otherStaticInfo, CATUnicodeString maxSimultaneousInstance, const CATUnicodeString &totalCreatedInstance, const CATUnicodeString &maxSimultaneousUsedMemory, const CATUnicodeString &uNbLeaked) {
    if(GetDebugOptions() == DBG_No)
      return;
    _tbl.NextRow();
    _tbl.AddToColumn( 1, "####");
    _tbl.AddToColumn( 2, classname);
    _tbl.AddToColumn( 3, otherStaticInfo);
    _tbl.AddToColumn( 4, "#");
    _tbl.AddToColumn( 5, maxSimultaneousInstance);
    _tbl.AddToColumn( 6, "/");
    _tbl.AddToColumn( 7, totalCreatedInstance);
    _tbl.AddToColumn( 8, "#");
    _tbl.AddToColumn( 9, maxSimultaneousUsedMemory);
    _tbl.AddToColumn(10, "#");
    _tbl.AddToColumn(11, uNbLeaked);
    _tbl.AddToColumn(12, "##MMCStatCounter##");
  };

  //                                             global counter       derivated counter
  CATUnicodeString          _counterName;      //      1                       1
  CATUnicodeString          _counterStaticInfo;//      1                       1
  size_t                    _unitsize;         //      1                       1
  T                         _Concurrent;       //      1                       1
  T                         _ConcurrentMax;    //      1                       1
  T                         _TotalUse;         //      1                       1
  int                       _done;             //      1                       1
  CATMMCTableDump           _tbl;              //      1                       1
  CATListPV                 _lstClients;       //      1                        
  CATMMCStatCounterItf*     _pSizeCounter;     //                              1
  bool                      _hasClient;

  //Debug purpose
  CATListPV                 _lstPtr;           // Follow up of initialized pointers
  CATListOfDouble           _ptrSz;            //           with their corresponding size
  CATUnicodeString          _lstErr;           // The history of added and removed objects.

private:
  CATListOfCATUnicodeString _lstTraces;

public:
  CATMMCStatCounter(const char* iclassname,
                    const char* iOtherStaticInfo=NULL,
                    size_t iUnitSize = 1,
                    CATMMCStatCounterItf* ipBaseCounter = NULL) :
      _counterName(iclassname), _counterStaticInfo(iOtherStaticInfo), _unitsize(iUnitSize), _pSizeCounter(ipBaseCounter), _hasClient(false), _ConcurrentMax(0), _Concurrent(0), _TotalUse(0), _tbl(), _done(false) {
    _lstTraces.Append("Class name");
    _lstTraces.Append("Peak count");
    _lstTraces.Append("Total session");
    _lstTraces.Append("Peak size");
  //_lstTraces.Append("Letter"   );
  //_lstTraces.Append("InfoData" );
  //_lstTraces.Append("Shareable");
  //_lstTraces.Append("Shared"   );
  //_lstTraces.Append("Buffer"   );
                                                _tbl.AddToColumn( 1, "####");
    _tbl.AddColumn();                           _tbl.AddToColumn( 2, "Class name");
    _tbl.AddColumn();                           _tbl.AddToColumn( 3, "   Info   ");
    _tbl.AddColumn();                           _tbl.AddToColumn( 4, "#");
    _tbl.AddColumn(CATMMCTableDump::TDA_Right); _tbl.AddToColumn( 5, "Peak count");
    _tbl.AddColumn();                           _tbl.AddToColumn( 6, "/");
    _tbl.AddColumn();                           _tbl.AddToColumn( 7, "total session");
    _tbl.AddColumn();                           _tbl.AddToColumn( 8, "#");
    _tbl.AddColumn(CATMMCTableDump::TDA_Right); _tbl.AddToColumn( 9, "Peak size");
    _tbl.AddColumn();                           _tbl.AddToColumn(10, "#");
    _tbl.AddColumn(CATMMCTableDump::TDA_Right); _tbl.AddToColumn(11, "Leak");
    _tbl.AddColumn();                           _tbl.AddToColumn(12, "##MMCStatCounter##");
  //_tbl._columnSeparator = " # ";
    if(_pSizeCounter)
      _pSizeCounter->AddClient(this);
  };
  virtual ~CATMMCStatCounter() {
    if(GetDebugOptions() == DBG_No)
      return;
    CloseStat();
  };
  void         Add(T iVal = 1) {
    if(GetDebugOptions()==DBG_No) return;
  //CATUnicodeString trace("Add: "); trace.Append(CATMMCTraces::DumpPointer(iptr)).Append(" [").Append(_counterName).Append("]");
  //if (GetDebugOptions(_counterName))
  //  cout << trace.ConvertToChar() << endl;
    _Concurrent += iVal; if (_ConcurrentMax<_Concurrent) _ConcurrentMax = _Concurrent; _TotalUse += iVal;
  };
  void         Rm(T iVal = 1) {
    if(GetDebugOptions()==DBG_No) return;
  //CATUnicodeString trace("Rm : "); trace.Append(CATMMCTraces::DumpPointer(iptr)).Append(" [").Append(_counterName).Append("]");
  //if (GetDebugOptions(_counterName))
  //  cout << trace.ConvertToChar() << endl;
    _Concurrent -= iVal;
  };
  void         Add(void* iptr, T iVal = 1, const char* iAdditionalTraces=NULL) {
    if(GetDebugOptions()==DBG_No) return; 
    if(!iptr)
      return;
    int i = _lstPtr.Locate(iptr);
    if(GetDebugOptions(_counterName)==DBG_WithPointers || i > 0)
    {
      CATUnicodeString trace("Add: ");
      trace.Append(CATMMCTraces::DumpPointer(iptr));
      trace.Append(" sz: ");
      trace.Append(CATMMCTraces::GetSizeWithUnit(iVal));
      //if(GetDebugOptions(_counterName)==DBG_MemoryCheck)
      //{
      //void* ptr = iptr;
      //ptr = static_cast<char*>(ptr) + (iVal - 1);
      //trace.Append(" last address: ");
      //trace.Append(CATMMCTraces::DumpPointer(ptr));
      //}
      if(i  > 0) {
        trace.Append("   <=== Error: Pointer ").Append(_counterName).Append(" already exists.\n");
        if (iAdditionalTraces)
          trace.Append(" [").Append(iAdditionalTraces).Append("]");
        if(GetDebugOptions() != DBG_HideErrors)
          std::cout << trace.ConvertToChar();
        _lstErr.Append(trace);
        return;
      };
      if(iAdditionalTraces)
        trace.Append(" [").Append(iAdditionalTraces).Append("]");
      {
        CATMutex m;
        {
          CATSYPMutexLocker mutexLocker(m);
          CATMMCThreadSrv::CheckNotMainThreadNoMutex();
        }
      }
      trace.Append("\n");
      if (GetDebugOptions() != DBG_HideErrors)
        std::cout << trace.ConvertToChar();
      _lstErr.Append(trace);
    }
    _lstPtr.Append(iptr);
    _ptrSz.Append(iVal);
    _Concurrent += iVal;
    _TotalUse += iVal;
  };
  void         Rm(void* iptr, const char* iAdditionalTraces = NULL)              {
    if(GetDebugOptions()==DBG_No) return; 
    if (!iptr)
      return;
    int i = _lstPtr.Locate(iptr);
    if(GetDebugOptions(_counterName)==DBG_WithPointers || i == 0)
    {
      CATUnicodeString trace("Rm : ");
      trace.Append(CATMMCTraces::DumpPointer(iptr));
      if(i == 0)
      {
        trace.Append("   <=== Error: pointer initialization not found.\n");
        if (iAdditionalTraces)
          trace.Append(" [").Append(iAdditionalTraces).Append("]");
        if(GetDebugOptions() != DBG_HideErrors)
          std::cout << trace.ConvertToChar();
        _lstErr.Append(trace);
        return;
      };
      if(iAdditionalTraces)
        trace.Append(" [").Append(iAdditionalTraces).Append("]");
      trace.Append("\n");
      std::cout << trace.ConvertToChar();
      _lstErr.Append(trace);
    }
    if(_ConcurrentMax < _Concurrent)
      _ConcurrentMax = _Concurrent;
    _Concurrent -= _ptrSz[i];
    _lstPtr.RemovePosition(i); _ptrSz.RemovePosition(i);
  };
};

typedef CATMMCStatCounter<unsigned int> CATMMCStatCounterUInt;
typedef CATMMCStatCounter<double>       CATMMCStatCounterDouble;

#define CATCOUNTANDSIZE(Class,Info)                                                                                                                                                   \
class CATCOUNTANDSIZE##Class {                                                                                                                  \
public:                                                                                                                                         \
  CATCOUNTANDSIZE##Class(CATMMCStatCounterDouble *ipSizeCounter=NULL, const char* iStatInfo=NULL):_count(#Class,Info,sizeof(Class),ipSizeCounter),_pSizeCounter(ipSizeCounter) {      \
  };                                                                                                                                            \
  ~CATCOUNTANDSIZE##Class() {                                                                                                                   \
  };                                                                                                                                            \
  void Add() {                                                                                                                                  \
    if(GetDebugOptions()==DBG_No) return;                                                                                                       \
    _count.Add();                                                                                                                               \
    if(_pSizeCounter)                                                                                                                           \
    {                                                                                                                                           \
      _pSizeCounter->Add(sizeof(Class));                                                                                                        \
    }                                                                                                                                           \
  };                                                                                                                                            \
  void Rm() {                                                                                                                                   \
    if(GetDebugOptions()==DBG_No) return;                                                                                                       \
    _count.Rm();                                                                                                                                \
    if(_pSizeCounter)                                                                                                                           \
    {                                                                                                                                           \
      _pSizeCounter->Rm(sizeof(Class));                                                                                                         \
    }                                                                                                                                           \
  };                                                                                                                                            \
                                                                                                                                                \
  CATMMCStatCounterUInt    _count;                                                                                                              \
  CATMMCStatCounterDouble *_pSizeCounter;                                                                                                       \
}
#define DefineDBLCOUNTER(Name,Info,Description) CATMMCStatCounterDouble Name(Description,Info)
#define DefineCATCOUNTANDSIZE3(Class,Info,Name) CATCOUNTANDSIZE(Class,Info) Name(NULL,NULL)
#define DefineCATCOUNTANDSIZE(Class,Info,Name,RefCounter) CATCOUNTANDSIZE(Class,Info) Name(&RefCounter)
#define DeclareDBLCOUNTER CATMMCStatCounterDouble
#define TypeDBLCOUNTER CATMMCStatCounterDouble
#define DeclareExternDBLCOUNTER(Name) extern CATMMCStatCounterDouble Name
#define DeclareExternCATCOUNTANDSIZE(Class,Name) extern CATCOUNTANDSIZE(Class,NULL) Name

#define CATMMCStatCounterADD(CounterInst)                     do{CounterInst.Add();if(DBG_WithPointers==GetDebugOptions(CounterInst._count._counterName)){CATUnicodeString trace("Add: [Idx:"); CATUnicodeString val;val.BuildFromNum(CounterInst._count._TotalUse);trace.Append(val); trace.Append("]"); trace.Append(CATMMCTraces::DumpPointer(this)).Append(" [").Append(CounterInst._count._counterName                                                                                                                                                                  ).Append("]");std::cout << trace.ConvertToChar() << std::endl;}}while(0)
#define CATMMCStatCounterADDBU(CounterInst)                   do{CounterInst.Add();if(DBG_WithPointers==GetDebugOptions(CounterInst._count._counterName)){CATUnicodeString trace("Add: [Idx:"); CATUnicodeString val;val.BuildFromNum(CounterInst._count._TotalUse);trace.Append(val); trace.Append("]"); trace.Append(CATMMCTraces::DumpPointer(this)).Append(" [").Append(CounterInst._count._counterName).Append(".");CATUnicodeString typBU(IsA());if(2!=typBU.Compare(CounterInst._count._counterName))trace.Append(",IsA:").Append(typBU);                         trace.Append("]");std::cout << trace.ConvertToChar() << std::endl;}}while(0)
#define CATMMCStatCounterADD2(CounterInst,AdditionalTraces)   do{CounterInst.Add();if(DBG_WithPointers==GetDebugOptions(CounterInst._count._counterName)){CATUnicodeString trace("Add: [Idx:"); CATUnicodeString val;val.BuildFromNum(CounterInst._count._TotalUse);trace.Append(val); trace.Append("]"); trace.Append(CATMMCTraces::DumpPointer(this)).Append(" [").Append(CounterInst._count._counterName).Append("."                                                                                                                             ).Append(AdditionalTraces).Append("]");std::cout << trace.ConvertToChar() << std::endl;}}while(0)
#define CATMMCStatCounterADDBU2(CounterInst,AdditionalTraces) do{CounterInst.Add();if(DBG_WithPointers==GetDebugOptions(CounterInst._count._counterName)){CATUnicodeString trace("Add: [Idx:"); CATUnicodeString val;val.BuildFromNum(CounterInst._count._TotalUse);trace.Append(val); trace.Append("]"); trace.Append(CATMMCTraces::DumpPointer(this)).Append(" [").Append(CounterInst._count._counterName).Append(".");CATUnicodeString typBU(IsA());if(2!=typBU.Compare(CounterInst._count._counterName))trace.Append(",IsA:").Append(typBU);trace.Append(AdditionalTraces).Append("]");std::cout << trace.ConvertToChar() << std::endl;}}while(0)
#define CATMMCStatCounterRM(CounterInst)                      do{CounterInst.Rm(); if(DBG_WithPointers==GetDebugOptions(CounterInst._count._counterName)){CATUnicodeString trace("Rm : "); trace.Append(CATMMCTraces::DumpPointer(this)).Append(" [").Append(CounterInst._count._counterName                                     ).Append("]");std::cout << trace.ConvertToChar() << std::endl;}}while(0)
#define CATMMCStatCounterRM2(CounterInst,AdditionalTraces)    do{CounterInst.Rm(); if(DBG_WithPointers==GetDebugOptions(CounterInst._count._counterName)){CATUnicodeString trace("Rm : "); trace.Append(CATMMCTraces::DumpPointer(this)).Append(" [").Append(CounterInst._count._counterName).Append(".").Append(AdditionalTraces).Append("]");std::cout << trace.ConvertToChar() << std::endl;}}while(0)

#else

#define CATCOUNTANDSIZE(Class)                                                                                                                  \
class CATCOUNTANDSIZE##Class {                                                                                                                  \
public:                                                                                                                                         \
  CATCOUNTANDSIZE##Class(){                                                                                                                     \
  };                                                                                                                                            \
  ~CATCOUNTANDSIZE##Class() {                                                                                                                   \
  };                                                                                                                                            \
  void Add() {                                                                                                                                  \
  };                                                                                                                                            \
  void Add(int t) {                                                                                                                             \
  };                                                                                                                                            \
  void Add(void* iptr, int v, const char* c=NULL) {                                                                                             \
  };                                                                                                                                            \
  void Rm() {                                                                                                                                   \
  };                                                                                                                                            \
  void Rm(int t) {                                                                                                                              \
  };                                                                                                                                            \
  void Rm(void* iptr, const char* c=NULL) {                                                                                                     \
  };                                                                                                                                            \
}
#define DefineDBLCOUNTER(Name,Info,Description) CATCOUNTANDSIZE(Double) Name
#define DefineCATCOUNTANDSIZE3(Class,Info,Name) CATCOUNTANDSIZE(Class) Name
#define DefineCATCOUNTANDSIZE(Class,Info,Name,RefCounter) CATCOUNTANDSIZE(Class) Name
#define DeclareDBLCOUNTER CATCOUNTANDSIZE(Double)
#define TypeDBLCOUNTER CATCOUNTANDSIZEDouble
#define DeclareExternDBLCOUNTER(Name) extern CATCOUNTANDSIZE(Double) Name
#define DeclareExternCATCOUNTANDSIZE(Class,Name) extern CATCOUNTANDSIZE(Class) Name

#define CATMMCStatCounterADD(CounterInst)                    do{}while(0)
#define CATMMCStatCounterADD2(CounterInst,AdditionalTraces)  do{}while(0)
#define CATMMCStatCounterADDBU(CounterInst)                  do{}while(0)
#define CATMMCStatCounterADDBU2(CounterInst,AdditionalTraces)do{}while(0)
#define CATMMCStatCounterRM(CounterInst)                     do{}while(0)
#define CATMMCStatCounterRM2(CounterInst,AdditionalTraces)   do{}while(0)

#endif

enum CATMMCSizeDesc {
  mmcSC_Letter    = 0x01, // size of CATPixelImage + letter
  mmcSC_InfoData  = 0x02, // include required additionnal information
  mmcSC_Shareable = 0x04, // include shareable data
  mmcSC_Shared    = 0x08, // include shared data
  mmcSC_Buffer    = 0x10  // include buffer
};

#define                        CountSzNew(Tracer,Class,Size,Pointer)                                                                                                        do{ Tracer.Add(Pointer,Size*sizeof(Class),NULL);                                                      }while(0)
#define                    New_CountSzNew(Tracer,Class,Size,Pointer)                                 if(!Size){ Pointer=NULL; }  else { Pointer=new          Class[Size]; } do{ Tracer.Add(Pointer,Size*sizeof(Class),NULL);                                                      }while(0)
#define                New_Opt_CountSzNew(Tracer,Class,Size,Pointer,Option)                          if(!Size){ Pointer=NULL; }  else { Pointer=new (Option) Class[Size]; } do{ Tracer.Add(Pointer,Size*sizeof(Class),NULL);                                                      }while(0)
#define               Decl_New_CountSzNew(Tracer,Class,Size,Pointer)                                     Class* Pointer=NULL; if(Size){ Pointer=new          Class[Size]; } do{ Tracer.Add(Pointer,Size*sizeof(Class),NULL);                                                      }while(0)
#define           Decl_New_Opt_CountSzNew(Tracer,Class,Size,Pointer,Option)                              Class* Pointer=NULL; if(Size){ Pointer=new (Option) Class[Size]; } do{ Tracer.Add(Pointer,Size*sizeof(Class),NULL);                                                      }while(0)
#define               New_MSet_CountSzNew(Tracer,Class,Size,Pointer,DftVal)                          if(!Size){ Pointer=NULL; }  else { Pointer=new          Class[Size]; } do{ Tracer.Add(Pointer,Size*sizeof(Class),NULL);             if(Pointer) memset(Pointer,DftVal,Size); }while(0)
#define           New_Opt_MSet_CountSzNew(Tracer,Class,Size,Pointer,Option,DftVal)                   if(!Size){ Pointer=NULL; }  else { Pointer=new (Option) Class[Size]; } do{ Tracer.Add(Pointer,Size*sizeof(Class),NULL);             if(Pointer) memset(Pointer,DftVal,Size); }while(0)
#define          Decl_New_MSet_CountSzNew(Tracer,Class,Size,Pointer,DftVal)                              Class* Pointer=NULL; if(Size){ Pointer=new          Class[Size]; } do{ Tracer.Add(Pointer,Size*sizeof(Class),NULL);             if(Pointer) memset(Pointer,DftVal,Size); }while(0)
#define      Decl_New_Opt_MSet_CountSzNew(Tracer,Class,Size,Pointer,Option,DftVal)                       Class* Pointer=NULL; if(Size){ Pointer=new (Option) Class[Size]; } do{ Tracer.Add(Pointer,Size*sizeof(Class),NULL);             if(Pointer) memset(Pointer,DftVal,Size); }while(0)
#define                    Tra_CountSzNew(Tracer,Class,Size,Pointer,AdditionalTraces)                                                                                       do{ Tracer.Add(Pointer,Size*sizeof(Class),AdditionalTraces);                                          }while(0)
#define                New_Tra_CountSzNew(Tracer,Class,Size,Pointer,AdditionalTraces)                if(!Size){ Pointer=NULL; }  else { Pointer=new          Class[Size]; } do{ Tracer.Add(Pointer,Size*sizeof(Class),AdditionalTraces);                                          }while(0)
#define            New_Opt_Tra_CountSzNew(Tracer,Class,Size,Pointer,Option,AdditionalTraces)         if(!Size){ Pointer=NULL; }  else { Pointer=new (Option) Class[Size]; } do{ Tracer.Add(Pointer,Size*sizeof(Class),AdditionalTraces);                                          }while(0)
#define           Decl_New_Tra_CountSzNew(Tracer,Class,Size,Pointer,AdditionalTraces)                    Class* Pointer=NULL; if(Size){ Pointer=new          Class[Size]; } do{ Tracer.Add(Pointer,Size*sizeof(Class),AdditionalTraces);                                          }while(0)
#define       Decl_New_Opt_Tra_CountSzNew(Tracer,Class,Size,Pointer,Option,AdditionalTraces)             Class* Pointer=NULL; if(Size){ Pointer=new (Option) Class[Size]; } do{ Tracer.Add(Pointer,Size*sizeof(Class),AdditionalTraces);                                          }while(0)
#define           New_MSet_Tra_CountSzNew(Tracer,Class,Size,Pointer,DftVal,AdditionalTraces)         if(!Size){ Pointer=NULL; }  else { Pointer=new          Class[Size]; } do{ Tracer.Add(Pointer,Size*sizeof(Class),AdditionalTraces); if(Pointer) memset(Pointer,DftVal,Size); }while(0)
#define       New_Opt_MSet_Tra_CountSzNew(Tracer,Class,Size,Pointer,Option,DftVal,AdditionalTraces)  if(!Size){ Pointer=NULL; }  else { Pointer=new (Option) Class[Size]; } do{ Tracer.Add(Pointer,Size*sizeof(Class),AdditionalTraces); if(Pointer) memset(Pointer,DftVal,Size); }while(0)
#define      Decl_New_MSet_Tra_CountSzNew(Tracer,Class,Size,Pointer,DftVal,AdditionalTraces)             Class* Pointer=NULL; if(Size){ Pointer=new          Class[Size]; } do{ Tracer.Add(Pointer,Size*sizeof(Class),AdditionalTraces); if(Pointer) memset(Pointer,DftVal,Size); }while(0)
#define  Decl_New_Opt_MSet_Tra_CountSzNew(Tracer,Class,Size,Pointer,Option,DftVal,AdditionalTraces)      Class* Pointer=NULL; if(Size){ Pointer=new (Option) Class[Size]; } do{ Tracer.Add(Pointer,Size*sizeof(Class),AdditionalTraces); if(Pointer) memset(Pointer,DftVal,Size); }while(0)

          
#define                        CountSzDel(Tracer,Pointer)                  do{ if(Pointer) { Tracer.Rm(Pointer,NULL);                                             } }while(0)
#define                 DelTab_CountSzDel(Tracer,Pointer)                  do{ if(Pointer) { Tracer.Rm(Pointer,NULL);             delete[] Pointer;               } }while(0)
#define              SysDelTab_CountSzDel(Tracer,Pointer)                  do{ if(Pointer) { Tracer.Rm(Pointer,NULL);             delete[] Pointer; Pointer=NULL; } }while(0)
#define                    Tra_CountSzDel(Tracer,Pointer,AdditionalTraces) do{ if(Pointer) { Tracer.Rm(Pointer,AdditionalTraces);                                 } }while(0)
#define             DelTab_Tra_CountSzDel(Tracer,Pointer,AdditionalTraces) do{ if(Pointer) { Tracer.Rm(Pointer,AdditionalTraces); delete[] Pointer;               } }while(0)
#define          SysDelTab_Tra_CountSzDel(Tracer,Pointer,AdditionalTraces) do{ if(Pointer) { Tracer.Rm(Pointer,AdditionalTraces); delete[] Pointer; Pointer=NULL; } }while(0)

class CATMMCArrayBoundReached {
public:
  CATMMCArrayBoundReached(char* iStart, size_t iBufferSize):_pStart(iStart), _pEnd(NULL), _length(iBufferSize){if(iBufferSize)_pEnd=_pStart+iBufferSize;};
  ~CATMMCArrayBoundReached()                                                                                  { _pStart=NULL;};
  void FullyInclude(char* iptr2Test, size_t length = 1)                                                       {
#ifndef CNEXT_CLIENT
#ifdef _WINDOWS_SOURCE
    if (IsDebuggerPresent()) {
      if (      iptr2Test           <   _pStart           )
        DebugBreak();
      else if ( iptr2Test           >= (_pStart + _length)) //A revoir
        DebugBreak();
      else if ((iptr2Test + length) >  (_pStart + _length)) //A revoir
        DebugBreak();
    }
#endif
#endif 
  };
private:
  CATMMCArrayBoundReached();
  char  *_pStart,*_pEnd;
  size_t _length;
};
#endif
  
