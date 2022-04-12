# Copyright (c) 2021-2022 KT-Elektronik, Klaucke und Partner GmbH
# SPDX-License-Identifier: Apache-2.0

add_subdirectory_ifdef(CONFIG_HAS_RX_FIT FITModules)
add_subdirectory_ifdef(CONFIG_HAS_RX_FIT FIT_Zephyr_adapter)
