//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
#ifndef  PLMExchangeNotification_h
#define  PLMExchangeNotification_h
// COPYRIGHT DASSAULT SYSTEMES 2012-2015
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
//    Base class for a simple object hierarchical model
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    Class that enables to define one  Notification;
//    it could be an Error, warning, information messages or other kind.
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
//   Revision 1.0  March     2007  (JLM) Initial Revision from ENORepNode
//   Revision 2.0  December  2012  (JLM) Duplication to implement Exchange Experience Model 
//   Revision 2.1  September 2015  (JLM) Exposed some tags to be shared by application 
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

// --- Define application constant
// --- * List of defined notification types.

/** Constant value to define an unknown notification.     */
#define PLMExchangeUnknownNotification     0x00000000
/** Constant value to define a simple trace notification. */
#define PLMExchangeTraceNotification       0x00000001
/** Constant value to define a debug trace notification.  */
#define PLMExchangeDebugNotification       0x00000002
/** Constant value to define an information notification. */
#define PLMExchangeInformationNotification 0x00000004
/** Constant value to define a warning notification.      */
#define PLMExchangeWarningNotification     0x00000008
/** Constant value to define an error notification.       */
#define PLMExchangeErrorNotification       0x00000010
/** Constant value to define a fatal error notification.  */
#define PLMExchangeFatalNotification       0x00000020

// --- Class definition

/**
  * Class representing one notification.
  *
  * <b>Role</b>:
  * Notification enables to manage information relative to a process to report error, trace or warning messages.
  */
class ExportedByPLMExchangeModel PLMExchangeNotification : public PLMExchangeNode
{
   public:

    /**
      * Constructs an Assembly relation.
      * 
      * @param ixFather
      *   Father node that aggregates node to be created.
      */
      PLMExchangeNotification( PLMExchangeBasicNode * ixFather = NULL ) ;          

    /**
      * Destructor.
      * 
      * <br><b>Role</b>: Destructor.
      */
      ~PLMExchangeNotification() ;

    /**
      * Copy constructor.
      * 
      * @param ixNode
      * Object to be duplicated.
      */
      PLMExchangeNotification( const PLMExchangeNotification & ixNode ) ;

    /**
      * Assignment operator from another object node.
      * 
      * @param ixNode
      * Object used as reference for the assignment.
      */
      PLMExchangeNotification & operator=( const PLMExchangeNotification & ixNode ) ;

      // -------------------------------------------
      // --- Manage services
      // -------------------------------------------

    /**
      * Sets notification information.
      *
      * <br><b>Role</b>: Sets notification information.
      * 
      * @param inType
      *  Notification type.
      * <br><b>Legal values</b>: It can be set to either:
      * <dl>
      * <dt>PLMExchangeTraceNotification</dt>       <dd>Simple trace notification. </dd>
      * <dt>PLMExchangeDebugNotification</dt>       <dd>Debug trace notification.</dd>
      * <dt>PLMExchangeInformationNotification</dt> <dd>Information notification.</dd>
      * <dt>PLMExchangeWarningNotification</dt>     <dd>Warning notification.</dd>
      * <dt>PLMExchangeErrorNotification</dt>       <dd>Error notification.</dd>
      * <dt>PLMExchangeFatalNotification</dt>       <dd>Fatal error notification.</dd>
      * </dl>
      * 
      * @param icErrorId
      *  Error name.
      * 
      * @param icMessage
      *  NLS notification message.
      * 
      * @return
      *  Return Code. 
      */
      HRESULT SetNotification( int inType , const CATUnicodeString & icErrorId , const CATUnicodeString & icMessage ) ;

    /**
      * Gets attribute value.
      *
      * @param onType
      *  Notification type.
      * <br><b>Legal values</b>: It can be set to either:
      * <dl>
      * <dt>PLMExchangeTraceNotification</dt>       <dd>Simple trace notification. </dd>
      * <dt>PLMExchangeDebugNotification</dt>       <dd>Debug trace notification.</dd>
      * <dt>PLMExchangeInformationNotification</dt> <dd>Information notification.</dd>
      * <dt>PLMExchangeWarningNotification</dt>     <dd>Warning notification.</dd>
      * <dt>PLMExchangeErrorNotification</dt>       <dd>Error notification.</dd>
      * <dt>PLMExchangeFatalNotification</dt>       <dd>Fatal error notification.</dd>
      * </dl>
      * 
      * @param ocErrorId
      *  Error name.
      * 
      * @param ocMessage
      *  NLS notification message.
      * 
      * @return
      *  Return Code. 
      */
      HRESULT GetNotification( int & onType , CATUnicodeString & ocErrorId , CATUnicodeString & ocMessage ) const ;

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
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>0</dt> <dd>Standard mode.</dd>
      * <dt>1</dt> <dd>One line mode.</dd>
      * </dl>
      */
      void _print( const char * const icInput , const char * const icType , int inMode = 0 ) const ;

      /** XML Tag Notitfication types. */
      static const CATUnicodeString usTraceNotificationTag       ;
      static const CATUnicodeString usDebugNotificationTag       ;
      static const CATUnicodeString usInformationNotificationTag ;
      static const CATUnicodeString usWarningNotificationTag     ;
      static const CATUnicodeString usErrorNotificationTag       ;
      static const CATUnicodeString usFatalNotificationTag       ;

      /** XML Tag for notification attribute. */
      static const CATUnicodeString usMsgTag                     ;
      static const CATUnicodeString usSeverityTag                ;

      // --- Member definition
      // --- * _cNlsMessage        NLS message.
      // --- * _nNotificationType  Type of notification.

    protected :

    /** NLS message. */
      CATUnicodeString _cNlsMessage       ;

    /** Type of notification. */
      int              _nNotificationType ;
} ;
#endif
 
