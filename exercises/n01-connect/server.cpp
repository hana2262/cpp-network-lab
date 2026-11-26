#include <arpa/inet.h>
#include <cstdio>
#include <sys/socket.h>
#include <unistd.h>

int main() {
    int listener_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listener_fd == -1) {
        std::perror("socket");
        return 1;
    }

    sockaddr_in local_addr{};
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(18080);
    int result = inet_pton(AF_INET, "127.0.0.1", &local_addr.sin_addr);
    if (result != 1) {
        if (result == 0) {
            std::fputs("inet_pton：IPv4 地址文本无效\n", stderr);
        } else {
            std::perror("inet_pton");
        }
        close(listener_fd);
        return 1;
    }

    if (bind(listener_fd, reinterpret_cast<const sockaddr*>(&local_addr), sizeof(local_addr)) ==
        -1) {
        std::perror("bind");
        close(listener_fd);
        return 1;
    }

    if (listen(listener_fd, 5) == -1) {
        std::perror("listen");
        close(listener_fd);
        return 1;
    }

    // 输出重定向时也要在阻塞前显示等待提示。
    std::puts("服务器正在监听：127.0.0.1:18080");
    std::fflush(stdout);

    sockaddr_in peer_addr{};
    // 输入为地址缓冲区容量，成功返回后为对端地址的实际长度。
    socklen_t peer_addr_size = sizeof(peer_addr);
    // 没有待接入连接时阻塞在这里；成功后监听 fd 仍然有效。
    int connection_fd =
        accept(listener_fd, reinterpret_cast<sockaddr*>(&peer_addr), &peer_addr_size);
    if (connection_fd == -1) {
        std::perror("accept");
        close(listener_fd);
        return 1;
    }

    std::printf("监听 fd：%d\n", listener_fd);
    std::printf("连接 fd：%d\n", connection_fd);

    close(connection_fd);
    close(listener_fd);
    return 0;
}
