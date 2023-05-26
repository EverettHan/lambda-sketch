//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2019
//===================================================================

#ifndef CSIJobCondition_H
#define CSIJobCondition_H

#include "CSICommandBinderModule.h"

#include "CSIJobPriority.h"
#include "CSIJobStatus.h"
#include "CSITemplateExport.h"

#include "JSONJOStream.h"

#include "DSUnicodeString.h"

#include <ctime>
#include <memory>
#include <type_traits>

#define TemplateClassExport

#if (defined(_LINUX_SOURCE) || defined(_DARWIN_SOURCE) || defined(_ANDROID_SOURCE))
#undef TemplateClassExport
// - For some reason, despise the extern template instantiation declaration, gcc/clang do not export the
//   JobEqualCondition/JobLTCondition/... class instances if we don't explicitly set the visibility of the classes.
// - On windows if we export the class the compiler complains that export + extern are redundant, so we leave it blank
#define TemplateClassExport __attribute__((visibility("default")))
#endif

#define CSIDeclareCondition(ClassName) \
  extern template TemplateDeclExport class ClassName<CATUnicodeString>; \
  extern template TemplateDeclExport class ClassName<JobStatus>; \
  extern template TemplateDeclExport class ClassName<JobPriority>; \
  extern template TemplateDeclExport class ClassName<int32_t>; \
  extern template TemplateDeclExport class ClassName<uint32_t>; \
  extern template TemplateDeclExport class ClassName<int64_t>; \
  extern template TemplateDeclExport class ClassName<uint64_t>; \
  extern template TemplateDeclExport class ClassName<std::time_t>; \
  extern template TemplateDeclExport class ClassName<double>; \
  extern template TemplateDeclExport class ClassName<float>;

  // time_t being a long on linux/android, compiler complains that template was already instantiated for long
#if (defined(_LINUX_SOURCE) || defined(_ANDROID_SOURCE))
#undef CSIDeclareCondition
#define CSIDeclareCondition(ClassName) \
  extern template TemplateDeclExport class ClassName<CATUnicodeString>; \
  extern template TemplateDeclExport class ClassName<JobStatus>; \
  extern template TemplateDeclExport class ClassName<JobPriority>; \
  extern template TemplateDeclExport class ClassName<int32_t>; \
  extern template TemplateDeclExport class ClassName<uint32_t>; \
  extern template TemplateDeclExport class ClassName<int64_t>; \
  extern template TemplateDeclExport class ClassName<uint64_t>; \
  extern template TemplateDeclExport class ClassName<double>; \
  extern template TemplateDeclExport class ClassName<float>;
#endif

#define CSIDeclareJobComparisonCondition(ClassName) \
  extern template TemplateDeclExport class ClassName<const char*>; \
  CSIDeclareCondition(ClassName);

namespace CSI
{
  class JobField;
  template <class T>
  class JobTypedField;
  class JobConditionImpl;

  class ExportedByCSIBinderModule JobCondition
  {
  public:
    JobCondition() = default;
    ~JobCondition() = default;

    JobCondition(const JobCondition&) = default;
    JobCondition& operator=(const JobCondition&) = default;

    JSON::JOStream ToJSON() const;

    bool IsEmpty() const;

    bool IsAdmin() const;

    JobCondition operator&&(const JobCondition& cond) const;

    JobCondition operator||(const JobCondition& cond) const;

    friend ExportedByCSIBinderModule JobCondition operator!(const JobCondition& cond);

  protected:
    explicit JobCondition(std::shared_ptr<JobConditionImpl> condImpl)
      : jobCondImpl_(std::move(condImpl))
    {
    }

    template <typename T>
    friend class JobTypedField;
    friend class JobTenantField;
    friend class JobCustomField;

    std::shared_ptr<JobConditionImpl> jobCondImpl_;
  };

  ExportedByCSIBinderModule JobCondition operator!(const JobCondition& cond);

  class ExportedByCSIBinderModule JobConditionImpl
  {
  public:
    virtual ~JobConditionImpl() = default;

    virtual JSON::JOStream ToJSON() const = 0;

    virtual bool IsAdmin() const = 0;

  protected:
    JobConditionImpl() = default;

    template <class T>
    static JSON::JOStream makeComparison(const CATUnicodeString& key, const char* op, const T& obj);

    static JSON::JOStream makeComparison(const CATUnicodeString& key, const char* op, std::time_t obj);

    static JSON::JOStream makeComparison(const CATUnicodeString& key, const char* op, JobStatus obj);

    static JSON::JOStream makeComparison(const CATUnicodeString& key, const char* op, JobPriority obj);
  };

  class ExportedByCSIBinderModule JobLogicalConditionImpl : public JobConditionImpl
  {
  public:
    ~JobLogicalConditionImpl() = default;

    bool IsAdmin() const override;

  protected:
    JobLogicalConditionImpl(const JobCondition& left, const JobCondition& right);

    JobCondition left_;
    JobCondition right_;
  };

  class ExportedByCSIBinderModule JobAndConditionImpl : public JobLogicalConditionImpl
  {
  public:
    JobAndConditionImpl(const JobCondition& left, const JobCondition& right);
    ~JobAndConditionImpl() = default;

    JSON::JOStream ToJSON() const override;
  };

  class ExportedByCSIBinderModule JobOrConditionImpl : public JobLogicalConditionImpl
  {
  public:
    JobOrConditionImpl(const JobCondition& left, const JobCondition& right);
    ~JobOrConditionImpl() = default;

    JSON::JOStream ToJSON() const override;
  };

  class ExportedByCSIBinderModule JobNotConditionImpl : public JobConditionImpl
  {
  public:
    JobNotConditionImpl(const JobCondition& cond);
    ~JobNotConditionImpl() = default;

    JSON::JOStream ToJSON() const override;

    bool IsAdmin() const override;

  protected:
    JobCondition cond_;
  };

  template <typename T>
  class TemplateClassExport JobInCondition : public JobConditionImpl
  {
  public:
    JobInCondition(const JobField& field, const std::vector<T>& vecVal);
    JobInCondition(const JobField& field, std::vector<T>&& vecVal);
    ~JobInCondition();

    JSON::JOStream ToJSON() const override;

    bool IsAdmin() const override;

  protected:
    CATUnicodeString field_;
    std::vector<T> vecVal_;
    bool isAdmin_;
  };

  template <typename T>
  class TemplateClassExport JobComparisonCondition : public JobConditionImpl
  {
  public:
    ~JobComparisonCondition();

    bool IsAdmin() const override;

  protected:
    JobComparisonCondition(const JobField& field, T val);

    CATUnicodeString field_;
    T val_;
    bool isAdmin_;
  };

  template <typename T>
  class TemplateClassExport JobEqualCondition : public JobComparisonCondition<T>
  {
  public:
    JobEqualCondition(const JobField& field, T val);
    ~JobEqualCondition();

    JSON::JOStream ToJSON() const override;
  };

  template <>
  class TemplateClassExport JobEqualCondition<JobStatus> : public JobComparisonCondition<JobStatus>
  {
  public:
    JobEqualCondition(const JobField& field, JobStatus val);
    ~JobEqualCondition();

    JSON::JOStream ToJSON() const override;
  };

  template <>
  class TemplateClassExport JobEqualCondition<JobPriority> : public JobComparisonCondition<JobPriority>
  {
  public:
    JobEqualCondition(const JobField& field, JobPriority val);
    ~JobEqualCondition();

    JSON::JOStream ToJSON() const override;
  };

  template <>
  class TemplateClassExport JobEqualCondition<std::nullptr_t> : public JobComparisonCondition<std::nullptr_t>
  {
  public:
    JobEqualCondition(const JobField& field, std::nullptr_t val);
    ~JobEqualCondition();

    JSON::JOStream ToJSON() const override;
  };

  template <>
  class TemplateClassExport JobEqualCondition<std::time_t> : public JobComparisonCondition<std::time_t>
  {
  public:
    JobEqualCondition(const JobField& field, std::time_t val);
    ~JobEqualCondition();

    JSON::JOStream ToJSON() const override;
  };

  template <typename T>
  class TemplateClassExport JobLTCondition : public JobComparisonCondition<T>
  {
  public:
    JobLTCondition(const JobField& field, T val);
    ~JobLTCondition();

    JSON::JOStream ToJSON() const override;
  };

  template <typename T>
  class TemplateClassExport JobLTECondition : public JobComparisonCondition<T>
  {
  public:
    JobLTECondition(const JobField& field, T val);
    ~JobLTECondition();

    JSON::JOStream ToJSON() const override;
  };

  template <typename T>
  class TemplateClassExport JobGTCondition : public JobComparisonCondition<T>
  {
  public:
    JobGTCondition(const JobField& field, T val);
    ~JobGTCondition();

    JSON::JOStream ToJSON() const override;
  };

  template <typename T>
  class TemplateClassExport JobGTECondition : public JobComparisonCondition<T>
  {
  public:
    JobGTECondition(const JobField& field, T val);
    ~JobGTECondition();

    JSON::JOStream ToJSON() const override;
  };

  CSIDeclareCondition(JobInCondition);

  CSIDeclareJobComparisonCondition(JobComparisonCondition);
  extern template TemplateDeclExport class JobComparisonCondition<std::nullptr_t>;
  extern template TemplateDeclExport class JobComparisonCondition<bool>;

  CSIDeclareJobComparisonCondition(JobEqualCondition);
  extern template TemplateDeclExport class JobEqualCondition<std::nullptr_t>;
  extern template TemplateDeclExport class JobEqualCondition<bool>;

  CSIDeclareJobComparisonCondition(JobLTCondition);
  CSIDeclareJobComparisonCondition(JobLTECondition);
  CSIDeclareJobComparisonCondition(JobGTCondition);
  CSIDeclareJobComparisonCondition(JobGTECondition);
} // namespace CSI

#endif
