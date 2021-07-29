#pragma once

#include <dfu/dfu_target.h>
#include <stddef.h>

bool dfu_target_application_identify(const void *const buf);
int dfu_target_application_init(size_t file_size, dfu_target_callback_t cb);
int dfu_target_application_offset_get(size_t *offset);
int dfu_target_application_write(const void *const buf, size_t len);
int dfu_target_application_done(bool successful);

