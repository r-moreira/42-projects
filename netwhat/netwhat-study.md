### Links
https://www.youtube.com/watch?v=QKfk7YFILws -> studying
### The network layer (47:00)

https://www.youtube.com/watch?v=qiQR5rTSshw
https://www.youtube.com/watch?v=0PbTi_Prpgs&list=PLmAuaUS7wSOP5wYwirQbMv5vKdPpJ_O_I

# My netwhat study notes

## Netwhat topics
 - What is an IP address
 - What is a Netmask
 - What is the subnet of an IP with Netmask
 - What is the broadcast address of a subnet
 - What are the different ways to represent an ip address with the Netmask
 - What are the differences between public and private IPs
 - What is a class of IP addresses
 - What is TCP◦What is UDP◦What are the network layers
 - What is the OSI model◦What is a DHCP server and the DHCP protocol
 - What is a DNS server and the DNS protocol◦What are the rules to make 2 devices communicate using IP addresses
 - How does routing work with IP◦What is a default gateway for routing
 - What is a port from an IP point of view and what is it used for when connectingto another device

---

## Resume of my research

### What is an IP address
 - IP address stands for internet protocol address; it is an identifying number that is associated with a specific computer or computer network. When connected to the internet, the IP address allows the computers to send and receive information.
 - 192.196.0.0 -> IP example
 - It's four **octets** separeted by **dots**

<img src="./imgs/ip-octets.png" alt="IP octets" width="250" height="150">

 - Each number is an 8-bit value (which is range from 0 to 255)
 - IP Addresses are **two adresses in one**:
 	1. Host Address
	2. Network Address

 - Since 1981, the IP space is broken in to **five classes**
	1. A (Large networks - First octet is the network, and the three remaining is the host)
	2. B (Medium networks - First two octets is the network, and the two remaining is the host )
	3. C (Devices)
	4. D (Multicast)
	5. E (Reserved)

<img src="./imgs/ip-classes.png" alt="IP octets" width="600" height="300">

### What is a Netmask
