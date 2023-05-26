#ifndef CATComponentIdStatus_H
#define CATComponentIdStatus_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005

/**
 * @level Private
 * @usage U3
 */

 /**
 * Definition of the possible component's status.
 * <tt> Possible values:</tt>
 * <dl>
 * @param <tt>CATComponentIdStatus_ToCreate</tt>     <dd>Component has to be created.
 * @param <tt>CATComponentIdStatus_ToModify</tt>     <dd>Component is modified.
 * @param <tt>CATComponentIdStatus_ToDelete</tt>     <dd>Component is deleted.
 * @param <tt>CATComponentIdStatus_Loaded</tt>       <dd>Component is loaded but not modified.
 * @param <tt>CATComponentIdStatus_Waiting</tt>      <dd>Component is not loaded.
 * @param <tt>CATComponentIdStatus_Lost</tt>         <dd>Component is deleted and delete operation is committed.
 * @param <tt>CATComponentIdStatus_Invalid</tt>      <dd>otherwise.
 * </dl>
 */
#if ! defined ( CATComponentIdStatus_definition )
#define CATComponentIdStatus_definition
typedef unsigned int CATComponentIdStatus;
#endif

#define CATComponentIdStatus_None                       0x00000000

#define CATComponentIdStatus_All                        0xFFFFFFFF

#define CATComponentIdStatus_ToCreate                   0x00000001 
#define CATComponentIdStatus_ToModify                   0x00000002 
#define CATComponentIdStatus_ToDelete                   0x00000004 
#define CATComponentIdStatus_Loaded                     0x00000008 
#define CATComponentIdStatus_Waiting                    0x00000010 
#define CATComponentIdStatus_Lost                       0x00000020 
#define CATComponentIdStatus_Invalid                    0x00000040 

#endif



