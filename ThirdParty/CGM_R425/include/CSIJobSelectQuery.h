//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2019
//===================================================================

#ifndef CSIJobSelectQuery_H
#define CSIJobSelectQuery_H

#include "CSICommandBinderModule.h"

#include "CSIJobCondition.h"
#include "CSIJobField.h"

namespace CSI
{
  class ExportedByCSIBinderModule JobSelectQuery
  {
  public:
    JobSelectQuery() = default;
    explicit JobSelectQuery(const JobCondition& cond);

    ~JobSelectQuery() = default;

    JobSelectQuery(const JobSelectQuery&) = default;
    JobSelectQuery& operator=(const JobSelectQuery&) = default;

    bool IsAdmin() const;

    inline const JobCondition& GetCondition() const
    {
      return condition_;
    }

    inline const OrderByField& GetOrderBy() const
    {
      return orderField_;
    }

    inline int GetLimit() const
    {
      return rowCount_;
    }

    inline int GetOffset() const
    {
      return offset_;
    }

    inline bool GetCount() const
    {
      return count_;
    }

    inline bool GetIncludeJobData() const
    {
      return includeJobData_;
    }

    JobSelectQuery& Where(const JobCondition& cond);

    JobSelectQuery& Count(bool count = true);

    JobSelectQuery& IncludeJobData(bool includeJobData = true);

    JobSelectQuery& Limit(int offset, int rowCount);

    JobSelectQuery& OrderBy(const JobField& field, Order order = Order::asc);

  private:
    JobCondition condition_;
    OrderByField orderField_;
    int rowCount_ = 0;
    int offset_ = 0;
    bool count_ = false;
    bool includeJobData_ = false;
  };

} // namespace CSI

#endif
