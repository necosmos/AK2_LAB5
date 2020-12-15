#include "hello1.h"

static uint number = 1;
module_param(number, uint, S_IRUGO);
MODULE_PARM_DESC(number, "Nuber of printed \"Hello, world\", must be in [1,10]");

static int __init hello_init(void)
{
	pr_info("Number=%d\n", number);

	if (number == 0) {
		pr_warn("It is not good to have 0\n");
	} else if (number >= 5 && number <= 10) {
		pr_warn("It is not good to be between 5 ant 10\n");
	} else if (number > 10) {
		pr_err("Number souldn`t be larger than 10\n");
		return -EINVAL;
	}

	print_hello(number);

	return 0;
}

static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello_init);
module_exit(hello_exit);
