#ifndef CATPLMMinorVersioningMode_H
#define CATPLMMinorVersioningMode_H

/**
 * @level Protected
 * @usage U3
 */

/**
 * Description of the two modes for new minor version.
 * <dt> <code>Classical</code>                                <dd> The default use mode.
 * <ul>
 * <li> The operation will concern a creation of minor from any component (minor) in the major family.</li>
 * <li> It can be any minor and will belong to the same major family</li>
 * <li> The current version in client session is not changed. No modification is performed in the authoring session.</li>
 * </ul>
 * <dt> <code>WithSessionModification</code>                         <dd> Advanced use.
 * <ul>
 * <li> The operation will concern a creation of minor from any component (minor) in the major family.</li>
 * <li> It can be any minor and will belong to the same major family</li>
 * <li> The data of the new minor  will be initialized from the old minor provided.</li>
 * <li> It results in a new minor of the component in the session, which will be agregated to the same instance 
 * as the previous minor.</li>
 * <li> These operations will be propagated to the server on next @href CATIPLMSaveEngine#Save call.</li> 
 * </ul>
 */

namespace CATPLMMinorVersioningMode {
  enum MinorVersioningMode { Classical=1, WithSessionModification=2 };
}

#endif
