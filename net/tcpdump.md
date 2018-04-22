# tcpdump 
+ [Let's learn tcpdump](https://jvns.ca/tcpdump-zine.pdf)
	+ `tcpdump -i any any port 1337` check any packets arriving at my sever listening on 1337
	+ `tcpdump port 1337 and host 1.2.3.4` what packages are coming into my server from IP 1.2.3.4
	+ `tcpdump udp[11]&0xf==3` show all DNS queries that fail
+ `-i` for interface, which interface to capture, `-i any`
+ `-w` for write to file like my_packets.pcap
+ `-A` to print out packet's content, maybe ngrep is better
