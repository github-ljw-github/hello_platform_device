#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <linux/of.h>

#define TAG "[hello]"
static int hello_probe(struct platform_device *pdev)
{
    pr_notice(TAG "Driver probe : %s\n", __func__);

    pr_notice(TAG "IORESOURCE_MEM:%x\n", platform_get_resource(pdev, IORESOURCE_MEM, 0));
    pr_notice(TAG "IORESOURCE_MEM:%x\n", platform_get_resource(pdev, IORESOURCE_MEM, 1));
    pr_notice(TAG "IORESOURCE_IRQ:%x\n", platform_get_resource(pdev, IORESOURCE_IRQ, 0));
    pr_notice(TAG "IORESOURCE_REG:%x\n", platform_get_resource(pdev, IORESOURCE_REG, 0));


    struct resource *mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
    if(mem)
    {
        pr_notice(TAG "mem->start: %x\n", mem->start);
        pr_notice(TAG "mem->end: %x\n", mem->end);
        pr_notice(TAG "mem->name: %s\n", mem->name);
    }

    return 0;
}
 
static int hello_remove(struct platform_device *pdev)
{
    pr_notice(TAG "Driver remove :  %s\n", __func__);
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
MODULE_LICENSE("GPL");
