#ifndef CATProxySpaceCategory_H
#define CATProxySpaceCategory_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2008

/**
 * @level Private
 * @usage U3
 */

  /**
 * Definition Data/Change Space Category .
 * <tt> Possible values:</tt>
 * <dl>
 * @param <tt>CatProxySpaceCategory_Associative</tt>    <dd>Full Authoring. Bidirectionnal associativity.
 * @param <tt>CatProxySpaceCategory_Immersive</tt>      <dd>DEPRECATED. Dedicated to 3DLive purpose.
 * @param <tt>CatProxySpaceCategory_Incoming</tt>       <dd>Navigation. Dedicated to Expand/Browse purpose, bidirectinnal associativity but no PC2 memory model.
 * @param <tt>CatProxySpaceCategory_Restricted</tt>     <dd>Internal ("Authoring but not Associative"). Save forbidden, all semantic relations are forced to Broken Remote status.
 * </dl>
 */
enum CATProxySpaceCategory 
{
  CatProxySpaceCategory_Associative,
  CatProxySpaceCategory_Immersive,
  CatProxySpaceCategory_Incoming,
  CatProxySpaceCategory_Restricted
};

#endif
