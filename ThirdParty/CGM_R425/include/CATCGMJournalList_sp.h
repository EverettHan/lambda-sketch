//=============================================================================
//
// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//
//=============================================================================
//
// RESPONSIBLE  : QF2
//
// DESCRIPTION  : CATCGMJournalList_sp 
//                CGM Smart Pointer for CATCGMJournalList
//                
//=============================================================================
// Creation QF2 March 2021
//=============================================================================

#ifndef CATCGMJournalList_sp_H
#define CATCGMJournalList_sp_H

#include "YP00IMPL.h"
#include <memory>
#include "DSYGMSharedPtr.h"

class CATCGMJournalList;
class CATSoftwareConfiguration;


#if __cplusplus >= 201103L // if C++11 
// #if _QF2CodeActif

/**
 * Class representing a smartpointer of a CATCGMJournalList. 
 * Never new, delete, addref or release it. 
 * Memory is handled automatically, based on c++ stack.
 ** 
 * Warnings: 
 * --------
 *  DOT NOT USE -> void InsertJournal(CATCGMJournalList * iJournalToInsert); // EVER or crash.
 *      //      -> unsigned short  Release(); // EVER
 *      //      -> unsigned short  AddRef(); 
 ***
 *  You can Use:
 *  HRESULT InsertCopy(...) or HRESULT InsertJournal(std::unique_ptr iJournal) instead are ok and compatible.
 *  and all other methods.
 *
 *
 * Compliancy with all plateform - AIX, Linux, Windows.
 * 
 * Usage:
 *   (1) CATCGMJournalList_sp spJournal = nullptr;
 *       CATCGMJournalList_sp spJournal = 0;
 *
 *   (2) CATCGMJournalList_sp pSmartJournal (new CATCGMJournalList(pConf, NULL));
 *
 *   (2) CATCGMJournalList  * pJournal = new CATCGMJournalList(pConf, NULL);
 *       CATCGMJournalList_sp pSmartJournal (std::move(pJournal));
 *
 *   (3a) std::shared_ptr<CATCGMJournalList> pSharedJournal = [...]
 *        CATCGMJournalList_sp pSmartJournal (pSharedJournal); // copy
 *   (3b) CATCGMJournalList_sp pSmartJournal (std::shared_ptr<CATCGMJournalList>(...)); // forbidden !
 * 
 *   (4) std::unique_ptr<CATCGMJournalList> pUniqJournal = [...]
 *       CATCGMJournalList_sp pSmartJournal (pUniqJournal); // move
 * 
 *   (*) Using "Maker" - see below line 130.
 *       CATCGMJournalList_sp spJournal = CGM::MakeSmartJournal(pConfig);
**/
class ExportedByYP00IMPL CATCGMJournalList_sp 
{
public:
  // - forbidden default constructor - 
  // Smart journal has to be initialized. 
  CATCGMJournalList_sp () = delete;

  /** Constructors  **/
  CATCGMJournalList_sp (std::nullptr_t) noexcept;                                               // (1)  (C++11)
  explicit  CATCGMJournalList_sp (CATCGMJournalList * && ipJournal)  noexcept;                  // (2)
  
  CATCGMJournalList_sp (std::shared_ptr<CATCGMJournalList>  & iJournalSptr) noexcept;           // (3a) (C++11)
  CATCGMJournalList_sp (std::shared_ptr<CATCGMJournalList>  && iJournalSptr) noexcept = delete; // (3b)  

  explicit CATCGMJournalList_sp (std::unique_ptr<CATCGMJournalList>  & iJournalSptr) noexcept;  // (4)  (C++11)

  /* Destructor  */
  virtual ~CATCGMJournalList_sp() = default;
  

// -------------------------------------------------------------------------------------------//

  /** Copy && Move Contructors **/
  CATCGMJournalList_sp (const CATCGMJournalList_sp &) noexcept = default;
  CATCGMJournalList_sp ( CATCGMJournalList_sp && )    noexcept = default;    // (c++11)

  /* Methods */
  std::shared_ptr<CATCGMJournalList> cast() const noexcept;                  // (c++11)

  // call internal release as if <tt>this</tt> had been deleted and set to null. 
  void reset() noexcept; 
  
  /**   Accessors   **/
  CATCGMJournalList & operator* () const noexcept;
  CATCGMJournalList * operator->() const noexcept;

  operator CATCGMJournalList * () const noexcept;
  
  explicit operator bool() const noexcept;


  // forbidden new operator 
   void * operator new    (size_t) = delete;
   void * operator new[]  (size_t) = delete;


private :
  // forbidden - compliance  linux
   void operator delete   (void* ptr) noexcept {};
   void operator delete [](void* ptr) noexcept {};

private:
  std::shared_ptr<CATCGMJournalList> _impl = nullptr;
  
};






// -------------------------------------------------------------------------------
// Implementation - Compatiblity for mkmk still under C++11.
//  -> Mostly AIX with legacy compiler
// -------------------------------------------------------------------------------
#else


class ExportedByYP00IMPL CATCGMJournalList_sp 
{
public:

  /** Constructors  **/
  CATCGMJournalList_sp (unsigned int); 

  explicit  CATCGMJournalList_sp (CATCGMJournalList * ipJournal) ;  
  /* Destructor  */
  virtual ~CATCGMJournalList_sp();

// -------------------------------------------------------------------------------------------//

  /** Copy Contructors **/
  CATCGMJournalList_sp (const CATCGMJournalList_sp & iOther);

  // Releases the ownership of the managed object.
  // Decrement ref counter. 
  void reset(); 

  
  /**   Accessors   **/
  CATCGMJournalList & operator* () const;
  CATCGMJournalList * operator->() const;

  operator CATCGMJournalList * () const;
  
  operator bool() const;


  bool operator==(const CATCGMJournalList_sp & iRight) ;
  bool operator!=(const CATCGMJournalList_sp & iRight) ;

private :
  // - forbidden default constructor - 
  // Smart journal has to be initialized. 
  CATCGMJournalList_sp ();


  void * operator new    (size_t) ;
  void * operator new[]  (size_t) ;

private:

// custom smartpointer...
  DSYGMSharedPtr<CATCGMJournalList> _impl; // multi OS - compliant AIX
};


#endif


/**
 * ========================================================= *
 *                    - Maker -
 * ========================================================= *
 * Usage:
 *  CATCGMJournalList_sp spJournal = CGM::MakeSmartJournal(pConfig, NULL);
 *  [..]
**/
namespace CGM
{
  // Beaware: Throw if param @iConfig is null !
  ExportedByYP00IMPL CATCGMJournalList_sp MakeSmartJournal(CATSoftwareConfiguration * iConfig, CATCGMJournalList * ioList = NULL) ;
}


#endif

