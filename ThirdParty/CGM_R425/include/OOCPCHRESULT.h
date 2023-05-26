#ifndef OOCPCHRESULT_H
#define OOCPCHRESULT_H


//-----------------------------------------------------------------------------------------------------------------------
// Design notes
//-----------------------------------------------------------------------------------------------------------------------
/**
 * @file
 * 
 * Constraints and design goals
 * ============================
 *
 * Design goals
 * ------------
 *
 * Making a richer error code that we can transition to easily from the current code base. This mostly locks us into using HRESULT or HRESULT compatible schemes.
 * It should enable easier debugging and possibly logging. For that, it should allow to identify where an error occurred and what it was about. Possibly down to locating the source file and line of code.
 * Applications/clients should also have a way to specify their own error codes, as much as possible.
 *
 *
 * Structure of HRESULT
 * --------------------
 *
 * As specified in
 * <https://docs.microsoft.com/en-us/windows/win32/com/structure-of-com-error-codes> and
 * <https://docs.microsoft.com/en-us/openspecs/windows_protocols/ms-erref/0642cb2f-2075-4469-918c-4441e69c548a> (section 2.1 of <https://docs.microsoft.com/en-us/openspecs/windows_protocols/ms-erref> if the link breaks.)
 * and contrary to the description found in SpecialAPI/PublicInterfaces/CATSysErrorDef.h
 * an HRESULT should be a 32 bit value structured as
 * 
 *      3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
 *      1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 *     +-+-+-+-+-+---------------------+-------------------------------+
 *     |S|R|C|N|X|    Facility         |               Code            |
 *     +-+-+-+-+-+---------------------+-------------------------------+
 *
 * where
 *
 *     S (1 bit): Official description: Severity. If set, indicates a failure result. If clear, indicates a success result.
 *                TNN9 notes: Since HRESULT is normally a typedef to a 2's complement signed integer, failure/success can be tested by comparing to 0.
 *
 *     R (1 bit): Official description: Reserved. If the N bit is clear, this bit MUST be set to 0. If the N bit is set, this bit is defined by the NTSTATUS numbering space.
 *                TNN9 notes: used for compatibility/conversion with NTSTATUS values, don't touch.
 *
 *     C (1 bit): Official description: Customer. This bit specifies if the value is customer-defined or Microsoft-defined. The bit is set for customer-defined values and clear for Microsoft-defined values.
 *                TNN9 notes: could set this bit and then use custom facility and code values. Ideally should try to avoid collision with other custom codes within 3DS and its clients, or maybe just strike an agreement with the applications.
 *
 *     N (1 bit): Official description: If set, indicates that the error code is an NTSTATUS value, except that this bit is set.
 *                TNN9 notes: used for compatibility/conversion with NTSTATUS values, don't touch.
 *
 *     X (1 bit): Official description: Reserved. SHOULD be set to 0.
 *                TNN9 notes: the Microsot documentation specifies some values that have this bit set, but overall doesn't matter. Also don't touch.
 *
 *     Facility (11 bits): Official description: An indicator of the source of the error. New facilities are occasionally added by Microsoft.
 *                         TNN9 notes: bunch of existing facilities are defined by Microsoft, but if we set the C bit we shouldn't really have to care about it?
 *
 *     Code (16 bits): Official description: The remainder of the error code.
 *
 *
 * __Extra notes__: It seems Windows has 3 flavours of "error codes": HRESULT, NTSTATUS, and "Win32 Error Codes". Both NTSTATUS and Win32 Error Codes can be converted
 * into an HRESULT via a scheme that doesn't matter for us, but not knowing about it makes reading documentation confusing. For example the two macros
 * HRESULT_FROM_WIN32 and HRESULT_FROM_NT exist for the purpose of creating an HRESULT value from those other two error codes.
 * Also the description of HRESULT that is available in SpecialAPI/PublicInterfaces/CATSysErrorDef.h *appears* to be describing an NTSTATUS rather than an HRESULT. The
 * interested reader can refer to <https://docs.microsoft.com/en-us/openspecs/windows_protocols/ms-erref/87fba13e-bf06-450e-83b1-9241dc81e781> for comparison. (section 2.3 of <https://docs.microsoft.com/en-us/openspecs/windows_protocols/ms-erref> if the link breaks.)
 * Despite the mismatched description, the rest of the macro definitions in CATSysErrorDef probably match HRESULT.
 *
 *
 * Making a custom HRESULT
 * -----------------------
 *
 * Two main options:
 *  1. Set the C flag, more freedom and bits to work with, basically perfectly fine for internal codes.
 *  2. Be COM compatible and don't touch the C flag, instead opt into the facility FACILITY_ITF: HRESULT values with that facility are allowed to collide and can be freely defined by whatever interface is returning the HRESULT. Better portability but fewer bits.
 */

/**
 * @file
 * 
 * Chosen design
 * =============
 *
 * Option 1 for custom HRESULT, i.e. setting the C bit. Because we want HRESULT, the R and N bits must be unset. The X bit should be left unset as well.
 * Remain
 *  - the S bit which will be used as intended for severity,
 *  - the facility code,
 *  - the (error/status) code.
 *
 * Facility code
 * -------------
 * Keep the MSB as reserved for now, later on could either give that bit to application/client codes so they can define custom facilities and use HRESULT codes
 * that are compatible with OOCPointCloud internals. Alternatively could provide an "EXTERNAL" facility code that uses that bit. For now, keep it reserve and try
 * to let that bit be unset.
 * As for designating the facilities, themselves, avoid the LSB for now, gives some leeway if some weird day we need to dedicate more bits to the code part. Because
 * we have the C bit set, we apriori have the freedom to reorganize the subdivision between facility/code. Another unconfirmed potential benefit (couldn't find the
 * relevant piece of information again) is that facilities defined by Microsoft usually uses the LSB.
 *
 * The facility code shall be no larger than 11 bits, it will be shifted left by 16 bits to produce the final HRESULT.
 *
 * Error/status code
 * -----------------
 * Have one bit reserved for application/client codes, apriori the MSB.
 * Have common situation pre-defined for common use.
 * In COM contexts, it is recommended to use values in the range 0x0200-0xFFFF only.
 *
 * The code shall be no larger than 16 bits.
 *
 * Code values
 * -----------
 * Beyond the above constraints/recommendations, the actual values of the different codes should not matter, it should be fine to simply increment the code value by
 * one from the previous code, similar to how enums work.
 *
 * Complete HRESULT values
 * -----------------------
 * The naming convention for complete HRESULT is FACILITY_SEVERITY_CODE
 */



//-----------------------------------------------------------------------------------------------------------------------
// Implementation
//-----------------------------------------------------------------------------------------------------------------------
#include "CATSysErrorDef.h"
#include <cstdint>


/**
 * @details
 * Microsoft defines falicities known to be in the range 0x0 - 0x51
 * 
 * CATSysErrorDef.h has some facilities up to 0x53
 * 
 * To avoid that range with some leeway, start facilities from 0x100
 *
 * Only the facilities listed here are guaranteed to be recognized
 * and handled properly by OOCPointCloud.
 *
 * @internal
 * Additionally, try to avoid the MSB (the 11-th bit), except for OOCPC_EXTERNAL.
 * The MSB could be used as a flag to enable application/client custom facilities.
 * The underlying type is specified explicitly as uint32_t because enum values are
 * intended to be left-shifted, and left-shift on signed type can end up being
 * awkward/UB. 32 bits because we want to produce HRESULT which are 32 bits.
 * If new facilities must be added, it is preferable to preserve the current enum
 * values.
 *
 * When creating a new facility code, it is recommended to create a dedicated header
 * for that facility (in OOCInterfaces, protected) which will contain the definitions
 * for codes in that facility/component. For tooling/debug purposes, it is also
 * recommended to define a *macro* that will automatically update the content of
 * OOCPCHRTool. See "HRTOOL utilities" further down in this file for details, and
 * OOCPCHRBuilder.h for an example.
 */
enum class OOCPCFacility : std::uint32_t
{
    eSTORAGE    = 0x101,
    eREPOSITORY,
    ePCIMPL,
    eIMPORTER,
    eINPUTBUFFER,
    eBUILDER,
    eLOD,
    eUPDATER,
    eITERATION,
    eQUERIES,
    eOPERATOR,
    eCACHE,
    eCONTAINER,
    eSTRINGREPOSITORY,
    eNODECACHE,
    eR2VSPC,
    eR2VSJAVA,
    eR2VSCSI,
    eFILESTREAM,
    eCLOUDSTORAGE,
    eR2VIMAGE,
    // ... (insert new facilities here)
    eODT        = 0x7FE,    //!< purely for ODT? don't care about value stability
    eEXTERNAL   = 0x7FF     //!< all 11 bits are set
};


/** @{ @name Severity codes
 * @details
 * The included header CATSysErrorDef.h already defines
 * 
 *  \#define SEVERITY_SUCCESS 0
 * 
 *  \#define SEVERITY_ERROR   1
 * 
 * so no need to redefine severity codes. The below is just for paranoid people.
 */
#ifndef SEVERITY_SUCCESS
#define SEVERITY_SUCCESS              0x0
#endif
#ifndef SEVERITY_ERROR
#define SEVERITY_ERROR                0x1
#endif
/** @} */   // Severity codes


/**
 * @details
 * The range of values    0x0 -   0x7F is reserved for pre-defined codes and future uses 
 *
 * The range of values   0x80 - 0x1FFF is reserved for facility/component specific codes,
 *      each facility is free to specify its own codes/semantics in that range, the convenience
 *      value COMPONENT_SPECIFIC_START is provided for ease of implementation
 *
 * The range of values 0x2000 - 0x2FFF is reserved for application/client specific codes,
 *      each application is free to specify its own codes/semantics in that range, the
 *      convenience value APPLICATION_SPECITIC_START is provided for ease of implementation
 *
 * The range of values 0x3000 - 0xFFFF is reserved for pre-defined codes and future uses
 *
 *
 * @internal
 * Listing of common HRESULT values that have already been taken into account to define these
 * general purpose codes (along with their decomposition into severity/facility/code):
 * HRESULT         |Severity           |Facility       |Code
 * ----------------|-------------------|---------------|---------------------------------
 * S_OK            |SEVERITY_SUCCESS   |FACILITY_NULL  |ERROR_SUCCESS/NO_ERROR (0x0)
 * S_FALSE         |SEVERITY_SUCCESS   |FACILITY_NULL  |ERROR_INVALID_FUNCTION (0x1)
 * E_NOTIMPL       |SEVERITY_ERROR     |FACILITY_NULL  |0x4001
 * E_ABORT         |SEVERITY_ERROR     |FACILITY_NULL  |0x4004
 * E_FAIL          |SEVERITY_ERROR     |FACILITY_NULL  |0x4005
 * E_UNEXPECTED    |SEVERITY_ERROR     |FACILITY_NULL  |0xFFFF
 * E_ACCESSDENIED  |SEVERITY_ERROR     |FACILITY_WIN32 |ERROR_ACCESS_DENIED (0x5)
 * E_OUTOFMEMORY   |SEVERITY_ERROR     |FACILITY_WIN32 |ERROR_OUTOFMEMORY (0xE)
 * E_INVALIDARG    |SEVERITY_ERROR     |FACILITY_WIN32 |ERROR_INVALID_PARAMETER (0x57)
 *
 * If new codes must be added, it is preferable to preserve the current enum/code values.
 */
enum class OOCPCCode : std::uint32_t
{
    // custom names/names that don't match existing
    // (some value may still match in their usage)
    eOK                 = 0,        //!< no alias for NO_ERROR since that is a macro in CATSysErrorDef and would break the enum definition
    eSUCCESS            = eOK,      //!< alias to conform to other values pulled from existing Microsoft/CATSysErrorDef codes
    eFALSE              = 1,
    eDEPENDENCYFAIL     = 0x400A,   //!< proposed: generic outer/dependent component failure?

    // for custom code implementation convenience
    eCOMPONENT_SPECIFIC_START   = 0x80,
    eAPPLICATION_SPECIFIC_START = 0x2000,


    //----------------------------------------------------------------------------------------------------

    // values pulled from Microsoft/CATSysErrorDef with the accompanying description
    // about half of them come from HRESULT that were already in use in various places in OOCPointCloud
    // the other half were pulled from low value codes
    // usage in OOCPointCloud may or may not stick closely to the official description
    eFILE_NOT_FOUND     = 0x2,      //!< The system cannot find the file  specified.
    eACCESSDENIED       = 0x5,      //!< Access is denied. __Note__: today, mostly lock related
    eOUTOFMEMORY        = 0xE,      //!< Not enough storage is available to complete this operation.
    eWRITE_PROTECT      = 0x13,     //!< The media is write protected.
    eNOT_READY          = 0x15,     //!< The device is not ready.
    eBAD_COMMAND        = 0x16,     //!< The device does not recognize the command.
    eCRC                = 0x17,     //!< Data error (cyclic redundancy check).
    eSEEK               = 0x19,     //!< The drive cannot locate a specific area or track on the disk. __Note__: will probably ditch the "drive/disk" part and apply to streams
    eWRITE_FAULT        = 0x1D,     //!< The system cannot write to the specified device.
    eREAD_FAULT         = 0x1E,     //!< The system cannot read from the specified device.
    eNOT_SUPPORTED      = 0x32,     //!< The request is not supported.
    eINVALID_PARAMETER  = 0x57,     //!< The parameter is incorrect. __Note__: today, was kinda generalized into "invalid pre-conditions"
    eOPEN_FAILED        = 0x6E,     //!< The system cannot open the device or file specified.
    eINVALID_NAME       = 0x7B,     //!< The fileneme, directory name, or volume label syntax is incorrect.
    //eSYNCHRONIZATION_REQUIRED   = 0x239,    //!< __Note__: was thinking this could still be fairly useful in OOC-IC and data repo/storage related contexts, doesn't fall inside the planned reserved ranges though

    // codes inferred from common HRESULTs but that didn't have a dedicated name
    // custom/unofficial descriptions
    eNOTIMPL            = 0x4001,
    eABORT              = 0x4004,   //!< generic cannot proceed/continue, should stop, one step short of catastrophic? (since we use error codes, there cannot be a true post-condition violation, since failure is part of the contract/possible outcomes)
    eFAIL               = 0x4005,   //!< generic non-descriptive (recoverable?) failure, probably avoid since goes counter to this whole redesign process? or keep for when there really is no better description?
    eUNEXPECTED         = 0xFFFF    //!< catastrophic/unrecoverable error
};


/** @{ @name HRESULT generation utilities */
#define OOCPCHR_CUSTOMER_BIT    (0x1 << 29)
#define MAKE_OOCPC_HRESULT(sev, fac, code)  ((HRESULT)(((std::uint32_t)(sev) << 31) | OOCPCHR_CUSTOMER_BIT | ((std::uint32_t)(fac) << 16) | (std::uint32_t)(code)))
/** @} */   // HRESULT generation utilities


/** @{ @name HRESULT testing utilities */

namespace oocpc
{
    inline std::uint32_t GetErrorCode( HRESULT const iHR )
    {
        return static_cast<std::uint32_t>( iHR & 0xFFFF );
    }
}
/** @} */   // HRESULT testing utilities


/** @{ @name HRTOOL utilities
 *
 * @details Several utilities to semi-automate the compilation of OOCPCHRTool, while keeping its list
 * of known custom HRESULT up to date.
 * 
 * @internal
 * Guide to adding a new facility/component.
 * For component XYZ, create a dedicated header, with the appropriate visibility. A priori
 * that header should belong to the FW OOCInterfaces and belong to its ProtectedInterfaces,
 * with the name "OOCPCHRXYZ.h". Within that header, include this one ("OOCPCHRESULT.h") and
 * define a dedicated enum class with underlying type std::uint32_t, that will contain any
 * relevant code for that facility. Code values must remain within the range 0x80 - 0x1FFF.
 * It is recommended to just start the first enum value explicitly at
 *  static_cast<std::uint32_t>(OOCPCCode::eCOMPONENT_SPECIFIC_START)
 *
 * Following dedicated code definition, define the custom HRESULT name/values by use of the
 * macro MAKE_OOCPC_HRESULT(sev, fac, code), e.g.
 * 
 *  \#define OOCPCXYZ_E_CODE  MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eXYZ, OOCPCXYZCode::eCODE)
 * 
 * After defining the custom HRESULT values, create a OOCPC_APPLY_LIST_TO_HRXYZ macro, which
 * should expand to a comma separated list of "OOCPC_APPLY(OOCPCXYZ_S_CODE)" with every HRESULT
 * defined. That macro definition should be protected by the OOCPC_USE_APPLY_LIST macro to
 * avoid uncontrolled macro name propagation.
 * Refer to OOCPCHRBuilder.h for an example.
 *
 * The final step for automatic listing of custom HRESULT is to include the dedicated facility
 * header below (in the block guarded by OOCPC_USE_APPLY_LIST), and ensure that the macro
 * OOCPC_APPLY_LIST_TO_ALL includes the newly defined OOCPC_APPLY_LIST_TO_HRXYZ in its expansion.
 * Be mindful of the commas.
 *
 * The above recommendation will ensure that newly defined custom HRESULT will be known and
 * listed by OOCPCHRTool, without having to edit the code of OOCPCHRTool directly.
 */
#ifdef OOCPC_USE_APPLY_LIST
#include "OOCPCHRBuilder.h"
#include "OOCPCHRCache.h"
#include "OOCPCHRContainer.h"
#include "OOCPCHRNodeCache.h"
#include "OOCPCHRImporter.h"
#include "OOCPCHRInputBuffer.h"
#include "OOCPCHRIteration.h"
#include "OOCPCHRLOD.h"
#include "OOCPCHROperator.h"
#include "OOCPCHRPCImpl.h"
#include "OOCPCHRQuery.h"
#include "OOCPCHRRepository.h"
#include "OOCPCHRStringRepository.h"
#include "OOCPCHRUpdater.h"
#include "OOCPCHRR2VSPC.h"
#include "OOCPCHRR2VSJNI.h"
#include "OOCPCHRR2VSCSI.h"

#define OOCPC_APPLY_LIST_TO_PREDEFINED      \
    OOCPC_APPLY(S_OK),                      \
    OOCPC_APPLY(S_FALSE),                   \
    OOCPC_APPLY(E_ACCESSDENIED),            \
    OOCPC_APPLY(E_OUTOFMEMORY),             \
    OOCPC_APPLY(E_INVALIDARG),              \
    OOCPC_APPLY(E_NOTIMPL),                 \
    OOCPC_APPLY(E_ABORT),                   \
    OOCPC_APPLY(E_FAIL),                    \
    OOCPC_APPLY(E_UNEXPECTED)

#define OOCPC_APPLY_LIST_TO_ALL             \
    OOCPC_APPLY_LIST_TO_HRBUILDER,          \
    OOCPC_APPLY_LIST_TO_HRCACHE,            \
    OOCPC_APPLY_LIST_TO_HRCONTAINER,        \
    OOCPC_APPLY_LIST_TO_HRNODECACHE,        \
    OOCPC_APPLY_LIST_TO_HRIMPORTER,         \
    OOCPC_APPLY_LIST_TO_HRINPUTBUFFER,      \
    OOCPC_APPLY_LIST_TO_HRITERATION,        \
    OOCPC_APPLY_LIST_TO_HRLOD,              \
    OOCPC_APPLY_LIST_TO_HROPERATOR,         \
    OOCPC_APPLY_LIST_TO_HRPCIMPL,           \
    OOCPC_APPLY_LIST_TO_HRQUERY,            \
    OOCPC_APPLY_LIST_TO_HRREPOSITORY,       \
    OOCPC_APPLY_LIST_TO_HRSTRINGREPOSITORY, \
    OOCPC_APPLY_LIST_TO_HRR2VSPC,           \
    OOCPC_APPLY_LIST_TO_HRR2VSJNI,         \
    OOCPC_APPLY_LIST_TO_HRR2VSCSI,          \
    OOCPC_APPLY_LIST_TO_HRUPDATER
#endif
/** @} */   // HRTOOL utilities

#endif  // ifndef OOCPCHRESULT_H
