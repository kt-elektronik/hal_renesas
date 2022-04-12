# Copyright (c) 2021-2022 KT-Elektronik, Klaucke und Partner GmbH
# SPDX-License-Identifier: Apache-2.0

message (STATUS "--> processing Renesas FITModules")

string(TOLOWER ${CONFIG_SOC_SERIES} _SOC_SERIES)

# r_bsp source files required by other FIT modules
zephyr_sources(
	r_bsp/mcu/all/r_bsp_locking.c
	r_bsp/mcu/all/mcu_locks.c
	r_bsp/mcu/all/r_bsp_cpu.c
	r_bsp/mcu/all/r_rx_intrinsic_functions.c
)

# r_sci_rx source files required for Zephyr RX UART driver
zephyr_sources_ifdef(CONFIG_UART_RX65N
	r_sci_rx/src/targets/${_SOC_SERIES}/r_sci_${_SOC_SERIES}.c
	r_sci_rx/src/targets/${_SOC_SERIES}/r_sci_${_SOC_SERIES}_data.c
)

# r_ether_rx source files required for the Zephyr RX ethernet driver
zephyr_sources_ifdef(CONFIG_ETH_RX65N
	r_ether_rx/src/r_ether_rx.c
	r_ether_rx/src/phy/phy.c
	r_ether_rx/src/targets/${_SOC_SERIES}/r_ether_setting_${_SOC_SERIES}.c
)

# configuration header files
zephyr_include_directories(r_config)

# iodefine.h
zephyr_include_directories(r_bsp/mcu/${_SOC_SERIES}/register_access/gnuc)
# general header files
zephyr_include_directories(
    r_bsp
    r_bsp/mcu/all
    r_bsp/mcu/${_SOC_SERIES}
    r_bsp/board/generic_${_SOC_SERIES}
)

# header files required for Zephyr RX UART driver
zephyr_include_directories_ifdef(CONFIG_UART_RX65N
	r_sci_rx/src/targets/${_SOC_SERIES}
	r_byteq
)

# header files required for Zephyr RX ethernet driver
zephyr_include_directories_ifdef(CONFIG_ETH_RX65N r_ether_rx)
