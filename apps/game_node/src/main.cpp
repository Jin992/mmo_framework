#include "net/TcpServer.hpp"
#include "net/Response.hpp"

void display_header()
{
    std::string header( 
    "███╗   ██╗███████╗ ██████╗ ███╗   ██╗        ███╗   ███╗███╗   ███╗ ██████╗\n"   
    "████╗  ██║██╔════╝██╔═══██╗████╗  ██║        ████╗ ████║████╗ ████║██╔═══██╗\n"  
    "██╔██╗ ██║█████╗  ██║   ██║██╔██╗ ██║        ██╔████╔██║██╔████╔██║██║   ██║\n"  
    "██║╚██╗██║██╔══╝  ██║   ██║██║╚██╗██║        ██║╚██╔╝██║██║╚██╔╝██║██║   ██║\n"  
    "██║ ╚████║███████╗╚██████╔╝██║ ╚████║        ██║ ╚═╝ ██║██║ ╚═╝ ██║╚██████╔╝\n"  
    "╚═╝  ╚═══╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝        ╚═╝     ╚═╝╚═╝     ╚═╝ ╚═════╝\n"   
    "\n"                                                                          
    "███████╗██████╗  █████╗ ███╗   ███╗███████╗██╗    ██╗ ██████╗ ██████╗ ██╗  ██╗\n"
    "██╔════╝██╔══██╗██╔══██╗████╗ ████║██╔════╝██║    ██║██╔═══██╗██╔══██╗██║ ██╔╝\n"
    "█████╗  ██████╔╝███████║██╔████╔██║█████╗  ██║ █╗ ██║██║   ██║██████╔╝█████╔╝\n" 
    "██╔══╝  ██╔══██╗██╔══██║██║╚██╔╝██║██╔══╝  ██║███╗██║██║   ██║██╔══██╗██╔═██╗\n"
    "██║     ██║  ██║██║  ██║██║ ╚═╝ ██║███████╗╚███╔███╔╝╚██████╔╝██║  ██║██║  ██╗\n"
    "╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝ ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝\n"
    );
    std::cout << header << std::endl;
}



int main() {
    display_header();
    TcpServer<net::tcp::response::Response> server(8555);
    server.run();
    return 0;    
}