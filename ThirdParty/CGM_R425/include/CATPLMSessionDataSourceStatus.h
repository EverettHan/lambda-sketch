#ifndef _CATPLMSessionDataSourceStatus_H
#define _CATPLMSessionDataSourceStatus_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010

/**
 * @level Private
 * @usage U3
 */

 /**
 * <tt> Possible values:</tt>
 * <dl>
 * @param <tt>CATPLMSessionDataSourceStatus_NONE</tt>                 <dd>
 * @param <tt>CATPLMSessionDataSourceStatus_Activated</tt>            <dd>.Is corresponding to a TOS cell Activated
 * @param <tt>CATPLMSessionDataSourceStatus_Destroyed</tt>            <dd>.Is corresponding to a TOS cell Destroyed or Garbaged (undo)
 * @param <tt>CATPLMSessionDataSourceStatus_ForSwitch</tt>            <dd>.Is corresponding to a TOS cell already here in session, to switch
 * </dl>
 */
#if ! defined ( CATPLMSessionDataSourceStatus_definition )
#define CATPLMSessionDataSourceStatus_definition
typedef unsigned int CATPLMSessionDataSourceStatus;
#endif

#define CATPLMSessionDataSourceStatus_Cardinality             3
#define CATPLMSessionDataSourceStatus_NONE           0x00000000
#define CATPLMSessionDataSourceStatus_Activated      0x00000001
#define CATPLMSessionDataSourceStatus_Destroyed      0x00000002
#define CATPLMSessionDataSourceStatus_ForSwitch      0x00000004

#endif

