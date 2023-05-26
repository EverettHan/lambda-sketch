//============================================================================= 
// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : QF2
// +R424 level only
//
// Class CATIPGMMultiProcRunner
//=============================================================================
#include "CATGMModelInterfaces.h"
#include "CATCGMVirtual.h"
#include "CATSysErrorDef.h"
#include "CATDataType.h"
#include <memory>

namespace EK {
  class Hypervisor;
  class Context;
}

/**
* Launch multiple processes for CATIPGMMultiProcRunner.
* Usefull to avoid the deletion/creation of multiples nodes between each call.
*
* Memory management through smart pointer life cycle.
*/
class ExportedByCATGMModelInterfaces CATIPGMMultiProcPoolLauncher : public CATCGMVirtual
{

public:

 /**
  * Start hypervisor and launch a pool with any number of subproc node(s)
  * dedicated to the CATIPGMMultiProcRunner.  
  * The pool name is determined internaly.
  *
  * @param iNumberOfNodes
  *   the number of processes to start.
  *
  * Return E_FAIL in case of error.
  */
  virtual HRESULT Launch (EK::Hypervisor & iHypervisor, CATUINT32 iNumberOfNodes = 4) noexcept = 0;

 /**
  * [Optional] Chose your own pool name. 
  * Start hypervisor and launch a chosen named pool with any number of subproc node(s)
  * dedicated to the CATIPGMMultiProcRunner.  
  * @param iPoolName
  *   The name of the pool to be launched.
  *   A Pool is a logical group of Nodes whose role is to perform the same task or part of a computation.
  * @param iNumberOfNodes
  *   the number of processes to start.
  *
  * Return E_FAIL in case of error.
  */
  virtual HRESULT Launch (EK::Hypervisor & iHypervisor, const char * iPoolName, CATUINT32 iNumberOfNodes = 4) noexcept = 0;


 /**
  * Returns the number of launched nodes by <tt>this</tt> Launcher, 
  * according to their poolname. 
  * If @param iPoolName is null, returns the count of all launched nodes,
  * despite their poolname. 
  */
  virtual CATUINT32 GetNumberOfNodes(const char * iPoolName = nullptr) const = 0;



protected:
  
  // Constructor
  CATIPGMMultiProcPoolLauncher() noexcept;

  // Destructor
  virtual  ~CATIPGMMultiProcPoolLauncher();


  // friend declaration
  friend std::default_delete< CATIPGMMultiProcPoolLauncher >;  


  /* forbiden copy constructor*/
  CATIPGMMultiProcPoolLauncher(const CATIPGMMultiProcPoolLauncher & iOther) = delete;
  /* forbiden operator */
  CATIPGMMultiProcPoolLauncher & operator = (const CATIPGMMultiProcPoolLauncher & iOther) = delete;


};

// [ Offical constructor ] 
ExportedByCATGMModelInterfaces
  std::shared_ptr<CATIPGMMultiProcPoolLauncher> CATPGMCreateMultiProcPoolLauncher(EK::Context & iEkContext) noexcept ;


/**
 * idée : Sans pointeur    */
//class CATGMMultiProcPoolLauncherPrivItf;
//
//class ExportedByCATGMModelInterfaces CATGMMultiProcPoolLauncher 
//{
//public:
//
//  CATGMMultiProcPoolLauncher(EK::Context & iEkContext) noexcept;
//
//  virtual ~CATGMMultiProcPoolLauncher();
//
//
//  HRESULT Launch (EK::Hypervisor & iHypervisor, CATUINT32 iNumberOfNodes = 4) noexcept ;
//
//protected:
//   CATGMMultiProcPoolLauncher(const CATGMMultiProcPoolLauncher & iOther) = delete;
//  /* forbiden operator */
//  CATGMMultiProcPoolLauncher & operator = (const CATGMMultiProcPoolLauncher & iOther) = delete;
//
//
//private:
//  std::unique_ptr 
//    <CATGMMultiProcPoolLauncherPrivItf> _impl; // dans /PrivateInterfaces
//};

