#ifndef CATOmyBSCTypeDefs_h
#define CATOmyBSCTypeDefs_h

/**
 * @level Private
 * @usage U1
 */


namespace LocalSaveTransaction
{
  enum Mode
  {
    UndefinedMode,
    Valid,
    Broken,
  };
  enum Status
  {
    UndefinedStatus,
    Ok,
    Rolledback,
    Error
  };
}
#endif
