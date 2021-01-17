#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <linux/of.h>
 
static int hello_probe(struct platform_device *pdev)
{
    pr_notice("Driver probe : %s\n", __func__);
    return 0;
}
 
static int hello_remove(struct platform_device *pdev)
{
    pr_notice("Driver remove :  %s\n", __func__);
    return 0;
}
 
static const struct of_device_id hello_dt_match[] = {
{ 
    .compatible = "hello" },
    {},
};
 
static struct platform_driver hello_driver = {
    .probe = hello_probe,
    .remove = hello_remove,
    .driver = {
        .name = "hello",
        .of_match_table = hello_dt_match,
    },
 
};
 
module_platform_driver(hello_driver);
MODULE_AUTHOR("hello");
MODULE_LICENSE("GPL v2");
