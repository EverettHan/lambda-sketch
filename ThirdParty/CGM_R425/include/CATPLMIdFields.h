#ifndef CATPLMIDFields_H
#define CATPLMIDFields_H

#include "CATPLMTypeH.h"
#include "CATPLMID_Any.h"
#include "CATPLMRepositoryName.h"
#include "CATPLMID_RepositoryLocation.h"
#include "CATPLMID_Simple.h"
#include "CATPLMIdentificationAccess.h"

/**
 * struct containing all the fields of a plmid (CATPLMID_Simple class)
 *
 * use Disassemble to extract all fields from a CATPLMID_Simple
 * use Assemble to create a CATPLMID_Simple
 */
struct ExportedByCATPLMIdentificationAccess CATPLMIdFields
{
  //PLM type of the object
  CATPLMTypeH type;
  //physicalid of the object (unique id in whole database)
  CATPLMID_Any physicalid;
  //logicalid of the object (can be copied from another object 
  //                         objects sharing the same logicalid 
  //                         are considered equivalent by reroute engine)
  CATPLMID_Any logicalid;
  //majorid of the object (minor versioning: objects sharing the same
  //                       majorid are considered equivalent
  //                       by instances and some SRs)
  CATPLMID_Any majorid;
  //repository (typically PLM1 or TST, check @href CATPLMRepositoryNames)
  CATPLMRepositoryName repository;
  //location:
  //  empty for new objects (not saved in db yet) 
  //  CATPLMID_RepositoryLocation::Dummy() for objects saved in db
  //  there exist other cases but they are unclear
  CATPLMID_RepositoryLocation location;

  CATPLMIdFields();
  CATPLMIdFields(const CATPLMTypeH&, const CATPLMID_Any&, const CATPLMID_Any&, const CATPLMID_Any&, const CATPLMRepositoryName&, const CATPLMID_RepositoryLocation&);
  CATPLMIdFields(const CATPLMIdFields&);
  CATPLMIdFields& operator=(const CATPLMIdFields&);
  ~CATPLMIdFields();

  /** extract all fields from a CATPLMID_Simple */
  static CATPLMIdFields Disassemble(const CATPLMID_Simple&);

  /**
   * generate a new plmid with given type, repository and (optionally) physicalid
   * in output physicalid == logicalid == majorid and repository == CATPLMID_RepositoryLocation{}
   */
  static CATPLMIdFields New(const CATPLMTypeH& iType, const CATPLMRepositoryName& iRepositoryName);
  static CATPLMIdFields New(const CATPLMTypeH& iType, const CATPLMID_Any& iPhysicalId, const CATPLMRepositoryName& iRepositoryName);

  static constexpr int CopyLogicalId = 0x1;
  static constexpr int CopyMajorId = 0x2;
  static constexpr int CopyLocation = 0x4;
  /**
   * generate a new plmid through partial copy of another
   * type and repository are always copied
   * physicalid is never copied
   * logicalid/majorid/location are optionally if specified through CopyLogicalId/CopyMajorId/CopyLocation flags
   * @param iCopyMode
   *   a combination (bitwise OR '|') of any of CopyLogicalId, CopyMajorId, CopyLocation
   */
  static CATPLMIdFields NewFrom(const CATPLMID_Simple& iToCopy, int iCopyMode = 0);

  /**
   * assemble all fields into a CATPLMID_Simple
   * returns empty in case of error
   * all fields are mandatory except location
   */
  CATPLMID_Simple Assemble() const;

  /** strict comparison of all fields*/
  bool operator==(const CATPLMIdFields& other) const;
  bool operator!=(const CATPLMIdFields& other) const { return !operator==(other); }
};

#endif
