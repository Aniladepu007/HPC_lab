#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include<arpa/inet.h>
#define endl "\n"
#define pb push_back
typedef int ll;
typedef unsigned long long ull;
using namespace std;
//#include<netdb.h>

int32_t main(int count, char* argv[]) {
      ll sockFd;
      sockFd = socket(AF_INET, SOCK_STREAM, 0);
      struct sockaddr_in server_addr;
      server_addr.sin_family = AF_INET;
      server_addr.sin_addr.s_addr = inet_addr("192.168.0.102");
      server_addr.sin_port = htons(9898);

      ll connection = connect(sockFd, (struct sockaddr *) &server_addr, sizeof(server_addr));
      ll maxSize = INT_MIN;
      vector<string> sender;
      string eachLine,fileDetails;
      fileDetails += argv[1];
      fileDetails += " ";

      ifstream stream(argv[1]);
      while(getline(stream,eachLine)) {
            if((ll)eachLine.size() > maxSize) { maxSize = eachLine.size(); }
                  sender.push_back(eachLine);
            eachLine.clear();
      }
//      for(auto x : sender)cout<<x<<endl;
      fileDetails += to_string(maxSize);
      cout<<"Transferring file : "<<argv[1]<<endl<<"......"<<endl<<"....";
      send(sockFd, fileDetails.data(), fileDetails.length(), 0);

      for(ll i=0; i<sender.size();i++) {
            sender[i].pb('\n');
            send( sockFd, sender[i].data(), sender[i].length(),0);
      }
      cout<<endl<<"Transfer Successful !\n";
      close(sockFd);
}
