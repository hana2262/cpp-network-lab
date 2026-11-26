#include <arpa/inet.h>
#include <cstdio>
#include <sys/socket.h>
#include <unistd.h>

int main() {
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1) {
        std::perror("socket");
        return 1;
    }
    
    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(18080);
    int result = inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    if (result != 1) {
        if (result == 0) {
            std::fputs("inet_pton：IPv4 地址文本无效\n", stderr);
        } else {
            std::perror("inet_pton");
        }
        close(client_fd);
        return 1;
    }

    if (connect(client_fd, reinterpret_cast<const sockaddr*>(&server_addr), sizeof(server_addr)) ==
        -1) {
        std::perror("connect");
        close(client_fd);
        return 1;
    }

    std::puts("连接成功");
    close(client_fd);
    return 0;
}
