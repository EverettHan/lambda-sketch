#ifndef CATPLMLogStatus_H
#define CATPLMLogStatus_H

/**
* Definition of the possible status on a todo item.
* <tt> Possible values:</tt>
* <dl>
* @param <tt>CATPLMLogStatusError</tt>
* @param <tt>CATPLMLogStatusNull</tt>
* @param <tt>CATPLMLogStatusCreated</tt>   <dd>Object definition is to be created in database.
* @param <tt>CATPLMLogStatusModified</tt>  <dd>Object definition is to be modified in database.
* @param <tt>CATPLMLogStatusDeleted</tt>   <dd>Object definition is to be deleted in database..
* </dl>
*/
enum  CATPLMLogStatus
{
  CATPLMLogStatusError = -1,
  CATPLMLogStatusNull = 0,
  CATPLMLogStatusCreated = 1,
  CATPLMLogStatusModified = 2,
  CATPLMLogStatusDeleted = 3
};

#endif
