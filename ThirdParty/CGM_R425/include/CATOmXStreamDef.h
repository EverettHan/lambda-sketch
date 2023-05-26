#ifndef CATOmXStreamDef_h
#define CATOmXStreamDef_h
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005
/**
 * @level Private
 * @usage U3
 */
/* 
* @COPYRIGHT DASSAULT SYSTEMES 2004
* ----------------------------------------------------------------------------------------------------------------------
*   Origin              : Local running (inside wintop) of remote persistency entity 
*                            associative kernel change/data set of ... actors ...
*                            made as simple as possible to be affordable for enhanced infrastructure integration
*   Software's Category : Physical Layer (Middleware services) dedicated to client side
*                            (in a kind of software classification similar to the layered OSI Network 
*                             upper (logical) Layer is mainly about two main axis  (
*                                  Modeler (domain) specialisation (for Data and Attributes ...)
*                                  Upper Levering Operand Integration exchange (QEOPS, 
*   Premilinary         : Do not forget to contact your Database Administrators or any other representative
*                            (Authoring definition) for more convenient support 
*                          (Just to be sure that appropriate schema (Table for Data , or Services) are supported 
*                              when reference persistency occured when dealing with local work realized  )
*   Specification       : Simple genuine (re-usable) services about 
*                            - associativity between local insulated implementation and shared remote repository
*                            - synthetic change set (persistency intents)
*   Limitations         : No attributes vocabulary provided to let this current functional component software 
*                              be as comprehensible in specifications
*                         Status is slaved to Modelers deployement and Behaviors
*                             for more detailled specification (UML sequence diagram, statechart, ..)  
*                             consult specialized specifications database relative to upper Logical Software layer 
*                             it means Product Structure Legacy, PLM Client Core, Representation Model
*   Favorites entry-point for developpers :
*                         CATPLMRepositoryName : Repository classification 
*                         CATProxySpace   : Instance of a domain resolution                    
*                         CATComponentId  : Handle on primary associativity between local and remote entity           
* ------------------ ----------------------------------------------------------------------------------------------------
*/
/** 
 * Define the direction of the stream.
 * @param CATOmXStreamAccess_ReadOnly
 *    The stream is read and cannot be written.
 * @param CATOmXStreamAccess_WriteOnly
 *    The stream is written and not read.
 * @param CATOmXStreamAccess_ReadWrite
 *    The stream can be written and read.
 */
enum CATOmXStreamAccess 
{
  CATOmXStreamAccess_ReadOnly  = +28,
  CATOmXStreamAccess_WriteOnly = +11,
  CATOmXStreamAccess_ReadWrite = +66
};


/** 
 * Define how internal location of stream is managed.
 * @param CATOmXStreamStorage_istream
 *    The stream is managed through C++ istream
 * @param CATOmXStreamStorage_ostream
 *    The stream is managed through C++ ostream
 * @param CATOmXStreamStorage_FileName
 *    The stream is managed through explicit pathName and C library.
 * @param CATOmXStreamStorage_memory
 *    The stream is managed inside memory  
 * @param CATOmXStreamStorage_CATStream
 *    The stream is managed through System API  
 */
enum CATOmXStreamStorage 
{ 
  CATOmXStreamStorage_FileName = +78,
  CATOmXStreamStorage_memory   = +57,
  CATOmXStreamStorage_CATStream = +66,
  CATOmXStreamStorage_LockBytes = +67,
  CATOmXStreamStorage_Unknown   = 68,
};


/** 
 * Define the encoding of the stream.
 * @param CATOmXStreamEncoding_Binary
 *    The stream is encoded in Binary format
 * @param CATOmXStreamEncoding_XML_like
 *    The stream is encoded in XML like format
 */
enum CATOmXStreamEncoding
{
  CATOmXStreamEncoding_Binary   = +7,
  CATOmXStreamEncoding_NotYetAvailable = 0
};


/** 
 * INTERNAL USE
 * Define version format of the stream.
 * @param CATOmXStreamVersion_V5R17
 *    The stream is defined for V5R17 format.
 * @param CATOmXStreamVersion_R201
 *    The stream is defined for R201 format.
 * @param CATOmXStreamVersion_R202
 *    The stream is defined for R201 format.
 * @param CATOmXStreamVersion_UnknownVersion
 *    The stream is not defined wityh appropriate format.
 */
enum CATOmXStreamVersion 
{ 
  CATOmXStreamVersion_V5R17          = +666,
  CATOmXStreamVersion_R201           = +667,
  CATOmXStreamVersion_R202           = +668,
  CATOmXStreamVersion_R216           = +669,
  CATOmXStreamVersion_UnknownVersion = +6666,
  CATOmXStreamVersion_CurrentSoftwareVersion= +6667
};

#endif

