puerto
======

Simple port scanner designed to handle large networks efficiently. 

usage
-----

    usage: puerto <options> ip/hostname/cidr/range ...
    
       -a           icmp alive first
       -t           scan tcp ports 
       -u           scan udp ports
       -n           no reverse dns lookups
       -p <ports>   specify ports
       -i <secs>    host interval in seconds
       -r <count>   times to retry a host/port
       -w <secs>    timeout
       -m <method>  Method for scan type. "list" for a list of methods.
       -o <file>    write output to file
       -f <format>  format for output. "list" for a list of formats.
       -h, -?       show help and exit
       
    Target can be any of a single IP, a hostname, a CIDR, or a range. 
    Multiple target specifications can be given for a single scan.
    
    Ports can be specified with -p as a comma separated list (1,2,3...), 
    a range (1-3), or both (1-3,5,7-9). 
    
    If -a is given, only hosts that respond to icmp will be scanned.
    Without -a, all hosts will be tested for all specicied ports.
    
    -t and -u are mutually excluse for now. 
