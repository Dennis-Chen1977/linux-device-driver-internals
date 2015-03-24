/* This file is used to display driver mode info of the net_device 
 * which has been registered into the system
 * Mar.23, 2015
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <net/net_namespace.h>
#include <linux/netdevice.h>
#include <net/sch_generic.h>

static int netdevobj_init(void)
{
        struct device *dev, *parent;
        struct net_device *ndev;
        struct net *net = &init_net;
	struct bus_type *bus = NULL;

        printk(KERN_INFO "++%s\n", __func__);
        for_each_netdev_rcu(net, ndev) {
                dev = &(ndev->dev);
		if (dev) {
                	parent = dev->parent;
		}
		if (dev && parent) {
			bus = parent->bus;
                	printk(KERN_INFO "dev->name = %s, parent->name = %s\n", 
				dev->kobj.name, parent->kobj.name);
			if (bus)
				printk(KERN_INFO "bus = %s\n", bus->name);
		}
        }

        return 0;
}

static void netdevobj_exit(void)
{
        printk(KERN_INFO "--%s\n", __func__);
}

module_init(netdevobj_init);
module_exit(netdevobj_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("dennis chen");
MODULE_DESCRIPTION("To display the driver mode info of the net_device object");
