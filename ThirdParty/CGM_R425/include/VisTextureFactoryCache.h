#ifndef VISTEXTUREFACTORYCACHE_H_
#define VISTEXTUREFACTORYCACHE_H_
#include "VisPrivateServices.h"
#include <string>

class ExportedByVisPrivateServices VisTextureFactoryCache
{
public:
  /**
   * Remove a texture from the cache
   *
   * @param iFileName the path of the texture to remove
   * @return true on success, false otherwise
   */
  static bool RemoveFromCache(const std::string &iFileName);

  /**
  * Remove all unused item. Call this method from Main thread. 
  *
  */
  static void CleanUnusedItems();


  /**
  *@return the number of item inside the cache
  */
  static unsigned int GetNumberOfItems();
};


#endif //VISTEXTUREFACTORYCACHE_H_
