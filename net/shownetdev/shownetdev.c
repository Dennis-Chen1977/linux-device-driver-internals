/*
 * This file is used to display all the net_device which have been registered
 * into the system
 * Nov.7, 2014
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <net/net_namespace.h>
#include <linux/netdevice.h>
#include <net/sch_generic.h>

static int netdev_show_init(void)
{
	struct net_device *dev;
	struct net *net = &init_net;
	int ns_cnt = 0;

	printk(KERN_INFO "netdev_show_init(), net devices:\n");
  	for_each_netdev_rcu(net, dev) {
		printk(KERN_INFO "%s[%d], type = %d, qdisc = %s\n", dev->name,  
				dev->ifindex, dev->type, dev->qdisc->ops->id);
	}
	for_each_net_rcu(net) {
		ns_cnt++;
	}
	printk(KERN_INFO "ns count = %d, page_sieze = 0x%lx, bits_long = %x\n", ns_cnt, PAGE_SIZE, ~(BITS_PER_LONG-1));

	return 0;
}

static void netdev_show_exit(void)
{
	printk(KERN_INFO "netdev_show_exit()\n");
}

module_init(netdev_show_init);
module_exit(netdev_show_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("dennis chen");
MODULE_DESCRIPTION("To display all the net devices registered into the system");
