#ifndef CATApproxMarshMultiRes_h
#define CATApproxMarshMultiRes_h
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2019
//

#include "MathAdvMarsh.h"
#include "CATMathInterval.h"
#include "CATCGMInterruptDef.h"
#include "CATMathDebugFactory.h"
class CATMathPoint;
class CATMathMarshFunction;
class CATMathMarshSolver;
class CATMathStructuralConstraint;
class CATMathMarshExternFunction;
class CATMathMarshMetric;
class CATMathTransformation;

#define JumpImplemented

class ExportedByMathAdvMarsh  CATApproxMarshMultiRes
{
  public:

  
     /**
    * Destructor
    */
    virtual ~CATApproxMarshMultiRes();


    virtual int SetData(const CATMathPoint* Input, const CATMathPoint* iTraget, const int NbrConstraints, const double iRadius, const double iResolution, 
                        const CATMathStructuralConstraint* iStructuralConstraint = NULL, const int NbStructuralConstraints = 0, const int NbConstraintsToKeep=0 ) = 0;

    virtual void SetMaxLevel(const short iMaxLevel) = 0;

    virtual void SetAnisotropy(CATMathTransformation * iInvAnisotropy) = 0;

#ifdef JumpImplemented
    virtual void SetJump(CATMathMarshFunction* iJump) = 0;
    //virtual void SetFaultJump(CATMathMarshFunction* iJump) = 0;
#endif
    virtual void SetOrderForSolve(const short iOrder) = 0;

    virtual void SetRadiusSmoothing(const double iRSmooth) = 0;
    
    /**
    * Return the function result 
    */
    virtual  CATMathMarshFunction* GetResult() = 0;

    virtual double GetDeltaSmooth() const = 0;

    /**
    * Compute the complete interpolation function
    */
    virtual int Run() = 0;

    /**
    * Return the max distance between the interpolation and the mesh
    */
    virtual int GetIndexOfResiduMax() = 0;
    
    virtual int SetTolAbsolute(const double iTol) = 0;
    virtual int SetTolRelative (const double iTol) = 0;
    virtual int SetInterval(CATMathInterval& iAreaOfInterest) = 0;
    virtual int SetCCFactor(const double iCCFactor) = 0;
    virtual void SetAuthorisedValueDeviationForSmoothing(const double iAuthorisedValueDeviationForSmoothing) = 0;
       

    virtual int SetDensityFirstLevel(const int iLevel) = 0;

    virtual void SetAnisotropyScale( const double iAnisotropyScale) = 0;

    virtual void SetRetryIsAllowed(const CATBoolean iReTryIsAllowed) = 0;

    virtual int SetExternalKernel(CATMathMarshExternFunction * iESE, const double iCfNormalisation=1.0) = 0;

    // Warning experimental Methode
    virtual int SetMetric(CATMathMarshMetric*    iMetric) = 0;

    virtual void SetDebugFactory(CATMathDebugFactory* debugFactory) = 0;

    virtual int FreezeScale(const CATMathPoint& iCenter, double iScale) = 0;

    virtual double GetTolAbsolute() const = 0;
    virtual double GetTolRelative () const = 0;
    virtual double GetAuthorisedValueDeviationForSmoothing () const = 0;

    
    virtual void SetNbMaxThreads(const int iNbMaxThreads) = 0;

    virtual int SetProgressBarFunction(CATCGMInterruptFunction ipInterruptFunction, const double iStartRatio=0, const double iEndRatio=100) = 0;

    virtual int GetNbMaxThreads()const = 0;

    virtual int UsePUM(bool iSwitch = true) = 0;

    virtual bool GetUsePUM() const = 0;

    static  CATApproxMarshMultiRes* CreateApproxMarshMultiRes(const double iResolution);
    


  protected:
    CATApproxMarshMultiRes();


};
#endif


