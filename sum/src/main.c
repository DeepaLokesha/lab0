/*
 * Section 6: sum function implemented via printk() or the Logger,
 * selected at build time via Kconfig (CONFIG_SUM_PRINT / CONFIG_SUM_LOG).
 */

#include <zephyr/kernel.h>

#if defined(CONFIG_SUM_PRINT)
#include "sum_printk/sum_printk.h"
#elif defined(CONFIG_SUM_LOG)
#include "sum_log/sum_log.h"
#endif

int main(void)
{
	int a = 5;
	int b = 7;
	int result;

#if defined(CONFIG_SUM_PRINT)
	result = sum_printk(a, b);
#elif defined(CONFIG_SUM_LOG)
	result = sum_log(a, b);
#else
#error "Either CONFIG_SUM_PRINT or CONFIG_SUM_LOG must be enabled"
#endif

	printk("main: sum() returned %d\n", result);

	return 0;
}
