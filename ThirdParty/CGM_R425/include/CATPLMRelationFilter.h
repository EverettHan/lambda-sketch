#ifndef CATPLMRelationFilter_H
#define CATPLMRelationFilter_H

/**
 * @level Private
 * @usage U1
 *
 */
#include "CATBaseUnknown.h"
#include "ExportedByCATPLMIdentification.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"

typedef unsigned int CATPLMRelation_State;

#define CATPLMRelation_State_Cardinality                3
#define CATPLMRelation_State_ALL                        0x00000000
#define CATPLMRelation_State_VALID                      0x00000001
#define CATPLMRelation_State_GARBAGED                   0x00000002
#define CATPLMRelation_State_DESTROYED                  0x00000004

typedef unsigned int CATPLMRelation_Orientation;

#define CATPLMRelation_Orientation_Cardinality          4
#define CATPLMRelation_Orientation_ALL                  0x00000000
#define CATPLMRelation_Orientation_NEUTRAL              0x00000001
#define CATPLMRelation_Orientation_IN                   0x00000002
#define CATPLMRelation_Orientation_OUT                  0x00000004
#define CATPLMRelation_Orientation_INOUT                0x00000008

typedef unsigned int CATPLMRelation_Access;

#define CATPLMRelation_Access_Cardinality               2
#define CATPLMRelation_Access_ALL                       0x00000000
#define CATPLMRelation_Access_PUBLIC                    0x00000001
#define CATPLMRelation_Access_PRIVATE                   0x00000002

typedef unsigned int CATPLMRelation_Resolution;

#define CATPLMRelation_Resolution_Cardinality           4
#define CATPLMRelation_Resolution_ALL                   0x00000000
#define CATPLMRelation_Resolution_SOLVED                0x00000001
#define CATPLMRelation_Resolution_NOT_OPENED            0x00000002
#define CATPLMRelation_Resolution_BROKEN_REMOTE         0x00000004
#define CATPLMRelation_Resolution_BROKEN_SESSION        0x00000008

class ExportedByCATPLMIdentification CATPLMRelationFilter
{
public:

  CATPLMRelationFilter();
  ~CATPLMRelationFilter();

  /**
  * Change state filter (default value is : VALID)
  */
  HRESULT SetFilterByState (CATPLMRelation_State iStates_MaskAnd){_State = iStates_MaskAnd; return S_OK;}

  /**
  * Change orientation filter (default value is : ALL)
  */
  HRESULT SetFilterByOrientation (CATPLMRelation_Orientation iOrientations_MaskAnd){_Orientation = iOrientations_MaskAnd; return S_OK;}

  /**
  * Change level filter (default value is : ALL)
  */
  HRESULT SetFilterByAccess (CATPLMRelation_Access iLevels_MaskAnd){_Access = iLevels_MaskAnd; return S_OK;}

  /**
  * Change resolution filter (default value is : ALL)
  */
  HRESULT SetFilterByResolution (CATPLMRelation_Resolution iLevels_MaskAnd){_Resolution = iLevels_MaskAnd; return S_OK;}

  /**
  * Change role filter
  */
  HRESULT SetFilterByRole(const char Role[]) {_Role = Role; _FilterByRole = TRUE; return S_OK;}
  HRESULT SetFilterByRole(CATUnicodeString & Role) {_Role = Role; _FilterByRole = TRUE; return S_OK;}
  HRESULT UnsetFilterByRole(){_FilterByRole = FALSE; return S_OK;}

  /**
  * Change category filter
  */
  HRESULT SetFilterByCategory(CATUnicodeString & Category) {_Category = Category; _FilterByCategory = TRUE; return S_OK;}
  HRESULT UnsetFilterByCategory(){_FilterByCategory = FALSE; return S_OK;}

private:

  friend class CATOmbRelationImpl;

  CATPLMRelationFilter(const CATPLMRelationFilter&);
  CATPLMRelationFilter& operator=( const CATPLMRelationFilter& );

  CATPLMRelation_State          _State:CATPLMRelation_State_Cardinality; 
  CATPLMRelation_Orientation    _Orientation:CATPLMRelation_Orientation_Cardinality;
  CATPLMRelation_Access         _Access:CATPLMRelation_Access_Cardinality;
  CATPLMRelation_Resolution     _Resolution:CATPLMRelation_Resolution_Cardinality;

  CATBoolean                    _FilterByRole;
  CATUnicodeString              _Role;
  CATBoolean                    _FilterByCategory;
  CATUnicodeString              _Category;
};

#endif
