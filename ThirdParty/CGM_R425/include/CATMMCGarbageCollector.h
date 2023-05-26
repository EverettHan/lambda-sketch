#ifndef CATMMCGARBAGECOLLECTOR_H
#define CATMMCGARBAGECOLLECTOR_H

#include "IDispatch.h"
#include "CATMMediaCore2.h"

#include "CATSysMacroPtr.h"
#include "CATListPV.h"


/**
 * @ingroup groupPotentialSysInfra
 * After having add object of type arrays, pointers or IUnknowns(reference counting pointers), data will be cleaned at its destruction.
 * @brief Services for collecting arrays, pointers and IUnknowns.
 *
 * Threadsafe : No.
 */
class ExportedByCATMMediaCore2 CATMMCGarbageCollector
{
public:
  CATMMCGarbageCollector();
  ~CATMMCGarbageCollector();

  /** @name Services to handle object's clean */
  /**@{*/ 
//void AddTab(void* ipTab);
//void AddPtr(void* ipPtr);
  void AddRIU(IUnknown* ipRIU);//Reference to IUnknown
  void AddRIU2(IUnknown** ipRIU);
  /**@}*/ 

  /** @name Services to keep an object and avoid its clean */
  /**@{*/ 
//int RemoveTab(void* ipTab);
//int RemovePtr(void* ipPtr);
  int RemoveRIU(void* ipRIU);
  int RemoveRIU2(void** ipRIU);
  /**@}*/

  /** @name Services to purge list. Data are deleted or released. */
  /**@{*/
//void PurgeTabs();
//void PurgePtrs();
  void PurgeRIUs();
  void PurgeRIUs2();
  void PurgeAll();
  /**@}*/

  /** @name Services to empty list. Data are NOT deleted or released. */
  /**@{*/
//void EmptyTabs();
//void EmptyPtrs();
  void EmptyRIUs();
  void EmptyRIUs2();
  void EmptyAll();
  /**@}*/

private:
//CATRawCollPV  _listTab;
//CATRawCollPV  _listPtr;
  CATRawCollPV  _listRIU;
  CATRawCollPV  _listRIU2;
};

#define DefineGarbageCollector(classname)                                                                                                                                    \
class classname##Garbage {                                                                                                                                                   \
  public:                                                                                                                                                                    \
  CATRawCollPV  _listPtr;                                                                                                                                                    \
  CATRawCollPV  _listTab;                                                                                                                                                    \
  classname##Garbage(){};                                                                                                                                                    \
  ~classname##Garbage(){PurgeAll();};                                                                                                                                        \
  void AddPtr(classname* ipPtr){if(ipPtr)_listPtr.Append((void*)ipPtr);};                                                                                                    \
  void AddTab(classname* ipTab){if(ipTab)_listTab.Append((void*)ipTab);};                                                                                                    \
  void RemovePtr(classname* ipPtr){if(ipPtr)_listPtr.RemoveValue((void*)ipPtr);};                                                                                            \
  void RemoveTab(classname* ipTab){if(ipTab)_listTab.RemoveValue((void*)ipTab);};                                                                                            \
  void PurgePtr()        { for(int i=_listPtr.Size(); i>=1; i--){classname* pTypedPtr=(classname*)_listPtr[i]; CATSysDeletePtr(pTypedPtr); _listPtr.RemovePosition(i); } };  \
  void PurgeTab()        { for(int i=_listTab.Size(); i>=1; i--){classname* pTypedTab=(classname*)_listTab[i]; CATSysDeleteTab(pTypedTab); _listTab.RemovePosition(i); } };  \
  void PurgeAll()        { PurgePtr(); PurgeTab(); };                                                                                                                        \
  void EmptyPtr()        { for(int i=_listPtr.Size(); i>=1; i--){classname* pTypedPtr=(classname*)_listPtr[i];                             _listPtr.RemovePosition(i); } };  \
  void EmptyTab()        { for(int i=_listTab.Size(); i>=1; i--){classname* pTypedTab=(classname*)_listTab[i];                             _listTab.RemovePosition(i); } };  \
  void EmptyAll()        { EmptyPtr(); EmptyTab(); };                                                                                                                        \
}
#define DeclareDeleteGarbageCollector(classname,variablename)  classname##Garbage g_##variablename;                                                                          \
                classname* variablename=g_##variablename._ptr

#define MAKE_ONCE(oncebool,action) do{ static bool oncebool=false;if(!oncebool){ action; oncebool=true; }}while(0)

//#define AT_LIBRARY_LOAD_UNLOAD(Identifiant,CodeAtLoad,CodeAtUnload)  class AtLibraryLoad##Identifiant {                                                                    \
//  AtLibraryLoad##Identifiant() { CodeAtLoad };                                                                                                                             \
//  ~AtLibraryLoad##Identifiant() { CodeAtUnload };                                                                                                                          \
//} _AtLibraryLoad##Identifiant
#define AT_LIBRARY_LOAD_UNLOAD(CodeAtLoad,CodeAtUnload)  class AtLibraryLoad{                                                                                                \
  AtLibraryLoad() { CodeAtLoad };                                                                                                                                            \
  ~AtLibraryLoad() { CodeAtUnload };                                                                                                                                         \
} _AtLibraryLoad


#endif
