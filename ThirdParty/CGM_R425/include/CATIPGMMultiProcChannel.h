#ifndef CATIPGMMultiProcChannel_h_
#define CATIPGMMultiProcChannel_h_

// COPYRIGHT DASSAULT SYSTEMES 2020

#include "CATGMModelInterfaces.h"
#include "CATCGMVirtual.h"
#include "CATListPOfCATCGMDiagnoses.h"
#include "CATListOfCATICGMObjects.h"
#include "CATSysErrorDef.h"
#include <memory> 
#include <vector>

class CATGeoFactory;
class CATICGMObject;
class CATCGMJournalList;
class CATCGMDiagnosis;
class CATMathStream;
class CATSoftwareConfiguration;

namespace EK {
  class Binary;
}

using CATGMJournalVector = std::vector<std::shared_ptr<CATCGMJournalList>>;

class ExportedByCATGMModelInterfaces CATIPGMMultiProcChannel : public CATCGMVirtual
{
public:  

 /**
  * ~ Class members ~
  *
  * Retrieve a pointer on the input Software Configuration */
  virtual  CATSoftwareConfiguration * GetConfig () const = 0;
  /* Retrieve a pointer on the input GeoFactory */
  virtual  CATGeoFactory            * GetFactory() const = 0;


 /**
  *----------------------------------------------------------------*
  *               ~ Asynchronuous Writing ~ 
  *----------------------------------------------------------------*
  * Methods to call in  CATIPGMMultiProcTask::Write() / OnExecute()
  * Data will be "catched" automatically afterwards by streamer engine.
  *   Will return E_FAIL if called on reading channel.
  *   Will return S_FALSE if no data have been sent, S_OK otherwise.
  */
  virtual HRESULT Send (CATICGMObject * iInputObj)                      = 0;   
  virtual HRESULT Send (const CATLISTP(CATICGMObject) & iObjectList)    = 0;

  virtual HRESULT Send (CATCGMDiagnosis * ipDiagnosis)                  = 0;
  virtual HRESULT Send (const CATLISTP(CATCGMDiagnosis) & iWarningList) = 0;
  
  /* order will be preserved. null pointers can be sent. */
  virtual HRESULT Send (std::unique_ptr<CATCGMJournalList> & ipJournal)       = 0;
  virtual HRESULT Send (const std::shared_ptr<CATCGMJournalList> & ipJournal) = 0;
  virtual HRESULT Send (const CATGMJournalVector & iJournalVector)            = 0;

  /* use smart pointer for better performance - no mem allocation 
  * reminder: EK offers EKBinaryWriter to help you to build your data. 
  */
  virtual HRESULT Send (const EK::Binary  & iBinary) = 0;
    
 /**
  * be aware: Only one binary/stream can be sent.
  * Example:
  *   CATMathStream  writeStream ((size_t) 0, CatCGMStreamWriteOnly);
  *   HRESULT hr = ioInputChannel.Send(writeStream);
  *
  * duplication of memory */
  virtual HRESULT Send (const CATMathStream & iStream) = 0;



 /**
  *----------------------------------------------------------------*
  *               ~ Asynchronuous Reading ~ 
  *----------------------------------------------------------------*
  * Retrieve asynchronuous sent objects (from Send(Xxx) methods).
  * You can call them in any order, regardless of the Send order. 
  *   Will return E_FAIL if called on writting channel.
  *   Will return S_FALSE if no data have been found, S_OK otherwise.
  */
  virtual HRESULT GetObjects  (CATLISTP(CATICGMObject)   & oObjectList)   const = 0;
  virtual HRESULT GetDiagnosis(CATLISTP(CATCGMDiagnosis) & oWarningList)  const = 0;

  /*Retrieve all journals in the correponding to the sent order. Null pointers can occur. */
  virtual HRESULT GetJournalArray (CATGMJournalVector  & opJournal)       const = 0;

 /** 
  * Construct a CATMathStream object to retrieve your data.
  * Example:  
  *   CATMathStream  myReadStream (iInputChannel.GetStreamLength(), CatCGMStreamReadWrite);
  *   HRESULT hr = iInputChannel.Get(myReadStream);
  */
  virtual size_t  GetStreamLength()                   const = 0;
  virtual HRESULT GetStream(CATMathStream & oStream)  const = 0;
 /** 
  * Using Smart pointer - better performance
  *   Param @oBinary has to be empty or return E_FAIL. 
  * reminder: EK offers EKBinaryReader to help you to read your data. 
  */
  virtual HRESULT GetBinary(EK::Binary    & oBinary)  const = 0;





// --------------------------------------------------------------------------------------------------------
  // @ depracated R424  
  [[deprecated("is deprecated [R424/R2022x] - Use GetObjects() instead.")]]
  virtual HRESULT Get(CATLISTP(CATICGMObject)   & oObjectList)  const = 0;
  // @ depracated R424  
  [[deprecated("is deprecated [R424/R2022x] - Use GetDiagnosis() instead.")]]
  virtual HRESULT Get(CATLISTP(CATCGMDiagnosis) & oWarningList) const = 0;
  // @ depracated R424  
  [[deprecated("is deprecated [R424/R2022x] - Use GetJournal() instead.")]]
  virtual HRESULT Get(CATCGMJournalList        *& oJournal)     const = 0;
  // @ depracated R424  
  [[deprecated("is deprecated [R424/R2022x] - Use GetStream() instead.")]]
  virtual HRESULT Get(CATMathStream & oStream) const = 0;

protected :
  /* protected Contructor */
  CATIPGMMultiProcChannel();

  /* protected destructor */
  virtual ~CATIPGMMultiProcChannel();

private :
  /* forbiden constructor */
  CATIPGMMultiProcChannel (const CATIPGMMultiProcChannel &);
  /* forbiden operator */
  CATIPGMMultiProcChannel & operator = (const CATIPGMMultiProcChannel &);

};

#endif

