/* Copyright 2023 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_CORE_TFRT_IFRT_IFRT_MODEL_CONTEXT_H_
#define TENSORFLOW_CORE_TFRT_IFRT_IFRT_MODEL_CONTEXT_H_

#include <utility>
#include <vector>

#include "absl/strings/string_view.h"
#include "tensorflow/core/tfrt/ifrt/ifrt_executable_registry.h"

namespace tensorflow {
namespace ifrt_serving {

inline constexpr absl::string_view kIfrtModelContextName = "IfrtModelContext";

// The runtime context for ifrt to be used in TFRT serving.
//
// This class is thread compatible.
class IfrtModelContext {
 public:
  void RegisterHandle(ServingExecutableRegistry::Handle handle) {
    handles_.push_back(std::move(handle));
  }

 private:
  std::vector<ServingExecutableRegistry::Handle> handles_;
};

}  // namespace ifrt_serving
}  // namespace tensorflow

#endif  // TENSORFLOW_CORE_TFRT_IFRT_IFRT_MODEL_CONTEXT_H_
