/*
 * This file is used to play with the Qdisc for the net dev queue
 * Nov.12, 2014
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <net/net_namespace.h>
#include <linux/netdevice.h>


static int qdisc_init(void)
{
	struct net_device *dev;
	struct net *net = &init_net;

	printk(KERN_INFO "+qdisc_init()\n");
  	for_each_netdev_rcu(net, dev) {
		printk(KERN_INFO "[%s]tx->qdisc = 0x%p\n", dev->name, dev->_tx[0].qdisc);
	}
	

	return 0;
}

static void qdisc_exit(void)
{
	printk(KERN_INFO "qdisc_exit()\n");
}

module_init(qdisc_init);
module_exit(qdisc_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("dennis chen");
MODULE_DESCRIPTION("Qdisc in the net dev queue");
