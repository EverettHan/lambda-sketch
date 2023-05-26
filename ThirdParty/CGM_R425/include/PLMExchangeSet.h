//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
#ifndef  PLMExchangeSetObject_h
#define  PLMExchangeSetObject_h
/// COPYRIGHT DASSAULT SYSTEMES 2013
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
//    Class that enables to define structure with Set/node paradigm.
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
//   Revision 1.0  July     2013  (JLM) Initial Revision to provide an implementation to set.
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
 * Class representing a basic set.
 *
 * <b>Role</b>:
 *   Define one of the mapping of an object @href PLMExchangeObject.
 */
class ExportedByPLMExchangeModel PLMExchangeSet : public PLMExchangeNode
{
   public:

   /**
     * Constructs one set.
     * 
     * @param ixFather
     *   Father object that aggregates this set.
     */
      PLMExchangeSet( PLMExchangeBasicNode * ixFather = NULL
                    , int                    inType   = PLMExchangeNodeSet ) ;          

   /**
     * Destructor.
     * 
     * <br><b>Role</b>: Destructor.
     */
      ~PLMExchangeSet() ;

    /**
      * Copy constructor.
      * 
      * @param ixNode
      * Object to be duplicated.
      */
      PLMExchangeSet( const PLMExchangeSet & ixNode ) ;

    /**
      * Assignment operator from another object node.
      * 
      * @param ixNode
      * Object used as reference for the assignment.
      */
      PLMExchangeSet & operator=( const PLMExchangeSet & ixNode ) ;

      // -----------------------------------------------
      // --- To support XML streaming                ---
      // -----------------------------------------------

    /**
      * Check if this node need to be streamed.
      *
      * <br><b>Role</b>: Check if this node need to be streamed. and Get XML node name.
      * 
      * @param iXMLFilter
      *   Streaming option to define what need to be streamed.
      * 
      * @param ocXmlNodeName
      *   XML Node name to be used.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>: Returns 0 if node not to be traversed by streaming. 
      */
      int IsValidForPutToStream( int iXMLFilter , CATUnicodeString & ocXmlNodeName ) const ;

   protected :
 } ;
#endif
 
