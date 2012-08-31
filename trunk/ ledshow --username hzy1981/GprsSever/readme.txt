新新娘美容院顾客资料管理系统0.0.2版 Build 20060904

修补BUG内容：将bin/qsqlmysql.dll和lib/qsqlmysql.a转移到plugins/sqldrivers/目录下面，并修改主程序main.cpp加入下面语句：
QApplication::addLibraryPath("../plugins");
使得客户机在没有安装QT的mysql库的情况下能正常运行


目录介绍：
bin　可执行文件目录, bpms.exe为可执行文件
doc　文档目录，里面的bpms.xml文件为DBDesigner4数据库设计文件
etc　配置文件目录, bpms.conf为数据库配置文件
hlp　预存放帮助文件
plugins 放置插件库的地方，libqsqlmysql.a和qsqlmysql.dll在sqldrivers目录下,为MySQL的qt for mingw版本编译的库
lib　静态库和动态库文件目录里面的，对应的dll文件在bin目录下
sql　MySQL数据库创建脚本文件bpms.sql
src　源码目录src.pro为工程文件
tmp　源码编译临时目录
bpms.pro为工程文件

为打包文件大小计，没有把QtGui, QtCore, QtSql这三个dll包含进来。程序是用mingw编译的。Qt为4.1.4
安装过程为：在MySQL中建个数据库，然后把sql/bpms.sql的脚本导入到新建的库中，然后修改etc/bpms.conf这个文本配置文件，设置参数，即完成。