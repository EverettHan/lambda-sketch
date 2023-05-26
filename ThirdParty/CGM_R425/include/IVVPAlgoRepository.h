//-----------------------------------------------------------------------------
// Copyright Dassault Systemes 2019
//-----------------------------------------------------------------------------
#ifndef IVVPAlgoRepository_H
#define IVVPAlgoRepository_H

#include "CATVisItf.h"

#include <array>
#include <map>
#include <memory>
#include <mutex>
class IVVPMatrixAlgo;
class IVVPViewProjMatrixAlgo;
class l_CATSupport;

//=============================================================================
/**
 * IVVPRole
 */
enum class IVVPRole : char {
  main = 0,
  left,
  right,
  InnerLeft,
  InnerRight
};


//=============================================================================
/**
 * IVVPAlgoRepository
 */
class ExportedByCATVisItf IVVPAlgoRepository
{
public:

  /** */
  static IVVPAlgoRepository& Instance();

  /** */
  std::shared_ptr<IVVPMatrixAlgo> GetVPMatrixAlgo(l_CATSupport const* iSupport, IVVPRole iRole) const;
  std::shared_ptr<IVVPViewProjMatrixAlgo> GetVPViewProjMatrixAlgo(l_CATSupport const* iSupport, IVVPRole iRole) const;

public:

  /** */
  void RegisterMatrixAlgo(l_CATSupport const* iSupport, IVVPRole iRole, std::shared_ptr<IVVPMatrixAlgo> const& iAlgo);
  void RegisterViewProjMatrixAlgo(l_CATSupport const* iSupport, IVVPRole iRole, std::shared_ptr<IVVPViewProjMatrixAlgo> const& iAlgo);

  /** */
  void UnregisterAll(l_CATSupport const* iSupport);

  /** */
  IVVPAlgoRepository(IVVPAlgoRepository const&) = delete;
  IVVPAlgoRepository& operator=(IVVPAlgoRepository const&) = delete;

private:

  //
  IVVPAlgoRepository() = default;

private:
  
  mutable std::mutex m_matrixAlgoMutex;
  std::map<l_CATSupport const*, std::array<std::weak_ptr<IVVPMatrixAlgo>, 5>> m_supportToMatrixAlgos;

  mutable std::mutex m_viewProjAlgoMutex;
  std::map<l_CATSupport const*, std::array<std::weak_ptr<IVVPViewProjMatrixAlgo>, 5>> m_supportToViewProjAlgos;
};

#endif
