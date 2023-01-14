#include <linux/module.h>
#include <linux/init.h>
#include <linux/of.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/file.h>
#include <linux/slab.h>
#include <linux/platform_device.h>

#include "mydriver.h"

static int __init my_init(void)
{
	return 1;
}

static void __exit my_exit(void)
{
	pr_info("Goodbye!\n");
}

module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");
