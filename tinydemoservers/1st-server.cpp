#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
static bool stop = false;
static void handle_term( int sig ){
    stop = true;
}
int main(int c , char** v){
    signal( SIGTERM ,handle_term);
    if(c<=3){
        printf("usage: %s ip_addr port_num backlog\n",basename(v[0]));
    }
    const char* ip=v[1];
    int port = atoi(v[2]);
    int backlog = atoi(v[3]);
    int sock = socket (PF_INET, SOCK_STREAM , 0);
    assert( sock >= 0);
    sockaddr_in addr;
    bzero(&addr,sizeof(addr));
    addr.sin_family=AF_INET;
    inet_pton(AF_INET,ip,&addr.sin_addr);
    addr.sin_port=htons(port);

    int ret=bind(sock,(sockaddr*)&addr,sizeof(addr));
    assert(ret!=-1);

    ret=listen(sock,backlog);
    assert(ret!=-1);

    while(!stop){
        sleep(1);
    }
    close(sock);
    return 0;
}