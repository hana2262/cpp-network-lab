# C++ 网络编程实验

从原始 Socket 通信出发，逐步实现基于 Linux Reactor 的 C++20 网络库，再通过 RPC 和实际服务验证其可复用性。按可验证的任务成果演进，不按开发天数划分版本。

## 当前成果

已完成 **N01：建立一次 TCP 连接**。服务端监听 `127.0.0.1:18080`，接入一个客户端后打印监听 fd 和连接 fd；客户端连接成功后打印提示，两端关闭资源并退出。

在 WSL Ubuntu-24.04、GCC 13.3.0 下，已验证正常连接、连接被拒绝、端口占用和 `accept` 阻塞行为，并审查 fd 关闭路径。具体环境、结果及未覆盖的失败分支见 [N01 成果说明](docs/tasks/N01.md)。

当前不收发应用数据，尚无持续维护的自动化测试和 CI。事件循环、协程、多线程与 RPC 属于后续目标，见 [开发路线](docs/roadmap.md)。

## 开始使用

环境：Linux 或 WSL Ubuntu，支持 C++20 的编译器，CMake 3.20 及以上。当前无第三方依赖。

在项目根目录执行：

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j2
```

在项目根目录的一个终端启动服务端：

```bash
./build/connect_server
```

再在同目录的另一个终端启动客户端：

```bash
./build/connect_client
```

预期服务端先显示监听提示并等待，客户端启动后显示“连接成功”，服务端打印两个不同的有效 fd，随后两端退出。fd 数值不固定。

## 目录与职责

```text
cpp-network-lab/
├── CMakeLists.txt            构建入口
├── README.md                 项目介绍与运行入口
├── exercises/n01-connect/    N01 服务端与客户端
└── docs/
    ├── tasks/               任务与成果说明
    ├── roadmap.md           开发路线
    └── references.md        参考来源与取舍
```

`exercises/` 保存阶段实验，`docs/tasks/` 说明各阶段解决的问题、设计与验证结果；当前构建入口只包含 N01 两个程序。工程与文档的版本变化通过 Git 追溯。

借鉴 [Airi](https://github.com/Airi-dynamic/Airi-Cpp-Server-Lib) 区分当前实现、历史阶段和技术说明的方式。出现实际复用后再建立 `include/`、`src/` 与 `examples/`，区分库实现和独立实验；当前保留已有路径，不复制整套工程或预建空目录。

## 参考与协作

路线与设计参考 Airi、muduo 等项目，具体来源和取舍见 [参考项目](docs/references.md)。参考项目不是工程依赖。

学习者主导核心代码实现；AI 助手参与知识引导、审查、必要骨架与实验辅助。N01 的实际分工见成果说明。本地协作规则和个人学习记录不随仓库发布。

当前尚未选择许可证，也没有发布版本。
