#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Winsock2.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_FDS 2048

int main() {
    // Tao socket cho ket noi
    int listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listener == -1) {
        perror("socket() failed");
        return 1;
    }

    // Khai bao dia chi server
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(9000);

    // Gan socket voi cau truc dia chi
    if (bind(listener, (struct sockaddr *)&addr, sizeof(addr))) {
        perror("bind() failed");
        return 1;
    }

    // Chuyen socket sang trang thai cho ket noi
    if (listen(listener, 5)) {
        perror("listen() failed");
        return 1;
    }

    struct pollfd fds[MAX_FDS];
    int nfds = 0;

    // Gan socket listener vao tap tham do
    fds[0].fd = listener;
    fds[0].events = POLLIN;
    nfds++;

    char buf[256];
    int flag[1024];
    memset(flag, 0, sizeof(flag));

    struct client_id
    {
        /* data */
        char name[256];
    }name_client[100];

    while (1) {
        int ret = poll(fds, nfds, -1);
        if (ret == -1) {
            break;
        }
        if (ret == 0) {
            printf("Timed out!!!\n");
            continue;
        }

        for (int i = 0; i < nfds; i++) {
            if (fds[i].revents & POLLIN) {
                if (fds[i].fd == listener) {
                    // Co ket noi moi
                    int client = accept(listener, NULL, NULL);
                    if (client >= MAX_FDS) {
                        // Vuot qua so luong toi da
                        close(client);
                    } else {
                        // Them vao mang tham do su kien
                        fds[nfds].fd = client;
                        fds[nfds].events = POLLIN;
                        nfds++;
                        printf("New client connected: %d\n", client);
                    }
                } else {
                    // Co du lieu tu client truyen den
                    int client = fds[i].fd;
                    ret = recv(client, buf, sizeof(buf), 0);
                    if (ret <= 0) {
                        // Ket noi bi dong => Xoa khoi mang
                    } else {
                        // Xu ly du lieu nhan duoc
                        //buf[ret] = 0;
                        char p[25];
                        printf("Received %s\n", buf);
                        memset(p, 0, sizeof(p));
                        strncpy(p , buf, strlen("/NICK") );
                        p[6] = '\0';
                        printf("%s\n", p);
                        if (flag[client] == 1) {
                            char msg[1024];
                            memset(msg, 0, sizeof(msg));
                            strcpy(msg, name_client[client].name);
                            strcat(msg, " : ");
                            strcat(msg, buf);
                            printf("Received from %s\n", msg);

                            //gửi đến tất cả client kết nối
                            for (int j = 0; j < nfds; j++) {
                                if (fds[j].fd != listener && fds[j].fd != client)
                                    send(fds[j].fd, msg, sizeof(msg), 0);
                            }
                        }
                        else {
                            if (!strcmp(p,"/NICK")) {
                                printf("1\n");
                                strncpy(name_client[client].name, buf + strlen("/NICK "), ret-strlen("/NICK ")-1);
                                int a = sizeof(name_client[client].name) - 1;
                                name_client[client].name[a] = '\0'; // Đảm bảo kết thúc chuỗi
                                flag[client] = 1;
                            }
                            else {
                                char str[] = "Nhap lai ***\n";
                                printf("2\n");
                                send(client, str, strlen(str), 0);
                            }
                        }

                    }
                }
            }
        }
    }

    return 0;
}
