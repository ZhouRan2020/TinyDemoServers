# TinyDemoServers 项目说明书

## 项目目标用户群体

- ISO C/C++学习者
- GNUC/GLibC学习者
- Linux学习者
- 网络编程学习者
- 高性能服务器开发学习者
- 学习了理论知识、简单程序，却从未接触过真实项目开发的人

## 本项目的任务/通过阅读、运行本项目的源码，我能学到什么？

- 在实际项目中，Modern C++，符合C++20标准的C++语言运用
- GLibC中，网络编程接口的运用
- 高性能服务器开发知识点的学习
- 真实项目的源代码架构，而不是“玩具代码”
- 真实项目的工具链使用，以及代码到产品的流程
- 强调“Code至上”的精神，一切用Code说话

## 本项目是什么？

    正如本项目的名字，本项目是一个集合了众多服务器“原子功能”的示例服务程序集合。
    项目分为两个部分：服务端程序和客户端程序，但是放在同一个仓库里保存。服务端和客户端的用户都需要下载全部的代码，但是编译时运行不同的程序，从而得到不同的可执行文件。服务端运行server.out，而客户端运行client.out。首先，服务端先开启服务。然后，客户端打开GUI界面（或许是CL）。用户会得到一个菜单，要么从菜单中选择想获取的服务，要么退出程序。用户在选择对应的服务后，通过互联网与服务器通信，服务器会给客户端发送相应的反馈数据，客户端把反馈数据在屏幕上展示出来。然后，用户要么返回菜单界面继续选择，要么直接退出程序。
    客户端所提供的服务包括：daytime，网络编程功能展示，文件服务，等等（取决于项目进度）。

## 使用方法

### 自己编译源代码

### 使用linux发布版

## 项目信息

### 项目周期

    项目从即日（12.01）开始，持续两个星期（14天），到12.14 23:59发布v1.0。
    12.16更新:因12.15 23:59有论文截稿，本项目周期顺延半个月(15天）。项目从即日（12.16)开始，持续两个星期（14天），到12.29 23:59发布v1.0。

### 项目分工

- 拟定功能：周冉
- 项目架构设计：周冉
- 源代码编写：周冉
- 测试：周冉
- 项目维护：周冉

### 项目运行环境

跨硬件平台，基于Linux操作系统。以两个.out文件的形式给出。License：MIT

### 项目材料和经费

- 办公场所：宿舍、实验室
- 个人电脑一台
- 鼠标键盘一套
- 百度智能云服务器实例一台
- 咖啡不限量
- 香烟不限量

## 项目创新点以及先进性

- 发扬BS的精神，让新手也能接触到Modern C++的正确用法
- 衔接课本知识与实际工业产品，强调项目开发工具链的使用
- 高度的解耦合，极强的可拓展性，新手也能轻易的修改代码
- 初步强调GUI的使用，不再仅限于开发“黑框程序”
- 方便向别人展示和交流所学成果，极强的正反馈
- Linux网络编程最佳的入门读物，有书可依，有大量注释

## 如何达到所说的目的?

### C++

- 强调编程风格，严格按照Google C++的规范来编码
- 本人是BS的狂热技术粉丝，会严格按照BS的建议来编码
- 使用STL容器，算法
- 使用Modern C++特性
- 会用双斜线给出关于语法细节的注释，以供参考

### 服务器开发

- 有书可依靠，以游双的经典教材为依据
- 权威的资料：头文件的注释，glibc用户手册，linux用户手册等
- 涵盖游双编程书籍正文的全部内容

### 项目规范

- 会广泛参考其他github C++项目，使得麻雀虽小五脏俱全。
- 工具链的使用，也尽量会以脚本代码文件的形式给出
- 会参考经典的tinywebserver，loadbalanceserver，httpserver等项目取并集，给出最完整的项目架构

## 代码结构

## 常见问题

## 联系方式

- email:rzhoujames@163.com
- address:南京市四牌楼2号
