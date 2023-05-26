//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2019
//===================================================================

#ifndef CSIJobField_H
#define CSIJobField_H

#include "CSICommandBinderModule.h"

#include "CSIJobCondition.h"
#include "CSIJobPriority.h"
#include "CSIJobStatus.h"

#include "DSUnicodeString.h"

#include <ctime>
#include <memory>

namespace CSI
{
  class JobCondition;
  class JobInternalField;

  class ExportedByCSIBinderModule JobField
  {
  public:
    virtual ~JobField() = default;

    virtual CATUnicodeString ToString() const;
    virtual bool IsAdmin() const;

  protected:
    JobField(const CATUnicodeString& fieldName);

    template <typename T>
    friend class JobComparisonCondition;
    friend class OrderByField;

    CATUnicodeString fieldName_;
  };

  template <typename T>
  class JobTypedField : public JobField
  {
  public:
    ~JobTypedField() = default;

    JobCondition In(const std::vector<T>& vecObj)
    {
      return JobCondition(std::make_shared<JobInCondition<T>>(*this, vecObj));
    }

    JobCondition operator==(std::nullptr_t obj)
    {
      return JobCondition(std::make_shared<JobEqualCondition<std::nullptr_t>>(*this, obj));
    }

    JobCondition operator==(T obj)
    {
      return JobCondition(std::make_shared<JobEqualCondition<T>>(*this, obj));
    }

    JobCondition operator<(T obj)
    {
      return JobCondition(std::make_shared<JobLTCondition<T>>(*this, obj));
    }

    JobCondition operator<=(T obj)
    {
      return JobCondition(std::make_shared<JobLTECondition<T>>(*this, obj));
    }

    JobCondition operator>(T obj)
    {
      return JobCondition(std::make_shared<JobGTCondition<T>>(*this, obj));
    }

    JobCondition operator>=(T obj)
    {
      return JobCondition(std::make_shared<JobGTECondition<T>>(*this, obj));
    }

  protected:
    JobTypedField(const CATUnicodeString& fieldName)
      : JobField(fieldName)
    {
      // EMPTY
    }

    friend class JobBuiltInField;
    friend class JobInternalField;
  };

  template <typename T>
  class JobAdminField : public JobTypedField<T>
  {
  public:
    ~JobAdminField() = default;
    bool IsAdmin() const override { return true; }

  protected:
    JobAdminField(const CATUnicodeString& fieldName)
      : JobTypedField<T>(fieldName)
    {
      // EMPTY
    }

    friend class JobBuiltInField;
  };

  class JobTenantField : public JobField
  {
  public:
    ~JobTenantField() = default;
    bool IsAdmin() const override { return true; }

    JobCondition In(const std::vector<CATUnicodeString>& vecObj)
    {
      return JobCondition(std::make_shared<JobInCondition<CATUnicodeString>>(*this, vecObj));
    }

    JobCondition operator==(std::nullptr_t obj)
    {
      return JobCondition(std::make_shared<JobEqualCondition<std::nullptr_t>>(*this, obj));
    }

    JobCondition operator==(const CATUnicodeString& obj)
    {
      return JobCondition(std::make_shared<JobEqualCondition<CATUnicodeString>>(*this, ToUpper(obj)));
    }

    JobCondition operator<(const CATUnicodeString& obj)
    {
      return JobCondition(std::make_shared<JobLTCondition<CATUnicodeString>>(*this, ToUpper(obj)));
    }

    JobCondition operator<=(const CATUnicodeString& obj)
    {
      return JobCondition(std::make_shared<JobLTECondition<CATUnicodeString>>(*this, ToUpper(obj)));
    }

    JobCondition operator>(const CATUnicodeString& obj)
    {
      return JobCondition(std::make_shared<JobGTCondition<CATUnicodeString>>(*this, ToUpper(obj)));
    }

    JobCondition operator>=(const CATUnicodeString& obj)
    {
      return JobCondition(std::make_shared<JobGTECondition<CATUnicodeString>>(*this, ToUpper(obj)));
    }

  protected:
    JobTenantField()
      : JobField("tenantId")
    {
      // EMPTY
    }

  private:
    CATUnicodeString ToUpper(const CATUnicodeString& str)
    {
      CATUnicodeString upper = str;
      upper.ToUpper();
      return upper;
    }

    friend class JobBuiltInField;
  };

  class ExportedByCSIBinderModule JobBuiltInField
  {
  public:
    static JobTypedField<CATUnicodeString> JobId;
    static JobTypedField<CATUnicodeString> Pool;
    static JobTypedField<CATUnicodeString> FunctionName;
    static JobTypedField<int> FunctionVersion;
    static JobTypedField<CATUnicodeString> Identifier;
    static JobAdminField<CATUnicodeString> UserName;
    static JobAdminField<CATUnicodeString> UserUUID;
    static JobTenantField TenantId;

    static JobTypedField<JobStatus> Status;
    static JobTypedField<int> TTK;
    static JobTypedField<int> TTL;
    static JobTypedField<JobPriority> Priority;

    static JobTypedField<std::time_t> CreationTime;
    static JobTypedField<std::time_t> ExpectedTime;
    static JobTypedField<std::time_t> SubmissionTime;
    static JobTypedField<std::time_t> FetchTime;
    static JobTypedField<std::time_t> StartingTime;
    static JobTypedField<std::time_t> CompletionTime;
  };

  class ExportedByCSIBinderModule JobCustomField : public JobField
  {
  public:
    JobCustomField(const CATUnicodeString& fieldName);
    ~JobCustomField() = default;

    CATUnicodeString ToString() const override;

    template <class T>
    JobCondition In(const std::vector<T>& vecObj)
    {
      return JobCondition(std::make_shared<JobInCondition<T>>(*this, vecObj));
    }

    template <class T>
    JobCondition operator==(T obj)
    {
      return JobCondition(std::make_shared<JobEqualCondition<T>>(*this, obj));
    }

    template <class T>
    JobCondition operator<(T obj)
    {
      return JobCondition(std::make_shared<JobLTCondition<T>>(*this, obj));
    }

    template <class T>
    JobCondition operator<=(T obj)
    {
      return JobCondition(std::make_shared<JobLTECondition<T>>(*this, obj));
    }

    template <class T>
    JobCondition operator>(T obj)
    {
      return JobCondition(std::make_shared<JobGTCondition<T>>(*this, obj));
    }

    template <class T>
    JobCondition operator>=(T obj)
    {
      return JobCondition(std::make_shared<JobGTECondition<T>>(*this, obj));
    }
  };

  enum class Order
  {
    asc = 0,
    desc = 1
  };

  class OrderByField
  {
  public:
    OrderByField() = default;

    OrderByField(const JobField& field, Order order)
      : field_(field.fieldName_)
      , order_(order)
      , isAdmin_(field.IsAdmin())
    {
    }

    ~OrderByField() = default;

    OrderByField(const OrderByField&) = default;
    OrderByField(OrderByField&&) = default;
    OrderByField& operator=(const OrderByField&) = default;
    OrderByField& operator=(OrderByField&&) = default;

    const CATUnicodeString& GetFieldName() const { return field_; }
    Order GetOrder() const { return order_; }
    bool IsAdmin() const { return isAdmin_; }

  private:
    CATUnicodeString field_;
    Order order_ = Order::asc;
    bool isAdmin_ = false;
  };

} // namespace CSI

#endif
