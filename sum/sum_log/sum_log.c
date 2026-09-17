#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(sum_log, CONFIG_LOG_DEFAULT_LEVEL);

#include "sum_log.h"

int sum_log(int a, int b)
{
	int inputs[2] = { a, b };
	int result = a + b;

	LOG_DBG("sum_log called with a=%d, b=%d", a, b);
	LOG_HEXDUMP_INF(inputs, sizeof(inputs), "Input values (hexdump)");
	LOG_INF("Computed sum: %d", result);
	LOG_WRN("Sample warning-level message from sum_log");
	LOG_ERR("Sample error-level message from sum_log (for demonstration only)");

	return result;
}
