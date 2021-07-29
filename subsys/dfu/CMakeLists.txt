#
# Copyright (c) 2019 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
#

if (NOT CONFIG_DFU_TARGET_MODEM
    AND NOT CONFIG_DFU_TARGET_MCUBOOT
    AND NOT CONFIG_DFU_TARGET_APPLICATION)
  message(FATAL_ERROR "No dfu supported target selected")
endif()

if (CONFIG_DFU_TARGET_APPLICATION)
  zephyr_include_directories(include)
endif()
zephyr_library()
zephyr_library_include_directories(include)

zephyr_library_sources(
  src/dfu_target.c
  )
zephyr_library_sources_ifdef(CONFIG_DFU_TARGET_MODEM
  src/dfu_target_modem.c
  )
zephyr_library_sources_ifdef(CONFIG_DFU_TARGET_MCUBOOT
  src/dfu_target_mcuboot.c
  )
