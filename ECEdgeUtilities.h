#ifndef ECEdgeUtilities_H
#define ECEdgeUtilities_H

#include <CATSysBoolean.h>
#include <CATCollec.h>
#include <ListVOfLong.h>

class CATEdge;
class CATBody;
class CATCell;
class CATListPtrCATCell;

class  ECEdgeUtilities
{
public:
    static  CATBoolean  IsLaminar(  CATEdge * iEdge,
                                    CATBody * iBody,
                                    CATLISTP(CATCell)  * oFaceList = NULL )  ;

};
#endif //ECEdgeUtilities_H
