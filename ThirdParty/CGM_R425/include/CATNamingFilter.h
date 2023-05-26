//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//===========================================================================
//                                                                           
//                                                      
//                                                                           
//  Usage Notes: V4 to V5 naming pattern 
//===========================================================================
//  Creation juin 1999                                 adt              
//===========================================================================
#ifndef _CATNAMIGFILTER
#define _CATNAMIGFILTER
#include "JS0STDLIB.h"
struct CATFilterTable;


class ExportedByJS0STDLIB  CATNamingFilter
{
public:
  CATNamingFilter (){};
  ~CATNamingFilter ();
  int LoadFilter(const char * iPath, int &ligne);
  int ChangeName ( const char *iName, char *&Subsitute);
  
private:
  CATFilterTable *_Table;
};

#endif
  

