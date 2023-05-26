// COPYRIGHT Dassault Systemes 2013

#ifndef PLMLinkAccessToolToolbox_H
#define PLMLinkAccessToolToolbox_H

#include "CATObjectModelerBase.h"
#include "CATOmxSR.h"
#include "CATBoolean.h"

class CATIOmbFunction ;
class CATIOmbProxySpecifications ;


enum ExportedByCATObjectModelerBase PLMLinkAccessMode { PLMLinkAccess_UNSET, PLMLinkAccess_ACCESS_DENIED, PLMLinkAccess_READ_ONLY, PLMLinkAccess_READ_WRITE} ;

enum ExportedByCATObjectModelerBase PLMLinkAccessScope { PLMLinkAccess_RELATION, PLMLinkAccess_BUNDLE } ;

struct ExportedByCATObjectModelerBase PLMLinkAccessSolveParameters
{
    PLMLinkAccessSolveParameters () : _unfold (FALSE), _forceLoading (FALSE) {}

    CATBoolean _unfold ;
    CATBoolean _forceLoading ; // To be deployed
    CATOmxSR <CATIOmbFunction> _overloadFunction ;
    CATOmxSR <CATIOmbProxySpecifications> _overloadProxySpecs ;

} ; 

class ExportedByCATObjectModelerBase PLMLinkAccessOperator
{
public :   

    static PLMLinkAccessOperator * Break () ;

    struct Statistics
    {
        Statistics () : _invalidArg (FALSE), _processed (0), _notLoaded (0), _unaccessible (0), _unexpectedErrors (0) {}

        CATBoolean _invalidArg ;
        int _processed, _notLoaded, _unaccessible, _unexpectedErrors ;
    } ;

} ;

#endif

