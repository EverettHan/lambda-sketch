#pragma once

#include "SGInfra.h"

#include <memory>
#include <vector>

constexpr unsigned int c_MaxCustomPassFilters = 16;

class ExportedBySGInfra CustomPassFilter
{
  friend class CustomPassRenderSGDesc;
  friend class CustomPassManager;

public:
  using value = unsigned int;

  static CustomPassFilter Generate();
  static unsigned int     GetUsedFilterNumber();

  CustomPassFilter();
  CustomPassFilter(const CustomPassFilter& iFilter);
  ~CustomPassFilter();

  value Value() const;
  
private:
  CustomPassFilter(std::shared_ptr<value> iValue);
  CustomPassFilter(unsigned int iValue);

  std::shared_ptr<value>                   m_Value;
  static std::vector<std::weak_ptr<value>> s_UsedIDs;
};
