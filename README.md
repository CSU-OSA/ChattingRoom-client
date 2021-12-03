# ChattingRoom-client

CSU-OSA Chatting Room (client)

CSU-OSA 聊天室(客户端)

**该版本建构匆忙, 很多功能尚不完善. 可能存在隐形bug, 甚至恶性bug. 如果遇到任何问题, 欢迎在issue里提出**

## 应用说明

使用Qt(cpp)作为开发框架. 与服务端直接进行Socket连接, 传输二进制数据(Google Protobuf编码). 目前仍使用类Http的无状态通信, 新消息的获取需要轮询服务端.

主要开发者: [OctAutumn](https://github.com/Oct-autumn)

感谢参与程序初期测试的Member(排序不分先后):
[c76d](https://github.com/c76d3656)
[jigsaw](https://github.com/j1g5awi)
[MagicalSheep](https://github.com/MagicalSheep)
[singleNeuron](https://github.com/singleNeuron)
