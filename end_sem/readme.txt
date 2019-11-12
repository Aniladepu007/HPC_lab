1.
Simple client server program,with fork and thread :
no need to change code just change the ip address in client
clients in VM and localhost
server in local host
sending file from client to server
commands :
		server :
				cd /home/<yourUsername>/7th_semester/HPC/client-server/server
				python file_transfer_server.py
		client :
				for localhost : cd /home/<yourUsername>/7th_semester/HPC/client-server/client1
				mininet VM2 : home
				python file_transfer_client.py 
				if need time for execution :
				in vim : ! time python file_transfer_client.py
input :
		server : with out quotes just give file name where to store
		client :
				localHost : do not give quotes only file.txt
				for VM's  : give with quotes for any client 'file.txt' This file is 1.3GB
server will get the file and store in the input file name given.

2.
In mininet vm-1 - pi code with omp header : (for pragma parallel pragma reduction and soo on)
		commands :
			(req)1. gcc -fopen pi.c -o output
				 2. export OMP_NUM_THREADS=4 (we can get output with out this too but dont know why we 	are doing this)
			(req)3. ./output 4 1500(we will get maximum for number of threads equal to number of cores)

3.open mpi : addition - hpc12 user creation and master slave setup (random addition with many processes)
(with seed value)
commands
	1.sudo su - hpc12
		password: (local user password) <yourUsername>123
	2.ssh-keygen -t rsa
	3.sudo mount -v -t nfs 172.17.9.213:/home/hpc12/cloud ~/cloud
    4.ssh-copy-id 172.16.18.28
    5.mpicc OpenMPI.c
	6.mpirun -np 2 -host 172.16.18.28,172.16.19.200 ./a.out
	7.mpirun -np 6 -host 172.16.18.28,172.16.19.200 ./a.out

4.bloom filter
		python bloom_filter.py
5.opencl (addition of vectors sin^2+cos^2)
		gcc opencl.c -lOpenCL -lm
6.hadoop
		command:
				wget http://mirrors.sonic.net/apache/hadoop/common/hadoop-2.9.2/hadoop-2.9.2.tar.gz
				tar xvzf hadoop-2.9.2.tar.gz
				sudo mkdir /usr/local/hadoop
				mv hadoop-2.9.2/* /usr/local/hadoop
				sudo chown -R <yourUsername>:<yourUsername> /usr/local/hadoop
				hadoop version(command not found)
				sudo apt install openjdk-8-jdk-headless
				sudo update-alternatives --config java

				config code modification

				stop-all.sh
				rm -R /usr/local/hadoop_store/hdfs/namenode
				rm -R /usr/local/hadoop_store/hdfs/datanode
				sudo mkdir -p /usr/local/hadoop_store/hdfs/namenode
				sudo mkdir -p /usr/local/hadoop_store/hdfs/datanode
				sudo chown -R <yourUsername>:<yourUsername> /usr/local/hadoop_store
				cd /usr/local/hadoop_store/hdfs/namenode
				hadoop namenode -format
				cd /usr/local/hadoop/sbin
				start-all.sh
				jps ( get 5 or 6 )
