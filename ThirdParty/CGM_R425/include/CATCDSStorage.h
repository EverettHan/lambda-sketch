// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
// CATCDSStorage:
//   An base interface class for storing data of CATCDSStream.
//
//
//=============================================================================
//
// Usage notes:
//   There are not much sense to use this class directly.
//
//=============================================================================
//  Jul 2002  Creation                         Vladislav Kornienkoint
//=============================================================================

#ifndef CATCDSStorage_h
#define CATCDSStorage_h

#include "CATCDSUtilities.h"
#include "CATCDSBoolean.h"
#include "CATCDSString.h"

class ExportedByCATCDSUtilities CATCDSStorage {
public:
  enum ReplayPart { rpScript, rpInput, rpOutput, rpReference, rpAll };

  struct Section {
    CATCDSString _header;
    CATCDSString _options;
    CATCDSString _body;
    ReplayPart _part;
    int _number;

    Section * _pNext;

    Section();
    ~Section();
  };

  /**
   *  Default constructor.
   */
  CATCDSStorage();
  ~CATCDSStorage();

  /**
   *  Creates new empty section
   *  @param iPart replay part
   *  @return newly created section
   */
  Section * CreateSection(ReplayPart iPart);

  /**
   *  Adds new section constructing it from three string
   *  @param iHeader header string
   *  @param iOptions options string
   *  @param iBody body string
   *  @param iPart replay part
   *  @param iNumber replay number
   *  @return TRUE if no problem, FALSE otherwise
   */
  CATCDSBoolean AddSection(const CATCDSString & iHeader, const CATCDSString & iOptions, const CATCDSString & iBody, ReplayPart iPart, int iNumber = 0);

  /**
   *  Sets mode for section search
   *  @param iPart replay part
   *  @param iNumber replay number
   */
  void ChooseReplayPart(ReplayPart iPart, int iNumber = 0);

  /**
   *  Finds any section for current replay part and number
   */
  CATCDSBoolean HasSections(ReplayPart iPart, int iNumber = 0) const;

  /**
   *  Finds section matching by header string
   *  @param iHeader header string for search
   *  @return pointer to found section or 0 if no section with such header found
   */
  const Section * FindSection(const CATCDSString & iHeader) const;

  const Section * GetFirstSection() const;

private:
  Section * _pFirstSection; // pointer to head of section's list
  Section * _pLastSection; // pointer to tail of section's list
  ReplayPart _replayPart;
  int _replayNumber;

  const Section * FindSection(const CATCDSString& iHeader, ReplayPart iPart, int iNumber = 0) const;

  CATCDSStorage(CATCDSStorage const &);
  CATCDSStorage & operator=(CATCDSStorage const &);
};

#endif
