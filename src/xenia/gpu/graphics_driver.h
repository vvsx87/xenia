/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_GPU_GRAPHICS_DRIVER_H_
#define XENIA_GPU_GRAPHICS_DRIVER_H_

#include <xenia/core.h>
#include <xenia/gpu/xenos/registers.h>
#include <xenia/gpu/xenos/xenos.h>


namespace xe {
namespace gpu {


class GraphicsDriver {
public:
  virtual ~GraphicsDriver();

  xe_memory_ref memory();
  xenos::RegisterFile* register_file() { return &register_file_; };
  void set_address_translation(uint32_t value) {
    address_translation_ = value;
  }

  virtual void Initialize() = 0;

  virtual void InvalidateState(
      uint32_t mask) = 0;
  virtual void SetShader(
      xenos::XE_GPU_SHADER_TYPE type,
      uint32_t address,
      uint32_t start,
      uint32_t length) = 0;
  virtual void DrawAutoIndexed(
      xenos::XE_GPU_PRIMITIVE_TYPE prim_type,
      uint32_t index_count) = 0;

protected:
  GraphicsDriver(xe_memory_ref memory);

  xe_memory_ref memory_;

  xenos::RegisterFile register_file_;
  uint32_t address_translation_;
};


}  // namespace gpu
}  // namespace xe


#endif  // XENIA_GPU_GRAPHICS_DRIVER_H_
