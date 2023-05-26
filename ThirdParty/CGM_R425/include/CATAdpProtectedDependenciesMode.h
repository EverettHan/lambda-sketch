#ifndef CATADPPROTECTEDDEPENDENCIESMODE_H_
#define CATADPPROTECTEDDEPENDENCIESMODE_H_

/**
* @level Protected
* @usage U1
*/

/**
  * Choose which dependency level to retrieve.
  *  <br><b>Role:</b>Description of the available modes defining the level of dependencies
  *  to be retrieved through an open/expand request.
  *  Please refer to @href CATAdpProtectedCompletionParameters for options/usage.
  *  <dl><dt><code><b>Default</b></code>  <dd>Modeler defined, mostly equivalent to FullModel.</dd>
  *      <dt><code><b>Strict</b></code>   <dd>No navigation to dependencies is made.</dd>
  *      <dt><code><b>FullModel</b></code><dd>All modeler dependencies are retrieved.</dd></dl>
  */
namespace CATAdpProtectedDependenciesMode
{
  enum DependenciesMode
  {
    Default,
    Strict,
    FullModel,
    SmartOpen
  };
}
#endif /* CATADPPROTECTEDDEPENDENCIESMODE_H_ */
