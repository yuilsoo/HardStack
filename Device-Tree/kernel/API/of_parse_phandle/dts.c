/*
 * DTS: of_parse_phandle
 *
 * struct device_node *of_parse_phandle(const struct device_node *np,
 *                          const char *phandle_name, int index)
 *
 * (C) 2019.01.11 BuddyZhang1 <buddy.zhang@aliyun.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

/*
 * Private DTS file: DTS_demo.dtsi
 *
 * / {
 *        DTS_demo {
 *                compatible = "DTS_demo, BiscuitOS";
 *                status = "okay";
 *                phy-handle = <&phy1>;
 *
 *                phy0: phy@0 {
 *                        compatible = "PHYX, BiscuitOS";
 *                        reg = <0>;
 *                };
 *
 *                phy1: phy@1 {
 *                        compatible = "PHY, BiscuitOS";
 *                        reg = <1>;
 *                };
 *        };
 * };
 *
 * On Core dtsi:
 *
 * include "DTS_demo.dtsi"
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/of_platform.h>

/* define name for device and driver */
#define DEV_NAME "DTS_demo"

/* probe platform driver */
static int DTS_demo_probe(struct platform_device *pdev)
{
    struct device_node *np = pdev->dev.of_node;
    const phandle *ph;
    struct device_node *phy;
    const char *value;

    printk("DTS demo probe entence.\n");

    phy = of_parse_phandle(np, "phy-handle", 0);
    if (!phy) {
        printk("Unable read phy-handle property\n");
        return -1;
    }

    /* Read property from special device node */
    value = of_get_property(phy, "compatible", NULL);
    if (value)
        printk("PHY: %s\n", value);

    return 0;
}

/* remove platform driver */
static int DTS_demo_remove(struct platform_device *pdev)
{
    return 0;
}

static const struct of_device_id DTS_demo_of_match[] = {
    { .compatible = "DTS_demo, BiscuitOS", },
    { },
};
MODULE_DEVICE_TABLE(of, DTS_demo_of_match);

/* platform driver information */
static struct platform_driver DTS_demo_driver = {
    .probe  = DTS_demo_probe,
    .remove = DTS_demo_remove,
    .driver = {
        .owner = THIS_MODULE,
        .name = DEV_NAME, /* Same as device name */
        .of_match_table = DTS_demo_of_match,
    },
};
module_platform_driver(DTS_demo_driver);
