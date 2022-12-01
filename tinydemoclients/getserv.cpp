#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <unistd.h>
#include <cassert>
#include <memory>

int main(int argc,char** argv)
{
    assert(argc==2);

    char* hostname{argv[1]};
    char servicename[]{"daytime"};
    char serviceproto[]{"tcp"};

    hostent* hostentptr{gethostbyname(hostname)};    
    assert(hostentptr);

    servent* serventptr{getservbyname(servicename,serviceproto)};
    assert(serventptr);
    //servent::s_port is in network endian(big endian).
    std::cout<<"service port is"<<ntohs(serventptr->s_port)<<" ."<<std::endl;

    sockaddr_in address;//address is initialized.
    address.sin_family=AF_INET;//sockaddr_in::sin_family requires a address family name
    //both expect net endian. conversion not need.
    address.sin_port=serventptr->s_port;
    //sin_addr expect net endian. hostent are in net endian. conversion not need.
    address.sin_addr=*reinterpret_cast<in_addr*>(*hostentptr->h_addr_list);//?

    //make a socket in given format.
    int sockfd = socket (AF_INET,SOCK_STREAM,0);
    assert(sockfd!=-1);//not errors
    //sizeof(sockaddr)==sizeof(sockaddr_in)

    int result = connect(sockfd,reinterpret_cast<sockaddr*>(&address),sizeof(address));//?
    assert(result!=-1);//not error

    //buffer will not be initialized for lack of a well-defined value.
    static constexpr int max_daytime_data_len {128};
    char buffer[max_daytime_data_len];
    //read what is in written in socket, and write it to buffer.
    result = read (sockfd,buffer,sizeof(buffer));
    assert(result!=0&&result!=-1);//not EOF or error

    buffer[result]='\x00';

    std::cout<<"The day time is "<<buffer<<std::endl;


    close(sockfd);
    return 0;
}