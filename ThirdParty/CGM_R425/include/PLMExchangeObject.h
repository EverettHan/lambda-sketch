//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
#ifndef  PLMExchangeObject_h
#define  PLMExchangeObject_h
/// COPYRIGHT DASSAULT SYSTEMES 2012-2013
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
//    Class that enables to define an Object
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
//   Revision 1.0  March 2007     (JLM) Initial Revision from ENORepNode
//   Revision 2.0  December 2012  (JLM) Duplication to implement Exchange Experience Model 
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
#include "PLMExchangeBaseObject.h"

// --- * Forward class declarations

class PLMExchangeAttribute   ;
class PLMExchangeClassObject ;

// --- Class definition

/**
  * Class representing an object.
  *
  * <b>Role</b>:
  * Define an object in the PLM Exchange Reporting model deriving from @href PLMExchangeObject.
  */
class ExportedByPLMExchangeModel PLMExchangeObject : public PLMExchangeBaseObject
{
   public:

   /**
     * Constructs an Object.
     * 
     * @param ixFather
     *   Node that aggregates this object.
     */
      PLMExchangeObject( PLMExchangeBasicNode * ixFather = NULL ) ;          

   /**
     * Destructor.
     * 
     * <br><b>Role</b>: Destructor.
     */
      ~PLMExchangeObject() ;

    /**
      * Copy constructor.
      * 
      * @param ixNode
      * Object to be duplicated.
      */
      PLMExchangeObject( const PLMExchangeObject & ixNode ) ;

    /**
      * Assignment operator from another object node.
      * 
      * @param ixNode
      * Object used as reference for the assignment.
      */
      PLMExchangeObject & operator=( const PLMExchangeObject & ixNode ) ;

      // -----------------------------------------
      // ---   Object relationship management  ---
      // -----------------------------------------

    /**
      * Gets "From Object" relationship.
      *
      * <br><b>Role</b>: Gets Object Owner or From Object according object core type.
      * 
      * @return
      * Object class. 
      */
      PLMExchangeObject * GetFromObject() const ;

    /**
      * Sets "From Object" relationship.
      *
      * <br><b>Role</b>: Sets Object Owner or From Object according object core type.
      * 
      * @param ixChild
      *   Object class.
      */
      void SetFromObject( PLMExchangeObject * const ixObject ) ;

    /**
      * Gets "To Object" relationship.
      *
      * <br><b>Role</b>: Gets Reference object for an instance or To Object.
      * 
      * @return
      * Object class. 
      */
      PLMExchangeObject * GetToObject() const ;

    /**
      * Sets "To Object" relationship.
      *
      * <br><b>Role</b>: Sets Reference object for an instance or To Object
      * 
      * @param ixChild
      *   Object class.
      */
      void SetToObject( PLMExchangeObject * const ixObject ) ;

    /** 
      * Get list of objects referencing the current object by a "From relation".
      *
      * <br><b>Role</b>: Get list of objects referencing the current object as Owner or From Object according object core type.
      * 
      * @param olstFromObjects
      * List of objects.
      * 
      * @return
      *  Number of objects in the list.
      */
      int GetObjectUsageByFrom( CATListOfPLMExchangeNode & olstFromObjects ) const ;

    /** 
      * Get list of objects referencing the current object by a "To relation".
      *
      * <br><b>Role</b>: Get list of objects referencing the current object as Owner or From Object according object core type.
      * 
      * @param olstToObjects
      * List of objects.
      * 
      * @return
      *  Number of objects in the list.
      */
      int GetObjectUsageByTo( CATListOfPLMExchangeNode & olstToObjects ) const ;

      // ---------------------------------------------------------------
      // --- Object hierachy improvement
      // ---------------------------------------------------------------

    /** 
      * List of defined organization filters:
      * 
      * @param WITH_FROM_ON_VPM
      *   Organize according <i>From</i> relation set on VPM objects (Owned by).
      * @param WITH_TO_ON_VPM
      *   Organize according <i>To</i> relation set on VPM objects (Instance Of).
      * @param WITH_FROM_ON_ER
      *   Organize according <i>From</i> relation set on VPM objects.
      * @param WITH_TO_ON_ER
      *   Organize according <i>To</i> relation set on VPM objects.
      * @param Debug
      *   All filters activated.
      * @param VPMObjectOnly
      *   Organize according <i>To</i> & <i>From</i> relationship on VPM objects.
      * @param ERObjectOnly
      *   Organize according <i>To</i> & <i>From</i> relationship on ER objects.
      */
      enum PLMExchangeStreamFilter
      {
        WITH_FROM_ON_VPM = 0x00000001
      , WITH_TO_ON_VPM   = 0x00000002
      , WITH_FROM_ON_ER  = 0x00000004
      , WITH_TO_ON_ER    = 0x00000008

      , Debug            = 0xFFFFFFFF  // All filters activated.
      , VPMObjectOnly    = 0x00000003  // WITH_FROM_ON_VPM|WITH_TO_ON_VPM
      , ERObjectOnly     = 0x0000000C  // WITH_FROM_ON_ER|WITH_TO_ON_ER
      } ;

    /**
      * Build object organization.
      *
      * <b>Role:</b> Build an object organization based on object <b>From</b> and <b>To</b> relationships.
      *
      * @param ixRoot
      *   Root object to be scanned for improving objects' organization.
      *
      * @param inOption
      *   Defines organization options.
      *
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>   <dd>Organization has been properly set.</dd>
      * <dt>E_FAIL</dt> <dd>Process has been stop due an error.</dd>
      * </dl>
      */
      static HRESULT OrganizeObjectHierachy( PLMExchangeNode * ixRoot , int inOption = WITH_FROM_ON_VPM ) ;

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
      * Fill attribute to stream.
      *
      * <br><b>Role</b>: Add in the write buffer attributes.
      * 
      * @param iStreamBuffer
      *   XML write buffer.
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
      // --- * _xFromObject      Object Owner or From Object.
      // --- * _xToObject        Reference object for an instance or To Object.

    /** Object Owner or From Object. */
      PLMExchangeObject      * _xFromObject     ;

    /** Reference object for an instance or To Object. */
      PLMExchangeObject      * _xToObject       ;

} ;
#endif
 
