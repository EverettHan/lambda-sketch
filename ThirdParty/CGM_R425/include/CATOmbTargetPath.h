#ifndef CATOmbTargetPath_H
#define CATOmbTargetPath_H

class CATBaseUnknown;

/**
 * read access on a path
 */
class CATOmbTargetPath
{
public:
  /**
   * return the size of the path
   */
  virtual int GetSize() const = 0;

  /**
   * return i-th element where i is in [ 1, GetSize() ]
   * out of bound access are not supported and may abort the program
   * returned pointer is not AddRef'ed
   */
  virtual CATBaseUnknown* GetItem(int i) const = 0;
};

#endif
