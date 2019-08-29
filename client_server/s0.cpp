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

static ll client_socket;

void runner() {
      char fileDetails[256];
      recv(client_socket, &fileDetails, sizeof(fileDetails), 0);
      ll i=0;
      stringstream ss;
      string temp[2];
      ss << fileDetails;
      while(ss >> temp[i++]);
      string s = "copy_";
      s += temp[0];
      temp[0] = s;
      FILE *fp = fopen((const char *)temp[0].c_str(),"w");
      cout<<"\nCreated file : "<<temp[0]<<endl;

      char eachLine[stoi(temp[1])];
      vector<string> clientMsg;
      while(recv(client_socket, &eachLine, strlen(eachLine), 0)) {
            s = "";
            for(ll i=0; eachLine[i]; i++) s += eachLine[i];
            clientMsg.pb(s);
      }
      for(auto x : clientMsg){ fputs(x.c_str(), fp); }
      fclose(fp);
      cout<<"Transfer Successful!\n\nClosing connection!\n";
      close(client_socket);
}

int32_t main() {
      ll sockfd,portNo = 9898;
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
      struct sockaddr_in server_addr;
      server_addr.sin_family = AF_INET;
      server_addr.sin_addr.s_addr = inet_addr("192.168.43.243"); //INADDR_ANY;
      server_addr.sin_port = htons(portNo);

      bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
      listen(sockfd ,2);

      cout<<"Listening on port :"<<portNo<<endl;
      client_socket = accept(sockfd, NULL, NULL);
      if(client_socket < 0) { cerr<<"Connection failed\n"<<endl; return 0; }
      else { cout << "Connection successful" << endl; }

      runner();
}
