#ifndef CATAdpProtectedLinkFilteringMode_H
#define CATAdpProtectedLinkFilteringMode_H

/**
* @level Protected
* @usage U1
*/

/**
  * Choose which links to retrieve.
  *  <br><b>Role:</b>Description of the available modes defining the type of link filtering which
  *  will be applied through an open/expand request.
  *  Please refer to @href CATAdpProtectedCompletionParameters for options/usage.
  *  <dt> <code><b>AllLinks</b></code>          <dd> All the links are retrieved </dd>
  *  <dt> <code><b>OnlyRelevantLinks</b></code> <dd> Only relevant links are retrieved  </dd>
  *  <dt> <code><b>NoLinks</b></code>           <dd> No links are retrieved </dd>
  *
  */

enum class CATAdpProtectedLinkFilteringMode
{
  AllLinks = 0,
  OnlyRelevantLinks = 1,
  NoLinks = 2
};

#endif
