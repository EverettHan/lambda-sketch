#ifndef _PLMPosSecurityToken_h_
#define _PLMPosSecurityToken_h_

// COPYRIGHT DASSAULT SYSTEMES 2005

/**
 * @level Protected
 * @usage U1
 */

// System
/* #include "CATBaseUnknown.h" */
#include "CATUnicodeString.h"
#include "CATHashDicOfCATUnicodeString.h"

// PLM POS base
#include "ExportedByGUIDPLMPosBaseInterfaces.h"


// Forward class declarations
class CATListValCATUnicodeString;
/* class CATUnicodeString; */


/**
 * PLM security token class.
 * <b>Role</b>: This class contains and manages the Security Token, i.e. the 
 * information that is necessary for the ENOVIA Core Server to setup the P&O
 * and Security environment, so as to provide run-time security services to PLM
 * commands.
 */
class ExportedByGUIDPLMPosBaseInterfaces PLMPosSecurityToken /* : public CATBaseUnknown */
{
    // Class declaration
    /* CATDeclareClass; */

  public:
    /**
     * Initializes SecurityToken with a previously serialized SecutityToken.
     * To generate such a string, use the ToString() method.
     **/
    PLMPosSecurityToken(const CATUnicodeString &iStrToken);
    /**
     * Initializes SecurityToken with login parameters, using a HashDico whose :
     * - key is the parameter name
     * - value is the parameter value (string)
     **/
    PLMPosSecurityToken(const CATHashDicCATUnicodeString &iAllLoginParameters);
    /** @nodoc */
    PLMPosSecurityToken(const PLMPosSecurityToken& iToken);
    /** @nodoc */
    virtual ~PLMPosSecurityToken();
    /**
     * Get current user id part of the token
     **/
    HRESULT GetUserId(CATUnicodeString& oUserId) const;
    /**
     * Get current user context id part of the token
     **/
    HRESULT GetCurrentContextId(CATUnicodeString& oContextId) const;
    /**
     * Get current user's login parameters names
     **/
    HRESULT GetParameterNames(CATListValCATUnicodeString& oListName) const;
    /**
     * Get current user's login parameters values
     * They are in the same order than parameters names : see GetParameterNames()
     **/
    HRESULT GetParameterValue(const CATUnicodeString& iName ,
                              CATUnicodeString&       oValue) const;
    /**
     * Compares this token to another token.
     * @return
     *     S_OK     tokens are identical
     *     S_FALSE  tokens are not identical
     *     E_FAIL   at least on of the tokens is not valid
     **/
    HRESULT Compare(const PLMPosSecurityToken& iTokenToCompare) const;
    //
    /**
     * Generates a string token to be reused by all PLM commands.
     * This token identifies the user's secured session
     * - is associated to each client connection (provider) on client side
     * - is associated to each client connection on server side
     **/
    virtual HRESULT ToString(CATUnicodeString &oStringToken) const;

  protected:
    /**
     * Initializes SecurityToken with a previously serialized SecutityToken.
     * To generate such a string, use the ToString() method.
     **/
    PLMPosSecurityToken();
    /**
     * Flag about token's validity.
     */
    int                        _valid;
    /**
     * Token's user id.
     */
    CATUnicodeString           _user;
    /**
     * Token's context id.
     */
    CATUnicodeString           _context;
    /**
     * Token's parameters (other than user and context ids).
     */
    CATHashDicCATUnicodeString _params;

  private:
    /** @nodoc */
    //virtual PLMPosSecurityToken& operator=(const PLMPosSecurityToken& iToken);
};

#endif
