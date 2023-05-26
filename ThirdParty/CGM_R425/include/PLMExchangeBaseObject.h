#ifndef  PLMExchangeBaseObjectObject_h
#define  PLMExchangeBaseObjectObject_h
/// COPYRIGHT DASSAULT SYSTEMES 2013-2016
// *****************************************************************
//
//   Identification :
//   ---------------
//
//      RESPONSIBLE : Jean-Luc MEDIONI
//      FUNCTION    : Exchange Experience 
//      USE         : ENOVIA
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    Class that enables to define a base Object 
//    (mother class for Object & Mapping not to be used directly)
//
// *****************************************************************
//
//   Remarks :
//   ---------
//
//
// ****************************************************************
//
//   Story :
//   -------
//
//   Revision 1.0  January 2013  (JLM) Duplication to implement Exchange Experience Model 
//
// ****************************************************************
//
// INSIDE class:
// -------------
//
//
//
// ****************************************************************
// Abstract class    : No
// Template code     : No
// Ilined   Function : No
// ****************************************************************

// --- Header that need to be referenced

// --- * System framework

#include "CATUnicodeString.h"

// --- * Mother class

#include "PLMExchangeModel.h"
#include "PLMExchangeNode.h"

// --- * Forward class declarations

class PLMExchangeAttribute   ;
class PLMExchangeClassObject ;

// --- Class definition

/**
 * Class representing a basic object.
 *
 * <b>Role</b>:
 * Define one Basic object that could be either @href PLMExchangeObject or @href PLMExchangeMapping .
 */
class ExportedByPLMExchangeModel PLMExchangeBaseObject : public PLMExchangeNode
{
   public:

   /**
     * Constructs a basic object.
     * 
     * @param ixFather
     *   Father object that used this basic object.
     */
      PLMExchangeBaseObject( PLMExchangeBasicNode * ixFather = NULL
                           , int                    inType   = PLMExchangeNodeBaseObject ) ;          

   /**
     * Destructor.
     * 
     * <br><b>Role</b>: Destructor.
     */
      ~PLMExchangeBaseObject() ;

    /**
      * Copy constructor.
      * 
      * @param ixNode
      * Object to be duplicated.
      */
      PLMExchangeBaseObject( const PLMExchangeBaseObject & ixNode ) ;

    /**
      * Assignment operator from another object node.
      * 
      * @param ixNode
      * Object used as reference for the assignment.
      */
      PLMExchangeBaseObject & operator=( const PLMExchangeBaseObject & ixNode ) ;

      // -----------------------------------------
      // ---   Object type management          ---
      // -----------------------------------------
      
    /**
      * Strings to enable debug display on storage mode.        
      */
      static const CATUnicodeString cObjectTypeName[] ;

    /**
      * Gets the name of the Modeling object type.
      *
      * <b>Role:</b> Gets the name of the Modeling object type.
      * 
      * @return
      *  returns the name of the Modeling object type.
      * 
      * @param inObjectType
      *   Core object type.
      */
      static CATUnicodeString GetObjectTypeName( PLMExchangeObjectType inObjectType ) ;

    /**
      * Gets the Modeling type based on the name of the modeling object type name.
      *
      * <b>Role:</b> Gets the Modeling type based on the name of the modeling object type name.
      * 
      * @return
      *  returns the Modeling obbject type.
      * 
      * @param icName
      *   Name of the Modeling object type.
      */
      static PLMExchangeObjectType GetObjectTypeFromName( const CATUnicodeString & icName ) ;

      // -----------------------------------------
      // ---   Object characteristic           ---
      // -----------------------------------------

   /**
     * Gets the Oid.
     *
     * <br><b>Role</b>: Gets the Oid.
     *
     * @return
     * Object Oid.
     */
      CATString GetOid() const ;

   /**
     * Sets the Oid.
     *
     * <br><b>Role</b>: Sets Oid.
     *
     * @param icId
     *   Oid.
     *
     * @param lUpdateIndex
     *   Enables to inhibit Oid indexation.
     *
     * @return
     * Returns error code
     */
      HRESULT SetOid( const CATString & icId , int lUpdateIndex = 1 ) ;

    /**
      * Gets Object class.
      *
      * <br><b>Role</b>: Gets Object class of this Object.
      * 
      * @return
      * Object class. 
      */
      PLMExchangeClassObject * GetObjectClass() const ;

    /**
      * Sets Object class.
      *
      * <br><b>Role</b>: Sets Object class of this Object.
      * 
      * @param ixClass
      *   Object class.
      * 
      * @param ilPropagateInformation
      *   Boolean value enabling to decide if Class definition if to be used as template for this object (default).
      */
      void SetObjectClass( PLMExchangeClassObject * const ixClass , int ilPropagateInformation = 1 ) ;

   /**
     * Gets the Operation.
     *
     * <br><b>Role</b>: Gets Operation associated to this object.
     *
     * @return
     *    Object Operation identifier.
     */
      CATUnicodeString GetOperation() const ;

   /**
     * Sets the Operation.
     *
     * <br><b>Role</b>: Sets Operation associated to this object.
     *
     * @param icOperation
     *   Operation identifier.
     *
     * @return
     * Returns error code
     */
      HRESULT SetOperation( const CATUnicodeString & icOperation ) ;

      // -------------------------------------------
      // --- Manage services
      // -------------------------------------------

    /**
      * Gets core object type.
      *
      * <br><b>Role</b>: Gets core object type.
      * 
      * @return
      *   Object core Type. 
      * <br><b>Legal values</b>: It can be set to either:
      * <dl>
      * <dt>PLMExchangeObjectType_Reference</dt>      <dd>Reference.</dd>
      * <dt>PLMExchangeObjectType_Port</dt>           <dd>Port.</dd>
      * <dt>PLMExchangeObjectType_Connection</dt>     <dd>Connection.</dd>
      * <dt>PLMExchangeObjectType_Instance</dt>       <dd>Instance.</dd>
      * <dt>PLMExchangeObjectType_Representation</dt> <dd>Representation.</dd>
      * <dt>PLMExchangeObjectType_RepInstance</dt>    <dd>Representation Instance.</dd>
      * <dt>PLMExchangeObjectType_Entity</dt>         <dd>Entity.</dd>
      * <dt>PLMExchangeObjectType_Relation</dt>       <dd>Relation.</dd>
      * </dl>
      */
      PLMExchangeObjectType GetObjectType() const ;

    /**
      * Sets  core object type.
      *
      * <br><b>Role</b>: Sets  core object type.
      * 
      * @param inMoType
      *   Object core Type.
      * <br><b>Legal values</b>: It can be set to either:
      * <dl>
      * <dt>PLMExchangeObjectType_Reference</dt>      <dd>Reference.</dd>
      * <dt>PLMExchangeObjectType_Port</dt>           <dd>Port.</dd>
      * <dt>PLMExchangeObjectType_Connection</dt>     <dd>Connection.</dd>
      * <dt>PLMExchangeObjectType_Instance</dt>       <dd>Instance.</dd>
      * <dt>PLMExchangeObjectType_Representation</dt> <dd>Representation.</dd>
      * <dt>PLMExchangeObjectType_RepInstance</dt>    <dd>Representation Instance.</dd>
      * <dt>PLMExchangeObjectType_Entity</dt>         <dd>Entity.</dd>
      * <dt>PLMExchangeObjectType_Relation</dt>       <dd>Relation.</dd>
      * </dl>
      */
      void SetObjectType( PLMExchangeObjectType inMoType ) ;

    /**
      * Search attribute by its name.
      *
      * <br><b>Role</b>: Search attribute by its name.
      * 
      * @return
      *     First attribute child having the right name.
      *     <br><b>Legal values</b>: Returns NULL if not found. 
      * 
      * @param icAttName
      *   Attribute name.
      */
      PLMExchangeAttribute * SearchAttributeByName( const CATUnicodeString & icAttName ) const ; 

      // ---------------------------------------------------------------
      // --- Describe object Properties:
      // ---------------------------------------------------------------

    /**
      * Enumeration of object properties.
      * 
      * <br><b>Role</b>: Enumeration of available object properties.
      * 
      * @param PLMExchangeObjectProperty_Undefined
      *  No property define, to be used for property mask initialization.
      * @param PLMExchangeObjectProperty_BySelection
      *  Define if Object selected by selection.
      * @param PLMExchangeObjectProperty_ByCompletion
      *  Define if Object selected by completion.
      * @param PLMExchangeObjectProperty_Publish
      *  Define if Publish is requested.
      * @param PLMExchangeObjectProperty_Filtered
      *  Define if an object has been filtered.
      * @param PLMExchangeObjectProperty_Import
      *  Define if Import is requested.
      * @param PLMExchangeObjectProperty_Create
      *  Define if Create operation is requested.
      * @param PLMExchangeObjectProperty_Update
      *  Define if update operation is requested.
      * @param PLMExchangeObjectProperty_Delete
      *  Define if deletion operation is requested.
      * @param PLMExchangeObjectProperty_Ignore
      *  Define if ignore operation is requested.
      * @param PLMExchangeObjectProperty_WithOwnership
      *  Define if Transfer site ownership operation is requested.
      * @param PLMExchangeObjectProperty_WithDelegation
      *  Define if delegation operation is requested.
      * @param PLMExchangeObjectProperty_OnlyReferenced
      *  Define if object is only referenced in PLM Briefcase with no definition.
      * @param PLMExchangeObjectProperty_ExportWaive
      *  Define if waive operation is requested.
      * @param PLMExchangeObjectProperty_Composition
      *  Indicates that <b>To</b> relation must be considered as one composition relation (used in particular in Object reorganization algorithm).
      * @param PLMExchangeObjectProperty_DwDegraded
      *  Indicates that the object has been degraded by downward process
      * @param PLMExchangeObjectProperty_DwFiltered
      *  Indicates that the object has been filtered by downward process
      */
      enum PLMExchangeObjectProperty
      {
        PLMExchangeObjectProperty_Undefined      = 0x00000000
      , PLMExchangeObjectProperty_BySelection    = 0x00000001
      , PLMExchangeObjectProperty_ByCompletion   = 0x00000002
      , PLMExchangeObjectProperty_Publish        = 0x00000004
      , PLMExchangeObjectProperty_Filtered       = 0x00000008
      , PLMExchangeObjectProperty_Import         = 0x00000010
      , PLMExchangeObjectProperty_Create         = 0x00000020
      , PLMExchangeObjectProperty_Update         = 0x00000040
      , PLMExchangeObjectProperty_Delete         = 0x00000080
      , PLMExchangeObjectProperty_Ignore         = 0x00000100
      , PLMExchangeObjectProperty_WithOwnership  = 0x00000200
      , PLMExchangeObjectProperty_WithDelegation = 0x00000400
      , PLMExchangeObjectProperty_OnlyReferenced = 0x00000800
      , PLMExchangeObjectProperty_ExportWaive    = 0x00001000
      , PLMExchangeObjectProperty_Composition    = 0x00002000
#ifdef CATIAR424 //FUN118229
	  , PLMExchangeObjectProperty_DwDegraded	 = 0x00004000
	  , PLMExchangeObjectProperty_DwFiltered	 = 0x00008000U
#endif
      } ;

    /**
      * Set one or several properties on an object.
      *
      * <b>Role:</b> Set one or several properties on an object.
      * 
      * @param iProperty
      *  Property identificator ( @see PLMExchangeBaseObject::PLMExchangeObjectProperty ).
      * 
      * @param ibValue
      *   Define if property is to set or to reset.
      * <br><b>Default values</b>: <b><i>TRUE</i></b> to set the property on this object. 
      */
      void SetProperty( PLMExchangeObjectProperty iProperty , CATBoolean ibValue = TRUE ) ;

    /**
      * Resets all properties on an object.
      *
      * <b>Role:</b> Resets all properties on an object.
      */
      void ResetProperty() ;

    /**
      * Checks if a specific of properties is set.
      *
      * <b>Role:</b> Checks if a specific of properties is supported by a <b><i>PLMExchangeBaseObject</b></i>.
      * 
      * @param iProperty [in]
      *  Property to be checked.
      * 
      * @return
      *   Method return code.:
      *   <br><b>Legal values</b>: Returns <b><i>TRUE</i></b> if all selected properties are set on this object
      *   and <b><i>FALSE</i></b> otherwise. 
      */
      CATBoolean IsPropertySupported( PLMExchangeObjectProperty iProperty ) const ;

    /**
      * Display property status.
      *
      * <b>Role:</b> Display property status.
      */
      void PrintProperty() const ;

    /**
      * Computes Object properties string.
      *
      * <b>Role:</b> Compute Object properties string by concatenation of all properties set.
      * 
      * @param ocPropertyString [out]
      *   Properties string.
      */
      void ComputePropertyString( CATUnicodeString & ocPropertyString ) const ;

    /**
      * Computes properties string.
      *
      * <b>Role:</b> Compute properties string by concatenation of all properties set.
      * 
      * @param inProperty [in]
      *   Properties mask.
      * 
      * @param ocPropertyString [out]
      *   Properties string.
      */
      static void ComputePropertyString( int inProperty , CATUnicodeString & ocPropertyString ) ;

    /**
      * Checks in once a series of properties are set.
      *
      * <b>Role:</b> Checks if a specific of properties is supported by a <b><i>PLMExchangeBaseObject</b></i>.
      * 
      * @param inProperties [in]
      *   Mask of property to be tested.
      * 
      * @return
      *   Method return code.
      *   <dl>
      *   <dt>-1</dt> <dd>At least one of the properties in the mask is set.</dd>
      *   <dt> 0</dt>  <dd>None of the properties in the mask is set.</dd>
      *   <dt> 1</dt>  <dd>All properties in the mask are set.</dd>
      *   </dl>
      */
      int IsAllPropertiesSet( int inProperties ) const ;

      // -------------------------------------------
      // --- Manage model services
      // -------------------------------------------

    /** 
      * Notify that one object will be deleted.
      *
      * <br><b>Role</b>: Notify that one object will be deleted.
      * 
      * 
      * @param ixReferenced
      * Object.
      * 
      * @return
      *   0 if Ok
      */
      int NotifyObjectDeletion( const PLMExchangeNode * ixReferenced ) ;

    /** 
      * Notify an object replacement.
      *
      * <br><b>Role</b>: In case of XML loading, we may have to replace on PLMExchangeNode by another one
      * (case of dummy node for instance).
      * <p><b>NB</b>: Does call <b><i>SuppressObjectUsage</i></b> to suppress all referencing
      * 
      * @param ixOld
      *  Object to be replaced.
      * 
      * @param ixNew
      *  Replacement Object.
      * 
      * @return
      *   0 if Ok
      */
      int NotifyObjectReplace( const PLMExchangeNode * ixOld , PLMExchangeNode * ixNew ) ;

      // -----------------------------------------------
      // --- To support XML streaming                ---
      // -----------------------------------------------

      // --- Unstream information from an XML stream

    /**
      * Enables to decode XML stream.
      *
      * <br><b>Role</b>: Decode XML node associated to this instance of object.
      * 
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <ul>
      * <li><tt>0</tt> if operation are executed without any errors.
      * <li><tt>1</tt> otherwise.
      * </ul>
      * 
      * @param icTag
      *   XML Attribute tag.
      * 
      * @param icValue
      *   XML Attribute value.
      */
      int GetFromStream( const CATUnicodeString & icTag , CATUnicodeString & icValue  ) ;

      // --- Stream information into an XML stream

    /**
      * Check if this node need to be streamed.
      *
      * <br><b>Role</b>: Check if this node need to be streamed. and Get XML node name.
      * 
      * @param inFileFilter
      *   Streaming option to define what need to be streamed.
      * 
      * @param ocXmlNodeName
      *   XML Node name to be used.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>: Returns 0 if node not to be traversed by streaming. 
      */
      int IsValidForPutToStream( int inFileFilter , CATUnicodeString & ocXmlNodeName ) const ;

    /**
      * Check if node needs to be streamed.
      *
      * <br><b>Role</b>: Checks if this node needs to be streamed according properties and current reporting filter.
      * 
      * @param inFileFilter
      *   Streaming option to define what need to be streamed.
      * 
      * @return
      *  Returns XML streaming mode: 
      * <br><b>Legal values</b>: 
      * <dl>
      * <dt>0</dt>  <dd>if node not to be traversed by streaming.</dd>
      * <dt>1</dt>  <dd>case of a node to be streamed without sub-XML nodes.</dd>
      * <dt>2</dt>  <dd>case of a node to be streamed with sub-XML nodes.</dd>
      * </dl>: 
      */
      virtual int IsValidForPutToStream( int inFileFilter ) const ;
      
    /**
      * Fill attribute to stream.
      *
      * <br><b>Role</b>: Add in the write buffer attributes.
      * 
      * @param iStreamBuffer
      *   Write buffer.
      * 
      * @param inFileFilter
      *   Streaming option to define what need to be streamed.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int PutAttributeToStream( PLMExchangeStreamBuffer & iStreamBuffer , int inFileFilter ) ;

      // --- Print attribute identity card

    /**
      * Internal print method to generate a report on standard output.
      *
      * <br><b>Role</b>: Internal method to generate a report on standard output that display the content
      *   of this node and its children.
      * 
      * @param icInput
      *  String to be used as header of the output.
      * 
      * @param icType
      *  String representing the object type
      * 
      * @param inMode
      *  Type of report to be generated.
      * 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>0</dt> <dd>Standard mode.</dd>
      * <dt>1</dt> <dd>One line mode.</dd>
      * </dl>
      */
      void _print( const char * const icInput , const char * const icType , int inMode = 0 ) const ;

   protected :
      // --- Member definition
      // --- * _nObjectType      Defines basic object type (core type).
      // --- * _nObjectProperty  Object properties repository.
      // --- * _cOid             Object Oid.
      // --- * _cOperation       Last operation applied on object.
      // --- * _xObjectClass     Object class.

    /** Defines basic object type (core type). */
      PLMExchangeObjectType    _nObjectType     ;

    /** Object properties repository. */
      int                      _nObjectProperty ;

    /** Node unique Identifier. */
      CATString                _cOid            ;

    /** Last operation applied on object. */
      CATUnicodeString         _cOperation      ;

    /** Object class. */
      PLMExchangeClassObject * _xObjectClass    ;

    /**
      * Enable to traverse node structure to fill XML write buffer.
      *
      * <br><b>Role</b>: Enable to traverse node structure to fill XML write buffer.
      * 
      * @param iStreamBuffer
      *   XML write buffer.
      * 
      * @param inXmlStreamingMode
      *   XML streaming mode:
      * <dl>
      * <dt>0</dt>  <dd>if node not to be traversed by streaming.</dd>
      * <dt>1</dt>  <dd>case of a node to be streamed without sub-XML nodes.</dd>
      * <dt>2</dt>  <dd>case of a node to be streamed with sub-XML nodes.</dd>
      * </dl>: 
      * 
      * @param icXmlNodeName
      *   XML Node name to be used.
      * 
      * @param inFileFilter
      *   Streaming option to define what need to be streamed.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int _putToStream( PLMExchangeStreamBuffer & iStreamBuffer
                              , int                       inXmlStreamingMode
                              , CATUnicodeString        & icXmlNodeName
                              , int                       inFileFilter ) ;

} ;
#endif
