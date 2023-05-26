#ifndef CATCGRContainer_h
#define CATCGRContainer_h

#include "SGInfra.h"

#include "CATVizGlobals.h"
#include "CATVizPtrList.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATSTGMode.h"
#include "CATHashTable.h"

//----------------------------------------------------------------
// CATIA Version 5 Release 12
// COPYRIGHT DASSAULT SYSTEMES 2003
//----------------------------------------------------------------
// Abstract : This class ensures the streaming and unstreaming
//            of composite CGRs
//----------------------------------------------------------------
// Usage : N/A
//----------------------------------------------------------------
// Inheritance : None
//----------------------------------------------------------------
// Main Methods : N/A
//----------------------------------------------------------------

class CATStorage;
class CATStreamer;
class CATStream;
class CATCGRContainer;
class CATILockBytes2;

ExportedBySGInfra CATCGRContainer * GetMainCGRContainer(const char * iURL, unsigned long ioMode);
ExportedBySGInfra CATCGRContainer * GetMainCGRContainer(CATILockBytes2 *LB2, unsigned long ioMode);

class ExportedBySGInfra CATCGRContainer
{
   friend class CATDmuStream3DBagRep;

public :
   
   CATCGRContainer(const char* iName);
   #ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 5054)
#endif

   CATCGRContainer(const char* iName, CATStorage * iStorage, unsigned long ioMode = CATVizCGRModeRead | CATVizCGRAccessModeMemory);

   #ifdef _MSC_VER
#pragma warning(pop)
#endif 

   virtual ~CATCGRContainer();
   
   // Fetches the name of the container
   inline const char* GetName() const;
   
   // Retrieves the number of childs
   inline int GetChildCount();
   
   // Creates a child container of the current container
   // Returns NULL if 'iName' already exists as a child of the current container
   CATCGRContainer * CreateChildContainer(const char* iName);
   // Registers 'iContainer' as a child container of the current container
   // Returns E_FAIL if 'iName' already exists as a child of the current container
   HRESULT RegisterChildContainer(CATCGRContainer * iContainer);
   
   // Returns NULL if the container was not found as a child of the current container
   CATCGRContainer * GetChildContainer(const char* iName);
   
   // Returns the root container
   inline CATCGRContainer * GetRootContainer();
   
   // Returns the father container
   inline CATCGRContainer * GetFatherContainer();

   // Detachs the container from it's father. Only allowed on container created in READ mode
   // It has to be deleted by itself
   inline HRESULT Detach();

   // Makes a container standalone in memory (it does not point to a file on disk...)
   HRESULT MakeStandalone(int iRecursive = 1);

   // Commit changes in direct IO mode
   HRESULT Commit();

   // Versionning
   inline unsigned int GetVersion() const;
   inline void         SetVersion(unsigned int iVersion);

   // CGR Versionning
   inline unsigned int GetCGRVersion() const;

   // Streamers
   // Creates a new streamer on this container
   CATStreamer * CreateStreamer(const char *iName);
   // Returns the main streamer of this container
   inline CATStreamer * GetStreamer();
   // Returns an alternative streamer
   CATStreamer * GetStreamer(const char *iName);
   
   // Filters
   HRESULT SetApplicativeFilters(const CATListOfCATUnicodeString &iListToFilter); 
   CATListOfCATUnicodeString* GetApplicativeFilter();

   // Debug methods
   // This dumps the actual hierarchy of containers
   void Dump();
   // This dumps the whole structure of the attached storage
   void DumpStructure();
  
   // Light scene graph mode
   inline void SetLightSceneGraph(unsigned int iOnOff);
   inline unsigned int LightSceneGraph();

   // SmartLoading mode
   inline void SetSmartLoading(unsigned int iOnOff);
   inline unsigned int SmartLoading();

   void PropagateCurrentRepBBox(const CATStreamer* iSrc);

private :
   
   // Constructor for R12 CGRs which had streams instead of storages
   // for containers withoud childs...
	   #ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 5054)
#endif
   CATCGRContainer(const char* iName, CATStream * iStream, unsigned long ioMode = CATVizCGRModeRead | CATVizCGRAccessModeMemory);
#ifdef _MSC_VER
#pragma warning(pop)
#endif 

   // Constructor that permit to specify a CGR version.
   // Will initialize _cgrVersion & streamer version with the iCgrVersion
   CATCGRContainer(const char* iName, CATStorage * iStorage, unsigned int iCGRVersion, unsigned long ioMode);

	 // Internal constructor
	 void InitContainer(const char* iName, CATStorage * iStorage, CATStream * iStream, unsigned int iCGRVersion, unsigned long ioMode);

   // Add a container as a child of the current container
   HRESULT AddChildContainer(CATCGRContainer * iContainer);
   // Add a streamer as a child of the current container
   HRESULT AddChildStreamer(CATStreamer * iStreamer);

   // Streamer initialization
	 CATStreamer * InitStreamer(CATStream * iStream, const char* iName);

   // Header Streaming
   HRESULT StreamHeader();
   // Header UnStreaming
   HRESULT UnStreamHeader();

   // We will be called on this method if one of our child is destroyed.
   // Useful for maintaining our list of childs up to date.
   inline void NotifyDeletion(CATCGRContainer * child);


   // The father container. If NULL this is the root container
   CATCGRContainer *          _father;
   // The list of childs
   CATVizPtrList<CATCGRContainer> _childContainers;
   // The list of child streamers
   CATVizPtrList<CATStreamer> _childStreamers;
   // The streamer in which we stream the header
   CATStreamer  *             _streamer;
   
   
   // The container version (exposed to clients)
   unsigned int               _version;
   // The CGR version of the container
   unsigned int               _cgrVersion;
   // The filter list
   CATListOfCATUnicodeString* _listOfFilter;


   // The name must be defined only once.
   // If it is changed afterwards, the hashtables won't be
   // able to recognize it, as the insertion of containers
   // is based on their names.
   
   char* _name;

   // The associated storage
   CATStorage   * _storage;
   // The IO mode : it will be propagated to the childs
   unsigned long  _ioMode;

   unsigned int _lightSceneGraph;
   unsigned int _smartLoading;

   // Debug methods
   void RankDump(int rank=0);
   void RankDumpStructure(CATStorage * iStorage, int rank=0);

   // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
   CATCGRContainer(const CATCGRContainer &);
   CATCGRContainer & operator = (const CATCGRContainer &);
};

// INLINED METHODS

inline unsigned int CATCGRContainer::GetVersion() const
{
   return _version;
}

inline void CATCGRContainer::SetVersion(unsigned int iVersion)
{
   _version = iVersion;
}

inline unsigned int CATCGRContainer::GetCGRVersion() const
{
   return _cgrVersion;
}

inline void CATCGRContainer::NotifyDeletion(CATCGRContainer * child)
{
      _childContainers.Remove(child);
}

inline CATStreamer * CATCGRContainer::GetStreamer()
{
   // Since version 1101340, we separate the header stream and the main data stream
   if(_cgrVersion >= 1101340)
   {
      CATStreamer * str = GetStreamer("MainDataStream");
      if(str) return str;
      if(_ioMode & CATVizCGRModeWrite)
         return CreateStreamer("MainDataStream");
      return NULL;
   }
   return _streamer;
}

inline const char* CATCGRContainer::GetName() const
{
   return _name;
}

inline int CATCGRContainer::GetChildCount()
{
   return _childContainers.Length();
}

inline CATCGRContainer * CATCGRContainer::GetRootContainer()
{
   if(_father)
      return _father->GetRootContainer();
   return this;
}

inline CATCGRContainer * CATCGRContainer::GetFatherContainer()
{
   return _father;
}

inline HRESULT CATCGRContainer::Detach()
{
   // Detach is allowed only on read operations
   if(!(_ioMode & CATVizCGRModeRead) || !_father) return E_FAIL;
   
   _father->NotifyDeletion(this);
   _father = NULL;
   return S_OK;
}

inline void CATCGRContainer::SetLightSceneGraph(unsigned int iOnOff)
{
   _lightSceneGraph = iOnOff;
}

inline unsigned int CATCGRContainer::LightSceneGraph()
{
   return _lightSceneGraph;
}

inline void CATCGRContainer::SetSmartLoading(unsigned int iOnOff)
{
   _smartLoading = iOnOff;
}

inline unsigned int CATCGRContainer::SmartLoading()
{
   return _smartLoading;
}


#endif
