/*
 * Copyright 2020 The TensorFlow Runtime Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//===- types.h --------------------------------------------------*- C++ -*-===//
//
// This file declares types for the 'tfrt' dialect.
//
//===----------------------------------------------------------------------===//

#ifndef TFRT_BASIC_KERNELS_OPDEFS_TYPES_H_
#define TFRT_BASIC_KERNELS_OPDEFS_TYPES_H_

#include "mlir/IR/Types.h"

namespace tfrt {

namespace TFRTTypes {

// TODO(tf-runtime-team): We should register TFRT dialect with MLIR core and
// then use TFRT's enum here.
enum Kind {
  kChain = mlir::Type::FIRST_PRIVATE_EXPERIMENTAL_2_TYPE,
};

}  // namespace TFRTTypes

class ChainType
    : public mlir::Type::TypeBase<ChainType, mlir::Type, mlir::TypeStorage> {
 public:
  using Base::Base;

  static ChainType get(mlir::MLIRContext *context) {
    return Base::get(context, TFRTTypes::kChain);
  }
};

}  // namespace tfrt

#endif  // TFRT_BASIC_KERNELS_OPDEFS_TYPES_H_
