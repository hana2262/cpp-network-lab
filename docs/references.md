# 参考项目与规范来源

参考项目帮助定位问题和比较方案。优先级表示阅读投入，不表示必须依次读完整个仓库。

| 参考 | 用途 | 何时使用 |
| --- | --- | --- |
| [Airi](https://github.com/Airi-dynamic/Airi-Cpp-Server-Lib) | 主路线与阶段记录 | 选择下一个工程增量 |
| [muduo](https://github.com/chenshuo/muduo) | Reactor、线程和连接设计 | 有相关职责或生命周期问题时 |
| [Boost.Asio](https://www.boost.org/latest/doc/html/boost_asio/overview/composition/cpp20_coroutines.html) | 成熟库使用对照 | 与自研同步比较读写、协程和取消 |
| [coasync](https://github.com/RFoe/coasync) | 协程组合与调度专题 | 已能解释自己的任务和等待操作后 |

## 本次规范的直接依据

2026-11-26 核对以下公开内容：

- [Airi 格式配置](https://github.com/Airi-dynamic/Airi-Cpp-Server-Lib/blob/c4959435b90408ca49623839f3ae03acfc11c330/.clang-format)：LLVM 基础、四空格、禁用 Tab、100 列。本项目沿用这些设置。
- [Airi 日志规范](https://github.com/Airi-dynamic/Airi-Cpp-Server-Lib/blob/c4959435b90408ca49623839f3ae03acfc11c330/dev-log/日志模板规范.md)：要求问题背景、执行路径、验证和局限。本项目保留这些信息，缩减固定章节和代码摘录，不建立重复历史副本。
- [Airi 配置提交](https://github.com/Airi-dynamic/Airi-Cpp-Server-Lib/commit/c4959435b90408ca49623839f3ae03acfc11c330) 使用 chore(ide) 标明范围；[CI 提交](https://github.com/Airi-dynamic/Airi-Cpp-Server-Lib/commit/466d08400c1993aaa846e85996abad2caf9a4ab4) 使用 chore(ci)，正文分项说明依赖安装与工作流调整。本项目借鉴类型、范围和按需列出具体改动，使用“中文类型(范围)：具体变化”；本项目的验证、限制与人工审查要求不冒称来自 Airi。
- [muduo EventLoop 接口](https://github.com/chenshuo/muduo/blob/master/muduo/net/EventLoop.h)：在 loop、runInLoop、queueInLoop 等接口旁说明线程要求。采用契约靠近接口的做法；本次读取文件的 Git blob 为 c2c53d3461563a76bb6b51575854c1301d227a2e。
- [coasync 使用说明](https://github.com/RFoe/coasync/blob/c725019def0380a586c047d7ab586ba2eb68fc29/README.md)：用入门条件与代码示例介绍能力。本项目保留清晰入口，不沿用未验证的性能或平台宣传。

这些材料是设计依据，不是外部项目对本仓库的强制指令。没有运行参考仓库或复现其性能；公开实现与简历描述不一致时，以具体版本和实验为依据。代码复用保留来源及适用许可证，不把阅读参考写成复制实现。

N01 首次发布前再决定本项目许可证；此处列举参考项目不授予本项目额外使用权。
