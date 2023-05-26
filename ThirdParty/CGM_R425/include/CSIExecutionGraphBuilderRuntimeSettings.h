#ifndef CSIExecutionGraphBuilderRuntimeSettings_H
#define CSIExecutionGraphBuilderRuntimeSettings_H

#include "CSICommandBinderModule.h"

namespace CSI
{
  namespace ExecutionGraph
  {
    namespace Builder
    {
      class ProgressEventsImpl;
      class RuntimeSettingsImpl;

      class ExportedByCSIBinderModule RuntimeSettings
      {
      public:
        class ExportedByCSIBinderModule ProgressEvents
        {
        public:
          ProgressEvents();
          ProgressEvents(const ProgressEvents&);
          ProgressEvents& operator=(const ProgressEvents&);
          ProgressEvents(ProgressEvents&&) noexcept;
          ProgressEvents& operator=(ProgressEvents&&) noexcept;
          ~ProgressEvents();

          void SetFlowIn(bool);       // A Block has been called.
          void SetFlowOut(bool);            // A Block has terminated (Success or Error).
          void SetNotPluggedProgress(bool); // A Block has returned an unplugged Progress.
          void SetSelect(bool);             // Connection monitoring (opening, opened, closed).
          void SetTimestamp(bool);          // Add a time to the Progress even

        private:
          friend ProgressEventsImpl& getImpl(const ProgressEvents&);
          ProgressEventsImpl* impl_;
        };

      public:
        RuntimeSettings();
        RuntimeSettings(const RuntimeSettings&);
        RuntimeSettings& operator=(const RuntimeSettings&);
        RuntimeSettings(RuntimeSettings&&) noexcept;
        RuntimeSettings& operator=(RuntimeSettings&&) noexcept;
        ~RuntimeSettings();

        void SetDirectData(bool);
        void SetMultipleCall(bool);
        void SetDefaultTimeout(int);
        void SetProgressEvents(ProgressEvents);

      private:
        friend RuntimeSettingsImpl& getImpl(const RuntimeSettings&);
        RuntimeSettingsImpl* impl_;
      };
    }
  }
}

#endif
