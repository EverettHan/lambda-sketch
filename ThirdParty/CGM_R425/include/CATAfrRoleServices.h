#ifndef CATAfrRoleServices_H
#define CATAfrRoleServices_H

// COPYRIGHT DASSAULT SYSTEMES 2016

#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATSYPArray.h"

class CATAfrRole;
class CATAfrRoleStruct;
class CATAfrRoleServices;

#include <CATLISTV_Clean.h>
#define CATLISTV_Append
#include <CATLISTV_Declare.h>
#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATAfrFoundation
CATLISTV_DECLARE( CATAfrRoleStruct );

class ExportedByCATAfrFoundation CATAfrRoleStruct
{
  public:

    /** Get the property Name. */
    const CATString & GetName() const;
    /** Get the property Title. */
    const CATUnicodeString & GetTitle() const;
    /** Get the property Tooltip. */
    const CATUnicodeString & GetTooltip() const;
    /** Returns list of Apps (CATIAfrAppsRoles implementation) */
    const CATSYPConstArray<CATString> & GetListApps() const;
    /** Get the property SelectedFlag. */
    const CATBoolean & GetSelectedFlag() const;
    /** Get the property Process. */
    const CATUnicodeString & GetProcess() const;

    CATAfrRoleStruct(CATAfrRole& pRole);
    CATAfrRoleStruct(const CATAfrRoleStruct &);
    CATAfrRoleStruct & operator=(const CATAfrRoleStruct &);
    virtual ~CATAfrRoleStruct();

  private:

    friend class CATAfrRoleServices_UT;

    // Copy constructor and equal operator
    // -----------------------------------
    CATAfrRoleStruct();

    CATString _name;
    CATUnicodeString _title;
    CATUnicodeString _tooltip;
    CATSYPConstArray<CATString> _listApps;
    CATBoolean _selectedFlag;
    CATUnicodeString _process;
};

int ExportedByCATAfrFoundation operator== (const CATAfrRoleStruct & i_left, const CATAfrRoleStruct & i_right);
int ExportedByCATAfrFoundation operator!= (const CATAfrRoleStruct & i_left, const CATAfrRoleStruct & i_right);

class ExportedByCATAfrFoundation CATAfrRoleServices
{
  public:

    /**
    *
    * <br>Service to return the list of granted roles
    * @return all granted roles  inside a CATAfrRoleStruct CATLISTV
    *
    */
    static CATLISTV(CATAfrRoleStruct) GetAllGrantedRoles();
    virtual ~CATAfrRoleServices();

  private:

    friend class CATAfrRoleServices_UT;

    // Copy constructor and equal operator
    // -----------------------------------
    CATAfrRoleServices();
    CATAfrRoleServices (CATAfrRoleServices &);
    CATAfrRoleServices & operator=(CATAfrRoleServices &);
};

#endif
