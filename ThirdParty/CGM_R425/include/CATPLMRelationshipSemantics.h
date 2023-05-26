#ifndef CATPLMRelationshipSemantics_H
#define CATPLMRelationshipSemantics_H
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#include "CATPLMSemantics.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

/**
* enum defining the possible values for the PropagOnDelete behaviour.
*/
enum SRPropagOnDelete {POD_NONE, POD_OUTWARD, POD_INWARD};
/**
* enum defining the possible values for the Visibility behaviour.
*/
enum SRVisibility {V_NO, V_YES};
/**
* enum defining the possible values for the Orientation behaviour.
*/
enum SROrientation   {O_NEUTRAL, O_IN, O_OUT, O_INOUT};
/**
* enum defining the possible values for the SynchroSensitivity behaviour.
*/
enum SRSynchroSensitivity {SS_NONE,SS_LAST,SS_PATH,SS_PATHANDLAST};


class CATListValCATPLMRelationshipSemantics;
class CATUnicodeString;

/**
* class to expose semantics (behaviors) relative to a category of a semantic relation.
* The category is defined by its name.
* The semantics are :
*    PropagOnDelete
*    Visibility
*    Orientation
*    SynchroSensitivity
*/

class ExportedByCATPLMSemantics CATPLMRelationshipSemantics
{

    public:
        /**
        * @nodoc
        */
        static const CATUnicodeString _AttrName;


        /**
        * @nodoc
        */
        static const CATUnicodeString _AttrPropagOnDelete;


        /**
        * @nodoc
        */
        static const CATUnicodeString _AttrVisibility;


        /**
        * @nodoc
        */
        static const CATUnicodeString _AttrOrientation;


        /**
        * @nodoc
        */
        static const CATUnicodeString _AttrSynchroSensitivity;



        /**
        * @nodoc
        */
        static const CATUnicodeString _ValuePropagOnDelete_None;


        /**
        * @nodoc
        */
        static const CATUnicodeString _ValuePropagOnDelete_Inward;


        /**
        * @nodoc
        */
        static const CATUnicodeString _ValuePropagOnDelete_Outward;


        /**
        * @nodoc
        */
        static const CATUnicodeString _ValueVisibility_No;


        /**
        * @nodoc
        */
        static const CATUnicodeString _ValueVisibility_Yes;


        /**
        * @nodoc
        */
        static const CATUnicodeString _ValueOrientation_Neutral;


        /**
        * @nodoc
        */
        static const CATUnicodeString _ValueOrientation_In;


        /**
        * @nodoc
        */
        static const CATUnicodeString _ValueOrientation_Out;


        /**
        * @nodoc
        */
        static const CATUnicodeString _ValueOrientation_InOut;


        /**
        * @nodoc
        */
        static const CATUnicodeString _ValueSynchroSensitivity_None;


        /**
        * @nodoc
        */
        static const CATUnicodeString _ValueSynchroSensitivity_Last;


        /**
        * @nodoc
        */
        static const CATUnicodeString _ValueSynchroSensitivity_Path;


        /**
        * @nodoc
        */
        static const CATUnicodeString _ValueSynchroSensitivity_PathAndLast;



        /**
        * default constructor.
        */
        CATPLMRelationshipSemantics();

        /**
        * constructor.
        * @param iName
        *   The name of the category.
        * @param iPropagOnDelete
        *   The value of the PropagOnDelete behavior.
        * @param iVisibility
        *   The value of the Visibility behavior.
        * @param iOrientation
        *   The value of the Orientation behavior.
        * @param iSynchroSensitivity
        *   The value of the SynchroSensitivity behavior.
        */
        CATPLMRelationshipSemantics (const CATUnicodeString& iName, SRPropagOnDelete iPropagOnDelete, SRVisibility iVisibility, SROrientation iOrientation, SRSynchroSensitivity iSynchroSensitivity);
        virtual ~CATPLMRelationshipSemantics ();

        /**
        * constructor.
        * @param original
        *   Original object to copy.
        */
        CATPLMRelationshipSemantics (const CATPLMRelationshipSemantics & original);

        /**
        * operator=.
        * @param original
        *   Original object.
        */
        CATPLMRelationshipSemantics& operator=(const CATPLMRelationshipSemantics& original);

        /**
        * operator==.
        * @param iToCompare
        *   Object to compare with this.
        * @return
        *   1 if iToCompare._Name == this._Name
        *   0 else
        */
        int operator==(const CATPLMRelationshipSemantics& iToCompare) const;

        /**
        * operator!=.
        * @param iToCompare
        *   Object to compare with this.
        * @return
        *   0 if iToCompare._Name == this._Name
        *   1 else
        */
        int operator!=(const CATPLMRelationshipSemantics& iToCompare) const;

        /**
        * Gets the name of the category, and the semantics associated.
        * @param oName
        *   The name of the category.
        * @param oPropagOnDelete
        *   The value of the PropagOnDelete behavior.
        * @param oVisibility
        *   The value of the Visibility behavior.
        * @param oOrientation
        *   The value of the Orientation behavior.
        * @param oSynchroSensitivity
        *   The value of the SynchroSensitivity behavior.
        * @return
        *   E_FAIL if this is not valid, if it has not been affected by the parsing.
        *   S_OK else.
        */
        HRESULT GetSemantics(CATUnicodeString& oName, SRPropagOnDelete& oPropagOnDelete, SRVisibility& oVisibility, SROrientation& oOrientation, SRSynchroSensitivity& oSynchroSensitivity);

        /**
        * Gets the complete of existing semantics.
        * @param oList
        *   The list of semantics.
        * @return
        *   HRESULT
        */
        static HRESULT ListAvailableRelationshipSemantics( CATListValCATPLMRelationshipSemantics& oList);

        /**
        * Gets the semantics from a name.
        * @param oSemantics
        *   The semantics.
        * @return
        *   HRESULT
        */
        static HRESULT GetSemanticsByName( const CATUnicodeString& iName, CATPLMRelationshipSemantics& oSemantics);

    protected :
        /**
        * Internal Use Only
        * Used to certify the validity of the object
        */
        void SetValid();

    private :
        CATUnicodeString _Name;
        SRPropagOnDelete _iPropag;
        SRVisibility _Visibility;
        SROrientation _Orient;
        SRSynchroSensitivity _Sensitivity;
        CATBoolean _IsValid;


        static HRESULT GetXMLAndDTDFilePath(CATUnicodeString& XMLPath, CATUnicodeString& DTDPath);

        static const CATUnicodeString _XMLName;
        static const CATUnicodeString _DTDName;

        friend class CATSAXHandlerForSemantics;
};

//-----------------------------------------------------------------------

#endif
