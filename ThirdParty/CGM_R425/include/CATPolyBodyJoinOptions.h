//COPYRIGHT DASSAULT SYSTEMES 2020, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyJoinOptions.h
//
//===================================================================
// September 2020 : F1Z : Creation
//===================================================================
#pragma once

#include "PolyBodyBoolean.h"
#include "CATPolyBodyOverlayOptions.h"

#include <bitset>

namespace PolyOverlay
{
  enum class JoinLevel : unsigned int;
}

class ExportedByPolyBodyBoolean CATPolyBodyJoinOptions : public CATPolyBodyOverlayOptions
{
public:
  CATPolyBodyJoinOptions();
  CATPolyBodyJoinOptions(const CATPolyBodyOverlayOptions & iToCopy);
  CATPolyBodyJoinOptions(const CATPolyBodyJoinOptions& iToCopy);
  ~CATPolyBodyJoinOptions();

  CATPolyBodyJoinOptions& operator=(const CATPolyBodyJoinOptions& iToCopy);

  // Only use border edges by default
  // this options allow the caller to specify the use of all the edges.
  inline void WithInternalEdges(bool iWithInternalEdges = true) { _withInternalEdges = iWithInternalEdges; }

  inline bool IsWithInternalEdges() { return _withInternalEdges; };
  bool IsJoinChangeActive(const PolyOverlay::JoinLevel iChange) const;

private:
  void UpdateLevel();

private:
  // void* instead of std::bitset<PolyOverlay::sJoinNbModifications> to avoid exposing bitset and helpersversioning
  void* _joinLevel;
  bool _withInternalEdges;
};


