#ifndef _CATPLMAsyncTaskStatus_H
#define _CATPLMAsyncTaskStatus_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @level Private
 * @usage U3
 */

 /**
 * <tt> Possible values:</tt>
 * <dl>
 * @param <tt>CATPLMAsyncTaskStatus_NONE</tt>                 <dd>unset status.
 * @param <tt>CATPLMAsyncTaskStatus_AsyncDone</tt>            <dd>asynchronous operation has succeed.
 * @param <tt>CATPLMAsyncTaskStatus_AsyncFailure</tt>         <dd>asynchronous operation has fail.
 * @param <tt>CATPLMAsyncTaskStatus_Committed</tt>            <dd>asynchronous operation is committed.
 * @param <tt>CATPLMAsyncTaskStatus_Aborted</tt>              <dd>asynchronous operation is aborted.
 * </dl>
 */
#if ! defined ( CATPLMAsyncTaskStatus_definition )
#define CATPLMAsyncTaskStatus_definition
typedef unsigned int CATPLMAsyncTaskStatus;
#endif

#define CATPLMAsyncTaskStatus_Cardinality          4
#define CATPLMAsyncTaskStatus_NONE                 0x00000000
#define CATPLMAsyncTaskStatus_AsyncDone            0x00000001
#define CATPLMAsyncTaskStatus_AsyncFailure         0x00000002
#define CATPLMAsyncTaskStatus_Committed            0x00000004
#define CATPLMAsyncTaskStatus_Aborted              0x00000008

#endif
