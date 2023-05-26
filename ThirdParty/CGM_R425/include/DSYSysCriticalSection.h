#ifndef DSYSysCriticalSection_H
#define DSYSysCriticalSection_H

// COPYRIGHT DASSAULT SYSTEMES  2009

/************************************************************************/
/* Defines                                                              */
/************************************************************************/
#ifdef _WINDOWS_SOURCE
# define DSYSYS_CRITICAL_SECTION_OBJ CRITICAL_SECTION
#else // _WINDOWS_SOURCE
# define DSYSYS_CRITICAL_SECTION_OBJ pthread_mutex_t
#endif  // _WINDOWS_SOURCE

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/
#include <stdlib.h>
#ifdef _WINDOWS_SOURCE
# include <windows.h>
#else // _WINDOWS_SOURCE
# include <pthread.h>
#endif  // _WINDOWS_SOURCE

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "DSYSysBase.h"

/************************************************************************/
/* Functions prototypes                                                 */
/************************************************************************/

/************************************************************************/
/* Classes declaration                                                  */
/************************************************************************/
/**
 * @class DSYSysCriticalSection
 */
class ExportedByDSYSysBase DSYSysCriticalSection
{
  ///////////////////////////////////////////
  ////// Types/Constants/Struct/Enum ////////
  ///////////////////////////////////////////
public:

  ///////////////////////////////////////////
  ///////////////// Methods /////////////////
  ///////////////////////////////////////////
public:
  /**
   * Constructor (Default)
   */
  DSYSysCriticalSection();

  /**
   * Destructor
   */
  virtual ~DSYSysCriticalSection();

  /**
   * Enter the Critical Section
   *
   * @return          0 if successful or -1 in the case of an error
   */
  int Enter(void);

  /**
   * Leave the Critical Section
   *
   * @return          0 if successful or -1 in the case of an error
   */
  int Leave(void);

private:
  /// Copy constructor
  DSYSysCriticalSection(const DSYSysCriticalSection& src);

  /// Affectation
  DSYSysCriticalSection& operator=(const DSYSysCriticalSection& src);

  ///////////////////////////////////////////
  ///////////////// Members /////////////////
  ///////////////////////////////////////////
protected:
  /// Critical Section object
  DSYSYS_CRITICAL_SECTION_OBJ m_CriticalSectionObj;
#ifdef _WINDOWS_SOURCE
#else // _WINDOWS_SOURCE
private:
  // Mutex attribute variable
  pthread_mutexattr_t m_MutexAttr;
#endif  // _WINDOWS_SOURCE
};

//===============================================================
//===============================================================
/**
 * @class DSYSysCriticalSectionLocker
 */
class ExportedByDSYSysBase DSYSysCriticalSectionLocker
{
  ///////////////////////////////////////////
  ////// Types/Constants/Struct/Enum ////////
  ///////////////////////////////////////////
public:

  ///////////////////////////////////////////
  ///////////////// Methods /////////////////
  ///////////////////////////////////////////
public:
  /**
   * Constructor
   *
   * @param pCs       Critical Section object adress (existing)
   */
  DSYSysCriticalSectionLocker(DSYSysCriticalSection* pCs)
  : m_pCriticalSection(pCs)
  {
    if ( m_pCriticalSection != NULL )
      m_pCriticalSection->Enter();
  }

  /**
   * Destructor
   */
  virtual ~DSYSysCriticalSectionLocker()
  {
    if ( m_pCriticalSection != NULL )
      m_pCriticalSection->Leave();
  }

  ///////////////////////////////////////////
  ///////////////// Members /////////////////
  ///////////////////////////////////////////
protected:
  /// Critical Section object
  DSYSysCriticalSection* m_pCriticalSection;
};

#endif  // DSYSysCriticalSection_H
