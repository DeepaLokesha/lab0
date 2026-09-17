#include <zephyr/kernel.h>
#include "sum_printk.h"

int sum_printk(int a, int b)
{
	int result = a + b;

	printk("sum_printk: computing %d + %d\n", a, b);
	printk("sum_printk: result = %d\n", result);

	return result;
}
