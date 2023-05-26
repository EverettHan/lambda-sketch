// COPYRIGHT Dassault Systemes 2005
//===================================================================
/**
* @level Protected
* @usage U1
*/

// To manage dependency with OMB
#define CATOmyBackgroundServices_V2

#ifndef CATOmyBackgroundServices_V1
#define CATOmyBackgroundServices_V1

#include "CATOmyAsyncInterfaces.h"
#include "CATOmxSharable.h"
#include "CATBoolean.h"
#include "CATOmxSR.h"
#include "CATUnicodeString.h"

class CATEvent;
class DSYSysPath;

class ExportedByCATOmyAsyncInterfaces CATOmyBackgroundResult : public CATOmxSharable
{
public:
  CATBoolean IsCompleted();
  /**
  * E_INVALIDARG : Task not stated
  * E_PENDING : Task is running
  * Otherwise : Task has completed with returned status 
  */
  HRESULT IsSuccess();  
  HRESULT WaitForCompletion();
  CATOmyBackgroundResult();

private : 
  ~CATOmyBackgroundResult();
  void Done(HRESULT iHR);
  void IsRunning(); 
  HRESULT _TaskStatus;
  CATBoolean _HasEnded;
  CATEvent* _pEndEvent;
  

friend class CATOmyBackgroundServices;
friend class MyBackwardTask;

};

class ExportedByCATOmyAsyncInterfaces CATOmyBackgroundServices
{
  /*
  *
  XXXXXX   XXXXX            XX   XX   XXXXX    XXXXXX            XX  XX   XXXXXX  XXXXXXX
  XX  XX  XX   XX           XXX  XX  XX   XX   X XX X            XX  XX  XX    X   XX   X
  XX  XX  XX   XX           XXXX XX  XX   XX     XX              XX  XX  XX        XX X
  XX  XX  XX   XX           XX XXXX  XX   XX     XX              XX  XX   XXXXX    XXXX
  XX  XX  XX   XX           XX  XXX  XX   XX     XX              XX  XX       XX   XX X
  XX  XX  XX   XX           XX   XX  XX   XX     XX              XX  XX  X    XX   XX   X
  XXXXXX   XXXXX            XX   XX   XXXXX     XXXX              XXXX   XXXXXX   XXXXXXX

  This class is just a prototype and Exposed API will be changed to follow the Logical/Physical Task Pattern
  *
  */

public:
  
  CATOmyBackgroundServices();
  ~CATOmyBackgroundServices();

  HRESULT CopyDictionaryAsync(DSYSysPath& iSourceDir, DSYSysPath& iDestDir,CATOmxSR<CATOmyBackgroundResult>& ohFutureResult);  
    
};

#endif


