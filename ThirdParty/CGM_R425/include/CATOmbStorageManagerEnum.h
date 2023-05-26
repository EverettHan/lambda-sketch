#ifndef CATOmbStorageManagerEnum_H
#define CATOmbStorageManagerEnum_H

/**
* @level Protected
* @usage U1
*/


/**
* Defines how a document has to be loaded. 
*
* @param CATPartialLoad
*     Document will be loaded partially. Containers are loaded on demand. 
* @param CATGlobalLoad
*     Document will be loaded globally. All containers are loaded after document has been loaded. 
*
*/
enum CATLoadMode
{
  CATPartialLoad = 0,
  CATGlobalLoad =1 
};

/**
* Defines the ILB Type. Only used by CATMemPersistServices::Save. 
* Impacts the save of a container. 
*
* @param CATGlobalSave
*     Default Mode. 
* @param CATStructureSave
*     CATMemPersistServices Mode. 
*
*/
enum CATSaveMode
{
  CATGlobalSave = 0,
  CATStructureSave = 1 
};

/**
* Specifies to the storage manager the kind of transaction, it is involved in.
*
* @param CATStgNoTransaction
*     Default mode. 
* @param CATStgOpenTransaction
*     Open Transaction. (Root Storage will only be closed when the manager will be closed)
* @param CATStgSaveTransaction
*     Save Transaction. 
*
*/
enum CATStgTransaction
{
  CATStgNoTransaction = 0,
  CATStgOpenTransaction = 1,
  CATStgSaveTransaction = 2 
};

/**
* Specifies how the RootStorage has been opened
*/
enum CATOmbRootStgTransaction
{
  CATOmbStgUnknown = 4, 
  CATOmbStgOpen = 3, 
  CATOmbStgSaveAs = 2,
  CATOmbStgSave = 1,    
  CATOmbStgWarmStart = 0
};

/**
* Defines the context for which the RootStorage will be opened. 
*/
enum CATOmbRootStgContext
{
  CATOmbUnstreamContext = 0,
  CATOmbAdditionalUnstreamContext = 1,
  CATOmbStreamContext = 2,
  CATOmbWarmStartContext = 3,
  CATOmbUnknownContext = 4
};

enum CATOmbOnRootStorageError
{
  CATOmbRaiseErrorAndAbort = 0,
  CATOmbRaiseErrorAndContinue = 1,
  CATOmbDoNotRaiseError = 2
};


#endif
