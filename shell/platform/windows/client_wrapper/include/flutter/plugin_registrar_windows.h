// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_SHELL_PLATFORM_WINDOWS_CLIENT_WRAPPER_INCLUDE_FLUTTER_PLUGIN_REGISTRAR_WINDOWS_H_
#define FLUTTER_SHELL_PLATFORM_WINDOWS_CLIENT_WRAPPER_INCLUDE_FLUTTER_PLUGIN_REGISTRAR_WINDOWS_H_

#include <flutter_windows.h>

#include <memory>

#include "flutter_view.h"
#include "plugin_registrar.h"

namespace flutter {

// An extension to PluginRegistrar providing access to Windows-specific
// functionality.
class PluginRegistrarWindows : public PluginRegistrar {
 public:
  // Creates a new PluginRegistrar. |core_registrar| and the messenger it
  // provides must remain valid as long as this object exists.
  explicit PluginRegistrarWindows(
      FlutterDesktopPluginRegistrarRef core_registrar)
      : PluginRegistrar(core_registrar) {
    view_ = std::make_unique<FlutterView>(
        FlutterDesktopRegistrarGetView(core_registrar));
  }

  virtual ~PluginRegistrarWindows() = default;

  // Prevent copying.
  PluginRegistrarWindows(PluginRegistrarWindows const&) = delete;
  PluginRegistrarWindows& operator=(PluginRegistrarWindows const&) = delete;

  FlutterView* GetView() { return view_.get(); }

 private:
  // The associated FlutterView, if any.
  std::unique_ptr<FlutterView> view_;
};

}  // namespace flutter

#endif  // FLUTTER_SHELL_PLATFORM_WINDOWS_CLIENT_WRAPPER_INCLUDE_FLUTTER_PLUGIN_REGISTRAR_WINDOWS_H_
