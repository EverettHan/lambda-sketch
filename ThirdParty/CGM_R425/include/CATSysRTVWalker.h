//-----------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2004
//-----------------------------------------------------------------------

#ifndef CATSysRTVWalker_h
#define CATSysRTVWalker_h

#define CATSysRTVWalker_Optimized

#include "CATLib.h"
#include "JS0LIB.h"         // exported by..
#include "DSYSysFNMatch.h"  // DSYSysFNMatchOptions
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#if defined(CATSysRTVWalker_Optimized)
# include "CATSysSimpleHashTable.h"
#endif  // CATSysRTVWalker_Optimized

//==========================================================
class ExportedByJS0LIB CATSysRTVWalker
//==========================================================
{
public:
  CATSysRTVWalker();
  ~CATSysRTVWalker();
  
  /**
   * SetPatternEx.
   * @param [in]  iFilterPattern is an optional pattern that allows to filter entry names following Unix filename pattern matching rules, in an efficient manner.
   *              If filtering is not required, iFilterPattern must be set to an empty string (or *).
   *              [Windows]: 
   *                 - the following characters are forbidden: 0x00-0x1F 0x7F " / : < > \ |
   *                   Note that the characters > < " also have a special meaning in patterns (DOS era legacy).
   *                 - "*.*" does not match all entries, but only the ones that actually contain a dot character, like on other OSes.
   *              Failing to comply to these rules will lead to undefined behavior.
   * @param [in]  iFilterOptions (see DSYSysFNMatch.h)
   */
  CATLibStatus SetPatternEx(const CATUnicodeString & iFilterPattern, const DSYSysFNMatchOptions & iFilterOptions);
  
  /**
   * SetPattern.
   * @deprecated R421 Use SetPatternEx.
   * @param [in] iPattern: the search will return entries that end with iPattern (case-sentsitive comparison).
   */
  // TODO IMPROVEMENT CATLibStatus SetPattern(const CATUnicodeString & iPattern);
  CATLibStatus SetPattern(CATUnicodeString iPattern);
  
  CATUnicodeString GetPattern();// TODO IMPROVEMENT const;
  CATUnicodeString GetConcatenation();// TODO IMPROVEMENT const;
  // TODO IMPROVEMENT CATLibStatus AppendRTVSubDir (const CATUnicodeString & iSubdir);
  CATLibStatus AppendRTVSubDir (CATUnicodeString iSubdir);
  CATLibStatus GetNext         (CATUnicodeString &oNextPath);
  
  CATLibStatus Reset();
  
  // @deprecated R417 Use GetNext
  CATLibStatus GetFoundedFiles (CATListValCATUnicodeString &oList);

private:
  // Member functions  
  CATLibStatus Search();
  
  // Members
#if defined(CATSysRTVWalker_Optimized)
  CATSysSimpleHashTable      m_AllreadyRead;
#else   // CATSysRTVWalker_Optimized
  CATListValCATUnicodeString m_AllreadyRead;
#endif  // CATSysRTVWalker_Optimized
  CATListValCATUnicodeString m_MatchingFilesList;
  CATUnicodeString m_Concatenation;
  CATUnicodeString m_FilterPattern;
  DSYSysFNMatchOptions m_FilterOptions;
  int  m_Index;
  bool m_bSearchDone;
};

/* TODO IMPROVEMENT BEGIN
//============================================================================
inline CATUnicodeString CATSysRTVWalker::GetPattern() const
//============================================================================
{
  return m_FilterPattern;
}

//============================================================================
inline CATUnicodeString CATSysRTVWalker::GetConcatenation () const
//============================================================================
{
  return m_Concatenation;
}

//============================================================================
inline CATSysRTVWalker::~CATSysRTVWalker()
//============================================================================
{
    Reset();
}
 TODO IMPROVEMENT END */

#endif
