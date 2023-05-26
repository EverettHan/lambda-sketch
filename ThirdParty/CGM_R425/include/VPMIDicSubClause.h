//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicSubClause_h
#define _VPMIDicSubClause_h

#include "VPMIDicInterfaces.h"

#include "CATString.h"
#include "CATBaseUnknown.h"
#include "VPMIDicElement.h"
#include "CATLISTV_VPMIDicGenericClass_var.h"
#include "VPMDicSUBCLAUSEBEHAVIOR.h"
#include "VPMDicCARDINALITY.h"
#include "CATBoolean.h"
class VPMIDicElement;
class VPMIDicClass;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicSubClause;
#else
extern "C" const IID IID_VPMIDicSubClause;
#endif

/**
 * Interface to manage the VPMIDicSubClause.
 */

class  ExportedByVPMIDicInterfaces VPMIDicSubClause: public VPMIDicElement
{
    CATDeclareInterface;

    public:

        /* returns the targeted generic classes of the sub clause 
        * corresponds to the TargetName keyword
        */
        virtual HRESULT GetTargetClasses (  CATLISTV_VPMIDicGenericClass_var & oDicClassList ) const = 0;

        /* behaviour when the pointed object is revised 
        * corresponds to the  minorrevision keyword
        */
        virtual VPMDicSUBCLAUSEBEHAVIOR GetMinorRevisionBehavior () const = 0;

        /* behaviour when the pointed object is cloned 
        * corresponds to the  clone keyword
        */
        virtual VPMDicSUBCLAUSEBEHAVIOR GetCloneBehavior () const = 0;

        /* cardinality  
        * corresponds to the  cardinality keyword
        */
        virtual VPMDicCARDINALITY GetCardinality () const = 0;

        /* is the modification stamp of the relation propagated to the pointed  
        * corresponds to the  propagatemodify keyword
        */
        virtual CATBoolean PropagatesMofify () const = 0;

        /* does the add connection (or remove connection) impacts the modification stamp of the pointed  
        * corresponds to the  propagateconnection keyword
        */
        virtual CATBoolean PropagatesConnection () const = 0;

      //---------------------------------------------------------------------
      // Deprecated methods
      //---------------------------------------------------------------------
#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " VPMIDicSubClause::GetTargetClass must be replaced by VPMIDicSubClause::GetTargetClasses .")

#else
        virtual HRESULT GetTargetClass ( VPMIDicClass ** oTargetClass ) const = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " VPMIDicSubClause::GetTargetClassName must be replaced by VPMIDicSubClause::GetTargetClasses .")

#else
        virtual HRESULT GetTargetClassName ( CATUnicodeString & oTargetClassName ) const = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " VPMIDicSubClause::GetTargetElement must be replaced by VPMIDicSubClause::GetTargetClasses .")

#else
        virtual HRESULT GetTargetElement ( VPMIDicElement ** oTargetElement ) const = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " VPMIDicSubClause::GetTargetElementName must be replaced by VPMIDicSubClause::GetTargetClasses .")

#else

        virtual HRESULT GetTargetElementName ( CATUnicodeString & oTargetElementName ) const = 0;
#endif

};

CATDeclareHandler( VPMIDicSubClause, VPMIDicElement );

#endif
