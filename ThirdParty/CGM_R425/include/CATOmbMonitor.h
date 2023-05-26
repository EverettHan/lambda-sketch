#ifndef __CATOmbMonitor_h__
#define __CATOmbMonitor_h__
#include "CATDataType.h"
/**
 * do not use directly this class use counter definition file
 */
#if defined(__CATOmbMonitor)
#define ExportedByCATOmbMonitor DSYExport
#else
#define ExportedByCATOmbMonitor DSYImport
#endif
#include "DSYExport.h"

/**
 * @level Private
 * @usage U1
 */

class ExportedByCATOmbMonitor CATOmbMonitor {
public:
  typedef unsigned Id;
  typedef unsigned Number;
  struct Counter {
    const char *v_name;  // not duplicated by Get/NextValue
    Number v_counter;    //
    CATULONG64 v_add;    // 
  };
  
  /**
  * Update the counter.
  * O(1)
  * @param id the counter
  * @param add the value to add to counter 
  */
  static unsigned Add(const Id id,const Number  add); 
  /*
  * return value and iterate to next counter;
  * Id iter = 0;
  * Counter out;
  * while( NextValue(iter,out) ) {
  *     ...:
  * }
  * @param current selected counter
  * @param out the returned structure
  * @param min_counter filter all null counter
  * @return 0 if no more value
  */
  static int NextValue(Id &current, Counter &out, const  Number min_counter = 1) ;
};

#endif
