# Copyright (c) 2021-2022 KT-Elektronik, Klaucke und Partner GmbH
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_HAS_RX_FIT)
	zephyr_library()

	add_subdirectory(
		FIT_Zephyr_adapter
		FITModules
	)
endif()
