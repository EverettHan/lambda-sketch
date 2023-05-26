#ifndef CATPLMTosBasicTimeLineEvents_H
#define CATPLMTosBasicTimeLineEvents_H
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
 * @param <tt>CATPLMTosBasicTimeLineEvent_ToCreate</tt>     <dd>Component has to be created.
 * @param <tt>CATPLMTosBasicTimeLineEvent_ToDelete</tt>     <dd>Component is deleted.
 * </dl>
 */
typedef unsigned int CATPLMTosBasicTimeLineEvents;

#define CATPLMTosBasicTimeLineEvent_ToCreate                   0x00000001 
#define CATPLMTosBasicTimeLineEvent_ToDelete                   0x00000002 

#endif



