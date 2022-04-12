# Adding the actual Drivers

Due to licensing issues, the actual FIT modules can not be included here. The following
FIT modules are required to be located in the appropriate directories:

```
|
+--r_bsp (tested with v5.61, changes necessary to platform.h)
+--r_byteq (tested with v1.81)
+--r_ether_rx (tested with v1.21)
+--r_sci_rx (tested with v2.46)
```

# modification of r_bsp/platform.h

The header file platform.h includes the actual r_bsp.h for the MCU. This can be done based on
Zephyr configuration:

```
#include <zephyr.h>

/* GENERIC_RX65N */
#if CONFIG_SOC_SERIES_RX65N
#include "./board/generic_rx65n/r_bsp.h"
#endif

/* GENERIC_RX66N */
#if CONFIG_SOC_SERIES_RX66N
#include "./board/generic_rx66n/r_bsp.h"
#endif

```
